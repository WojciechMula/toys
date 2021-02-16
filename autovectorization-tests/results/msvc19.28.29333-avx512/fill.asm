_v$ = 8                                       ; size = 4
void fill_epi32(std::vector<int,std::allocator<int> > &) PROC ; fill_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    edi
        mov     edx, DWORD PTR [eax+4]
        mov     ecx, edx
        mov     edi, DWORD PTR [eax]
        sub     ecx, edi
        add     ecx, 3
        xor     eax, eax
        shr     ecx, 2
        cmp     edi, edx
        cmova   ecx, eax
        test    ecx, ecx
        je      SHORT $LN17@fill_epi32
        mov     eax, 42                             ; 0000002aH
        rep stosd
$LN17@fill_epi32:
        pop     edi
        ret     0
void fill_epi32(std::vector<int,std::allocator<int> > &) ENDP ; fill_epi32

_v$ = 8                                       ; size = 4
void fill_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; fill_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        mov     eax, DWORD PTR [ecx+4]
        mov     ecx, DWORD PTR [ecx]
        sub     eax, ecx
        push    eax
        push    42                                  ; 0000002aH
        push    ecx
        call    _memset
        add     esp, 12                             ; 0000000cH
        ret     0
void fill_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; fill_epi8
