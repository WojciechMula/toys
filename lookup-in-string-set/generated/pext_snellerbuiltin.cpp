//lookup: name=lookup_snellerbuiltin_pext, type=pext, dataset=snellerbuiltin
int lookup_snellerbuiltin_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "LN") {
                return 33;
            }
            if (s == "PI") {
                return 40;
            }
        }
        break;
        case 3: {
            static constexpr const char lookup[32][3] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'O', 'G'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'A', 'N'},
                {'S', 'I', 'N'},
                {}, // no match
                {'E', 'X', 'P'},
                {'A', 'B', 'S'},
                {'C', 'O', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'O', 'W'},
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
                -1,
                -1,
                35,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                45,
                43,
                -1,
                28,
                19,
                44,
                -1,
                -1,
                -1,
                38,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w0 = 0;
            memcpy(&w0, &s[1], 2);
            const uint64_t idx = _pext_u64(w0, 0x1e08);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[32][4] = {
                {'L', 'N', '1', 'P'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'O', 'G', '2'},
                {'E', 'X', 'P', '2'},
                {'A', 'C', 'O', 'S'},
                {}, // no match
                {'C', 'B', 'R', 'T'},
                {'S', 'Q', 'R', 'T'},
                {'S', 'I', 'Z', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'E', 'I', 'L'},
                {'T', 'R', 'I', 'M'},
                {'S', 'I', 'G', 'N'},
                {'A', 'T', 'A', 'N'},
                {}, // no match
                {'A', 'S', 'I', 'N'},
            };
            static constexpr const int value[32] = {
                34,
                -1,
                -1,
                -1,
                36,
                30,
                47,
                -1,
                27,
                26,
                101,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                1,
                20,
                48,
                -1,
                46,
            };
            uint32_t w1 = 0;
            memcpy(&w1, &s[0], 4);
            const uint64_t idx = _pext_u64(w1, 0xe081000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[32][5] = {
                {'L', 'O', 'G', '1', '0'},
                {}, // no match
                {'A', 'T', 'A', 'N', '2'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'E', 'A', 'S', 'T'},
                {}, // no match
                {'F', 'L', 'O', 'O', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'X', 'P', '1', '0'},
                {'E', 'X', 'P', 'M', '1'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'H', 'Y', 'P', 'O', 'T'},
                {'L', 'T', 'R', 'I', 'M'},
                {'L', 'O', 'W', 'E', 'R'},
                {}, // no match
                {'R', 'O', 'U', 'N', 'D'},
                {'R', 'T', 'R', 'I', 'M'},
                {'U', 'P', 'P', 'E', 'R'},
                {'T', 'R', 'U', 'N', 'C'},
            };
            static constexpr const int value[32] = {
                37,
                -1,
                49,
                -1,
                -1,
                -1,
                -1,
                -1,
                50,
                -1,
                24,
                -1,
                -1,
                -1,
                -1,
                -1,
                31,
                29,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                32,
                2,
                5,
                -1,
                21,
                3,
                4,
                23,
            };
            // merge
            uint32_t w2 = 0;
            memcpy(&w2, &s[0], 4);
            const uint8_t w3 = s[4];
            const uint32_t w4 = (uint32_t(w2) & 0x100010) | (uint32_t(w3) & 0x43);
            const uint64_t idx = _pext_u64(w4, 0x100053);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            if (s == "CONCAT") {
                return 0;
            }
        }
        break;
        case 7: {
            if (s == "DEGREES") {
                return 41;
            }
            if (s == "RADIANS") {
                return 42;
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[8][8] = {
                {}, // no match
                {'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S'},
                {'G', 'E', 'O', '_', 'H', 'A', 'S', 'H'},
                {}, // no match
                {'T', 'Y', 'P', 'E', '_', 'B', 'I', 'T'},
                {'P', 'O', 'W', '_', 'U', 'I', 'N', 'T'},
                {'G', 'R', 'E', 'A', 'T', 'E', 'S', 'T'},
                {}, // no match
            };
            static constexpr const int value[8] = {
                -1,
                6,
                96,
                -1,
                116,
                39,
                51,
                -1,
            };
            uint16_t w5 = 0;
            memcpy(&w5, &s[6], 2);
            const uint64_t idx = _pext_u64(w5, 0x414);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static constexpr const char lookup[8][9] = {
                {'S', 'U', 'B', 'S', 'T', 'R', 'I', 'N', 'G'},
                {}, // no match
                {'E', 'Q', 'U', 'A', 'L', 'S', '_', 'C', 'I'},
                {}, // no match
                {'B', 'I', 'T', '_', 'C', 'O', 'U', 'N', 'T'},
                {'M', 'A', 'K', 'E', '_', 'L', 'I', 'S', 'T'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[8] = {
                16,
                -1,
                8,
                -1,
                18,
                114,
                -1,
                -1,
            };
            uint16_t w6 = 0;
            memcpy(&w6, &s[7], 2);
            const uint64_t idx = _pext_u64(w6, 0x1810);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            static constexpr const char lookup[8][10] = {
                {'T', 'A', 'B', 'L', 'E', '_', 'G', 'L', 'O', 'B'},
                {'A', 'R', 'R', 'A', 'Y', '_', 'S', 'I', 'Z', 'E'},
                {'R', 'O', 'U', 'N', 'D', '_', 'E', 'V', 'E', 'N'},
                {}, // no match
                {'S', 'P', 'L', 'I', 'T', '_', 'P', 'A', 'R', 'T'},
                {}, // no match
                {'G', 'E', 'O', '_', 'T', 'I', 'L', 'E', '_', 'X'},
                {'G', 'E', 'O', '_', 'T', 'I', 'L', 'E', '_', 'Y'},
            };
            static constexpr const int value[8] = {
                105,
                103,
                22,
                -1,
                17,
                -1,
                97,
                98,
            };
            const uint8_t w7 = s[9];
            const uint64_t idx = _pext_u64(w7, 0x19);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 11: {
            static constexpr const char lookup[8][11] = {
                {'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S', '_', 'C', 'I'},
                {'C', 'H', 'A', 'R', '_', 'L', 'E', 'N', 'G', 'T', 'H'},
                {}, // no match
                {}, // no match
                {'I', 'N', '_', 'S', 'U', 'B', 'Q', 'U', 'E', 'R', 'Y'},
                {'G', 'E', 'O', '_', 'T', 'I', 'L', 'E', '_', 'E', 'S'},
                {'M', 'A', 'K', 'E', '_', 'S', 'T', 'R', 'U', 'C', 'T'},
                {'T', 'I', 'M', 'E', '_', 'B', 'U', 'C', 'K', 'E', 'T'},
            };
            static constexpr const int value[8] = {
                7,
                14,
                -1,
                -1,
                107,
                99,
                115,
                113,
            };
            uint16_t w8 = 0;
            memcpy(&w8, &s[9], 2);
            const uint64_t idx = _pext_u64(w8, 0x1404);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 12: {
            static constexpr const char lookup[16][12] = {
                {'G', 'E', 'O', '_', 'D', 'I', 'S', 'T', 'A', 'N', 'C', 'E'},
                {}, // no match
                {'I', 'S', '_', 'S', 'U', 'B', 'N', 'E', 'T', '_', 'O', 'F'},
                {}, // no match
                {}, // no match
                {'O', 'C', 'T', 'E', 'T', '_', 'L', 'E', 'N', 'G', 'T', 'H'},
                {}, // no match
                {}, // no match
                {'W', 'I', 'D', 'T', 'H', '_', 'B', 'U', 'C', 'K', 'E', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'D', 'A', 'Y'},
                {'E', 'Q', 'U', 'A', 'L', 'S', '_', 'F', 'U', 'Z', 'Z', 'Y'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                100,
                -1,
                15,
                -1,
                -1,
                13,
                -1,
                -1,
                52,
                -1,
                -1,
                -1,
                58,
                9,
                -1,
                -1,
            };
            uint16_t w9 = 0;
            memcpy(&w9, &s[10], 2);
            const uint64_t idx = _pext_u64(w9, 0x1a10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 13: {
            static constexpr const char lookup[8][13] = {
                {'T', 'O', '_', 'U', 'N', 'I', 'X', '_', 'E', 'P', 'O', 'C', 'H'},
                {'T', 'A', 'B', 'L', 'E', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'W', 'E', 'E', 'K'},
                {'T', 'O', '_', 'U', 'N', 'I', 'X', '_', 'M', 'I', 'C', 'R', 'O'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'Y', 'E', 'A', 'R'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'H', 'O', 'U', 'R'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'D', 'A', 'Y'},
                {}, // no match
            };
            static constexpr const int value[8] = {
                94,
                106,
                59,
                95,
                62,
                57,
                68,
                -1,
            };
            uint16_t w10 = 0;
            memcpy(&w10, &s[11], 2);
            const uint64_t idx = _pext_u64(w10, 0x1110);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 14: {
            static constexpr const char lookup[32][14] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'M', 'O', 'N', 'T', 'H'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'W', 'E', 'E', 'K'},
                {}, // no match
                {'A', 'R', 'R', 'A', 'Y', '_', 'P', 'O', 'S', 'I', 'T', 'I', 'O', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'Y', 'E', 'A', 'R'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'H', 'O', 'U', 'R'},
                {'A', 'R', 'R', 'A', 'Y', '_', 'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S'},
                {}, // no match
                {'I', 'N', '_', 'R', 'E', 'P', 'L', 'A', 'C', 'E', 'M', 'E', 'N', 'T'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'D', 'O', 'W'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'D', 'A', 'Y'},
                {'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S', '_', 'F', 'U', 'Z', 'Z', 'Y'},
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
                -1,
                -1,
                -1,
                -1,
                60,
                69,
                -1,
                104,
                -1,
                -1,
                -1,
                72,
                67,
                102,
                -1,
                108,
                -1,
                90,
                -1,
                -1,
                -1,
                89,
                11,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w11 = 0;
            memcpy(&w11, &s[12], 2);
            const uint64_t idx = _pext_u64(w11, 0x1d10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 15: {
            static constexpr const char lookup[16][15] = {
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'Y', 'E', 'A', 'R'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'H', 'O', 'U', 'R'},
                {'A', 'S', 'S', 'E', 'R', 'T', '_', 'I', 'O', 'N', '_', 'T', 'Y', 'P', 'E'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'M', 'I', 'N', 'U', 'T', 'E'},
                {'P', 'A', 'R', 'T', 'I', 'T', 'I', 'O', 'N', '_', 'V', 'A', 'L', 'U', 'E'},
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'M', 'O', 'N', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                -1,
                93,
                55,
                88,
                117,
                -1,
                56,
                118,
                -1,
                -1,
                70,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w12 = 0;
            memcpy(&w12, &s[13], 2);
            const uint64_t idx = _pext_u64(w12, 0x905);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 16: {
            static constexpr const char lookup[32][16] = {
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'M', 'I', 'N', 'U', 'T', 'E'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'S', 'E', 'C', 'O', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'M', 'O', 'N', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'H', 'A', 'S', 'H', '_', 'R', 'E', 'P', 'L', 'A', 'C', 'E', 'M', 'E', 'N', 'T'},
                {}, // no match
                {'L', 'I', 'S', 'T', '_', 'R', 'E', 'P', 'L', 'A', 'C', 'E', 'M', 'E', 'N', 'T'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'Q', 'U', 'A', 'R', 'T', 'E', 'R'},
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'D', 'O', 'W'},
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'D', 'A', 'Y'},
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'D', 'O', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                66,
                65,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                91,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                109,
                -1,
                112,
                61,
                79,
                -1,
                -1,
                78,
                80,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            // merge
            uint16_t w13 = 0;
            memcpy(&w13, &s[14], 2);
            const uint8_t w14 = s[3];
            const uint16_t w15 = (uint16_t(w13) & 0x1a08) | (uint16_t(w14) & 0x10);
            const uint64_t idx = _pext_u64(w15, 0x1a18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 17: {
            static constexpr const char lookup[8][17] = {
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'S', 'E', 'C', 'O', 'N', 'D'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'M', 'I', 'N', 'U', 'T', 'E'},
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'Y', 'E', 'A', 'R'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'Q', 'U', 'A', 'R', 'T', 'E', 'R'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'H', 'O', 'U', 'R'},
            };
            static constexpr const int value[8] = {
                -1,
                86,
                -1,
                87,
                83,
                71,
                -1,
                77,
            };
            uint16_t w16 = 0;
            memcpy(&w16, &s[15], 2);
            const uint64_t idx = _pext_u64(w16, 0x1014);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 18: {
            static constexpr const char lookup[8][18] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'C', 'A', 'L', 'A', 'R', '_', 'R', 'E', 'P', 'L', 'A', 'C', 'E', 'M', 'E', 'N', 'T'},
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'M', 'O', 'N', 'T', 'H'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'Q', 'U', 'A', 'R', 'T', 'E', 'R'},
                {'S', 'T', 'R', 'U', 'C', 'T', '_', 'R', 'E', 'P', 'L', 'A', 'C', 'E', 'M', 'E', 'N', 'T'},
            };
            static constexpr const int value[8] = {
                -1,
                -1,
                -1,
                110,
                81,
                -1,
                92,
                111,
            };
            // merge
            uint32_t w17 = 0;
            memcpy(&w17, &s[4], 4);
            const uint8_t w18 = s[17];
            const uint32_t w19 = (uint32_t(w17) & 0x400) | (uint32_t(w18) & 0x14);
            const uint64_t idx = _pext_u64(w19, 0x414);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 19: {
            if (s == "DATE_EXTRACT_SECOND") {
                return 75;
            }
            if (s == "DATE_EXTRACT_MINUTE") {
                return 76;
            }
        }
        break;
        case 20: {
            static constexpr const char lookup[8][20] = {
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'M', 'I', 'L', 'L', 'I', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'M', 'I', 'C', 'R', 'O', 'S', 'E', 'C', 'O', 'N', 'D'},
                {}, // no match
                {'E', 'Q', 'U', 'A', 'L', 'S', '_', 'F', 'U', 'Z', 'Z', 'Y', '_', 'U', 'N', 'I', 'C', 'O', 'D', 'E'},
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'Q', 'U', 'A', 'R', 'T', 'E', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[8] = {
                54,
                53,
                -1,
                10,
                82,
                -1,
                -1,
                -1,
            };
            uint64_t w20 = 0;
            memcpy(&w20, &s[12], 8);
            const uint64_t idx = _pext_u64(w20, 0x1100000000000400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 21: {
            if (s == "DATE_DIFF_MICROSECOND") {
                return 63;
            }
            if (s == "DATE_DIFF_MILLISECOND") {
                return 64;
            }
        }
        break;
        case 22: {
            static constexpr const char lookup[4][22] = {
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'M', 'I', 'L', 'L', 'I', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'M', 'I', 'C', 'R', 'O', 'S', 'E', 'C', 'O', 'N', 'D'},
                {}, // no match
                {'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S', '_', 'F', 'U', 'Z', 'Z', 'Y', '_', 'U', 'N', 'I', 'C', 'O', 'D', 'E'},
            };
            static constexpr const int value[4] = {
                85,
                84,
                -1,
                12,
            };
            uint64_t w21 = 0;
            memcpy(&w21, &s[14], 8);
            const uint64_t idx = _pext_u64(w21, 0x100000000000400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 24: {
            if (s == "DATE_EXTRACT_MICROSECOND") {
                return 73;
            }
            if (s == "DATE_EXTRACT_MILLISECOND") {
                return 74;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_snellerbuiltin_pext, type=pext, dataset=snellerbuiltin
void check_snellerbuiltin_pext() {
    assert(lookup_snellerbuiltin_pext("CONCAT") == 0);
    assert(lookup_snellerbuiltin_pext("TRIM") == 1);
    assert(lookup_snellerbuiltin_pext("LTRIM") == 2);
    assert(lookup_snellerbuiltin_pext("RTRIM") == 3);
    assert(lookup_snellerbuiltin_pext("UPPER") == 4);
    assert(lookup_snellerbuiltin_pext("LOWER") == 5);
    assert(lookup_snellerbuiltin_pext("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_pext("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_pext("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_pext("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_pext("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_pext("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_pext("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_pext("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_pext("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_pext("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_pext("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_pext("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_pext("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_pext("ABS") == 19);
    assert(lookup_snellerbuiltin_pext("SIGN") == 20);
    assert(lookup_snellerbuiltin_pext("ROUND") == 21);
    assert(lookup_snellerbuiltin_pext("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_pext("TRUNC") == 23);
    assert(lookup_snellerbuiltin_pext("FLOOR") == 24);
    assert(lookup_snellerbuiltin_pext("CEIL") == 25);
    assert(lookup_snellerbuiltin_pext("SQRT") == 26);
    assert(lookup_snellerbuiltin_pext("CBRT") == 27);
    assert(lookup_snellerbuiltin_pext("EXP") == 28);
    assert(lookup_snellerbuiltin_pext("EXPM1") == 29);
    assert(lookup_snellerbuiltin_pext("EXP2") == 30);
    assert(lookup_snellerbuiltin_pext("EXP10") == 31);
    assert(lookup_snellerbuiltin_pext("HYPOT") == 32);
    assert(lookup_snellerbuiltin_pext("LN") == 33);
    assert(lookup_snellerbuiltin_pext("LN1P") == 34);
    assert(lookup_snellerbuiltin_pext("LOG") == 35);
    assert(lookup_snellerbuiltin_pext("LOG2") == 36);
    assert(lookup_snellerbuiltin_pext("LOG10") == 37);
    assert(lookup_snellerbuiltin_pext("POW") == 38);
    assert(lookup_snellerbuiltin_pext("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_pext("PI") == 40);
    assert(lookup_snellerbuiltin_pext("DEGREES") == 41);
    assert(lookup_snellerbuiltin_pext("RADIANS") == 42);
    assert(lookup_snellerbuiltin_pext("SIN") == 43);
    assert(lookup_snellerbuiltin_pext("COS") == 44);
    assert(lookup_snellerbuiltin_pext("TAN") == 45);
    assert(lookup_snellerbuiltin_pext("ASIN") == 46);
    assert(lookup_snellerbuiltin_pext("ACOS") == 47);
    assert(lookup_snellerbuiltin_pext("ATAN") == 48);
    assert(lookup_snellerbuiltin_pext("ATAN2") == 49);
    assert(lookup_snellerbuiltin_pext("LEAST") == 50);
    assert(lookup_snellerbuiltin_pext("GREATEST") == 51);
    assert(lookup_snellerbuiltin_pext("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_pext("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_pext("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_pext("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_pext("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_pext("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_pext("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_pext("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_pext("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_pext("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_pext("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_pext("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_pext("SIZE") == 101);
    assert(lookup_snellerbuiltin_pext("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_pext("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_pext("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_pext("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_pext("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_pext("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_pext("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_pext("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_pext("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_pext("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_pext("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_pext("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_pext("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_pext("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_pext("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_pext("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_pext("PARTITION_VALUE") == 118);
}

