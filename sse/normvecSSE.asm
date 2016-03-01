bits 32

global normvec_SSE

segment .text

; extern void normvec_SSE(float* v);
normvec_SSE:
	push ebp
	mov ebp, esp

	push esi
	mov esi, [ebp+8 + 0*4]
	
	movups xmm0, [esi] ; za³aduj wektor
	
	movaps xmm1, xmm0  ; xmm1 = |  0  |  z  |  y  |  x  |
	mulps  xmm1, xmm0  ; xmm1 = |  0  | z*z | y*y | x*x |
	
	movaps xmm2, xmm1
	movaps xmm3, xmm1

	shufps xmm2, xmm1, 0fdh ; xmm2 = |  0  |  0  |  0  | y^2 |
	shufps xmm3, xmm1, 0feh ; xmm3 = |  0  |  0  |  0  | z^2 |
	
	addss  xmm1, xmm2       ;
	addss  xmm1, xmm3       ; xmm1 = |  0  |  nu |  nu | x^2+y^2+z^2 |
	sqrtss xmm1, xmm1       ; xmm1 = |  0  |  nu | nu | sqrt(x^2+y^2+z^2) |
				;                                  len
	
	shufps xmm1, xmm1, 000h ; xmm1 = | len | len | len | len |
	
	divps  xmm0, xmm1       ; xmm0 = |  0  |z/len|y/len|x/len| -- wynik
	
	movups [esi], xmm0

	pop esi
	pop ebp
	ret

; eof