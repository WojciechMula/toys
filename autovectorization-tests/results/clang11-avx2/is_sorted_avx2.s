	.text
	.file	"is_sorted.cpp"
	.globl	_Z14is_sorted_epi8RKSt6vectorIaSaIaEE # -- Begin function _Z14is_sorted_epi8RKSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z14is_sorted_epi8RKSt6vectorIaSaIaEE,@function
_Z14is_sorted_epi8RKSt6vectorIaSaIaEE:  # @_Z14is_sorted_epi8RKSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rdi
	cmpq	%rdi, %rcx
	je	.LBB0_1
# %bb.2:
	leaq	-1(%rdi), %rdx
	.p2align	4, 0x90
.LBB0_3:                                # =>This Inner Loop Header: Depth=1
	cmpq	%rcx, %rdx
	je	.LBB0_4
# %bb.5:                                #   in Loop: Header=BB0_3 Depth=1
	leaq	1(%rcx), %rsi
	movzbl	1(%rcx), %eax
	cmpb	(%rcx), %al
	movq	%rsi, %rcx
	jge	.LBB0_3
# %bb.6:
	cmpq	%rdi, %rsi
	sete	%al
	retq
.LBB0_1:
	movq	%rcx, %rsi
	cmpq	%rdi, %rsi
	sete	%al
	retq
.LBB0_4:
	movq	%rdi, %rsi
	cmpq	%rdi, %rsi
	sete	%al
	retq
.Lfunc_end0:
	.size	_Z14is_sorted_epi8RKSt6vectorIaSaIaEE, .Lfunc_end0-_Z14is_sorted_epi8RKSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z15is_sorted_epi32RKSt6vectorIiSaIiEE # -- Begin function _Z15is_sorted_epi32RKSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z15is_sorted_epi32RKSt6vectorIiSaIiEE,@function
_Z15is_sorted_epi32RKSt6vectorIiSaIiEE: # @_Z15is_sorted_epi32RKSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rax
	cmpq	%rax, %rcx
	je	.LBB1_1
# %bb.2:
	leaq	-4(%rax), %rdx
	.p2align	4, 0x90
.LBB1_3:                                # =>This Inner Loop Header: Depth=1
	cmpq	%rcx, %rdx
	je	.LBB1_4
# %bb.5:                                #   in Loop: Header=BB1_3 Depth=1
	leaq	4(%rcx), %rsi
	movl	4(%rcx), %edi
	cmpl	(%rcx), %edi
	movq	%rsi, %rcx
	jge	.LBB1_3
# %bb.6:
	cmpq	%rax, %rsi
	sete	%al
	retq
.LBB1_1:
	movq	%rcx, %rsi
	cmpq	%rax, %rsi
	sete	%al
	retq
.LBB1_4:
	movq	%rax, %rsi
	cmpq	%rax, %rsi
	sete	%al
	retq
.Lfunc_end1:
	.size	_Z15is_sorted_epi32RKSt6vectorIiSaIiEE, .Lfunc_end1-_Z15is_sorted_epi32RKSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
