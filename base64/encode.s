	.file	"encode.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z17encode_triplets_1PKhjPh
	.type	_Z17encode_triplets_1PKhjPh, @function
_Z17encode_triplets_1PKhjPh:
.LFB0:
	.cfi_startproc
	xorl	%r8d, %r8d
	testl	%esi, %esi
	leal	(%rsi,%rsi,2), %r9d
	je	.L1
	.p2align 4,,10
	.p2align 3
.L5:
	movl	%r8d, %eax
	leal	2(%r8), %esi
	addq	$4, %rdx
	movzbl	(%rdi,%rax), %ecx
	leal	1(%r8), %eax
	addl	$3, %r8d
	movzbl	(%rdi,%rsi), %esi
	movzbl	(%rdi,%rax), %eax
	movq	%rcx, %r10
	sarl	$6, %ecx
	andl	$63, %r10d
	movzbl	lookup8(%r10), %r10d
	movb	%r10b, -4(%rdx)
	movl	%eax, %r10d
	sarl	$4, %eax
	andl	$15, %r10d
	sall	$2, %r10d
	orl	%r10d, %ecx
	movslq	%ecx, %rcx
	movzbl	lookup8(%rcx), %ecx
	movb	%cl, -3(%rdx)
	movl	%esi, %ecx
	shrq	$2, %rsi
	andl	$3, %ecx
	andl	$63, %esi
	sall	$4, %ecx
	orl	%ecx, %eax
	cltq
	movzbl	lookup8(%rax), %eax
	movb	%al, -2(%rdx)
	movzbl	lookup8(%rsi), %eax
	cmpl	%r9d, %r8d
	movb	%al, -1(%rdx)
	jne	.L5
.L1:
	rep ret
	.cfi_endproc
.LFE0:
	.size	_Z17encode_triplets_1PKhjPh, .-_Z17encode_triplets_1PKhjPh
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	_Z17encode_triplets_2PKhjPh
	.type	_Z17encode_triplets_2PKhjPh, @function
_Z17encode_triplets_2PKhjPh:
.LFB1:
	.cfi_startproc
	xorl	%r8d, %r8d
	testl	%esi, %esi
	leal	(%rsi,%rsi,2), %r9d
	je	.L8
	.p2align 4,,10
	.p2align 3
.L12:
	leal	2(%r8), %esi
	movl	%r8d, %eax
	addq	$4, %rdx
	movzbl	(%rdi,%rax), %ecx
	leal	1(%r8), %eax
	addl	$3, %r8d
	movzbl	(%rdi,%rsi), %esi
	movzbl	(%rdi,%rax), %eax
	movq	%rcx, %r11
	sarl	$6, %ecx
	movq	%rsi, %r10
	andl	$63, %r11d
	andl	$3, %esi
	andl	$252, %r10d
	sall	$4, %esi
	movl	lookup32(%r10), %r10d
	sall	$24, %r10d
	orl	lookup32(,%r11,4), %r10d
	movl	%eax, %r11d
	andl	$15, %r11d
	sarl	$4, %eax
	sall	$2, %r11d
	orl	%esi, %eax
	orl	%r11d, %ecx
	cltq
	movslq	%ecx, %rcx
	movl	lookup32(,%rcx,4), %ecx
	sall	$8, %ecx
	orl	%ecx, %r10d
	movl	lookup32(,%rax,4), %ecx
	movl	%r10d, %eax
	sall	$16, %ecx
	orl	%ecx, %eax
	movl	%eax, -4(%rdx)
	cmpl	%r9d, %r8d
	jne	.L12
.L8:
	rep ret
	.cfi_endproc
.LFE1:
	.size	_Z17encode_triplets_2PKhjPh, .-_Z17encode_triplets_2PKhjPh
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	_Z17encode_triplets_3PKhjPh
	.type	_Z17encode_triplets_3PKhjPh, @function
_Z17encode_triplets_3PKhjPh:
.LFB2:
	.cfi_startproc
	xorl	%r8d, %r8d
	testl	%esi, %esi
	leal	(%rsi,%rsi,2), %r9d
	je	.L14
	.p2align 4,,10
	.p2align 3
.L18:
	leal	2(%r8), %esi
	movl	%r8d, %eax
	addq	$4, %rdx
	movzbl	(%rdi,%rax), %ecx
	leal	1(%r8), %eax
	addl	$3, %r8d
	movzbl	(%rdi,%rsi), %r10d
	movzbl	(%rdi,%rax), %eax
	movq	%rcx, %r11
	sarl	$6, %ecx
	movq	%r10, %rsi
	andl	$63, %r11d
	andl	$3, %r10d
	andl	$252, %esi
	sall	$4, %r10d
	movl	lookup32_3(%rsi), %esi
	orl	lookup32_0(,%r11,4), %esi
	movl	%eax, %r11d
	andl	$15, %r11d
	sarl	$4, %eax
	sall	$2, %r11d
	orl	%r10d, %eax
	orl	%r11d, %ecx
	cltq
	movslq	%ecx, %rcx
	orl	lookup32_1(,%rcx,4), %esi
	movl	%esi, %ecx
	orl	lookup32_2(,%rax,4), %ecx
	movl	%ecx, -4(%rdx)
	cmpl	%r9d, %r8d
	jne	.L18
.L14:
	rep ret
	.cfi_endproc
.LFE2:
	.size	_Z17encode_triplets_3PKhjPh, .-_Z17encode_triplets_3PKhjPh
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	_Z17encode_triplets_4PKhjPh
	.type	_Z17encode_triplets_4PKhjPh, @function
_Z17encode_triplets_4PKhjPh:
.LFB3:
	.cfi_startproc
	xorl	%ecx, %ecx
	testl	%esi, %esi
	leal	(%rsi,%rsi,2), %r8d
	je	.L20
	.p2align 4,,10
	.p2align 3
.L24:
	movl	%ecx, %eax
	addl	$3, %ecx
	addq	$4, %rdx
	movl	(%rdi,%rax), %eax
	movl	%eax, %esi
	andl	$63, %esi
	movzbl	lookup8(%rsi), %esi
	movb	%sil, -4(%rdx)
	movl	%eax, %esi
	shrl	$8, %esi
	andl	$63, %esi
	movzbl	lookup8(%rsi), %esi
	movb	%sil, -3(%rdx)
	movl	%eax, %esi
	shrl	$24, %eax
	shrl	$16, %esi
	andl	$63, %eax
	andl	$63, %esi
	movzbl	lookup8(%rsi), %esi
	movb	%sil, -2(%rdx)
	movzbl	lookup8(%rax), %eax
	cmpl	%r8d, %ecx
	movb	%al, -1(%rdx)
	jne	.L24
.L20:
	rep ret
	.cfi_endproc
.LFE3:
	.size	_Z17encode_triplets_4PKhjPh, .-_Z17encode_triplets_4PKhjPh
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.text.unlikely
.LCOLDB4:
	.text
.LHOTB4:
	.p2align 4,,15
	.globl	_Z17encode_triplets_5PKhjPh
	.type	_Z17encode_triplets_5PKhjPh, @function
_Z17encode_triplets_5PKhjPh:
.LFB4:
	.cfi_startproc
	xorl	%r8d, %r8d
	testl	%esi, %esi
	leal	(%rsi,%rsi,2), %r9d
	je	.L26
	.p2align 4,,10
	.p2align 3
.L30:
	movl	%r8d, %eax
	addl	$3, %r8d
	addq	$4, %rdx
	movl	(%rdi,%rax), %eax
	movl	%eax, %ecx
	shrl	$8, %ecx
	andl	$63, %ecx
	movl	lookup32(,%rcx,4), %ecx
	movl	%ecx, %esi
	movl	%eax, %ecx
	shrl	$16, %ecx
	sall	$8, %esi
	andl	$63, %ecx
	movl	lookup32(,%rcx,4), %ecx
	sall	$16, %ecx
	orl	%esi, %ecx
	movl	%eax, %esi
	shrl	$24, %eax
	andl	$63, %esi
	andl	$63, %eax
	orl	lookup32(,%rsi,4), %ecx
	movl	lookup32(,%rax,4), %eax
	sall	$24, %eax
	orl	%eax, %ecx
	movl	%ecx, -4(%rdx)
	cmpl	%r9d, %r8d
	jne	.L30
.L26:
	rep ret
	.cfi_endproc
.LFE4:
	.size	_Z17encode_triplets_5PKhjPh, .-_Z17encode_triplets_5PKhjPh
	.section	.text.unlikely
.LCOLDE4:
	.text
.LHOTE4:
	.section	.text.unlikely
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4,,15
	.globl	_Z17encode_triplets_6PKhjPh
	.type	_Z17encode_triplets_6PKhjPh, @function
_Z17encode_triplets_6PKhjPh:
.LFB5:
	.cfi_startproc
	xorl	%r8d, %r8d
	testl	%esi, %esi
	leal	(%rsi,%rsi,2), %r9d
	je	.L32
	.p2align 4,,10
	.p2align 3
.L36:
	movl	%r8d, %eax
	addl	$3, %r8d
	addq	$4, %rdx
	movl	(%rdi,%rax), %eax
	movl	%eax, %ecx
	movl	%eax, %esi
	shrl	$8, %ecx
	shrl	$16, %esi
	andl	$63, %esi
	andl	$63, %ecx
	movl	lookup32_1(,%rcx,4), %ecx
	orl	lookup32_2(,%rsi,4), %ecx
	movl	%eax, %esi
	andl	$63, %esi
	shrl	$24, %eax
	orl	lookup32_0(,%rsi,4), %ecx
	andl	$63, %eax
	orl	lookup32_3(,%rax,4), %ecx
	movl	%ecx, -4(%rdx)
	cmpl	%r9d, %r8d
	jne	.L36
.L32:
	rep ret
	.cfi_endproc
.LFE5:
	.size	_Z17encode_triplets_6PKhjPh, .-_Z17encode_triplets_6PKhjPh
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.globl	lookup32_3
	.data
	.align 64
	.type	lookup32_3, @object
	.size	lookup32_3, 256
lookup32_3:
	.long	1090519040
	.long	1107296256
	.long	1124073472
	.long	1140850688
	.long	1157627904
	.long	1174405120
	.long	1191182336
	.long	1207959552
	.long	1224736768
	.long	1241513984
	.long	1258291200
	.long	1275068416
	.long	1291845632
	.long	1308622848
	.long	1325400064
	.long	1342177280
	.long	1358954496
	.long	1375731712
	.long	1392508928
	.long	1409286144
	.long	1426063360
	.long	1442840576
	.long	1459617792
	.long	1476395008
	.long	1493172224
	.long	1509949440
	.long	1627389952
	.long	1644167168
	.long	1660944384
	.long	1677721600
	.long	1694498816
	.long	1711276032
	.long	1728053248
	.long	1744830464
	.long	1761607680
	.long	1778384896
	.long	1795162112
	.long	1811939328
	.long	1828716544
	.long	1845493760
	.long	1862270976
	.long	1879048192
	.long	1895825408
	.long	1912602624
	.long	1929379840
	.long	1946157056
	.long	1962934272
	.long	1979711488
	.long	1996488704
	.long	2013265920
	.long	2030043136
	.long	2046820352
	.long	805306368
	.long	822083584
	.long	838860800
	.long	855638016
	.long	872415232
	.long	889192448
	.long	905969664
	.long	922746880
	.long	939524096
	.long	956301312
	.long	721420288
	.long	788529152
	.globl	lookup32_2
	.align 64
	.type	lookup32_2, @object
	.size	lookup32_2, 256
lookup32_2:
	.long	4259840
	.long	4325376
	.long	4390912
	.long	4456448
	.long	4521984
	.long	4587520
	.long	4653056
	.long	4718592
	.long	4784128
	.long	4849664
	.long	4915200
	.long	4980736
	.long	5046272
	.long	5111808
	.long	5177344
	.long	5242880
	.long	5308416
	.long	5373952
	.long	5439488
	.long	5505024
	.long	5570560
	.long	5636096
	.long	5701632
	.long	5767168
	.long	5832704
	.long	5898240
	.long	6356992
	.long	6422528
	.long	6488064
	.long	6553600
	.long	6619136
	.long	6684672
	.long	6750208
	.long	6815744
	.long	6881280
	.long	6946816
	.long	7012352
	.long	7077888
	.long	7143424
	.long	7208960
	.long	7274496
	.long	7340032
	.long	7405568
	.long	7471104
	.long	7536640
	.long	7602176
	.long	7667712
	.long	7733248
	.long	7798784
	.long	7864320
	.long	7929856
	.long	7995392
	.long	3145728
	.long	3211264
	.long	3276800
	.long	3342336
	.long	3407872
	.long	3473408
	.long	3538944
	.long	3604480
	.long	3670016
	.long	3735552
	.long	2818048
	.long	3080192
	.globl	lookup32_1
	.align 64
	.type	lookup32_1, @object
	.size	lookup32_1, 256
lookup32_1:
	.long	16640
	.long	16896
	.long	17152
	.long	17408
	.long	17664
	.long	17920
	.long	18176
	.long	18432
	.long	18688
	.long	18944
	.long	19200
	.long	19456
	.long	19712
	.long	19968
	.long	20224
	.long	20480
	.long	20736
	.long	20992
	.long	21248
	.long	21504
	.long	21760
	.long	22016
	.long	22272
	.long	22528
	.long	22784
	.long	23040
	.long	24832
	.long	25088
	.long	25344
	.long	25600
	.long	25856
	.long	26112
	.long	26368
	.long	26624
	.long	26880
	.long	27136
	.long	27392
	.long	27648
	.long	27904
	.long	28160
	.long	28416
	.long	28672
	.long	28928
	.long	29184
	.long	29440
	.long	29696
	.long	29952
	.long	30208
	.long	30464
	.long	30720
	.long	30976
	.long	31232
	.long	12288
	.long	12544
	.long	12800
	.long	13056
	.long	13312
	.long	13568
	.long	13824
	.long	14080
	.long	14336
	.long	14592
	.long	11008
	.long	12032
	.globl	lookup32_0
	.align 64
	.type	lookup32_0, @object
	.size	lookup32_0, 256
lookup32_0:
	.long	65
	.long	66
	.long	67
	.long	68
	.long	69
	.long	70
	.long	71
	.long	72
	.long	73
	.long	74
	.long	75
	.long	76
	.long	77
	.long	78
	.long	79
	.long	80
	.long	81
	.long	82
	.long	83
	.long	84
	.long	85
	.long	86
	.long	87
	.long	88
	.long	89
	.long	90
	.long	97
	.long	98
	.long	99
	.long	100
	.long	101
	.long	102
	.long	103
	.long	104
	.long	105
	.long	106
	.long	107
	.long	108
	.long	109
	.long	110
	.long	111
	.long	112
	.long	113
	.long	114
	.long	115
	.long	116
	.long	117
	.long	118
	.long	119
	.long	120
	.long	121
	.long	122
	.long	48
	.long	49
	.long	50
	.long	51
	.long	52
	.long	53
	.long	54
	.long	55
	.long	56
	.long	57
	.long	43
	.long	47
	.globl	lookup32
	.align 64
	.type	lookup32, @object
	.size	lookup32, 256
lookup32:
	.long	65
	.long	66
	.long	67
	.long	68
	.long	69
	.long	70
	.long	71
	.long	72
	.long	73
	.long	74
	.long	75
	.long	76
	.long	77
	.long	78
	.long	79
	.long	80
	.long	81
	.long	82
	.long	83
	.long	84
	.long	85
	.long	86
	.long	87
	.long	88
	.long	89
	.long	90
	.long	97
	.long	98
	.long	99
	.long	100
	.long	101
	.long	102
	.long	103
	.long	104
	.long	105
	.long	106
	.long	107
	.long	108
	.long	109
	.long	110
	.long	111
	.long	112
	.long	113
	.long	114
	.long	115
	.long	116
	.long	117
	.long	118
	.long	119
	.long	120
	.long	121
	.long	122
	.long	48
	.long	49
	.long	50
	.long	51
	.long	52
	.long	53
	.long	54
	.long	55
	.long	56
	.long	57
	.long	43
	.long	47
	.globl	lookup8
	.align 64
	.type	lookup8, @object
	.size	lookup8, 64
lookup8:
	.byte	65
	.byte	66
	.byte	67
	.byte	68
	.byte	69
	.byte	70
	.byte	71
	.byte	72
	.byte	73
	.byte	74
	.byte	75
	.byte	76
	.byte	77
	.byte	78
	.byte	79
	.byte	80
	.byte	81
	.byte	82
	.byte	83
	.byte	84
	.byte	85
	.byte	86
	.byte	87
	.byte	88
	.byte	89
	.byte	90
	.byte	97
	.byte	98
	.byte	99
	.byte	100
	.byte	101
	.byte	102
	.byte	103
	.byte	104
	.byte	105
	.byte	106
	.byte	107
	.byte	108
	.byte	109
	.byte	110
	.byte	111
	.byte	112
	.byte	113
	.byte	114
	.byte	115
	.byte	116
	.byte	117
	.byte	118
	.byte	119
	.byte	120
	.byte	121
	.byte	122
	.byte	48
	.byte	49
	.byte	50
	.byte	51
	.byte	52
	.byte	53
	.byte	54
	.byte	55
	.byte	56
	.byte	57
	.byte	43
	.byte	47
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
