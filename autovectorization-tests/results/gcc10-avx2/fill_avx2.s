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
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	cmpq	%rsi, %rdx
	je	.L12
	leaq	-4(%rsi), %rcx
	movq	%rdx, %rax
	subq	%rdx, %rcx
	movq	%rcx, %rdi
	shrq	$2, %rdi
	addq	$1, %rdi
	cmpq	$24, %rcx
	jbe	.L7
	movq	%rdi, %rcx
	vmovdqa	.LC0(%rip), %ymm0
	shrq	$3, %rcx
	salq	$5, %rcx
	addq	%rdx, %rcx
	.p2align 4,,10
	.p2align 3
.L8:
	vmovdqu	%xmm0, (%rax)
	vextracti128	$0x1, %ymm0, 16(%rax)
	addq	$32, %rax
	cmpq	%rcx, %rax
	jne	.L8
	movq	%rdi, %rax
	andq	$-8, %rax
	leaq	(%rdx,%rax,4), %rdx
	cmpq	%rax, %rdi
	je	.L11
	vzeroupper
.L7:
	leaq	4(%rdx), %rax
	movl	$42, (%rdx)
	cmpq	%rax, %rsi
	je	.L12
	leaq	8(%rdx), %rax
	movl	$42, 4(%rdx)
	cmpq	%rax, %rsi
	je	.L12
	leaq	12(%rdx), %rax
	movl	$42, 8(%rdx)
	cmpq	%rax, %rsi
	je	.L12
	leaq	16(%rdx), %rax
	movl	$42, 12(%rdx)
	cmpq	%rax, %rsi
	je	.L12
	leaq	20(%rdx), %rax
	movl	$42, 16(%rdx)
	cmpq	%rax, %rsi
	je	.L12
	leaq	24(%rdx), %rax
	movl	$42, 20(%rdx)
	cmpq	%rax, %rsi
	je	.L12
	movl	$42, 24(%rdx)
.L12:
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	.cfi_restore_state
	vzeroupper
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1354:
	.size	_Z10fill_epi32RSt6vectorIiSaIiEE, .-_Z10fill_epi32RSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
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
