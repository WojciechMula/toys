
//lookup: name=lookup_irc_hash1, dataset=irc, type=hash, hash=hash1
int lookup_irc_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 46) * 3;
    constexpr const std::string_view lookup[138] = {
        "SUMMON", // 966 (0x3c6)
        "OPER", // 644 (0x284)
        "",
        "",
        "",
        "",
        "STATS", // 830 (0x33e)
        "NAMREPLY", // 1336 (0x538)
        "",
        "",
        "",
        "",
        "REHASH", // 924 (0x39c)
        "",
        "",
        "",
        "",
        "",
        "KILL", // 604 (0x25c)
        "PING", // 604 (0x25c)
        "PONG", // 604 (0x25c)
        "SQUIT", // 835 (0x343)
        "",
        "",
        "PASS", // 652 (0x28c)
        "WALL", // 652 (0x28c)
        "NOTICE", // 882 (0x372)
        "",
        "",
        "",
        "INFO", // 608 (0x260)
        "HELP", // 608 (0x260)
        "",
        "",
        "",
        "",
        "USERS", // 840 (0x348)
        "RESTART", // 1162 (0x48a)
        "",
        "LINKS", // 795 (0x31b)
        "",
        "",
        "NICK", // 612 (0x264)
        "TIME", // 612 (0x264)
        "XTRA", // 612 (0x264)
        "",
        "",
        "",
        "QUIT", // 660 (0x294)
        "",
        "",
        "",
        "",
        "",
        "AWAY", // 616 (0x268)
        "",
        "",
        "TOPIC", // 755 (0x2f3)
        "ERROR", // 755 (0x2f3)
        "",
        "GRPH", // 572 (0x23c)
        "",
        "",
        "",
        "",
        "",
        "WHOIS", // 850 (0x352)
        "",
        "",
        "NAMES", // 805 (0x325)
        "",
        "",
        "USER", // 668 (0x29c)
        "SERVER", // 990 (0x3de)
        "INVITE", // 852 (0x354)
        "ADMIN", // 715 (0x2cb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WHOREPLY", // 1408 (0x580)
        "MOTD", // 580 (0x244)
        "",
        "TRACE", // 765 (0x2fd)
        "",
        "",
        "MSG", // 444 (0x1bc)
        "",
        "",
        "",
        "",
        "",
        "LINREPLY", // 1320 (0x528)
        "",
        "",
        "",
        "",
        "",
        "LUSERS", // 954 (0x3ba)
        "",
        "",
        "CHANNEL", // 1001 (0x3e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WHO", // 498 (0x1f2)
        "",
        "",
        "VOICE", // 775 (0x307)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIST", // 640 (0x280)
        "",
        "",
        "DIE", // 411 (0x19b)
        "",
        "",
        "VERSION", // 1148 (0x47c)
        "",
        "",
        "PRIVMSG", // 1057 (0x421)
        "CONNECT", // 1057 (0x421)
        "",
    };
    constexpr const int values[138] = {
        17, // 966 (0x3c6)
        29, // 644 (0x284)
        -1,
        -1,
        -1,
        -1,
        18, // 830 (0x33e)
        35, // 1336 (0x538)
        -1,
        -1,
        -1,
        -1,
        33, // 924 (0x39c)
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 604 (0x25c)
        27, // 604 (0x25c)
        28, // 604 (0x25c)
        13, // 835 (0x343)
        -1,
        -1,
        30, // 652 (0x28c)
        31, // 652 (0x28c)
        39, // 882 (0x372)
        -1,
        -1,
        -1,
        15, // 608 (0x260)
        22, // 608 (0x260)
        -1,
        -1,
        -1,
        -1,
        19, // 840 (0x348)
        20, // 1162 (0x48a)
        -1,
        16, // 795 (0x31b)
        -1,
        -1,
        0, // 612 (0x264)
        32, // 612 (0x264)
        43, // 612 (0x264)
        -1,
        -1,
        -1,
        12, // 660 (0x294)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 616 (0x268)
        -1,
        -1,
        8, // 755 (0x2f3)
        23, // 755 (0x2f3)
        -1,
        42, // 572 (0x23c)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 850 (0x352)
        -1,
        -1,
        34, // 805 (0x325)
        -1,
        -1,
        5, // 668 (0x29c)
        6, // 990 (0x3de)
        9, // 852 (0x354)
        36, // 715 (0x2cb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 1408 (0x580)
        44, // 580 (0x244)
        -1,
        37, // 765 (0x2fd)
        -1,
        -1,
        1, // 444 (0x1bc)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 1320 (0x528)
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 954 (0x3ba)
        -1,
        -1,
        10, // 1001 (0x3e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 498 (0x1f2)
        -1,
        -1,
        41, // 775 (0x307)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 640 (0x280)
        -1,
        -1,
        25, // 411 (0x19b)
        -1,
        -1,
        11, // 1148 (0x47c)
        -1,
        -1,
        2, // 1057 (0x421)
        26, // 1057 (0x421)
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash1, dataset=irc, type=hash, hash=hash1
void check_irc_hash1() {
    assert(lookup_irc_hash1("SUMMON") == 17);
    assert(lookup_irc_hash1("OPER") == 29);
    assert(lookup_irc_hash1("STATS") == 18);
    assert(lookup_irc_hash1("NAMREPLY") == 35);
    assert(lookup_irc_hash1("REHASH") == 33);
    assert(lookup_irc_hash1("KILL") == 14);
    assert(lookup_irc_hash1("PING") == 27);
    assert(lookup_irc_hash1("PONG") == 28);
    assert(lookup_irc_hash1("SQUIT") == 13);
    assert(lookup_irc_hash1("PASS") == 30);
    assert(lookup_irc_hash1("WALL") == 31);
    assert(lookup_irc_hash1("NOTICE") == 39);
    assert(lookup_irc_hash1("INFO") == 15);
    assert(lookup_irc_hash1("HELP") == 22);
    assert(lookup_irc_hash1("USERS") == 19);
    assert(lookup_irc_hash1("RESTART") == 20);
    assert(lookup_irc_hash1("LINKS") == 16);
    assert(lookup_irc_hash1("NICK") == 0);
    assert(lookup_irc_hash1("TIME") == 32);
    assert(lookup_irc_hash1("XTRA") == 43);
    assert(lookup_irc_hash1("QUIT") == 12);
    assert(lookup_irc_hash1("AWAY") == 24);
    assert(lookup_irc_hash1("TOPIC") == 8);
    assert(lookup_irc_hash1("ERROR") == 23);
    assert(lookup_irc_hash1("GRPH") == 42);
    assert(lookup_irc_hash1("WHOIS") == 4);
    assert(lookup_irc_hash1("NAMES") == 34);
    assert(lookup_irc_hash1("USER") == 5);
    assert(lookup_irc_hash1("SERVER") == 6);
    assert(lookup_irc_hash1("INVITE") == 9);
    assert(lookup_irc_hash1("ADMIN") == 36);
    assert(lookup_irc_hash1("WHOREPLY") == 21);
    assert(lookup_irc_hash1("MOTD") == 44);
    assert(lookup_irc_hash1("TRACE") == 37);
    assert(lookup_irc_hash1("MSG") == 1);
    assert(lookup_irc_hash1("LINREPLY") == 38);
    assert(lookup_irc_hash1("LUSERS") == 40);
    assert(lookup_irc_hash1("CHANNEL") == 10);
    assert(lookup_irc_hash1("WHO") == 3);
    assert(lookup_irc_hash1("VOICE") == 41);
    assert(lookup_irc_hash1("LIST") == 7);
    assert(lookup_irc_hash1("DIE") == 25);
    assert(lookup_irc_hash1("VERSION") == 11);
    assert(lookup_irc_hash1("PRIVMSG") == 2);
    assert(lookup_irc_hash1("CONNECT") == 26);
}

//lookup: name=lookup_irc_hash2, dataset=irc, type=hash, hash=hash2
int lookup_irc_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 101) * 2;
    constexpr const std::string_view lookup[202] = {
        "SQUIT", // 6969 (0x1b39)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "USER", // 6974 (0x1b3e)
        "",
        "WHO", // 6874 (0x1ada)
        "INFO", // 5763 (0x1683)
        "HELP", // 5764 (0x1684)
        "ERROR", // 5663 (0x161f)
        "",
        "",
        "",
        "",
        "MSG", // 5464 (0x1558)
        "OPER", // 6474 (0x194a)
        "",
        "",
        "SUMMON", // 6476 (0x194c)
        "",
        "",
        "",
        "",
        "",
        "NAMES", // 6479 (0x194f)
        "",
        "",
        "",
        "ADMIN", // 5067 (0x13cb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NOTICE", // 5376 (0x1500)
        "",
        "STATS", // 6892 (0x1aec)
        "",
        "LIST", // 6388 (0x18f4)
        "",
        "",
        "",
        "RESTART", // 6895 (0x1aef)
        "",
        "PING", // 5684 (0x1634)
        "PONG", // 5684 (0x1634)
        "",
        "",
        "",
        "",
        "PRIVMSG", // 5687 (0x1637)
        "",
        "AWAY", // 5789 (0x169d)
        "",
        "SERVER", // 6800 (0x1a90)
        "QUIT", // 6800 (0x1a90)
        "",
        "",
        "TIME", // 5792 (0x16a0)
        "",
        "TRACE", // 5793 (0x16a1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KILL", // 5696 (0x1640)
        "",
        "CHANNEL", // 5091 (0x13e3)
        "VERSION", // 6707 (0x1a33)
        "",
        "",
        "LINKS", // 6305 (0x18a1)
        "WALL", // 6608 (0x19d0)
        "LUSERS", // 6306 (0x18a2)
        "",
        "WHOIS", // 7216 (0x1c30)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DIE", // 4695 (0x1257)
        "",
        "",
        "",
        "",
        "",
        "REHASH", // 5910 (0x1716)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WHOREPLY", // 7735 (0x1e37)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NAMREPLY", // 6934 (0x1b16)
        "GRPH", // 5116 (0x13fc)
        "",
        "",
        "XTRA", // 5724 (0x165c)
        "",
        "",
        "",
        "TOPIC", // 5625 (0x15f9)
        "",
        "",
        "",
        "CONNECT", // 5627 (0x15fb)
        "",
        "VOICE", // 5931 (0x172b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PASS", // 6644 (0x19f4)
        "",
        "",
        "",
        "USERS", // 7050 (0x1b8a)
        "MOTD", // 5232 (0x1470)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "INVITE", // 5035 (0x13ab)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LINREPLY", // 6756 (0x1a64)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NICK", // 5854 (0x16de)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[202] = {
        13, // 6969 (0x1b39)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 6974 (0x1b3e)
        -1,
        3, // 6874 (0x1ada)
        15, // 5763 (0x1683)
        22, // 5764 (0x1684)
        23, // 5663 (0x161f)
        -1,
        -1,
        -1,
        -1,
        1, // 5464 (0x1558)
        29, // 6474 (0x194a)
        -1,
        -1,
        17, // 6476 (0x194c)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 6479 (0x194f)
        -1,
        -1,
        -1,
        36, // 5067 (0x13cb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 5376 (0x1500)
        -1,
        18, // 6892 (0x1aec)
        -1,
        7, // 6388 (0x18f4)
        -1,
        -1,
        -1,
        20, // 6895 (0x1aef)
        -1,
        27, // 5684 (0x1634)
        28, // 5684 (0x1634)
        -1,
        -1,
        -1,
        -1,
        2, // 5687 (0x1637)
        -1,
        24, // 5789 (0x169d)
        -1,
        6, // 6800 (0x1a90)
        12, // 6800 (0x1a90)
        -1,
        -1,
        32, // 5792 (0x16a0)
        -1,
        37, // 5793 (0x16a1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 5696 (0x1640)
        -1,
        10, // 5091 (0x13e3)
        11, // 6707 (0x1a33)
        -1,
        -1,
        16, // 6305 (0x18a1)
        31, // 6608 (0x19d0)
        40, // 6306 (0x18a2)
        -1,
        4, // 7216 (0x1c30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 4695 (0x1257)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 5910 (0x1716)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 7735 (0x1e37)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 6934 (0x1b16)
        42, // 5116 (0x13fc)
        -1,
        -1,
        43, // 5724 (0x165c)
        -1,
        -1,
        -1,
        8, // 5625 (0x15f9)
        -1,
        -1,
        -1,
        26, // 5627 (0x15fb)
        -1,
        41, // 5931 (0x172b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 6644 (0x19f4)
        -1,
        -1,
        -1,
        19, // 7050 (0x1b8a)
        44, // 5232 (0x1470)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 5035 (0x13ab)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 6756 (0x1a64)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 5854 (0x16de)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash2, dataset=irc, type=hash, hash=hash2
void check_irc_hash2() {
    assert(lookup_irc_hash2("SQUIT") == 13);
    assert(lookup_irc_hash2("USER") == 5);
    assert(lookup_irc_hash2("WHO") == 3);
    assert(lookup_irc_hash2("INFO") == 15);
    assert(lookup_irc_hash2("HELP") == 22);
    assert(lookup_irc_hash2("ERROR") == 23);
    assert(lookup_irc_hash2("MSG") == 1);
    assert(lookup_irc_hash2("OPER") == 29);
    assert(lookup_irc_hash2("SUMMON") == 17);
    assert(lookup_irc_hash2("NAMES") == 34);
    assert(lookup_irc_hash2("ADMIN") == 36);
    assert(lookup_irc_hash2("NOTICE") == 39);
    assert(lookup_irc_hash2("STATS") == 18);
    assert(lookup_irc_hash2("LIST") == 7);
    assert(lookup_irc_hash2("RESTART") == 20);
    assert(lookup_irc_hash2("PING") == 27);
    assert(lookup_irc_hash2("PONG") == 28);
    assert(lookup_irc_hash2("PRIVMSG") == 2);
    assert(lookup_irc_hash2("AWAY") == 24);
    assert(lookup_irc_hash2("SERVER") == 6);
    assert(lookup_irc_hash2("QUIT") == 12);
    assert(lookup_irc_hash2("TIME") == 32);
    assert(lookup_irc_hash2("TRACE") == 37);
    assert(lookup_irc_hash2("KILL") == 14);
    assert(lookup_irc_hash2("CHANNEL") == 10);
    assert(lookup_irc_hash2("VERSION") == 11);
    assert(lookup_irc_hash2("LINKS") == 16);
    assert(lookup_irc_hash2("WALL") == 31);
    assert(lookup_irc_hash2("LUSERS") == 40);
    assert(lookup_irc_hash2("WHOIS") == 4);
    assert(lookup_irc_hash2("DIE") == 25);
    assert(lookup_irc_hash2("REHASH") == 33);
    assert(lookup_irc_hash2("WHOREPLY") == 21);
    assert(lookup_irc_hash2("NAMREPLY") == 35);
    assert(lookup_irc_hash2("GRPH") == 42);
    assert(lookup_irc_hash2("XTRA") == 43);
    assert(lookup_irc_hash2("TOPIC") == 8);
    assert(lookup_irc_hash2("CONNECT") == 26);
    assert(lookup_irc_hash2("VOICE") == 41);
    assert(lookup_irc_hash2("PASS") == 30);
    assert(lookup_irc_hash2("USERS") == 19);
    assert(lookup_irc_hash2("MOTD") == 44);
    assert(lookup_irc_hash2("INVITE") == 9);
    assert(lookup_irc_hash2("LINREPLY") == 38);
    assert(lookup_irc_hash2("NICK") == 0);
}

//lookup: name=lookup_irc_hash3, dataset=irc, type=hash, hash=hash3
int lookup_irc_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 291) * 1;
    constexpr const std::string_view lookup[291] = {
        "",
        "",
        "",
        "",
        "",
        "CHANNEL", // 19211 (0x4b0b)
        "",
        "",
        "",
        "",
        "",
        "USERS", // 23291 (0x5afb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LUSERS", // 21262 (0x530e)
        "CONNECT", // 19226 (0x4b1a)
        "",
        "",
        "",
        "MSG", // 20685 (0x50cd)
        "LINKS", // 20977 (0x51f1)
        "TOPIC", // 23015 (0x59e7)
        "",
        "USER", // 23017 (0x59e9)
        "",
        "",
        "TRACE", // 23020 (0x59ec)
        "",
        "",
        "",
        "",
        "DIE", // 18369 (0x47c1)
        "",
        "",
        "",
        "TIME", // 22738 (0x58d2)
        "",
        "",
        "",
        "LIST", // 20705 (0x50e1)
        "",
        "",
        "",
        "SERVER", // 23037 (0x59fd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SUMMON", // 23049 (0x5a09)
        "",
        "",
        "",
        "",
        "",
        "",
        "RESTART", // 23056 (0x5a10)
        "",
        "",
        "",
        "KILL", // 20441 (0x4fd9)
        "",
        "REHASH", // 22771 (0x58f3)
        "",
        "",
        "",
        "",
        "",
        "",
        "SQUIT", // 22778 (0x58fa)
        "",
        "STATS", // 22780 (0x58fc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "INVITE", // 20473 (0x4ff9)
        "",
        "",
        "",
        "",
        "",
        "ADMIN", // 18151 (0x46e7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PRIVMSG", // 22544 (0x5810)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "INFO", // 19937 (0x4de1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AWAY", // 17908 (0x45f4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "QUIT", // 21997 (0x55ed)
        "WHOREPLY", // 24617 (0x6029)
        "",
        "",
        "HELP", // 19673 (0x4cd9)
        "",
        "",
        "",
        "",
        "",
        "PING", // 21716 (0x54d4)
        "",
        "",
        "",
        "PASS", // 21720 (0x54d8)
        "",
        "PONG", // 21722 (0x54da)
        "",
        "NAMREPLY", // 22306 (0x5722)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "XTRA", // 23769 (0x5cd9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VERSION", // 24074 (0x5e0a)
        "",
        "",
        "",
        "GRPH", // 19422 (0x4bde)
        "",
        "",
        "",
        "NOTICE", // 21754 (0x54fa)
        "WHOIS", // 23792 (0x5cf0)
        "",
        "",
        "",
        "WALL", // 23505 (0x5bd1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OPER", // 21478 (0x53e6)
        "",
        "",
        "NAMES", // 21481 (0x53e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VOICE", // 23529 (0x5be9)
        "",
        "",
        "",
        "WHO", // 23242 (0x5aca)
        "",
        "",
        "NICK", // 21208 (0x52d8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LINREPLY", // 21802 (0x552a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ERROR", // 19193 (0x4af9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOTD", // 20951 (0x51d7)
    };
    constexpr const int values[291] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 19211 (0x4b0b)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 23291 (0x5afb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 21262 (0x530e)
        26, // 19226 (0x4b1a)
        -1,
        -1,
        -1,
        1, // 20685 (0x50cd)
        16, // 20977 (0x51f1)
        8, // 23015 (0x59e7)
        -1,
        5, // 23017 (0x59e9)
        -1,
        -1,
        37, // 23020 (0x59ec)
        -1,
        -1,
        -1,
        -1,
        25, // 18369 (0x47c1)
        -1,
        -1,
        -1,
        32, // 22738 (0x58d2)
        -1,
        -1,
        -1,
        7, // 20705 (0x50e1)
        -1,
        -1,
        -1,
        6, // 23037 (0x59fd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 23049 (0x5a09)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 23056 (0x5a10)
        -1,
        -1,
        -1,
        14, // 20441 (0x4fd9)
        -1,
        33, // 22771 (0x58f3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 22778 (0x58fa)
        -1,
        18, // 22780 (0x58fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 20473 (0x4ff9)
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 18151 (0x46e7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 22544 (0x5810)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 19937 (0x4de1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 17908 (0x45f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 21997 (0x55ed)
        21, // 24617 (0x6029)
        -1,
        -1,
        22, // 19673 (0x4cd9)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 21716 (0x54d4)
        -1,
        -1,
        -1,
        30, // 21720 (0x54d8)
        -1,
        28, // 21722 (0x54da)
        -1,
        35, // 22306 (0x5722)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 23769 (0x5cd9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 24074 (0x5e0a)
        -1,
        -1,
        -1,
        42, // 19422 (0x4bde)
        -1,
        -1,
        -1,
        39, // 21754 (0x54fa)
        4, // 23792 (0x5cf0)
        -1,
        -1,
        -1,
        31, // 23505 (0x5bd1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 21478 (0x53e6)
        -1,
        -1,
        34, // 21481 (0x53e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 23529 (0x5be9)
        -1,
        -1,
        -1,
        3, // 23242 (0x5aca)
        -1,
        -1,
        0, // 21208 (0x52d8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 21802 (0x552a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 19193 (0x4af9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 20951 (0x51d7)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash3, dataset=irc, type=hash, hash=hash3
void check_irc_hash3() {
    assert(lookup_irc_hash3("CHANNEL") == 10);
    assert(lookup_irc_hash3("USERS") == 19);
    assert(lookup_irc_hash3("LUSERS") == 40);
    assert(lookup_irc_hash3("CONNECT") == 26);
    assert(lookup_irc_hash3("MSG") == 1);
    assert(lookup_irc_hash3("LINKS") == 16);
    assert(lookup_irc_hash3("TOPIC") == 8);
    assert(lookup_irc_hash3("USER") == 5);
    assert(lookup_irc_hash3("TRACE") == 37);
    assert(lookup_irc_hash3("DIE") == 25);
    assert(lookup_irc_hash3("TIME") == 32);
    assert(lookup_irc_hash3("LIST") == 7);
    assert(lookup_irc_hash3("SERVER") == 6);
    assert(lookup_irc_hash3("SUMMON") == 17);
    assert(lookup_irc_hash3("RESTART") == 20);
    assert(lookup_irc_hash3("KILL") == 14);
    assert(lookup_irc_hash3("REHASH") == 33);
    assert(lookup_irc_hash3("SQUIT") == 13);
    assert(lookup_irc_hash3("STATS") == 18);
    assert(lookup_irc_hash3("INVITE") == 9);
    assert(lookup_irc_hash3("ADMIN") == 36);
    assert(lookup_irc_hash3("PRIVMSG") == 2);
    assert(lookup_irc_hash3("INFO") == 15);
    assert(lookup_irc_hash3("AWAY") == 24);
    assert(lookup_irc_hash3("QUIT") == 12);
    assert(lookup_irc_hash3("WHOREPLY") == 21);
    assert(lookup_irc_hash3("HELP") == 22);
    assert(lookup_irc_hash3("PING") == 27);
    assert(lookup_irc_hash3("PASS") == 30);
    assert(lookup_irc_hash3("PONG") == 28);
    assert(lookup_irc_hash3("NAMREPLY") == 35);
    assert(lookup_irc_hash3("XTRA") == 43);
    assert(lookup_irc_hash3("VERSION") == 11);
    assert(lookup_irc_hash3("GRPH") == 42);
    assert(lookup_irc_hash3("NOTICE") == 39);
    assert(lookup_irc_hash3("WHOIS") == 4);
    assert(lookup_irc_hash3("WALL") == 31);
    assert(lookup_irc_hash3("OPER") == 29);
    assert(lookup_irc_hash3("NAMES") == 34);
    assert(lookup_irc_hash3("VOICE") == 41);
    assert(lookup_irc_hash3("WHO") == 3);
    assert(lookup_irc_hash3("NICK") == 0);
    assert(lookup_irc_hash3("LINREPLY") == 38);
    assert(lookup_irc_hash3("ERROR") == 23);
    assert(lookup_irc_hash3("MOTD") == 44);
}

//lookup: name=lookup_irc_hash_sum0, dataset=irc, type=hash, hash=hash_sum0
int lookup_irc_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 54) * 2;
    constexpr const std::string_view lookup[108] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TOPIC", // 383 (0x17f)
        "",
        "",
        "",
        "LINKS", // 385 (0x181)
        "",
        "",
        "",
        "RESTART", // 549 (0x225)
        "",
        "VERSION", // 550 (0x226)
        "",
        "REHASH", // 443 (0x1bb)
        "",
        "PRIVMSG", // 552 (0x228)
        "",
        "",
        "",
        "",
        "",
        "MSG", // 231 (0xe7)
        "",
        "WHOIS", // 394 (0x18a)
        "ERROR", // 394 (0x18a)
        "",
        "",
        "NOTICE", // 450 (0x1c2)
        "",
        "CHANNEL", // 505 (0x1f9)
        "",
        "",
        "",
        "STATS", // 399 (0x18f)
        "",
        "WHO", // 238 (0xee)
        "NAMREPLY", // 616 (0x268)
        "NICK", // 293 (0x125)
        "",
        "USERS", // 402 (0x192)
        "",
        "",
        "",
        "",
        "",
        "HELP", // 297 (0x129)
        "",
        "SQUIT", // 406 (0x196)
        "",
        "LINREPLY", // 623 (0x26f)
        "",
        "KILL", // 300 (0x12c)
        "INFO", // 300 (0x12c)
        "INVITE", // 463 (0x1cf)
        "",
        "PING", // 302 (0x12e)
        "",
        "TIME", // 303 (0x12f)
        "",
        "WALL", // 304 (0x130)
        "",
        "GRPH", // 305 (0x131)
        "",
        "AWAY", // 306 (0x132)
        "CONNECT", // 522 (0x20a)
        "ADMIN", // 361 (0x169)
        "",
        "PONG", // 308 (0x134)
        "MOTD", // 308 (0x134)
        "SERVER", // 471 (0x1d7)
        "",
        "WHOREPLY", // 634 (0x27a)
        "OPER", // 310 (0x136)
        "PASS", // 311 (0x137)
        "",
        "",
        "",
        "TRACE", // 367 (0x16f)
        "",
        "",
        "",
        "",
        "",
        "LIST", // 316 (0x13c)
        "LUSERS", // 478 (0x1de)
        "SUMMON", // 479 (0x1df)
        "",
        "DIE", // 210 (0xd2)
        "NAMES", // 372 (0x174)
        "USER", // 319 (0x13f)
        "XTRA", // 319 (0x13f)
        "VOICE", // 374 (0x176)
        "",
        "",
        "",
        "",
        "",
        "QUIT", // 323 (0x143)
        "",
    };
    constexpr const int values[108] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 383 (0x17f)
        -1,
        -1,
        -1,
        16, // 385 (0x181)
        -1,
        -1,
        -1,
        20, // 549 (0x225)
        -1,
        11, // 550 (0x226)
        -1,
        33, // 443 (0x1bb)
        -1,
        2, // 552 (0x228)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 231 (0xe7)
        -1,
        4, // 394 (0x18a)
        23, // 394 (0x18a)
        -1,
        -1,
        39, // 450 (0x1c2)
        -1,
        10, // 505 (0x1f9)
        -1,
        -1,
        -1,
        18, // 399 (0x18f)
        -1,
        3, // 238 (0xee)
        35, // 616 (0x268)
        0, // 293 (0x125)
        -1,
        19, // 402 (0x192)
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 297 (0x129)
        -1,
        13, // 406 (0x196)
        -1,
        38, // 623 (0x26f)
        -1,
        14, // 300 (0x12c)
        15, // 300 (0x12c)
        9, // 463 (0x1cf)
        -1,
        27, // 302 (0x12e)
        -1,
        32, // 303 (0x12f)
        -1,
        31, // 304 (0x130)
        -1,
        42, // 305 (0x131)
        -1,
        24, // 306 (0x132)
        26, // 522 (0x20a)
        36, // 361 (0x169)
        -1,
        28, // 308 (0x134)
        44, // 308 (0x134)
        6, // 471 (0x1d7)
        -1,
        21, // 634 (0x27a)
        29, // 310 (0x136)
        30, // 311 (0x137)
        -1,
        -1,
        -1,
        37, // 367 (0x16f)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 316 (0x13c)
        40, // 478 (0x1de)
        17, // 479 (0x1df)
        -1,
        25, // 210 (0xd2)
        34, // 372 (0x174)
        5, // 319 (0x13f)
        43, // 319 (0x13f)
        41, // 374 (0x176)
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 323 (0x143)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash_sum0, dataset=irc, type=hash, hash=hash_sum0
void check_irc_hash_sum0() {
    assert(lookup_irc_hash_sum0("TOPIC") == 8);
    assert(lookup_irc_hash_sum0("LINKS") == 16);
    assert(lookup_irc_hash_sum0("RESTART") == 20);
    assert(lookup_irc_hash_sum0("VERSION") == 11);
    assert(lookup_irc_hash_sum0("REHASH") == 33);
    assert(lookup_irc_hash_sum0("PRIVMSG") == 2);
    assert(lookup_irc_hash_sum0("MSG") == 1);
    assert(lookup_irc_hash_sum0("WHOIS") == 4);
    assert(lookup_irc_hash_sum0("ERROR") == 23);
    assert(lookup_irc_hash_sum0("NOTICE") == 39);
    assert(lookup_irc_hash_sum0("CHANNEL") == 10);
    assert(lookup_irc_hash_sum0("STATS") == 18);
    assert(lookup_irc_hash_sum0("WHO") == 3);
    assert(lookup_irc_hash_sum0("NAMREPLY") == 35);
    assert(lookup_irc_hash_sum0("NICK") == 0);
    assert(lookup_irc_hash_sum0("USERS") == 19);
    assert(lookup_irc_hash_sum0("HELP") == 22);
    assert(lookup_irc_hash_sum0("SQUIT") == 13);
    assert(lookup_irc_hash_sum0("LINREPLY") == 38);
    assert(lookup_irc_hash_sum0("KILL") == 14);
    assert(lookup_irc_hash_sum0("INFO") == 15);
    assert(lookup_irc_hash_sum0("INVITE") == 9);
    assert(lookup_irc_hash_sum0("PING") == 27);
    assert(lookup_irc_hash_sum0("TIME") == 32);
    assert(lookup_irc_hash_sum0("WALL") == 31);
    assert(lookup_irc_hash_sum0("GRPH") == 42);
    assert(lookup_irc_hash_sum0("AWAY") == 24);
    assert(lookup_irc_hash_sum0("CONNECT") == 26);
    assert(lookup_irc_hash_sum0("ADMIN") == 36);
    assert(lookup_irc_hash_sum0("PONG") == 28);
    assert(lookup_irc_hash_sum0("MOTD") == 44);
    assert(lookup_irc_hash_sum0("SERVER") == 6);
    assert(lookup_irc_hash_sum0("WHOREPLY") == 21);
    assert(lookup_irc_hash_sum0("OPER") == 29);
    assert(lookup_irc_hash_sum0("PASS") == 30);
    assert(lookup_irc_hash_sum0("TRACE") == 37);
    assert(lookup_irc_hash_sum0("LIST") == 7);
    assert(lookup_irc_hash_sum0("LUSERS") == 40);
    assert(lookup_irc_hash_sum0("SUMMON") == 17);
    assert(lookup_irc_hash_sum0("DIE") == 25);
    assert(lookup_irc_hash_sum0("NAMES") == 34);
    assert(lookup_irc_hash_sum0("USER") == 5);
    assert(lookup_irc_hash_sum0("XTRA") == 43);
    assert(lookup_irc_hash_sum0("VOICE") == 41);
    assert(lookup_irc_hash_sum0("QUIT") == 12);
}

//lookup: name=lookup_irc_hash_sumN, dataset=irc, type=hash, hash=hash_sumN
int lookup_irc_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 47) * 2;
    constexpr const std::string_view lookup[94] = {
        "",
        "",
        "NAMES", // 377 (0x179)
        "",
        "",
        "",
        "VOICE", // 379 (0x17b)
        "",
        "",
        "",
        "",
        "",
        "WHO", // 241 (0xf1)
        "",
        "SERVER", // 477 (0x1dd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TOPIC", // 388 (0x184)
        "CONNECT", // 529 (0x211)
        "NAMREPLY", // 624 (0x270)
        "",
        "LINKS", // 390 (0x186)
        "LUSERS", // 484 (0x1e4)
        "NICK", // 297 (0x129)
        "SUMMON", // 485 (0x1e5)
        "",
        "",
        "",
        "",
        "",
        "",
        "HELP", // 301 (0x12d)
        "",
        "LINREPLY", // 631 (0x277)
        "",
        "",
        "",
        "KILL", // 304 (0x130)
        "INFO", // 304 (0x130)
        "WHOIS", // 399 (0x18f)
        "ERROR", // 399 (0x18f)
        "PING", // 306 (0x132)
        "",
        "DIE", // 213 (0xd5)
        "TIME", // 307 (0x133)
        "WALL", // 308 (0x134)
        "REHASH", // 449 (0x1c1)
        "GRPH", // 309 (0x135)
        "",
        "STATS", // 404 (0x194)
        "AWAY", // 310 (0x136)
        "",
        "",
        "PONG", // 312 (0x138)
        "MOTD", // 312 (0x138)
        "USERS", // 407 (0x197)
        "WHOREPLY", // 642 (0x282)
        "OPER", // 314 (0x13a)
        "",
        "PASS", // 315 (0x13b)
        "NOTICE", // 456 (0x1c8)
        "",
        "",
        "SQUIT", // 411 (0x19b)
        "",
        "",
        "",
        "ADMIN", // 366 (0x16e)
        "",
        "LIST", // 320 (0x140)
        "",
        "RESTART", // 556 (0x22c)
        "",
        "VERSION", // 557 (0x22d)
        "",
        "USER", // 323 (0x143)
        "XTRA", // 323 (0x143)
        "PRIVMSG", // 559 (0x22f)
        "CHANNEL", // 512 (0x200)
        "TRACE", // 372 (0x174)
        "",
        "",
        "",
        "QUIT", // 327 (0x147)
        "",
        "MSG", // 234 (0xea)
        "INVITE", // 469 (0x1d5)
    };
    constexpr const int values[94] = {
        -1,
        -1,
        34, // 377 (0x179)
        -1,
        -1,
        -1,
        41, // 379 (0x17b)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 241 (0xf1)
        -1,
        6, // 477 (0x1dd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 388 (0x184)
        26, // 529 (0x211)
        35, // 624 (0x270)
        -1,
        16, // 390 (0x186)
        40, // 484 (0x1e4)
        0, // 297 (0x129)
        17, // 485 (0x1e5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 301 (0x12d)
        -1,
        38, // 631 (0x277)
        -1,
        -1,
        -1,
        14, // 304 (0x130)
        15, // 304 (0x130)
        4, // 399 (0x18f)
        23, // 399 (0x18f)
        27, // 306 (0x132)
        -1,
        25, // 213 (0xd5)
        32, // 307 (0x133)
        31, // 308 (0x134)
        33, // 449 (0x1c1)
        42, // 309 (0x135)
        -1,
        18, // 404 (0x194)
        24, // 310 (0x136)
        -1,
        -1,
        28, // 312 (0x138)
        44, // 312 (0x138)
        19, // 407 (0x197)
        21, // 642 (0x282)
        29, // 314 (0x13a)
        -1,
        30, // 315 (0x13b)
        39, // 456 (0x1c8)
        -1,
        -1,
        13, // 411 (0x19b)
        -1,
        -1,
        -1,
        36, // 366 (0x16e)
        -1,
        7, // 320 (0x140)
        -1,
        20, // 556 (0x22c)
        -1,
        11, // 557 (0x22d)
        -1,
        5, // 323 (0x143)
        43, // 323 (0x143)
        2, // 559 (0x22f)
        10, // 512 (0x200)
        37, // 372 (0x174)
        -1,
        -1,
        -1,
        12, // 327 (0x147)
        -1,
        1, // 234 (0xea)
        9, // 469 (0x1d5)
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash_sumN, dataset=irc, type=hash, hash=hash_sumN
void check_irc_hash_sumN() {
    assert(lookup_irc_hash_sumN("NAMES") == 34);
    assert(lookup_irc_hash_sumN("VOICE") == 41);
    assert(lookup_irc_hash_sumN("WHO") == 3);
    assert(lookup_irc_hash_sumN("SERVER") == 6);
    assert(lookup_irc_hash_sumN("TOPIC") == 8);
    assert(lookup_irc_hash_sumN("CONNECT") == 26);
    assert(lookup_irc_hash_sumN("NAMREPLY") == 35);
    assert(lookup_irc_hash_sumN("LINKS") == 16);
    assert(lookup_irc_hash_sumN("LUSERS") == 40);
    assert(lookup_irc_hash_sumN("NICK") == 0);
    assert(lookup_irc_hash_sumN("SUMMON") == 17);
    assert(lookup_irc_hash_sumN("HELP") == 22);
    assert(lookup_irc_hash_sumN("LINREPLY") == 38);
    assert(lookup_irc_hash_sumN("KILL") == 14);
    assert(lookup_irc_hash_sumN("INFO") == 15);
    assert(lookup_irc_hash_sumN("WHOIS") == 4);
    assert(lookup_irc_hash_sumN("ERROR") == 23);
    assert(lookup_irc_hash_sumN("PING") == 27);
    assert(lookup_irc_hash_sumN("DIE") == 25);
    assert(lookup_irc_hash_sumN("TIME") == 32);
    assert(lookup_irc_hash_sumN("WALL") == 31);
    assert(lookup_irc_hash_sumN("REHASH") == 33);
    assert(lookup_irc_hash_sumN("GRPH") == 42);
    assert(lookup_irc_hash_sumN("STATS") == 18);
    assert(lookup_irc_hash_sumN("AWAY") == 24);
    assert(lookup_irc_hash_sumN("PONG") == 28);
    assert(lookup_irc_hash_sumN("MOTD") == 44);
    assert(lookup_irc_hash_sumN("USERS") == 19);
    assert(lookup_irc_hash_sumN("WHOREPLY") == 21);
    assert(lookup_irc_hash_sumN("OPER") == 29);
    assert(lookup_irc_hash_sumN("PASS") == 30);
    assert(lookup_irc_hash_sumN("NOTICE") == 39);
    assert(lookup_irc_hash_sumN("SQUIT") == 13);
    assert(lookup_irc_hash_sumN("ADMIN") == 36);
    assert(lookup_irc_hash_sumN("LIST") == 7);
    assert(lookup_irc_hash_sumN("RESTART") == 20);
    assert(lookup_irc_hash_sumN("VERSION") == 11);
    assert(lookup_irc_hash_sumN("USER") == 5);
    assert(lookup_irc_hash_sumN("XTRA") == 43);
    assert(lookup_irc_hash_sumN("PRIVMSG") == 2);
    assert(lookup_irc_hash_sumN("CHANNEL") == 10);
    assert(lookup_irc_hash_sumN("TRACE") == 37);
    assert(lookup_irc_hash_sumN("QUIT") == 12);
    assert(lookup_irc_hash_sumN("MSG") == 1);
    assert(lookup_irc_hash_sumN("INVITE") == 9);
}

//lookup: name=lookup_irc_hash_djb2, dataset=irc, type=hash, hash=hash_djb2
int lookup_irc_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 309) * 1;
    constexpr const std::string_view lookup[309] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SQUIT", // 214602526431 (0x31f74eaedf)
        "",
        "",
        "REHASH", // 7081829529924 (0x670ddeef944)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "USERS", // 214604953019 (0x31f773b5bb)
        "",
        "",
        "",
        "",
        "",
        "MSG", // 197057360 (0xbbedb50)
        "TRACE", // 214603726296 (0x31f760fdd8)
        "",
        "",
        "SUMMON", // 7081887832680 (0x670e1689a68)
        "INFO", // 6502743733 (0x18397feb5)
        "",
        "",
        "",
        "",
        "INVITE", // 7081488496536 (0x670c99b3798)
        "",
        "",
        "ADMIN", // 214580703954 (0x31f601b2d2)
        "WALL", // 6503232889 (0x1839f7579)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RESTART", // 233700388196238 (0xd48c9c9f4f8e)
        "",
        "",
        "",
        "",
        "",
        "",
        "WHO", // 197067895 (0xbbf0477)
        "",
        "",
        "",
        "WHOREPLY", // 7712329618322627 (0x1b6652ab4a74c3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "USER", // 6503180392 (0x1839ea868)
        "",
        "VOICE", // 214605999039 (0x31f783abbf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOTD", // 6502889021 (0x1839a363d)
        "DIE", // 197047227 (0xbbeb3bb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ERROR", // 214585956403 (0x31f651d833)
        "",
        "",
        "SERVER", // 7081869047104 (0x670e049f540)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHANNEL", // 233681112034402 (0xd4881fac6c62)
        "",
        "",
        "",
        "",
        "",
        "",
        "PING", // 6502990103 (0x1839bc117)
        "NOTICE", // 7081685286987 (0x670d556004b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TIME", // 6503133816 (0x1839df278)
        "",
        "",
        "QUIT", // 6503038956 (0x1839c7fec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PONG", // 6502996637 (0x1839bda9d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "STATS", // 214602612824 (0x31f7500058)
        "",
        "",
        "NAMREPLY", // 7711936933789265 (0x1b65f73d77fe51)
        "",
        "",
        "LINKS", // 214593929930 (0x31f6cb82ca)
        "GRPH", // 6502676538 (0x18396f83a)
        "",
        "",
        "NICK", // 6502917870 (0x1839aa6ee)
        "",
        "PRIVMSG", // 233698302246161 (0xd48c204a3d11)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TOPIC", // 214603635016 (0x31f75f9948)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KILL", // 6502810357 (0x1839902f5)
        "",
        "",
        "",
        "HELP", // 6502698194 (0x183974cd2)
        "",
        "",
        "",
        "VERSION", // 233705552854863 (0xd48dd075bf4f)
        "",
        "LUSERS", // 7081614091943 (0x670d117a6a7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIST", // 6502846533 (0x183999045)
        "",
        "PASS", // 6502981568 (0x1839b9fc0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OPER", // 6502961503 (0x1839b515f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WHOIS", // 214606940147 (0x31f79207f3)
        "CONNECT", // 233681401389267 (0xd48830eba0d3)
        "",
        "AWAY", // 6502465883 (0x18393c15b)
        "",
        "",
        "",
        "",
        "",
        "NAMES", // 214596012989 (0x31f6eb4bbd)
        "",
        "",
        "",
        "",
        "",
        "LINREPLY", // 7711862067782456 (0x1b65e5cf1b6338)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "XTRA", // 6503289704 (0x183a05368)
    };
    constexpr const int values[309] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 214602526431 (0x31f74eaedf)
        -1,
        -1,
        33, // 7081829529924 (0x670ddeef944)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 214604953019 (0x31f773b5bb)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 197057360 (0xbbedb50)
        37, // 214603726296 (0x31f760fdd8)
        -1,
        -1,
        17, // 7081887832680 (0x670e1689a68)
        15, // 6502743733 (0x18397feb5)
        -1,
        -1,
        -1,
        -1,
        9, // 7081488496536 (0x670c99b3798)
        -1,
        -1,
        36, // 214580703954 (0x31f601b2d2)
        31, // 6503232889 (0x1839f7579)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 233700388196238 (0xd48c9c9f4f8e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 197067895 (0xbbf0477)
        -1,
        -1,
        -1,
        21, // 7712329618322627 (0x1b6652ab4a74c3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 6503180392 (0x1839ea868)
        -1,
        41, // 214605999039 (0x31f783abbf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 6502889021 (0x1839a363d)
        25, // 197047227 (0xbbeb3bb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 214585956403 (0x31f651d833)
        -1,
        -1,
        6, // 7081869047104 (0x670e049f540)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 233681112034402 (0xd4881fac6c62)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 6502990103 (0x1839bc117)
        39, // 7081685286987 (0x670d556004b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 6503133816 (0x1839df278)
        -1,
        -1,
        12, // 6503038956 (0x1839c7fec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 6502996637 (0x1839bda9d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 214602612824 (0x31f7500058)
        -1,
        -1,
        35, // 7711936933789265 (0x1b65f73d77fe51)
        -1,
        -1,
        16, // 214593929930 (0x31f6cb82ca)
        42, // 6502676538 (0x18396f83a)
        -1,
        -1,
        0, // 6502917870 (0x1839aa6ee)
        -1,
        2, // 233698302246161 (0xd48c204a3d11)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 214603635016 (0x31f75f9948)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 6502810357 (0x1839902f5)
        -1,
        -1,
        -1,
        22, // 6502698194 (0x183974cd2)
        -1,
        -1,
        -1,
        11, // 233705552854863 (0xd48dd075bf4f)
        -1,
        40, // 7081614091943 (0x670d117a6a7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 6502846533 (0x183999045)
        -1,
        30, // 6502981568 (0x1839b9fc0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 6502961503 (0x1839b515f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 214606940147 (0x31f79207f3)
        26, // 233681401389267 (0xd48830eba0d3)
        -1,
        24, // 6502465883 (0x18393c15b)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 214596012989 (0x31f6eb4bbd)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 7711862067782456 (0x1b65e5cf1b6338)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 6503289704 (0x183a05368)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash_djb2, dataset=irc, type=hash, hash=hash_djb2
void check_irc_hash_djb2() {
    assert(lookup_irc_hash_djb2("SQUIT") == 13);
    assert(lookup_irc_hash_djb2("REHASH") == 33);
    assert(lookup_irc_hash_djb2("USERS") == 19);
    assert(lookup_irc_hash_djb2("MSG") == 1);
    assert(lookup_irc_hash_djb2("TRACE") == 37);
    assert(lookup_irc_hash_djb2("SUMMON") == 17);
    assert(lookup_irc_hash_djb2("INFO") == 15);
    assert(lookup_irc_hash_djb2("INVITE") == 9);
    assert(lookup_irc_hash_djb2("ADMIN") == 36);
    assert(lookup_irc_hash_djb2("WALL") == 31);
    assert(lookup_irc_hash_djb2("RESTART") == 20);
    assert(lookup_irc_hash_djb2("WHO") == 3);
    assert(lookup_irc_hash_djb2("WHOREPLY") == 21);
    assert(lookup_irc_hash_djb2("USER") == 5);
    assert(lookup_irc_hash_djb2("VOICE") == 41);
    assert(lookup_irc_hash_djb2("MOTD") == 44);
    assert(lookup_irc_hash_djb2("DIE") == 25);
    assert(lookup_irc_hash_djb2("ERROR") == 23);
    assert(lookup_irc_hash_djb2("SERVER") == 6);
    assert(lookup_irc_hash_djb2("CHANNEL") == 10);
    assert(lookup_irc_hash_djb2("PING") == 27);
    assert(lookup_irc_hash_djb2("NOTICE") == 39);
    assert(lookup_irc_hash_djb2("TIME") == 32);
    assert(lookup_irc_hash_djb2("QUIT") == 12);
    assert(lookup_irc_hash_djb2("PONG") == 28);
    assert(lookup_irc_hash_djb2("STATS") == 18);
    assert(lookup_irc_hash_djb2("NAMREPLY") == 35);
    assert(lookup_irc_hash_djb2("LINKS") == 16);
    assert(lookup_irc_hash_djb2("GRPH") == 42);
    assert(lookup_irc_hash_djb2("NICK") == 0);
    assert(lookup_irc_hash_djb2("PRIVMSG") == 2);
    assert(lookup_irc_hash_djb2("TOPIC") == 8);
    assert(lookup_irc_hash_djb2("KILL") == 14);
    assert(lookup_irc_hash_djb2("HELP") == 22);
    assert(lookup_irc_hash_djb2("VERSION") == 11);
    assert(lookup_irc_hash_djb2("LUSERS") == 40);
    assert(lookup_irc_hash_djb2("LIST") == 7);
    assert(lookup_irc_hash_djb2("PASS") == 30);
    assert(lookup_irc_hash_djb2("OPER") == 29);
    assert(lookup_irc_hash_djb2("WHOIS") == 4);
    assert(lookup_irc_hash_djb2("CONNECT") == 26);
    assert(lookup_irc_hash_djb2("AWAY") == 24);
    assert(lookup_irc_hash_djb2("NAMES") == 34);
    assert(lookup_irc_hash_djb2("LINREPLY") == 38);
    assert(lookup_irc_hash_djb2("XTRA") == 43);
}

//lookup: name=lookup_irc_hash_sdb, dataset=irc, type=hash, hash=hash_sdb
int lookup_irc_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 274) * 1;
    constexpr const std::string_view lookup[274] = {
        "",
        "GRPH", // 19987820180999063 (0x4702d109b90b97)
        "",
        "RESTART", // 14516195258446270899 (0xc973e2ad6de651b3)
        "",
        "USER", // 23929015340240131 (0x5503500b2e0d03)
        "",
        "",
        "",
        "",
        "",
        "REHASH", // 2330726965923245773 (0x205867d3a8476ecd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "STATS", // 304015751826253495 (0x43814b72dba26b7)
        "",
        "",
        "LUSERS", // 2235867094133075840 (0x1f076546a6c96f80)
        "TOPIC", // 305986179745851095 (0x43f14cf2dee26d7)
        "MOTD", // 21676889094294566 (0x4d03040a4d0c26)
        "",
        "LIST", // 21395349688880098 (0x4c02f50a0d0be2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WHO", // 373701084214 (0x5702520436)
        "",
        "",
        "",
        "",
        "",
        "",
        "CHANNEL", // 12249679596827321287 (0xa9ff9ab1153e23c7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OPER", // 22239920655043654 (0x4f03170a7a0c46)
        "",
        "",
        "TRACE", // 306830656214607505 (0x44214db2ddf2691)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SUMMON", // 2411515399698347453 (0x21776c7ab16775bd)
        "WHOREPLY", // 8881242866426520712 (0x7b40835509532488)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "INVITE", // 2137064407908313821 (0x1da860c19f816add)
        "",
        "",
        "",
        "",
        "",
        "",
        "VERSION", // 15120542671138217188 (0xd1d6f57284545ce4)
        "",
        "",
        "HELP", // 20269277974235961 (0x4802cd09820b39)
        "",
        "",
        "AWAY", // 18298759857703686 (0x4102a009260b06)
        "",
        "",
        "",
        "",
        "",
        "KILL", // 21113836055235498 (0x4b02ec09eb0baa)
        "",
        "",
        "LINREPLY", // 229872422959630453 (0x330abc0322ac875)
        "",
        "",
        "",
        "",
        "CONNECT", // 12470930022696562234 (0xad11a4c825952e3a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PASS", // 22521369858739205 (0x5003110a490c05)
        "PING", // 22521404221295666 (0x5003190a740c32)
        "",
        "",
        "",
        "VOICE", // 312742012989613866 (0x45715342e96272a)
        "",
        "ERROR", // 256161754398925468 (0x38e11c227fd229c)
        "",
        "DIE", // 292089299844 (0x4401e10384)
        "",
        "",
        "",
        "WALL", // 24491965290581158 (0x5703500aff0ca6)
        "",
        "",
        "",
        "NAMREPLY", // 584531821205897680 (0x81cac982ae3c1d0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PRIVMSG", // 14508316407321220550 (0xc957e4e7735a55c6)
        "ADMIN", // 238708815433768859 (0x350106724af1f9b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TIME", // 23647458753973401 (0x54033d0adf0c99)
        "USERS", // 310490118686058332 (0x44f151e2e8d275c)
        "NICK", // 21958376954203103 (0x4e03070a330bdf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LINKS", // 277273636109427633 (0x3d912e729e223b1)
        "",
        "",
        "",
        "MSG", // 330748199925 (0x4d022103f5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "XTRA", // 24773560536010099 (0x58036c0b920d73)
        "",
        "",
        "",
        "",
        "INFO", // 20550830265273234 (0x4902df09cd0b92)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SERVER", // 2358876100028428651 (0x20bc6950ab5a716b)
        "NAMES", // 281777386059866976 (0x3e9130a29d62360)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "QUIT", // 22802969398480055 (0x51032e0ad20cb7)
        "NOTICE", // 2266548850155024260 (0x1f74662ba78f6f84)
        "",
        "",
        "",
        "WHOIS", // 314149374985709332 (0x45c15312e6f2714)
        "",
        "SQUIT", // 303171296833185530 (0x43514b02dd626fa)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PONG", // 22521429993458792 (0x50031f0a980c68)
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[274] = {
        -1,
        42, // 19987820180999063 (0x4702d109b90b97)
        -1,
        20, // 14516195258446270899 (0xc973e2ad6de651b3)
        -1,
        5, // 23929015340240131 (0x5503500b2e0d03)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 2330726965923245773 (0x205867d3a8476ecd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 304015751826253495 (0x43814b72dba26b7)
        -1,
        -1,
        40, // 2235867094133075840 (0x1f076546a6c96f80)
        8, // 305986179745851095 (0x43f14cf2dee26d7)
        44, // 21676889094294566 (0x4d03040a4d0c26)
        -1,
        7, // 21395349688880098 (0x4c02f50a0d0be2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 373701084214 (0x5702520436)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 12249679596827321287 (0xa9ff9ab1153e23c7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 22239920655043654 (0x4f03170a7a0c46)
        -1,
        -1,
        37, // 306830656214607505 (0x44214db2ddf2691)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 2411515399698347453 (0x21776c7ab16775bd)
        21, // 8881242866426520712 (0x7b40835509532488)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 2137064407908313821 (0x1da860c19f816add)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 15120542671138217188 (0xd1d6f57284545ce4)
        -1,
        -1,
        22, // 20269277974235961 (0x4802cd09820b39)
        -1,
        -1,
        24, // 18298759857703686 (0x4102a009260b06)
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 21113836055235498 (0x4b02ec09eb0baa)
        -1,
        -1,
        38, // 229872422959630453 (0x330abc0322ac875)
        -1,
        -1,
        -1,
        -1,
        26, // 12470930022696562234 (0xad11a4c825952e3a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 22521369858739205 (0x5003110a490c05)
        27, // 22521404221295666 (0x5003190a740c32)
        -1,
        -1,
        -1,
        41, // 312742012989613866 (0x45715342e96272a)
        -1,
        23, // 256161754398925468 (0x38e11c227fd229c)
        -1,
        25, // 292089299844 (0x4401e10384)
        -1,
        -1,
        -1,
        31, // 24491965290581158 (0x5703500aff0ca6)
        -1,
        -1,
        -1,
        35, // 584531821205897680 (0x81cac982ae3c1d0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 14508316407321220550 (0xc957e4e7735a55c6)
        36, // 238708815433768859 (0x350106724af1f9b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 23647458753973401 (0x54033d0adf0c99)
        19, // 310490118686058332 (0x44f151e2e8d275c)
        0, // 21958376954203103 (0x4e03070a330bdf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 277273636109427633 (0x3d912e729e223b1)
        -1,
        -1,
        -1,
        1, // 330748199925 (0x4d022103f5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 24773560536010099 (0x58036c0b920d73)
        -1,
        -1,
        -1,
        -1,
        15, // 20550830265273234 (0x4902df09cd0b92)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 2358876100028428651 (0x20bc6950ab5a716b)
        34, // 281777386059866976 (0x3e9130a29d62360)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 22802969398480055 (0x51032e0ad20cb7)
        39, // 2266548850155024260 (0x1f74662ba78f6f84)
        -1,
        -1,
        -1,
        4, // 314149374985709332 (0x45c15312e6f2714)
        -1,
        13, // 303171296833185530 (0x43514b02dd626fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 22521429993458792 (0x50031f0a980c68)
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_irc_hash_sdb, dataset=irc, type=hash, hash=hash_sdb
void check_irc_hash_sdb() {
    assert(lookup_irc_hash_sdb("GRPH") == 42);
    assert(lookup_irc_hash_sdb("RESTART") == 20);
    assert(lookup_irc_hash_sdb("USER") == 5);
    assert(lookup_irc_hash_sdb("REHASH") == 33);
    assert(lookup_irc_hash_sdb("STATS") == 18);
    assert(lookup_irc_hash_sdb("LUSERS") == 40);
    assert(lookup_irc_hash_sdb("TOPIC") == 8);
    assert(lookup_irc_hash_sdb("MOTD") == 44);
    assert(lookup_irc_hash_sdb("LIST") == 7);
    assert(lookup_irc_hash_sdb("WHO") == 3);
    assert(lookup_irc_hash_sdb("CHANNEL") == 10);
    assert(lookup_irc_hash_sdb("OPER") == 29);
    assert(lookup_irc_hash_sdb("TRACE") == 37);
    assert(lookup_irc_hash_sdb("SUMMON") == 17);
    assert(lookup_irc_hash_sdb("WHOREPLY") == 21);
    assert(lookup_irc_hash_sdb("INVITE") == 9);
    assert(lookup_irc_hash_sdb("VERSION") == 11);
    assert(lookup_irc_hash_sdb("HELP") == 22);
    assert(lookup_irc_hash_sdb("AWAY") == 24);
    assert(lookup_irc_hash_sdb("KILL") == 14);
    assert(lookup_irc_hash_sdb("LINREPLY") == 38);
    assert(lookup_irc_hash_sdb("CONNECT") == 26);
    assert(lookup_irc_hash_sdb("PASS") == 30);
    assert(lookup_irc_hash_sdb("PING") == 27);
    assert(lookup_irc_hash_sdb("VOICE") == 41);
    assert(lookup_irc_hash_sdb("ERROR") == 23);
    assert(lookup_irc_hash_sdb("DIE") == 25);
    assert(lookup_irc_hash_sdb("WALL") == 31);
    assert(lookup_irc_hash_sdb("NAMREPLY") == 35);
    assert(lookup_irc_hash_sdb("PRIVMSG") == 2);
    assert(lookup_irc_hash_sdb("ADMIN") == 36);
    assert(lookup_irc_hash_sdb("TIME") == 32);
    assert(lookup_irc_hash_sdb("USERS") == 19);
    assert(lookup_irc_hash_sdb("NICK") == 0);
    assert(lookup_irc_hash_sdb("LINKS") == 16);
    assert(lookup_irc_hash_sdb("MSG") == 1);
    assert(lookup_irc_hash_sdb("XTRA") == 43);
    assert(lookup_irc_hash_sdb("INFO") == 15);
    assert(lookup_irc_hash_sdb("SERVER") == 6);
    assert(lookup_irc_hash_sdb("NAMES") == 34);
    assert(lookup_irc_hash_sdb("QUIT") == 12);
    assert(lookup_irc_hash_sdb("NOTICE") == 39);
    assert(lookup_irc_hash_sdb("WHOIS") == 4);
    assert(lookup_irc_hash_sdb("SQUIT") == 13);
    assert(lookup_irc_hash_sdb("PONG") == 28);
}
