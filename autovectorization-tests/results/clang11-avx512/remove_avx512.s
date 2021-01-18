	.text
	.file	"remove.cpp"
	.globl	_Z11remove_epi8RSt6vectorIaSaIaEE # -- Begin function _Z11remove_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z11remove_epi8RSt6vectorIaSaIaEE,@function
_Z11remove_epi8RSt6vectorIaSaIaEE:      # @_Z11remove_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rsi
	movq	%rsi, %rdx
	subq	%rax, %rdx
	cmpq	$4, %rdx
	jl	.LBB0_8
# %bb.1:
	shrq	$2, %rdx
	addq	$3, %rax
	addq	$1, %rdx
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	cmpb	$42, -3(%rax)
	je	.LBB0_18
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, -2(%rax)
	je	.LBB0_17
# %bb.4:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, -1(%rax)
	je	.LBB0_16
# %bb.5:                                #   in Loop: Header=BB0_2 Depth=1
	cmpb	$42, (%rax)
	je	.LBB0_19
# %bb.6:                                #   in Loop: Header=BB0_2 Depth=1
	addq	$4, %rax
	addq	$-1, %rdx
	cmpq	$1, %rdx
	jg	.LBB0_2
# %bb.7:
	addq	$-3, %rax
.LBB0_8:
	movq	%rsi, %rdx
	subq	%rax, %rdx
	cmpq	$1, %rdx
	je	.LBB0_15
# %bb.9:
	cmpq	$2, %rdx
	je	.LBB0_13
# %bb.10:
	cmpq	$3, %rdx
	jne	.LBB0_24
# %bb.11:
	cmpb	$42, (%rax)
	je	.LBB0_19
# %bb.12:
	addq	$1, %rax
.LBB0_13:
	cmpb	$42, (%rax)
	je	.LBB0_19
# %bb.14:
	addq	$1, %rax
.LBB0_15:
	cmpb	$42, (%rax)
	cmovneq	%rsi, %rax
	cmpq	%rsi, %rax
	jne	.LBB0_20
	jmp	.LBB0_24
.LBB0_18:
	addq	$-3, %rax
	cmpq	%rsi, %rax
	jne	.LBB0_20
	jmp	.LBB0_24
.LBB0_17:
	addq	$-2, %rax
.LBB0_19:
	cmpq	%rsi, %rax
	je	.LBB0_24
.LBB0_20:
	leaq	1(%rax), %rdx
	cmpq	%rsi, %rdx
	jne	.LBB0_21
.LBB0_24:
	retq
	.p2align	4, 0x90
.LBB0_23:                               #   in Loop: Header=BB0_21 Depth=1
	addq	$1, %rdx
	cmpq	%rdx, %rsi
	je	.LBB0_24
.LBB0_21:                               # =>This Inner Loop Header: Depth=1
	movzbl	(%rdx), %ecx
	cmpb	$42, %cl
	je	.LBB0_23
# %bb.22:                               #   in Loop: Header=BB0_21 Depth=1
	movb	%cl, (%rax)
	addq	$1, %rax
	jmp	.LBB0_23
.LBB0_16:
	addq	$-1, %rax
	cmpq	%rsi, %rax
	jne	.LBB0_20
	jmp	.LBB0_24
.Lfunc_end0:
	.size	_Z11remove_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z11remove_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z12remove_epi32RSt6vectorIiSaIiEE # -- Begin function _Z12remove_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z12remove_epi32RSt6vectorIiSaIiEE,@function
_Z12remove_epi32RSt6vectorIiSaIiEE:     # @_Z12remove_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	movq	%rcx, %rdx
	subq	%rax, %rdx
	cmpq	$16, %rdx
	jl	.LBB1_8
# %bb.1:
	shrq	$4, %rdx
	addq	$8, %rax
	addq	$1, %rdx
	.p2align	4, 0x90
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	cmpl	$42, -8(%rax)
	je	.LBB1_18
# %bb.3:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, -4(%rax)
	je	.LBB1_17
# %bb.4:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, (%rax)
	je	.LBB1_19
# %bb.5:                                #   in Loop: Header=BB1_2 Depth=1
	cmpl	$42, 4(%rax)
	je	.LBB1_16
# %bb.6:                                #   in Loop: Header=BB1_2 Depth=1
	addq	$16, %rax
	addq	$-1, %rdx
	cmpq	$1, %rdx
	jg	.LBB1_2
# %bb.7:
	addq	$-8, %rax
	movq	%rcx, %rdx
	subq	%rax, %rdx
.LBB1_8:
	sarq	$2, %rdx
	cmpq	$1, %rdx
	je	.LBB1_15
# %bb.9:
	cmpq	$2, %rdx
	je	.LBB1_13
# %bb.10:
	cmpq	$3, %rdx
	jne	.LBB1_24
# %bb.11:
	cmpl	$42, (%rax)
	je	.LBB1_19
# %bb.12:
	addq	$4, %rax
.LBB1_13:
	cmpl	$42, (%rax)
	je	.LBB1_19
# %bb.14:
	addq	$4, %rax
.LBB1_15:
	cmpl	$42, (%rax)
	cmovneq	%rcx, %rax
	cmpq	%rcx, %rax
	jne	.LBB1_20
	jmp	.LBB1_24
.LBB1_18:
	addq	$-8, %rax
	cmpq	%rcx, %rax
	jne	.LBB1_20
	jmp	.LBB1_24
.LBB1_17:
	addq	$-4, %rax
.LBB1_19:
	cmpq	%rcx, %rax
	je	.LBB1_24
.LBB1_20:
	leaq	4(%rax), %rdx
	cmpq	%rcx, %rdx
	jne	.LBB1_21
.LBB1_24:
	retq
	.p2align	4, 0x90
.LBB1_23:                               #   in Loop: Header=BB1_21 Depth=1
	addq	$4, %rdx
	cmpq	%rdx, %rcx
	je	.LBB1_24
.LBB1_21:                               # =>This Inner Loop Header: Depth=1
	movl	(%rdx), %esi
	cmpl	$42, %esi
	je	.LBB1_23
# %bb.22:                               #   in Loop: Header=BB1_21 Depth=1
	movl	%esi, (%rax)
	addq	$4, %rax
	jmp	.LBB1_23
.LBB1_16:
	addq	$4, %rax
	cmpq	%rcx, %rax
	jne	.LBB1_20
	jmp	.LBB1_24
.Lfunc_end1:
	.size	_Z12remove_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z12remove_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
