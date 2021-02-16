_x$ = 8                                       ; size = 4
bool <lambda_b04b230afa1f9f4d5d61ec8317e156ba>::operator()(int)const  PROC ; <lambda_b04b230afa1f9f4d5d61ec8317e156ba>::operator(), COMDAT
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
bool <lambda_b04b230afa1f9f4d5d61ec8317e156ba>::operator()(int)const  ENDP ; <lambda_b04b230afa1f9f4d5d61ec8317e156ba>::operator()

_x$ = 8                                       ; size = 4
bool <lambda_1ca96eb0ae177b0888bc5941a2950080>::operator()(int)const  PROC ; <lambda_1ca96eb0ae177b0888bc5941a2950080>::operator(), COMDAT
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
bool <lambda_1ca96eb0ae177b0888bc5941a2950080>::operator()(int)const  ENDP ; <lambda_1ca96eb0ae177b0888bc5941a2950080>::operator()

_v$ = 8                                       ; size = 4
unsigned int count_if_epi32(std::vector<int,std::allocator<int> > const &) PROC ; count_if_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        push    edi
        xor     esi, esi
        mov     edi, DWORD PTR [eax+4]
        mov     ecx, DWORD PTR [eax]
        cmp     ecx, edi
        je      SHORT $LN30@count_if_e
$LL23@count_if_e:
        mov     eax, DWORD PTR [ecx]
        cmp     eax, 42                             ; 0000002aH
        je      SHORT $LN24@count_if_e
        cmp     eax, -1
        je      SHORT $LN24@count_if_e
        xor     dl, dl
        jmp     SHORT $LN25@count_if_e
$LN24@count_if_e:
        mov     dl, 1
$LN25@count_if_e:
        test    dl, dl
        lea     eax, DWORD PTR [esi+1]
        cmove   eax, esi
        add     ecx, 4
        mov     esi, eax
        cmp     ecx, edi
        jne     SHORT $LL23@count_if_e
$LN30@count_if_e:
        pop     edi
        mov     eax, esi
        pop     esi
        ret     0
unsigned int count_if_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; count_if_epi32

_v$ = 8                                       ; size = 4
unsigned int count_if_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; count_if_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    esi
        push    edi
        xor     esi, esi
        mov     edi, DWORD PTR [eax+4]
        mov     ecx, DWORD PTR [eax]
        cmp     ecx, edi
        je      SHORT $LN30@count_if_e
$LL23@count_if_e:
        movsx   eax, BYTE PTR [ecx]
        cmp     eax, 42                             ; 0000002aH
        je      SHORT $LN24@count_if_e
        cmp     eax, -1
        je      SHORT $LN24@count_if_e
        xor     dl, dl
        jmp     SHORT $LN25@count_if_e
$LN24@count_if_e:
        mov     dl, 1
$LN25@count_if_e:
        test    dl, dl
        lea     eax, DWORD PTR [esi+1]
        cmove   eax, esi
        inc     ecx
        mov     esi, eax
        cmp     ecx, edi
        jne     SHORT $LL23@count_if_e
$LN30@count_if_e:
        pop     edi
        mov     eax, esi
        pop     esi
        ret     0
unsigned int count_if_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; count_if_epi8
