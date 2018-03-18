
uint32_t parse1_chunk(const char* s) {

    const uint32_t input = *reinterpret_cast<const uint32_t*>(s);

    const uint32_t t1 = input - packed32('0');

    const uint32_t t2a = t1 & 0xffff;
    const uint32_t t2b = t1 >> 16;

    const uint32_t t3a = ((t2a * (2561)) >> 8) & 0xff;
    const uint32_t t3b = ((t2b * (2561)) >> 8) & 0xff;

    const uint32_t t4  = t3a | (t3b << 16);

    return (t4 * (6553601) >> 16);
}


// ------------------------------------------------------------------------


uint32_t parse2_chunk(const char* s) {

    const uint32_t input = bswap(*reinterpret_cast<const uint32_t*>(s));

    const uint32_t t1 = input - packed32('0');
    const uint32_t t2 = t1 & 0xff00ff00;
    const uint32_t t3 = (t2 >> (8-1)) + (t2 >> (8-3));
    const uint32_t t4 = t1 + t3;
    const uint32_t t5 = t4 & 0x00ff00ff;
    
    // reversed order, so multiplier is diffrent
    return (t5 * (100 + 65536)) >> 16;
}


// ------------------------------------------------------------------------


uint32_t parse3_chunk(const char* s) {

    const uint32_t input = bswap(*reinterpret_cast<const uint32_t*>(s));

    const uint32_t t1 = input - packed32('0');
    const uint32_t t2 = (t1 * 10) >> 8;

    const uint32_t t3 = t1 + t2;
    const uint32_t t4 = t3 & 0x00ff00ff;

    return (t4 * (100 + 65536)) >> 16;
}


uint64_t parse1(const char* s) {
    return convchunk_aux(parse1_chunk, s);
}

uint64_t parse2(const char* s) {
    return convchunk_aux(parse2_chunk, s);
}

uint64_t parse3(const char* s) {
    return convchunk_aux(parse3_chunk, s);
}

