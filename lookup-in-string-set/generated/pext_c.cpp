//lookup: name=lookup_c, dataset=c
int lookup_c(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "if") {
                return 0;
            }
            if (s == "do") {
                return 1;
            }
        }
        break;
        case 3: {
            if (s == "int") {
                return 2;
            }
            if (s == "for") {
                return 3;
            }
        }
        break;
        case 4: {
            static char lookup[16][4] = {
                {}, // no match
                {'v', 'o', 'i', 'd'},
                {'c', 'a', 's', 'e'},
                {'e', 'l', 's', 'e'},
                {}, // no match
                {'c', 'h', 'a', 'r'},
                {}, // no match
                {'l', 'o', 'n', 'g'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'e', 'n', 'u', 'm'},
                {}, // no match
                {}, // no match
                {'a', 'u', 't', 'o'},
                {'g', 'o', 't', 'o'},
            };
            static int value[16] = {
                -1,
                10,
                4,
                8,
                -1,
                5,
                -1,
                9,
                -1,
                -1,
                -1,
                11,
                -1,
                -1,
                6,
                7,
            };
            uint32_t w0 = 0;
            memcpy(&w0, &s[0], 4);
            const uint64_t idx = _pext_u64(w0, 0xb000800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static char lookup[16][5] = {
                {}, // no match
                {'b', 'r', 'e', 'a', 'k'},
                {}, // no match
                {}, // no match
                {'w', 'h', 'i', 'l', 'e'},
                {'u', 'n', 'i', 'o', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'l', 'o', 'a', 't'},
                {'s', 'h', 'o', 'r', 't'},
                {'c', 'o', 'n', 's', 't'},
            };
            static int value[16] = {
                -1,
                15,
                -1,
                -1,
                16,
                14,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                12,
                13,
                17,
            };
            uint16_t w1 = 0;
            memcpy(&w1, &s[3], 2);
            const uint64_t idx = _pext_u64(w1, 0x1411);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static char lookup[16][6] = {
                {'s', 'i', 'g', 'n', 'e', 'd'},
                {'s', 't', 'r', 'u', 'c', 't'},
                {'d', 'o', 'u', 'b', 'l', 'e'},
                {}, // no match
                {'s', 'i', 'z', 'e', 'o', 'f'},
                {}, // no match
                {}, // no match
                {'s', 't', 'a', 't', 'i', 'c'},
                {}, // no match
                {'s', 'w', 'i', 't', 'c', 'h'},
                {}, // no match
                {}, // no match
                {'e', 'x', 't', 'e', 'r', 'n'},
                {'r', 'e', 't', 'u', 'r', 'n'},
                {}, // no match
                {}, // no match
            };
            static int value[16] = {
                25,
                21,
                18,
                -1,
                23,
                -1,
                -1,
                19,
                -1,
                24,
                -1,
                -1,
                20,
                22,
                -1,
                -1,
            };
            uint32_t w2 = 0;
            memcpy(&w2, &s[2], 4);
            const uint64_t idx = _pext_u64(w2, 0xb001000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            if (s == "typedef") {
                return 26;
            }
            if (s == "default") {
                return 27;
            }
        }
        break;
        case 8: {
            static char lookup[8][8] = {
                {'u', 'n', 's', 'i', 'g', 'n', 'e', 'd'},
                {}, // no match
                {'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'},
                {'c', 'o', 'n', 't', 'i', 'n', 'u', 'e'},
                {'r', 'e', 'g', 'i', 's', 't', 'e', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[8] = {
                28,
                -1,
                31,
                29,
                30,
                -1,
                -1,
                -1,
            };
            uint16_t w3 = 0;
            memcpy(&w3, &s[6], 2);
            const uint64_t idx = _pext_u64(w3, 0x1110);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_c, dataset=c
void check_c() {
    assert(lookup_c("typedef") == 26);
    assert(lookup_c("default") == 27);
    assert(lookup_c("unsigned") == 28);
    assert(lookup_c("continue") == 29);
    assert(lookup_c("register") == 30);
    assert(lookup_c("volatile") == 31);
    assert(lookup_c("if") == 0);
    assert(lookup_c("do") == 1);
    assert(lookup_c("int") == 2);
    assert(lookup_c("for") == 3);
    assert(lookup_c("case") == 4);
    assert(lookup_c("char") == 5);
    assert(lookup_c("auto") == 6);
    assert(lookup_c("goto") == 7);
    assert(lookup_c("else") == 8);
    assert(lookup_c("long") == 9);
    assert(lookup_c("void") == 10);
    assert(lookup_c("enum") == 11);
    assert(lookup_c("float") == 12);
    assert(lookup_c("short") == 13);
    assert(lookup_c("union") == 14);
    assert(lookup_c("break") == 15);
    assert(lookup_c("while") == 16);
    assert(lookup_c("const") == 17);
    assert(lookup_c("double") == 18);
    assert(lookup_c("static") == 19);
    assert(lookup_c("extern") == 20);
    assert(lookup_c("struct") == 21);
    assert(lookup_c("return") == 22);
    assert(lookup_c("sizeof") == 23);
    assert(lookup_c("switch") == 24);
    assert(lookup_c("signed") == 25);
}

