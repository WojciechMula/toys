_x$ = 8                                       ; size = 1
int <lambda_b961ac9dca32e245ad7c3bf10969bcc3>::operator()(signed char)const  PROC ; <lambda_b961ac9dca32e245ad7c3bf10969bcc3>::operator(), COMDAT
        movsx   eax, BYTE PTR _x$[esp-4]
        neg     eax
        ret     4
int <lambda_b961ac9dca32e245ad7c3bf10969bcc3>::operator()(signed char)const  ENDP ; <lambda_b961ac9dca32e245ad7c3bf10969bcc3>::operator()

_x$ = 8                                       ; size = 4
int <lambda_30572cd3855b56bd1f49cceb7feff3dc>::operator()(int)const  PROC ; <lambda_30572cd3855b56bd1f49cceb7feff3dc>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        neg     eax
        ret     4
int <lambda_30572cd3855b56bd1f49cceb7feff3dc>::operator()(int)const  ENDP ; <lambda_30572cd3855b56bd1f49cceb7feff3dc>::operator()

_v$ = 8                                       ; size = 4
void transform_neg_epi32(std::vector<int,std::allocator<int> > &) PROC ; transform_neg_epi32, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     eax, DWORD PTR [ecx]
        mov     esi, edi
        sub     esi, eax
        xor     ecx, ecx
        add     esi, 3
        mov     edx, eax
        shr     esi, 2
        cmp     eax, edi
        cmova   esi, ecx
        test    esi, esi
        je      SHORT $LN33@transform_
        cmp     esi, 32                             ; 00000020H
        jb      SHORT $LN33@transform_
        lea     ecx, DWORD PTR [eax-4]
        lea     ecx, DWORD PTR [ecx+esi*4]
        cmp     eax, ecx
        jbe     SHORT $LN33@transform_
        and     esi, -32                      ; ffffffe0H
        npad    9
$LL24@transform_:
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  ymm0, ymm0, YMMWORD PTR [eax]
        vmovdqu YMMWORD PTR [edx], ymm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  ymm0, ymm0, YMMWORD PTR [eax+32]
        vmovdqu YMMWORD PTR [edx+32], ymm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  ymm0, ymm0, YMMWORD PTR [eax+64]
        vmovdqu YMMWORD PTR [edx+64], ymm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  ymm0, ymm0, YMMWORD PTR [eax+96]
        vmovdqu YMMWORD PTR [edx+96], ymm0
        add     ebx, 32                             ; 00000020H
        sub     edx, -128               ; ffffff80H
        sub     eax, -128               ; ffffff80H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
        npad    7
$LL32@transform_:
        mov     ecx, DWORD PTR [eax]
        neg     ecx
        mov     DWORD PTR [edx+eax], ecx
        add     eax, 4
        cmp     eax, edi
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_neg_epi32(std::vector<int,std::allocator<int> > &) ENDP ; transform_neg_epi32

_v$ = 8                                       ; size = 4
void transform_neg_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; transform_neg_epi8, COMDAT
        mov     ecx, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [ecx+4]
        xor     ebx, ebx
        mov     eax, DWORD PTR [ecx]
        mov     esi, edi
        sub     esi, eax
        xor     ecx, ecx
        cmp     eax, edi
        mov     edx, eax
        cmova   esi, ecx
        test    esi, esi
        je      SHORT $LN33@transform_
        cmp     esi, 128                      ; 00000080H
        jb      SHORT $LN33@transform_
        lea     ecx, DWORD PTR [eax-1]
        add     ecx, esi
        cmp     eax, ecx
        jbe     SHORT $LN33@transform_
        and     esi, -128               ; ffffff80H
$LL24@transform_:
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  ymm0, ymm0, YMMWORD PTR [eax]
        vmovdqu YMMWORD PTR [edx], ymm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  ymm0, ymm0, YMMWORD PTR [eax+32]
        vmovdqu YMMWORD PTR [edx+32], ymm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  ymm0, ymm0, YMMWORD PTR [eax+64]
        vmovdqu YMMWORD PTR [edx+64], ymm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  ymm0, ymm0, YMMWORD PTR [eax+96]
        vmovdqu YMMWORD PTR [edx+96], ymm0
        sub     ebx, -128               ; ffffff80H
        sub     edx, -128               ; ffffff80H
        sub     eax, -128               ; ffffff80H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
        npad    4
$LL32@transform_:
        mov     cl, BYTE PTR [eax]
        neg     cl
        mov     BYTE PTR [edx+eax], cl
        inc     eax
        cmp     eax, edi
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_neg_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; transform_neg_epi8
