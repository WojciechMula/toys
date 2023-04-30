
//lookup: name=lookup_modula2_hash1, dataset=modula2, type=hash, hash=hash1
int lookup_modula2_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 61) * 2;
    static std::string_view lookup[122] = {
        "",
        "",
        "",
        "",
        "EXIT", // 612 (0x264)
        "TYPE", // 612 (0x264)
        "ELSE", // 552 (0x228)
        "EXPORT", // 918 (0x396)
        "",
        "",
        "BY", // 310 (0x136)
        "",
        "",
        "",
        "",
        "",
        "MOD", // 435 (0x1b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UNTIL", // 805 (0x325)
        "",
        "SET", // 501 (0x1f5)
        "",
        "LOOP", // 624 (0x270)
        "",
        "",
        "",
        "VAR", // 504 (0x1f8)
        "",
        "OR", // 322 (0x142)
        "",
        "",
        "",
        "",
        "",
        "REPEAT", // 996 (0x3e4)
        "",
        "TO", // 326 (0x146)
        "",
        "MODULE", // 876 (0x36c)
        "",
        "CONST", // 755 (0x2f3)
        "",
        "ELSIF", // 695 (0x2b7)
        "",
        "",
        "",
        "WITH", // 636 (0x27c)
        "",
        "IMPORT", // 942 (0x3ae)
        "",
        "",
        "",
        "FOR", // 456 (0x1c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AND", // 399 (0x18f)
        "",
        "",
        "",
        "DIV", // 462 (0x1ce)
        "",
        "POINTER", // 1134 (0x46e)
        "",
        "",
        "",
        "ARRAY", // 770 (0x302)
        "THEN", // 648 (0x288)
        "FROM", // 588 (0x24c)
        "",
        "IMPLEMENTATION", // 2114 (0x842)
        "",
        "",
        "",
        "IF", // 286 (0x11e)
        "",
        "",
        "",
        "",
        "",
        "END", // 411 (0x19b)
        "RETURN", // 960 (0x3c0)
        "RECORD", // 900 (0x384)
        "",
        "",
        "",
        "WHILE", // 780 (0x30c)
        "",
        "BEGIN", // 720 (0x2d0)
        "",
        "DO", // 294 (0x126)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OF", // 298 (0x12a)
        "",
        "",
        "",
        "CASE", // 544 (0x220)
        "",
        "DEFINITION", // 1460 (0x5b4)
        "",
        "IN", // 302 (0x12e)
        "",
        "NOT", // 486 (0x1e6)
        "",
        "PROCEDURE", // 1341 (0x53d)
        "QUALIFIED", // 1341 (0x53d)
    };
    static int values[122] = {
        -1,
        -1,
        -1,
        -1,
        12, // 612 (0x264)
        35, // 612 (0x264)
        9, // 552 (0x228)
        13, // 918 (0x396)
        -1,
        -1,
        3, // 310 (0x136)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 435 (0x1b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 805 (0x325)
        -1,
        32, // 501 (0x1f5)
        -1,
        20, // 624 (0x270)
        -1,
        -1,
        -1,
        37, // 504 (0x1f8)
        -1,
        25, // 322 (0x142)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 996 (0x3e4)
        -1,
        34, // 326 (0x146)
        -1,
        22, // 876 (0x36c)
        -1,
        5, // 755 (0x2f3)
        -1,
        10, // 695 (0x2b7)
        -1,
        -1,
        -1,
        39, // 636 (0x27c)
        -1,
        18, // 942 (0x3ae)
        -1,
        -1,
        -1,
        14, // 456 (0x1c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 399 (0x18f)
        -1,
        -1,
        -1,
        7, // 462 (0x1ce)
        -1,
        26, // 1134 (0x46e)
        -1,
        -1,
        -1,
        1, // 770 (0x302)
        33, // 648 (0x288)
        15, // 588 (0x24c)
        -1,
        17, // 2114 (0x842)
        -1,
        -1,
        -1,
        16, // 286 (0x11e)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 411 (0x19b)
        31, // 960 (0x3c0)
        29, // 900 (0x384)
        -1,
        -1,
        -1,
        38, // 780 (0x30c)
        -1,
        2, // 720 (0x2d0)
        -1,
        8, // 294 (0x126)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 298 (0x12a)
        -1,
        -1,
        -1,
        4, // 544 (0x220)
        -1,
        6, // 1460 (0x5b4)
        -1,
        19, // 302 (0x12e)
        -1,
        23, // 486 (0x1e6)
        -1,
        27, // 1341 (0x53d)
        28, // 1341 (0x53d)
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula2_hash1, dataset=modula2, type=hash, hash=hash1
void check_modula2_hash1() {
    assert(lookup_modula2_hash1("EXIT") == 12);
    assert(lookup_modula2_hash1("TYPE") == 35);
    assert(lookup_modula2_hash1("ELSE") == 9);
    assert(lookup_modula2_hash1("EXPORT") == 13);
    assert(lookup_modula2_hash1("BY") == 3);
    assert(lookup_modula2_hash1("MOD") == 21);
    assert(lookup_modula2_hash1("UNTIL") == 36);
    assert(lookup_modula2_hash1("SET") == 32);
    assert(lookup_modula2_hash1("LOOP") == 20);
    assert(lookup_modula2_hash1("VAR") == 37);
    assert(lookup_modula2_hash1("OR") == 25);
    assert(lookup_modula2_hash1("REPEAT") == 30);
    assert(lookup_modula2_hash1("TO") == 34);
    assert(lookup_modula2_hash1("MODULE") == 22);
    assert(lookup_modula2_hash1("CONST") == 5);
    assert(lookup_modula2_hash1("ELSIF") == 10);
    assert(lookup_modula2_hash1("WITH") == 39);
    assert(lookup_modula2_hash1("IMPORT") == 18);
    assert(lookup_modula2_hash1("FOR") == 14);
    assert(lookup_modula2_hash1("AND") == 0);
    assert(lookup_modula2_hash1("DIV") == 7);
    assert(lookup_modula2_hash1("POINTER") == 26);
    assert(lookup_modula2_hash1("ARRAY") == 1);
    assert(lookup_modula2_hash1("THEN") == 33);
    assert(lookup_modula2_hash1("FROM") == 15);
    assert(lookup_modula2_hash1("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash1("IF") == 16);
    assert(lookup_modula2_hash1("END") == 11);
    assert(lookup_modula2_hash1("RETURN") == 31);
    assert(lookup_modula2_hash1("RECORD") == 29);
    assert(lookup_modula2_hash1("WHILE") == 38);
    assert(lookup_modula2_hash1("BEGIN") == 2);
    assert(lookup_modula2_hash1("DO") == 8);
    assert(lookup_modula2_hash1("OF") == 24);
    assert(lookup_modula2_hash1("CASE") == 4);
    assert(lookup_modula2_hash1("DEFINITION") == 6);
    assert(lookup_modula2_hash1("IN") == 19);
    assert(lookup_modula2_hash1("NOT") == 23);
    assert(lookup_modula2_hash1("PROCEDURE") == 27);
    assert(lookup_modula2_hash1("QUALIFIED") == 28);
}

//lookup: name=lookup_modula2_hash2, dataset=modula2, type=hash, hash=hash2
int lookup_modula2_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 61) * 2;
    static std::string_view lookup[122] = {
        "",
        "",
        "REPEAT", // 6894 (0x1aee)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DO", // 5374 (0x14fe)
        "",
        "ELSE", // 4765 (0x129d)
        "IMPLEMENTATION", // 5680 (0x1630)
        "ELSIF", // 4827 (0x12db)
        "",
        "FOR", // 5743 (0x166f)
        "",
        "OR", // 6476 (0x194c)
        "",
        "",
        "",
        "MODULE", // 5319 (0x14c7)
        "",
        "CONST", // 5625 (0x15f9)
        "",
        "",
        "",
        "",
        "",
        "BY", // 5872 (0x16f0)
        "",
        "",
        "",
        "FROM", // 5386 (0x150a)
        "",
        "IN", // 5692 (0x163c)
        "",
        "",
        "",
        "BEGIN", // 5145 (0x1419)
        "SET", // 6975 (0x1b3f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "QUALIFIED", // 5517 (0x158d)
        "",
        "NOT", // 6555 (0x199b)
        "WHILE", // 6006 (0x1776)
        "THEN", // 6556 (0x199c)
        "",
        "IMPORT", // 6130 (0x17f2)
        "",
        "AND", // 4423 (0x1147)
        "RECORD", // 5582 (0x15ce)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OF", // 5528 (0x1598)
        "",
        "PROCEDURE", // 5529 (0x1599)
        "",
        "POINTER", // 6567 (0x19a7)
        "VAR", // 7055 (0x1b8f)
        "",
        "",
        "",
        "",
        "",
        "",
        "CASE", // 4619 (0x120b)
        "",
        "IF", // 5108 (0x13f4)
        "LOOP", // 6084 (0x17c4)
        "WITH", // 6268 (0x187c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RETURN", // 6394 (0x18fa)
        "TO", // 6638 (0x19ee)
        "",
        "",
        "DEFINITION", // 5298 (0x14b2)
        "UNTIL", // 6457 (0x1939)
        "",
        "",
        "ARRAY", // 5788 (0x169c)
        "MOD", // 5239 (0x1477)
        "",
        "",
        "DIV", // 5851 (0x16db)
        "",
        "",
        "",
        "EXIT", // 5792 (0x16a0)
        "TYPE", // 5792 (0x16a0)
        "END", // 4695 (0x1257)
        "",
        "EXPORT", // 5794 (0x16a2)
        "",
    };
    static int values[122] = {
        -1,
        -1,
        30, // 6894 (0x1aee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 5374 (0x14fe)
        -1,
        9, // 4765 (0x129d)
        17, // 5680 (0x1630)
        10, // 4827 (0x12db)
        -1,
        14, // 5743 (0x166f)
        -1,
        25, // 6476 (0x194c)
        -1,
        -1,
        -1,
        22, // 5319 (0x14c7)
        -1,
        5, // 5625 (0x15f9)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 5872 (0x16f0)
        -1,
        -1,
        -1,
        15, // 5386 (0x150a)
        -1,
        19, // 5692 (0x163c)
        -1,
        -1,
        -1,
        2, // 5145 (0x1419)
        32, // 6975 (0x1b3f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 5517 (0x158d)
        -1,
        23, // 6555 (0x199b)
        38, // 6006 (0x1776)
        33, // 6556 (0x199c)
        -1,
        18, // 6130 (0x17f2)
        -1,
        0, // 4423 (0x1147)
        29, // 5582 (0x15ce)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 5528 (0x1598)
        -1,
        27, // 5529 (0x1599)
        -1,
        26, // 6567 (0x19a7)
        37, // 7055 (0x1b8f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 4619 (0x120b)
        -1,
        16, // 5108 (0x13f4)
        20, // 6084 (0x17c4)
        39, // 6268 (0x187c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 6394 (0x18fa)
        34, // 6638 (0x19ee)
        -1,
        -1,
        6, // 5298 (0x14b2)
        36, // 6457 (0x1939)
        -1,
        -1,
        1, // 5788 (0x169c)
        21, // 5239 (0x1477)
        -1,
        -1,
        7, // 5851 (0x16db)
        -1,
        -1,
        -1,
        12, // 5792 (0x16a0)
        35, // 5792 (0x16a0)
        11, // 4695 (0x1257)
        -1,
        13, // 5794 (0x16a2)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula2_hash2, dataset=modula2, type=hash, hash=hash2
void check_modula2_hash2() {
    assert(lookup_modula2_hash2("REPEAT") == 30);
    assert(lookup_modula2_hash2("DO") == 8);
    assert(lookup_modula2_hash2("ELSE") == 9);
    assert(lookup_modula2_hash2("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash2("ELSIF") == 10);
    assert(lookup_modula2_hash2("FOR") == 14);
    assert(lookup_modula2_hash2("OR") == 25);
    assert(lookup_modula2_hash2("MODULE") == 22);
    assert(lookup_modula2_hash2("CONST") == 5);
    assert(lookup_modula2_hash2("BY") == 3);
    assert(lookup_modula2_hash2("FROM") == 15);
    assert(lookup_modula2_hash2("IN") == 19);
    assert(lookup_modula2_hash2("BEGIN") == 2);
    assert(lookup_modula2_hash2("SET") == 32);
    assert(lookup_modula2_hash2("QUALIFIED") == 28);
    assert(lookup_modula2_hash2("NOT") == 23);
    assert(lookup_modula2_hash2("WHILE") == 38);
    assert(lookup_modula2_hash2("THEN") == 33);
    assert(lookup_modula2_hash2("IMPORT") == 18);
    assert(lookup_modula2_hash2("AND") == 0);
    assert(lookup_modula2_hash2("RECORD") == 29);
    assert(lookup_modula2_hash2("OF") == 24);
    assert(lookup_modula2_hash2("PROCEDURE") == 27);
    assert(lookup_modula2_hash2("POINTER") == 26);
    assert(lookup_modula2_hash2("VAR") == 37);
    assert(lookup_modula2_hash2("CASE") == 4);
    assert(lookup_modula2_hash2("IF") == 16);
    assert(lookup_modula2_hash2("LOOP") == 20);
    assert(lookup_modula2_hash2("WITH") == 39);
    assert(lookup_modula2_hash2("RETURN") == 31);
    assert(lookup_modula2_hash2("TO") == 34);
    assert(lookup_modula2_hash2("DEFINITION") == 6);
    assert(lookup_modula2_hash2("UNTIL") == 36);
    assert(lookup_modula2_hash2("ARRAY") == 1);
    assert(lookup_modula2_hash2("MOD") == 21);
    assert(lookup_modula2_hash2("DIV") == 7);
    assert(lookup_modula2_hash2("EXIT") == 12);
    assert(lookup_modula2_hash2("TYPE") == 35);
    assert(lookup_modula2_hash2("END") == 11);
    assert(lookup_modula2_hash2("EXPORT") == 13);
}

//lookup: name=lookup_modula2_hash3, dataset=modula2, type=hash, hash=hash3
int lookup_modula2_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 187) * 1;
    static std::string_view lookup[187] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "NOT", // 20950 (0x51d6)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXPORT", // 19474 (0x4c12)
        "AND", // 17605 (0x44c5)
        "",
        "WHILE", // 23778 (0x5ce2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 18176 (0x4700)
        "IMPLEMENTATION", // 22665 (0x5889)
        "",
        "",
        "EXIT", // 18928 (0x49f0)
        "BY", // 17620 (0x44d4)
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
        "",
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
        "PROCEDURE", // 23088 (0x5a30)
        "",
        "DEFINITION", // 20285 (0x4f3d)
        "",
        "UNTIL", // 23279 (0x5aef)
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
        "",
        "",
        "IMPORT", // 20487 (0x5007)
        "",
        "",
        "",
        "MOD", // 20678 (0x50c6)
        "",
        "",
        "",
        "POINTER", // 22552 (0x5818)
        "IF", // 19374 (0x4bae)
        "",
        "",
        "END", // 18629 (0x48c5)
        "",
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
        "IN", // 19390 (0x4bbe)
        "",
        "",
        "",
        "",
        "WITH", // 23509 (0x5bd5)
        "",
        "",
        "LOOP", // 20707 (0x50e3)
        "",
        "",
        "RECORD", // 22767 (0x58ef)
        "",
        "TO", // 22208 (0x56c0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RETURN", // 22777 (0x58f9)
        "",
        "",
        "OF", // 20910 (0x51ae)
        "SET", // 22220 (0x56cc)
        "",
        "REPEAT", // 22783 (0x58ff)
        "",
        "QUALIFIED", // 23346 (0x5b32)
        "",
        "DO", // 18112 (0x46c0)
        "",
        "",
        "",
        "",
        "",
        "",
        "CONST", // 18680 (0x48f8)
        "VAR", // 22982 (0x59c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OR", // 20934 (0x51c6)
        "",
        "",
        "MODULE", // 21498 (0x53fa)
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[187] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 20950 (0x51d6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 18900 (0x49d4)
        9, // 18901 (0x49d5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 19474 (0x4c12)
        0, // 17605 (0x44c5)
        -1,
        38, // 23778 (0x5ce2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 18176 (0x4700)
        17, // 22665 (0x5889)
        -1,
        -1,
        12, // 18928 (0x49f0)
        3, // 17620 (0x44d4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 18378 (0x47ca)
        -1,
        -1,
        -1,
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
        27, // 23088 (0x5a30)
        -1,
        6, // 20285 (0x4f3d)
        -1,
        36, // 23279 (0x5aef)
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 19171 (0x4ae3)
        -1,
        -1,
        -1,
        10, // 19175 (0x4ae7)
        -1,
        -1,
        18, // 20487 (0x5007)
        -1,
        -1,
        -1,
        21, // 20678 (0x50c6)
        -1,
        -1,
        -1,
        26, // 22552 (0x5818)
        16, // 19374 (0x4bae)
        -1,
        -1,
        11, // 18629 (0x48c5)
        -1,
        -1,
        33, // 22746 (0x58da)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 22754 (0x58e2)
        -1,
        19, // 19390 (0x4bbe)
        -1,
        -1,
        -1,
        -1,
        39, // 23509 (0x5bd5)
        -1,
        -1,
        20, // 20707 (0x50e3)
        -1,
        -1,
        29, // 22767 (0x58ef)
        -1,
        34, // 22208 (0x56c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 22777 (0x58f9)
        -1,
        -1,
        24, // 20910 (0x51ae)
        32, // 22220 (0x56cc)
        -1,
        30, // 22783 (0x58ff)
        -1,
        28, // 23346 (0x5b32)
        -1,
        8, // 18112 (0x46c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 18680 (0x48f8)
        37, // 22982 (0x59c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 20934 (0x51c6)
        -1,
        -1,
        22, // 21498 (0x53fa)
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

//check: name=check_modula2_hash3, dataset=modula2, type=hash, hash=hash3
void check_modula2_hash3() {
    assert(lookup_modula2_hash3("NOT") == 23);
    assert(lookup_modula2_hash3("FOR") == 14);
    assert(lookup_modula2_hash3("ELSE") == 9);
    assert(lookup_modula2_hash3("EXPORT") == 13);
    assert(lookup_modula2_hash3("AND") == 0);
    assert(lookup_modula2_hash3("WHILE") == 38);
    assert(lookup_modula2_hash3("ARRAY") == 1);
    assert(lookup_modula2_hash3("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash3("EXIT") == 12);
    assert(lookup_modula2_hash3("BY") == 3);
    assert(lookup_modula2_hash3("CASE") == 4);
    assert(lookup_modula2_hash3("DIV") == 7);
    assert(lookup_modula2_hash3("BEGIN") == 2);
    assert(lookup_modula2_hash3("PROCEDURE") == 27);
    assert(lookup_modula2_hash3("DEFINITION") == 6);
    assert(lookup_modula2_hash3("UNTIL") == 36);
    assert(lookup_modula2_hash3("FROM") == 15);
    assert(lookup_modula2_hash3("ELSIF") == 10);
    assert(lookup_modula2_hash3("IMPORT") == 18);
    assert(lookup_modula2_hash3("MOD") == 21);
    assert(lookup_modula2_hash3("POINTER") == 26);
    assert(lookup_modula2_hash3("IF") == 16);
    assert(lookup_modula2_hash3("END") == 11);
    assert(lookup_modula2_hash3("THEN") == 33);
    assert(lookup_modula2_hash3("TYPE") == 35);
    assert(lookup_modula2_hash3("IN") == 19);
    assert(lookup_modula2_hash3("WITH") == 39);
    assert(lookup_modula2_hash3("LOOP") == 20);
    assert(lookup_modula2_hash3("RECORD") == 29);
    assert(lookup_modula2_hash3("TO") == 34);
    assert(lookup_modula2_hash3("RETURN") == 31);
    assert(lookup_modula2_hash3("OF") == 24);
    assert(lookup_modula2_hash3("SET") == 32);
    assert(lookup_modula2_hash3("REPEAT") == 30);
    assert(lookup_modula2_hash3("QUALIFIED") == 28);
    assert(lookup_modula2_hash3("DO") == 8);
    assert(lookup_modula2_hash3("CONST") == 5);
    assert(lookup_modula2_hash3("VAR") == 37);
    assert(lookup_modula2_hash3("OR") == 25);
    assert(lookup_modula2_hash3("MODULE") == 22);
}

//lookup: name=lookup_modula2_hash_sum0, dataset=modula2, type=hash, hash=hash_sum0
int lookup_modula2_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 62) * 2;
    static std::string_view lookup[124] = {
        "",
        "",
        "DEFINITION", // 745 (0x2e9)
        "",
        "",
        "",
        "",
        "",
        "EXIT", // 314 (0x13a)
        "LOOP", // 314 (0x13a)
        "WHILE", // 377 (0x179)
        "",
        "WITH", // 316 (0x13c)
        "",
        "",
        "",
        "IMPLEMENTATION", // 1062 (0x426)
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 383 (0x17f)
        "",
        "TYPE", // 322 (0x142)
        "",
        "RECORD", // 447 (0x1bf)
        "",
        "",
        "",
        "REPEAT", // 449 (0x1c1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONST", // 391 (0x187)
        "IF", // 143 (0x8f)
        "MODULE", // 454 (0x1c6)
        "",
        "",
        "",
        "",
        "",
        "DO", // 147 (0x93)
        "",
        "UNTIL", // 396 (0x18c)
        "",
        "AND", // 211 (0xd3)
        "OF", // 149 (0x95)
        "",
        "",
        "IN", // 151 (0x97)
        "",
        "",
        "",
        "END", // 215 (0xd7)
        "",
        "",
        "",
        "BY", // 155 (0x9b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CASE", // 284 (0x11c)
        "",
        "OR", // 161 (0xa1)
        "",
        "MOD", // 224 (0xe0)
        "",
        "TO", // 163 (0xa3)
        "",
        "QUALIFIED", // 660 (0x294)
        "",
        "DIV", // 227 (0xe3)
        "IMPORT", // 475 (0x1db)
        "",
        "",
        "",
        "",
        "",
        "",
        "FOR", // 231 (0xe7)
        "",
        "RETURN", // 480 (0x1e0)
        "",
        "BEGIN", // 357 (0x165)
        "VAR", // 233 (0xe9)
        "EXPORT", // 482 (0x1e2)
        "",
        "ELSE", // 297 (0x129)
        "POINTER", // 545 (0x221)
        "SET", // 236 (0xec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NOT", // 241 (0xf1)
        "THEN", // 303 (0x12f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FROM", // 308 (0x134)
        "",
        "ELSIF", // 371 (0x173)
        "PROCEDURE", // 681 (0x2a9)
    };
    static int values[124] = {
        -1,
        -1,
        6, // 745 (0x2e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 314 (0x13a)
        20, // 314 (0x13a)
        38, // 377 (0x179)
        -1,
        39, // 316 (0x13c)
        -1,
        -1,
        -1,
        17, // 1062 (0x426)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 383 (0x17f)
        -1,
        35, // 322 (0x142)
        -1,
        29, // 447 (0x1bf)
        -1,
        -1,
        -1,
        30, // 449 (0x1c1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 391 (0x187)
        16, // 143 (0x8f)
        22, // 454 (0x1c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 147 (0x93)
        -1,
        36, // 396 (0x18c)
        -1,
        0, // 211 (0xd3)
        24, // 149 (0x95)
        -1,
        -1,
        19, // 151 (0x97)
        -1,
        -1,
        -1,
        11, // 215 (0xd7)
        -1,
        -1,
        -1,
        3, // 155 (0x9b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 284 (0x11c)
        -1,
        25, // 161 (0xa1)
        -1,
        21, // 224 (0xe0)
        -1,
        34, // 163 (0xa3)
        -1,
        28, // 660 (0x294)
        -1,
        7, // 227 (0xe3)
        18, // 475 (0x1db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 231 (0xe7)
        -1,
        31, // 480 (0x1e0)
        -1,
        2, // 357 (0x165)
        37, // 233 (0xe9)
        13, // 482 (0x1e2)
        -1,
        9, // 297 (0x129)
        26, // 545 (0x221)
        32, // 236 (0xec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 241 (0xf1)
        33, // 303 (0x12f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 308 (0x134)
        -1,
        10, // 371 (0x173)
        27, // 681 (0x2a9)
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula2_hash_sum0, dataset=modula2, type=hash, hash=hash_sum0
void check_modula2_hash_sum0() {
    assert(lookup_modula2_hash_sum0("DEFINITION") == 6);
    assert(lookup_modula2_hash_sum0("EXIT") == 12);
    assert(lookup_modula2_hash_sum0("LOOP") == 20);
    assert(lookup_modula2_hash_sum0("WHILE") == 38);
    assert(lookup_modula2_hash_sum0("WITH") == 39);
    assert(lookup_modula2_hash_sum0("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash_sum0("ARRAY") == 1);
    assert(lookup_modula2_hash_sum0("TYPE") == 35);
    assert(lookup_modula2_hash_sum0("RECORD") == 29);
    assert(lookup_modula2_hash_sum0("REPEAT") == 30);
    assert(lookup_modula2_hash_sum0("CONST") == 5);
    assert(lookup_modula2_hash_sum0("IF") == 16);
    assert(lookup_modula2_hash_sum0("MODULE") == 22);
    assert(lookup_modula2_hash_sum0("DO") == 8);
    assert(lookup_modula2_hash_sum0("UNTIL") == 36);
    assert(lookup_modula2_hash_sum0("AND") == 0);
    assert(lookup_modula2_hash_sum0("OF") == 24);
    assert(lookup_modula2_hash_sum0("IN") == 19);
    assert(lookup_modula2_hash_sum0("END") == 11);
    assert(lookup_modula2_hash_sum0("BY") == 3);
    assert(lookup_modula2_hash_sum0("CASE") == 4);
    assert(lookup_modula2_hash_sum0("OR") == 25);
    assert(lookup_modula2_hash_sum0("MOD") == 21);
    assert(lookup_modula2_hash_sum0("TO") == 34);
    assert(lookup_modula2_hash_sum0("QUALIFIED") == 28);
    assert(lookup_modula2_hash_sum0("DIV") == 7);
    assert(lookup_modula2_hash_sum0("IMPORT") == 18);
    assert(lookup_modula2_hash_sum0("FOR") == 14);
    assert(lookup_modula2_hash_sum0("RETURN") == 31);
    assert(lookup_modula2_hash_sum0("BEGIN") == 2);
    assert(lookup_modula2_hash_sum0("VAR") == 37);
    assert(lookup_modula2_hash_sum0("EXPORT") == 13);
    assert(lookup_modula2_hash_sum0("ELSE") == 9);
    assert(lookup_modula2_hash_sum0("POINTER") == 26);
    assert(lookup_modula2_hash_sum0("SET") == 32);
    assert(lookup_modula2_hash_sum0("NOT") == 23);
    assert(lookup_modula2_hash_sum0("THEN") == 33);
    assert(lookup_modula2_hash_sum0("FROM") == 15);
    assert(lookup_modula2_hash_sum0("ELSIF") == 10);
    assert(lookup_modula2_hash_sum0("PROCEDURE") == 27);
}

//lookup: name=lookup_modula2_hash_sumN, dataset=modula2, type=hash, hash=hash_sumN
int lookup_modula2_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 48) * 2;
    static std::string_view lookup[96] = {
        "CASE", // 288 (0x120)
        "",
        "IF", // 145 (0x91)
        "IMPORT", // 481 (0x1e1)
        "",
        "",
        "",
        "",
        "ARRAY", // 388 (0x184)
        "NOT", // 244 (0xf4)
        "DO", // 149 (0x95)
        "",
        "RETURN", // 486 (0x1e6)
        "",
        "OF", // 151 (0x97)
        "",
        "EXPORT", // 488 (0x1e8)
        "",
        "IN", // 153 (0x99)
        "",
        "",
        "",
        "",
        "",
        "CONST", // 396 (0x18c)
        "",
        "BY", // 157 (0x9d)
        "ELSE", // 301 (0x12d)
        "",
        "",
        "",
        "",
        "",
        "",
        "UNTIL", // 401 (0x191)
        "",
        "PROCEDURE", // 690 (0x2b2)
        "",
        "OR", // 163 (0xa3)
        "THEN", // 307 (0x133)
        "IMPLEMENTATION", // 1076 (0x434)
        "",
        "RECORD", // 453 (0x1c5)
        "TO", // 165 (0xa5)
        "AND", // 214 (0xd6)
        "",
        "REPEAT", // 455 (0x1c7)
        "",
        "FROM", // 312 (0x138)
        "POINTER", // 552 (0x228)
        "",
        "",
        "BEGIN", // 362 (0x16a)
        "END", // 218 (0xda)
        "",
        "",
        "MODULE", // 460 (0x1cc)
        "",
        "",
        "",
        "EXIT", // 318 (0x13e)
        "LOOP", // 318 (0x13e)
        "",
        "",
        "WITH", // 320 (0x140)
        "",
        "",
        "",
        "",
        "",
        "DEFINITION", // 755 (0x2f3)
        "MOD", // 227 (0xe3)
        "",
        "",
        "",
        "",
        "DIV", // 230 (0xe6)
        "TYPE", // 326 (0x146)
        "",
        "",
        "ELSIF", // 376 (0x178)
        "",
        "",
        "",
        "FOR", // 234 (0xea)
        "",
        "",
        "",
        "VAR", // 236 (0xec)
        "",
        "QUALIFIED", // 669 (0x29d)
        "",
        "WHILE", // 382 (0x17e)
        "",
        "SET", // 239 (0xef)
        "",
    };
    static int values[96] = {
        4, // 288 (0x120)
        -1,
        16, // 145 (0x91)
        18, // 481 (0x1e1)
        -1,
        -1,
        -1,
        -1,
        1, // 388 (0x184)
        23, // 244 (0xf4)
        8, // 149 (0x95)
        -1,
        31, // 486 (0x1e6)
        -1,
        24, // 151 (0x97)
        -1,
        13, // 488 (0x1e8)
        -1,
        19, // 153 (0x99)
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 396 (0x18c)
        -1,
        3, // 157 (0x9d)
        9, // 301 (0x12d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 401 (0x191)
        -1,
        27, // 690 (0x2b2)
        -1,
        25, // 163 (0xa3)
        33, // 307 (0x133)
        17, // 1076 (0x434)
        -1,
        29, // 453 (0x1c5)
        34, // 165 (0xa5)
        0, // 214 (0xd6)
        -1,
        30, // 455 (0x1c7)
        -1,
        15, // 312 (0x138)
        26, // 552 (0x228)
        -1,
        -1,
        2, // 362 (0x16a)
        11, // 218 (0xda)
        -1,
        -1,
        22, // 460 (0x1cc)
        -1,
        -1,
        -1,
        12, // 318 (0x13e)
        20, // 318 (0x13e)
        -1,
        -1,
        39, // 320 (0x140)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 755 (0x2f3)
        21, // 227 (0xe3)
        -1,
        -1,
        -1,
        -1,
        7, // 230 (0xe6)
        35, // 326 (0x146)
        -1,
        -1,
        10, // 376 (0x178)
        -1,
        -1,
        -1,
        14, // 234 (0xea)
        -1,
        -1,
        -1,
        37, // 236 (0xec)
        -1,
        28, // 669 (0x29d)
        -1,
        38, // 382 (0x17e)
        -1,
        32, // 239 (0xef)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula2_hash_sumN, dataset=modula2, type=hash, hash=hash_sumN
void check_modula2_hash_sumN() {
    assert(lookup_modula2_hash_sumN("CASE") == 4);
    assert(lookup_modula2_hash_sumN("IF") == 16);
    assert(lookup_modula2_hash_sumN("IMPORT") == 18);
    assert(lookup_modula2_hash_sumN("ARRAY") == 1);
    assert(lookup_modula2_hash_sumN("NOT") == 23);
    assert(lookup_modula2_hash_sumN("DO") == 8);
    assert(lookup_modula2_hash_sumN("RETURN") == 31);
    assert(lookup_modula2_hash_sumN("OF") == 24);
    assert(lookup_modula2_hash_sumN("EXPORT") == 13);
    assert(lookup_modula2_hash_sumN("IN") == 19);
    assert(lookup_modula2_hash_sumN("CONST") == 5);
    assert(lookup_modula2_hash_sumN("BY") == 3);
    assert(lookup_modula2_hash_sumN("ELSE") == 9);
    assert(lookup_modula2_hash_sumN("UNTIL") == 36);
    assert(lookup_modula2_hash_sumN("PROCEDURE") == 27);
    assert(lookup_modula2_hash_sumN("OR") == 25);
    assert(lookup_modula2_hash_sumN("THEN") == 33);
    assert(lookup_modula2_hash_sumN("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash_sumN("RECORD") == 29);
    assert(lookup_modula2_hash_sumN("TO") == 34);
    assert(lookup_modula2_hash_sumN("AND") == 0);
    assert(lookup_modula2_hash_sumN("REPEAT") == 30);
    assert(lookup_modula2_hash_sumN("FROM") == 15);
    assert(lookup_modula2_hash_sumN("POINTER") == 26);
    assert(lookup_modula2_hash_sumN("BEGIN") == 2);
    assert(lookup_modula2_hash_sumN("END") == 11);
    assert(lookup_modula2_hash_sumN("MODULE") == 22);
    assert(lookup_modula2_hash_sumN("EXIT") == 12);
    assert(lookup_modula2_hash_sumN("LOOP") == 20);
    assert(lookup_modula2_hash_sumN("WITH") == 39);
    assert(lookup_modula2_hash_sumN("DEFINITION") == 6);
    assert(lookup_modula2_hash_sumN("MOD") == 21);
    assert(lookup_modula2_hash_sumN("DIV") == 7);
    assert(lookup_modula2_hash_sumN("TYPE") == 35);
    assert(lookup_modula2_hash_sumN("ELSIF") == 10);
    assert(lookup_modula2_hash_sumN("FOR") == 14);
    assert(lookup_modula2_hash_sumN("VAR") == 37);
    assert(lookup_modula2_hash_sumN("QUALIFIED") == 28);
    assert(lookup_modula2_hash_sumN("WHILE") == 38);
    assert(lookup_modula2_hash_sumN("SET") == 32);
}

//lookup: name=lookup_modula2_hash_djb2, dataset=modula2, type=hash, hash=hash_djb2
int lookup_modula2_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 245) * 1;
    static std::string_view lookup[245] = {
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
        "ELSIF", // 214585741660 (0x31f64e915c)
        "",
        "",
        "",
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
        "",
        "",
        "TO", // 5971660 (0x5b1ecc)
        "",
        "IMPLEMENTATION", // 12018645430926769807 (0xa6cace5787c2fe8f)
        "",
        "",
        "",
        "FOR", // 197049616 (0xbbebd10)
        "",
        "WHILE", // 214606933698 (0x31f791eec2)
        "",
        "",
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
        "ELSE", // 6502598226 (0x18395c652)
        "",
        "",
        "",
        "",
        "",
        "",
        "CONST", // 214583472528 (0x31f62bf190)
        "",
        "",
        "",
        "",
        "",
        "EXIT", // 6502610979 (0x18395f823)
        "",
        "",
        "",
        "",
        "",
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
        "VAR", // 197066578 (0xbbeff52)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OF", // 5971486 (0x5b1e1e)
        "MODULE", // 7081645589967 (0x670d2f845cf)
        "RECORD", // 7081829365448 (0x670ddec76c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OR", // 5971498 (0x5b1e2a)
        "DIV", // 197047244 (0xbbeb3cc)
        "",
        "",
        "",
        "BEGIN", // 214581919278 (0x31f6143e2e)
        "",
        "",
        "",
        "QUALIFIED", // 254498974681712477 (0x3882978159ac75d)
        "",
        "",
        "END", // 197048480 (0xbbeb8a0)
        "",
        "",
        "",
        "",
        "",
        "DEFINITION", // 8397840522078840306 (0x748b1f760ee3e5f2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SET", // 197063445 (0xbbef315)
        "",
        "",
        "IF", // 5971288 (0x5b1d58)
        "REPEAT", // 7081829821194 (0x670ddf36b0a)
        "",
        "IMPORT", // 7081487101476 (0x670c985ee24)
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
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 214581212264 (0x31f6097468)
        "NOT", // 197058330 (0xbbedf1a)
        "RETURN", // 7081829982921 (0x670ddf5e2c9)
        "",
        "",
        "AND", // 197044124 (0xbbea79c)
        "",
        "BY", // 5971076 (0x5b1c84)
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
        "",
        "",
        "POINTER", // 233698184559658 (0xd48c19467c2a)
        "",
        "",
        "",
        "THEN", // 6503132472 (0x1839ded38)
        "",
        "TYPE", // 6503151339 (0x1839e36eb)
        "EXPORT", // 7081343605035 (0x670c0f8592b)
        "LOOP", // 6502852931 (0x18399a943)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DO", // 5971132 (0x5b1cbc)
        "",
        "",
        "",
        "",
        "",
        "CASE", // 6502514373 (0x183947ec5)
        "",
    };
    static int values[245] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 254497458141296274 (0x3882816fcc07692)
        10, // 214585741660 (0x31f64e915c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 6502640573 (0x183966bbd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 5971660 (0x5b1ecc)
        -1,
        17, // 12018645430926769807 (0xa6cace5787c2fe8f)
        -1,
        -1,
        -1,
        14, // 197049616 (0xbbebd10)
        -1,
        38, // 214606933698 (0x31f791eec2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 197057225 (0xbbedac9)
        -1,
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
        -1,
        5, // 214583472528 (0x31f62bf190)
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 6502610979 (0x18395f823)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 6503241861 (0x1839f9885)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 197066578 (0xbbeff52)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 5971486 (0x5b1e1e)
        22, // 7081645589967 (0x670d2f845cf)
        29, // 7081829365448 (0x670ddec76c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 5971498 (0x5b1e2a)
        7, // 197047244 (0xbbeb3cc)
        -1,
        -1,
        -1,
        2, // 214581919278 (0x31f6143e2e)
        -1,
        -1,
        -1,
        28, // 254498974681712477 (0x3882978159ac75d)
        -1,
        -1,
        11, // 197048480 (0xbbeb8a0)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 8397840522078840306 (0x748b1f760ee3e5f2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 197063445 (0xbbef315)
        -1,
        -1,
        16, // 5971288 (0x5b1d58)
        30, // 7081829821194 (0x670ddf36b0a)
        -1,
        18, // 7081487101476 (0x670c985ee24)
        -1,
        -1,
        -1,
        -1,
        19, // 5971296 (0x5b1d60)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 214581212264 (0x31f6097468)
        23, // 197058330 (0xbbedf1a)
        31, // 7081829982921 (0x670ddf5e2c9)
        -1,
        -1,
        0, // 197044124 (0xbbea79c)
        -1,
        3, // 5971076 (0x5b1c84)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 214604789365 (0x31f7713675)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 233698184559658 (0xd48c19467c2a)
        -1,
        -1,
        -1,
        33, // 6503132472 (0x1839ded38)
        -1,
        35, // 6503151339 (0x1839e36eb)
        13, // 7081343605035 (0x670c0f8592b)
        20, // 6502852931 (0x18399a943)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 5971132 (0x5b1cbc)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 6502514373 (0x183947ec5)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula2_hash_djb2, dataset=modula2, type=hash, hash=hash_djb2
void check_modula2_hash_djb2() {
    assert(lookup_modula2_hash_djb2("PROCEDURE") == 27);
    assert(lookup_modula2_hash_djb2("ELSIF") == 10);
    assert(lookup_modula2_hash_djb2("FROM") == 15);
    assert(lookup_modula2_hash_djb2("TO") == 34);
    assert(lookup_modula2_hash_djb2("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash_djb2("FOR") == 14);
    assert(lookup_modula2_hash_djb2("WHILE") == 38);
    assert(lookup_modula2_hash_djb2("MOD") == 21);
    assert(lookup_modula2_hash_djb2("ELSE") == 9);
    assert(lookup_modula2_hash_djb2("CONST") == 5);
    assert(lookup_modula2_hash_djb2("EXIT") == 12);
    assert(lookup_modula2_hash_djb2("WITH") == 39);
    assert(lookup_modula2_hash_djb2("VAR") == 37);
    assert(lookup_modula2_hash_djb2("OF") == 24);
    assert(lookup_modula2_hash_djb2("MODULE") == 22);
    assert(lookup_modula2_hash_djb2("RECORD") == 29);
    assert(lookup_modula2_hash_djb2("OR") == 25);
    assert(lookup_modula2_hash_djb2("DIV") == 7);
    assert(lookup_modula2_hash_djb2("BEGIN") == 2);
    assert(lookup_modula2_hash_djb2("QUALIFIED") == 28);
    assert(lookup_modula2_hash_djb2("END") == 11);
    assert(lookup_modula2_hash_djb2("DEFINITION") == 6);
    assert(lookup_modula2_hash_djb2("SET") == 32);
    assert(lookup_modula2_hash_djb2("IF") == 16);
    assert(lookup_modula2_hash_djb2("REPEAT") == 30);
    assert(lookup_modula2_hash_djb2("IMPORT") == 18);
    assert(lookup_modula2_hash_djb2("IN") == 19);
    assert(lookup_modula2_hash_djb2("ARRAY") == 1);
    assert(lookup_modula2_hash_djb2("NOT") == 23);
    assert(lookup_modula2_hash_djb2("RETURN") == 31);
    assert(lookup_modula2_hash_djb2("AND") == 0);
    assert(lookup_modula2_hash_djb2("BY") == 3);
    assert(lookup_modula2_hash_djb2("UNTIL") == 36);
    assert(lookup_modula2_hash_djb2("POINTER") == 26);
    assert(lookup_modula2_hash_djb2("THEN") == 33);
    assert(lookup_modula2_hash_djb2("TYPE") == 35);
    assert(lookup_modula2_hash_djb2("EXPORT") == 13);
    assert(lookup_modula2_hash_djb2("LOOP") == 20);
    assert(lookup_modula2_hash_djb2("DO") == 8);
    assert(lookup_modula2_hash_djb2("CASE") == 4);
}

//lookup: name=lookup_modula2_hash_sdb, dataset=modula2, type=hash, hash=hash_sdb
int lookup_modula2_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 204) * 1;
    static std::string_view lookup[204] = {
        "",
        "",
        "",
        "",
        "",
        "IF", // 4784417 (0x490121)
        "",
        "TO", // 5505355 (0x54014b)
        "",
        "",
        "",
        "",
        "",
        "IN", // 4784425 (0x490129)
        "FROM", // 19706306547747710 (0x4602c8099d0b7e)
        "",
        "",
        "RECORD", // 2329319457892298429 (0x205367b4a8136ebd)
        "",
        "",
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
        "VAR", // 369405264923 (0x560245041b)
        "",
        "",
        "",
        "CONST", // 248561333006508435 (0x373113726c02193)
        "",
        "",
        "",
        "AND", // 279203545975 (0x4101d40377)
        "",
        "",
        "",
        "BY", // 4325663 (0x42011f)
        "",
        "",
        "",
        "",
        "EXPORT", // 2067819038152944088 (0x1cb25e759ce569d8)
        "",
        "",
        "",
        "",
        "BEGIN", // 242368234950631377 (0x35d10a025121fd1)
        "",
        "",
        "",
        "POINTER", // 14430062605607326261 (0xc841e17c6ddf5235)
        "",
        "",
        "QUALIFIED", // 2782784495837123956 (0x269e6fc150d61574)
        "",
        "",
        "NOT", // 335043298303 (0x4e022303ff)
        "CASE", // 18861692627323544 (0x43029c08ea0a98)
        "",
        "",
        "",
        "",
        "",
        "UNTIL", // 309082614949947194 (0x44a15002e57273a)
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
        "MOD", // 330747937766 (0x4d021d03e6)
        "",
        "",
        "DIV", // 292089299861 (0x4401e10395)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WITH", // 24491999653989634 (0x5703580b370d02)
        "END", // 296384988059 (0x4501ec039b)
        "",
        "",
        "",
        "",
        "MODULE", // 2236710775997295976 (0x1f0a6499a49b6d68)
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
        "OF", // 5177651 (0x4f0133)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RETURN", // 2334105215428620488 (0x20646853aa0270c8)
        "FOR", // 300680414133 (0x4601f303b5)
        "",
        "OR", // 5177663 (0x4f013f)
        "",
        "",
        "",
        "DO", // 4456731 (0x44011b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IMPORT", // 2131997420225391145 (0x1d96605b9e956a29)
        "SET", // 356519445518 (0x530237040e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PROCEDURE", // 16891062999041638559 (0xea691c4e109f009f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY", // 242650027774648629 (0x35e10ea263f2135)
        "",
        "DEFINITION", // 11412229119462205535 (0x9e6061eb68e9e85f)
        "",
        "",
        "EXIT", // 19424818686331790 (0x4502c509a00b8e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IMPLEMENTATION", // 9926293913137255018 (0x89c147b8e4ab126a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOOP", // 21395375460781064 (0x4c02fb0a2d0c08)
        "THEN", // 23647454458088577 (0x54033c0ad10c81)
        "TYPE", // 23647527479938354 (0x54034d0b420d32)
        "",
    };
    static int values[204] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 4784417 (0x490121)
        -1,
        34, // 5505355 (0x54014b)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 4784425 (0x490129)
        15, // 19706306547747710 (0x4602c8099d0b7e)
        -1,
        -1,
        29, // 2329319457892298429 (0x205367b4a8136ebd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 314149349213742809 (0x45c152b2e4e26d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 369405264923 (0x560245041b)
        -1,
        -1,
        -1,
        5, // 248561333006508435 (0x373113726c02193)
        -1,
        -1,
        -1,
        0, // 279203545975 (0x4101d40377)
        -1,
        -1,
        -1,
        3, // 4325663 (0x42011f)
        -1,
        -1,
        -1,
        -1,
        13, // 2067819038152944088 (0x1cb25e759ce569d8)
        -1,
        -1,
        -1,
        -1,
        2, // 242368234950631377 (0x35d10a025121fd1)
        -1,
        -1,
        -1,
        26, // 14430062605607326261 (0xc841e17c6ddf5235)
        -1,
        -1,
        28, // 2782784495837123956 (0x269e6fc150d61574)
        -1,
        -1,
        23, // 335043298303 (0x4e022303ff)
        4, // 18861692627323544 (0x43029c08ea0a98)
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 309082614949947194 (0x44a15002e57273a)
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
        21, // 330747937766 (0x4d021d03e6)
        -1,
        -1,
        7, // 292089299861 (0x4401e10395)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 24491999653989634 (0x5703580b370d02)
        11, // 296384988059 (0x4501ec039b)
        -1,
        -1,
        -1,
        -1,
        22, // 2236710775997295976 (0x1f0a6499a49b6d68)
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
        30, // 2332979092168994719 (0x2060681fa9256f9f)
        -1,
        -1,
        -1,
        24, // 5177651 (0x4f0133)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 2334105215428620488 (0x20646853aa0270c8)
        14, // 300680414133 (0x4601f303b5)
        -1,
        25, // 5177663 (0x4f013f)
        -1,
        -1,
        -1,
        8, // 4456731 (0x44011b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 2131997420225391145 (0x1d96605b9e956a29)
        32, // 356519445518 (0x530237040e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 16891062999041638559 (0xea691c4e109f009f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 242650027774648629 (0x35e10ea263f2135)
        -1,
        6, // 11412229119462205535 (0x9e6061eb68e9e85f)
        -1,
        -1,
        12, // 19424818686331790 (0x4502c509a00b8e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 9926293913137255018 (0x89c147b8e4ab126a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 21395375460781064 (0x4c02fb0a2d0c08)
        33, // 23647454458088577 (0x54033c0ad10c81)
        35, // 23647527479938354 (0x54034d0b420d32)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_modula2_hash_sdb, dataset=modula2, type=hash, hash=hash_sdb
void check_modula2_hash_sdb() {
    assert(lookup_modula2_hash_sdb("IF") == 16);
    assert(lookup_modula2_hash_sdb("TO") == 34);
    assert(lookup_modula2_hash_sdb("IN") == 19);
    assert(lookup_modula2_hash_sdb("FROM") == 15);
    assert(lookup_modula2_hash_sdb("RECORD") == 29);
    assert(lookup_modula2_hash_sdb("WHILE") == 38);
    assert(lookup_modula2_hash_sdb("VAR") == 37);
    assert(lookup_modula2_hash_sdb("CONST") == 5);
    assert(lookup_modula2_hash_sdb("AND") == 0);
    assert(lookup_modula2_hash_sdb("BY") == 3);
    assert(lookup_modula2_hash_sdb("EXPORT") == 13);
    assert(lookup_modula2_hash_sdb("BEGIN") == 2);
    assert(lookup_modula2_hash_sdb("POINTER") == 26);
    assert(lookup_modula2_hash_sdb("QUALIFIED") == 28);
    assert(lookup_modula2_hash_sdb("NOT") == 23);
    assert(lookup_modula2_hash_sdb("CASE") == 4);
    assert(lookup_modula2_hash_sdb("UNTIL") == 36);
    assert(lookup_modula2_hash_sdb("ELSIF") == 10);
    assert(lookup_modula2_hash_sdb("MOD") == 21);
    assert(lookup_modula2_hash_sdb("DIV") == 7);
    assert(lookup_modula2_hash_sdb("WITH") == 39);
    assert(lookup_modula2_hash_sdb("END") == 11);
    assert(lookup_modula2_hash_sdb("MODULE") == 22);
    assert(lookup_modula2_hash_sdb("ELSE") == 9);
    assert(lookup_modula2_hash_sdb("REPEAT") == 30);
    assert(lookup_modula2_hash_sdb("OF") == 24);
    assert(lookup_modula2_hash_sdb("RETURN") == 31);
    assert(lookup_modula2_hash_sdb("FOR") == 14);
    assert(lookup_modula2_hash_sdb("OR") == 25);
    assert(lookup_modula2_hash_sdb("DO") == 8);
    assert(lookup_modula2_hash_sdb("IMPORT") == 18);
    assert(lookup_modula2_hash_sdb("SET") == 32);
    assert(lookup_modula2_hash_sdb("PROCEDURE") == 27);
    assert(lookup_modula2_hash_sdb("ARRAY") == 1);
    assert(lookup_modula2_hash_sdb("DEFINITION") == 6);
    assert(lookup_modula2_hash_sdb("EXIT") == 12);
    assert(lookup_modula2_hash_sdb("IMPLEMENTATION") == 17);
    assert(lookup_modula2_hash_sdb("LOOP") == 20);
    assert(lookup_modula2_hash_sdb("THEN") == 33);
    assert(lookup_modula2_hash_sdb("TYPE") == 35);
}
