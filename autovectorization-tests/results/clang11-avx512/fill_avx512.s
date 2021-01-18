	.text
	.file	"fill.cpp"
	.globl	_Z9fill_epi8RSt6vectorIaSaIaEE  # -- Begin function _Z9fill_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z9fill_epi8RSt6vectorIaSaIaEE,@function
_Z9fill_epi8RSt6vectorIaSaIaEE:         # @_Z9fill_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	%rdi, %rax
	movq	(%rdi), %rdi
	movq	8(%rax), %rdx
	cmpq	%rdx, %rdi
	je	.LBB0_1
# %bb.2:
	subq	%rdi, %rdx
	movl	$42, %esi
	jmp	memset                          # TAILCALL
.LBB0_1:
	retq
.Lfunc_end0:
	.size	_Z9fill_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z9fill_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2                               # -- Begin function _Z10fill_epi32RSt6vectorIiSaIiEE
.LCPI1_0:
	.long	42                              # 0x2a
	.text
	.globl	_Z10fill_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z10fill_epi32RSt6vectorIiSaIiEE,@function
_Z10fill_epi32RSt6vectorIiSaIiEE:       # @_Z10fill_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB1_12
# %bb.1:
	movq	%rcx, %r9
	subq	%rax, %r9
	addq	$-4, %r9
	cmpq	$252, %r9
	jb	.LBB1_11
# %bb.2:
	shrq	$2, %r9
	addq	$1, %r9
	movq	%r9, %r8
	andq	$-64, %r8
	leaq	-64(%r8), %rdx
	movq	%rdx, %rdi
	shrq	$6, %rdi
	addq	$1, %rdi
	movl	%edi, %esi
	andl	$3, %esi
	cmpq	$192, %rdx
	jae	.LBB1_4
# %bb.3:
	xorl	%edx, %edx
	jmp	.LBB1_6
.LBB1_4:
	andq	$-4, %rdi
	negq	%rdi
	xorl	%edx, %edx
	vbroadcastss	.LCPI1_0(%rip), %zmm0   # zmm0 = [42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42]
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vmovups	%zmm0, (%rax,%rdx,4)
	vmovups	%zmm0, 64(%rax,%rdx,4)
	vmovups	%zmm0, 128(%rax,%rdx,4)
	vmovups	%zmm0, 192(%rax,%rdx,4)
	vmovups	%zmm0, 256(%rax,%rdx,4)
	vmovups	%zmm0, 320(%rax,%rdx,4)
	vmovups	%zmm0, 384(%rax,%rdx,4)
	vmovups	%zmm0, 448(%rax,%rdx,4)
	vmovups	%zmm0, 512(%rax,%rdx,4)
	vmovups	%zmm0, 576(%rax,%rdx,4)
	vmovups	%zmm0, 640(%rax,%rdx,4)
	vmovups	%zmm0, 704(%rax,%rdx,4)
	vmovups	%zmm0, 768(%rax,%rdx,4)
	vmovups	%zmm0, 832(%rax,%rdx,4)
	vmovups	%zmm0, 896(%rax,%rdx,4)
	vmovups	%zmm0, 960(%rax,%rdx,4)
	addq	$256, %rdx                      # imm = 0x100
	addq	$4, %rdi
	jne	.LBB1_5
.LBB1_6:
	testq	%rsi, %rsi
	je	.LBB1_9
# %bb.7:
	leaq	(%rax,%rdx,4), %rdx
	addq	$192, %rdx
	negq	%rsi
	vbroadcastss	.LCPI1_0(%rip), %zmm0   # zmm0 = [42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42]
	.p2align	4, 0x90
.LBB1_8:                                # =>This Inner Loop Header: Depth=1
	vmovups	%zmm0, -192(%rdx)
	vmovups	%zmm0, -128(%rdx)
	vmovups	%zmm0, -64(%rdx)
	vmovups	%zmm0, (%rdx)
	addq	$256, %rdx                      # imm = 0x100
	incq	%rsi
	jne	.LBB1_8
.LBB1_9:
	cmpq	%r8, %r9
	je	.LBB1_12
# %bb.10:
	leaq	(%rax,%r8,4), %rax
	.p2align	4, 0x90
.LBB1_11:                               # =>This Inner Loop Header: Depth=1
	movl	$42, (%rax)
	addq	$4, %rax
	cmpq	%rax, %rcx
	jne	.LBB1_11
.LBB1_12:
	vzeroupper
	retq
.Lfunc_end1:
	.size	_Z10fill_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z10fill_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
