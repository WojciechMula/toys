	.text
	.file	"count.cpp"
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4                               # -- Begin function _Z10count_epi8RKSt6vectorIaSaIaEE
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
	cmpq	$16, %r8
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
	andq	$-16, %rdi
	leaq	(%rsi,%rdi), %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%eax, %eax
	vpbroadcastq	.LCPI0_1(%rip), %ymm1   # ymm1 = [1,1,1,1]
	vmovdqa	.LCPI0_0(%rip), %xmm8           # xmm8 = <42,42,42,42,u,u,u,u,u,u,u,u,u,u,u,u>
	vpxor	%xmm3, %xmm3, %xmm3
	vpxor	%xmm4, %xmm4, %xmm4
	vpxor	%xmm5, %xmm5, %xmm5
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	vmovd	(%rsi,%rax), %xmm6              # xmm6 = mem[0],zero,zero,zero
	vmovd	4(%rsi,%rax), %xmm7             # xmm7 = mem[0],zero,zero,zero
	vmovd	8(%rsi,%rax), %xmm2             # xmm2 = mem[0],zero,zero,zero
	vmovd	12(%rsi,%rax), %xmm9            # xmm9 = mem[0],zero,zero,zero
	vpcmpeqb	%xmm6, %xmm8, %xmm6
	vpmovzxbq	%xmm6, %ymm6            # ymm6 = xmm6[0],zero,zero,zero,zero,zero,zero,zero,xmm6[1],zero,zero,zero,zero,zero,zero,zero,xmm6[2],zero,zero,zero,zero,zero,zero,zero,xmm6[3],zero,zero,zero,zero,zero,zero,zero
	vpand	%ymm1, %ymm6, %ymm6
	vpaddq	%ymm6, %ymm0, %ymm0
	vpcmpeqb	%xmm7, %xmm8, %xmm6
	vpmovzxbq	%xmm6, %ymm6            # ymm6 = xmm6[0],zero,zero,zero,zero,zero,zero,zero,xmm6[1],zero,zero,zero,zero,zero,zero,zero,xmm6[2],zero,zero,zero,zero,zero,zero,zero,xmm6[3],zero,zero,zero,zero,zero,zero,zero
	vpand	%ymm1, %ymm6, %ymm6
	vpaddq	%ymm6, %ymm3, %ymm3
	vpcmpeqb	%xmm2, %xmm8, %xmm2
	vpmovzxbq	%xmm2, %ymm2            # ymm2 = xmm2[0],zero,zero,zero,zero,zero,zero,zero,xmm2[1],zero,zero,zero,zero,zero,zero,zero,xmm2[2],zero,zero,zero,zero,zero,zero,zero,xmm2[3],zero,zero,zero,zero,zero,zero,zero
	vpand	%ymm1, %ymm2, %ymm2
	vpaddq	%ymm2, %ymm4, %ymm4
	vpcmpeqb	%xmm8, %xmm9, %xmm2
	vpmovzxbq	%xmm2, %ymm2            # ymm2 = xmm2[0],zero,zero,zero,zero,zero,zero,zero,xmm2[1],zero,zero,zero,zero,zero,zero,zero,xmm2[2],zero,zero,zero,zero,zero,zero,zero,xmm2[3],zero,zero,zero,zero,zero,zero,zero
	vpand	%ymm1, %ymm2, %ymm2
	vpaddq	%ymm2, %ymm5, %ymm5
	addq	$16, %rax
	cmpq	%rax, %rdi
	jne	.LBB0_5
# %bb.6:
	vpaddq	%ymm0, %ymm3, %ymm0
	vpaddq	%ymm0, %ymm4, %ymm0
	vpaddq	%ymm0, %ymm5, %ymm0
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
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI1_1:
	.quad	1                               # 0x1
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
	cmpq	$60, %r8
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
	andq	$-16, %rdi
	leaq	(%rsi,%rdi,4), %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	vpbroadcastd	.LCPI1_0(%rip), %xmm1   # xmm1 = [42,42,42,42]
	vpbroadcastq	.LCPI1_1(%rip), %ymm2   # ymm2 = [1,1,1,1]
	xorl	%eax, %eax
	vpxor	%xmm3, %xmm3, %xmm3
	vpxor	%xmm4, %xmm4, %xmm4
	vpxor	%xmm5, %xmm5, %xmm5
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vpcmpeqd	(%rsi,%rax,4), %xmm1, %xmm6
	vpmovzxdq	%xmm6, %ymm6            # ymm6 = xmm6[0],zero,xmm6[1],zero,xmm6[2],zero,xmm6[3],zero
	vpand	%ymm2, %ymm6, %ymm6
	vpcmpeqd	16(%rsi,%rax,4), %xmm1, %xmm7
	vpaddq	%ymm6, %ymm0, %ymm0
	vpmovzxdq	%xmm7, %ymm6            # ymm6 = xmm7[0],zero,xmm7[1],zero,xmm7[2],zero,xmm7[3],zero
	vpand	%ymm2, %ymm6, %ymm6
	vpaddq	%ymm6, %ymm3, %ymm3
	vpcmpeqd	32(%rsi,%rax,4), %xmm1, %xmm6
	vpmovzxdq	%xmm6, %ymm6            # ymm6 = xmm6[0],zero,xmm6[1],zero,xmm6[2],zero,xmm6[3],zero
	vpand	%ymm2, %ymm6, %ymm6
	vpaddq	%ymm6, %ymm4, %ymm4
	vpcmpeqd	48(%rsi,%rax,4), %xmm1, %xmm6
	vpmovzxdq	%xmm6, %ymm6            # ymm6 = xmm6[0],zero,xmm6[1],zero,xmm6[2],zero,xmm6[3],zero
	vpand	%ymm2, %ymm6, %ymm6
	vpaddq	%ymm6, %ymm5, %ymm5
	addq	$16, %rax
	cmpq	%rax, %rdi
	jne	.LBB1_5
# %bb.6:
	vpaddq	%ymm0, %ymm3, %ymm0
	vpaddq	%ymm0, %ymm4, %ymm0
	vpaddq	%ymm0, %ymm5, %ymm0
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
