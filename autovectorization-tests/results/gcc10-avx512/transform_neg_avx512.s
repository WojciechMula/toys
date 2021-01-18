	.file	"transform_neg.cpp"
	.text
	.p2align 4
	.globl	_Z18transform_neg_epi8RSt6vectorIaSaIaEE
	.type	_Z18transform_neg_epi8RSt6vectorIaSaIaEE, @function
_Z18transform_neg_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	(%rdi), %rdx
	movq	8(%rdi), %rcx
	cmpq	%rdx, %rcx
	je	.L13
	leaq	-1(%rcx), %r8
	movq	%rcx, %rsi
	movq	%rdx, %rax
	subq	%rdx, %r8
	subq	%rdx, %rsi
	cmpq	$62, %r8
	jbe	.L9
	movq	%rsi, %rdi
	vpxor	%xmm2, %xmm2, %xmm2
	vmovdqa64	.LC0(%rip), %zmm3
	andq	$-64, %rdi
	addq	%rdx, %rdi
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu8	(%rax), %zmm5
	vpmovsxbw	(%rax), %zmm1
	addq	$64, %rax
	vextracti64x4	$0x1, %zmm5, %ymm0
	vpsubw	%zmm1, %zmm2, %zmm1
	vpmovsxbw	%ymm0, %zmm0
	vpsubw	%zmm0, %zmm2, %zmm0
	vpermt2b	%zmm0, %zmm3, %zmm1
	vmovdqu8	%zmm1, -64(%rax)
	cmpq	%rdi, %rax
	jne	.L4
	movq	%rsi, %rdi
	andq	$-64, %rdi
	leaq	(%rdx,%rdi), %rax
	cmpq	%rdi, %rsi
	je	.L12
.L3:
	subq	%rdi, %r8
	subq	%rdi, %rsi
	cmpq	$30, %r8
	jbe	.L8
	addq	%rdi, %rdx
	vpxor	%xmm2, %xmm2, %xmm2
	vmovdqu8	(%rdx), %xmm4
	vinserti128	$0x1, 16(%rdx), %ymm4, %ymm1
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxbw	%xmm4, %ymm0
	vpmovsxbw	%xmm1, %ymm1
	vpsubw	%ymm0, %ymm2, %ymm0
	vpsubw	%ymm1, %ymm2, %ymm1
	vmovdqa	.LC1(%rip), %ymm2
	vpand	%ymm0, %ymm2, %ymm0
	vpand	%ymm1, %ymm2, %ymm2
	vpackuswb	%ymm2, %ymm0, %ymm0
	vpermq	$216, %ymm0, %ymm0
	vmovdqu8	%xmm0, (%rdx)
	vextracti128	$0x1, %ymm0, 16(%rdx)
	movq	%rsi, %rdx
	andq	$-32, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %rsi
	je	.L12
	.p2align 4,,10
	.p2align 3
.L8:
	negb	(%rax)
	addq	$1, %rax
	cmpq	%rax, %rcx
	jne	.L8
.L12:
	vzeroupper
.L13:
	ret
.L9:
	xorl	%edi, %edi
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z18transform_neg_epi8RSt6vectorIaSaIaEE, .-_Z18transform_neg_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z19transform_neg_epi32RSt6vectorIiSaIiEE
	.type	_Z19transform_neg_epi32RSt6vectorIiSaIiEE, @function
_Z19transform_neg_epi32RSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	(%rdi), %rsi
	movq	8(%rdi), %rdi
	cmpq	%rsi, %rdi
	je	.L31
	leaq	-4(%rdi), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdx
	movq	%rdx, %r8
	shrq	$2, %r8
	leaq	1(%r8), %rcx
	cmpq	$56, %rdx
	jbe	.L22
	movq	%rcx, %rdx
	vpxor	%xmm1, %xmm1, %xmm1
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L18:
	vpsubd	(%rax), %zmm1, %zmm0
	addq	$64, %rax
	vmovdqu32	%zmm0, -64(%rax)
	cmpq	%rdx, %rax
	jne	.L18
	movq	%rcx, %rdx
	andq	$-16, %rdx
	leaq	(%rsi,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L30
.L17:
	subq	%rdx, %r8
	subq	%rdx, %rcx
	cmpq	$6, %r8
	jbe	.L20
	leaq	(%rsi,%rdx,4), %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu8	(%rdx), %xmm2
	vinserti128	$0x1, 16(%rdx), %ymm2, %ymm1
	vpsubd	%ymm1, %ymm0, %ymm0
	vmovdqu8	%xmm0, (%rdx)
	vextracti128	$0x1, %ymm0, 16(%rdx)
	movq	%rcx, %rdx
	andq	$-8, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L30
.L20:
	leaq	4(%rax), %rdx
	negl	(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	8(%rax), %rdx
	negl	4(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	12(%rax), %rdx
	negl	8(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	16(%rax), %rdx
	negl	12(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	20(%rax), %rdx
	negl	16(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	24(%rax), %rdx
	negl	20(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	negl	24(%rax)
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	vzeroupper
.L31:
	ret
.L22:
	xorl	%edx, %edx
	jmp	.L17
	.cfi_endproc
.LFE1357:
	.size	_Z19transform_neg_epi32RSt6vectorIiSaIiEE, .-_Z19transform_neg_epi32RSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
	.byte	0
	.byte	2
	.byte	4
	.byte	6
	.byte	8
	.byte	10
	.byte	12
	.byte	14
	.byte	16
	.byte	18
	.byte	20
	.byte	22
	.byte	24
	.byte	26
	.byte	28
	.byte	30
	.byte	32
	.byte	34
	.byte	36
	.byte	38
	.byte	40
	.byte	42
	.byte	44
	.byte	46
	.byte	48
	.byte	50
	.byte	52
	.byte	54
	.byte	56
	.byte	58
	.byte	60
	.byte	62
	.byte	64
	.byte	66
	.byte	68
	.byte	70
	.byte	72
	.byte	74
	.byte	76
	.byte	78
	.byte	80
	.byte	82
	.byte	84
	.byte	86
	.byte	88
	.byte	90
	.byte	92
	.byte	94
	.byte	96
	.byte	98
	.byte	100
	.byte	102
	.byte	104
	.byte	106
	.byte	108
	.byte	110
	.byte	112
	.byte	114
	.byte	116
	.byte	118
	.byte	120
	.byte	122
	.byte	124
	.byte	126
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC1:
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
