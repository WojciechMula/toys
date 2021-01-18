	.text
	.file	"count_if.cpp"
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4                               # -- Begin function _Z13count_if_epi8RKSt6vectorIaSaIaEE
.LCPI0_0:
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.byte	42                              # 0x2a
	.zero	1
	.zero	1
	.zero	1
	.zero	1
	.zero	1
	.zero	1
	.zero	1
	.zero	1
	.text
	.globl	_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z13count_if_epi8RKSt6vectorIaSaIaEE,@function
_Z13count_if_epi8RKSt6vectorIaSaIaEE:   # @_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rdx
	movq	8(%rdi), %rdi
	cmpq	%rdi, %rdx
	je	.LBB0_1
# %bb.2:
	movq	%rdi, %r8
	subq	%rdx, %r8
	cmpq	$32, %r8
	jae	.LBB0_4
# %bb.3:
	xorl	%eax, %eax
	movq	%rdx, %rsi
	jmp	.LBB0_7
.LBB0_1:
	xorl	%eax, %eax
	retq
.LBB0_4:
	movq	%r8, %rcx
	andq	$-32, %rcx
	leaq	(%rdx,%rcx), %rsi
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%eax, %eax
	vmovdqa	.LCPI0_0(%rip), %xmm8           # xmm8 = <42,42,42,42,42,42,42,42,u,u,u,u,u,u,u,u>
	vpcmpeqd	%xmm9, %xmm9, %xmm9
	vpxor	%xmm3, %xmm3, %xmm3
	vpxor	%xmm4, %xmm4, %xmm4
	vpxor	%xmm5, %xmm5, %xmm5
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vmovq	(%rdx,%rax), %xmm6              # xmm6 = mem[0],zero
	vmovq	8(%rdx,%rax), %xmm7             # xmm7 = mem[0],zero
	vmovq	16(%rdx,%rax), %xmm1            # xmm1 = mem[0],zero
	vmovq	24(%rdx,%rax), %xmm2            # xmm2 = mem[0],zero
	vpcmpeqb	%xmm8, %xmm6, %k0
	vpcmpeqb	%xmm8, %xmm7, %k1
	vpcmpeqb	%xmm8, %xmm1, %k2
	vpcmpeqb	%xmm8, %xmm2, %k3
	vpcmpeqb	%xmm9, %xmm6, %k4
	vpcmpeqb	%xmm9, %xmm7, %k5
	vpcmpeqb	%xmm9, %xmm1, %k6
	vpcmpeqb	%xmm9, %xmm2, %k7
	korb	%k4, %k0, %k0
	korb	%k5, %k1, %k1
	korb	%k6, %k2, %k2
	korb	%k7, %k3, %k3
	vpmovm2q	%k0, %zmm1
	vpsubq	%zmm1, %zmm0, %zmm0
	vpmovm2q	%k1, %zmm1
	vpsubq	%zmm1, %zmm3, %zmm3
	vpmovm2q	%k2, %zmm1
	vpsubq	%zmm1, %zmm4, %zmm4
	vpmovm2q	%k3, %zmm1
	vpsubq	%zmm1, %zmm5, %zmm5
	addq	$32, %rax
	cmpq	%rax, %rcx
	jne	.LBB0_5
# %bb.6:
	vpaddq	%zmm0, %zmm3, %zmm0
	vpaddq	%zmm0, %zmm4, %zmm0
	vpaddq	%zmm0, %zmm5, %zmm0
	vextracti64x4	$1, %zmm0, %ymm1
	vpaddq	%zmm1, %zmm0, %zmm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpshufd	$78, %xmm0, %xmm1               # xmm1 = xmm0[2,3,0,1]
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rcx, %r8
	je	.LBB0_8
	.p2align	4, 0x90
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	movzbl	(%rsi), %ecx
	cmpb	$42, %cl
	sete	%dl
	cmpb	$-1, %cl
	sete	%cl
	orb	%dl, %cl
	movzbl	%cl, %ecx
	addq	%rcx, %rax
	addq	$1, %rsi
	cmpq	%rsi, %rdi
	jne	.LBB0_7
.LBB0_8:
	vzeroupper
	retq
.Lfunc_end0:
	.size	_Z13count_if_epi8RKSt6vectorIaSaIaEE, .Lfunc_end0-_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2                               # -- Begin function _Z14count_if_epi32RKSt6vectorIiSaIiEE
.LCPI1_0:
	.long	42                              # 0x2a
	.text
	.globl	_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z14count_if_epi32RKSt6vectorIiSaIiEE,@function
_Z14count_if_epi32RKSt6vectorIiSaIiEE:  # @_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rsi
	movq	8(%rdi), %r9
	cmpq	%r9, %rsi
	je	.LBB1_1
# %bb.2:
	movq	%r9, %r8
	subq	%rsi, %r8
	addq	$-4, %r8
	cmpq	$124, %r8
	jae	.LBB1_4
# %bb.3:
	xorl	%eax, %eax
	movq	%rsi, %rdi
	jmp	.LBB1_7
.LBB1_1:
	xorl	%eax, %eax
	retq
.LBB1_4:
	shrq	$2, %r8
	addq	$1, %r8
	movq	%r8, %rcx
	andq	$-32, %rcx
	leaq	(%rsi,%rcx,4), %rdi
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%eax, %eax
	vpbroadcastd	.LCPI1_0(%rip), %ymm1   # ymm1 = [42,42,42,42,42,42,42,42]
	vpcmpeqd	%ymm2, %ymm2, %ymm2
	vpxor	%xmm3, %xmm3, %xmm3
	vpxor	%xmm4, %xmm4, %xmm4
	vpxor	%xmm5, %xmm5, %xmm5
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vmovdqu	(%rsi,%rax,4), %ymm6
	vmovdqu	32(%rsi,%rax,4), %ymm7
	vmovdqu	64(%rsi,%rax,4), %ymm8
	vmovdqu	96(%rsi,%rax,4), %ymm9
	vpcmpeqd	%ymm1, %ymm6, %k0
	vpcmpeqd	%ymm1, %ymm7, %k1
	vpcmpeqd	%ymm1, %ymm8, %k2
	vpcmpeqd	%ymm1, %ymm9, %k3
	vpcmpeqd	%ymm2, %ymm6, %k4
	korb	%k4, %k0, %k0
	vpcmpeqd	%ymm2, %ymm7, %k4
	korb	%k4, %k1, %k1
	vpcmpeqd	%ymm2, %ymm8, %k4
	korb	%k4, %k2, %k2
	vpcmpeqd	%ymm2, %ymm9, %k4
	korb	%k4, %k3, %k3
	vpmovm2q	%k0, %zmm6
	vpsubq	%zmm6, %zmm0, %zmm0
	vpmovm2q	%k1, %zmm6
	vpsubq	%zmm6, %zmm3, %zmm3
	vpmovm2q	%k2, %zmm6
	vpsubq	%zmm6, %zmm4, %zmm4
	vpmovm2q	%k3, %zmm6
	vpsubq	%zmm6, %zmm5, %zmm5
	addq	$32, %rax
	cmpq	%rax, %rcx
	jne	.LBB1_5
# %bb.6:
	vpaddq	%zmm0, %zmm3, %zmm0
	vpaddq	%zmm0, %zmm4, %zmm0
	vpaddq	%zmm0, %zmm5, %zmm0
	vextracti64x4	$1, %zmm0, %ymm1
	vpaddq	%zmm1, %zmm0, %zmm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpshufd	$78, %xmm0, %xmm1               # xmm1 = xmm0[2,3,0,1]
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rcx, %r8
	je	.LBB1_8
	.p2align	4, 0x90
.LBB1_7:                                # =>This Inner Loop Header: Depth=1
	movl	(%rdi), %esi
	cmpl	$42, %esi
	sete	%cl
	cmpl	$-1, %esi
	sete	%dl
	orb	%cl, %dl
	movzbl	%dl, %ecx
	addq	%rcx, %rax
	addq	$4, %rdi
	cmpq	%rdi, %r9
	jne	.LBB1_7
.LBB1_8:
	vzeroupper
	retq
.Lfunc_end1:
	.size	_Z14count_if_epi32RKSt6vectorIiSaIiEE, .Lfunc_end1-_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
