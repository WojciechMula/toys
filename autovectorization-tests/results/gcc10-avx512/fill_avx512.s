	.file	"fill.cpp"
	.text
	.p2align 4
	.globl	_Z9fill_epi8RSt6vectorIaSaIaEE
	.type	_Z9fill_epi8RSt6vectorIaSaIaEE, @function
_Z9fill_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rdx
	movq	(%rdi), %rdi
	cmpq	%rdx, %rdi
	je	.L3
	subq	%rdi, %rdx
	movl	$42, %esi
	jmp	memset@PLT
	.p2align 4,,10
	.p2align 3
.L3:
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z9fill_epi8RSt6vectorIaSaIaEE, .-_Z9fill_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z10fill_epi32RSt6vectorIiSaIiEE
	.type	_Z10fill_epi32RSt6vectorIiSaIiEE, @function
_Z10fill_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %rcx
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	cmpq	%rdi, %rcx
	je	.L21
	leaq	-4(%rdi), %rdx
	movq	%rcx, %rax
	subq	%rcx, %rdx
	movq	%rdx, %r8
	shrq	$2, %r8
	leaq	1(%r8), %rsi
	cmpq	$56, %rdx
	jbe	.L12
	vmovdqa32	.LC0(%rip), %zmm0
	movq	%rsi, %rdx
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rcx, %rdx
	.p2align 4,,10
	.p2align 3
.L8:
	vmovdqu32	%zmm0, (%rax)
	addq	$64, %rax
	cmpq	%rdx, %rax
	jne	.L8
	movq	%rsi, %rdx
	andq	$-16, %rdx
	leaq	(%rcx,%rdx,4), %rax
	cmpq	%rdx, %rsi
	je	.L20
.L7:
	subq	%rdx, %r8
	subq	%rdx, %rsi
	cmpq	$6, %r8
	jbe	.L10
	vmovdqa	.LC1(%rip), %ymm0
	vmovdqu8	%xmm0, (%rcx,%rdx,4)
	vextracti128	$0x1, %ymm0, 16(%rcx,%rdx,4)
	movq	%rsi, %rdx
	andq	$-8, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rsi
	je	.L20
.L10:
	leaq	4(%rax), %rdx
	movl	$42, (%rax)
	cmpq	%rdx, %rdi
	je	.L20
	leaq	8(%rax), %rdx
	movl	$42, 4(%rax)
	cmpq	%rdx, %rdi
	je	.L20
	leaq	12(%rax), %rdx
	movl	$42, 8(%rax)
	cmpq	%rdx, %rdi
	je	.L20
	leaq	16(%rax), %rdx
	movl	$42, 12(%rax)
	cmpq	%rdx, %rdi
	je	.L20
	leaq	20(%rax), %rdx
	movl	$42, 16(%rax)
	cmpq	%rdx, %rdi
	je	.L20
	leaq	24(%rax), %rdx
	movl	$42, 20(%rax)
	cmpq	%rdx, %rdi
	je	.L20
	movl	$42, 24(%rax)
	vzeroupper
.L21:
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L20:
	.cfi_restore_state
	vzeroupper
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L12:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	.L7
	.cfi_endproc
.LFE1354:
	.size	_Z10fill_epi32RSt6vectorIiSaIiEE, .-_Z10fill_epi32RSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
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
	.section	.rodata.cst32,"aM",@progbits,32
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
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
