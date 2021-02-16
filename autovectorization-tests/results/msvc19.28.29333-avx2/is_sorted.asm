_v$ = 8                                       ; size = 4
bool is_sorted_epi32(std::vector<int,std::allocator<int> > const &) PROC ; is_sorted_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        push    edi
        mov     edi, DWORD PTR [eax+4]
        mov     edx, edi
        mov     esi, DWORD PTR [eax]
        cmp     esi, edx
        je      SHORT $LN17@is_sorted_
        lea     eax, DWORD PTR [esi+4]
        cmp     eax, edx
        je      SHORT $LN17@is_sorted_
        sub     esi, eax
        npad    6
$LL18@is_sorted_:
        mov     ecx, DWORD PTR [eax]
        cmp     ecx, DWORD PTR [esi+eax]
        jl      SHORT $LN25@is_sorted_
        add     eax, 4
        cmp     eax, edx
        jne     SHORT $LL18@is_sorted_
        cmp     edx, edi
        pop     edi
        sete    al
        pop     esi
        ret     0
$LN25@is_sorted_:
        mov     edx, eax
$LN17@is_sorted_:
        cmp     edx, edi
        pop     edi
        sete    al
        pop     esi
        ret     0
bool is_sorted_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; is_sorted_epi32

_v$ = 8                                       ; size = 4
bool is_sorted_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; is_sorted_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        push    edi
        mov     edi, DWORD PTR [eax+4]
        mov     edx, edi
        mov     esi, DWORD PTR [eax]
        cmp     esi, edx
        je      SHORT $LN17@is_sorted_
        lea     eax, DWORD PTR [esi+1]
        cmp     eax, edx
        je      SHORT $LN17@is_sorted_
        sub     esi, eax
        npad    6
$LL18@is_sorted_:
        mov     cl, BYTE PTR [eax]
        cmp     cl, BYTE PTR [esi+eax]
        jl      SHORT $LN25@is_sorted_
        inc     eax
        cmp     eax, edx
        jne     SHORT $LL18@is_sorted_
        cmp     edx, edi
        pop     edi
        sete    al
        pop     esi
        ret     0
$LN25@is_sorted_:
        mov     edx, eax
$LN17@is_sorted_:
        cmp     edx, edi
        pop     edi
        sete    al
        pop     esi
        ret     0
bool is_sorted_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; is_sorted_epi8
