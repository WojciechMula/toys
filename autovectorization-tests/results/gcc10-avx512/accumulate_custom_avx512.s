	.file	"accumulate_custom.cpp"
	.text
	.p2align 4
	.globl	_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE
	.type	_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE, @function
_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE:
.LFB894:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rax
	cmpq	%rsi, %rax
	je	.L4
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L3:
	movsbl	(%rax), %ecx
	movsbl	%dl, %edx
	addq	$1, %rax
	subl	%ecx, %edx
	cmpq	%rsi, %rax
	jne	.L3
	movslq	%edx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE894:
	.size	_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE, .-_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE
	.type	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE, @function
_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE:
.LFB898:
	.cfi_startproc
	movq	8(%rdi), %r8
	movq	(%rdi), %rsi
	cmpq	%r8, %rsi
	je	.L14
	leaq	-4(%r8), %rdx
	movq	%rsi, %rax
	subq	%rsi, %rdx
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rdi
	cmpq	$56, %rdx
	jbe	.L15
	movq	%rdi, %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	shrq	$4, %rdx
	salq	$6, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L10:
	vpsubd	(%rax), %zmm0, %zmm0
	addq	$64, %rax
	cmpq	%rdx, %rax
	jne	.L10
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
	je	.L11
.L9:
	subq	%rdx, %r9
	subq	%rdx, %rdi
	cmpq	$6, %r9
	jbe	.L12
	vmovdqu8	(%rsi,%rdx,4), %xmm2
	vpxor	%xmm1, %xmm1, %xmm1
	vinserti128	$0x1, 16(%rsi,%rdx,4), %ymm2, %ymm0
	vpsubd	%ymm0, %ymm1, %ymm1
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
	je	.L11
.L12:
	leaq	4(%rcx), %rdx
	subl	(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L11
	leaq	8(%rcx), %rdx
	subl	4(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L11
	leaq	12(%rcx), %rdx
	subl	8(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L11
	leaq	16(%rcx), %rdx
	subl	12(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L11
	leaq	20(%rcx), %rdx
	subl	16(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L11
	leaq	24(%rcx), %rdx
	subl	20(%rcx), %eax
	cmpq	%rdx, %r8
	je	.L11
	subl	24(%rcx), %eax
.L11:
	cltq
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L14:
	xorl	%eax, %eax
	ret
.L15:
	movq	%rsi, %rcx
	xorl	%edx, %edx
	xorl	%eax, %eax
	jmp	.L9
	.cfi_endproc
.LFE898:
	.size	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE, .-_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
