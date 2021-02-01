	.file	"avx512f.cpp"
	.text
	.p2align 4
	.globl	_Z9all_equalDv8_x
	.type	_Z9all_equalDv8_x, @function
_Z9all_equalDv8_x:
.LFB5356:
	.cfi_startproc
	vpxor	%xmm2, %xmm2, %xmm2
	vmovdqa64	%zmm0, %zmm1
	vpshufb	%xmm2, %xmm0, %xmm0
	vshufi32x4	$0x0, %zmm0, %zmm0, %zmm0
	vpxord	%zmm1, %zmm0, %zmm0
	vptestnmd	%zmm0, %zmm0, %k0
	kmovw	%k0, %eax
	cmpw	$-1, %ax
	sete	%al
	ret
	.cfi_endproc
.LFE5356:
	.size	_Z9all_equalDv8_x, .-_Z9all_equalDv8_x
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
