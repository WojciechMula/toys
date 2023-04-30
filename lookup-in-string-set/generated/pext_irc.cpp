//lookup: name=lookup_irc_pext, type=pext, dataset=irc
int lookup_irc_pext(std::string_view s) {
    switch (s.size()) {
        case 3: {
            static constexpr const char lookup[4][3] = {
                {'D', 'I', 'E'},
                {'M', 'S', 'G'},
                {}, // no match
                {'W', 'H', 'O'},
            };
            static constexpr const int value[4] = {
                25,
                1,
                -1,
                3,
            };
            const uint8_t w0 = s[2];
            const uint64_t idx = _pext_u64(w0, 0xa);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 4: {
            static constexpr const char lookup[64][4] = {
                {'H', 'E', 'L', 'P'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'X', 'T', 'R', 'A'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'O', 'P', 'E', 'R'},
                {'U', 'S', 'E', 'R'},
                {}, // no match
                {}, // no match
                {'P', 'A', 'S', 'S'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'Q', 'U', 'I', 'T'},
                {}, // no match
                {'L', 'I', 'S', 'T'},
                {'M', 'O', 'T', 'D'},
                {}, // no match
                {}, // no match
                {'T', 'I', 'M', 'E'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'P', 'I', 'N', 'G'},
                {'P', 'O', 'N', 'G'},
                {}, // no match
                {'G', 'R', 'P', 'H'},
                {}, // no match
                {}, // no match
                {}, // no match
                {'A', 'W', 'A', 'Y'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'N', 'I', 'C', 'K'},
                {}, // no match
                {'W', 'A', 'L', 'L'},
                {}, // no match
                {'K', 'I', 'L', 'L'},
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {}, // no match
                {'I', 'N', 'F', 'O'},
            };
            static constexpr const int value[64] = {
                22,
                -1,
                -1,
                -1,
                43,
                -1,
                -1,
                -1,
                29,
                5,
                -1,
                -1,
                30,
                -1,
                -1,
                -1,
                12,
                -1,
                7,
                44,
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
                27,
                28,
                -1,
                42,
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
                0,
                -1,
                31,
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
                -1,
                -1,
                -1,
                -1,
                15,
            };
            uint32_t w1 = 0;
            memcpy(&w1, &s[0], 4);
            const uint64_t idx = _pext_u64(w1, 0xf000a00);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 5: {
            static constexpr const char lookup[16][5] = {
                {}, // no match
                {}, // no match
                {'T', 'R', 'A', 'C', 'E'},
                {'V', 'O', 'I', 'C', 'E'},
                {'T', 'O', 'P', 'I', 'C'},
                {'A', 'D', 'M', 'I', 'N'},
                {}, // no match
                {}, // no match
                {'S', 'T', 'A', 'T', 'S'},
                {'N', 'A', 'M', 'E', 'S'},
                {'U', 'S', 'E', 'R', 'S'},
                {}, // no match
                {'S', 'Q', 'U', 'I', 'T'},
                {'W', 'H', 'O', 'I', 'S'},
                {'E', 'R', 'R', 'O', 'R'},
                {'L', 'I', 'N', 'K', 'S'},
            };
            static constexpr const int value[16] = {
                -1,
                -1,
                37,
                41,
                8,
                36,
                -1,
                -1,
                18,
                34,
                19,
                -1,
                13,
                4,
                23,
                16,
            };
            uint32_t w2 = 0;
            memcpy(&w2, &s[1], 4);
            const uint64_t idx = _pext_u64(w2, 0x100a0800);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 6: {
            static constexpr const char lookup[8][6] = {
                {'N', 'O', 'T', 'I', 'C', 'E'},
                {'I', 'N', 'V', 'I', 'T', 'E'},
                {'S', 'U', 'M', 'M', 'O', 'N'},
                {'R', 'E', 'H', 'A', 'S', 'H'},
                {'S', 'E', 'R', 'V', 'E', 'R'},
                {'L', 'U', 'S', 'E', 'R', 'S'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[8] = {
                39,
                9,
                17,
                33,
                6,
                40,
                -1,
                -1,
            };
            uint16_t w3 = 0;
            memcpy(&w3, &s[4], 2);
            const uint64_t idx = _pext_u64(w3, 0x1810);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 7: {
            static constexpr const char lookup[8][7] = {
                {'C', 'H', 'A', 'N', 'N', 'E', 'L'},
                {}, // no match
                {'V', 'E', 'R', 'S', 'I', 'O', 'N'},
                {'P', 'R', 'I', 'V', 'M', 'S', 'G'},
                {'C', 'O', 'N', 'N', 'E', 'C', 'T'},
                {'R', 'E', 'S', 'T', 'A', 'R', 'T'},
                {}, // no match
                {}, // no match
            };
            static constexpr const int value[8] = {
                10,
                -1,
                11,
                2,
                26,
                20,
                -1,
                -1,
            };
            uint16_t w4 = 0;
            memcpy(&w4, &s[5], 2);
            const uint64_t idx = _pext_u64(w4, 0x1210);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
        case 8: {
            static constexpr const char lookup[4][8] = {
                {}, // no match
                {'N', 'A', 'M', 'R', 'E', 'P', 'L', 'Y'},
                {'L', 'I', 'N', 'R', 'E', 'P', 'L', 'Y'},
                {'W', 'H', 'O', 'R', 'E', 'P', 'L', 'Y'},
            };
            static constexpr const int value[4] = {
                -1,
                35,
                38,
                21,
            };
            const uint8_t w5 = s[2];
            const uint64_t idx = _pext_u64(w5, 0x3);
            if (memcmp(lookup[idx], s.data(), sizeof(lookup[0])) == 0) {
                return value[idx];
            }
        }
        break;
    }
    return -1;
}

#include <cassert>
//check: name=check_irc_pext, type=pext, dataset=irc
void check_irc_pext() {
    assert(lookup_irc_pext("SERVER") == 6);
    assert(lookup_irc_pext("INVITE") == 9);
    assert(lookup_irc_pext("SUMMON") == 17);
    assert(lookup_irc_pext("REHASH") == 33);
    assert(lookup_irc_pext("NOTICE") == 39);
    assert(lookup_irc_pext("LUSERS") == 40);
    assert(lookup_irc_pext("WHOREPLY") == 21);
    assert(lookup_irc_pext("NAMREPLY") == 35);
    assert(lookup_irc_pext("LINREPLY") == 38);
    assert(lookup_irc_pext("NICK") == 0);
    assert(lookup_irc_pext("USER") == 5);
    assert(lookup_irc_pext("LIST") == 7);
    assert(lookup_irc_pext("QUIT") == 12);
    assert(lookup_irc_pext("KILL") == 14);
    assert(lookup_irc_pext("INFO") == 15);
    assert(lookup_irc_pext("HELP") == 22);
    assert(lookup_irc_pext("AWAY") == 24);
    assert(lookup_irc_pext("PING") == 27);
    assert(lookup_irc_pext("PONG") == 28);
    assert(lookup_irc_pext("OPER") == 29);
    assert(lookup_irc_pext("PASS") == 30);
    assert(lookup_irc_pext("WALL") == 31);
    assert(lookup_irc_pext("TIME") == 32);
    assert(lookup_irc_pext("GRPH") == 42);
    assert(lookup_irc_pext("XTRA") == 43);
    assert(lookup_irc_pext("MOTD") == 44);
    assert(lookup_irc_pext("MSG") == 1);
    assert(lookup_irc_pext("WHO") == 3);
    assert(lookup_irc_pext("DIE") == 25);
    assert(lookup_irc_pext("PRIVMSG") == 2);
    assert(lookup_irc_pext("CHANNEL") == 10);
    assert(lookup_irc_pext("VERSION") == 11);
    assert(lookup_irc_pext("RESTART") == 20);
    assert(lookup_irc_pext("CONNECT") == 26);
    assert(lookup_irc_pext("WHOIS") == 4);
    assert(lookup_irc_pext("TOPIC") == 8);
    assert(lookup_irc_pext("SQUIT") == 13);
    assert(lookup_irc_pext("LINKS") == 16);
    assert(lookup_irc_pext("STATS") == 18);
    assert(lookup_irc_pext("USERS") == 19);
    assert(lookup_irc_pext("ERROR") == 23);
    assert(lookup_irc_pext("NAMES") == 34);
    assert(lookup_irc_pext("ADMIN") == 36);
    assert(lookup_irc_pext("TRACE") == 37);
    assert(lookup_irc_pext("VOICE") == 41);
}

