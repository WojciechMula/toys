_x$ = 8                                       ; size = 1
int <lambda_8f53ed9c4a99a3b4acb6d8c9e08d2835>::operator()(signed char)const  PROC ; <lambda_8f53ed9c4a99a3b4acb6d8c9e08d2835>::operator(), COMDAT
        movsx   eax, BYTE PTR _x$[esp-4]
        neg     eax
        ret     4
int <lambda_8f53ed9c4a99a3b4acb6d8c9e08d2835>::operator()(signed char)const  ENDP ; <lambda_8f53ed9c4a99a3b4acb6d8c9e08d2835>::operator()

_x$ = 8                                       ; size = 4
int <lambda_7849b560375db7e925c372d823166a5f>::operator()(int)const  PROC ; <lambda_7849b560375db7e925c372d823166a5f>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        neg     eax
        ret     4
int <lambda_7849b560375db7e925c372d823166a5f>::operator()(int)const  ENDP ; <lambda_7849b560375db7e925c372d823166a5f>::operator()

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
        cmp     esi, 64                             ; 00000040H
        jb      SHORT $LN33@transform_
        lea     ecx, DWORD PTR [eax-4]
        lea     ecx, DWORD PTR [ecx+esi*4]
        cmp     eax, ecx
        jbe     SHORT $LN33@transform_
        and     esi, -64                      ; ffffffc0H
        npad    9
$LL24@transform_:
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  zmm0, zmm0, ZMMWORD PTR [eax]
        vmovdqu32 ZMMWORD PTR [edx], zmm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  zmm0, zmm0, ZMMWORD PTR [eax+64]
        vmovdqu32 ZMMWORD PTR [edx+64], zmm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  zmm0, zmm0, ZMMWORD PTR [eax+128]
        vmovdqu32 ZMMWORD PTR [edx+128], zmm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubd  zmm0, zmm0, ZMMWORD PTR [eax+192]
        vmovdqu32 ZMMWORD PTR [edx+192], zmm0
        add     ebx, 64                             ; 00000040H
        add     edx, 256                      ; 00000100H
        add     eax, 256                      ; 00000100H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
        npad    2
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
        cmp     esi, 256                      ; 00000100H
        jb      SHORT $LN33@transform_
        lea     ecx, DWORD PTR [eax-1]
        add     ecx, esi
        cmp     eax, ecx
        jbe     SHORT $LN33@transform_
        and     esi, -256               ; ffffff00H
        npad    10
$LL24@transform_:
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  zmm0, zmm0, ZMMWORD PTR [eax]
        vmovdqu32 ZMMWORD PTR [edx], zmm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  zmm0, zmm0, ZMMWORD PTR [eax+64]
        vmovdqu32 ZMMWORD PTR [edx+64], zmm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  zmm0, zmm0, ZMMWORD PTR [eax+128]
        vmovdqu32 ZMMWORD PTR [edx+128], zmm0
        vxorpd  xmm0, xmm0, xmm0
        vpsubb  zmm0, zmm0, ZMMWORD PTR [eax+192]
        vmovdqu32 ZMMWORD PTR [edx+192], zmm0
        add     ebx, 256                      ; 00000100H
        add     edx, 256                      ; 00000100H
        add     eax, 256                      ; 00000100H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
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
