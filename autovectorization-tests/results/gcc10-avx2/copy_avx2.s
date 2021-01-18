	.file	"copy.cpp"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"vector::_M_realloc_insert"
	.text
	.p2align 4
	.globl	_Z9copy_epi8RKSt6vectorIaSaIaEERS1_
	.type	_Z9copy_epi8RKSt6vectorIaSaIaEERS1_, @function
_Z9copy_epi8RKSt6vectorIaSaIaEERS1_:
.LFB1353:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	8(%rdi), %r14
	movq	(%rdi), %rbp
	movq	%r14, %rax
	subq	%rbp, %rax
	testq	%rax, %rax
	jle	.L20
	movq	8(%rsi), %rbx
	movq	%rsi, %r12
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L23:
	movzbl	0(%rbp), %eax
	addq	$1, %rbp
	movb	%al, (%rbx)
	movq	8(%r12), %rax
	leaq	1(%rax), %rbx
	movq	%rbx, 8(%r12)
	cmpq	%r14, %rbp
	je	.L20
.L13:
	cmpq	%rbx, 16(%r12)
	jne	.L23
	movabsq	$9223372036854775807, %rax
	movq	(%r12), %r8
	subq	%r8, %rbx
	movq	%rbx, %r13
	cmpq	%rax, %rbx
	je	.L24
	testq	%rbx, %rbx
	movl	$1, %eax
	cmovne	%rbx, %rax
	addq	%rbx, %rax
	movq	%rax, %rbx
	jc	.L16
	testq	%rax, %rax
	js	.L16
	jne	.L8
	xorl	%r9d, %r9d
	xorl	%r15d, %r15d
.L14:
	movzbl	0(%rbp), %eax
	leaq	1(%r15,%r13), %rbx
	movb	%al, (%r15,%r13)
	testq	%r13, %r13
	jg	.L25
	testq	%r8, %r8
	jne	.L26
.L11:
	vmovq	%r15, %xmm1
	addq	$1, %rbp
	movq	%r9, 16(%r12)
	vpinsrq	$1, %rbx, %xmm1, %xmm0
	vmovdqu	%xmm0, (%r12)
	cmpq	%r14, %rbp
	jne	.L13
.L20:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	.cfi_restore_state
	movabsq	$9223372036854775807, %rbx
.L8:
	movq	%rbx, %rdi
	movq	%r8, (%rsp)
	call	_Znwm@PLT
	movq	(%rsp), %r8
	movq	%rax, %r15
	leaq	(%rax,%rbx), %r9
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L25:
	movq	%r8, %rsi
	movq	%r13, %rdx
	movq	%r15, %rdi
	movq	%r9, 8(%rsp)
	movq	%r8, (%rsp)
	call	memmove@PLT
	movq	16(%r12), %rsi
	movq	(%rsp), %r8
	movq	8(%rsp), %r9
	subq	%r8, %rsi
.L10:
	movq	%r8, %rdi
	movq	%r9, (%rsp)
	call	_ZdlPvm@PLT
	movq	(%rsp), %r9
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L26:
	movq	16(%r12), %rsi
	subq	%r8, %rsi
	jmp	.L10
.L24:
	leaq	.LC0(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
	.cfi_endproc
.LFE1353:
	.size	_Z9copy_epi8RKSt6vectorIaSaIaEERS1_, .-_Z9copy_epi8RKSt6vectorIaSaIaEERS1_
	.p2align 4
	.globl	_Z10copy_epi32RKSt6vectorIiSaIiEERS1_
	.type	_Z10copy_epi32RKSt6vectorIiSaIiEERS1_, @function
_Z10copy_epi32RKSt6vectorIiSaIiEERS1_:
.LFB1354:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	(%rdi), %rbp
	movq	8(%rdi), %rax
	subq	%rbp, %rax
	movq	%rax, %r12
	sarq	$2, %r12
	testq	%rax, %rax
	jle	.L51
	movq	8(%rsi), %rbx
	movq	16(%rsi), %r15
	movq	%rsi, %r14
	jmp	.L40
	.p2align 4,,10
	.p2align 3
.L53:
	movl	0(%rbp), %eax
	addq	$4, %rbx
	addq	$4, %rbp
	movl	%eax, -4(%rbx)
	movq	%rbx, 8(%r14)
	subq	$1, %r12
	je	.L51
.L40:
	cmpq	%r15, %rbx
	jne	.L53
	movabsq	$2305843009213693951, %rcx
	movq	(%r14), %r9
	movq	%rbx, %rdx
	subq	%r9, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	cmpq	%rcx, %rax
	je	.L54
	testq	%rax, %rax
	movl	$1, %esi
	cmovne	%rax, %rsi
	addq	%rsi, %rax
	jc	.L33
	xorl	%r15d, %r15d
	xorl	%r13d, %r13d
	testq	%rax, %rax
	jne	.L55
.L35:
	movl	0(%rbp), %eax
	leaq	4(%r13,%rdx), %rbx
	movl	%eax, 0(%r13,%rdx)
	testq	%rdx, %rdx
	jg	.L56
	testq	%r9, %r9
	jne	.L57
.L38:
	vmovq	%r13, %xmm1
	movq	%r15, 16(%r14)
	addq	$4, %rbp
	vpinsrq	$1, %rbx, %xmm1, %xmm0
	vmovdqu	%xmm0, (%r14)
	subq	$1, %r12
	jne	.L40
.L51:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L56:
	.cfi_restore_state
	movq	%r9, %rsi
	movq	%r13, %rdi
	movq	%r9, (%rsp)
	call	memmove@PLT
	movq	16(%r14), %rsi
	movq	(%rsp), %r9
	subq	%r9, %rsi
.L37:
	movq	%r9, %rdi
	call	_ZdlPvm@PLT
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L55:
	movabsq	$2305843009213693951, %rcx
	cmpq	%rcx, %rax
	cmova	%rcx, %rax
	leaq	0(,%rax,4), %r15
.L34:
	movq	%r15, %rdi
	movq	%rdx, 8(%rsp)
	movq	%r9, (%rsp)
	call	_Znwm@PLT
	movq	(%rsp), %r9
	movq	8(%rsp), %rdx
	movq	%rax, %r13
	addq	%rax, %r15
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L57:
	movq	16(%r14), %rsi
	subq	%r9, %rsi
	jmp	.L37
.L54:
	leaq	.LC0(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
.L33:
	movabsq	$9223372036854775804, %r15
	jmp	.L34
	.cfi_endproc
.LFE1354:
	.size	_Z10copy_epi32RKSt6vectorIiSaIiEERS1_, .-_Z10copy_epi32RKSt6vectorIiSaIiEERS1_
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
