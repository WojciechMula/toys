_x$ = 8                                       ; size = 1
int <lambda_c07f4741c6ba1968dfccda49f97a3adb>::operator()(signed char)const  PROC ; <lambda_c07f4741c6ba1968dfccda49f97a3adb>::operator(), COMDAT
        movsx   eax, BYTE PTR _x$[esp-4]
        add     eax, 42                             ; 0000002aH
        ret     4
int <lambda_c07f4741c6ba1968dfccda49f97a3adb>::operator()(signed char)const  ENDP ; <lambda_c07f4741c6ba1968dfccda49f97a3adb>::operator()

_x$ = 8                                       ; size = 4
int <lambda_001dde25d8afb13db2b8523cb52741fc>::operator()(int)const  PROC ; <lambda_001dde25d8afb13db2b8523cb52741fc>::operator(), COMDAT
        mov     eax, DWORD PTR _x$[esp-4]
        add     eax, 42                             ; 0000002aH
        ret     4
int <lambda_001dde25d8afb13db2b8523cb52741fc>::operator()(int)const  ENDP ; <lambda_001dde25d8afb13db2b8523cb52741fc>::operator()

_v$ = 8                                       ; size = 4
void transform_inc_epi32(std::vector<int,std::allocator<int> > &) PROC ; transform_inc_epi32, COMDAT
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
        je      SHORT $LN31@transform_
        cmp     esi, 64                             ; 00000040H
        jb      SHORT $LN31@transform_
        lea     ecx, DWORD PTR [eax-4]
        lea     ecx, DWORD PTR [ecx+esi*4]
        cmp     eax, ecx
        jbe     SHORT $LN31@transform_
        mov     ecx, 42                             ; 0000002aH
        and     esi, -64                      ; ffffffc0H
        vpbroadcastd zmm1, ecx
$LL24@transform_:
        vpaddd  zmm0, zmm1, ZMMWORD PTR [eax]
        vmovdqu32 ZMMWORD PTR [edx], zmm0
        vpaddd  zmm0, zmm1, ZMMWORD PTR [eax+64]
        vmovdqu32 ZMMWORD PTR [edx+64], zmm0
        vpaddd  zmm0, zmm1, ZMMWORD PTR [eax+128]
        vmovdqu32 ZMMWORD PTR [edx+128], zmm0
        vpaddd  zmm0, zmm1, ZMMWORD PTR [eax+192]
        vmovdqu32 ZMMWORD PTR [edx+192], zmm0
        add     ebx, 64                             ; 00000040H
        add     edx, 256                      ; 00000100H
        add     eax, 256                      ; 00000100H
        cmp     ebx, esi
        jne     SHORT $LL24@transform_
$LN31@transform_:
        cmp     eax, edi
        je      SHORT $LN23@transform_
        sub     edx, eax
$LL30@transform_:
        mov     ecx, DWORD PTR [eax]
        add     ecx, 42                             ; 0000002aH
        mov     DWORD PTR [edx+eax], ecx
        add     eax, 4
        cmp     eax, edi
        jne     SHORT $LL30@transform_
$LN23@transform_:
        pop     edi
        pop     esi
        pop     ebx
        vzeroupper
        ret     0
void transform_inc_epi32(std::vector<int,std::allocator<int> > &) ENDP ; transform_inc_epi32

_v$ = 8                                       ; size = 4
void transform_inc_epi8(std::vector<signed char,std::allocator<signed char> > &) PROC ; transform_inc_epi8, COMDAT
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
        mov     cl, 42                                    ; 0000002aH
        and     esi, -256               ; ffffff00H
        movzx   ecx, cl
        vpbroadcastb zmm1, ecx
$LL24@transform_:
        vpaddb  zmm0, zmm1, ZMMWORD PTR [eax]
        vmovdqu32 ZMMWORD PTR [edx], zmm0
        vpaddb  zmm0, zmm1, ZMMWORD PTR [eax+64]
        vmovdqu32 ZMMWORD PTR [edx+64], zmm0
        vpaddb  zmm0, zmm1, ZMMWORD PTR [eax+128]
        vmovdqu32 ZMMWORD PTR [edx+128], zmm0
        vpaddb  zmm0, zmm1, ZMMWORD PTR [eax+192]
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
        add     cl, 42                                    ; 0000002aH
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
void transform_inc_epi8(std::vector<signed char,std::allocator<signed char> > &) ENDP ; transform_inc_epi8
