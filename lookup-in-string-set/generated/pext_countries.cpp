//lookup: name=lookup_countries_pext, type=pext, dataset=countries
int lookup_countries_pext(std::string_view s) {
    switch (s.size()) {
        case 4: {
            static constexpr const char lookup[32][4] = {
                {}, // no match
                {'C', 'U', 'B', 'A'},
                {}, // no match
                {}, // no match
                {'C', 'H', 'A', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'I', 'J', 'I'},
                {}, // no match
                {'M', 'A', 'L', 'I'},
                {}, // no match
                {'O', 'M', 'A', 'N'},
                {'I', 'R', 'A', 'N'},
                {'T', 'O', 'G', 'O'},
                {}, // no match
                {}, // no match
                {'I', 'R', 'A', 'Q'},
                {'L', 'A', 'O', 'S'},
                {}, // no match
                {'P', 'E', 'R', 'U'},
                {}, // no match
                {}, // no match
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
                -1,
                150,
                -1,
                -1,
                9,
                -1,
                -1,
                -1,
                167,
                -1,
                29,
                -1,
                81,
                65,
                48,
                -1,
                -1,
                66,
                75,
                -1,
                188,
                -1,
                -1,
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
            uint32_t w0 = 0;
            memcpy(&w0, &s[0], 4);
            const uint64_t idx = _pext_u64(w0, 0x1c041000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[1024][5] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'O', 'N', 'G', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'N', 'D', 'I', 'A'},
                {}, // no match
                {'S', 'Y', 'R', 'I', 'A'},
                {}, // no match
                {'G', 'H', 'A', 'N', 'A'},
                {'C', 'H', 'I', 'N', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'A', 'M', 'O', 'A'},
                {'B', 'U', 'R', 'M', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'A', 'L', 'T', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'I', 'B', 'Y', 'A'},
                {'K', 'E', 'N', 'Y', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'Q', 'A', 'T', 'A', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'I', 'G', 'E', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'G', 'Y', 'P', 'T'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'A', 'L', 'A', 'U'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'H', 'I', 'L', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'A', 'U', 'R', 'U'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'T', 'A', 'L', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'H', 'A', 'I', 'T', 'I'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'E', 'P', 'A', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'U', 'D', 'A', 'N'},
                {}, // no match
                {'J', 'A', 'P', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'Y', 'E', 'M', 'E', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'P', 'A', 'I', 'N'},
                {'B', 'E', 'N', 'I', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'A', 'B', 'O', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'O', 'N', 'G', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
            static constexpr const int value[1024] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                177,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                63,
                -1,
                89,
                -1,
                19,
                61,
                -1,
                -1,
                -1,
                175,
                58,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                26,
                23,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                183,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                80,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                45,
                -1,
                68,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                97,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                138,
                2,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            uint32_t w1 = 0;
            memcpy(&w1, &s[1], 4);
            const uint64_t idx = _pext_u64(w1, 0xf1d1800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[256][6] = {
                {'G', 'A', 'M', 'B', 'I', 'A'},
                {'Z', 'A', 'M', 'B', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'E', 'R', 'B', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'A', 'T', 'V', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'A', 'N', 'A', 'D', 'A'},
                {'P', 'A', 'N', 'A', 'M', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'U', 'Y', 'A', 'N', 'A'},
                {}, // no match
                {'A', 'N', 'G', 'O', 'L', 'A'},
                {'U', 'G', 'A', 'N', 'D', 'A'},
                {'G', 'U', 'I', 'N', 'E', 'A'},
                {'R', 'W', 'A', 'N', 'D', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'Y', 'P', 'R', 'U', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'R', 'E', 'E', 'C', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'K', 'U', 'W', 'A', 'I', 'T'},
                {}, // no match
                {'B', 'E', 'L', 'I', 'Z', 'E'},
                {}, // no match
                {'F', 'R', 'A', 'N', 'C', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'O', 'L', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'U', 'V', 'A', 'L', 'U'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'O', 'R', 'W', 'A', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'A', 'L', 'A', 'W', 'I'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'R', 'U', 'N', 'E', 'I'},
                {'T', 'U', 'R', 'K', 'E', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'O', 'N', 'A', 'C', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'J', 'O', 'R', 'D', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'E', 'X', 'I', 'C', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'H', 'U', 'T', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'R', 'A', 'Z', 'I', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'W', 'E', 'D', 'E', 'N'},
                {}, // no match
                {}, // no match
                {'I', 'S', 'R', 'A', 'E', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                18,
                51,
                -1,
                -1,
                -1,
                135,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                148,
                161,
                -1,
                -1,
                -1,
                -1,
                186,
                -1,
                1,
                50,
                20,
                37,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                115,
                -1,
                -1,
                -1,
                73,
                -1,
                147,
                -1,
                112,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                131,
                -1,
                -1,
                -1,
                -1,
                -1,
                178,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                130,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                28,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                57,
                92,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                127,
                -1,
                -1,
                -1,
                69,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                159,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                56,
                -1,
                -1,
                -1,
                -1,
                -1,
                182,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                139,
                -1,
                -1,
                67,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            uint64_t w2;
            uint32_t w3 = 0;
            memcpy(&w3, &s[0], 4);
            w2 = uint64_t(w3);
            uint32_t w4 = 0;
            memcpy(&w4, &s[2], 4);
            w2 |= (uint64_t(w4) << 32);
            const uint64_t idx = _pext_u64(w2, 0xc04000018101010);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[1024][7] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'R', 'E', 'N', 'A', 'D', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'A', 'M', 'I', 'B', 'I', 'A'},
                {'G', 'E', 'O', 'R', 'G', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'U', 'R', 'K', 'I', 'N', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'J', 'A', 'M', 'A', 'I', 'C', 'A'},
                {'S', 'O', 'M', 'A', 'L', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'L', 'B', 'A', 'N', 'I', 'A'},
                {}, // no match
                {'B', 'U', 'R', 'U', 'N', 'D', 'I'},
                {}, // no match
                {}, // no match
                {'E', 'S', 'T', 'O', 'N', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'R', 'O', 'M', 'A', 'N', 'I', 'A'},
                {'A', 'R', 'M', 'E', 'N', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'R', 'O', 'A', 'T', 'I', 'A'},
                {}, // no match
                {'L', 'I', 'B', 'E', 'R', 'I', 'A'},
                {}, // no match
                {}, // no match
                {'A', 'U', 'S', 'T', 'R', 'I', 'A'},
                {'N', 'I', 'G', 'E', 'R', 'I', 'A'},
                {'A', 'L', 'G', 'E', 'R', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'E', 'R', 'I', 'T', 'R', 'E', 'A'},
                {}, // no match
                {}, // no match
                {'B', 'O', 'L', 'I', 'V', 'I', 'A'},
                {}, // no match
                {'T', 'U', 'N', 'I', 'S', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'D', 'E', 'N', 'M', 'A', 'R', 'K'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'O', 'L', 'D', 'O', 'V', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'N', 'D', 'O', 'R', 'R', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'C', 'E', 'L', 'A', 'N', 'D'},
                {}, // no match
                {'I', 'R', 'E', 'L', 'A', 'N', 'D'},
                {}, // no match
                {'B', 'A', 'H', 'R', 'A', 'I', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'F', 'I', 'N', 'L', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'O', 'R', 'O', 'C', 'C', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'E', 'N', 'E', 'G', 'A', 'L'},
                {}, // no match
                {}, // no match
                {'U', 'K', 'R', 'A', 'I', 'N', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'E', 'B', 'A', 'N', 'O', 'N'},
                {}, // no match
                {}, // no match
                {'V', 'I', 'E', 'T', 'N', 'A', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'E', 'S', 'O', 'T', 'H', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'E', 'L', 'G', 'I', 'U', 'M'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'G', 'E', 'R', 'M', 'A', 'N', 'Y'},
                {}, // no match
                {}, // no match
                {'E', 'C', 'U', 'A', 'D', 'O', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'Y', 'A', 'N', 'M', 'A', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'A', 'H', 'A', 'M', 'A', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'U', 'R', 'U', 'G', 'U', 'A', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'O', 'M', 'O', 'R', 'O', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'H', 'U', 'N', 'G', 'A', 'R', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'E', 'L', 'A', 'R', 'U', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'V', 'A', 'N', 'U', 'A', 'T', 'U'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
            static constexpr const int value[1024] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                154,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                34,
                113,
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
                -1,
                -1,
                -1,
                158,
                42,
                -1,
                -1,
                -1,
                98,
                -1,
                5,
                -1,
                -1,
                110,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                133,
                100,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                107,
                -1,
                25,
                -1,
                -1,
                101,
                36,
                0,
                -1,
                -1,
                -1,
                -1,
                15,
                -1,
                -1,
                181,
                -1,
                49,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                126,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                117,
                -1,
                118,
                -1,
                54,
                -1,
                -1,
                -1,
                111,
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
                39,
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
                -1,
                -1,
                -1,
                -1,
                76,
                -1,
                -1,
                96,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                185,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                145,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                190,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                116,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                179,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            uint64_t w5;
            uint32_t w6 = 0;
            memcpy(&w6, &s[1], 4);
            w5 = uint64_t(w6);
            uint32_t w7 = 0;
            memcpy(&w7, &s[3], 4);
            w5 |= (uint64_t(w7) << 32);
            const uint64_t idx = _pext_u64(w5, 0x141000001a000c14);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[256][8] = {
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'A', 'M', 'B', 'O', 'D', 'I', 'A'},
                {'K', 'I', 'R', 'I', 'B', 'A', 'T', 'I'},
                {'B', 'O', 'T', 'S', 'W', 'A', 'N', 'A'},
                {}, // no match
                {'C', 'O', 'L', 'O', 'M', 'B', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'O', 'N', 'G', 'O', 'L', 'I', 'A'},
                {}, // no match
                {'D', 'O', 'M', 'I', 'N', 'I', 'C', 'A'},
                {'T', 'A', 'N', 'Z', 'A', 'N', 'I', 'A'},
                {'S', 'L', 'O', 'V', 'E', 'N', 'I', 'A'},
                {'S', 'L', 'O', 'V', 'A', 'K', 'I', 'A'},
                {}, // no match
                {}, // no match
                {'E', 'T', 'H', 'I', 'O', 'P', 'I', 'A'},
                {}, // no match
                {'D', 'J', 'I', 'B', 'O', 'U', 'T', 'I'},
                {'B', 'U', 'L', 'G', 'A', 'R', 'I', 'A'},
                {}, // no match
                {'M', 'A', 'L', 'A', 'Y', 'S', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'H', 'A', 'I', 'L', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'O', 'R', 'T', 'U', 'G', 'A', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'A', 'M', 'E', 'R', 'O', 'O', 'N'},
                {}, // no match
                {'P', 'A', 'K', 'I', 'S', 'T', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'U', 'R', 'I', 'N', 'A', 'M', 'E'},
                {'Z', 'I', 'M', 'B', 'A', 'B', 'W', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'B', 'A', 'R', 'B', 'A', 'D', 'O', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'A', 'R', 'A', 'G', 'U', 'A', 'Y'},
                {'M', 'A', 'L', 'D', 'I', 'V', 'E', 'S'},
                {'H', 'O', 'N', 'D', 'U', 'R', 'A', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                168,
                3,
                -1,
                184,
                -1,
                -1,
                -1,
                79,
                -1,
                151,
                47,
                137,
                136,
                -1,
                -1,
                16,
                -1,
                12,
                106,
                -1,
                77,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                132,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                6,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                189,
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
                146,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                187,
                78,
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
            };
            uint32_t w8 = 0;
            memcpy(&w8, &s[4], 4);
            const uint64_t idx = _pext_u64(w8, 0x15001b04);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 9: {
            static constexpr const char lookup[128][9] = {
                {'A', 'U', 'S', 'T', 'R', 'A', 'L', 'I', 'A'},
                {}, // no match
                {'L', 'I', 'T', 'H', 'U', 'A', 'N', 'I', 'A'},
                {'M', 'A', 'C', 'E', 'D', 'O', 'N', 'I', 'A'},
                {}, // no match
                {}, // no match
                {'I', 'N', 'D', 'O', 'N', 'E', 'S', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'R', 'I', ' ', 'L', 'A', 'N', 'K', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'V', 'E', 'N', 'E', 'Z', 'U', 'E', 'L', 'A'},
                {'G', 'U', 'A', 'T', 'E', 'M', 'A', 'L', 'A'},
                {'N', 'I', 'C', 'A', 'R', 'A', 'G', 'U', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'R', 'G', 'E', 'N', 'T', 'I', 'N', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'I', 'N', 'G', 'A', 'P', 'O', 'R', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'W', 'A', 'Z', 'I', 'L', 'A', 'N', 'D'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'A', 'U', 'R', 'I', 'T', 'I', 'U', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
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
                166,
                -1,
                122,
                124,
                -1,
                -1,
                64,
                -1,
                -1,
                -1,
                88,
                -1,
                -1,
                -1,
                -1,
                -1,
                191,
                155,
                160,
                -1,
                -1,
                -1,
                -1,
                -1,
                180,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                87,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
            uint32_t w9 = 0;
            memcpy(&w9, &s[5], 4);
            const uint64_t idx = _pext_u64(w9, 0x14061208);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 10: {
            static constexpr const char lookup[128][10] = {
                {}, // no match
                {}, // no match
                {'B', 'A', 'N', 'G', 'L', 'A', 'D', 'E', 'S', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'O', 'S', 'T', 'A', ' ', 'R', 'I', 'C', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'A', 'U', 'R', 'I', 'T', 'A', 'N', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'I', 'C', 'R', 'O', 'N', 'E', 'S', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'A', 'D', 'A', 'G', 'A', 'S', 'C', 'A', 'R'},
                {}, // no match
                {'E', 'A', 'S', 'T', ' ', 'T', 'I', 'M', 'O', 'R'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'E', 'Y', 'C', 'H', 'E', 'L', 'L', 'E', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'O', 'Z', 'A', 'M', 'B', 'I', 'Q', 'U', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'C', 'A', 'P', 'E', ' ', 'V', 'E', 'R', 'D', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'Z', 'E', 'R', 'B', 'A', 'I', 'J', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'K', 'A', 'Z', 'A', 'K', 'H', 'S', 'T', 'A', 'N'},
                {}, // no match
                {'U', 'Z', 'B', 'E', 'K', 'I', 'S', 'T', 'A', 'N'},
                {'T', 'A', 'J', 'I', 'K', 'I', 'S', 'T', 'A', 'N'},
                {'K', 'Y', 'R', 'G', 'Y', 'Z', 'S', 'T', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'M', 'O', 'N', 'T', 'E', 'N', 'E', 'G', 'R', 'O'},
                {}, // no match
                {'S', 'A', 'N', ' ', 'M', 'A', 'R', 'I', 'N', 'O'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'L', 'U', 'X', 'E', 'M', 'B', 'O', 'U', 'R', 'G'},
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
                55,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                30,
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
                27,
                -1,
                62,
                -1,
                -1,
                -1,
                -1,
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
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
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
                7,
                -1,
                -1,
                -1,
                -1,
                -1,
                102,
                -1,
                -1,
                -1,
                -1,
                -1,
                70,
                -1,
                95,
                90,
                74,
                -1,
                -1,
                -1,
                128,
                -1,
                134,
                -1,
                -1,
                -1,
                -1,
                -1,
                123,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint64_t w10 = 0;
            memcpy(&w10, &s[2], 8);
            const uint64_t idx = _pext_u64(w10, 0x700100011000800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 11: {
            static constexpr const char lookup[16][11] = {
                {'N', 'E', 'W', ' ', 'Z', 'E', 'A', 'L', 'A', 'N', 'D'},
                {'S', 'W', 'I', 'T', 'Z', 'E', 'R', 'L', 'A', 'N', 'D'},
                {'S', 'A', 'I', 'N', 'T', ' ', 'L', 'U', 'C', 'I', 'A'},
                {}, // no match
                {'A', 'F', 'G', 'H', 'A', 'N', 'I', 'S', 'T', 'A', 'N'},
                {'S', 'O', 'U', 'T', 'H', ' ', 'S', 'U', 'D', 'A', 'N'},
                {}, // no match
                {}, // no match
                {'I', 'V', 'O', 'R', 'Y', ' ', 'C', 'O', 'A', 'S', 'T'},
                {'E', 'L', ' ', 'S', 'A', 'L', 'V', 'A', 'D', 'O', 'R'},
                {'N', 'E', 'T', 'H', 'E', 'R', 'L', 'A', 'N', 'D', 'S'},
                {'P', 'H', 'I', 'L', 'I', 'P', 'P', 'I', 'N', 'E', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[16] = {
                172,
                140,
                163,
                -1,
                53,
                44,
                -1,
                -1,
                22,
                153,
                129,
                83,
                -1,
                -1,
                -1,
                -1,
            };
            uint64_t w11 = 0;
            memcpy(&w11, &s[3], 8);
            const uint64_t idx = _pext_u64(w11, 0x1900000010000000);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 12: {
            static constexpr const char lookup[32][12] = {
                {'S', 'O', 'U', 'T', 'H', ' ', 'A', 'F', 'R', 'I', 'C', 'A'},
                {}, // no match
                {'S', 'A', 'U', 'D', 'I', ' ', 'A', 'R', 'A', 'B', 'I', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'S', 'I', 'E', 'R', 'R', 'A', ' ', 'L', 'E', 'O', 'N', 'E'},
                {'K', 'O', 'R', 'E', 'A', ',', ' ', 'N', 'O', 'R', 'T', 'H'},
                {'K', 'O', 'R', 'E', 'A', ',', ' ', 'S', 'O', 'U', 'T', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'T', 'U', 'R', 'K', 'M', 'E', 'N', 'I', 'S', 'T', 'A', 'N'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'V', 'A', 'T', 'I', 'C', 'A', 'N', ' ', 'C', 'I', 'T', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[32] = {
                43,
                -1,
                86,
                -1,
                -1,
                -1,
                -1,
                41,
                71,
                72,
                -1,
                -1,
                -1,
                93,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                143,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            uint32_t w12 = 0;
            memcpy(&w12, &s[8], 4);
            const uint64_t idx = _pext_u64(w12, 0x1c080400);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 13: {
            if (s == "GUINEA-BISSAU") {
                return 21;
            }
            if (s == "LIECHTENSTEIN") {
                return 121;
            }
        }
        break;
        case 14: {
            if (s == "UNITED KINGDOM") {
                return 142;
            }
        }
        break;
        case 15: {
            if (s == "SOLOMON ISLANDS") {
                return 176;
            }
        }
        break;
        case 16: {
            if (s == "MARSHALL ISLANDS") {
                return 169;
            }
            if (s == "PAPUA NEW GUINEA") {
                return 174;
            }
        }
        break;
        case 17: {
            if (s == "EQUATORIAL GUINEA") {
                return 14;
            }
        }
        break;
        case 18: {
            if (s == "RUSSIAN FEDERATION") {
                return 85;
            }
            if (s == "DOMINICAN REPUBLIC") {
                return 152;
            }
        }
        break;
        case 19: {
            if (s == "ANTIGUA AND BARBUDA") {
                return 144;
            }
            if (s == "TRINIDAD AND TOBAGO") {
                return 165;
            }
        }
        break;
        case 20: {
            if (s == "UNITED ARAB EMIRATES") {
                return 94;
            }
        }
        break;
        case 21: {
            if (s == "SAO TOME AND PRINCIPE") {
                return 38;
            }
            if (s == "SAINT KITTS AND NEVIS") {
                return 162;
            }
        }
        break;
        case 22: {
            if (s == "BOSNIA AND HERZEGOVINA") {
                return 105;
            }
        }
        break;
        case 24: {
            if (s == "CENTRAL AFRICAN REPUBLIC") {
                return 8;
            }
        }
        break;
        case 32: {
            if (s == "SAINT VINCENT AND THE GRENADINES") {
                return 164;
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_countries_pext, type=pext, dataset=countries
void check_countries_pext() {
    assert(lookup_countries_pext("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_pext("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_pext("UNITED KINGDOM") == 142);
    assert(lookup_countries_pext("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_pext("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_pext("GUINEA-BISSAU") == 21);
    assert(lookup_countries_pext("LIECHTENSTEIN") == 121);
    assert(lookup_countries_pext("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_pext("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_pext("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_pext("ANGOLA") == 1);
    assert(lookup_countries_pext("GAMBIA") == 18);
    assert(lookup_countries_pext("GUINEA") == 20);
    assert(lookup_countries_pext("MALAWI") == 28);
    assert(lookup_countries_pext("RWANDA") == 37);
    assert(lookup_countries_pext("UGANDA") == 50);
    assert(lookup_countries_pext("ZAMBIA") == 51);
    assert(lookup_countries_pext("BHUTAN") == 56);
    assert(lookup_countries_pext("BRUNEI") == 57);
    assert(lookup_countries_pext("ISRAEL") == 67);
    assert(lookup_countries_pext("JORDAN") == 69);
    assert(lookup_countries_pext("KUWAIT") == 73);
    assert(lookup_countries_pext("TURKEY") == 92);
    assert(lookup_countries_pext("CYPRUS") == 108);
    assert(lookup_countries_pext("FRANCE") == 112);
    assert(lookup_countries_pext("GREECE") == 115);
    assert(lookup_countries_pext("LATVIA") == 120);
    assert(lookup_countries_pext("MONACO") == 127);
    assert(lookup_countries_pext("NORWAY") == 130);
    assert(lookup_countries_pext("POLAND") == 131);
    assert(lookup_countries_pext("SERBIA") == 135);
    assert(lookup_countries_pext("SWEDEN") == 139);
    assert(lookup_countries_pext("BELIZE") == 147);
    assert(lookup_countries_pext("CANADA") == 148);
    assert(lookup_countries_pext("MEXICO") == 159);
    assert(lookup_countries_pext("PANAMA") == 161);
    assert(lookup_countries_pext("TUVALU") == 178);
    assert(lookup_countries_pext("BRAZIL") == 182);
    assert(lookup_countries_pext("GUYANA") == 186);
    assert(lookup_countries_pext("SIERRA LEONE") == 41);
    assert(lookup_countries_pext("SOUTH AFRICA") == 43);
    assert(lookup_countries_pext("KOREA, NORTH") == 71);
    assert(lookup_countries_pext("KOREA, SOUTH") == 72);
    assert(lookup_countries_pext("SAUDI ARABIA") == 86);
    assert(lookup_countries_pext("TURKMENISTAN") == 93);
    assert(lookup_countries_pext("VATICAN CITY") == 143);
    assert(lookup_countries_pext("CAPE VERDE") == 7);
    assert(lookup_countries_pext("MADAGASCAR") == 27);
    assert(lookup_countries_pext("MAURITANIA") == 30);
    assert(lookup_countries_pext("MOZAMBIQUE") == 33);
    assert(lookup_countries_pext("SEYCHELLES") == 40);
    assert(lookup_countries_pext("BANGLADESH") == 55);
    assert(lookup_countries_pext("EAST TIMOR") == 62);
    assert(lookup_countries_pext("KAZAKHSTAN") == 70);
    assert(lookup_countries_pext("KYRGYZSTAN") == 74);
    assert(lookup_countries_pext("TAJIKISTAN") == 90);
    assert(lookup_countries_pext("UZBEKISTAN") == 95);
    assert(lookup_countries_pext("AZERBAIJAN") == 102);
    assert(lookup_countries_pext("LUXEMBOURG") == 123);
    assert(lookup_countries_pext("MONTENEGRO") == 128);
    assert(lookup_countries_pext("SAN MARINO") == 134);
    assert(lookup_countries_pext("COSTA RICA") == 149);
    assert(lookup_countries_pext("MICRONESIA") == 170);
    assert(lookup_countries_pext("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_pext("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_pext("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_pext("ALGERIA") == 0);
    assert(lookup_countries_pext("BURKINA") == 4);
    assert(lookup_countries_pext("BURUNDI") == 5);
    assert(lookup_countries_pext("COMOROS") == 10);
    assert(lookup_countries_pext("ERITREA") == 15);
    assert(lookup_countries_pext("LESOTHO") == 24);
    assert(lookup_countries_pext("LIBERIA") == 25);
    assert(lookup_countries_pext("MOROCCO") == 32);
    assert(lookup_countries_pext("NAMIBIA") == 34);
    assert(lookup_countries_pext("NIGERIA") == 36);
    assert(lookup_countries_pext("SENEGAL") == 39);
    assert(lookup_countries_pext("SOMALIA") == 42);
    assert(lookup_countries_pext("TUNISIA") == 49);
    assert(lookup_countries_pext("BAHRAIN") == 54);
    assert(lookup_countries_pext("MYANMAR") == 59);
    assert(lookup_countries_pext("LEBANON") == 76);
    assert(lookup_countries_pext("VIETNAM") == 96);
    assert(lookup_countries_pext("ALBANIA") == 98);
    assert(lookup_countries_pext("ANDORRA") == 99);
    assert(lookup_countries_pext("ARMENIA") == 100);
    assert(lookup_countries_pext("AUSTRIA") == 101);
    assert(lookup_countries_pext("BELARUS") == 103);
    assert(lookup_countries_pext("BELGIUM") == 104);
    assert(lookup_countries_pext("CROATIA") == 107);
    assert(lookup_countries_pext("DENMARK") == 109);
    assert(lookup_countries_pext("ESTONIA") == 110);
    assert(lookup_countries_pext("FINLAND") == 111);
    assert(lookup_countries_pext("GEORGIA") == 113);
    assert(lookup_countries_pext("GERMANY") == 114);
    assert(lookup_countries_pext("HUNGARY") == 116);
    assert(lookup_countries_pext("ICELAND") == 117);
    assert(lookup_countries_pext("IRELAND") == 118);
    assert(lookup_countries_pext("MOLDOVA") == 126);
    assert(lookup_countries_pext("ROMANIA") == 133);
    assert(lookup_countries_pext("UKRAINE") == 141);
    assert(lookup_countries_pext("BAHAMAS") == 145);
    assert(lookup_countries_pext("GRENADA") == 154);
    assert(lookup_countries_pext("JAMAICA") == 158);
    assert(lookup_countries_pext("VANUATU") == 179);
    assert(lookup_countries_pext("BOLIVIA") == 181);
    assert(lookup_countries_pext("ECUADOR") == 185);
    assert(lookup_countries_pext("URUGUAY") == 190);
    assert(lookup_countries_pext("BOTSWANA") == 3);
    assert(lookup_countries_pext("CAMEROON") == 6);
    assert(lookup_countries_pext("DJIBOUTI") == 12);
    assert(lookup_countries_pext("ETHIOPIA") == 16);
    assert(lookup_countries_pext("TANZANIA") == 47);
    assert(lookup_countries_pext("ZIMBABWE") == 52);
    assert(lookup_countries_pext("CAMBODIA") == 60);
    assert(lookup_countries_pext("MALAYSIA") == 77);
    assert(lookup_countries_pext("MALDIVES") == 78);
    assert(lookup_countries_pext("MONGOLIA") == 79);
    assert(lookup_countries_pext("PAKISTAN") == 82);
    assert(lookup_countries_pext("THAILAND") == 91);
    assert(lookup_countries_pext("BULGARIA") == 106);
    assert(lookup_countries_pext("PORTUGAL") == 132);
    assert(lookup_countries_pext("SLOVAKIA") == 136);
    assert(lookup_countries_pext("SLOVENIA") == 137);
    assert(lookup_countries_pext("BARBADOS") == 146);
    assert(lookup_countries_pext("DOMINICA") == 151);
    assert(lookup_countries_pext("HONDURAS") == 157);
    assert(lookup_countries_pext("KIRIBATI") == 168);
    assert(lookup_countries_pext("COLOMBIA") == 184);
    assert(lookup_countries_pext("PARAGUAY") == 187);
    assert(lookup_countries_pext("SURINAME") == 189);
    assert(lookup_countries_pext("BENIN") == 2);
    assert(lookup_countries_pext("CONGO") == 11);
    assert(lookup_countries_pext("EGYPT") == 13);
    assert(lookup_countries_pext("GABON") == 17);
    assert(lookup_countries_pext("GHANA") == 19);
    assert(lookup_countries_pext("KENYA") == 23);
    assert(lookup_countries_pext("LIBYA") == 26);
    assert(lookup_countries_pext("NIGER") == 35);
    assert(lookup_countries_pext("SUDAN") == 45);
    assert(lookup_countries_pext("BURMA") == 58);
    assert(lookup_countries_pext("CHINA") == 61);
    assert(lookup_countries_pext("INDIA") == 63);
    assert(lookup_countries_pext("JAPAN") == 68);
    assert(lookup_countries_pext("NEPAL") == 80);
    assert(lookup_countries_pext("QATAR") == 84);
    assert(lookup_countries_pext("SYRIA") == 89);
    assert(lookup_countries_pext("YEMEN") == 97);
    assert(lookup_countries_pext("ITALY") == 119);
    assert(lookup_countries_pext("MALTA") == 125);
    assert(lookup_countries_pext("SPAIN") == 138);
    assert(lookup_countries_pext("HAITI") == 156);
    assert(lookup_countries_pext("NAURU") == 171);
    assert(lookup_countries_pext("PALAU") == 173);
    assert(lookup_countries_pext("SAMOA") == 175);
    assert(lookup_countries_pext("TONGA") == 177);
    assert(lookup_countries_pext("CHILE") == 183);
    assert(lookup_countries_pext("MAURITIUS") == 31);
    assert(lookup_countries_pext("SWAZILAND") == 46);
    assert(lookup_countries_pext("INDONESIA") == 64);
    assert(lookup_countries_pext("SINGAPORE") == 87);
    assert(lookup_countries_pext("SRI LANKA") == 88);
    assert(lookup_countries_pext("LITHUANIA") == 122);
    assert(lookup_countries_pext("MACEDONIA") == 124);
    assert(lookup_countries_pext("GUATEMALA") == 155);
    assert(lookup_countries_pext("NICARAGUA") == 160);
    assert(lookup_countries_pext("AUSTRALIA") == 166);
    assert(lookup_countries_pext("ARGENTINA") == 180);
    assert(lookup_countries_pext("VENEZUELA") == 191);
    assert(lookup_countries_pext("IVORY COAST") == 22);
    assert(lookup_countries_pext("SOUTH SUDAN") == 44);
    assert(lookup_countries_pext("AFGHANISTAN") == 53);
    assert(lookup_countries_pext("PHILIPPINES") == 83);
    assert(lookup_countries_pext("NETHERLANDS") == 129);
    assert(lookup_countries_pext("SWITZERLAND") == 140);
    assert(lookup_countries_pext("EL SALVADOR") == 153);
    assert(lookup_countries_pext("SAINT LUCIA") == 163);
    assert(lookup_countries_pext("NEW ZEALAND") == 172);
    assert(lookup_countries_pext("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_pext("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_pext("CHAD") == 9);
    assert(lookup_countries_pext("MALI") == 29);
    assert(lookup_countries_pext("TOGO") == 48);
    assert(lookup_countries_pext("IRAN") == 65);
    assert(lookup_countries_pext("IRAQ") == 66);
    assert(lookup_countries_pext("LAOS") == 75);
    assert(lookup_countries_pext("OMAN") == 81);
    assert(lookup_countries_pext("CUBA") == 150);
    assert(lookup_countries_pext("FIJI") == 167);
    assert(lookup_countries_pext("PERU") == 188);
    assert(lookup_countries_pext("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_pext("BOSNIA AND HERZEGOVINA") == 105);
}

