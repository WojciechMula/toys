
//lookup: name=lookup_modula3_hash1, dataset=modula3, type=hash, hash=hash1
int lookup_modula3_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 97) * 2;
    static constexpr const std::string_view lookup[194] = {
        "",
        "",
        "NOT", // 486 (0x1e6)
        "",
        "",
        "",
        "DO", // 294 (0x126)
        "MODULE", // 876 (0x36c)
        "WHILE", // 780 (0x30c)
        "",
        "",
        "",
        "FROM", // 588 (0x24c)
        "",
        "OF", // 298 (0x12a)
        "",
        "OBJECT", // 978 (0x3d2)
        "",
        "",
        "",
        "READONLY", // 1368 (0x558)
        "",
        "AND", // 399 (0x18f)
        "IN", // 302 (0x12e)
        "",
        "",
        "",
        "",
        "BITS", // 596 (0x254)
        "",
        "",
        "",
        "ELSIF", // 695 (0x2b7)
        "SET", // 501 (0x1f5)
        "INTERFACE", // 1278 (0x4fe)
        "",
        "",
        "",
        "BY", // 310 (0x136)
        "VAR", // 504 (0x1f8)
        "RAISES", // 990 (0x3de)
        "",
        "",
        "",
        "LOCK", // 604 (0x25c)
        "",
        "END", // 411 (0x19b)
        "",
        "",
        "",
        "",
        "",
        "REPEAT", // 996 (0x3e4)
        "",
        "RECORD", // 900 (0x384)
        "",
        "",
        "",
        "UNTIL", // 805 (0x325)
        "",
        "EXIT", // 612 (0x264)
        "TYPE", // 612 (0x264)
        "OR", // 322 (0x142)
        "",
        "",
        "",
        "",
        "",
        "TRY", // 519 (0x207)
        "",
        "TO", // 326 (0x146)
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
        "BEGIN", // 720 (0x2d0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXCEPT", // 918 (0x396)
        "",
        "FINALLY", // 1113 (0x459)
        "",
        "MOD", // 435 (0x1b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UNSAFE", // 924 (0x39c)
        "",
        "",
        "",
        "METHODS", // 1120 (0x460)
        "",
        "WITH", // 636 (0x27c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CASE", // 544 (0x220)
        "",
        "TYPECASE", // 1224 (0x4c8)
        "UNTRACED", // 1224 (0x4c8)
        "",
        "",
        "EXCEPTION", // 1323 (0x52b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "THEN", // 648 (0x288)
        "",
        "ELSE", // 552 (0x228)
        "",
        "FOR", // 456 (0x1c8)
        "REF", // 456 (0x1c8)
        "IMPORT", // 942 (0x3ae)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DIV", // 462 (0x1ce)
        "",
        "",
        "",
        "CONST", // 755 (0x2f3)
        "INLINE", // 852 (0x354)
        "",
        "",
        "",
        "",
        "",
        "",
        "PROCEDURE", // 1341 (0x53d)
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
        "RETURN", // 960 (0x3c0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 770 (0x302)
        "",
        "IF", // 286 (0x11e)
        "",
        "",
        "",
        "EXPORTS", // 1064 (0x428)
        "",
        "EVAL", // 580 (0x244)
        "",
        "VALUE", // 775 (0x307)
        "",
    };
    static constexpr const int values[194] = {
        -1,
        -1,
        29, // 486 (0x1e6)
        -1,
        -1,
        -1,
        8, // 294 (0x126)
        28, // 876 (0x36c)
        51, // 780 (0x30c)
        -1,
        -1,
        -1,
        19, // 588 (0x24c)
        -1,
        31, // 298 (0x12a)
        -1,
        30, // 978 (0x3d2)
        -1,
        -1,
        -1,
        35, // 1368 (0x558)
        -1,
        0, // 399 (0x18f)
        23, // 302 (0x12e)
        -1,
        -1,
        -1,
        -1,
        3, // 596 (0x254)
        -1,
        -1,
        -1,
        10, // 695 (0x2b7)
        40, // 501 (0x1f5)
        22, // 1278 (0x4fe)
        -1,
        -1,
        -1,
        4, // 310 (0x136)
        50, // 504 (0x1f8)
        34, // 990 (0x3de)
        -1,
        -1,
        -1,
        25, // 604 (0x25c)
        -1,
        11, // 411 (0x19b)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 996 (0x3e4)
        -1,
        36, // 900 (0x384)
        -1,
        -1,
        -1,
        47, // 805 (0x325)
        -1,
        15, // 612 (0x264)
        44, // 612 (0x264)
        32, // 322 (0x142)
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 519 (0x207)
        -1,
        42, // 326 (0x146)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 720 (0x2d0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 918 (0x396)
        -1,
        17, // 1113 (0x459)
        -1,
        27, // 435 (0x1b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 924 (0x39c)
        -1,
        -1,
        -1,
        26, // 1120 (0x460)
        -1,
        52, // 636 (0x27c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 544 (0x220)
        -1,
        45, // 1224 (0x4c8)
        48, // 1224 (0x4c8)
        -1,
        -1,
        14, // 1323 (0x52b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 648 (0x288)
        -1,
        9, // 552 (0x228)
        -1,
        18, // 456 (0x1c8)
        37, // 456 (0x1c8)
        21, // 942 (0x3ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 462 (0x1ce)
        -1,
        -1,
        -1,
        6, // 755 (0x2f3)
        24, // 852 (0x354)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 1341 (0x53d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 960 (0x3c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 770 (0x302)
        -1,
        20, // 286 (0x11e)
        -1,
        -1,
        -1,
        16, // 1064 (0x428)
        -1,
        12, // 580 (0x244)
        -1,
        49, // 775 (0x307)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula3_hash1, dataset=modula3, type=hash, hash=hash1
void check_modula3_hash1() {
    assert(lookup_modula3_hash1("NOT") == 29);
    assert(lookup_modula3_hash1("DO") == 8);
    assert(lookup_modula3_hash1("MODULE") == 28);
    assert(lookup_modula3_hash1("WHILE") == 51);
    assert(lookup_modula3_hash1("FROM") == 19);
    assert(lookup_modula3_hash1("OF") == 31);
    assert(lookup_modula3_hash1("OBJECT") == 30);
    assert(lookup_modula3_hash1("READONLY") == 35);
    assert(lookup_modula3_hash1("AND") == 0);
    assert(lookup_modula3_hash1("IN") == 23);
    assert(lookup_modula3_hash1("BITS") == 3);
    assert(lookup_modula3_hash1("ELSIF") == 10);
    assert(lookup_modula3_hash1("SET") == 40);
    assert(lookup_modula3_hash1("INTERFACE") == 22);
    assert(lookup_modula3_hash1("BY") == 4);
    assert(lookup_modula3_hash1("VAR") == 50);
    assert(lookup_modula3_hash1("RAISES") == 34);
    assert(lookup_modula3_hash1("LOCK") == 25);
    assert(lookup_modula3_hash1("END") == 11);
    assert(lookup_modula3_hash1("REPEAT") == 38);
    assert(lookup_modula3_hash1("RECORD") == 36);
    assert(lookup_modula3_hash1("UNTIL") == 47);
    assert(lookup_modula3_hash1("EXIT") == 15);
    assert(lookup_modula3_hash1("TYPE") == 44);
    assert(lookup_modula3_hash1("OR") == 32);
    assert(lookup_modula3_hash1("TRY") == 43);
    assert(lookup_modula3_hash1("TO") == 42);
    assert(lookup_modula3_hash1("BEGIN") == 2);
    assert(lookup_modula3_hash1("EXCEPT") == 13);
    assert(lookup_modula3_hash1("FINALLY") == 17);
    assert(lookup_modula3_hash1("MOD") == 27);
    assert(lookup_modula3_hash1("UNSAFE") == 46);
    assert(lookup_modula3_hash1("METHODS") == 26);
    assert(lookup_modula3_hash1("WITH") == 52);
    assert(lookup_modula3_hash1("CASE") == 5);
    assert(lookup_modula3_hash1("TYPECASE") == 45);
    assert(lookup_modula3_hash1("UNTRACED") == 48);
    assert(lookup_modula3_hash1("EXCEPTION") == 14);
    assert(lookup_modula3_hash1("THEN") == 41);
    assert(lookup_modula3_hash1("ELSE") == 9);
    assert(lookup_modula3_hash1("FOR") == 18);
    assert(lookup_modula3_hash1("REF") == 37);
    assert(lookup_modula3_hash1("IMPORT") == 21);
    assert(lookup_modula3_hash1("DIV") == 7);
    assert(lookup_modula3_hash1("CONST") == 6);
    assert(lookup_modula3_hash1("INLINE") == 24);
    assert(lookup_modula3_hash1("PROCEDURE") == 33);
    assert(lookup_modula3_hash1("RETURN") == 39);
    assert(lookup_modula3_hash1("ARRAY") == 1);
    assert(lookup_modula3_hash1("IF") == 20);
    assert(lookup_modula3_hash1("EXPORTS") == 16);
    assert(lookup_modula3_hash1("EVAL") == 12);
    assert(lookup_modula3_hash1("VALUE") == 49);
}

//lookup: name=lookup_modula3_hash2, dataset=modula3, type=hash, hash=hash2
int lookup_modula3_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 111) * 2;
    static constexpr const std::string_view lookup[222] = {
        "",
        "",
        "",
        "",
        "IF", // 5108 (0x13f4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NOT", // 6555 (0x199b)
        "",
        "THEN", // 6556 (0x199c)
        "",
        "",
        "",
        "FINALLY", // 6225 (0x1851)
        "",
        "",
        "",
        "",
        "",
        "REPEAT", // 6894 (0x1aee)
        "WHILE", // 6006 (0x1776)
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 5788 (0x169c)
        "UNTRACED", // 5788 (0x169c)
        "",
        "",
        "",
        "",
        "UNTIL", // 6457 (0x1939)
        "",
        "EXIT", // 5792 (0x16a0)
        "TYPE", // 5792 (0x16a0)
        "",
        "",
        "EXCEPT", // 5794 (0x16a2)
        "MOD", // 5239 (0x1477)
        "EVAL", // 5240 (0x1478)
        "",
        "",
        "",
        "IMPORT", // 6130 (0x17f2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RAISES", // 6800 (0x1a90)
        "",
        "",
        "",
        "IN", // 5692 (0x163c)
        "",
        "RECORD", // 5582 (0x15ce)
        "TYPECASE", // 5804 (0x16ac)
        "END", // 4695 (0x1257)
        "INTERFACE", // 5028 (0x13a4)
        "",
        "",
        "BITS", // 5474 (0x1562)
        "LOCK", // 5696 (0x1640)
        "",
        "",
        "",
        "",
        "OR", // 6476 (0x194c)
        "",
        "BEGIN", // 5145 (0x1419)
        "",
        "INLINE", // 5035 (0x13ab)
        "",
        "",
        "",
        "TRY", // 7479 (0x1d37)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DO", // 5374 (0x14fe)
        "",
        "",
        "",
        "VALUE", // 5931 (0x172b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WITH", // 6268 (0x187c)
        "",
        "",
        "",
        "ELSIF", // 4827 (0x12db)
        "",
        "",
        "",
        "",
        "",
        "METHODS", // 6384 (0x18f0)
        "",
        "FROM", // 5386 (0x150a)
        "",
        "EXPORTS", // 5720 (0x1658)
        "",
        "",
        "",
        "",
        "",
        "VAR", // 7055 (0x1b8f)
        "",
        "EXCEPTION", // 5391 (0x150f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RETURN", // 6394 (0x18fa)
        "",
        "CASE", // 4619 (0x120b)
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
        "CONST", // 5625 (0x15f9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DIV", // 5851 (0x16db)
        "",
        "",
        "",
        "",
        "",
        "FOR", // 5743 (0x166f)
        "REF", // 5743 (0x166f)
        "",
        "",
        "",
        "",
        "OBJECT", // 6634 (0x19ea)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OF", // 5528 (0x1598)
        "TO", // 6638 (0x19ee)
        "PROCEDURE", // 5529 (0x1599)
        "",
        "READONLY", // 7306 (0x1c8a)
        "",
        "",
        "",
        "SET", // 6975 (0x1b3f)
        "",
        "AND", // 4423 (0x1147)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UNSAFE", // 5871 (0x16ef)
        "",
        "BY", // 5872 (0x16f0)
        "",
        "",
        "",
        "MODULE", // 5319 (0x14c7)
        "",
        "ELSE", // 4765 (0x129d)
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
    };
    static constexpr const int values[222] = {
        -1,
        -1,
        -1,
        -1,
        20, // 5108 (0x13f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 6555 (0x199b)
        -1,
        41, // 6556 (0x199c)
        -1,
        -1,
        -1,
        17, // 6225 (0x1851)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 6894 (0x1aee)
        51, // 6006 (0x1776)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 5788 (0x169c)
        48, // 5788 (0x169c)
        -1,
        -1,
        -1,
        -1,
        47, // 6457 (0x1939)
        -1,
        15, // 5792 (0x16a0)
        44, // 5792 (0x16a0)
        -1,
        -1,
        13, // 5794 (0x16a2)
        27, // 5239 (0x1477)
        12, // 5240 (0x1478)
        -1,
        -1,
        -1,
        21, // 6130 (0x17f2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 6800 (0x1a90)
        -1,
        -1,
        -1,
        23, // 5692 (0x163c)
        -1,
        36, // 5582 (0x15ce)
        45, // 5804 (0x16ac)
        11, // 4695 (0x1257)
        22, // 5028 (0x13a4)
        -1,
        -1,
        3, // 5474 (0x1562)
        25, // 5696 (0x1640)
        -1,
        -1,
        -1,
        -1,
        32, // 6476 (0x194c)
        -1,
        2, // 5145 (0x1419)
        -1,
        24, // 5035 (0x13ab)
        -1,
        -1,
        -1,
        43, // 7479 (0x1d37)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 5374 (0x14fe)
        -1,
        -1,
        -1,
        49, // 5931 (0x172b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 6268 (0x187c)
        -1,
        -1,
        -1,
        10, // 4827 (0x12db)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 6384 (0x18f0)
        -1,
        19, // 5386 (0x150a)
        -1,
        16, // 5720 (0x1658)
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 7055 (0x1b8f)
        -1,
        14, // 5391 (0x150f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 6394 (0x18fa)
        -1,
        5, // 4619 (0x120b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 5625 (0x15f9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 5851 (0x16db)
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 5743 (0x166f)
        37, // 5743 (0x166f)
        -1,
        -1,
        -1,
        -1,
        30, // 6634 (0x19ea)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 5528 (0x1598)
        42, // 6638 (0x19ee)
        33, // 5529 (0x1599)
        -1,
        35, // 7306 (0x1c8a)
        -1,
        -1,
        -1,
        40, // 6975 (0x1b3f)
        -1,
        0, // 4423 (0x1147)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 5871 (0x16ef)
        -1,
        4, // 5872 (0x16f0)
        -1,
        -1,
        -1,
        28, // 5319 (0x14c7)
        -1,
        9, // 4765 (0x129d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
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
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula3_hash2, dataset=modula3, type=hash, hash=hash2
void check_modula3_hash2() {
    assert(lookup_modula3_hash2("IF") == 20);
    assert(lookup_modula3_hash2("NOT") == 29);
    assert(lookup_modula3_hash2("THEN") == 41);
    assert(lookup_modula3_hash2("FINALLY") == 17);
    assert(lookup_modula3_hash2("REPEAT") == 38);
    assert(lookup_modula3_hash2("WHILE") == 51);
    assert(lookup_modula3_hash2("ARRAY") == 1);
    assert(lookup_modula3_hash2("UNTRACED") == 48);
    assert(lookup_modula3_hash2("UNTIL") == 47);
    assert(lookup_modula3_hash2("EXIT") == 15);
    assert(lookup_modula3_hash2("TYPE") == 44);
    assert(lookup_modula3_hash2("EXCEPT") == 13);
    assert(lookup_modula3_hash2("MOD") == 27);
    assert(lookup_modula3_hash2("EVAL") == 12);
    assert(lookup_modula3_hash2("IMPORT") == 21);
    assert(lookup_modula3_hash2("RAISES") == 34);
    assert(lookup_modula3_hash2("IN") == 23);
    assert(lookup_modula3_hash2("RECORD") == 36);
    assert(lookup_modula3_hash2("TYPECASE") == 45);
    assert(lookup_modula3_hash2("END") == 11);
    assert(lookup_modula3_hash2("INTERFACE") == 22);
    assert(lookup_modula3_hash2("BITS") == 3);
    assert(lookup_modula3_hash2("LOCK") == 25);
    assert(lookup_modula3_hash2("OR") == 32);
    assert(lookup_modula3_hash2("BEGIN") == 2);
    assert(lookup_modula3_hash2("INLINE") == 24);
    assert(lookup_modula3_hash2("TRY") == 43);
    assert(lookup_modula3_hash2("DO") == 8);
    assert(lookup_modula3_hash2("VALUE") == 49);
    assert(lookup_modula3_hash2("WITH") == 52);
    assert(lookup_modula3_hash2("ELSIF") == 10);
    assert(lookup_modula3_hash2("METHODS") == 26);
    assert(lookup_modula3_hash2("FROM") == 19);
    assert(lookup_modula3_hash2("EXPORTS") == 16);
    assert(lookup_modula3_hash2("VAR") == 50);
    assert(lookup_modula3_hash2("EXCEPTION") == 14);
    assert(lookup_modula3_hash2("RETURN") == 39);
    assert(lookup_modula3_hash2("CASE") == 5);
    assert(lookup_modula3_hash2("CONST") == 6);
    assert(lookup_modula3_hash2("DIV") == 7);
    assert(lookup_modula3_hash2("FOR") == 18);
    assert(lookup_modula3_hash2("REF") == 37);
    assert(lookup_modula3_hash2("OBJECT") == 30);
    assert(lookup_modula3_hash2("OF") == 31);
    assert(lookup_modula3_hash2("TO") == 42);
    assert(lookup_modula3_hash2("PROCEDURE") == 33);
    assert(lookup_modula3_hash2("READONLY") == 35);
    assert(lookup_modula3_hash2("SET") == 40);
    assert(lookup_modula3_hash2("AND") == 0);
    assert(lookup_modula3_hash2("UNSAFE") == 46);
    assert(lookup_modula3_hash2("BY") == 4);
    assert(lookup_modula3_hash2("MODULE") == 28);
    assert(lookup_modula3_hash2("ELSE") == 9);
}

//lookup: name=lookup_modula3_hash3, dataset=modula3, type=hash, hash=hash3
int lookup_modula3_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 351) * 1;
    static constexpr const std::string_view lookup[351] = {
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
        "METHODS", // 21775 (0x550f)
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
        "END", // 18629 (0x48c5)
        "",
        "UNSAFE", // 23545 (0x5bf9)
        "",
        "TRY", // 22494 (0x57de)
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
        "AND", // 17605 (0x44c5)
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
        "IF", // 19374 (0x4bae)
        "BY", // 17620 (0x44d4)
        "",
        "",
        "",
        "",
        "",
        "",
        "CONST", // 18680 (0x48f8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IN", // 19390 (0x4bbe)
        "",
        "MODULE", // 21498 (0x53fa)
        "",
        "",
        "EXPORTS", // 19746 (0x4d22)
        "",
        "",
        "",
        "",
        "TO", // 22208 (0x56c0)
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
        "SET", // 22220 (0x56cc)
        "",
        "",
        "",
        "",
        "",
        "UNTIL", // 23279 (0x5aef)
        "",
        "INLINE", // 20473 (0x4ff9)
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
        "CASE", // 18378 (0x47ca)
        "",
        "",
        "IMPORT", // 20487 (0x5007)
        "",
        "",
        "",
        "",
        "DIV", // 18386 (0x47d2)
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
        "BEGIN", // 18408 (0x47e8)
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
        "VAR", // 22982 (0x59c6)
        "READONLY", // 23334 (0x5b26)
        "EXCEPT", // 19474 (0x4c12)
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
        "REF", // 21950 (0x55be)
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
        "OF", // 20910 (0x51ae)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DO", // 18112 (0x46c0)
        "",
        "",
        "",
        "",
        "",
        "FROM", // 19171 (0x4ae3)
        "",
        "",
        "",
        "ELSIF", // 19175 (0x4ae7)
        "UNTRACED", // 24090 (0x5e1a)
        "",
        "",
        "OR", // 20934 (0x51c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "INTERFACE", // 21292 (0x532c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NOT", // 20950 (0x51d6)
        "",
        "BITS", // 18144 (0x46e0)
        "",
        "",
        "",
        "",
        "",
        "",
        "OBJECT", // 22012 (0x55fc)
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
        "WHILE", // 23778 (0x5ce2)
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
        "PROCEDURE", // 23088 (0x5a30)
        "",
        "ARRAY", // 18176 (0x4700)
        "",
        "",
        "",
        "",
        "EXCEPTION", // 20287 (0x4f3f)
        "",
        "THEN", // 22746 (0x58da)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TYPE", // 22754 (0x58e2)
        "",
        "",
        "",
        "",
        "",
        "",
        "FOR", // 18900 (0x49d4)
        "ELSE", // 18901 (0x49d5)
        "",
        "",
        "",
        "",
        "RECORD", // 22767 (0x58ef)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RETURN", // 22777 (0x58f9)
        "RAISES", // 22778 (0x58fa)
        "EVAL", // 18918 (0x49e6)
        "",
        "",
        "",
        "REPEAT", // 22783 (0x58ff)
        "MOD", // 20678 (0x50c6)
        "",
        "",
        "",
        "",
        "EXIT", // 18928 (0x49f0)
        "",
        "",
        "",
        "TYPECASE", // 23846 (0x5d26)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FINALLY", // 19993 (0x4e19)
        "",
        "",
        "",
        "",
        "",
        "WITH", // 23509 (0x5bd5)
        "LOCK", // 20702 (0x50de)
        "",
        "",
        "",
        "",
        "VALUE", // 23515 (0x5bdb)
        "",
    };
    static constexpr const int values[351] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 21775 (0x550f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 18629 (0x48c5)
        -1,
        46, // 23545 (0x5bf9)
        -1,
        43, // 22494 (0x57de)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 17605 (0x44c5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 19374 (0x4bae)
        4, // 17620 (0x44d4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 18680 (0x48f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 19390 (0x4bbe)
        -1,
        28, // 21498 (0x53fa)
        -1,
        -1,
        16, // 19746 (0x4d22)
        -1,
        -1,
        -1,
        -1,
        42, // 22208 (0x56c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 22220 (0x56cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 23279 (0x5aef)
        -1,
        24, // 20473 (0x4ff9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 18378 (0x47ca)
        -1,
        -1,
        21, // 20487 (0x5007)
        -1,
        -1,
        -1,
        -1,
        7, // 18386 (0x47d2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 18408 (0x47e8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 22982 (0x59c6)
        35, // 23334 (0x5b26)
        13, // 19474 (0x4c12)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 21950 (0x55be)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 20910 (0x51ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 18112 (0x46c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 19171 (0x4ae3)
        -1,
        -1,
        -1,
        10, // 19175 (0x4ae7)
        48, // 24090 (0x5e1a)
        -1,
        -1,
        32, // 20934 (0x51c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 21292 (0x532c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 20950 (0x51d6)
        -1,
        3, // 18144 (0x46e0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 22012 (0x55fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 23778 (0x5ce2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 23088 (0x5a30)
        -1,
        1, // 18176 (0x4700)
        -1,
        -1,
        -1,
        -1,
        14, // 20287 (0x4f3f)
        -1,
        41, // 22746 (0x58da)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 22754 (0x58e2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 18900 (0x49d4)
        9, // 18901 (0x49d5)
        -1,
        -1,
        -1,
        -1,
        36, // 22767 (0x58ef)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 22777 (0x58f9)
        34, // 22778 (0x58fa)
        12, // 18918 (0x49e6)
        -1,
        -1,
        -1,
        38, // 22783 (0x58ff)
        27, // 20678 (0x50c6)
        -1,
        -1,
        -1,
        -1,
        15, // 18928 (0x49f0)
        -1,
        -1,
        -1,
        45, // 23846 (0x5d26)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 19993 (0x4e19)
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 23509 (0x5bd5)
        25, // 20702 (0x50de)
        -1,
        -1,
        -1,
        -1,
        49, // 23515 (0x5bdb)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula3_hash3, dataset=modula3, type=hash, hash=hash3
void check_modula3_hash3() {
    assert(lookup_modula3_hash3("METHODS") == 26);
    assert(lookup_modula3_hash3("END") == 11);
    assert(lookup_modula3_hash3("UNSAFE") == 46);
    assert(lookup_modula3_hash3("TRY") == 43);
    assert(lookup_modula3_hash3("AND") == 0);
    assert(lookup_modula3_hash3("IF") == 20);
    assert(lookup_modula3_hash3("BY") == 4);
    assert(lookup_modula3_hash3("CONST") == 6);
    assert(lookup_modula3_hash3("IN") == 23);
    assert(lookup_modula3_hash3("MODULE") == 28);
    assert(lookup_modula3_hash3("EXPORTS") == 16);
    assert(lookup_modula3_hash3("TO") == 42);
    assert(lookup_modula3_hash3("SET") == 40);
    assert(lookup_modula3_hash3("UNTIL") == 47);
    assert(lookup_modula3_hash3("INLINE") == 24);
    assert(lookup_modula3_hash3("CASE") == 5);
    assert(lookup_modula3_hash3("IMPORT") == 21);
    assert(lookup_modula3_hash3("DIV") == 7);
    assert(lookup_modula3_hash3("BEGIN") == 2);
    assert(lookup_modula3_hash3("VAR") == 50);
    assert(lookup_modula3_hash3("READONLY") == 35);
    assert(lookup_modula3_hash3("EXCEPT") == 13);
    assert(lookup_modula3_hash3("REF") == 37);
    assert(lookup_modula3_hash3("OF") == 31);
    assert(lookup_modula3_hash3("DO") == 8);
    assert(lookup_modula3_hash3("FROM") == 19);
    assert(lookup_modula3_hash3("ELSIF") == 10);
    assert(lookup_modula3_hash3("UNTRACED") == 48);
    assert(lookup_modula3_hash3("OR") == 32);
    assert(lookup_modula3_hash3("INTERFACE") == 22);
    assert(lookup_modula3_hash3("NOT") == 29);
    assert(lookup_modula3_hash3("BITS") == 3);
    assert(lookup_modula3_hash3("OBJECT") == 30);
    assert(lookup_modula3_hash3("WHILE") == 51);
    assert(lookup_modula3_hash3("PROCEDURE") == 33);
    assert(lookup_modula3_hash3("ARRAY") == 1);
    assert(lookup_modula3_hash3("EXCEPTION") == 14);
    assert(lookup_modula3_hash3("THEN") == 41);
    assert(lookup_modula3_hash3("TYPE") == 44);
    assert(lookup_modula3_hash3("FOR") == 18);
    assert(lookup_modula3_hash3("ELSE") == 9);
    assert(lookup_modula3_hash3("RECORD") == 36);
    assert(lookup_modula3_hash3("RETURN") == 39);
    assert(lookup_modula3_hash3("RAISES") == 34);
    assert(lookup_modula3_hash3("EVAL") == 12);
    assert(lookup_modula3_hash3("REPEAT") == 38);
    assert(lookup_modula3_hash3("MOD") == 27);
    assert(lookup_modula3_hash3("EXIT") == 15);
    assert(lookup_modula3_hash3("TYPECASE") == 45);
    assert(lookup_modula3_hash3("FINALLY") == 17);
    assert(lookup_modula3_hash3("WITH") == 52);
    assert(lookup_modula3_hash3("LOCK") == 25);
    assert(lookup_modula3_hash3("VALUE") == 49);
}

//lookup: name=lookup_modula3_hash_sum0, dataset=modula3, type=hash, hash=hash_sum0
int lookup_modula3_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 87) * 2;
    static constexpr const std::string_view lookup[174] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OBJECT", // 439 (0x1b7)
        "",
        "FINALLY", // 527 (0x20f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BEGIN", // 357 (0x165)
        "",
        "METHODS", // 532 (0x214)
        "",
        "",
        "",
        "INLINE", // 447 (0x1bf)
        "RECORD", // 447 (0x1bf)
        "",
        "",
        "REPEAT", // 449 (0x1c1)
        "",
        "UNSAFE", // 450 (0x1c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MODULE", // 454 (0x1c6)
        "",
        "RAISES", // 455 (0x1c7)
        "",
        "",
        "",
        "EXCEPT", // 457 (0x1c9)
        "",
        "CASE", // 284 (0x11c)
        "ELSIF", // 371 (0x173)
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
        "WHILE", // 377 (0x179)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VALUE", // 381 (0x17d)
        "",
        "",
        "",
        "ARRAY", // 383 (0x17f)
        "EVAL", // 296 (0x128)
        "ELSE", // 297 (0x129)
        "LOCK", // 297 (0x129)
        "AND", // 211 (0xd3)
        "",
        "",
        "",
        "",
        "",
        "IMPORT", // 475 (0x1db)
        "",
        "END", // 215 (0xd7)
        "",
        "THEN", // 303 (0x12f)
        "",
        "CONST", // 391 (0x187)
        "EXPORTS", // 565 (0x235)
        "",
        "",
        "BITS", // 306 (0x132)
        "RETURN", // 480 (0x1e0)
        "",
        "",
        "FROM", // 308 (0x134)
        "REF", // 221 (0xdd)
        "INTERFACE", // 657 (0x291)
        "UNTIL", // 396 (0x18c)
        "",
        "",
        "MOD", // 224 (0xe0)
        "",
        "",
        "",
        "",
        "",
        "DIV", // 227 (0xe3)
        "EXIT", // 314 (0x13a)
        "",
        "",
        "WITH", // 316 (0x13c)
        "",
        "IF", // 143 (0x8f)
        "",
        "FOR", // 231 (0xe7)
        "",
        "",
        "",
        "VAR", // 233 (0xe9)
        "",
        "DO", // 147 (0x93)
        "",
        "TYPE", // 322 (0x142)
        "",
        "OF", // 149 (0x95)
        "SET", // 236 (0xec)
        "",
        "",
        "IN", // 151 (0x97)
        "",
        "",
        "",
        "",
        "",
        "NOT", // 241 (0xf1)
        "",
        "BY", // 155 (0x9b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PROCEDURE", // 681 (0x2a9)
        "",
        "",
        "",
        "OR", // 161 (0xa1)
        "",
        "",
        "",
        "TO", // 163 (0xa3)
        "UNTRACED", // 598 (0x256)
        "",
        "",
        "EXCEPTION", // 687 (0x2af)
        "",
        "",
        "",
        "",
        "",
        "TRY", // 255 (0xff)
        "",
        "",
        "",
        "",
        "",
        "READONLY", // 606 (0x25e)
        "TYPECASE", // 606 (0x25e)
        "",
        "",
        "",
        "",
    };
    static constexpr const int values[174] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 439 (0x1b7)
        -1,
        17, // 527 (0x20f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 357 (0x165)
        -1,
        26, // 532 (0x214)
        -1,
        -1,
        -1,
        24, // 447 (0x1bf)
        36, // 447 (0x1bf)
        -1,
        -1,
        38, // 449 (0x1c1)
        -1,
        46, // 450 (0x1c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 454 (0x1c6)
        -1,
        34, // 455 (0x1c7)
        -1,
        -1,
        -1,
        13, // 457 (0x1c9)
        -1,
        5, // 284 (0x11c)
        10, // 371 (0x173)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 377 (0x179)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 381 (0x17d)
        -1,
        -1,
        -1,
        1, // 383 (0x17f)
        12, // 296 (0x128)
        9, // 297 (0x129)
        25, // 297 (0x129)
        0, // 211 (0xd3)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 475 (0x1db)
        -1,
        11, // 215 (0xd7)
        -1,
        41, // 303 (0x12f)
        -1,
        6, // 391 (0x187)
        16, // 565 (0x235)
        -1,
        -1,
        3, // 306 (0x132)
        39, // 480 (0x1e0)
        -1,
        -1,
        19, // 308 (0x134)
        37, // 221 (0xdd)
        22, // 657 (0x291)
        47, // 396 (0x18c)
        -1,
        -1,
        27, // 224 (0xe0)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 227 (0xe3)
        15, // 314 (0x13a)
        -1,
        -1,
        52, // 316 (0x13c)
        -1,
        20, // 143 (0x8f)
        -1,
        18, // 231 (0xe7)
        -1,
        -1,
        -1,
        50, // 233 (0xe9)
        -1,
        8, // 147 (0x93)
        -1,
        44, // 322 (0x142)
        -1,
        31, // 149 (0x95)
        40, // 236 (0xec)
        -1,
        -1,
        23, // 151 (0x97)
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 241 (0xf1)
        -1,
        4, // 155 (0x9b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 681 (0x2a9)
        -1,
        -1,
        -1,
        32, // 161 (0xa1)
        -1,
        -1,
        -1,
        42, // 163 (0xa3)
        48, // 598 (0x256)
        -1,
        -1,
        14, // 687 (0x2af)
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 255 (0xff)
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 606 (0x25e)
        45, // 606 (0x25e)
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

//check: name=check_modula3_hash_sum0, dataset=modula3, type=hash, hash=hash_sum0
void check_modula3_hash_sum0() {
    assert(lookup_modula3_hash_sum0("OBJECT") == 30);
    assert(lookup_modula3_hash_sum0("FINALLY") == 17);
    assert(lookup_modula3_hash_sum0("BEGIN") == 2);
    assert(lookup_modula3_hash_sum0("METHODS") == 26);
    assert(lookup_modula3_hash_sum0("INLINE") == 24);
    assert(lookup_modula3_hash_sum0("RECORD") == 36);
    assert(lookup_modula3_hash_sum0("REPEAT") == 38);
    assert(lookup_modula3_hash_sum0("UNSAFE") == 46);
    assert(lookup_modula3_hash_sum0("MODULE") == 28);
    assert(lookup_modula3_hash_sum0("RAISES") == 34);
    assert(lookup_modula3_hash_sum0("EXCEPT") == 13);
    assert(lookup_modula3_hash_sum0("CASE") == 5);
    assert(lookup_modula3_hash_sum0("ELSIF") == 10);
    assert(lookup_modula3_hash_sum0("WHILE") == 51);
    assert(lookup_modula3_hash_sum0("VALUE") == 49);
    assert(lookup_modula3_hash_sum0("ARRAY") == 1);
    assert(lookup_modula3_hash_sum0("EVAL") == 12);
    assert(lookup_modula3_hash_sum0("ELSE") == 9);
    assert(lookup_modula3_hash_sum0("LOCK") == 25);
    assert(lookup_modula3_hash_sum0("AND") == 0);
    assert(lookup_modula3_hash_sum0("IMPORT") == 21);
    assert(lookup_modula3_hash_sum0("END") == 11);
    assert(lookup_modula3_hash_sum0("THEN") == 41);
    assert(lookup_modula3_hash_sum0("CONST") == 6);
    assert(lookup_modula3_hash_sum0("EXPORTS") == 16);
    assert(lookup_modula3_hash_sum0("BITS") == 3);
    assert(lookup_modula3_hash_sum0("RETURN") == 39);
    assert(lookup_modula3_hash_sum0("FROM") == 19);
    assert(lookup_modula3_hash_sum0("REF") == 37);
    assert(lookup_modula3_hash_sum0("INTERFACE") == 22);
    assert(lookup_modula3_hash_sum0("UNTIL") == 47);
    assert(lookup_modula3_hash_sum0("MOD") == 27);
    assert(lookup_modula3_hash_sum0("DIV") == 7);
    assert(lookup_modula3_hash_sum0("EXIT") == 15);
    assert(lookup_modula3_hash_sum0("WITH") == 52);
    assert(lookup_modula3_hash_sum0("IF") == 20);
    assert(lookup_modula3_hash_sum0("FOR") == 18);
    assert(lookup_modula3_hash_sum0("VAR") == 50);
    assert(lookup_modula3_hash_sum0("DO") == 8);
    assert(lookup_modula3_hash_sum0("TYPE") == 44);
    assert(lookup_modula3_hash_sum0("OF") == 31);
    assert(lookup_modula3_hash_sum0("SET") == 40);
    assert(lookup_modula3_hash_sum0("IN") == 23);
    assert(lookup_modula3_hash_sum0("NOT") == 29);
    assert(lookup_modula3_hash_sum0("BY") == 4);
    assert(lookup_modula3_hash_sum0("PROCEDURE") == 33);
    assert(lookup_modula3_hash_sum0("OR") == 32);
    assert(lookup_modula3_hash_sum0("TO") == 42);
    assert(lookup_modula3_hash_sum0("UNTRACED") == 48);
    assert(lookup_modula3_hash_sum0("EXCEPTION") == 14);
    assert(lookup_modula3_hash_sum0("TRY") == 43);
    assert(lookup_modula3_hash_sum0("READONLY") == 35);
    assert(lookup_modula3_hash_sum0("TYPECASE") == 45);
}

//lookup: name=lookup_modula3_hash_sumN, dataset=modula3, type=hash, hash=hash_sumN
int lookup_modula3_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 88) * 2;
    static constexpr const std::string_view lookup[176] = {
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
        "OBJECT", // 445 (0x1bd)
        "",
        "FINALLY", // 534 (0x216)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BEGIN", // 362 (0x16a)
        "",
        "METHODS", // 539 (0x21b)
        "",
        "",
        "",
        "INLINE", // 453 (0x1c5)
        "RECORD", // 453 (0x1c5)
        "",
        "",
        "REPEAT", // 455 (0x1c7)
        "",
        "UNSAFE", // 456 (0x1c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MODULE", // 460 (0x1cc)
        "",
        "RAISES", // 461 (0x1cd)
        "",
        "",
        "",
        "EXCEPT", // 463 (0x1cf)
        "",
        "CASE", // 288 (0x120)
        "ELSIF", // 376 (0x178)
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
        "WHILE", // 382 (0x17e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VALUE", // 386 (0x182)
        "",
        "",
        "",
        "ARRAY", // 388 (0x184)
        "EVAL", // 300 (0x12c)
        "ELSE", // 301 (0x12d)
        "LOCK", // 301 (0x12d)
        "AND", // 214 (0xd6)
        "",
        "",
        "",
        "",
        "",
        "IMPORT", // 481 (0x1e1)
        "",
        "END", // 218 (0xda)
        "",
        "THEN", // 307 (0x133)
        "",
        "CONST", // 396 (0x18c)
        "EXPORTS", // 572 (0x23c)
        "",
        "",
        "BITS", // 310 (0x136)
        "RETURN", // 486 (0x1e6)
        "",
        "",
        "FROM", // 312 (0x138)
        "REF", // 224 (0xe0)
        "UNTIL", // 401 (0x191)
        "",
        "INTERFACE", // 666 (0x29a)
        "",
        "MOD", // 227 (0xe3)
        "",
        "",
        "",
        "",
        "",
        "DIV", // 230 (0xe6)
        "EXIT", // 318 (0x13e)
        "",
        "",
        "WITH", // 320 (0x140)
        "",
        "IF", // 145 (0x91)
        "",
        "FOR", // 234 (0xea)
        "",
        "",
        "",
        "VAR", // 236 (0xec)
        "",
        "DO", // 149 (0x95)
        "",
        "TYPE", // 326 (0x146)
        "",
        "OF", // 151 (0x97)
        "SET", // 239 (0xef)
        "",
        "",
        "IN", // 153 (0x99)
        "",
        "",
        "",
        "",
        "",
        "NOT", // 244 (0xf4)
        "",
        "BY", // 157 (0x9d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PROCEDURE", // 690 (0x2b2)
        "",
        "OR", // 163 (0xa3)
        "",
        "",
        "",
        "TO", // 165 (0xa5)
        "",
        "UNTRACED", // 606 (0x25e)
        "",
        "",
        "",
        "EXCEPTION", // 696 (0x2b8)
        "",
        "",
        "",
        "TRY", // 258 (0x102)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "READONLY", // 614 (0x266)
        "TYPECASE", // 614 (0x266)
        "",
        "",
    };
    static constexpr const int values[176] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 445 (0x1bd)
        -1,
        17, // 534 (0x216)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 362 (0x16a)
        -1,
        26, // 539 (0x21b)
        -1,
        -1,
        -1,
        24, // 453 (0x1c5)
        36, // 453 (0x1c5)
        -1,
        -1,
        38, // 455 (0x1c7)
        -1,
        46, // 456 (0x1c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 460 (0x1cc)
        -1,
        34, // 461 (0x1cd)
        -1,
        -1,
        -1,
        13, // 463 (0x1cf)
        -1,
        5, // 288 (0x120)
        10, // 376 (0x178)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 382 (0x17e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 386 (0x182)
        -1,
        -1,
        -1,
        1, // 388 (0x184)
        12, // 300 (0x12c)
        9, // 301 (0x12d)
        25, // 301 (0x12d)
        0, // 214 (0xd6)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 481 (0x1e1)
        -1,
        11, // 218 (0xda)
        -1,
        41, // 307 (0x133)
        -1,
        6, // 396 (0x18c)
        16, // 572 (0x23c)
        -1,
        -1,
        3, // 310 (0x136)
        39, // 486 (0x1e6)
        -1,
        -1,
        19, // 312 (0x138)
        37, // 224 (0xe0)
        47, // 401 (0x191)
        -1,
        22, // 666 (0x29a)
        -1,
        27, // 227 (0xe3)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 230 (0xe6)
        15, // 318 (0x13e)
        -1,
        -1,
        52, // 320 (0x140)
        -1,
        20, // 145 (0x91)
        -1,
        18, // 234 (0xea)
        -1,
        -1,
        -1,
        50, // 236 (0xec)
        -1,
        8, // 149 (0x95)
        -1,
        44, // 326 (0x146)
        -1,
        31, // 151 (0x97)
        40, // 239 (0xef)
        -1,
        -1,
        23, // 153 (0x99)
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 244 (0xf4)
        -1,
        4, // 157 (0x9d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 690 (0x2b2)
        -1,
        32, // 163 (0xa3)
        -1,
        -1,
        -1,
        42, // 165 (0xa5)
        -1,
        48, // 606 (0x25e)
        -1,
        -1,
        -1,
        14, // 696 (0x2b8)
        -1,
        -1,
        -1,
        43, // 258 (0x102)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 614 (0x266)
        45, // 614 (0x266)
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

//check: name=check_modula3_hash_sumN, dataset=modula3, type=hash, hash=hash_sumN
void check_modula3_hash_sumN() {
    assert(lookup_modula3_hash_sumN("OBJECT") == 30);
    assert(lookup_modula3_hash_sumN("FINALLY") == 17);
    assert(lookup_modula3_hash_sumN("BEGIN") == 2);
    assert(lookup_modula3_hash_sumN("METHODS") == 26);
    assert(lookup_modula3_hash_sumN("INLINE") == 24);
    assert(lookup_modula3_hash_sumN("RECORD") == 36);
    assert(lookup_modula3_hash_sumN("REPEAT") == 38);
    assert(lookup_modula3_hash_sumN("UNSAFE") == 46);
    assert(lookup_modula3_hash_sumN("MODULE") == 28);
    assert(lookup_modula3_hash_sumN("RAISES") == 34);
    assert(lookup_modula3_hash_sumN("EXCEPT") == 13);
    assert(lookup_modula3_hash_sumN("CASE") == 5);
    assert(lookup_modula3_hash_sumN("ELSIF") == 10);
    assert(lookup_modula3_hash_sumN("WHILE") == 51);
    assert(lookup_modula3_hash_sumN("VALUE") == 49);
    assert(lookup_modula3_hash_sumN("ARRAY") == 1);
    assert(lookup_modula3_hash_sumN("EVAL") == 12);
    assert(lookup_modula3_hash_sumN("ELSE") == 9);
    assert(lookup_modula3_hash_sumN("LOCK") == 25);
    assert(lookup_modula3_hash_sumN("AND") == 0);
    assert(lookup_modula3_hash_sumN("IMPORT") == 21);
    assert(lookup_modula3_hash_sumN("END") == 11);
    assert(lookup_modula3_hash_sumN("THEN") == 41);
    assert(lookup_modula3_hash_sumN("CONST") == 6);
    assert(lookup_modula3_hash_sumN("EXPORTS") == 16);
    assert(lookup_modula3_hash_sumN("BITS") == 3);
    assert(lookup_modula3_hash_sumN("RETURN") == 39);
    assert(lookup_modula3_hash_sumN("FROM") == 19);
    assert(lookup_modula3_hash_sumN("REF") == 37);
    assert(lookup_modula3_hash_sumN("UNTIL") == 47);
    assert(lookup_modula3_hash_sumN("INTERFACE") == 22);
    assert(lookup_modula3_hash_sumN("MOD") == 27);
    assert(lookup_modula3_hash_sumN("DIV") == 7);
    assert(lookup_modula3_hash_sumN("EXIT") == 15);
    assert(lookup_modula3_hash_sumN("WITH") == 52);
    assert(lookup_modula3_hash_sumN("IF") == 20);
    assert(lookup_modula3_hash_sumN("FOR") == 18);
    assert(lookup_modula3_hash_sumN("VAR") == 50);
    assert(lookup_modula3_hash_sumN("DO") == 8);
    assert(lookup_modula3_hash_sumN("TYPE") == 44);
    assert(lookup_modula3_hash_sumN("OF") == 31);
    assert(lookup_modula3_hash_sumN("SET") == 40);
    assert(lookup_modula3_hash_sumN("IN") == 23);
    assert(lookup_modula3_hash_sumN("NOT") == 29);
    assert(lookup_modula3_hash_sumN("BY") == 4);
    assert(lookup_modula3_hash_sumN("PROCEDURE") == 33);
    assert(lookup_modula3_hash_sumN("OR") == 32);
    assert(lookup_modula3_hash_sumN("TO") == 42);
    assert(lookup_modula3_hash_sumN("UNTRACED") == 48);
    assert(lookup_modula3_hash_sumN("EXCEPTION") == 14);
    assert(lookup_modula3_hash_sumN("TRY") == 43);
    assert(lookup_modula3_hash_sumN("READONLY") == 35);
    assert(lookup_modula3_hash_sumN("TYPECASE") == 45);
}

//lookup: name=lookup_modula3_hash_djb2, dataset=modula3, type=hash, hash=hash_djb2
int lookup_modula3_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 349) * 1;
    static constexpr const std::string_view lookup[349] = {
        "",
        "RAISES", // 7081824841328 (0x670dda76e70)
        "",
        "",
        "",
        "",
        "",
        "INTERFACE", // 254487449358273882 (0x3881efca2cb8d5a)
        "",
        "",
        "",
        "",
        "",
        "IMPORT", // 7081487101476 (0x670c985ee24)
        "",
        "",
        "",
        "NOT", // 197058330 (0xbbedf1a)
        "",
        "",
        "",
        "",
        "INLINE", // 7081488136968 (0x670c995bb08)
        "",
        "TRY", // 197064968 (0xbbef908)
        "",
        "",
        "",
        "FOR", // 197049616 (0xbbebd10)
        "EXPORTS", // 233684338966238 (0xd488e0037ede)
        "",
        "",
        "",
        "",
        "RECORD", // 7081829365448 (0x670ddec76c8)
        "BY", // 5971076 (0x5b1c84)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EVAL", // 6502608529 (0x18395ee91)
        "",
        "",
        "",
        "",
        "",
        "",
        "EXIT", // 6502610979 (0x18395f823)
        "",
        "VALUE", // 214605499782 (0x31f77c0d86)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXCEPTION", // 254482227951415608 (0x3881a3ceeb1b138)
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
        "PROCEDURE", // 254497458141296274 (0x3882816fcc07692)
        "",
        "",
        "BEGIN", // 214581919278 (0x31f6143e2e)
        "",
        "",
        "",
        "FINALLY", // 233685040521560 (0xd48909d46158)
        "",
        "",
        "DO", // 5971132 (0x5b1cbc)
        "",
        "",
        "",
        "LOCK", // 6502852530 (0x18399a7b2)
        "OF", // 5971486 (0x5b1e1e)
        "",
        "",
        "DIV", // 197047244 (0xbbeb3cc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OR", // 5971498 (0x5b1e2a)
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
        "CASE", // 6502514373 (0x183947ec5)
        "AND", // 197044124 (0xbbea79c)
        "",
        "",
        "",
        "",
        "",
        "RETURN", // 7081829982921 (0x670ddf5e2c9)
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
        "THEN", // 6503132472 (0x1839ded38)
        "",
        "",
        "",
        "",
        "ARRAY", // 214581212264 (0x31f6097468)
        "",
        "",
        "",
        "",
        "",
        "EXCEPT", // 7081343126898 (0x670c0f10d72)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TYPE", // 6503151339 (0x1839e36eb)
        "",
        "",
        "BITS", // 6502487195 (0x18394149b)
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
        "REF", // 197062342 (0xbbeeec6)
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
        "UNTIL", // 214604789365 (0x31f7713675)
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
        "ELSE", // 6502598226 (0x18395c652)
        "",
        "",
        "",
        "",
        "",
        "ELSIF", // 214585741660 (0x31f64e915c)
        "",
        "READONLY", // 7712112087562631 (0x1b662005727987)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TYPECASE", // 7712223741579591 (0x1b663a048b9147)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VAR", // 197066578 (0xbbeff52)
        "",
        "",
        "",
        "",
        "",
        "",
        "UNSAFE", // 7081958004267 (0x670e597562b)
        "SET", // 197063445 (0xbbef315)
        "IF", // 5971288 (0x5b1d58)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IN", // 5971296 (0x5b1d60)
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
        "OBJECT", // 7081708641696 (0x670d6ba5da0)
        "",
        "TO", // 5971660 (0x5b1ecc)
        "",
        "",
        "",
        "METHODS", // 233693931625853 (0xd48b1bc7dd7d)
        "MODULE", // 7081645589967 (0x670d2f845cf)
        "",
        "",
        "WHILE", // 214606933698 (0x31f791eec2)
        "",
        "",
        "",
        "",
        "",
        "CONST", // 214583472528 (0x31f62bf190)
        "",
        "",
        "",
        "END", // 197048480 (0xbbeb8a0)
        "UNTRACED", // 7712252325763295 (0x1b6640ac4b98df)
        "",
        "WITH", // 6503241861 (0x1839f9885)
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
        "MOD", // 197057225 (0xbbedac9)
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
        "FROM", // 6502640573 (0x183966bbd)
        "",
        "",
        "",
        "",
        "REPEAT", // 7081829821194 (0x670ddf36b0a)
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
    };
    static constexpr const int values[349] = {
        -1,
        34, // 7081824841328 (0x670dda76e70)
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 254487449358273882 (0x3881efca2cb8d5a)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 7081487101476 (0x670c985ee24)
        -1,
        -1,
        -1,
        29, // 197058330 (0xbbedf1a)
        -1,
        -1,
        -1,
        -1,
        24, // 7081488136968 (0x670c995bb08)
        -1,
        43, // 197064968 (0xbbef908)
        -1,
        -1,
        -1,
        18, // 197049616 (0xbbebd10)
        16, // 233684338966238 (0xd488e0037ede)
        -1,
        -1,
        -1,
        -1,
        36, // 7081829365448 (0x670ddec76c8)
        4, // 5971076 (0x5b1c84)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 6502608529 (0x18395ee91)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 6502610979 (0x18395f823)
        -1,
        49, // 214605499782 (0x31f77c0d86)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 254482227951415608 (0x3881a3ceeb1b138)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 254497458141296274 (0x3882816fcc07692)
        -1,
        -1,
        2, // 214581919278 (0x31f6143e2e)
        -1,
        -1,
        -1,
        17, // 233685040521560 (0xd48909d46158)
        -1,
        -1,
        8, // 5971132 (0x5b1cbc)
        -1,
        -1,
        -1,
        25, // 6502852530 (0x18399a7b2)
        31, // 5971486 (0x5b1e1e)
        -1,
        -1,
        7, // 197047244 (0xbbeb3cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 5971498 (0x5b1e2a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 6502514373 (0x183947ec5)
        0, // 197044124 (0xbbea79c)
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 7081829982921 (0x670ddf5e2c9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 6503132472 (0x1839ded38)
        -1,
        -1,
        -1,
        -1,
        1, // 214581212264 (0x31f6097468)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 7081343126898 (0x670c0f10d72)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 6503151339 (0x1839e36eb)
        -1,
        -1,
        3, // 6502487195 (0x18394149b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 197062342 (0xbbeeec6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 214604789365 (0x31f7713675)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 6502598226 (0x18395c652)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 214585741660 (0x31f64e915c)
        -1,
        35, // 7712112087562631 (0x1b662005727987)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 7712223741579591 (0x1b663a048b9147)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 197066578 (0xbbeff52)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 7081958004267 (0x670e597562b)
        40, // 197063445 (0xbbef315)
        20, // 5971288 (0x5b1d58)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 5971296 (0x5b1d60)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 7081708641696 (0x670d6ba5da0)
        -1,
        42, // 5971660 (0x5b1ecc)
        -1,
        -1,
        -1,
        26, // 233693931625853 (0xd48b1bc7dd7d)
        28, // 7081645589967 (0x670d2f845cf)
        -1,
        -1,
        51, // 214606933698 (0x31f791eec2)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 214583472528 (0x31f62bf190)
        -1,
        -1,
        -1,
        11, // 197048480 (0xbbeb8a0)
        48, // 7712252325763295 (0x1b6640ac4b98df)
        -1,
        52, // 6503241861 (0x1839f9885)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 197057225 (0xbbedac9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 6502640573 (0x183966bbd)
        -1,
        -1,
        -1,
        -1,
        38, // 7081829821194 (0x670ddf36b0a)
        -1,
        -1,
        -1,
        -1,
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
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula3_hash_djb2, dataset=modula3, type=hash, hash=hash_djb2
void check_modula3_hash_djb2() {
    assert(lookup_modula3_hash_djb2("RAISES") == 34);
    assert(lookup_modula3_hash_djb2("INTERFACE") == 22);
    assert(lookup_modula3_hash_djb2("IMPORT") == 21);
    assert(lookup_modula3_hash_djb2("NOT") == 29);
    assert(lookup_modula3_hash_djb2("INLINE") == 24);
    assert(lookup_modula3_hash_djb2("TRY") == 43);
    assert(lookup_modula3_hash_djb2("FOR") == 18);
    assert(lookup_modula3_hash_djb2("EXPORTS") == 16);
    assert(lookup_modula3_hash_djb2("RECORD") == 36);
    assert(lookup_modula3_hash_djb2("BY") == 4);
    assert(lookup_modula3_hash_djb2("EVAL") == 12);
    assert(lookup_modula3_hash_djb2("EXIT") == 15);
    assert(lookup_modula3_hash_djb2("VALUE") == 49);
    assert(lookup_modula3_hash_djb2("EXCEPTION") == 14);
    assert(lookup_modula3_hash_djb2("PROCEDURE") == 33);
    assert(lookup_modula3_hash_djb2("BEGIN") == 2);
    assert(lookup_modula3_hash_djb2("FINALLY") == 17);
    assert(lookup_modula3_hash_djb2("DO") == 8);
    assert(lookup_modula3_hash_djb2("LOCK") == 25);
    assert(lookup_modula3_hash_djb2("OF") == 31);
    assert(lookup_modula3_hash_djb2("DIV") == 7);
    assert(lookup_modula3_hash_djb2("OR") == 32);
    assert(lookup_modula3_hash_djb2("CASE") == 5);
    assert(lookup_modula3_hash_djb2("AND") == 0);
    assert(lookup_modula3_hash_djb2("RETURN") == 39);
    assert(lookup_modula3_hash_djb2("THEN") == 41);
    assert(lookup_modula3_hash_djb2("ARRAY") == 1);
    assert(lookup_modula3_hash_djb2("EXCEPT") == 13);
    assert(lookup_modula3_hash_djb2("TYPE") == 44);
    assert(lookup_modula3_hash_djb2("BITS") == 3);
    assert(lookup_modula3_hash_djb2("REF") == 37);
    assert(lookup_modula3_hash_djb2("UNTIL") == 47);
    assert(lookup_modula3_hash_djb2("ELSE") == 9);
    assert(lookup_modula3_hash_djb2("ELSIF") == 10);
    assert(lookup_modula3_hash_djb2("READONLY") == 35);
    assert(lookup_modula3_hash_djb2("TYPECASE") == 45);
    assert(lookup_modula3_hash_djb2("VAR") == 50);
    assert(lookup_modula3_hash_djb2("UNSAFE") == 46);
    assert(lookup_modula3_hash_djb2("SET") == 40);
    assert(lookup_modula3_hash_djb2("IF") == 20);
    assert(lookup_modula3_hash_djb2("IN") == 23);
    assert(lookup_modula3_hash_djb2("OBJECT") == 30);
    assert(lookup_modula3_hash_djb2("TO") == 42);
    assert(lookup_modula3_hash_djb2("METHODS") == 26);
    assert(lookup_modula3_hash_djb2("MODULE") == 28);
    assert(lookup_modula3_hash_djb2("WHILE") == 51);
    assert(lookup_modula3_hash_djb2("CONST") == 6);
    assert(lookup_modula3_hash_djb2("END") == 11);
    assert(lookup_modula3_hash_djb2("UNTRACED") == 48);
    assert(lookup_modula3_hash_djb2("WITH") == 52);
    assert(lookup_modula3_hash_djb2("MOD") == 27);
    assert(lookup_modula3_hash_djb2("FROM") == 19);
    assert(lookup_modula3_hash_djb2("REPEAT") == 38);
}

//lookup: name=lookup_modula3_hash_sdb, dataset=modula3, type=hash, hash=hash_sdb
int lookup_modula3_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 297) * 1;
    static constexpr const std::string_view lookup[297] = {
        "LOCK", // 21395375459994591 (0x4c02fb0a210bdf)
        "",
        "",
        "",
        "",
        "",
        "THEN", // 23647454458088577 (0x54033c0ad10c81)
        "",
        "",
        "FINALLY", // 12771272047816945683 (0xb13cac432c013013)
        "UNTRACED", // 8322789576284907580 (0x73807d060ac9283c)
        "FROM", // 19706306547747710 (0x4602c8099d0b7e)
        "CONST", // 248561333006508435 (0x373113726c02193)
        "",
        "",
        "",
        "",
        "EXIT", // 19424818686331790 (0x4502c509a00b8e)
        "",
        "",
        "PROCEDURE", // 16891062999041638559 (0xea691c4e109f009f)
        "",
        "",
        "REF", // 352224084983 (0x52023103f7)
        "",
        "TYPE", // 23647527479938354 (0x54034d0b420d32)
        "MOD", // 330747937766 (0x4d021d03e6)
        "",
        "",
        "DIV", // 292089299861 (0x4401e10395)
        "",
        "",
        "",
        "",
        "",
        "UNSAFE", // 2440226723505010046 (0x21dd6d46b1ee757e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IF", // 4784417 (0x490121)
        "",
        "",
        "",
        "",
        "",
        "OF", // 5177651 (0x4f0133)
        "",
        "IN", // 4784425 (0x490129)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OR", // 5177663 (0x4f013f)
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
        "OBJECT", // 2245154492687477559 (0x1f28641da2826b37)
        "",
        "RAISES", // 2317496830248644135 (0x20296716a7106e27)
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
        "READONLY", // 4036069744632520842 (0x3803000c7985e08a)
        "",
        "EXCEPTION", // 14706490080638991983 (0xcc17f2cf5d4afe6f)
        "INTERFACE", // 6188151492508728993 (0x55e0baff07493ea1)
        "IMPORT", // 2131997420225391145 (0x1d96605b9e956a29)
        "",
        "",
        "",
        "",
        "",
        "MODULE", // 2236710775997295976 (0x1f0a6499a49b6d68)
        "METHODS", // 13756186557115155158 (0xbee7caca50da42d6)
        "",
        "",
        "RECORD", // 2329319457892298429 (0x205367b4a8136ebd)
        "BITS", // 18580213357087446 (0x42029b09000ad6)
        "",
        "",
        "",
        "AND", // 279203545975 (0x4101d40377)
        "",
        "",
        "",
        "",
        "",
        "WITH", // 24491999653989634 (0x5703580b370d02)
        "",
        "",
        "",
        "",
        "",
        "",
        "UNTIL", // 309082614949947194 (0x44a15002e57273a)
        "",
        "EXPORTS", // 13009976035436412379 (0xb48cb84640883ddb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 242650027774648629 (0x35e10ea263f2135)
        "",
        "SET", // 356519445518 (0x530237040e)
        "",
        "",
        "RETURN", // 2334105215428620488 (0x20646853aa0270c8)
        "",
        "NOT", // 335043298303 (0x4e022303ff)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "INLINE", // 2134249271576062397 (0x1d9e60679e6d69bd)
        "",
        "",
        "BY", // 4325663 (0x42011f)
        "TRY", // 360815658051 (0x54024a0443)
        "",
        "",
        "",
        "",
        "",
        "",
        "TO", // 5505355 (0x54014b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WHILE", // 314149349213742809 (0x45c152b2e4e26d9)
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
        "VALUE", // 308800835012273665 (0x44914b92d402601)
        "",
        "",
        "",
        "",
        "ELSE", // 19424767142660913 (0x4502b909620b31)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "REPEAT", // 2332979092168994719 (0x2060681fa9256f9f)
        "",
        "",
        "",
        "",
        "",
        "",
        "END", // 296384988059 (0x4501ec039b)
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
        "FOR", // 300680414133 (0x4601f303b5)
        "",
        "VAR", // 369405264923 (0x560245041b)
        "",
        "",
        "",
        "",
        "",
        "",
        "EXCEPT", // 2064159317967792153 (0x1ca55df69b486819)
        "",
        "",
        "",
        "",
        "",
        "DO", // 4456731 (0x44011b)
        "TYPECASE", // 9052119141571901290 (0x7d9f966629e8376a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ELSIF", // 254472676894777829 (0x388118d275b21e5)
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
        "CASE", // 18861692627323544 (0x43029c08ea0a98)
        "",
        "",
        "",
        "",
        "",
        "",
        "BEGIN", // 242368234950631377 (0x35d10a025121fd1)
        "",
        "",
        "",
        "",
        "EVAL", // 19424810095086428 (0x4502c3098c0b5c)
    };
    static constexpr const int values[297] = {
        25, // 21395375459994591 (0x4c02fb0a210bdf)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 23647454458088577 (0x54033c0ad10c81)
        -1,
        -1,
        17, // 12771272047816945683 (0xb13cac432c013013)
        48, // 8322789576284907580 (0x73807d060ac9283c)
        19, // 19706306547747710 (0x4602c8099d0b7e)
        6, // 248561333006508435 (0x373113726c02193)
        -1,
        -1,
        -1,
        -1,
        15, // 19424818686331790 (0x4502c509a00b8e)
        -1,
        -1,
        33, // 16891062999041638559 (0xea691c4e109f009f)
        -1,
        -1,
        37, // 352224084983 (0x52023103f7)
        -1,
        44, // 23647527479938354 (0x54034d0b420d32)
        27, // 330747937766 (0x4d021d03e6)
        -1,
        -1,
        7, // 292089299861 (0x4401e10395)
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 2440226723505010046 (0x21dd6d46b1ee757e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 4784417 (0x490121)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 5177651 (0x4f0133)
        -1,
        23, // 4784425 (0x490129)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 5177663 (0x4f013f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 2245154492687477559 (0x1f28641da2826b37)
        -1,
        34, // 2317496830248644135 (0x20296716a7106e27)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 4036069744632520842 (0x3803000c7985e08a)
        -1,
        14, // 14706490080638991983 (0xcc17f2cf5d4afe6f)
        22, // 6188151492508728993 (0x55e0baff07493ea1)
        21, // 2131997420225391145 (0x1d96605b9e956a29)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 2236710775997295976 (0x1f0a6499a49b6d68)
        26, // 13756186557115155158 (0xbee7caca50da42d6)
        -1,
        -1,
        36, // 2329319457892298429 (0x205367b4a8136ebd)
        3, // 18580213357087446 (0x42029b09000ad6)
        -1,
        -1,
        -1,
        0, // 279203545975 (0x4101d40377)
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 24491999653989634 (0x5703580b370d02)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 309082614949947194 (0x44a15002e57273a)
        -1,
        16, // 13009976035436412379 (0xb48cb84640883ddb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 242650027774648629 (0x35e10ea263f2135)
        -1,
        40, // 356519445518 (0x530237040e)
        -1,
        -1,
        39, // 2334105215428620488 (0x20646853aa0270c8)
        -1,
        29, // 335043298303 (0x4e022303ff)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 2134249271576062397 (0x1d9e60679e6d69bd)
        -1,
        -1,
        4, // 4325663 (0x42011f)
        43, // 360815658051 (0x54024a0443)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 5505355 (0x54014b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 314149349213742809 (0x45c152b2e4e26d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 308800835012273665 (0x44914b92d402601)
        -1,
        -1,
        -1,
        -1,
        9, // 19424767142660913 (0x4502b909620b31)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 2332979092168994719 (0x2060681fa9256f9f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 296384988059 (0x4501ec039b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 300680414133 (0x4601f303b5)
        -1,
        50, // 369405264923 (0x560245041b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 2064159317967792153 (0x1ca55df69b486819)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 4456731 (0x44011b)
        45, // 9052119141571901290 (0x7d9f966629e8376a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 254472676894777829 (0x388118d275b21e5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 18861692627323544 (0x43029c08ea0a98)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 242368234950631377 (0x35d10a025121fd1)
        -1,
        -1,
        -1,
        -1,
        12, // 19424810095086428 (0x4502c3098c0b5c)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula3_hash_sdb, dataset=modula3, type=hash, hash=hash_sdb
void check_modula3_hash_sdb() {
    assert(lookup_modula3_hash_sdb("LOCK") == 25);
    assert(lookup_modula3_hash_sdb("THEN") == 41);
    assert(lookup_modula3_hash_sdb("FINALLY") == 17);
    assert(lookup_modula3_hash_sdb("UNTRACED") == 48);
    assert(lookup_modula3_hash_sdb("FROM") == 19);
    assert(lookup_modula3_hash_sdb("CONST") == 6);
    assert(lookup_modula3_hash_sdb("EXIT") == 15);
    assert(lookup_modula3_hash_sdb("PROCEDURE") == 33);
    assert(lookup_modula3_hash_sdb("REF") == 37);
    assert(lookup_modula3_hash_sdb("TYPE") == 44);
    assert(lookup_modula3_hash_sdb("MOD") == 27);
    assert(lookup_modula3_hash_sdb("DIV") == 7);
    assert(lookup_modula3_hash_sdb("UNSAFE") == 46);
    assert(lookup_modula3_hash_sdb("IF") == 20);
    assert(lookup_modula3_hash_sdb("OF") == 31);
    assert(lookup_modula3_hash_sdb("IN") == 23);
    assert(lookup_modula3_hash_sdb("OR") == 32);
    assert(lookup_modula3_hash_sdb("OBJECT") == 30);
    assert(lookup_modula3_hash_sdb("RAISES") == 34);
    assert(lookup_modula3_hash_sdb("READONLY") == 35);
    assert(lookup_modula3_hash_sdb("EXCEPTION") == 14);
    assert(lookup_modula3_hash_sdb("INTERFACE") == 22);
    assert(lookup_modula3_hash_sdb("IMPORT") == 21);
    assert(lookup_modula3_hash_sdb("MODULE") == 28);
    assert(lookup_modula3_hash_sdb("METHODS") == 26);
    assert(lookup_modula3_hash_sdb("RECORD") == 36);
    assert(lookup_modula3_hash_sdb("BITS") == 3);
    assert(lookup_modula3_hash_sdb("AND") == 0);
    assert(lookup_modula3_hash_sdb("WITH") == 52);
    assert(lookup_modula3_hash_sdb("UNTIL") == 47);
    assert(lookup_modula3_hash_sdb("EXPORTS") == 16);
    assert(lookup_modula3_hash_sdb("ARRAY") == 1);
    assert(lookup_modula3_hash_sdb("SET") == 40);
    assert(lookup_modula3_hash_sdb("RETURN") == 39);
    assert(lookup_modula3_hash_sdb("NOT") == 29);
    assert(lookup_modula3_hash_sdb("INLINE") == 24);
    assert(lookup_modula3_hash_sdb("BY") == 4);
    assert(lookup_modula3_hash_sdb("TRY") == 43);
    assert(lookup_modula3_hash_sdb("TO") == 42);
    assert(lookup_modula3_hash_sdb("WHILE") == 51);
    assert(lookup_modula3_hash_sdb("VALUE") == 49);
    assert(lookup_modula3_hash_sdb("ELSE") == 9);
    assert(lookup_modula3_hash_sdb("REPEAT") == 38);
    assert(lookup_modula3_hash_sdb("END") == 11);
    assert(lookup_modula3_hash_sdb("FOR") == 18);
    assert(lookup_modula3_hash_sdb("VAR") == 50);
    assert(lookup_modula3_hash_sdb("EXCEPT") == 13);
    assert(lookup_modula3_hash_sdb("DO") == 8);
    assert(lookup_modula3_hash_sdb("TYPECASE") == 45);
    assert(lookup_modula3_hash_sdb("ELSIF") == 10);
    assert(lookup_modula3_hash_sdb("CASE") == 5);
    assert(lookup_modula3_hash_sdb("BEGIN") == 2);
    assert(lookup_modula3_hash_sdb("EVAL") == 12);
}
