_v$ = 8                                       ; size = 4
void replace_epi32(std::vector<int,std::allocator<int> > &) PROC ; replace_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN17@replace_ep
        npad    3
$LL23@replace_ep:
        cmp     DWORD PTR [eax], 13                 ; 0000000dH
        jne     SHORT $LN29@replace_ep
        mov     DWORD PTR [eax], 42                 ; 0000002aH
$LN29@replace_ep:
        add     eax, 4
        cmp     eax, ecx
        jne     SHORT $LL23@replace_ep
$LN17@replace_ep:
        ret     0
void replace_epi32(std::vector<int,std::allocator<int> > &) ENDP ; replace_epi32

_v$ = 8                                       ; size = 4
void replace_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; replace_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN17@replace_ep
        npad    3
$LL23@replace_ep:
        cmp     BYTE PTR [eax], 13                        ; 0000000dH
        jne     SHORT $LN29@replace_ep
        mov     BYTE PTR [eax], 42                        ; 0000002aH
$LN29@replace_ep:
        inc     eax
        cmp     eax, ecx
        jne     SHORT $LL23@replace_ep
$LN17@replace_ep:
        ret     0
void replace_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; replace_epi8
