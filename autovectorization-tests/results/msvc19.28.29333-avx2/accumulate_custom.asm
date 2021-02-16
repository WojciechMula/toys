_a$ = 8                                       ; size = 1
_b$ = 12                                                ; size = 1
int <lambda_d9ce0fa66cc4512040f4e4474a7a5f4e>::operator()(signed char,signed char)const  PROC ; <lambda_d9ce0fa66cc4512040f4e4474a7a5f4e>::operator(), COMDAT
        movsx   eax, BYTE PTR _a$[esp-4]
        movsx   ecx, BYTE PTR _b$[esp-4]
        sub     eax, ecx
        ret     8
int <lambda_d9ce0fa66cc4512040f4e4474a7a5f4e>::operator()(signed char,signed char)const  ENDP ; <lambda_d9ce0fa66cc4512040f4e4474a7a5f4e>::operator()

_a$ = 8                                       ; size = 4
_b$ = 12                                                ; size = 4
int <lambda_bbf72e9468240e08a91e9a4835a8b82d>::operator()(int,int)const  PROC ; <lambda_bbf72e9468240e08a91e9a4835a8b82d>::operator(), COMDAT
        mov     eax, DWORD PTR _a$[esp-4]
        sub     eax, DWORD PTR _b$[esp-4]
        ret     8
int <lambda_bbf72e9468240e08a91e9a4835a8b82d>::operator()(int,int)const  ENDP ; <lambda_bbf72e9468240e08a91e9a4835a8b82d>::operator()

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
        cmp     eax, 16                             ; 00000010H
        jb      SHORT $LN21@accumulate
        and     eax, -16                      ; fffffff0H
        vpxor   xmm0, xmm0, xmm0
        vpxor   xmm1, xmm1, xmm1
        npad    11
$LL14@accumulate:
        vpsubd  ymm0, ymm0, YMMWORD PTR [ecx]
        vpsubd  ymm1, ymm1, YMMWORD PTR [ecx+32]
        add     esi, 16                             ; 00000010H
        add     ecx, 64                             ; 00000040H
        cmp     esi, eax
        jne     SHORT $LL14@accumulate
        vpaddd  ymm0, ymm0, ymm1
        vphaddd ymm0, ymm0, ymm0
        vphaddd ymm1, ymm0, ymm0
        vextracti128 xmm0, ymm1, 1
        vpaddd  xmm0, xmm1, xmm0
        vmovd   edx, xmm0
$LN21@accumulate:
        cmp     ecx, edi
        je      SHORT $LN27@accumulate
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
