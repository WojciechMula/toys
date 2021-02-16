_x$ = 8                                       ; size = 1
bool <lambda_b117bf54b35f6628f43e6190b3c041ab>::operator()(signed char)const  PROC ; <lambda_b117bf54b35f6628f43e6190b3c041ab>::operator(), COMDAT
        cmp     BYTE PTR _x$[esp-4], 42             ; 0000002aH
        sete    al
        ret     4
bool <lambda_b117bf54b35f6628f43e6190b3c041ab>::operator()(signed char)const  ENDP ; <lambda_b117bf54b35f6628f43e6190b3c041ab>::operator()

_x$ = 8                                       ; size = 4
bool <lambda_4d0ea1357c146fd4c3ae19f09d91b5ef>::operator()(int)const  PROC ; <lambda_4d0ea1357c146fd4c3ae19f09d91b5ef>::operator(), COMDAT
        cmp     DWORD PTR _x$[esp-4], 42      ; 0000002aH
        sete    al
        ret     4
bool <lambda_4d0ea1357c146fd4c3ae19f09d91b5ef>::operator()(int)const  ENDP ; <lambda_4d0ea1357c146fd4c3ae19f09d91b5ef>::operator()

_v$ = 8                                       ; size = 4
bool all_of_epi32(std::vector<int,std::allocator<int> > const &) PROC ; all_of_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN13@all_of_epi
        npad    3
$LL14@all_of_epi:
        cmp     DWORD PTR [eax], 42                 ; 0000002aH
        jne     SHORT $LN20@all_of_epi
        add     eax, 4
        cmp     eax, ecx
        jne     SHORT $LL14@all_of_epi
$LN13@all_of_epi:
        mov     al, 1
        ret     0
$LN20@all_of_epi:
        xor     al, al
        ret     0
bool all_of_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; all_of_epi32

_v$ = 8                                       ; size = 4
bool all_of_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; all_of_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN13@all_of_epi
        npad    3
$LL14@all_of_epi:
        cmp     BYTE PTR [eax], 42                        ; 0000002aH
        jne     SHORT $LN20@all_of_epi
        inc     eax
        cmp     eax, ecx
        jne     SHORT $LL14@all_of_epi
$LN13@all_of_epi:
        mov     al, 1
        ret     0
$LN20@all_of_epi:
        xor     al, al
        ret     0
bool all_of_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; all_of_epi8
