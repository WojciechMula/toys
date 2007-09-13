bits 32

global dotprod_SSE

segment .data align=16

mask
     dd 0xffffffff ; x
     dd 0xffffffff ; y
     dd 0xffffffff ; z
     dd 0x00000000 ; w

segment .text

; edi -> float[4]
; esi -> float[4]
; edx -> float[4]
dotprod_SSE:
	push ebp
	mov  ebp, esp

	push edi
	push esi
	push edx

	mov edi, [ebp+8]
	mov esi, [ebp+12]
	mov edx, [ebp+16]

	movups xmm0, [edi]	; xmm0 = |  w1 |  z1 |  y1 |  x1 |
	movups xmm1, [esi]	; xmm1 = |  w2 |  z2 |  y2 |  x2 |
	movups xmm2, [mask]	; xmm2 = |00000|11111|11111|11111|
	
	andps  xmm0, xmm2	; xmm0 = | 0.0 | z1  | y1  |  x1 |
	mulps  xmm0, xmm1	; xmm0 = |w1*w2|z1*z2|y1*y2|x1*x2|

	movaps xmm1, xmm0
	shufps xmm1, xmm1, 0eh	; xmm1 = |  nu |  nu |w1*w2|z1*z2|
	addps  xmm0, xmm1	; xmm0 = |  nu |  nu | w+y | z+x |

	movaps xmm1, xmm0
	shufps xmm1, xmm1, 01h	; xmm1 = |  nu |  nu |  nu | w+y |
	addss  xmm0, xmm1	; xmm0 -- wynik

	movups [edx], xmm0
	
	pop edx
	pop esi
	pop edi
	pop ebp
	ret