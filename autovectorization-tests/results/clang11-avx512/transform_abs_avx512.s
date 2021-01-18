	.text
	.file	"transform_abs.cpp"
	.globl	_Z18transform_abs_epi8RSt6vectorIaSaIaEE # -- Begin function _Z18transform_abs_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z18transform_abs_epi8RSt6vectorIaSaIaEE,@function
_Z18transform_abs_epi8RSt6vectorIaSaIaEE: # @_Z18transform_abs_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rdx
	movq	8(%rdi), %r9
	cmpq	%r9, %rdx
	je	.LBB0_7
# %bb.1:
	movq	%r9, %r8
	subq	%rdx, %r8
	cmpq	$256, %r8                       # imm = 0x100
	jae	.LBB0_3
# %bb.2:
	movq	%rdx, %rcx
	jmp	.LBB0_6
.LBB0_3:
	movq	%r8, %rdi
	andq	$-256, %rdi
	leaq	(%rdx,%rdi), %rcx
	xorl	%esi, %esi
	.p2align	4, 0x90
.LBB0_4:                                # =>This Inner Loop Header: Depth=1
	vpabsb	(%rdx,%rsi), %zmm0
	vpabsb	64(%rdx,%rsi), %zmm1
	vpabsb	128(%rdx,%rsi), %zmm2
	vpabsb	192(%rdx,%rsi), %zmm3
	vmovdqu64	%zmm0, (%rdx,%rsi)
	vmovdqu64	%zmm1, 64(%rdx,%rsi)
	vmovdqu64	%zmm2, 128(%rdx,%rsi)
	vmovdqu64	%zmm3, 192(%rdx,%rsi)
	addq	$256, %rsi                      # imm = 0x100
	cmpq	%rsi, %rdi
	jne	.LBB0_4
# %bb.5:
	cmpq	%rdi, %r8
	je	.LBB0_7
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	movzbl	(%rcx), %edx
	movl	%edx, %eax
	sarb	$7, %al
	addb	%al, %dl
	xorb	%al, %dl
	movb	%dl, (%rcx)
	addq	$1, %rcx
	cmpq	%rcx, %r9
	jne	.LBB0_6
.LBB0_7:
	vzeroupper
	retq
.Lfunc_end0:
	.size	_Z18transform_abs_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z18transform_abs_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z19transform_abs_epi32RSt6vectorIiSaIiEE # -- Begin function _Z19transform_abs_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z19transform_abs_epi32RSt6vectorIiSaIiEE,@function
_Z19transform_abs_epi32RSt6vectorIiSaIiEE: # @_Z19transform_abs_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rdx
	movq	8(%rdi), %rax
	cmpq	%rax, %rdx
	je	.LBB1_7
# %bb.1:
	movq	%rax, %r8
	subq	%rdx, %r8
	addq	$-4, %r8
	cmpq	$252, %r8
	jae	.LBB1_3
# %bb.2:
	movq	%rdx, %rcx
	jmp	.LBB1_6
.LBB1_3:
	shrq	$2, %r8
	addq	$1, %r8
	movq	%r8, %rdi
	andq	$-64, %rdi
	leaq	(%rdx,%rdi,4), %rcx
	xorl	%esi, %esi
	.p2align	4, 0x90
.LBB1_4:                                # =>This Inner Loop Header: Depth=1
	vpabsd	(%rdx,%rsi,4), %zmm0
	vpabsd	64(%rdx,%rsi,4), %zmm1
	vpabsd	128(%rdx,%rsi,4), %zmm2
	vpabsd	192(%rdx,%rsi,4), %zmm3
	vmovdqu64	%zmm0, (%rdx,%rsi,4)
	vmovdqu64	%zmm1, 64(%rdx,%rsi,4)
	vmovdqu64	%zmm2, 128(%rdx,%rsi,4)
	vmovdqu64	%zmm3, 192(%rdx,%rsi,4)
	addq	$64, %rsi
	cmpq	%rsi, %rdi
	jne	.LBB1_4
# %bb.5:
	cmpq	%rdi, %r8
	je	.LBB1_7
	.p2align	4, 0x90
.LBB1_6:                                # =>This Inner Loop Header: Depth=1
	movl	(%rcx), %edx
	movl	%edx, %esi
	negl	%esi
	cmovll	%edx, %esi
	movl	%esi, (%rcx)
	addq	$4, %rcx
	cmpq	%rcx, %rax
	jne	.LBB1_6
.LBB1_7:
	vzeroupper
	retq
.Lfunc_end1:
	.size	_Z19transform_abs_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z19transform_abs_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
