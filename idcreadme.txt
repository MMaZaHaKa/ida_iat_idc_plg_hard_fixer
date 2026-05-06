вводишь адрес начала
вводишь адрес конца
выбери файл куда сейвнуть таблтицу

вот этому из дампа нужно дать имя
data:6784A000                         ; Segment type: Pure data
.idata:6784A000                         ; Segment permissions: Read
.idata:6784A000                         _idata          segment para public 'DATA' use32
.idata:6784A000                                         assume cs:_idata
.idata:6784A000                                         ;org 6784A000h
.idata:6784A000                         ; HANDLE (__stdcall *CreateFileA)(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
.idata:6784A000 D0 DD B2 74             CreateFileA     dd 74B2DDD0h            ; DATA XREF: sub_678312B0+2A^r
.idata:6784A000                                                                 ; sub_678313E0+2B^r ...
.idata:6784A004                         ; HANDLE (__stdcall *CreateFileW)(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
.idata:6784A004 D0 E0 B2 74             CreateFileW     dd 74B2E0D0h            ; DATA XREF: sub_67831550+1F^r
.idata:6784A008                         ; int (__stdcall *DeviceIOControl)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)
.idata:6784A008 10 11 AD 74             DeviceIOControl dd 74AD1110h            ; DATA XREF: sub_678312B0+90^r
.idata:6784A008                                                                 ; sub_678313E0+75^r ...
.idata:6784A00C                         ; int (__stdcall *dword_6784A00C)(_DWORD)
.idata:6784A00C 80 DB B2 74             dword_6784A00C  dd 74B2DB80h            ; DATA XREF: sub_678312B0+110^r
.idata:6784A00C                                                                 ; sub_678313E0+14B^r ...
.idata:6784A010 10 6A AD 74             dword_6784A010  dd 74AD6A10h            ; DATA XREF: __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int)+219^r
.idata:6784A010                                                                 ; ___crtGetEnvironmentStringsA:loc_6784196A^r ...
.idata:6784A014 20 73 AD 74             dword_6784A014  dd 74AD7320h            ; DATA XREF: std::_Init_locks::_Init_locks(void)+A^r
.idata:6784A014                                                                 ; ___addlocaleref+7^r ...
.idata:6784A018 C0 72 AD 74             dword_6784A018  dd 74AD72C0h            ; DATA XREF: sub_6784918E-DA93^r
.idata:6784A018                                                                 ; ___removelocaleref+13^r ...
.idata:6784A01C E0 72 AD 74             dword_6784A01C  dd 74AD72E0h            ; DATA XREF: __ReleaseCPLocHash+D^r
.idata:6784A020 40 5B AD 74             dword_6784A020  dd 74AD5B40h            ; DATA XREF: __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int):loc_6783E02A^r
.idata:6784A020                                                                 ; __crtGetStringTypeA_stat(localeinfo_struct *,ulong,char const *,int,ushort *,int,int,int):loc_67841DF1^r ...
.idata:6784A024 60 66 AD 74             dword_6784A024  dd 74AD6660h            ; DATA XREF: __malloc_crt+21^r
.idata:6784A024                                                                 ; __calloc_crt+28^r ...
.idata:6784A028 00 BA A9 77             dword_6784A028  dd 77A9BA00h            ; DATA XREF: sub_6783B7D6+8^r
.idata:6784A02C 80 C6 A6 77             dword_6784A02C  dd 77A6C680h            ; DATA XREF: sub_6783B7E6+8^r
.idata:6784A02C                                                                 ; __mtdeletelocks+3^r ...
.idata:6784A030 10 A2 A8 77             dword_6784A030  dd 77A8A210h            ; DATA XREF: sub_6783B7F6+8^r
.idata:6784A030                                                                 ; __lock+2A^r ...
.idata:6784A034 90 A1 A8 77             dword_6784A034  dd 77A8A190h            ; DATA XREF: sub_6783B806+8^r
.idata:6784A034                                                                 ; __unlock+F^r ...
.idata:6784A038 30 54 AD 74             dword_6784A038  dd 74AD5430h            ; DATA XREF: __time32+B^r
.idata:6784A038                                                                 ; ___security_init_cookie+37^r
.idata:6784A03C B0 13 A8 77             dword_6784A03C  dd 77A813B0h            ; DATA XREF: _malloc+14^r
.idata:6784A03C                                                                 ; ___sbh_alloc_new_region+5D^r ...
.idata:6784A040 E0 66 AD 74             dword_6784A040  dd 74AD66E0h            ; DATA XREF: __invoke_watson+115^r
.idata:6784A040                                                                 ; ___report_gsfailure+FE^r
.idata:6784A044 20 DB B2 74             dword_6784A044  dd 74B2DB20h            ; DATA XREF: __invoke_watson+10E^r
.idata:6784A044                                                                 ; ___report_gsfailure+F7^r
.idata:6784A048 D0 67 AD 74             dword_6784A048  dd 74AD67D0h            ; DATA XREF: __invoke_watson+F3^r
.idata:6784A048                                                                 ; _abort+109^r ...
.idata:6784A04C 20 66 AD 74             dword_6784A04C  dd 74AD6620h            ; DATA XREF: __invoke_watson+E6^r
.idata:6784A04C                                                                 ; _abort+FC^r ...
.idata:6784A050 30 58 AD 74             dword_6784A050  dd 74AD5830h            ; DATA XREF: __invoke_watson+DC^r
.idata:6784A050                                                                 ; ___report_gsfailure+BB^r
.idata:6784A054 10 4F AD 74             dword_6784A054  dd 74AD4F10h            ; DATA XREF: _free+79^r
.idata:6784A054                                                                 ; __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int):loc_6783DFBF^r ...
.idata:6784A058 F0 56 AD 74             dword_6784A058  dd 74AD56F0h            ; DATA XREF: _free+68^r
.idata:6784A058                                                                 ; ___sbh_free_block+2B6^r ...
.idata:6784A05C 30 87 AD 74             dword_6784A05C  dd 74AD8730h            ; DATA XREF: _CRT_INIT(x,x,x)+106^r
.idata:6784A05C                                                                 ; __getptd_noexit+56^r ...
.idata:6784A060 B0 4B AD 74             dword_6784A060  dd 74AD4BB0h            ; DATA XREF: _CRT_INIT(x,x,x)+36^r
.idata:6784A064 20 5D AD 74             dword_6784A064  dd 74AD5D20h            ; DATA XREF: _CxxThrowException(x,x)+42^r
.idata:6784A068 00 7B AD 74             dword_6784A068  dd 74AD7B00h            ; DATA XREF: sub_67845DCE^r
.idata:6784A06C 10 4C AD 74             dword_6784A06C  dd 74AD4C10h            ; DATA XREF: setSBUpLow(threadmbcinfostruct *)+21^r
.idata:6784A06C                                                                 ; __setmbcp_nolock+86^r ...
.idata:6784A070 40 59 AD 74             dword_6784A070  dd 74AD5940h            ; DATA XREF: __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int)+297^r
.idata:6784A070                                                                 ; __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int)+368^r
.idata:6784A074 60 59 AD 74             dword_6784A074  dd 74AD5960h            ; DATA XREF: __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int)+32^r
.idata:6784A074                                                                 ; __crtLCMapStringA_stat(localeinfo_struct *,ulong,ulong,char const *,int,char *,int,int,int)+146^r ...
.idata:6784A078 A0 4B AD 74             dword_6784A078  dd 74AD4BA0h            ; DATA XREF: getSystemCP(int)+4C^r
.idata:6784A07C 60 50 AD 74             dword_6784A07C  dd 74AD5060h            ; DATA XREF: getSystemCP(int)+29^r
.idata:6784A080 C0 58 AD 74             dword_6784A080  dd 74AD58C0h            ; DATA XREF: __setmbcp_nolock+73^r
.idata:6784A084 D0 4F AD 74             dword_6784A084  dd 74AD4FD0h            ; DATA XREF: __encode_pointer+3F^r
.idata:6784A084                                                                 ; __decode_pointer+3F^r ...
.idata:6784A088 B0 50 AD 74             dword_6784A088  dd 74AD50B0h            ; DATA XREF: __encode_pointer+5A^r
.idata:6784A088                                                                 ; __decode_pointer+5A^r ...
.idata:6784A08C 50 67 AD 74             dword_6784A08C  dd 74AD6750h            ; DATA XREF: __encode_pointer+C^r
.idata:6784A08C                                                                 ; __decode_pointer+C^r ...
.idata:6784A090 20 67 AD 74             dword_6784A090  dd 74AD6720h            ; DATA XREF: sub_6783F720^r
.idata:6784A090                                                                 ; __mtinit:loc_6783FB59^r
.idata:6784A094 70 67 AD 74             dword_6784A094  dd 74AD6770h            ; DATA XREF: ___set_flsgetvalue+2A^r
.idata:6784A094                                                                 ; __freeptd+66^r ...
.idata:6784A098 30 67 AD 74             dword_6784A098  dd 74AD6730h            ; DATA XREF: __mtterm+2B^r
.idata:6784A098                                                                 ; __mtinit+8E^r
.idata:6784A09C 00 4E AD 74             dword_6784A09C  dd 74AD4E00h            ; DATA XREF: __getptd_noexit+6E^r
.idata:6784A09C                                                                 ; ___crtInitCritSecAndSpinCount+46^r
.idata:6784A0A0 D0 68 AD 74             dword_6784A0A0  dd 74AD68D0h            ; DATA XREF: ___sbh_free_block+231^r
.idata:6784A0A0                                                                 ; __heap_term+2F^r
.idata:6784A0A4 70 68 AD 74             dword_6784A0A4  dd 74AD6870h            ; DATA XREF: ___sbh_alloc_new_region+77^r
.idata:6784A0A4                                                                 ; ___sbh_alloc_new_group+54^r
.idata:6784A0A8 F0 D9 A7 77             dword_6784A0A8  dd 77A7D9F0h            ; DATA XREF: ___sbh_alloc_new_region+27^r
.idata:6784A0A8                                                                 ; _realloc+134^r ...
.idata:6784A0AC B0 56 AD 74             dword_6784A0AC  dd 74AD56B0h            ; DATA XREF: __heap_init+15^r
.idata:6784A0B0 D0 56 AD 74             dword_6784A0B0  dd 74AD56D0h            ; DATA XREF: __heap_term+66^r
.idata:6784A0B4 C0 3B AD 74             dword_6784A0B4  dd 74AD3BC0h            ; DATA XREF: ___crtExitProcess+11^r
.idata:6784A0B8 50 E2 B2 74             dword_6784A0B8  dd 74B2E250h            ; DATA XREF: __NMSG_WRITE+1A0^r
.idata:6784A0B8                                                                 ; __write_nolock+260^r ...
.idata:6784A0BC 30 52 AD 74             dword_6784A0BC  dd 74AD5230h            ; DATA XREF: __NMSG_WRITE+176^r
.idata:6784A0BC                                                                 ; __ioinit+1C9^r
.idata:6784A0C0 70 4F AD 74             dword_6784A0C0  dd 74AD4F70h            ; DATA XREF: __NMSG_WRITE+A3^r
.idata:6784A0C0                                                                 ; __setargv+2C^r
.idata:6784A0C4 F0 10 AD 74             dword_6784A0C4  dd 74AD10F0h            ; DATA XREF: __ioinit+233^r
.idata:6784A0C8 30 E0 B2 74             dword_6784A0C8  dd 74B2E030h            ; DATA XREF: __ioinit+13F^r
.idata:6784A0C8                                                                 ; __ioinit+1DB^r
.idata:6784A0CC 20 34 B1 74             dword_6784A0CC  dd 74B13420h            ; DATA XREF: __ioinit+15^r
.idata:6784A0D0 00 4B AD 74             dword_6784A0D0  dd 74AD4B00h            ; DATA XREF: ___crtGetEnvironmentStringsA+111^r
.idata:6784A0D0                                                                 ; ___crtGetEnvironmentStringsA+12A^r
.idata:6784A0D4 A0 4D AD 74             dword_6784A0D4  dd 74AD4DA0h            ; DATA XREF: ___crtGetEnvironmentStringsA:loc_678419CC^r
.idata:6784A0D8 20 4B AD 74             dword_6784A0D8  dd 74AD4B20h            ; DATA XREF: ___crtGetEnvironmentStringsA+CC^r
.idata:6784A0DC B0 4D AD 74             dword_6784A0DC  dd 74AD4DB0h            ; DATA XREF: ___crtGetEnvironmentStringsA+F^r
.idata:6784A0E0 A0 5C AD 74             dword_6784A0E0  dd 74AD5CA0h            ; DATA XREF: ___security_init_cookie+5F^r
.idata:6784A0E4 40 D0 B2 74             dword_6784A0E4  dd 74B2D040h            ; DATA XREF: ___security_init_cookie+53^r
.idata:6784A0E8 30 DB B2 74             dword_6784A0E8  dd 74B2DB30h            ; DATA XREF: ___security_init_cookie+43^r
.idata:6784A0EC 70 52 AD 74             dword_6784A0EC  dd 74AD5270h            ; DATA XREF: __crtGetStringTypeA_stat(localeinfo_struct *,ulong,char const *,int,ushort *,int,int,int)+193^r
.idata:6784A0F0 B0 52 AD 74             dword_6784A0F0  dd 74AD52B0h            ; DATA XREF: __crtGetStringTypeA_stat(localeinfo_struct *,ulong,char const *,int,ushort *,int,int,int)+2F^r
.idata:6784A0F0                                                                 ; __crtGetStringTypeA_stat(localeinfo_struct *,ulong,char const *,int,ushort *,int,int,int)+11E^r
.idata:6784A0F4 40 EF A7 77             dword_6784A0F4  dd 77A7EF40h            ; DATA XREF: __msize+82^r
.idata:6784A0F8 20 4F AD 74             dword_6784A0F8  dd 74AD4F20h            ; DATA XREF: ___ansicp+24^r
.idata:6784A0FC F0 E1 B2 74             dword_6784A0FC  dd 74B2E1F0h            ; DATA XREF: __lseeki64_nolock+42^r
.idata:6784A100 10 E5 B2 74             dword_6784A100  dd 74B2E510h            ; DATA XREF: __write_nolock:loc_6784310A^r
.idata:6784A104 20 E5 B2 74             dword_6784A104  dd 74B2E520h            ; DATA XREF: __write_nolock+127^r
.idata:6784A108 80 DC B2 74             dword_6784A108  dd 74B2DC80h            ; DATA XREF: ___crtInitCritSecAndSpinCount+16^r
.idata:6784A10C 80 59 AD 74             dword_6784A10C  dd 74AD5980h            ; DATA XREF: sub_67844BBC+28^r
.idata:6784A110 20 65 AD 74             dword_6784A110  dd 74AD6520h            ; DATA XREF: __free_osfhnd:loc_678450A7^r
.idata:6784A114 C0 E5 B2 74             dword_6784A114  dd 74B2E5C0h            ; DATA XREF: __putwch_nolock+9E^r
.idata:6784A118 30 E5 B2 74             dword_6784A118  dd 74B2E530h            ; DATA XREF: __putwch_nolock+7B^r
.idata:6784A11C D0 E5 B2 74             dword_6784A11C  dd 74B2E5D0h            ; DATA XREF: __putwch_nolock+48^r
.idata:6784A120 40 DF B2 74             dword_6784A120  dd 74B2DF40h            ; DATA XREF: __commit+8C^r
.idata:6784A124 B0 4F AD 74             dword_6784A124  dd 74AD4FB0h            ; DATA XREF: __ms_p5_mp_test_fdiv+5^r
.idata:6784A128 00 00 00 00                             dd 0
.idata:6784A128                         _idata          ends
.idata:6784A128
.text:6784A12C                         ; ===================