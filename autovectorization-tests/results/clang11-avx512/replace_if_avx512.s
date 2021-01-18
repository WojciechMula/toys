	.text
	.file	"replace_if.cpp"
	.globl	_Z15replace_if_epi8RSt6vectorIaSaIaEE # -- Begin function _Z15replace_if_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z15replace_if_epi8RSt6vectorIaSaIaEE,@function
_Z15replace_if_epi8RSt6vectorIaSaIaEE:  # @_Z15replace_if_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	jne	.LBB0_1
.LBB0_5:
	retq
	.p2align	4, 0x90
.LBB0_3:                                #   in Loop: Header=BB0_1 Depth=1
	movb	$42, (%rax)
.LBB0_4:                                #   in Loop: Header=BB0_1 Depth=1
	addq	$1, %rax
	cmpq	%rax, %rcx
	je	.LBB0_5
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movzbl	(%rax), %edx
	cmpb	$13, %dl
	je	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	cmpb	$-12, %dl
	je	.LBB0_3
	jmp	.LBB0_4
.Lfunc_end0:
	.size	_Z15replace_if_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z15replace_if_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z16replace_if_epi32RSt6vectorIiSaIiEE # -- Begin function _Z16replace_if_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z16replace_if_epi32RSt6vectorIiSaIiEE,@function
_Z16replace_if_epi32RSt6vectorIiSaIiEE: # @_Z16replace_if_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	jne	.LBB1_1
.LBB1_5:
	retq
	.p2align	4, 0x90
.LBB1_3:                                #   in Loop: Header=BB1_1 Depth=1
	movl	$42, (%rax)
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
	addq	$4, %rax
	cmpq	%rax, %rcx
	je	.LBB1_5
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	movzbl	(%rax), %edx
	cmpb	$13, %dl
	je	.LBB1_3
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	cmpb	$-12, %dl
	je	.LBB1_3
	jmp	.LBB1_4
.Lfunc_end1:
	.size	_Z16replace_if_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z16replace_if_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
