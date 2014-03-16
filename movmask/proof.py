def byte_to_qword(byte):
	assert 0 <= byte <= 255

	def get(i):
		if byte & (1 << i):
			return 1 << (8*(i + 1) - 1)
		else:
			return 0

	return get(0) | get(1) | get(2) | get(3) | get(4) | get(5) | get(6) | get(7)

	      
def qword_to_byte(qword):
	assert (qword & 0x7f7f7f7f7f7f7f7f) == 0

	constant = (1 << 8)         | \
	           (1 << (2*8 - 1)) | \
	           (1 << (3*8 - 2)) | \
	           (1 << (4*8 - 3)) | \
	           (1 << (5*8 - 4)) | \
	           (1 << (6*8 - 5)) | \
	           (1 << (7*8 - 6)) | \
	           (1 << (8*8 - 7))

	assert constant < 2**64

	return ((qword * constant) >> 64) & 0xff

def proof():
	for byte in xrange(256):
		q = byte_to_qword(byte)

		result = qword_to_byte(q)

		assert result == byte, 'expected %d, got %d' % (byte, result)

	return True

if __name__ == '__main__':
	print proof()
