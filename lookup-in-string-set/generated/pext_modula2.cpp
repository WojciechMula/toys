//lookup: name=lookup_modula2_pext, type=pext, dataset=modula2
int lookup_modula2_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static constexpr const char lookup[16][2] = {
                {'I', 'F'},
                {'O', 'F'},
                {}, // no match
                {}, // no match
                {'I', 'N'},
                {'D', 'O'},
                {}, // no match
                {'T', 'O'},
                {}, // no match
                {'O', 'R'},
                {}, // no match
                {}, // no match
                {'B', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                16,
                24,
                -1,
                -1,
                19,
                8,
                -1,
                34,
                -1,
                25,
                -1,
                -1,
                3,
                -1,
                -1,
                -1,
            };
            uint16_t w0 = 0;
            memcpy(&w0, &s[0], 2);
            const uint64_t idx = _pext_u64(w0, 0x1814);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 3: {
            static constexpr const char lookup[64][3] = {
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
                {'A', 'N', 'D'},
                {'E', 'N', 'D'},
                {}, // no match
                {'M', 'O', 'D'},
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
                {'V', 'A', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'O', 'R'},
                {}, // no match
                {}, // no match
                {'S', 'E', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'O', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'I', 'V'},
            };
            static constexpr const int value[64] = {
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
                0,
                11,
                -1,
                21,
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
                37,
                -1,
                -1,
                -1,
                14,
                -1,
                -1,
                32,
                -1,
                -1,
                -1,
                -1,
                23,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                7,
            };
            // combine 2 loads
            uint32_t w1;
            uint16_t w2 = 0;
            memcpy(&w2, &s[0], 2);
            w1 = uint32_t(w2);
            const uint8_t w3 = s[2];
            w1 |= (uint32_t(w3) << 16);
            const uint64_t idx = _pext_u64(w1, 0x160904);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[32][4] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'Y', 'P', 'E'},
                {'C', 'A', 'S', 'E'},
                {'E', 'L', 'S', 'E'},
                {}, // no match
                {'W', 'I', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'H', 'E', 'N'},
                {'F', 'R', 'O', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'O', 'O', 'P'},
                {}, // no match
                {'E', 'X', 'I', 'T'},
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
            static constexpr const int value[32] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                35,
                4,
                9,
                -1,
                39,
                -1,
                -1,
                -1,
                33,
                15,
                -1,
                -1,
                -1,
                -1,
                20,
                -1,
                12,
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
            uint32_t w4 = 0;
            memcpy(&w4, &s[0], 4);
            const uint64_t idx = _pext_u64(w4, 0x1c020800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[8][5] = {
                {'W', 'H', 'I', 'L', 'E'},
                {'E', 'L', 'S', 'I', 'F'},
                {'U', 'N', 'T', 'I', 'L'},
                {'B', 'E', 'G', 'I', 'N'},
                {'C', 'O', 'N', 'S', 'T'},
                {}, // no match
                {'A', 'R', 'R', 'A', 'Y'},
                {}, // no match
            };
            static constexpr const int value[8] = {
                38,
                10,
                36,
                2,
                5,
                -1,
                1,
                -1,
            };
            const uint8_t w5 = s[4];
            const uint64_t idx = _pext_u64(w5, 0x1a);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[16][6] = {
                {'M', 'O', 'D', 'U', 'L', 'E'},
                {}, // no match
                {'R', 'E', 'C', 'O', 'R', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'R', 'E', 'T', 'U', 'R', 'N'},
                {}, // no match
                {'R', 'E', 'P', 'E', 'A', 'T'},
                {}, // no match
                {'I', 'M', 'P', 'O', 'R', 'T'},
                {'E', 'X', 'P', 'O', 'R', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                22,
                -1,
                29,
                -1,
                -1,
                -1,
                31,
                -1,
                30,
                -1,
                18,
                13,
                -1,
                -1,
                -1,
                -1,
            };
            // combine 2 loads
            uint64_t w6;
            uint32_t w7 = 0;
            memcpy(&w7, &s[1], 4);
            w6 = uint64_t(w7);
            const uint8_t w8 = s[5];
            w6 |= (uint64_t(w8) << 32);
            const uint64_t idx = _pext_u64(w6, 0x1810000010);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            if (s == "POINTER") {
                return 26;
            }
        }
        break;
        case 9: {
            if (s == "PROCEDURE") {
                return 27;
            }
            if (s == "QUALIFIED") {
                return 28;
            }
        }
        break;
        case 10: {
            if (s == "DEFINITION") {
                return 6;
            }
        }
        break;
        case 14: {
            if (s == "IMPLEMENTATION") {
                return 17;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_modula2_pext, type=pext, dataset=modula2
void check_modula2_pext() {
    assert(lookup_modula2_pext("ARRAY") == 1);
    assert(lookup_modula2_pext("BEGIN") == 2);
    assert(lookup_modula2_pext("CONST") == 5);
    assert(lookup_modula2_pext("ELSIF") == 10);
    assert(lookup_modula2_pext("UNTIL") == 36);
    assert(lookup_modula2_pext("WHILE") == 38);
    assert(lookup_modula2_pext("BY") == 3);
    assert(lookup_modula2_pext("DO") == 8);
    assert(lookup_modula2_pext("IF") == 16);
    assert(lookup_modula2_pext("IN") == 19);
    assert(lookup_modula2_pext("OF") == 24);
    assert(lookup_modula2_pext("OR") == 25);
    assert(lookup_modula2_pext("TO") == 34);
    assert(lookup_modula2_pext("EXPORT") == 13);
    assert(lookup_modula2_pext("IMPORT") == 18);
    assert(lookup_modula2_pext("MODULE") == 22);
    assert(lookup_modula2_pext("RECORD") == 29);
    assert(lookup_modula2_pext("REPEAT") == 30);
    assert(lookup_modula2_pext("RETURN") == 31);
    assert(lookup_modula2_pext("IMPLEMENTATION") == 17);
    assert(lookup_modula2_pext("POINTER") == 26);
    assert(lookup_modula2_pext("DEFINITION") == 6);
    assert(lookup_modula2_pext("PROCEDURE") == 27);
    assert(lookup_modula2_pext("QUALIFIED") == 28);
    assert(lookup_modula2_pext("AND") == 0);
    assert(lookup_modula2_pext("DIV") == 7);
    assert(lookup_modula2_pext("END") == 11);
    assert(lookup_modula2_pext("FOR") == 14);
    assert(lookup_modula2_pext("MOD") == 21);
    assert(lookup_modula2_pext("NOT") == 23);
    assert(lookup_modula2_pext("SET") == 32);
    assert(lookup_modula2_pext("VAR") == 37);
    assert(lookup_modula2_pext("CASE") == 4);
    assert(lookup_modula2_pext("ELSE") == 9);
    assert(lookup_modula2_pext("EXIT") == 12);
    assert(lookup_modula2_pext("FROM") == 15);
    assert(lookup_modula2_pext("LOOP") == 20);
    assert(lookup_modula2_pext("THEN") == 33);
    assert(lookup_modula2_pext("TYPE") == 35);
    assert(lookup_modula2_pext("WITH") == 39);
}

