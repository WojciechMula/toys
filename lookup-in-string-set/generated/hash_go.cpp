
//lookup: name=lookup_go_hash1, dataset=go, type=hash, hash=hash1
int lookup_go_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 38) * 2;
    constexpr const std::string_view lookup[76] = {
        "chan", // 836 (0x344)
        "",
        "",
        "",
        "case", // 800 (0x320)
        "for", // 648 (0x288)
        "",
        "",
        "continue", // 1600 (0x640)
        "",
        "",
        "",
        "defer", // 1070 (0x42e)
        "func", // 804 (0x324)
        "",
        "",
        "",
        "",
        "package", // 1491 (0x5d3)
        "",
        "else", // 808 (0x328)
        "go", // 428 (0x1ac)
        "const", // 1075 (0x433)
        "range", // 1075 (0x433)
        "var", // 696 (0x2b8)
        "",
        "",
        "",
        "return", // 1344 (0x540)
        "",
        "",
        "",
        "",
        "",
        "map", // 663 (0x297)
        "",
        "select", // 1386 (0x56a)
        "struct", // 1386 (0x56a)
        "",
        "",
        "goto", // 856 (0x358)
        "",
        "",
        "",
        "switch", // 1314 (0x522)
        "",
        "",
        "",
        "fallthrough", // 2266 (0x8da)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "default", // 1512 (0x5e8)
        "interface", // 1854 (0x73e)
        "",
        "",
        "type", // 868 (0x364)
        "",
        "",
        "",
        "if", // 414 (0x19e)
        "import", // 1326 (0x52e)
        "",
        "",
        "",
        "",
        "break", // 1025 (0x401)
        "",
    };
    constexpr const int values[76] = {
        2, // 836 (0x344)
        -1,
        -1,
        -1,
        1, // 800 (0x320)
        9, // 648 (0x288)
        -1,
        -1,
        4, // 1600 (0x640)
        -1,
        -1,
        -1,
        6, // 1070 (0x42e)
        10, // 804 (0x324)
        -1,
        -1,
        -1,
        -1,
        17, // 1491 (0x5d3)
        -1,
        7, // 808 (0x328)
        11, // 428 (0x1ac)
        3, // 1075 (0x433)
        18, // 1075 (0x433)
        24, // 696 (0x2b8)
        -1,
        -1,
        -1,
        19, // 1344 (0x540)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 663 (0x297)
        -1,
        20, // 1386 (0x56a)
        21, // 1386 (0x56a)
        -1,
        -1,
        12, // 856 (0x358)
        -1,
        -1,
        -1,
        22, // 1314 (0x522)
        -1,
        -1,
        -1,
        8, // 2266 (0x8da)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 1512 (0x5e8)
        15, // 1854 (0x73e)
        -1,
        -1,
        23, // 868 (0x364)
        -1,
        -1,
        -1,
        13, // 414 (0x19e)
        14, // 1326 (0x52e)
        -1,
        -1,
        -1,
        -1,
        0, // 1025 (0x401)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_go_hash1, dataset=go, type=hash, hash=hash1
void check_go_hash1() {
    assert(lookup_go_hash1("chan") == 2);
    assert(lookup_go_hash1("case") == 1);
    assert(lookup_go_hash1("for") == 9);
    assert(lookup_go_hash1("continue") == 4);
    assert(lookup_go_hash1("defer") == 6);
    assert(lookup_go_hash1("func") == 10);
    assert(lookup_go_hash1("package") == 17);
    assert(lookup_go_hash1("else") == 7);
    assert(lookup_go_hash1("go") == 11);
    assert(lookup_go_hash1("const") == 3);
    assert(lookup_go_hash1("range") == 18);
    assert(lookup_go_hash1("var") == 24);
    assert(lookup_go_hash1("return") == 19);
    assert(lookup_go_hash1("map") == 16);
    assert(lookup_go_hash1("select") == 20);
    assert(lookup_go_hash1("struct") == 21);
    assert(lookup_go_hash1("goto") == 12);
    assert(lookup_go_hash1("switch") == 22);
    assert(lookup_go_hash1("fallthrough") == 8);
    assert(lookup_go_hash1("default") == 5);
    assert(lookup_go_hash1("interface") == 15);
    assert(lookup_go_hash1("type") == 23);
    assert(lookup_go_hash1("if") == 13);
    assert(lookup_go_hash1("import") == 14);
    assert(lookup_go_hash1("break") == 0);
}

//lookup: name=lookup_go_hash2, dataset=go, type=hash, hash=hash2
int lookup_go_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 27) * 2;
    constexpr const std::string_view lookup[54] = {
        "select", // 13338 (0x341a)
        "struct", // 13338 (0x341a)
        "continue", // 9991 (0x2707)
        "import", // 12178 (0x2f92)
        "",
        "",
        "",
        "",
        "func", // 10102 (0x2776)
        "",
        "case", // 9995 (0x270b)
        "switch", // 11966 (0x2ebe)
        "const", // 11481 (0x2cd9)
        "package", // 11319 (0x2c37)
        "break", // 10483 (0x28f3)
        "map", // 12211 (0x2fb3)
        "fallthrough", // 10619 (0x297b)
        "",
        "var", // 13455 (0x348f)
        "",
        "return", // 12538 (0x30fa)
        "",
        "defer", // 11405 (0x2c8d)
        "",
        "interface", // 10596 (0x2964)
        "",
        "chan", // 10894 (0x2a8e)
        "",
        "go", // 11435 (0x2cab)
        "",
        "",
        "",
        "goto", // 11437 (0x2cad)
        "if", // 10708 (0x29d4)
        "range", // 11519 (0x2cff)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 11631 (0x2d6f)
        "type", // 11712 (0x2dc0)
        "",
        "",
        "",
        "",
        "default", // 11607 (0x2d57)
        "",
        "",
        "",
        "else", // 10205 (0x27dd)
        "",
    };
    constexpr const int values[54] = {
        20, // 13338 (0x341a)
        21, // 13338 (0x341a)
        4, // 9991 (0x2707)
        14, // 12178 (0x2f92)
        -1,
        -1,
        -1,
        -1,
        10, // 10102 (0x2776)
        -1,
        1, // 9995 (0x270b)
        22, // 11966 (0x2ebe)
        3, // 11481 (0x2cd9)
        17, // 11319 (0x2c37)
        0, // 10483 (0x28f3)
        16, // 12211 (0x2fb3)
        8, // 10619 (0x297b)
        -1,
        24, // 13455 (0x348f)
        -1,
        19, // 12538 (0x30fa)
        -1,
        6, // 11405 (0x2c8d)
        -1,
        15, // 10596 (0x2964)
        -1,
        2, // 10894 (0x2a8e)
        -1,
        11, // 11435 (0x2cab)
        -1,
        -1,
        -1,
        12, // 11437 (0x2cad)
        13, // 10708 (0x29d4)
        18, // 11519 (0x2cff)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 11631 (0x2d6f)
        23, // 11712 (0x2dc0)
        -1,
        -1,
        -1,
        -1,
        5, // 11607 (0x2d57)
        -1,
        -1,
        -1,
        7, // 10205 (0x27dd)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_go_hash2, dataset=go, type=hash, hash=hash2
void check_go_hash2() {
    assert(lookup_go_hash2("select") == 20);
    assert(lookup_go_hash2("struct") == 21);
    assert(lookup_go_hash2("continue") == 4);
    assert(lookup_go_hash2("import") == 14);
    assert(lookup_go_hash2("func") == 10);
    assert(lookup_go_hash2("case") == 1);
    assert(lookup_go_hash2("switch") == 22);
    assert(lookup_go_hash2("const") == 3);
    assert(lookup_go_hash2("package") == 17);
    assert(lookup_go_hash2("break") == 0);
    assert(lookup_go_hash2("map") == 16);
    assert(lookup_go_hash2("fallthrough") == 8);
    assert(lookup_go_hash2("var") == 24);
    assert(lookup_go_hash2("return") == 19);
    assert(lookup_go_hash2("defer") == 6);
    assert(lookup_go_hash2("interface") == 15);
    assert(lookup_go_hash2("chan") == 2);
    assert(lookup_go_hash2("go") == 11);
    assert(lookup_go_hash2("goto") == 12);
    assert(lookup_go_hash2("if") == 13);
    assert(lookup_go_hash2("range") == 18);
    assert(lookup_go_hash2("for") == 9);
    assert(lookup_go_hash2("type") == 23);
    assert(lookup_go_hash2("default") == 5);
    assert(lookup_go_hash2("else") == 7);
}

//lookup: name=lookup_go_hash3, dataset=go, type=hash, hash=hash3
int lookup_go_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 107) * 1;
    constexpr const std::string_view lookup[107] = {
        "",
        "",
        "defer", // 27180 (0x6a2c)
        "return", // 31033 (0x7939)
        "",
        "",
        "",
        "chan", // 26650 (0x681a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "default", // 27728 (0x6c50)
        "interface", // 29548 (0x736c)
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
        "continue", // 27740 (0x6c5c)
        "func", // 27420 (0x6b1c)
        "",
        "",
        "break", // 26674 (0x6832)
        "",
        "",
        "",
        "",
        "",
        "",
        "range", // 30747 (0x781b)
        "",
        "",
        "",
        "map", // 28932 (0x7104)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "select", // 31295 (0x7a3f)
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
        "go", // 27136 (0x6a00)
        "struct", // 31310 (0x7a4e)
        "import", // 28743 (0x7047)
        "",
        "",
        "",
        "",
        "package", // 30781 (0x783d)
        "",
        "",
        "",
        "goto", // 27682 (0x6c22)
        "",
        "",
        "const", // 26936 (0x6938)
        "",
        "",
        "",
        "",
        "",
        "for", // 27156 (0x6a14)
        "else", // 27157 (0x6a15)
        "type", // 31010 (0x7922)
        "",
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
        "var", // 31238 (0x7a06)
        "",
        "",
        "",
        "fallthrough", // 29316 (0x7284)
        "",
    };
    constexpr const int values[107] = {
        -1,
        -1,
        6, // 27180 (0x6a2c)
        19, // 31033 (0x7939)
        -1,
        -1,
        -1,
        2, // 26650 (0x681a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 27728 (0x6c50)
        15, // 29548 (0x736c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 27630 (0x6bee)
        -1,
        -1,
        4, // 27740 (0x6c5c)
        10, // 27420 (0x6b1c)
        -1,
        -1,
        0, // 26674 (0x6832)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 30747 (0x781b)
        -1,
        -1,
        -1,
        16, // 28932 (0x7104)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 31295 (0x7a3f)
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 31301 (0x7a45)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 27136 (0x6a00)
        21, // 31310 (0x7a4e)
        14, // 28743 (0x7047)
        -1,
        -1,
        -1,
        -1,
        17, // 30781 (0x783d)
        -1,
        -1,
        -1,
        12, // 27682 (0x6c22)
        -1,
        -1,
        3, // 26936 (0x6938)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 27156 (0x6a14)
        7, // 27157 (0x6a15)
        23, // 31010 (0x7922)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 26634 (0x680a)
        -1,
        -1,
        24, // 31238 (0x7a06)
        -1,
        -1,
        -1,
        8, // 29316 (0x7284)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_go_hash3, dataset=go, type=hash, hash=hash3
void check_go_hash3() {
    assert(lookup_go_hash3("defer") == 6);
    assert(lookup_go_hash3("return") == 19);
    assert(lookup_go_hash3("chan") == 2);
    assert(lookup_go_hash3("default") == 5);
    assert(lookup_go_hash3("interface") == 15);
    assert(lookup_go_hash3("if") == 13);
    assert(lookup_go_hash3("continue") == 4);
    assert(lookup_go_hash3("func") == 10);
    assert(lookup_go_hash3("break") == 0);
    assert(lookup_go_hash3("range") == 18);
    assert(lookup_go_hash3("map") == 16);
    assert(lookup_go_hash3("select") == 20);
    assert(lookup_go_hash3("switch") == 22);
    assert(lookup_go_hash3("go") == 11);
    assert(lookup_go_hash3("struct") == 21);
    assert(lookup_go_hash3("import") == 14);
    assert(lookup_go_hash3("package") == 17);
    assert(lookup_go_hash3("goto") == 12);
    assert(lookup_go_hash3("const") == 3);
    assert(lookup_go_hash3("for") == 9);
    assert(lookup_go_hash3("else") == 7);
    assert(lookup_go_hash3("type") == 23);
    assert(lookup_go_hash3("case") == 1);
    assert(lookup_go_hash3("var") == 24);
    assert(lookup_go_hash3("fallthrough") == 8);
}

//lookup: name=lookup_go_hash_sum0, dataset=go, type=hash, hash=hash_sum0
int lookup_go_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 73) * 1;
    constexpr const std::string_view lookup[73] = {
        "",
        "switch", // 658 (0x292)
        "",
        "goto", // 441 (0x1b9)
        "",
        "",
        "break", // 517 (0x205)
        "defer", // 518 (0x206)
        "",
        "",
        "import", // 667 (0x29b)
        "default", // 741 (0x2e5)
        "type", // 450 (0x1c2)
        "",
        "range", // 525 (0x20d)
        "return", // 672 (0x2a0)
        "fallthrough", // 1184 (0x4a0)
        "",
        "",
        "",
        "struct", // 677 (0x2a5)
        "",
        "",
        "",
        "",
        "",
        "map", // 318 (0x13e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 327 (0x147)
        "",
        "var", // 329 (0x149)
        "",
        "",
        "const", // 551 (0x227)
        "",
        "",
        "",
        "",
        "chan", // 410 (0x19a)
        "",
        "case", // 412 (0x19c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "select", // 640 (0x280)
        "",
        "",
        "package", // 716 (0x2cc)
        "else", // 425 (0x1a9)
        "if", // 207 (0xcf)
        "",
        "func", // 428 (0x1ac)
        "",
        "",
        "continue", // 869 (0x365)
        "",
        "go", // 214 (0xd6)
        "interface", // 945 (0x3b1)
        "",
        "",
        "",
    };
    constexpr const int values[73] = {
        -1,
        22, // 658 (0x292)
        -1,
        12, // 441 (0x1b9)
        -1,
        -1,
        0, // 517 (0x205)
        6, // 518 (0x206)
        -1,
        -1,
        14, // 667 (0x29b)
        5, // 741 (0x2e5)
        23, // 450 (0x1c2)
        -1,
        18, // 525 (0x20d)
        19, // 672 (0x2a0)
        8, // 1184 (0x4a0)
        -1,
        -1,
        -1,
        21, // 677 (0x2a5)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 318 (0x13e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 327 (0x147)
        -1,
        24, // 329 (0x149)
        -1,
        -1,
        3, // 551 (0x227)
        -1,
        -1,
        -1,
        -1,
        2, // 410 (0x19a)
        -1,
        1, // 412 (0x19c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 640 (0x280)
        -1,
        -1,
        17, // 716 (0x2cc)
        7, // 425 (0x1a9)
        13, // 207 (0xcf)
        -1,
        10, // 428 (0x1ac)
        -1,
        -1,
        4, // 869 (0x365)
        -1,
        11, // 214 (0xd6)
        15, // 945 (0x3b1)
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

//check: name=check_go_hash_sum0, dataset=go, type=hash, hash=hash_sum0
void check_go_hash_sum0() {
    assert(lookup_go_hash_sum0("switch") == 22);
    assert(lookup_go_hash_sum0("goto") == 12);
    assert(lookup_go_hash_sum0("break") == 0);
    assert(lookup_go_hash_sum0("defer") == 6);
    assert(lookup_go_hash_sum0("import") == 14);
    assert(lookup_go_hash_sum0("default") == 5);
    assert(lookup_go_hash_sum0("type") == 23);
    assert(lookup_go_hash_sum0("range") == 18);
    assert(lookup_go_hash_sum0("return") == 19);
    assert(lookup_go_hash_sum0("fallthrough") == 8);
    assert(lookup_go_hash_sum0("struct") == 21);
    assert(lookup_go_hash_sum0("map") == 16);
    assert(lookup_go_hash_sum0("for") == 9);
    assert(lookup_go_hash_sum0("var") == 24);
    assert(lookup_go_hash_sum0("const") == 3);
    assert(lookup_go_hash_sum0("chan") == 2);
    assert(lookup_go_hash_sum0("case") == 1);
    assert(lookup_go_hash_sum0("select") == 20);
    assert(lookup_go_hash_sum0("package") == 17);
    assert(lookup_go_hash_sum0("else") == 7);
    assert(lookup_go_hash_sum0("if") == 13);
    assert(lookup_go_hash_sum0("func") == 10);
    assert(lookup_go_hash_sum0("continue") == 4);
    assert(lookup_go_hash_sum0("go") == 11);
    assert(lookup_go_hash_sum0("interface") == 15);
}

//lookup: name=lookup_go_hash_sumN, dataset=go, type=hash, hash=hash_sumN
int lookup_go_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 63) * 1;
    constexpr const std::string_view lookup[63] = {
        "",
        "",
        "",
        "",
        "goto", // 445 (0x1bd)
        "",
        "map", // 321 (0x141)
        "",
        "",
        "interface", // 954 (0x3ba)
        "",
        "",
        "",
        "type", // 454 (0x1c6)
        "",
        "for", // 330 (0x14a)
        "select", // 646 (0x286)
        "var", // 332 (0x14c)
        "break", // 522 (0x20a)
        "defer", // 523 (0x20b)
        "if", // 209 (0xd1)
        "",
        "",
        "",
        "",
        "",
        "range", // 530 (0x212)
        "go", // 216 (0xd8)
        "",
        "",
        "package", // 723 (0x2d3)
        "",
        "",
        "",
        "switch", // 664 (0x298)
        "",
        "chan", // 414 (0x19e)
        "",
        "case", // 416 (0x1a0)
        "",
        "",
        "",
        "",
        "import", // 673 (0x2a1)
        "",
        "",
        "",
        "",
        "return", // 678 (0x2a6)
        "",
        "",
        "else", // 429 (0x1ad)
        "const", // 556 (0x22c)
        "struct", // 683 (0x2ab)
        "func", // 432 (0x1b0)
        "default", // 748 (0x2ec)
        "",
        "",
        "continue", // 877 (0x36d)
        "",
        "",
        "fallthrough", // 1195 (0x4ab)
        "",
    };
    constexpr const int values[63] = {
        -1,
        -1,
        -1,
        -1,
        12, // 445 (0x1bd)
        -1,
        16, // 321 (0x141)
        -1,
        -1,
        15, // 954 (0x3ba)
        -1,
        -1,
        -1,
        23, // 454 (0x1c6)
        -1,
        9, // 330 (0x14a)
        20, // 646 (0x286)
        24, // 332 (0x14c)
        0, // 522 (0x20a)
        6, // 523 (0x20b)
        13, // 209 (0xd1)
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 530 (0x212)
        11, // 216 (0xd8)
        -1,
        -1,
        17, // 723 (0x2d3)
        -1,
        -1,
        -1,
        22, // 664 (0x298)
        -1,
        2, // 414 (0x19e)
        -1,
        1, // 416 (0x1a0)
        -1,
        -1,
        -1,
        -1,
        14, // 673 (0x2a1)
        -1,
        -1,
        -1,
        -1,
        19, // 678 (0x2a6)
        -1,
        -1,
        7, // 429 (0x1ad)
        3, // 556 (0x22c)
        21, // 683 (0x2ab)
        10, // 432 (0x1b0)
        5, // 748 (0x2ec)
        -1,
        -1,
        4, // 877 (0x36d)
        -1,
        -1,
        8, // 1195 (0x4ab)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_go_hash_sumN, dataset=go, type=hash, hash=hash_sumN
void check_go_hash_sumN() {
    assert(lookup_go_hash_sumN("goto") == 12);
    assert(lookup_go_hash_sumN("map") == 16);
    assert(lookup_go_hash_sumN("interface") == 15);
    assert(lookup_go_hash_sumN("type") == 23);
    assert(lookup_go_hash_sumN("for") == 9);
    assert(lookup_go_hash_sumN("select") == 20);
    assert(lookup_go_hash_sumN("var") == 24);
    assert(lookup_go_hash_sumN("break") == 0);
    assert(lookup_go_hash_sumN("defer") == 6);
    assert(lookup_go_hash_sumN("if") == 13);
    assert(lookup_go_hash_sumN("range") == 18);
    assert(lookup_go_hash_sumN("go") == 11);
    assert(lookup_go_hash_sumN("package") == 17);
    assert(lookup_go_hash_sumN("switch") == 22);
    assert(lookup_go_hash_sumN("chan") == 2);
    assert(lookup_go_hash_sumN("case") == 1);
    assert(lookup_go_hash_sumN("import") == 14);
    assert(lookup_go_hash_sumN("return") == 19);
    assert(lookup_go_hash_sumN("else") == 7);
    assert(lookup_go_hash_sumN("const") == 3);
    assert(lookup_go_hash_sumN("struct") == 21);
    assert(lookup_go_hash_sumN("func") == 10);
    assert(lookup_go_hash_sumN("default") == 5);
    assert(lookup_go_hash_sumN("continue") == 4);
    assert(lookup_go_hash_sumN("fallthrough") == 8);
}

//lookup: name=lookup_go_hash_djb2, dataset=go, type=hash, hash=hash_djb2
int lookup_go_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 107) * 1;
    constexpr const std::string_view lookup[107] = {
        "",
        "",
        "",
        "switch", // 7083181535963 (0x6712e84f2db)
        "",
        "for", // 197085552 (0xbbf4970)
        "goto", // 6503859330 (0x183a90482)
        "go", // 5972319 (0x5b215f)
        "",
        "",
        "",
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
        "",
        "return", // 7083121450889 (0x6712af01f89)
        "",
        "func", // 6503829717 (0x183a890d5)
        "",
        "",
        "select", // 7083160280873 (0x6712d409f29)
        "range", // 214639893206 (0x31f988dad6)
        "",
        "",
        "continue", // 7712892661735406 (0x1b66d5c34b1fee)
        "",
        "default", // 233724910009454 (0xd492523c7c6e)
        "",
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
        "",
        "chan", // 6503707331 (0x183a6b2c3)
        "package", // 233740247863157 (0xd495e4718f75)
        "",
        "",
        "",
        "",
        "",
        "var", // 197102514 (0xbbf8bb2)
        "break", // 214621519406 (0x31f8707e2e)
        "",
        "if", // 5972376 (0x5b2198)
        "const", // 214622607920 (0x31f8811a30)
        "fallthrough", // 481004315519664713 (0x6acdee061fac249)
        "defer", // 214623425295 (0x31f88d930f)
        "",
        "",
        "",
        "",
        "",
        "type", // 6504337259 (0x183b04f6b)
        "",
        "",
        "",
        "",
        "case", // 6503700293 (0x183a69745)
        "",
        "",
        "",
        "",
        "",
        "",
        "import", // 7082778569444 (0x67116802ae4)
        "",
        "",
        "",
        "",
        "",
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
        "map", // 197092711 (0xbbf6567)
        "",
        "",
        "",
        "",
    };
    constexpr const int values[107] = {
        -1,
        -1,
        -1,
        22, // 7083181535963 (0x6712e84f2db)
        -1,
        9, // 197085552 (0xbbf4970)
        12, // 6503859330 (0x183a90482)
        11, // 5972319 (0x5b215f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 254533860842675834 (0x3884932a6d61e7a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 7083121450889 (0x6712af01f89)
        -1,
        10, // 6503829717 (0x183a890d5)
        -1,
        -1,
        20, // 7083160280873 (0x6712d409f29)
        18, // 214639893206 (0x31f988dad6)
        -1,
        -1,
        4, // 7712892661735406 (0x1b66d5c34b1fee)
        -1,
        5, // 233724910009454 (0xd492523c7c6e)
        -1,
        7, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 6503707331 (0x183a6b2c3)
        17, // 233740247863157 (0xd495e4718f75)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 197102514 (0xbbf8bb2)
        0, // 214621519406 (0x31f8707e2e)
        -1,
        13, // 5972376 (0x5b2198)
        3, // 214622607920 (0x31f8811a30)
        8, // 481004315519664713 (0x6acdee061fac249)
        6, // 214623425295 (0x31f88d930f)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 6504337259 (0x183b04f6b)
        -1,
        -1,
        -1,
        -1,
        1, // 6503700293 (0x183a69745)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 7082778569444 (0x67116802ae4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 7083178302734 (0x6712e539d0e)
        -1,
        16, // 197092711 (0xbbf6567)
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

//check: name=check_go_hash_djb2, dataset=go, type=hash, hash=hash_djb2
void check_go_hash_djb2() {
    assert(lookup_go_hash_djb2("switch") == 22);
    assert(lookup_go_hash_djb2("for") == 9);
    assert(lookup_go_hash_djb2("goto") == 12);
    assert(lookup_go_hash_djb2("go") == 11);
    assert(lookup_go_hash_djb2("interface") == 15);
    assert(lookup_go_hash_djb2("return") == 19);
    assert(lookup_go_hash_djb2("func") == 10);
    assert(lookup_go_hash_djb2("select") == 20);
    assert(lookup_go_hash_djb2("range") == 18);
    assert(lookup_go_hash_djb2("continue") == 4);
    assert(lookup_go_hash_djb2("default") == 5);
    assert(lookup_go_hash_djb2("else") == 7);
    assert(lookup_go_hash_djb2("chan") == 2);
    assert(lookup_go_hash_djb2("package") == 17);
    assert(lookup_go_hash_djb2("var") == 24);
    assert(lookup_go_hash_djb2("break") == 0);
    assert(lookup_go_hash_djb2("if") == 13);
    assert(lookup_go_hash_djb2("const") == 3);
    assert(lookup_go_hash_djb2("fallthrough") == 8);
    assert(lookup_go_hash_djb2("defer") == 6);
    assert(lookup_go_hash_djb2("type") == 23);
    assert(lookup_go_hash_djb2("case") == 1);
    assert(lookup_go_hash_djb2("import") == 14);
    assert(lookup_go_hash_djb2("struct") == 21);
    assert(lookup_go_hash_djb2("map") == 16);
}

//lookup: name=lookup_go_hash_sdb, dataset=go, type=hash, hash=hash_sdb
int lookup_go_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 71) * 1;
    constexpr const std::string_view lookup[71] = {
        "goto", // 28996381010759823 (0x67040e0deb108f)
        "",
        "interface", // 12514925068772314305 (0xadadf20b0ace0cc1)
        "map", // 468200654184 (0x6d02ef0568)
        "",
        "",
        "import", // 3059784849221326761 (0x2a768a1be2f597a9)
        "",
        "",
        "",
        "type", // 32656101195518514 (0x74048d0f821232)
        "",
        "else", // 28433340858241073 (0x6503f90da21031)
        "return", // 3261892644424556104 (0x2d449213ee629e48)
        "default", // 18130751609074855161 (0xfb9d5e8711bfacf9)
        "",
        "",
        "",
        "",
        "go", // 6750628 (0x6701a4)
        "",
        "package", // 1399373631390272162 (0x136b92e74f10caa2)
        "if", // 6881697 (0x6901a1)
        "func", // 28714893149343884 (0x66040b0dee108c)
        "",
        "",
        "",
        "",
        "defer", // 366226480669142914 (0x515190b37a02f82)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 27870266342903704 (0x6303dc0d2a0f98)
        "",
        "select", // 3284974374203989420 (0x2d9692c9eeb09dac)
        "",
        "continue", // 6848942472000841643 (0x5f0c54e41ab227ab)
        "",
        "struct", // 3337332499566470045 (0x2e509639f606a39d)
        "",
        "",
        "var", // 506858898875 (0x76032505bb)
        "",
        "chan", // 27870296409247658 (0x6303e30d420faa)
        "",
        "",
        "for", // 438134048085 (0x6602d30555)
        "",
        "",
        "",
        "",
        "break", // 363130290293256227 (0x50a1913381d3023)
        "",
        "",
        "",
        "",
        "range", // 412391503681172421 (0x5b91be33d4e33c5)
        "",
        "switch", // 3344932667539956616 (0x2e6b9689f651a388)
        "",
        "",
        "fallthrough", // 5979596356427994742 (0x52fbcb34751c5676)
        "",
        "",
        "",
        "const", // 365663719708962995 (0x5131937388030b3)
        "",
    };
    constexpr const int values[71] = {
        12, // 28996381010759823 (0x67040e0deb108f)
        -1,
        15, // 12514925068772314305 (0xadadf20b0ace0cc1)
        16, // 468200654184 (0x6d02ef0568)
        -1,
        -1,
        14, // 3059784849221326761 (0x2a768a1be2f597a9)
        -1,
        -1,
        -1,
        23, // 32656101195518514 (0x74048d0f821232)
        -1,
        7, // 28433340858241073 (0x6503f90da21031)
        19, // 3261892644424556104 (0x2d449213ee629e48)
        5, // 18130751609074855161 (0xfb9d5e8711bfacf9)
        -1,
        -1,
        -1,
        -1,
        11, // 6750628 (0x6701a4)
        -1,
        17, // 1399373631390272162 (0x136b92e74f10caa2)
        13, // 6881697 (0x6901a1)
        10, // 28714893149343884 (0x66040b0dee108c)
        -1,
        -1,
        -1,
        -1,
        6, // 366226480669142914 (0x515190b37a02f82)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 27870266342903704 (0x6303dc0d2a0f98)
        -1,
        20, // 3284974374203989420 (0x2d9692c9eeb09dac)
        -1,
        4, // 6848942472000841643 (0x5f0c54e41ab227ab)
        -1,
        21, // 3337332499566470045 (0x2e509639f606a39d)
        -1,
        -1,
        24, // 506858898875 (0x76032505bb)
        -1,
        2, // 27870296409247658 (0x6303e30d420faa)
        -1,
        -1,
        9, // 438134048085 (0x6602d30555)
        -1,
        -1,
        -1,
        -1,
        0, // 363130290293256227 (0x50a1913381d3023)
        -1,
        -1,
        -1,
        -1,
        18, // 412391503681172421 (0x5b91be33d4e33c5)
        -1,
        22, // 3344932667539956616 (0x2e6b9689f651a388)
        -1,
        -1,
        8, // 5979596356427994742 (0x52fbcb34751c5676)
        -1,
        -1,
        -1,
        3, // 365663719708962995 (0x5131937388030b3)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_go_hash_sdb, dataset=go, type=hash, hash=hash_sdb
void check_go_hash_sdb() {
    assert(lookup_go_hash_sdb("goto") == 12);
    assert(lookup_go_hash_sdb("interface") == 15);
    assert(lookup_go_hash_sdb("map") == 16);
    assert(lookup_go_hash_sdb("import") == 14);
    assert(lookup_go_hash_sdb("type") == 23);
    assert(lookup_go_hash_sdb("else") == 7);
    assert(lookup_go_hash_sdb("return") == 19);
    assert(lookup_go_hash_sdb("default") == 5);
    assert(lookup_go_hash_sdb("go") == 11);
    assert(lookup_go_hash_sdb("package") == 17);
    assert(lookup_go_hash_sdb("if") == 13);
    assert(lookup_go_hash_sdb("func") == 10);
    assert(lookup_go_hash_sdb("defer") == 6);
    assert(lookup_go_hash_sdb("case") == 1);
    assert(lookup_go_hash_sdb("select") == 20);
    assert(lookup_go_hash_sdb("continue") == 4);
    assert(lookup_go_hash_sdb("struct") == 21);
    assert(lookup_go_hash_sdb("var") == 24);
    assert(lookup_go_hash_sdb("chan") == 2);
    assert(lookup_go_hash_sdb("for") == 9);
    assert(lookup_go_hash_sdb("break") == 0);
    assert(lookup_go_hash_sdb("range") == 18);
    assert(lookup_go_hash_sdb("switch") == 22);
    assert(lookup_go_hash_sdb("fallthrough") == 8);
    assert(lookup_go_hash_sdb("const") == 3);
}
