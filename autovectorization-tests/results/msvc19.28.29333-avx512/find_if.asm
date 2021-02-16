_x$ = 8                                       ; size = 4
bool <lambda_c55a951d9de6e7f14effe8b1fcdf8a9a>::operator()(int)const  PROC ; <lambda_c55a951d9de6e7f14effe8b1fcdf8a9a>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        cmp     eax, 42                             ; 0000002aH
        je      SHORT $LN3@operator
        cmp     eax, -1
        je      SHORT $LN3@operator
        xor     al, al
        ret     4
$LN3@operator:
        mov     al, 1
        ret     4
bool <lambda_c55a951d9de6e7f14effe8b1fcdf8a9a>::operator()(int)const  ENDP ; <lambda_c55a951d9de6e7f14effe8b1fcdf8a9a>::operator()

_x$ = 8                                       ; size = 4
bool <lambda_b471ea8d4cd0da91a59e4d70ab9d5552>::operator()(int)const  PROC ; <lambda_b471ea8d4cd0da91a59e4d70ab9d5552>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        cmp     eax, 42                             ; 0000002aH
        je      SHORT $LN3@operator
        cmp     eax, -1
        je      SHORT $LN3@operator
        xor     al, al
        ret     4
$LN3@operator:
        mov     al, 1
        ret     4
bool <lambda_b471ea8d4cd0da91a59e4d70ab9d5552>::operator()(int)const  ENDP ; <lambda_b471ea8d4cd0da91a59e4d70ab9d5552>::operator()

_v$ = 8                                       ; size = 4
bool find_if_epi32(std::vector<int,std::allocator<int> > const &) PROC ; find_if_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        mov     eax, DWORD PTR [ecx+4]
        mov     ecx, DWORD PTR [ecx]
        cmp     ecx, eax
        je      SHORT $LN36@find_if_ep
        npad    3
$LL18@find_if_ep:
        mov     edx, DWORD PTR [ecx]
        cmp     edx, 42                             ; 0000002aH
        je      SHORT $LN23@find_if_ep
        cmp     edx, -1
        je      SHORT $LN23@find_if_ep
        add     ecx, 4
        cmp     ecx, eax
        jne     SHORT $LL18@find_if_ep
$LN23@find_if_ep:
        cmp     ecx, eax
$LN36@find_if_ep:
        setne   al
        ret     0
bool find_if_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; find_if_epi32

_v$ = 8                                       ; size = 4
bool find_if_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; find_if_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        mov     eax, DWORD PTR [ecx+4]
        mov     ecx, DWORD PTR [ecx]
        cmp     ecx, eax
        je      SHORT $LN36@find_if_ep
        npad    3
$LL18@find_if_ep:
        movsx   edx, BYTE PTR [ecx]
        cmp     edx, 42                             ; 0000002aH
        je      SHORT $LN23@find_if_ep
        cmp     edx, -1
        je      SHORT $LN23@find_if_ep
        inc     ecx
        cmp     ecx, eax
        jne     SHORT $LL18@find_if_ep
$LN23@find_if_ep:
        cmp     ecx, eax
$LN36@find_if_ep:
        setne   al
        ret     0
bool find_if_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; find_if_epi8
