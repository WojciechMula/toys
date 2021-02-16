_x$ = 8                                       ; size = 1
int <lambda_aef477b5112c5bc789d750d6e9e25197>::operator()(signed char)const  PROC ; <lambda_aef477b5112c5bc789d750d6e9e25197>::operator(), COMDAT
        movsx   eax, BYTE PTR _x$[esp-4]
        cdq
        xor     eax, edx
        sub     eax, edx
        ret     4
int <lambda_aef477b5112c5bc789d750d6e9e25197>::operator()(signed char)const  ENDP ; <lambda_aef477b5112c5bc789d750d6e9e25197>::operator()

_x$ = 8                                       ; size = 4
int <lambda_21a8e6427fe49c1429ea01155035878e>::operator()(int)const  PROC ; <lambda_21a8e6427fe49c1429ea01155035878e>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        cdq
        xor     eax, edx
        sub     eax, edx
        ret     4
int <lambda_21a8e6427fe49c1429ea01155035878e>::operator()(int)const  ENDP ; <lambda_21a8e6427fe49c1429ea01155035878e>::operator()

_v$ = 8                                       ; size = 4
void transform_abs_epi32(std::vector<int,std::allocator<int> > &) PROC ; transform_abs_epi32, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     ebx, DWORD PTR [eax+4]
        xor     edi, edi
        mov     ecx, DWORD PTR [eax]
        mov     edx, ebx
        sub     edx, ecx
        xor     eax, eax
        add     edx, 3
        mov     esi, ecx
        shr     edx, 2
        cmp     ecx, ebx
        cmova   edx, eax
        test    edx, edx
        je      SHORT $LN33@transform_
        cmp     edx, 64                             ; 00000040H
        jb      SHORT $LN33@transform_
        lea     eax, DWORD PTR [ecx-4]
        lea     eax, DWORD PTR [eax+edx*4]
        cmp     ecx, eax
        jbe     SHORT $LN33@transform_
        and     edx, -64                      ; ffffffc0H
        npad    9
$LL24@transform_:
        vpabsd  zmm0, ZMMWORD PTR [ecx]
        vmovdqu32 ZMMWORD PTR [esi], zmm0
        vpabsd  zmm0, ZMMWORD PTR [ecx+64]
        vmovdqu32 ZMMWORD PTR [esi+64], zmm0
        vpabsd  zmm0, ZMMWORD PTR [ecx+128]
        vmovdqu32 ZMMWORD PTR [esi+128], zmm0
        vpabsd  zmm0, ZMMWORD PTR [ecx+192]
        vmovdqu32 ZMMWORD PTR [esi+192], zmm0
        add     edi, 64                             ; 00000040H
        add     esi, 256                      ; 00000100H
        add     ecx, 256                      ; 00000100H
        cmp     edi, edx
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     ecx, ebx
        je      SHORT $LN23@transform_
        sub     esi, ecx
        npad    1
$LL32@transform_:
        mov     eax, DWORD PTR [ecx]
        cdq
        xor     eax, edx
        sub     eax, edx
        mov     DWORD PTR [esi+ecx], eax
        add     ecx, 4
        cmp     ecx, ebx
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_abs_epi32(std::vector<int,std::allocator<int> > &) ENDP ; transform_abs_epi32

_v$ = 8                                       ; size = 4
void transform_abs_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; transform_abs_epi8, COMDAT
        mov     eax, DWORD PTR _v$[esp-4]
        push    ebx
        push    esi
        push    edi
        mov     edi, DWORD PTR [eax+4]
        xor     ebx, ebx
        mov     ecx, DWORD PTR [eax]
        mov     edx, edi
        sub     edx, ecx
        xor     eax, eax
        cmp     ecx, edi
        mov     esi, ecx
        cmova   edx, eax
        test    edx, edx
        je      SHORT $LN33@transform_
        cmp     edx, 64                             ; 00000040H
        jb      SHORT $LN33@transform_
        lea     eax, DWORD PTR [ecx-1]
        add     eax, edx
        cmp     ecx, eax
        jbe     SHORT $LN33@transform_
        and     edx, -64                      ; ffffffc0H
$LL24@transform_:
        vpmovsxbd zmm0, XMMWORD PTR [ecx]
        vpabsd  zmm0, zmm0
        vpmovdb xmm0, zmm0
        vmovdqu XMMWORD PTR [esi], xmm0
        vpmovsxbd zmm0, XMMWORD PTR [ecx+16]
        vpabsd  zmm0, zmm0
        vpmovdb xmm0, zmm0
        vmovdqu XMMWORD PTR [esi+16], xmm0
        vpmovsxbd zmm0, XMMWORD PTR [ecx+32]
        vpabsd  zmm0, zmm0
        vpmovdb xmm0, zmm0
        vmovdqu XMMWORD PTR [esi+32], xmm0
        vpmovsxbd zmm0, XMMWORD PTR [ecx+48]
        vpabsd  zmm0, zmm0
        vpmovdb xmm0, zmm0
        vmovdqu XMMWORD PTR [esi+48], xmm0
        add     ebx, 64                             ; 00000040H
        add     esi, 64                             ; 00000040H
        add     ecx, 64                             ; 00000040H
        cmp     ebx, edx
        jne     SHORT $LL24@transform_
$LN33@transform_:
        cmp     ecx, edi
        je      SHORT $LN23@transform_
        sub     esi, ecx
$LL32@transform_:
        movsx   eax, BYTE PTR [ecx]
        cdq
        xor     eax, edx
        sub     eax, edx
        mov     BYTE PTR [esi+ecx], al
        inc     ecx
        cmp     ecx, edi
        jne     SHORT $LL32@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_abs_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; transform_abs_epi8
