_v$ = 8                                       ; size = 4
void remove_epi32(std::vector<int,std::allocator<int> > &) PROC ; remove_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        mov     esi, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, esi
        je      SHORT $LN17@remove_epi
        npad    2
$LL26@remove_epi:
        cmp     DWORD PTR [eax], 42                 ; 0000002aH
        je      SHORT $LN37@remove_epi
        add     eax, 4
        cmp     eax, esi
        jne     SHORT $LL26@remove_epi
$LN37@remove_epi:
        cmp     eax, esi
        je      SHORT $LN17@remove_epi
        lea     ecx, DWORD PTR [eax+4]
        cmp     ecx, esi
        je      SHORT $LN17@remove_epi
$LL16@remove_epi:
        mov     edx, DWORD PTR [ecx]
        cmp     edx, 42                             ; 0000002aH
        je      SHORT $LN19@remove_epi
        mov     DWORD PTR [eax], edx
        add     eax, 4
$LN19@remove_epi:
        add     ecx, 4
        cmp     ecx, esi
        jne     SHORT $LL16@remove_epi
$LN17@remove_epi:
        pop     esi
        ret     0
void remove_epi32(std::vector<int,std::allocator<int> > &) ENDP ; remove_epi32

_v$ = 8                                       ; size = 4
void remove_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; remove_epi8, COMDAT
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
        je      SHORT $LN17@remove_epi
        lea     eax, DWORD PTR [ecx+1]
        cmp     eax, esi
        je      SHORT $LN17@remove_epi
        npad    4
$LL16@remove_epi:
        mov     dl, BYTE PTR [eax]
        cmp     dl, 42                                    ; 0000002aH
        je      SHORT $LN19@remove_epi
        mov     BYTE PTR [ecx], dl
        inc     ecx
$LN19@remove_epi:
        inc     eax
        cmp     eax, esi
        jne     SHORT $LL16@remove_epi
$LN17@remove_epi:
        pop     esi
        ret     0
void remove_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; remove_epi8
