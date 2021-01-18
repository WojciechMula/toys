	.file	"reverse.cpp"
	.text
	.p2align 4
	.globl	_Z12reverse_epi8RSt6vectorIaSaIaEE
	.type	_Z12reverse_epi8RSt6vectorIaSaIaEE, @function
_Z12reverse_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %rsi
	cmpq	%rdi, %rsi
	je	.L23
	leaq	-1(%rdi), %rdx
	cmpq	%rsi, %rdx
	jbe	.L23
	leaq	-2(%rdi), %rcx
	movq	%rsi, %rax
	subq	%rsi, %rcx
	movq	%rcx, %r10
	shrq	%r10
	movq	%r10, %r9
	leaq	1(%r10), %r8
	notq	%r9
	leaq	(%rsi,%r8), %r11
	addq	%rdi, %r9
	cmpq	%r9, %r11
	setbe	%r11b
	cmpq	%rdi, %rsi
	setnb	%r9b
	orb	%r9b, %r11b
	je	.L10
	cmpq	$61, %rcx
	jbe	.L10
	cmpq	$125, %rcx
	jbe	.L12
	movq	%r8, %r9
	leaq	-64(%rdi), %rcx
	vmovdqa64	.LC0(%rip), %zmm2
	andq	$-64, %r9
	addq	%rsi, %r9
	.p2align 4,,10
	.p2align 3
.L5:
	vmovdqu8	(%rcx), %zmm0
	vmovdqu8	(%rax), %zmm1
	addq	$64, %rax
	subq	$64, %rcx
	vpermt2b	%zmm0, %zmm2, %zmm0
	vpermt2b	%zmm1, %zmm2, %zmm1
	vmovdqu8	%zmm0, -64(%rax)
	vmovdqu8	%zmm1, 64(%rcx)
	cmpq	%r9, %rax
	jne	.L5
	movq	%r8, %rcx
	andq	$-64, %rcx
	subq	%rcx, %rdx
	leaq	(%rsi,%rcx), %rax
	cmpq	%rcx, %r8
	je	.L22
.L4:
	subq	%rcx, %r10
	subq	%rcx, %r8
	cmpq	$30, %r10
	jbe	.L9
	vmovdqa	.LC1(%rip), %ymm2
	addq	%rcx, %rsi
	subq	%rcx, %rdi
	movq	%r8, %rcx
	vmovdqu8	(%rsi), %xmm3
	vmovdqu8	-32(%rdi), %xmm4
	andq	$-32, %rcx
	vinserti128	$0x1, 16(%rsi), %ymm3, %ymm0
	vinserti128	$0x1, -16(%rdi), %ymm4, %ymm1
	subq	%rcx, %rdx
	addq	%rcx, %rax
	vperm2i128	$1, %ymm1, %ymm1, %ymm1
	vperm2i128	$1, %ymm0, %ymm0, %ymm0
	vpshufb	%ymm2, %ymm1, %ymm1
	vpshufb	%ymm2, %ymm0, %ymm0
	vmovdqu8	%xmm1, (%rsi)
	vextracti128	$0x1, %ymm1, 16(%rsi)
	vextracti128	$0x1, %ymm0, -16(%rdi)
	vmovdqu8	%xmm0, -32(%rdi)
	cmpq	%rcx, %r8
	je	.L22
	.p2align 4,,10
	.p2align 3
.L9:
	movzbl	(%rax), %ecx
	movzbl	(%rdx), %esi
	addq	$1, %rax
	subq	$1, %rdx
	movb	%sil, -1(%rax)
	movb	%cl, 1(%rdx)
	cmpq	%rax, %rdx
	ja	.L9
.L22:
	vzeroupper
.L23:
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	movzbl	(%rax), %ecx
	movzbl	(%rdx), %esi
	addq	$1, %rax
	subq	$1, %rdx
	movb	%sil, -1(%rax)
	movb	%cl, 1(%rdx)
	cmpq	%rdx, %rax
	jb	.L10
	ret
.L12:
	xorl	%ecx, %ecx
	jmp	.L4
	.cfi_endproc
.LFE1353:
	.size	_Z12reverse_epi8RSt6vectorIaSaIaEE, .-_Z12reverse_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z13reverse_epi32RSt6vectorIiSaIiEE
	.type	_Z13reverse_epi32RSt6vectorIiSaIiEE, @function
_Z13reverse_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	8(%rdi), %r8
	movq	(%rdi), %rsi
	cmpq	%r8, %rsi
	je	.L51
	leaq	-4(%r8), %rdx
	cmpq	%rsi, %rdx
	jbe	.L51
	leaq	-5(%r8), %rcx
	movq	%rsi, %rax
	subq	%rsi, %rcx
	movq	%rcx, %r10
	shrq	$3, %r10
	leaq	1(%r10), %rdi
	movq	%rdi, %r9
	leaq	(%rsi,%rdi,4), %r11
	negq	%r9
	leaq	(%r8,%r9,4), %r9
	cmpq	%r9, %r11
	setbe	%r11b
	cmpq	%r8, %rsi
	setnb	%r9b
	orb	%r9b, %r11b
	je	.L33
	cmpq	$55, %rcx
	jbe	.L33
	cmpq	$119, %rcx
	jbe	.L35
	movq	%rdi, %r9
	leaq	-64(%r8), %rcx
	vmovdqa32	.LC2(%rip), %zmm1
	shrq	$4, %r9
	salq	$6, %r9
	addq	%rsi, %r9
	.p2align 4,,10
	.p2align 3
.L29:
	vmovdqu32	(%rax), %zmm0
	vpermd	(%rcx), %zmm1, %zmm2
	addq	$64, %rax
	subq	$64, %rcx
	vpermd	%zmm0, %zmm1, %zmm0
	vmovdqu32	%zmm2, -64(%rax)
	vmovdqu32	%zmm0, 64(%rcx)
	cmpq	%r9, %rax
	jne	.L29
	movq	%rdi, %rcx
	andq	$-16, %rcx
	movq	%rcx, %rax
	negq	%rax
	leaq	(%rdx,%rax,4), %rdx
	leaq	(%rsi,%rcx,4), %rax
	cmpq	%rcx, %rdi
	je	.L50
.L28:
	subq	%rcx, %r10
	subq	%rcx, %rdi
	cmpq	$6, %r10
	jbe	.L31
	vmovdqa	.LC3(%rip), %ymm2
	leaq	(%rsi,%rcx,4), %rsi
	notq	%rcx
	leaq	-28(%r8,%rcx,4), %rcx
	vmovdqu8	(%rsi), %xmm3
	vinserti128	$0x1, 16(%rsi), %ymm3, %ymm0
	vmovdqu8	(%rcx), %xmm4
	vinserti128	$0x1, 16(%rcx), %ymm4, %ymm1
	vpermd	%ymm0, %ymm2, %ymm0
	vpermd	%ymm1, %ymm2, %ymm1
	vmovdqu8	%xmm1, (%rsi)
	vextracti128	$0x1, %ymm1, 16(%rsi)
	vextracti128	$0x1, %ymm0, 16(%rcx)
	vmovdqu8	%xmm0, (%rcx)
	movq	%rdi, %rcx
	andq	$-8, %rcx
	movq	%rcx, %rsi
	leaq	(%rax,%rcx,4), %rax
	negq	%rsi
	leaq	(%rdx,%rsi,4), %rdx
	cmpq	%rcx, %rdi
	je	.L50
.L31:
	movl	(%rax), %ecx
	movl	(%rdx), %esi
	movl	%esi, (%rax)
	leaq	4(%rax), %rsi
	movl	%ecx, (%rdx)
	leaq	-4(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L50
	movl	4(%rax), %ecx
	movl	-4(%rdx), %esi
	movl	%esi, 4(%rax)
	leaq	-8(%rdx), %rsi
	movl	%ecx, -4(%rdx)
	leaq	8(%rax), %rcx
	cmpq	%rcx, %rsi
	jbe	.L50
	movl	8(%rax), %ecx
	movl	-8(%rdx), %esi
	movl	%esi, 8(%rax)
	leaq	12(%rax), %rsi
	movl	%ecx, -8(%rdx)
	leaq	-12(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L50
	movl	12(%rax), %ecx
	movl	-12(%rdx), %esi
	movl	%esi, 12(%rax)
	leaq	16(%rax), %rsi
	movl	%ecx, -12(%rdx)
	leaq	-16(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L50
	movl	16(%rax), %ecx
	movl	-16(%rdx), %esi
	movl	%esi, 16(%rax)
	leaq	20(%rax), %rsi
	movl	%ecx, -16(%rdx)
	leaq	-20(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L50
	movl	20(%rax), %ecx
	movl	-20(%rdx), %esi
	movl	%esi, 20(%rax)
	leaq	24(%rax), %rsi
	movl	%ecx, -20(%rdx)
	leaq	-24(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L50
	movl	24(%rax), %ecx
	movl	-24(%rdx), %esi
	movl	%esi, 24(%rax)
	movl	%ecx, -24(%rdx)
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L33:
	movl	(%rax), %ecx
	movl	(%rdx), %esi
	addq	$4, %rax
	subq	$4, %rdx
	movl	%esi, -4(%rax)
	movl	%ecx, 4(%rdx)
	cmpq	%rdx, %rax
	jb	.L33
	ret
	.p2align 4,,10
	.p2align 3
.L50:
	vzeroupper
.L51:
	ret
.L35:
	xorl	%ecx, %ecx
	jmp	.L28
	.cfi_endproc
.LFE1354:
	.size	_Z13reverse_epi32RSt6vectorIiSaIiEE, .-_Z13reverse_epi32RSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
	.byte	63
	.byte	62
	.byte	61
	.byte	60
	.byte	59
	.byte	58
	.byte	57
	.byte	56
	.byte	55
	.byte	54
	.byte	53
	.byte	52
	.byte	51
	.byte	50
	.byte	49
	.byte	48
	.byte	47
	.byte	46
	.byte	45
	.byte	44
	.byte	43
	.byte	42
	.byte	41
	.byte	40
	.byte	39
	.byte	38
	.byte	37
	.byte	36
	.byte	35
	.byte	34
	.byte	33
	.byte	32
	.byte	31
	.byte	30
	.byte	29
	.byte	28
	.byte	27
	.byte	26
	.byte	25
	.byte	24
	.byte	23
	.byte	22
	.byte	21
	.byte	20
	.byte	19
	.byte	18
	.byte	17
	.byte	16
	.byte	15
	.byte	14
	.byte	13
	.byte	12
	.byte	11
	.byte	10
	.byte	9
	.byte	8
	.byte	7
	.byte	6
	.byte	5
	.byte	4
	.byte	3
	.byte	2
	.byte	1
	.byte	0
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC1:
	.byte	15
	.byte	14
	.byte	13
	.byte	12
	.byte	11
	.byte	10
	.byte	9
	.byte	8
	.byte	7
	.byte	6
	.byte	5
	.byte	4
	.byte	3
	.byte	2
	.byte	1
	.byte	0
	.byte	15
	.byte	14
	.byte	13
	.byte	12
	.byte	11
	.byte	10
	.byte	9
	.byte	8
	.byte	7
	.byte	6
	.byte	5
	.byte	4
	.byte	3
	.byte	2
	.byte	1
	.byte	0
	.section	.rodata
	.align 64
.LC2:
	.long	15
	.long	14
	.long	13
	.long	12
	.long	11
	.long	10
	.long	9
	.long	8
	.long	7
	.long	6
	.long	5
	.long	4
	.long	3
	.long	2
	.long	1
	.long	0
	.section	.rodata.cst32
	.align 32
.LC3:
	.long	7
	.long	6
	.long	5
	.long	4
	.long	3
	.long	2
	.long	1
	.long	0
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
