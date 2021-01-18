	.text
	.file	"reverse.cpp"
	.globl	_Z12reverse_epi8RSt6vectorIaSaIaEE # -- Begin function _Z12reverse_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z12reverse_epi8RSt6vectorIaSaIaEE,@function
_Z12reverse_epi8RSt6vectorIaSaIaEE:     # @_Z12reverse_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB0_4
# %bb.1:
	addq	$-1, %rcx
	cmpq	%rax, %rcx
	jbe	.LBB0_4
# %bb.2:
	addq	$1, %rax
	.p2align	4, 0x90
.LBB0_3:                                # =>This Inner Loop Header: Depth=1
	movzbl	-1(%rax), %esi
	movzbl	(%rcx), %edx
	movb	%dl, -1(%rax)
	movb	%sil, (%rcx)
	addq	$-1, %rcx
	leaq	1(%rax), %rdx
	cmpq	%rcx, %rax
	movq	%rdx, %rax
	jb	.LBB0_3
.LBB0_4:
	retq
.Lfunc_end0:
	.size	_Z12reverse_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z12reverse_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z13reverse_epi32RSt6vectorIiSaIiEE # -- Begin function _Z13reverse_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z13reverse_epi32RSt6vectorIiSaIiEE,@function
_Z13reverse_epi32RSt6vectorIiSaIiEE:    # @_Z13reverse_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB1_4
# %bb.1:
	addq	$-4, %rcx
	cmpq	%rax, %rcx
	jbe	.LBB1_4
# %bb.2:
	addq	$4, %rax
	.p2align	4, 0x90
.LBB1_3:                                # =>This Inner Loop Header: Depth=1
	movl	-4(%rax), %edx
	movl	(%rcx), %esi
	movl	%esi, -4(%rax)
	movl	%edx, (%rcx)
	addq	$-4, %rcx
	leaq	4(%rax), %rdx
	cmpq	%rcx, %rax
	movq	%rdx, %rax
	jb	.LBB1_3
.LBB1_4:
	retq
.Lfunc_end1:
	.size	_Z13reverse_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z13reverse_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
