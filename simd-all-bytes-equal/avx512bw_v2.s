	.file	"avx512bw_v2.cpp"
	.text
	.p2align 4
	.globl	_Z9all_equalDv8_x
	.type	_Z9all_equalDv8_x, @function
_Z9all_equalDv8_x:
.LFB5356:
	.cfi_startproc
	vpbroadcastb	%xmm0, %zmm1
	vpcmpeqd	%zmm1, %zmm0, %k0
	kortestw	%k0, %k0
	setc	%al
	ret
	.cfi_endproc
.LFE5356:
	.size	_Z9all_equalDv8_x, .-_Z9all_equalDv8_x
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
