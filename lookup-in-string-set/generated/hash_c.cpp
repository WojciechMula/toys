
//lookup: name=lookup_c_hash1, dataset=c, hash=hash1
int lookup_c_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 151) * 1;
    static std::string_view lookup[151] = {
        "",
        "",
        "default", // 1512 (0x5e8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "register", // 1824 (0x720)
        "",
        "",
        "",
        "typedef", // 1526 (0x5f6)
        "",
        "const", // 1075 (0x433)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "struct", // 1386 (0x56a)
        "",
        "",
        "",
        "",
        "",
        "float", // 1090 (0x442)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 1100 (0x44c)
        "for", // 648 (0x288)
        "case", // 800 (0x320)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 808 (0x328)
        "",
        "",
        "",
        "",
        "extern", // 1266 (0x4f2)
        "int", // 663 (0x297)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "unsigned", // 1736 (0x6c8)
        "static", // 1284 (0x504)
        "auto", // 832 (0x340)
        "union", // 1135 (0x46f)
        "",
        "",
        "",
        "signed", // 1290 (0x50a)
        "",
        "",
        "enum", // 840 (0x348)
        "",
        "",
        "",
        "long", // 844 (0x34c)
        "continue", // 1600 (0x640)
        "volatile", // 1752 (0x6d8)
        "",
        "",
        "sizeof", // 1302 (0x516)
        "",
        "",
        "char", // 852 (0x354)
        "short", // 1155 (0x483)
        "",
        "",
        "goto", // 856 (0x358)
        "",
        "",
        "",
        "",
        "switch", // 1314 (0x522)
        "",
        "",
        "",
        "",
        "",
        "if", // 414 (0x19e)
        "",
        "",
        "",
        "",
        "void", // 872 (0x368)
        "",
        "break", // 1025 (0x401)
        "do", // 422 (0x1a6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "return", // 1344 (0x540)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 1206 (0x4b6)
        "",
    };
    static int values[151] = {
        -1,
        -1,
        27, // 1512 (0x5e8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 1824 (0x720)
        -1,
        -1,
        -1,
        26, // 1526 (0x5f6)
        -1,
        17, // 1075 (0x433)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 1386 (0x56a)
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 1090 (0x442)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 1100 (0x44c)
        3, // 648 (0x288)
        4, // 800 (0x320)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 808 (0x328)
        -1,
        -1,
        -1,
        -1,
        20, // 1266 (0x4f2)
        2, // 663 (0x297)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 1736 (0x6c8)
        19, // 1284 (0x504)
        6, // 832 (0x340)
        14, // 1135 (0x46f)
        -1,
        -1,
        -1,
        25, // 1290 (0x50a)
        -1,
        -1,
        11, // 840 (0x348)
        -1,
        -1,
        -1,
        9, // 844 (0x34c)
        29, // 1600 (0x640)
        31, // 1752 (0x6d8)
        -1,
        -1,
        23, // 1302 (0x516)
        -1,
        -1,
        5, // 852 (0x354)
        13, // 1155 (0x483)
        -1,
        -1,
        7, // 856 (0x358)
        -1,
        -1,
        -1,
        -1,
        24, // 1314 (0x522)
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 414 (0x19e)
        -1,
        -1,
        -1,
        -1,
        10, // 872 (0x368)
        -1,
        15, // 1025 (0x401)
        1, // 422 (0x1a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 1344 (0x540)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 1206 (0x4b6)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_c_hash1, dataset=c, hash=hash1
void check_c_hash1() {
    assert(lookup_c_hash1("default") == 27);
    assert(lookup_c_hash1("register") == 30);
    assert(lookup_c_hash1("typedef") == 26);
    assert(lookup_c_hash1("const") == 17);
    assert(lookup_c_hash1("struct") == 21);
    assert(lookup_c_hash1("float") == 12);
    assert(lookup_c_hash1("while") == 16);
    assert(lookup_c_hash1("for") == 3);
    assert(lookup_c_hash1("case") == 4);
    assert(lookup_c_hash1("else") == 8);
    assert(lookup_c_hash1("extern") == 20);
    assert(lookup_c_hash1("int") == 2);
    assert(lookup_c_hash1("unsigned") == 28);
    assert(lookup_c_hash1("static") == 19);
    assert(lookup_c_hash1("auto") == 6);
    assert(lookup_c_hash1("union") == 14);
    assert(lookup_c_hash1("signed") == 25);
    assert(lookup_c_hash1("enum") == 11);
    assert(lookup_c_hash1("long") == 9);
    assert(lookup_c_hash1("continue") == 29);
    assert(lookup_c_hash1("volatile") == 31);
    assert(lookup_c_hash1("sizeof") == 23);
    assert(lookup_c_hash1("char") == 5);
    assert(lookup_c_hash1("short") == 13);
    assert(lookup_c_hash1("goto") == 7);
    assert(lookup_c_hash1("switch") == 24);
    assert(lookup_c_hash1("if") == 0);
    assert(lookup_c_hash1("void") == 10);
    assert(lookup_c_hash1("break") == 15);
    assert(lookup_c_hash1("do") == 1);
    assert(lookup_c_hash1("return") == 22);
    assert(lookup_c_hash1("double") == 18);
}

//lookup: name=lookup_c_hash2, dataset=c, hash=hash2
int lookup_c_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 152) * 1;
    static std::string_view lookup[152] = {
        "",
        "",
        "",
        "",
        "unsigned", // 11708 (0x2dbc)
        "",
        "do", // 11102 (0x2b5e)
        "",
        "extern", // 11104 (0x2b60)
        "",
        "",
        "",
        "",
        "",
        "while", // 12022 (0x2ef6)
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 10205 (0x27dd)
        "",
        "int", // 12183 (0x2f97)
        "long", // 11120 (0x2b70)
        "",
        "",
        "",
        "sizeof", // 11732 (0x2dd4)
        "",
        "",
        "",
        "",
        "",
        "char", // 11282 (0x2c12)
        "",
        "",
        "goto", // 11437 (0x2cad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "volatile", // 11910 (0x2e86)
        "default", // 11607 (0x2d57)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 10098 (0x2772)
        "",
        "if", // 10708 (0x29d4)
        "enum", // 11013 (0x2b05)
        "",
        "",
        "",
        "",
        "return", // 12538 (0x30fa)
        "",
        "",
        "",
        "",
        "for", // 11631 (0x2d6f)
        "",
        "const", // 11481 (0x2cd9)
        "",
        "",
        "register", // 13004 (0x32cc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "signed", // 11498 (0x2cea)
        "union", // 12867 (0x3243)
        "void", // 11804 (0x2e1c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "switch", // 11966 (0x2ebe)
        "continue", // 9991 (0x2707)
        "",
        "short", // 13337 (0x3419)
        "struct", // 13338 (0x341a)
        "case", // 9995 (0x270b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "auto", // 10763 (0x2a0b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "float", // 11837 (0x2e3d)
        "",
        "typedef", // 11839 (0x2e3f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "static", // 11391 (0x2c7f)
        "",
        "",
        "",
        "break", // 10483 (0x28f3)
        "",
        "",
        "",
        "",
    };
    static int values[152] = {
        -1,
        -1,
        -1,
        -1,
        28, // 11708 (0x2dbc)
        -1,
        1, // 11102 (0x2b5e)
        -1,
        20, // 11104 (0x2b60)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 12022 (0x2ef6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 10205 (0x27dd)
        -1,
        2, // 12183 (0x2f97)
        9, // 11120 (0x2b70)
        -1,
        -1,
        -1,
        23, // 11732 (0x2dd4)
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 11282 (0x2c12)
        -1,
        -1,
        7, // 11437 (0x2cad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 11910 (0x2e86)
        27, // 11607 (0x2d57)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 10098 (0x2772)
        -1,
        0, // 10708 (0x29d4)
        11, // 11013 (0x2b05)
        -1,
        -1,
        -1,
        -1,
        22, // 12538 (0x30fa)
        -1,
        -1,
        -1,
        -1,
        3, // 11631 (0x2d6f)
        -1,
        17, // 11481 (0x2cd9)
        -1,
        -1,
        30, // 13004 (0x32cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 11498 (0x2cea)
        14, // 12867 (0x3243)
        10, // 11804 (0x2e1c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 11966 (0x2ebe)
        29, // 9991 (0x2707)
        -1,
        13, // 13337 (0x3419)
        21, // 13338 (0x341a)
        4, // 9995 (0x270b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 10763 (0x2a0b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 11837 (0x2e3d)
        -1,
        26, // 11839 (0x2e3f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 11391 (0x2c7f)
        -1,
        -1,
        -1,
        15, // 10483 (0x28f3)
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

//check: name=check_c_hash2, dataset=c, hash=hash2
void check_c_hash2() {
    assert(lookup_c_hash2("unsigned") == 28);
    assert(lookup_c_hash2("do") == 1);
    assert(lookup_c_hash2("extern") == 20);
    assert(lookup_c_hash2("while") == 16);
    assert(lookup_c_hash2("else") == 8);
    assert(lookup_c_hash2("int") == 2);
    assert(lookup_c_hash2("long") == 9);
    assert(lookup_c_hash2("sizeof") == 23);
    assert(lookup_c_hash2("char") == 5);
    assert(lookup_c_hash2("goto") == 7);
    assert(lookup_c_hash2("volatile") == 31);
    assert(lookup_c_hash2("default") == 27);
    assert(lookup_c_hash2("double") == 18);
    assert(lookup_c_hash2("if") == 0);
    assert(lookup_c_hash2("enum") == 11);
    assert(lookup_c_hash2("return") == 22);
    assert(lookup_c_hash2("for") == 3);
    assert(lookup_c_hash2("const") == 17);
    assert(lookup_c_hash2("register") == 30);
    assert(lookup_c_hash2("signed") == 25);
    assert(lookup_c_hash2("union") == 14);
    assert(lookup_c_hash2("void") == 10);
    assert(lookup_c_hash2("switch") == 24);
    assert(lookup_c_hash2("continue") == 29);
    assert(lookup_c_hash2("short") == 13);
    assert(lookup_c_hash2("struct") == 21);
    assert(lookup_c_hash2("case") == 4);
    assert(lookup_c_hash2("auto") == 6);
    assert(lookup_c_hash2("float") == 12);
    assert(lookup_c_hash2("typedef") == 26);
    assert(lookup_c_hash2("static") == 19);
    assert(lookup_c_hash2("break") == 15);
}

//lookup: name=lookup_c_hash3, dataset=c, hash=hash3
int lookup_c_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 121) * 1;
    static std::string_view lookup[121] = {
        "",
        "",
        "register", // 31583 (0x7b5f)
        "",
        "",
        "",
        "",
        "typedef", // 31830 (0x7c56)
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 26634 (0x680a)
        "extern", // 27724 (0x6c4c)
        "auto", // 26152 (0x6628)
        "",
        "",
        "default", // 27728 (0x6c50)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "continue", // 27740 (0x6c5c)
        "",
        "",
        "char", // 26654 (0x681e)
        "long", // 28954 (0x711a)
        "",
        "",
        "",
        "unsigned", // 32346 (0x7e5a)
        "",
        "",
        "if", // 27630 (0x6bee)
        "",
        "",
        "",
        "",
        "",
        "",
        "short", // 31025 (0x7931)
        "",
        "void", // 31511 (0x7b17)
        "for", // 27156 (0x6a14)
        "else", // 27157 (0x6a15)
        "break", // 26674 (0x6832)
        "volatile", // 32604 (0x7f5c)
        "",
        "return", // 31033 (0x7939)
        "",
        "",
        "",
        "",
        "",
        "enum", // 27167 (0x6a1f)
        "",
        "signed", // 31283 (0x7a33)
        "",
        "sizeof", // 31285 (0x7a35)
        "",
        "",
        "",
        "",
        "",
        "",
        "const", // 26936 (0x6938)
        "static", // 31293 (0x7a3d)
        "",
        "union", // 31537 (0x7b31)
        "",
        "",
        "",
        "",
        "",
        "switch", // 31301 (0x7a45)
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 32034 (0x7d22)
        "",
        "struct", // 31310 (0x7a4e)
        "",
        "goto", // 27682 (0x6c22)
        "int", // 27925 (0x6d15)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 27450 (0x6b3a)
        "",
        "",
        "",
        "",
        "",
        "",
        "do", // 26368 (0x6700)
        "",
        "float", // 27701 (0x6c35)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[121] = {
        -1,
        -1,
        30, // 31583 (0x7b5f)
        -1,
        -1,
        -1,
        -1,
        26, // 31830 (0x7c56)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 26634 (0x680a)
        20, // 27724 (0x6c4c)
        6, // 26152 (0x6628)
        -1,
        -1,
        27, // 27728 (0x6c50)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 27740 (0x6c5c)
        -1,
        -1,
        5, // 26654 (0x681e)
        9, // 28954 (0x711a)
        -1,
        -1,
        -1,
        28, // 32346 (0x7e5a)
        -1,
        -1,
        0, // 27630 (0x6bee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 31025 (0x7931)
        -1,
        10, // 31511 (0x7b17)
        3, // 27156 (0x6a14)
        8, // 27157 (0x6a15)
        15, // 26674 (0x6832)
        31, // 32604 (0x7f5c)
        -1,
        22, // 31033 (0x7939)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 27167 (0x6a1f)
        -1,
        25, // 31283 (0x7a33)
        -1,
        23, // 31285 (0x7a35)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 26936 (0x6938)
        19, // 31293 (0x7a3d)
        -1,
        14, // 31537 (0x7b31)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 31301 (0x7a45)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 32034 (0x7d22)
        -1,
        21, // 31310 (0x7a4e)
        -1,
        7, // 27682 (0x6c22)
        2, // 27925 (0x6d15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 27450 (0x6b3a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 26368 (0x6700)
        -1,
        12, // 27701 (0x6c35)
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

//check: name=check_c_hash3, dataset=c, hash=hash3
void check_c_hash3() {
    assert(lookup_c_hash3("register") == 30);
    assert(lookup_c_hash3("typedef") == 26);
    assert(lookup_c_hash3("case") == 4);
    assert(lookup_c_hash3("extern") == 20);
    assert(lookup_c_hash3("auto") == 6);
    assert(lookup_c_hash3("default") == 27);
    assert(lookup_c_hash3("continue") == 29);
    assert(lookup_c_hash3("char") == 5);
    assert(lookup_c_hash3("long") == 9);
    assert(lookup_c_hash3("unsigned") == 28);
    assert(lookup_c_hash3("if") == 0);
    assert(lookup_c_hash3("short") == 13);
    assert(lookup_c_hash3("void") == 10);
    assert(lookup_c_hash3("for") == 3);
    assert(lookup_c_hash3("else") == 8);
    assert(lookup_c_hash3("break") == 15);
    assert(lookup_c_hash3("volatile") == 31);
    assert(lookup_c_hash3("return") == 22);
    assert(lookup_c_hash3("enum") == 11);
    assert(lookup_c_hash3("signed") == 25);
    assert(lookup_c_hash3("sizeof") == 23);
    assert(lookup_c_hash3("const") == 17);
    assert(lookup_c_hash3("static") == 19);
    assert(lookup_c_hash3("union") == 14);
    assert(lookup_c_hash3("switch") == 24);
    assert(lookup_c_hash3("while") == 16);
    assert(lookup_c_hash3("struct") == 21);
    assert(lookup_c_hash3("goto") == 7);
    assert(lookup_c_hash3("int") == 2);
    assert(lookup_c_hash3("double") == 18);
    assert(lookup_c_hash3("do") == 1);
    assert(lookup_c_hash3("float") == 12);
}

//lookup: name=lookup_c_hash_sum0, dataset=c, hash=hash_sum0
int lookup_c_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 45) * 2;
    static std::string_view lookup[90] = {
        "",
        "",
        "",
        "",
        "struct", // 677 (0x2a5)
        "",
        "",
        "",
        "signed", // 634 (0x27a)
        "",
        "double", // 635 (0x27b)
        "",
        "unsigned", // 861 (0x35d)
        "",
        "case", // 412 (0x19c)
        "",
        "",
        "",
        "char", // 414 (0x19e)
        "volatile", // 864 (0x360)
        "",
        "",
        "const", // 551 (0x227)
        "",
        "for", // 327 (0x147)
        "",
        "union", // 553 (0x229)
        "",
        "continue", // 869 (0x365)
        "register", // 869 (0x365)
        "",
        "",
        "int", // 331 (0x14b)
        "",
        "",
        "",
        "static", // 648 (0x288)
        "",
        "",
        "",
        "else", // 425 (0x1a9)
        "short", // 560 (0x230)
        "default", // 741 (0x2e5)
        "",
        "break", // 517 (0x205)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "sizeof", // 656 (0x290)
        "",
        "if", // 207 (0xcf)
        "long", // 432 (0x1b0)
        "switch", // 658 (0x292)
        "",
        "void", // 434 (0x1b2)
        "",
        "",
        "",
        "do", // 211 (0xd3)
        "",
        "enum", // 437 (0x1b5)
        "extern", // 662 (0x296)
        "typedef", // 753 (0x2f1)
        "",
        "",
        "",
        "",
        "",
        "auto", // 441 (0x1b9)
        "goto", // 441 (0x1b9)
        "",
        "",
        "",
        "",
        "float", // 534 (0x216)
        "",
        "",
        "",
        "",
        "",
        "while", // 537 (0x219)
        "return", // 672 (0x2a0)
        "",
        "",
        "",
        "",
    };
    static int values[90] = {
        -1,
        -1,
        -1,
        -1,
        21, // 677 (0x2a5)
        -1,
        -1,
        -1,
        25, // 634 (0x27a)
        -1,
        18, // 635 (0x27b)
        -1,
        28, // 861 (0x35d)
        -1,
        4, // 412 (0x19c)
        -1,
        -1,
        -1,
        5, // 414 (0x19e)
        31, // 864 (0x360)
        -1,
        -1,
        17, // 551 (0x227)
        -1,
        3, // 327 (0x147)
        -1,
        14, // 553 (0x229)
        -1,
        29, // 869 (0x365)
        30, // 869 (0x365)
        -1,
        -1,
        2, // 331 (0x14b)
        -1,
        -1,
        -1,
        19, // 648 (0x288)
        -1,
        -1,
        -1,
        8, // 425 (0x1a9)
        13, // 560 (0x230)
        27, // 741 (0x2e5)
        -1,
        15, // 517 (0x205)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 656 (0x290)
        -1,
        0, // 207 (0xcf)
        9, // 432 (0x1b0)
        24, // 658 (0x292)
        -1,
        10, // 434 (0x1b2)
        -1,
        -1,
        -1,
        1, // 211 (0xd3)
        -1,
        11, // 437 (0x1b5)
        20, // 662 (0x296)
        26, // 753 (0x2f1)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 441 (0x1b9)
        7, // 441 (0x1b9)
        -1,
        -1,
        -1,
        -1,
        12, // 534 (0x216)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 537 (0x219)
        22, // 672 (0x2a0)
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

//check: name=check_c_hash_sum0, dataset=c, hash=hash_sum0
void check_c_hash_sum0() {
    assert(lookup_c_hash_sum0("struct") == 21);
    assert(lookup_c_hash_sum0("signed") == 25);
    assert(lookup_c_hash_sum0("double") == 18);
    assert(lookup_c_hash_sum0("unsigned") == 28);
    assert(lookup_c_hash_sum0("case") == 4);
    assert(lookup_c_hash_sum0("char") == 5);
    assert(lookup_c_hash_sum0("volatile") == 31);
    assert(lookup_c_hash_sum0("const") == 17);
    assert(lookup_c_hash_sum0("for") == 3);
    assert(lookup_c_hash_sum0("union") == 14);
    assert(lookup_c_hash_sum0("continue") == 29);
    assert(lookup_c_hash_sum0("register") == 30);
    assert(lookup_c_hash_sum0("int") == 2);
    assert(lookup_c_hash_sum0("static") == 19);
    assert(lookup_c_hash_sum0("else") == 8);
    assert(lookup_c_hash_sum0("short") == 13);
    assert(lookup_c_hash_sum0("default") == 27);
    assert(lookup_c_hash_sum0("break") == 15);
    assert(lookup_c_hash_sum0("sizeof") == 23);
    assert(lookup_c_hash_sum0("if") == 0);
    assert(lookup_c_hash_sum0("long") == 9);
    assert(lookup_c_hash_sum0("switch") == 24);
    assert(lookup_c_hash_sum0("void") == 10);
    assert(lookup_c_hash_sum0("do") == 1);
    assert(lookup_c_hash_sum0("enum") == 11);
    assert(lookup_c_hash_sum0("extern") == 20);
    assert(lookup_c_hash_sum0("typedef") == 26);
    assert(lookup_c_hash_sum0("auto") == 6);
    assert(lookup_c_hash_sum0("goto") == 7);
    assert(lookup_c_hash_sum0("float") == 12);
    assert(lookup_c_hash_sum0("while") == 16);
    assert(lookup_c_hash_sum0("return") == 22);
}

//lookup: name=lookup_c_hash_sumN, dataset=c, hash=hash_sumN
int lookup_c_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 50) * 2;
    static std::string_view lookup[100] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "static", // 654 (0x28e)
        "",
        "",
        "",
        "const", // 556 (0x22c)
        "",
        "",
        "",
        "union", // 558 (0x22e)
        "",
        "if", // 209 (0xd1)
        "",
        "typedef", // 760 (0x2f8)
        "",
        "",
        "",
        "sizeof", // 662 (0x296)
        "",
        "do", // 213 (0xd5)
        "",
        "switch", // 664 (0x298)
        "",
        "short", // 565 (0x235)
        "",
        "case", // 416 (0x1a0)
        "",
        "",
        "",
        "char", // 418 (0x1a2)
        "extern", // 668 (0x29c)
        "unsigned", // 869 (0x365)
        "",
        "",
        "",
        "",
        "",
        "break", // 522 (0x20a)
        "volatile", // 872 (0x368)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "continue", // 877 (0x36d)
        "register", // 877 (0x36d)
        "return", // 678 (0x2a6)
        "",
        "else", // 429 (0x1ad)
        "",
        "for", // 330 (0x14a)
        "",
        "",
        "",
        "",
        "",
        "struct", // 683 (0x2ab)
        "",
        "int", // 334 (0x14e)
        "",
        "",
        "",
        "long", // 436 (0x1b4)
        "",
        "",
        "",
        "void", // 438 (0x1b6)
        "",
        "float", // 539 (0x21b)
        "",
        "signed", // 640 (0x280)
        "",
        "enum", // 441 (0x1b9)
        "double", // 641 (0x281)
        "while", // 542 (0x21e)
        "",
        "",
        "",
        "",
        "",
        "auto", // 445 (0x1bd)
        "goto", // 445 (0x1bd)
        "",
        "",
        "",
        "",
        "default", // 748 (0x2ec)
        "",
        "",
        "",
    };
    static int values[100] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 654 (0x28e)
        -1,
        -1,
        -1,
        17, // 556 (0x22c)
        -1,
        -1,
        -1,
        14, // 558 (0x22e)
        -1,
        0, // 209 (0xd1)
        -1,
        26, // 760 (0x2f8)
        -1,
        -1,
        -1,
        23, // 662 (0x296)
        -1,
        1, // 213 (0xd5)
        -1,
        24, // 664 (0x298)
        -1,
        13, // 565 (0x235)
        -1,
        4, // 416 (0x1a0)
        -1,
        -1,
        -1,
        5, // 418 (0x1a2)
        20, // 668 (0x29c)
        28, // 869 (0x365)
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 522 (0x20a)
        31, // 872 (0x368)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 877 (0x36d)
        30, // 877 (0x36d)
        22, // 678 (0x2a6)
        -1,
        8, // 429 (0x1ad)
        -1,
        3, // 330 (0x14a)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 683 (0x2ab)
        -1,
        2, // 334 (0x14e)
        -1,
        -1,
        -1,
        9, // 436 (0x1b4)
        -1,
        -1,
        -1,
        10, // 438 (0x1b6)
        -1,
        12, // 539 (0x21b)
        -1,
        25, // 640 (0x280)
        -1,
        11, // 441 (0x1b9)
        18, // 641 (0x281)
        16, // 542 (0x21e)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 445 (0x1bd)
        7, // 445 (0x1bd)
        -1,
        -1,
        -1,
        -1,
        27, // 748 (0x2ec)
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

//check: name=check_c_hash_sumN, dataset=c, hash=hash_sumN
void check_c_hash_sumN() {
    assert(lookup_c_hash_sumN("static") == 19);
    assert(lookup_c_hash_sumN("const") == 17);
    assert(lookup_c_hash_sumN("union") == 14);
    assert(lookup_c_hash_sumN("if") == 0);
    assert(lookup_c_hash_sumN("typedef") == 26);
    assert(lookup_c_hash_sumN("sizeof") == 23);
    assert(lookup_c_hash_sumN("do") == 1);
    assert(lookup_c_hash_sumN("switch") == 24);
    assert(lookup_c_hash_sumN("short") == 13);
    assert(lookup_c_hash_sumN("case") == 4);
    assert(lookup_c_hash_sumN("char") == 5);
    assert(lookup_c_hash_sumN("extern") == 20);
    assert(lookup_c_hash_sumN("unsigned") == 28);
    assert(lookup_c_hash_sumN("break") == 15);
    assert(lookup_c_hash_sumN("volatile") == 31);
    assert(lookup_c_hash_sumN("continue") == 29);
    assert(lookup_c_hash_sumN("register") == 30);
    assert(lookup_c_hash_sumN("return") == 22);
    assert(lookup_c_hash_sumN("else") == 8);
    assert(lookup_c_hash_sumN("for") == 3);
    assert(lookup_c_hash_sumN("struct") == 21);
    assert(lookup_c_hash_sumN("int") == 2);
    assert(lookup_c_hash_sumN("long") == 9);
    assert(lookup_c_hash_sumN("void") == 10);
    assert(lookup_c_hash_sumN("float") == 12);
    assert(lookup_c_hash_sumN("signed") == 25);
    assert(lookup_c_hash_sumN("enum") == 11);
    assert(lookup_c_hash_sumN("double") == 18);
    assert(lookup_c_hash_sumN("while") == 16);
    assert(lookup_c_hash_sumN("auto") == 6);
    assert(lookup_c_hash_sumN("goto") == 7);
    assert(lookup_c_hash_sumN("default") == 27);
}

//lookup: name=lookup_c_hash_djb2, dataset=c, hash=hash_djb2
int lookup_c_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 109) * 1;
    static std::string_view lookup[109] = {
        "",
        "do", // 5972220 (0x5b20fc)
        "int", // 197088788 (0xbbf5614)
        "",
        "float", // 214626058367 (0x31f8b5c07f)
        "struct", // 7083178302734 (0x6712e539d0e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "enum", // 6503786398 (0x183a7e79e)
        "",
        "",
        "",
        "",
        "case", // 6503700293 (0x183a69745)
        "sizeof", // 7083165528057 (0x6712d90aff9)
        "",
        "break", // 214621519406 (0x31f8707e2e)
        "",
        "continue", // 7712892661735406 (0x1b66d5c34b1fee)
        "goto", // 6503859330 (0x183a90482)
        "typedef", // 233746368189018 (0xd497513e525a)
        "",
        "void", // 6504398011 (0x183b13cbb)
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 7082585429636 (0x6710afd1684)
        "",
        "for", // 197085552 (0xbbf4970)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 5972376 (0x5b2198)
        "",
        "else", // 6503784146 (0x183a7ded2)
        "",
        "",
        "return", // 7083121450889 (0x6712af01f89)
        "",
        "",
        "short", // 214641332153 (0x31f99ecfb9)
        "",
        "default", // 233724910009454 (0xd492523c7c6e)
        "",
        "",
        "const", // 214622607920 (0x31f8811a30)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 214646069090 (0x31f9e71762)
        "",
        "volatile", // 7713702311738249 (0x1b67924631bb89)
        "",
        "",
        "switch", // 7083181535963 (0x6712e84f2db)
        "",
        "",
        "",
        "register", // 7713518737072878 (0x1b6767884aa2ee)
        "",
        "",
        "",
        "char", // 6503707335 (0x183a6b2c7)
        "",
        "",
        "signed", // 7083164854723 (0x6712d8669c3)
        "union", // 214643912978 (0x31f9c63112)
        "long", // 6504038809 (0x183abc199)
        "",
        "",
        "",
        "",
        "static", // 7083177690897 (0x6712e4a4711)
        "extern", // 7082635205855 (0x6710df49cdf)
        "",
        "",
        "",
        "",
        "",
        "",
        "unsigned", // 7713658684800454 (0x1b67881dd37dc6)
        "",
        "",
        "",
        "",
        "auto", // 6503650242 (0x183a5d3c2)
        "",
    };
    static int values[109] = {
        -1,
        1, // 5972220 (0x5b20fc)
        2, // 197088788 (0xbbf5614)
        -1,
        12, // 214626058367 (0x31f8b5c07f)
        21, // 7083178302734 (0x6712e539d0e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 6503786398 (0x183a7e79e)
        -1,
        -1,
        -1,
        -1,
        4, // 6503700293 (0x183a69745)
        23, // 7083165528057 (0x6712d90aff9)
        -1,
        15, // 214621519406 (0x31f8707e2e)
        -1,
        29, // 7712892661735406 (0x1b66d5c34b1fee)
        7, // 6503859330 (0x183a90482)
        26, // 233746368189018 (0xd497513e525a)
        -1,
        10, // 6504398011 (0x183b13cbb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 7082585429636 (0x6710afd1684)
        -1,
        3, // 197085552 (0xbbf4970)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 5972376 (0x5b2198)
        -1,
        8, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        22, // 7083121450889 (0x6712af01f89)
        -1,
        -1,
        13, // 214641332153 (0x31f99ecfb9)
        -1,
        27, // 233724910009454 (0xd492523c7c6e)
        -1,
        -1,
        17, // 214622607920 (0x31f8811a30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 214646069090 (0x31f9e71762)
        -1,
        31, // 7713702311738249 (0x1b67924631bb89)
        -1,
        -1,
        24, // 7083181535963 (0x6712e84f2db)
        -1,
        -1,
        -1,
        30, // 7713518737072878 (0x1b6767884aa2ee)
        -1,
        -1,
        -1,
        5, // 6503707335 (0x183a6b2c7)
        -1,
        -1,
        25, // 7083164854723 (0x6712d8669c3)
        14, // 214643912978 (0x31f9c63112)
        9, // 6504038809 (0x183abc199)
        -1,
        -1,
        -1,
        -1,
        19, // 7083177690897 (0x6712e4a4711)
        20, // 7082635205855 (0x6710df49cdf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 7713658684800454 (0x1b67881dd37dc6)
        -1,
        -1,
        -1,
        -1,
        6, // 6503650242 (0x183a5d3c2)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_c_hash_djb2, dataset=c, hash=hash_djb2
void check_c_hash_djb2() {
    assert(lookup_c_hash_djb2("do") == 1);
    assert(lookup_c_hash_djb2("int") == 2);
    assert(lookup_c_hash_djb2("float") == 12);
    assert(lookup_c_hash_djb2("struct") == 21);
    assert(lookup_c_hash_djb2("enum") == 11);
    assert(lookup_c_hash_djb2("case") == 4);
    assert(lookup_c_hash_djb2("sizeof") == 23);
    assert(lookup_c_hash_djb2("break") == 15);
    assert(lookup_c_hash_djb2("continue") == 29);
    assert(lookup_c_hash_djb2("goto") == 7);
    assert(lookup_c_hash_djb2("typedef") == 26);
    assert(lookup_c_hash_djb2("void") == 10);
    assert(lookup_c_hash_djb2("double") == 18);
    assert(lookup_c_hash_djb2("for") == 3);
    assert(lookup_c_hash_djb2("if") == 0);
    assert(lookup_c_hash_djb2("else") == 8);
    assert(lookup_c_hash_djb2("return") == 22);
    assert(lookup_c_hash_djb2("short") == 13);
    assert(lookup_c_hash_djb2("default") == 27);
    assert(lookup_c_hash_djb2("const") == 17);
    assert(lookup_c_hash_djb2("while") == 16);
    assert(lookup_c_hash_djb2("volatile") == 31);
    assert(lookup_c_hash_djb2("switch") == 24);
    assert(lookup_c_hash_djb2("register") == 30);
    assert(lookup_c_hash_djb2("char") == 5);
    assert(lookup_c_hash_djb2("signed") == 25);
    assert(lookup_c_hash_djb2("union") == 14);
    assert(lookup_c_hash_djb2("long") == 9);
    assert(lookup_c_hash_djb2("static") == 19);
    assert(lookup_c_hash_djb2("extern") == 20);
    assert(lookup_c_hash_djb2("unsigned") == 28);
    assert(lookup_c_hash_djb2("auto") == 6);
}

//lookup: name=lookup_c_hash_sdb, dataset=c, hash=hash_sdb
int lookup_c_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 131) * 1;
    static std::string_view lookup[131] = {
        "",
        "",
        "",
        "",
        "",
        "if", // 6881697 (0x6901a1)
        "",
        "",
        "auto", // 27307324983808035 (0x6103de0d6d1023)
        "",
        "",
        "",
        "static", // 3332546763507343818 (0x2e3f959ff43ba1ca)
        "",
        "case", // 27870266342903704 (0x6303dc0d2a0f98)
        "extern", // 2996732478728017764 (0x2996884fe1759764)
        "char", // 27870296409247662 (0x6303e30d420fae)
        "",
        "",
        "",
        "",
        "",
        "",
        "register", // 17087298121750970967 (0xed22471bfe2a8257)
        "",
        "void", // 33219085507826168 (0x7604950f7511f8)
        "signed", // 3297078571319795376 (0x2dc1937df0119eb0)
        "for", // 438134048085 (0x6602d30555)
        "sizeof", // 3302427291692736640 (0x2dd4941ff1e6a080)
        "",
        "",
        "typedef", // 2657618279341420639 (0x24e1c1be90baf05f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "goto", // 28996381010759823 (0x67040e0deb108f)
        "",
        "",
        "",
        "",
        "enum", // 28433349449093201 (0x6503fb0db01051)
        "",
        "",
        "float", // 374952978071105832 (0x53419bf39673128)
        "",
        "default", // 18130751609074855161 (0xfb9d5e8711bfacf9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "volatile", // 3452512564192461556 (0x2fe9c9e28b43c2f4)
        "else", // 28433340858241073 (0x6503f90da21031)
        "",
        "",
        "const", // 365663719708962995 (0x5131937388030b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "long", // 30403949176295676 (0x6c043b0e6c10fc)
        "",
        "",
        "",
        "return", // 3261892644424556104 (0x2d449213ee629e48)
        "",
        "",
        "unsigned", // 2703208532253982581 (0x2583b9d67ecdbf75)
        "",
        "",
        "",
        "do", // 6554011 (0x64019b)
        "",
        "",
        "",
        "break", // 363130290293256227 (0x50a1913381d3023)
        "",
        "",
        "",
        "",
        "while", // 431251735916197369 (0x5fc1d2b400e35f9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "int", // 451020064111 (0x6902e4056f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "short", // 417740035065394444 (0x5cc1c593e88350c)
        "",
        "union", // 426184954403829259 (0x5ea1cf53fdb360b)
        "",
        "",
        "",
        "",
        "continue", // 6848942472000841643 (0x5f0c54e41ab227ab)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "struct", // 3337332499566470045 (0x2e509639f606a39d)
        "",
        "",
        "switch", // 3344932667539956616 (0x2e6b9689f651a388)
        "",
        "",
        "double", // 2941278687000499069 (0x28d18561dc17937d)
        "",
        "",
    };
    static int values[131] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 6881697 (0x6901a1)
        -1,
        -1,
        6, // 27307324983808035 (0x6103de0d6d1023)
        -1,
        -1,
        -1,
        19, // 3332546763507343818 (0x2e3f959ff43ba1ca)
        -1,
        4, // 27870266342903704 (0x6303dc0d2a0f98)
        20, // 2996732478728017764 (0x2996884fe1759764)
        5, // 27870296409247662 (0x6303e30d420fae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 17087298121750970967 (0xed22471bfe2a8257)
        -1,
        10, // 33219085507826168 (0x7604950f7511f8)
        25, // 3297078571319795376 (0x2dc1937df0119eb0)
        3, // 438134048085 (0x6602d30555)
        23, // 3302427291692736640 (0x2dd4941ff1e6a080)
        -1,
        -1,
        26, // 2657618279341420639 (0x24e1c1be90baf05f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 28996381010759823 (0x67040e0deb108f)
        -1,
        -1,
        -1,
        -1,
        11, // 28433349449093201 (0x6503fb0db01051)
        -1,
        -1,
        12, // 374952978071105832 (0x53419bf39673128)
        -1,
        27, // 18130751609074855161 (0xfb9d5e8711bfacf9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 3452512564192461556 (0x2fe9c9e28b43c2f4)
        8, // 28433340858241073 (0x6503f90da21031)
        -1,
        -1,
        17, // 365663719708962995 (0x5131937388030b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 30403949176295676 (0x6c043b0e6c10fc)
        -1,
        -1,
        -1,
        22, // 3261892644424556104 (0x2d449213ee629e48)
        -1,
        -1,
        28, // 2703208532253982581 (0x2583b9d67ecdbf75)
        -1,
        -1,
        -1,
        1, // 6554011 (0x64019b)
        -1,
        -1,
        -1,
        15, // 363130290293256227 (0x50a1913381d3023)
        -1,
        -1,
        -1,
        -1,
        16, // 431251735916197369 (0x5fc1d2b400e35f9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 451020064111 (0x6902e4056f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 417740035065394444 (0x5cc1c593e88350c)
        -1,
        14, // 426184954403829259 (0x5ea1cf53fdb360b)
        -1,
        -1,
        -1,
        -1,
        29, // 6848942472000841643 (0x5f0c54e41ab227ab)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 3337332499566470045 (0x2e509639f606a39d)
        -1,
        -1,
        24, // 3344932667539956616 (0x2e6b9689f651a388)
        -1,
        -1,
        18, // 2941278687000499069 (0x28d18561dc17937d)
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

//check: name=check_c_hash_sdb, dataset=c, hash=hash_sdb
void check_c_hash_sdb() {
    assert(lookup_c_hash_sdb("if") == 0);
    assert(lookup_c_hash_sdb("auto") == 6);
    assert(lookup_c_hash_sdb("static") == 19);
    assert(lookup_c_hash_sdb("case") == 4);
    assert(lookup_c_hash_sdb("extern") == 20);
    assert(lookup_c_hash_sdb("char") == 5);
    assert(lookup_c_hash_sdb("register") == 30);
    assert(lookup_c_hash_sdb("void") == 10);
    assert(lookup_c_hash_sdb("signed") == 25);
    assert(lookup_c_hash_sdb("for") == 3);
    assert(lookup_c_hash_sdb("sizeof") == 23);
    assert(lookup_c_hash_sdb("typedef") == 26);
    assert(lookup_c_hash_sdb("goto") == 7);
    assert(lookup_c_hash_sdb("enum") == 11);
    assert(lookup_c_hash_sdb("float") == 12);
    assert(lookup_c_hash_sdb("default") == 27);
    assert(lookup_c_hash_sdb("volatile") == 31);
    assert(lookup_c_hash_sdb("else") == 8);
    assert(lookup_c_hash_sdb("const") == 17);
    assert(lookup_c_hash_sdb("long") == 9);
    assert(lookup_c_hash_sdb("return") == 22);
    assert(lookup_c_hash_sdb("unsigned") == 28);
    assert(lookup_c_hash_sdb("do") == 1);
    assert(lookup_c_hash_sdb("break") == 15);
    assert(lookup_c_hash_sdb("while") == 16);
    assert(lookup_c_hash_sdb("int") == 2);
    assert(lookup_c_hash_sdb("short") == 13);
    assert(lookup_c_hash_sdb("union") == 14);
    assert(lookup_c_hash_sdb("continue") == 29);
    assert(lookup_c_hash_sdb("struct") == 21);
    assert(lookup_c_hash_sdb("switch") == 24);
    assert(lookup_c_hash_sdb("double") == 18);
}
