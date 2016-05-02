void blend() {
	int n = width * height * 4;

	uint8_t *iA = imgA;
	uint8_t *iB = imgB;
	uint8_t *iD = data;

	uint32_t a1 = alpha;
	uint32_t a2 = 255 - alpha;

	uint32_t R, G, B;
	uint32_t R1, G1, B1;
	uint32_t R2, G2, B2;

	while (n--) {
		R1 =  (*iA) & 0xff;
		G1 = ((*iA) >>  8) & 0xff;
		B1 = ((*iA) >> 16) & 0xff;
		
		R2 =  (*iB) & 0xff;
		G2 = ((*iB) >>  8) & 0xff;
		B2 = ((*iB) >> 16) & 0xff;

		R = (R1*a1 + R2*a2) >> 8;
		G = (G1*a1 + G2*a2) >> 8;
		B = (B1*a1 + B2*a2) >> 8;

		if (R > 255) R = 255;
		if (G > 255) G = 255;
		if (B > 255) B = 255;

		(*iD) = R | (G << 8) | (B << 16);

		iA++;
		iB++;
		iD++;
	}
}

