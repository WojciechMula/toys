_v$ = 8                                       ; size = 4
void unique_epi32(std::vector<int,std::allocator<int> > &) PROC ; unique_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        mov     esi, DWORD PTR [eax+4]
        mov     ecx, DWORD PTR [eax]
        cmp     ecx, esi
        je      SHORT $LN22@unique_epi
        lea     edx, DWORD PTR [ecx+4]
        cmp     edx, esi
        je      SHORT $LN22@unique_epi
        push    ebx
        mov     ebx, DWORD PTR [ecx]
        push    edi
        npad    7
$LL20@unique_epi:
        mov     edi, DWORD PTR [edx]
        lea     eax, DWORD PTR [edx+4]
        cmp     ebx, edi
        je      SHORT $LN32@unique_epi
        mov     ecx, edx
        mov     ebx, edi
        mov     edx, eax
        cmp     edx, esi
        jne     SHORT $LL20@unique_epi
        pop     edi
        pop     ebx
        pop     esi
        ret     0
$LN32@unique_epi:
        cmp     eax, esi
        je      SHORT $LN39@unique_epi
        npad    5
$LL21@unique_epi:
        mov     edx, DWORD PTR [eax]
        cmp     DWORD PTR [ecx], edx
        je      SHORT $LN25@unique_epi
        add     ecx, 4
        mov     DWORD PTR [ecx], edx
$LN25@unique_epi:
        add     eax, 4
        cmp     eax, esi
        jne     SHORT $LL21@unique_epi
$LN39@unique_epi:
        pop     edi
        pop     ebx
$LN22@unique_epi:
        pop     esi
        ret     0
void unique_epi32(std::vector<int,std::allocator<int> > &) ENDP ; unique_epi32

_v$ = 8                                       ; size = 4
void unique_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; unique_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        mov     esi, DWORD PTR [eax+4]
        mov     ecx, DWORD PTR [eax]
        cmp     ecx, esi
        je      SHORT $LN22@unique_epi
        lea     edx, DWORD PTR [ecx+1]
        cmp     edx, esi
        je      SHORT $LN22@unique_epi
        push    ebx
        mov     bh, BYTE PTR [ecx]
$LL20@unique_epi:
        mov     bl, BYTE PTR [edx]
        lea     eax, DWORD PTR [edx+1]
        cmp     bh, bl
        je      SHORT $LN32@unique_epi
        mov     ecx, edx
        mov     bh, bl
        mov     edx, eax
        cmp     edx, esi
        jne     SHORT $LL20@unique_epi
        pop     ebx
        pop     esi
        ret     0
$LN32@unique_epi:
        cmp     eax, esi
        je      SHORT $LN38@unique_epi
$LL21@unique_epi:
        mov     dl, BYTE PTR [eax]
        cmp     BYTE PTR [ecx], dl
        je      SHORT $LN25@unique_epi
        inc     ecx
        mov     BYTE PTR [ecx], dl
$LN25@unique_epi:
        inc     eax
        cmp     eax, esi
        jne     SHORT $LL21@unique_epi
$LN38@unique_epi:
        pop     ebx
$LN22@unique_epi:
        pop     esi
        ret     0
void unique_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; unique_epi8
