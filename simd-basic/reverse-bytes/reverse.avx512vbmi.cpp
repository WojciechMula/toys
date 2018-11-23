__m512i reverse_avx512vbmi(const __m512i v) {

    // reverse order of all bytes at once
    const __m512i indices_byte = _mm512_set_epi64(
        0x0001020304050607llu, 0x08090a0b0c0d0e0fllu,
        0x1011121314151617llu, 0x18191a1b1c1d1e1fllu,
        0x2021222324252627llu, 0x28292a2b2c2d2e2fllu,
        0x3031323334353637llu, 0x38393a3b3c3d3e3fllu
    );

    return _mm512_permutexvar_epi8(indices_byte, v);
}

