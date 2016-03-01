; 11.03.2002
;
; |i j k|
; |a b c| = i(b*z-c*y) - j(a*z-c*x) + k(a*y-b*x)
; |x y z|
;
;         = [b*z - c*y, c*x - a*z, a*y - b*x] =
;
;         = [b*z, c*x, a*y] - [c*y, a*z, b*x]
;
; i,j,k - wersory osi
;
; w uk³. kartezjañskim i=[1,0,0], j=[0,1,0], oraz k=[0,0,1]

bits 32

global vecprod_SSE

segment .text

; extern void vecprod_SSE(float *v1, float *v2, float *vp);
vecprod_SSE:
	push ebp
	mov ebp, esp

	push edi
	push esi
	push edx

	mov edi, [ebp+8 + 0*4]
	mov esi, [ebp+8 + 1*4]
	mov edx, [ebp+8 + 2*4]
	
	movups xmm0, [edi] ; xmm0 = | 0 | c | b | a |
	movups xmm1, [esi] ; xmm1 = | 0 | z | y | x |
	
	movaps xmm2, xmm0
	movaps xmm3, xmm1
	
	shufps xmm0, xmm0, 0d8h ; xmm0 = | 0 | b | c | a |
	shufps xmm1, xmm1, 0e1h ; xmm1 = | 0 | z | x | y |
	mulps  xmm0, xmm1       ; xmm0 = | 0 |bz |cx |ay |
	
	shufps xmm2, xmm2, 0e1h ; xmm2 = | 0 | c | a | b |
	shufps xmm3, xmm3, 0d8h ; xmm3 = | 0 | y | z | x |
	mulps  xmm2, xmm3       ; xmm3 = | 0 |cy |az |bx |
	
	subps  xmm0, xmm2       ; xmm0 -- wynik
	
	movups [edx], xmm0
	
	pop edx
	pop esi
	pop edi
	
	pop ebp
	ret

; eof