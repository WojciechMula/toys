	.file	"avx2.cpp"
	.text
	.p2align 4
	.globl	_Z9all_equalDv4_x
	.type	_Z9all_equalDv4_x, @function
_Z9all_equalDv4_x:
.LFB5356:
	.cfi_startproc
	vmovdqa	%ymm0, %ymm2
	vpxor	%xmm0, %xmm0, %xmm0
	vpshufb	%xmm0, %xmm2, %xmm0
	vinserti128	$1, %xmm0, %ymm0, %ymm0
	vpcmpeqb	%ymm2, %ymm0, %ymm0
	vpmovmskb	%ymm0, %eax
	cmpl	$-1, %eax
	sete	%al
	ret
	.cfi_endproc
.LFE5356:
	.size	_Z9all_equalDv4_x, .-_Z9all_equalDv4_x
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
