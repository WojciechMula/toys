	.text
	.file	"count.cpp"
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4                               # -- Begin function _Z10count_epi8RKSt6vectorIaSaIaEE
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
	.globl	_Z10count_epi8RKSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z10count_epi8RKSt6vectorIaSaIaEE,@function
_Z10count_epi8RKSt6vectorIaSaIaEE:      # @_Z10count_epi8RKSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rsi
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rsi
	je	.LBB0_1
# %bb.2:
	movq	%rcx, %r8
	subq	%rsi, %r8
	cmpq	$32, %r8
	jae	.LBB0_4
# %bb.3:
	xorl	%eax, %eax
	movq	%rsi, %rdx
	jmp	.LBB0_7
.LBB0_1:
	xorl	%eax, %eax
	retq
.LBB0_4:
	movq	%r8, %rdi
	andq	$-32, %rdi
	leaq	(%rsi,%rdi), %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%eax, %eax
	vmovdqa	.LCPI0_0(%rip), %xmm8           # xmm8 = <42,42,42,42,42,42,42,42,u,u,u,u,u,u,u,u>
	vpxor	%xmm2, %xmm2, %xmm2
	vpxor	%xmm3, %xmm3, %xmm3
	vpxor	%xmm4, %xmm4, %xmm4
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vmovq	(%rsi,%rax), %xmm5              # xmm5 = mem[0],zero
	vmovq	8(%rsi,%rax), %xmm6             # xmm6 = mem[0],zero
	vmovq	16(%rsi,%rax), %xmm7            # xmm7 = mem[0],zero
	vmovq	24(%rsi,%rax), %xmm1            # xmm1 = mem[0],zero
	vpcmpeqb	%xmm8, %xmm5, %k0
	vpcmpeqb	%xmm8, %xmm6, %k1
	vpcmpeqb	%xmm8, %xmm7, %k2
	vpcmpeqb	%xmm8, %xmm1, %k3
	vpmovm2q	%k0, %zmm1
	vpsubq	%zmm1, %zmm0, %zmm0
	vpmovm2q	%k1, %zmm1
	vpsubq	%zmm1, %zmm2, %zmm2
	vpmovm2q	%k2, %zmm1
	vpsubq	%zmm1, %zmm3, %zmm3
	vpmovm2q	%k3, %zmm1
	vpsubq	%zmm1, %zmm4, %zmm4
	addq	$32, %rax
	cmpq	%rax, %rdi
	jne	.LBB0_5
# %bb.6:
	vpaddq	%zmm0, %zmm2, %zmm0
	vpaddq	%zmm0, %zmm3, %zmm0
	vpaddq	%zmm0, %zmm4, %zmm0
	vextracti64x4	$1, %zmm0, %ymm1
	vpaddq	%zmm1, %zmm0, %zmm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpshufd	$78, %xmm0, %xmm1               # xmm1 = xmm0[2,3,0,1]
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rdi, %r8
	je	.LBB0_8
	.p2align	4, 0x90
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	xorl	%esi, %esi
	cmpb	$42, (%rdx)
	sete	%sil
	addq	%rsi, %rax
	addq	$1, %rdx
	cmpq	%rdx, %rcx
	jne	.LBB0_7
.LBB0_8:
	vzeroupper
	retq
.Lfunc_end0:
	.size	_Z10count_epi8RKSt6vectorIaSaIaEE, .Lfunc_end0-_Z10count_epi8RKSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2                               # -- Begin function _Z11count_epi32RKSt6vectorIiSaIiEE
.LCPI1_0:
	.long	42                              # 0x2a
	.text
	.globl	_Z11count_epi32RKSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z11count_epi32RKSt6vectorIiSaIiEE,@function
_Z11count_epi32RKSt6vectorIiSaIiEE:     # @_Z11count_epi32RKSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rsi
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rsi
	je	.LBB1_1
# %bb.2:
	movq	%rcx, %r8
	subq	%rsi, %r8
	addq	$-4, %r8
	cmpq	$124, %r8
	jae	.LBB1_4
# %bb.3:
	xorl	%eax, %eax
	movq	%rsi, %rdx
	jmp	.LBB1_7
.LBB1_1:
	xorl	%eax, %eax
	retq
.LBB1_4:
	shrq	$2, %r8
	addq	$1, %r8
	movq	%r8, %rdi
	andq	$-32, %rdi
	leaq	(%rsi,%rdi,4), %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	vpbroadcastd	.LCPI1_0(%rip), %ymm1   # ymm1 = [42,42,42,42,42,42,42,42]
	xorl	%eax, %eax
	vpxor	%xmm2, %xmm2, %xmm2
	vpxor	%xmm3, %xmm3, %xmm3
	vpxor	%xmm4, %xmm4, %xmm4
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vpcmpeqd	(%rsi,%rax,4), %ymm1, %k0
	vpcmpeqd	32(%rsi,%rax,4), %ymm1, %k1
	vpcmpeqd	64(%rsi,%rax,4), %ymm1, %k2
	vpcmpeqd	96(%rsi,%rax,4), %ymm1, %k3
	vpmovm2q	%k0, %zmm5
	vpsubq	%zmm5, %zmm0, %zmm0
	vpmovm2q	%k1, %zmm5
	vpsubq	%zmm5, %zmm2, %zmm2
	vpmovm2q	%k2, %zmm5
	vpsubq	%zmm5, %zmm3, %zmm3
	vpmovm2q	%k3, %zmm5
	vpsubq	%zmm5, %zmm4, %zmm4
	addq	$32, %rax
	cmpq	%rax, %rdi
	jne	.LBB1_5
# %bb.6:
	vpaddq	%zmm0, %zmm2, %zmm0
	vpaddq	%zmm0, %zmm3, %zmm0
	vpaddq	%zmm0, %zmm4, %zmm0
	vextracti64x4	$1, %zmm0, %ymm1
	vpaddq	%zmm1, %zmm0, %zmm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpshufd	$78, %xmm0, %xmm1               # xmm1 = xmm0[2,3,0,1]
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rdi, %r8
	je	.LBB1_8
	.p2align	4, 0x90
.LBB1_7:                                # =>This Inner Loop Header: Depth=1
	xorl	%esi, %esi
	cmpl	$42, (%rdx)
	sete	%sil
	addq	%rsi, %rax
	addq	$4, %rdx
	cmpq	%rdx, %rcx
	jne	.LBB1_7
.LBB1_8:
	vzeroupper
	retq
.Lfunc_end1:
	.size	_Z11count_epi32RKSt6vectorIiSaIiEE, .Lfunc_end1-_Z11count_epi32RKSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
