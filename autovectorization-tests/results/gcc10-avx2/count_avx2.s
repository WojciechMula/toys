	.file	"count.cpp"
	.text
	.p2align 4
	.globl	_Z10count_epi8RKSt6vectorIaSaIaEE
	.type	_Z10count_epi8RKSt6vectorIaSaIaEE, @function
_Z10count_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %r10
	movq	(%rdi), %rsi
	cmpq	%r10, %rsi
	je	.L24
	leaq	-1(%r10), %rdi
	movq	%r10, %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdi
	subq	%rsi, %rdx
	cmpq	$30, %rdi
	jbe	.L25
	movq	%rdx, %rcx
	vmovdqa	.LC0(%rip), %ymm4
	vmovdqa	.LC1(%rip), %ymm3
	vpxor	%xmm5, %xmm5, %xmm5
	andq	$-32, %rcx
	addq	%rsi, %rcx
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu	(%rax), %xmm7
	vinserti128	$0x1, 16(%rax), %ymm7, %ymm0
	addq	$32, %rax
	vpcmpeqb	%ymm4, %ymm0, %ymm0
	vpand	%ymm3, %ymm0, %ymm0
	vpmovsxbw	%xmm0, %ymm1
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxwd	%xmm1, %ymm2
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxbw	%xmm0, %ymm0
	vpmovsxdq	%xmm2, %ymm7
	vextracti128	$0x1, %ymm2, %xmm2
	vpmovsxwd	%xmm1, %ymm1
	vpaddq	%ymm5, %ymm7, %ymm5
	vpmovsxdq	%xmm2, %ymm2
	vpmovsxwd	%xmm0, %ymm6
	vpaddq	%ymm5, %ymm2, %ymm2
	vpmovsxdq	%xmm1, %ymm5
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddq	%ymm2, %ymm5, %ymm2
	vpmovsxdq	%xmm1, %ymm1
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm2, %ymm1, %ymm1
	vpmovsxdq	%xmm6, %ymm2
	vpmovsxwd	%xmm0, %ymm0
	vpaddq	%ymm1, %ymm2, %ymm1
	vextracti128	$0x1, %ymm6, %xmm2
	vpmovsxdq	%xmm0, %ymm5
	vpmovsxdq	%xmm2, %ymm2
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm1, %ymm2, %ymm2
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm2, %ymm5, %ymm2
	vpaddq	%ymm2, %ymm0, %ymm5
	cmpq	%rcx, %rax
	jne	.L4
	vextracti128	$0x1, %ymm5, %xmm0
	movq	%rdx, %r8
	vpaddq	%xmm0, %xmm5, %xmm0
	andq	$-32, %r8
	vpsrldq	$8, %xmm0, %xmm5
	leaq	(%rsi,%r8), %r9
	vpaddq	%xmm5, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%r8, %rdx
	je	.L29
	vzeroupper
.L3:
	movq	%rdx, %rcx
	subq	%r8, %rdi
	subq	%r8, %rcx
	cmpq	$14, %rdi
	jbe	.L6
	vmovdqa	.LC2(%rip), %xmm1
	vpcmpeqb	(%rsi,%r8), %xmm1, %xmm1
	vpand	.LC3(%rip), %xmm1, %xmm1
	vpmovsxbw	%xmm1, %xmm2
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxwd	%xmm2, %xmm3
	vpsrldq	$8, %xmm2, %xmm2
	vpmovsxbw	%xmm1, %xmm1
	vpmovsxdq	%xmm3, %xmm4
	vpsrldq	$8, %xmm3, %xmm3
	vpmovsxwd	%xmm2, %xmm2
	vpmovsxdq	%xmm3, %xmm3
	vpmovsxwd	%xmm1, %xmm0
	vpaddq	%xmm3, %xmm4, %xmm4
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxdq	%xmm2, %xmm3
	vpsrldq	$8, %xmm2, %xmm2
	vpaddq	%xmm4, %xmm3, %xmm3
	vpmovsxwd	%xmm1, %xmm1
	vpmovsxdq	%xmm2, %xmm2
	vpaddq	%xmm3, %xmm2, %xmm2
	vpmovsxdq	%xmm0, %xmm3
	vpaddq	%xmm2, %xmm3, %xmm3
	vpsrldq	$8, %xmm0, %xmm2
	vpmovsxdq	%xmm1, %xmm0
	vpmovsxdq	%xmm2, %xmm2
	vpaddq	%xmm3, %xmm2, %xmm2
	vpaddq	%xmm2, %xmm0, %xmm2
	vpsrldq	$8, %xmm1, %xmm0
	vpmovsxdq	%xmm0, %xmm0
	vpaddq	%xmm2, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	addq	%rdx, %rax
	movq	%rcx, %rdx
	andq	$-16, %rdx
	addq	%rdx, %r9
	cmpq	%rdx, %rcx
	je	.L1
.L6:
	xorl	%edx, %edx
	cmpb	$42, (%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	1(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 1(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	2(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 2(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	3(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 3(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	4(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 4(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	5(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 5(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	6(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 6(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	7(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 7(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	8(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 8(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	9(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 9(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	10(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 10(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	11(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 11(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	12(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 12(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	13(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 13(%r9)
	sete	%dl
	addq	%rdx, %rax
	leaq	14(%r9), %rdx
	cmpq	%rdx, %r10
	je	.L1
	xorl	%edx, %edx
	cmpb	$42, 14(%r9)
	sete	%dl
	addq	%rdx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L24:
	xorl	%eax, %eax
.L1:
	ret
.L25:
	movq	%rsi, %r9
	xorl	%r8d, %r8d
	xorl	%eax, %eax
	jmp	.L3
.L29:
	vzeroupper
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z10count_epi8RKSt6vectorIaSaIaEE, .-_Z10count_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z11count_epi32RKSt6vectorIiSaIiEE
	.type	_Z11count_epi32RKSt6vectorIiSaIiEE, @function
_Z11count_epi32RKSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rcx
	cmpq	%rsi, %rcx
	je	.L43
	leaq	-4(%rsi), %rdx
	movq	%rcx, %rax
	subq	%rcx, %rdx
	movq	%rdx, %rdi
	shrq	$2, %rdi
	addq	$1, %rdi
	cmpq	$24, %rdx
	jbe	.L44
	movq	%rdi, %rdx
	vmovdqa	.LC4(%rip), %ymm4
	vmovdqa	.LC5(%rip), %ymm3
	vpxor	%xmm1, %xmm1, %xmm1
	shrq	$3, %rdx
	salq	$5, %rdx
	addq	%rcx, %rdx
	.p2align 4,,10
	.p2align 3
.L33:
	vmovdqu	(%rax), %xmm5
	vinserti128	$0x1, 16(%rax), %ymm5, %ymm0
	addq	$32, %rax
	vpcmpeqd	%ymm0, %ymm4, %ymm0
	vpand	%ymm3, %ymm0, %ymm0
	vpmovsxdq	%xmm0, %ymm2
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm1, %ymm2, %ymm1
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm1, %ymm0, %ymm1
	cmpq	%rdx, %rax
	jne	.L33
	vextracti128	$0x1, %ymm1, %xmm0
	movq	%rdi, %rdx
	vpaddq	%xmm0, %xmm1, %xmm0
	andq	$-8, %rdx
	vpsrldq	$8, %xmm0, %xmm1
	leaq	(%rcx,%rdx,4), %rcx
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rdx, %rdi
	je	.L47
	vzeroupper
.L32:
	xorl	%edx, %edx
	cmpl	$42, (%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	4(%rcx), %rdx
	cmpq	%rdx, %rsi
	je	.L30
	xorl	%edx, %edx
	cmpl	$42, 4(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	8(%rcx), %rdx
	cmpq	%rdx, %rsi
	je	.L30
	xorl	%edx, %edx
	cmpl	$42, 8(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	12(%rcx), %rdx
	cmpq	%rdx, %rsi
	je	.L30
	xorl	%edx, %edx
	cmpl	$42, 12(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	16(%rcx), %rdx
	cmpq	%rdx, %rsi
	je	.L30
	xorl	%edx, %edx
	cmpl	$42, 16(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	20(%rcx), %rdx
	cmpq	%rdx, %rsi
	je	.L30
	xorl	%edx, %edx
	cmpl	$42, 20(%rcx)
	sete	%dl
	addq	%rdx, %rax
	leaq	24(%rcx), %rdx
	cmpq	%rdx, %rsi
	je	.L30
	xorl	%edx, %edx
	cmpl	$42, 24(%rcx)
	sete	%dl
	addq	%rdx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L43:
	xorl	%eax, %eax
.L30:
	ret
	.p2align 4,,10
	.p2align 3
.L47:
	vzeroupper
	ret
.L44:
	xorl	%eax, %eax
	jmp	.L32
	.cfi_endproc
.LFE1354:
	.size	_Z11count_epi32RKSt6vectorIiSaIiEE, .-_Z11count_epi32RKSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
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
	.align 32
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
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
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
	.align 16
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
	.section	.rodata.cst32
	.align 32
.LC4:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.align 32
.LC5:
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
