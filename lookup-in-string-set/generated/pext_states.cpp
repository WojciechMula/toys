//lookup: name=lookup_states_pext, type=pext, dataset=states
int lookup_states_pext(std::string_view s) {
    switch (s.size()) {
        case 4: {
            static constexpr const char lookup[4][4] = {
                {'I', 'O', 'W', 'A'},
                {}, // no match
                {'U', 'T', 'A', 'H'},
                {'O', 'H', 'I', 'O'},
            };
            static constexpr const int value[4] = {
                14,
                -1,
                43,
                34,
            };
            const uint8_t w0 = s[3];
            const uint64_t idx = _pext_u64(w0, 0xc);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[4][5] = {
                {'M', 'A', 'I', 'N', 'E'},
                {'I', 'D', 'A', 'H', 'O'},
                {'T', 'E', 'X', 'A', 'S'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                18,
                11,
                42,
                -1,
            };
            const uint8_t w1 = s[4];
            const uint64_t idx = _pext_u64(w1, 0x18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[16][6] = {
                {'N', 'E', 'V', 'A', 'D', 'A'},
                {'A', 'L', 'A', 'S', 'K', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'H', 'A', 'W', 'A', 'I', 'I'},
                {}, // no match
                {'O', 'R', 'E', 'G', 'O', 'N'},
                {'K', 'A', 'N', 'S', 'A', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                27,
                1,
                -1,
                -1,
                -1,
                10,
                -1,
                36,
                15,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w2 = 0;
            memcpy(&w2, &s[4], 2);
            const uint64_t idx = _pext_u64(w2, 0x1c08);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[16][7] = {
                {'A', 'L', 'A', 'B', 'A', 'M', 'A'},
                {'G', 'E', 'O', 'R', 'G', 'I', 'A'},
                {}, // no match
                {'F', 'L', 'O', 'R', 'I', 'D', 'A'},
                {'I', 'N', 'D', 'I', 'A', 'N', 'A'},
                {'M', 'O', 'N', 'T', 'A', 'N', 'A'},
                {'W', 'Y', 'O', 'M', 'I', 'N', 'G'},
                {'A', 'R', 'I', 'Z', 'O', 'N', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'V', 'E', 'R', 'M', 'O', 'N', 'T'},
                {}, // no match
            };
            static constexpr const int value[16] = {
                0,
                9,
                -1,
                8,
                13,
                25,
                49,
                2,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                44,
                -1,
            };
            uint32_t w3 = 0;
            memcpy(&w3, &s[3], 4);
            const uint64_t idx = _pext_u64(w3, 0x10020810);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[32][8] = {
                {}, // no match
                {'D', 'E', 'L', 'A', 'W', 'A', 'R', 'E'},
                {}, // no match
                {}, // no match
                {'V', 'I', 'R', 'G', 'I', 'N', 'I', 'A'},
                {'N', 'E', 'B', 'R', 'A', 'S', 'K', 'A'},
                {'O', 'K', 'L', 'A', 'H', 'O', 'M', 'A'},
                {'M', 'A', 'R', 'Y', 'L', 'A', 'N', 'D'},
                {'A', 'R', 'K', 'A', 'N', 'S', 'A', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'L', 'L', 'I', 'N', 'O', 'I', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'I', 'S', 'S', 'O', 'U', 'R', 'I'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'K', 'E', 'N', 'T', 'U', 'C', 'K', 'Y'},
                {}, // no match
                {}, // no match
                {'M', 'I', 'C', 'H', 'I', 'G', 'A', 'N'},
                {'N', 'E', 'W', ' ', 'Y', 'O', 'R', 'K'},
                {'C', 'O', 'L', 'O', 'R', 'A', 'D', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                -1,
                7,
                -1,
                -1,
                45,
                26,
                35,
                19,
                3,
                -1,
                -1,
                -1,
                12,
                -1,
                -1,
                -1,
                -1,
                24,
                -1,
                -1,
                -1,
                16,
                -1,
                -1,
                21,
                31,
                5,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w4 = 0;
            memcpy(&w4, &s[6], 2);
            const uint64_t idx = _pext_u64(w4, 0xa0e);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static constexpr const char lookup[8][9] = {
                {'L', 'O', 'U', 'I', 'S', 'I', 'A', 'N', 'A'},
                {'M', 'I', 'N', 'N', 'E', 'S', 'O', 'T', 'A'},
                {'T', 'E', 'N', 'N', 'E', 'S', 'S', 'E', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'W', 'I', 'S', 'C', 'O', 'N', 'S', 'I', 'N'},
                {}, // no match
            };
            static constexpr const int value[8] = {
                17,
                22,
                41,
                -1,
                -1,
                -1,
                48,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[7], 2);
            const uint64_t idx = _pext_u64(w5, 0xc10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            static constexpr const char lookup[8][10] = {
                {}, // no match
                {'C', 'A', 'L', 'I', 'F', 'O', 'R', 'N', 'I', 'A'},
                {'W', 'A', 'S', 'H', 'I', 'N', 'G', 'T', 'O', 'N'},
                {'N', 'E', 'W', ' ', 'M', 'E', 'X', 'I', 'C', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'E', 'W', ' ', 'J', 'E', 'R', 'S', 'E', 'Y'},
            };
            static constexpr const int value[8] = {
                -1,
                4,
                46,
                30,
                -1,
                -1,
                -1,
                29,
            };
            const uint8_t w6 = s[9];
            const uint64_t idx = _pext_u64(w6, 0x19);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 11: {
            if (s == "CONNECTICUT") {
                return 6;
            }
            if (s == "MISSISSIPPI") {
                return 23;
            }
        }
        break;
        case 12: {
            static constexpr const char lookup[8][12] = {
                {}, // no match
                {'P', 'E', 'N', 'N', 'S', 'Y', 'L', 'V', 'A', 'N', 'I', 'A'},
                {'N', 'O', 'R', 'T', 'H', ' ', 'D', 'A', 'K', 'O', 'T', 'A'},
                {'S', 'O', 'U', 'T', 'H', ' ', 'D', 'A', 'K', 'O', 'T', 'A'},
                {}, // no match
                {'R', 'H', 'O', 'D', 'E', ' ', 'I', 'S', 'L', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[8] = {
                -1,
                37,
                33,
                40,
                -1,
                38,
                -1,
                -1,
            };
            // merge
            uint16_t w7 = 0;
            memcpy(&w7, &s[10], 2);
            const uint8_t w8 = s[2];
            const uint16_t w9 = (uint16_t(w7) & 0x410) | (uint16_t(w8) & 0x4);
            const uint64_t idx = _pext_u64(w9, 0x414);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 13: {
            static constexpr const char lookup[4][13] = {
                {'W', 'E', 'S', 'T', ' ', 'V', 'I', 'R', 'G', 'I', 'N', 'I', 'A'},
                {'N', 'E', 'W', ' ', 'H', 'A', 'M', 'P', 'S', 'H', 'I', 'R', 'E'},
                {'M', 'A', 'S', 'S', 'A', 'C', 'H', 'U', 'S', 'E', 'T', 'T', 'S'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                47,
                28,
                20,
                -1,
            };
            const uint8_t w10 = s[12];
            const uint64_t idx = _pext_u64(w10, 0x14);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 14: {
            if (s == "NORTH CAROLINA") {
                return 32;
            }
            if (s == "SOUTH CAROLINA") {
                return 39;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_states_pext, type=pext, dataset=states
void check_states_pext() {
    assert(lookup_states_pext("ARKANSAS") == 3);
    assert(lookup_states_pext("COLORADO") == 5);
    assert(lookup_states_pext("DELAWARE") == 7);
    assert(lookup_states_pext("ILLINOIS") == 12);
    assert(lookup_states_pext("KENTUCKY") == 16);
    assert(lookup_states_pext("MARYLAND") == 19);
    assert(lookup_states_pext("MICHIGAN") == 21);
    assert(lookup_states_pext("MISSOURI") == 24);
    assert(lookup_states_pext("NEBRASKA") == 26);
    assert(lookup_states_pext("NEW YORK") == 31);
    assert(lookup_states_pext("OKLAHOMA") == 35);
    assert(lookup_states_pext("VIRGINIA") == 45);
    assert(lookup_states_pext("CONNECTICUT") == 6);
    assert(lookup_states_pext("MISSISSIPPI") == 23);
    assert(lookup_states_pext("IDAHO") == 11);
    assert(lookup_states_pext("MAINE") == 18);
    assert(lookup_states_pext("TEXAS") == 42);
    assert(lookup_states_pext("MASSACHUSETTS") == 20);
    assert(lookup_states_pext("NEW HAMPSHIRE") == 28);
    assert(lookup_states_pext("WEST VIRGINIA") == 47);
    assert(lookup_states_pext("ALABAMA") == 0);
    assert(lookup_states_pext("ARIZONA") == 2);
    assert(lookup_states_pext("FLORIDA") == 8);
    assert(lookup_states_pext("GEORGIA") == 9);
    assert(lookup_states_pext("INDIANA") == 13);
    assert(lookup_states_pext("MONTANA") == 25);
    assert(lookup_states_pext("VERMONT") == 44);
    assert(lookup_states_pext("WYOMING") == 49);
    assert(lookup_states_pext("LOUISIANA") == 17);
    assert(lookup_states_pext("MINNESOTA") == 22);
    assert(lookup_states_pext("TENNESSEE") == 41);
    assert(lookup_states_pext("WISCONSIN") == 48);
    assert(lookup_states_pext("NORTH DAKOTA") == 33);
    assert(lookup_states_pext("PENNSYLVANIA") == 37);
    assert(lookup_states_pext("RHODE ISLAND") == 38);
    assert(lookup_states_pext("SOUTH DAKOTA") == 40);
    assert(lookup_states_pext("IOWA") == 14);
    assert(lookup_states_pext("OHIO") == 34);
    assert(lookup_states_pext("UTAH") == 43);
    assert(lookup_states_pext("ALASKA") == 1);
    assert(lookup_states_pext("HAWAII") == 10);
    assert(lookup_states_pext("KANSAS") == 15);
    assert(lookup_states_pext("NEVADA") == 27);
    assert(lookup_states_pext("OREGON") == 36);
    assert(lookup_states_pext("CALIFORNIA") == 4);
    assert(lookup_states_pext("NEW JERSEY") == 29);
    assert(lookup_states_pext("NEW MEXICO") == 30);
    assert(lookup_states_pext("WASHINGTON") == 46);
    assert(lookup_states_pext("NORTH CAROLINA") == 32);
    assert(lookup_states_pext("SOUTH CAROLINA") == 39);
}

