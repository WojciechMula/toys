_c$ = 8                                       ; size = 1
bool <lambda_9bbb52f3676869698f6f6e6ca6b17244>::operator()(signed char)const  PROC ; <lambda_9bbb52f3676869698f6f6e6ca6b17244>::operator(), COMDAT
        cmp     BYTE PTR _c$[esp-4], 42             ; 0000002aH
        setne   al
        ret     4
bool <lambda_9bbb52f3676869698f6f6e6ca6b17244>::operator()(signed char)const  ENDP ; <lambda_9bbb52f3676869698f6f6e6ca6b17244>::operator()

_c$ = 8                                       ; size = 1
bool <lambda_f855773cd7b1f9acdd2454dc846c141b>::operator()(signed char)const  PROC ; <lambda_f855773cd7b1f9acdd2454dc846c141b>::operator(), COMDAT
        cmp     BYTE PTR _c$[esp-4], 42             ; 0000002aH
        setne   al
        ret     4
bool <lambda_f855773cd7b1f9acdd2454dc846c141b>::operator()(signed char)const  ENDP ; <lambda_f855773cd7b1f9acdd2454dc846c141b>::operator()

_v$ = 8                                       ; size = 4
void remove_if_epi32(std::vector<int,std::allocator<int> > &) PROC ; remove_if_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        mov     esi, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, esi
        je      SHORT $LN17@remove_if_
        npad    2
$LL24@remove_if_:
        cmp     BYTE PTR [eax], 42                        ; 0000002aH
        jne     SHORT $LN39@remove_if_
        add     eax, 4
        cmp     eax, esi
        jne     SHORT $LL24@remove_if_
$LN39@remove_if_:
        cmp     eax, esi
        je      SHORT $LN17@remove_if_
        lea     edx, DWORD PTR [eax+4]
        cmp     edx, esi
        je      SHORT $LN17@remove_if_
$LL16@remove_if_:
        cmp     BYTE PTR [edx], 42                        ; 0000002aH
        jne     SHORT $LN19@remove_if_
        mov     ecx, DWORD PTR [edx]
        mov     DWORD PTR [eax], ecx
        add     eax, 4
$LN19@remove_if_:
        add     edx, 4
        cmp     edx, esi
        jne     SHORT $LL16@remove_if_
$LN17@remove_if_:
        pop     esi
        ret     0
void remove_if_epi32(std::vector<int,std::allocator<int> > &) ENDP ; remove_if_epi32

_v$ = 8                                       ; size = 4
void remove_if_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; remove_if_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        mov     edx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR [eax]
        cmp     eax, edx
        je      SHORT $LN17@remove_if_
        npad    3
$LL24@remove_if_:
        cmp     BYTE PTR [eax], 42                        ; 0000002aH
        jne     SHORT $LN33@remove_if_
        inc     eax
        cmp     eax, edx
        jne     SHORT $LL24@remove_if_
$LN33@remove_if_:
        cmp     eax, edx
        je      SHORT $LN17@remove_if_
        lea     ecx, DWORD PTR [eax+1]
        cmp     ecx, edx
        je      SHORT $LN17@remove_if_
$LL16@remove_if_:
        cmp     BYTE PTR [ecx], 42                        ; 0000002aH
        jne     SHORT $LN19@remove_if_
        mov     BYTE PTR [eax], 42                        ; 0000002aH
        inc     eax
$LN19@remove_if_:
        inc     ecx
        cmp     ecx, edx
        jne     SHORT $LL16@remove_if_
$LN17@remove_if_:
        ret     0
void remove_if_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; remove_if_epi8
