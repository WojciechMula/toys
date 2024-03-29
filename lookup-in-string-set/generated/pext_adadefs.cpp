//lookup: name=lookup_adadefs_pext, type=pext, dataset=adadefs
int lookup_adadefs_pext(std::string_view s) {
    switch (s.size()) {
        case 3: {
            static constexpr const char lookup[4][3] = {
                {}, // no match
                {'v', 'a', 'l'},
                {'p', 'o', 's'},
                {'a', 'f', 't'},
            };
            static constexpr const int value[4] = {
                -1,
                51,
                39,
                15,
            };
            const uint8_t w0 = s[2];
            const uint64_t idx = _pext_u64(w0, 0x14);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[32][4] = {
                {}, // no match
                {'e', 'm', 'a', 'x'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'s', 'u', 'c', 'c'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'l', 'a', 's', 't'},
                {}, // no match
                {'p', 'r', 'e', 'd'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'o', 'r', 'e'},
                {'b', 'a', 's', 'e'},
                {}, // no match
                {'t', 'r', 'u', 'e'},
                {'s', 'i', 'z', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                -1,
                22,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                49,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                29,
                -1,
                41,
                -1,
                -1,
                -1,
                -1,
                26,
                16,
                -1,
                13,
                46,
                -1,
                -1,
                -1,
            };
            uint16_t w1 = 0;
            memcpy(&w1, &s[2], 2);
            const uint64_t idx = _pext_u64(w1, 0x50d);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[128][5] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'e', 'l', 't', 'a'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'i', 'm', 'a', 'g', 'e'},
                {'r', 'a', 'n', 'g', 'e'},
                {'l', 'a', 'r', 'g', 'e'},
                {}, // no match
                {}, // no match
                {'f', 'a', 'l', 's', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'v', 'a', 'l', 'u', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'w', 'i', 'd', 't', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'s', 'm', 'a', 'l', 'l'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'l', 'o', 'a', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'c', 'o', 'u', 'n', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'i', 'r', 's', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[128] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                20,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                27,
                42,
                28,
                -1,
                -1,
                3,
                -1,
                -1,
                -1,
                52,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                53,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                47,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                4,
                -1,
                -1,
                -1,
                -1,
                19,
                -1,
                -1,
                -1,
                24,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint32_t w2 = 0;
            memcpy(&w2, &s[1], 4);
            const uint64_t idx = _pext_u64(w2, 0x1c141800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[4][6] = {
                {'s', 't', 'r', 'i', 'n', 'g'},
                {'l', 'e', 'n', 'g', 't', 'h'},
                {'d', 'i', 'g', 'i', 't', 's'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                11,
                31,
                21,
                -1,
            };
            const uint8_t w3 = s[5];
            const uint64_t idx = _pext_u64(w3, 0x18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[16][7] = {
                {'n', 'a', 't', 'u', 'r', 'a', 'l'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'b', 'o', 'o', 'l', 'e', 'a', 'n'},
                {'e', 'p', 's', 'i', 'l', 'o', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'l', 'a', 's', 't', 'b', 'i', 't'},
                {}, // no match
                {}, // no match
                {'i', 'n', 't', 'e', 'g', 'e', 'r'},
                {}, // no match
                {'a', 'd', 'd', 'r', 'e', 's', 's'},
                {}, // no match
            };
            static constexpr const int value[16] = {
                6,
                -1,
                -1,
                -1,
                0,
                23,
                -1,
                -1,
                -1,
                30,
                -1,
                -1,
                5,
                -1,
                14,
                -1,
            };
            uint16_t w4 = 0;
            memcpy(&w4, &s[5], 2);
            const uint64_t idx = _pext_u64(w4, 0x1308);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[16][8] = {
                {}, // no match
                {'m', 'a', 'n', 't', 'i', 's', 's', 'a'},
                {'c', 'a', 'l', 'l', 'a', 'b', 'l', 'e'},
                {'p', 'o', 's', 'i', 't', 'i', 'v', 'e'},
                {}, // no match
                {}, // no match
                {'p', 'o', 's', 'i', 't', 'i', 'o', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'i', 'r', 's', 't', 'b', 'i', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                -1,
                38,
                17,
                8,
                -1,
                -1,
                40,
                -1,
                -1,
                -1,
                25,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[6], 2);
            const uint64_t idx = _pext_u64(w5, 0x1c10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            if (s == "character") {
                return 1;
            }
            if (s == "safe_emax") {
                return 43;
            }
        }
        break;
        case 10: {
            static constexpr const char lookup[4][10] = {
                {'t', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'e', 'd'},
                {'s', 'a', 'f', 'e', '_', 'l', 'a', 'r', 'g', 'e'},
                {'s', 'a', 'f', 'e', '_', 's', 'm', 'a', 'l', 'l'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                50,
                44,
                45,
                -1,
            };
            const uint8_t w6 = s[9];
            const uint64_t idx = _pext_u64(w6, 0x9);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 11: {
            if (s == "constrained") {
                return 18;
            }
        }
        break;
        case 12: {
            static constexpr const char lookup[4][12] = {
                {'s', 't', 'o', 'r', 'a', 'g', 'e', '_', 's', 'i', 'z', 'e'},
                {'m', 'a', 'c', 'h', 'i', 'n', 'e', '_', 'e', 'm', 'i', 'n'},
                {}, // no match
                {'m', 'a', 'c', 'h', 'i', 'n', 'e', '_', 'e', 'm', 'a', 'x'},
            };
            static constexpr const int value[4] = {
                48,
                33,
                -1,
                32,
            };
            const uint8_t w7 = s[11];
            const uint64_t idx = _pext_u64(w7, 0x18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 13: {
            static constexpr const char lookup[16][13] = {
                {}, // no match
                {'n', 'u', 'm', 'e', 'r', 'i', 'c', '_', 'e', 'r', 'r', 'o', 'r'},
                {'s', 't', 'o', 'r', 'a', 'g', 'e', '_', 'e', 'r', 'r', 'o', 'r'},
                {'t', 'a', 's', 'k', 'i', 'n', 'g', '_', 'e', 'r', 'r', 'o', 'r'},
                {}, // no match
                {}, // no match
                {'p', 'r', 'o', 'g', 'r', 'a', 'm', '_', 'e', 'r', 'r', 'o', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'m', 'a', 'c', 'h', 'i', 'n', 'e', '_', 'r', 'a', 'd', 'i', 'x'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                -1,
                7,
                10,
                12,
                -1,
                -1,
                9,
                -1,
                -1,
                -1,
                36,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint64_t w8 = 0;
            memcpy(&w8, &s[5], 8);
            const uint64_t idx = _pext_u64(w8, 0x800000000000e00);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 14: {
            if (s == "machine_rounds") {
                return 37;
            }
        }
        break;
        case 16: {
            if (s == "constraint_error") {
                return 2;
            }
            if (s == "machine_mantissa") {
                return 34;
            }
        }
        break;
        case 17: {
            if (s == "machine_overflows") {
                return 35;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_adadefs_pext, type=pext, dataset=adadefs
void check_adadefs_pext() {
    assert(lookup_adadefs_pext("boolean") == 0);
    assert(lookup_adadefs_pext("character") == 1);
    assert(lookup_adadefs_pext("constraint_error") == 2);
    assert(lookup_adadefs_pext("false") == 3);
    assert(lookup_adadefs_pext("float") == 4);
    assert(lookup_adadefs_pext("integer") == 5);
    assert(lookup_adadefs_pext("natural") == 6);
    assert(lookup_adadefs_pext("numeric_error") == 7);
    assert(lookup_adadefs_pext("positive") == 8);
    assert(lookup_adadefs_pext("program_error") == 9);
    assert(lookup_adadefs_pext("storage_error") == 10);
    assert(lookup_adadefs_pext("string") == 11);
    assert(lookup_adadefs_pext("tasking_error") == 12);
    assert(lookup_adadefs_pext("true") == 13);
    assert(lookup_adadefs_pext("address") == 14);
    assert(lookup_adadefs_pext("aft") == 15);
    assert(lookup_adadefs_pext("base") == 16);
    assert(lookup_adadefs_pext("callable") == 17);
    assert(lookup_adadefs_pext("constrained") == 18);
    assert(lookup_adadefs_pext("count") == 19);
    assert(lookup_adadefs_pext("delta") == 20);
    assert(lookup_adadefs_pext("digits") == 21);
    assert(lookup_adadefs_pext("emax") == 22);
    assert(lookup_adadefs_pext("epsilon") == 23);
    assert(lookup_adadefs_pext("first") == 24);
    assert(lookup_adadefs_pext("firstbit") == 25);
    assert(lookup_adadefs_pext("fore") == 26);
    assert(lookup_adadefs_pext("image") == 27);
    assert(lookup_adadefs_pext("large") == 28);
    assert(lookup_adadefs_pext("last") == 29);
    assert(lookup_adadefs_pext("lastbit") == 30);
    assert(lookup_adadefs_pext("length") == 31);
    assert(lookup_adadefs_pext("machine_emax") == 32);
    assert(lookup_adadefs_pext("machine_emin") == 33);
    assert(lookup_adadefs_pext("machine_mantissa") == 34);
    assert(lookup_adadefs_pext("machine_overflows") == 35);
    assert(lookup_adadefs_pext("machine_radix") == 36);
    assert(lookup_adadefs_pext("machine_rounds") == 37);
    assert(lookup_adadefs_pext("mantissa") == 38);
    assert(lookup_adadefs_pext("pos") == 39);
    assert(lookup_adadefs_pext("position") == 40);
    assert(lookup_adadefs_pext("pred") == 41);
    assert(lookup_adadefs_pext("range") == 42);
    assert(lookup_adadefs_pext("safe_emax") == 43);
    assert(lookup_adadefs_pext("safe_large") == 44);
    assert(lookup_adadefs_pext("safe_small") == 45);
    assert(lookup_adadefs_pext("size") == 46);
    assert(lookup_adadefs_pext("small") == 47);
    assert(lookup_adadefs_pext("storage_size") == 48);
    assert(lookup_adadefs_pext("succ") == 49);
    assert(lookup_adadefs_pext("terminated") == 50);
    assert(lookup_adadefs_pext("val") == 51);
    assert(lookup_adadefs_pext("value") == 52);
    assert(lookup_adadefs_pext("width") == 53);
}

