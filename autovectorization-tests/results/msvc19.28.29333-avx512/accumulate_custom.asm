_a$ = 8                                       ; size = 1
_b$ = 12                                                ; size = 1
int <lambda_33f3fe1bea049687d63b94c1218fab25>::operator()(signed char,signed char)const  PROC ; <lambda_33f3fe1bea049687d63b94c1218fab25>::operator(), COMDAT
        movsx   eax, BYTE PTR _a$[esp-4]
        movsx   ecx, BYTE PTR _b$[esp-4]
        sub     eax, ecx
        ret     8
int <lambda_33f3fe1bea049687d63b94c1218fab25>::operator()(signed char,signed char)const  ENDP ; <lambda_33f3fe1bea049687d63b94c1218fab25>::operator()

_a$ = 8                                       ; size = 4
_b$ = 12                                                ; size = 4
int <lambda_e5ab7ffcb189447d90320b79702d5c58>::operator()(int,int)const  PROC ; <lambda_e5ab7ffcb189447d90320b79702d5c58>::operator(), COMDAT
        mov     eax, DWORD PTR _a$[esp-4]
        sub     eax, DWORD PTR _b$[esp-4]
        ret     8
int <lambda_e5ab7ffcb189447d90320b79702d5c58>::operator()(int,int)const  ENDP ; <lambda_e5ab7ffcb189447d90320b79702d5c58>::operator()

_v$ = 8                                       ; size = 4
unsigned int accumulate_custom_epi32(std::vector<int,std::allocator<int> > const &) PROC ; accumulate_custom_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        xor     edx, edx
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [ecx]
        mov     eax, edi
        sub     eax, ecx
        xor     esi, esi
        add     eax, 3
        shr     eax, 2
        cmp     ecx, edi
        cmova   eax, ebx
        test    eax, eax
        je      SHORT $LN21@accumulate
        cmp     eax, 32                             ; 00000020H
        jb      SHORT $LN21@accumulate
        vpbroadcastd zmm0, edx
        and     eax, -32                      ; ffffffe0H
        vmovdqu32 zmm1, zmm0
        npad    7
$LL14@accumulate:
        vpsubd  zmm0, zmm0, ZMMWORD PTR [ecx]
        vpsubd  zmm1, zmm1, ZMMWORD PTR [ecx+64]
        add     esi, 32                             ; 00000020H
        sub     ecx, -128               ; ffffff80H
        cmp     esi, eax
        jne     SHORT $LL14@accumulate
        vpaddd  zmm1, zmm0, zmm1
        vextracti32x8 ymm0, zmm1, 1
        vpaddd  ymm1, ymm0, ymm1
        vextracti32x4 xmm0, ymm1, 1
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 8
        vpaddd  xmm1, xmm0, xmm1
        vpsrldq xmm0, xmm1, 4
        vpaddd  xmm0, xmm0, xmm1
        vmovd   edx, xmm0
$LN21@accumulate:
        cmp     ecx, edi
        je      SHORT $LN27@accumulate
        npad    3
$LL20@accumulate:
        sub     edx, DWORD PTR [ecx]
        add     ecx, 4
        cmp     ecx, edi
        jne     SHORT $LL20@accumulate
$LN27@accumulate:
        pop     edi
        pop     esi
        mov     eax, edx
        pop     ebx
        vzeroupper
        ret     0
unsigned int accumulate_custom_epi32(std::vector<int,std::allocator<int> > const &) ENDP ; accumulate_custom_epi32

_v$ = 8                                       ; size = 4
unsigned int accumulate_custom_epi8(std::vector<signed char,std::allocator<signed char> > const &) PROC ; accumulate_custom_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        xor     eax, eax
        push    esi
        mov     esi, DWORD PTR [ecx+4]
        mov     edx, DWORD PTR [ecx]
        cmp     edx, esi
        je      SHORT $LN13@accumulate
$LL14@accumulate:
        movsx   ecx, BYTE PTR [edx]
        inc     edx
        movsx   eax, al
        sub     eax, ecx
        cmp     edx, esi
        jne     SHORT $LL14@accumulate
$LN13@accumulate:
        pop     esi
        ret     0
unsigned int accumulate_custom_epi8(std::vector<signed char,std::allocator<signed char> > const &) ENDP ; accumulate_custom_epi8
