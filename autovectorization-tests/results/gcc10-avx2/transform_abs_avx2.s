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
	je	.L11
	leaq	-1(%rcx), %r8
	movq	%rcx, %rsi
	movq	%rdx, %rax
	subq	%rdx, %r8
	subq	%rdx, %rsi
	cmpq	$30, %r8
	jbe	.L8
	movq	%rsi, %rdi
	andq	$-32, %rdi
	addq	%rdx, %rdi
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu	(%rax), %xmm1
	vinserti128	$0x1, 16(%rax), %ymm1, %ymm0
	addq	$32, %rax
	vpabsb	%ymm0, %ymm0
	vmovdqu	%xmm0, -32(%rax)
	vextracti128	$0x1, %ymm0, -16(%rax)
	cmpq	%rdi, %rax
	jne	.L4
	movq	%rsi, %rdi
	andq	$-32, %rdi
	leaq	(%rdx,%rdi), %rax
	cmpq	%rdi, %rsi
	je	.L13
	vzeroupper
.L3:
	subq	%rdi, %r8
	subq	%rdi, %rsi
	cmpq	$14, %r8
	jbe	.L6
	addq	%rdi, %rdx
	vpabsb	(%rdx), %xmm0
	vmovdqu	%xmm0, (%rdx)
	movq	%rsi, %rdx
	andq	$-16, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %rsi
	je	.L11
.L6:
	movzbl	(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, (%rax)
	subb	%dl, (%rax)
	leaq	1(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	1(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 1(%rax)
	subb	%dl, 1(%rax)
	leaq	2(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	2(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 2(%rax)
	subb	%dl, 2(%rax)
	leaq	3(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	3(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 3(%rax)
	subb	%dl, 3(%rax)
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	4(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 4(%rax)
	subb	%dl, 4(%rax)
	leaq	5(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	5(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 5(%rax)
	subb	%dl, 5(%rax)
	leaq	6(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	6(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 6(%rax)
	subb	%dl, 6(%rax)
	leaq	7(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	7(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 7(%rax)
	subb	%dl, 7(%rax)
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	8(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 8(%rax)
	subb	%dl, 8(%rax)
	leaq	9(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	9(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 9(%rax)
	subb	%dl, 9(%rax)
	leaq	10(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	10(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 10(%rax)
	subb	%dl, 10(%rax)
	leaq	11(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	11(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 11(%rax)
	subb	%dl, 11(%rax)
	leaq	12(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	12(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 12(%rax)
	subb	%dl, 12(%rax)
	leaq	13(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	13(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 13(%rax)
	subb	%dl, 13(%rax)
	leaq	14(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L11
	movzbl	14(%rax), %edx
	sarb	$7, %dl
	xorb	%dl, 14(%rax)
	subb	%dl, 14(%rax)
.L11:
	ret
.L8:
	xorl	%edi, %edi
	jmp	.L3
.L13:
	vzeroupper
	ret
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
	je	.L24
	leaq	-4(%rdi), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdx
	movq	%rdx, %r8
	shrq	$2, %r8
	leaq	1(%r8), %rcx
	cmpq	$24, %rdx
	jbe	.L21
	movq	%rcx, %rdx
	shrq	$3, %rdx
	salq	$5, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L17:
	vmovdqu	(%rax), %xmm2
	vinserti128	$0x1, 16(%rax), %ymm2, %ymm0
	addq	$32, %rax
	vpabsd	%ymm0, %ymm0
	vmovdqu	%xmm0, -32(%rax)
	vextracti128	$0x1, %ymm0, -16(%rax)
	cmpq	%rax, %rdx
	jne	.L17
	movq	%rcx, %rdx
	andq	$-8, %rdx
	leaq	(%rsi,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L25
	vzeroupper
.L16:
	subq	%rdx, %r8
	subq	%rdx, %rcx
	cmpq	$2, %r8
	jbe	.L19
	leaq	(%rsi,%rdx,4), %rdx
	vpabsd	(%rdx), %xmm0
	vmovdqu	%xmm0, (%rdx)
	movq	%rcx, %rdx
	andq	$-4, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L24
.L19:
	vmovd	(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	4(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, (%rax)
	cmpq	%rdx, %rdi
	je	.L24
	vmovd	4(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	leaq	8(%rax), %rdx
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 4(%rax)
	cmpq	%rdx, %rdi
	je	.L24
	vmovd	8(%rax), %xmm0
	vpxor	%xmm1, %xmm1, %xmm1
	vpsubd	%xmm0, %xmm1, %xmm1
	vpmaxsd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, 8(%rax)
.L24:
	ret
	.p2align 4,,10
	.p2align 3
.L25:
	vzeroupper
	ret
.L21:
	xorl	%edx, %edx
	jmp	.L16
	.cfi_endproc
.LFE1357:
	.size	_Z19transform_abs_epi32RSt6vectorIiSaIiEE, .-_Z19transform_abs_epi32RSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
