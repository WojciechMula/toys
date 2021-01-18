	.file	"transform_inc.cpp"
	.text
	.p2align 4
	.globl	_Z18transform_inc_epi8RSt6vectorIaSaIaEE
	.type	_Z18transform_inc_epi8RSt6vectorIaSaIaEE, @function
_Z18transform_inc_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	(%rdi), %rdx
	movq	8(%rdi), %rcx
	cmpq	%rdx, %rcx
	je	.L13
	leaq	-1(%rcx), %r8
	movq	%rcx, %rsi
	movq	%rdx, %rax
	subq	%rdx, %r8
	subq	%rdx, %rsi
	cmpq	$62, %r8
	jbe	.L9
	vmovdqa64	.LC0(%rip), %zmm1
	movq	%rsi, %rdi
	andq	$-64, %rdi
	addq	%rdx, %rdi
	.p2align 4,,10
	.p2align 3
.L4:
	vpaddb	(%rax), %zmm1, %zmm0
	addq	$64, %rax
	vmovdqu8	%zmm0, -64(%rax)
	cmpq	%rdi, %rax
	jne	.L4
	movq	%rsi, %rdi
	andq	$-64, %rdi
	leaq	(%rdx,%rdi), %rax
	cmpq	%rdi, %rsi
	je	.L12
.L3:
	subq	%rdi, %r8
	subq	%rdi, %rsi
	cmpq	$30, %r8
	jbe	.L8
	addq	%rdi, %rdx
	vmovdqu8	(%rdx), %xmm2
	vinserti128	$0x1, 16(%rdx), %ymm2, %ymm0
	vpaddb	.LC1(%rip), %ymm0, %ymm0
	vmovdqu8	%xmm0, (%rdx)
	vextracti128	$0x1, %ymm0, 16(%rdx)
	movq	%rsi, %rdx
	andq	$-32, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %rsi
	je	.L12
	.p2align 4,,10
	.p2align 3
.L8:
	addb	$42, (%rax)
	addq	$1, %rax
	cmpq	%rax, %rcx
	jne	.L8
.L12:
	vzeroupper
.L13:
	ret
.L9:
	xorl	%edi, %edi
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z18transform_inc_epi8RSt6vectorIaSaIaEE, .-_Z18transform_inc_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z19transform_inc_epi32RSt6vectorIiSaIiEE
	.type	_Z19transform_inc_epi32RSt6vectorIiSaIiEE, @function
_Z19transform_inc_epi32RSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	(%rdi), %rsi
	movq	8(%rdi), %rdi
	cmpq	%rsi, %rdi
	je	.L31
	leaq	-4(%rdi), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdx
	movq	%rdx, %r8
	shrq	$2, %r8
	leaq	1(%r8), %rcx
	cmpq	$56, %rdx
	jbe	.L22
	vmovdqa32	.LC2(%rip), %zmm1
	movq	%rcx, %rdx
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L18:
	vpaddd	(%rax), %zmm1, %zmm0
	addq	$64, %rax
	vmovdqu32	%zmm0, -64(%rax)
	cmpq	%rdx, %rax
	jne	.L18
	movq	%rcx, %rdx
	andq	$-16, %rdx
	leaq	(%rsi,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L30
.L17:
	subq	%rdx, %r8
	subq	%rdx, %rcx
	cmpq	$6, %r8
	jbe	.L20
	leaq	(%rsi,%rdx,4), %rdx
	vmovdqu8	(%rdx), %xmm2
	vinserti128	$0x1, 16(%rdx), %ymm2, %ymm0
	vpaddd	.LC3(%rip), %ymm0, %ymm0
	vmovdqu8	%xmm0, (%rdx)
	vextracti128	$0x1, %ymm0, 16(%rdx)
	movq	%rcx, %rdx
	andq	$-8, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rcx
	je	.L30
.L20:
	leaq	4(%rax), %rdx
	addl	$42, (%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	8(%rax), %rdx
	addl	$42, 4(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	12(%rax), %rdx
	addl	$42, 8(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	16(%rax), %rdx
	addl	$42, 12(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	20(%rax), %rdx
	addl	$42, 16(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	leaq	24(%rax), %rdx
	addl	$42, 20(%rax)
	cmpq	%rdx, %rdi
	je	.L30
	addl	$42, 24(%rax)
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	vzeroupper
.L31:
	ret
.L22:
	xorl	%edx, %edx
	jmp	.L17
	.cfi_endproc
.LFE1357:
	.size	_Z19transform_inc_epi32RSt6vectorIiSaIiEE, .-_Z19transform_inc_epi32RSt6vectorIiSaIiEE
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
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC1:
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
	.section	.rodata
	.align 64
.LC2:
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
	.section	.rodata.cst32
	.align 32
.LC3:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
