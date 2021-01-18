	.file	"replace.cpp"
	.text
	.p2align 4
	.globl	_Z12replace_epi8RSt6vectorIaSaIaEE
	.type	_Z12replace_epi8RSt6vectorIaSaIaEE, @function
_Z12replace_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rdx
	cmpq	%rcx, %rdx
	je	.L23
	leaq	-1(%rcx), %r8
	movq	%rcx, %rsi
	movq	%rdx, %rax
	subq	%rdx, %r8
	subq	%rdx, %rsi
	cmpq	$62, %r8
	jbe	.L13
	vmovdqa64	.LC0(%rip), %zmm0
	movq	%rsi, %rdi
	vmovdqa64	.LC1(%rip), %zmm1
	andq	$-64, %rdi
	addq	%rdx, %rdi
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L4:
	addq	$64, %rax
	cmpq	%rdi, %rax
	je	.L25
.L5:
	vmovdqu8	(%rax), %zmm3
	vpcmpb	$0, %zmm0, %zmm3, %k1
	kortestq	%k1, %k1
	je	.L4
	vmovdqu8	%zmm1, (%rax){%k1}
	addq	$64, %rax
	cmpq	%rdi, %rax
	jne	.L5
	.p2align 4,,10
	.p2align 3
.L25:
	movq	%rsi, %rdi
	andq	$-64, %rdi
	leaq	(%rdx,%rdi), %rax
	cmpq	%rdi, %rsi
	je	.L22
.L3:
	subq	%rdi, %r8
	subq	%rdi, %rsi
	cmpq	$30, %r8
	jbe	.L11
	addq	%rdi, %rdx
	vmovdqu8	(%rdx), %xmm2
	vinserti128	$0x1, 16(%rdx), %ymm2, %ymm0
	vpcmpb	$0, .LC2(%rip), %ymm0, %k1
	kortestd	%k1, %k1
	jne	.L26
.L8:
	movq	%rsi, %rdx
	andq	$-32, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %rsi
	je	.L22
	.p2align 4,,10
	.p2align 3
.L11:
	cmpb	$13, (%rax)
	jne	.L12
	movb	$42, (%rax)
.L12:
	addq	$1, %rax
	cmpq	%rax, %rcx
	jne	.L11
.L22:
	vzeroupper
.L23:
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	vmovdqa	.LC3(%rip), %ymm0
	vmovdqu8	%ymm0, (%rdx){%k1}
	jmp	.L8
.L13:
	xorl	%edi, %edi
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z12replace_epi8RSt6vectorIaSaIaEE, .-_Z12replace_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z13replace_epi32RSt6vectorIiSaIiEE
	.type	_Z13replace_epi32RSt6vectorIiSaIiEE, @function
_Z13replace_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rdi
	cmpq	%rcx, %rdi
	je	.L68
	movq	%rcx, %rsi
	leaq	-4(%rcx), %rdx
	movq	%rdi, %rax
	subq	%rdi, %rsi
	subq	%rdi, %rdx
	andl	$3, %esi
	jne	.L53
	cmpq	$24, %rdx
	jbe	.L53
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rsi
	cmpq	$56, %rdx
	jbe	.L46
	vmovdqa32	.LC4(%rip), %zmm0
	movq	%rsi, %r8
	xorl	%edx, %edx
	vmovdqa32	.LC5(%rip), %zmm1
	shrq	$4, %r8
	jmp	.L32
	.p2align 4,,10
	.p2align 3
.L31:
	addq	$1, %rdx
	addq	$64, %rax
	cmpq	%rdx, %r8
	jbe	.L69
.L32:
	vmovdqu32	(%rax), %zmm3
	vpcmpd	$0, %zmm0, %zmm3, %k1
	kortestw	%k1, %k1
	je	.L31
	addq	$1, %rdx
	vmovdqu32	%zmm1, (%rax){%k1}
	addq	$64, %rax
	cmpq	%rdx, %r8
	ja	.L32
.L69:
	movq	%rsi, %rdx
	andq	$-16, %rdx
	leaq	(%rdi,%rdx,4), %rax
	cmpq	%rdx, %rsi
	je	.L67
.L30:
	subq	%rdx, %r9
	subq	%rdx, %rsi
	cmpq	$6, %r9
	jbe	.L34
	leaq	(%rdi,%rdx,4), %rdx
	vmovdqu8	(%rdx), %xmm2
	vinserti128	$0x1, 16(%rdx), %ymm2, %ymm0
	vpcmpd	$0, .LC6(%rip), %ymm0, %k1
	kortestb	%k1, %k1
	jne	.L70
.L35:
	movq	%rsi, %rdx
	andq	$-8, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rsi
	je	.L67
.L34:
	cmpl	$13, (%rax)
	je	.L71
.L37:
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L67
	cmpl	$13, 4(%rax)
	je	.L72
.L38:
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L67
	cmpl	$13, 8(%rax)
	je	.L73
.L39:
	leaq	12(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L67
	cmpl	$13, 12(%rax)
	je	.L74
	leaq	16(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L67
.L76:
	cmpl	$13, 16(%rax)
	jne	.L41
	movl	$42, 16(%rax)
.L41:
	leaq	20(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L67
	cmpl	$13, 20(%rax)
	jne	.L42
	movl	$42, 20(%rax)
.L42:
	leaq	24(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L67
	cmpl	$13, 24(%rax)
	je	.L75
.L67:
	vzeroupper
.L68:
	ret
	.p2align 4,,10
	.p2align 3
.L53:
	cmpl	$13, (%rax)
	jne	.L45
	movl	$42, (%rax)
.L45:
	addq	$4, %rax
	cmpq	%rcx, %rax
	jne	.L53
	ret
	.p2align 4,,10
	.p2align 3
.L71:
	movl	$42, (%rax)
	jmp	.L37
	.p2align 4,,10
	.p2align 3
.L72:
	movl	$42, 4(%rax)
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L73:
	movl	$42, 8(%rax)
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L70:
	vmovdqa	.LC7(%rip), %ymm0
	vmovdqu32	%ymm0, (%rdx){%k1}
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L74:
	leaq	16(%rax), %rdx
	movl	$42, 12(%rax)
	cmpq	%rdx, %rcx
	jne	.L76
	jmp	.L67
	.p2align 4,,10
	.p2align 3
.L75:
	movl	$42, 24(%rax)
	vzeroupper
	ret
.L46:
	xorl	%edx, %edx
	jmp	.L30
	.cfi_endproc
.LFE1354:
	.size	_Z13replace_epi32RSt6vectorIiSaIiEE, .-_Z13replace_epi32RSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.align 64
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
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC2:
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.align 32
.LC3:
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
	.section	.rodata
	.align 64
.LC4:
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.align 64
.LC5:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.section	.rodata.cst32
	.align 32
.LC6:
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.align 32
.LC7:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
