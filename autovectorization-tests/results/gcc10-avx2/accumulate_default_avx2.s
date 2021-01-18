	.file	"accumulate_default.cpp"
	.text
	.p2align 4
	.globl	_Z15accumulate_epi8RKSt6vectorIaSaIaEE
	.type	_Z15accumulate_epi8RKSt6vectorIaSaIaEE, @function
_Z15accumulate_epi8RKSt6vectorIaSaIaEE:
.LFB894:
	.cfi_startproc
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %r8
	cmpq	%rdi, %r8
	je	.L8
	leaq	-1(%rdi), %r9
	movq	%rdi, %rcx
	movq	%r8, %rax
	subq	%r8, %r9
	subq	%r8, %rcx
	cmpq	$30, %r9
	jbe	.L9
	movq	%rcx, %rdx
	vpxor	%xmm2, %xmm2, %xmm2
	andq	$-32, %rdx
	addq	%r8, %rdx
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu	(%rax), %xmm4
	vinserti128	$0x1, 16(%rax), %ymm4, %ymm1
	addq	$32, %rax
	vpmovsxbw	%xmm4, %ymm0
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxwd	%xmm0, %ymm3
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxbw	%xmm1, %ymm1
	vpaddd	%ymm2, %ymm3, %ymm2
	vpmovsxwd	%xmm0, %ymm0
	vpaddd	%ymm2, %ymm0, %ymm0
	vpmovsxwd	%xmm1, %ymm2
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddd	%ymm0, %ymm2, %ymm0
	vpmovsxwd	%xmm1, %ymm1
	vpaddd	%ymm0, %ymm1, %ymm2
	cmpq	%rdx, %rax
	jne	.L4
	vextracti128	$0x1, %ymm2, %xmm1
	movq	%rcx, %rax
	vpaddd	%xmm1, %xmm2, %xmm1
	andq	$-32, %rax
	vpsrldq	$8, %xmm1, %xmm2
	leaq	(%r8,%rax), %rsi
	vpaddd	%xmm2, %xmm1, %xmm1
	vpsrldq	$4, %xmm1, %xmm0
	vpaddd	%xmm0, %xmm1, %xmm1
	vmovd	%xmm1, %edx
	cmpq	%rax, %rcx
	je	.L13
	vzeroupper
.L3:
	subq	%rax, %r9
	subq	%rax, %rcx
	cmpq	$14, %r9
	jbe	.L6
	vmovdqu	(%r8,%rax), %xmm1
	vpmovsxbw	%xmm1, %xmm2
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxwd	%xmm2, %xmm0
	vpsrldq	$8, %xmm2, %xmm2
	vpmovsxbw	%xmm1, %xmm1
	vpmovsxwd	%xmm2, %xmm2
	vpaddd	%xmm2, %xmm0, %xmm2
	vpmovsxwd	%xmm1, %xmm0
	vpaddd	%xmm2, %xmm0, %xmm2
	vpsrldq	$8, %xmm1, %xmm0
	vpmovsxwd	%xmm0, %xmm0
	vpaddd	%xmm2, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %eax
	addl	%eax, %edx
	movq	%rcx, %rax
	andq	$-16, %rax
	addq	%rax, %rsi
	cmpq	%rax, %rcx
	je	.L5
.L6:
	movsbl	(%rsi), %eax
	addl	%eax, %edx
	leaq	1(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	1(%rsi), %eax
	addl	%eax, %edx
	leaq	2(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	2(%rsi), %eax
	addl	%eax, %edx
	leaq	3(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	3(%rsi), %eax
	addl	%eax, %edx
	leaq	4(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	4(%rsi), %eax
	addl	%eax, %edx
	leaq	5(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	5(%rsi), %eax
	addl	%eax, %edx
	leaq	6(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	6(%rsi), %eax
	addl	%eax, %edx
	leaq	7(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	7(%rsi), %eax
	addl	%eax, %edx
	leaq	8(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	8(%rsi), %eax
	addl	%eax, %edx
	leaq	9(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	9(%rsi), %eax
	addl	%eax, %edx
	leaq	10(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	10(%rsi), %eax
	addl	%eax, %edx
	leaq	11(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	11(%rsi), %eax
	addl	%eax, %edx
	leaq	12(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	12(%rsi), %eax
	addl	%eax, %edx
	leaq	13(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	13(%rsi), %eax
	addl	%eax, %edx
	leaq	14(%rsi), %rax
	cmpq	%rax, %rdi
	je	.L5
	movsbl	14(%rsi), %eax
	addl	%eax, %edx
.L5:
	movslq	%edx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	xorl	%eax, %eax
	ret
.L9:
	movq	%r8, %rsi
	xorl	%eax, %eax
	xorl	%edx, %edx
	jmp	.L3
.L13:
	vzeroupper
	jmp	.L5
	.cfi_endproc
.LFE894:
	.size	_Z15accumulate_epi8RKSt6vectorIaSaIaEE, .-_Z15accumulate_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z16accumulate_epi32RKSt6vectorIiSaIiEE
	.type	_Z16accumulate_epi32RKSt6vectorIiSaIiEE, @function
_Z16accumulate_epi32RKSt6vectorIiSaIiEE:
.LFB895:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %rdx
	cmpq	%rsi, %rdx
	je	.L19
	leaq	-4(%rsi), %rcx
	movq	%rdx, %rax
	subq	%rdx, %rcx
	movq	%rcx, %rdi
	shrq	$2, %rdi
	addq	$1, %rdi
	cmpq	$24, %rcx
	jbe	.L20
	movq	%rdi, %rcx
	vpxor	%xmm2, %xmm2, %xmm2
	shrq	$3, %rcx
	salq	$5, %rcx
	addq	%rdx, %rcx
	.p2align 4,,10
	.p2align 3
.L17:
	vmovdqu	(%rax), %xmm3
	vinserti128	$0x1, 16(%rax), %ymm3, %ymm1
	addq	$32, %rax
	vpaddd	%ymm1, %ymm2, %ymm2
	cmpq	%rcx, %rax
	jne	.L17
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
	je	.L23
	vzeroupper
.L16:
	leaq	4(%rdx), %rcx
	addl	(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L18
	leaq	8(%rdx), %rcx
	addl	4(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L18
	leaq	12(%rdx), %rcx
	addl	8(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L18
	leaq	16(%rdx), %rcx
	addl	12(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L18
	leaq	20(%rdx), %rcx
	addl	16(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L18
	leaq	24(%rdx), %rcx
	addl	20(%rdx), %eax
	cmpq	%rcx, %rsi
	je	.L18
	addl	24(%rdx), %eax
.L18:
	cltq
	ret
	.p2align 4,,10
	.p2align 3
.L19:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	vzeroupper
	cltq
	ret
.L20:
	xorl	%eax, %eax
	jmp	.L16
	.cfi_endproc
.LFE895:
	.size	_Z16accumulate_epi32RKSt6vectorIiSaIiEE, .-_Z16accumulate_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
