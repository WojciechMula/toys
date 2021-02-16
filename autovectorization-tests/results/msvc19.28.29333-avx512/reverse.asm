_v$ = 8                                       ; size = 4
void reverse_epi32(std::vector<int,std::allocator<int> > &) PROC ; reverse_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    DWORD PTR [eax+4]
        push    DWORD PTR [eax]
        call    ___std_reverse_trivially_swappable_4
        add     esp, 8
        ret     0
void reverse_epi32(std::vector<int,std::allocator<int> > &) ENDP ; reverse_epi32

_v$ = 8                                       ; size = 4
void reverse_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; reverse_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    DWORD PTR [eax+4]
        push    DWORD PTR [eax]
        call    ___std_reverse_trivially_swappable_1
        add     esp, 8
        ret     0
void reverse_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; reverse_epi8
