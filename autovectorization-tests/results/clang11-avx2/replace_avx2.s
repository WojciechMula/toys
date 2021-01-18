	.text
	.file	"replace.cpp"
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4                               # -- Begin function _Z12replace_epi8RSt6vectorIaSaIaEE
.LCPI0_0:
	.zero	16,13
	.text
	.globl	_Z12replace_epi8RSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z12replace_epi8RSt6vectorIaSaIaEE,@function
_Z12replace_epi8RSt6vectorIaSaIaEE:     # @_Z12replace_epi8RSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rdx
	movq	8(%rdi), %rax
	cmpq	%rax, %rdx
	je	.LBB0_41
# %bb.1:
	movq	%rax, %r8
	subq	%rdx, %r8
	cmpq	$16, %r8
	jae	.LBB0_3
# %bb.2:
	movq	%rdx, %rcx
	jmp	.LBB0_38
.LBB0_3:
	movq	%r8, %r9
	andq	$-16, %r9
	leaq	(%rdx,%r9), %rcx
	xorl	%esi, %esi
	vmovdqa	.LCPI0_0(%rip), %xmm0           # xmm0 = [13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13]
	jmp	.LBB0_4
	.p2align	4, 0x90
.LBB0_36:                               #   in Loop: Header=BB0_4 Depth=1
	addq	$16, %rsi
	cmpq	%rsi, %r9
	je	.LBB0_37
.LBB0_4:                                # =>This Inner Loop Header: Depth=1
	vpcmpeqb	(%rdx,%rsi), %xmm0, %xmm1
	vmovd	%xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_5
# %bb.6:                                #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$1, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_7
.LBB0_8:                                #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$2, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_9
.LBB0_10:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$3, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_11
.LBB0_12:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$4, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_13
.LBB0_14:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$5, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_15
.LBB0_16:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$6, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_17
.LBB0_18:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$7, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_19
.LBB0_20:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$8, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_21
.LBB0_22:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$9, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_23
.LBB0_24:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$10, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_25
.LBB0_26:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$11, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_27
.LBB0_28:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$12, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_29
.LBB0_30:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$13, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_31
.LBB0_32:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$14, %xmm1, %edi
	testb	$1, %dil
	jne	.LBB0_33
.LBB0_34:                               #   in Loop: Header=BB0_4 Depth=1
	vpextrb	$15, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_36
	jmp	.LBB0_35
	.p2align	4, 0x90
.LBB0_5:                                #   in Loop: Header=BB0_4 Depth=1
	movb	$42, (%rdx,%rsi)
	vpextrb	$1, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_8
.LBB0_7:                                #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 1(%rdx,%rsi)
	vpextrb	$2, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_10
.LBB0_9:                                #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 2(%rdx,%rsi)
	vpextrb	$3, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_12
.LBB0_11:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 3(%rdx,%rsi)
	vpextrb	$4, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_14
.LBB0_13:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 4(%rdx,%rsi)
	vpextrb	$5, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_16
.LBB0_15:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 5(%rdx,%rsi)
	vpextrb	$6, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_18
.LBB0_17:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 6(%rdx,%rsi)
	vpextrb	$7, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_20
.LBB0_19:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 7(%rdx,%rsi)
	vpextrb	$8, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_22
.LBB0_21:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 8(%rdx,%rsi)
	vpextrb	$9, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_24
.LBB0_23:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 9(%rdx,%rsi)
	vpextrb	$10, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_26
.LBB0_25:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 10(%rdx,%rsi)
	vpextrb	$11, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_28
.LBB0_27:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 11(%rdx,%rsi)
	vpextrb	$12, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_30
.LBB0_29:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 12(%rdx,%rsi)
	vpextrb	$13, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_32
.LBB0_31:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 13(%rdx,%rsi)
	vpextrb	$14, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_34
.LBB0_33:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 14(%rdx,%rsi)
	vpextrb	$15, %xmm1, %edi
	testb	$1, %dil
	je	.LBB0_36
.LBB0_35:                               #   in Loop: Header=BB0_4 Depth=1
	movb	$42, 15(%rdx,%rsi)
	jmp	.LBB0_36
.LBB0_37:
	cmpq	%r9, %r8
	jne	.LBB0_38
.LBB0_41:
	retq
	.p2align	4, 0x90
.LBB0_40:                               #   in Loop: Header=BB0_38 Depth=1
	addq	$1, %rcx
	cmpq	%rcx, %rax
	je	.LBB0_41
.LBB0_38:                               # =>This Inner Loop Header: Depth=1
	cmpb	$13, (%rcx)
	jne	.LBB0_40
# %bb.39:                               #   in Loop: Header=BB0_38 Depth=1
	movb	$42, (%rcx)
	jmp	.LBB0_40
.Lfunc_end0:
	.size	_Z12replace_epi8RSt6vectorIaSaIaEE, .Lfunc_end0-_Z12replace_epi8RSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2                               # -- Begin function _Z13replace_epi32RSt6vectorIiSaIiEE
.LCPI1_0:
	.long	13                              # 0xd
.LCPI1_1:
	.long	42                              # 0x2a
	.text
	.globl	_Z13replace_epi32RSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z13replace_epi32RSt6vectorIiSaIiEE,@function
_Z13replace_epi32RSt6vectorIiSaIiEE:    # @_Z13replace_epi32RSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.LBB1_13
# %bb.1:
	movq	%rcx, %r10
	subq	%rax, %r10
	addq	$-4, %r10
	cmpq	$124, %r10
	jb	.LBB1_10
# %bb.2:
	shrq	$2, %r10
	addq	$1, %r10
	movq	%r10, %r8
	andq	$-32, %r8
	leaq	-32(%r8), %rdx
	movq	%rdx, %r9
	shrq	$5, %r9
	addq	$1, %r9
	testq	%rdx, %rdx
	je	.LBB1_3
# %bb.4:
	leaq	224(%rax), %rdi
	movq	%r9, %rdx
	andq	$-2, %rdx
	negq	%rdx
	xorl	%esi, %esi
	vpbroadcastd	.LCPI1_0(%rip), %ymm0   # ymm0 = [13,13,13,13,13,13,13,13]
	vpbroadcastd	.LCPI1_1(%rip), %ymm1   # ymm1 = [42,42,42,42,42,42,42,42]
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vpcmpeqd	-224(%rdi,%rsi,4), %ymm0, %ymm2
	vpcmpeqd	-192(%rdi,%rsi,4), %ymm0, %ymm3
	vpcmpeqd	-160(%rdi,%rsi,4), %ymm0, %ymm4
	vpcmpeqd	-128(%rdi,%rsi,4), %ymm0, %ymm5
	vpmaskmovd	%ymm1, %ymm2, -224(%rdi,%rsi,4)
	vpmaskmovd	%ymm1, %ymm3, -192(%rdi,%rsi,4)
	vpmaskmovd	%ymm1, %ymm4, -160(%rdi,%rsi,4)
	vpmaskmovd	%ymm1, %ymm5, -128(%rdi,%rsi,4)
	vpcmpeqd	-96(%rdi,%rsi,4), %ymm0, %ymm2
	vpcmpeqd	-64(%rdi,%rsi,4), %ymm0, %ymm3
	vpcmpeqd	-32(%rdi,%rsi,4), %ymm0, %ymm4
	vpcmpeqd	(%rdi,%rsi,4), %ymm0, %ymm5
	vpmaskmovd	%ymm1, %ymm2, -96(%rdi,%rsi,4)
	vpmaskmovd	%ymm1, %ymm3, -64(%rdi,%rsi,4)
	vpmaskmovd	%ymm1, %ymm4, -32(%rdi,%rsi,4)
	vpmaskmovd	%ymm1, %ymm5, (%rdi,%rsi,4)
	addq	$64, %rsi
	addq	$2, %rdx
	jne	.LBB1_5
# %bb.6:
	testb	$1, %r9b
	je	.LBB1_8
.LBB1_7:
	vpbroadcastd	.LCPI1_0(%rip), %ymm0   # ymm0 = [13,13,13,13,13,13,13,13]
	vpcmpeqd	(%rax,%rsi,4), %ymm0, %ymm1
	vpcmpeqd	32(%rax,%rsi,4), %ymm0, %ymm2
	vpcmpeqd	64(%rax,%rsi,4), %ymm0, %ymm3
	vpcmpeqd	96(%rax,%rsi,4), %ymm0, %ymm0
	vpbroadcastd	.LCPI1_1(%rip), %ymm4   # ymm4 = [42,42,42,42,42,42,42,42]
	vpmaskmovd	%ymm4, %ymm1, (%rax,%rsi,4)
	vpmaskmovd	%ymm4, %ymm2, 32(%rax,%rsi,4)
	vpmaskmovd	%ymm4, %ymm3, 64(%rax,%rsi,4)
	vpmaskmovd	%ymm4, %ymm0, 96(%rax,%rsi,4)
.LBB1_8:
	cmpq	%r8, %r10
	jne	.LBB1_9
.LBB1_13:
	vzeroupper
	retq
.LBB1_9:
	leaq	(%rax,%r8,4), %rax
	jmp	.LBB1_10
	.p2align	4, 0x90
.LBB1_12:                               #   in Loop: Header=BB1_10 Depth=1
	addq	$4, %rax
	cmpq	%rax, %rcx
	je	.LBB1_13
.LBB1_10:                               # =>This Inner Loop Header: Depth=1
	cmpl	$13, (%rax)
	jne	.LBB1_12
# %bb.11:                               #   in Loop: Header=BB1_10 Depth=1
	movl	$42, (%rax)
	jmp	.LBB1_12
.LBB1_3:
	xorl	%esi, %esi
	testb	$1, %r9b
	jne	.LBB1_7
	jmp	.LBB1_8
.Lfunc_end1:
	.size	_Z13replace_epi32RSt6vectorIiSaIiEE, .Lfunc_end1-_Z13replace_epi32RSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
