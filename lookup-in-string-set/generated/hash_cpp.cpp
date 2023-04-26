
//lookup: name=lookup_cpp_hash1, dataset=cpp, hash=hash1
int lookup_cpp_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 85) * 2;
    static std::string_view lookup[170] = {
        "",
        "",
        "",
        "",
        "char", // 852 (0x354)
        "",
        "",
        "",
        "",
        "",
        "break", // 1025 (0x401)
        "",
        "goto", // 856 (0x358)
        "",
        "new", // 687 (0x2af)
        "",
        "",
        "",
        "static", // 1284 (0x504)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "operator", // 1800 (0x708)
        "signed", // 1290 (0x50a)
        "delete", // 1206 (0x4b6)
        "double", // 1206 (0x4b6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "friend", // 1212 (0x4bc)
        "void", // 872 (0x368)
        "asm", // 618 (0x26a)
        "",
        "",
        "",
        "",
        "",
        "struct", // 1386 (0x56a)
        "",
        "sizeof", // 1302 (0x516)
        "",
        "",
        "",
        "",
        "",
        "union", // 1135 (0x46f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 800 (0x320)
        "",
        "template", // 1736 (0x6c8)
        "unsigned", // 1736 (0x6c8)
        "",
        "",
        "protected", // 1908 (0x774)
        "",
        "register", // 1824 (0x720)
        "switch", // 1314 (0x522)
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
        "",
        "inline", // 1236 (0x4d4)
        "private", // 1491 (0x5d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "class", // 1070 (0x42e)
        "short", // 1155 (0x483)
        "",
        "",
        "virtual", // 1582 (0x62e)
        "volatile", // 1752 (0x6d8)
        "for", // 648 (0x288)
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "auto", // 832 (0x340)
        "default", // 1512 (0x5e8)
        "int", // 663 (0x297)
        "",
        "return", // 1344 (0x540)
        "",
        "continue", // 1600 (0x640)
        "float", // 1090 (0x442)
        "",
        "",
        "",
        "",
        "overload", // 1688 (0x698)
        "",
        "if", // 414 (0x19e)
        "this", // 924 (0x39c)
        "enum", // 840 (0x348)
        "",
        "extern", // 1266 (0x4f2)
        "public", // 1266 (0x4f2)
        "",
        "",
        "",
        "",
        "long", // 844 (0x34c)
        "",
        "catch", // 1015 (0x3f7)
        "while", // 1100 (0x44c)
        "typedef", // 1526 (0x5f6)
        "",
        "do", // 422 (0x1a6)
        "",
        "",
        "",
        "",
        "",
    };
    static int values[170] = {
        -1,
        -1,
        -1,
        -1,
        5, // 852 (0x354)
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 1025 (0x401)
        -1,
        19, // 856 (0x358)
        -1,
        24, // 687 (0x2af)
        -1,
        -1,
        -1,
        35, // 1284 (0x504)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1800 (0x708)
        33, // 1290 (0x50a)
        10, // 1206 (0x4b6)
        12, // 1206 (0x4b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 1212 (0x4bc)
        44, // 872 (0x368)
        0, // 618 (0x26a)
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 1386 (0x56a)
        -1,
        34, // 1302 (0x516)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 1135 (0x46f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 800 (0x320)
        -1,
        38, // 1736 (0x6c8)
        42, // 1736 (0x6c8)
        -1,
        -1,
        28, // 1908 (0x774)
        -1,
        30, // 1824 (0x720)
        37, // 1314 (0x522)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 808 (0x328)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 1236 (0x4d4)
        27, // 1491 (0x5d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 1070 (0x42e)
        32, // 1155 (0x483)
        -1,
        -1,
        43, // 1582 (0x62e)
        45, // 1752 (0x6d8)
        17, // 648 (0x288)
        -1,
        -1,
        -1,
        7, // 1075 (0x433)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 832 (0x340)
        9, // 1512 (0x5e8)
        22, // 663 (0x297)
        -1,
        31, // 1344 (0x540)
        -1,
        8, // 1600 (0x640)
        16, // 1090 (0x442)
        -1,
        -1,
        -1,
        -1,
        26, // 1688 (0x698)
        -1,
        20, // 414 (0x19e)
        39, // 924 (0x39c)
        14, // 840 (0x348)
        -1,
        15, // 1266 (0x4f2)
        29, // 1266 (0x4f2)
        -1,
        -1,
        -1,
        -1,
        23, // 844 (0x34c)
        -1,
        4, // 1015 (0x3f7)
        46, // 1100 (0x44c)
        40, // 1526 (0x5f6)
        -1,
        11, // 422 (0x1a6)
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

//check: name=check_cpp_hash1, dataset=cpp, hash=hash1
void check_cpp_hash1() {
    assert(lookup_cpp_hash1("char") == 5);
    assert(lookup_cpp_hash1("break") == 2);
    assert(lookup_cpp_hash1("goto") == 19);
    assert(lookup_cpp_hash1("new") == 24);
    assert(lookup_cpp_hash1("static") == 35);
    assert(lookup_cpp_hash1("operator") == 25);
    assert(lookup_cpp_hash1("signed") == 33);
    assert(lookup_cpp_hash1("delete") == 10);
    assert(lookup_cpp_hash1("double") == 12);
    assert(lookup_cpp_hash1("friend") == 18);
    assert(lookup_cpp_hash1("void") == 44);
    assert(lookup_cpp_hash1("asm") == 0);
    assert(lookup_cpp_hash1("struct") == 36);
    assert(lookup_cpp_hash1("sizeof") == 34);
    assert(lookup_cpp_hash1("union") == 41);
    assert(lookup_cpp_hash1("case") == 3);
    assert(lookup_cpp_hash1("template") == 38);
    assert(lookup_cpp_hash1("unsigned") == 42);
    assert(lookup_cpp_hash1("protected") == 28);
    assert(lookup_cpp_hash1("register") == 30);
    assert(lookup_cpp_hash1("switch") == 37);
    assert(lookup_cpp_hash1("else") == 13);
    assert(lookup_cpp_hash1("inline") == 21);
    assert(lookup_cpp_hash1("private") == 27);
    assert(lookup_cpp_hash1("class") == 6);
    assert(lookup_cpp_hash1("short") == 32);
    assert(lookup_cpp_hash1("virtual") == 43);
    assert(lookup_cpp_hash1("volatile") == 45);
    assert(lookup_cpp_hash1("for") == 17);
    assert(lookup_cpp_hash1("const") == 7);
    assert(lookup_cpp_hash1("auto") == 1);
    assert(lookup_cpp_hash1("default") == 9);
    assert(lookup_cpp_hash1("int") == 22);
    assert(lookup_cpp_hash1("return") == 31);
    assert(lookup_cpp_hash1("continue") == 8);
    assert(lookup_cpp_hash1("float") == 16);
    assert(lookup_cpp_hash1("overload") == 26);
    assert(lookup_cpp_hash1("if") == 20);
    assert(lookup_cpp_hash1("this") == 39);
    assert(lookup_cpp_hash1("enum") == 14);
    assert(lookup_cpp_hash1("extern") == 15);
    assert(lookup_cpp_hash1("public") == 29);
    assert(lookup_cpp_hash1("long") == 23);
    assert(lookup_cpp_hash1("catch") == 4);
    assert(lookup_cpp_hash1("while") == 46);
    assert(lookup_cpp_hash1("typedef") == 40);
    assert(lookup_cpp_hash1("do") == 11);
}

//lookup: name=lookup_cpp_hash2, dataset=cpp, hash=hash2
int lookup_cpp_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 69) * 2;
    static std::string_view lookup[138] = {
        "",
        "",
        "",
        "",
        "sizeof", // 11732 (0x2dd4)
        "",
        "class", // 11388 (0x2c7c)
        "private", // 11319 (0x2c37)
        "",
        "",
        "void", // 11804 (0x2e1c)
        "",
        "static", // 11391 (0x2c7f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "long", // 11120 (0x2b70)
        "",
        "",
        "",
        "if", // 10708 (0x29d4)
        "",
        "",
        "",
        "default", // 11607 (0x2d57)
        "",
        "while", // 12022 (0x2ef6)
        "",
        "asm", // 10574 (0x294e)
        "",
        "",
        "",
        "operator", // 12646 (0x3166)
        "this", // 13336 (0x3418)
        "catch", // 10301 (0x283d)
        "short", // 13337 (0x3419)
        "struct", // 13338 (0x341a)
        "",
        "",
        "",
        "",
        "",
        "delete", // 10098 (0x2772)
        "double", // 10098 (0x2772)
        "",
        "",
        "",
        "",
        "const", // 11481 (0x2cd9)
        "",
        "",
        "",
        "switch", // 11966 (0x2ebe)
        "",
        "",
        "",
        "protected", // 11209 (0x2bc9)
        "",
        "register", // 13004 (0x32cc)
        "",
        "union", // 12867 (0x3243)
        "",
        "",
        "",
        "char", // 11282 (0x2c12)
        "",
        "",
        "",
        "",
        "",
        "float", // 11837 (0x2e3d)
        "",
        "for", // 11631 (0x2d6f)
        "int", // 12183 (0x2f97)
        "typedef", // 11839 (0x2e3f)
        "",
        "",
        "",
        "enum", // 11013 (0x2b05)
        "volatile", // 11910 (0x2e86)
        "",
        "",
        "signed", // 11498 (0x2cea)
        "",
        "",
        "",
        "inline", // 10603 (0x296b)
        "",
        "unsigned", // 11708 (0x2dbc)
        "",
        "new", // 13089 (0x3321)
        "",
        "return", // 12538 (0x30fa)
        "",
        "",
        "",
        "",
        "",
        "goto", // 11437 (0x2cad)
        "overload", // 11092 (0x2b54)
        "",
        "",
        "public", // 11094 (0x2b56)
        "",
        "continue", // 9991 (0x2707)
        "virtual", // 12751 (0x31cf)
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 9995 (0x270b)
        "",
        "",
        "",
        "",
        "",
        "do", // 11102 (0x2b5e)
        "else", // 10205 (0x27dd)
        "friend", // 10206 (0x27de)
        "template", // 11724 (0x2dcc)
        "break", // 10483 (0x28f3)
        "extern", // 11104 (0x2b60)
        "",
        "",
        "",
        "",
        "",
        "",
        "auto", // 10763 (0x2a0b)
        "",
    };
    static int values[138] = {
        -1,
        -1,
        -1,
        -1,
        34, // 11732 (0x2dd4)
        -1,
        6, // 11388 (0x2c7c)
        27, // 11319 (0x2c37)
        -1,
        -1,
        44, // 11804 (0x2e1c)
        -1,
        35, // 11391 (0x2c7f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 11120 (0x2b70)
        -1,
        -1,
        -1,
        20, // 10708 (0x29d4)
        -1,
        -1,
        -1,
        9, // 11607 (0x2d57)
        -1,
        46, // 12022 (0x2ef6)
        -1,
        0, // 10574 (0x294e)
        -1,
        -1,
        -1,
        25, // 12646 (0x3166)
        39, // 13336 (0x3418)
        4, // 10301 (0x283d)
        32, // 13337 (0x3419)
        36, // 13338 (0x341a)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 10098 (0x2772)
        12, // 10098 (0x2772)
        -1,
        -1,
        -1,
        -1,
        7, // 11481 (0x2cd9)
        -1,
        -1,
        -1,
        37, // 11966 (0x2ebe)
        -1,
        -1,
        -1,
        28, // 11209 (0x2bc9)
        -1,
        30, // 13004 (0x32cc)
        -1,
        41, // 12867 (0x3243)
        -1,
        -1,
        -1,
        5, // 11282 (0x2c12)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 11837 (0x2e3d)
        -1,
        17, // 11631 (0x2d6f)
        22, // 12183 (0x2f97)
        40, // 11839 (0x2e3f)
        -1,
        -1,
        -1,
        14, // 11013 (0x2b05)
        45, // 11910 (0x2e86)
        -1,
        -1,
        33, // 11498 (0x2cea)
        -1,
        -1,
        -1,
        21, // 10603 (0x296b)
        -1,
        42, // 11708 (0x2dbc)
        -1,
        24, // 13089 (0x3321)
        -1,
        31, // 12538 (0x30fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 11437 (0x2cad)
        26, // 11092 (0x2b54)
        -1,
        -1,
        29, // 11094 (0x2b56)
        -1,
        8, // 9991 (0x2707)
        43, // 12751 (0x31cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 9995 (0x270b)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 11102 (0x2b5e)
        13, // 10205 (0x27dd)
        18, // 10206 (0x27de)
        38, // 11724 (0x2dcc)
        2, // 10483 (0x28f3)
        15, // 11104 (0x2b60)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 10763 (0x2a0b)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cpp_hash2, dataset=cpp, hash=hash2
void check_cpp_hash2() {
    assert(lookup_cpp_hash2("sizeof") == 34);
    assert(lookup_cpp_hash2("class") == 6);
    assert(lookup_cpp_hash2("private") == 27);
    assert(lookup_cpp_hash2("void") == 44);
    assert(lookup_cpp_hash2("static") == 35);
    assert(lookup_cpp_hash2("long") == 23);
    assert(lookup_cpp_hash2("if") == 20);
    assert(lookup_cpp_hash2("default") == 9);
    assert(lookup_cpp_hash2("while") == 46);
    assert(lookup_cpp_hash2("asm") == 0);
    assert(lookup_cpp_hash2("operator") == 25);
    assert(lookup_cpp_hash2("this") == 39);
    assert(lookup_cpp_hash2("catch") == 4);
    assert(lookup_cpp_hash2("short") == 32);
    assert(lookup_cpp_hash2("struct") == 36);
    assert(lookup_cpp_hash2("delete") == 10);
    assert(lookup_cpp_hash2("double") == 12);
    assert(lookup_cpp_hash2("const") == 7);
    assert(lookup_cpp_hash2("switch") == 37);
    assert(lookup_cpp_hash2("protected") == 28);
    assert(lookup_cpp_hash2("register") == 30);
    assert(lookup_cpp_hash2("union") == 41);
    assert(lookup_cpp_hash2("char") == 5);
    assert(lookup_cpp_hash2("float") == 16);
    assert(lookup_cpp_hash2("for") == 17);
    assert(lookup_cpp_hash2("int") == 22);
    assert(lookup_cpp_hash2("typedef") == 40);
    assert(lookup_cpp_hash2("enum") == 14);
    assert(lookup_cpp_hash2("volatile") == 45);
    assert(lookup_cpp_hash2("signed") == 33);
    assert(lookup_cpp_hash2("inline") == 21);
    assert(lookup_cpp_hash2("unsigned") == 42);
    assert(lookup_cpp_hash2("new") == 24);
    assert(lookup_cpp_hash2("return") == 31);
    assert(lookup_cpp_hash2("goto") == 19);
    assert(lookup_cpp_hash2("overload") == 26);
    assert(lookup_cpp_hash2("public") == 29);
    assert(lookup_cpp_hash2("continue") == 8);
    assert(lookup_cpp_hash2("virtual") == 43);
    assert(lookup_cpp_hash2("case") == 3);
    assert(lookup_cpp_hash2("do") == 11);
    assert(lookup_cpp_hash2("else") == 13);
    assert(lookup_cpp_hash2("friend") == 18);
    assert(lookup_cpp_hash2("template") == 38);
    assert(lookup_cpp_hash2("break") == 2);
    assert(lookup_cpp_hash2("extern") == 15);
    assert(lookup_cpp_hash2("auto") == 1);
}

//lookup: name=lookup_cpp_hash3, dataset=cpp, hash=hash3
int lookup_cpp_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 248) * 1;
    static std::string_view lookup[248] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "this", // 31007 (0x791f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "void", // 31511 (0x7b17)
        "",
        "",
        "",
        "",
        "",
        "",
        "public", // 30526 (0x773e)
        "",
        "",
        "short", // 31025 (0x7931)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "return", // 31033 (0x7939)
        "",
        "signed", // 31283 (0x7a33)
        "",
        "sizeof", // 31285 (0x7a35)
        "",
        "",
        "",
        "union", // 31537 (0x7b31)
        "while", // 32034 (0x7d22)
        "",
        "",
        "static", // 31293 (0x7a3d)
        "private", // 30798 (0x784e)
        "",
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
        "",
        "",
        "struct", // 31310 (0x7a4e)
        "",
        "",
        "",
        "overload", // 30818 (0x7862)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "operator", // 30826 (0x786a)
        "",
        "",
        "",
        "",
        "",
        "do", // 26368 (0x6700)
        "",
        "",
        "asm", // 25875 (0x6513)
        "",
        "",
        "typedef", // 31830 (0x7c56)
        "register", // 31583 (0x7b5f)
        "",
        "",
        "template", // 32082 (0x7d52)
        "",
        "virtual", // 32332 (0x7e4c)
        "",
        "",
        "protected", // 31343 (0x7a6f)
        "",
        "",
        "case", // 26634 (0x680a)
        "",
        "",
        "",
        "if", // 27630 (0x6bee)
        "",
        "",
        "",
        "unsigned", // 32346 (0x7e5a)
        "",
        "",
        "",
        "",
        "",
        "auto", // 26152 (0x6628)
        "",
        "",
        "",
        "volatile", // 32604 (0x7f5c)
        "",
        "char", // 26654 (0x681e)
        "",
        "",
        "",
        "",
        "",
        "for", // 27156 (0x6a14)
        "else", // 27157 (0x6a15)
        "catch", // 26910 (0x691e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "enum", // 27167 (0x6a1f)
        "",
        "",
        "break", // 26674 (0x6832)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "class", // 26932 (0x6934)
        "int", // 27925 (0x6d15)
        "",
        "",
        "const", // 26936 (0x6938)
        "",
        "goto", // 27682 (0x6c22)
        "",
        "",
        "",
        "",
        "",
        "delete", // 27440 (0x6b30)
        "",
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
        "float", // 27701 (0x6c35)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "new", // 29199 (0x720f)
        "",
        "",
        "long", // 28954 (0x711a)
        "",
        "friend", // 27964 (0x6d3c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "extern", // 27724 (0x6c4c)
        "",
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
        "inline", // 28729 (0x7039)
        "",
        "",
        "continue", // 27740 (0x6c5c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
    static int values[248] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 31007 (0x791f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 31511 (0x7b17)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 30526 (0x773e)
        -1,
        -1,
        32, // 31025 (0x7931)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 31033 (0x7939)
        -1,
        33, // 31283 (0x7a33)
        -1,
        34, // 31285 (0x7a35)
        -1,
        -1,
        -1,
        41, // 31537 (0x7b31)
        46, // 32034 (0x7d22)
        -1,
        -1,
        35, // 31293 (0x7a3d)
        27, // 30798 (0x784e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 31301 (0x7a45)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 31310 (0x7a4e)
        -1,
        -1,
        -1,
        26, // 30818 (0x7862)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 30826 (0x786a)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 26368 (0x6700)
        -1,
        -1,
        0, // 25875 (0x6513)
        -1,
        -1,
        40, // 31830 (0x7c56)
        30, // 31583 (0x7b5f)
        -1,
        -1,
        38, // 32082 (0x7d52)
        -1,
        43, // 32332 (0x7e4c)
        -1,
        -1,
        28, // 31343 (0x7a6f)
        -1,
        -1,
        3, // 26634 (0x680a)
        -1,
        -1,
        -1,
        20, // 27630 (0x6bee)
        -1,
        -1,
        -1,
        42, // 32346 (0x7e5a)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 26152 (0x6628)
        -1,
        -1,
        -1,
        45, // 32604 (0x7f5c)
        -1,
        5, // 26654 (0x681e)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 27156 (0x6a14)
        13, // 27157 (0x6a15)
        4, // 26910 (0x691e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 27167 (0x6a1f)
        -1,
        -1,
        2, // 26674 (0x6832)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 26932 (0x6934)
        22, // 27925 (0x6d15)
        -1,
        -1,
        7, // 26936 (0x6938)
        -1,
        19, // 27682 (0x6c22)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 27440 (0x6b30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 27450 (0x6b3a)
        -1,
        -1,
        16, // 27701 (0x6c35)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 29199 (0x720f)
        -1,
        -1,
        23, // 28954 (0x711a)
        -1,
        18, // 27964 (0x6d3c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 27724 (0x6c4c)
        -1,
        -1,
        -1,
        9, // 27728 (0x6c50)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 28729 (0x7039)
        -1,
        -1,
        8, // 27740 (0x6c5c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
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

//check: name=check_cpp_hash3, dataset=cpp, hash=hash3
void check_cpp_hash3() {
    assert(lookup_cpp_hash3("this") == 39);
    assert(lookup_cpp_hash3("void") == 44);
    assert(lookup_cpp_hash3("public") == 29);
    assert(lookup_cpp_hash3("short") == 32);
    assert(lookup_cpp_hash3("return") == 31);
    assert(lookup_cpp_hash3("signed") == 33);
    assert(lookup_cpp_hash3("sizeof") == 34);
    assert(lookup_cpp_hash3("union") == 41);
    assert(lookup_cpp_hash3("while") == 46);
    assert(lookup_cpp_hash3("static") == 35);
    assert(lookup_cpp_hash3("private") == 27);
    assert(lookup_cpp_hash3("switch") == 37);
    assert(lookup_cpp_hash3("struct") == 36);
    assert(lookup_cpp_hash3("overload") == 26);
    assert(lookup_cpp_hash3("operator") == 25);
    assert(lookup_cpp_hash3("do") == 11);
    assert(lookup_cpp_hash3("asm") == 0);
    assert(lookup_cpp_hash3("typedef") == 40);
    assert(lookup_cpp_hash3("register") == 30);
    assert(lookup_cpp_hash3("template") == 38);
    assert(lookup_cpp_hash3("virtual") == 43);
    assert(lookup_cpp_hash3("protected") == 28);
    assert(lookup_cpp_hash3("case") == 3);
    assert(lookup_cpp_hash3("if") == 20);
    assert(lookup_cpp_hash3("unsigned") == 42);
    assert(lookup_cpp_hash3("auto") == 1);
    assert(lookup_cpp_hash3("volatile") == 45);
    assert(lookup_cpp_hash3("char") == 5);
    assert(lookup_cpp_hash3("for") == 17);
    assert(lookup_cpp_hash3("else") == 13);
    assert(lookup_cpp_hash3("catch") == 4);
    assert(lookup_cpp_hash3("enum") == 14);
    assert(lookup_cpp_hash3("break") == 2);
    assert(lookup_cpp_hash3("class") == 6);
    assert(lookup_cpp_hash3("int") == 22);
    assert(lookup_cpp_hash3("const") == 7);
    assert(lookup_cpp_hash3("goto") == 19);
    assert(lookup_cpp_hash3("delete") == 10);
    assert(lookup_cpp_hash3("double") == 12);
    assert(lookup_cpp_hash3("float") == 16);
    assert(lookup_cpp_hash3("new") == 24);
    assert(lookup_cpp_hash3("long") == 23);
    assert(lookup_cpp_hash3("friend") == 18);
    assert(lookup_cpp_hash3("extern") == 15);
    assert(lookup_cpp_hash3("default") == 9);
    assert(lookup_cpp_hash3("inline") == 21);
    assert(lookup_cpp_hash3("continue") == 8);
}

//lookup: name=lookup_cpp_hash_sum0, dataset=cpp, hash=hash_sum0
int lookup_cpp_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 90) * 2;
    static std::string_view lookup[180] = {
        "",
        "",
        "",
        "",
        "friend", // 632 (0x278)
        "",
        "",
        "",
        "signed", // 634 (0x27a)
        "",
        "double", // 635 (0x27b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "inline", // 639 (0x27f)
        "public", // 639 (0x27f)
        "",
        "",
        "const", // 551 (0x227)
        "",
        "",
        "",
        "union", // 553 (0x229)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "static", // 648 (0x288)
        "",
        "",
        "",
        "short", // 560 (0x230)
        "",
        "default", // 741 (0x2e5)
        "",
        "",
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
        "",
        "switch", // 658 (0x292)
        "",
        "",
        "",
        "",
        "",
        "do", // 211 (0xd3)
        "",
        "extern", // 662 (0x296)
        "",
        "typedef", // 753 (0x2f1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "return", // 672 (0x2a0)
        "",
        "private", // 763 (0x2fb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "struct", // 677 (0x2a5)
        "",
        "",
        "",
        "",
        "",
        "overload", // 860 (0x35c)
        "template", // 860 (0x35c)
        "asm", // 321 (0x141)
        "unsigned", // 861 (0x35d)
        "case", // 412 (0x19c)
        "",
        "",
        "",
        "char", // 414 (0x19e)
        "volatile", // 864 (0x360)
        "virtual", // 775 (0x307)
        "",
        "",
        "",
        "for", // 327 (0x147)
        "",
        "",
        "",
        "continue", // 869 (0x365)
        "register", // 869 (0x365)
        "new", // 330 (0x14a)
        "",
        "int", // 331 (0x14b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "catch", // 515 (0x203)
        "else", // 425 (0x1a9)
        "operator", // 876 (0x36c)
        "",
        "break", // 517 (0x205)
        "",
        "",
        "",
        "",
        "",
        "protected", // 970 (0x3ca)
        "",
        "",
        "",
        "long", // 432 (0x1b0)
        "",
        "",
        "",
        "void", // 434 (0x1b2)
        "",
        "",
        "",
        "",
        "",
        "enum", // 437 (0x1b5)
        "",
        "",
        "",
        "",
        "",
        "this", // 440 (0x1b8)
        "",
        "auto", // 441 (0x1b9)
        "goto", // 441 (0x1b9)
        "",
        "",
        "",
        "",
        "class", // 534 (0x216)
        "float", // 534 (0x216)
        "",
        "",
        "",
        "",
        "delete", // 627 (0x273)
        "while", // 537 (0x219)
        "",
        "",
        "",
        "",
    };
    static int values[180] = {
        -1,
        -1,
        -1,
        -1,
        18, // 632 (0x278)
        -1,
        -1,
        -1,
        33, // 634 (0x27a)
        -1,
        12, // 635 (0x27b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 639 (0x27f)
        29, // 639 (0x27f)
        -1,
        -1,
        7, // 551 (0x227)
        -1,
        -1,
        -1,
        41, // 553 (0x229)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 648 (0x288)
        -1,
        -1,
        -1,
        32, // 560 (0x230)
        -1,
        9, // 741 (0x2e5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 656 (0x290)
        -1,
        20, // 207 (0xcf)
        -1,
        37, // 658 (0x292)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 211 (0xd3)
        -1,
        15, // 662 (0x296)
        -1,
        40, // 753 (0x2f1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 672 (0x2a0)
        -1,
        27, // 763 (0x2fb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 677 (0x2a5)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 860 (0x35c)
        38, // 860 (0x35c)
        0, // 321 (0x141)
        42, // 861 (0x35d)
        3, // 412 (0x19c)
        -1,
        -1,
        -1,
        5, // 414 (0x19e)
        45, // 864 (0x360)
        43, // 775 (0x307)
        -1,
        -1,
        -1,
        17, // 327 (0x147)
        -1,
        -1,
        -1,
        8, // 869 (0x365)
        30, // 869 (0x365)
        24, // 330 (0x14a)
        -1,
        22, // 331 (0x14b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 515 (0x203)
        13, // 425 (0x1a9)
        25, // 876 (0x36c)
        -1,
        2, // 517 (0x205)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 970 (0x3ca)
        -1,
        -1,
        -1,
        23, // 432 (0x1b0)
        -1,
        -1,
        -1,
        44, // 434 (0x1b2)
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 437 (0x1b5)
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 440 (0x1b8)
        -1,
        1, // 441 (0x1b9)
        19, // 441 (0x1b9)
        -1,
        -1,
        -1,
        -1,
        6, // 534 (0x216)
        16, // 534 (0x216)
        -1,
        -1,
        -1,
        -1,
        10, // 627 (0x273)
        46, // 537 (0x219)
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

//check: name=check_cpp_hash_sum0, dataset=cpp, hash=hash_sum0
void check_cpp_hash_sum0() {
    assert(lookup_cpp_hash_sum0("friend") == 18);
    assert(lookup_cpp_hash_sum0("signed") == 33);
    assert(lookup_cpp_hash_sum0("double") == 12);
    assert(lookup_cpp_hash_sum0("inline") == 21);
    assert(lookup_cpp_hash_sum0("public") == 29);
    assert(lookup_cpp_hash_sum0("const") == 7);
    assert(lookup_cpp_hash_sum0("union") == 41);
    assert(lookup_cpp_hash_sum0("static") == 35);
    assert(lookup_cpp_hash_sum0("short") == 32);
    assert(lookup_cpp_hash_sum0("default") == 9);
    assert(lookup_cpp_hash_sum0("sizeof") == 34);
    assert(lookup_cpp_hash_sum0("if") == 20);
    assert(lookup_cpp_hash_sum0("switch") == 37);
    assert(lookup_cpp_hash_sum0("do") == 11);
    assert(lookup_cpp_hash_sum0("extern") == 15);
    assert(lookup_cpp_hash_sum0("typedef") == 40);
    assert(lookup_cpp_hash_sum0("return") == 31);
    assert(lookup_cpp_hash_sum0("private") == 27);
    assert(lookup_cpp_hash_sum0("struct") == 36);
    assert(lookup_cpp_hash_sum0("overload") == 26);
    assert(lookup_cpp_hash_sum0("template") == 38);
    assert(lookup_cpp_hash_sum0("asm") == 0);
    assert(lookup_cpp_hash_sum0("unsigned") == 42);
    assert(lookup_cpp_hash_sum0("case") == 3);
    assert(lookup_cpp_hash_sum0("char") == 5);
    assert(lookup_cpp_hash_sum0("volatile") == 45);
    assert(lookup_cpp_hash_sum0("virtual") == 43);
    assert(lookup_cpp_hash_sum0("for") == 17);
    assert(lookup_cpp_hash_sum0("continue") == 8);
    assert(lookup_cpp_hash_sum0("register") == 30);
    assert(lookup_cpp_hash_sum0("new") == 24);
    assert(lookup_cpp_hash_sum0("int") == 22);
    assert(lookup_cpp_hash_sum0("catch") == 4);
    assert(lookup_cpp_hash_sum0("else") == 13);
    assert(lookup_cpp_hash_sum0("operator") == 25);
    assert(lookup_cpp_hash_sum0("break") == 2);
    assert(lookup_cpp_hash_sum0("protected") == 28);
    assert(lookup_cpp_hash_sum0("long") == 23);
    assert(lookup_cpp_hash_sum0("void") == 44);
    assert(lookup_cpp_hash_sum0("enum") == 14);
    assert(lookup_cpp_hash_sum0("this") == 39);
    assert(lookup_cpp_hash_sum0("auto") == 1);
    assert(lookup_cpp_hash_sum0("goto") == 19);
    assert(lookup_cpp_hash_sum0("class") == 6);
    assert(lookup_cpp_hash_sum0("float") == 16);
    assert(lookup_cpp_hash_sum0("delete") == 10);
    assert(lookup_cpp_hash_sum0("while") == 46);
}

//lookup: name=lookup_cpp_hash_sumN, dataset=cpp, hash=hash_sumN
int lookup_cpp_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 74) * 2;
    static std::string_view lookup[148] = {
        "this", // 444 (0x1bc)
        "",
        "auto", // 445 (0x1bd)
        "goto", // 445 (0x1bd)
        "catch", // 520 (0x208)
        "extern", // 668 (0x29c)
        "",
        "",
        "break", // 522 (0x20a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "default", // 748 (0x2ec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "return", // 678 (0x2a6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "protected", // 979 (0x3d3)
        "struct", // 683 (0x2ab)
        "",
        "",
        "",
        "",
        "typedef", // 760 (0x2f8)
        "",
        "class", // 539 (0x21b)
        "float", // 539 (0x21b)
        "",
        "",
        "",
        "",
        "while", // 542 (0x21e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "asm", // 324 (0x144)
        "",
        "",
        "",
        "private", // 770 (0x302)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 330 (0x14a)
        "",
        "",
        "",
        "",
        "",
        "new", // 333 (0x14d)
        "",
        "const", // 556 (0x22c)
        "int", // 334 (0x14e)
        "",
        "",
        "union", // 558 (0x22e)
        "",
        "delete", // 633 (0x279)
        "",
        "virtual", // 782 (0x30e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 416 (0x1a0)
        "friend", // 638 (0x27e)
        "short", // 565 (0x235)
        "",
        "char", // 418 (0x1a2)
        "signed", // 640 (0x280)
        "double", // 641 (0x281)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "inline", // 645 (0x285)
        "public", // 645 (0x285)
        "overload", // 868 (0x364)
        "template", // 868 (0x364)
        "unsigned", // 869 (0x365)
        "",
        "",
        "",
        "",
        "",
        "volatile", // 872 (0x368)
        "",
        "else", // 429 (0x1ad)
        "",
        "",
        "",
        "if", // 209 (0xd1)
        "",
        "static", // 654 (0x28e)
        "",
        "continue", // 877 (0x36d)
        "register", // 877 (0x36d)
        "",
        "",
        "do", // 213 (0xd5)
        "",
        "long", // 436 (0x1b4)
        "",
        "",
        "",
        "void", // 438 (0x1b6)
        "",
        "",
        "",
        "operator", // 884 (0x374)
        "sizeof", // 662 (0x296)
        "enum", // 441 (0x1b9)
        "",
        "switch", // 664 (0x298)
        "",
        "",
        "",
    };
    static int values[148] = {
        39, // 444 (0x1bc)
        -1,
        1, // 445 (0x1bd)
        19, // 445 (0x1bd)
        4, // 520 (0x208)
        15, // 668 (0x29c)
        -1,
        -1,
        2, // 522 (0x20a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 748 (0x2ec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 678 (0x2a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 979 (0x3d3)
        36, // 683 (0x2ab)
        -1,
        -1,
        -1,
        -1,
        40, // 760 (0x2f8)
        -1,
        6, // 539 (0x21b)
        16, // 539 (0x21b)
        -1,
        -1,
        -1,
        -1,
        46, // 542 (0x21e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 324 (0x144)
        -1,
        -1,
        -1,
        27, // 770 (0x302)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 330 (0x14a)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 333 (0x14d)
        -1,
        7, // 556 (0x22c)
        22, // 334 (0x14e)
        -1,
        -1,
        41, // 558 (0x22e)
        -1,
        10, // 633 (0x279)
        -1,
        43, // 782 (0x30e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 416 (0x1a0)
        18, // 638 (0x27e)
        32, // 565 (0x235)
        -1,
        5, // 418 (0x1a2)
        33, // 640 (0x280)
        12, // 641 (0x281)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 645 (0x285)
        29, // 645 (0x285)
        26, // 868 (0x364)
        38, // 868 (0x364)
        42, // 869 (0x365)
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 872 (0x368)
        -1,
        13, // 429 (0x1ad)
        -1,
        -1,
        -1,
        20, // 209 (0xd1)
        -1,
        35, // 654 (0x28e)
        -1,
        8, // 877 (0x36d)
        30, // 877 (0x36d)
        -1,
        -1,
        11, // 213 (0xd5)
        -1,
        23, // 436 (0x1b4)
        -1,
        -1,
        -1,
        44, // 438 (0x1b6)
        -1,
        -1,
        -1,
        25, // 884 (0x374)
        34, // 662 (0x296)
        14, // 441 (0x1b9)
        -1,
        37, // 664 (0x298)
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

//check: name=check_cpp_hash_sumN, dataset=cpp, hash=hash_sumN
void check_cpp_hash_sumN() {
    assert(lookup_cpp_hash_sumN("this") == 39);
    assert(lookup_cpp_hash_sumN("auto") == 1);
    assert(lookup_cpp_hash_sumN("goto") == 19);
    assert(lookup_cpp_hash_sumN("catch") == 4);
    assert(lookup_cpp_hash_sumN("extern") == 15);
    assert(lookup_cpp_hash_sumN("break") == 2);
    assert(lookup_cpp_hash_sumN("default") == 9);
    assert(lookup_cpp_hash_sumN("return") == 31);
    assert(lookup_cpp_hash_sumN("protected") == 28);
    assert(lookup_cpp_hash_sumN("struct") == 36);
    assert(lookup_cpp_hash_sumN("typedef") == 40);
    assert(lookup_cpp_hash_sumN("class") == 6);
    assert(lookup_cpp_hash_sumN("float") == 16);
    assert(lookup_cpp_hash_sumN("while") == 46);
    assert(lookup_cpp_hash_sumN("asm") == 0);
    assert(lookup_cpp_hash_sumN("private") == 27);
    assert(lookup_cpp_hash_sumN("for") == 17);
    assert(lookup_cpp_hash_sumN("new") == 24);
    assert(lookup_cpp_hash_sumN("const") == 7);
    assert(lookup_cpp_hash_sumN("int") == 22);
    assert(lookup_cpp_hash_sumN("union") == 41);
    assert(lookup_cpp_hash_sumN("delete") == 10);
    assert(lookup_cpp_hash_sumN("virtual") == 43);
    assert(lookup_cpp_hash_sumN("case") == 3);
    assert(lookup_cpp_hash_sumN("friend") == 18);
    assert(lookup_cpp_hash_sumN("short") == 32);
    assert(lookup_cpp_hash_sumN("char") == 5);
    assert(lookup_cpp_hash_sumN("signed") == 33);
    assert(lookup_cpp_hash_sumN("double") == 12);
    assert(lookup_cpp_hash_sumN("inline") == 21);
    assert(lookup_cpp_hash_sumN("public") == 29);
    assert(lookup_cpp_hash_sumN("overload") == 26);
    assert(lookup_cpp_hash_sumN("template") == 38);
    assert(lookup_cpp_hash_sumN("unsigned") == 42);
    assert(lookup_cpp_hash_sumN("volatile") == 45);
    assert(lookup_cpp_hash_sumN("else") == 13);
    assert(lookup_cpp_hash_sumN("if") == 20);
    assert(lookup_cpp_hash_sumN("static") == 35);
    assert(lookup_cpp_hash_sumN("continue") == 8);
    assert(lookup_cpp_hash_sumN("register") == 30);
    assert(lookup_cpp_hash_sumN("do") == 11);
    assert(lookup_cpp_hash_sumN("long") == 23);
    assert(lookup_cpp_hash_sumN("void") == 44);
    assert(lookup_cpp_hash_sumN("operator") == 25);
    assert(lookup_cpp_hash_sumN("sizeof") == 34);
    assert(lookup_cpp_hash_sumN("enum") == 14);
    assert(lookup_cpp_hash_sumN("switch") == 37);
}

//lookup: name=lookup_cpp_hash_djb2, dataset=cpp, hash=hash_djb2
int lookup_cpp_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 304) * 1;
    static std::string_view lookup[304] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "switch", // 7083181535963 (0x6712e84f2db)
        "",
        "",
        "register", // 7713518737072878 (0x1b6767884aa2ee)
        "",
        "",
        "",
        "",
        "",
        "",
        "operator", // 7713405019647573 (0x1b674d0e346e55)
        "unsigned", // 7713658684800454 (0x1b67881dd37dc6)
        "",
        "",
        "",
        "",
        "void", // 6504398011 (0x183b13cbb)
        "delete", // 7082573250524 (0x6710a433fdc)
        "",
        "continue", // 7712892661735406 (0x1b66d5c34b1fee)
        "",
        "",
        "",
        "goto", // 6503859330 (0x183a90482)
        "",
        "",
        "",
        "",
        "char", // 6503707335 (0x183a6b2c7)
        "",
        "",
        "",
        "",
        "",
        "",
        "break", // 214621519406 (0x31f8707e2e)
        "",
        "",
        "",
        "",
        "",
        "private", // 233740920676100 (0xd4960c8bdf04)
        "",
        "",
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
        "friend", // 7082666830273 (0x6710fd729c1)
        "union", // 214643912978 (0x31f9c63112)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "asm", // 197080234 (0xbbf34aa)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "auto", // 6503650242 (0x183a5d3c2)
        "new", // 197093939 (0xbbf6a33)
        "",
        "overload", // 7713412768844773 (0x1b674edc17cbe5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "int", // 197088788 (0xbbf5614)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "struct", // 7083178302734 (0x6712e539d0e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "sizeof", // 7083165528057 (0x6712d90aff9)
        "",
        "",
        "do", // 5972220 (0x5b20fc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "inline", // 7082779604936 (0x671168ff7c8)
        "long", // 6504038809 (0x183abc199)
        "",
        "",
        "catch", // 214622110796 (0x31f879844c)
        "",
        "",
        "extern", // 7082635205855 (0x6710df49cdf)
        "",
        "",
        "",
        "signed", // 7083164854723 (0x6712d8669c3)
        "",
        "",
        "",
        "",
        "",
        "",
        "typedef", // 233746368189018 (0xd497513e525a)
        "",
        "",
        "",
        "default", // 233724910009454 (0xd492523c7c6e)
        "class", // 214622485951 (0x31f87f3dbf)
        "",
        "",
        "",
        "protected", // 254543870290962451 (0x388524d28722813)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "virtual", // 233748327887952 (0xd497c60cf450)
        "this", // 6504318529 (0x183b00641)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "short", // 214641332153 (0x31f99ecfb9)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "return", // 7083121450889 (0x6712af01f89)
        "",
        "",
        "",
        "",
        "",
        "",
        "const", // 214622607920 (0x31f8811a30)
        "static", // 7083177690897 (0x6712e4a4711)
        "else", // 6503784146 (0x183a7ded2)
        "",
        "",
        "template", // 7713604216800869 (0x1b677b6f47c665)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "public", // 7083061497864 (0x671275d5008)
        "volatile", // 7713702311738249 (0x1b67924631bb89)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "float", // 214626058367 (0x31f8b5c07f)
        "",
        "",
        "",
        "",
        "double", // 7082585429636 (0x6710afd1684)
        "case", // 6503700293 (0x183a69745)
        "",
        "",
        "if", // 5972376 (0x5b2198)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[304] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 7083181535963 (0x6712e84f2db)
        -1,
        -1,
        30, // 7713518737072878 (0x1b6767884aa2ee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 7713405019647573 (0x1b674d0e346e55)
        42, // 7713658684800454 (0x1b67881dd37dc6)
        -1,
        -1,
        -1,
        -1,
        44, // 6504398011 (0x183b13cbb)
        10, // 7082573250524 (0x6710a433fdc)
        -1,
        8, // 7712892661735406 (0x1b66d5c34b1fee)
        -1,
        -1,
        -1,
        19, // 6503859330 (0x183a90482)
        -1,
        -1,
        -1,
        -1,
        5, // 6503707335 (0x183a6b2c7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 214621519406 (0x31f8707e2e)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 233740920676100 (0xd4960c8bdf04)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 6503786398 (0x183a7e79e)
        -1,
        -1,
        18, // 7082666830273 (0x6710fd729c1)
        41, // 214643912978 (0x31f9c63112)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 197080234 (0xbbf34aa)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 6503650242 (0x183a5d3c2)
        24, // 197093939 (0xbbf6a33)
        -1,
        26, // 7713412768844773 (0x1b674edc17cbe5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 197088788 (0xbbf5614)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 7083178302734 (0x6712e539d0e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 7083165528057 (0x6712d90aff9)
        -1,
        -1,
        11, // 5972220 (0x5b20fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 7082779604936 (0x671168ff7c8)
        23, // 6504038809 (0x183abc199)
        -1,
        -1,
        4, // 214622110796 (0x31f879844c)
        -1,
        -1,
        15, // 7082635205855 (0x6710df49cdf)
        -1,
        -1,
        -1,
        33, // 7083164854723 (0x6712d8669c3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 233746368189018 (0xd497513e525a)
        -1,
        -1,
        -1,
        9, // 233724910009454 (0xd492523c7c6e)
        6, // 214622485951 (0x31f87f3dbf)
        -1,
        -1,
        -1,
        28, // 254543870290962451 (0x388524d28722813)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 233748327887952 (0xd497c60cf450)
        39, // 6504318529 (0x183b00641)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 214641332153 (0x31f99ecfb9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 214646069090 (0x31f9e71762)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 197085552 (0xbbf4970)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 7083121450889 (0x6712af01f89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 214622607920 (0x31f8811a30)
        35, // 7083177690897 (0x6712e4a4711)
        13, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        38, // 7713604216800869 (0x1b677b6f47c665)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 7083061497864 (0x671275d5008)
        45, // 7713702311738249 (0x1b67924631bb89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 214626058367 (0x31f8b5c07f)
        -1,
        -1,
        -1,
        -1,
        12, // 7082585429636 (0x6710afd1684)
        3, // 6503700293 (0x183a69745)
        -1,
        -1,
        20, // 5972376 (0x5b2198)
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

//check: name=check_cpp_hash_djb2, dataset=cpp, hash=hash_djb2
void check_cpp_hash_djb2() {
    assert(lookup_cpp_hash_djb2("switch") == 37);
    assert(lookup_cpp_hash_djb2("register") == 30);
    assert(lookup_cpp_hash_djb2("operator") == 25);
    assert(lookup_cpp_hash_djb2("unsigned") == 42);
    assert(lookup_cpp_hash_djb2("void") == 44);
    assert(lookup_cpp_hash_djb2("delete") == 10);
    assert(lookup_cpp_hash_djb2("continue") == 8);
    assert(lookup_cpp_hash_djb2("goto") == 19);
    assert(lookup_cpp_hash_djb2("char") == 5);
    assert(lookup_cpp_hash_djb2("break") == 2);
    assert(lookup_cpp_hash_djb2("private") == 27);
    assert(lookup_cpp_hash_djb2("enum") == 14);
    assert(lookup_cpp_hash_djb2("friend") == 18);
    assert(lookup_cpp_hash_djb2("union") == 41);
    assert(lookup_cpp_hash_djb2("asm") == 0);
    assert(lookup_cpp_hash_djb2("auto") == 1);
    assert(lookup_cpp_hash_djb2("new") == 24);
    assert(lookup_cpp_hash_djb2("overload") == 26);
    assert(lookup_cpp_hash_djb2("int") == 22);
    assert(lookup_cpp_hash_djb2("struct") == 36);
    assert(lookup_cpp_hash_djb2("sizeof") == 34);
    assert(lookup_cpp_hash_djb2("do") == 11);
    assert(lookup_cpp_hash_djb2("inline") == 21);
    assert(lookup_cpp_hash_djb2("long") == 23);
    assert(lookup_cpp_hash_djb2("catch") == 4);
    assert(lookup_cpp_hash_djb2("extern") == 15);
    assert(lookup_cpp_hash_djb2("signed") == 33);
    assert(lookup_cpp_hash_djb2("typedef") == 40);
    assert(lookup_cpp_hash_djb2("default") == 9);
    assert(lookup_cpp_hash_djb2("class") == 6);
    assert(lookup_cpp_hash_djb2("protected") == 28);
    assert(lookup_cpp_hash_djb2("virtual") == 43);
    assert(lookup_cpp_hash_djb2("this") == 39);
    assert(lookup_cpp_hash_djb2("short") == 32);
    assert(lookup_cpp_hash_djb2("while") == 46);
    assert(lookup_cpp_hash_djb2("for") == 17);
    assert(lookup_cpp_hash_djb2("return") == 31);
    assert(lookup_cpp_hash_djb2("const") == 7);
    assert(lookup_cpp_hash_djb2("static") == 35);
    assert(lookup_cpp_hash_djb2("else") == 13);
    assert(lookup_cpp_hash_djb2("template") == 38);
    assert(lookup_cpp_hash_djb2("public") == 29);
    assert(lookup_cpp_hash_djb2("volatile") == 45);
    assert(lookup_cpp_hash_djb2("float") == 16);
    assert(lookup_cpp_hash_djb2("double") == 12);
    assert(lookup_cpp_hash_djb2("case") == 3);
    assert(lookup_cpp_hash_djb2("if") == 20);
}

//lookup: name=lookup_cpp_hash_sdb, dataset=cpp, hash=hash_sdb
int lookup_cpp_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 236) * 1;
    static std::string_view lookup[236] = {
        "",
        "public", // 3260204451718471445 (0x2d3e92acefd39f15)
        "overload", // 17255079645396769038 (0xef765b8422f2990e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "sizeof", // 3302427291692736640 (0x2dd4941ff1e6a080)
        "",
        "friend", // 2998702146399343922 (0x299d87b6df559532)
        "",
        "new", // 472496276868 (0x6e02f90584)
        "",
        "",
        "",
        "",
        "",
        "",
        "auto", // 27307324983808035 (0x6103de0d6d1023)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "catch", // 361722554615476019 (0x50518bf371a2f33)
        "",
        "",
        "",
        "",
        "extern", // 2996732478728017764 (0x2996884fe1759764)
        "",
        "",
        "do", // 6554011 (0x64019b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "union", // 426184954403829259 (0x5ea1cf53fdb360b)
        "signed", // 3297078571319795376 (0x2dc1937df0119eb0)
        "",
        "",
        "",
        "",
        "",
        "this", // 32656028173930898 (0x74047c0f151192)
        "delete", // 2904965760630034323 (0x285082f7d7068f93)
        "",
        "inline", // 3062036700571998013 (0x2a7e8a27e2cd973d)
        "",
        "",
        "",
        "",
        "",
        "",
        "operator", // 16339972781482018612 (0xe2c33eabffc98734)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "class", // 364819122969718764 (0x510190f37e12fec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "char", // 27870296409247662 (0x6303e30d420fae)
        "",
        "",
        "",
        "static", // 3332546763507343818 (0x2e3f959ff43ba1ca)
        "",
        "",
        "unsigned", // 2703208532253982581 (0x2583b9d67ecdbf75)
        "",
        "register", // 17087298121750970967 (0xed22471bfe2a8257)
        "",
        "",
        "",
        "typedef", // 2657618279341420639 (0x24e1c1be90baf05f)
        "void", // 33219085507826168 (0x7604950f7511f8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "return", // 3261892644424556104 (0x2d449213ee629e48)
        "",
        "",
        "break", // 363130290293256227 (0x50a1913381d3023)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "enum", // 28433349449093201 (0x6503fb0db01051)
        "",
        "",
        "float", // 374952978071105832 (0x53419bf39673128)
        "",
        "",
        "",
        "",
        "struct", // 3337332499566470045 (0x2e509639f606a39d)
        "",
        "asm", // 416657507631 (0x6102b9052f)
        "",
        "",
        "",
        "const", // 365663719708962995 (0x5131937388030b3)
        "short", // 417740035065394444 (0x5cc1c593e88350c)
        "default", // 18130751609074855161 (0xfb9d5e8711bfacf9)
        "",
        "",
        "",
        "if", // 6881697 (0x6901a1)
        "template", // 410239291073665550 (0x5b17676315a9a0e)
        "",
        "",
        "for", // 438134048085 (0x6602d30555)
        "",
        "",
        "",
        "while", // 431251735916197369 (0x5fc1d2b400e35f9)
        "",
        "private", // 1853414300009618939 (0x19b8a67c6db3ddfb)
        "",
        "double", // 2941278687000499069 (0x28d18561dc17937d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 28433340858241073 (0x6503f90da21031)
        "",
        "",
        "",
        "",
        "",
        "",
        "volatile", // 3452512564192461556 (0x2fe9c9e28b43c2f4)
        "",
        "",
        "",
        "switch", // 3344932667539956616 (0x2e6b9689f651a388)
        "",
        "",
        "",
        "case", // 27870266342903704 (0x6303dc0d2a0f98)
        "",
        "",
        "",
        "long", // 30403949176295676 (0x6c043b0e6c10fc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "protected", // 5201487412384685718 (0x482f653e2edade96)
        "continue", // 6848942472000841643 (0x5f0c54e41ab227ab)
        "",
        "",
        "",
        "virtual", // 2567257810834155947 (0x23a0bb60859de9ab)
    };
    static int values[236] = {
        -1,
        29, // 3260204451718471445 (0x2d3e92acefd39f15)
        26, // 17255079645396769038 (0xef765b8422f2990e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 3302427291692736640 (0x2dd4941ff1e6a080)
        -1,
        18, // 2998702146399343922 (0x299d87b6df559532)
        -1,
        24, // 472496276868 (0x6e02f90584)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 27307324983808035 (0x6103de0d6d1023)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 28996381010759823 (0x67040e0deb108f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 361722554615476019 (0x50518bf371a2f33)
        -1,
        -1,
        -1,
        -1,
        15, // 2996732478728017764 (0x2996884fe1759764)
        -1,
        -1,
        11, // 6554011 (0x64019b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 426184954403829259 (0x5ea1cf53fdb360b)
        33, // 3297078571319795376 (0x2dc1937df0119eb0)
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 32656028173930898 (0x74047c0f151192)
        10, // 2904965760630034323 (0x285082f7d7068f93)
        -1,
        21, // 3062036700571998013 (0x2a7e8a27e2cd973d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 16339972781482018612 (0xe2c33eabffc98734)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 364819122969718764 (0x510190f37e12fec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 27870296409247662 (0x6303e30d420fae)
        -1,
        -1,
        -1,
        35, // 3332546763507343818 (0x2e3f959ff43ba1ca)
        -1,
        -1,
        42, // 2703208532253982581 (0x2583b9d67ecdbf75)
        -1,
        30, // 17087298121750970967 (0xed22471bfe2a8257)
        -1,
        -1,
        -1,
        40, // 2657618279341420639 (0x24e1c1be90baf05f)
        44, // 33219085507826168 (0x7604950f7511f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 3261892644424556104 (0x2d449213ee629e48)
        -1,
        -1,
        2, // 363130290293256227 (0x50a1913381d3023)
        -1,
        -1,
        -1,
        22, // 451020064111 (0x6902e4056f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 28433349449093201 (0x6503fb0db01051)
        -1,
        -1,
        16, // 374952978071105832 (0x53419bf39673128)
        -1,
        -1,
        -1,
        -1,
        36, // 3337332499566470045 (0x2e509639f606a39d)
        -1,
        0, // 416657507631 (0x6102b9052f)
        -1,
        -1,
        -1,
        7, // 365663719708962995 (0x5131937388030b3)
        32, // 417740035065394444 (0x5cc1c593e88350c)
        9, // 18130751609074855161 (0xfb9d5e8711bfacf9)
        -1,
        -1,
        -1,
        20, // 6881697 (0x6901a1)
        38, // 410239291073665550 (0x5b17676315a9a0e)
        -1,
        -1,
        17, // 438134048085 (0x6602d30555)
        -1,
        -1,
        -1,
        46, // 431251735916197369 (0x5fc1d2b400e35f9)
        -1,
        27, // 1853414300009618939 (0x19b8a67c6db3ddfb)
        -1,
        12, // 2941278687000499069 (0x28d18561dc17937d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 28433340858241073 (0x6503f90da21031)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 3452512564192461556 (0x2fe9c9e28b43c2f4)
        -1,
        -1,
        -1,
        37, // 3344932667539956616 (0x2e6b9689f651a388)
        -1,
        -1,
        -1,
        3, // 27870266342903704 (0x6303dc0d2a0f98)
        -1,
        -1,
        -1,
        23, // 30403949176295676 (0x6c043b0e6c10fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 5201487412384685718 (0x482f653e2edade96)
        8, // 6848942472000841643 (0x5f0c54e41ab227ab)
        -1,
        -1,
        -1,
        43, // 2567257810834155947 (0x23a0bb60859de9ab)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cpp_hash_sdb, dataset=cpp, hash=hash_sdb
void check_cpp_hash_sdb() {
    assert(lookup_cpp_hash_sdb("public") == 29);
    assert(lookup_cpp_hash_sdb("overload") == 26);
    assert(lookup_cpp_hash_sdb("sizeof") == 34);
    assert(lookup_cpp_hash_sdb("friend") == 18);
    assert(lookup_cpp_hash_sdb("new") == 24);
    assert(lookup_cpp_hash_sdb("auto") == 1);
    assert(lookup_cpp_hash_sdb("goto") == 19);
    assert(lookup_cpp_hash_sdb("catch") == 4);
    assert(lookup_cpp_hash_sdb("extern") == 15);
    assert(lookup_cpp_hash_sdb("do") == 11);
    assert(lookup_cpp_hash_sdb("union") == 41);
    assert(lookup_cpp_hash_sdb("signed") == 33);
    assert(lookup_cpp_hash_sdb("this") == 39);
    assert(lookup_cpp_hash_sdb("delete") == 10);
    assert(lookup_cpp_hash_sdb("inline") == 21);
    assert(lookup_cpp_hash_sdb("operator") == 25);
    assert(lookup_cpp_hash_sdb("class") == 6);
    assert(lookup_cpp_hash_sdb("char") == 5);
    assert(lookup_cpp_hash_sdb("static") == 35);
    assert(lookup_cpp_hash_sdb("unsigned") == 42);
    assert(lookup_cpp_hash_sdb("register") == 30);
    assert(lookup_cpp_hash_sdb("typedef") == 40);
    assert(lookup_cpp_hash_sdb("void") == 44);
    assert(lookup_cpp_hash_sdb("return") == 31);
    assert(lookup_cpp_hash_sdb("break") == 2);
    assert(lookup_cpp_hash_sdb("int") == 22);
    assert(lookup_cpp_hash_sdb("enum") == 14);
    assert(lookup_cpp_hash_sdb("float") == 16);
    assert(lookup_cpp_hash_sdb("struct") == 36);
    assert(lookup_cpp_hash_sdb("asm") == 0);
    assert(lookup_cpp_hash_sdb("const") == 7);
    assert(lookup_cpp_hash_sdb("short") == 32);
    assert(lookup_cpp_hash_sdb("default") == 9);
    assert(lookup_cpp_hash_sdb("if") == 20);
    assert(lookup_cpp_hash_sdb("template") == 38);
    assert(lookup_cpp_hash_sdb("for") == 17);
    assert(lookup_cpp_hash_sdb("while") == 46);
    assert(lookup_cpp_hash_sdb("private") == 27);
    assert(lookup_cpp_hash_sdb("double") == 12);
    assert(lookup_cpp_hash_sdb("else") == 13);
    assert(lookup_cpp_hash_sdb("volatile") == 45);
    assert(lookup_cpp_hash_sdb("switch") == 37);
    assert(lookup_cpp_hash_sdb("case") == 3);
    assert(lookup_cpp_hash_sdb("long") == 23);
    assert(lookup_cpp_hash_sdb("protected") == 28);
    assert(lookup_cpp_hash_sdb("continue") == 8);
    assert(lookup_cpp_hash_sdb("virtual") == 43);
}
