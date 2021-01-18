	.text
	.file	"transform_neg.cpp"
	.globl	_Z18transform_neg_epi8RSt6vectorIaSaIaEE # -- Begin function _Z18transform_neg_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z18transform_neg_epi8RSt6vectorIaSaIaEE,@function
_Z18transform_neg_epi8RSt6vectorIaSaIaEE: # @_Z18transform_neg_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB0_11
# %bb.1:
	movq	%rcx, %rdx
	subq	%rax, %rdx
	cmpq	$256, %rdx                      # imm = 0x100
	jb	.LBB0_10
# %bb.2:
	movq	%rdx, %r8
	andq	$-256, %r8
	leaq	-256(%r8), %rsi
	movq	%rsi, %r9
	shrq	$8, %r9
	addq	$1, %r9
	testq	%rsi, %rsi
	je	.LBB0_3
# %bb.4:
	movq	%r9, %rdi
	andq	$-2, %rdi
	negq	%rdi
	xorl	%esi, %esi
	vpxor	%xmm0, %xmm0, %xmm0
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vpsubb	(%rax,%rsi), %zmm0, %zmm1
	vpsubb	64(%rax,%rsi), %zmm0, %zmm2
	vpsubb	128(%rax,%rsi), %zmm0, %zmm3
	vpsubb	192(%rax,%rsi), %zmm0, %zmm4
	vmovdqu64	%zmm1, (%rax,%rsi)
	vmovdqu64	%zmm2, 64(%rax,%rsi)
	vmovdqu64	%zmm3, 128(%rax,%rsi)
	vmovdqu64	%zmm4, 192(%rax,%rsi)
	vpsubb	256(%rax,%rsi), %zmm0, %zmm1
	vpsubb	320(%rax,%rsi), %zmm0, %zmm2
	vpsubb	384(%rax,%rsi), %zmm0, %zmm3
	vpsubb	448(%rax,%rsi), %zmm0, %zmm4
	vmovdqu64	%zmm1, 256(%rax,%rsi)
	vmovdqu64	%zmm2, 320(%rax,%rsi)
	vmovdqu64	%zmm3, 384(%rax,%rsi)
	vmovdqu64	%zmm4, 448(%rax,%rsi)
	addq	$512, %rsi                      # imm = 0x200
	addq	$2, %rdi
	jne	.LBB0_5
# %bb.6:
	testb	$1, %r9b
	je	.LBB0_8
.LBB0_7:
	vpxor	%xmm0, %xmm0, %xmm0
	vpsubb	(%rax,%rsi), %zmm0, %zmm1
	vpsubb	64(%rax,%rsi), %zmm0, %zmm2
	vpsubb	128(%rax,%rsi), %zmm0, %zmm3
	vpsubb	192(%rax,%rsi), %zmm0, %zmm0
	vmovdqu64	%zmm1, (%rax,%rsi)
	vmovdqu64	%zmm2, 64(%rax,%rsi)
	vmovdqu64	%zmm3, 128(%rax,%rsi)
	vmovdqu64	%zmm0, 192(%rax,%rsi)
.LBB0_8:
	cmpq	%r8, %rdx
	je	.LBB0_11
# %bb.9:
	addq	%r8, %rax
	.p2align	4, 0x90
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	negb	(%rax)
	addq	$1, %rax
	cmpq	%rax, %rcx
	jne	.LBB0_10
.LBB0_11:
	vzeroupper
	retq
.LBB0_3:
	xorl	%esi, %esi
	testb	$1, %r9b
	jne	.LBB0_7
	jmp	.LBB0_8
.Lfunc_end0:
	.size	_Z18transform_neg_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z18transform_neg_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z19transform_neg_epi32RSt6vectorIiSaIiEE # -- Begin function _Z19transform_neg_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z19transform_neg_epi32RSt6vectorIiSaIiEE,@function
_Z19transform_neg_epi32RSt6vectorIiSaIiEE: # @_Z19transform_neg_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB1_11
# %bb.1:
	movq	%rcx, %rdx
	subq	%rax, %rdx
	addq	$-4, %rdx
	cmpq	$252, %rdx
	jb	.LBB1_10
# %bb.2:
	shrq	$2, %rdx
	addq	$1, %rdx
	movq	%rdx, %r8
	andq	$-64, %r8
	leaq	-64(%r8), %rsi
	movq	%rsi, %r9
	shrq	$6, %r9
	addq	$1, %r9
	testq	%rsi, %rsi
	je	.LBB1_3
# %bb.4:
	movq	%r9, %rdi
	andq	$-2, %rdi
	negq	%rdi
	xorl	%esi, %esi
	vpxor	%xmm0, %xmm0, %xmm0
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vpsubd	(%rax,%rsi,4), %zmm0, %zmm1
	vpsubd	64(%rax,%rsi,4), %zmm0, %zmm2
	vpsubd	128(%rax,%rsi,4), %zmm0, %zmm3
	vpsubd	192(%rax,%rsi,4), %zmm0, %zmm4
	vmovdqu64	%zmm1, (%rax,%rsi,4)
	vmovdqu64	%zmm2, 64(%rax,%rsi,4)
	vmovdqu64	%zmm3, 128(%rax,%rsi,4)
	vmovdqu64	%zmm4, 192(%rax,%rsi,4)
	vpsubd	256(%rax,%rsi,4), %zmm0, %zmm1
	vpsubd	320(%rax,%rsi,4), %zmm0, %zmm2
	vpsubd	384(%rax,%rsi,4), %zmm0, %zmm3
	vpsubd	448(%rax,%rsi,4), %zmm0, %zmm4
	vmovdqu64	%zmm1, 256(%rax,%rsi,4)
	vmovdqu64	%zmm2, 320(%rax,%rsi,4)
	vmovdqu64	%zmm3, 384(%rax,%rsi,4)
	vmovdqu64	%zmm4, 448(%rax,%rsi,4)
	subq	$-128, %rsi
	addq	$2, %rdi
	jne	.LBB1_5
# %bb.6:
	testb	$1, %r9b
	je	.LBB1_8
.LBB1_7:
	vpxor	%xmm0, %xmm0, %xmm0
	vpsubd	(%rax,%rsi,4), %zmm0, %zmm1
	vpsubd	64(%rax,%rsi,4), %zmm0, %zmm2
	vpsubd	128(%rax,%rsi,4), %zmm0, %zmm3
	vpsubd	192(%rax,%rsi,4), %zmm0, %zmm0
	vmovdqu64	%zmm1, (%rax,%rsi,4)
	vmovdqu64	%zmm2, 64(%rax,%rsi,4)
	vmovdqu64	%zmm3, 128(%rax,%rsi,4)
	vmovdqu64	%zmm0, 192(%rax,%rsi,4)
.LBB1_8:
	cmpq	%r8, %rdx
	je	.LBB1_11
# %bb.9:
	leaq	(%rax,%r8,4), %rax
	.p2align	4, 0x90
.LBB1_10:                               # =>This Inner Loop Header: Depth=1
	negl	(%rax)
	addq	$4, %rax
	cmpq	%rax, %rcx
	jne	.LBB1_10
.LBB1_11:
	vzeroupper
	retq
.LBB1_3:
	xorl	%esi, %esi
	testb	$1, %r9b
	jne	.LBB1_7
	jmp	.LBB1_8
.Lfunc_end1:
	.size	_Z19transform_neg_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z19transform_neg_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
