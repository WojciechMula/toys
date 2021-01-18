	.file	"transform_abs.cpp"
	.text
	.p2align 4
	.globl	_Z18transform_abs_epi8RSt6vectorIaSaIaEE
	.type	_Z18transform_abs_epi8RSt6vectorIaSaIaEE, @function
_Z18transform_abs_epi8RSt6vectorIaSaIaEE:
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
	andq	$-64, %rdi
	addq	%rdx, %rdi
	.p2align 4,,10
	.p2align 3
.L4:
	vpabsb	(%rax), %zmm0
	addq	$64, %rax
	vmovdqu8	%zmm0, -64(%rax)
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
	vmovdqu8	(%rdx), %xmm1
	vinserti128	$0x1, 16(%rdx), %ymm1, %ymm0
	vpabsb	%ymm0, %ymm0
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
	movzbl	(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, (%rax)
	subb	%dl, (%rax)
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
	.size	_Z18transform_abs_epi8RSt6vectorIaSaIaEE, .-_Z18transform_abs_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z19transform_abs_epi32RSt6vectorIiSaIiEE
	.type	_Z19transform_abs_epi32RSt6vectorIiSaIiEE, @function
_Z19transform_abs_epi32RSt6vectorIiSaIiEE:
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
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L18:
	vpabsd	(%rax), %zmm0
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
	vmovdqu8	(%rdx), %xmm2
	vinserti128	$0x1, 16(%rdx), %ymm2, %ymm0
	vpabsd	%ymm0, %ymm0
	vmovdqu8	%xmm0, (%rdx)
	vextracti128	$0x1, %ymm0, 16(%rdx)
	movq	%rcx, %rdx
	andq	$-8, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L30
.L20:
	vmovd	(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	4(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, (%rax)
	cmpq	%rdx, %rdi
	je	.L30
	vmovd	4(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	8(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 4(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	vmovd	8(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	12(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 8(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	vmovd	12(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	16(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 12(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	vmovd	16(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	20(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 16(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	vmovd	20(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	24(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 20(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	vmovd	24(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 24(%rax)
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
	.size	_Z19transform_abs_epi32RSt6vectorIiSaIiEE, .-_Z19transform_abs_epi32RSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
