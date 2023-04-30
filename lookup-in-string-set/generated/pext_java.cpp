//lookup: name=lookup_java_pext, type=pext, dataset=java
int lookup_java_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "if") {
                return 2;
            }
            if (s == "do") {
                return 6;
            }
        }
        break;
        case 3: {
            static constexpr const char lookup[4][3] = {
                {'t', 'r', 'y'},
                {'f', 'o', 'r'},
                {'i', 'n', 't'},
                {'n', 'e', 'w'},
            };
            static constexpr const int value[4] = {
                19,
                40,
                22,
                41,
            };
            const uint8_t w0 = s[2];
            const uint64_t idx = _pext_u64(w0, 0x6);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[32][4] = {
                {}, // no match
                {'v', 'o', 'i', 'd'},
                {}, // no match
                {}, // no match
                {'c', 'a', 's', 'e'},
                {'e', 'l', 's', 'e'},
                {}, // no match
                {'b', 'y', 't', 'e'},
                {}, // no match
                {'c', 'h', 'a', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'h', 'i', 's'},
                {}, // no match
                {'l', 'o', 'n', 'g'},
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
                {'g', 'o', 't', 'o'},
            };
            static constexpr const int value[32] = {
                -1,
                24,
                -1,
                -1,
                20,
                16,
                -1,
                15,
                -1,
                30,
                -1,
                -1,
                -1,
                46,
                -1,
                32,
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
                44,
            };
            uint32_t w1 = 0;
            memcpy(&w1, &s[0], 4);
            const uint64_t idx = _pext_u64(w1, 0xb040800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[32][5] = {
                {}, // no match
                {'c', 'a', 't', 'c', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'b', 'r', 'e', 'a', 'k'},
                {}, // no match
                {}, // no match
                {'w', 'h', 'i', 'l', 'e'},
                {'f', 'i', 'n', 'a', 'l'},
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
                {'s', 'u', 'p', 'e', 'r'},
                {}, // no match
                {'c', 'l', 'a', 's', 's'},
                {}, // no match
                {'f', 'l', 'o', 'a', 't'},
                {'s', 'h', 'o', 'r', 't'},
                {'c', 'o', 'n', 's', 't'},
                {}, // no match
                {'t', 'h', 'r', 'o', 'w'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                -1,
                25,
                -1,
                -1,
                -1,
                10,
                -1,
                -1,
                34,
                26,
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
                35,
                -1,
                36,
                23,
                39,
                -1,
                4,
                -1,
                -1,
            };
            uint16_t w2 = 0;
            memcpy(&w2, &s[3], 2);
            const uint64_t idx = _pext_u64(w2, 0x1611);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[32][6] = {
                {'p', 'u', 'b', 'l', 'i', 'c'},
                {'s', 't', 'a', 't', 'i', 'c'},
                {}, // no match
                {}, // no match
                {'d', 'o', 'u', 'b', 'l', 'e'},
                {}, // no match
                {'n', 'a', 't', 'i', 'v', 'e'},
                {}, // no match
                {}, // no match
                {'s', 'w', 'i', 't', 'c', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'r', 'e', 't', 'u', 'r', 'n'},
                {}, // no match
                {}, // no match
                {'t', 'h', 'r', 'o', 'w', 's'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'i', 'm', 'p', 'o', 'r', 't'},
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
                13,
                28,
                -1,
                -1,
                11,
                -1,
                37,
                -1,
                -1,
                38,
                -1,
                -1,
                -1,
                -1,
                -1,
                18,
                -1,
                -1,
                9,
                -1,
                -1,
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
            };
            uint32_t w3 = 0;
            memcpy(&w3, &s[2], 4);
            const uint64_t idx = _pext_u64(w3, 0x1c101000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[16][7] = {
                {}, // no match
                {}, // no match
                {'p', 'a', 'c', 'k', 'a', 'g', 'e'},
                {'p', 'r', 'i', 'v', 'a', 't', 'e'},
                {}, // no match
                {}, // no match
                {'b', 'o', 'o', 'l', 'e', 'a', 'n'},
                {}, // no match
                {'e', 'x', 't', 'e', 'n', 'd', 's'},
                {}, // no match
                {'d', 'e', 'f', 'a', 'u', 'l', 't'},
                {}, // no match
                {'f', 'i', 'n', 'a', 'l', 'l', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                -1,
                -1,
                45,
                3,
                -1,
                -1,
                5,
                -1,
                21,
                -1,
                1,
                -1,
                31,
                -1,
                -1,
                -1,
            };
            uint16_t w4 = 0;
            memcpy(&w4, &s[5], 2);
            const uint64_t idx = _pext_u64(w4, 0x1c10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[4][8] = {
                {'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'},
                {'c', 'o', 'n', 't', 'i', 'n', 'u', 'e'},
                {'a', 'b', 's', 't', 'r', 'a', 'c', 't'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                29,
                43,
                0,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[6], 2);
            const uint64_t idx = _pext_u64(w5, 0x1010);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static constexpr const char lookup[4][9] = {
                {'p', 'r', 'o', 't', 'e', 'c', 't', 'e', 'd'},
                {'i', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e'},
                {'t', 'r', 'a', 'n', 's', 'i', 'e', 'n', 't'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                8,
                27,
                14,
                -1,
            };
            const uint8_t w6 = s[8];
            const uint64_t idx = _pext_u64(w6, 0x11);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            if (s == "implements") {
                return 7;
            }
            if (s == "instanceof") {
                return 17;
            }
        }
        break;
        case 12: {
            if (s == "synchronized") {
                return 42;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_java_pext, type=pext, dataset=java
void check_java_pext() {
    assert(lookup_java_pext("abstract") == 0);
    assert(lookup_java_pext("volatile") == 29);
    assert(lookup_java_pext("continue") == 43);
    assert(lookup_java_pext("default") == 1);
    assert(lookup_java_pext("private") == 3);
    assert(lookup_java_pext("boolean") == 5);
    assert(lookup_java_pext("extends") == 21);
    assert(lookup_java_pext("finally") == 31);
    assert(lookup_java_pext("package") == 45);
    assert(lookup_java_pext("try") == 19);
    assert(lookup_java_pext("int") == 22);
    assert(lookup_java_pext("for") == 40);
    assert(lookup_java_pext("new") == 41);
    assert(lookup_java_pext("implements") == 7);
    assert(lookup_java_pext("instanceof") == 17);
    assert(lookup_java_pext("byte") == 15);
    assert(lookup_java_pext("else") == 16);
    assert(lookup_java_pext("case") == 20);
    assert(lookup_java_pext("void") == 24);
    assert(lookup_java_pext("char") == 30);
    assert(lookup_java_pext("long") == 32);
    assert(lookup_java_pext("goto") == 44);
    assert(lookup_java_pext("this") == 46);
    assert(lookup_java_pext("synchronized") == 42);
    assert(lookup_java_pext("throw") == 4);
    assert(lookup_java_pext("break") == 10);
    assert(lookup_java_pext("short") == 23);
    assert(lookup_java_pext("catch") == 25);
    assert(lookup_java_pext("final") == 26);
    assert(lookup_java_pext("super") == 33);
    assert(lookup_java_pext("while") == 34);
    assert(lookup_java_pext("class") == 35);
    assert(lookup_java_pext("float") == 36);
    assert(lookup_java_pext("const") == 39);
    assert(lookup_java_pext("protected") == 8);
    assert(lookup_java_pext("transient") == 14);
    assert(lookup_java_pext("interface") == 27);
    assert(lookup_java_pext("throws") == 9);
    assert(lookup_java_pext("double") == 11);
    assert(lookup_java_pext("import") == 12);
    assert(lookup_java_pext("public") == 13);
    assert(lookup_java_pext("return") == 18);
    assert(lookup_java_pext("static") == 28);
    assert(lookup_java_pext("native") == 37);
    assert(lookup_java_pext("switch") == 38);
    assert(lookup_java_pext("if") == 2);
    assert(lookup_java_pext("do") == 6);
}

