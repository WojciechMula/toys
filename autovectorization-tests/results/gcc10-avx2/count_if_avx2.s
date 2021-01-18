	.file	"count_if.cpp"
	.text
	.p2align 4
	.globl	_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.type	_Z13count_if_epi8RKSt6vectorIaSaIaEE, @function
_Z13count_if_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %r9
	movq	(%rdi), %rsi
	cmpq	%r9, %rsi
	je	.L38
	leaq	-1(%r9), %rdi
	movq	%r9, %rcx
	movq	%rsi, %rax
	subq	%rsi, %rdi
	subq	%rsi, %rcx
	cmpq	$30, %rdi
	jbe	.L39
	movq	%rcx, %rdx
	vmovdqa	.LC0(%rip), %ymm4
	vpxor	%xmm6, %xmm6, %xmm6
	vpcmpeqd	%ymm3, %ymm3, %ymm3
	andq	$-32, %rdx
	addq	%rsi, %rdx
	.p2align 4,,10
	.p2align 3
.L4:
	vmovdqu	(%rax), %xmm7
	vinserti128	$0x1, 16(%rax), %ymm7, %ymm1
	addq	$32, %rax
	vpmovsxbw	%xmm7, %ymm2
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxwd	%xmm2, %ymm5
	vextracti128	$0x1, %ymm2, %xmm2
	vpmovsxbw	%xmm1, %ymm1
	vpmovsxwd	%xmm2, %ymm2
	vpcmpeqd	%ymm4, %ymm5, %ymm8
	vpmovsxwd	%xmm1, %ymm7
	vpcmpeqd	%ymm4, %ymm2, %ymm0
	vpcmpeqd	%ymm3, %ymm2, %ymm2
	vextracti128	$0x1, %ymm1, %xmm1
	vpcmpeqd	%ymm3, %ymm5, %ymm5
	vpmovsxwd	%xmm1, %ymm1
	vpor	%ymm2, %ymm0, %ymm2
	vpcmpeqd	%ymm4, %ymm1, %ymm0
	vpcmpeqd	%ymm3, %ymm1, %ymm1
	vpor	%ymm5, %ymm8, %ymm8
	vpcmpeqd	%ymm4, %ymm7, %ymm5
	vpcmpeqd	%ymm3, %ymm7, %ymm7
	vpor	%ymm1, %ymm0, %ymm1
	vpmovsxdq	%xmm8, %ymm0
	vpsubq	%ymm0, %ymm6, %ymm0
	vextracti128	$0x1, %ymm8, %xmm6
	vpor	%ymm7, %ymm5, %ymm5
	vpmovsxdq	%xmm6, %ymm6
	vpsubq	%ymm6, %ymm0, %ymm0
	vpmovsxdq	%xmm2, %ymm6
	vextracti128	$0x1, %ymm2, %xmm2
	vpsubq	%ymm6, %ymm0, %ymm0
	vpmovsxdq	%xmm2, %ymm2
	vextracti128	$0x1, %ymm1, %xmm6
	vpsubq	%ymm2, %ymm0, %ymm0
	vpmovsxdq	%xmm5, %ymm2
	vextracti128	$0x1, %ymm5, %xmm5
	vpsubq	%ymm2, %ymm0, %ymm0
	vpmovsxdq	%xmm5, %ymm5
	vpmovsxdq	%xmm1, %ymm2
	vpsubq	%ymm5, %ymm0, %ymm0
	vpmovsxdq	%xmm6, %ymm6
	vpsubq	%ymm2, %ymm0, %ymm0
	vpsubq	%ymm6, %ymm0, %ymm6
	cmpq	%rdx, %rax
	jne	.L4
	vextracti128	$0x1, %ymm6, %xmm0
	movq	%rcx, %rax
	vpaddq	%xmm0, %xmm6, %xmm0
	andq	$-32, %rax
	vpsrldq	$8, %xmm0, %xmm6
	leaq	(%rsi,%rax), %r8
	vpaddq	%xmm6, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	cmpq	%rax, %rcx
	je	.L99
	vzeroupper
.L3:
	subq	%rax, %rdi
	subq	%rax, %rcx
	cmpq	$14, %rdi
	jbe	.L6
	vmovdqu	(%rsi,%rax), %xmm1
	vmovdqa	.LC1(%rip), %xmm5
	vpcmpeqd	%xmm6, %xmm6, %xmm6
	vpmovsxbw	%xmm1, %xmm2
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxwd	%xmm2, %xmm3
	vpsrldq	$8, %xmm2, %xmm2
	vpmovsxbw	%xmm1, %xmm1
	vpcmpeqd	%xmm5, %xmm3, %xmm4
	vpcmpeqd	%xmm6, %xmm3, %xmm3
	vpmovsxwd	%xmm2, %xmm2
	vpmovsxwd	%xmm1, %xmm7
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxwd	%xmm1, %xmm1
	vpor	%xmm3, %xmm4, %xmm4
	vpcmpeqd	%xmm5, %xmm2, %xmm3
	vpcmpeqd	%xmm6, %xmm2, %xmm2
	vpmovsxdq	%xmm4, %xmm0
	vpand	.LC2(%rip), %xmm0, %xmm0
	vpsrldq	$8, %xmm4, %xmm4
	vpmovsxdq	%xmm4, %xmm4
	vpor	%xmm2, %xmm3, %xmm3
	vpcmpeqd	%xmm5, %xmm7, %xmm2
	vpsubq	%xmm4, %xmm0, %xmm0
	vpcmpeqd	%xmm6, %xmm7, %xmm7
	vpcmpeqd	%xmm5, %xmm1, %xmm5
	vpmovsxdq	%xmm3, %xmm4
	vpcmpeqd	%xmm6, %xmm1, %xmm1
	vpsrldq	$8, %xmm3, %xmm3
	vpsubq	%xmm4, %xmm0, %xmm0
	vpmovsxdq	%xmm3, %xmm3
	vpor	%xmm7, %xmm2, %xmm2
	vpsubq	%xmm3, %xmm0, %xmm0
	vpmovsxdq	%xmm2, %xmm3
	vpsrldq	$8, %xmm2, %xmm2
	vpor	%xmm1, %xmm5, %xmm1
	vpmovsxdq	%xmm2, %xmm2
	vpsubq	%xmm3, %xmm0, %xmm0
	vpsubq	%xmm2, %xmm0, %xmm0
	vpmovsxdq	%xmm1, %xmm2
	vpsrldq	$8, %xmm1, %xmm1
	vpsubq	%xmm2, %xmm0, %xmm0
	vpmovsxdq	%xmm1, %xmm1
	vpsubq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	addq	%rax, %rdx
	movq	%rcx, %rax
	andq	$-16, %rax
	addq	%rax, %r8
	cmpq	%rax, %rcx
	je	.L5
.L6:
	movsbl	(%r8), %eax
	cmpl	$42, %eax
	je	.L40
	cmpl	$-1, %eax
	je	.L40
.L8:
	leaq	1(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	1(%r8), %eax
	cmpl	$42, %eax
	je	.L41
	cmpl	$-1, %eax
	je	.L41
.L10:
	leaq	2(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	2(%r8), %eax
	cmpl	$-1, %eax
	je	.L42
	cmpl	$42, %eax
	je	.L42
.L12:
	leaq	3(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	3(%r8), %eax
	cmpl	$-1, %eax
	je	.L43
	cmpl	$42, %eax
	je	.L43
.L14:
	leaq	4(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	4(%r8), %eax
	cmpl	$42, %eax
	je	.L44
	cmpl	$-1, %eax
	je	.L44
.L16:
	leaq	5(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	5(%r8), %eax
	cmpl	$42, %eax
	je	.L45
	cmpl	$-1, %eax
	je	.L45
.L18:
	leaq	6(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	6(%r8), %eax
	cmpl	$42, %eax
	je	.L46
	cmpl	$-1, %eax
	je	.L46
.L20:
	leaq	7(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	7(%r8), %eax
	cmpl	$42, %eax
	je	.L47
	cmpl	$-1, %eax
	je	.L47
.L22:
	leaq	8(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	8(%r8), %eax
	cmpl	$42, %eax
	je	.L48
	cmpl	$-1, %eax
	je	.L48
.L24:
	leaq	9(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	9(%r8), %eax
	cmpl	$42, %eax
	je	.L49
	cmpl	$-1, %eax
	je	.L49
.L26:
	leaq	10(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	10(%r8), %eax
	cmpl	$42, %eax
	je	.L50
	cmpl	$-1, %eax
	je	.L50
.L28:
	leaq	11(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	11(%r8), %eax
	cmpl	$42, %eax
	je	.L51
	cmpl	$-1, %eax
	je	.L51
.L30:
	leaq	12(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	12(%r8), %eax
	cmpl	$42, %eax
	je	.L52
	cmpl	$-1, %eax
	je	.L52
.L32:
	leaq	13(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	13(%r8), %eax
	cmpl	$42, %eax
	je	.L53
	cmpl	$-1, %eax
	je	.L53
.L34:
	leaq	14(%r8), %rax
	cmpq	%rax, %r9
	je	.L5
	movsbl	14(%r8), %eax
	cmpl	$42, %eax
	je	.L36
	cmpl	$-1, %eax
	je	.L36
.L5:
	movq	%rdx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L40:
	addq	$1, %rdx
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L41:
	addq	$1, %rdx
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L42:
	addq	$1, %rdx
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L43:
	addq	$1, %rdx
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L44:
	addq	$1, %rdx
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L45:
	addq	$1, %rdx
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L46:
	addq	$1, %rdx
	jmp	.L20
	.p2align 4,,10
	.p2align 3
.L47:
	addq	$1, %rdx
	jmp	.L22
	.p2align 4,,10
	.p2align 3
.L48:
	addq	$1, %rdx
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L49:
	addq	$1, %rdx
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L50:
	addq	$1, %rdx
	jmp	.L28
.L36:
	addq	$1, %rdx
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L51:
	addq	$1, %rdx
	jmp	.L30
	.p2align 4,,10
	.p2align 3
.L38:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	addq	$1, %rdx
	jmp	.L32
.L53:
	addq	$1, %rdx
	jmp	.L34
.L39:
	movq	%rsi, %r8
	xorl	%eax, %eax
	xorl	%edx, %edx
	jmp	.L3
.L99:
	vzeroupper
	jmp	.L5
	.cfi_endproc
.LFE1353:
	.size	_Z13count_if_epi8RKSt6vectorIaSaIaEE, .-_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.type	_Z14count_if_epi32RKSt6vectorIiSaIiEE, @function
_Z14count_if_epi32RKSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	8(%rdi), %r8
	movq	(%rdi), %rdi
	cmpq	%r8, %rdi
	je	.L113
	leaq	-4(%r8), %rdx
	movq	%rdi, %rax
	subq	%rdi, %rdx
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rcx
	cmpq	$24, %rdx
	jbe	.L114
	movq	%rcx, %rdx
	vmovdqa	.LC0(%rip), %ymm4
	vpxor	%xmm2, %xmm2, %xmm2
	vpcmpeqd	%ymm3, %ymm3, %ymm3
	shrq	$3, %rdx
	salq	$5, %rdx
	addq	%rdi, %rdx
	.p2align 4,,10
	.p2align 3
.L103:
	vmovdqu	(%rax), %xmm5
	vinserti128	$0x1, 16(%rax), %ymm5, %ymm1
	addq	$32, %rax
	vpcmpeqd	%ymm1, %ymm4, %ymm0
	vpcmpeqd	%ymm3, %ymm1, %ymm1
	vpor	%ymm1, %ymm0, %ymm0
	vpmovsxdq	%xmm0, %ymm1
	vextracti128	$0x1, %ymm0, %xmm0
	vpsubq	%ymm1, %ymm2, %ymm2
	vpmovsxdq	%xmm0, %ymm0
	vpsubq	%ymm0, %ymm2, %ymm2
	cmpq	%rdx, %rax
	jne	.L103
	vextracti128	$0x1, %ymm2, %xmm0
	movq	%rcx, %rax
	vpaddq	%xmm0, %xmm2, %xmm0
	andq	$-8, %rax
	vpsrldq	$8, %xmm0, %xmm2
	leaq	(%rdi,%rax,4), %rsi
	vpaddq	%xmm2, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	cmpq	%rax, %rcx
	je	.L125
	vzeroupper
.L102:
	subq	%rax, %r9
	subq	%rax, %rcx
	cmpq	$2, %r9
	jbe	.L105
	vmovdqu	(%rdi,%rax,4), %xmm0
	vpcmpeqd	%xmm2, %xmm2, %xmm2
	vpcmpeqd	.LC1(%rip), %xmm0, %xmm1
	vpcmpeqd	%xmm2, %xmm0, %xmm0
	vpor	%xmm0, %xmm1, %xmm1
	vpmovsxdq	%xmm1, %xmm0
	vpsrldq	$8, %xmm1, %xmm1
	vpand	.LC2(%rip), %xmm0, %xmm0
	vpmovsxdq	%xmm1, %xmm1
	vpsubq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	addq	%rax, %rdx
	movq	%rcx, %rax
	andq	$-4, %rax
	leaq	(%rsi,%rax,4), %rsi
	cmpq	%rax, %rcx
	je	.L104
.L105:
	movl	(%rsi), %eax
	cmpl	$42, %eax
	je	.L115
	cmpl	$-1, %eax
	je	.L115
.L107:
	leaq	4(%rsi), %rax
	cmpq	%rax, %r8
	je	.L104
	movl	4(%rsi), %eax
	cmpl	$42, %eax
	je	.L116
	cmpl	$-1, %eax
	je	.L116
.L109:
	leaq	8(%rsi), %rax
	cmpq	%rax, %r8
	je	.L104
	movl	8(%rsi), %eax
	cmpl	$42, %eax
	je	.L111
	cmpl	$-1, %eax
	je	.L111
.L104:
	movq	%rdx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L115:
	addq	$1, %rdx
	jmp	.L107
	.p2align 4,,10
	.p2align 3
.L111:
	addq	$1, %rdx
	movq	%rdx, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L116:
	addq	$1, %rdx
	jmp	.L109
	.p2align 4,,10
	.p2align 3
.L113:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L125:
	vzeroupper
	movq	%rdx, %rax
	ret
.L114:
	movq	%rdi, %rsi
	xorl	%eax, %eax
	xorl	%edx, %edx
	jmp	.L102
	.cfi_endproc
.LFE1357:
	.size	_Z14count_if_epi32RKSt6vectorIiSaIiEE, .-_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC1:
	.long	42
	.long	42
	.long	42
	.long	42
	.align 16
.LC2:
	.quad	1
	.quad	1
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
