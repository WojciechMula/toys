	.file	"replace.cpp"
	.text
	.p2align 4
	.globl	_Z12replace_epi8RSt6vectorIaSaIaEE
	.type	_Z12replace_epi8RSt6vectorIaSaIaEE, @function
_Z12replace_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rdx
	movq	(%rdi), %rax
	cmpq	%rdx, %rax
	je	.L6
	.p2align 4,,10
	.p2align 3
.L4:
	cmpb	$13, (%rax)
	jne	.L3
	movb	$42, (%rax)
.L3:
	addq	$1, %rax
	cmpq	%rdx, %rax
	jne	.L4
.L6:
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z12replace_epi8RSt6vectorIaSaIaEE, .-_Z12replace_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z13replace_epi32RSt6vectorIiSaIiEE
	.type	_Z13replace_epi32RSt6vectorIiSaIiEE, @function
_Z13replace_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %rsi
	cmpq	%rdi, %rsi
	je	.L32
	movq	%rdi, %rcx
	leaq	-4(%rdi), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rcx
	subq	%rsi, %rdx
	andl	$3, %ecx
	jne	.L26
	cmpq	$8, %rdx
	jbe	.L26
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rcx
	cmpq	$24, %rdx
	jbe	.L23
	movq	%rcx, %r8
	vmovdqa	.LC0(%rip), %ymm1
	vmovdqa	.LC1(%rip), %ymm2
	xorl	%edx, %edx
	shrq	$3, %r8
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L12:
	addq	$1, %rdx
	addq	$32, %rax
	cmpq	%rdx, %r8
	jbe	.L33
.L13:
	vmovdqu	(%rax), %xmm3
	vinserti128	$0x1, 16(%rax), %ymm3, %ymm0
	vpcmpeqd	%ymm0, %ymm1, %ymm0
	vptest	%ymm0, %ymm0
	je	.L12
	addq	$1, %rdx
	vpmaskmovd	%ymm2, %ymm0, (%rax)
	addq	$32, %rax
	cmpq	%rdx, %r8
	ja	.L13
.L33:
	movq	%rcx, %rdx
	andq	$-8, %rdx
	leaq	(%rsi,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L34
	vzeroupper
.L11:
	subq	%rdx, %r9
	subq	%rdx, %rcx
	cmpq	$2, %r9
	jbe	.L15
	vmovdqa	.LC2(%rip), %xmm0
	leaq	(%rsi,%rdx,4), %rdx
	vpcmpeqd	(%rdx), %xmm0, %xmm0
	vptest	%xmm0, %xmm0
	jne	.L35
.L16:
	movq	%rcx, %rdx
	andq	$-4, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L32
.L15:
	cmpl	$13, (%rax)
	je	.L36
.L18:
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L32
	cmpl	$13, 4(%rax)
	je	.L37
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.L32
.L39:
	cmpl	$13, 8(%rax)
	je	.L38
.L32:
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	cmpl	$13, (%rax)
	jne	.L22
	movl	$42, (%rax)
.L22:
	addq	$4, %rax
	cmpq	%rdi, %rax
	jne	.L26
	ret
	.p2align 4,,10
	.p2align 3
.L36:
	movl	$42, (%rax)
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L35:
	vmovdqa	.LC3(%rip), %xmm1
	vpmaskmovd	%xmm1, %xmm0, (%rdx)
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L37:
	leaq	8(%rax), %rdx
	movl	$42, 4(%rax)
	cmpq	%rdx, %rdi
	jne	.L39
	jmp	.L32
	.p2align 4,,10
	.p2align 3
.L38:
	movl	$42, 8(%rax)
	ret
	.p2align 4,,10
	.p2align 3
.L34:
	vzeroupper
	ret
.L23:
	xorl	%edx, %edx
	jmp	.L11
	.cfi_endproc
.LFE1354:
	.size	_Z13replace_epi32RSt6vectorIiSaIiEE, .-_Z13replace_epi32RSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.long	13
	.align 32
.LC1:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC2:
	.long	13
	.long	13
	.long	13
	.long	13
	.align 16
.LC3:
	.long	42
	.long	42
	.long	42
	.long	42
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
