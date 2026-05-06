#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <psapi.h>
#include <winnt.h>

#include <cstdio>
#include <cwchar>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#pragma comment(lib, "psapi.lib")

HANDLE InitConsole() // with proto
{
    AllocConsole();

    //SetConsoleOutputCP(866);
    //setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    return hConsole;
}

struct DumpEntry
{
    DWORD slot;
    DWORD ptr;
};

static std::wstring GetDirFromPath(const wchar_t* path)
{
    std::wstring s = path ? path : L"";
    size_t pos = s.find_last_of(L"\\/");
    if (pos == std::wstring::npos)
        return L".";
    return s.substr(0, pos);
}

static std::string SanitizeIdaName(const std::string& in)
{
    std::string s = in;
    for (char& c : s)
    {
        unsigned char uc = static_cast<unsigned char>(c);
        if (!(std::isalnum(uc) || c == '_'))
            c = '_';
    }
    if (s.empty())
        s = "unk";
    if (std::isdigit(static_cast<unsigned char>(s[0])))
        s = "_" + s;
    return s;
}

static bool ParseDumpFile(const wchar_t* path, std::vector<DumpEntry>& out)
{
    FILE* f = nullptr;
    if (_wfopen_s(&f, path, L"rt") != 0 || !f)
        return false;

    wchar_t line[512];
    while (fgetws(line, _countof(line), f))
    {
        unsigned int a = 0, b = 0;
        if (swscanf_s(line, L"%x %x", &a, &b) == 2)
        {
            out.push_back({ static_cast<DWORD>(a), static_cast<DWORD>(b) });
        }
    }

    fclose(f);
    return !out.empty();
}

static void AddExportsFromModule(HMODULE hMod, std::unordered_map<uintptr_t, std::string>& addrToName)
{
    MODULEINFO mi{};
    if (!GetModuleInformation(GetCurrentProcess(), hMod, &mi, sizeof(mi)))
        return;

    auto base = reinterpret_cast<BYTE*>(mi.lpBaseOfDll);

    auto dos = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
    if (!dos || dos->e_magic != IMAGE_DOS_SIGNATURE)
        return;

    auto nt = reinterpret_cast<IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
    if (!nt || nt->Signature != IMAGE_NT_SIGNATURE)
        return;

    const auto& dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
    if (!dir.VirtualAddress || !dir.Size)
        return;

    auto exp = reinterpret_cast<IMAGE_EXPORT_DIRECTORY*>(base + dir.VirtualAddress);
    if (!exp)
        return;

    auto funcs = reinterpret_cast<DWORD*>(base + exp->AddressOfFunctions);
    auto names = reinterpret_cast<DWORD*>(base + exp->AddressOfNames);
    auto ords = reinterpret_cast<WORD*>(base + exp->AddressOfNameOrdinals);

    std::vector<std::string> perIndex(exp->NumberOfFunctions);

    for (DWORD i = 0; i < exp->NumberOfNames; ++i)
    {
        DWORD idx = ords[i];
        if (idx < exp->NumberOfFunctions)
        {
            const char* nm = reinterpret_cast<const char*>(base + names[i]);
            if (nm && *nm)
                perIndex[idx] = nm;
        }
    }

    DWORD expStart = dir.VirtualAddress;
    DWORD expEnd = dir.VirtualAddress + dir.Size;

    for (DWORD i = 0; i < exp->NumberOfFunctions; ++i)
    {
        DWORD rva = funcs[i];
        if (!rva)
            continue;

        if (rva >= expStart && rva < expEnd)
            continue; // forwarded export

        uintptr_t addr = reinterpret_cast<uintptr_t>(base + rva);

        std::string name = perIndex[i];
        if (name.empty())
        {
            char tmp[64];
            sprintf_s(tmp, "ord%u", exp->Base + i);
            name = tmp;
        }

        if (addrToName.find(addr) == addrToName.end())
            addrToName.emplace(addr, name);
    }
}

static void CollectAllExports(std::unordered_map<uintptr_t, std::string>& addrToName)
{
    HMODULE mods[1024]{};
    DWORD needed = 0;

    if (!EnumProcessModules(GetCurrentProcess(), mods, sizeof(mods), &needed))
        return;

    const size_t count = needed / sizeof(HMODULE);
    for (size_t i = 0; i < count; ++i)
        AddExportsFromModule(mods[i], addrToName);
}

static void GenerateIdc(const wchar_t* inFile, const wchar_t* outFile)
{
    std::vector<DumpEntry> entries;
    if (!ParseDumpFile(inFile, entries))
        return;

    std::unordered_map<uintptr_t, std::string> addrToName;
    CollectAllExports(addrToName);

    FILE* f = nullptr;
    if (_wfopen_s(&f, outFile, L"wt") != 0 || !f)
        return;

    //fwprintf(f, L"#include <idc.idc>\n\n");
    //fwprintf(f, L"static main()\n{\n");

    for (const auto& e : entries)
    {
        auto it = addrToName.find(static_cast<uintptr_t>(e.ptr));
        if (it == addrToName.end())
        {
            fwprintf(f, L"    // unresolved: 0x%08X -> 0x%08X\n", e.slot, e.ptr);
            continue;
        }

        std::string safe = SanitizeIdaName(it->second);

        // Можно оставить только имя функции, либо сделать уникальным:
        // name = func_XXXXXXXX
        char unique[128];
        //sprintf_s(unique, "%s_%08X", safe.c_str(), e.slot);
        sprintf_s(unique, "%s", safe.c_str());

        fwprintf(f, L"    set_name(0x%08X, \"%S\", SN_AUTO);\n", e.slot, unique);
    }

    //fwprintf(f, L"}\n");
    fclose(f);
}

static DWORD WINAPI WorkerThread(LPVOID param)
{
    HMODULE self = reinterpret_cast<HMODULE>(param);

    wchar_t dllPath[MAX_PATH]{};
    GetModuleFileNameW(self, dllPath, MAX_PATH);

    std::wstring dir = GetDirFromPath(dllPath);
    std::wstring inFile = dir + L"\\iat_dump.txt";
    std::wstring outFile = dir + L"\\iat_fix.txt";

    GenerateIdc(inFile.c_str(), outFile.c_str());
    printf("fixer done\n");
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        InitConsole();
        printf("fixer loaded\n");
        DisableThreadLibraryCalls(hModule);
        HANDLE h = CreateThread(nullptr, 0, WorkerThread, hModule, 0, nullptr);
        if (h)
            CloseHandle(h);
    }
    return TRUE;
}