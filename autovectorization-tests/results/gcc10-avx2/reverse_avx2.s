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
	je	.L21
	leaq	-1(%rdi), %rdx
	cmpq	%rsi, %rdx
	jbe	.L21
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
	je	.L9
	cmpq	$29, %rcx
	jbe	.L9
	cmpq	$61, %rcx
	jbe	.L11
	movq	%r8, %r9
	vmovdqa	.LC0(%rip), %ymm2
	leaq	-32(%rdi), %rcx
	andq	$-32, %r9
	addq	%rsi, %r9
	.p2align 4,,10
	.p2align 3
.L5:
	vmovdqu	(%rcx), %xmm4
	vmovdqu	(%rax), %xmm3
	addq	$32, %rax
	subq	$32, %rcx
	vinserti128	$0x1, 48(%rcx), %ymm4, %ymm1
	vinserti128	$0x1, -16(%rax), %ymm3, %ymm0
	vperm2i128	$1, %ymm1, %ymm1, %ymm1
	vperm2i128	$1, %ymm0, %ymm0, %ymm0
	vpshufb	%ymm2, %ymm1, %ymm1
	vpshufb	%ymm2, %ymm0, %ymm0
	vmovdqu	%xmm1, -32(%rax)
	vextracti128	$0x1, %ymm1, -16(%rax)
	vextracti128	$0x1, %ymm0, 48(%rcx)
	vmovdqu	%xmm0, 32(%rcx)
	cmpq	%r9, %rax
	jne	.L5
	movq	%r8, %rcx
	andq	$-32, %rcx
	subq	%rcx, %rdx
	leaq	(%rsi,%rcx), %rax
	cmpq	%rcx, %r8
	je	.L23
	vzeroupper
.L4:
	subq	%rcx, %r10
	subq	%rcx, %r8
	cmpq	$14, %r10
	jbe	.L7
	addq	%rcx, %rsi
	subq	%rcx, %rdi
	vmovdqa	.LC1(%rip), %xmm2
	movq	%r8, %rcx
	vmovdqu	(%rsi), %xmm0
	vmovdqu	-16(%rdi), %xmm5
	andq	$-16, %rcx
	subq	%rcx, %rdx
	addq	%rcx, %rax
	vpshufb	%xmm2, %xmm5, %xmm1
	vpshufb	%xmm2, %xmm0, %xmm0
	vmovdqu	%xmm1, (%rsi)
	vmovdqu	%xmm0, -16(%rdi)
	cmpq	%rcx, %r8
	je	.L21
.L7:
	movzbl	(%rax), %ecx
	movzbl	(%rdx), %esi
	movb	%sil, (%rax)
	leaq	1(%rax), %rsi
	movb	%cl, (%rdx)
	leaq	-1(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	1(%rax), %ecx
	movzbl	-1(%rdx), %esi
	movb	%sil, 1(%rax)
	leaq	-2(%rdx), %rsi
	movb	%cl, -1(%rdx)
	leaq	2(%rax), %rcx
	cmpq	%rcx, %rsi
	jbe	.L21
	movzbl	2(%rax), %ecx
	movzbl	-2(%rdx), %esi
	movb	%sil, 2(%rax)
	leaq	3(%rax), %rsi
	movb	%cl, -2(%rdx)
	leaq	-3(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	3(%rax), %ecx
	movzbl	-3(%rdx), %esi
	movb	%sil, 3(%rax)
	leaq	4(%rax), %rsi
	movb	%cl, -3(%rdx)
	leaq	-4(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	4(%rax), %ecx
	movzbl	-4(%rdx), %esi
	movb	%sil, 4(%rax)
	leaq	5(%rax), %rsi
	movb	%cl, -4(%rdx)
	leaq	-5(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	5(%rax), %ecx
	movzbl	-5(%rdx), %esi
	movb	%sil, 5(%rax)
	leaq	6(%rax), %rsi
	movb	%cl, -5(%rdx)
	leaq	-6(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	6(%rax), %ecx
	movzbl	-6(%rdx), %esi
	movb	%sil, 6(%rax)
	leaq	7(%rax), %rsi
	movb	%cl, -6(%rdx)
	leaq	-7(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	7(%rax), %ecx
	movzbl	-7(%rdx), %esi
	movb	%sil, 7(%rax)
	leaq	8(%rax), %rsi
	movb	%cl, -7(%rdx)
	leaq	-8(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	8(%rax), %ecx
	movzbl	-8(%rdx), %esi
	movb	%sil, 8(%rax)
	leaq	9(%rax), %rsi
	movb	%cl, -8(%rdx)
	leaq	-9(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	9(%rax), %ecx
	movzbl	-9(%rdx), %esi
	movb	%sil, 9(%rax)
	leaq	10(%rax), %rsi
	movb	%cl, -9(%rdx)
	leaq	-10(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	10(%rax), %ecx
	movzbl	-10(%rdx), %esi
	movb	%sil, 10(%rax)
	leaq	11(%rax), %rsi
	movb	%cl, -10(%rdx)
	leaq	-11(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	11(%rax), %ecx
	movzbl	-11(%rdx), %esi
	movb	%sil, 11(%rax)
	leaq	12(%rax), %rsi
	movb	%cl, -11(%rdx)
	leaq	-12(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	12(%rax), %ecx
	movzbl	-12(%rdx), %esi
	movb	%sil, 12(%rax)
	leaq	13(%rax), %rsi
	movb	%cl, -12(%rdx)
	leaq	-13(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	13(%rax), %ecx
	movzbl	-13(%rdx), %esi
	movb	%sil, 13(%rax)
	leaq	14(%rax), %rsi
	movb	%cl, -13(%rdx)
	leaq	-14(%rdx), %rcx
	cmpq	%rcx, %rsi
	jnb	.L21
	movzbl	14(%rax), %ecx
	movzbl	-14(%rdx), %esi
	movb	%sil, 14(%rax)
	movb	%cl, -14(%rdx)
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	movzbl	(%rax), %ecx
	movzbl	(%rdx), %esi
	addq	$1, %rax
	subq	$1, %rdx
	movb	%sil, -1(%rax)
	movb	%cl, 1(%rdx)
	cmpq	%rdx, %rax
	jb	.L9
.L21:
	ret
.L11:
	xorl	%ecx, %ecx
	jmp	.L4
.L23:
	vzeroupper
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z12reverse_epi8RSt6vectorIaSaIaEE, .-_Z12reverse_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z13reverse_epi32RSt6vectorIiSaIiEE
	.type	_Z13reverse_epi32RSt6vectorIiSaIiEE, @function
_Z13reverse_epi32RSt6vectorIiSaIiEE:
.LFB1354:
	.cfi_startproc
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %rsi
	cmpq	%rdi, %rsi
	je	.L44
	leaq	-4(%rdi), %rcx
	cmpq	%rsi, %rcx
	jbe	.L44
	leaq	-5(%rdi), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdx
	movq	%rdx, %r10
	shrq	$3, %r10
	leaq	1(%r10), %r8
	movq	%r8, %r9
	leaq	(%rsi,%r8,4), %r11
	negq	%r9
	leaq	(%rdi,%r9,4), %r9
	cmpq	%r9, %r11
	setbe	%r11b
	cmpq	%rdi, %rsi
	setnb	%r9b
	orb	%r9b, %r11b
	je	.L32
	cmpq	$23, %rdx
	jbe	.L32
	cmpq	$55, %rdx
	jbe	.L34
	movq	%r8, %r9
	vmovdqa	.LC2(%rip), %ymm2
	leaq	-32(%rdi), %rdx
	shrq	$3, %r9
	salq	$5, %r9
	addq	%rsi, %r9
	.p2align 4,,10
	.p2align 3
.L28:
	vmovdqu	(%rdx), %xmm4
	vmovdqu	(%rax), %xmm3
	addq	$32, %rax
	subq	$32, %rdx
	vinserti128	$0x1, 48(%rdx), %ymm4, %ymm1
	vinserti128	$0x1, -16(%rax), %ymm3, %ymm0
	vpermd	%ymm1, %ymm2, %ymm1
	vpermd	%ymm0, %ymm2, %ymm0
	vmovdqu	%xmm1, -32(%rax)
	vextracti128	$0x1, %ymm1, -16(%rax)
	vextracti128	$0x1, %ymm0, 48(%rdx)
	vmovdqu	%xmm0, 32(%rdx)
	cmpq	%r9, %rax
	jne	.L28
	movq	%r8, %rax
	andq	$-8, %rax
	movq	%rax, %rdx
	negq	%rdx
	leaq	(%rcx,%rdx,4), %rcx
	leaq	(%rsi,%rax,4), %rdx
	cmpq	%rax, %r8
	je	.L45
	vzeroupper
.L27:
	subq	%rax, %r10
	subq	%rax, %r8
	cmpq	$2, %r10
	jbe	.L30
	leaq	(%rsi,%rax,4), %rsi
	notq	%rax
	vmovdqu	(%rsi), %xmm0
	vpshufd	$27, -12(%rdi,%rax,4), %xmm1
	vmovdqu	%xmm1, (%rsi)
	vpshufd	$27, %xmm0, %xmm0
	vmovdqu	%xmm0, -12(%rdi,%rax,4)
	movq	%r8, %rax
	andq	$-4, %rax
	movq	%rax, %rsi
	leaq	(%rdx,%rax,4), %rdx
	negq	%rsi
	leaq	(%rcx,%rsi,4), %rcx
	cmpq	%rax, %r8
	je	.L44
.L30:
	movl	(%rdx), %eax
	movl	(%rcx), %esi
	movl	%esi, (%rdx)
	leaq	4(%rdx), %rsi
	movl	%eax, (%rcx)
	leaq	-4(%rcx), %rax
	cmpq	%rax, %rsi
	jnb	.L44
	movl	4(%rdx), %eax
	movl	-4(%rcx), %esi
	movl	%esi, 4(%rdx)
	leaq	-8(%rcx), %rsi
	movl	%eax, -4(%rcx)
	leaq	8(%rdx), %rax
	cmpq	%rax, %rsi
	jbe	.L44
	movl	8(%rdx), %eax
	movl	-8(%rcx), %esi
	movl	%esi, 8(%rdx)
	movl	%eax, -8(%rcx)
	ret
	.p2align 4,,10
	.p2align 3
.L32:
	movl	(%rax), %edx
	movl	(%rcx), %esi
	addq	$4, %rax
	subq	$4, %rcx
	movl	%esi, -4(%rax)
	movl	%edx, 4(%rcx)
	cmpq	%rcx, %rax
	jb	.L32
.L44:
	ret
.L45:
	vzeroupper
	ret
.L34:
	movq	%rsi, %rdx
	xorl	%eax, %eax
	jmp	.L27
	.cfi_endproc
.LFE1354:
	.size	_Z13reverse_epi32RSt6vectorIiSaIiEE, .-_Z13reverse_epi32RSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
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
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
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
	.section	.rodata.cst32
	.align 32
.LC2:
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
