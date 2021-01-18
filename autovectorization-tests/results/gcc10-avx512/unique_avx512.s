	.file	"unique.cpp"
	.text
	.p2align 4
	.globl	_Z11unique_epi8RSt6vectorIaSaIaEE
	.type	_Z11unique_epi8RSt6vectorIaSaIaEE, @function
_Z11unique_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	cmpq	%rsi, %rdx
	jne	.L3
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L11:
	movzbl	-1(%rdx), %ecx
	cmpb	1(%rax), %cl
	je	.L10
.L3:
	movq	%rdx, %rax
	leaq	1(%rdx), %rdx
	cmpq	%rdx, %rsi
	jne	.L11
.L7:
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	cmpq	%rax, %rsi
	je	.L7
	leaq	2(%rax), %rdx
	cmpq	%rdx, %rsi
	jne	.L4
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L12:
	movzbl	(%rax), %ecx
.L4:
	movzbl	(%rdx), %edi
	cmpb	%dil, %cl
	je	.L5
	movb	%dil, 1(%rax)
	addq	$1, %rax
.L5:
	addq	$1, %rdx
	cmpq	%rsi, %rdx
	jne	.L12
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z11unique_epi8RSt6vectorIaSaIaEE, .-_Z11unique_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z12unique_epi32RSt6vectorIiSaIiEE
	.type	_Z12unique_epi32RSt6vectorIiSaIiEE, @function
_Z12unique_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	cmpq	%rsi, %rdx
	jne	.L15
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L22:
	movl	-4(%rdx), %ecx
	cmpl	4(%rax), %ecx
	je	.L21
.L15:
	movq	%rdx, %rax
	leaq	4(%rdx), %rdx
	cmpq	%rdx, %rsi
	jne	.L22
.L19:
	ret
	.p2align 4,,10
	.p2align 3
.L21:
	cmpq	%rax, %rsi
	je	.L19
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rsi
	jne	.L16
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L23:
	movl	(%rax), %ecx
.L16:
	movl	(%rdx), %edi
	cmpl	%edi, %ecx
	je	.L17
	movl	%edi, 4(%rax)
	addq	$4, %rax
.L17:
	addq	$4, %rdx
	cmpq	%rsi, %rdx
	jne	.L23
	ret
	.cfi_endproc
.LFE1354:
	.size	_Z12unique_epi32RSt6vectorIiSaIiEE, .-_Z12unique_epi32RSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
