	.file	"is_sorted.cpp"
	.text
	.p2align 4
	.globl	_Z14is_sorted_epi8RKSt6vectorIaSaIaEE
	.type	_Z14is_sorted_epi8RKSt6vectorIaSaIaEE, @function
_Z14is_sorted_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	movl	$1, %r8d
	cmpq	%rsi, %rdx
	je	.L1
	leaq	1(%rdx), %rax
	cmpq	%rsi, %rax
	je	.L1
	movzbl	(%rdx), %edx
	jmp	.L4
	.p2align 4,,10
	.p2align 3
.L3:
	addq	$1, %rax
	cmpq	%rax, %rsi
	je	.L9
.L4:
	movl	%edx, %ecx
	movzbl	(%rax), %edx
	cmpb	%dl, %cl
	jle	.L3
	cmpq	%rax, %rsi
	sete	%r8b
.L1:
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	movl	$1, %r8d
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z14is_sorted_epi8RKSt6vectorIaSaIaEE, .-_Z14is_sorted_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z15is_sorted_epi32RKSt6vectorIiSaIiEE
	.type	_Z15is_sorted_epi32RKSt6vectorIiSaIiEE, @function
_Z15is_sorted_epi32RKSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	movl	$1, %r8d
	cmpq	%rsi, %rdx
	je	.L10
	leaq	4(%rdx), %rax
	cmpq	%rsi, %rax
	je	.L10
	movl	(%rdx), %edx
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L12:
	addq	$4, %rax
	cmpq	%rax, %rsi
	je	.L17
.L13:
	movl	%edx, %ecx
	movl	(%rax), %edx
	cmpl	%edx, %ecx
	jle	.L12
	cmpq	%rax, %rsi
	sete	%r8b
.L10:
	movl	%r8d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	movl	$1, %r8d
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE1354:
	.size	_Z15is_sorted_epi32RKSt6vectorIiSaIiEE, .-_Z15is_sorted_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
