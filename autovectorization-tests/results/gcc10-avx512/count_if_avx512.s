	.file	"count_if.cpp"
	.text
	.p2align 4
	.globl	_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.type	_Z13count_if_epi8RKSt6vectorIaSaIaEE, @function
_Z13count_if_epi8RKSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rsi
	cmpq	%rcx, %rsi
	je	.L11
	leaq	-1(%rcx), %r8
	movq	%rcx, %rdi
	movq	%rsi, %rdx
	subq	%rsi, %r8
	subq	%rsi, %rdi
	cmpq	$62, %r8
	jbe	.L12
	movq	%rdi, %r9
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqa32	.LC0(%rip), %zmm7
	vpternlogd	$0xFF, %zmm6, %zmm6, %zmm6
	andq	$-64, %r9
	vpternlogd	$0xFF, %zmm3, %zmm3, %zmm3
	addq	%rsi, %r9
	.p2align 4,,10
	.p2align 3
.L4:
	vpmovsxbw	(%rdx), %zmm2
	vmovdqu8	(%rdx), %zmm4
	addq	$64, %rdx
	vpmovsxwd	%ymm2, %zmm5
	vextracti64x4	$0x1, %zmm2, %ymm2
	vextracti64x4	$0x1, %zmm4, %ymm1
	vpcmpd	$0, %zmm7, %zmm5, %k0
	vpcmpd	$0, %zmm6, %zmm5, %k5
	vpmovsxwd	%ymm2, %zmm2
	vpcmpd	$0, %zmm7, %zmm2, %k6
	vpcmpd	$0, %zmm6, %zmm2, %k7
	vpmovsxbw	%ymm1, %zmm1
	vpmovsxwd	%ymm1, %zmm4
	vextracti64x4	$0x1, %zmm1, %ymm1
	vpmovsxwd	%ymm1, %zmm1
	kmovw	%k5, %r10d
	kmovw	%k0, %eax
	orl	%r10d, %eax
	kmovw	%eax, %k4
	kmovw	%k7, %r10d
	kmovw	%k6, %eax
	vpcmpd	$0, %zmm6, %zmm1, %k7
	vpcmpd	$0, %zmm7, %zmm1, %k6
	vpcmpd	$0, %zmm7, %zmm4, %k0
	vmovdqa64	%zmm3, %zmm1{%k4}{z}
	orl	%r10d, %eax
	vpcmpd	$0, %zmm6, %zmm4, %k5
	vpsubq	%zmm1, %zmm0, %zmm0
	kshiftrw	$8, %k4, %k4
	kmovw	%eax, %k3
	vmovdqa64	%zmm3, %zmm1{%k4}{z}
	vpsubq	%zmm1, %zmm0, %zmm0
	vmovdqa64	%zmm3, %zmm1{%k3}{z}
	kmovw	%k0, %eax
	kshiftrw	$8, %k3, %k3
	vpsubq	%zmm1, %zmm0, %zmm0
	kmovw	%k5, %r10d
	vmovdqa64	%zmm3, %zmm1{%k3}{z}
	orl	%r10d, %eax
	kmovw	%eax, %k2
	vpsubq	%zmm1, %zmm0, %zmm0
	kmovw	%k6, %eax
	kmovw	%k7, %r10d
	vmovdqa64	%zmm3, %zmm1{%k2}{z}
	orl	%r10d, %eax
	kshiftrw	$8, %k2, %k2
	vpsubq	%zmm1, %zmm0, %zmm0
	vmovdqa64	%zmm3, %zmm1{%k2}{z}
	kmovw	%eax, %k1
	vpsubq	%zmm1, %zmm0, %zmm0
	vmovdqa64	%zmm3, %zmm1{%k1}{z}
	kshiftrw	$8, %k1, %k1
	vpsubq	%zmm1, %zmm0, %zmm0
	vmovdqa64	%zmm3, %zmm1{%k1}{z}
	vpsubq	%zmm1, %zmm0, %zmm0
	cmpq	%rdx, %r9
	jne	.L4
	vmovdqa	%ymm0, %ymm1
	vextracti64x4	$0x1, %zmm0, %ymm0
	movq	%rdi, %rdx
	vpaddq	%ymm0, %ymm1, %ymm0
	andq	$-64, %rdx
	vmovdqa	%xmm0, %xmm1
	vextracti64x2	$0x1, %ymm0, %xmm0
	leaq	(%rsi,%rdx), %rax
	vpaddq	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %r9
	cmpq	%rdx, %rdi
	je	.L5
.L3:
	subq	%rdx, %r8
	subq	%rdx, %rdi
	cmpq	$30, %r8
	jbe	.L9
	vmovdqu8	(%rsi,%rdx), %xmm1
	vpcmpeqd	%ymm2, %ymm2, %ymm2
	vinserti128	$0x1, 16(%rsi,%rdx), %ymm1, %ymm0
	vmovdqa	.LC1(%rip), %ymm3
	vpmovsxbw	%xmm1, %ymm1
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxwd	%xmm1, %ymm5
	vextracti128	$0x1, %ymm1, %xmm1
	vpmovsxbw	%xmm0, %ymm0
	vpcmpd	$0, %ymm2, %ymm5, %k5
	vpmovsxwd	%xmm1, %ymm1
	vpmovsxwd	%xmm0, %ymm4
	vpcmpd	$0, %ymm3, %ymm5, %k0
	vpcmpd	$0, %ymm2, %ymm1, %k7
	vextracti128	$0x1, %ymm0, %xmm0
	vpcmpd	$0, %ymm3, %ymm1, %k6
	vpmovsxwd	%xmm0, %ymm0
	vpcmpeqd	%ymm1, %ymm1, %ymm1
	kmovb	%k5, %esi
	vpcmpd	$0, %ymm2, %ymm4, %k5
	kmovb	%k0, %edx
	orl	%esi, %edx
	vpcmpd	$0, %ymm3, %ymm4, %k0
	kmovb	%k7, %esi
	kmovb	%edx, %k4
	vpcmpd	$0, %ymm2, %ymm0, %k7
	kmovb	%k6, %edx
	vpcmpd	$0, %ymm3, %ymm0, %k6
	vmovdqa64	.LC2(%rip), %ymm0{%k4}{z}
	orl	%esi, %edx
	kshiftrb	$4, %k4, %k4
	vmovdqa64	%ymm1, %ymm2{%k4}{z}
	kmovb	%edx, %k3
	kmovb	%k5, %esi
	kmovb	%k0, %edx
	orl	%esi, %edx
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa64	%ymm1, %ymm2{%k3}{z}
	kshiftrb	$4, %k3, %k3
	kmovb	%edx, %k2
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa64	%ymm1, %ymm2{%k3}{z}
	kmovb	%k6, %edx
	kmovb	%k7, %esi
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa64	%ymm1, %ymm2{%k2}{z}
	orl	%esi, %edx
	kshiftrb	$4, %k2, %k2
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa64	%ymm1, %ymm2{%k2}{z}
	kmovb	%edx, %k1
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa64	%ymm1, %ymm2{%k1}{z}
	kshiftrb	$4, %k1, %k1
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa64	%ymm1, %ymm2{%k1}{z}
	vpsubq	%ymm2, %ymm0, %ymm0
	vmovdqa	%xmm0, %xmm1
	vextracti64x2	$0x1, %ymm0, %xmm0
	vpaddq	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	addq	%rdx, %r9
	movq	%rdi, %rdx
	andq	$-32, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %rdi
	jne	.L9
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L16:
	addq	$1, %rax
	cmpq	%rax, %rcx
	je	.L5
.L9:
	movsbl	(%rax), %edx
	cmpl	$42, %edx
	je	.L8
	cmpl	$-1, %edx
	jne	.L16
.L8:
	addq	$1, %rax
	addq	$1, %r9
	cmpq	%rax, %rcx
	jne	.L9
.L5:
	movq	%r9, %rax
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	xorl	%eax, %eax
	ret
.L12:
	movq	%rsi, %rax
	xorl	%edx, %edx
	xorl	%r9d, %r9d
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z13count_if_epi8RKSt6vectorIaSaIaEE, .-_Z13count_if_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.type	_Z14count_if_epi32RKSt6vectorIiSaIiEE, @function
_Z14count_if_epi32RKSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %r8
	cmpq	%rdi, %r8
	je	.L38
	leaq	-4(%rdi), %rax
	movq	%r8, %rdx
	subq	%r8, %rax
	movq	%rax, %r10
	shrq	$2, %r10
	leaq	1(%r10), %r9
	cmpq	$56, %rax
	jbe	.L39
	movq	%r9, %rsi
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqa32	.LC0(%rip), %zmm4
	vpternlogd	$0xFF, %zmm3, %zmm3, %zmm3
	shrq	$4, %rsi
	vpternlogd	$0xFF, %zmm1, %zmm1, %zmm1
	salq	$6, %rsi
	addq	%r8, %rsi
	.p2align 4,,10
	.p2align 3
.L20:
	vmovdqu32	(%rdx), %zmm6
	addq	$64, %rdx
	vpcmpd	$0, %zmm4, %zmm6, %k0
	vpcmpd	$0, %zmm3, %zmm6, %k2
	kmovw	%k0, %eax
	kmovw	%k2, %ecx
	orl	%ecx, %eax
	kmovw	%eax, %k1
	vmovdqa64	%zmm1, %zmm2{%k1}{z}
	kshiftrw	$8, %k1, %k1
	vpsubq	%zmm2, %zmm0, %zmm0
	vmovdqa64	%zmm1, %zmm2{%k1}{z}
	vpsubq	%zmm2, %zmm0, %zmm0
	cmpq	%rsi, %rdx
	jne	.L20
	vmovdqa	%ymm0, %ymm1
	vextracti64x4	$0x1, %zmm0, %ymm0
	movq	%r9, %rdx
	vpaddq	%ymm0, %ymm1, %ymm0
	andq	$-16, %rdx
	vmovdqa	%xmm0, %xmm1
	vextracti64x2	$0x1, %ymm0, %xmm0
	leaq	(%r8,%rdx,4), %rcx
	vpaddq	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	cmpq	%rdx, %r9
	je	.L72
.L19:
	subq	%rdx, %r10
	subq	%rdx, %r9
	cmpq	$6, %r10
	jbe	.L22
	vmovdqu8	(%r8,%rdx,4), %xmm5
	vpcmpeqd	%ymm1, %ymm1, %ymm1
	vinserti128	$0x1, 16(%r8,%rdx,4), %ymm5, %ymm0
	vpcmpd	$0, %ymm1, %ymm0, %k4
	vpcmpd	$0, .LC1(%rip), %ymm0, %k3
	kmovb	%k4, %esi
	kmovb	%k3, %edx
	orl	%esi, %edx
	kmovb	%edx, %k1
	vmovdqa64	.LC2(%rip), %ymm1{%k1}{z}
	kshiftrb	$4, %k1, %k1
	vpmovm2q	%k1, %ymm0
	vpsubq	%ymm0, %ymm1, %ymm1
	vmovdqa	%xmm1, %xmm0
	vextracti64x2	$0x1, %ymm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rdx
	addq	%rdx, %rax
	movq	%r9, %rdx
	andq	$-8, %rdx
	leaq	(%rcx,%rdx,4), %rcx
	cmpq	%rdx, %r9
	je	.L72
.L22:
	movl	(%rcx), %edx
	cmpl	$42, %edx
	je	.L40
	cmpl	$-1, %edx
	je	.L40
.L24:
	leaq	4(%rcx), %rdx
	cmpq	%rdx, %rdi
	je	.L72
	movl	4(%rcx), %edx
	cmpl	$42, %edx
	je	.L41
	cmpl	$-1, %edx
	je	.L41
.L26:
	leaq	8(%rcx), %rdx
	cmpq	%rdx, %rdi
	je	.L72
	movl	8(%rcx), %edx
	cmpl	$42, %edx
	je	.L42
	cmpl	$-1, %edx
	je	.L42
.L28:
	leaq	12(%rcx), %rdx
	cmpq	%rdx, %rdi
	je	.L72
	movl	12(%rcx), %edx
	cmpl	$-1, %edx
	je	.L43
	cmpl	$42, %edx
	je	.L43
.L30:
	leaq	16(%rcx), %rdx
	cmpq	%rdx, %rdi
	je	.L72
	movl	16(%rcx), %edx
	cmpl	$42, %edx
	je	.L44
	cmpl	$-1, %edx
	je	.L44
.L32:
	leaq	20(%rcx), %rdx
	cmpq	%rdx, %rdi
	je	.L72
	movl	20(%rcx), %edx
	cmpl	$42, %edx
	je	.L45
	cmpl	$-1, %edx
	je	.L45
.L34:
	leaq	24(%rcx), %rdx
	cmpq	%rdx, %rdi
	je	.L72
	movl	24(%rcx), %edx
	cmpl	$42, %edx
	je	.L36
	cmpl	$-1, %edx
	je	.L36
.L72:
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L40:
	addq	$1, %rax
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L41:
	addq	$1, %rax
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L42:
	addq	$1, %rax
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L43:
	addq	$1, %rax
	jmp	.L30
	.p2align 4,,10
	.p2align 3
.L44:
	addq	$1, %rax
	jmp	.L32
	.p2align 4,,10
	.p2align 3
.L45:
	addq	$1, %rax
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L36:
	addq	$1, %rax
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L38:
	xorl	%eax, %eax
	ret
.L39:
	movq	%r8, %rcx
	xorl	%edx, %edx
	xorl	%eax, %eax
	jmp	.L19
	.cfi_endproc
.LFE1357:
	.size	_Z14count_if_epi32RKSt6vectorIiSaIiEE, .-_Z14count_if_epi32RKSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
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
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC1:
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.long	42
	.align 32
.LC2:
	.quad	1
	.quad	1
	.quad	1
	.quad	1
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
