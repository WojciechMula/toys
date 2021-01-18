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
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	cmpq	%rsi, %rdx
	je	.L12
	leaq	-4(%rsi), %rcx
	movq	%rdx, %rax
	subq	%rdx, %rcx
	movq	%rcx, %rdi
	shrq	$2, %rdi
	addq	$1, %rdi
	cmpq	$24, %rcx
	jbe	.L13
	movq	%rdi, %rcx
	vpxor	%xmm2, %xmm2, %xmm2
	shrq	$3, %rcx
	salq	$5, %rcx
	addq	%rdx, %rcx
	.p2align 4,,10
	.p2align 3
.L10:
	vmovdqu	(%rax), %xmm3
	vinserti128	$0x1, 16(%rax), %ymm3, %ymm1
	addq	$32, %rax
	vpsubd	%ymm1, %ymm2, %ymm2
	cmpq	%rcx, %rax
	jne	.L10
	vmovdqa	%xmm2, %xmm0
	vextracti128	$0x1, %ymm2, %xmm2
	movq	%rdi, %rcx
	vpaddd	%xmm2, %xmm0, %xmm0
	andq	$-8, %rcx
	vpsrldq	$8, %xmm0, %xmm1
	leaq	(%rdx,%rcx,4), %rdx
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %eax
	cmpq	%rcx, %rdi
	je	.L16
	vzeroupper
.L9:
	leaq	4(%rdx), %rcx
	subl	(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L11
	leaq	8(%rdx), %rcx
	subl	4(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L11
	leaq	12(%rdx), %rcx
	subl	8(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L11
	leaq	16(%rdx), %rcx
	subl	12(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L11
	leaq	20(%rdx), %rcx
	subl	16(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L11
	leaq	24(%rdx), %rcx
	subl	20(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L11
	subl	24(%rdx), %eax
.L11:
	cltq
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	vzeroupper
	cltq
	ret
.L13:
	xorl	%eax, %eax
	jmp	.L9
	.cfi_endproc
.LFE898:
	.size	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE, .-_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
