	.file	"transform_inc.cpp"
	.text
	.p2align 4
	.globl	_Z18transform_inc_epi8RSt6vectorIaSaIaEE
	.type	_Z18transform_inc_epi8RSt6vectorIaSaIaEE, @function
_Z18transform_inc_epi8RSt6vectorIaSaIaEE:
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
	vmovdqa	.LC0(%rip), %ymm1
	andq	$-32, %rdi
	addq	%rdx, %rdi
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu	(%rax), %xmm2
	vinserti128	$0x1, 16(%rax), %ymm2, %ymm0
	addq	$32, %rax
	vpaddb	%ymm1, %ymm0, %ymm0
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
	vmovdqa	.LC1(%rip), %xmm0
	vpaddb	(%rdx), %xmm0, %xmm0
	vmovdqu	%xmm0, (%rdx)
	movq	%rsi, %rdx
	andq	$-16, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %rsi
	je	.L11
.L6:
	leaq	1(%rax), %rdx
	addb	$42, (%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	2(%rax), %rdx
	addb	$42, 1(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	3(%rax), %rdx
	addb	$42, 2(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	4(%rax), %rdx
	addb	$42, 3(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	5(%rax), %rdx
	addb	$42, 4(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	6(%rax), %rdx
	addb	$42, 5(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	7(%rax), %rdx
	addb	$42, 6(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	8(%rax), %rdx
	addb	$42, 7(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	9(%rax), %rdx
	addb	$42, 8(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	10(%rax), %rdx
	addb	$42, 9(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	11(%rax), %rdx
	addb	$42, 10(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	12(%rax), %rdx
	addb	$42, 11(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	13(%rax), %rdx
	addb	$42, 12(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	leaq	14(%rax), %rdx
	addb	$42, 13(%rax)
	cmpq	%rdx, %rcx
	je	.L11
	addb	$42, 14(%rax)
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
	.size	_Z18transform_inc_epi8RSt6vectorIaSaIaEE, .-_Z18transform_inc_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z19transform_inc_epi32RSt6vectorIiSaIiEE
	.type	_Z19transform_inc_epi32RSt6vectorIiSaIiEE, @function
_Z19transform_inc_epi32RSt6vectorIiSaIiEE:
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
	vmovdqa	.LC2(%rip), %ymm1
	shrq	$3, %rdx
	salq	$5, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L17:
	vmovdqu	(%rax), %xmm2
	vinserti128	$0x1, 16(%rax), %ymm2, %ymm0
	addq	$32, %rax
	vpaddd	%ymm0, %ymm1, %ymm0
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
	vmovdqa	.LC3(%rip), %xmm0
	vpaddd	(%rdx), %xmm0, %xmm0
	vmovdqu	%xmm0, (%rdx)
	movq	%rcx, %rdx
	andq	$-4, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L24
.L19:
	leaq	4(%rax), %rdx
	addl	$42, (%rax)
	cmpq	%rdx, %rdi
	je	.L24
	leaq	8(%rax), %rdx
	addl	$42, 4(%rax)
	cmpq	%rdx, %rdi
	je	.L24
	addl	$42, 8(%rax)
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
	.size	_Z19transform_inc_epi32RSt6vectorIiSaIiEE, .-_Z19transform_inc_epi32RSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC1:
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.section	.rodata.cst32
	.align 32
.LC2:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.section	.rodata.cst16
	.align 16
.LC3:
	.long	42
	.long	42
	.long	42
	.long	42
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
