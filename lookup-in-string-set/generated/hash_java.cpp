
//lookup: name=lookup_java_hash1, dataset=java, hash=hash1
int lookup_java_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 97) * 2;
    static std::string_view lookup[194] = {
        "",
        "",
        "boolean", // 1456 (0x5b0)
        "",
        "",
        "",
        "class", // 1070 (0x42e)
        "",
        "",
        "",
        "public", // 1266 (0x4f2)
        "native", // 1266 (0x4f2)
        "volatile", // 1752 (0x6d8)
        "",
        "",
        "",
        "const", // 1075 (0x433)
        "new", // 687 (0x2af)
        "finally", // 1561 (0x619)
        "",
        "",
        "",
        "throw", // 1175 (0x497)
        "interface", // 1854 (0x73e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "byte", // 796 (0x31c)
        "",
        "",
        "",
        "",
        "",
        "static", // 1284 (0x504)
        "float", // 1090 (0x442)
        "case", // 800 (0x320)
        "",
        "",
        "",
        "if", // 414 (0x19e)
        "",
        "",
        "",
        "throws", // 1386 (0x56a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 808 (0x328)
        "try", // 711 (0x2c7)
        "instanceof", // 2070 (0x816)
        "while", // 1100 (0x44c)
        "do", // 422 (0x1a6)
        "",
        "",
        "",
        "private", // 1491 (0x5d3)
        "package", // 1491 (0x5d3)
        "",
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
        "",
        "",
        "",
        "",
        "catch", // 1015 (0x3f7)
        "",
        "",
        "",
        "",
        "",
        "continue", // 1600 (0x640)
        "",
        "",
        "",
        "",
        "",
        "transient", // 2088 (0x828)
        "this", // 924 (0x39c)
        "",
        "",
        "switch", // 1314 (0x522)
        "",
        "",
        "",
        "abstract", // 1704 (0x6a8)
        "break", // 1025 (0x401)
        "",
        "",
        "default", // 1512 (0x5e8)
        "extends", // 1512 (0x5e8)
        "synchronized", // 2580 (0xa14)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "protected", // 1908 (0x774)
        "import", // 1326 (0x52e)
        "implements", // 2200 (0x898)
        "for", // 648 (0x288)
        "",
        "",
        "long", // 844 (0x34c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "char", // 852 (0x354)
        "",
        "",
        "",
        "super", // 1145 (0x479)
        "",
        "",
        "",
        "final", // 1050 (0x41a)
        "goto", // 856 (0x358)
        "int", // 663 (0x297)
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
        "short", // 1155 (0x483)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "void", // 872 (0x368)
        "",
    };
    static int values[194] = {
        -1,
        -1,
        5, // 1456 (0x5b0)
        -1,
        -1,
        -1,
        35, // 1070 (0x42e)
        -1,
        -1,
        -1,
        13, // 1266 (0x4f2)
        37, // 1266 (0x4f2)
        29, // 1752 (0x6d8)
        -1,
        -1,
        -1,
        39, // 1075 (0x433)
        41, // 687 (0x2af)
        31, // 1561 (0x619)
        -1,
        -1,
        -1,
        4, // 1175 (0x497)
        27, // 1854 (0x73e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 796 (0x31c)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 1284 (0x504)
        36, // 1090 (0x442)
        20, // 800 (0x320)
        -1,
        -1,
        -1,
        2, // 414 (0x19e)
        -1,
        -1,
        -1,
        9, // 1386 (0x56a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 808 (0x328)
        19, // 711 (0x2c7)
        17, // 2070 (0x816)
        34, // 1100 (0x44c)
        6, // 422 (0x1a6)
        -1,
        -1,
        -1,
        3, // 1491 (0x5d3)
        45, // 1491 (0x5d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 1206 (0x4b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1015 (0x3f7)
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 1600 (0x640)
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 2088 (0x828)
        46, // 924 (0x39c)
        -1,
        -1,
        38, // 1314 (0x522)
        -1,
        -1,
        -1,
        0, // 1704 (0x6a8)
        10, // 1025 (0x401)
        -1,
        -1,
        1, // 1512 (0x5e8)
        21, // 1512 (0x5e8)
        42, // 2580 (0xa14)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 1908 (0x774)
        12, // 1326 (0x52e)
        7, // 2200 (0x898)
        40, // 648 (0x288)
        -1,
        -1,
        32, // 844 (0x34c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 852 (0x354)
        -1,
        -1,
        -1,
        33, // 1145 (0x479)
        -1,
        -1,
        -1,
        26, // 1050 (0x41a)
        44, // 856 (0x358)
        22, // 663 (0x297)
        -1,
        -1,
        -1,
        18, // 1344 (0x540)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 1155 (0x483)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 872 (0x368)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_java_hash1, dataset=java, hash=hash1
void check_java_hash1() {
    assert(lookup_java_hash1("boolean") == 5);
    assert(lookup_java_hash1("class") == 35);
    assert(lookup_java_hash1("public") == 13);
    assert(lookup_java_hash1("native") == 37);
    assert(lookup_java_hash1("volatile") == 29);
    assert(lookup_java_hash1("const") == 39);
    assert(lookup_java_hash1("new") == 41);
    assert(lookup_java_hash1("finally") == 31);
    assert(lookup_java_hash1("throw") == 4);
    assert(lookup_java_hash1("interface") == 27);
    assert(lookup_java_hash1("byte") == 15);
    assert(lookup_java_hash1("static") == 28);
    assert(lookup_java_hash1("float") == 36);
    assert(lookup_java_hash1("case") == 20);
    assert(lookup_java_hash1("if") == 2);
    assert(lookup_java_hash1("throws") == 9);
    assert(lookup_java_hash1("else") == 16);
    assert(lookup_java_hash1("try") == 19);
    assert(lookup_java_hash1("instanceof") == 17);
    assert(lookup_java_hash1("while") == 34);
    assert(lookup_java_hash1("do") == 6);
    assert(lookup_java_hash1("private") == 3);
    assert(lookup_java_hash1("package") == 45);
    assert(lookup_java_hash1("double") == 11);
    assert(lookup_java_hash1("catch") == 25);
    assert(lookup_java_hash1("continue") == 43);
    assert(lookup_java_hash1("transient") == 14);
    assert(lookup_java_hash1("this") == 46);
    assert(lookup_java_hash1("switch") == 38);
    assert(lookup_java_hash1("abstract") == 0);
    assert(lookup_java_hash1("break") == 10);
    assert(lookup_java_hash1("default") == 1);
    assert(lookup_java_hash1("extends") == 21);
    assert(lookup_java_hash1("synchronized") == 42);
    assert(lookup_java_hash1("protected") == 8);
    assert(lookup_java_hash1("import") == 12);
    assert(lookup_java_hash1("implements") == 7);
    assert(lookup_java_hash1("for") == 40);
    assert(lookup_java_hash1("long") == 32);
    assert(lookup_java_hash1("char") == 30);
    assert(lookup_java_hash1("super") == 33);
    assert(lookup_java_hash1("final") == 26);
    assert(lookup_java_hash1("goto") == 44);
    assert(lookup_java_hash1("int") == 22);
    assert(lookup_java_hash1("return") == 18);
    assert(lookup_java_hash1("short") == 23);
    assert(lookup_java_hash1("void") == 24);
}

//lookup: name=lookup_java_hash2, dataset=java, hash=hash2
int lookup_java_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 65) * 2;
    static std::string_view lookup[130] = {
        "else", // 10205 (0x27dd)
        "",
        "interface", // 10596 (0x2964)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "long", // 11120 (0x2b70)
        "",
        "switch", // 11966 (0x2ebe)
        "",
        "float", // 11837 (0x2e3d)
        "",
        "",
        "",
        "private", // 11319 (0x2c37)
        "package", // 11319 (0x2c37)
        "transient", // 13465 (0x3499)
        "",
        "this", // 13336 (0x3418)
        "",
        "short", // 13337 (0x3419)
        "",
        "throws", // 13338 (0x341a)
        "class", // 11388 (0x2c7c)
        "",
        "",
        "abstract", // 11260 (0x2bfc)
        "volatile", // 11910 (0x2e86)
        "static", // 11391 (0x2c7f)
        "",
        "",
        "",
        "break", // 10483 (0x28f3)
        "",
        "",
        "",
        "",
        "",
        "throw", // 13801 (0x35e9)
        "",
        "byte", // 9902 (0x26ae)
        "",
        "double", // 10098 (0x2772)
        "import", // 12178 (0x2f92)
        "new", // 13089 (0x3321)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "int", // 12183 (0x2f97)
        "",
        "protected", // 11209 (0x2bc9)
        "",
        "",
        "",
        "catch", // 10301 (0x283d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "final", // 11021 (0x2b0d)
        "",
        "default", // 11607 (0x2d57)
        "char", // 11282 (0x2c12)
        "extends", // 11608 (0x2d58)
        "",
        "void", // 11804 (0x2e1c)
        "",
        "implements", // 12065 (0x2f21)
        "",
        "const", // 11481 (0x2cd9)
        "",
        "super", // 13107 (0x3333)
        "",
        "",
        "",
        "public", // 11094 (0x2b56)
        "",
        "",
        "",
        "continue", // 9991 (0x2707)
        "",
        "",
        "",
        "if", // 10708 (0x29d4)
        "synchronized", // 11488 (0x2ce0)
        "",
        "",
        "case", // 9995 (0x270b)
        "",
        "",
        "",
        "do", // 11102 (0x2b5e)
        "finally", // 12337 (0x3031)
        "",
        "",
        "boolean", // 10779 (0x2a1b)
        "native", // 11104 (0x2b60)
        "",
        "",
        "instanceof", // 10716 (0x29dc)
        "",
        "",
        "",
        "return", // 12538 (0x30fa)
        "",
        "",
        "",
        "",
        "",
        "for", // 11631 (0x2d6f)
        "",
        "while", // 12022 (0x2ef6)
        "goto", // 11437 (0x2cad)
        "",
        "",
        "try", // 14039 (0x36d7)
        "",
    };
    static int values[130] = {
        16, // 10205 (0x27dd)
        -1,
        27, // 10596 (0x2964)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 11120 (0x2b70)
        -1,
        38, // 11966 (0x2ebe)
        -1,
        36, // 11837 (0x2e3d)
        -1,
        -1,
        -1,
        3, // 11319 (0x2c37)
        45, // 11319 (0x2c37)
        14, // 13465 (0x3499)
        -1,
        46, // 13336 (0x3418)
        -1,
        23, // 13337 (0x3419)
        -1,
        9, // 13338 (0x341a)
        35, // 11388 (0x2c7c)
        -1,
        -1,
        0, // 11260 (0x2bfc)
        29, // 11910 (0x2e86)
        28, // 11391 (0x2c7f)
        -1,
        -1,
        -1,
        10, // 10483 (0x28f3)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 13801 (0x35e9)
        -1,
        15, // 9902 (0x26ae)
        -1,
        11, // 10098 (0x2772)
        12, // 12178 (0x2f92)
        41, // 13089 (0x3321)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 12183 (0x2f97)
        -1,
        8, // 11209 (0x2bc9)
        -1,
        -1,
        -1,
        25, // 10301 (0x283d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 11021 (0x2b0d)
        -1,
        1, // 11607 (0x2d57)
        30, // 11282 (0x2c12)
        21, // 11608 (0x2d58)
        -1,
        24, // 11804 (0x2e1c)
        -1,
        7, // 12065 (0x2f21)
        -1,
        39, // 11481 (0x2cd9)
        -1,
        33, // 13107 (0x3333)
        -1,
        -1,
        -1,
        13, // 11094 (0x2b56)
        -1,
        -1,
        -1,
        43, // 9991 (0x2707)
        -1,
        -1,
        -1,
        2, // 10708 (0x29d4)
        42, // 11488 (0x2ce0)
        -1,
        -1,
        20, // 9995 (0x270b)
        -1,
        -1,
        -1,
        6, // 11102 (0x2b5e)
        31, // 12337 (0x3031)
        -1,
        -1,
        5, // 10779 (0x2a1b)
        37, // 11104 (0x2b60)
        -1,
        -1,
        17, // 10716 (0x29dc)
        -1,
        -1,
        -1,
        18, // 12538 (0x30fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 11631 (0x2d6f)
        -1,
        34, // 12022 (0x2ef6)
        44, // 11437 (0x2cad)
        -1,
        -1,
        19, // 14039 (0x36d7)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_java_hash2, dataset=java, hash=hash2
void check_java_hash2() {
    assert(lookup_java_hash2("else") == 16);
    assert(lookup_java_hash2("interface") == 27);
    assert(lookup_java_hash2("long") == 32);
    assert(lookup_java_hash2("switch") == 38);
    assert(lookup_java_hash2("float") == 36);
    assert(lookup_java_hash2("private") == 3);
    assert(lookup_java_hash2("package") == 45);
    assert(lookup_java_hash2("transient") == 14);
    assert(lookup_java_hash2("this") == 46);
    assert(lookup_java_hash2("short") == 23);
    assert(lookup_java_hash2("throws") == 9);
    assert(lookup_java_hash2("class") == 35);
    assert(lookup_java_hash2("abstract") == 0);
    assert(lookup_java_hash2("volatile") == 29);
    assert(lookup_java_hash2("static") == 28);
    assert(lookup_java_hash2("break") == 10);
    assert(lookup_java_hash2("throw") == 4);
    assert(lookup_java_hash2("byte") == 15);
    assert(lookup_java_hash2("double") == 11);
    assert(lookup_java_hash2("import") == 12);
    assert(lookup_java_hash2("new") == 41);
    assert(lookup_java_hash2("int") == 22);
    assert(lookup_java_hash2("protected") == 8);
    assert(lookup_java_hash2("catch") == 25);
    assert(lookup_java_hash2("final") == 26);
    assert(lookup_java_hash2("default") == 1);
    assert(lookup_java_hash2("char") == 30);
    assert(lookup_java_hash2("extends") == 21);
    assert(lookup_java_hash2("void") == 24);
    assert(lookup_java_hash2("implements") == 7);
    assert(lookup_java_hash2("const") == 39);
    assert(lookup_java_hash2("super") == 33);
    assert(lookup_java_hash2("public") == 13);
    assert(lookup_java_hash2("continue") == 43);
    assert(lookup_java_hash2("if") == 2);
    assert(lookup_java_hash2("synchronized") == 42);
    assert(lookup_java_hash2("case") == 20);
    assert(lookup_java_hash2("do") == 6);
    assert(lookup_java_hash2("finally") == 31);
    assert(lookup_java_hash2("boolean") == 5);
    assert(lookup_java_hash2("native") == 37);
    assert(lookup_java_hash2("instanceof") == 17);
    assert(lookup_java_hash2("return") == 18);
    assert(lookup_java_hash2("for") == 40);
    assert(lookup_java_hash2("while") == 34);
    assert(lookup_java_hash2("goto") == 44);
    assert(lookup_java_hash2("try") == 19);
}

//lookup: name=lookup_java_hash3, dataset=java, hash=hash3
int lookup_java_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 328) * 1;
    static std::string_view lookup[328] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "abstract", // 27230 (0x6a5e)
        "new", // 29199 (0x720f)
        "",
        "",
        "",
        "",
        "",
        "",
        "catch", // 26910 (0x691e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "public", // 30526 (0x773e)
        "void", // 31511 (0x7b17)
        "",
        "",
        "",
        "",
        "interface", // 29548 (0x736c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "class", // 26932 (0x6934)
        "",
        "",
        "",
        "const", // 26936 (0x6938)
        "finally", // 28249 (0x6e59)
        "",
        "",
        "",
        "int", // 27925 (0x6d15)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "throws", // 31553 (0x7b41)
        "case", // 26634 (0x680a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 27630 (0x6bee)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "char", // 26654 (0x681e)
        "",
        "",
        "",
        "long", // 28954 (0x711a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "extends", // 28002 (0x6d62)
        "",
        "throw", // 31284 (0x7a34)
        "",
        "",
        "",
        "do", // 26368 (0x6700)
        "",
        "goto", // 27682 (0x6c22)
        "",
        "volatile", // 32604 (0x7f5c)
        "static", // 31293 (0x7a3d)
        "",
        "",
        "",
        "synchronized", // 32937 (0x80a9)
        "final", // 27690 (0x6c2a)
        "",
        "",
        "switch", // 31301 (0x7a45)
        "",
        "",
        "",
        "",
        "",
        "",
        "native", // 29996 (0x752c)
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
        "",
        "",
        "",
        "byte", // 26402 (0x6722)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "this", // 31007 (0x791f)
        "default", // 27728 (0x6c50)
        "",
        "",
        "",
        "",
        "",
        "",
        "protected", // 31343 (0x7a6f)
        "",
        "",
        "",
        "",
        "continue", // 27740 (0x6c5c)
        "",
        "",
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
        "",
        "super", // 31036 (0x793c)
        "",
        "",
        "import", // 28743 (0x7047)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 32034 (0x7d22)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "transient", // 32383 (0x7e7f)
        "",
        "",
        "",
        "",
        "",
        "",
        "try", // 30750 (0x781e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 27156 (0x6a14)
        "else", // 27157 (0x6a15)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "package", // 30781 (0x783d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "private", // 30798 (0x784e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "instanceof", // 29822 (0x747e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "implements", // 29834 (0x748a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "boolean", // 27220 (0x6a54)
        "",
        "",
        "",
    };
    static int values[328] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 27230 (0x6a5e)
        41, // 29199 (0x720f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 26910 (0x691e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 30526 (0x773e)
        24, // 31511 (0x7b17)
        -1,
        -1,
        -1,
        -1,
        27, // 29548 (0x736c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 26932 (0x6934)
        -1,
        -1,
        -1,
        39, // 26936 (0x6938)
        31, // 28249 (0x6e59)
        -1,
        -1,
        -1,
        22, // 27925 (0x6d15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 31553 (0x7b41)
        20, // 26634 (0x680a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 27630 (0x6bee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 26654 (0x681e)
        -1,
        -1,
        -1,
        32, // 28954 (0x711a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 26674 (0x6832)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 28002 (0x6d62)
        -1,
        4, // 31284 (0x7a34)
        -1,
        -1,
        -1,
        6, // 26368 (0x6700)
        -1,
        44, // 27682 (0x6c22)
        -1,
        29, // 32604 (0x7f5c)
        28, // 31293 (0x7a3d)
        -1,
        -1,
        -1,
        42, // 32937 (0x80a9)
        26, // 27690 (0x6c2a)
        -1,
        -1,
        38, // 31301 (0x7a45)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 29996 (0x752c)
        36, // 27701 (0x6c35)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 26402 (0x6722)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 31007 (0x791f)
        1, // 27728 (0x6c50)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 31343 (0x7a6f)
        -1,
        -1,
        -1,
        -1,
        43, // 27740 (0x6c5c)
        -1,
        -1,
        -1,
        -1,
        23, // 31025 (0x7931)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 31033 (0x7939)
        -1,
        -1,
        33, // 31036 (0x793c)
        -1,
        -1,
        12, // 28743 (0x7047)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 32034 (0x7d22)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 27450 (0x6b3a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 32383 (0x7e7f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 30750 (0x781e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 27156 (0x6a14)
        16, // 27157 (0x6a15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 30781 (0x783d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 30798 (0x784e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 29822 (0x747e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 29834 (0x748a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 27220 (0x6a54)
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

//check: name=check_java_hash3, dataset=java, hash=hash3
void check_java_hash3() {
    assert(lookup_java_hash3("abstract") == 0);
    assert(lookup_java_hash3("new") == 41);
    assert(lookup_java_hash3("catch") == 25);
    assert(lookup_java_hash3("public") == 13);
    assert(lookup_java_hash3("void") == 24);
    assert(lookup_java_hash3("interface") == 27);
    assert(lookup_java_hash3("class") == 35);
    assert(lookup_java_hash3("const") == 39);
    assert(lookup_java_hash3("finally") == 31);
    assert(lookup_java_hash3("int") == 22);
    assert(lookup_java_hash3("throws") == 9);
    assert(lookup_java_hash3("case") == 20);
    assert(lookup_java_hash3("if") == 2);
    assert(lookup_java_hash3("char") == 30);
    assert(lookup_java_hash3("long") == 32);
    assert(lookup_java_hash3("break") == 10);
    assert(lookup_java_hash3("extends") == 21);
    assert(lookup_java_hash3("throw") == 4);
    assert(lookup_java_hash3("do") == 6);
    assert(lookup_java_hash3("goto") == 44);
    assert(lookup_java_hash3("volatile") == 29);
    assert(lookup_java_hash3("static") == 28);
    assert(lookup_java_hash3("synchronized") == 42);
    assert(lookup_java_hash3("final") == 26);
    assert(lookup_java_hash3("switch") == 38);
    assert(lookup_java_hash3("native") == 37);
    assert(lookup_java_hash3("float") == 36);
    assert(lookup_java_hash3("byte") == 15);
    assert(lookup_java_hash3("this") == 46);
    assert(lookup_java_hash3("default") == 1);
    assert(lookup_java_hash3("protected") == 8);
    assert(lookup_java_hash3("continue") == 43);
    assert(lookup_java_hash3("short") == 23);
    assert(lookup_java_hash3("return") == 18);
    assert(lookup_java_hash3("super") == 33);
    assert(lookup_java_hash3("import") == 12);
    assert(lookup_java_hash3("while") == 34);
    assert(lookup_java_hash3("double") == 11);
    assert(lookup_java_hash3("transient") == 14);
    assert(lookup_java_hash3("try") == 19);
    assert(lookup_java_hash3("for") == 40);
    assert(lookup_java_hash3("else") == 16);
    assert(lookup_java_hash3("package") == 45);
    assert(lookup_java_hash3("private") == 3);
    assert(lookup_java_hash3("instanceof") == 17);
    assert(lookup_java_hash3("implements") == 7);
    assert(lookup_java_hash3("boolean") == 5);
}

//lookup: name=lookup_java_hash_sum0, dataset=java, hash=hash_sum0
int lookup_java_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 56) * 2;
    static std::string_view lookup[112] = {
        "return", // 672 (0x2a0)
        "short", // 560 (0x230)
        "",
        "",
        "instanceof", // 1066 (0x42a)
        "",
        "",
        "",
        "throw", // 564 (0x234)
        "",
        "",
        "",
        "",
        "",
        "throws", // 679 (0x2a7)
        "",
        "boolean", // 736 (0x2e0)
        "",
        "",
        "",
        "",
        "",
        "catch", // 515 (0x203)
        "",
        "abstract", // 852 (0x354)
        "",
        "default", // 741 (0x2e5)
        "break", // 517 (0x205)
        "",
        "",
        "try", // 351 (0x15f)
        "",
        "",
        "",
        "",
        "",
        "protected", // 970 (0x3ca)
        "final", // 522 (0x20a)
        "double", // 635 (0x27b)
        "",
        "case", // 412 (0x19c)
        "",
        "",
        "",
        "implements", // 1086 (0x43e)
        "char", // 414 (0x19e)
        "public", // 639 (0x27f)
        "finally", // 751 (0x2ef)
        "volatile", // 864 (0x360)
        "synchronized", // 1312 (0x520)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "continue", // 869 (0x365)
        "",
        "class", // 534 (0x216)
        "float", // 534 (0x216)
        "native", // 647 (0x287)
        "",
        "transient", // 984 (0x3d8)
        "static", // 648 (0x288)
        "else", // 425 (0x1a9)
        "while", // 537 (0x219)
        "",
        "",
        "private", // 763 (0x2fb)
        "extends", // 763 (0x2fb)
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 207 (0xcf)
        "",
        "long", // 432 (0x1b0)
        "",
        "",
        "",
        "void", // 434 (0x1b2)
        "switch", // 658 (0x292)
        "do", // 211 (0xd3)
        "",
        "byte", // 436 (0x1b4)
        "package", // 716 (0x2cc)
        "",
        "",
        "",
        "",
        "const", // 551 (0x227)
        "for", // 327 (0x147)
        "this", // 440 (0x1b8)
        "",
        "interface", // 945 (0x3b1)
        "goto", // 441 (0x1b9)
        "new", // 330 (0x14a)
        "",
        "import", // 667 (0x29b)
        "int", // 331 (0x14b)
        "",
        "",
        "",
        "",
        "",
        "",
        "super", // 559 (0x22f)
        "",
    };
    static int values[112] = {
        18, // 672 (0x2a0)
        23, // 560 (0x230)
        -1,
        -1,
        17, // 1066 (0x42a)
        -1,
        -1,
        -1,
        4, // 564 (0x234)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 679 (0x2a7)
        -1,
        5, // 736 (0x2e0)
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 515 (0x203)
        -1,
        0, // 852 (0x354)
        -1,
        1, // 741 (0x2e5)
        10, // 517 (0x205)
        -1,
        -1,
        19, // 351 (0x15f)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 970 (0x3ca)
        26, // 522 (0x20a)
        11, // 635 (0x27b)
        -1,
        20, // 412 (0x19c)
        -1,
        -1,
        -1,
        7, // 1086 (0x43e)
        30, // 414 (0x19e)
        13, // 639 (0x27f)
        31, // 751 (0x2ef)
        29, // 864 (0x360)
        42, // 1312 (0x520)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 869 (0x365)
        -1,
        35, // 534 (0x216)
        36, // 534 (0x216)
        37, // 647 (0x287)
        -1,
        14, // 984 (0x3d8)
        28, // 648 (0x288)
        16, // 425 (0x1a9)
        34, // 537 (0x219)
        -1,
        -1,
        3, // 763 (0x2fb)
        21, // 763 (0x2fb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 207 (0xcf)
        -1,
        32, // 432 (0x1b0)
        -1,
        -1,
        -1,
        24, // 434 (0x1b2)
        38, // 658 (0x292)
        6, // 211 (0xd3)
        -1,
        15, // 436 (0x1b4)
        45, // 716 (0x2cc)
        -1,
        -1,
        -1,
        -1,
        39, // 551 (0x227)
        40, // 327 (0x147)
        46, // 440 (0x1b8)
        -1,
        27, // 945 (0x3b1)
        44, // 441 (0x1b9)
        41, // 330 (0x14a)
        -1,
        12, // 667 (0x29b)
        22, // 331 (0x14b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 559 (0x22f)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_java_hash_sum0, dataset=java, hash=hash_sum0
void check_java_hash_sum0() {
    assert(lookup_java_hash_sum0("return") == 18);
    assert(lookup_java_hash_sum0("short") == 23);
    assert(lookup_java_hash_sum0("instanceof") == 17);
    assert(lookup_java_hash_sum0("throw") == 4);
    assert(lookup_java_hash_sum0("throws") == 9);
    assert(lookup_java_hash_sum0("boolean") == 5);
    assert(lookup_java_hash_sum0("catch") == 25);
    assert(lookup_java_hash_sum0("abstract") == 0);
    assert(lookup_java_hash_sum0("default") == 1);
    assert(lookup_java_hash_sum0("break") == 10);
    assert(lookup_java_hash_sum0("try") == 19);
    assert(lookup_java_hash_sum0("protected") == 8);
    assert(lookup_java_hash_sum0("final") == 26);
    assert(lookup_java_hash_sum0("double") == 11);
    assert(lookup_java_hash_sum0("case") == 20);
    assert(lookup_java_hash_sum0("implements") == 7);
    assert(lookup_java_hash_sum0("char") == 30);
    assert(lookup_java_hash_sum0("public") == 13);
    assert(lookup_java_hash_sum0("finally") == 31);
    assert(lookup_java_hash_sum0("volatile") == 29);
    assert(lookup_java_hash_sum0("synchronized") == 42);
    assert(lookup_java_hash_sum0("continue") == 43);
    assert(lookup_java_hash_sum0("class") == 35);
    assert(lookup_java_hash_sum0("float") == 36);
    assert(lookup_java_hash_sum0("native") == 37);
    assert(lookup_java_hash_sum0("transient") == 14);
    assert(lookup_java_hash_sum0("static") == 28);
    assert(lookup_java_hash_sum0("else") == 16);
    assert(lookup_java_hash_sum0("while") == 34);
    assert(lookup_java_hash_sum0("private") == 3);
    assert(lookup_java_hash_sum0("extends") == 21);
    assert(lookup_java_hash_sum0("if") == 2);
    assert(lookup_java_hash_sum0("long") == 32);
    assert(lookup_java_hash_sum0("void") == 24);
    assert(lookup_java_hash_sum0("switch") == 38);
    assert(lookup_java_hash_sum0("do") == 6);
    assert(lookup_java_hash_sum0("byte") == 15);
    assert(lookup_java_hash_sum0("package") == 45);
    assert(lookup_java_hash_sum0("const") == 39);
    assert(lookup_java_hash_sum0("for") == 40);
    assert(lookup_java_hash_sum0("this") == 46);
    assert(lookup_java_hash_sum0("interface") == 27);
    assert(lookup_java_hash_sum0("goto") == 44);
    assert(lookup_java_hash_sum0("new") == 41);
    assert(lookup_java_hash_sum0("import") == 12);
    assert(lookup_java_hash_sum0("int") == 22);
    assert(lookup_java_hash_sum0("super") == 33);
}

//lookup: name=lookup_java_hash_sumN, dataset=java, hash=hash_sumN
int lookup_java_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 63) * 2;
    static std::string_view lookup[126] = {
        "",
        "",
        "synchronized", // 1324 (0x52c)
        "",
        "throw", // 569 (0x239)
        "finally", // 758 (0x2f6)
        "this", // 444 (0x1bc)
        "",
        "goto", // 445 (0x1bd)
        "",
        "instanceof", // 1076 (0x434)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "interface", // 954 (0x3ba)
        "",
        "",
        "",
        "double", // 641 (0x281)
        "",
        "",
        "",
        "",
        "",
        "private", // 770 (0x302)
        "extends", // 770 (0x302)
        "public", // 645 (0x285)
        "for", // 330 (0x14a)
        "catch", // 520 (0x208)
        "",
        "",
        "",
        "break", // 522 (0x20a)
        "new", // 333 (0x14d)
        "int", // 334 (0x14e)
        "",
        "if", // 209 (0xd1)
        "",
        "",
        "",
        "",
        "",
        "final", // 527 (0x20f)
        "native", // 653 (0x28d)
        "do", // 213 (0xd5)
        "static", // 654 (0x28e)
        "implements", // 1096 (0x448)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "package", // 723 (0x2d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "protected", // 979 (0x3d3)
        "switch", // 664 (0x298)
        "class", // 539 (0x21b)
        "float", // 539 (0x21b)
        "",
        "",
        "",
        "",
        "case", // 416 (0x1a0)
        "while", // 542 (0x21e)
        "try", // 354 (0x162)
        "",
        "char", // 418 (0x1a2)
        "",
        "abstract", // 860 (0x35c)
        "",
        "",
        "",
        "import", // 673 (0x2a1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "transient", // 993 (0x3e1)
        "return", // 678 (0x2a6)
        "",
        "",
        "boolean", // 743 (0x2e7)
        "",
        "else", // 429 (0x1ad)
        "",
        "const", // 556 (0x22c)
        "",
        "volatile", // 872 (0x368)
        "",
        "",
        "",
        "default", // 748 (0x2ec)
        "throws", // 685 (0x2ad)
        "",
        "",
        "",
        "",
        "long", // 436 (0x1b4)
        "continue", // 877 (0x36d)
        "",
        "",
        "void", // 438 (0x1b6)
        "super", // 564 (0x234)
        "short", // 565 (0x235)
        "",
        "byte", // 440 (0x1b8)
        "",
    };
    static int values[126] = {
        -1,
        -1,
        42, // 1324 (0x52c)
        -1,
        4, // 569 (0x239)
        31, // 758 (0x2f6)
        46, // 444 (0x1bc)
        -1,
        44, // 445 (0x1bd)
        -1,
        17, // 1076 (0x434)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 954 (0x3ba)
        -1,
        -1,
        -1,
        11, // 641 (0x281)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 770 (0x302)
        21, // 770 (0x302)
        13, // 645 (0x285)
        40, // 330 (0x14a)
        25, // 520 (0x208)
        -1,
        -1,
        -1,
        10, // 522 (0x20a)
        41, // 333 (0x14d)
        22, // 334 (0x14e)
        -1,
        2, // 209 (0xd1)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 527 (0x20f)
        37, // 653 (0x28d)
        6, // 213 (0xd5)
        28, // 654 (0x28e)
        7, // 1096 (0x448)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 723 (0x2d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 979 (0x3d3)
        38, // 664 (0x298)
        35, // 539 (0x21b)
        36, // 539 (0x21b)
        -1,
        -1,
        -1,
        -1,
        20, // 416 (0x1a0)
        34, // 542 (0x21e)
        19, // 354 (0x162)
        -1,
        30, // 418 (0x1a2)
        -1,
        0, // 860 (0x35c)
        -1,
        -1,
        -1,
        12, // 673 (0x2a1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 993 (0x3e1)
        18, // 678 (0x2a6)
        -1,
        -1,
        5, // 743 (0x2e7)
        -1,
        16, // 429 (0x1ad)
        -1,
        39, // 556 (0x22c)
        -1,
        29, // 872 (0x368)
        -1,
        -1,
        -1,
        1, // 748 (0x2ec)
        9, // 685 (0x2ad)
        -1,
        -1,
        -1,
        -1,
        32, // 436 (0x1b4)
        43, // 877 (0x36d)
        -1,
        -1,
        24, // 438 (0x1b6)
        33, // 564 (0x234)
        23, // 565 (0x235)
        -1,
        15, // 440 (0x1b8)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_java_hash_sumN, dataset=java, hash=hash_sumN
void check_java_hash_sumN() {
    assert(lookup_java_hash_sumN("synchronized") == 42);
    assert(lookup_java_hash_sumN("throw") == 4);
    assert(lookup_java_hash_sumN("finally") == 31);
    assert(lookup_java_hash_sumN("this") == 46);
    assert(lookup_java_hash_sumN("goto") == 44);
    assert(lookup_java_hash_sumN("instanceof") == 17);
    assert(lookup_java_hash_sumN("interface") == 27);
    assert(lookup_java_hash_sumN("double") == 11);
    assert(lookup_java_hash_sumN("private") == 3);
    assert(lookup_java_hash_sumN("extends") == 21);
    assert(lookup_java_hash_sumN("public") == 13);
    assert(lookup_java_hash_sumN("for") == 40);
    assert(lookup_java_hash_sumN("catch") == 25);
    assert(lookup_java_hash_sumN("break") == 10);
    assert(lookup_java_hash_sumN("new") == 41);
    assert(lookup_java_hash_sumN("int") == 22);
    assert(lookup_java_hash_sumN("if") == 2);
    assert(lookup_java_hash_sumN("final") == 26);
    assert(lookup_java_hash_sumN("native") == 37);
    assert(lookup_java_hash_sumN("do") == 6);
    assert(lookup_java_hash_sumN("static") == 28);
    assert(lookup_java_hash_sumN("implements") == 7);
    assert(lookup_java_hash_sumN("package") == 45);
    assert(lookup_java_hash_sumN("protected") == 8);
    assert(lookup_java_hash_sumN("switch") == 38);
    assert(lookup_java_hash_sumN("class") == 35);
    assert(lookup_java_hash_sumN("float") == 36);
    assert(lookup_java_hash_sumN("case") == 20);
    assert(lookup_java_hash_sumN("while") == 34);
    assert(lookup_java_hash_sumN("try") == 19);
    assert(lookup_java_hash_sumN("char") == 30);
    assert(lookup_java_hash_sumN("abstract") == 0);
    assert(lookup_java_hash_sumN("import") == 12);
    assert(lookup_java_hash_sumN("transient") == 14);
    assert(lookup_java_hash_sumN("return") == 18);
    assert(lookup_java_hash_sumN("boolean") == 5);
    assert(lookup_java_hash_sumN("else") == 16);
    assert(lookup_java_hash_sumN("const") == 39);
    assert(lookup_java_hash_sumN("volatile") == 29);
    assert(lookup_java_hash_sumN("default") == 1);
    assert(lookup_java_hash_sumN("throws") == 9);
    assert(lookup_java_hash_sumN("long") == 32);
    assert(lookup_java_hash_sumN("continue") == 43);
    assert(lookup_java_hash_sumN("void") == 24);
    assert(lookup_java_hash_sumN("super") == 33);
    assert(lookup_java_hash_sumN("short") == 23);
    assert(lookup_java_hash_sumN("byte") == 15);
}

//lookup: name=lookup_java_hash_djb2, dataset=java, hash=hash_djb2
int lookup_java_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 230) * 1;
    static std::string_view lookup[230] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "static", // 7083177690897 (0x6712e4a4711)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 7082585429636 (0x6710afd1684)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "interface", // 254533860842675834 (0x3884932a6d61e7a)
        "",
        "",
        "package", // 233740247863157 (0xd495e4718f75)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "catch", // 214622110796 (0x31f879844c)
        "",
        "",
        "new", // 197093939 (0xbbf6a33)
        "do", // 5972220 (0x5b20fc)
        "",
        "",
        "",
        "",
        "transient", // 254549477626873985 (0x3885766b7b60881)
        "",
        "",
        "",
        "boolean", // 233722729478249 (0xd491d0443869)
        "",
        "",
        "",
        "",
        "",
        "throw", // 214642521245 (0x31f9b0f49d)
        "",
        "",
        "",
        "return", // 7083121450889 (0x6712af01f89)
        "goto", // 6503859330 (0x183a90482)
        "class", // 214622485951 (0x31f87f3dbf)
        "",
        "short", // 214641332153 (0x31f99ecfb9)
        "",
        "",
        "finally", // 233727658964536 (0xd492f6163638)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "byte", // 6503690525 (0x183a6711d)
        "",
        "abstract", // 7712790831751517 (0x1b66be0dc0e15d)
        "",
        "",
        "",
        "void", // 6504398011 (0x183b13cbb)
        "super", // 214641799992 (0x31f9a5f338)
        "",
        "import", // 7082778569444 (0x67116802ae4)
        "",
        "else", // 6503784146 (0x183a7ded2)
        "",
        "",
        "volatile", // 7713702311738249 (0x1b67924631bb89)
        "throws", // 7083203201200 (0x6712fcf88b0)
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
        "instanceof", // 8399617383906139251 (0x74916f81f0ebdc73)
        "",
        "",
        "try", // 197100904 (0xbbf8568)
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
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
        "long", // 6504038809 (0x183abc199)
        "",
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
        "",
        "",
        "default", // 233724910009454 (0xd492523c7c6e)
        "",
        "",
        "",
        "",
        "",
        "",
        "protected", // 254543870290962451 (0x388524d28722813)
        "for", // 197085552 (0xbbf4970)
        "switch", // 7083181535963 (0x6712e84f2db)
        "",
        "",
        "continue", // 7712892661735406 (0x1b66d5c34b1fee)
        "",
        "native", // 7082960152688 (0x6712152e870)
        "",
        "",
        "",
        "",
        "",
        "extends", // 233726961788644 (0xd492cc8826e4)
        "",
        "",
        "",
        "int", // 197088788 (0xbbf5614)
        "this", // 6504318529 (0x183b00641)
        "private", // 233740920676100 (0xd4960c8bdf04)
        "",
        "",
        "case", // 6503700293 (0x183a69745)
        "",
        "",
        "",
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
        "",
        "",
        "",
        "implements", // 8399615839465885831 (0x74916e1a591bd087)
        "",
        "",
        "",
        "",
        "break", // 214621519406 (0x31f8707e2e)
        "synchronized", // 16567027359139331977 (0xe5e9e79b75ad7f89)
        "",
        "",
        "",
        "",
        "",
        "",
        "public", // 7083061497864 (0x671275d5008)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "final", // 214625949459 (0x31f8b41713)
    };
    static int values[230] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 7083177690897 (0x6712e4a4711)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 7082585429636 (0x6710afd1684)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 254533860842675834 (0x3884932a6d61e7a)
        -1,
        -1,
        45, // 233740247863157 (0xd495e4718f75)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 214622110796 (0x31f879844c)
        -1,
        -1,
        41, // 197093939 (0xbbf6a33)
        6, // 5972220 (0x5b20fc)
        -1,
        -1,
        -1,
        -1,
        14, // 254549477626873985 (0x3885766b7b60881)
        -1,
        -1,
        -1,
        5, // 233722729478249 (0xd491d0443869)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 214642521245 (0x31f9b0f49d)
        -1,
        -1,
        -1,
        18, // 7083121450889 (0x6712af01f89)
        44, // 6503859330 (0x183a90482)
        35, // 214622485951 (0x31f87f3dbf)
        -1,
        23, // 214641332153 (0x31f99ecfb9)
        -1,
        -1,
        31, // 233727658964536 (0xd492f6163638)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 6503690525 (0x183a6711d)
        -1,
        0, // 7712790831751517 (0x1b66be0dc0e15d)
        -1,
        -1,
        -1,
        24, // 6504398011 (0x183b13cbb)
        33, // 214641799992 (0x31f9a5f338)
        -1,
        12, // 7082778569444 (0x67116802ae4)
        -1,
        16, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        29, // 7713702311738249 (0x1b67924631bb89)
        9, // 7083203201200 (0x6712fcf88b0)
        -1,
        -1,
        -1,
        -1,
        30, // 6503707335 (0x183a6b2c7)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 8399617383906139251 (0x74916f81f0ebdc73)
        -1,
        -1,
        19, // 197100904 (0xbbf8568)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 214626058367 (0x31f8b5c07f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 214622607920 (0x31f8811a30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 6504038809 (0x183abc199)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 214646069090 (0x31f9e71762)
        -1,
        -1,
        -1,
        1, // 233724910009454 (0xd492523c7c6e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 254543870290962451 (0x388524d28722813)
        40, // 197085552 (0xbbf4970)
        38, // 7083181535963 (0x6712e84f2db)
        -1,
        -1,
        43, // 7712892661735406 (0x1b66d5c34b1fee)
        -1,
        37, // 7082960152688 (0x6712152e870)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 233726961788644 (0xd492cc8826e4)
        -1,
        -1,
        -1,
        22, // 197088788 (0xbbf5614)
        46, // 6504318529 (0x183b00641)
        3, // 233740920676100 (0xd4960c8bdf04)
        -1,
        -1,
        20, // 6503700293 (0x183a69745)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 5972376 (0x5b2198)
        -1,
        -1,
        -1,
        -1,
        7, // 8399615839465885831 (0x74916e1a591bd087)
        -1,
        -1,
        -1,
        -1,
        10, // 214621519406 (0x31f8707e2e)
        42, // 16567027359139331977 (0xe5e9e79b75ad7f89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 7083061497864 (0x671275d5008)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 214625949459 (0x31f8b41713)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_java_hash_djb2, dataset=java, hash=hash_djb2
void check_java_hash_djb2() {
    assert(lookup_java_hash_djb2("static") == 28);
    assert(lookup_java_hash_djb2("double") == 11);
    assert(lookup_java_hash_djb2("interface") == 27);
    assert(lookup_java_hash_djb2("package") == 45);
    assert(lookup_java_hash_djb2("catch") == 25);
    assert(lookup_java_hash_djb2("new") == 41);
    assert(lookup_java_hash_djb2("do") == 6);
    assert(lookup_java_hash_djb2("transient") == 14);
    assert(lookup_java_hash_djb2("boolean") == 5);
    assert(lookup_java_hash_djb2("throw") == 4);
    assert(lookup_java_hash_djb2("return") == 18);
    assert(lookup_java_hash_djb2("goto") == 44);
    assert(lookup_java_hash_djb2("class") == 35);
    assert(lookup_java_hash_djb2("short") == 23);
    assert(lookup_java_hash_djb2("finally") == 31);
    assert(lookup_java_hash_djb2("byte") == 15);
    assert(lookup_java_hash_djb2("abstract") == 0);
    assert(lookup_java_hash_djb2("void") == 24);
    assert(lookup_java_hash_djb2("super") == 33);
    assert(lookup_java_hash_djb2("import") == 12);
    assert(lookup_java_hash_djb2("else") == 16);
    assert(lookup_java_hash_djb2("volatile") == 29);
    assert(lookup_java_hash_djb2("throws") == 9);
    assert(lookup_java_hash_djb2("char") == 30);
    assert(lookup_java_hash_djb2("instanceof") == 17);
    assert(lookup_java_hash_djb2("try") == 19);
    assert(lookup_java_hash_djb2("float") == 36);
    assert(lookup_java_hash_djb2("const") == 39);
    assert(lookup_java_hash_djb2("long") == 32);
    assert(lookup_java_hash_djb2("while") == 34);
    assert(lookup_java_hash_djb2("default") == 1);
    assert(lookup_java_hash_djb2("protected") == 8);
    assert(lookup_java_hash_djb2("for") == 40);
    assert(lookup_java_hash_djb2("switch") == 38);
    assert(lookup_java_hash_djb2("continue") == 43);
    assert(lookup_java_hash_djb2("native") == 37);
    assert(lookup_java_hash_djb2("extends") == 21);
    assert(lookup_java_hash_djb2("int") == 22);
    assert(lookup_java_hash_djb2("this") == 46);
    assert(lookup_java_hash_djb2("private") == 3);
    assert(lookup_java_hash_djb2("case") == 20);
    assert(lookup_java_hash_djb2("if") == 2);
    assert(lookup_java_hash_djb2("implements") == 7);
    assert(lookup_java_hash_djb2("break") == 10);
    assert(lookup_java_hash_djb2("synchronized") == 42);
    assert(lookup_java_hash_djb2("public") == 13);
    assert(lookup_java_hash_djb2("final") == 26);
}

//lookup: name=lookup_java_hash_sdb, dataset=java, hash=hash_sdb
int lookup_java_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 365) * 1;
    static std::string_view lookup[365] = {
        "interface", // 12514925068772314305 (0xadadf20b0ace0cc1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 28433340858241073 (0x6503f90da21031)
        "",
        "for", // 438134048085 (0x6602d30555)
        "",
        "",
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
        "switch", // 3344932667539956616 (0x2e6b9689f651a388)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "static", // 3332546763507343818 (0x2e3f959ff43ba1ca)
        "instanceof", // 724521019631549344 (0xa0e040757713ba0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 27870266342903704 (0x6303dc0d2a0f98)
        "",
        "",
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
        "",
        "synchronized", // 3330564478679133348 (0x2e388abf4d342ca4)
        "class", // 364819122969718764 (0x510190f37e12fec)
        "",
        "",
        "",
        "",
        "",
        "boolean", // 18113585239123538960 (0xfb6061ce1ab7b410)
        "do", // 6554011 (0x64019b)
        "",
        "throw", // 421117979607119218 (0x5d81c923f033572)
        "",
        "extends", // 365770552778081885 (0x5137a613ba2c65d)
        "",
        "",
        "",
        "",
        "",
        "",
        "char", // 27870296409247662 (0x6303e30d420fae)
        "",
        "private", // 1853414300009618939 (0x19b8a67c6db3ddfb)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "throws", // 3322131201497211081 (0x2e1a94b9f27ba0c9)
        "",
        "",
        "short", // 417740035065394444 (0x5cc1c593e88350c)
        "",
        "",
        "",
        "",
        "",
        "",
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
        "continue", // 6848942472000841643 (0x5f0c54e41ab227ab)
        "",
        "",
        "",
        "package", // 1399373631390272162 (0x136b92e74f10caa2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "const", // 365663719708962995 (0x5131937388030b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "finally", // 116369992049604787 (0x19d6de426a1b8b3)
        "void", // 33219085507826168 (0x7604950f7511f8)
        "",
        "implements", // 11829362627980883380 (0xa42a56a2b014f5b4)
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "import", // 3059784849221326761 (0x2a768a1be2f597a9)
        "",
        "new", // 472496276868 (0x6e02f90584)
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "transient", // 18292036757232426046 (0xfdda5e83ed3a1c3e)
        "",
        "super", // 421399716591318603 (0x5d91ccf3fe0364b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "this", // 32656028173930898 (0x74047c0f151192)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "final", // 374108432876187846 (0x53119a3391030c6)
        "",
        "byte", // 27588855798435928 (0x6203eb0da01058)
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "break", // 363130290293256227 (0x50a1913381d3023)
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 431251735916197369 (0x5fc1d2b400e35f9)
        "public", // 3260204451718471445 (0x2d3e92acefd39f15)
        "",
        "abstract", // 3406116446903072422 (0x2f44f4dcb145f6a6)
        "",
        "",
        "",
        "",
        "float", // 374952978071105832 (0x53419bf39673128)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "native", // 3147045235970447567 (0x2bac8cf7e61a98cf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "try", // 498269292003 (0x74032a05e3)
        "",
        "",
        "",
        "if", // 6881697 (0x6901a1)
        "",
        "",
        "",
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
    static int values[365] = {
        27, // 12514925068772314305 (0xadadf20b0ace0cc1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 28433340858241073 (0x6503f90da21031)
        -1,
        40, // 438134048085 (0x6602d30555)
        -1,
        -1,
        -1,
        11, // 2941278687000499069 (0x28d18561dc17937d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 3344932667539956616 (0x2e6b9689f651a388)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 3332546763507343818 (0x2e3f959ff43ba1ca)
        17, // 724521019631549344 (0xa0e040757713ba0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 27870266342903704 (0x6303dc0d2a0f98)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 3261892644424556104 (0x2d449213ee629e48)
        -1,
        -1,
        -1,
        42, // 3330564478679133348 (0x2e388abf4d342ca4)
        35, // 364819122969718764 (0x510190f37e12fec)
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 18113585239123538960 (0xfb6061ce1ab7b410)
        6, // 6554011 (0x64019b)
        -1,
        4, // 421117979607119218 (0x5d81c923f033572)
        -1,
        21, // 365770552778081885 (0x5137a613ba2c65d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 27870296409247662 (0x6303e30d420fae)
        -1,
        3, // 1853414300009618939 (0x19b8a67c6db3ddfb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 3452512564192461556 (0x2fe9c9e28b43c2f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 3322131201497211081 (0x2e1a94b9f27ba0c9)
        -1,
        -1,
        23, // 417740035065394444 (0x5cc1c593e88350c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 28996381010759823 (0x67040e0deb108f)
        -1,
        -1,
        -1,
        -1,
        43, // 6848942472000841643 (0x5f0c54e41ab227ab)
        -1,
        -1,
        -1,
        45, // 1399373631390272162 (0x136b92e74f10caa2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 18130751609074855161 (0xfb9d5e8711bfacf9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 365663719708962995 (0x5131937388030b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 116369992049604787 (0x19d6de426a1b8b3)
        24, // 33219085507826168 (0x7604950f7511f8)
        -1,
        7, // 11829362627980883380 (0xa42a56a2b014f5b4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
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
        -1,
        -1,
        12, // 3059784849221326761 (0x2a768a1be2f597a9)
        -1,
        41, // 472496276868 (0x6e02f90584)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 361722554615476019 (0x50518bf371a2f33)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 18292036757232426046 (0xfdda5e83ed3a1c3e)
        -1,
        33, // 421399716591318603 (0x5d91ccf3fe0364b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 32656028173930898 (0x74047c0f151192)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 374108432876187846 (0x53119a3391030c6)
        -1,
        15, // 27588855798435928 (0x6203eb0da01058)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 30403949176295676 (0x6c043b0e6c10fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 363130290293256227 (0x50a1913381d3023)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 431251735916197369 (0x5fc1d2b400e35f9)
        13, // 3260204451718471445 (0x2d3e92acefd39f15)
        -1,
        0, // 3406116446903072422 (0x2f44f4dcb145f6a6)
        -1,
        -1,
        -1,
        -1,
        36, // 374952978071105832 (0x53419bf39673128)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 3147045235970447567 (0x2bac8cf7e61a98cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 5201487412384685718 (0x482f653e2edade96)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 498269292003 (0x74032a05e3)
        -1,
        -1,
        -1,
        2, // 6881697 (0x6901a1)
        -1,
        -1,
        -1,
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

//check: name=check_java_hash_sdb, dataset=java, hash=hash_sdb
void check_java_hash_sdb() {
    assert(lookup_java_hash_sdb("interface") == 27);
    assert(lookup_java_hash_sdb("else") == 16);
    assert(lookup_java_hash_sdb("for") == 40);
    assert(lookup_java_hash_sdb("double") == 11);
    assert(lookup_java_hash_sdb("switch") == 38);
    assert(lookup_java_hash_sdb("static") == 28);
    assert(lookup_java_hash_sdb("instanceof") == 17);
    assert(lookup_java_hash_sdb("case") == 20);
    assert(lookup_java_hash_sdb("return") == 18);
    assert(lookup_java_hash_sdb("synchronized") == 42);
    assert(lookup_java_hash_sdb("class") == 35);
    assert(lookup_java_hash_sdb("boolean") == 5);
    assert(lookup_java_hash_sdb("do") == 6);
    assert(lookup_java_hash_sdb("throw") == 4);
    assert(lookup_java_hash_sdb("extends") == 21);
    assert(lookup_java_hash_sdb("char") == 30);
    assert(lookup_java_hash_sdb("private") == 3);
    assert(lookup_java_hash_sdb("volatile") == 29);
    assert(lookup_java_hash_sdb("throws") == 9);
    assert(lookup_java_hash_sdb("short") == 23);
    assert(lookup_java_hash_sdb("goto") == 44);
    assert(lookup_java_hash_sdb("continue") == 43);
    assert(lookup_java_hash_sdb("package") == 45);
    assert(lookup_java_hash_sdb("default") == 1);
    assert(lookup_java_hash_sdb("const") == 39);
    assert(lookup_java_hash_sdb("finally") == 31);
    assert(lookup_java_hash_sdb("void") == 24);
    assert(lookup_java_hash_sdb("implements") == 7);
    assert(lookup_java_hash_sdb("int") == 22);
    assert(lookup_java_hash_sdb("import") == 12);
    assert(lookup_java_hash_sdb("new") == 41);
    assert(lookup_java_hash_sdb("catch") == 25);
    assert(lookup_java_hash_sdb("transient") == 14);
    assert(lookup_java_hash_sdb("super") == 33);
    assert(lookup_java_hash_sdb("this") == 46);
    assert(lookup_java_hash_sdb("final") == 26);
    assert(lookup_java_hash_sdb("byte") == 15);
    assert(lookup_java_hash_sdb("long") == 32);
    assert(lookup_java_hash_sdb("break") == 10);
    assert(lookup_java_hash_sdb("while") == 34);
    assert(lookup_java_hash_sdb("public") == 13);
    assert(lookup_java_hash_sdb("abstract") == 0);
    assert(lookup_java_hash_sdb("float") == 36);
    assert(lookup_java_hash_sdb("native") == 37);
    assert(lookup_java_hash_sdb("protected") == 8);
    assert(lookup_java_hash_sdb("try") == 19);
    assert(lookup_java_hash_sdb("if") == 2);
}
