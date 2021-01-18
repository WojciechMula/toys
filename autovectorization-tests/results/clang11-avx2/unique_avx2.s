	.text
	.file	"unique.cpp"
	.globl	_Z11unique_epi8RSt6vectorIaSaIaEE # -- Begin function _Z11unique_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z11unique_epi8RSt6vectorIaSaIaEE,@function
_Z11unique_epi8RSt6vectorIaSaIaEE:      # @_Z11unique_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rsi
	cmpq	%rsi, %rcx
	je	.LBB0_5
# %bb.1:
	addq	$1, %rcx
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	cmpq	%rcx, %rsi
	je	.LBB0_10
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	movzbl	-1(%rcx), %eax
	leaq	1(%rcx), %rdx
	cmpb	(%rcx), %al
	movq	%rdx, %rcx
	jne	.LBB0_2
# %bb.4:
	addq	$-2, %rdx
	movq	%rdx, %rcx
.LBB0_5:
	cmpq	%rsi, %rcx
	je	.LBB0_10
# %bb.6:
	leaq	2(%rcx), %rdx
	cmpq	%rsi, %rdx
	jne	.LBB0_7
.LBB0_10:
	retq
	.p2align	4, 0x90
.LBB0_9:                                #   in Loop: Header=BB0_7 Depth=1
	addq	$1, %rdx
	cmpq	%rdx, %rsi
	je	.LBB0_10
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	movzbl	(%rdx), %eax
	cmpb	%al, (%rcx)
	je	.LBB0_9
# %bb.8:                                #   in Loop: Header=BB0_7 Depth=1
	movb	%al, 1(%rcx)
	addq	$1, %rcx
	jmp	.LBB0_9
.Lfunc_end0:
	.size	_Z11unique_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z11unique_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z12unique_epi32RSt6vectorIiSaIiEE # -- Begin function _Z12unique_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z12unique_epi32RSt6vectorIiSaIiEE,@function
_Z12unique_epi32RSt6vectorIiSaIiEE:     # @_Z12unique_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rax
	cmpq	%rax, %rcx
	je	.LBB1_5
# %bb.1:
	addq	$4, %rcx
	.p2align	4, 0x90
.LBB1_2:                                # =>This Inner Loop Header: Depth=1
	cmpq	%rcx, %rax
	je	.LBB1_10
# %bb.3:                                #   in Loop: Header=BB1_2 Depth=1
	movl	-4(%rcx), %esi
	leaq	4(%rcx), %rdx
	cmpl	(%rcx), %esi
	movq	%rdx, %rcx
	jne	.LBB1_2
# %bb.4:
	addq	$-8, %rdx
	movq	%rdx, %rcx
.LBB1_5:
	cmpq	%rax, %rcx
	je	.LBB1_10
# %bb.6:
	leaq	8(%rcx), %rdx
	cmpq	%rax, %rdx
	jne	.LBB1_7
.LBB1_10:
	retq
	.p2align	4, 0x90
.LBB1_9:                                #   in Loop: Header=BB1_7 Depth=1
	addq	$4, %rdx
	cmpq	%rdx, %rax
	je	.LBB1_10
.LBB1_7:                                # =>This Inner Loop Header: Depth=1
	movl	(%rdx), %esi
	cmpl	%esi, (%rcx)
	je	.LBB1_9
# %bb.8:                                #   in Loop: Header=BB1_7 Depth=1
	movl	%esi, 4(%rcx)
	addq	$4, %rcx
	jmp	.LBB1_9
.Lfunc_end1:
	.size	_Z12unique_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z12unique_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
