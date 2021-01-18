	.file	"count.cpp"
	.text
	.p2align 4
	.globl	_Z10count_epi8RKSt6vectorIaSaIaEE
	.type	_Z10count_epi8RKSt6vectorIaSaIaEE, @function
_Z10count_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rcx
	cmpq	%rsi, %rcx
	je	.L11
	leaq	-1(%rsi), %r9
	movq	%rsi, %rdi
	movq	%rcx, %rax
	subq	%rcx, %r9
	subq	%rcx, %rdi
	cmpq	$62, %r9
	jbe	.L12
	movq	%rdi, %rdx
	vpxor	%xmm4, %xmm4, %xmm4
	vmovdqa64	.LC0(%rip), %zmm6
	vmovdqa64	.LC1(%rip), %zmm5
	andq	$-64, %rdx
	addq	%rcx, %rdx
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu8	(%rax), %zmm7
	addq	$64, %rax
	vpcmpb	$0, %zmm6, %zmm7, %k1
	vmovdqu8	%zmm5, %zmm0{%k1}{z}
	vpmovsxbw	%ymm0, %zmm1
	vextracti64x4	$0x1, %zmm0, %ymm0
	vpmovsxwd	%ymm1, %zmm3
	vextracti64x4	$0x1, %zmm1, %ymm1
	vpmovsxbw	%ymm0, %zmm0
	vpmovsxdq	%ymm3, %zmm7
	vextracti32x8	$0x1, %zmm3, %ymm3
	vpmovsxwd	%ymm1, %zmm1
	vpaddq	%zmm4, %zmm7, %zmm4
	vpmovsxdq	%ymm3, %zmm3
	vpmovsxwd	%ymm0, %zmm2
	vpaddq	%zmm4, %zmm3, %zmm3
	vpmovsxdq	%ymm1, %zmm4
	vextracti32x8	$0x1, %zmm1, %ymm1
	vpaddq	%zmm3, %zmm4, %zmm3
	vpmovsxdq	%ymm1, %zmm1
	vextracti64x4	$0x1, %zmm0, %ymm0
	vpaddq	%zmm3, %zmm1, %zmm1
	vpmovsxdq	%ymm2, %zmm3
	vpmovsxwd	%ymm0, %zmm0
	vpaddq	%zmm1, %zmm3, %zmm3
	vextracti32x8	$0x1, %zmm2, %ymm1
	vpmovsxdq	%ymm0, %zmm4
	vpmovsxdq	%ymm1, %zmm1
	vextracti32x8	$0x1, %zmm0, %ymm0
	vpaddq	%zmm3, %zmm1, %zmm1
	vpmovsxdq	%ymm0, %zmm0
	vpaddq	%zmm1, %zmm4, %zmm1
	vpaddq	%zmm1, %zmm0, %zmm4
	cmpq	%rdx, %rax
	jne	.L4
	vextracti64x4	$0x1, %zmm4, %ymm0
	movq	%rdi, %r8
	vpaddq	%ymm0, %ymm4, %ymm0
	andq	$-64, %r8
	vmovdqa	%xmm0, %xmm1
	vextracti64x2	$0x1, %ymm0, %xmm0
	leaq	(%rcx,%r8), %rax
	vpaddq	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	cmpq	%r8, %rdi
	je	.L5
.L3:
	subq	%r8, %r9
	subq	%r8, %rdi
	cmpq	$30, %r9
	jbe	.L9
	vmovdqu8	(%rcx,%r8), %xmm5
	vinserti128	$0x1, 16(%rcx,%r8), %ymm5, %ymm0
	vpcmpb	$0, .LC2(%rip), %ymm0, %k1
	vmovdqu8	.LC3(%rip), %ymm1{%k1}{z}
	vpmovsxbw	%xmm1, %ymm0
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxwd	%xmm0, %ymm3
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxbw	%xmm1, %ymm1
	vpmovsxdq	%xmm3, %ymm4
	vextracti128	$0x1, %ymm3, %xmm3
	vpmovsxwd	%xmm0, %ymm0
	vpmovsxdq	%xmm3, %ymm3
	vpmovsxwd	%xmm1, %ymm2
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddq	%ymm3, %ymm4, %ymm4
	vpmovsxdq	%xmm0, %ymm3
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm4, %ymm3, %ymm3
	vpmovsxdq	%xmm0, %ymm0
	vpmovsxwd	%xmm1, %ymm1
	vpaddq	%ymm3, %ymm0, %ymm0
	vpmovsxdq	%xmm2, %ymm3
	vpaddq	%ymm0, %ymm3, %ymm3
	vextracti128	$0x1, %ymm2, %xmm0
	vpmovsxdq	%xmm1, %ymm2
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm3, %ymm0, %ymm0
	vpaddq	%ymm0, %ymm2, %ymm2
	vextracti128	$0x1, %ymm1, %xmm0
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm2, %ymm0, %ymm0
	vmovdqa	%xmm0, %xmm1
	vextracti64x2	$0x1, %ymm0, %xmm0
	vpaddq	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rcx
	addq	%rcx, %rdx
	movq	%rdi, %rcx
	andq	$-32, %rcx
	addq	%rcx, %rax
	cmpq	%rcx, %rdi
	je	.L5
	.p2align 4,,10
	.p2align 3
.L9:
	xorl	%ecx, %ecx
	cmpb	$42, (%rax)
	sete	%cl
	addq	$1, %rax
	addq	%rcx, %rdx
	cmpq	%rax, %rsi
	jne	.L9
.L5:
	movq	%rdx, %rax
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	xorl	%eax, %eax
	ret
.L12:
	xorl	%r8d, %r8d
	xorl	%edx, %edx
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z10count_epi8RKSt6vectorIaSaIaEE, .-_Z10count_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z11count_epi32RKSt6vectorIiSaIiEE
	.type	_Z11count_epi32RKSt6vectorIiSaIiEE, @function
_Z11count_epi32RKSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %r8
	movq	(%rdi), %rdi
	cmpq	%r8, %rdi
	je	.L31
	leaq	-4(%r8), %rdx
	movq	%rdi, %rax
	subq	%rdi, %rdx
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rsi
	cmpq	$56, %rdx
	jbe	.L32
	movq	%rsi, %rdx
	vpxor	%xmm1, %xmm1, %xmm1
	vmovdqa32	.LC4(%rip), %zmm4
	vmovdqa32	.LC5(%rip), %zmm3
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rdi, %rdx
	.p2align 4,,10
	.p2align 3
.L19:
	vmovdqu32	(%rax), %zmm6
	addq	$64, %rax
	vpcmpd	$0, %zmm4, %zmm6, %k1
	vmovdqa32	%zmm3, %zmm0{%k1}{z}
	vpmovsxdq	%ymm0, %zmm2
	vextracti32x8	$0x1, %zmm0, %ymm0
	vpaddq	%zmm1, %zmm2, %zmm1
	vpmovsxdq	%ymm0, %zmm0
	vpaddq	%zmm1, %zmm0, %zmm1
	cmpq	%rdx, %rax
	jne	.L19
	vextracti64x4	$0x1, %zmm1, %ymm0
	movq	%rsi, %rdx
	vpaddq	%ymm0, %ymm1, %ymm0
	andq	$-16, %rdx
	vmovdqa	%xmm0, %xmm2
	vextracti64x2	$0x1, %ymm0, %xmm0
	leaq	(%rdi,%rdx,4), %rcx
	vpaddq	%xmm0, %xmm2, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rdx, %rsi
	je	.L40
.L18:
	subq	%rdx, %r9
	subq	%rdx, %rsi
	cmpq	$6, %r9
	jbe	.L21
	vmovdqu8	(%rdi,%rdx,4), %xmm5
	vinserti128	$0x1, 16(%rdi,%rdx,4), %ymm5, %ymm0
	vpcmpd	$0, .LC6(%rip), %ymm0, %k1
	vmovdqa32	.LC7(%rip), %ymm0{%k1}{z}
	vpmovsxdq	%xmm0, %ymm1
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm0, %ymm1, %ymm1
	vmovdqa	%xmm1, %xmm0
	vextracti64x2	$0x1, %ymm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	addq	%rdx, %rax
	movq	%rsi, %rdx
	andq	$-8, %rdx
	leaq	(%rcx,%rdx,4), %rcx
	cmpq	%rdx, %rsi
	je	.L40
.L21:
	xorl	%edx, %edx
	cmpl	$42, (%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	4(%rcx), %rdx
	cmpq	%rdx, %r8
	je	.L40
	xorl	%edx, %edx
	cmpl	$42, 4(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	8(%rcx), %rdx
	cmpq	%rdx, %r8
	je	.L40
	xorl	%edx, %edx
	cmpl	$42, 8(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	12(%rcx), %rdx
	cmpq	%rdx, %r8
	je	.L40
	xorl	%edx, %edx
	cmpl	$42, 12(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	16(%rcx), %rdx
	cmpq	%rdx, %r8
	je	.L40
	xorl	%edx, %edx
	cmpl	$42, 16(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	20(%rcx), %rdx
	cmpq	%rdx, %r8
	je	.L40
	xorl	%edx, %edx
	cmpl	$42, 20(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	24(%rcx), %rdx
	cmpq	%rdx, %r8
	je	.L40
	xorl	%edx, %edx
	cmpl	$42, 24(%rcx)
	sete	%dl
	addq	%rdx, %rax
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L40:
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L31:
	xorl	%eax, %eax
	ret
.L32:
	movq	%rdi, %rcx
	xorl	%edx, %edx
	xorl	%eax, %eax
	jmp	.L18
	.cfi_endproc
.LFE1354:
	.size	_Z11count_epi32RKSt6vectorIiSaIiEE, .-_Z11count_epi32RKSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.align 64
.LC1:
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC2:
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.align 32
.LC3:
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.section	.rodata
	.align 64
.LC4:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.align 64
.LC5:
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.section	.rodata.cst32
	.align 32
.LC6:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.align 32
.LC7:
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
