//lookup: name=lookup_go, dataset=go
int lookup_go(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "go") {
                return 11;
            }
            if (s == "if") {
                return 13;
            }
        }
        break;
        case 3: {
            static char lookup[4][3] = {
                {'m', 'a', 'p'},
                {}, // no match
                {'v', 'a', 'r'},
                {'f', 'o', 'r'},
            };
            static int value[4] = {
                16,
                -1,
                24,
                9,
            };
            uint16_t w0 = 0;
            memcpy(&w0, &s[1], 2);
            const uint64_t idx = _pext_u64(w0, 0x208);
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
                {'f', 'u', 'n', 'c'},
                {}, // no match
                {}, // no match
                {}, // no match
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
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'c', 'h', 'a', 'n'},
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
                10,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                23,
                1,
                7,
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
                -1,
                -1,
                -1,
                12,
                -1,
                -1,
            };
            uint32_t w1 = 0;
            memcpy(&w1, &s[0], 4);
            const uint64_t idx = _pext_u64(w1, 0xd020800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static char lookup[4][5] = {
                {'b', 'r', 'e', 'a', 'k'},
                {'r', 'a', 'n', 'g', 'e'},
                {'d', 'e', 'f', 'e', 'r'},
                {'c', 'o', 'n', 's', 't'},
            };
            static int value[4] = {
                0,
                18,
                6,
                3,
            };
            const uint8_t w2 = s[4];
            const uint64_t idx = _pext_u64(w2, 0x14);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static char lookup[8][6] = {
                {}, // no match
                {'s', 'w', 'i', 't', 'c', 'h'},
                {}, // no match
                {'r', 'e', 't', 'u', 'r', 'n'},
                {'s', 'e', 'l', 'e', 'c', 't'},
                {'s', 't', 'r', 'u', 'c', 't'},
                {'i', 'm', 'p', 'o', 'r', 't'},
                {}, // no match
            };
            static int value[8] = {
                -1,
                22,
                -1,
                19,
                20,
                21,
                14,
                -1,
            };
            uint32_t w3 = 0;
            memcpy(&w3, &s[2], 4);
            const uint64_t idx = _pext_u64(w3, 0x10101000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            if (s == "default") {
                return 5;
            }
            if (s == "package") {
                return 17;
            }
        }
        break;
        case 8: {
            if (s == "continue") {
                return 4;
            }
        }
        break;
        case 9: {
            if (s == "interface") {
                return 15;
            }
        }
        break;
        case 11: {
            if (s == "fallthrough") {
                return 8;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_go, dataset=go
void check_go() {
    assert(lookup_go("case") == 1);
    assert(lookup_go("chan") == 2);
    assert(lookup_go("else") == 7);
    assert(lookup_go("func") == 10);
    assert(lookup_go("goto") == 12);
    assert(lookup_go("type") == 23);
    assert(lookup_go("default") == 5);
    assert(lookup_go("package") == 17);
    assert(lookup_go("go") == 11);
    assert(lookup_go("if") == 13);
    assert(lookup_go("import") == 14);
    assert(lookup_go("return") == 19);
    assert(lookup_go("select") == 20);
    assert(lookup_go("struct") == 21);
    assert(lookup_go("switch") == 22);
    assert(lookup_go("continue") == 4);
    assert(lookup_go("for") == 9);
    assert(lookup_go("map") == 16);
    assert(lookup_go("var") == 24);
    assert(lookup_go("interface") == 15);
    assert(lookup_go("break") == 0);
    assert(lookup_go("const") == 3);
    assert(lookup_go("defer") == 6);
    assert(lookup_go("range") == 18);
    assert(lookup_go("fallthrough") == 8);
}

