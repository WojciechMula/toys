	.file	"remove_if.cpp"
	.text
	.p2align 4
	.globl	_Z14remove_if_epi8RSt6vectorIaSaIaEE
	.type	_Z14remove_if_epi8RSt6vectorIaSaIaEE, @function
_Z14remove_if_epi8RSt6vectorIaSaIaEE:
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
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L32:
	cmpb	$42, 1(%rax)
	jne	.L28
	cmpb	$42, 2(%rax)
	jne	.L29
	cmpb	$42, 3(%rax)
	jne	.L30
	addq	$4, %rax
	cmpq	%rdx, %rax
	je	.L31
.L7:
	cmpb	$42, (%rax)
	je	.L32
.L3:
	cmpq	%rax, %rcx
	je	.L25
	leaq	1(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L25
	.p2align 4,,10
	.p2align 3
.L16:
	cmpb	$42, (%rdx)
	jne	.L15
	movb	$42, (%rax)
	addq	$1, %rax
.L15:
	addq	$1, %rdx
	cmpq	%rdx, %rcx
	jne	.L16
.L25:
	ret
	.p2align 4,,10
	.p2align 3
.L31:
	movq	%rcx, %rsi
	subq	%rax, %rsi
.L2:
	cmpq	$2, %rsi
	je	.L8
	cmpq	$3, %rsi
	je	.L9
	cmpq	$1, %rsi
	jne	.L25
.L10:
	cmpb	$42, (%rax)
	jne	.L3
	ret
.L9:
	cmpb	$42, (%rax)
	jne	.L3
	addq	$1, %rax
.L8:
	cmpb	$42, (%rax)
	jne	.L3
	addq	$1, %rax
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L28:
	addq	$1, %rax
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L29:
	addq	$2, %rax
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L30:
	addq	$3, %rax
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z14remove_if_epi8RSt6vectorIaSaIaEE, .-_Z14remove_if_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z15remove_if_epi32RSt6vectorIiSaIiEE
	.type	_Z15remove_if_epi32RSt6vectorIiSaIiEE, @function
_Z15remove_if_epi32RSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rax
	movq	%rsi, %rdx
	subq	%rax, %rdx
	movq	%rdx, %rcx
	sarq	$4, %rdx
	sarq	$2, %rcx
	testq	%rdx, %rdx
	jle	.L34
	salq	$4, %rdx
	addq	%rax, %rdx
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L63:
	cmpb	$42, 4(%rax)
	jne	.L59
	cmpb	$42, 8(%rax)
	jne	.L60
	cmpb	$42, 12(%rax)
	jne	.L61
	addq	$16, %rax
	cmpq	%rax, %rdx
	je	.L62
.L39:
	cmpb	$42, (%rax)
	je	.L63
.L35:
	cmpq	%rax, %rsi
	je	.L57
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rsi
	je	.L57
	.p2align 4,,10
	.p2align 3
.L48:
	movl	(%rdx), %ecx
	cmpb	$42, %cl
	jne	.L47
	movl	%ecx, (%rax)
	addq	$4, %rax
.L47:
	addq	$4, %rdx
	cmpq	%rdx, %rsi
	jne	.L48
.L57:
	ret
	.p2align 4,,10
	.p2align 3
.L62:
	movq	%rsi, %rcx
	subq	%rax, %rcx
	sarq	$2, %rcx
.L34:
	cmpq	$2, %rcx
	je	.L40
	cmpq	$3, %rcx
	je	.L41
	cmpq	$1, %rcx
	jne	.L57
.L42:
	cmpb	$42, (%rax)
	jne	.L35
	ret
.L41:
	cmpb	$42, (%rax)
	jne	.L35
	addq	$4, %rax
.L40:
	cmpb	$42, (%rax)
	jne	.L35
	addq	$4, %rax
	jmp	.L42
	.p2align 4,,10
	.p2align 3
.L59:
	addq	$4, %rax
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L60:
	addq	$8, %rax
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L61:
	addq	$12, %rax
	jmp	.L35
	.cfi_endproc
.LFE1357:
	.size	_Z15remove_if_epi32RSt6vectorIiSaIiEE, .-_Z15remove_if_epi32RSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
