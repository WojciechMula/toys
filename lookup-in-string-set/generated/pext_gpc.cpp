//lookup: name=lookup_gpc_pext, type=pext, dataset=gpc
int lookup_gpc_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static char lookup[16][2] = {
                {'I', 'f'},
                {'O', 'f'},
                {}, // no match
                {}, // no match
                {'I', 'n'},
                {'D', 'o'},
                {}, // no match
                {'T', 'o'},
                {}, // no match
                {'O', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[16] = {
                14,
                20,
                -1,
                -1,
                15,
                6,
                -1,
                29,
                -1,
                21,
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
                {'A', 'n', 'd'},
                {'E', 'n', 'd'},
                {}, // no match
                {'M', 'o', 'd'},
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
                {'N', 'i', 'l'},
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
                {'V', 'a', 'r'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'o', 'r'},
                {}, // no match
                {}, // no match
                {'S', 'e', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'o', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'i', 'v'},
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
                0,
                9,
                -1,
                17,
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
                18,
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
                32,
                -1,
                -1,
                -1,
                11,
                -1,
                -1,
                27,
                -1,
                -1,
                -1,
                -1,
                19,
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
                {'F', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'y', 'p', 'e'},
                {'C', 'a', 's', 'e'},
                {'E', 'l', 's', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'W', 'i', 't', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'h', 'e', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'o', 't', 'o'},
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
                10,
                -1,
                -1,
                -1,
                30,
                3,
                8,
                -1,
                -1,
                -1,
                -1,
                -1,
                34,
                -1,
                -1,
                -1,
                28,
                -1,
                -1,
                -1,
                13,
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
                {'W', 'h', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {'L', 'a', 'b', 'e', 'l'},
                {'U', 'n', 't', 'i', 'l'},
                {}, // no match
                {'B', 'e', 'g', 'i', 'n'},
                {'C', 'o', 'n', 's', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'r', 'r', 'a', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[16] = {
                -1,
                33,
                -1,
                -1,
                16,
                31,
                -1,
                2,
                4,
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
                {'P', 'a', 'c', 'k', 'e', 'd'},
                {'R', 'e', 'c', 'o', 'r', 'd'},
                {}, // no match
                {'D', 'o', 'w', 'n', 't', 'o'},
                {'R', 'e', 'p', 'e', 'a', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static int value[8] = {
                22,
                25,
                -1,
                7,
                26,
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
            if (s == "Program") {
                return 24;
            }
        }
        break;
        case 8: {
            if (s == "Function") {
                return 12;
            }
        }
        break;
        case 9: {
            if (s == "Procedure") {
                return 23;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_gpc_pext, type=pext, dataset=gpc
void check_gpc_pext() {
    assert(lookup_gpc_pext("Function") == 12);
    assert(lookup_gpc_pext("Procedure") == 23);
    assert(lookup_gpc_pext("Program") == 24);
    assert(lookup_gpc_pext("And") == 0);
    assert(lookup_gpc_pext("Div") == 5);
    assert(lookup_gpc_pext("End") == 9);
    assert(lookup_gpc_pext("For") == 11);
    assert(lookup_gpc_pext("Mod") == 17);
    assert(lookup_gpc_pext("Nil") == 18);
    assert(lookup_gpc_pext("Not") == 19);
    assert(lookup_gpc_pext("Set") == 27);
    assert(lookup_gpc_pext("Var") == 32);
    assert(lookup_gpc_pext("Array") == 1);
    assert(lookup_gpc_pext("Begin") == 2);
    assert(lookup_gpc_pext("Const") == 4);
    assert(lookup_gpc_pext("Label") == 16);
    assert(lookup_gpc_pext("Until") == 31);
    assert(lookup_gpc_pext("While") == 33);
    assert(lookup_gpc_pext("Case") == 3);
    assert(lookup_gpc_pext("Else") == 8);
    assert(lookup_gpc_pext("File") == 10);
    assert(lookup_gpc_pext("Goto") == 13);
    assert(lookup_gpc_pext("Then") == 28);
    assert(lookup_gpc_pext("Type") == 30);
    assert(lookup_gpc_pext("With") == 34);
    assert(lookup_gpc_pext("Do") == 6);
    assert(lookup_gpc_pext("If") == 14);
    assert(lookup_gpc_pext("In") == 15);
    assert(lookup_gpc_pext("Of") == 20);
    assert(lookup_gpc_pext("Or") == 21);
    assert(lookup_gpc_pext("To") == 29);
    assert(lookup_gpc_pext("Downto") == 7);
    assert(lookup_gpc_pext("Packed") == 22);
    assert(lookup_gpc_pext("Record") == 25);
    assert(lookup_gpc_pext("Repeat") == 26);
}

