	.text
	.file	"copy.cpp"
	.globl	_Z9copy_epi8RKSt6vectorIaSaIaEERS1_ # -- Begin function _Z9copy_epi8RKSt6vectorIaSaIaEERS1_
	.p2align	4, 0x90
	.type	_Z9copy_epi8RKSt6vectorIaSaIaEERS1_,@function
_Z9copy_epi8RKSt6vectorIaSaIaEERS1_:    # @_Z9copy_epi8RKSt6vectorIaSaIaEERS1_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	pushq	%rax
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	(%rdi), %rbp
	movq	8(%rdi), %r15
	subq	%rbp, %r15
	testq	%r15, %r15
	jle	.LBB0_21
# %bb.1:
	movabsq	$9223372036854775807, %r12      # imm = 0x7FFFFFFFFFFFFFFF
	movq	8(%rsi), %rbx
	addq	$1, %r15
	movq	%rsi, (%rsp)                    # 8-byte Spill
	jmp	.LBB0_2
	.p2align	4, 0x90
.LBB0_3:                                #   in Loop: Header=BB0_2 Depth=1
	movzbl	(%rbp), %eax
	movb	%al, (%rbx)
	movq	8(%rsi), %r14
	addq	$1, %r14
	movq	%r14, 8(%rsi)
.LBB0_20:                               #   in Loop: Header=BB0_2 Depth=1
	addq	$1, %rbp
	addq	$-1, %r15
	movq	%r14, %rbx
	cmpq	$1, %r15
	jle	.LBB0_21
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	cmpq	16(%rsi), %rbx
	jne	.LBB0_3
# %bb.4:                                #   in Loop: Header=BB0_2 Depth=1
	movq	(%rsi), %rcx
	subq	%rcx, %rbx
	cmpq	%r12, %rbx
	je	.LBB0_22
# %bb.5:                                #   in Loop: Header=BB0_2 Depth=1
	movl	$1, %eax
	testq	%rbx, %rbx
	jne	.LBB0_6
# %bb.7:                                #   in Loop: Header=BB0_2 Depth=1
	movq	%rax, %rdx
	addq	%rbx, %rdx
	movq	%r12, %rsi
	jns	.LBB0_8
.LBB0_9:                                #   in Loop: Header=BB0_2 Depth=1
	addq	%rbx, %rax
	jae	.LBB0_10
.LBB0_11:                               #   in Loop: Header=BB0_2 Depth=1
	testq	%r12, %r12
	je	.LBB0_12
.LBB0_13:                               #   in Loop: Header=BB0_2 Depth=1
	js	.LBB0_23
# %bb.14:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%rcx, %r14
	movq	%r12, %rdi
	callq	_Znwm
	movq	%rax, %r13
	movq	%r14, %rcx
	jmp	.LBB0_15
.LBB0_6:                                #   in Loop: Header=BB0_2 Depth=1
	movq	%rbx, %rax
	movq	%rax, %rdx
	addq	%rbx, %rdx
	movq	%r12, %rsi
	js	.LBB0_9
.LBB0_8:                                #   in Loop: Header=BB0_2 Depth=1
	movq	%rdx, %rsi
	addq	%rbx, %rax
	jb	.LBB0_11
.LBB0_10:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%rsi, %r12
	testq	%r12, %r12
	jne	.LBB0_13
.LBB0_12:                               #   in Loop: Header=BB0_2 Depth=1
	xorl	%r13d, %r13d
.LBB0_15:                               #   in Loop: Header=BB0_2 Depth=1
	leaq	(%rbx,%r13), %r14
	movzbl	(%rbp), %eax
	movb	%al, (%r13,%rbx)
	testq	%rbx, %rbx
	jle	.LBB0_17
# %bb.16:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%r13, %rdi
	movq	%rcx, %rsi
	movq	%rbx, %rdx
	movq	%rcx, %rbx
	callq	memmove
	movq	%rbx, %rcx
.LBB0_17:                               #   in Loop: Header=BB0_2 Depth=1
	addq	$1, %r14
	testq	%rcx, %rcx
	je	.LBB0_19
# %bb.18:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%rcx, %rdi
	callq	_ZdlPv
.LBB0_19:                               #   in Loop: Header=BB0_2 Depth=1
	movq	(%rsp), %rsi                    # 8-byte Reload
	movq	%r13, (%rsi)
	movq	%r14, 8(%rsi)
	addq	%r13, %r12
	movq	%r12, 16(%rsi)
	movabsq	$9223372036854775807, %r12      # imm = 0x7FFFFFFFFFFFFFFF
	jmp	.LBB0_20
.LBB0_21:
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB0_22:
	.cfi_def_cfa_offset 64
	movl	$.L.str, %edi
	callq	_ZSt20__throw_length_errorPKc
.LBB0_23:
	callq	_ZSt17__throw_bad_allocv
.Lfunc_end0:
	.size	_Z9copy_epi8RKSt6vectorIaSaIaEERS1_, .Lfunc_end0-_Z9copy_epi8RKSt6vectorIaSaIaEERS1_
	.cfi_endproc
                                        # -- End function
	.globl	_Z10copy_epi32RKSt6vectorIiSaIiEERS1_ # -- Begin function _Z10copy_epi32RKSt6vectorIiSaIiEERS1_
	.p2align	4, 0x90
	.type	_Z10copy_epi32RKSt6vectorIiSaIiEERS1_,@function
_Z10copy_epi32RKSt6vectorIiSaIiEERS1_:  # @_Z10copy_epi32RKSt6vectorIiSaIiEERS1_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	(%rdi), %r13
	movq	8(%rdi), %rbp
	subq	%r13, %rbp
	testq	%rbp, %rbp
	jle	.LBB1_20
# %bb.1:
	movq	%rsi, %r14
	movabsq	$2305843009213693951, %rdi      # imm = 0x1FFFFFFFFFFFFFFF
	movq	8(%rsi), %rbx
	movq	16(%rsi), %rax
	shrq	$2, %rbp
	addq	$1, %rbp
	movq	%rsi, 8(%rsp)                   # 8-byte Spill
	jmp	.LBB1_2
	.p2align	4, 0x90
.LBB1_3:                                #   in Loop: Header=BB1_2 Depth=1
	movl	(%r13), %ecx
	movl	%ecx, (%rbx)
	addq	$4, %rbx
	movq	%rbx, 8(%r14)
	addq	$4, %r13
	addq	$-1, %rbp
	cmpq	$1, %rbp
	jle	.LBB1_20
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	cmpq	%rax, %rbx
	jne	.LBB1_3
# %bb.4:                                #   in Loop: Header=BB1_2 Depth=1
	movq	(%r14), %rsi
	subq	%rsi, %rbx
	movabsq	$9223372036854775804, %rax      # imm = 0x7FFFFFFFFFFFFFFC
	cmpq	%rax, %rbx
	je	.LBB1_21
# %bb.5:                                #   in Loop: Header=BB1_2 Depth=1
	movq	%rbx, %r14
	sarq	$2, %r14
	movl	$1, %eax
	testq	%rbx, %rbx
	jne	.LBB1_6
# %bb.7:                                #   in Loop: Header=BB1_2 Depth=1
	leaq	(%rax,%r14), %rdx
	movq	%rdi, %rcx
	cmpq	%rdi, %rdx
	jbe	.LBB1_8
.LBB1_9:                                #   in Loop: Header=BB1_2 Depth=1
	addq	%r14, %rax
	jae	.LBB1_10
.LBB1_11:                               #   in Loop: Header=BB1_2 Depth=1
	testq	%rdi, %rdi
	movq	%rdi, 16(%rsp)                  # 8-byte Spill
	je	.LBB1_12
.LBB1_13:                               #   in Loop: Header=BB1_2 Depth=1
	leaq	(,%rdi,4), %rdi
	movq	%rsi, %r15
	callq	_Znwm
	movq	%r15, %rsi
	movq	%rax, %r12
	jmp	.LBB1_14
.LBB1_6:                                #   in Loop: Header=BB1_2 Depth=1
	movq	%r14, %rax
	leaq	(%rax,%r14), %rdx
	movq	%rdi, %rcx
	cmpq	%rdi, %rdx
	ja	.LBB1_9
.LBB1_8:                                #   in Loop: Header=BB1_2 Depth=1
	movq	%rdx, %rcx
	addq	%r14, %rax
	jb	.LBB1_11
.LBB1_10:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%rcx, %rdi
	testq	%rdi, %rdi
	movq	%rdi, 16(%rsp)                  # 8-byte Spill
	jne	.LBB1_13
.LBB1_12:                               #   in Loop: Header=BB1_2 Depth=1
	xorl	%r12d, %r12d
.LBB1_14:                               #   in Loop: Header=BB1_2 Depth=1
	leaq	(%r12,%r14,4), %r15
	movl	(%r13), %eax
	movl	%eax, (%r12,%r14,4)
	testq	%rbx, %rbx
	jle	.LBB1_16
# %bb.15:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%r12, %rdi
	movq	%rbx, %rdx
	movq	%rsi, %rbx
	callq	memmove
	movq	%rbx, %rsi
.LBB1_16:                               #   in Loop: Header=BB1_2 Depth=1
	addq	$4, %r15
	testq	%rsi, %rsi
	movq	8(%rsp), %r14                   # 8-byte Reload
	je	.LBB1_18
# %bb.17:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%rsi, %rdi
	callq	_ZdlPv
.LBB1_18:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%r12, (%r14)
	movq	%r15, 8(%r14)
	movq	16(%rsp), %rax                  # 8-byte Reload
	leaq	(%r12,%rax,4), %rax
	movq	%rax, 16(%r14)
	movq	%r15, %rbx
	movabsq	$2305843009213693951, %rdi      # imm = 0x1FFFFFFFFFFFFFFF
	addq	$4, %r13
	addq	$-1, %rbp
	cmpq	$1, %rbp
	jg	.LBB1_2
.LBB1_20:
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB1_21:
	.cfi_def_cfa_offset 80
	movl	$.L.str, %edi
	callq	_ZSt20__throw_length_errorPKc
.Lfunc_end1:
	.size	_Z10copy_epi32RKSt6vectorIiSaIiEERS1_, .Lfunc_end1-_Z10copy_epi32RKSt6vectorIiSaIiEERS1_
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"vector::_M_realloc_insert"
	.size	.L.str, 26

	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __gxx_personality_v0
