void dump_epu16(__m256i v) {
    uint16_t tmp[16];

    _mm256_storeu_si256((__m256i*)tmp, v);
    printf("[ %5u ", tmp[0]);
    for (int i=1; i < 16; i++)
        printf("| %5u ", tmp[i]);

    printf(" ]\n");
}


void dump_epi32(__m256i v) {
    int32_t tmp[8];

    _mm256_storeu_si256((__m256i*)tmp, v);
    printf("[ %6d ", tmp[0]);
    for (int i=1; i < 8; i++)
        printf("| %6d ", tmp[i]);

    printf(" ]\n");
}


void dump_epi32_hex(__m256i v) {
    int32_t tmp[8];

    _mm256_storeu_si256((__m256i*)tmp, v);
    printf("[ %08x ", tmp[0]);
    for (int i=1; i < 8; i++)
        printf("| %08x ", tmp[i]);

    printf(" ]\n");
}


void dump_ps(__m256 v) {
    float tmp[8];

    _mm256_storeu_ps(tmp, v);
    printf("[ %f ", tmp[0]);
    for (int i=1; i < 8; i++)
        printf("| %f ", tmp[i]);

    printf(" ]\n");
}
