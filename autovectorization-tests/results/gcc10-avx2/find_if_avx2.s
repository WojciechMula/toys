	.file	"find_if.cpp"
	.text
	.p2align 4
	.globl	_Z12find_if_epi8RKSt6vectorIaSaIaEE
	.type	_Z12find_if_epi8RKSt6vectorIaSaIaEE, @function
_Z12find_if_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rax
	movq	%rsi, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rdx
	sarq	$2, %rdx
	testq	%rdx, %rdx
	jle	.L2
	leaq	(%rax,%rdx,4), %rcx
	.p2align 4,,10
	.p2align 3
.L12:
	movsbl	(%rax), %edx
	cmpl	$42, %edx
	je	.L36
	cmpl	$-1, %edx
	je	.L36
	movsbl	1(%rax), %edx
	cmpl	$42, %edx
	je	.L21
	cmpl	$-1, %edx
	je	.L21
	movsbl	2(%rax), %edx
	cmpl	$42, %edx
	je	.L22
	cmpl	$-1, %edx
	je	.L22
	movsbl	3(%rax), %edx
	cmpl	$42, %edx
	je	.L23
	cmpl	$-1, %edx
	je	.L23
	addq	$4, %rax
	cmpq	%rax, %rcx
	jne	.L12
	movq	%rsi, %rcx
	subq	%rax, %rcx
.L2:
	cmpq	$2, %rcx
	je	.L13
	cmpq	$3, %rcx
	je	.L14
	xorl	%r8d, %r8d
	cmpq	$1, %rcx
	jne	.L1
.L15:
	movsbl	(%rax), %edx
	cmpl	$42, %edx
	sete	%r8b
	cmpl	$-1, %edx
	sete	%dl
	orb	%dl, %r8b
	je	.L1
	.p2align 4,,10
	.p2align 3
.L36:
	cmpq	%rax, %rsi
	setne	%r8b
.L1:
	movl	%r8d, %eax
	ret
.L14:
	movsbl	(%rax), %edx
	cmpl	$42, %edx
	je	.L36
	cmpl	$-1, %edx
	je	.L36
	addq	$1, %rax
.L13:
	movsbl	(%rax), %edx
	cmpl	$42, %edx
	je	.L36
	cmpl	$-1, %edx
	je	.L36
	addq	$1, %rax
	jmp	.L15
	.p2align 4,,10
	.p2align 3
.L21:
	addq	$1, %rax
	cmpq	%rax, %rsi
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L22:
	addq	$2, %rax
	cmpq	%rax, %rsi
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	addq	$3, %rax
	cmpq	%rax, %rsi
	setne	%r8b
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z12find_if_epi8RKSt6vectorIaSaIaEE, .-_Z12find_if_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z13find_if_epi32RKSt6vectorIiSaIiEE
	.type	_Z13find_if_epi32RKSt6vectorIiSaIiEE, @function
_Z13find_if_epi32RKSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rax
	movq	%rsi, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rdx
	sarq	$4, %rcx
	sarq	$2, %rdx
	testq	%rcx, %rcx
	jle	.L39
	salq	$4, %rcx
	addq	%rax, %rcx
	.p2align 4,,10
	.p2align 3
.L49:
	movl	(%rax), %edx
	cmpl	$42, %edx
	je	.L73
	cmpl	$-1, %edx
	je	.L73
	movl	4(%rax), %edx
	cmpl	$42, %edx
	je	.L58
	cmpl	$-1, %edx
	je	.L58
	movl	8(%rax), %edx
	cmpl	$42, %edx
	je	.L59
	cmpl	$-1, %edx
	je	.L59
	movl	12(%rax), %edx
	cmpl	$42, %edx
	je	.L60
	cmpl	$-1, %edx
	je	.L60
	addq	$16, %rax
	cmpq	%rax, %rcx
	jne	.L49
	movq	%rsi, %rdx
	subq	%rax, %rdx
	sarq	$2, %rdx
.L39:
	cmpq	$2, %rdx
	je	.L50
	cmpq	$3, %rdx
	je	.L51
	xorl	%r8d, %r8d
	cmpq	$1, %rdx
	jne	.L38
.L52:
	movl	(%rax), %edx
	cmpl	$42, %edx
	sete	%r8b
	cmpl	$-1, %edx
	sete	%dl
	orb	%dl, %r8b
	je	.L38
	.p2align 4,,10
	.p2align 3
.L73:
	cmpq	%rax, %rsi
	setne	%r8b
.L38:
	movl	%r8d, %eax
	ret
.L51:
	movl	(%rax), %edx
	cmpl	$42, %edx
	je	.L73
	cmpl	$-1, %edx
	je	.L73
	addq	$4, %rax
.L50:
	movl	(%rax), %edx
	cmpl	$42, %edx
	je	.L73
	cmpl	$-1, %edx
	je	.L73
	addq	$4, %rax
	jmp	.L52
	.p2align 4,,10
	.p2align 3
.L58:
	addq	$4, %rax
	cmpq	%rax, %rsi
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L59:
	addq	$8, %rax
	cmpq	%rax, %rsi
	setne	%r8b
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L60:
	addq	$12, %rax
	cmpq	%rax, %rsi
	setne	%r8b
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1357:
	.size	_Z13find_if_epi32RKSt6vectorIiSaIiEE, .-_Z13find_if_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
