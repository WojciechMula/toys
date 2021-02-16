_v$ = 8                                       ; size = 4
bool find_epi32(std::vector<int,std::allocator<int> > const &) PROC ; find_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        mov     eax, DWORD PTR [ecx+4]
        mov     ecx, DWORD PTR [ecx]
        cmp     ecx, eax
        je      SHORT $LN35@find_epi32
        npad    3
$LL22@find_epi32:
        cmp     DWORD PTR [ecx], 42                 ; 0000002aH
        je      SHORT $LN30@find_epi32
        add     ecx, 4
        cmp     ecx, eax
        jne     SHORT $LL22@find_epi32
$LN30@find_epi32:
        cmp     ecx, eax
$LN35@find_epi32:
        setne   al
        ret     0
bool find_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; find_epi32

_v$ = 8                                       ; size = 4
bool find_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; find_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        mov     ecx, DWORD PTR [eax]
        mov     esi, DWORD PTR [eax+4]
        mov     eax, esi
        sub     eax, ecx
        push    eax
        push    42                                  ; 0000002aH
        push    ecx
        call    _memchr
        add     esp, 12                             ; 0000000cH
        mov     ecx, esi
        test    eax, eax
        cmovne  ecx, eax
        cmp     ecx, esi
        pop     esi
        setne   al
        ret     0
bool find_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; find_epi8
