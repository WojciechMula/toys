	.file	"remove.cpp"
	.text
	.p2align 4
	.globl	_Z11remove_epi8RSt6vectorIaSaIaEE
	.type	_Z11remove_epi8RSt6vectorIaSaIaEE, @function
_Z11remove_epi8RSt6vectorIaSaIaEE:
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
	leaq	(%rax,%rdx,4), %rdx
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L35:
	cmpb	$42, 1(%rax)
	je	.L31
	cmpb	$42, 2(%rax)
	je	.L32
	cmpb	$42, 3(%rax)
	je	.L33
	addq	$4, %rax
	cmpq	%rdx, %rax
	je	.L34
.L7:
	cmpb	$42, (%rax)
	jne	.L35
.L3:
	cmpq	%rsi, %rax
	je	.L28
	leaq	1(%rax), %rdx
	cmpq	%rdx, %rsi
	je	.L28
	.p2align 4,,10
	.p2align 3
.L16:
	movzbl	(%rdx), %ecx
	cmpb	$42, %cl
	je	.L15
	movb	%cl, (%rax)
	addq	$1, %rax
.L15:
	addq	$1, %rdx
	cmpq	%rdx, %rsi
	jne	.L16
.L28:
	ret
	.p2align 4,,10
	.p2align 3
.L34:
	movq	%rsi, %rcx
	subq	%rax, %rcx
.L2:
	cmpq	$2, %rcx
	je	.L8
	cmpq	$3, %rcx
	je	.L9
	cmpq	$1, %rcx
	jne	.L28
.L10:
	cmpb	$42, (%rax)
	je	.L3
	ret
.L9:
	cmpb	$42, (%rax)
	je	.L3
	addq	$1, %rax
.L8:
	cmpb	$42, (%rax)
	je	.L3
	addq	$1, %rax
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L31:
	addq	$1, %rax
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L32:
	addq	$2, %rax
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L33:
	addq	$3, %rax
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z11remove_epi8RSt6vectorIaSaIaEE, .-_Z11remove_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z12remove_epi32RSt6vectorIiSaIiEE
	.type	_Z12remove_epi32RSt6vectorIiSaIiEE, @function
_Z12remove_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rax
	movq	%rsi, %rdx
	subq	%rax, %rdx
	movq	%rdx, %rcx
	sarq	$4, %rdx
	sarq	$2, %rcx
	testq	%rdx, %rdx
	jle	.L37
	salq	$4, %rdx
	addq	%rax, %rdx
	jmp	.L42
	.p2align 4,,10
	.p2align 3
.L69:
	cmpl	$42, 4(%rax)
	je	.L65
	cmpl	$42, 8(%rax)
	je	.L66
	cmpl	$42, 12(%rax)
	je	.L67
	addq	$16, %rax
	cmpq	%rdx, %rax
	je	.L68
.L42:
	cmpl	$42, (%rax)
	jne	.L69
.L38:
	cmpq	%rsi, %rax
	je	.L63
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rsi
	je	.L63
	.p2align 4,,10
	.p2align 3
.L51:
	movl	(%rdx), %ecx
	cmpl	$42, %ecx
	je	.L50
	movl	%ecx, (%rax)
	addq	$4, %rax
.L50:
	addq	$4, %rdx
	cmpq	%rdx, %rsi
	jne	.L51
.L63:
	ret
	.p2align 4,,10
	.p2align 3
.L68:
	movq	%rsi, %rcx
	subq	%rax, %rcx
	sarq	$2, %rcx
.L37:
	cmpq	$2, %rcx
	je	.L43
	cmpq	$3, %rcx
	je	.L44
	cmpq	$1, %rcx
	jne	.L63
.L45:
	cmpl	$42, (%rax)
	je	.L38
	ret
.L44:
	cmpl	$42, (%rax)
	je	.L38
	addq	$4, %rax
.L43:
	cmpl	$42, (%rax)
	je	.L38
	addq	$4, %rax
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L65:
	addq	$4, %rax
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L66:
	addq	$8, %rax
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L67:
	addq	$12, %rax
	jmp	.L38
	.cfi_endproc
.LFE1354:
	.size	_Z12remove_epi32RSt6vectorIiSaIiEE, .-_Z12remove_epi32RSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
