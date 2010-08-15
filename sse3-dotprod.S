/*
	Calculate 4 x dot product using SSE3 instructions, $Revision: 1.2 $
	
	New SSE3 instruction HADDPS is used.
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/
	
	License: public domain
	
	initial release 14.09.2007, last update $Date: 2008-06-08 23:00:44 $
*/

# start-snippet1
# void sse3_dotprod4(float vec1x4[4*4], float vec2x4[4*4], float result[4]);
sse3_dotprod4:
	mov	4(%esp), %eax	# vec1x4 address
	mov	8(%esp), %edx	# vec2x4 address

	# load 8 vectors		# index -> 0   1   2   3 
	movups	0x00(%eax), %xmm0	# xmm0 := x00 x01 x02 x03
	movups	0x00(%edx), %xmm1	# xmm1 := y00 y01 y02 y03
	movups	0x10(%eax), %xmm2	# xmm2 := x10 x11 x12 x13
	movups	0x10(%edx), %xmm3	# xmm3 := y10 y11 y12 y13
	movups	0x20(%eax), %xmm4	# xmm4 := x20 x21 x22 x23
	movups	0x20(%edx), %xmm5	# xmm5 := y20 y21 y22 y23
	movups	0x30(%eax), %xmm6	# xmm6 := x30 x31 x32 x33
	movups	0x30(%edx), %xmm7	# xmm7 := y30 y31 y32 y33

	# parallel multiplication
	mulps	%xmm1, %xmm0		# xmm0 := x0*y0 = d00 d01 d02 d03
	mulps	%xmm3, %xmm2		# xmm2 := x1*y1 = d10 d11 d12 d13
	mulps	%xmm5, %xmm4		# xmm4 := x2*y2 = d20 d21 d22 d13
	mulps	%xmm1, %xmm6		# xmm6 := x3*y3 = d30 d31 d32 d33

	# horizontal addition
	haddps	%xmm2, %xmm0		# xmm0 := |d00+d01|d02+d03|d10+d11|d12+d13|
	haddps	%xmm6, %xmm4		# xmm4 := |d20+d21|d22+d23|d30+d31|d32+d33|
	mov	12(%esp), %eax
	haddps	%xmm4, %xmm0		# xmm0 := | dot0  | dot1  | dot2  | dot 3 |

	# save result
	movups	%xmm0, (%eax)
	ret
# end1


# start-snippet2
# void sse3_dotprod4(float vec1x4[4*4], float vec2x4[4*4], float result[4]);
#      (pointers are 16-byte aligned)
sse3_dotprod4_aligned:
	mov	4(%esp), %eax	# vec1x4 address
	mov	8(%esp), %edx	# vec2x4 address

	# load 4 vectors (vec1)		# index -> 0   1   2   3 
	movaps	0x00(%eax), %xmm0	# xmm0 := x00 x01 x02 x03
	movaps	0x10(%eax), %xmm1	# xmm1 := x10 x11 x12 x13
	movaps	0x20(%eax), %xmm2	# xmm2 := x20 x21 x22 x23
	movaps	0x30(%eax), %xmm3	# xmm3 := x30 x31 x32 x33

	# parallel multiplication
	mulps	0x00(%edx), %xmm0	# xmm0 := x0*y0 = d00 d01 d02 d03
	mulps	0x10(%edx), %xmm2	# xmm2 := x1*y1 = d10 d11 d12 d13
	mulps	0x20(%edx), %xmm4	# xmm4 := x2*y2 = d20 d21 d22 d13
	mulps	0x30(%edx), %xmm6	# xmm6 := x3*y3 = d30 d31 d32 d33

	# horizontal addition
	haddps	%xmm2, %xmm0		# xmm0 := |d00+d01|d02+d03|d10+d11|d12+d13|
	haddps	%xmm6, %xmm4		# xmm4 := |d20+d21|d22+d23|d30+d31|d32+d33|
	mov	12(%esp), %eax
	haddps	%xmm4, %xmm0		# xmm0 := | dot0  | dot1  | dot2  | dot 3 |

	# save result
	movaps	%xmm0, (%eax)
	ret
# end2

# vim: ts=8 nowrap noexpandtab
