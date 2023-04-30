//lookup: name=lookup_jscript_pext, type=pext, dataset=jscript
int lookup_jscript_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static char lookup[4][2] = {
                {'i', 'f'},
                {}, // no match
                {'i', 'n'},
                {'d', 'o'},
            };
            static int value[4] = {
                22,
                -1,
                25,
                11,
            };
            const uint8_t w0 = s[1];
            const uint64_t idx = _pext_u64(w0, 0x9);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 3: {
            static char lookup[8][3] = {
                {'v', 'a', 'r'},
                {'f', 'o', 'r'},
                {'n', 'e', 'w'},
                {'i', 'n', 't'},
                {'t', 'r', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[8] = {
                49,
                19,
                31,
                27,
                48,
                -1,
                -1,
                -1,
            };
            uint16_t w1 = 0;
            memcpy(&w1, &s[1], 2);
            const uint64_t idx = _pext_u64(w1, 0xc08);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static char lookup[32][4] = {
                {}, // no match
                {'v', 'o', 'i', 'd'},
                {}, // no match
                {}, // no match
                {'c', 'a', 's', 'e'},
                {'e', 'l', 's', 'e'},
                {'t', 'r', 'u', 'e'},
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
                {'n', 'u', 'l', 'l'},
                {'w', 'i', 't', 'h'},
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
            static int value[32] = {
                -1,
                50,
                -1,
                -1,
                4,
                13,
                47,
                3,
                -1,
                6,
                -1,
                -1,
                -1,
                43,
                -1,
                29,
                -1,
                -1,
                32,
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
                21,
            };
            uint32_t w2 = 0;
            memcpy(&w2, &s[0], 4);
            const uint64_t idx = _pext_u64(w2, 0xb040800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static char lookup[32][5] = {
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
                {'f', 'a', 'l', 's', 'e'},
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
            static int value[32] = {
                -1,
                5,
                -1,
                -1,
                -1,
                2,
                -1,
                -1,
                51,
                16,
                -1,
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
                40,
                -1,
                7,
                -1,
                18,
                38,
                8,
                -1,
                44,
                -1,
                -1,
            };
            uint16_t w3 = 0;
            memcpy(&w3, &s[3], 2);
            const uint64_t idx = _pext_u64(w3, 0x1611);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static char lookup[32][6] = {
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
            static int value[32] = {
                36,
                39,
                -1,
                -1,
                12,
                -1,
                30,
                -1,
                -1,
                41,
                -1,
                -1,
                -1,
                -1,
                -1,
                37,
                -1,
                -1,
                45,
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
            };
            uint32_t w4 = 0;
            memcpy(&w4, &s[2], 4);
            const uint64_t idx = _pext_u64(w4, 0x1c101000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static char lookup[16][7] = {
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
            static int value[16] = {
                -1,
                -1,
                33,
                34,
                -1,
                -1,
                1,
                -1,
                14,
                -1,
                10,
                -1,
                17,
                -1,
                -1,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[5], 2);
            const uint64_t idx = _pext_u64(w5, 0x1c10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static char lookup[4][8] = {
                {'c', 'o', 'n', 't', 'i', 'n', 'u', 'e'},
                {'f', 'u', 'n', 'c', 't', 'i', 'o', 'n'},
                {'a', 'b', 's', 't', 'r', 'a', 'c', 't'},
                {}, // no match
            };
            static int value[4] = {
                9,
                20,
                0,
                -1,
            };
            const uint8_t w6 = s[7];
            const uint64_t idx = _pext_u64(w6, 0x18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static char lookup[4][9] = {
                {'p', 'r', 'o', 't', 'e', 'c', 't', 'e', 'd'},
                {'i', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e'},
                {'t', 'r', 'a', 'n', 's', 'i', 'e', 'n', 't'},
                {}, // no match
            };
            static int value[4] = {
                35,
                28,
                46,
                -1,
            };
            const uint8_t w7 = s[8];
            const uint64_t idx = _pext_u64(w7, 0x11);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            if (s == "implements") {
                return 23;
            }
            if (s == "instanceof") {
                return 26;
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
//check: name=check_jscript_pext, type=pext, dataset=jscript
void check_jscript_pext() {
    assert(lookup_jscript_pext("synchronized") == 42);
    assert(lookup_jscript_pext("abstract") == 0);
    assert(lookup_jscript_pext("continue") == 9);
    assert(lookup_jscript_pext("function") == 20);
    assert(lookup_jscript_pext("for") == 19);
    assert(lookup_jscript_pext("int") == 27);
    assert(lookup_jscript_pext("new") == 31);
    assert(lookup_jscript_pext("try") == 48);
    assert(lookup_jscript_pext("var") == 49);
    assert(lookup_jscript_pext("boolean") == 1);
    assert(lookup_jscript_pext("default") == 10);
    assert(lookup_jscript_pext("extends") == 14);
    assert(lookup_jscript_pext("finally") == 17);
    assert(lookup_jscript_pext("package") == 33);
    assert(lookup_jscript_pext("private") == 34);
    assert(lookup_jscript_pext("byte") == 3);
    assert(lookup_jscript_pext("case") == 4);
    assert(lookup_jscript_pext("char") == 6);
    assert(lookup_jscript_pext("else") == 13);
    assert(lookup_jscript_pext("goto") == 21);
    assert(lookup_jscript_pext("long") == 29);
    assert(lookup_jscript_pext("null") == 32);
    assert(lookup_jscript_pext("this") == 43);
    assert(lookup_jscript_pext("true") == 47);
    assert(lookup_jscript_pext("void") == 50);
    assert(lookup_jscript_pext("with") == 52);
    assert(lookup_jscript_pext("double") == 12);
    assert(lookup_jscript_pext("import") == 24);
    assert(lookup_jscript_pext("native") == 30);
    assert(lookup_jscript_pext("public") == 36);
    assert(lookup_jscript_pext("return") == 37);
    assert(lookup_jscript_pext("static") == 39);
    assert(lookup_jscript_pext("switch") == 41);
    assert(lookup_jscript_pext("throws") == 45);
    assert(lookup_jscript_pext("interface") == 28);
    assert(lookup_jscript_pext("protected") == 35);
    assert(lookup_jscript_pext("transient") == 46);
    assert(lookup_jscript_pext("implements") == 23);
    assert(lookup_jscript_pext("instanceof") == 26);
    assert(lookup_jscript_pext("break") == 2);
    assert(lookup_jscript_pext("catch") == 5);
    assert(lookup_jscript_pext("class") == 7);
    assert(lookup_jscript_pext("const") == 8);
    assert(lookup_jscript_pext("false") == 15);
    assert(lookup_jscript_pext("final") == 16);
    assert(lookup_jscript_pext("float") == 18);
    assert(lookup_jscript_pext("short") == 38);
    assert(lookup_jscript_pext("super") == 40);
    assert(lookup_jscript_pext("throw") == 44);
    assert(lookup_jscript_pext("while") == 51);
    assert(lookup_jscript_pext("do") == 11);
    assert(lookup_jscript_pext("if") == 22);
    assert(lookup_jscript_pext("in") == 25);
}

