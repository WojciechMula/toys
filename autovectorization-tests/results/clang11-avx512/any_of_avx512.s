	.text
	.file	"any_of.cpp"
	.globl	_Z11any_of_epi8RKSt6vectorIaSaIaEE # -- Begin function _Z11any_of_epi8RKSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z11any_of_epi8RKSt6vectorIaSaIaEE,@function
_Z11any_of_epi8RKSt6vectorIaSaIaEE:     # @_Z11any_of_epi8RKSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rax
	movq	%rax, %rsi
	subq	%rcx, %rsi
	cmpq	$4, %rsi
	jl	.LBB0_8
# %bb.1:
	shrq	$2, %rsi
	addq	$3, %rcx
	addq	$1, %rsi
	movq	%rcx, %rdx
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	cmpb	$42, -3(%rdx)
	je	.LBB0_19
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, -2(%rdx)
	je	.LBB0_18
# %bb.4:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, -1(%rdx)
	je	.LBB0_17
# %bb.5:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, (%rdx)
	je	.LBB0_20
# %bb.6:                                #   in Loop: Header=BB0_2 Depth=1
	addq	$4, %rdx
	addq	$-1, %rsi
	cmpq	$1, %rsi
	jg	.LBB0_2
# %bb.7:
	addq	$-3, %rdx
	movq	%rdx, %rcx
.LBB0_8:
	movq	%rax, %rsi
	subq	%rcx, %rsi
	cmpq	$1, %rsi
	je	.LBB0_16
# %bb.9:
	cmpq	$2, %rsi
	je	.LBB0_13
# %bb.10:
	movq	%rax, %rdx
	cmpq	$3, %rsi
	jne	.LBB0_20
# %bb.11:
	cmpb	$42, (%rcx)
	movq	%rcx, %rdx
	je	.LBB0_20
# %bb.12:
	addq	$1, %rcx
.LBB0_13:
	cmpb	$42, (%rcx)
	jne	.LBB0_15
# %bb.14:
	movq	%rcx, %rdx
.LBB0_20:
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB0_15:
	addq	$1, %rcx
.LBB0_16:
	cmpb	$42, (%rcx)
	cmovneq	%rax, %rcx
	movq	%rcx, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB0_19:
	addq	$-3, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB0_18:
	addq	$-2, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB0_17:
	addq	$-1, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.Lfunc_end0:
	.size	_Z11any_of_epi8RKSt6vectorIaSaIaEE, .Lfunc_end0-_Z11any_of_epi8RKSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z12any_of_epi32RKSt6vectorIiSaIiEE # -- Begin function _Z12any_of_epi32RKSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z12any_of_epi32RKSt6vectorIiSaIiEE,@function
_Z12any_of_epi32RKSt6vectorIiSaIiEE:    # @_Z12any_of_epi32RKSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rax
	movq	%rax, %rsi
	subq	%rcx, %rsi
	cmpq	$16, %rsi
	jl	.LBB1_8
# %bb.1:
	shrq	$4, %rsi
	addq	$8, %rcx
	addq	$1, %rsi
	movq	%rcx, %rdx
	.p2align	4, 0x90
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	cmpl	$42, -8(%rdx)
	je	.LBB1_20
# %bb.3:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, -4(%rdx)
	je	.LBB1_19
# %bb.4:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, (%rdx)
	je	.LBB1_21
# %bb.5:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, 4(%rdx)
	je	.LBB1_18
# %bb.6:                                #   in Loop: Header=BB1_2 Depth=1
	addq	$16, %rdx
	addq	$-1, %rsi
	cmpq	$1, %rsi
	jg	.LBB1_2
# %bb.7:
	addq	$-8, %rdx
	movq	%rax, %rsi
	subq	%rdx, %rsi
	movq	%rdx, %rcx
.LBB1_8:
	sarq	$2, %rsi
	cmpq	$1, %rsi
	je	.LBB1_17
# %bb.9:
	cmpq	$2, %rsi
	je	.LBB1_14
# %bb.10:
	movq	%rax, %rdx
	cmpq	$3, %rsi
	jne	.LBB1_21
# %bb.11:
	cmpl	$42, (%rcx)
	jne	.LBB1_13
# %bb.12:
	movq	%rcx, %rdx
.LBB1_21:
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB1_20:
	addq	$-8, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB1_19:
	addq	$-4, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB1_18:
	addq	$4, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB1_13:
	addq	$4, %rcx
.LBB1_14:
	cmpl	$42, (%rcx)
	jne	.LBB1_16
# %bb.15:
	movq	%rcx, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.LBB1_16:
	addq	$4, %rcx
.LBB1_17:
	cmpl	$42, (%rcx)
	cmovneq	%rax, %rcx
	movq	%rcx, %rdx
	cmpq	%rax, %rdx
	setne	%al
	retq
.Lfunc_end1:
	.size	_Z12any_of_epi32RKSt6vectorIiSaIiEE, .Lfunc_end1-_Z12any_of_epi32RKSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
