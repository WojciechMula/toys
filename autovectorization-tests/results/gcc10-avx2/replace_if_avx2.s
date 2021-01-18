	.file	"replace_if.cpp"
	.text
	.p2align 4
	.globl	_Z15replace_if_epi8RSt6vectorIaSaIaEE
	.type	_Z15replace_if_epi8RSt6vectorIaSaIaEE, @function
_Z15replace_if_epi8RSt6vectorIaSaIaEE:
.LFB1353:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rax
	cmpq	%rcx, %rax
	jne	.L5
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L3:
	addq	$1, %rax
	cmpq	%rax, %rcx
	je	.L11
.L5:
	movzbl	(%rax), %edx
	cmpb	$13, %dl
	je	.L6
	cmpb	$-12, %dl
	jne	.L3
.L6:
	movb	$42, (%rax)
	addq	$1, %rax
	cmpq	%rax, %rcx
	jne	.L5
.L11:
	ret
	.cfi_endproc
.LFE1353:
	.size	_Z15replace_if_epi8RSt6vectorIaSaIaEE, .-_Z15replace_if_epi8RSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z16replace_if_epi32RSt6vectorIiSaIiEE
	.type	_Z16replace_if_epi32RSt6vectorIiSaIiEE, @function
_Z16replace_if_epi32RSt6vectorIiSaIiEE:
.LFB1357:
	.cfi_startproc
	movq	8(%rdi), %rcx
	movq	(%rdi), %rdi
	cmpq	%rcx, %rdi
	je	.L130
	movq	%rcx, %rsi
	leaq	-4(%rcx), %rdx
	movq	%rdi, %rax
	subq	%rdi, %rsi
	subq	%rdi, %rdx
	andl	$3, %esi
	jne	.L109
	cmpq	$56, %rdx
	jbe	.L109
	movq	%rdx, %r9
	shrq	$2, %r9
	leaq	1(%r9), %rsi
	cmpq	$120, %rdx
	jbe	.L61
	movq	%rsi, %r8
	vmovdqa	.LC0(%rip), %ymm1
	vmovdqa	.LC1(%rip), %ymm2
	xorl	%edx, %edx
	vmovdqa	.LC2(%rip), %ymm4
	vmovdqa	.LC3(%rip), %ymm3
	shrq	$5, %r8
	vmovdqa	.LC4(%rip), %ymm5
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L17:
	vptest	%ymm6, %ymm6
	jne	.L131
.L18:
	vptest	%ymm7, %ymm7
	jne	.L132
.L19:
	vptest	%ymm0, %ymm0
	jne	.L133
.L20:
	addq	$1, %rdx
	subq	$-128, %rax
	cmpq	%rdx, %r8
	jbe	.L134
.L21:
	vmovdqu	(%rax), %xmm7
	vinserti128	$0x1, 16(%rax), %ymm7, %ymm0
	vmovdqu	32(%rax), %xmm7
	vinserti128	$0x1, 48(%rax), %ymm7, %ymm6
	vpand	%ymm0, %ymm1, %ymm0
	vmovdqu	64(%rax), %xmm7
	vpand	%ymm6, %ymm1, %ymm6
	vpackusdw	%ymm6, %ymm0, %ymm0
	vinserti128	$0x1, 80(%rax), %ymm7, %ymm6
	vmovdqu	96(%rax), %xmm7
	vinserti128	$0x1, 112(%rax), %ymm7, %ymm7
	vpermq	$216, %ymm0, %ymm0
	vpand	%ymm6, %ymm1, %ymm6
	vpand	%ymm0, %ymm2, %ymm0
	vpand	%ymm7, %ymm1, %ymm7
	vpackusdw	%ymm7, %ymm6, %ymm6
	vpermq	$216, %ymm6, %ymm6
	vpand	%ymm6, %ymm2, %ymm6
	vpackuswb	%ymm6, %ymm0, %ymm0
	vpermq	$216, %ymm0, %ymm0
	vpcmpeqb	%ymm0, %ymm4, %ymm6
	vpcmpeqb	%ymm0, %ymm3, %ymm0
	vpor	%ymm0, %ymm6, %ymm0
	vpmovsxbw	%xmm0, %ymm6
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxwd	%xmm6, %ymm8
	vpmovsxbw	%xmm0, %ymm0
	vextracti128	$0x1, %ymm6, %xmm6
	vptest	%ymm8, %ymm8
	vpmovsxwd	%xmm0, %ymm7
	vextracti128	$0x1, %ymm0, %xmm0
	vpmovsxwd	%xmm6, %ymm6
	vpmovsxwd	%xmm0, %ymm0
	je	.L17
	vptest	%ymm6, %ymm6
	vpmaskmovd	%ymm5, %ymm8, (%rax)
	je	.L18
	.p2align 4,,10
	.p2align 3
.L131:
	vptest	%ymm7, %ymm7
	vpmaskmovd	%ymm5, %ymm6, 32(%rax)
	je	.L19
	.p2align 4,,10
	.p2align 3
.L132:
	vptest	%ymm0, %ymm0
	vpmaskmovd	%ymm5, %ymm7, 64(%rax)
	je	.L20
	.p2align 4,,10
	.p2align 3
.L133:
	addq	$1, %rdx
	vpmaskmovd	%ymm5, %ymm0, 96(%rax)
	subq	$-128, %rax
	cmpq	%rdx, %r8
	ja	.L21
.L134:
	movq	%rsi, %rdx
	andq	$-32, %rdx
	leaq	(%rdi,%rdx,4), %rax
	cmpq	%rdx, %rsi
	je	.L135
	vzeroupper
.L16:
	subq	%rdx, %r9
	subq	%rdx, %rsi
	cmpq	$14, %r9
	jbe	.L23
	leaq	(%rdi,%rdx,4), %rdx
	vmovdqa	.LC5(%rip), %xmm0
	vpand	16(%rdx), %xmm0, %xmm2
	vpand	(%rdx), %xmm0, %xmm1
	leaq	16(%rdx), %r9
	leaq	32(%rdx), %r8
	leaq	48(%rdx), %rdi
	vpackusdw	%xmm2, %xmm1, %xmm1
	vpand	32(%rdx), %xmm0, %xmm2
	vpand	48(%rdx), %xmm0, %xmm0
	vpackusdw	%xmm0, %xmm2, %xmm0
	vmovdqa	.LC6(%rip), %xmm2
	vpand	%xmm1, %xmm2, %xmm1
	vpand	%xmm0, %xmm2, %xmm2
	vpackuswb	%xmm2, %xmm1, %xmm1
	vpcmpeqb	.LC7(%rip), %xmm1, %xmm0
	vpcmpeqb	.LC8(%rip), %xmm1, %xmm1
	vpor	%xmm1, %xmm0, %xmm0
	vpmovsxbw	%xmm0, %xmm1
	vpsrldq	$8, %xmm0, %xmm0
	vpmovsxwd	%xmm1, %xmm3
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxbw	%xmm0, %xmm0
	vptest	%xmm3, %xmm3
	vpmovsxwd	%xmm0, %xmm2
	vpmovsxwd	%xmm1, %xmm1
	vpsrldq	$8, %xmm0, %xmm0
	vpmovsxwd	%xmm0, %xmm0
	jne	.L136
.L24:
	vptest	%xmm1, %xmm1
	jne	.L137
.L25:
	vptest	%xmm2, %xmm2
	jne	.L138
.L26:
	vptest	%xmm0, %xmm0
	jne	.L139
.L27:
	movq	%rsi, %rdx
	andq	$-16, %rdx
	leaq	(%rax,%rdx,4), %rax
	cmpq	%rdx, %rsi
	je	.L130
.L23:
	movl	(%rax), %edx
	cmpb	$13, %dl
	je	.L62
	cmpb	$-12, %dl
	je	.L62
.L29:
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	4(%rax), %edx
	cmpb	$13, %dl
	je	.L63
	cmpb	$-12, %dl
	je	.L63
.L31:
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	8(%rax), %edx
	cmpb	$13, %dl
	je	.L64
	cmpb	$-12, %dl
	je	.L64
.L33:
	leaq	12(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	12(%rax), %edx
	cmpb	$13, %dl
	je	.L65
	cmpb	$-12, %dl
	je	.L65
.L35:
	leaq	16(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	16(%rax), %edx
	cmpb	$13, %dl
	je	.L66
	cmpb	$-12, %dl
	je	.L66
.L37:
	leaq	20(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	20(%rax), %edx
	cmpb	$13, %dl
	je	.L67
	cmpb	$-12, %dl
	je	.L67
.L39:
	leaq	24(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	24(%rax), %edx
	cmpb	$13, %dl
	je	.L68
	cmpb	$-12, %dl
	je	.L68
.L41:
	leaq	28(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	28(%rax), %edx
	cmpb	$13, %dl
	je	.L69
	cmpb	$-12, %dl
	je	.L69
.L43:
	leaq	32(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	32(%rax), %edx
	cmpb	$13, %dl
	je	.L70
	cmpb	$-12, %dl
	je	.L70
.L45:
	leaq	36(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	36(%rax), %edx
	cmpb	$13, %dl
	je	.L71
	cmpb	$-12, %dl
	je	.L71
.L47:
	leaq	40(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	40(%rax), %edx
	cmpb	$13, %dl
	je	.L72
	cmpb	$-12, %dl
	je	.L72
.L49:
	leaq	44(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	44(%rax), %edx
	cmpb	$13, %dl
	je	.L73
	cmpb	$-12, %dl
	je	.L73
.L51:
	leaq	48(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	48(%rax), %edx
	cmpb	$13, %dl
	je	.L74
	cmpb	$-12, %dl
	je	.L74
.L53:
	leaq	52(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	52(%rax), %edx
	cmpb	$13, %dl
	je	.L75
	cmpb	$-12, %dl
	je	.L75
.L55:
	leaq	56(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L130
	movl	56(%rax), %edx
	cmpb	$13, %dl
	je	.L57
	cmpb	$-12, %dl
	je	.L57
.L130:
	ret
	.p2align 4,,10
	.p2align 3
.L76:
	movl	$42, (%rax)
.L59:
	addq	$4, %rax
	cmpq	%rcx, %rax
	je	.L130
.L109:
	movl	(%rax), %edx
	cmpb	$-12, %dl
	je	.L76
	cmpb	$13, %dl
	jne	.L59
	movl	$42, (%rax)
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L62:
	movl	$42, (%rax)
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L63:
	movl	$42, 4(%rax)
	jmp	.L31
	.p2align 4,,10
	.p2align 3
.L64:
	movl	$42, 8(%rax)
	jmp	.L33
	.p2align 4,,10
	.p2align 3
.L139:
	vmovdqa	.LC9(%rip), %xmm1
	vpmaskmovd	%xmm1, %xmm0, (%rdi)
	jmp	.L27
	.p2align 4,,10
	.p2align 3
.L138:
	vmovdqa	.LC9(%rip), %xmm1
	vpmaskmovd	%xmm1, %xmm2, (%r8)
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L137:
	vmovdqa	.LC9(%rip), %xmm3
	vpmaskmovd	%xmm3, %xmm1, (%r9)
	jmp	.L25
	.p2align 4,,10
	.p2align 3
.L136:
	vmovdqa	.LC9(%rip), %xmm4
	vpmaskmovd	%xmm4, %xmm3, (%rdx)
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L65:
	movl	$42, 12(%rax)
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L66:
	movl	$42, 16(%rax)
	jmp	.L37
	.p2align 4,,10
	.p2align 3
.L67:
	movl	$42, 20(%rax)
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L68:
	movl	$42, 24(%rax)
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L69:
	movl	$42, 28(%rax)
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L70:
	movl	$42, 32(%rax)
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L71:
	movl	$42, 36(%rax)
	jmp	.L47
	.p2align 4,,10
	.p2align 3
.L72:
	movl	$42, 40(%rax)
	jmp	.L49
.L57:
	movl	$42, 56(%rax)
	ret
	.p2align 4,,10
	.p2align 3
.L73:
	movl	$42, 44(%rax)
	jmp	.L51
	.p2align 4,,10
	.p2align 3
.L74:
	movl	$42, 48(%rax)
	jmp	.L53
.L75:
	movl	$42, 52(%rax)
	jmp	.L55
.L61:
	xorl	%edx, %edx
	jmp	.L16
.L135:
	vzeroupper
	ret
	.cfi_endproc
.LFE1357:
	.size	_Z16replace_if_epi32RSt6vectorIiSaIiEE, .-_Z16replace_if_epi32RSt6vectorIiSaIiEE
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
	.long	65535
	.long	65535
	.long	65535
	.long	65535
	.long	65535
	.long	65535
	.long	65535
	.long	65535
	.align 32
.LC1:
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
.LC2:
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
.LC3:
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
.LC4:
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
.LC5:
	.long	65535
	.long	65535
	.long	65535
	.long	65535
	.align 16
.LC6:
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.align 16
.LC7:
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
	.align 16
.LC8:
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
	.align 16
.LC9:
	.long	42
	.long	42
	.long	42
	.long	42
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
