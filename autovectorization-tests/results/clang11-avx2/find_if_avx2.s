	.text
	.file	"find_if.cpp"
	.globl	_Z12find_if_epi8RKSt6vectorIaSaIaEE # -- Begin function _Z12find_if_epi8RKSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z12find_if_epi8RKSt6vectorIaSaIaEE,@function
_Z12find_if_epi8RKSt6vectorIaSaIaEE:    # @_Z12find_if_epi8RKSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rdx
	movq	8(%rdi), %rax
	movq	%rax, %rsi
	subq	%rdx, %rsi
	cmpq	$4, %rsi
	jl	.LBB0_12
# %bb.1:
	shrq	$2, %rsi
	addq	$3, %rdx
	addq	$1, %rsi
	movq	%rdx, %rcx
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	movzbl	-3(%rcx), %edx
	cmpb	$-1, %dl
	je	.LBB0_22
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, %dl
	je	.LBB0_22
# %bb.4:                                #   in Loop: Header=BB0_2 Depth=1
	movzbl	-2(%rcx), %edx
	cmpb	$-1, %dl
	je	.LBB0_23
# %bb.5:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, %dl
	je	.LBB0_23
# %bb.6:                                #   in Loop: Header=BB0_2 Depth=1
	movzbl	-1(%rcx), %edx
	cmpb	$-1, %dl
	je	.LBB0_24
# %bb.7:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, %dl
	je	.LBB0_24
# %bb.8:                                #   in Loop: Header=BB0_2 Depth=1
	movzbl	(%rcx), %edx
	cmpb	$-1, %dl
	je	.LBB0_21
# %bb.9:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, %dl
	je	.LBB0_21
# %bb.10:                               #   in Loop: Header=BB0_2 Depth=1
	addq	$4, %rcx
	addq	$-1, %rsi
	cmpq	$1, %rsi
	jg	.LBB0_2
# %bb.11:
	addq	$-3, %rcx
	movq	%rcx, %rdx
.LBB0_12:
	movq	%rax, %rsi
	subq	%rdx, %rsi
	cmpq	$1, %rsi
	je	.LBB0_27
# %bb.13:
	cmpq	$2, %rsi
	je	.LBB0_18
# %bb.14:
	movq	%rax, %rcx
	cmpq	$3, %rsi
	jne	.LBB0_21
# %bb.15:
	movb	(%rdx), %sil
	cmpb	$-1, %sil
	je	.LBB0_30
# %bb.16:
	movq	%rdx, %rcx
	cmpb	$42, %sil
	je	.LBB0_21
# %bb.17:
	addq	$1, %rdx
.LBB0_18:
	movb	(%rdx), %cl
	cmpb	$-1, %cl
	je	.LBB0_30
# %bb.19:
	cmpb	$42, %cl
	jne	.LBB0_26
# %bb.20:
	movq	%rdx, %rcx
	jmp	.LBB0_21
.LBB0_30:
	movq	%rdx, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB0_22:
	addq	$-3, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB0_23:
	addq	$-2, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB0_24:
	addq	$-1, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB0_26:
	addq	$1, %rdx
.LBB0_27:
	movq	%rdx, %rcx
	movb	(%rdx), %dl
	cmpb	$-1, %dl
	je	.LBB0_21
# %bb.28:
	cmpb	$42, %dl
	jne	.LBB0_29
.LBB0_21:
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB0_29:
	movq	%rax, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.Lfunc_end0:
	.size	_Z12find_if_epi8RKSt6vectorIaSaIaEE, .Lfunc_end0-_Z12find_if_epi8RKSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z13find_if_epi32RKSt6vectorIiSaIiEE # -- Begin function _Z13find_if_epi32RKSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z13find_if_epi32RKSt6vectorIiSaIiEE,@function
_Z13find_if_epi32RKSt6vectorIiSaIiEE:   # @_Z13find_if_epi32RKSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rsi
	movq	8(%rdi), %rax
	movq	%rax, %rdx
	subq	%rsi, %rdx
	cmpq	$16, %rdx
	jl	.LBB1_12
# %bb.1:
	shrq	$4, %rdx
	addq	$8, %rsi
	addq	$1, %rdx
	movq	%rsi, %rcx
	.p2align	4, 0x90
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	movl	-8(%rcx), %esi
	cmpl	$-1, %esi
	je	.LBB1_19
# %bb.3:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, %esi
	je	.LBB1_19
# %bb.4:                                #   in Loop: Header=BB1_2 Depth=1
	movl	-4(%rcx), %esi
	cmpl	$-1, %esi
	je	.LBB1_20
# %bb.5:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, %esi
	je	.LBB1_20
# %bb.6:                                #   in Loop: Header=BB1_2 Depth=1
	movl	(%rcx), %esi
	cmpl	$-1, %esi
	je	.LBB1_18
# %bb.7:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, %esi
	je	.LBB1_18
# %bb.8:                                #   in Loop: Header=BB1_2 Depth=1
	movl	4(%rcx), %esi
	cmpl	$-1, %esi
	je	.LBB1_21
# %bb.9:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, %esi
	je	.LBB1_21
# %bb.10:                               #   in Loop: Header=BB1_2 Depth=1
	addq	$16, %rcx
	addq	$-1, %rdx
	cmpq	$1, %rdx
	jg	.LBB1_2
# %bb.11:
	addq	$-8, %rcx
	movq	%rax, %rdx
	subq	%rcx, %rdx
	movq	%rcx, %rsi
.LBB1_12:
	sarq	$2, %rdx
	cmpq	$1, %rdx
	je	.LBB1_29
# %bb.13:
	cmpq	$2, %rdx
	je	.LBB1_24
# %bb.14:
	movq	%rax, %rcx
	cmpq	$3, %rdx
	jne	.LBB1_18
# %bb.15:
	movl	(%rsi), %ecx
	cmpl	$-1, %ecx
	je	.LBB1_22
# %bb.16:
	cmpl	$42, %ecx
	jne	.LBB1_23
# %bb.17:
	movq	%rsi, %rcx
	jmp	.LBB1_18
.LBB1_19:
	addq	$-8, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB1_20:
	addq	$-4, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB1_21:
	addq	$4, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB1_23:
	addq	$4, %rsi
.LBB1_24:
	movl	(%rsi), %ecx
	cmpl	$-1, %ecx
	je	.LBB1_22
# %bb.25:
	cmpl	$42, %ecx
	jne	.LBB1_28
.LBB1_22:
	movq	%rsi, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB1_28:
	addq	$4, %rsi
.LBB1_29:
	movq	%rsi, %rcx
	movl	(%rsi), %edx
	cmpl	$-1, %edx
	je	.LBB1_18
# %bb.30:
	cmpl	$42, %edx
	jne	.LBB1_31
.LBB1_18:
	cmpq	%rax, %rcx
	setne	%al
	retq
.LBB1_31:
	movq	%rax, %rcx
	cmpq	%rax, %rcx
	setne	%al
	retq
.Lfunc_end1:
	.size	_Z13find_if_epi32RKSt6vectorIiSaIiEE, .Lfunc_end1-_Z13find_if_epi32RKSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
