	.file	"find.cpp"
	.text
	.p2align 4
	.globl	_Z9find_epi8RKSt6vectorIaSaIaEE
	.type	_Z9find_epi8RKSt6vectorIaSaIaEE, @function
_Z9find_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rax
	movq	%rcx, %rsi
	subq	%rax, %rsi
	movq	%rsi, %rdx
	sarq	$2, %rdx
	testq	%rdx, %rdx
	jle	.L2
	leaq	(%rax,%rdx,4), %rdx
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L3:
	cmpb	$42, 1(%rax)
	je	.L24
	cmpb	$42, 2(%rax)
	je	.L25
	cmpb	$42, 3(%rax)
	je	.L26
	addq	$4, %rax
	cmpq	%rdx, %rax
	je	.L27
.L8:
	cmpb	$42, (%rax)
	jne	.L3
.L22:
	cmpq	%rax, %rcx
	setne	%r8b
.L1:
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L27:
	movq	%rcx, %rsi
	subq	%rax, %rsi
.L2:
	cmpq	$2, %rsi
	je	.L9
	cmpq	$3, %rsi
	je	.L10
	xorl	%r8d, %r8d
	cmpq	$1, %rsi
	jne	.L1
.L11:
	xorl	%r8d, %r8d
	cmpb	$42, (%rax)
	jne	.L1
	jmp	.L22
.L10:
	cmpb	$42, (%rax)
	je	.L22
	addq	$1, %rax
.L9:
	cmpb	$42, (%rax)
	je	.L22
	addq	$1, %rax
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L24:
	addq	$1, %rax
	cmpq	%rax, %rcx
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L25:
	addq	$2, %rax
	cmpq	%rax, %rcx
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	addq	$3, %rax
	cmpq	%rax, %rcx
	setne	%r8b
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z9find_epi8RKSt6vectorIaSaIaEE, .-_Z9find_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z10find_epi32RKSt6vectorIiSaIiEE
	.type	_Z10find_epi32RKSt6vectorIiSaIiEE, @function
_Z10find_epi32RKSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rax
	movq	%rcx, %rdx
	subq	%rax, %rdx
	movq	%rdx, %rsi
	sarq	$4, %rdx
	sarq	$2, %rsi
	testq	%rdx, %rdx
	jle	.L29
	salq	$4, %rdx
	addq	%rax, %rdx
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L30:
	cmpl	$42, 4(%rax)
	je	.L50
	cmpl	$42, 8(%rax)
	je	.L51
	cmpl	$42, 12(%rax)
	je	.L52
	addq	$16, %rax
	cmpq	%rdx, %rax
	je	.L53
.L35:
	cmpl	$42, (%rax)
	jne	.L30
.L49:
	cmpq	%rax, %rcx
	setne	%r8b
.L28:
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L53:
	movq	%rcx, %rsi
	subq	%rax, %rsi
	sarq	$2, %rsi
.L29:
	cmpq	$2, %rsi
	je	.L36
	cmpq	$3, %rsi
	je	.L37
	xorl	%r8d, %r8d
	cmpq	$1, %rsi
	jne	.L28
.L38:
	xorl	%r8d, %r8d
	cmpl	$42, (%rax)
	jne	.L28
	jmp	.L49
.L37:
	cmpl	$42, (%rax)
	je	.L49
	addq	$4, %rax
.L36:
	cmpl	$42, (%rax)
	je	.L49
	addq	$4, %rax
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L50:
	addq	$4, %rax
	cmpq	%rax, %rcx
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L51:
	addq	$8, %rax
	cmpq	%rax, %rcx
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	addq	$12, %rax
	cmpq	%rax, %rcx
	setne	%r8b
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1354:
	.size	_Z10find_epi32RKSt6vectorIiSaIiEE, .-_Z10find_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
