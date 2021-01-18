	.file	"adjacent_find.cpp"
	.text
	.p2align 4
	.globl	_Z18adjacent_find_epi8RKSt6vectorIaSaIaEE
	.type	_Z18adjacent_find_epi8RKSt6vectorIaSaIaEE, @function
_Z18adjacent_find_epi8RKSt6vectorIaSaIaEE:
.LFB1325:
	.cfi_startproc
	movq	8(%rdi), %rdx
	movq	(%rdi), %rax
	cmpq	%rax, %rdx
	jne	.L3
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L7:
	movzbl	(%rax), %esi
	cmpb	%sil, -1(%rax)
	je	.L6
.L3:
	movq	%rax, %rcx
	addq	$1, %rax
	cmpq	%rax, %rdx
	jne	.L7
.L2:
	cmpq	%rax, %rdx
	setne	%al
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%rcx, %rax
	cmpq	%rax, %rdx
	setne	%al
	ret
	.cfi_endproc
.LFE1325:
	.size	_Z18adjacent_find_epi8RKSt6vectorIaSaIaEE, .-_Z18adjacent_find_epi8RKSt6vectorIaSaIaEE
	.p2align 4
	.globl	_Z19adjacent_find_epi32RKSt6vectorIiSaIiEE
	.type	_Z19adjacent_find_epi32RKSt6vectorIiSaIiEE, @function
_Z19adjacent_find_epi32RKSt6vectorIiSaIiEE:
.LFB1326:
	.cfi_startproc
	movq	8(%rdi), %rdx
	movq	(%rdi), %rax
	cmpq	%rax, %rdx
	jne	.L10
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L13:
	movl	(%rax), %esi
	cmpl	%esi, -4(%rax)
	je	.L12
.L10:
	movq	%rax, %rcx
	addq	$4, %rax
	cmpq	%rax, %rdx
	jne	.L13
.L9:
	cmpq	%rax, %rdx
	setne	%al
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	movq	%rcx, %rax
	cmpq	%rax, %rdx
	setne	%al
	ret
	.cfi_endproc
.LFE1326:
	.size	_Z19adjacent_find_epi32RKSt6vectorIiSaIiEE, .-_Z19adjacent_find_epi32RKSt6vectorIiSaIiEE
	.ident	"GCC: (GNU) 9.0.0 20190117 (experimental)"
	.section	.note.GNU-stack,"",@progbits
