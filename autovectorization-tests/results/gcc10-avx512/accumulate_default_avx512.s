	.file	"accumulate_default.cpp"
	.text
	.p2align 4
	.globl	_Z15accumulate_epi8RKSt6vectorIaSaIaEE
	.type	_Z15accumulate_epi8RKSt6vectorIaSaIaEE, @function
_Z15accumulate_epi8RKSt6vectorIaSaIaEE:
.LFB894:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rcx
	cmpq	%rsi, %rcx
	je	.L9
	leaq	-1(%rsi), %r9
	movq	%rsi, %rdi
	movq	%rcx, %rax
	subq	%rcx, %r9
	subq	%rcx, %rdi
	cmpq	$62, %r9
	jbe	.L10
	movq	%rdi, %rdx
	vpxor	%xmm2, %xmm2, %xmm2
	andq	$-64, %rdx
	addq	%rcx, %rdx
	.p2align 4,,10
	.p2align 3
.L4:
	vpmovsxbw	(%rax), %zmm1
	vmovdqu8	(%rax), %zmm4
	addq	$64, %rax
	vpmovsxwd	%ymm1, %zmm3
	vextracti64x4	$0x1, %zmm4, %ymm0
	vextracti64x4	$0x1, %zmm1, %ymm1
	vpmovsxbw	%ymm0, %zmm0
	vpaddd	%zmm2, %zmm3, %zmm2
	vpmovsxwd	%ymm1, %zmm1
	vpaddd	%zmm2, %zmm1, %zmm1
	vpmovsxwd	%ymm0, %zmm2
	vextracti64x4	$0x1, %zmm0, %ymm0
	vpaddd	%zmm1, %zmm2, %zmm1
	vpmovsxwd	%ymm0, %zmm0
	vpaddd	%zmm1, %zmm0, %zmm2
	cmpq	%rdx, %rax
	jne	.L4
	vextracti32x8	$0x1, %zmm2, %ymm0
	movq	%rdi, %r8
	vpaddd	%ymm0, %ymm2, %ymm2
	andq	$-64, %r8
	vmovdqa	%xmm2, %xmm0
	vextracti128	$0x1, %ymm2, %xmm2
	leaq	(%rcx,%r8), %rax
	vpaddd	%xmm2, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %edx
	cmpq	%r8, %rdi
	je	.L5
.L3:
	subq	%r8, %r9
	subq	%r8, %rdi
	cmpq	$30, %r9
	jbe	.L8
	vmovdqu8	(%rcx,%r8), %xmm2
	vinserti128	$0x1, 16(%rcx,%r8), %ymm2, %ymm1
	vpmovsxbw	%xmm2, %ymm2
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxwd	%xmm2, %ymm0
	vextracti128	$0x1, %ymm2, %xmm2
	vpmovsxbw	%xmm1, %ymm1
	vpmovsxwd	%xmm2, %ymm2
	vpaddd	%ymm2, %ymm0, %ymm2
	vpmovsxwd	%xmm1, %ymm0
	vpaddd	%ymm2, %ymm0, %ymm2
	vextracti128	$0x1, %ymm1, %xmm0
	vpmovsxwd	%xmm0, %ymm0
	vpaddd	%ymm2, %ymm0, %ymm0
	vmovdqa	%xmm0, %xmm1
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddd	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %ecx
	addl	%ecx, %edx
	movq	%rdi, %rcx
	andq	$-32, %rcx
	addq	%rcx, %rax
	cmpq	%rcx, %rdi
	je	.L5
	.p2align 4,,10
	.p2align 3
.L8:
	movsbl	(%rax), %ecx
	addq	$1, %rax
	addl	%ecx, %edx
	cmpq	%rax, %rsi
	jne	.L8
.L5:
	movslq	%edx, %rax
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	xorl	%eax, %eax
	ret
.L10:
	xorl	%r8d, %r8d
	xorl	%edx, %edx
	jmp	.L3
	.cfi_endproc
.LFE894:
	.size	_Z15accumulate_epi8RKSt6vectorIaSaIaEE, .-_Z15accumulate_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z16accumulate_epi32RKSt6vectorIiSaIiEE
	.type	_Z16accumulate_epi32RKSt6vectorIiSaIiEE, @function
_Z16accumulate_epi32RKSt6vectorIiSaIiEE:
.LFB895:
	.cfi_startproc
	movq	8(%rdi), %r8
	movq	(%rdi), %rsi
	cmpq	%r8, %rsi
	je	.L21
	leaq	-4(%r8), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdx
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rdi
	cmpq	$56, %rdx
	jbe	.L22
	movq	%rdi, %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L17:
	vpaddd	(%rax), %zmm0, %zmm0
	addq	$64, %rax
	cmpq	%rdx, %rax
	jne	.L17
	vmovdqa	%ymm0, %ymm1
	vextracti32x8	$0x1, %zmm0, %ymm0
	movq	%rdi, %rdx
	vpaddd	%ymm0, %ymm1, %ymm0
	andq	$-16, %rdx
	vmovdqa	%xmm0, %xmm1
	vextracti128	$0x1, %ymm0, %xmm0
	leaq	(%rsi,%rdx,4), %rcx
	vpaddd	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %eax
	cmpq	%rdx, %rdi
	je	.L18
.L16:
	subq	%rdx, %r9
	subq	%rdx, %rdi
	cmpq	$6, %r9
	jbe	.L19
	vmovdqu8	(%rsi,%rdx,4), %xmm2
	vinserti128	$0x1, 16(%rsi,%rdx,4), %ymm2, %ymm1
	vmovdqa	%xmm1, %xmm0
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %edx
	addl	%edx, %eax
	movq	%rdi, %rdx
	andq	$-8, %rdx
	leaq	(%rcx,%rdx,4), %rcx
	cmpq	%rdx, %rdi
	je	.L18
.L19:
	leaq	4(%rcx), %rdx
	addl	(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L18
	leaq	8(%rcx), %rdx
	addl	4(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L18
	leaq	12(%rcx), %rdx
	addl	8(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L18
	leaq	16(%rcx), %rdx
	addl	12(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L18
	leaq	20(%rcx), %rdx
	addl	16(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L18
	leaq	24(%rcx), %rdx
	addl	20(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L18
	addl	24(%rcx), %eax
.L18:
	cltq
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L21:
	xorl	%eax, %eax
	ret
.L22:
	movq	%rsi, %rcx
	xorl	%edx, %edx
	xorl	%eax, %eax
	jmp	.L16
	.cfi_endproc
.LFE895:
	.size	_Z16accumulate_epi32RKSt6vectorIiSaIiEE, .-_Z16accumulate_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
