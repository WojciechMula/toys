	.text
	.file	"copy_if.cpp"
	.globl	_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_ # -- Begin function _Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_
	.p2align	4, 0x90
	.type	_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_,@function
_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_: # @_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_
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
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	(%rdi), %rbp
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rbp
	je	.LBB0_17
# %bb.1:
	movabsq	$9223372036854775807, %rdx      # imm = 0x7FFFFFFFFFFFFFFF
	leaq	8(%rsi), %rdi
	leaq	16(%rsi), %r8
	movq	%rcx, 24(%rsp)                  # 8-byte Spill
	movq	%rdi, 16(%rsp)                  # 8-byte Spill
	movq	%r8, 8(%rsp)                    # 8-byte Spill
	movq	%rsi, 32(%rsp)                  # 8-byte Spill
	jmp	.LBB0_2
	.p2align	4, 0x90
.LBB0_4:                                #   in Loop: Header=BB0_2 Depth=1
	movb	%al, (%rbx)
	movq	(%rdi), %r12
	addq	$1, %r12
	movq	%rdi, %rax
.LBB0_15:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%r12, (%rax)
.LBB0_16:                               #   in Loop: Header=BB0_2 Depth=1
	addq	$1, %rbp
	cmpq	%rbp, %rcx
	je	.LBB0_17
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	movzbl	(%rbp), %eax
	testb	%al, %al
	jle	.LBB0_16
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	movq	(%rdi), %rbx
	cmpq	(%r8), %rbx
	jne	.LBB0_4
# %bb.5:                                #   in Loop: Header=BB0_2 Depth=1
	movq	(%rsi), %r15
	subq	%r15, %rbx
	cmpq	%rdx, %rbx
	je	.LBB0_18
# %bb.6:                                #   in Loop: Header=BB0_2 Depth=1
	testq	%rbx, %rbx
	movq	%rbx, %rcx
	movl	$1, %esi
	cmoveq	%rsi, %rcx
	movq	%rcx, %r12
	addq	%rbx, %r12
	cmovsq	%rdx, %r12
	addq	%rbx, %rcx
	cmovbq	%rdx, %r12
	testq	%r12, %r12
	je	.LBB0_7
# %bb.8:                                #   in Loop: Header=BB0_2 Depth=1
	js	.LBB0_19
# %bb.9:                                #   in Loop: Header=BB0_2 Depth=1
	movq	%r12, %rdi
	callq	_Znwm
	movq	%rax, %r13
	movzbl	(%rbp), %eax
	leaq	(%rbx,%r13), %r14
	movb	%al, (%r13,%rbx)
	testq	%rbx, %rbx
	jle	.LBB0_12
.LBB0_11:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%r13, %rdi
	movq	%r15, %rsi
	movq	%rbx, %rdx
	callq	memmove
.LBB0_12:                               #   in Loop: Header=BB0_2 Depth=1
	addq	$1, %r14
	testq	%r15, %r15
	je	.LBB0_14
# %bb.13:                               #   in Loop: Header=BB0_2 Depth=1
	movq	%r15, %rdi
	callq	_ZdlPv
.LBB0_14:                               #   in Loop: Header=BB0_2 Depth=1
	movq	32(%rsp), %rsi                  # 8-byte Reload
	movq	%r13, (%rsi)
	movq	%r14, 8(%rsi)
	addq	%r13, %r12
	movq	8(%rsp), %r8                    # 8-byte Reload
	movq	%r8, %rax
	movq	24(%rsp), %rcx                  # 8-byte Reload
	movabsq	$9223372036854775807, %rdx      # imm = 0x7FFFFFFFFFFFFFFF
	movq	16(%rsp), %rdi                  # 8-byte Reload
	jmp	.LBB0_15
.LBB0_7:                                #   in Loop: Header=BB0_2 Depth=1
	xorl	%r13d, %r13d
	leaq	(%rbx,%r13), %r14
	movb	%al, (%r13,%rbx)
	testq	%rbx, %rbx
	jg	.LBB0_11
	jmp	.LBB0_12
.LBB0_17:
	addq	$40, %rsp
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
.LBB0_18:
	.cfi_def_cfa_offset 96
	movl	$.L.str, %edi
	callq	_ZSt20__throw_length_errorPKc
.LBB0_19:
	callq	_ZSt17__throw_bad_allocv
.Lfunc_end0:
	.size	_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_, .Lfunc_end0-_Z12copy_if_epi8RKSt6vectorIaSaIaEERS1_
	.cfi_endproc
                                        # -- End function
	.globl	_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_ # -- Begin function _Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_
	.p2align	4, 0x90
	.type	_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_,@function
_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_: # @_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_
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
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	(%rdi), %r13
	movq	8(%rdi), %rcx
	cmpq	%rcx, %r13
	je	.LBB1_16
# %bb.1:
	leaq	8(%rsi), %rdx
	leaq	16(%rsi), %rdi
	movq	%rcx, 16(%rsp)                  # 8-byte Spill
	movq	%rdx, 8(%rsp)                   # 8-byte Spill
	movq	%rdi, (%rsp)                    # 8-byte Spill
	movq	%rsi, 24(%rsp)                  # 8-byte Spill
	jmp	.LBB1_2
	.p2align	4, 0x90
.LBB1_4:                                #   in Loop: Header=BB1_2 Depth=1
	movl	%eax, (%rbx)
	addq	$4, %rbx
	movq	%rdx, %rax
.LBB1_14:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%rbx, (%rax)
.LBB1_15:                               #   in Loop: Header=BB1_2 Depth=1
	addq	$4, %r13
	cmpq	%r13, %rcx
	je	.LBB1_16
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	movl	(%r13), %eax
	testl	%eax, %eax
	jle	.LBB1_15
# %bb.3:                                #   in Loop: Header=BB1_2 Depth=1
	movq	(%rdx), %rbx
	cmpq	(%rdi), %rbx
	jne	.LBB1_4
# %bb.5:                                #   in Loop: Header=BB1_2 Depth=1
	movq	(%rsi), %rcx
	movq	%rcx, 32(%rsp)                  # 8-byte Spill
	subq	%rcx, %rbx
	movabsq	$9223372036854775804, %rcx      # imm = 0x7FFFFFFFFFFFFFFC
	cmpq	%rcx, %rbx
	je	.LBB1_17
# %bb.6:                                #   in Loop: Header=BB1_2 Depth=1
	movq	%rbx, %r14
	sarq	$2, %r14
	testq	%rbx, %rbx
	movq	%r14, %rcx
	movl	$1, %edx
	cmoveq	%rdx, %rcx
	leaq	(%rcx,%r14), %rbp
	movabsq	$2305843009213693951, %rdx      # imm = 0x1FFFFFFFFFFFFFFF
	cmpq	%rdx, %rbp
	cmovaq	%rdx, %rbp
	addq	%r14, %rcx
	cmovbq	%rdx, %rbp
	testq	%rbp, %rbp
	je	.LBB1_7
# %bb.8:                                #   in Loop: Header=BB1_2 Depth=1
	leaq	(,%rbp,4), %rdi
	callq	_Znwm
	movq	%rax, %r12
	movl	(%r13), %eax
	jmp	.LBB1_9
.LBB1_7:                                #   in Loop: Header=BB1_2 Depth=1
	xorl	%r12d, %r12d
.LBB1_9:                                #   in Loop: Header=BB1_2 Depth=1
	leaq	(%r12,%r14,4), %r15
	movl	%eax, (%r12,%r14,4)
	testq	%rbx, %rbx
	movq	32(%rsp), %r14                  # 8-byte Reload
	jle	.LBB1_11
# %bb.10:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%r12, %rdi
	movq	%r14, %rsi
	movq	%rbx, %rdx
	callq	memmove
.LBB1_11:                               #   in Loop: Header=BB1_2 Depth=1
	addq	$4, %r15
	testq	%r14, %r14
	je	.LBB1_13
# %bb.12:                               #   in Loop: Header=BB1_2 Depth=1
	movq	%r14, %rdi
	callq	_ZdlPv
.LBB1_13:                               #   in Loop: Header=BB1_2 Depth=1
	movq	24(%rsp), %rsi                  # 8-byte Reload
	movq	%r12, (%rsi)
	movq	%r15, 8(%rsi)
	leaq	(%r12,%rbp,4), %rbx
	movq	(%rsp), %rdi                    # 8-byte Reload
	movq	%rdi, %rax
	movq	16(%rsp), %rcx                  # 8-byte Reload
	movq	8(%rsp), %rdx                   # 8-byte Reload
	jmp	.LBB1_14
.LBB1_16:
	addq	$40, %rsp
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
.LBB1_17:
	.cfi_def_cfa_offset 96
	movl	$.L.str, %edi
	callq	_ZSt20__throw_length_errorPKc
.Lfunc_end1:
	.size	_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_, .Lfunc_end1-_Z13copy_if_epi32RKSt6vectorIiSaIiEERS1_
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
