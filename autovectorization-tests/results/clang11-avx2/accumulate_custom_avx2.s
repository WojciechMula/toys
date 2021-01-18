	.text
	.file	"accumulate_custom.cpp"
	.globl	_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE # -- Begin function _Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE
	.p2align	4, 0x90
	.type	_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE,@function
_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE: # @_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rdx
	xorl	%eax, %eax
	cmpq	%rdx, %rcx
	je	.LBB0_2
	.p2align	4, 0x90
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movsbq	(%rcx), %rsi
	movsbl	%al, %eax
	cltq
	subq	%rsi, %rax
	addq	$1, %rcx
	cmpq	%rcx, %rdx
	jne	.LBB0_1
.LBB0_2:
	retq
.Lfunc_end0:
	.size	_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE, .Lfunc_end0-_Z22accumulate_custom_epi8RKSt6vectorIaSaIaEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE # -- Begin function _Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE
	.p2align	4, 0x90
	.type	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE,@function
_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE: # @_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rcx
	movq	8(%rdi), %rdx
	xorl	%eax, %eax
	cmpq	%rdx, %rcx
	je	.LBB1_12
# %bb.1:
	movq	%rdx, %rsi
	subq	%rcx, %rsi
	addq	$-4, %rsi
	cmpq	$124, %rsi
	jb	.LBB1_10
# %bb.2:
	shrq	$2, %rsi
	addq	$1, %rsi
	movq	%rsi, %r8
	andq	$-32, %r8
	leaq	-32(%r8), %rax
	movq	%rax, %r9
	shrq	$5, %r9
	addq	$1, %r9
	testq	%rax, %rax
	je	.LBB1_3
# %bb.4:
	movq	%r9, %rax
	andq	$-2, %rax
	negq	%rax
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%edi, %edi
	vpxor	%xmm1, %xmm1, %xmm1
	vpxor	%xmm2, %xmm2, %xmm2
	vpxor	%xmm3, %xmm3, %xmm3
	.p2align	4, 0x90
.LBB1_5:                                # =>This Inner Loop Header: Depth=1
	vpsubd	(%rcx,%rdi,4), %ymm0, %ymm0
	vpsubd	32(%rcx,%rdi,4), %ymm1, %ymm1
	vpsubd	64(%rcx,%rdi,4), %ymm2, %ymm2
	vpsubd	96(%rcx,%rdi,4), %ymm3, %ymm3
	vpsubd	128(%rcx,%rdi,4), %ymm0, %ymm0
	vpsubd	160(%rcx,%rdi,4), %ymm1, %ymm1
	vpsubd	192(%rcx,%rdi,4), %ymm2, %ymm2
	vpsubd	224(%rcx,%rdi,4), %ymm3, %ymm3
	addq	$64, %rdi
	addq	$2, %rax
	jne	.LBB1_5
# %bb.6:
	testb	$1, %r9b
	je	.LBB1_8
.LBB1_7:
	vpsubd	96(%rcx,%rdi,4), %ymm3, %ymm3
	vpsubd	64(%rcx,%rdi,4), %ymm2, %ymm2
	vpsubd	32(%rcx,%rdi,4), %ymm1, %ymm1
	vpsubd	(%rcx,%rdi,4), %ymm0, %ymm0
.LBB1_8:
	vpaddd	%ymm3, %ymm1, %ymm1
	vpaddd	%ymm2, %ymm0, %ymm0
	vpaddd	%ymm1, %ymm0, %ymm0
	vextracti128	$1, %ymm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpshufd	$78, %xmm0, %xmm1               # xmm1 = xmm0[2,3,0,1]
	vpaddd	%xmm1, %xmm0, %xmm0
	vpshufd	$229, %xmm0, %xmm1              # xmm1 = xmm0[1,1,2,3]
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %eax
	cmpq	%r8, %rsi
	je	.LBB1_11
# %bb.9:
	leaq	(%rcx,%r8,4), %rcx
	.p2align	4, 0x90
.LBB1_10:                               # =>This Inner Loop Header: Depth=1
	subl	(%rcx), %eax
	addq	$4, %rcx
	cmpq	%rcx, %rdx
	jne	.LBB1_10
.LBB1_11:
	cltq
.LBB1_12:
	vzeroupper
	retq
.LBB1_3:
	vpxor	%xmm0, %xmm0, %xmm0
	xorl	%edi, %edi
	vpxor	%xmm1, %xmm1, %xmm1
	vpxor	%xmm2, %xmm2, %xmm2
	vpxor	%xmm3, %xmm3, %xmm3
	testb	$1, %r9b
	jne	.LBB1_7
	jmp	.LBB1_8
.Lfunc_end1:
	.size	_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE, .Lfunc_end1-_Z23accumulate_custom_epi32RKSt6vectorIiSaIiEE
	.cfi_endproc
                                        # -- End function
	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
