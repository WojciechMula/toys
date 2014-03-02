size_t strstr32(const char* s, size_t n, const char* neddle) {
	const size_t k = strlen(neddle);
	size_t last_pos = k - 1;
	
	while (last_pos > 0) {
		if (neddle[0] != neddle[last_pos])
			break;

		last_pos -= 1;
	}

	if (last_pos == 0) {
		// neddle contains single char
		// we could use some specalized matcher here...
	}

	const uint32_t first = 0x01010101 * static_cast<uint8_t>(neddle[0]);
	const uint32_t last  = 0x01010101 * static_cast<uint8_t>(neddle[last_pos]);

	uint32_t* block_first = reinterpret_cast<uint32_t*>(const_cast<char*>(s));
	uint32_t* block_last  = reinterpret_cast<uint32_t*>(const_cast<char*>(s + last_pos));

	for (auto i=0u; i < n - k; i+=4, block_first++, block_last++) {
		const uint32_t t1 = (*block_first ^ first) | (*block_last ^ last);
		const uint32_t t2 = (t1 - 0x01010101u) & ((~t1) & 0x80808080u);

		if (t2) {
			uint32_t mask = 0x80;
			for (auto j=0u; j < 4; j++) {
				const char* substr = reinterpret_cast<char*>(block_first) + j + 1;
				if ((t2 & mask) && memcmp(substr, neddle + 1, k - 1) == 0) {
					return i + j;
				}

				mask <<= 8;
			}
		}
	}

	return NOT_FOUND;
}

