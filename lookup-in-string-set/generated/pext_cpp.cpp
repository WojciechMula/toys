//lookup: name=lookup_cpp_pext, type=pext, dataset=cpp
int lookup_cpp_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "do") {
                return 11;
            }
            if (s == "if") {
                return 20;
            }
        }
        break;
        case 3: {
            static constexpr const char lookup[8][3] = {
                {}, // no match
                {}, // no match
                {'a', 's', 'm'},
                {}, // no match
                {}, // no match
                {'f', 'o', 'r'},
                {'i', 'n', 't'},
                {'n', 'e', 'w'},
            };
            static constexpr const int value[8] = {
                -1,
                -1,
                0,
                -1,
                -1,
                17,
                22,
                24,
            };
            const uint8_t w0 = s[2];
            const uint64_t idx = _pext_u64(w0, 0x16);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[32][4] = {
                {}, // no match
                {'v', 'o', 'i', 'd'},
                {'c', 'a', 's', 'e'},
                {'e', 'l', 's', 'e'},
                {}, // no match
                {}, // no match
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
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'c', 'h', 'a', 'r'},
                {}, // no match
                {'t', 'h', 'i', 's'},
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
                44,
                3,
                13,
                -1,
                -1,
                -1,
                23,
                -1,
                -1,
                -1,
                14,
                -1,
                -1,
                1,
                19,
                -1,
                -1,
                -1,
                -1,
                -1,
                5,
                -1,
                39,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint32_t w1 = 0;
            memcpy(&w1, &s[0], 4);
            const uint64_t idx = _pext_u64(w1, 0x1b000800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[16][5] = {
                {}, // no match
                {'c', 'a', 't', 'c', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'b', 'r', 'e', 'a', 'k'},
                {}, // no match
                {'c', 'l', 'a', 's', 's'},
                {'w', 'h', 'i', 'l', 'e'},
                {'f', 'l', 'o', 'a', 't'},
                {'s', 'h', 'o', 'r', 't'},
                {'c', 'o', 'n', 's', 't'},
                {}, // no match
                {'u', 'n', 'i', 'o', 'n'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                -1,
                4,
                -1,
                -1,
                -1,
                2,
                -1,
                6,
                46,
                16,
                32,
                7,
                -1,
                41,
                -1,
                -1,
            };
            uint16_t w2 = 0;
            memcpy(&w2, &s[3], 2);
            const uint64_t idx = _pext_u64(w2, 0x611);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[64][6] = {
                {'s', 'i', 'g', 'n', 'e', 'd'},
                {}, // no match
                {'f', 'r', 'i', 'e', 'n', 'd'},
                {'s', 'w', 'i', 't', 'c', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'o', 'u', 'b', 'l', 'e'},
                {}, // no match
                {'i', 'n', 'l', 'i', 'n', 'e'},
                {}, // no match
                {'d', 'e', 'l', 'e', 't', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'s', 'i', 'z', 'e', 'o', 'f'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'e', 'x', 't', 'e', 'r', 'n'},
                {'r', 'e', 't', 'u', 'r', 'n'},
                {'p', 'u', 'b', 'l', 'i', 'c'},
                {'s', 't', 'a', 't', 'i', 'c'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'s', 't', 'r', 'u', 'c', 't'},
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
            static constexpr const int value[64] = {
                33,
                -1,
                18,
                37,
                -1,
                -1,
                -1,
                -1,
                12,
                -1,
                21,
                -1,
                10,
                -1,
                -1,
                -1,
                -1,
                -1,
                34,
                -1,
                -1,
                -1,
                15,
                31,
                29,
                35,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                36,
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
            uint32_t w3 = 0;
            memcpy(&w3, &s[2], 4);
            const uint64_t idx = _pext_u64(w3, 0x13121000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[8][7] = {
                {'p', 'r', 'i', 'v', 'a', 't', 'e'},
                {'t', 'y', 'p', 'e', 'd', 'e', 'f'},
                {'v', 'i', 'r', 't', 'u', 'a', 'l'},
                {}, // no match
                {'d', 'e', 'f', 'a', 'u', 'l', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[8] = {
                27,
                40,
                43,
                -1,
                9,
                -1,
                -1,
                -1,
            };
            const uint8_t w4 = s[6];
            const uint64_t idx = _pext_u64(w4, 0x1a);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[32][8] = {
                {}, // no match
                {'o', 'v', 'e', 'r', 'l', 'o', 'a', 'd'},
                {}, // no match
                {'u', 'n', 's', 'i', 'g', 'n', 'e', 'd'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'e', 'm', 'p', 'l', 'a', 't', 'e'},
                {'c', 'o', 'n', 't', 'i', 'n', 'u', 'e'},
                {}, // no match
                {}, // no match
                {'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'r', 'e', 'g', 'i', 's', 't', 'e', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'o', 'p', 'e', 'r', 'a', 't', 'o', 'r'},
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
                26,
                -1,
                42,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                38,
                8,
                -1,
                -1,
                45,
                -1,
                -1,
                -1,
                -1,
                30,
                -1,
                -1,
                -1,
                25,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[6], 2);
            const uint64_t idx = _pext_u64(w5, 0x110d);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            if (s == "protected") {
                return 28;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_cpp_pext, type=pext, dataset=cpp
void check_cpp_pext() {
    assert(lookup_cpp_pext("asm") == 0);
    assert(lookup_cpp_pext("auto") == 1);
    assert(lookup_cpp_pext("break") == 2);
    assert(lookup_cpp_pext("case") == 3);
    assert(lookup_cpp_pext("catch") == 4);
    assert(lookup_cpp_pext("char") == 5);
    assert(lookup_cpp_pext("class") == 6);
    assert(lookup_cpp_pext("const") == 7);
    assert(lookup_cpp_pext("continue") == 8);
    assert(lookup_cpp_pext("default") == 9);
    assert(lookup_cpp_pext("delete") == 10);
    assert(lookup_cpp_pext("do") == 11);
    assert(lookup_cpp_pext("double") == 12);
    assert(lookup_cpp_pext("else") == 13);
    assert(lookup_cpp_pext("enum") == 14);
    assert(lookup_cpp_pext("extern") == 15);
    assert(lookup_cpp_pext("float") == 16);
    assert(lookup_cpp_pext("for") == 17);
    assert(lookup_cpp_pext("friend") == 18);
    assert(lookup_cpp_pext("goto") == 19);
    assert(lookup_cpp_pext("if") == 20);
    assert(lookup_cpp_pext("inline") == 21);
    assert(lookup_cpp_pext("int") == 22);
    assert(lookup_cpp_pext("long") == 23);
    assert(lookup_cpp_pext("new") == 24);
    assert(lookup_cpp_pext("operator") == 25);
    assert(lookup_cpp_pext("overload") == 26);
    assert(lookup_cpp_pext("private") == 27);
    assert(lookup_cpp_pext("protected") == 28);
    assert(lookup_cpp_pext("public") == 29);
    assert(lookup_cpp_pext("register") == 30);
    assert(lookup_cpp_pext("return") == 31);
    assert(lookup_cpp_pext("short") == 32);
    assert(lookup_cpp_pext("signed") == 33);
    assert(lookup_cpp_pext("sizeof") == 34);
    assert(lookup_cpp_pext("static") == 35);
    assert(lookup_cpp_pext("struct") == 36);
    assert(lookup_cpp_pext("switch") == 37);
    assert(lookup_cpp_pext("template") == 38);
    assert(lookup_cpp_pext("this") == 39);
    assert(lookup_cpp_pext("typedef") == 40);
    assert(lookup_cpp_pext("union") == 41);
    assert(lookup_cpp_pext("unsigned") == 42);
    assert(lookup_cpp_pext("virtual") == 43);
    assert(lookup_cpp_pext("void") == 44);
    assert(lookup_cpp_pext("volatile") == 45);
    assert(lookup_cpp_pext("while") == 46);
}

