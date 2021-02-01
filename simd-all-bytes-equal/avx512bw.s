	.file	"avx512bw.cpp"
	.text
	.p2align 4
	.globl	_Z9all_equalDv8_x
	.type	_Z9all_equalDv8_x, @function
_Z9all_equalDv8_x:
.LFB5356:
	.cfi_startproc
	movabsq	$1099511627775, %rax
	vpbroadcastb	%xmm0, %zmm1
	vpcmpub	$0, %zmm1, %zmm0, %k0
	kmovq	%k0, %rdx
	cmpq	%rax, %rdx
	sete	%al
	ret
	.cfi_endproc
.LFE5356:
	.size	_Z9all_equalDv8_x, .-_Z9all_equalDv8_x
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
