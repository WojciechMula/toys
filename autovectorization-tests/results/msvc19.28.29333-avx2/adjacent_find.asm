_v$ = 8                                       ; size = 4
bool adjacent_find_epi32(std::vector<int,std::allocator<int> > const &) PROC ; adjacent_find_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        push    esi
        push    edi
        mov     eax, DWORD PTR [ecx+4]
        mov     esi, eax
        mov     edi, DWORD PTR [ecx]
        cmp     edi, eax
        je      SHORT $LN31@adjacent_f
        lea     ecx, DWORD PTR [edi+4]
        cmp     ecx, eax
        je      SHORT $LN31@adjacent_f
        mov     esi, edi
        mov     edi, DWORD PTR [edi]
        npad    4
$LL20@adjacent_f:
        mov     edx, DWORD PTR [ecx]
        cmp     edi, edx
        je      SHORT $LN31@adjacent_f
        mov     esi, ecx
        mov     edi, edx
        add     ecx, 4
        cmp     ecx, eax
        jne     SHORT $LL20@adjacent_f
        mov     esi, eax
$LN31@adjacent_f:
        cmp     esi, eax
        pop     edi
        setne   al
        pop     esi
        ret     0
bool adjacent_find_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; adjacent_find_epi32

_v$ = 8                                       ; size = 4
bool adjacent_find_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; adjacent_find_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        push    esi
        mov     eax, DWORD PTR [ecx+4]
        mov     esi, eax
        mov     edx, DWORD PTR [ecx]
        cmp     edx, eax
        je      SHORT $LN31@adjacent_f
        lea     ecx, DWORD PTR [edx+1]
        cmp     ecx, eax
        je      SHORT $LN31@adjacent_f
        push    ebx
        mov     bl, BYTE PTR [edx]
        mov     esi, edx
        npad    4
$LL20@adjacent_f:
        mov     dl, BYTE PTR [ecx]
        cmp     bl, dl
        je      SHORT $LN35@adjacent_f
        mov     esi, ecx
        mov     bl, dl
        inc     ecx
        cmp     ecx, eax
        jne     SHORT $LL20@adjacent_f
        mov     esi, eax
$LN35@adjacent_f:
        pop     ebx
$LN31@adjacent_f:
        cmp     esi, eax
        pop     esi
        setne   al
        ret     0
bool adjacent_find_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; adjacent_find_epi8
