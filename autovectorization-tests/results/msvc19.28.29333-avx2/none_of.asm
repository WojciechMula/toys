_x$ = 8                                       ; size = 1
bool <lambda_90d1d7fd9197fd097bda85b94f044474>::operator()(signed char)const  PROC ; <lambda_90d1d7fd9197fd097bda85b94f044474>::operator(), COMDAT
        cmp     BYTE PTR _x$[esp-4], 42             ; 0000002aH
        sete    al
        ret     4
bool <lambda_90d1d7fd9197fd097bda85b94f044474>::operator()(signed char)const  ENDP ; <lambda_90d1d7fd9197fd097bda85b94f044474>::operator()

_x$ = 8                                       ; size = 4
bool <lambda_aa77c881993408bc39b649cb2cadb898>::operator()(int)const  PROC ; <lambda_aa77c881993408bc39b649cb2cadb898>::operator(), COMDAT
        cmp     DWORD PTR _x$[esp-4], 42      ; 0000002aH
        sete    al
        ret     4
bool <lambda_aa77c881993408bc39b649cb2cadb898>::operator()(int)const  ENDP ; <lambda_aa77c881993408bc39b649cb2cadb898>::operator()

_v$ = 8                                       ; size = 4
bool none_of_epi32(std::vector<int,std::allocator<int> > const &) PROC ; none_of_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN13@none_of_ep
        npad    3
$LL14@none_of_ep:
        cmp     DWORD PTR [eax], 42                 ; 0000002aH
        je      SHORT $LN20@none_of_ep
        add     eax, 4
        cmp     eax, ecx
        jne     SHORT $LL14@none_of_ep
$LN13@none_of_ep:
        mov     al, 1
        ret     0
$LN20@none_of_ep:
        xor     al, al
        ret     0
bool none_of_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; none_of_epi32

_v$ = 8                                       ; size = 4
bool none_of_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; none_of_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN13@none_of_ep
        npad    3
$LL14@none_of_ep:
        cmp     BYTE PTR [eax], 42                        ; 0000002aH
        je      SHORT $LN20@none_of_ep
        inc     eax
        cmp     eax, ecx
        jne     SHORT $LL14@none_of_ep
$LN13@none_of_ep:
        mov     al, 1
        ret     0
$LN20@none_of_ep:
        xor     al, al
        ret     0
bool none_of_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; none_of_epi8
