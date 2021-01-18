	.file	"all_of.cpp"
	.text
	.p2align 4
	.globl	_Z11all_of_epi8RKSt6vectorIaSaIaEE
	.type	_Z11all_of_epi8RKSt6vectorIaSaIaEE, @function
_Z11all_of_epi8RKSt6vectorIaSaIaEE:
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
	jne	.L24
	cmpb	$42, 2(%rax)
	jne	.L25
	cmpb	$42, 3(%rax)
	jne	.L26
	addq	$4, %rax
	cmpq	%rax, %rdx
	je	.L27
.L8:
	cmpb	$42, (%rax)
	je	.L3
.L22:
	cmpq	%rax, %rcx
	sete	%r8b
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
	movl	$1, %r8d
	cmpq	$1, %rsi
	jne	.L1
.L11:
	cmpb	$42, (%rax)
	movl	$1, %r8d
	jne	.L22
	jmp	.L1
.L10:
	cmpb	$42, (%rax)
	jne	.L22
	addq	$1, %rax
.L9:
	cmpb	$42, (%rax)
	jne	.L22
	addq	$1, %rax
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L24:
	addq	$1, %rax
	cmpq	%rax, %rcx
	sete	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L25:
	addq	$2, %rax
	cmpq	%rax, %rcx
	sete	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	addq	$3, %rax
	cmpq	%rax, %rcx
	sete	%r8b
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z11all_of_epi8RKSt6vectorIaSaIaEE, .-_Z11all_of_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z12all_of_epi32RKSt6vectorIiSaIiEE
	.type	_Z12all_of_epi32RKSt6vectorIiSaIiEE, @function
_Z12all_of_epi32RKSt6vectorIiSaIiEE:
.LFB1357:
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
	jne	.L50
	cmpl	$42, 8(%rax)
	jne	.L51
	cmpl	$42, 12(%rax)
	jne	.L52
	addq	$16, %rax
	cmpq	%rax, %rdx
	je	.L53
.L35:
	cmpl	$42, (%rax)
	je	.L30
.L49:
	cmpq	%rax, %rcx
	sete	%r8b
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
	movl	$1, %r8d
	cmpq	$1, %rsi
	jne	.L28
.L38:
	cmpl	$42, (%rax)
	movl	$1, %r8d
	jne	.L49
	jmp	.L28
.L37:
	cmpl	$42, (%rax)
	jne	.L49
	addq	$4, %rax
.L36:
	cmpl	$42, (%rax)
	jne	.L49
	addq	$4, %rax
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L50:
	addq	$4, %rax
	cmpq	%rax, %rcx
	sete	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L51:
	addq	$8, %rax
	cmpq	%rax, %rcx
	sete	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	addq	$12, %rax
	cmpq	%rax, %rcx
	sete	%r8b
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1357:
	.size	_Z12all_of_epi32RKSt6vectorIiSaIiEE, .-_Z12all_of_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
