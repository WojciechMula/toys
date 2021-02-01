	.file	"sse.cpp"
	.text
	.p2align 4
	.globl	_Z9all_equalDv2_x
	.type	_Z9all_equalDv2_x, @function
_Z9all_equalDv2_x:
.LFB5356:
	.cfi_startproc
	pxor	%xmm2, %xmm2
	movdqa	%xmm0, %xmm1
	pshufb	%xmm2, %xmm0
	pcmpeqb	%xmm1, %xmm0
	pmovmskb	%xmm0, %eax
	cmpl	$65535, %eax
	sete	%al
	ret
	.cfi_endproc
.LFE5356:
	.size	_Z9all_equalDv2_x, .-_Z9all_equalDv2_x
	.ident	"GCC: (Debian 10.2.1-5) 10.2.1 20210108"
	.section	.note.GNU-stack,"",@progbits
