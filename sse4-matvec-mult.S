/*
	Mutiplication of matrix 4x4 and vector 4x1 using
	SSE4 instructions, $Revision: 1.3 $
	
	[a0 a1 a2 a3]   [X0]
	[b0 b1 b2 b3]   [X1]
	|           | * |  | = [y0 y1 y2 y3]
	[c0 c1 c2 c3]   [X2]
	[d0 d1 d2 d3]   [X3]
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/
	
	License: public domain
	
	initial release 13-00-2007, last update $Date: 2008-06-08 23:00:44 $
*/

# start-snippet
# void sse4_matvec_mult(float mat[4][4], float vec[4], float result[4]);
sse4_matvec_mult:
	mov	 4(%esp), %eax	# mat[0][0] address
	mov	 8(%esp), %edx	# vec address

	# load matrix                    column -> 0  1  2  3
	movups	0x00(%eax), %xmm0	# xmm0 := a0 a1 a2 a3  A row
	movups	0x10(%eax), %xmm1	# xmm1 := b0 b1 b2 b3  B  |
	movups	0x20(%eax), %xmm2	# xmm2 := c0 c1 c2 c3  C  v
	movups	0x30(%eax), %xmm3	# xmm3 := d0 d1 d2 d3  D

	# load vector
	movups	(%edx), %xmm4		# xmm4 := X0 X1 X2 X3

	# calculate result, i.e. get dot products
	# of input vector and all rows
	dpps	$0b11110001, %xmm4, %xmm0	# xmm0 := | dotA |  0   |  0   |  0   |
	dpps	$0b11110010, %xmm4, %xmm1	# xmm1 := |  0   | dotB |  0   |  0   |
	dpps	$0b11110100, %xmm4, %xmm2	# xmm2 := |  0   |  0   | dotC |  0   |
	dpps	$0b11111000, %xmm4, %xmm3	# xmm3 := |  0   |  0   |  0   | dotD |

	orps	%xmm1, %xmm0	# xmm0 := | dotA | dotB |  0   |  0   |
	orps	%xmm2, %xmm3	# xmm3 := |  0   |  0   | dotC | dotD |
	orps	%xmm3, %xmm0	# xmm0 := | dotA | dotB | dotC | dotD |
	
	# save result, i.e. xmm0
	mov	12(%esp), %eax	# result address
	movups	%xmm0, (%eax)

	ret
# end-snippet

# vim: ts=8 nowrap
