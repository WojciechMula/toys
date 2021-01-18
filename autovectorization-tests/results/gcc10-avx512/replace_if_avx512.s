	.file	"replace_if.cpp"
	.text
	.p2align 4
	.globl	_Z15replace_if_epi8RSt6vectorIaSaIaEE
	.type	_Z15replace_if_epi8RSt6vectorIaSaIaEE, @function
_Z15replace_if_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %rsi
	cmpq	%rdi, %rsi
	je	.L23
	leaq	-1(%rdi), %r10
	movq	%rdi, %r8
	movq	%rsi, %rax
	subq	%rsi, %r10
	subq	%rsi, %r8
	cmpq	$62, %r10
	jbe	.L13
	vmovdqa64	.LC0(%rip), %zmm1
	movq	%r8, %r9
	vmovdqa64	.LC1(%rip), %zmm0
	vmovdqa64	.LC2(%rip), %zmm2
	andq	$-64, %r9
	addq	%rsi, %r9
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L4:
	addq	$64, %rax
	cmpq	%r9, %rax
	je	.L25
.L5:
	vmovdqu8	(%rax), %zmm4
	vpcmpb	$0, %zmm1, %zmm4, %k0
	vpcmpb	$0, %zmm0, %zmm4, %k3
	kmovq	%k0, %rdx
	kmovq	%k3, %rcx
	orq	%rcx, %rdx
	je	.L4
	kmovq	%rdx, %k1
	vmovdqu8	%zmm2, (%rax){%k1}
	addq	$64, %rax
	cmpq	%r9, %rax
	jne	.L5
	.p2align 4,,10
	.p2align 3
.L25:
	movq	%r8, %rdx
	andq	$-64, %rdx
	leaq	(%rsi,%rdx), %rax
	cmpq	%rdx, %r8
	je	.L22
.L3:
	subq	%rdx, %r10
	subq	%rdx, %r8
	cmpq	$30, %r10
	jbe	.L11
	addq	%rdx, %rsi
	vmovdqu8	(%rsi), %xmm3
	vinserti128	$0x1, 16(%rsi), %ymm3, %ymm0
	vpcmpb	$0, .LC3(%rip), %ymm0, %k4
	vpcmpb	$0, .LC4(%rip), %ymm0, %k5
	kmovd	%k4, %edx
	kmovd	%k5, %ecx
	orl	%ecx, %edx
	jne	.L26
.L8:
	movq	%r8, %rdx
	andq	$-32, %rdx
	addq	%rdx, %rax
	cmpq	%rdx, %r8
	jne	.L11
	jmp	.L22
	.p2align 4,,10
	.p2align 3
.L27:
	addq	$1, %rax
	cmpq	%rax, %rdi
	je	.L22
.L11:
	movzbl	(%rax), %edx
	cmpb	$13, %dl
	je	.L10
	cmpb	$-12, %dl
	jne	.L27
.L10:
	movb	$42, (%rax)
	addq	$1, %rax
	cmpq	%rax, %rdi
	jne	.L11
.L22:
	vzeroupper
.L23:
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	vmovdqa	.LC5(%rip), %ymm0
	kmovd	%edx, %k2
	vmovdqu8	%ymm0, (%rsi){%k2}
	jmp	.L8
.L13:
	xorl	%edx, %edx
	jmp	.L3
	.cfi_endproc
.LFE1353:
	.size	_Z15replace_if_epi8RSt6vectorIaSaIaEE, .-_Z15replace_if_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z16replace_if_epi32RSt6vectorIiSaIiEE
	.type	_Z16replace_if_epi32RSt6vectorIiSaIiEE, @function
_Z16replace_if_epi32RSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	8(%rdi), %rsi
	movq	(%rdi), %r9
	cmpq	%rsi, %r9
	je	.L81
	movq	%rsi, %rcx
	leaq	-4(%rsi), %rdx
	movq	%r9, %rax
	subq	%r9, %rcx
	subq	%r9, %rdx
	andl	$3, %ecx
	jne	.L67
	cmpq	$120, %rdx
	jbe	.L67
	movq	%rdx, %r10
	shrq	$2, %r10
	leaq	1(%r10), %r8
	cmpq	$248, %rdx
	jbe	.L49
	vmovdqa64	.LC6(%rip), %zmm2
	movq	%r8, %r11
	xorl	%ecx, %ecx
	vmovdqa64	.LC7(%rip), %zmm5
	vmovdqa64	.LC0(%rip), %zmm4
	shrq	$6, %r11
	vmovdqa64	.LC1(%rip), %zmm3
	vmovdqa32	.LC8(%rip), %zmm6
	jmp	.L36
	.p2align 4,,10
	.p2align 3
.L32:
	kortestw	%k4, %k4
	jne	.L83
.L33:
	kortestw	%k2, %k2
	jne	.L84
.L34:
	kortestw	%k3, %k3
	jne	.L85
.L35:
	addq	$1, %rcx
	addq	$256, %rax
	cmpq	%rcx, %r11
	jbe	.L86
.L36:
	vmovdqu16	128(%rax), %zmm1
	vmovdqu16	(%rax), %zmm0
	vpermt2w	192(%rax), %zmm2, %zmm1
	vpermt2w	64(%rax), %zmm2, %zmm0
	vpermt2b	%zmm1, %zmm5, %zmm0
	vpcmpb	$0, %zmm4, %zmm0, %k0
	vpcmpb	$0, %zmm3, %zmm0, %k5
	kmovq	%k0, %rdx
	kmovq	%k5, %rdi
	orq	%rdi, %rdx
	kmovq	%rdx, %k1
	kshiftrq	$32, %k1, %k2
	kshiftrd	$16, %k1, %k4
	kshiftrd	$16, %k2, %k3
	kortestw	%k1, %k1
	je	.L32
	vmovdqu32	%zmm6, (%rax){%k1}
	kortestw	%k4, %k4
	je	.L33
	.p2align 4,,10
	.p2align 3
.L83:
	vmovdqu32	%zmm6, 64(%rax){%k4}
	kortestw	%k2, %k2
	je	.L34
	.p2align 4,,10
	.p2align 3
.L84:
	vmovdqu32	%zmm6, 128(%rax){%k2}
	kortestw	%k3, %k3
	je	.L35
	.p2align 4,,10
	.p2align 3
.L85:
	vmovdqu32	%zmm6, 192(%rax){%k3}
	addq	$1, %rcx
	addq	$256, %rax
	cmpq	%rcx, %r11
	ja	.L36
.L86:
	movq	%r8, %rax
	andq	$-64, %rax
	leaq	(%r9,%rax,4), %rdx
	cmpq	%rax, %r8
	je	.L80
.L31:
	subq	%rax, %r10
	subq	%rax, %r8
	cmpq	$30, %r10
	jbe	.L38
	vmovdqa	.LC9(%rip), %ymm1
	leaq	(%r9,%rax,4), %rax
	vmovdqu8	(%rax), %xmm7
	vinserti128	$0x1, 16(%rax), %ymm7, %ymm0
	leaq	32(%rax), %r11
	leaq	64(%rax), %r10
	vmovdqu8	32(%rax), %xmm7
	vinserti128	$0x1, 48(%rax), %ymm7, %ymm2
	leaq	96(%rax), %r9
	vmovdqu8	64(%rax), %xmm6
	vmovdqu8	96(%rax), %xmm4
	vpermt2w	%ymm2, %ymm1, %ymm0
	vinserti128	$0x1, 112(%rax), %ymm4, %ymm3
	vinserti128	$0x1, 80(%rax), %ymm6, %ymm2
	vpermt2w	%ymm3, %ymm1, %ymm2
	vmovdqa	.LC10(%rip), %ymm1
	vpand	%ymm0, %ymm1, %ymm0
	vpand	%ymm2, %ymm1, %ymm1
	vpackuswb	%ymm1, %ymm0, %ymm0
	vpermq	$216, %ymm0, %ymm0
	vpcmpb	$0, .LC3(%rip), %ymm0, %k6
	vpcmpb	$0, .LC4(%rip), %ymm0, %k7
	kmovd	%k6, %ecx
	kmovd	%k7, %edi
	orl	%edi, %ecx
	kmovd	%ecx, %k4
	kmovw	%ecx, %k3
	kshiftrd	$16, %k4, %k1
	kortestb	%k3, %k3
	kmovw	%k1, %k2
	kshiftrw	$8, %k4, %k4
	kshiftrw	$8, %k1, %k1
	jne	.L87
	kortestb	%k4, %k4
	jne	.L88
.L40:
	kortestb	%k2, %k2
	jne	.L89
.L41:
	kortestb	%k1, %k1
	jne	.L90
.L42:
	movq	%r8, %rax
	andq	$-32, %rax
	leaq	(%rdx,%rax,4), %rdx
	cmpq	%rax, %r8
	je	.L80
.L38:
	movq	%rdx, %rax
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L91:
	cmpb	$-12, %dl
	je	.L44
	addq	$4, %rax
	cmpq	%rax, %rsi
	je	.L80
.L45:
	movl	(%rax), %edx
	cmpb	$13, %dl
	jne	.L91
.L44:
	movl	$42, (%rax)
	addq	$4, %rax
	cmpq	%rax, %rsi
	jne	.L45
.L80:
	vzeroupper
.L81:
	ret
	.p2align 4,,10
	.p2align 3
.L50:
	movl	$42, (%rax)
	addq	$4, %rax
	cmpq	%rax, %rsi
	je	.L92
.L67:
	movl	(%rax), %edx
	cmpb	$-12, %dl
	je	.L50
	cmpb	$13, %dl
	je	.L50
	addq	$4, %rax
	cmpq	%rax, %rsi
	jne	.L67
.L92:
	ret
	.p2align 4,,10
	.p2align 3
.L87:
	vmovdqa	.LC11(%rip), %ymm0
	kortestb	%k4, %k4
	vmovdqu32	%ymm0, (%rax){%k3}
	je	.L40
.L88:
	vmovdqa	.LC11(%rip), %ymm0
	kortestb	%k2, %k2
	vmovdqu32	%ymm0, (%r11){%k4}
	je	.L41
.L89:
	vmovdqa	.LC11(%rip), %ymm0
	kortestb	%k1, %k1
	vmovdqu32	%ymm0, (%r10){%k2}
	je	.L42
.L90:
	vmovdqa	.LC11(%rip), %ymm0
	vmovdqu32	%ymm0, (%r9){%k1}
	jmp	.L42
.L49:
	movq	%r9, %rdx
	xorl	%eax, %eax
	jmp	.L31
	.cfi_endproc
.LFE1357:
	.size	_Z16replace_if_epi32RSt6vectorIiSaIiEE, .-_Z16replace_if_epi32RSt6vectorIiSaIiEE
	.section	.rodata
	.align 64
.LC0:
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.align 64
.LC1:
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.align 64
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
.LC3:
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.byte	13
	.align 32
.LC4:
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.byte	-12
	.align 32
.LC5:
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
.LC6:
	.value	0
	.value	2
	.value	4
	.value	6
	.value	8
	.value	10
	.value	12
	.value	14
	.value	16
	.value	18
	.value	20
	.value	22
	.value	24
	.value	26
	.value	28
	.value	30
	.value	32
	.value	34
	.value	36
	.value	38
	.value	40
	.value	42
	.value	44
	.value	46
	.value	48
	.value	50
	.value	52
	.value	54
	.value	56
	.value	58
	.value	60
	.value	62
	.align 64
.LC7:
	.byte	0
	.byte	2
	.byte	4
	.byte	6
	.byte	8
	.byte	10
	.byte	12
	.byte	14
	.byte	16
	.byte	18
	.byte	20
	.byte	22
	.byte	24
	.byte	26
	.byte	28
	.byte	30
	.byte	32
	.byte	34
	.byte	36
	.byte	38
	.byte	40
	.byte	42
	.byte	44
	.byte	46
	.byte	48
	.byte	50
	.byte	52
	.byte	54
	.byte	56
	.byte	58
	.byte	60
	.byte	62
	.byte	64
	.byte	66
	.byte	68
	.byte	70
	.byte	72
	.byte	74
	.byte	76
	.byte	78
	.byte	80
	.byte	82
	.byte	84
	.byte	86
	.byte	88
	.byte	90
	.byte	92
	.byte	94
	.byte	96
	.byte	98
	.byte	100
	.byte	102
	.byte	104
	.byte	106
	.byte	108
	.byte	110
	.byte	112
	.byte	114
	.byte	116
	.byte	118
	.byte	120
	.byte	122
	.byte	124
	.byte	126
	.align 64
.LC8:
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
.LC9:
	.value	0
	.value	2
	.value	4
	.value	6
	.value	8
	.value	10
	.value	12
	.value	14
	.value	16
	.value	18
	.value	20
	.value	22
	.value	24
	.value	26
	.value	28
	.value	30
	.align 32
.LC10:
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.align 32
.LC11:
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
