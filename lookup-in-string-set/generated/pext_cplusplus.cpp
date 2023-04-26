//lookup: name=lookup_cplusplus, dataset=cplusplus
int lookup_cplusplus(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static char lookup[4][2] = {
                {'i', 'f'},
                {'d', 'o'},
                {'o', 'r'},
                {}, // no match
            };
            static int value[4] = {
                61,
                48,
                71,
                -1,
            };
            const uint8_t w0 = s[1];
            const uint64_t idx = _pext_u64(w0, 0x18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 3: {
            static char lookup[32][3] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'a', 'n', 'd'},
                {}, // no match
                {'a', 's', 'm'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'r', 'y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'f', 'o', 'r'},
                {'x', 'o', 'r'},
                {'i', 'n', 't'},
                {}, // no match
                {'n', 'o', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'n', 'e', 'w'},
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
                31,
                -1,
                30,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                92,
                -1,
                -1,
                -1,
                -1,
                58,
                104,
                63,
                -1,
                68,
                -1,
                -1,
                -1,
                67,
                -1,
            };
            // combine 2 loads
            uint32_t w1;
            uint16_t w2 = 0;
            memcpy(&w2, &s[0], 2);
            w1 = uint32_t(w2);
            const uint8_t w3 = s[2];
            w1 |= (uint32_t(w3) << 16);
            const uint64_t idx = _pext_u64(w1, 0x160110);
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
                {}, // no match
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
                {'b', 'o', 'o', 'l'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'e', 'n', 'u', 'm'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'a', 'u', 't', 'o'},
                {'g', 'o', 't', 'o'},
            };
            static int value[32] = {
                -1,
                101,
                -1,
                -1,
                38,
                51,
                91,
                -1,
                -1,
                40,
                -1,
                -1,
                -1,
                89,
                -1,
                64,
                -1,
                -1,
                -1,
                36,
                -1,
                -1,
                -1,
                52,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                33,
                60,
            };
            uint32_t w4 = 0;
            memcpy(&w4, &s[0], 4);
            const uint64_t idx = _pext_u64(w4, 0xb040800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static char lookup[64][5] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'w', 'h', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {'f', 'a', 'l', 's', 'e'},
                {'u', 's', 'i', 'n', 'g'},
                {'s', 'i', 'g', 'o', 'f'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'c', 'a', 't', 'c', 'h'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'b', 'r', 'e', 'a', 'k'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'c', 'o', 'm', 'p', 'l'},
                {'_', '_', 'a', 's', 'm'},
                {}, // no match
                {'u', 'n', 'i', 'o', 'n'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'o', 'r', '_', 'e', 'q'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'b', 'i', 't', 'o', 'r'},
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
            static int value[64] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                103,
                -1,
                -1,
                56,
                99,
                82,
                -1,
                -1,
                -1,
                39,
                -1,
                -1,
                -1,
                37,
                -1,
                -1,
                -1,
                -1,
                42,
                2,
                -1,
                97,
                -1,
                -1,
                -1,
                72,
                -1,
                -1,
                -1,
                35,
                -1,
                41,
                -1,
                57,
                79,
                43,
                -1,
                90,
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
            uint16_t w5 = 0;
            memcpy(&w5, &s[3], 2);
            const uint64_t idx = _pext_u64(w5, 0x1e11);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static char lookup[256][6] = {
                {}, // no match
                {'s', 'i', 'g', 'n', 'e', 'd'},
                {'f', 'r', 'i', 'e', 'n', 'd'},
                {}, // no match
                {'t', 'y', 'p', 'e', 'i', 'd'},
                {'b', 'i', 't', 'a', 'n', 'd'},
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
                {'e', 'x', 'p', 'o', 'r', 't'},
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
                {'i', 'n', 'l', 'i', 'n', 'e'},
                {}, // no match
                {'d', 'o', 'u', 'b', 'l', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'a', 'n', 'd', '_', 'e', 'q'},
                {}, // no match
                {}, // no match
                {'x', 'o', 'r', '_', 'e', 'q'},
                {'n', 'o', 't', '_', 'e', 'q'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'e', 'l', 'e', 't', 'e'},
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
                {'t', 'y', 'p', 'e', 'o', 'f'},
                {}, // no match
                {'s', 'i', 'z', 'e', 'o', 'f'},
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
                {'p', 'u', 'b', 'l', 'i', 'c'},
                {}, // no match
                {'_', '_', 'i', 'm', 'a', 'g'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                {'_', '_', 'r', 'e', 'a', 'l'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'s', 'w', 'i', 't', 'c', 'h'},
                {'_', '_', 'n', 'u', 'l', 'l'},
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
                {}, // no match
                {'e', 'x', 't', 'e', 'r', 'n'},
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
            static int value[256] = {
                -1,
                81,
                59,
                -1,
                95,
                34,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                86,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                54,
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
                62,
                -1,
                49,
                -1,
                -1,
                -1,
                32,
                -1,
                -1,
                105,
                69,
                -1,
                -1,
                -1,
                -1,
                -1,
                47,
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
                96,
                -1,
                83,
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
                75,
                -1,
                11,
                -1,
                -1,
                -1,
                -1,
                -1,
                84,
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
                17,
                -1,
                -1,
                -1,
                -1,
                -1,
                87,
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
                55,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                78,
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
            uint32_t w6 = 0;
            memcpy(&w6, &s[2], 4);
            const uint64_t idx = _pext_u64(w6, 0xb10101c);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static char lookup[16][7] = {
                {'m', 'u', 't', 'a', 'b', 'l', 'e'},
                {'p', 'r', 'i', 'v', 'a', 't', 'e'},
                {'t', 'y', 'p', 'e', 'd', 'e', 'f'},
                {}, // no match
                {'v', 'i', 'r', 't', 'u', 'a', 'l'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'d', 'e', 'f', 'a', 'u', 'l', 't'},
                {'_', '_', 'c', 'o', 'n', 's', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'_', '_', 'a', 's', 'm', '_', '_'},
            };
            static int value[16] = {
                65,
                73,
                93,
                -1,
                100,
                -1,
                -1,
                -1,
                46,
                8,
                -1,
                -1,
                -1,
                -1,
                -1,
                3,
            };
            uint16_t w7 = 0;
            memcpy(&w7, &s[5], 2);
            const uint64_t idx = _pext_u64(w7, 0x1a10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static char lookup[64][8] = {
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
                {'_', '_', 'i', 'm', 'a', 'g', '_', '_'},
                {}, // no match
                {'_', '_', 'r', 'e', 'a', 'l', '_', '_'},
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
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'_', '_', 's', 'i', 'g', 'n', 'e', 'd'},
                {'u', 'n', 's', 'i', 'g', 'n', 'e', 'd'},
                {'_', '_', 't', 'y', 'p', 'e', 'o', 'f'},
                {'e', 'x', 'p', 'l', 'i', 'c', 'i', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'t', 'e', 'm', 'p', 'l', 'a', 't', 'e'},
                {}, // no match
                {'c', 'o', 'n', 't', 'i', 'n', 'u', 'e'},
                {}, // no match
                {'t', 'y', 'p', 'e', 'n', 'a', 'm', 'e'},
                {'_', '_', 'i', 'n', 'l', 'i', 'n', 'e'},
                {'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'},
            };
            static int value[64] = {
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
                12,
                -1,
                18,
                -1,
                -1,
                76,
                -1,
                -1,
                -1,
                70,
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
                22,
                98,
                25,
                53,
                -1,
                -1,
                -1,
                88,
                -1,
                45,
                -1,
                94,
                13,
                102,
            };
            uint64_t w8 = 0;
            memcpy(&w8, &s[0], 8);
            const uint64_t idx = _pext_u64(w8, 0x2508080000002000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static char lookup[16][9] = {
                {}, // no match
                {'_', '_', 'a', 'l', 'i', 'g', 'n', 'o', 'f'},
                {'p', 'r', 'o', 't', 'e', 'c', 't', 'e', 'd'},
                {}, // no match
                {'n', 'a', 'm', 'e', 's', 'p', 'a', 'c', 'e'},
                {}, // no match
                {'s', 'i', 'g', 'n', 'a', 't', 'u', 'r', 'e'},
                {}, // no match
                {}, // no match
                {'_', '_', 'c', 'o', 'm', 'p', 'l', 'e', 'x'},
                {'_', '_', 'w', 'c', 'h', 'a', 'r', '_', 't'},
                {}, // no match
                {'_', '_', 's', 'i', 'g', 'o', 'f', '_', '_'},
                {'_', '_', 'l', 'a', 'b', 'e', 'l', '_', '_'},
                {'_', '_', 'c', 'o', 'n', 's', 't', '_', '_'},
                {}, // no match
            };
            static int value[16] = {
                -1,
                0,
                74,
                -1,
                66,
                -1,
                80,
                -1,
                -1,
                6,
                29,
                -1,
                24,
                15,
                9,
                -1,
            };
            uint32_t w9 = 0;
            memcpy(&w9, &s[5], 4);
            const uint64_t idx = _pext_u64(w9, 0x11001800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            static char lookup[32][10] = {
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
                {'_', '_', 's', 'i', 'g', 'n', 'e', 'd', '_', '_'},
                {'_', '_', 'i', 'n', 'l', 'i', 'n', 'e', '_', '_'},
                {'_', '_', 't', 'y', 'p', 'e', 'o', 'f', '_', '_'},
                {}, // no match
                {}, // no match
                {'_', '_', 'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'_', '_', 'r', 'e', 's', 't', 'r', 'i', 'c', 't'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'c', 'o', 'n', 's', 't', '_', 'c', 'a', 's', 't'},
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
                -1,
                -1,
                -1,
                23,
                14,
                26,
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
                19,
                -1,
                -1,
                -1,
                44,
                -1,
                -1,
            };
            uint32_t w10 = 0;
            memcpy(&w10, &s[6], 4);
            const uint64_t idx = _pext_u64(w10, 0x30100300);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 11: {
            static char lookup[4][11] = {
                {'_', '_', 'a', 'l', 'i', 'g', 'n', 'o', 'f', '_', '_'},
                {'_', '_', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '_', '_'},
                {'s', 't', 'a', 't', 'i', 'c', '_', 'c', 'a', 's', 't'},
                {'_', '_', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e'},
            };
            static int value[4] = {
                1,
                7,
                85,
                4,
            };
            uint32_t w11 = 0;
            memcpy(&w11, &s[7], 4);
            const uint64_t idx = _pext_u64(w11, 0x20001000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 12: {
            static char lookup[4][12] = {
                {'_', '_', 'v', 'o', 'l', 'a', 't', 'i', 'l', 'e', '_', '_'},
                {'_', '_', 'r', 'e', 's', 't', 'r', 'i', 'c', 't', '_', '_'},
                {'d', 'y', 'n', 'a', 'm', 'i', 'c', '_', 'c', 'a', 's', 't'},
                {}, // no match
            };
            static int value[4] = {
                28,
                20,
                50,
                -1,
            };
            uint32_t w12 = 0;
            memcpy(&w12, &s[8], 4);
            const uint64_t idx = _pext_u64(w12, 0x20001000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 13: {
            static char lookup[4][13] = {
                {'_', '_', 's', 'i', 'g', 'n', 'a', 't', 'u', 'r', 'e', '_', '_'},
                {'_', '_', 'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e', '_', '_'},
                {}, // no match
                {'_', '_', 'e', 'x', 't', 'e', 'n', 's', 'i', 'o', 'n', '_', '_'},
            };
            static int value[4] = {
                21,
                5,
                -1,
                10,
            };
            uint16_t w13 = 0;
            memcpy(&w13, &s[9], 2);
            const uint64_t idx = _pext_u64(w13, 0x804);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 16: {
            if (s == "reinterpret_cast") {
                return 77;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_cplusplus, dataset=cplusplus
void check_cplusplus() {
    assert(lookup_cplusplus("__asm__") == 3);
    assert(lookup_cplusplus("__const") == 8);
    assert(lookup_cplusplus("default") == 46);
    assert(lookup_cplusplus("mutable") == 65);
    assert(lookup_cplusplus("private") == 73);
    assert(lookup_cplusplus("typedef") == 93);
    assert(lookup_cplusplus("virtual") == 100);
    assert(lookup_cplusplus("__imag") == 11);
    assert(lookup_cplusplus("__null") == 16);
    assert(lookup_cplusplus("__real") == 17);
    assert(lookup_cplusplus("and_eq") == 32);
    assert(lookup_cplusplus("bitand") == 34);
    assert(lookup_cplusplus("delete") == 47);
    assert(lookup_cplusplus("double") == 49);
    assert(lookup_cplusplus("export") == 54);
    assert(lookup_cplusplus("extern") == 55);
    assert(lookup_cplusplus("friend") == 59);
    assert(lookup_cplusplus("inline") == 62);
    assert(lookup_cplusplus("not_eq") == 69);
    assert(lookup_cplusplus("public") == 75);
    assert(lookup_cplusplus("return") == 78);
    assert(lookup_cplusplus("signed") == 81);
    assert(lookup_cplusplus("sizeof") == 83);
    assert(lookup_cplusplus("static") == 84);
    assert(lookup_cplusplus("struct") == 86);
    assert(lookup_cplusplus("switch") == 87);
    assert(lookup_cplusplus("typeid") == 95);
    assert(lookup_cplusplus("typeof") == 96);
    assert(lookup_cplusplus("xor_eq") == 105);
    assert(lookup_cplusplus("auto") == 33);
    assert(lookup_cplusplus("bool") == 36);
    assert(lookup_cplusplus("case") == 38);
    assert(lookup_cplusplus("char") == 40);
    assert(lookup_cplusplus("else") == 51);
    assert(lookup_cplusplus("enum") == 52);
    assert(lookup_cplusplus("goto") == 60);
    assert(lookup_cplusplus("long") == 64);
    assert(lookup_cplusplus("this") == 89);
    assert(lookup_cplusplus("true") == 91);
    assert(lookup_cplusplus("void") == 101);
    assert(lookup_cplusplus("__restrict__") == 20);
    assert(lookup_cplusplus("__volatile__") == 28);
    assert(lookup_cplusplus("dynamic_cast") == 50);
    assert(lookup_cplusplus("asm") == 30);
    assert(lookup_cplusplus("and") == 31);
    assert(lookup_cplusplus("for") == 58);
    assert(lookup_cplusplus("int") == 63);
    assert(lookup_cplusplus("new") == 67);
    assert(lookup_cplusplus("not") == 68);
    assert(lookup_cplusplus("try") == 92);
    assert(lookup_cplusplus("xor") == 104);
    assert(lookup_cplusplus("__asm") == 2);
    assert(lookup_cplusplus("bitor") == 35);
    assert(lookup_cplusplus("break") == 37);
    assert(lookup_cplusplus("catch") == 39);
    assert(lookup_cplusplus("class") == 41);
    assert(lookup_cplusplus("compl") == 42);
    assert(lookup_cplusplus("const") == 43);
    assert(lookup_cplusplus("false") == 56);
    assert(lookup_cplusplus("float") == 57);
    assert(lookup_cplusplus("or_eq") == 72);
    assert(lookup_cplusplus("short") == 79);
    assert(lookup_cplusplus("sigof") == 82);
    assert(lookup_cplusplus("throw") == 90);
    assert(lookup_cplusplus("union") == 97);
    assert(lookup_cplusplus("using") == 99);
    assert(lookup_cplusplus("while") == 103);
    assert(lookup_cplusplus("reinterpret_cast") == 77);
    assert(lookup_cplusplus("__alignof__") == 1);
    assert(lookup_cplusplus("__attribute") == 4);
    assert(lookup_cplusplus("__complex__") == 7);
    assert(lookup_cplusplus("static_cast") == 85);
    assert(lookup_cplusplus("do") == 48);
    assert(lookup_cplusplus("if") == 61);
    assert(lookup_cplusplus("or") == 71);
    assert(lookup_cplusplus("__alignof") == 0);
    assert(lookup_cplusplus("__complex") == 6);
    assert(lookup_cplusplus("__const__") == 9);
    assert(lookup_cplusplus("__label__") == 15);
    assert(lookup_cplusplus("__sigof__") == 24);
    assert(lookup_cplusplus("__wchar_t") == 29);
    assert(lookup_cplusplus("namespace") == 66);
    assert(lookup_cplusplus("protected") == 74);
    assert(lookup_cplusplus("signature") == 80);
    assert(lookup_cplusplus("__attribute__") == 5);
    assert(lookup_cplusplus("__extension__") == 10);
    assert(lookup_cplusplus("__signature__") == 21);
    assert(lookup_cplusplus("__imag__") == 12);
    assert(lookup_cplusplus("__inline") == 13);
    assert(lookup_cplusplus("__real__") == 18);
    assert(lookup_cplusplus("__signed") == 22);
    assert(lookup_cplusplus("__typeof") == 25);
    assert(lookup_cplusplus("continue") == 45);
    assert(lookup_cplusplus("explicit") == 53);
    assert(lookup_cplusplus("operator") == 70);
    assert(lookup_cplusplus("register") == 76);
    assert(lookup_cplusplus("template") == 88);
    assert(lookup_cplusplus("typename") == 94);
    assert(lookup_cplusplus("unsigned") == 98);
    assert(lookup_cplusplus("volatile") == 102);
    assert(lookup_cplusplus("__inline__") == 14);
    assert(lookup_cplusplus("__restrict") == 19);
    assert(lookup_cplusplus("__signed__") == 23);
    assert(lookup_cplusplus("__typeof__") == 26);
    assert(lookup_cplusplus("__volatile") == 27);
    assert(lookup_cplusplus("const_cast") == 44);
}

