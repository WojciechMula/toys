	.file	"copy_if.cpp"
	.text
	.section	.rodata._ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_.str1.1,"aMS",@progbits,1
.LC0:
	.string	"vector::_M_realloc_insert"
	.section	.text._ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_
	.type	_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_, @function
_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_:
.LFB1407:
	.cfi_startproc
	movabsq	$9223372036854775807, %rcx
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
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	8(%rdi), %r14
	movq	(%rdi), %r8
	movq	%r14, %rax
	subq	%r8, %rax
	cmpq	%rcx, %rax
	je	.L18
	testq	%rax, %rax
	movq	%rdx, %r15
	movl	$1, %edx
	movq	%rsi, %r12
	cmovne	%rax, %rdx
	xorl	%esi, %esi
	movq	%rdi, %rbx
	addq	%rdx, %rax
	movq	%r12, %rdx
	setc	%sil
	movq	%rax, %r13
	subq	%r8, %rdx
	testq	%rsi, %rsi
	jne	.L13
	testq	%rax, %rax
	js	.L13
	jne	.L5
	xorl	%r13d, %r13d
	xorl	%ebp, %ebp
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L13:
	movq	%rcx, %r13
.L5:
	movq	%r13, %rdi
	movq	%rdx, 16(%rsp)
	movq	%r8, 8(%rsp)
	call	_Znwm@PLT
	movq	8(%rsp), %r8
	movq	16(%rsp), %rdx
	movq	%rax, %rbp
	addq	%rax, %r13
.L11:
	movzbl	(%r15), %eax
	movq	%r14, %r9
	leaq	1(%rbp,%rdx), %r10
	movq	16(%rbx), %r15
	subq	%r12, %r9
	movb	%al, 0(%rbp,%rdx)
	leaq	(%r10,%r9), %r14
	testq	%rdx, %rdx
	jg	.L19
	testq	%r9, %r9
	jg	.L7
	testq	%r8, %r8
	jne	.L10
.L8:
	vmovq	%rbp, %xmm1
	movq	%r13, 16(%rbx)
	vpinsrq	$1, %r14, %xmm1, %xmm0
	vmovdqu	%xmm0, (%rbx)
	addq	$40, %rsp
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
.L19:
	.cfi_restore_state
	movq	%r8, %rsi
	movq	%rbp, %rdi
	movq	%r9, 24(%rsp)
	movq	%r10, 16(%rsp)
	movq	%r8, 8(%rsp)
	call	memmove@PLT
	movq	24(%rsp), %r9
	movq	8(%rsp), %r8
	movq	16(%rsp), %r10
	testq	%r9, %r9
	jg	.L7
.L10:
	movq	%r15, %rsi
	movq	%r8, %rdi
	subq	%r8, %rsi
	call	_ZdlPvm@PLT
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L7:
	movq	%r9, %rdx
	movq	%r12, %rsi
	movq	%r10, %rdi
	movq	%r8, 8(%rsp)
	call	memcpy@PLT
	movq	8(%rsp), %r8
	testq	%r8, %r8
	je	.L8
	jmp	.L10
.L18:
	leaq	.LC0(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
	.cfi_endproc
.LFE1407:
	.size	_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_, .-_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_
	.text
	.p2align 4
	.globl	_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_
	.type	_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_, @function
_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_:
.LFB1353:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	8(%rdi), %r12
	movq	(%rdi), %rbx
	cmpq	%r12, %rbx
	je	.L26
	movq	%rsi, %rbp
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L22:
	addq	$1, %rbx
	cmpq	%rbx, %r12
	je	.L26
.L24:
	movzbl	(%rbx), %eax
	testb	%al, %al
	jle	.L22
	movq	8(%rbp), %rsi
	cmpq	16(%rbp), %rsi
	je	.L23
	addq	$1, %rbx
	movb	%al, (%rsi)
	addq	$1, 8(%rbp)
	cmpq	%rbx, %r12
	jne	.L24
.L26:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	.cfi_restore_state
	movq	%rbx, %rdx
	movq	%rbp, %rdi
	call	_ZNSt6vectorIaSaIaEE17_M_realloc_insertIJRKaEEEvN9__gnu_cxx17__normal_iteratorIPaS1_EEDpOT_
	jmp	.L22
	.cfi_endproc
.LFE1353:
	.size	_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_, .-_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_
	.section	.text._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.type	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, @function
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB1414:
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
	movabsq	$2305843009213693951, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	8(%rdi), %r14
	movq	(%rdi), %r13
	movq	%r14, %rax
	subq	%r13, %rax
	sarq	$2, %rax
	cmpq	%rbx, %rax
	je	.L44
	testq	%rax, %rax
	movq	%rdx, %r15
	movl	$1, %edx
	movq	%rdi, %rbp
	cmovne	%rax, %rdx
	xorl	%ecx, %ecx
	movq	%rsi, %r12
	addq	%rdx, %rax
	movq	%rsi, %rdx
	setc	%cl
	subq	%r13, %rdx
	testq	%rcx, %rcx
	jne	.L40
	testq	%rax, %rax
	jne	.L33
	xorl	%ebx, %ebx
.L39:
	movl	(%r15), %eax
	movq	%r14, %r8
	leaq	4(%rcx,%rdx), %r9
	movq	16(%rbp), %r15
	subq	%r12, %r8
	movl	%eax, (%rcx,%rdx)
	leaq	(%r9,%r8), %r14
	testq	%rdx, %rdx
	jg	.L45
	testq	%r8, %r8
	jg	.L35
.L37:
	testq	%r13, %r13
	jne	.L38
.L36:
	vmovq	%rcx, %xmm1
	movq	%rbx, 16(%rbp)
	vpinsrq	$1, %r14, %xmm1, %xmm0
	vmovdqu	%xmm0, 0(%rbp)
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
.L33:
	.cfi_restore_state
	cmpq	%rbx, %rax
	cmova	%rbx, %rax
	leaq	0(,%rax,4), %rbx
.L32:
	movq	%rbx, %rdi
	movq	%rdx, (%rsp)
	call	_Znwm@PLT
	movq	(%rsp), %rdx
	movq	%rax, %rcx
	addq	%rax, %rbx
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L45:
	movq	%rcx, %rdi
	movq	%r13, %rsi
	movq	%r8, 8(%rsp)
	movq	%r9, (%rsp)
	call	memmove@PLT
	movq	8(%rsp), %r8
	movq	(%rsp), %r9
	movq	%rax, %rcx
	testq	%r8, %r8
	jg	.L35
.L38:
	movq	%r15, %rsi
	movq	%r13, %rdi
	movq	%rcx, (%rsp)
	subq	%r13, %rsi
	call	_ZdlPvm@PLT
	movq	(%rsp), %rcx
	jmp	.L36
	.p2align 4,,10
	.p2align 3
.L35:
	movq	%r8, %rdx
	movq	%r12, %rsi
	movq	%r9, %rdi
	movq	%rcx, (%rsp)
	call	memcpy@PLT
	movq	(%rsp), %rcx
	jmp	.L37
	.p2align 4,,10
	.p2align 3
.L40:
	movabsq	$9223372036854775804, %rbx
	jmp	.L32
.L44:
	leaq	.LC0(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
	.cfi_endproc
.LFE1414:
	.size	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, .-_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.text
	.p2align 4
	.globl	_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_
	.type	_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_, @function
_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_:
.LFB1357:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	8(%rdi), %r12
	movq	(%rdi), %rbx
	cmpq	%r12, %rbx
	je	.L52
	movq	%rsi, %rbp
	jmp	.L50
	.p2align 4,,10
	.p2align 3
.L48:
	addq	$4, %rbx
	cmpq	%rbx, %r12
	je	.L52
.L50:
	movl	(%rbx), %eax
	testl	%eax, %eax
	jle	.L48
	movq	8(%rbp), %rsi
	cmpq	16(%rbp), %rsi
	je	.L49
	movl	%eax, (%rsi)
	addq	$4, %rbx
	addq	$4, %rsi
	movq	%rsi, 8(%rbp)
	cmpq	%rbx, %r12
	jne	.L50
.L52:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L49:
	.cfi_restore_state
	movq	%rbx, %rdx
	movq	%rbp, %rdi
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L48
	.cfi_endproc
.LFE1357:
	.size	_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_, .-_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
