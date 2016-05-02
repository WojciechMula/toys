void swar_64bit_blend() {

    const uint64_t alpha0 = alpha;
    const uint64_t alpha1 = 255 - alpha;

	const int n = width * height * 4;

    for (size_t i=0; i < n; i += 8) {
        const uint64_t A = *(uint64_t*)(imgA + i);
        const uint64_t B = *(uint64_t*)(imgB + i);

        uint64_t A0 = A & 0x00ff00ff00ff00ffllu;
        uint64_t B0 = B & 0x00ff00ff00ff00ffllu;
        uint64_t A1 = (A >> 8) & 0x00ff00ff00ff00ffllu;
        uint64_t B1 = (B >> 8) & 0x00ff00ff00ff00ffllu;

        A0 *= alpha0;
        B0 *= alpha1;
        A1 *= alpha0;
        B1 *= alpha1;

        const uint64_t R0 = ((A0 + B0) >> 8) & 0x00ff00ff00ff00ffllu;
        const uint64_t R1 = (A1 + B1) & 0xff00ff00ff00ff00llu;

        *(uint64_t*)(data + i) = (R0 | R1);
    }
}
