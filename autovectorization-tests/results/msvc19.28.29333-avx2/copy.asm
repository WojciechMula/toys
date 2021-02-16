_x$ = 8                                       ; size = 1
bool <lambda_927aa56c448f9c55be2bcb37a8933483>::operator()(signed char)const  PROC ; <lambda_927aa56c448f9c55be2bcb37a8933483>::operator(), COMDAT
        cmp     BYTE PTR _x$[esp-4], 42             ; 0000002aH
        sete    al
        ret     4
bool <lambda_927aa56c448f9c55be2bcb37a8933483>::operator()(signed char)const  ENDP ; <lambda_927aa56c448f9c55be2bcb37a8933483>::operator()

_x$ = 8                                       ; size = 4
bool <lambda_75eb68450bfbdc920c8935cf3cee0978>::operator()(int)const  PROC ; <lambda_75eb68450bfbdc920c8935cf3cee0978>::operator(), COMDAT
        cmp     DWORD PTR _x$[esp-4], 42      ; 0000002aH
        sete    al
        ret     4
bool <lambda_75eb68450bfbdc920c8935cf3cee0978>::operator()(int)const  ENDP ; <lambda_75eb68450bfbdc920c8935cf3cee0978>::operator()

_v$ = 8                                       ; size = 4
bool any_of_epi32(std::vector<int,std::allocator<int> > const &) PROC ; any_of_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN13@any_of_epi
        npad    3
$LL14@any_of_epi:
        cmp     DWORD PTR [eax], 42                 ; 0000002aH
        je      SHORT $LN20@any_of_epi
        add     eax, 4
        cmp     eax, ecx
        jne     SHORT $LL14@any_of_epi
$LN13@any_of_epi:
        xor     al, al
        ret     0
$LN20@any_of_epi:
        mov     al, 1
        ret     0
bool any_of_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; any_of_epi32

_v$ = 8                                       ; size = 4
bool any_of_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; any_of_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, ecx
        je      SHORT $LN13@any_of_epi
        npad    3
$LL14@any_of_epi:
        cmp     BYTE PTR [eax], 42                        ; 0000002aH
        je      SHORT $LN20@any_of_epi
        inc     eax
        cmp     eax, ecx
        jne     SHORT $LL14@any_of_epi
$LN13@any_of_epi:
        xor     al, al
        ret     0
$LN20@any_of_epi:
        mov     al, 1
        ret     0
bool any_of_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; any_of_epi8
