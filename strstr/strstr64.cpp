/*

	Karp-Rabin string search modification 

	Instead of fancy hash function we use equality
	of first and last character of searched substring:

	size_t n = strlen(string);
	size_t k = strlen(substring)

	size_t first = 0;
	size_t last  = k - 1;

	for (i=0; i < n - k; i++) {
		if (string[i] == substring[first] and string[i + n - 1] == substring[last]) {
			// exact compare substring and string[i .. i + n]
		}
	}
*/


size_t strstr64(const char* s, size_t n, const char* neddle) {
	// 1. calculate first and last indexes
	// instead of comparision single first & last characters
	// we compare 4 bytes at once [on 64-bit machines we can use 8 bytes]
	const size_t k = strlen(neddle);
	const size_t last_pos = k - 1;
	
	const uint64_t first = 0x0101010101010101llu * static_cast<uint8_t>(neddle[0]);
	const uint64_t last  = 0x0101010101010101llu * static_cast<uint8_t>(neddle[last_pos]);

	uint64_t* block_first = reinterpret_cast<uint64_t*>(const_cast<char*>(s));
	uint64_t* block_last  = reinterpret_cast<uint64_t*>(const_cast<char*>(s + last_pos));

	// 2. sequence scan
	for (auto i=0u; i < n - k; i+=8, block_first++, block_last++) {
		// 0 bytes in eq indicate matching chars
		const uint64_t eq = (*block_first ^ first) | (*block_last ^ last);
		const uint64_t zeros = (eq - 0x0101010101010101u) & ((~eq) & 0x8080808080808080u);

		if (zeros) {
			uint64_t mask = 0x80;

			for (auto j=0u; j < 8; j++) {
				const char* substr = reinterpret_cast<char*>(block_first) + j + 1;
				if ((zeros & mask) && memcmp(substr, neddle + 1, k - 1) == 0) {
					return i + j;
				}

				mask <<= 8;
			}
		}
	}

	return NOT_FOUND;
}
