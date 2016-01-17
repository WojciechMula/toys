#include <cstdint>

#define EXTRACT_INDICES_FROM_BYTES \
    const uint8_t x0 = ptr[3*i + 0]; \
    const uint8_t x1 = ptr[3*i + 1]; \
    const uint8_t x2 = ptr[3*i + 2]; \
    const uint8_t a = x0 & 0x3f; \
    const uint8_t b = ((x1 & 0xf) << 2) | (x0 >> 6); \
    const uint8_t c = ((x2 & 0x3) << 4) | (x1 >> 4); \
    const uint8_t d = x2 >> 2;

#define EXTRACT_INDICES_FROM_DWORD \
    const uint32_t x = *reinterpret_cast<const uint32_t*>(&ptr[3*i]); \
    const uint8_t a = x & 0x3f; \
    const uint8_t b = (x >> 8) & 0x3f; \
    const uint8_t c = (x >> 16) & 0x3f; \
    const uint8_t d = (x >> 24) & 0x3f;

#define SAVE_BYTES \
    *r++ = lookup8[a]; \
    *r++ = lookup8[b]; \
    *r++ = lookup8[c]; \
    *r++ = lookup8[d];

#define SAVE_DWORD \
    *reinterpret_cast<uint32_t*>(r) = w; \
    r += 4;

#define CONSTRUCT_DWORD_FROM_1_LOOKUP \
    const uint32_t w =  uint32_t(lookup8[a]) \
                     | (uint32_t(lookup8[b]) << 8) \
                     | (uint32_t(lookup8[c]) << 16) \
                     | (uint32_t(lookup8[d]) << 24);

#define CONSTRUCT_DWORD_FROM_4_LOOKUPS \
    const uint32_t w = uint32_t(lookup32_0[a]) \
                     | uint32_t(lookup32_1[b]) \
                     | uint32_t(lookup32_2[c]) \
                     | uint32_t(lookup32_3[d]);


#define BASE64_LOOKUP(TYPE, N) { \
    (TYPE('A') << (N)), (TYPE('B') << (N)), (TYPE('C') << (N)), (TYPE('D') << (N)), \
    (TYPE('E') << (N)), (TYPE('F') << (N)), (TYPE('G') << (N)), (TYPE('H') << (N)), \
    (TYPE('I') << (N)), (TYPE('J') << (N)), (TYPE('K') << (N)), (TYPE('L') << (N)), \
    (TYPE('M') << (N)), (TYPE('N') << (N)), (TYPE('O') << (N)), (TYPE('P') << (N)), \
    (TYPE('Q') << (N)), (TYPE('R') << (N)), (TYPE('S') << (N)), (TYPE('T') << (N)), \
    (TYPE('U') << (N)), (TYPE('V') << (N)), (TYPE('W') << (N)), (TYPE('X') << (N)), \
    (TYPE('Y') << (N)), (TYPE('Z') << (N)), (TYPE('a') << (N)), (TYPE('b') << (N)), \
    (TYPE('c') << (N)), (TYPE('d') << (N)), (TYPE('e') << (N)), (TYPE('f') << (N)), \
    (TYPE('g') << (N)), (TYPE('h') << (N)), (TYPE('i') << (N)), (TYPE('j') << (N)), \
    (TYPE('k') << (N)), (TYPE('l') << (N)), (TYPE('m') << (N)), (TYPE('n') << (N)), \
    (TYPE('o') << (N)), (TYPE('p') << (N)), (TYPE('q') << (N)), (TYPE('r') << (N)), \
    (TYPE('s') << (N)), (TYPE('t') << (N)), (TYPE('u') << (N)), (TYPE('v') << (N)), \
    (TYPE('w') << (N)), (TYPE('x') << (N)), (TYPE('y') << (N)), (TYPE('z') << (N)), \
    (TYPE('0') << (N)), (TYPE('1') << (N)), (TYPE('2') << (N)), (TYPE('3') << (N)), \
    (TYPE('4') << (N)), (TYPE('5') << (N)), (TYPE('6') << (N)), (TYPE('7') << (N)), \
    (TYPE('8') << (N)), (TYPE('9') << (N)), (TYPE('+') << (N)), (TYPE('/') << (N)) }

uint8_t  lookup8[64] = BASE64_LOOKUP(uint8_t, 0);
uint32_t lookup32[64] = BASE64_LOOKUP(uint32_t, 0);
uint32_t lookup32_0[64] = BASE64_LOOKUP(uint32_t, 0);
uint32_t lookup32_1[64] = BASE64_LOOKUP(uint32_t, 8);
uint32_t lookup32_2[64] = BASE64_LOOKUP(uint32_t, 16);
uint32_t lookup32_3[64] = BASE64_LOOKUP(uint32_t, 24);


void encode_triplets_1(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        EXTRACT_INDICES_FROM_BYTES
        SAVE_BYTES
    }
}

void encode_triplets_2(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        EXTRACT_INDICES_FROM_BYTES
        CONSTRUCT_DWORD_FROM_1_LOOKUP
        SAVE_DWORD
    }
}

void encode_triplets_3(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        EXTRACT_INDICES_FROM_BYTES
        CONSTRUCT_DWORD_FROM_4_LOOKUPS
        SAVE_DWORD
    }
}

void encode_triplets_4(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        EXTRACT_INDICES_FROM_DWORD
        SAVE_BYTES
    }
}

void encode_triplets_5(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        EXTRACT_INDICES_FROM_DWORD
        CONSTRUCT_DWORD_FROM_1_LOOKUP
        SAVE_DWORD
    }
}

void encode_triplets_6(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        EXTRACT_INDICES_FROM_DWORD
        CONSTRUCT_DWORD_FROM_4_LOOKUPS
        SAVE_DWORD
    }
}

void encode_triplets_7(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i+=2) {
        
        const uint64_t x = *reinterpret_cast<const uint32_t*>(&ptr[3*i]);

        const uint64_t a = (x >> (0*6)) & 0x3f;
        const uint64_t b = (x >> (1*6)) & 0x3f;
        const uint64_t c = (x >> (2*6)) & 0x3f;
        const uint64_t d = (x >> (3*6)) & 0x3f;
        const uint64_t e = (x >> (4*6)) & 0x3f;
        const uint64_t f = (x >> (5*6)) & 0x3f;
        const uint64_t g = (x >> (6*6)) & 0x3f;
        const uint64_t h = (x >> (7*6)) & 0x3f;

        *r++ = lookup8[a];
        *r++ = lookup8[b];
        *r++ = lookup8[c];
        *r++ = lookup8[d];
        *r++ = lookup8[e];
        *r++ = lookup8[f];
        *r++ = lookup8[g];
        *r++ = lookup8[h];
    }
}

//#define HAVE_BMI2_INSTRUCTION

#if defined(HAVE_BMI2_INSTRUCTION)

#include <immintrin.h>

void encode_triplets_8(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i+=2) {
        
        const uint64_t x = *reinterpret_cast<const uint64_t*>(&ptr[3*i]);

        const uint64_t a = x & 0x3f;//_bextr_u64(x, 0*6, 6);
        const uint64_t b = _bextr_u64(x, 1*6, 6);
        const uint64_t c = _bextr_u64(x, 2*6, 6);
        const uint64_t d = _bextr_u64(x, 3*6, 6);
        const uint64_t e = _bextr_u64(x, 4*6, 6);
        const uint64_t f = _bextr_u64(x, 5*6, 6);
        const uint64_t g = _bextr_u64(x, 6*6, 6);
        const uint64_t h = _bextr_u64(x, 7*6, 6);

        *r++ = lookup8[a];
        *r++ = lookup8[b];
        *r++ = lookup8[c];
        *r++ = lookup8[d];
        *r++ = lookup8[e];
        *r++ = lookup8[f];
        *r++ = lookup8[g];
        *r++ = lookup8[h];
    }
}


void encode_triplets_9(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint64_t* r = reinterpret_cast<uint64_t*>(output);

    for (unsigned i=0; i < count; i+=2) {
        
        const uint64_t x = *reinterpret_cast<const uint64_t*>(&ptr[3*i]);

        const uint64_t a = x & 0x3f;
        const uint64_t b = _bextr_u64(x, 1*6, 6);
        const uint64_t c = _bextr_u64(x, 2*6, 6);
        const uint64_t d = _bextr_u64(x, 3*6, 6);
        const uint64_t e = _bextr_u64(x, 4*6, 6);
        const uint64_t f = _bextr_u64(x, 5*6, 6);
        const uint64_t g = _bextr_u64(x, 6*6, 6);
        const uint64_t h = _bextr_u64(x, 7*6, 6);

        const uint64_t result = 0
          | (uint64_t(lookup8[a]) << 0*6)
          | (uint64_t(lookup8[b]) << 1*6)
          | (uint64_t(lookup8[c]) << 2*6)
          | (uint64_t(lookup8[d]) << 3*6)
          | (uint64_t(lookup8[e]) << 4*6)
          | (uint64_t(lookup8[f]) << 5*6)
          | (uint64_t(lookup8[g]) << 6*6)
          | (uint64_t(lookup8[h]) << 7*6);

        *r++ = result;
    }
}


void encode_triplets_10(const uint8_t* ptr, unsigned count, uint8_t* output) {

    uint8_t* r = output;

    for (unsigned i=0; i < count; i++) {
        
        const uint32_t x = *reinterpret_cast<const uint32_t*>(&ptr[3*i]);

        const uint32_t a = x & 0x3f;
        const uint32_t b = _bextr_u32(x, 1*6, 6);
        const uint32_t c = _bextr_u32(x, 2*6, 6);
        const uint32_t d = _bextr_u32(x, 3*6, 6);

        *r++ = lookup8[a];
        *r++ = lookup8[b];
        *r++ = lookup8[c];
        *r++ = lookup8[d];
    }
}

#endif // define(HAVE_BMI2_INSTRUCTION)
