
//lookup: name=lookup_jscript_hash1, dataset=jscript, type=hash, hash=hash1
int lookup_jscript_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 87) * 2;
    static std::string_view lookup[174] = {
        "transient", // 2088 (0x828)
        "var", // 696 (0x2b8)
        "",
        "",
        "null", // 872 (0x368)
        "void", // 872 (0x368)
        "",
        "",
        "",
        "",
        "",
        "",
        "final", // 1050 (0x41a)
        "",
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
        "package", // 1491 (0x5d3)
        "private", // 1491 (0x5d3)
        "byte", // 796 (0x31c)
        "",
        "super", // 1145 (0x479)
        "",
        "try", // 711 (0x2c7)
        "",
        "",
        "",
        "case", // 800 (0x320)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "import", // 1326 (0x52e)
        "",
        "with", // 892 (0x37c)
        "",
        "",
        "",
        "short", // 1155 (0x483)
        "",
        "else", // 808 (0x328)
        "implements", // 2200 (0x898)
        "class", // 1070 (0x42e)
        "",
        "interface", // 1854 (0x73e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "const", // 1075 (0x433)
        "",
        "",
        "",
        "default", // 1512 (0x5e8)
        "extends", // 1512 (0x5e8)
        "continue", // 1600 (0x640)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 648 (0x288)
        "return", // 1344 (0x540)
        "",
        "",
        "",
        "",
        "",
        "",
        "function", // 1696 (0x6a0)
        "",
        "throw", // 1175 (0x497)
        "",
        "",
        "",
        "float", // 1090 (0x442)
        "",
        "",
        "",
        "native", // 1266 (0x4f2)
        "public", // 1266 (0x4f2)
        "",
        "",
        "",
        "",
        "abstract", // 1704 (0x6a8)
        "",
        "",
        "",
        "",
        "",
        "int", // 663 (0x297)
        "this", // 924 (0x39c)
        "",
        "",
        "while", // 1100 (0x44c)
        "",
        "synchronized", // 2580 (0xa14)
        "",
        "catch", // 1015 (0x3f7)
        "false", // 1015 (0x3f7)
        "",
        "",
        "",
        "",
        "long", // 844 (0x34c)
        "",
        "",
        "",
        "",
        "",
        "boolean", // 1456 (0x5b0)
        "",
        "",
        "",
        "if", // 414 (0x19e)
        "static", // 1284 (0x504)
        "",
        "",
        "break", // 1025 (0x401)
        "",
        "char", // 852 (0x354)
        "instanceof", // 2070 (0x816)
        "",
        "",
        "",
        "",
        "",
        "",
        "goto", // 856 (0x358)
        "",
        "do", // 422 (0x1a6)
        "",
        "double", // 1206 (0x4b6)
        "",
        "",
        "",
        "",
        "",
        "new", // 687 (0x2af)
        "",
        "",
        "",
        "",
        "",
        "protected", // 1908 (0x774)
        "throws", // 1386 (0x56a)
        "finally", // 1561 (0x619)
        "in", // 430 (0x1ae)
        "",
        "",
        "",
        "",
        "true", // 868 (0x364)
        "",
        "",
        "",
    };
    static int values[174] = {
        46, // 2088 (0x828)
        49, // 696 (0x2b8)
        -1,
        -1,
        32, // 872 (0x368)
        50, // 872 (0x368)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 1050 (0x41a)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 1314 (0x522)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 1491 (0x5d3)
        34, // 1491 (0x5d3)
        3, // 796 (0x31c)
        -1,
        40, // 1145 (0x479)
        -1,
        48, // 711 (0x2c7)
        -1,
        -1,
        -1,
        4, // 800 (0x320)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 1326 (0x52e)
        -1,
        52, // 892 (0x37c)
        -1,
        -1,
        -1,
        38, // 1155 (0x483)
        -1,
        13, // 808 (0x328)
        23, // 2200 (0x898)
        7, // 1070 (0x42e)
        -1,
        28, // 1854 (0x73e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 1075 (0x433)
        -1,
        -1,
        -1,
        10, // 1512 (0x5e8)
        14, // 1512 (0x5e8)
        9, // 1600 (0x640)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 648 (0x288)
        37, // 1344 (0x540)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 1696 (0x6a0)
        -1,
        44, // 1175 (0x497)
        -1,
        -1,
        -1,
        18, // 1090 (0x442)
        -1,
        -1,
        -1,
        30, // 1266 (0x4f2)
        36, // 1266 (0x4f2)
        -1,
        -1,
        -1,
        -1,
        0, // 1704 (0x6a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 663 (0x297)
        43, // 924 (0x39c)
        -1,
        -1,
        51, // 1100 (0x44c)
        -1,
        42, // 2580 (0xa14)
        -1,
        5, // 1015 (0x3f7)
        15, // 1015 (0x3f7)
        -1,
        -1,
        -1,
        -1,
        29, // 844 (0x34c)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 1456 (0x5b0)
        -1,
        -1,
        -1,
        22, // 414 (0x19e)
        39, // 1284 (0x504)
        -1,
        -1,
        2, // 1025 (0x401)
        -1,
        6, // 852 (0x354)
        26, // 2070 (0x816)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 856 (0x358)
        -1,
        11, // 422 (0x1a6)
        -1,
        12, // 1206 (0x4b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 687 (0x2af)
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 1908 (0x774)
        45, // 1386 (0x56a)
        17, // 1561 (0x619)
        25, // 430 (0x1ae)
        -1,
        -1,
        -1,
        -1,
        47, // 868 (0x364)
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

//check: name=check_jscript_hash1, dataset=jscript, type=hash, hash=hash1
void check_jscript_hash1() {
    assert(lookup_jscript_hash1("transient") == 46);
    assert(lookup_jscript_hash1("var") == 49);
    assert(lookup_jscript_hash1("null") == 32);
    assert(lookup_jscript_hash1("void") == 50);
    assert(lookup_jscript_hash1("final") == 16);
    assert(lookup_jscript_hash1("switch") == 41);
    assert(lookup_jscript_hash1("package") == 33);
    assert(lookup_jscript_hash1("private") == 34);
    assert(lookup_jscript_hash1("byte") == 3);
    assert(lookup_jscript_hash1("super") == 40);
    assert(lookup_jscript_hash1("try") == 48);
    assert(lookup_jscript_hash1("case") == 4);
    assert(lookup_jscript_hash1("import") == 24);
    assert(lookup_jscript_hash1("with") == 52);
    assert(lookup_jscript_hash1("short") == 38);
    assert(lookup_jscript_hash1("else") == 13);
    assert(lookup_jscript_hash1("implements") == 23);
    assert(lookup_jscript_hash1("class") == 7);
    assert(lookup_jscript_hash1("interface") == 28);
    assert(lookup_jscript_hash1("const") == 8);
    assert(lookup_jscript_hash1("default") == 10);
    assert(lookup_jscript_hash1("extends") == 14);
    assert(lookup_jscript_hash1("continue") == 9);
    assert(lookup_jscript_hash1("for") == 19);
    assert(lookup_jscript_hash1("return") == 37);
    assert(lookup_jscript_hash1("function") == 20);
    assert(lookup_jscript_hash1("throw") == 44);
    assert(lookup_jscript_hash1("float") == 18);
    assert(lookup_jscript_hash1("native") == 30);
    assert(lookup_jscript_hash1("public") == 36);
    assert(lookup_jscript_hash1("abstract") == 0);
    assert(lookup_jscript_hash1("int") == 27);
    assert(lookup_jscript_hash1("this") == 43);
    assert(lookup_jscript_hash1("while") == 51);
    assert(lookup_jscript_hash1("synchronized") == 42);
    assert(lookup_jscript_hash1("catch") == 5);
    assert(lookup_jscript_hash1("false") == 15);
    assert(lookup_jscript_hash1("long") == 29);
    assert(lookup_jscript_hash1("boolean") == 1);
    assert(lookup_jscript_hash1("if") == 22);
    assert(lookup_jscript_hash1("static") == 39);
    assert(lookup_jscript_hash1("break") == 2);
    assert(lookup_jscript_hash1("char") == 6);
    assert(lookup_jscript_hash1("instanceof") == 26);
    assert(lookup_jscript_hash1("goto") == 21);
    assert(lookup_jscript_hash1("do") == 11);
    assert(lookup_jscript_hash1("double") == 12);
    assert(lookup_jscript_hash1("new") == 31);
    assert(lookup_jscript_hash1("protected") == 35);
    assert(lookup_jscript_hash1("throws") == 45);
    assert(lookup_jscript_hash1("finally") == 17);
    assert(lookup_jscript_hash1("in") == 25);
    assert(lookup_jscript_hash1("true") == 47);
}

//lookup: name=lookup_jscript_hash2, dataset=jscript, type=hash, hash=hash2
int lookup_jscript_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 88) * 2;
    static std::string_view lookup[176] = {
        "",
        "",
        "transient", // 13465 (0x3499)
        "",
        "",
        "",
        "false", // 10299 (0x283b)
        "",
        "null", // 11884 (0x2e6c)
        "",
        "catch", // 10301 (0x283d)
        "",
        "public", // 11094 (0x2b56)
        "",
        "",
        "",
        "true", // 11712 (0x2dc0)
        "",
        "implements", // 12065 (0x2f21)
        "",
        "",
        "",
        "break", // 10483 (0x28f3)
        "",
        "void", // 11804 (0x2e1c)
        "",
        "",
        "",
        "do", // 11102 (0x2b5e)
        "",
        "for", // 11631 (0x2d6f)
        "",
        "native", // 11104 (0x2b60)
        "",
        "finally", // 12337 (0x3031)
        "",
        "char", // 11282 (0x2c12)
        "",
        "",
        "",
        "in", // 11548 (0x2d1c)
        "",
        "final", // 11021 (0x2b0d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "protected", // 11209 (0x2bc9)
        "",
        "import", // 12178 (0x2f92)
        "",
        "",
        "",
        "class", // 11388 (0x2c7c)
        "interface", // 10596 (0x2964)
        "",
        "",
        "",
        "",
        "int", // 12183 (0x2f97)
        "static", // 11391 (0x2c7f)
        "",
        "",
        "const", // 11481 (0x2cd9)
        "",
        "return", // 12538 (0x30fa)
        "",
        "boolean", // 10779 (0x2a1b)
        "",
        "",
        "",
        "float", // 11837 (0x2e3d)
        "",
        "byte", // 9902 (0x26ae)
        "",
        "continue", // 9991 (0x2707)
        "try", // 14039 (0x36d7)
        "synchronized", // 11488 (0x2ce0)
        "this", // 13336 (0x3418)
        "short", // 13337 (0x3419)
        "",
        "throws", // 13338 (0x341a)
        "",
        "case", // 9995 (0x270b)
        "",
        "function", // 11228 (0x2bdc)
        "",
        "",
        "",
        "while", // 12022 (0x2ef6)
        "",
        "package", // 11319 (0x2c37)
        "private", // 11319 (0x2c37)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 10708 (0x29d4)
        "with", // 12380 (0x305c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "new", // 13089 (0x3321)
        "",
        "double", // 10098 (0x2772)
        "",
        "",
        "",
        "instanceof", // 10716 (0x29dc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "throw", // 13801 (0x35e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "default", // 11607 (0x2d57)
        "var", // 13455 (0x348f)
        "extends", // 11608 (0x2d58)
        "",
        "",
        "",
        "",
        "",
        "super", // 13107 (0x3333)
        "",
        "abstract", // 11260 (0x2bfc)
        "",
        "else", // 10205 (0x27dd)
        "goto", // 11437 (0x2cad)
        "switch", // 11966 (0x2ebe)
        "",
        "",
        "",
    };
    static int values[176] = {
        -1,
        -1,
        46, // 13465 (0x3499)
        -1,
        -1,
        -1,
        15, // 10299 (0x283b)
        -1,
        32, // 11884 (0x2e6c)
        -1,
        5, // 10301 (0x283d)
        -1,
        36, // 11094 (0x2b56)
        -1,
        -1,
        -1,
        47, // 11712 (0x2dc0)
        -1,
        23, // 12065 (0x2f21)
        -1,
        -1,
        -1,
        2, // 10483 (0x28f3)
        -1,
        50, // 11804 (0x2e1c)
        -1,
        -1,
        -1,
        11, // 11102 (0x2b5e)
        -1,
        19, // 11631 (0x2d6f)
        -1,
        30, // 11104 (0x2b60)
        -1,
        17, // 12337 (0x3031)
        -1,
        6, // 11282 (0x2c12)
        -1,
        -1,
        -1,
        25, // 11548 (0x2d1c)
        -1,
        16, // 11021 (0x2b0d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 11120 (0x2b70)
        -1,
        35, // 11209 (0x2bc9)
        -1,
        24, // 12178 (0x2f92)
        -1,
        -1,
        -1,
        7, // 11388 (0x2c7c)
        28, // 10596 (0x2964)
        -1,
        -1,
        -1,
        -1,
        27, // 12183 (0x2f97)
        39, // 11391 (0x2c7f)
        -1,
        -1,
        8, // 11481 (0x2cd9)
        -1,
        37, // 12538 (0x30fa)
        -1,
        1, // 10779 (0x2a1b)
        -1,
        -1,
        -1,
        18, // 11837 (0x2e3d)
        -1,
        3, // 9902 (0x26ae)
        -1,
        9, // 9991 (0x2707)
        48, // 14039 (0x36d7)
        42, // 11488 (0x2ce0)
        43, // 13336 (0x3418)
        38, // 13337 (0x3419)
        -1,
        45, // 13338 (0x341a)
        -1,
        4, // 9995 (0x270b)
        -1,
        20, // 11228 (0x2bdc)
        -1,
        -1,
        -1,
        51, // 12022 (0x2ef6)
        -1,
        33, // 11319 (0x2c37)
        34, // 11319 (0x2c37)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 10708 (0x29d4)
        52, // 12380 (0x305c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 13089 (0x3321)
        -1,
        12, // 10098 (0x2772)
        -1,
        -1,
        -1,
        26, // 10716 (0x29dc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 13801 (0x35e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 11607 (0x2d57)
        49, // 13455 (0x348f)
        14, // 11608 (0x2d58)
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 13107 (0x3333)
        -1,
        0, // 11260 (0x2bfc)
        -1,
        13, // 10205 (0x27dd)
        21, // 11437 (0x2cad)
        41, // 11966 (0x2ebe)
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

//check: name=check_jscript_hash2, dataset=jscript, type=hash, hash=hash2
void check_jscript_hash2() {
    assert(lookup_jscript_hash2("transient") == 46);
    assert(lookup_jscript_hash2("false") == 15);
    assert(lookup_jscript_hash2("null") == 32);
    assert(lookup_jscript_hash2("catch") == 5);
    assert(lookup_jscript_hash2("public") == 36);
    assert(lookup_jscript_hash2("true") == 47);
    assert(lookup_jscript_hash2("implements") == 23);
    assert(lookup_jscript_hash2("break") == 2);
    assert(lookup_jscript_hash2("void") == 50);
    assert(lookup_jscript_hash2("do") == 11);
    assert(lookup_jscript_hash2("for") == 19);
    assert(lookup_jscript_hash2("native") == 30);
    assert(lookup_jscript_hash2("finally") == 17);
    assert(lookup_jscript_hash2("char") == 6);
    assert(lookup_jscript_hash2("in") == 25);
    assert(lookup_jscript_hash2("final") == 16);
    assert(lookup_jscript_hash2("long") == 29);
    assert(lookup_jscript_hash2("protected") == 35);
    assert(lookup_jscript_hash2("import") == 24);
    assert(lookup_jscript_hash2("class") == 7);
    assert(lookup_jscript_hash2("interface") == 28);
    assert(lookup_jscript_hash2("int") == 27);
    assert(lookup_jscript_hash2("static") == 39);
    assert(lookup_jscript_hash2("const") == 8);
    assert(lookup_jscript_hash2("return") == 37);
    assert(lookup_jscript_hash2("boolean") == 1);
    assert(lookup_jscript_hash2("float") == 18);
    assert(lookup_jscript_hash2("byte") == 3);
    assert(lookup_jscript_hash2("continue") == 9);
    assert(lookup_jscript_hash2("try") == 48);
    assert(lookup_jscript_hash2("synchronized") == 42);
    assert(lookup_jscript_hash2("this") == 43);
    assert(lookup_jscript_hash2("short") == 38);
    assert(lookup_jscript_hash2("throws") == 45);
    assert(lookup_jscript_hash2("case") == 4);
    assert(lookup_jscript_hash2("function") == 20);
    assert(lookup_jscript_hash2("while") == 51);
    assert(lookup_jscript_hash2("package") == 33);
    assert(lookup_jscript_hash2("private") == 34);
    assert(lookup_jscript_hash2("if") == 22);
    assert(lookup_jscript_hash2("with") == 52);
    assert(lookup_jscript_hash2("new") == 31);
    assert(lookup_jscript_hash2("double") == 12);
    assert(lookup_jscript_hash2("instanceof") == 26);
    assert(lookup_jscript_hash2("throw") == 44);
    assert(lookup_jscript_hash2("default") == 10);
    assert(lookup_jscript_hash2("var") == 49);
    assert(lookup_jscript_hash2("extends") == 14);
    assert(lookup_jscript_hash2("super") == 40);
    assert(lookup_jscript_hash2("abstract") == 0);
    assert(lookup_jscript_hash2("else") == 13);
    assert(lookup_jscript_hash2("goto") == 21);
    assert(lookup_jscript_hash2("switch") == 41);
}

//lookup: name=lookup_jscript_hash3, dataset=jscript, type=hash, hash=hash3
int lookup_jscript_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 392) * 1;
    static std::string_view lookup[392] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "synchronized", // 32937 (0x80a9)
        "double", // 27450 (0x6b3a)
        "",
        "",
        "with", // 31765 (0x7c15)
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
        "finally", // 28249 (0x6e59)
        "",
        "",
        "",
        "",
        "instanceof", // 29822 (0x747e)
        "",
        "",
        "",
        "",
        "true", // 31003 (0x791b)
        "",
        "",
        "",
        "this", // 31007 (0x791f)
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
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "null", // 29477 (0x7325)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "do", // 26368 (0x6700)
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
        "interface", // 29548 (0x736c)
        "",
        "",
        "void", // 31511 (0x7b17)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "boolean", // 27220 (0x6a54)
        "",
        "try", // 30750 (0x781e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "abstract", // 27230 (0x6a5e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 27630 (0x6bee)
        "new", // 29199 (0x720f)
        "",
        "throws", // 31553 (0x7b41)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "native", // 29996 (0x752c)
        "package", // 30781 (0x783d)
        "in", // 27646 (0x6bfe)
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "false", // 27675 (0x6c1b)
        "",
        "",
        "",
        "transient", // 32383 (0x7e7f)
        "",
        "",
        "goto", // 27682 (0x6c22)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "final", // 27690 (0x6c2a)
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
        "float", // 27701 (0x6c35)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "var", // 31238 (0x7a06)
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
        "",
        "while", // 32034 (0x7d22)
        "",
        "",
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
        "",
        "",
        "function", // 28523 (0x6f6b)
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
        "throw", // 31284 (0x7a34)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "static", // 31293 (0x7a3d)
        "",
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
        "long", // 28954 (0x711a)
        "",
        "",
        "",
        "public", // 30526 (0x773e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 26634 (0x680a)
        "",
        "",
        "",
        "",
        "protected", // 31343 (0x7a6f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "char", // 26654 (0x681e)
        "",
    };
    static int values[392] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 32937 (0x80a9)
        12, // 27450 (0x6b3a)
        -1,
        -1,
        52, // 31765 (0x7c15)
        -1,
        -1,
        -1,
        -1,
        2, // 26674 (0x6832)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 28249 (0x6e59)
        -1,
        -1,
        -1,
        -1,
        26, // 29822 (0x747e)
        -1,
        -1,
        -1,
        -1,
        47, // 31003 (0x791b)
        -1,
        -1,
        -1,
        43, // 31007 (0x791f)
        -1,
        -1,
        23, // 29834 (0x748a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 31025 (0x7931)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 31033 (0x7939)
        -1,
        -1,
        40, // 31036 (0x793c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 29477 (0x7325)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 27925 (0x6d15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 26368 (0x6700)
        -1,
        -1,
        -1,
        19, // 27156 (0x6a14)
        13, // 27157 (0x6a15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 28743 (0x7047)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 26402 (0x6722)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 29548 (0x736c)
        -1,
        -1,
        50, // 31511 (0x7b17)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 28002 (0x6d62)
        -1,
        1, // 27220 (0x6a54)
        -1,
        48, // 30750 (0x781e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 27230 (0x6a5e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 27630 (0x6bee)
        31, // 29199 (0x720f)
        -1,
        45, // 31553 (0x7b41)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 29996 (0x752c)
        33, // 30781 (0x783d)
        25, // 27646 (0x6bfe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 30798 (0x784e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 27675 (0x6c1b)
        -1,
        -1,
        -1,
        46, // 32383 (0x7e7f)
        -1,
        -1,
        21, // 27682 (0x6c22)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 27690 (0x6c2a)
        -1,
        -1,
        -1,
        5, // 26910 (0x691e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 27701 (0x6c35)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 31238 (0x7a06)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 26932 (0x6934)
        -1,
        -1,
        -1,
        8, // 26936 (0x6938)
        -1,
        51, // 32034 (0x7d22)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 27728 (0x6c50)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 28523 (0x6f6b)
        9, // 27740 (0x6c5c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 31284 (0x7a34)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 31293 (0x7a3d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 31301 (0x7a45)
        -1,
        -1,
        -1,
        -1,
        29, // 28954 (0x711a)
        -1,
        -1,
        -1,
        36, // 30526 (0x773e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 26634 (0x680a)
        -1,
        -1,
        -1,
        -1,
        35, // 31343 (0x7a6f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 26654 (0x681e)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_jscript_hash3, dataset=jscript, type=hash, hash=hash3
void check_jscript_hash3() {
    assert(lookup_jscript_hash3("synchronized") == 42);
    assert(lookup_jscript_hash3("double") == 12);
    assert(lookup_jscript_hash3("with") == 52);
    assert(lookup_jscript_hash3("break") == 2);
    assert(lookup_jscript_hash3("finally") == 17);
    assert(lookup_jscript_hash3("instanceof") == 26);
    assert(lookup_jscript_hash3("true") == 47);
    assert(lookup_jscript_hash3("this") == 43);
    assert(lookup_jscript_hash3("implements") == 23);
    assert(lookup_jscript_hash3("short") == 38);
    assert(lookup_jscript_hash3("return") == 37);
    assert(lookup_jscript_hash3("super") == 40);
    assert(lookup_jscript_hash3("null") == 32);
    assert(lookup_jscript_hash3("int") == 27);
    assert(lookup_jscript_hash3("do") == 11);
    assert(lookup_jscript_hash3("for") == 19);
    assert(lookup_jscript_hash3("else") == 13);
    assert(lookup_jscript_hash3("import") == 24);
    assert(lookup_jscript_hash3("byte") == 3);
    assert(lookup_jscript_hash3("interface") == 28);
    assert(lookup_jscript_hash3("void") == 50);
    assert(lookup_jscript_hash3("extends") == 14);
    assert(lookup_jscript_hash3("boolean") == 1);
    assert(lookup_jscript_hash3("try") == 48);
    assert(lookup_jscript_hash3("abstract") == 0);
    assert(lookup_jscript_hash3("if") == 22);
    assert(lookup_jscript_hash3("new") == 31);
    assert(lookup_jscript_hash3("throws") == 45);
    assert(lookup_jscript_hash3("native") == 30);
    assert(lookup_jscript_hash3("package") == 33);
    assert(lookup_jscript_hash3("in") == 25);
    assert(lookup_jscript_hash3("private") == 34);
    assert(lookup_jscript_hash3("false") == 15);
    assert(lookup_jscript_hash3("transient") == 46);
    assert(lookup_jscript_hash3("goto") == 21);
    assert(lookup_jscript_hash3("final") == 16);
    assert(lookup_jscript_hash3("catch") == 5);
    assert(lookup_jscript_hash3("float") == 18);
    assert(lookup_jscript_hash3("var") == 49);
    assert(lookup_jscript_hash3("class") == 7);
    assert(lookup_jscript_hash3("const") == 8);
    assert(lookup_jscript_hash3("while") == 51);
    assert(lookup_jscript_hash3("default") == 10);
    assert(lookup_jscript_hash3("function") == 20);
    assert(lookup_jscript_hash3("continue") == 9);
    assert(lookup_jscript_hash3("throw") == 44);
    assert(lookup_jscript_hash3("static") == 39);
    assert(lookup_jscript_hash3("switch") == 41);
    assert(lookup_jscript_hash3("long") == 29);
    assert(lookup_jscript_hash3("public") == 36);
    assert(lookup_jscript_hash3("case") == 4);
    assert(lookup_jscript_hash3("protected") == 35);
    assert(lookup_jscript_hash3("char") == 6);
}

//lookup: name=lookup_jscript_hash_sum0, dataset=jscript, type=hash, hash=hash_sum0
int lookup_jscript_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 87) * 2;
    static std::string_view lookup[174] = {
        "final", // 522 (0x20a)
        "function", // 870 (0x366)
        "byte", // 436 (0x1b4)
        "false", // 523 (0x20b)
        "",
        "",
        "try", // 351 (0x15f)
        "",
        "",
        "",
        "this", // 440 (0x1b8)
        "",
        "goto", // 441 (0x1b9)
        "",
        "synchronized", // 1312 (0x520)
        "",
        "null", // 443 (0x1bb)
        "",
        "with", // 444 (0x1bc)
        "",
        "",
        "",
        "",
        "",
        "class", // 534 (0x216)
        "float", // 534 (0x216)
        "protected", // 970 (0x3ca)
        "true", // 448 (0x1c0)
        "",
        "",
        "while", // 537 (0x219)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "package", // 716 (0x2cc)
        "",
        "",
        "",
        "instanceof", // 1066 (0x42a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 635 (0x27b)
        "",
        "transient", // 984 (0x3d8)
        "",
        "",
        "",
        "const", // 551 (0x227)
        "",
        "public", // 639 (0x27f)
        "",
        "",
        "",
        "",
        "",
        "if", // 207 (0xcf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "do", // 211 (0xd3)
        "super", // 559 (0x22f)
        "native", // 647 (0x287)
        "short", // 560 (0x230)
        "static", // 648 (0x288)
        "",
        "boolean", // 736 (0x2e0)
        "",
        "in", // 215 (0xd7)
        "",
        "implements", // 1086 (0x43e)
        "throw", // 564 (0x234)
        "",
        "",
        "",
        "",
        "default", // 741 (0x2e5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "switch", // 658 (0x292)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "finally", // 751 (0x2ef)
        "",
        "",
        "",
        "",
        "",
        "import", // 667 (0x29b)
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
        "case", // 412 (0x19c)
        "",
        "",
        "",
        "char", // 414 (0x19e)
        "for", // 327 (0x147)
        "extends", // 763 (0x2fb)
        "private", // 763 (0x2fb)
        "var", // 329 (0x149)
        "",
        "abstract", // 852 (0x354)
        "new", // 330 (0x14a)
        "int", // 331 (0x14b)
        "throws", // 679 (0x2a7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "interface", // 945 (0x3b1)
        "",
        "",
        "",
        "else", // 425 (0x1a9)
        "",
        "",
        "",
        "",
        "",
        "catch", // 515 (0x203)
        "",
        "",
        "",
        "break", // 517 (0x205)
        "",
        "",
        "",
        "long", // 432 (0x1b0)
        "",
        "",
        "",
        "continue", // 869 (0x365)
        "void", // 434 (0x1b2)
    };
    static int values[174] = {
        16, // 522 (0x20a)
        20, // 870 (0x366)
        3, // 436 (0x1b4)
        15, // 523 (0x20b)
        -1,
        -1,
        48, // 351 (0x15f)
        -1,
        -1,
        -1,
        43, // 440 (0x1b8)
        -1,
        21, // 441 (0x1b9)
        -1,
        42, // 1312 (0x520)
        -1,
        32, // 443 (0x1bb)
        -1,
        52, // 444 (0x1bc)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 534 (0x216)
        18, // 534 (0x216)
        35, // 970 (0x3ca)
        47, // 448 (0x1c0)
        -1,
        -1,
        51, // 537 (0x219)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 716 (0x2cc)
        -1,
        -1,
        -1,
        26, // 1066 (0x42a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 635 (0x27b)
        -1,
        46, // 984 (0x3d8)
        -1,
        -1,
        -1,
        8, // 551 (0x227)
        -1,
        36, // 639 (0x27f)
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 207 (0xcf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 211 (0xd3)
        40, // 559 (0x22f)
        30, // 647 (0x287)
        38, // 560 (0x230)
        39, // 648 (0x288)
        -1,
        1, // 736 (0x2e0)
        -1,
        25, // 215 (0xd7)
        -1,
        23, // 1086 (0x43e)
        44, // 564 (0x234)
        -1,
        -1,
        -1,
        -1,
        10, // 741 (0x2e5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 658 (0x292)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 751 (0x2ef)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 667 (0x29b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 672 (0x2a0)
        -1,
        4, // 412 (0x19c)
        -1,
        -1,
        -1,
        6, // 414 (0x19e)
        19, // 327 (0x147)
        14, // 763 (0x2fb)
        34, // 763 (0x2fb)
        49, // 329 (0x149)
        -1,
        0, // 852 (0x354)
        31, // 330 (0x14a)
        27, // 331 (0x14b)
        45, // 679 (0x2a7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 945 (0x3b1)
        -1,
        -1,
        -1,
        13, // 425 (0x1a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 515 (0x203)
        -1,
        -1,
        -1,
        2, // 517 (0x205)
        -1,
        -1,
        -1,
        29, // 432 (0x1b0)
        -1,
        -1,
        -1,
        9, // 869 (0x365)
        50, // 434 (0x1b2)
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_jscript_hash_sum0, dataset=jscript, type=hash, hash=hash_sum0
void check_jscript_hash_sum0() {
    assert(lookup_jscript_hash_sum0("final") == 16);
    assert(lookup_jscript_hash_sum0("function") == 20);
    assert(lookup_jscript_hash_sum0("byte") == 3);
    assert(lookup_jscript_hash_sum0("false") == 15);
    assert(lookup_jscript_hash_sum0("try") == 48);
    assert(lookup_jscript_hash_sum0("this") == 43);
    assert(lookup_jscript_hash_sum0("goto") == 21);
    assert(lookup_jscript_hash_sum0("synchronized") == 42);
    assert(lookup_jscript_hash_sum0("null") == 32);
    assert(lookup_jscript_hash_sum0("with") == 52);
    assert(lookup_jscript_hash_sum0("class") == 7);
    assert(lookup_jscript_hash_sum0("float") == 18);
    assert(lookup_jscript_hash_sum0("protected") == 35);
    assert(lookup_jscript_hash_sum0("true") == 47);
    assert(lookup_jscript_hash_sum0("while") == 51);
    assert(lookup_jscript_hash_sum0("package") == 33);
    assert(lookup_jscript_hash_sum0("instanceof") == 26);
    assert(lookup_jscript_hash_sum0("double") == 12);
    assert(lookup_jscript_hash_sum0("transient") == 46);
    assert(lookup_jscript_hash_sum0("const") == 8);
    assert(lookup_jscript_hash_sum0("public") == 36);
    assert(lookup_jscript_hash_sum0("if") == 22);
    assert(lookup_jscript_hash_sum0("do") == 11);
    assert(lookup_jscript_hash_sum0("super") == 40);
    assert(lookup_jscript_hash_sum0("native") == 30);
    assert(lookup_jscript_hash_sum0("short") == 38);
    assert(lookup_jscript_hash_sum0("static") == 39);
    assert(lookup_jscript_hash_sum0("boolean") == 1);
    assert(lookup_jscript_hash_sum0("in") == 25);
    assert(lookup_jscript_hash_sum0("implements") == 23);
    assert(lookup_jscript_hash_sum0("throw") == 44);
    assert(lookup_jscript_hash_sum0("default") == 10);
    assert(lookup_jscript_hash_sum0("switch") == 41);
    assert(lookup_jscript_hash_sum0("finally") == 17);
    assert(lookup_jscript_hash_sum0("import") == 24);
    assert(lookup_jscript_hash_sum0("return") == 37);
    assert(lookup_jscript_hash_sum0("case") == 4);
    assert(lookup_jscript_hash_sum0("char") == 6);
    assert(lookup_jscript_hash_sum0("for") == 19);
    assert(lookup_jscript_hash_sum0("extends") == 14);
    assert(lookup_jscript_hash_sum0("private") == 34);
    assert(lookup_jscript_hash_sum0("var") == 49);
    assert(lookup_jscript_hash_sum0("abstract") == 0);
    assert(lookup_jscript_hash_sum0("new") == 31);
    assert(lookup_jscript_hash_sum0("int") == 27);
    assert(lookup_jscript_hash_sum0("throws") == 45);
    assert(lookup_jscript_hash_sum0("interface") == 28);
    assert(lookup_jscript_hash_sum0("else") == 13);
    assert(lookup_jscript_hash_sum0("catch") == 5);
    assert(lookup_jscript_hash_sum0("break") == 2);
    assert(lookup_jscript_hash_sum0("long") == 29);
    assert(lookup_jscript_hash_sum0("continue") == 9);
    assert(lookup_jscript_hash_sum0("void") == 50);
}

//lookup: name=lookup_jscript_hash_sumN, dataset=jscript, type=hash, hash=hash_sumN
int lookup_jscript_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 70) * 2;
    static std::string_view lookup[140] = {
        "extends", // 770 (0x302)
        "private", // 770 (0x302)
        "",
        "",
        "",
        "",
        "do", // 213 (0xd5)
        "",
        "super", // 564 (0x234)
        "try", // 354 (0x162)
        "short", // 565 (0x235)
        "",
        "",
        "",
        "in", // 217 (0xd9)
        "",
        "",
        "",
        "else", // 429 (0x1ad)
        "throw", // 569 (0x239)
        "",
        "",
        "double", // 641 (0x281)
        "",
        "",
        "",
        "transient", // 993 (0x3e1)
        "",
        "",
        "",
        "public", // 645 (0x285)
        "",
        "long", // 436 (0x1b4)
        "",
        "",
        "",
        "void", // 438 (0x1b6)
        "",
        "",
        "",
        "abstract", // 860 (0x35c)
        "byte", // 440 (0x1b8)
        "",
        "",
        "",
        "",
        "native", // 653 (0x28d)
        "package", // 723 (0x2d3)
        "static", // 654 (0x28e)
        "this", // 444 (0x1bc)
        "goto", // 445 (0x1bd)
        "",
        "instanceof", // 1076 (0x434)
        "",
        "null", // 447 (0x1bf)
        "",
        "with", // 448 (0x1c0)
        "",
        "",
        "",
        "catch", // 520 (0x208)
        "",
        "",
        "",
        "break", // 522 (0x20a)
        "true", // 452 (0x1c4)
        "",
        "",
        "switch", // 664 (0x298)
        "",
        "",
        "",
        "",
        "",
        "continue", // 877 (0x36d)
        "final", // 527 (0x20f)
        "false", // 528 (0x210)
        "function", // 878 (0x36e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "boolean", // 743 (0x2e7)
        "import", // 673 (0x2a1)
        "interface", // 954 (0x3ba)
        "",
        "",
        "",
        "implements", // 1096 (0x448)
        "",
        "",
        "",
        "default", // 748 (0x2ec)
        "return", // 678 (0x2a6)
        "class", // 539 (0x21b)
        "float", // 539 (0x21b)
        "for", // 330 (0x14a)
        "",
        "",
        "",
        "var", // 332 (0x14c)
        "while", // 542 (0x21e)
        "new", // 333 (0x14d)
        "",
        "int", // 334 (0x14e)
        "",
        "throws", // 685 (0x2ad)
        "",
        "",
        "",
        "",
        "",
        "finally", // 758 (0x2f6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "synchronized", // 1324 (0x52c)
        "",
        "",
        "",
        "case", // 416 (0x1a0)
        "const", // 556 (0x22c)
        "",
        "",
        "char", // 418 (0x1a2)
        "",
        "if", // 209 (0xd1)
        "protected", // 979 (0x3d3)
    };
    static int values[140] = {
        14, // 770 (0x302)
        34, // 770 (0x302)
        -1,
        -1,
        -1,
        -1,
        11, // 213 (0xd5)
        -1,
        40, // 564 (0x234)
        48, // 354 (0x162)
        38, // 565 (0x235)
        -1,
        -1,
        -1,
        25, // 217 (0xd9)
        -1,
        -1,
        -1,
        13, // 429 (0x1ad)
        44, // 569 (0x239)
        -1,
        -1,
        12, // 641 (0x281)
        -1,
        -1,
        -1,
        46, // 993 (0x3e1)
        -1,
        -1,
        -1,
        36, // 645 (0x285)
        -1,
        29, // 436 (0x1b4)
        -1,
        -1,
        -1,
        50, // 438 (0x1b6)
        -1,
        -1,
        -1,
        0, // 860 (0x35c)
        3, // 440 (0x1b8)
        -1,
        -1,
        -1,
        -1,
        30, // 653 (0x28d)
        33, // 723 (0x2d3)
        39, // 654 (0x28e)
        43, // 444 (0x1bc)
        21, // 445 (0x1bd)
        -1,
        26, // 1076 (0x434)
        -1,
        32, // 447 (0x1bf)
        -1,
        52, // 448 (0x1c0)
        -1,
        -1,
        -1,
        5, // 520 (0x208)
        -1,
        -1,
        -1,
        2, // 522 (0x20a)
        47, // 452 (0x1c4)
        -1,
        -1,
        41, // 664 (0x298)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 877 (0x36d)
        16, // 527 (0x20f)
        15, // 528 (0x210)
        20, // 878 (0x36e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 743 (0x2e7)
        24, // 673 (0x2a1)
        28, // 954 (0x3ba)
        -1,
        -1,
        -1,
        23, // 1096 (0x448)
        -1,
        -1,
        -1,
        10, // 748 (0x2ec)
        37, // 678 (0x2a6)
        7, // 539 (0x21b)
        18, // 539 (0x21b)
        19, // 330 (0x14a)
        -1,
        -1,
        -1,
        49, // 332 (0x14c)
        51, // 542 (0x21e)
        31, // 333 (0x14d)
        -1,
        27, // 334 (0x14e)
        -1,
        45, // 685 (0x2ad)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 758 (0x2f6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 1324 (0x52c)
        -1,
        -1,
        -1,
        4, // 416 (0x1a0)
        8, // 556 (0x22c)
        -1,
        -1,
        6, // 418 (0x1a2)
        -1,
        22, // 209 (0xd1)
        35, // 979 (0x3d3)
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_jscript_hash_sumN, dataset=jscript, type=hash, hash=hash_sumN
void check_jscript_hash_sumN() {
    assert(lookup_jscript_hash_sumN("extends") == 14);
    assert(lookup_jscript_hash_sumN("private") == 34);
    assert(lookup_jscript_hash_sumN("do") == 11);
    assert(lookup_jscript_hash_sumN("super") == 40);
    assert(lookup_jscript_hash_sumN("try") == 48);
    assert(lookup_jscript_hash_sumN("short") == 38);
    assert(lookup_jscript_hash_sumN("in") == 25);
    assert(lookup_jscript_hash_sumN("else") == 13);
    assert(lookup_jscript_hash_sumN("throw") == 44);
    assert(lookup_jscript_hash_sumN("double") == 12);
    assert(lookup_jscript_hash_sumN("transient") == 46);
    assert(lookup_jscript_hash_sumN("public") == 36);
    assert(lookup_jscript_hash_sumN("long") == 29);
    assert(lookup_jscript_hash_sumN("void") == 50);
    assert(lookup_jscript_hash_sumN("abstract") == 0);
    assert(lookup_jscript_hash_sumN("byte") == 3);
    assert(lookup_jscript_hash_sumN("native") == 30);
    assert(lookup_jscript_hash_sumN("package") == 33);
    assert(lookup_jscript_hash_sumN("static") == 39);
    assert(lookup_jscript_hash_sumN("this") == 43);
    assert(lookup_jscript_hash_sumN("goto") == 21);
    assert(lookup_jscript_hash_sumN("instanceof") == 26);
    assert(lookup_jscript_hash_sumN("null") == 32);
    assert(lookup_jscript_hash_sumN("with") == 52);
    assert(lookup_jscript_hash_sumN("catch") == 5);
    assert(lookup_jscript_hash_sumN("break") == 2);
    assert(lookup_jscript_hash_sumN("true") == 47);
    assert(lookup_jscript_hash_sumN("switch") == 41);
    assert(lookup_jscript_hash_sumN("continue") == 9);
    assert(lookup_jscript_hash_sumN("final") == 16);
    assert(lookup_jscript_hash_sumN("false") == 15);
    assert(lookup_jscript_hash_sumN("function") == 20);
    assert(lookup_jscript_hash_sumN("boolean") == 1);
    assert(lookup_jscript_hash_sumN("import") == 24);
    assert(lookup_jscript_hash_sumN("interface") == 28);
    assert(lookup_jscript_hash_sumN("implements") == 23);
    assert(lookup_jscript_hash_sumN("default") == 10);
    assert(lookup_jscript_hash_sumN("return") == 37);
    assert(lookup_jscript_hash_sumN("class") == 7);
    assert(lookup_jscript_hash_sumN("float") == 18);
    assert(lookup_jscript_hash_sumN("for") == 19);
    assert(lookup_jscript_hash_sumN("var") == 49);
    assert(lookup_jscript_hash_sumN("while") == 51);
    assert(lookup_jscript_hash_sumN("new") == 31);
    assert(lookup_jscript_hash_sumN("int") == 27);
    assert(lookup_jscript_hash_sumN("throws") == 45);
    assert(lookup_jscript_hash_sumN("finally") == 17);
    assert(lookup_jscript_hash_sumN("synchronized") == 42);
    assert(lookup_jscript_hash_sumN("case") == 4);
    assert(lookup_jscript_hash_sumN("const") == 8);
    assert(lookup_jscript_hash_sumN("char") == 6);
    assert(lookup_jscript_hash_sumN("if") == 22);
    assert(lookup_jscript_hash_sumN("protected") == 35);
}

//lookup: name=lookup_jscript_hash_djb2, dataset=jscript, type=hash, hash=hash_djb2
int lookup_jscript_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 310) * 1;
    static std::string_view lookup[310] = {
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
        "true", // 6504329801 (0x183b03249)
        "",
        "short", // 214641332153 (0x31f99ecfb9)
        "",
        "",
        "",
        "",
        "native", // 7082960152688 (0x6712152e870)
        "",
        "",
        "void", // 6504398011 (0x183b13cbb)
        "",
        "",
        "",
        "char", // 6503707335 (0x183a6b2c7)
        "null", // 6504117156 (0x183acf3a4)
        "",
        "",
        "",
        "",
        "with", // 6504427781 (0x183b1b105)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "instanceof", // 8399617383906139251 (0x74916f81f0ebdc73)
        "",
        "",
        "",
        "",
        "finally", // 233727658964536 (0xd492f6163638)
        "",
        "",
        "",
        "",
        "",
        "super", // 214641799992 (0x31f9a5f338)
        "",
        "",
        "",
        "",
        "static", // 7083177690897 (0x6712e4a4711)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "int", // 197088788 (0xbbf5614)
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
        "",
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
        "case", // 6503700293 (0x183a69745)
        "try", // 197100904 (0xbbf8568)
        "",
        "",
        "",
        "",
        "",
        "goto", // 6503859330 (0x183a90482)
        "",
        "",
        "",
        "",
        "",
        "",
        "synchronized", // 16567027359139331977 (0xe5e9e79b75ad7f89)
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "transient", // 254549477626873985 (0x3885766b7b60881)
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
        "boolean", // 233722729478249 (0xd491d0443869)
        "throws", // 7083203201200 (0x6712fcf88b0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "implements", // 8399615839465885831 (0x74916e1a591bd087)
        "",
        "",
        "var", // 197102514 (0xbbf8bb2)
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
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "switch", // 7083181535963 (0x6712e84f2db)
        "import", // 7082778569444 (0x67116802ae4)
        "",
        "catch", // 214622110796 (0x31f879844c)
        "",
        "",
        "this", // 6504318529 (0x183b00641)
        "",
        "protected", // 254543870290962451 (0x388524d28722813)
        "",
        "",
        "extends", // 233726961788644 (0xd492cc8826e4)
        "",
        "",
        "function", // 7713028246101167 (0x1b66f554c05caf)
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
        "",
        "",
        "",
        "in", // 5972384 (0x5b21a0)
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
        "",
        "class", // 214622485951 (0x31f87f3dbf)
        "for", // 197085552 (0xbbf4970)
        "",
        "",
        "byte", // 6503690525 (0x183a6711d)
        "else", // 6503784146 (0x183a7ded2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "continue", // 7712892661735406 (0x1b66d5c34b1fee)
        "abstract", // 7712790831751517 (0x1b66be0dc0e15d)
        "",
        "new", // 197093939 (0xbbf6a33)
        "private", // 233740920676100 (0xd4960c8bdf04)
        "",
        "false", // 214625660372 (0x31f8afadd4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "public", // 7083061497864 (0x671275d5008)
        "",
        "",
        "",
        "",
        "",
    };
    static int values[310] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 7082585429636 (0x6710afd1684)
        -1,
        -1,
        -1,
        -1,
        47, // 6504329801 (0x183b03249)
        -1,
        38, // 214641332153 (0x31f99ecfb9)
        -1,
        -1,
        -1,
        -1,
        30, // 7082960152688 (0x6712152e870)
        -1,
        -1,
        50, // 6504398011 (0x183b13cbb)
        -1,
        -1,
        -1,
        6, // 6503707335 (0x183a6b2c7)
        32, // 6504117156 (0x183acf3a4)
        -1,
        -1,
        -1,
        -1,
        52, // 6504427781 (0x183b1b105)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 233724910009454 (0xd492523c7c6e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 8399617383906139251 (0x74916f81f0ebdc73)
        -1,
        -1,
        -1,
        -1,
        17, // 233727658964536 (0xd492f6163638)
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 214641799992 (0x31f9a5f338)
        -1,
        -1,
        -1,
        -1,
        39, // 7083177690897 (0x6712e4a4711)
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
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 197088788 (0xbbf5614)
        -1,
        8, // 214622607920 (0x31f8811a30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 6504038809 (0x183abc199)
        -1,
        -1,
        -1,
        4, // 6503700293 (0x183a69745)
        48, // 197100904 (0xbbf8568)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 6503859330 (0x183a90482)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 16567027359139331977 (0xe5e9e79b75ad7f89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 214625949459 (0x31f8b41713)
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 254549477626873985 (0x3885766b7b60881)
        -1,
        -1,
        -1,
        -1,
        51, // 214646069090 (0x31f9e71762)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 233722729478249 (0xd491d0443869)
        45, // 7083203201200 (0x6712fcf88b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 8399615839465885831 (0x74916e1a591bd087)
        -1,
        -1,
        49, // 197102514 (0xbbf8bb2)
        -1,
        -1,
        33, // 233740247863157 (0xd495e4718f75)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 254533860842675834 (0x3884932a6d61e7a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 7083181535963 (0x6712e84f2db)
        24, // 7082778569444 (0x67116802ae4)
        -1,
        5, // 214622110796 (0x31f879844c)
        -1,
        -1,
        43, // 6504318529 (0x183b00641)
        -1,
        35, // 254543870290962451 (0x388524d28722813)
        -1,
        -1,
        14, // 233726961788644 (0xd492cc8826e4)
        -1,
        -1,
        20, // 7713028246101167 (0x1b66f554c05caf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 5972376 (0x5b2198)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 5972384 (0x5b21a0)
        -1,
        -1,
        18, // 214626058367 (0x31f8b5c07f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 214642521245 (0x31f9b0f49d)
        -1,
        -1,
        -1,
        37, // 7083121450889 (0x6712af01f89)
        -1,
        7, // 214622485951 (0x31f87f3dbf)
        19, // 197085552 (0xbbf4970)
        -1,
        -1,
        3, // 6503690525 (0x183a6711d)
        13, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 7712892661735406 (0x1b66d5c34b1fee)
        0, // 7712790831751517 (0x1b66be0dc0e15d)
        -1,
        31, // 197093939 (0xbbf6a33)
        34, // 233740920676100 (0xd4960c8bdf04)
        -1,
        15, // 214625660372 (0x31f8afadd4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
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
        -1,
        -1,
        36, // 7083061497864 (0x671275d5008)
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

//check: name=check_jscript_hash_djb2, dataset=jscript, type=hash, hash=hash_djb2
void check_jscript_hash_djb2() {
    assert(lookup_jscript_hash_djb2("double") == 12);
    assert(lookup_jscript_hash_djb2("true") == 47);
    assert(lookup_jscript_hash_djb2("short") == 38);
    assert(lookup_jscript_hash_djb2("native") == 30);
    assert(lookup_jscript_hash_djb2("void") == 50);
    assert(lookup_jscript_hash_djb2("char") == 6);
    assert(lookup_jscript_hash_djb2("null") == 32);
    assert(lookup_jscript_hash_djb2("with") == 52);
    assert(lookup_jscript_hash_djb2("default") == 10);
    assert(lookup_jscript_hash_djb2("instanceof") == 26);
    assert(lookup_jscript_hash_djb2("finally") == 17);
    assert(lookup_jscript_hash_djb2("super") == 40);
    assert(lookup_jscript_hash_djb2("static") == 39);
    assert(lookup_jscript_hash_djb2("do") == 11);
    assert(lookup_jscript_hash_djb2("int") == 27);
    assert(lookup_jscript_hash_djb2("const") == 8);
    assert(lookup_jscript_hash_djb2("long") == 29);
    assert(lookup_jscript_hash_djb2("case") == 4);
    assert(lookup_jscript_hash_djb2("try") == 48);
    assert(lookup_jscript_hash_djb2("goto") == 21);
    assert(lookup_jscript_hash_djb2("synchronized") == 42);
    assert(lookup_jscript_hash_djb2("final") == 16);
    assert(lookup_jscript_hash_djb2("transient") == 46);
    assert(lookup_jscript_hash_djb2("while") == 51);
    assert(lookup_jscript_hash_djb2("boolean") == 1);
    assert(lookup_jscript_hash_djb2("throws") == 45);
    assert(lookup_jscript_hash_djb2("implements") == 23);
    assert(lookup_jscript_hash_djb2("var") == 49);
    assert(lookup_jscript_hash_djb2("package") == 33);
    assert(lookup_jscript_hash_djb2("interface") == 28);
    assert(lookup_jscript_hash_djb2("switch") == 41);
    assert(lookup_jscript_hash_djb2("import") == 24);
    assert(lookup_jscript_hash_djb2("catch") == 5);
    assert(lookup_jscript_hash_djb2("this") == 43);
    assert(lookup_jscript_hash_djb2("protected") == 35);
    assert(lookup_jscript_hash_djb2("extends") == 14);
    assert(lookup_jscript_hash_djb2("function") == 20);
    assert(lookup_jscript_hash_djb2("if") == 22);
    assert(lookup_jscript_hash_djb2("in") == 25);
    assert(lookup_jscript_hash_djb2("float") == 18);
    assert(lookup_jscript_hash_djb2("throw") == 44);
    assert(lookup_jscript_hash_djb2("return") == 37);
    assert(lookup_jscript_hash_djb2("class") == 7);
    assert(lookup_jscript_hash_djb2("for") == 19);
    assert(lookup_jscript_hash_djb2("byte") == 3);
    assert(lookup_jscript_hash_djb2("else") == 13);
    assert(lookup_jscript_hash_djb2("continue") == 9);
    assert(lookup_jscript_hash_djb2("abstract") == 0);
    assert(lookup_jscript_hash_djb2("new") == 31);
    assert(lookup_jscript_hash_djb2("private") == 34);
    assert(lookup_jscript_hash_djb2("false") == 15);
    assert(lookup_jscript_hash_djb2("break") == 2);
    assert(lookup_jscript_hash_djb2("public") == 36);
}

//lookup: name=lookup_jscript_hash_sdb, dataset=jscript, type=hash, hash=hash_sdb
int lookup_jscript_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 390) * 1;
    static std::string_view lookup[390] = {
        "",
        "",
        "",
        "",
        "",
        "extends", // 365770552778081885 (0x5137a613ba2c65d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "new", // 472496276868 (0x6e02f90584)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 438134048085 (0x6602d30555)
        "",
        "",
        "",
        "",
        "",
        "",
        "abstract", // 3406116446903072422 (0x2f44f4dcb145f6a6)
        "else", // 28433340858241073 (0x6503f90da21031)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "do", // 6554011 (0x64019b)
        "",
        "goto", // 28996381010759823 (0x67040e0deb108f)
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "package", // 1399373631390272162 (0x136b92e74f10caa2)
        "try", // 498269292003 (0x74032a05e3)
        "",
        "var", // 506858898875 (0x76032505bb)
        "final", // 374108432876187846 (0x53119a3391030c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "function", // 10100634927348600308 (0x8c2ca9f372844df4)
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
        "if", // 6881697 (0x6901a1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "in", // 6881705 (0x6901a9)
        "",
        "",
        "void", // 33219085507826168 (0x7604950f7511f8)
        "",
        "",
        "",
        "char", // 27870296409247662 (0x6303e30d420fae)
        "",
        "",
        "",
        "",
        "null", // 30967002214699367 (0x6e04530ec41167)
        "",
        "",
        "",
        "import", // 3059784849221326761 (0x2a768a1be2f597a9)
        "",
        "",
        "",
        "",
        "",
        "",
        "byte", // 27588855798435928 (0x6203eb0da01058)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "interface", // 12514925068772314305 (0xadadf20b0ace0cc1)
        "transient", // 18292036757232426046 (0xfdda5e83ed3a1c3e)
        "native", // 3147045235970447567 (0x2bac8cf7e61a98cf)
        "synchronized", // 3330564478679133348 (0x2e388abf4d342ca4)
        "while", // 431251735916197369 (0x5fc1d2b400e35f9)
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
        "",
        "",
        "",
        "false", // 371856315221159947 (0x5291959383e300b)
        "",
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
        "",
        "",
        "",
        "true", // 32656071128322562 (0x7404860f5d1202)
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "throw", // 421117979607119218 (0x5d81c923f033572)
        "",
        "",
        "",
        "",
        "",
        "return", // 3261892644424556104 (0x2d449213ee629e48)
        "",
        "",
        "",
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
        "case", // 27870266342903704 (0x6303dc0d2a0f98)
        "public", // 3260204451718471445 (0x2d3e92acefd39f15)
        "long", // 30403949176295676 (0x6c043b0e6c10fc)
        "",
        "this", // 32656028173930898 (0x74047c0f151192)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "int", // 451020064111 (0x6902e4056f)
        "",
        "super", // 421399716591318603 (0x5d91ccf3fe0364b)
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
        "",
        "",
        "",
        "",
        "protected", // 5201487412384685718 (0x482f653e2edade96)
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
        "private", // 1853414300009618939 (0x19b8a67c6db3ddfb)
        "",
        "",
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
        "float", // 374952978071105832 (0x53419bf39673128)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "boolean", // 18113585239123538960 (0xfb6061ce1ab7b410)
        "throws", // 3322131201497211081 (0x2e1a94b9f27ba0c9)
        "",
        "",
        "with", // 33500573369569794 (0x7704980f771202)
        "",
        "",
        "",
        "",
        "",
    };
    static int values[390] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 365770552778081885 (0x5137a613ba2c65d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 472496276868 (0x6e02f90584)
        -1,
        -1,
        10, // 18130751609074855161 (0xfb9d5e8711bfacf9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 438134048085 (0x6602d30555)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 3406116446903072422 (0x2f44f4dcb145f6a6)
        13, // 28433340858241073 (0x6503f90da21031)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 6554011 (0x64019b)
        -1,
        21, // 28996381010759823 (0x67040e0deb108f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 11829362627980883380 (0xa42a56a2b014f5b4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 1399373631390272162 (0x136b92e74f10caa2)
        48, // 498269292003 (0x74032a05e3)
        -1,
        49, // 506858898875 (0x76032505bb)
        16, // 374108432876187846 (0x53119a3391030c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 365663719708962995 (0x5131937388030b3)
        -1,
        -1,
        20, // 10100634927348600308 (0x8c2ca9f372844df4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 3344932667539956616 (0x2e6b9689f651a388)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 6881697 (0x6901a1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 6881705 (0x6901a9)
        -1,
        -1,
        50, // 33219085507826168 (0x7604950f7511f8)
        -1,
        -1,
        -1,
        6, // 27870296409247662 (0x6303e30d420fae)
        -1,
        -1,
        -1,
        -1,
        32, // 30967002214699367 (0x6e04530ec41167)
        -1,
        -1,
        -1,
        24, // 3059784849221326761 (0x2a768a1be2f597a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 27588855798435928 (0x6203eb0da01058)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 12514925068772314305 (0xadadf20b0ace0cc1)
        46, // 18292036757232426046 (0xfdda5e83ed3a1c3e)
        30, // 3147045235970447567 (0x2bac8cf7e61a98cf)
        42, // 3330564478679133348 (0x2e388abf4d342ca4)
        51, // 431251735916197369 (0x5fc1d2b400e35f9)
        -1,
        -1,
        -1,
        -1,
        7, // 364819122969718764 (0x510190f37e12fec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 371856315221159947 (0x5291959383e300b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 3332546763507343818 (0x2e3f959ff43ba1ca)
        -1,
        -1,
        -1,
        47, // 32656071128322562 (0x7404860f5d1202)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 116369992049604787 (0x19d6de426a1b8b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 421117979607119218 (0x5d81c923f033572)
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 3261892644424556104 (0x2d449213ee629e48)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 363130290293256227 (0x50a1913381d3023)
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
        4, // 27870266342903704 (0x6303dc0d2a0f98)
        36, // 3260204451718471445 (0x2d3e92acefd39f15)
        29, // 30403949176295676 (0x6c043b0e6c10fc)
        -1,
        43, // 32656028173930898 (0x74047c0f151192)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 361722554615476019 (0x50518bf371a2f33)
        -1,
        27, // 451020064111 (0x6902e4056f)
        -1,
        40, // 421399716591318603 (0x5d91ccf3fe0364b)
        26, // 724521019631549344 (0xa0e040757713ba0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 5201487412384685718 (0x482f653e2edade96)
        -1,
        -1,
        -1,
        -1,
        9, // 6848942472000841643 (0x5f0c54e41ab227ab)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 1853414300009618939 (0x19b8a67c6db3ddfb)
        -1,
        -1,
        -1,
        -1,
        38, // 417740035065394444 (0x5cc1c593e88350c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 374952978071105832 (0x53419bf39673128)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 18113585239123538960 (0xfb6061ce1ab7b410)
        45, // 3322131201497211081 (0x2e1a94b9f27ba0c9)
        -1,
        -1,
        52, // 33500573369569794 (0x7704980f771202)
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

//check: name=check_jscript_hash_sdb, dataset=jscript, type=hash, hash=hash_sdb
void check_jscript_hash_sdb() {
    assert(lookup_jscript_hash_sdb("extends") == 14);
    assert(lookup_jscript_hash_sdb("new") == 31);
    assert(lookup_jscript_hash_sdb("default") == 10);
    assert(lookup_jscript_hash_sdb("for") == 19);
    assert(lookup_jscript_hash_sdb("abstract") == 0);
    assert(lookup_jscript_hash_sdb("else") == 13);
    assert(lookup_jscript_hash_sdb("do") == 11);
    assert(lookup_jscript_hash_sdb("goto") == 21);
    assert(lookup_jscript_hash_sdb("implements") == 23);
    assert(lookup_jscript_hash_sdb("package") == 33);
    assert(lookup_jscript_hash_sdb("try") == 48);
    assert(lookup_jscript_hash_sdb("var") == 49);
    assert(lookup_jscript_hash_sdb("final") == 16);
    assert(lookup_jscript_hash_sdb("const") == 8);
    assert(lookup_jscript_hash_sdb("function") == 20);
    assert(lookup_jscript_hash_sdb("switch") == 41);
    assert(lookup_jscript_hash_sdb("if") == 22);
    assert(lookup_jscript_hash_sdb("in") == 25);
    assert(lookup_jscript_hash_sdb("void") == 50);
    assert(lookup_jscript_hash_sdb("char") == 6);
    assert(lookup_jscript_hash_sdb("null") == 32);
    assert(lookup_jscript_hash_sdb("import") == 24);
    assert(lookup_jscript_hash_sdb("byte") == 3);
    assert(lookup_jscript_hash_sdb("interface") == 28);
    assert(lookup_jscript_hash_sdb("transient") == 46);
    assert(lookup_jscript_hash_sdb("native") == 30);
    assert(lookup_jscript_hash_sdb("synchronized") == 42);
    assert(lookup_jscript_hash_sdb("while") == 51);
    assert(lookup_jscript_hash_sdb("class") == 7);
    assert(lookup_jscript_hash_sdb("false") == 15);
    assert(lookup_jscript_hash_sdb("static") == 39);
    assert(lookup_jscript_hash_sdb("true") == 47);
    assert(lookup_jscript_hash_sdb("finally") == 17);
    assert(lookup_jscript_hash_sdb("throw") == 44);
    assert(lookup_jscript_hash_sdb("return") == 37);
    assert(lookup_jscript_hash_sdb("break") == 2);
    assert(lookup_jscript_hash_sdb("double") == 12);
    assert(lookup_jscript_hash_sdb("case") == 4);
    assert(lookup_jscript_hash_sdb("public") == 36);
    assert(lookup_jscript_hash_sdb("long") == 29);
    assert(lookup_jscript_hash_sdb("this") == 43);
    assert(lookup_jscript_hash_sdb("catch") == 5);
    assert(lookup_jscript_hash_sdb("int") == 27);
    assert(lookup_jscript_hash_sdb("super") == 40);
    assert(lookup_jscript_hash_sdb("instanceof") == 26);
    assert(lookup_jscript_hash_sdb("protected") == 35);
    assert(lookup_jscript_hash_sdb("continue") == 9);
    assert(lookup_jscript_hash_sdb("private") == 34);
    assert(lookup_jscript_hash_sdb("short") == 38);
    assert(lookup_jscript_hash_sdb("float") == 18);
    assert(lookup_jscript_hash_sdb("boolean") == 1);
    assert(lookup_jscript_hash_sdb("throws") == 45);
    assert(lookup_jscript_hash_sdb("with") == 52);
}
