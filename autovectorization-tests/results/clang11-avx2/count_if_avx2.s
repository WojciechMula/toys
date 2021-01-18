	.text
	.file	"count_if.cpp"
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4                               # -- Begin function _Z13count_if_epi8RKSt6vectorIaSaIaEE
.LCPI0_0:
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
	.zero	1
	.zero	1
	.zero	1
	.zero	1
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI0_1:
	.quad	1                               # 0x1
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
	cmpq	$16, %r8
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
	andq	$-16, %rcx
	leaq	(%rdx,%rcx), %rsi
	vpxor	%xmm11, %xmm11, %xmm11
	xorl	%eax, %eax
	vmovdqa	.LCPI0_0(%rip), %xmm8           # xmm8 = <42,42,42,42,u,u,u,u,u,u,u,u,u,u,u,u>
	vpbroadcastq	.LCPI0_1(%rip), %ymm10  # ymm10 = [1,1,1,1]
	vpcmpeqd	%xmm9, %xmm9, %xmm9
	vpxor	%xmm4, %xmm4, %xmm4
	vpxor	%xmm5, %xmm5, %xmm5
	vpxor	%xmm6, %xmm6, %xmm6
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vmovd	(%rdx,%rax), %xmm7              # xmm7 = mem[0],zero,zero,zero
	vmovd	4(%rdx,%rax), %xmm1             # xmm1 = mem[0],zero,zero,zero
	vmovd	8(%rdx,%rax), %xmm3             # xmm3 = mem[0],zero,zero,zero
	vmovd	12(%rdx,%rax), %xmm2            # xmm2 = mem[0],zero,zero,zero
	vpcmpeqb	%xmm7, %xmm8, %xmm0
	vpmovzxbd	%xmm0, %xmm12           # xmm12 = xmm0[0],zero,zero,zero,xmm0[1],zero,zero,zero,xmm0[2],zero,zero,zero,xmm0[3],zero,zero,zero
	vpcmpeqb	%xmm1, %xmm8, %xmm0
	vpmovzxbd	%xmm0, %xmm13           # xmm13 = xmm0[0],zero,zero,zero,xmm0[1],zero,zero,zero,xmm0[2],zero,zero,zero,xmm0[3],zero,zero,zero
	vpcmpeqb	%xmm3, %xmm8, %xmm0
	vpmovzxbd	%xmm0, %xmm14           # xmm14 = xmm0[0],zero,zero,zero,xmm0[1],zero,zero,zero,xmm0[2],zero,zero,zero,xmm0[3],zero,zero,zero
	vpcmpeqb	%xmm2, %xmm8, %xmm0
	vpmovzxbd	%xmm0, %xmm0            # xmm0 = xmm0[0],zero,zero,zero,xmm0[1],zero,zero,zero,xmm0[2],zero,zero,zero,xmm0[3],zero,zero,zero
	vpcmpeqb	%xmm7, %xmm9, %xmm7
	vpmovzxbd	%xmm7, %xmm7            # xmm7 = xmm7[0],zero,zero,zero,xmm7[1],zero,zero,zero,xmm7[2],zero,zero,zero,xmm7[3],zero,zero,zero
	vpor	%xmm7, %xmm12, %xmm7
	vpcmpeqb	%xmm1, %xmm9, %xmm1
	vpmovzxbd	%xmm1, %xmm1            # xmm1 = xmm1[0],zero,zero,zero,xmm1[1],zero,zero,zero,xmm1[2],zero,zero,zero,xmm1[3],zero,zero,zero
	vpor	%xmm1, %xmm13, %xmm1
	vpcmpeqb	%xmm3, %xmm9, %xmm3
	vpmovzxbd	%xmm3, %xmm3            # xmm3 = xmm3[0],zero,zero,zero,xmm3[1],zero,zero,zero,xmm3[2],zero,zero,zero,xmm3[3],zero,zero,zero
	vpor	%xmm3, %xmm14, %xmm3
	vpcmpeqb	%xmm2, %xmm9, %xmm2
	vpmovzxbd	%xmm2, %xmm2            # xmm2 = xmm2[0],zero,zero,zero,xmm2[1],zero,zero,zero,xmm2[2],zero,zero,zero,xmm2[3],zero,zero,zero
	vpor	%xmm2, %xmm0, %xmm0
	vpmovzxdq	%xmm7, %ymm2            # ymm2 = xmm7[0],zero,xmm7[1],zero,xmm7[2],zero,xmm7[3],zero
	vpand	%ymm2, %ymm10, %ymm2
	vpaddq	%ymm2, %ymm11, %ymm11
	vpmovzxdq	%xmm1, %ymm1            # ymm1 = xmm1[0],zero,xmm1[1],zero,xmm1[2],zero,xmm1[3],zero
	vpand	%ymm1, %ymm10, %ymm1
	vpaddq	%ymm1, %ymm4, %ymm4
	vpmovzxdq	%xmm3, %ymm1            # ymm1 = xmm3[0],zero,xmm3[1],zero,xmm3[2],zero,xmm3[3],zero
	vpand	%ymm1, %ymm10, %ymm1
	vpaddq	%ymm1, %ymm5, %ymm5
	vpmovzxdq	%xmm0, %ymm0            # ymm0 = xmm0[0],zero,xmm0[1],zero,xmm0[2],zero,xmm0[3],zero
	vpand	%ymm0, %ymm10, %ymm0
	vpaddq	%ymm0, %ymm6, %ymm6
	addq	$16, %rax
	cmpq	%rax, %rcx
	jne	.LBB0_5
# %bb.6:
	vpaddq	%ymm4, %ymm11, %ymm0
	vpaddq	%ymm0, %ymm5, %ymm0
	vpaddq	%ymm0, %ymm6, %ymm0
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
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI1_1:
	.quad	1                               # 0x1
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
	cmpq	$60, %r8
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
	andq	$-16, %rcx
	leaq	(%rsi,%rcx,4), %rdi
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%eax, %eax
	vpbroadcastd	.LCPI1_0(%rip), %xmm9   # xmm9 = [42,42,42,42]
	vpbroadcastq	.LCPI1_1(%rip), %ymm10  # ymm10 = [1,1,1,1]
	vpcmpeqd	%xmm8, %xmm8, %xmm8
	vpxor	%xmm4, %xmm4, %xmm4
	vpxor	%xmm5, %xmm5, %xmm5
	vpxor	%xmm6, %xmm6, %xmm6
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vmovdqu	(%rsi,%rax,4), %xmm7
	vmovdqu	16(%rsi,%rax,4), %xmm3
	vmovdqu	32(%rsi,%rax,4), %xmm1
	vmovdqu	48(%rsi,%rax,4), %xmm2
	vpcmpeqd	%xmm7, %xmm9, %xmm11
	vpcmpeqd	%xmm3, %xmm9, %xmm12
	vpcmpeqd	%xmm1, %xmm9, %xmm13
	vpcmpeqd	%xmm2, %xmm9, %xmm14
	vpcmpeqd	%xmm7, %xmm8, %xmm7
	vpor	%xmm7, %xmm11, %xmm7
	vpcmpeqd	%xmm3, %xmm8, %xmm3
	vpor	%xmm3, %xmm12, %xmm3
	vpcmpeqd	%xmm1, %xmm8, %xmm1
	vpor	%xmm1, %xmm13, %xmm1
	vpcmpeqd	%xmm2, %xmm8, %xmm2
	vpor	%xmm2, %xmm14, %xmm2
	vpmovzxdq	%xmm7, %ymm7            # ymm7 = xmm7[0],zero,xmm7[1],zero,xmm7[2],zero,xmm7[3],zero
	vpand	%ymm7, %ymm10, %ymm7
	vpaddq	%ymm7, %ymm0, %ymm0
	vpmovzxdq	%xmm3, %ymm3            # ymm3 = xmm3[0],zero,xmm3[1],zero,xmm3[2],zero,xmm3[3],zero
	vpand	%ymm3, %ymm10, %ymm3
	vpaddq	%ymm3, %ymm4, %ymm4
	vpmovzxdq	%xmm1, %ymm1            # ymm1 = xmm1[0],zero,xmm1[1],zero,xmm1[2],zero,xmm1[3],zero
	vpand	%ymm1, %ymm10, %ymm1
	vpaddq	%ymm1, %ymm5, %ymm5
	vpmovzxdq	%xmm2, %ymm1            # ymm1 = xmm2[0],zero,xmm2[1],zero,xmm2[2],zero,xmm2[3],zero
	vpand	%ymm1, %ymm10, %ymm1
	vpaddq	%ymm1, %ymm6, %ymm6
	addq	$16, %rax
	cmpq	%rax, %rcx
	jne	.LBB1_5
# %bb.6:
	vpaddq	%ymm0, %ymm4, %ymm0
	vpaddq	%ymm0, %ymm5, %ymm0
	vpaddq	%ymm0, %ymm6, %ymm0
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
