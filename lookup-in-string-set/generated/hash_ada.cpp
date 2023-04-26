
//lookup: name=lookup_ada_hash1, dataset=ada, hash=hash1
int lookup_ada_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 130) * 2;
    static std::string_view lookup[260] = {
        "begin", // 1040 (0x410)
        "",
        "",
        "",
        "",
        "",
        "terminate", // 1953 (0x7a1)
        "",
        "use", // 654 (0x28e)
        "",
        "",
        "",
        "function", // 1696 (0x6a0)
        "when", // 916 (0x394)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "rem", // 669 (0x29d)
        "",
        "case", // 800 (0x320)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 414 (0x19e)
        "",
        "abort", // 1065 (0x429)
        "",
        "limited", // 1456 (0x5b0)
        "",
        "",
        "",
        "else", // 808 (0x328)
        "not", // 678 (0x2a6)
        "",
        "",
        "constant", // 1720 (0x6b8)
        "",
        "out", // 681 (0x2a9)
        "",
        "do", // 422 (0x1a6)
        "",
        "",
        "",
        "",
        "",
        "raise", // 1075 (0x433)
        "range", // 1075 (0x433)
        "at", // 426 (0x1aa)
        "of", // 426 (0x1aa)
        "new", // 687 (0x2af)
        "",
        "separate", // 1728 (0x6c0)
        "",
        "",
        "",
        "in", // 430 (0x1ae)
        "",
        "",
        "",
        "",
        "",
        "renames", // 1603 (0x643)
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
        "array", // 1090 (0x442)
        "is", // 440 (0x1b8)
        "",
        "",
        "xor", // 702 (0x2be)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "others", // 1356 (0x54c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 1100 (0x44c)
        "or", // 450 (0x1c2)
        "package", // 1491 (0x5d3)
        "private", // 1491 (0x5d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "delay", // 1105 (0x451)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "entry", // 1110 (0x456)
        "",
        "and", // 591 (0x24f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "reverse", // 1505 (0x5e1)
        "delta", // 985 (0x3d9)
        "goto", // 856 (0x358)
        "",
        "",
        "",
        "",
        "",
        "exception", // 1899 (0x76b)
        "",
        "",
        "",
        "",
        "",
        "subtype", // 1512 (0x5e8)
        "",
        "end", // 603 (0x25b)
        "",
        "pragma", // 1254 (0x4e6)
        "",
        "",
        "",
        "select", // 1386 (0x56a)
        "",
        "",
        "",
        "exit", // 868 (0x364)
        "type", // 868 (0x364)
        "",
        "",
        "",
        "",
        "",
        "",
        "null", // 872 (0x368)
        "",
        "",
        "",
        "",
        "",
        "all", // 615 (0x267)
        "",
        "body", // 876 (0x36c)
        "",
        "procedure", // 1917 (0x77d)
        "",
        "",
        "",
        "",
        "",
        "loop", // 880 (0x370)
        "",
        "",
        "",
        "access", // 1272 (0x4f8)
        "",
        "",
        "",
        "",
        "",
        "elsif", // 1015 (0x3f7)
        "",
        "",
        "",
        "declare", // 1407 (0x57f)
        "mod", // 627 (0x273)
        "accept", // 1278 (0x4fe)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "task", // 892 (0x37c)
        "with", // 892 (0x37c)
        "",
        "",
        "record", // 1284 (0x504)
        "generic", // 1414 (0x586)
        "",
        "",
        "abs", // 636 (0x27c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "digits", // 1290 (0x50a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "then", // 904 (0x388)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 648 (0x288)
        "",
        "",
        "",
    };
    static int values[260] = {
        57, // 1040 (0x410)
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 1953 (0x7a1)
        -1,
        41, // 654 (0x28e)
        -1,
        -1,
        -1,
        20, // 1696 (0x6a0)
        26, // 916 (0x394)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 669 (0x29d)
        -1,
        30, // 800 (0x320)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 414 (0x19e)
        -1,
        33, // 1065 (0x429)
        -1,
        48, // 1456 (0x5b0)
        -1,
        -1,
        -1,
        0, // 808 (0x328)
        11, // 678 (0x2a6)
        -1,
        -1,
        31, // 1720 (0x6b8)
        -1,
        42, // 681 (0x2a9)
        -1,
        43, // 422 (0x1a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 1075 (0x433)
        5, // 1075 (0x433)
        32, // 426 (0x1aa)
        45, // 426 (0x1aa)
        27, // 687 (0x2af)
        -1,
        14, // 1728 (0x6c0)
        -1,
        -1,
        -1,
        52, // 430 (0x1ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 1603 (0x643)
        -1,
        13, // 1344 (0x540)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 1090 (0x442)
        53, // 440 (0x1b8)
        -1,
        -1,
        59, // 702 (0x2be)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 1356 (0x54c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1100 (0x44c)
        46, // 450 (0x1c2)
        22, // 1491 (0x5d3)
        24, // 1491 (0x5d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 1105 (0x451)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 1110 (0x456)
        -1,
        35, // 591 (0x24f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 1505 (0x5e1)
        36, // 985 (0x3d9)
        60, // 856 (0x358)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 1899 (0x76b)
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 1512 (0x5e8)
        -1,
        8, // 603 (0x25b)
        -1,
        39, // 1254 (0x4e6)
        -1,
        -1,
        -1,
        15, // 1386 (0x56a)
        -1,
        -1,
        -1,
        1, // 868 (0x364)
        3, // 868 (0x364)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 872 (0x368)
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 615 (0x267)
        -1,
        58, // 876 (0x36c)
        -1,
        23, // 1917 (0x77d)
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 880 (0x370)
        -1,
        -1,
        -1,
        37, // 1272 (0x4f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 1015 (0x3f7)
        -1,
        -1,
        -1,
        7, // 1407 (0x57f)
        56, // 627 (0x273)
        34, // 1278 (0x4fe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 892 (0x37c)
        62, // 892 (0x37c)
        -1,
        -1,
        9, // 1284 (0x504)
        61, // 1414 (0x586)
        -1,
        -1,
        38, // 636 (0x27c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 1290 (0x50a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 904 (0x388)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 648 (0x288)
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

//check: name=check_ada_hash1, dataset=ada, hash=hash1
void check_ada_hash1() {
    assert(lookup_ada_hash1("begin") == 57);
    assert(lookup_ada_hash1("terminate") == 2);
    assert(lookup_ada_hash1("use") == 41);
    assert(lookup_ada_hash1("function") == 20);
    assert(lookup_ada_hash1("when") == 26);
    assert(lookup_ada_hash1("rem") == 55);
    assert(lookup_ada_hash1("case") == 30);
    assert(lookup_ada_hash1("if") == 54);
    assert(lookup_ada_hash1("abort") == 33);
    assert(lookup_ada_hash1("limited") == 48);
    assert(lookup_ada_hash1("else") == 0);
    assert(lookup_ada_hash1("not") == 11);
    assert(lookup_ada_hash1("constant") == 31);
    assert(lookup_ada_hash1("out") == 42);
    assert(lookup_ada_hash1("do") == 43);
    assert(lookup_ada_hash1("raise") == 4);
    assert(lookup_ada_hash1("range") == 5);
    assert(lookup_ada_hash1("at") == 32);
    assert(lookup_ada_hash1("of") == 45);
    assert(lookup_ada_hash1("new") == 27);
    assert(lookup_ada_hash1("separate") == 14);
    assert(lookup_ada_hash1("in") == 52);
    assert(lookup_ada_hash1("renames") == 17);
    assert(lookup_ada_hash1("return") == 13);
    assert(lookup_ada_hash1("array") == 40);
    assert(lookup_ada_hash1("is") == 53);
    assert(lookup_ada_hash1("xor") == 59);
    assert(lookup_ada_hash1("others") == 44);
    assert(lookup_ada_hash1("while") == 25);
    assert(lookup_ada_hash1("or") == 46);
    assert(lookup_ada_hash1("package") == 22);
    assert(lookup_ada_hash1("private") == 24);
    assert(lookup_ada_hash1("delay") == 29);
    assert(lookup_ada_hash1("entry") == 28);
    assert(lookup_ada_hash1("and") == 35);
    assert(lookup_ada_hash1("reverse") == 6);
    assert(lookup_ada_hash1("delta") == 36);
    assert(lookup_ada_hash1("goto") == 60);
    assert(lookup_ada_hash1("exception") == 10);
    assert(lookup_ada_hash1("subtype") == 18);
    assert(lookup_ada_hash1("end") == 8);
    assert(lookup_ada_hash1("pragma") == 39);
    assert(lookup_ada_hash1("select") == 15);
    assert(lookup_ada_hash1("exit") == 1);
    assert(lookup_ada_hash1("type") == 3);
    assert(lookup_ada_hash1("null") == 50);
    assert(lookup_ada_hash1("all") == 47);
    assert(lookup_ada_hash1("body") == 58);
    assert(lookup_ada_hash1("procedure") == 23);
    assert(lookup_ada_hash1("loop") == 49);
    assert(lookup_ada_hash1("access") == 37);
    assert(lookup_ada_hash1("elsif") == 19);
    assert(lookup_ada_hash1("declare") == 7);
    assert(lookup_ada_hash1("mod") == 56);
    assert(lookup_ada_hash1("accept") == 34);
    assert(lookup_ada_hash1("task") == 51);
    assert(lookup_ada_hash1("with") == 62);
    assert(lookup_ada_hash1("record") == 9);
    assert(lookup_ada_hash1("generic") == 61);
    assert(lookup_ada_hash1("abs") == 38);
    assert(lookup_ada_hash1("digits") == 16);
    assert(lookup_ada_hash1("then") == 12);
    assert(lookup_ada_hash1("for") == 21);
}

//lookup: name=lookup_ada_hash2, dataset=ada, hash=hash2
int lookup_ada_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 149) * 2;
    static std::string_view lookup[298] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "constant", // 11476 (0x2cd4)
        "",
        "is", // 12073 (0x2f29)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 11631 (0x2d6f)
        "",
        "",
        "",
        "",
        "",
        "case", // 9995 (0x270b)
        "delta", // 9697 (0x25e1)
        "with", // 12380 (0x305c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "elsif", // 10299 (0x283b)
        "and", // 9703 (0x25e7)
        "",
        "",
        "",
        "",
        "",
        "",
        "return", // 12538 (0x30fa)
        "",
        "",
        "",
        "",
        "",
        "digits", // 11498 (0x2cea)
        "",
        "mod", // 10903 (0x2a97)
        "",
        "",
        "",
        "delay", // 12097 (0x2f41)
        "",
        "",
        "",
        "",
        "",
        "loop", // 12100 (0x2f44)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "task", // 12408 (0x3078)
        "",
        "",
        "",
        "",
        "",
        "reverse", // 11517 (0x2cfd)
        "",
        "",
        "",
        "raise", // 11519 (0x2cff)
        "range", // 11519 (0x2cff)
        "use", // 11818 (0x2e2a)
        "",
        "",
        "",
        "all", // 10479 (0x28ef)
        "begin", // 10777 (0x2a19)
        "",
        "",
        "",
        "",
        "",
        "",
        "function", // 11228 (0x2bdc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "rem", // 12425 (0x3089)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "generic", // 10194 (0x27d2)
        "",
        "",
        "",
        "",
        "",
        "out", // 12879 (0x324f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 10205 (0x27dd)
        "",
        "abort", // 11249 (0x2bf1)
        "",
        "accept", // 11250 (0x2bf2)
        "in", // 11548 (0x2d1c)
        "do", // 11102 (0x2b5e)
        "",
        "select", // 13338 (0x341a)
        "",
        "",
        "",
        "at", // 11254 (0x2bf6)
        "limited", // 10807 (0x2a37)
        "",
        "",
        "",
        "",
        "record", // 11406 (0x2c8e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "exit", // 11712 (0x2dc0)
        "type", // 11712 (0x2dc0)
        "body", // 11862 (0x2e56)
        "",
        "",
        "",
        "exception", // 11119 (0x2b6f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "not", // 12763 (0x31db)
        "others", // 12763 (0x31db)
        "then", // 12764 (0x31dc)
        "",
        "",
        "",
        "",
        "",
        "while", // 12022 (0x2ef6)
        "",
        "terminate", // 11725 (0x2dcd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "null", // 11884 (0x2e6c)
        "goto", // 11437 (0x2cad)
        "",
        "",
        "",
        "",
        "declare", // 10099 (0x2773)
        "",
        "",
        "",
        "array", // 11740 (0x2ddc)
        "",
        "",
        "",
        "end", // 10103 (0x2777)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "xor", // 13683 (0x3573)
        "",
        "",
        "",
        "new", // 13089 (0x3321)
        "abs", // 11152 (0x2b90)
        "",
        "",
        "",
        "",
        "if", // 10708 (0x29d4)
        "",
        "",
        "",
        "when", // 13094 (0x3326)
        "access", // 11157 (0x2b95)
        "",
        "",
        "",
        "",
        "separate", // 11607 (0x2d57)
        "",
        "subtype", // 11608 (0x2d58)
        "",
        "or", // 12652 (0x316c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "renames", // 13105 (0x3331)
        "pragma", // 10870 (0x2a76)
        "",
        "",
        "package", // 11319 (0x2c37)
        "private", // 11319 (0x2c37)
        "of", // 11320 (0x2c38)
        "",
        "procedure", // 11321 (0x2c39)
        "",
        "entry", // 12216 (0x2fb8)
        "",
        "",
        "",
    };
    static int values[298] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 11476 (0x2cd4)
        -1,
        53, // 12073 (0x2f29)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 11631 (0x2d6f)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 9995 (0x270b)
        36, // 9697 (0x25e1)
        62, // 12380 (0x305c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 10299 (0x283b)
        35, // 9703 (0x25e7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 12538 (0x30fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 11498 (0x2cea)
        -1,
        56, // 10903 (0x2a97)
        -1,
        -1,
        -1,
        29, // 12097 (0x2f41)
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 12100 (0x2f44)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 12408 (0x3078)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 11517 (0x2cfd)
        -1,
        -1,
        -1,
        4, // 11519 (0x2cff)
        5, // 11519 (0x2cff)
        41, // 11818 (0x2e2a)
        -1,
        -1,
        -1,
        47, // 10479 (0x28ef)
        57, // 10777 (0x2a19)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 11228 (0x2bdc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 12425 (0x3089)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 10194 (0x27d2)
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 12879 (0x324f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 10205 (0x27dd)
        -1,
        33, // 11249 (0x2bf1)
        -1,
        34, // 11250 (0x2bf2)
        52, // 11548 (0x2d1c)
        43, // 11102 (0x2b5e)
        -1,
        15, // 13338 (0x341a)
        -1,
        -1,
        -1,
        32, // 11254 (0x2bf6)
        48, // 10807 (0x2a37)
        -1,
        -1,
        -1,
        -1,
        9, // 11406 (0x2c8e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 11712 (0x2dc0)
        3, // 11712 (0x2dc0)
        58, // 11862 (0x2e56)
        -1,
        -1,
        -1,
        10, // 11119 (0x2b6f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 12763 (0x31db)
        44, // 12763 (0x31db)
        12, // 12764 (0x31dc)
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 12022 (0x2ef6)
        -1,
        2, // 11725 (0x2dcd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 11884 (0x2e6c)
        60, // 11437 (0x2cad)
        -1,
        -1,
        -1,
        -1,
        7, // 10099 (0x2773)
        -1,
        -1,
        -1,
        40, // 11740 (0x2ddc)
        -1,
        -1,
        -1,
        8, // 10103 (0x2777)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        59, // 13683 (0x3573)
        -1,
        -1,
        -1,
        27, // 13089 (0x3321)
        38, // 11152 (0x2b90)
        -1,
        -1,
        -1,
        -1,
        54, // 10708 (0x29d4)
        -1,
        -1,
        -1,
        26, // 13094 (0x3326)
        37, // 11157 (0x2b95)
        -1,
        -1,
        -1,
        -1,
        14, // 11607 (0x2d57)
        -1,
        18, // 11608 (0x2d58)
        -1,
        46, // 12652 (0x316c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 13105 (0x3331)
        39, // 10870 (0x2a76)
        -1,
        -1,
        22, // 11319 (0x2c37)
        24, // 11319 (0x2c37)
        45, // 11320 (0x2c38)
        -1,
        23, // 11321 (0x2c39)
        -1,
        28, // 12216 (0x2fb8)
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

//check: name=check_ada_hash2, dataset=ada, hash=hash2
void check_ada_hash2() {
    assert(lookup_ada_hash2("constant") == 31);
    assert(lookup_ada_hash2("is") == 53);
    assert(lookup_ada_hash2("for") == 21);
    assert(lookup_ada_hash2("case") == 30);
    assert(lookup_ada_hash2("delta") == 36);
    assert(lookup_ada_hash2("with") == 62);
    assert(lookup_ada_hash2("elsif") == 19);
    assert(lookup_ada_hash2("and") == 35);
    assert(lookup_ada_hash2("return") == 13);
    assert(lookup_ada_hash2("digits") == 16);
    assert(lookup_ada_hash2("mod") == 56);
    assert(lookup_ada_hash2("delay") == 29);
    assert(lookup_ada_hash2("loop") == 49);
    assert(lookup_ada_hash2("task") == 51);
    assert(lookup_ada_hash2("reverse") == 6);
    assert(lookup_ada_hash2("raise") == 4);
    assert(lookup_ada_hash2("range") == 5);
    assert(lookup_ada_hash2("use") == 41);
    assert(lookup_ada_hash2("all") == 47);
    assert(lookup_ada_hash2("begin") == 57);
    assert(lookup_ada_hash2("function") == 20);
    assert(lookup_ada_hash2("rem") == 55);
    assert(lookup_ada_hash2("generic") == 61);
    assert(lookup_ada_hash2("out") == 42);
    assert(lookup_ada_hash2("else") == 0);
    assert(lookup_ada_hash2("abort") == 33);
    assert(lookup_ada_hash2("accept") == 34);
    assert(lookup_ada_hash2("in") == 52);
    assert(lookup_ada_hash2("do") == 43);
    assert(lookup_ada_hash2("select") == 15);
    assert(lookup_ada_hash2("at") == 32);
    assert(lookup_ada_hash2("limited") == 48);
    assert(lookup_ada_hash2("record") == 9);
    assert(lookup_ada_hash2("exit") == 1);
    assert(lookup_ada_hash2("type") == 3);
    assert(lookup_ada_hash2("body") == 58);
    assert(lookup_ada_hash2("exception") == 10);
    assert(lookup_ada_hash2("not") == 11);
    assert(lookup_ada_hash2("others") == 44);
    assert(lookup_ada_hash2("then") == 12);
    assert(lookup_ada_hash2("while") == 25);
    assert(lookup_ada_hash2("terminate") == 2);
    assert(lookup_ada_hash2("null") == 50);
    assert(lookup_ada_hash2("goto") == 60);
    assert(lookup_ada_hash2("declare") == 7);
    assert(lookup_ada_hash2("array") == 40);
    assert(lookup_ada_hash2("end") == 8);
    assert(lookup_ada_hash2("xor") == 59);
    assert(lookup_ada_hash2("new") == 27);
    assert(lookup_ada_hash2("abs") == 38);
    assert(lookup_ada_hash2("if") == 54);
    assert(lookup_ada_hash2("when") == 26);
    assert(lookup_ada_hash2("access") == 37);
    assert(lookup_ada_hash2("separate") == 14);
    assert(lookup_ada_hash2("subtype") == 18);
    assert(lookup_ada_hash2("or") == 46);
    assert(lookup_ada_hash2("renames") == 17);
    assert(lookup_ada_hash2("pragma") == 39);
    assert(lookup_ada_hash2("package") == 22);
    assert(lookup_ada_hash2("private") == 24);
    assert(lookup_ada_hash2("of") == 45);
    assert(lookup_ada_hash2("procedure") == 23);
    assert(lookup_ada_hash2("entry") == 28);
}

//lookup: name=lookup_ada_hash3, dataset=ada, hash=hash3
int lookup_ada_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 70) * 2;
    static std::string_view lookup[140] = {
        "type", // 31010 (0x7922)
        "or", // 29190 (0x7206)
        "pragma", // 30521 (0x7739)
        "",
        "",
        "",
        "delta", // 27163 (0x6a1b)
        "",
        "",
        "",
        "end", // 26885 (0x6905)
        "select", // 31295 (0x7a3f)
        "is", // 27656 (0x6c08)
        "",
        "reverse", // 31297 (0x7a41)
        "null", // 29477 (0x7325)
        "",
        "",
        "new", // 29199 (0x720f)
        "",
        "",
        "",
        "",
        "",
        "entry", // 27452 (0x6b3c)
        "",
        "record", // 31023 (0x792f)
        "",
        "access", // 26684 (0x683c)
        "limited", // 29764 (0x7444)
        "terminate", // 32355 (0x7e63)
        "accept", // 26685 (0x683d)
        "not", // 29206 (0x7216)
        "",
        "raise", // 30747 (0x781b)
        "range", // 30747 (0x781b)
        "digits", // 27458 (0x6b42)
        "",
        "",
        "",
        "",
        "",
        "renames", // 31311 (0x7a4f)
        "abort", // 26411 (0x672b)
        "body", // 26412 (0x672c)
        "",
        "return", // 31033 (0x7939)
        "",
        "exit", // 27184 (0x6a30)
        "mod", // 28934 (0x7106)
        "",
        "",
        "",
        "",
        "delay", // 27187 (0x6a33)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "and", // 25861 (0x6505)
        "",
        "goto", // 27682 (0x6c22)
        "",
        "function", // 28523 (0x6f6b)
        "",
        "case", // 26634 (0x680a)
        "abs", // 25864 (0x6508)
        "constant", // 27755 (0x6c6b)
        "",
        "",
        "",
        "all", // 25867 (0x650b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "array", // 26432 (0x6740)
        "",
        "rem", // 30213 (0x7605)
        "",
        "while", // 32034 (0x7d22)
        "",
        "others", // 30285 (0x764d)
        "",
        "separate", // 31826 (0x7c52)
        "of", // 29166 (0x71ee)
        "use", // 30987 (0x790b)
        "",
        "do", // 26368 (0x6700)
        "",
        "",
        "",
        "if", // 27630 (0x6bee)
        "",
        "package", // 30781 (0x783d)
        "",
        "task", // 30992 (0x7910)
        "",
        "exception", // 28543 (0x6f7f)
        "loop", // 28963 (0x7123)
        "procedure", // 31344 (0x7a70)
        "xor", // 31764 (0x7c14)
        "with", // 31765 (0x7c15)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "generic", // 28479 (0x6f3f)
        "",
        "when", // 31770 (0x7c1a)
        "at", // 25610 (0x640a)
        "elsif", // 27431 (0x6b27)
        "",
        "then", // 31002 (0x791a)
        "",
        "declare", // 27713 (0x6c41)
        "",
        "begin", // 26664 (0x6828)
        "",
        "",
        "",
        "for", // 27156 (0x6a14)
        "in", // 27646 (0x6bfe)
        "else", // 27157 (0x6a15)
        "",
        "private", // 30798 (0x784e)
        "out", // 29468 (0x731c)
        "subtype", // 31569 (0x7b51)
        "",
    };
    static int values[140] = {
        3, // 31010 (0x7922)
        46, // 29190 (0x7206)
        39, // 30521 (0x7739)
        -1,
        -1,
        -1,
        36, // 27163 (0x6a1b)
        -1,
        -1,
        -1,
        8, // 26885 (0x6905)
        15, // 31295 (0x7a3f)
        53, // 27656 (0x6c08)
        -1,
        6, // 31297 (0x7a41)
        50, // 29477 (0x7325)
        -1,
        -1,
        27, // 29199 (0x720f)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 27452 (0x6b3c)
        -1,
        9, // 31023 (0x792f)
        -1,
        37, // 26684 (0x683c)
        48, // 29764 (0x7444)
        2, // 32355 (0x7e63)
        34, // 26685 (0x683d)
        11, // 29206 (0x7216)
        -1,
        4, // 30747 (0x781b)
        5, // 30747 (0x781b)
        16, // 27458 (0x6b42)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 31311 (0x7a4f)
        33, // 26411 (0x672b)
        58, // 26412 (0x672c)
        -1,
        13, // 31033 (0x7939)
        -1,
        1, // 27184 (0x6a30)
        56, // 28934 (0x7106)
        -1,
        -1,
        -1,
        -1,
        29, // 27187 (0x6a33)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 25861 (0x6505)
        -1,
        60, // 27682 (0x6c22)
        -1,
        20, // 28523 (0x6f6b)
        -1,
        30, // 26634 (0x680a)
        38, // 25864 (0x6508)
        31, // 27755 (0x6c6b)
        -1,
        -1,
        -1,
        47, // 25867 (0x650b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 26432 (0x6740)
        -1,
        55, // 30213 (0x7605)
        -1,
        25, // 32034 (0x7d22)
        -1,
        44, // 30285 (0x764d)
        -1,
        14, // 31826 (0x7c52)
        45, // 29166 (0x71ee)
        41, // 30987 (0x790b)
        -1,
        43, // 26368 (0x6700)
        -1,
        -1,
        -1,
        54, // 27630 (0x6bee)
        -1,
        22, // 30781 (0x783d)
        -1,
        51, // 30992 (0x7910)
        -1,
        10, // 28543 (0x6f7f)
        49, // 28963 (0x7123)
        23, // 31344 (0x7a70)
        59, // 31764 (0x7c14)
        62, // 31765 (0x7c15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 28479 (0x6f3f)
        -1,
        26, // 31770 (0x7c1a)
        32, // 25610 (0x640a)
        19, // 27431 (0x6b27)
        -1,
        12, // 31002 (0x791a)
        -1,
        7, // 27713 (0x6c41)
        -1,
        57, // 26664 (0x6828)
        -1,
        -1,
        -1,
        21, // 27156 (0x6a14)
        52, // 27646 (0x6bfe)
        0, // 27157 (0x6a15)
        -1,
        24, // 30798 (0x784e)
        42, // 29468 (0x731c)
        18, // 31569 (0x7b51)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_ada_hash3, dataset=ada, hash=hash3
void check_ada_hash3() {
    assert(lookup_ada_hash3("type") == 3);
    assert(lookup_ada_hash3("or") == 46);
    assert(lookup_ada_hash3("pragma") == 39);
    assert(lookup_ada_hash3("delta") == 36);
    assert(lookup_ada_hash3("end") == 8);
    assert(lookup_ada_hash3("select") == 15);
    assert(lookup_ada_hash3("is") == 53);
    assert(lookup_ada_hash3("reverse") == 6);
    assert(lookup_ada_hash3("null") == 50);
    assert(lookup_ada_hash3("new") == 27);
    assert(lookup_ada_hash3("entry") == 28);
    assert(lookup_ada_hash3("record") == 9);
    assert(lookup_ada_hash3("access") == 37);
    assert(lookup_ada_hash3("limited") == 48);
    assert(lookup_ada_hash3("terminate") == 2);
    assert(lookup_ada_hash3("accept") == 34);
    assert(lookup_ada_hash3("not") == 11);
    assert(lookup_ada_hash3("raise") == 4);
    assert(lookup_ada_hash3("range") == 5);
    assert(lookup_ada_hash3("digits") == 16);
    assert(lookup_ada_hash3("renames") == 17);
    assert(lookup_ada_hash3("abort") == 33);
    assert(lookup_ada_hash3("body") == 58);
    assert(lookup_ada_hash3("return") == 13);
    assert(lookup_ada_hash3("exit") == 1);
    assert(lookup_ada_hash3("mod") == 56);
    assert(lookup_ada_hash3("delay") == 29);
    assert(lookup_ada_hash3("and") == 35);
    assert(lookup_ada_hash3("goto") == 60);
    assert(lookup_ada_hash3("function") == 20);
    assert(lookup_ada_hash3("case") == 30);
    assert(lookup_ada_hash3("abs") == 38);
    assert(lookup_ada_hash3("constant") == 31);
    assert(lookup_ada_hash3("all") == 47);
    assert(lookup_ada_hash3("array") == 40);
    assert(lookup_ada_hash3("rem") == 55);
    assert(lookup_ada_hash3("while") == 25);
    assert(lookup_ada_hash3("others") == 44);
    assert(lookup_ada_hash3("separate") == 14);
    assert(lookup_ada_hash3("of") == 45);
    assert(lookup_ada_hash3("use") == 41);
    assert(lookup_ada_hash3("do") == 43);
    assert(lookup_ada_hash3("if") == 54);
    assert(lookup_ada_hash3("package") == 22);
    assert(lookup_ada_hash3("task") == 51);
    assert(lookup_ada_hash3("exception") == 10);
    assert(lookup_ada_hash3("loop") == 49);
    assert(lookup_ada_hash3("procedure") == 23);
    assert(lookup_ada_hash3("xor") == 59);
    assert(lookup_ada_hash3("with") == 62);
    assert(lookup_ada_hash3("generic") == 61);
    assert(lookup_ada_hash3("when") == 26);
    assert(lookup_ada_hash3("at") == 32);
    assert(lookup_ada_hash3("elsif") == 19);
    assert(lookup_ada_hash3("then") == 12);
    assert(lookup_ada_hash3("declare") == 7);
    assert(lookup_ada_hash3("begin") == 57);
    assert(lookup_ada_hash3("for") == 21);
    assert(lookup_ada_hash3("in") == 52);
    assert(lookup_ada_hash3("else") == 0);
    assert(lookup_ada_hash3("private") == 24);
    assert(lookup_ada_hash3("out") == 42);
    assert(lookup_ada_hash3("subtype") == 18);
}

//lookup: name=lookup_ada_hash_sum0, dataset=ada, hash=hash_sum0
int lookup_ada_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 138) * 2;
    static std::string_view lookup[276] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "terminate", // 969 (0x3c9)
        "procedure", // 969 (0x3c9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "exception", // 975 (0x3cf)
        "",
        "entry", // 562 (0x232)
        "",
        "else", // 425 (0x1a9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "body", // 430 (0x1ae)
        "",
        "then", // 431 (0x1af)
        "",
        "",
        "",
        "",
        "",
        "when", // 434 (0x1b2)
        "",
        "task", // 435 (0x1b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "separate", // 853 (0x355)
        "",
        "package", // 716 (0x2cc)
        "",
        "goto", // 441 (0x1b9)
        "",
        "exit", // 442 (0x1ba)
        "loop", // 442 (0x1ba)
        "null", // 443 (0x1bb)
        "",
        "declare", // 720 (0x2d0)
        "with", // 444 (0x1bc)
        "and", // 307 (0x133)
        "",
        "",
        "",
        "",
        "",
        "abs", // 310 (0x136)
        "",
        "end", // 311 (0x137)
        "",
        "type", // 450 (0x1c2)
        "",
        "all", // 313 (0x139)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "function", // 870 (0x366)
        "",
        "generic", // 733 (0x2dd)
        "",
        "mod", // 320 (0x140)
        "",
        "",
        "",
        "constant", // 874 (0x36a)
        "",
        "",
        "",
        "rem", // 324 (0x144)
        "",
        "",
        "",
        "",
        "",
        "for", // 327 (0x147)
        "",
        "",
        "",
        "",
        "",
        "new", // 330 (0x14a)
        "limited", // 744 (0x2e8)
        "",
        "",
        "",
        "",
        "renames", // 747 (0x2eb)
        "use", // 333 (0x14d)
        "",
        "",
        "",
        "",
        "",
        "",
        "not", // 337 (0x151)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "out", // 344 (0x158)
        "",
        "if", // 207 (0xcf)
        "xor", // 345 (0x159)
        "",
        "",
        "",
        "",
        "accept", // 624 (0x270)
        "",
        "private", // 763 (0x2fb)
        "do", // 211 (0xd3)
        "reverse", // 764 (0x2fc)
        "access", // 626 (0x272)
        "at", // 213 (0xd5)
        "of", // 213 (0xd5)
        "",
        "",
        "in", // 215 (0xd7)
        "",
        "",
        "",
        "",
        "",
        "pragma", // 632 (0x278)
        "",
        "",
        "",
        "is", // 220 (0xdc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "record", // 639 (0x27f)
        "or", // 225 (0xe1)
        "select", // 640 (0x280)
        "",
        "",
        "",
        "subtype", // 780 (0x30c)
        "",
        "",
        "",
        "digits", // 644 (0x284)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "begin", // 517 (0x205)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "delta", // 522 (0x20a)
        "",
        "others", // 661 (0x295)
        "",
        "",
        "",
        "range", // 525 (0x20d)
        "",
        "",
        "",
        "delay", // 527 (0x20f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "elsif", // 531 (0x213)
        "",
        "raise", // 532 (0x214)
        "",
        "",
        "",
        "return", // 672 (0x2a0)
        "",
        "",
        "",
        "abort", // 536 (0x218)
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
        "",
        "",
        "array", // 543 (0x21f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 412 (0x19c)
        "",
        "",
        "",
    };
    static int values[276] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 969 (0x3c9)
        23, // 969 (0x3c9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 975 (0x3cf)
        -1,
        28, // 562 (0x232)
        -1,
        0, // 425 (0x1a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 430 (0x1ae)
        -1,
        12, // 431 (0x1af)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 434 (0x1b2)
        -1,
        51, // 435 (0x1b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 853 (0x355)
        -1,
        22, // 716 (0x2cc)
        -1,
        60, // 441 (0x1b9)
        -1,
        1, // 442 (0x1ba)
        49, // 442 (0x1ba)
        50, // 443 (0x1bb)
        -1,
        7, // 720 (0x2d0)
        62, // 444 (0x1bc)
        35, // 307 (0x133)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 310 (0x136)
        -1,
        8, // 311 (0x137)
        -1,
        3, // 450 (0x1c2)
        -1,
        47, // 313 (0x139)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 870 (0x366)
        -1,
        61, // 733 (0x2dd)
        -1,
        56, // 320 (0x140)
        -1,
        -1,
        -1,
        31, // 874 (0x36a)
        -1,
        -1,
        -1,
        55, // 324 (0x144)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 327 (0x147)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 330 (0x14a)
        48, // 744 (0x2e8)
        -1,
        -1,
        -1,
        -1,
        17, // 747 (0x2eb)
        41, // 333 (0x14d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 337 (0x151)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 344 (0x158)
        -1,
        54, // 207 (0xcf)
        59, // 345 (0x159)
        -1,
        -1,
        -1,
        -1,
        34, // 624 (0x270)
        -1,
        24, // 763 (0x2fb)
        43, // 211 (0xd3)
        6, // 764 (0x2fc)
        37, // 626 (0x272)
        32, // 213 (0xd5)
        45, // 213 (0xd5)
        -1,
        -1,
        52, // 215 (0xd7)
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 632 (0x278)
        -1,
        -1,
        -1,
        53, // 220 (0xdc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 639 (0x27f)
        46, // 225 (0xe1)
        15, // 640 (0x280)
        -1,
        -1,
        -1,
        18, // 780 (0x30c)
        -1,
        -1,
        -1,
        16, // 644 (0x284)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        57, // 517 (0x205)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 522 (0x20a)
        -1,
        44, // 661 (0x295)
        -1,
        -1,
        -1,
        5, // 525 (0x20d)
        -1,
        -1,
        -1,
        29, // 527 (0x20f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 531 (0x213)
        -1,
        4, // 532 (0x214)
        -1,
        -1,
        -1,
        13, // 672 (0x2a0)
        -1,
        -1,
        -1,
        33, // 536 (0x218)
        -1,
        25, // 537 (0x219)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 543 (0x21f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 412 (0x19c)
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

//check: name=check_ada_hash_sum0, dataset=ada, hash=hash_sum0
void check_ada_hash_sum0() {
    assert(lookup_ada_hash_sum0("terminate") == 2);
    assert(lookup_ada_hash_sum0("procedure") == 23);
    assert(lookup_ada_hash_sum0("exception") == 10);
    assert(lookup_ada_hash_sum0("entry") == 28);
    assert(lookup_ada_hash_sum0("else") == 0);
    assert(lookup_ada_hash_sum0("body") == 58);
    assert(lookup_ada_hash_sum0("then") == 12);
    assert(lookup_ada_hash_sum0("when") == 26);
    assert(lookup_ada_hash_sum0("task") == 51);
    assert(lookup_ada_hash_sum0("separate") == 14);
    assert(lookup_ada_hash_sum0("package") == 22);
    assert(lookup_ada_hash_sum0("goto") == 60);
    assert(lookup_ada_hash_sum0("exit") == 1);
    assert(lookup_ada_hash_sum0("loop") == 49);
    assert(lookup_ada_hash_sum0("null") == 50);
    assert(lookup_ada_hash_sum0("declare") == 7);
    assert(lookup_ada_hash_sum0("with") == 62);
    assert(lookup_ada_hash_sum0("and") == 35);
    assert(lookup_ada_hash_sum0("abs") == 38);
    assert(lookup_ada_hash_sum0("end") == 8);
    assert(lookup_ada_hash_sum0("type") == 3);
    assert(lookup_ada_hash_sum0("all") == 47);
    assert(lookup_ada_hash_sum0("function") == 20);
    assert(lookup_ada_hash_sum0("generic") == 61);
    assert(lookup_ada_hash_sum0("mod") == 56);
    assert(lookup_ada_hash_sum0("constant") == 31);
    assert(lookup_ada_hash_sum0("rem") == 55);
    assert(lookup_ada_hash_sum0("for") == 21);
    assert(lookup_ada_hash_sum0("new") == 27);
    assert(lookup_ada_hash_sum0("limited") == 48);
    assert(lookup_ada_hash_sum0("renames") == 17);
    assert(lookup_ada_hash_sum0("use") == 41);
    assert(lookup_ada_hash_sum0("not") == 11);
    assert(lookup_ada_hash_sum0("out") == 42);
    assert(lookup_ada_hash_sum0("if") == 54);
    assert(lookup_ada_hash_sum0("xor") == 59);
    assert(lookup_ada_hash_sum0("accept") == 34);
    assert(lookup_ada_hash_sum0("private") == 24);
    assert(lookup_ada_hash_sum0("do") == 43);
    assert(lookup_ada_hash_sum0("reverse") == 6);
    assert(lookup_ada_hash_sum0("access") == 37);
    assert(lookup_ada_hash_sum0("at") == 32);
    assert(lookup_ada_hash_sum0("of") == 45);
    assert(lookup_ada_hash_sum0("in") == 52);
    assert(lookup_ada_hash_sum0("pragma") == 39);
    assert(lookup_ada_hash_sum0("is") == 53);
    assert(lookup_ada_hash_sum0("record") == 9);
    assert(lookup_ada_hash_sum0("or") == 46);
    assert(lookup_ada_hash_sum0("select") == 15);
    assert(lookup_ada_hash_sum0("subtype") == 18);
    assert(lookup_ada_hash_sum0("digits") == 16);
    assert(lookup_ada_hash_sum0("begin") == 57);
    assert(lookup_ada_hash_sum0("delta") == 36);
    assert(lookup_ada_hash_sum0("others") == 44);
    assert(lookup_ada_hash_sum0("range") == 5);
    assert(lookup_ada_hash_sum0("delay") == 29);
    assert(lookup_ada_hash_sum0("elsif") == 19);
    assert(lookup_ada_hash_sum0("raise") == 4);
    assert(lookup_ada_hash_sum0("return") == 13);
    assert(lookup_ada_hash_sum0("abort") == 33);
    assert(lookup_ada_hash_sum0("while") == 25);
    assert(lookup_ada_hash_sum0("array") == 40);
    assert(lookup_ada_hash_sum0("case") == 30);
}

//lookup: name=lookup_ada_hash_sumN, dataset=ada, hash=hash_sumN
int lookup_ada_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 140) * 2;
    static std::string_view lookup[280] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "exception", // 984 (0x3d8)
        "",
        "",
        "",
        "",
        "",
        "entry", // 567 (0x237)
        "",
        "",
        "",
        "else", // 429 (0x1ad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "body", // 434 (0x1b2)
        "",
        "then", // 435 (0x1b3)
        "",
        "",
        "",
        "",
        "",
        "when", // 438 (0x1b6)
        "",
        "task", // 439 (0x1b7)
        "",
        "",
        "",
        "separate", // 861 (0x35d)
        "",
        "",
        "",
        "package", // 723 (0x2d3)
        "",
        "",
        "",
        "goto", // 445 (0x1bd)
        "",
        "exit", // 446 (0x1be)
        "loop", // 446 (0x1be)
        "declare", // 727 (0x2d7)
        "null", // 447 (0x1bf)
        "with", // 448 (0x1c0)
        "",
        "",
        "",
        "and", // 310 (0x136)
        "",
        "",
        "",
        "",
        "",
        "abs", // 313 (0x139)
        "",
        "type", // 454 (0x1c6)
        "end", // 314 (0x13a)
        "",
        "",
        "all", // 316 (0x13c)
        "",
        "",
        "",
        "function", // 878 (0x36e)
        "",
        "",
        "",
        "generic", // 740 (0x2e4)
        "",
        "",
        "",
        "constant", // 882 (0x372)
        "",
        "mod", // 323 (0x143)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "rem", // 327 (0x147)
        "",
        "",
        "",
        "",
        "",
        "for", // 330 (0x14a)
        "",
        "limited", // 751 (0x2ef)
        "",
        "",
        "",
        "new", // 333 (0x14d)
        "",
        "renames", // 754 (0x2f2)
        "",
        "",
        "",
        "use", // 336 (0x150)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "not", // 340 (0x154)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "out", // 347 (0x15b)
        "",
        "xor", // 348 (0x15c)
        "",
        "if", // 209 (0xd1)
        "",
        "private", // 770 (0x302)
        "accept", // 630 (0x276)
        "reverse", // 771 (0x303)
        "",
        "access", // 632 (0x278)
        "",
        "do", // 213 (0xd5)
        "",
        "",
        "",
        "at", // 215 (0xd7)
        "of", // 215 (0xd7)
        "",
        "",
        "in", // 217 (0xd9)
        "",
        "pragma", // 638 (0x27e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "is", // 222 (0xde)
        "",
        "",
        "",
        "",
        "",
        "record", // 645 (0x285)
        "",
        "select", // 646 (0x286)
        "",
        "subtype", // 787 (0x313)
        "or", // 227 (0xe3)
        "",
        "",
        "",
        "",
        "digits", // 650 (0x28a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "begin", // 522 (0x20a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "delta", // 527 (0x20f)
        "others", // 667 (0x29b)
        "",
        "",
        "",
        "",
        "range", // 530 (0x212)
        "",
        "",
        "",
        "delay", // 532 (0x214)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "elsif", // 536 (0x218)
        "",
        "raise", // 537 (0x219)
        "",
        "return", // 678 (0x2a6)
        "",
        "",
        "",
        "",
        "",
        "abort", // 541 (0x21d)
        "",
        "while", // 542 (0x21e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "array", // 548 (0x224)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 416 (0x1a0)
        "",
        "",
        "",
        "terminate", // 978 (0x3d2)
        "procedure", // 978 (0x3d2)
        "",
        "",
    };
    static int values[280] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 984 (0x3d8)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 567 (0x237)
        -1,
        -1,
        -1,
        0, // 429 (0x1ad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 434 (0x1b2)
        -1,
        12, // 435 (0x1b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 438 (0x1b6)
        -1,
        51, // 439 (0x1b7)
        -1,
        -1,
        -1,
        14, // 861 (0x35d)
        -1,
        -1,
        -1,
        22, // 723 (0x2d3)
        -1,
        -1,
        -1,
        60, // 445 (0x1bd)
        -1,
        1, // 446 (0x1be)
        49, // 446 (0x1be)
        7, // 727 (0x2d7)
        50, // 447 (0x1bf)
        62, // 448 (0x1c0)
        -1,
        -1,
        -1,
        35, // 310 (0x136)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 313 (0x139)
        -1,
        3, // 454 (0x1c6)
        8, // 314 (0x13a)
        -1,
        -1,
        47, // 316 (0x13c)
        -1,
        -1,
        -1,
        20, // 878 (0x36e)
        -1,
        -1,
        -1,
        61, // 740 (0x2e4)
        -1,
        -1,
        -1,
        31, // 882 (0x372)
        -1,
        56, // 323 (0x143)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 327 (0x147)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 330 (0x14a)
        -1,
        48, // 751 (0x2ef)
        -1,
        -1,
        -1,
        27, // 333 (0x14d)
        -1,
        17, // 754 (0x2f2)
        -1,
        -1,
        -1,
        41, // 336 (0x150)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 340 (0x154)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 347 (0x15b)
        -1,
        59, // 348 (0x15c)
        -1,
        54, // 209 (0xd1)
        -1,
        24, // 770 (0x302)
        34, // 630 (0x276)
        6, // 771 (0x303)
        -1,
        37, // 632 (0x278)
        -1,
        43, // 213 (0xd5)
        -1,
        -1,
        -1,
        32, // 215 (0xd7)
        45, // 215 (0xd7)
        -1,
        -1,
        52, // 217 (0xd9)
        -1,
        39, // 638 (0x27e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 222 (0xde)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 645 (0x285)
        -1,
        15, // 646 (0x286)
        -1,
        18, // 787 (0x313)
        46, // 227 (0xe3)
        -1,
        -1,
        -1,
        -1,
        16, // 650 (0x28a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        57, // 522 (0x20a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 527 (0x20f)
        44, // 667 (0x29b)
        -1,
        -1,
        -1,
        -1,
        5, // 530 (0x212)
        -1,
        -1,
        -1,
        29, // 532 (0x214)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 536 (0x218)
        -1,
        4, // 537 (0x219)
        -1,
        13, // 678 (0x2a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 541 (0x21d)
        -1,
        25, // 542 (0x21e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 548 (0x224)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 416 (0x1a0)
        -1,
        -1,
        -1,
        2, // 978 (0x3d2)
        23, // 978 (0x3d2)
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

//check: name=check_ada_hash_sumN, dataset=ada, hash=hash_sumN
void check_ada_hash_sumN() {
    assert(lookup_ada_hash_sumN("exception") == 10);
    assert(lookup_ada_hash_sumN("entry") == 28);
    assert(lookup_ada_hash_sumN("else") == 0);
    assert(lookup_ada_hash_sumN("body") == 58);
    assert(lookup_ada_hash_sumN("then") == 12);
    assert(lookup_ada_hash_sumN("when") == 26);
    assert(lookup_ada_hash_sumN("task") == 51);
    assert(lookup_ada_hash_sumN("separate") == 14);
    assert(lookup_ada_hash_sumN("package") == 22);
    assert(lookup_ada_hash_sumN("goto") == 60);
    assert(lookup_ada_hash_sumN("exit") == 1);
    assert(lookup_ada_hash_sumN("loop") == 49);
    assert(lookup_ada_hash_sumN("declare") == 7);
    assert(lookup_ada_hash_sumN("null") == 50);
    assert(lookup_ada_hash_sumN("with") == 62);
    assert(lookup_ada_hash_sumN("and") == 35);
    assert(lookup_ada_hash_sumN("abs") == 38);
    assert(lookup_ada_hash_sumN("type") == 3);
    assert(lookup_ada_hash_sumN("end") == 8);
    assert(lookup_ada_hash_sumN("all") == 47);
    assert(lookup_ada_hash_sumN("function") == 20);
    assert(lookup_ada_hash_sumN("generic") == 61);
    assert(lookup_ada_hash_sumN("constant") == 31);
    assert(lookup_ada_hash_sumN("mod") == 56);
    assert(lookup_ada_hash_sumN("rem") == 55);
    assert(lookup_ada_hash_sumN("for") == 21);
    assert(lookup_ada_hash_sumN("limited") == 48);
    assert(lookup_ada_hash_sumN("new") == 27);
    assert(lookup_ada_hash_sumN("renames") == 17);
    assert(lookup_ada_hash_sumN("use") == 41);
    assert(lookup_ada_hash_sumN("not") == 11);
    assert(lookup_ada_hash_sumN("out") == 42);
    assert(lookup_ada_hash_sumN("xor") == 59);
    assert(lookup_ada_hash_sumN("if") == 54);
    assert(lookup_ada_hash_sumN("private") == 24);
    assert(lookup_ada_hash_sumN("accept") == 34);
    assert(lookup_ada_hash_sumN("reverse") == 6);
    assert(lookup_ada_hash_sumN("access") == 37);
    assert(lookup_ada_hash_sumN("do") == 43);
    assert(lookup_ada_hash_sumN("at") == 32);
    assert(lookup_ada_hash_sumN("of") == 45);
    assert(lookup_ada_hash_sumN("in") == 52);
    assert(lookup_ada_hash_sumN("pragma") == 39);
    assert(lookup_ada_hash_sumN("is") == 53);
    assert(lookup_ada_hash_sumN("record") == 9);
    assert(lookup_ada_hash_sumN("select") == 15);
    assert(lookup_ada_hash_sumN("subtype") == 18);
    assert(lookup_ada_hash_sumN("or") == 46);
    assert(lookup_ada_hash_sumN("digits") == 16);
    assert(lookup_ada_hash_sumN("begin") == 57);
    assert(lookup_ada_hash_sumN("delta") == 36);
    assert(lookup_ada_hash_sumN("others") == 44);
    assert(lookup_ada_hash_sumN("range") == 5);
    assert(lookup_ada_hash_sumN("delay") == 29);
    assert(lookup_ada_hash_sumN("elsif") == 19);
    assert(lookup_ada_hash_sumN("raise") == 4);
    assert(lookup_ada_hash_sumN("return") == 13);
    assert(lookup_ada_hash_sumN("abort") == 33);
    assert(lookup_ada_hash_sumN("while") == 25);
    assert(lookup_ada_hash_sumN("array") == 40);
    assert(lookup_ada_hash_sumN("case") == 30);
    assert(lookup_ada_hash_sumN("terminate") == 2);
    assert(lookup_ada_hash_sumN("procedure") == 23);
}

//lookup: name=lookup_ada_hash_djb2, dataset=ada, hash=hash_djb2
int lookup_ada_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 457) * 1;
    static std::string_view lookup[457] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "exit", // 6503796899 (0x183a810a3)
        "mod", // 197093161 (0xbbf6729)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "of", // 5972574 (0x5b225e)
        "",
        "when", // 6504426203 (0x183b1aadb)
        "",
        "",
        "",
        "",
        "others", // 7083021384862 (0x67124f93c9e)
        "select", // 7083160280873 (0x6712d409f29)
        "at", // 5972126 (0x5b209e)
        "",
        "",
        "or", // 5972586 (0x5b226a)
        "",
        "",
        "",
        "",
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
        "else", // 6503784146 (0x183a7ded2)
        "",
        "generic", // 233728794041094 (0xd49339be1b06)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "then", // 6504318392 (0x183b005b8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "digits", // 7082577818893 (0x6710a88f50d)
        "",
        "",
        "",
        "",
        "",
        "subtype", // 233744904138869 (0xd496f9fab075)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "reverse", // 233743009676453 (0xd496890f7ca5)
        "",
        "all", // 197080002 (0xbbf33c2)
        "delta", // 214623432307 (0x31f88dae73)
        "",
        "rem", // 197098285 (0xbbf7b2d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "out", // 197095553 (0xbbf7081)
        "",
        "",
        "",
        "xor", // 197105154 (0xbbf9602)
        "",
        "",
        "",
        "do", // 5972220 (0x5b20fc)
        "separate", // 7713561698190878 (0x1b677188f9461e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "body", // 6503679127 (0x183a64497)
        "",
        "",
        "",
        "",
        "",
        "abort", // 214619769953 (0x31f855cc61)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "limited", // 233735406882385 (0xd494c3e60e51)
        "and", // 197080060 (0xbbf33fc)
        "",
        "",
        "",
        "",
        "constant", // 7712892660930419 (0x1b66d5c33ed773)
        "",
        "",
        "for", // 197085552 (0xbbf4970)
        "",
        "use", // 197102006 (0xbbf89b6)
        "pragma", // 7083057898849 (0x67127266561)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "not", // 197094266 (0xbbf6b7a)
        "",
        "",
        "array", // 214620347656 (0x31f85e9d08)
        "accept", // 7082453148953 (0x671031aa519)
        "",
        "",
        "loop", // 6504038851 (0x183abc1c3)
        "",
        "",
        "",
        "",
        "task", // 6504311228 (0x183afe9bc)
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
        "terminate", // 254548945491251666 (0x38856ead1f4d1d2)
        "",
        "",
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
        "abs", // 197079679 (0xbbf327f)
        "begin", // 214621054670 (0x31f86966ce)
        "function", // 7713028246101167 (0x1b66f554c05caf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "elsif", // 214624877052 (0x31f8a3b9fc)
        "",
        "",
        "exception", // 254528639435817560 (0x3884472f2bc4258)
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
        "case", // 6503700293 (0x183a69745)
        "goto", // 6503859330 (0x183a90482)
        "in", // 5972384 (0x5b21a0)
        "",
        "",
        "",
        "",
        "is", // 5972389 (0x5b21a5)
        "",
        "",
        "",
        "",
        "raise", // 214639888157 (0x31f988c71d)
        "",
        "",
        "",
        "access", // 7082453149051 (0x671031aa57b)
        "",
        "",
        "",
        "while", // 214646069090 (0x31f9e71762)
        "",
        "renames", // 233743000039444 (0xd496887c7014)
        "",
        "",
        "declare", // 233724906825401 (0xd492520be6b9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "range", // 214639893206 (0x31f988dad6)
        "",
        "",
        "",
        "procedure", // 254543869625698226 (0x388524d00cb07b2)
        "",
        "",
        "",
        "",
        "",
        "new", // 197093939 (0xbbf6a33)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "record", // 7083120833416 (0x6712ae6b388)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "null", // 6504117156 (0x183acf3a4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "end", // 197084416 (0xbbf4500)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "delay", // 214623431704 (0x31f88dac18)
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
        "",
        "",
        "",
        "entry", // 214624950331 (0x31f8a4d83b)
        "",
        "",
        "",
        "",
        "",
    };
    static int values[457] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 6503796899 (0x183a810a3)
        56, // 197093161 (0xbbf6729)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 5972574 (0x5b225e)
        -1,
        26, // 6504426203 (0x183b1aadb)
        -1,
        -1,
        -1,
        -1,
        44, // 7083021384862 (0x67124f93c9e)
        15, // 7083160280873 (0x6712d409f29)
        32, // 5972126 (0x5b209e)
        -1,
        -1,
        46, // 5972586 (0x5b226a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 233740247863157 (0xd495e4718f75)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 6503784146 (0x183a7ded2)
        -1,
        61, // 233728794041094 (0xd49339be1b06)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 6504318392 (0x183b005b8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 7082577818893 (0x6710a88f50d)
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 233744904138869 (0xd496f9fab075)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 233743009676453 (0xd496890f7ca5)
        -1,
        47, // 197080002 (0xbbf33c2)
        36, // 214623432307 (0x31f88dae73)
        -1,
        55, // 197098285 (0xbbf7b2d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 197095553 (0xbbf7081)
        -1,
        -1,
        -1,
        59, // 197105154 (0xbbf9602)
        -1,
        -1,
        -1,
        43, // 5972220 (0x5b20fc)
        14, // 7713561698190878 (0x1b677188f9461e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 6503679127 (0x183a64497)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 214619769953 (0x31f855cc61)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 233735406882385 (0xd494c3e60e51)
        35, // 197080060 (0xbbf33fc)
        -1,
        -1,
        -1,
        -1,
        31, // 7712892660930419 (0x1b66d5c33ed773)
        -1,
        -1,
        21, // 197085552 (0xbbf4970)
        -1,
        41, // 197102006 (0xbbf89b6)
        39, // 7083057898849 (0x67127266561)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 6504337259 (0x183b04f6b)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 197094266 (0xbbf6b7a)
        -1,
        -1,
        40, // 214620347656 (0x31f85e9d08)
        34, // 7082453148953 (0x671031aa519)
        -1,
        -1,
        49, // 6504038851 (0x183abc1c3)
        -1,
        -1,
        -1,
        -1,
        51, // 6504311228 (0x183afe9bc)
        -1,
        -1,
        -1,
        -1,
        24, // 233740920676100 (0xd4960c8bdf04)
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 254548945491251666 (0x38856ead1f4d1d2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        62, // 6504427781 (0x183b1b105)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 197079679 (0xbbf327f)
        57, // 214621054670 (0x31f86966ce)
        20, // 7713028246101167 (0x1b66f554c05caf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 214624877052 (0x31f8a3b9fc)
        -1,
        -1,
        10, // 254528639435817560 (0x3884472f2bc4258)
        -1,
        -1,
        -1,
        -1,
        54, // 5972376 (0x5b2198)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 6503700293 (0x183a69745)
        60, // 6503859330 (0x183a90482)
        52, // 5972384 (0x5b21a0)
        -1,
        -1,
        -1,
        -1,
        53, // 5972389 (0x5b21a5)
        -1,
        -1,
        -1,
        -1,
        4, // 214639888157 (0x31f988c71d)
        -1,
        -1,
        -1,
        37, // 7082453149051 (0x671031aa57b)
        -1,
        -1,
        -1,
        25, // 214646069090 (0x31f9e71762)
        -1,
        17, // 233743000039444 (0xd496887c7014)
        -1,
        -1,
        7, // 233724906825401 (0xd492520be6b9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 214639893206 (0x31f988dad6)
        -1,
        -1,
        -1,
        23, // 254543869625698226 (0x388524d00cb07b2)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 197093939 (0xbbf6a33)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 7083120833416 (0x6712ae6b388)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 6504117156 (0x183acf3a4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 197084416 (0xbbf4500)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 214623431704 (0x31f88dac18)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 7083121450889 (0x6712af01f89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 214624950331 (0x31f8a4d83b)
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

//check: name=check_ada_hash_djb2, dataset=ada, hash=hash_djb2
void check_ada_hash_djb2() {
    assert(lookup_ada_hash_djb2("exit") == 1);
    assert(lookup_ada_hash_djb2("mod") == 56);
    assert(lookup_ada_hash_djb2("of") == 45);
    assert(lookup_ada_hash_djb2("when") == 26);
    assert(lookup_ada_hash_djb2("others") == 44);
    assert(lookup_ada_hash_djb2("select") == 15);
    assert(lookup_ada_hash_djb2("at") == 32);
    assert(lookup_ada_hash_djb2("or") == 46);
    assert(lookup_ada_hash_djb2("package") == 22);
    assert(lookup_ada_hash_djb2("else") == 0);
    assert(lookup_ada_hash_djb2("generic") == 61);
    assert(lookup_ada_hash_djb2("then") == 12);
    assert(lookup_ada_hash_djb2("digits") == 16);
    assert(lookup_ada_hash_djb2("subtype") == 18);
    assert(lookup_ada_hash_djb2("reverse") == 6);
    assert(lookup_ada_hash_djb2("all") == 47);
    assert(lookup_ada_hash_djb2("delta") == 36);
    assert(lookup_ada_hash_djb2("rem") == 55);
    assert(lookup_ada_hash_djb2("out") == 42);
    assert(lookup_ada_hash_djb2("xor") == 59);
    assert(lookup_ada_hash_djb2("do") == 43);
    assert(lookup_ada_hash_djb2("separate") == 14);
    assert(lookup_ada_hash_djb2("body") == 58);
    assert(lookup_ada_hash_djb2("abort") == 33);
    assert(lookup_ada_hash_djb2("limited") == 48);
    assert(lookup_ada_hash_djb2("and") == 35);
    assert(lookup_ada_hash_djb2("constant") == 31);
    assert(lookup_ada_hash_djb2("for") == 21);
    assert(lookup_ada_hash_djb2("use") == 41);
    assert(lookup_ada_hash_djb2("pragma") == 39);
    assert(lookup_ada_hash_djb2("type") == 3);
    assert(lookup_ada_hash_djb2("not") == 11);
    assert(lookup_ada_hash_djb2("array") == 40);
    assert(lookup_ada_hash_djb2("accept") == 34);
    assert(lookup_ada_hash_djb2("loop") == 49);
    assert(lookup_ada_hash_djb2("task") == 51);
    assert(lookup_ada_hash_djb2("private") == 24);
    assert(lookup_ada_hash_djb2("terminate") == 2);
    assert(lookup_ada_hash_djb2("with") == 62);
    assert(lookup_ada_hash_djb2("abs") == 38);
    assert(lookup_ada_hash_djb2("begin") == 57);
    assert(lookup_ada_hash_djb2("function") == 20);
    assert(lookup_ada_hash_djb2("elsif") == 19);
    assert(lookup_ada_hash_djb2("exception") == 10);
    assert(lookup_ada_hash_djb2("if") == 54);
    assert(lookup_ada_hash_djb2("case") == 30);
    assert(lookup_ada_hash_djb2("goto") == 60);
    assert(lookup_ada_hash_djb2("in") == 52);
    assert(lookup_ada_hash_djb2("is") == 53);
    assert(lookup_ada_hash_djb2("raise") == 4);
    assert(lookup_ada_hash_djb2("access") == 37);
    assert(lookup_ada_hash_djb2("while") == 25);
    assert(lookup_ada_hash_djb2("renames") == 17);
    assert(lookup_ada_hash_djb2("declare") == 7);
    assert(lookup_ada_hash_djb2("range") == 5);
    assert(lookup_ada_hash_djb2("procedure") == 23);
    assert(lookup_ada_hash_djb2("new") == 27);
    assert(lookup_ada_hash_djb2("record") == 9);
    assert(lookup_ada_hash_djb2("null") == 50);
    assert(lookup_ada_hash_djb2("end") == 8);
    assert(lookup_ada_hash_djb2("delay") == 29);
    assert(lookup_ada_hash_djb2("return") == 13);
    assert(lookup_ada_hash_djb2("entry") == 28);
}

//lookup: name=lookup_ada_hash_sdb, dataset=ada, hash=hash_sdb
int lookup_ada_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 534) * 1;
    static std::string_view lookup[534] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "constant", // 6848661134469900296 (0x5f0b55041b1a2808)
        "separate", // 18086001717932494911 (0xfafe62bd1c78903f)
        "",
        "",
        "",
        "delay", // 366226506441043891 (0x515191137c02fb3)
        "",
        "",
        "exit", // 28433392401911950 (0x6504050de0108e)
        "",
        "",
        "",
        "",
        "",
        "digits", // 2917069936268906626 (0x287b83a6d8479082)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "reverse", // 1867204366169856574 (0x19e9a47a689cda3e)
        "in", // 6881705 (0x6901a9)
        "",
        "",
        "",
        "",
        "is", // 6881710 (0x6901ae)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "elsif", // 371575063597232389 (0x528198d391b3105)
        "",
        "",
        "",
        "others", // 3233181664223141471 (0x2cde9197ee539e5f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "subtype", // 2361212694669486014 (0x20c4b66f80eae7be)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "at", // 6357399 (0x610197)
        "",
        "",
        "",
        "and", // 416657179927 (0x6102b40517)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "declare", // 18123714378165562494 (0xfb845e341132ac7e)
        "renames", // 1839054836912674561 (0x1985a2a164a4d701)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "limited", // 1027254439249103470 (0xe418a784962ca6e)
        "begin", // 359470621653085937 (0x4fd18a036d22ef1)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "procedure", // 4771092501595672255 (0x4236535a1423cebf)
        "",
        "",
        "",
        "terminate", // 10444314889610648033 (0x90f1a90e4590d9e1)
        "",
        "",
        "accept", // 2819674551904406312 (0x27217f10d0788b28)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "end", // 433838622011 (0x6502cc053b)
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
        "pragma", // 3249789121641225700 (0x2d1991fcee5a9de4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "function", // 10100634927348600308 (0x8c2ca9f372844df4)
        "of", // 7274931 (0x6f01b3)
        "loop", // 30403949176361224 (0x6c043b0e6d1108)
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
        "or", // 7274943 (0x6f01bf)
        "abs", // 416656393474 (0x6102a80502)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "mod", // 468201571718 (0x6d02fd0586)
        "",
        "",
        "",
        "new", // 472496276868 (0x6e02f90584)
        "",
        "out", // 476792686010 (0x6f030f05ba)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "access", // 2819674551904602928 (0x27217f10d07b8b30)
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
        "",
        "",
        "",
        "",
        "",
        "when", // 33500569073226194 (0x7704970f6211d2)
        "range", // 412391503681172421 (0x5b91be33d4e33c5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "array", // 359752414477103189 (0x4fe18ea37ff3055)
        "",
        "exception", // 2586519583193025679 (0x23e529db60cfcc8f)
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
        "generic", // 168162147972200515 (0x2556e95268cb843)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "rem", // 489677718942 (0x720311059e)
        "",
        "",
        "",
        "select", // 3284974374203989420 (0x2d9692c9eeb09dac)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "then", // 32656028173668737 (0x74047c0f111181)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "xor", // 515450537463 (0x78033f05f7)
        "",
        "",
        "type", // 32656101195518514 (0x74048d0f821232)
        "",
        "",
        "",
        "",
        "",
        "",
        "record", // 3257106886888234045 (0x2d339174ec739c3d)
        "",
        "use", // 502564718043 (0x75033105db)
        "",
        "else", // 28433340858241073 (0x6503f90da21031)
        "",
        "all", // 416657048857 (0x6102b20519)
        "",
        "",
        "",
        "private", // 1853414300009618939 (0x19b8a67c6db3ddfb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "not", // 472496932255 (0x6e0303059f)
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
        "body", // 27588812843782114 (0x6203e10d540fe2)
        "",
        "",
        "",
        "",
        "",
        "abort", // 355248183461162680 (0x4ee1857364e2eb8)
        "",
        "with", // 33500573369569794 (0x7704980f771202)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "delta", // 366226506442289108 (0x515191137d32fd4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "task", // 32655998107062633 (0x7404750ef51169)
        "raise", // 412391482205156284 (0x5b91bde3d3c33bc)
        "",
        "",
        "",
        "",
        "",
        "",
        "null", // 30967002214699367 (0x6e04530ec41167)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "entry", // 372138095159554418 (0x52a19a039603172)
        "",
        "",
        "",
        "",
        "",
        "",
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
    static int values[534] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 6848661134469900296 (0x5f0b55041b1a2808)
        14, // 18086001717932494911 (0xfafe62bd1c78903f)
        -1,
        -1,
        -1,
        29, // 366226506441043891 (0x515191137c02fb3)
        -1,
        -1,
        1, // 28433392401911950 (0x6504050de0108e)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 2917069936268906626 (0x287b83a6d8479082)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 6881697 (0x6901a1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 1867204366169856574 (0x19e9a47a689cda3e)
        52, // 6881705 (0x6901a9)
        -1,
        -1,
        -1,
        -1,
        53, // 6881710 (0x6901ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 371575063597232389 (0x528198d391b3105)
        -1,
        -1,
        -1,
        44, // 3233181664223141471 (0x2cde9197ee539e5f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 431251735916197369 (0x5fc1d2b400e35f9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 2361212694669486014 (0x20c4b66f80eae7be)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 6357399 (0x610197)
        -1,
        -1,
        -1,
        35, // 416657179927 (0x6102b40517)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 18123714378165562494 (0xfb845e341132ac7e)
        17, // 1839054836912674561 (0x1985a2a164a4d701)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 1027254439249103470 (0xe418a784962ca6e)
        57, // 359470621653085937 (0x4fd18a036d22ef1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 28996381010759823 (0x67040e0deb108f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 4771092501595672255 (0x4236535a1423cebf)
        -1,
        -1,
        -1,
        2, // 10444314889610648033 (0x90f1a90e4590d9e1)
        -1,
        -1,
        34, // 2819674551904406312 (0x27217f10d0788b28)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 433838622011 (0x6502cc053b)
        -1,
        43, // 6554011 (0x64019b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 3249789121641225700 (0x2d1991fcee5a9de4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 10100634927348600308 (0x8c2ca9f372844df4)
        45, // 7274931 (0x6f01b3)
        49, // 30403949176361224 (0x6c043b0e6d1108)
        -1,
        -1,
        -1,
        -1,
        21, // 438134048085 (0x6602d30555)
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 7274943 (0x6f01bf)
        38, // 416656393474 (0x6102a80502)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        56, // 468201571718 (0x6d02fd0586)
        -1,
        -1,
        -1,
        27, // 472496276868 (0x6e02f90584)
        -1,
        42, // 476792686010 (0x6f030f05ba)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 2819674551904602928 (0x27217f10d07b8b30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 1399373631390272162 (0x136b92e74f10caa2)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 33500569073226194 (0x7704970f6211d2)
        5, // 412391503681172421 (0x5b91be33d4e33c5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 359752414477103189 (0x4fe18ea37ff3055)
        -1,
        10, // 2586519583193025679 (0x23e529db60cfcc8f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 27870266342903704 (0x6303dc0d2a0f98)
        -1,
        -1,
        61, // 168162147972200515 (0x2556e95268cb843)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 489677718942 (0x720311059e)
        -1,
        -1,
        -1,
        15, // 3284974374203989420 (0x2d9692c9eeb09dac)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 32656028173668737 (0x74047c0f111181)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        59, // 515450537463 (0x78033f05f7)
        -1,
        -1,
        3, // 32656101195518514 (0x74048d0f821232)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 3257106886888234045 (0x2d339174ec739c3d)
        -1,
        41, // 502564718043 (0x75033105db)
        -1,
        0, // 28433340858241073 (0x6503f90da21031)
        -1,
        47, // 416657048857 (0x6102b20519)
        -1,
        -1,
        -1,
        24, // 1853414300009618939 (0x19b8a67c6db3ddfb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 472496932255 (0x6e0303059f)
        -1,
        -1,
        13, // 3261892644424556104 (0x2d449213ee629e48)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 27588812843782114 (0x6203e10d540fe2)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 355248183461162680 (0x4ee1857364e2eb8)
        -1,
        62, // 33500573369569794 (0x7704980f771202)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 366226506442289108 (0x515191137d32fd4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 32655998107062633 (0x7404750ef51169)
        4, // 412391482205156284 (0x5b91bde3d3c33bc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 30967002214699367 (0x6e04530ec41167)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 372138095159554418 (0x52a19a039603172)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
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

//check: name=check_ada_hash_sdb, dataset=ada, hash=hash_sdb
void check_ada_hash_sdb() {
    assert(lookup_ada_hash_sdb("constant") == 31);
    assert(lookup_ada_hash_sdb("separate") == 14);
    assert(lookup_ada_hash_sdb("delay") == 29);
    assert(lookup_ada_hash_sdb("exit") == 1);
    assert(lookup_ada_hash_sdb("digits") == 16);
    assert(lookup_ada_hash_sdb("if") == 54);
    assert(lookup_ada_hash_sdb("reverse") == 6);
    assert(lookup_ada_hash_sdb("in") == 52);
    assert(lookup_ada_hash_sdb("is") == 53);
    assert(lookup_ada_hash_sdb("elsif") == 19);
    assert(lookup_ada_hash_sdb("others") == 44);
    assert(lookup_ada_hash_sdb("while") == 25);
    assert(lookup_ada_hash_sdb("subtype") == 18);
    assert(lookup_ada_hash_sdb("at") == 32);
    assert(lookup_ada_hash_sdb("and") == 35);
    assert(lookup_ada_hash_sdb("declare") == 7);
    assert(lookup_ada_hash_sdb("renames") == 17);
    assert(lookup_ada_hash_sdb("limited") == 48);
    assert(lookup_ada_hash_sdb("begin") == 57);
    assert(lookup_ada_hash_sdb("goto") == 60);
    assert(lookup_ada_hash_sdb("procedure") == 23);
    assert(lookup_ada_hash_sdb("terminate") == 2);
    assert(lookup_ada_hash_sdb("accept") == 34);
    assert(lookup_ada_hash_sdb("end") == 8);
    assert(lookup_ada_hash_sdb("do") == 43);
    assert(lookup_ada_hash_sdb("pragma") == 39);
    assert(lookup_ada_hash_sdb("function") == 20);
    assert(lookup_ada_hash_sdb("of") == 45);
    assert(lookup_ada_hash_sdb("loop") == 49);
    assert(lookup_ada_hash_sdb("for") == 21);
    assert(lookup_ada_hash_sdb("or") == 46);
    assert(lookup_ada_hash_sdb("abs") == 38);
    assert(lookup_ada_hash_sdb("mod") == 56);
    assert(lookup_ada_hash_sdb("new") == 27);
    assert(lookup_ada_hash_sdb("out") == 42);
    assert(lookup_ada_hash_sdb("access") == 37);
    assert(lookup_ada_hash_sdb("package") == 22);
    assert(lookup_ada_hash_sdb("when") == 26);
    assert(lookup_ada_hash_sdb("range") == 5);
    assert(lookup_ada_hash_sdb("array") == 40);
    assert(lookup_ada_hash_sdb("exception") == 10);
    assert(lookup_ada_hash_sdb("case") == 30);
    assert(lookup_ada_hash_sdb("generic") == 61);
    assert(lookup_ada_hash_sdb("rem") == 55);
    assert(lookup_ada_hash_sdb("select") == 15);
    assert(lookup_ada_hash_sdb("then") == 12);
    assert(lookup_ada_hash_sdb("xor") == 59);
    assert(lookup_ada_hash_sdb("type") == 3);
    assert(lookup_ada_hash_sdb("record") == 9);
    assert(lookup_ada_hash_sdb("use") == 41);
    assert(lookup_ada_hash_sdb("else") == 0);
    assert(lookup_ada_hash_sdb("all") == 47);
    assert(lookup_ada_hash_sdb("private") == 24);
    assert(lookup_ada_hash_sdb("not") == 11);
    assert(lookup_ada_hash_sdb("return") == 13);
    assert(lookup_ada_hash_sdb("body") == 58);
    assert(lookup_ada_hash_sdb("abort") == 33);
    assert(lookup_ada_hash_sdb("with") == 62);
    assert(lookup_ada_hash_sdb("delta") == 36);
    assert(lookup_ada_hash_sdb("task") == 51);
    assert(lookup_ada_hash_sdb("raise") == 4);
    assert(lookup_ada_hash_sdb("null") == 50);
    assert(lookup_ada_hash_sdb("entry") == 28);
}
