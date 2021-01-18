	.text
	.file	"replace.cpp"
	.section	.rodata,"a",@progbits
	.p2align	6                               # -- Begin function _Z12replace_epi8RSt6vectorIaSaIaEE
.LCPI0_0:
	.zero	64,13
.LCPI0_1:
	.zero	64,42
	.text
	.globl	_Z12replace_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z12replace_epi8RSt6vectorIaSaIaEE,@function
_Z12replace_epi8RSt6vectorIaSaIaEE:     # @_Z12replace_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB0_13
# %bb.1:
	movq	%rcx, %r10
	subq	%rax, %r10
	cmpq	$256, %r10                      # imm = 0x100
	jb	.LBB0_10
# %bb.2:
	movq	%r10, %r8
	andq	$-256, %r8
	leaq	-256(%r8), %rdx
	movq	%rdx, %r9
	shrq	$8, %r9
	addq	$1, %r9
	testq	%rdx, %rdx
	je	.LBB0_3
# %bb.4:
	leaq	448(%rax), %rdi
	movq	%r9, %rdx
	andq	$-2, %rdx
	negq	%rdx
	xorl	%esi, %esi
	vmovdqa64	.LCPI0_0(%rip), %zmm0   # zmm0 = [13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13]
	vmovdqa64	.LCPI0_1(%rip), %zmm1   # zmm1 = [42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42]
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vpcmpeqb	-448(%rdi,%rsi), %zmm0, %k1
	vpcmpeqb	-384(%rdi,%rsi), %zmm0, %k2
	vpcmpeqb	-320(%rdi,%rsi), %zmm0, %k3
	vpcmpeqb	-256(%rdi,%rsi), %zmm0, %k4
	vmovdqu8	%zmm1, -448(%rdi,%rsi) {%k1}
	vmovdqu8	%zmm1, -384(%rdi,%rsi) {%k2}
	vmovdqu8	%zmm1, -320(%rdi,%rsi) {%k3}
	vmovdqu8	%zmm1, -256(%rdi,%rsi) {%k4}
	vpcmpeqb	-192(%rdi,%rsi), %zmm0, %k1
	vpcmpeqb	-128(%rdi,%rsi), %zmm0, %k2
	vpcmpeqb	-64(%rdi,%rsi), %zmm0, %k3
	vpcmpeqb	(%rdi,%rsi), %zmm0, %k4
	vmovdqu8	%zmm1, -192(%rdi,%rsi) {%k1}
	vmovdqu8	%zmm1, -128(%rdi,%rsi) {%k2}
	vmovdqu8	%zmm1, -64(%rdi,%rsi) {%k3}
	vmovdqu8	%zmm1, (%rdi,%rsi) {%k4}
	addq	$512, %rsi                      # imm = 0x200
	addq	$2, %rdx
	jne	.LBB0_5
# %bb.6:
	testb	$1, %r9b
	je	.LBB0_8
.LBB0_7:
	vmovdqa64	.LCPI0_0(%rip), %zmm0   # zmm0 = [13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13]
	vpcmpeqb	(%rax,%rsi), %zmm0, %k1
	vpcmpeqb	64(%rax,%rsi), %zmm0, %k2
	vpcmpeqb	128(%rax,%rsi), %zmm0, %k3
	vpcmpeqb	192(%rax,%rsi), %zmm0, %k4
	vmovdqa64	.LCPI0_1(%rip), %zmm0   # zmm0 = [42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42]
	vmovdqu8	%zmm0, (%rax,%rsi) {%k1}
	vmovdqu8	%zmm0, 64(%rax,%rsi) {%k2}
	vmovdqu8	%zmm0, 128(%rax,%rsi) {%k3}
	vmovdqu8	%zmm0, 192(%rax,%rsi) {%k4}
.LBB0_8:
	cmpq	%r8, %r10
	jne	.LBB0_9
.LBB0_13:
	vzeroupper
	retq
.LBB0_9:
	addq	%r8, %rax
	jmp	.LBB0_10
	.p2align	4, 0x90
.LBB0_12:                               #   in Loop: Header=BB0_10 Depth=1
	addq	$1, %rax
	cmpq	%rax, %rcx
	je	.LBB0_13
.LBB0_10:                               # =>This Inner Loop Header: Depth=1
	cmpb	$13, (%rax)
	jne	.LBB0_12
# %bb.11:                               #   in Loop: Header=BB0_10 Depth=1
	movb	$42, (%rax)
	jmp	.LBB0_12
.LBB0_3:
	xorl	%esi, %esi
	testb	$1, %r9b
	jne	.LBB0_7
	jmp	.LBB0_8
.Lfunc_end0:
	.size	_Z12replace_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z12replace_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2                               # -- Begin function _Z13replace_epi32RSt6vectorIiSaIiEE
.LCPI1_0:
	.long	13                              # 0xd
.LCPI1_1:
	.long	42                              # 0x2a
	.text
	.globl	_Z13replace_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z13replace_epi32RSt6vectorIiSaIiEE,@function
_Z13replace_epi32RSt6vectorIiSaIiEE:    # @_Z13replace_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB1_13
# %bb.1:
	movq	%rcx, %r10
	subq	%rax, %r10
	addq	$-4, %r10
	cmpq	$252, %r10
	jb	.LBB1_10
# %bb.2:
	shrq	$2, %r10
	addq	$1, %r10
	movq	%r10, %r8
	andq	$-64, %r8
	leaq	-64(%r8), %rdx
	movq	%rdx, %r9
	shrq	$6, %r9
	addq	$1, %r9
	testq	%rdx, %rdx
	je	.LBB1_3
# %bb.4:
	leaq	448(%rax), %rdi
	movq	%r9, %rdx
	andq	$-2, %rdx
	negq	%rdx
	xorl	%esi, %esi
	vpbroadcastd	.LCPI1_0(%rip), %zmm0   # zmm0 = [13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13]
	vpbroadcastd	.LCPI1_1(%rip), %zmm1   # zmm1 = [42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42]
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vpcmpeqd	-448(%rdi,%rsi,4), %zmm0, %k1
	vpcmpeqd	-384(%rdi,%rsi,4), %zmm0, %k2
	vpcmpeqd	-320(%rdi,%rsi,4), %zmm0, %k3
	vpcmpeqd	-256(%rdi,%rsi,4), %zmm0, %k4
	vmovdqu32	%zmm1, -448(%rdi,%rsi,4) {%k1}
	vmovdqu32	%zmm1, -384(%rdi,%rsi,4) {%k2}
	vmovdqu32	%zmm1, -320(%rdi,%rsi,4) {%k3}
	vmovdqu32	%zmm1, -256(%rdi,%rsi,4) {%k4}
	vpcmpeqd	-192(%rdi,%rsi,4), %zmm0, %k1
	vpcmpeqd	-128(%rdi,%rsi,4), %zmm0, %k2
	vpcmpeqd	-64(%rdi,%rsi,4), %zmm0, %k3
	vpcmpeqd	(%rdi,%rsi,4), %zmm0, %k4
	vmovdqu32	%zmm1, -192(%rdi,%rsi,4) {%k1}
	vmovdqu32	%zmm1, -128(%rdi,%rsi,4) {%k2}
	vmovdqu32	%zmm1, -64(%rdi,%rsi,4) {%k3}
	vmovdqu32	%zmm1, (%rdi,%rsi,4) {%k4}
	subq	$-128, %rsi
	addq	$2, %rdx
	jne	.LBB1_5
# %bb.6:
	testb	$1, %r9b
	je	.LBB1_8
.LBB1_7:
	vpbroadcastd	.LCPI1_0(%rip), %zmm0   # zmm0 = [13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13]
	vpcmpeqd	(%rax,%rsi,4), %zmm0, %k1
	vpcmpeqd	64(%rax,%rsi,4), %zmm0, %k2
	vpcmpeqd	128(%rax,%rsi,4), %zmm0, %k3
	vpcmpeqd	192(%rax,%rsi,4), %zmm0, %k4
	vpbroadcastd	.LCPI1_1(%rip), %zmm0   # zmm0 = [42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42]
	vmovdqu32	%zmm0, (%rax,%rsi,4) {%k1}
	vmovdqu32	%zmm0, 64(%rax,%rsi,4) {%k2}
	vmovdqu32	%zmm0, 128(%rax,%rsi,4) {%k3}
	vmovdqu32	%zmm0, 192(%rax,%rsi,4) {%k4}
.LBB1_8:
	cmpq	%r8, %r10
	jne	.LBB1_9
.LBB1_13:
	vzeroupper
	retq
.LBB1_9:
	leaq	(%rax,%r8,4), %rax
	jmp	.LBB1_10
	.p2align	4, 0x90
.LBB1_12:                               #   in Loop: Header=BB1_10 Depth=1
	addq	$4, %rax
	cmpq	%rax, %rcx
	je	.LBB1_13
.LBB1_10:                               # =>This Inner Loop Header: Depth=1
	cmpl	$13, (%rax)
	jne	.LBB1_12
# %bb.11:                               #   in Loop: Header=BB1_10 Depth=1
	movl	$42, (%rax)
	jmp	.LBB1_12
.LBB1_3:
	xorl	%esi, %esi
	testb	$1, %r9b
	jne	.LBB1_7
	jmp	.LBB1_8
.Lfunc_end1:
	.size	_Z13replace_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z13replace_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
