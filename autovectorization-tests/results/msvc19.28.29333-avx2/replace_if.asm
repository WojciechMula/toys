_x$ = 8                                       ; size = 1
bool <lambda_ad861479477e1fbb05bd322ccf289cc9>::operator()(signed char)const  PROC ; <lambda_ad861479477e1fbb05bd322ccf289cc9>::operator(), COMDAT
        mov     al, BYTE PTR _x$[esp-4]
        cmp     al, 13                                    ; 0000000dH
        je      SHORT $LN3@operator
        cmp     al, -12                             ; fffffff4H
        je      SHORT $LN3@operator
        xor     al, al
        ret     4
$LN3@operator:
        mov     al, 1
        ret     4
bool <lambda_ad861479477e1fbb05bd322ccf289cc9>::operator()(signed char)const  ENDP ; <lambda_ad861479477e1fbb05bd322ccf289cc9>::operator()

_x$ = 8                                       ; size = 1
bool <lambda_4093684095680229e393b4c1222caf42>::operator()(signed char)const  PROC ; <lambda_4093684095680229e393b4c1222caf42>::operator(), COMDAT
        mov     al, BYTE PTR _x$[esp-4]
        cmp     al, 13                                    ; 0000000dH
        je      SHORT $LN3@operator
        cmp     al, -12                             ; fffffff4H
        je      SHORT $LN3@operator
        xor     al, al
        ret     4
$LN3@operator:
        mov     al, 1
        ret     4
bool <lambda_4093684095680229e393b4c1222caf42>::operator()(signed char)const  ENDP ; <lambda_4093684095680229e393b4c1222caf42>::operator()

_v$ = 8                                       ; size = 4
void replace_if_epi32(std::vector<int,std::allocator<int> > &) PROC ; replace_if_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     edx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, edx
        je      SHORT $LN17@replace_if
        npad    3
$LL18@replace_if:
        mov     cl, BYTE PTR [eax]
        cmp     cl, 13                                    ; 0000000dH
        je      SHORT $LN23@replace_if
        cmp     cl, -12                             ; fffffff4H
        jne     SHORT $LN16@replace_if
$LN23@replace_if:
        mov     DWORD PTR [eax], 42                 ; 0000002aH
$LN16@replace_if:
        add     eax, 4
        cmp     eax, edx
        jne     SHORT $LL18@replace_if
$LN17@replace_if:
        ret     0
void replace_if_epi32(std::vector<int,std::allocator<int> > &) ENDP ; replace_if_epi32

_v$ = 8                                       ; size = 4
void replace_if_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; replace_if_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     edx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, edx
        je      SHORT $LN17@replace_if
        npad    3
$LL27@replace_if:
        mov     cl, BYTE PTR [eax]
        cmp     cl, 13                                    ; 0000000dH
        je      SHORT $LN28@replace_if
        cmp     cl, -12                             ; fffffff4H
        jne     SHORT $LN33@replace_if
$LN28@replace_if:
        mov     BYTE PTR [eax], 42                        ; 0000002aH
$LN33@replace_if:
        inc     eax
        cmp     eax, edx
        jne     SHORT $LL27@replace_if
$LN17@replace_if:
        ret     0
void replace_if_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; replace_if_epi8
