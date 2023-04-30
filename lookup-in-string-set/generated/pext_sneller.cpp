//lookup: name=lookup_sneller_pext, type=pext, dataset=sneller
int lookup_sneller_pext(std::string_view s) {
    switch (s.size()) {
        case 2: {
            static constexpr const char lookup[32][2] = {
                {'P', 'I'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'O'},
                {}, // no match
                {'I', 'N'},
                {}, // no match
                {'L', 'N'},
                {'O', 'N'},
                {'A', 'S'},
                {'B', 'Y'},
                {}, // no match
                {}, // no match
                {'I', 'S'},
                {}, // no match
                {}, // no match
                {'O', 'R'},
                {'A', 'T'},
                {}, // no match
                {}, // no match
                {'G', 'V'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                161,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                30,
                -1,
                37,
                -1,
                154,
                17,
                2,
                23,
                -1,
                -1,
                36,
                -1,
                -1,
                16,
                3,
                -1,
                -1,
                92,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w0 = 0;
            memcpy(&w0, &s[0], 2);
            const uint64_t idx = _pext_u64(w0, 0x140e);
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
                {'A', 'S', 'C'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'N', 'D'},
                {'E', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'V', 'G'},
                {}, // no match
                {}, // no match
                {'L', 'O', 'G'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'L', 'L'},
                {}, // no match
                {'S', 'U', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'A', 'N'},
                {'S', 'I', 'N'},
                {'M', 'I', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'X', 'P'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'B', 'S'},
                {}, // no match
                {'C', 'O', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'O', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'O', 'W'},
                {'D', 'O', 'W'},
                {}, // no match
                {'M', 'A', 'X'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'Y'},
                {}, // no match
                {'D', 'O', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                4,
                -1,
                -1,
                -1,
                -1,
                -1,
                1,
                53,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                76,
                -1,
                -1,
                156,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                68,
                -1,
                -1,
                -1,
                -1,
                166,
                164,
                69,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                149,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                140,
                -1,
                165,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                159,
                117,
                -1,
                70,
                -1,
                -1,
                -1,
                116,
                -1,
                118,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            const uint64_t idx = _pext_u64(w1, 0x1f0804);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[512][4] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'R', 'U', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                {'C', 'A', 'S', 'E'},
                {}, // no match
                {}, // no match
                {'L', 'I', 'K', 'E'},
                {}, // no match
                {'E', 'L', 'S', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'E', 'S', 'C'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'W', 'I', 'T', 'H'},
                {}, // no match
                {'B', 'O', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'U', 'L', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'E', 'I', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'R', 'I', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'R', 'O', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'N', 'T', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'W', 'E', 'E', 'K'},
                {'T', 'H', 'E', 'N'},
                {'W', 'H', 'E', 'N'},
                {}, // no match
                {'J', 'O', 'I', 'N'},
                {'A', 'S', 'I', 'N'},
                {}, // no match
                {'A', 'T', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'R', 'A', 'N', 'K'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'I', 'G', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'E', 'X', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'N', '1', 'P'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'B', 'R', 'T'},
                {'L', 'E', 'F', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'Q', 'R', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'A', 'S', 'T'},
                {'C', 'A', 'S', 'T'},
                {}, // no match
                {}, // no match
                {'L', 'I', 'S', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'X', 'P', '2'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'Y', 'E', 'A', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'H', 'O', 'U', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'O', 'V', 'E', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'C', 'O', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'O', 'G', '2'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
            static constexpr const int value[512] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                46,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                222,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                49,
                -1,
                -1,
                28,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                58,
                -1,
                64,
                -1,
                -1,
                -1,
                31,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                146,
                -1,
                -1,
                -1,
                -1,
                61,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                119,
                51,
                50,
                -1,
                44,
                167,
                -1,
                169,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                85,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                141,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                155,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                148,
                41,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                147,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                56,
                5,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                151,
                -1,
                -1,
                -1,
                -1,
                -1,
                122,
                -1,
                -1,
                -1,
                115,
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
                -1,
                168,
                -1,
                -1,
                -1,
                -1,
                -1,
                157,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            memcpy(&w4, &s[0], 4);
            const uint64_t idx = _pext_u64(w4, 0x1a031c02);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[256][5] = {
                {}, // no match
                {'E', 'V', 'E', 'R', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'W', 'H', 'E', 'R', 'E'},
                {}, // no match
                {}, // no match
                {'M', 'O', 'N', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'O', 'G', '1', '0'},
                {}, // no match
                {'O', 'R', 'D', 'E', 'R'},
                {}, // no match
                {'L', 'E', 'A', 'S', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'R', 'O', 'U', 'P'},
                {}, // no match
                {'I', 'N', 'N', 'E', 'R'},
                {'C', 'R', 'O', 'S', 'S'},
                {'F', 'L', 'O', 'A', 'T'},
                {'F', 'A', 'L', 'S', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'V', 'A', 'L', 'U', 'E'},
                {}, // no match
                {}, // no match
                {'E', 'X', 'P', '1', '0'},
                {}, // no match
                {'L', 'O', 'W', 'E', 'R'},
                {}, // no match
                {'F', 'I', 'R', 'S', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'U', 'P', 'P', 'E', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'T', 'A', 'N', '2'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'R', 'I', 'G', 'H', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'U', 'L', 'L', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'O', 'U', 'N', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'R', 'U', 'N', 'C'},
                {'R', 'O', 'U', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'L', 'O', 'O', 'R'},
                {}, // no match
                {'L', 'I', 'M', 'I', 'T'},
                {'I', 'L', 'I', 'K', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'U', 'N', 'I', 'O', 'N'},
                {}, // no match
                {}, // no match
                {'E', 'X', 'P', 'M', '1'},
                {}, // no match
                {}, // no match
                {'H', 'Y', 'P', 'O', 'T'},
                {'L', 'T', 'R', 'I', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'R', 'T', 'R', 'I', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
            static constexpr const int value[256] = {
                -1,
                73,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                20,
                -1,
                -1,
                120,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                158,
                -1,
                22,
                -1,
                171,
                -1,
                -1,
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
                -1,
                45,
                43,
                95,
                47,
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
                152,
                -1,
                126,
                -1,
                55,
                -1,
                -1,
                -1,
                -1,
                -1,
                125,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                170,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                42,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                67,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                144,
                142,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                145,
                -1,
                25,
                27,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                15,
                -1,
                -1,
                150,
                -1,
                -1,
                153,
                123,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                124,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            // merge
            uint32_t w5 = 0;
            memcpy(&w5, &s[0], 4);
            const uint8_t w6 = s[4];
            const uint32_t w7 = (uint32_t(w5) & 0x9180010) | (uint32_t(w6) & 0x7);
            const uint64_t idx = _pext_u64(w7, 0x9180017);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[128][6] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'U', 'L', 'L', 'I', 'F'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'E', 'C', 'O', 'N', 'D'},
                {'S', 'T', 'R', 'I', 'N', 'G'},
                {'H', 'A', 'V', 'I', 'N', 'G'},
                {'S', 'Y', 'M', 'B', 'O', 'L'},
                {}, // no match
                {'E', 'S', 'C', 'A', 'P', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'I', 'N', 'U', 'T', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'R', 'I', 'D', 'A', 'Y'},
                {'M', 'O', 'N', 'D', 'A', 'Y'},
                {'S', 'U', 'N', 'D', 'A', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'I', 'L', 'T', 'E', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'I', 'T', '_', 'O', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'X', 'I', 'S', 'T', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'O', 'N', 'C', 'A', 'T'},
                {}, // no match
                {}, // no match
                {'S', 'T', 'R', 'U', 'C', 'T'},
                {'S', 'E', 'L', 'E', 'C', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'O', 'F', 'F', 'S', 'E', 'T'},
                {'S', 'T', 'D', 'D', 'E', 'V'},
                {}, // no match
                {'U', 'T', 'C', 'N', 'O', 'W'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'A', 'T', 'E', 'S', 'T'},
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                113,
                98,
                24,
                101,
                -1,
                66,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                114,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                107,
                103,
                102,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                59,
                -1,
                -1,
                -1,
                82,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                14,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                6,
                -1,
                -1,
                100,
                0,
                -1,
                -1,
                -1,
                26,
                79,
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
                72,
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
            uint64_t w8;
            uint32_t w9 = 0;
            memcpy(&w9, &s[1], 4);
            w8 = uint64_t(w9);
            const uint8_t w10 = s[5];
            w8 |= (uint64_t(w10) << 32);
            const uint64_t idx = _pext_u64(w8, 0x1416000410);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[128][7] = {
                {'D', 'E', 'C', 'I', 'M', 'A', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'I', 'T', '_', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'O', 'O', 'L', 'E', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'E', 'T', 'W', 'E', 'E', 'N'},
                {}, // no match
                {}, // no match
                {'E', 'X', 'P', 'L', 'A', 'I', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'E', 'A', 'D', 'I', 'N', 'G'},
                {'M', 'I', 'S', 'S', 'I', 'N', 'G'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'X', 'T', 'R', 'A', 'C', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'E', 'F', 'A', 'U', 'L', 'T'},
                {}, // no match
                {'U', 'N', 'P', 'I', 'V', 'O', 'T'},
                {}, // no match
                {}, // no match
                {'T', 'U', 'E', 'S', 'D', 'A', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'I', 'M', 'I', 'L', 'A', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'N', 'T', 'E', 'G', 'E', 'R'},
                {'Q', 'U', 'A', 'R', 'T', 'E', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'O', 'O', 'L', '_', 'O', 'R'},
                {'B', 'I', 'T', '_', 'X', 'O', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'E', 'G', 'R', 'E', 'E', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'R', 'A', 'D', 'I', 'A', 'N', 'S'},
                {}, // no match
            };
            static constexpr const int value[128] = {
                99,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                81,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                48,
                -1,
                -1,
                65,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                35,
                -1,
                -1,
                -1,
                13,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                89,
                -1,
                60,
                -1,
                -1,
                104,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                29,
                -1,
                -1,
                -1,
                94,
                121,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                75,
                83,
                -1,
                -1,
                -1,
                -1,
                -1,
                162,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                163,
                -1,
            };
            uint32_t w11 = 0;
            memcpy(&w11, &s[3], 4);
            const uint64_t idx = _pext_u64(w11, 0x130e0010);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[128][8] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'E', 'O', '_', 'H', 'A', 'S', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'V', 'A', 'R', 'I', 'A', 'N', 'C', 'E'},
                {}, // no match
                {'C', 'O', 'A', 'L', 'E', 'S', 'C', 'E'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'R', 'A', 'I', 'L', 'I', 'N', 'G'},
                {'B', 'O', 'O', 'L', '_', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'A', 'T', 'U', 'R', 'D', 'A', 'Y'},
                {'T', 'H', 'U', 'R', 'S', 'D', 'A', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'R', 'A', 'P', 'H', 'V', 'I', 'Z'},
                {}, // no match
                {}, // no match
                {'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'I', 'S', 'T', 'I', 'N', 'C', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'Y', 'P', 'E', '_', 'B', 'I', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'O', 'W', '_', 'U', 'I', 'N', 'T'},
                {}, // no match
                {}, // no match
                {'G', 'R', 'E', 'A', 'T', 'E', 'S', 'T'},
                {'E', 'A', 'R', 'L', 'I', 'E', 'S', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                217,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                77,
                -1,
                7,
                -1,
                8,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                63,
                74,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                108,
                106,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                93,
                -1,
                -1,
                127,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                237,
                -1,
                -1,
                -1,
                160,
                -1,
                -1,
                172,
                71,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            uint32_t w12 = 0;
            memcpy(&w12, &s[4], 4);
            const uint64_t idx = _pext_u64(w12, 0x141c1001);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static constexpr const char lookup[32][9] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F'},
                {}, // no match
                {'S', 'U', 'B', 'S', 'T', 'R', 'I', 'N', 'G'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'Q', 'U', 'A', 'L', 'S', '_', 'C', 'I'},
                {}, // no match
                {'P', 'A', 'R', 'T', 'I', 'T', 'I', 'O', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'I', 'M', 'E', 'S', 'T', 'A', 'M', 'P'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'I', 'T', '_', 'C', 'O', 'U', 'N', 'T'},
                {'M', 'A', 'K', 'E', '_', 'L', 'I', 'S', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'W', 'E', 'D', 'N', 'E', 'S', 'D', 'A', 'Y'},
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
                9,
                -1,
                137,
                -1,
                -1,
                -1,
                129,
                -1,
                34,
                -1,
                -1,
                -1,
                97,
                -1,
                -1,
                -1,
                139,
                235,
                -1,
                -1,
                -1,
                -1,
                105,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w13 = 0;
            memcpy(&w13, &s[7], 2);
            const uint64_t idx = _pext_u64(w13, 0x1d10);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            static constexpr const char lookup[32][10] = {
                {}, // no match
                {}, // no match
                {'T', 'A', 'B', 'L', 'E', '_', 'G', 'L', 'O', 'B'},
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C'},
                {}, // no match
                {'A', 'R', 'R', 'A', 'Y', '_', 'S', 'I', 'Z', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'E', 'N', 'S', 'E', '_', 'R', 'A', 'N', 'K'},
                {}, // no match
                {}, // no match
                {'R', 'O', 'U', 'N', 'D', '_', 'E', 'V', 'E', 'N'},
                {}, // no match
                {'S', 'T', 'D', 'D', 'E', 'V', '_', 'P', 'O', 'P'},
                {}, // no match
                {'R', 'O', 'W', '_', 'N', 'U', 'M', 'B', 'E', 'R'},
                {}, // no match
                {'S', 'P', 'L', 'I', 'T', '_', 'P', 'A', 'R', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'E', 'O', '_', 'T', 'I', 'L', 'E', '_', 'X'},
                {'G', 'E', 'O', '_', 'T', 'I', 'L', 'E', '_', 'Y'},
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
                226,
                12,
                -1,
                224,
                -1,
                -1,
                -1,
                -1,
                -1,
                86,
                -1,
                -1,
                143,
                -1,
                80,
                -1,
                84,
                -1,
                138,
                -1,
                -1,
                -1,
                218,
                219,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            const uint8_t w14 = s[9];
            const uint64_t idx = _pext_u64(w14, 0x1f);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 11: {
            static constexpr const char lookup[16][11] = {
                {'C', 'O', 'N', 'T', 'A', 'I', 'N', 'S', '_', 'C', 'I'},
                {}, // no match
                {}, // no match
                {'C', 'H', 'A', 'R', '_', 'L', 'E', 'N', 'G', 'T', 'H'},
                {}, // no match
                {}, // no match
                {'M', 'I', 'L', 'L', 'I', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'M', 'I', 'C', 'R', 'O', 'S', 'E', 'C', 'O', 'N', 'D'},
                {}, // no match
                {'I', 'N', '_', 'S', 'U', 'B', 'Q', 'U', 'E', 'R', 'Y'},
                {}, // no match
                {'G', 'E', 'O', '_', 'T', 'I', 'L', 'E', '_', 'E', 'S'},
                {}, // no match
                {'M', 'A', 'K', 'E', '_', 'S', 'T', 'R', 'U', 'C', 'T'},
                {}, // no match
                {'T', 'I', 'M', 'E', '_', 'B', 'U', 'C', 'K', 'E', 'T'},
            };
            static constexpr const int value[16] = {
                128,
                -1,
                -1,
                135,
                -1,
                -1,
                111,
                109,
                -1,
                228,
                -1,
                220,
                -1,
                236,
                -1,
                234,
            };
            uint64_t w15 = 0;
            memcpy(&w15, &s[3], 8);
            const uint64_t idx = _pext_u64(w15, 0x1404000000000400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 12: {
            static constexpr const char lookup[32][12] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {'O', 'C', 'T', 'E', 'T', '_', 'L', 'E', 'N', 'G', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'E', 'O', '_', 'D', 'I', 'S', 'T', 'A', 'N', 'C', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'S', '_', 'S', 'U', 'B', 'N', 'E', 'T', '_', 'O', 'F'},
                {}, // no match
                {}, // no match
                {'V', 'A', 'R', 'I', 'A', 'N', 'C', 'E', '_', 'P', 'O', 'P'},
                {'D', 'A', 'T', 'E', '_', 'A', 'D', 'D', '_', 'D', 'A', 'Y'},
                {}, // no match
                {'E', 'Q', 'U', 'A', 'L', 'S', '_', 'F', 'U', 'Z', 'Z', 'Y'},
                {'M', 'I', 'L', 'L', 'I', 'S', 'E', 'C', 'O', 'N', 'D', 'S'},
                {'M', 'I', 'C', 'R', 'O', 'S', 'E', 'C', 'O', 'N', 'D', 'S'},
                {}, // no match
                {}, // no match
                {'W', 'I', 'D', 'T', 'H', '_', 'B', 'U', 'C', 'K', 'E', 'T'},
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
                134,
                -1,
                -1,
                -1,
                -1,
                -1,
                221,
                -1,
                -1,
                -1,
                136,
                -1,
                -1,
                78,
                179,
                -1,
                130,
                112,
                110,
                -1,
                -1,
                173,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint64_t w16 = 0;
            memcpy(&w16, &s[4], 8);
            const uint64_t idx = _pext_u64(w16, 0x1610000000000004);
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
                215,
                227,
                180,
                216,
                183,
                178,
                189,
                -1,
            };
            uint16_t w17 = 0;
            memcpy(&w17, &s[11], 2);
            const uint64_t idx = _pext_u64(w17, 0x1110);
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
                181,
                190,
                -1,
                225,
                -1,
                -1,
                -1,
                193,
                188,
                223,
                -1,
                229,
                -1,
                211,
                -1,
                -1,
                -1,
                210,
                132,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w18 = 0;
            memcpy(&w18, &s[12], 2);
            const uint64_t idx = _pext_u64(w18, 0x1d10);
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
                214,
                176,
                209,
                238,
                -1,
                177,
                239,
                -1,
                -1,
                191,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint16_t w19 = 0;
            memcpy(&w19, &s[13], 2);
            const uint64_t idx = _pext_u64(w19, 0x905);
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
                187,
                186,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                212,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                230,
                -1,
                233,
                182,
                200,
                -1,
                -1,
                199,
                201,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            // merge
            uint16_t w20 = 0;
            memcpy(&w20, &s[14], 2);
            const uint8_t w21 = s[3];
            const uint16_t w22 = (uint16_t(w20) & 0x1a08) | (uint16_t(w21) & 0x10);
            const uint64_t idx = _pext_u64(w22, 0x1a18);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 17: {
            static constexpr const char lookup[8][17] = {
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'S', 'N', 'E', 'L', 'L', 'E', 'R', '_', 'D', 'A', 'T', 'A', 'S', 'H', 'A', 'P', 'E'},
                {'D', 'A', 'T', 'E', '_', 'T', 'R', 'U', 'N', 'C', '_', 'M', 'I', 'N', 'U', 'T', 'E'},
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'Y', 'E', 'A', 'R'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'Q', 'U', 'A', 'R', 'T', 'E', 'R'},
                {}, // no match
                {'D', 'A', 'T', 'E', '_', 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'H', 'O', 'U', 'R'},
            };
            static constexpr const int value[8] = {
                -1,
                207,
                88,
                208,
                204,
                192,
                -1,
                198,
            };
            uint16_t w23 = 0;
            memcpy(&w23, &s[15], 2);
            const uint64_t idx = _pext_u64(w23, 0x1014);
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
                231,
                202,
                -1,
                213,
                232,
            };
            // merge
            uint32_t w24 = 0;
            memcpy(&w24, &s[4], 4);
            const uint8_t w25 = s[17];
            const uint32_t w26 = (uint32_t(w24) & 0x400) | (uint32_t(w25) & 0x14);
            const uint64_t idx = _pext_u64(w26, 0x414);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 19: {
            if (s == "DATE_EXTRACT_SECOND") {
                return 196;
            }
            if (s == "DATE_EXTRACT_MINUTE") {
                return 197;
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
                175,
                174,
                -1,
                131,
                203,
                -1,
                -1,
                -1,
            };
            uint64_t w27 = 0;
            memcpy(&w27, &s[12], 8);
            const uint64_t idx = _pext_u64(w27, 0x1100000000000400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 21: {
            static constexpr const char lookup[4][21] = {
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'M', 'I', 'L', 'L', 'I', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'D', 'A', 'T', 'E', '_', 'D', 'I', 'F', 'F', '_', 'M', 'I', 'C', 'R', 'O', 'S', 'E', 'C', 'O', 'N', 'D'},
                {'A', 'P', 'P', 'R', 'O', 'X', '_', 'C', 'O', 'U', 'N', 'T', '_', 'D', 'I', 'S', 'T', 'I', 'N', 'C', 'T'},
                {}, // no match
            };
            static constexpr const int value[4] = {
                185,
                184,
                87,
                -1,
            };
            uint64_t w28 = 0;
            memcpy(&w28, &s[13], 8);
            const uint64_t idx = _pext_u64(w28, 0x1000000000000400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
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
                206,
                205,
                -1,
                133,
            };
            uint64_t w29 = 0;
            memcpy(&w29, &s[14], 8);
            const uint64_t idx = _pext_u64(w29, 0x100000000000400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 24: {
            if (s == "DATE_EXTRACT_MICROSECOND") {
                return 194;
            }
            if (s == "DATE_EXTRACT_MILLISECOND") {
                return 195;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_sneller_pext, type=pext, dataset=sneller
void check_sneller_pext() {
    assert(lookup_sneller_pext("VARIANCE_POP") == 78);
    assert(lookup_sneller_pext("MICROSECONDS") == 110);
    assert(lookup_sneller_pext("MILLISECONDS") == 112);
    assert(lookup_sneller_pext("EQUALS_FUZZY") == 130);
    assert(lookup_sneller_pext("OCTET_LENGTH") == 134);
    assert(lookup_sneller_pext("IS_SUBNET_OF") == 136);
    assert(lookup_sneller_pext("WIDTH_BUCKET") == 173);
    assert(lookup_sneller_pext("DATE_ADD_DAY") == 179);
    assert(lookup_sneller_pext("GEO_DISTANCE") == 221);
    assert(lookup_sneller_pext("CAST") == 5);
    assert(lookup_sneller_pext("DESC") == 10);
    assert(lookup_sneller_pext("OVER") == 18);
    assert(lookup_sneller_pext("FROM") == 19);
    assert(lookup_sneller_pext("LIKE") == 28);
    assert(lookup_sneller_pext("NULL") == 31);
    assert(lookup_sneller_pext("INTO") == 38);
    assert(lookup_sneller_pext("LEFT") == 41);
    assert(lookup_sneller_pext("JOIN") == 44);
    assert(lookup_sneller_pext("TRUE") == 46);
    assert(lookup_sneller_pext("CASE") == 49);
    assert(lookup_sneller_pext("WHEN") == 50);
    assert(lookup_sneller_pext("THEN") == 51);
    assert(lookup_sneller_pext("ELSE") == 52);
    assert(lookup_sneller_pext("LAST") == 56);
    assert(lookup_sneller_pext("WITH") == 58);
    assert(lookup_sneller_pext("TRIM") == 61);
    assert(lookup_sneller_pext("BOTH") == 64);
    assert(lookup_sneller_pext("RANK") == 85);
    assert(lookup_sneller_pext("TEXT") == 90);
    assert(lookup_sneller_pext("LIST") == 91);
    assert(lookup_sneller_pext("HOUR") == 115);
    assert(lookup_sneller_pext("WEEK") == 119);
    assert(lookup_sneller_pext("YEAR") == 122);
    assert(lookup_sneller_pext("SIGN") == 141);
    assert(lookup_sneller_pext("CEIL") == 146);
    assert(lookup_sneller_pext("SQRT") == 147);
    assert(lookup_sneller_pext("CBRT") == 148);
    assert(lookup_sneller_pext("EXP2") == 151);
    assert(lookup_sneller_pext("LN1P") == 155);
    assert(lookup_sneller_pext("LOG2") == 157);
    assert(lookup_sneller_pext("ASIN") == 167);
    assert(lookup_sneller_pext("ACOS") == 168);
    assert(lookup_sneller_pext("ATAN") == 169);
    assert(lookup_sneller_pext("SIZE") == 222);
    assert(lookup_sneller_pext("DATE_EXTRACT_MONTH") == 202);
    assert(lookup_sneller_pext("DATE_TRUNC_QUARTER") == 213);
    assert(lookup_sneller_pext("SCALAR_REPLACEMENT") == 231);
    assert(lookup_sneller_pext("STRUCT_REPLACEMENT") == 232);
    assert(lookup_sneller_pext("APPROX_COUNT_DISTINCT") == 87);
    assert(lookup_sneller_pext("DATE_DIFF_MICROSECOND") == 184);
    assert(lookup_sneller_pext("DATE_DIFF_MILLISECOND") == 185);
    assert(lookup_sneller_pext("DATE_ADD_SECOND") == 176);
    assert(lookup_sneller_pext("DATE_ADD_MINUTE") == 177);
    assert(lookup_sneller_pext("DATE_DIFF_MONTH") == 191);
    assert(lookup_sneller_pext("DATE_TRUNC_HOUR") == 209);
    assert(lookup_sneller_pext("DATE_TRUNC_YEAR") == 214);
    assert(lookup_sneller_pext("ASSERT_ION_TYPE") == 238);
    assert(lookup_sneller_pext("PARTITION_VALUE") == 239);
    assert(lookup_sneller_pext("DATE_EXTRACT_MICROSECOND") == 194);
    assert(lookup_sneller_pext("DATE_EXTRACT_MILLISECOND") == 195);
    assert(lookup_sneller_pext("SELECT") == 0);
    assert(lookup_sneller_pext("CONCAT") == 6);
    assert(lookup_sneller_pext("EXISTS") == 14);
    assert(lookup_sneller_pext("HAVING") == 24);
    assert(lookup_sneller_pext("OFFSET") == 26);
    assert(lookup_sneller_pext("NULLIF") == 33);
    assert(lookup_sneller_pext("UTCNOW") == 57);
    assert(lookup_sneller_pext("FILTER") == 59);
    assert(lookup_sneller_pext("ESCAPE") == 66);
    assert(lookup_sneller_pext("LATEST") == 72);
    assert(lookup_sneller_pext("STDDEV") == 79);
    assert(lookup_sneller_pext("BIT_OR") == 82);
    assert(lookup_sneller_pext("STRING") == 98);
    assert(lookup_sneller_pext("STRUCT") == 100);
    assert(lookup_sneller_pext("SYMBOL") == 101);
    assert(lookup_sneller_pext("SUNDAY") == 102);
    assert(lookup_sneller_pext("MONDAY") == 103);
    assert(lookup_sneller_pext("FRIDAY") == 107);
    assert(lookup_sneller_pext("SECOND") == 113);
    assert(lookup_sneller_pext("MINUTE") == 114);
    assert(lookup_sneller_pext("AND") == 1);
    assert(lookup_sneller_pext("ASC") == 4);
    assert(lookup_sneller_pext("NOT") == 39);
    assert(lookup_sneller_pext("ALL") == 40);
    assert(lookup_sneller_pext("END") == 53);
    assert(lookup_sneller_pext("SUM") == 68);
    assert(lookup_sneller_pext("MIN") == 69);
    assert(lookup_sneller_pext("MAX") == 70);
    assert(lookup_sneller_pext("AVG") == 76);
    assert(lookup_sneller_pext("DAY") == 116);
    assert(lookup_sneller_pext("DOW") == 117);
    assert(lookup_sneller_pext("DOY") == 118);
    assert(lookup_sneller_pext("ABS") == 140);
    assert(lookup_sneller_pext("EXP") == 149);
    assert(lookup_sneller_pext("LOG") == 156);
    assert(lookup_sneller_pext("POW") == 159);
    assert(lookup_sneller_pext("SIN") == 164);
    assert(lookup_sneller_pext("COS") == 165);
    assert(lookup_sneller_pext("TAN") == 166);
    assert(lookup_sneller_pext("EXTRACT") == 13);
    assert(lookup_sneller_pext("SIMILAR") == 29);
    assert(lookup_sneller_pext("MISSING") == 35);
    assert(lookup_sneller_pext("BETWEEN") == 48);
    assert(lookup_sneller_pext("UNPIVOT") == 60);
    assert(lookup_sneller_pext("LEADING") == 62);
    assert(lookup_sneller_pext("EXPLAIN") == 65);
    assert(lookup_sneller_pext("BOOL_OR") == 75);
    assert(lookup_sneller_pext("BIT_AND") == 81);
    assert(lookup_sneller_pext("BIT_XOR") == 83);
    assert(lookup_sneller_pext("DEFAULT") == 89);
    assert(lookup_sneller_pext("INTEGER") == 94);
    assert(lookup_sneller_pext("BOOLEAN") == 96);
    assert(lookup_sneller_pext("DECIMAL") == 99);
    assert(lookup_sneller_pext("TUESDAY") == 104);
    assert(lookup_sneller_pext("QUARTER") == 121);
    assert(lookup_sneller_pext("DEGREES") == 162);
    assert(lookup_sneller_pext("RADIANS") == 163);
    assert(lookup_sneller_pext("COALESCE") == 7);
    assert(lookup_sneller_pext("DATE_ADD") == 8);
    assert(lookup_sneller_pext("DISTINCT") == 11);
    assert(lookup_sneller_pext("TRAILING") == 63);
    assert(lookup_sneller_pext("EARLIEST") == 71);
    assert(lookup_sneller_pext("BOOL_AND") == 74);
    assert(lookup_sneller_pext("VARIANCE") == 77);
    assert(lookup_sneller_pext("GRAPHVIZ") == 93);
    assert(lookup_sneller_pext("THURSDAY") == 106);
    assert(lookup_sneller_pext("SATURDAY") == 108);
    assert(lookup_sneller_pext("CONTAINS") == 127);
    assert(lookup_sneller_pext("POW_UINT") == 160);
    assert(lookup_sneller_pext("GREATEST") == 172);
    assert(lookup_sneller_pext("GEO_HASH") == 217);
    assert(lookup_sneller_pext("TYPE_BIT") == 237);
    assert(lookup_sneller_pext("UNION") == 15);
    assert(lookup_sneller_pext("WHERE") == 20);
    assert(lookup_sneller_pext("GROUP") == 21);
    assert(lookup_sneller_pext("ORDER") == 22);
    assert(lookup_sneller_pext("LIMIT") == 25);
    assert(lookup_sneller_pext("ILIKE") == 27);
    assert(lookup_sneller_pext("NULLS") == 32);
    assert(lookup_sneller_pext("RIGHT") == 42);
    assert(lookup_sneller_pext("CROSS") == 43);
    assert(lookup_sneller_pext("INNER") == 45);
    assert(lookup_sneller_pext("FALSE") == 47);
    assert(lookup_sneller_pext("VALUE") == 54);
    assert(lookup_sneller_pext("FIRST") == 55);
    assert(lookup_sneller_pext("COUNT") == 67);
    assert(lookup_sneller_pext("EVERY") == 73);
    assert(lookup_sneller_pext("FLOAT") == 95);
    assert(lookup_sneller_pext("MONTH") == 120);
    assert(lookup_sneller_pext("LTRIM") == 123);
    assert(lookup_sneller_pext("RTRIM") == 124);
    assert(lookup_sneller_pext("UPPER") == 125);
    assert(lookup_sneller_pext("LOWER") == 126);
    assert(lookup_sneller_pext("ROUND") == 142);
    assert(lookup_sneller_pext("TRUNC") == 144);
    assert(lookup_sneller_pext("FLOOR") == 145);
    assert(lookup_sneller_pext("EXPM1") == 150);
    assert(lookup_sneller_pext("EXP10") == 152);
    assert(lookup_sneller_pext("HYPOT") == 153);
    assert(lookup_sneller_pext("LOG10") == 158);
    assert(lookup_sneller_pext("ATAN2") == 170);
    assert(lookup_sneller_pext("LEAST") == 171);
    assert(lookup_sneller_pext("DATE_EXTRACT_SECOND") == 196);
    assert(lookup_sneller_pext("DATE_EXTRACT_MINUTE") == 197);
    assert(lookup_sneller_pext("CONTAINS_FUZZY_UNICODE") == 133);
    assert(lookup_sneller_pext("DATE_TRUNC_MICROSECOND") == 205);
    assert(lookup_sneller_pext("DATE_TRUNC_MILLISECOND") == 206);
    assert(lookup_sneller_pext("AS") == 2);
    assert(lookup_sneller_pext("AT") == 3);
    assert(lookup_sneller_pext("OR") == 16);
    assert(lookup_sneller_pext("ON") == 17);
    assert(lookup_sneller_pext("BY") == 23);
    assert(lookup_sneller_pext("TO") == 30);
    assert(lookup_sneller_pext("IS") == 36);
    assert(lookup_sneller_pext("IN") == 37);
    assert(lookup_sneller_pext("GV") == 92);
    assert(lookup_sneller_pext("LN") == 154);
    assert(lookup_sneller_pext("PI") == 161);
    assert(lookup_sneller_pext("DATE_ADD_QUARTER") == 182);
    assert(lookup_sneller_pext("DATE_DIFF_SECOND") == 186);
    assert(lookup_sneller_pext("DATE_DIFF_MINUTE") == 187);
    assert(lookup_sneller_pext("DATE_EXTRACT_DAY") == 199);
    assert(lookup_sneller_pext("DATE_EXTRACT_DOW") == 200);
    assert(lookup_sneller_pext("DATE_EXTRACT_DOY") == 201);
    assert(lookup_sneller_pext("DATE_TRUNC_MONTH") == 212);
    assert(lookup_sneller_pext("HASH_REPLACEMENT") == 230);
    assert(lookup_sneller_pext("LIST_REPLACEMENT") == 233);
    assert(lookup_sneller_pext("DATE_TRUNC") == 12);
    assert(lookup_sneller_pext("STDDEV_POP") == 80);
    assert(lookup_sneller_pext("ROW_NUMBER") == 84);
    assert(lookup_sneller_pext("DENSE_RANK") == 86);
    assert(lookup_sneller_pext("SPLIT_PART") == 138);
    assert(lookup_sneller_pext("ROUND_EVEN") == 143);
    assert(lookup_sneller_pext("GEO_TILE_X") == 218);
    assert(lookup_sneller_pext("GEO_TILE_Y") == 219);
    assert(lookup_sneller_pext("ARRAY_SIZE") == 224);
    assert(lookup_sneller_pext("TABLE_GLOB") == 226);
    assert(lookup_sneller_pext("DATE_ADD_HOUR") == 178);
    assert(lookup_sneller_pext("DATE_ADD_WEEK") == 180);
    assert(lookup_sneller_pext("DATE_ADD_YEAR") == 183);
    assert(lookup_sneller_pext("DATE_DIFF_DAY") == 189);
    assert(lookup_sneller_pext("TO_UNIX_EPOCH") == 215);
    assert(lookup_sneller_pext("TO_UNIX_MICRO") == 216);
    assert(lookup_sneller_pext("TABLE_PATTERN") == 227);
    assert(lookup_sneller_pext("CONTAINS_FUZZY") == 132);
    assert(lookup_sneller_pext("DATE_ADD_MONTH") == 181);
    assert(lookup_sneller_pext("DATE_DIFF_HOUR") == 188);
    assert(lookup_sneller_pext("DATE_DIFF_WEEK") == 190);
    assert(lookup_sneller_pext("DATE_DIFF_YEAR") == 193);
    assert(lookup_sneller_pext("DATE_TRUNC_DAY") == 210);
    assert(lookup_sneller_pext("DATE_TRUNC_DOW") == 211);
    assert(lookup_sneller_pext("ARRAY_CONTAINS") == 223);
    assert(lookup_sneller_pext("ARRAY_POSITION") == 225);
    assert(lookup_sneller_pext("IN_REPLACEMENT") == 229);
    assert(lookup_sneller_pext("DATE_DIFF") == 9);
    assert(lookup_sneller_pext("PARTITION") == 34);
    assert(lookup_sneller_pext("TIMESTAMP") == 97);
    assert(lookup_sneller_pext("WEDNESDAY") == 105);
    assert(lookup_sneller_pext("EQUALS_CI") == 129);
    assert(lookup_sneller_pext("SUBSTRING") == 137);
    assert(lookup_sneller_pext("BIT_COUNT") == 139);
    assert(lookup_sneller_pext("MAKE_LIST") == 235);
    assert(lookup_sneller_pext("SNELLER_DATASHAPE") == 88);
    assert(lookup_sneller_pext("DATE_DIFF_QUARTER") == 192);
    assert(lookup_sneller_pext("DATE_EXTRACT_HOUR") == 198);
    assert(lookup_sneller_pext("DATE_EXTRACT_YEAR") == 204);
    assert(lookup_sneller_pext("DATE_TRUNC_SECOND") == 207);
    assert(lookup_sneller_pext("DATE_TRUNC_MINUTE") == 208);
    assert(lookup_sneller_pext("MICROSECOND") == 109);
    assert(lookup_sneller_pext("MILLISECOND") == 111);
    assert(lookup_sneller_pext("CONTAINS_CI") == 128);
    assert(lookup_sneller_pext("CHAR_LENGTH") == 135);
    assert(lookup_sneller_pext("GEO_TILE_ES") == 220);
    assert(lookup_sneller_pext("IN_SUBQUERY") == 228);
    assert(lookup_sneller_pext("TIME_BUCKET") == 234);
    assert(lookup_sneller_pext("MAKE_STRUCT") == 236);
    assert(lookup_sneller_pext("EQUALS_FUZZY_UNICODE") == 131);
    assert(lookup_sneller_pext("DATE_ADD_MICROSECOND") == 174);
    assert(lookup_sneller_pext("DATE_ADD_MILLISECOND") == 175);
    assert(lookup_sneller_pext("DATE_EXTRACT_QUARTER") == 203);
}

