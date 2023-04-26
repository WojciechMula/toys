//lookup: name=lookup_pascal, dataset=pascal
int lookup_pascal(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static char lookup[16][2] = {
                {'i', 'f'},
                {'o', 'f'},
                {}, // no match
                {}, // no match
                {'i', 'n'},
                {'d', 'o'},
                {}, // no match
                {'t', 'o'},
                {}, // no match
                {'o', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[16] = {
                35,
                20,
                -1,
                -1,
                18,
                28,
                -1,
                30,
                -1,
                13,
                -1,
                -1,
                -1,
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
            static char lookup[128][3] = {
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
                {'a', 'n', 'd'},
                {'e', 'n', 'd'},
                {}, // no match
                {'m', 'o', 'd'},
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
                {'n', 'i', 'l'},
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
                {'v', 'a', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'o', 'r'},
                {}, // no match
                {}, // no match
                {'s', 'e', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'n', 'o', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'i', 'v'},
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
            static int value[128] = {
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
                2,
                32,
                -1,
                33,
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
                16,
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
                5,
                -1,
                -1,
                -1,
                23,
                -1,
                -1,
                9,
                -1,
                -1,
                -1,
                -1,
                15,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                29,
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
            // combine 2 loads
            uint32_t w1;
            uint16_t w2 = 0;
            memcpy(&w2, &s[0], 2);
            w1 = uint32_t(w2);
            const uint8_t w3 = s[2];
            w1 |= (uint32_t(w3) << 16);
            const uint64_t idx = _pext_u64(w1, 0x1e0904);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static char lookup[32][4] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'y', 'p', 'e'},
                {'c', 'a', 's', 'e'},
                {'e', 'l', 's', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'w', 'i', 't', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'h', 'e', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'g', 'o', 't', 'o'},
                {}, // no match
                {}, // no match
            };
            static int value[32] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                25,
                -1,
                -1,
                -1,
                31,
                4,
                26,
                -1,
                -1,
                -1,
                -1,
                -1,
                0,
                -1,
                -1,
                -1,
                8,
                -1,
                -1,
                -1,
                21,
                -1,
                -1,
            };
            uint32_t w4 = 0;
            memcpy(&w4, &s[0], 4);
            const uint64_t idx = _pext_u64(w4, 0xc120800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static char lookup[16][5] = {
                {}, // no match
                {'w', 'h', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {'l', 'a', 'b', 'e', 'l'},
                {'u', 'n', 't', 'i', 'l'},
                {}, // no match
                {'b', 'e', 'g', 'i', 'n'},
                {'c', 'o', 'n', 's', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'a', 'r', 'r', 'a', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[16] = {
                -1,
                24,
                -1,
                -1,
                17,
                7,
                -1,
                34,
                6,
                -1,
                -1,
                -1,
                1,
                -1,
                -1,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[3], 2);
            const uint64_t idx = _pext_u64(w5, 0x1a08);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static char lookup[8][6] = {
                {'p', 'a', 'c', 'k', 'e', 'd'},
                {'r', 'e', 'c', 'o', 'r', 'd'},
                {}, // no match
                {'d', 'o', 'w', 'n', 't', 'o'},
                {'r', 'e', 'p', 'e', 'a', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[8] = {
                14,
                10,
                -1,
                27,
                19,
                -1,
                -1,
                -1,
            };
            uint16_t w6 = 0;
            memcpy(&w6, &s[4], 2);
            const uint64_t idx = _pext_u64(w6, 0x1810);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            if (s == "program") {
                return 11;
            }
            if (s == "forward") {
                return 22;
            }
        }
        break;
        case 8: {
            if (s == "function") {
                return 3;
            }
        }
        break;
        case 9: {
            if (s == "procedure") {
                return 12;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_pascal, dataset=pascal
void check_pascal() {
    assert(lookup_pascal("with") == 0);
    assert(lookup_pascal("case") == 4);
    assert(lookup_pascal("then") == 8);
    assert(lookup_pascal("goto") == 21);
    assert(lookup_pascal("file") == 25);
    assert(lookup_pascal("else") == 26);
    assert(lookup_pascal("type") == 31);
    assert(lookup_pascal("array") == 1);
    assert(lookup_pascal("const") == 6);
    assert(lookup_pascal("until") == 7);
    assert(lookup_pascal("label") == 17);
    assert(lookup_pascal("while") == 24);
    assert(lookup_pascal("begin") == 34);
    assert(lookup_pascal("and") == 2);
    assert(lookup_pascal("var") == 5);
    assert(lookup_pascal("set") == 9);
    assert(lookup_pascal("not") == 15);
    assert(lookup_pascal("nil") == 16);
    assert(lookup_pascal("for") == 23);
    assert(lookup_pascal("div") == 29);
    assert(lookup_pascal("end") == 32);
    assert(lookup_pascal("mod") == 33);
    assert(lookup_pascal("function") == 3);
    assert(lookup_pascal("record") == 10);
    assert(lookup_pascal("packed") == 14);
    assert(lookup_pascal("repeat") == 19);
    assert(lookup_pascal("downto") == 27);
    assert(lookup_pascal("program") == 11);
    assert(lookup_pascal("forward") == 22);
    assert(lookup_pascal("procedure") == 12);
    assert(lookup_pascal("or") == 13);
    assert(lookup_pascal("in") == 18);
    assert(lookup_pascal("of") == 20);
    assert(lookup_pascal("do") == 28);
    assert(lookup_pascal("to") == 30);
    assert(lookup_pascal("if") == 35);
}

