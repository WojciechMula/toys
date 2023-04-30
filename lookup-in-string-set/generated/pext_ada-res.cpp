//lookup: name=lookup_ada_res_pext, type=pext, dataset=ada-res
int lookup_ada_res_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static constexpr const char lookup[16][2] = {
                {}, // no match
                {}, // no match
                {'i', 'f'},
                {'o', 'f'},
                {}, // no match
                {}, // no match
                {'i', 'n'},
                {'d', 'o'},
                {'i', 's'},
                {'o', 'r'},
                {'a', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                -1,
                -1,
                54,
                45,
                -1,
                -1,
                52,
                43,
                53,
                46,
                32,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w0 = 0;
            memcpy(&w0, &s[0], 2);
            const uint64_t idx = _pext_u64(w0, 0x1c04);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 3: {
            static constexpr const char lookup[128][3] = {
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
                {'u', 's', 'e'},
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
                {'a', 'l', 'l'},
                {}, // no match
                {'r', 'e', 'm'},
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
                {'a', 'b', 's'},
                {}, // no match
                {'x', 'o', 'r'},
                {'f', 'o', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'n', 'o', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'o', 'u', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'n', 'e', 'w'},
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
                -1,
                -1,
                -1,
                35,
                8,
                -1,
                56,
                -1,
                -1,
                -1,
                41,
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
                47,
                -1,
                55,
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
                38,
                -1,
                59,
                21,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                11,
                -1,
                -1,
                -1,
                42,
                -1,
                -1,
                -1,
                27,
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
            // combine 2 loads
            uint32_t w1;
            uint16_t w2 = 0;
            memcpy(&w2, &s[0], 2);
            w1 = uint32_t(w2);
            const uint8_t w3 = s[2];
            w1 |= (uint32_t(w3) << 16);
            const uint64_t idx = _pext_u64(w1, 0x1e1104);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[32][4] = {
                {}, // no match
                {'w', 'i', 't', 'h'},
                {'l', 'o', 'o', 'p'},
                {}, // no match
                {}, // no match
                {'b', 'o', 'd', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'a', 's', 'k'},
                {}, // no match
                {'e', 'x', 'i', 't'},
                {'n', 'u', 'l', 'l'},
                {}, // no match
                {}, // no match
                {'t', 'y', 'p', 'e'},
                {}, // no match
                {'e', 'l', 's', 'e'},
                {'c', 'a', 's', 'e'},
                {'t', 'h', 'e', 'n'},
                {'w', 'h', 'e', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'g', 'o', 't', 'o'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                -1,
                62,
                49,
                -1,
                -1,
                58,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                51,
                -1,
                1,
                50,
                -1,
                -1,
                3,
                -1,
                0,
                30,
                12,
                26,
                -1,
                -1,
                -1,
                60,
                -1,
                -1,
            };
            uint32_t w4 = 0;
            memcpy(&w4, &s[0], 4);
            const uint64_t idx = _pext_u64(w4, 0x7020002);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[64][5] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'e', 'l', 't', 'a'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'r', 'a', 'n', 'g', 'e'},
                {}, // no match
                {'w', 'h', 'i', 'l', 'e'},
                {'e', 'l', 's', 'i', 'f'},
                {'r', 'a', 'i', 's', 'e'},
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
                {'b', 'e', 'g', 'i', 'n'},
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
                {'a', 'b', 'o', 'r', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'e', 'l', 'a', 'y'},
                {'a', 'r', 'r', 'a', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'e', 'n', 't', 'r', 'y'},
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
            static constexpr const int value[64] = {
                -1,
                -1,
                -1,
                -1,
                36,
                -1,
                -1,
                -1,
                5,
                -1,
                25,
                19,
                4,
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
                57,
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
                33,
                -1,
                -1,
                -1,
                29,
                40,
                -1,
                -1,
                -1,
                28,
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
            uint32_t w5 = 0;
            memcpy(&w5, &s[1], 4);
            const uint64_t idx = _pext_u64(w5, 0x1c181000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[32][6] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {'p', 'r', 'a', 'g', 'm', 'a'},
                {'r', 'e', 'c', 'o', 'r', 'd'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'r', 'e', 't', 'u', 'r', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'o', 't', 'h', 'e', 'r', 's'},
                {'a', 'c', 'c', 'e', 's', 's'},
                {'d', 'i', 'g', 'i', 't', 's'},
                {}, // no match
                {'a', 'c', 'c', 'e', 'p', 't'},
                {'s', 'e', 'l', 'e', 'c', 't'},
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
                39,
                9,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                13,
                -1,
                -1,
                -1,
                44,
                37,
                16,
                -1,
                34,
                15,
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
            uint16_t w6 = 0;
            memcpy(&w6, &s[4], 2);
            const uint64_t idx = _pext_u64(w6, 0x1c05);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[16][7] = {
                {'s', 'u', 'b', 't', 'y', 'p', 'e'},
                {'g', 'e', 'n', 'e', 'r', 'i', 'c'},
                {'d', 'e', 'c', 'l', 'a', 'r', 'e'},
                {'r', 'e', 'v', 'e', 'r', 's', 'e'},
                {'p', 'r', 'i', 'v', 'a', 't', 'e'},
                {'l', 'i', 'm', 'i', 't', 'e', 'd'},
                {}, // no match
                {'p', 'a', 'c', 'k', 'a', 'g', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'r', 'e', 'n', 'a', 'm', 'e', 's'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                18,
                61,
                7,
                6,
                24,
                48,
                -1,
                22,
                -1,
                -1,
                -1,
                -1,
                -1,
                17,
                -1,
                -1,
            };
            uint16_t w7 = 0;
            memcpy(&w7, &s[5], 2);
            const uint64_t idx = _pext_u64(w7, 0x1007);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[4][8] = {
                {'s', 'e', 'p', 'a', 'r', 'a', 't', 'e'},
                {'f', 'u', 'n', 'c', 't', 'i', 'o', 'n'},
                {'c', 'o', 'n', 's', 't', 'a', 'n', 't'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                14,
                20,
                31,
                -1,
            };
            const uint8_t w8 = s[7];
            const uint64_t idx = _pext_u64(w8, 0x18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static constexpr const char lookup[4][9] = {
                {'p', 'r', 'o', 'c', 'e', 'd', 'u', 'r', 'e'},
                {'t', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'e'},
                {}, // no match
                {'e', 'x', 'c', 'e', 'p', 't', 'i', 'o', 'n'},
            };
            static constexpr const int value[4] = {
                23,
                2,
                -1,
                10,
            };
            uint16_t w9 = 0;
            memcpy(&w9, &s[7], 2);
            const uint64_t idx = _pext_u64(w9, 0x804);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_ada_res_pext, type=pext, dataset=ada-res
void check_ada_res_pext() {
    assert(lookup_ada_res_pext("at") == 32);
    assert(lookup_ada_res_pext("do") == 43);
    assert(lookup_ada_res_pext("of") == 45);
    assert(lookup_ada_res_pext("or") == 46);
    assert(lookup_ada_res_pext("in") == 52);
    assert(lookup_ada_res_pext("is") == 53);
    assert(lookup_ada_res_pext("if") == 54);
    assert(lookup_ada_res_pext("else") == 0);
    assert(lookup_ada_res_pext("exit") == 1);
    assert(lookup_ada_res_pext("type") == 3);
    assert(lookup_ada_res_pext("then") == 12);
    assert(lookup_ada_res_pext("when") == 26);
    assert(lookup_ada_res_pext("case") == 30);
    assert(lookup_ada_res_pext("loop") == 49);
    assert(lookup_ada_res_pext("null") == 50);
    assert(lookup_ada_res_pext("task") == 51);
    assert(lookup_ada_res_pext("body") == 58);
    assert(lookup_ada_res_pext("goto") == 60);
    assert(lookup_ada_res_pext("with") == 62);
    assert(lookup_ada_res_pext("terminate") == 2);
    assert(lookup_ada_res_pext("exception") == 10);
    assert(lookup_ada_res_pext("procedure") == 23);
    assert(lookup_ada_res_pext("raise") == 4);
    assert(lookup_ada_res_pext("range") == 5);
    assert(lookup_ada_res_pext("elsif") == 19);
    assert(lookup_ada_res_pext("while") == 25);
    assert(lookup_ada_res_pext("entry") == 28);
    assert(lookup_ada_res_pext("delay") == 29);
    assert(lookup_ada_res_pext("abort") == 33);
    assert(lookup_ada_res_pext("delta") == 36);
    assert(lookup_ada_res_pext("array") == 40);
    assert(lookup_ada_res_pext("begin") == 57);
    assert(lookup_ada_res_pext("reverse") == 6);
    assert(lookup_ada_res_pext("declare") == 7);
    assert(lookup_ada_res_pext("renames") == 17);
    assert(lookup_ada_res_pext("subtype") == 18);
    assert(lookup_ada_res_pext("package") == 22);
    assert(lookup_ada_res_pext("private") == 24);
    assert(lookup_ada_res_pext("limited") == 48);
    assert(lookup_ada_res_pext("generic") == 61);
    assert(lookup_ada_res_pext("end") == 8);
    assert(lookup_ada_res_pext("not") == 11);
    assert(lookup_ada_res_pext("for") == 21);
    assert(lookup_ada_res_pext("new") == 27);
    assert(lookup_ada_res_pext("and") == 35);
    assert(lookup_ada_res_pext("abs") == 38);
    assert(lookup_ada_res_pext("use") == 41);
    assert(lookup_ada_res_pext("out") == 42);
    assert(lookup_ada_res_pext("all") == 47);
    assert(lookup_ada_res_pext("rem") == 55);
    assert(lookup_ada_res_pext("mod") == 56);
    assert(lookup_ada_res_pext("xor") == 59);
    assert(lookup_ada_res_pext("record") == 9);
    assert(lookup_ada_res_pext("return") == 13);
    assert(lookup_ada_res_pext("select") == 15);
    assert(lookup_ada_res_pext("digits") == 16);
    assert(lookup_ada_res_pext("accept") == 34);
    assert(lookup_ada_res_pext("access") == 37);
    assert(lookup_ada_res_pext("pragma") == 39);
    assert(lookup_ada_res_pext("others") == 44);
    assert(lookup_ada_res_pext("separate") == 14);
    assert(lookup_ada_res_pext("function") == 20);
    assert(lookup_ada_res_pext("constant") == 31);
}

