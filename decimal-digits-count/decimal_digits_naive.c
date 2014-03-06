
int decimal_digits_naive(int x) {
	assert(x >= 0);

	if (x == 0)
		return 1;

	int pow = 1;
	int digits = 0;

	while (x >= pow) {
		pow *= 10;
		digits += 1;
	}

	return digits;
}
