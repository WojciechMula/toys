
//lookup: name=lookup_pascal_hash1, dataset=pascal, type=hash, hash=hash1
int lookup_pascal_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 41) * 2;
    static constexpr const std::string_view lookup[82] = {
        "",
        "",
        "packed", // 1272 (0x4f8)
        "",
        "then", // 904 (0x388)
        "",
        "to", // 454 (0x1c6)
        "",
        "if", // 414 (0x19e)
        "",
        "",
        "",
        "",
        "",
        "type", // 868 (0x364)
        "",
        "",
        "",
        "const", // 1075 (0x433)
        "",
        "",
        "",
        "",
        "",
        "do", // 422 (0x1a6)
        "mod", // 627 (0x273)
        "record", // 1284 (0x504)
        "",
        "label", // 1080 (0x438)
        "",
        "function", // 1696 (0x6a0)
        "begin", // 1040 (0x410)
        "of", // 426 (0x1aa)
        "",
        "and", // 591 (0x24f)
        "",
        "until", // 1125 (0x465)
        "",
        "",
        "",
        "in", // 430 (0x1ae)
        "forward", // 1414 (0x586)
        "case", // 800 (0x320)
        "",
        "not", // 678 (0x2a6)
        "",
        "",
        "",
        "array", // 1090 (0x442)
        "",
        "",
        "",
        "",
        "",
        "repeat", // 1380 (0x564)
        "",
        "",
        "",
        "else", // 808 (0x328)
        "end", // 603 (0x25b)
        "program", // 1547 (0x60b)
        "",
        "with", // 892 (0x37c)
        "procedure", // 1917 (0x77d)
        "",
        "",
        "for", // 648 (0x288)
        "file", // 812 (0x32c)
        "while", // 1100 (0x44c)
        "",
        "",
        "",
        "goto", // 856 (0x358)
        "downto", // 1266 (0x4f2)
        "set", // 693 (0x2b5)
        "",
        "",
        "",
        "nil", // 654 (0x28e)
        "div", // 654 (0x28e)
        "var", // 696 (0x2b8)
        "or", // 450 (0x1c2)
    };
    static constexpr const int values[82] = {
        -1,
        -1,
        14, // 1272 (0x4f8)
        -1,
        8, // 904 (0x388)
        -1,
        30, // 454 (0x1c6)
        -1,
        35, // 414 (0x19e)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 868 (0x364)
        -1,
        -1,
        -1,
        6, // 1075 (0x433)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 422 (0x1a6)
        33, // 627 (0x273)
        10, // 1284 (0x504)
        -1,
        17, // 1080 (0x438)
        -1,
        3, // 1696 (0x6a0)
        34, // 1040 (0x410)
        20, // 426 (0x1aa)
        -1,
        2, // 591 (0x24f)
        -1,
        7, // 1125 (0x465)
        -1,
        -1,
        -1,
        18, // 430 (0x1ae)
        22, // 1414 (0x586)
        4, // 800 (0x320)
        -1,
        15, // 678 (0x2a6)
        -1,
        -1,
        -1,
        1, // 1090 (0x442)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 1380 (0x564)
        -1,
        -1,
        -1,
        26, // 808 (0x328)
        32, // 603 (0x25b)
        11, // 1547 (0x60b)
        -1,
        0, // 892 (0x37c)
        12, // 1917 (0x77d)
        -1,
        -1,
        23, // 648 (0x288)
        25, // 812 (0x32c)
        24, // 1100 (0x44c)
        -1,
        -1,
        -1,
        21, // 856 (0x358)
        27, // 1266 (0x4f2)
        9, // 693 (0x2b5)
        -1,
        -1,
        -1,
        16, // 654 (0x28e)
        29, // 654 (0x28e)
        5, // 696 (0x2b8)
        13, // 450 (0x1c2)
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_pascal_hash1, dataset=pascal, type=hash, hash=hash1
void check_pascal_hash1() {
    assert(lookup_pascal_hash1("packed") == 14);
    assert(lookup_pascal_hash1("then") == 8);
    assert(lookup_pascal_hash1("to") == 30);
    assert(lookup_pascal_hash1("if") == 35);
    assert(lookup_pascal_hash1("type") == 31);
    assert(lookup_pascal_hash1("const") == 6);
    assert(lookup_pascal_hash1("do") == 28);
    assert(lookup_pascal_hash1("mod") == 33);
    assert(lookup_pascal_hash1("record") == 10);
    assert(lookup_pascal_hash1("label") == 17);
    assert(lookup_pascal_hash1("function") == 3);
    assert(lookup_pascal_hash1("begin") == 34);
    assert(lookup_pascal_hash1("of") == 20);
    assert(lookup_pascal_hash1("and") == 2);
    assert(lookup_pascal_hash1("until") == 7);
    assert(lookup_pascal_hash1("in") == 18);
    assert(lookup_pascal_hash1("forward") == 22);
    assert(lookup_pascal_hash1("case") == 4);
    assert(lookup_pascal_hash1("not") == 15);
    assert(lookup_pascal_hash1("array") == 1);
    assert(lookup_pascal_hash1("repeat") == 19);
    assert(lookup_pascal_hash1("else") == 26);
    assert(lookup_pascal_hash1("end") == 32);
    assert(lookup_pascal_hash1("program") == 11);
    assert(lookup_pascal_hash1("with") == 0);
    assert(lookup_pascal_hash1("procedure") == 12);
    assert(lookup_pascal_hash1("for") == 23);
    assert(lookup_pascal_hash1("file") == 25);
    assert(lookup_pascal_hash1("while") == 24);
    assert(lookup_pascal_hash1("goto") == 21);
    assert(lookup_pascal_hash1("downto") == 27);
    assert(lookup_pascal_hash1("set") == 9);
    assert(lookup_pascal_hash1("nil") == 16);
    assert(lookup_pascal_hash1("div") == 29);
    assert(lookup_pascal_hash1("var") == 5);
    assert(lookup_pascal_hash1("or") == 13);
}

//lookup: name=lookup_pascal_hash2, dataset=pascal, type=hash, hash=hash2
int lookup_pascal_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 156) * 1;
    static constexpr const std::string_view lookup[156] = {
        "",
        "",
        "file", // 10298 (0x283a)
        "",
        "in", // 11548 (0x2d1c)
        "",
        "",
        "",
        "",
        "",
        "while", // 12022 (0x2ef6)
        "case", // 9995 (0x270b)
        "type", // 11712 (0x2dc0)
        "begin", // 10777 (0x2a19)
        "",
        "",
        "or", // 12652 (0x316c)
        "",
        "record", // 11406 (0x2c8e)
        "",
        "",
        "",
        "downto", // 11098 (0x2b5a)
        "",
        "",
        "",
        "do", // 11102 (0x2b5e)
        "nil", // 11883 (0x2e6b)
        "",
        "",
        "",
        "and", // 9703 (0x25e7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "var", // 13455 (0x348f)
        "array", // 11740 (0x2ddc)
        "",
        "",
        "",
        "",
        "",
        "",
        "program", // 12215 (0x2fb7)
        "",
        "goto", // 11437 (0x2cad)
        "",
        "",
        "",
        "",
        "",
        "",
        "with", // 12380 (0x305c)
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
        "forward", // 10207 (0x27df)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "set", // 13343 (0x341f)
        "",
        "",
        "to", // 12878 (0x324e)
        "for", // 11631 (0x2d6f)
        "of", // 11320 (0x2c38)
        "procedure", // 11321 (0x2c39)
        "",
        "",
        "",
        "const", // 11481 (0x2cd9)
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 10708 (0x29d4)
        "",
        "",
        "div", // 11803 (0x2e1b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "end", // 10103 (0x2777)
        "",
        "",
        "",
        "",
        "",
        "label", // 11669 (0x2d95)
        "repeat", // 13230 (0x33ae)
        "not", // 12763 (0x31db)
        "then", // 12764 (0x31dc)
        "",
        "packed", // 11206 (0x2bc6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "mod", // 10903 (0x2a97)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "function", // 11228 (0x2bdc)
        "until", // 12633 (0x3159)
        "",
        "",
    };
    static constexpr const int values[156] = {
        -1,
        -1,
        25, // 10298 (0x283a)
        -1,
        18, // 11548 (0x2d1c)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 12022 (0x2ef6)
        4, // 9995 (0x270b)
        31, // 11712 (0x2dc0)
        34, // 10777 (0x2a19)
        -1,
        -1,
        13, // 12652 (0x316c)
        -1,
        10, // 11406 (0x2c8e)
        -1,
        -1,
        -1,
        27, // 11098 (0x2b5a)
        -1,
        -1,
        -1,
        28, // 11102 (0x2b5e)
        16, // 11883 (0x2e6b)
        -1,
        -1,
        -1,
        2, // 9703 (0x25e7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 13455 (0x348f)
        1, // 11740 (0x2ddc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 12215 (0x2fb7)
        -1,
        21, // 11437 (0x2cad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 12380 (0x305c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 10205 (0x27dd)
        -1,
        22, // 10207 (0x27df)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 13343 (0x341f)
        -1,
        -1,
        30, // 12878 (0x324e)
        23, // 11631 (0x2d6f)
        20, // 11320 (0x2c38)
        12, // 11321 (0x2c39)
        -1,
        -1,
        -1,
        6, // 11481 (0x2cd9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 10708 (0x29d4)
        -1,
        -1,
        29, // 11803 (0x2e1b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 10103 (0x2777)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 11669 (0x2d95)
        19, // 13230 (0x33ae)
        15, // 12763 (0x31db)
        8, // 12764 (0x31dc)
        -1,
        14, // 11206 (0x2bc6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 10903 (0x2a97)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 11228 (0x2bdc)
        7, // 12633 (0x3159)
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

//check: name=check_pascal_hash2, dataset=pascal, type=hash, hash=hash2
void check_pascal_hash2() {
    assert(lookup_pascal_hash2("file") == 25);
    assert(lookup_pascal_hash2("in") == 18);
    assert(lookup_pascal_hash2("while") == 24);
    assert(lookup_pascal_hash2("case") == 4);
    assert(lookup_pascal_hash2("type") == 31);
    assert(lookup_pascal_hash2("begin") == 34);
    assert(lookup_pascal_hash2("or") == 13);
    assert(lookup_pascal_hash2("record") == 10);
    assert(lookup_pascal_hash2("downto") == 27);
    assert(lookup_pascal_hash2("do") == 28);
    assert(lookup_pascal_hash2("nil") == 16);
    assert(lookup_pascal_hash2("and") == 2);
    assert(lookup_pascal_hash2("var") == 5);
    assert(lookup_pascal_hash2("array") == 1);
    assert(lookup_pascal_hash2("program") == 11);
    assert(lookup_pascal_hash2("goto") == 21);
    assert(lookup_pascal_hash2("with") == 0);
    assert(lookup_pascal_hash2("else") == 26);
    assert(lookup_pascal_hash2("forward") == 22);
    assert(lookup_pascal_hash2("set") == 9);
    assert(lookup_pascal_hash2("to") == 30);
    assert(lookup_pascal_hash2("for") == 23);
    assert(lookup_pascal_hash2("of") == 20);
    assert(lookup_pascal_hash2("procedure") == 12);
    assert(lookup_pascal_hash2("const") == 6);
    assert(lookup_pascal_hash2("if") == 35);
    assert(lookup_pascal_hash2("div") == 29);
    assert(lookup_pascal_hash2("end") == 32);
    assert(lookup_pascal_hash2("label") == 17);
    assert(lookup_pascal_hash2("repeat") == 19);
    assert(lookup_pascal_hash2("not") == 15);
    assert(lookup_pascal_hash2("then") == 8);
    assert(lookup_pascal_hash2("packed") == 14);
    assert(lookup_pascal_hash2("mod") == 33);
    assert(lookup_pascal_hash2("function") == 3);
    assert(lookup_pascal_hash2("until") == 7);
}

//lookup: name=lookup_pascal_hash3, dataset=pascal, type=hash, hash=hash3
int lookup_pascal_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 207) * 1;
    static constexpr const std::string_view lookup[207] = {
        "",
        "",
        "",
        "or", // 29190 (0x7206)
        "",
        "nil", // 29192 (0x7208)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "not", // 29206 (0x7216)
        "",
        "",
        "",
        "",
        "",
        "",
        "const", // 26936 (0x6938)
        "",
        "",
        "",
        "",
        "label", // 29218 (0x7222)
        "",
        "",
        "",
        "to", // 30464 (0x7700)
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
        "set", // 30476 (0x770c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "until", // 31535 (0x7b2f)
        "",
        "",
        "",
        "",
        "",
        "",
        "packed", // 30507 (0x772b)
        "do", // 26368 (0x6700)
        "",
        "",
        "forward", // 28234 (0x6e4a)
        "",
        "",
        "",
        "file", // 27410 (0x6b12)
        "procedure", // 31344 (0x7a70)
        "",
        "",
        "",
        "",
        "",
        "",
        "with", // 31765 (0x7c15)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "downto", // 27460 (0x6b44)
        "",
        "case", // 26634 (0x680a)
        "",
        "",
        "",
        "",
        "array", // 26432 (0x6740)
        "",
        "",
        "div", // 26642 (0x6812)
        "",
        "",
        "",
        "",
        "goto", // 27682 (0x6c22)
        "",
        "",
        "",
        "",
        "while", // 32034 (0x7d22)
        "",
        "",
        "then", // 31002 (0x791a)
        "",
        "mod", // 28934 (0x7106)
        "",
        "",
        "function", // 28523 (0x6f6b)
        "",
        "",
        "type", // 31010 (0x7922)
        "begin", // 26664 (0x6828)
        "",
        "program", // 30806 (0x7856)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "record", // 31023 (0x792f)
        "",
        "end", // 26885 (0x6905)
        "",
        "",
        "",
        "of", // 29166 (0x71ee)
        "",
        "var", // 31238 (0x7a06)
        "",
        "",
        "",
        "",
        "and", // 25861 (0x6505)
        "",
        "",
        "repeat", // 31039 (0x793f)
        "",
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
    static constexpr const int values[207] = {
        -1,
        -1,
        -1,
        13, // 29190 (0x7206)
        -1,
        16, // 29192 (0x7208)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 29206 (0x7216)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 26936 (0x6938)
        -1,
        -1,
        -1,
        -1,
        17, // 29218 (0x7222)
        -1,
        -1,
        -1,
        30, // 30464 (0x7700)
        -1,
        -1,
        -1,
        23, // 27156 (0x6a14)
        26, // 27157 (0x6a15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 30476 (0x770c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 31535 (0x7b2f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 30507 (0x772b)
        28, // 26368 (0x6700)
        -1,
        -1,
        22, // 28234 (0x6e4a)
        -1,
        -1,
        -1,
        25, // 27410 (0x6b12)
        12, // 31344 (0x7a70)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 31765 (0x7c15)
        -1,
        -1,
        -1,
        -1,
        35, // 27630 (0x6bee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 27646 (0x6bfe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 27460 (0x6b44)
        -1,
        4, // 26634 (0x680a)
        -1,
        -1,
        -1,
        -1,
        1, // 26432 (0x6740)
        -1,
        -1,
        29, // 26642 (0x6812)
        -1,
        -1,
        -1,
        -1,
        21, // 27682 (0x6c22)
        -1,
        -1,
        -1,
        -1,
        24, // 32034 (0x7d22)
        -1,
        -1,
        8, // 31002 (0x791a)
        -1,
        33, // 28934 (0x7106)
        -1,
        -1,
        3, // 28523 (0x6f6b)
        -1,
        -1,
        31, // 31010 (0x7922)
        34, // 26664 (0x6828)
        -1,
        11, // 30806 (0x7856)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 31023 (0x792f)
        -1,
        32, // 26885 (0x6905)
        -1,
        -1,
        -1,
        20, // 29166 (0x71ee)
        -1,
        5, // 31238 (0x7a06)
        -1,
        -1,
        -1,
        -1,
        2, // 25861 (0x6505)
        -1,
        -1,
        19, // 31039 (0x793f)
        -1,
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

//check: name=check_pascal_hash3, dataset=pascal, type=hash, hash=hash3
void check_pascal_hash3() {
    assert(lookup_pascal_hash3("or") == 13);
    assert(lookup_pascal_hash3("nil") == 16);
    assert(lookup_pascal_hash3("not") == 15);
    assert(lookup_pascal_hash3("const") == 6);
    assert(lookup_pascal_hash3("label") == 17);
    assert(lookup_pascal_hash3("to") == 30);
    assert(lookup_pascal_hash3("for") == 23);
    assert(lookup_pascal_hash3("else") == 26);
    assert(lookup_pascal_hash3("set") == 9);
    assert(lookup_pascal_hash3("until") == 7);
    assert(lookup_pascal_hash3("packed") == 14);
    assert(lookup_pascal_hash3("do") == 28);
    assert(lookup_pascal_hash3("forward") == 22);
    assert(lookup_pascal_hash3("file") == 25);
    assert(lookup_pascal_hash3("procedure") == 12);
    assert(lookup_pascal_hash3("with") == 0);
    assert(lookup_pascal_hash3("if") == 35);
    assert(lookup_pascal_hash3("in") == 18);
    assert(lookup_pascal_hash3("downto") == 27);
    assert(lookup_pascal_hash3("case") == 4);
    assert(lookup_pascal_hash3("array") == 1);
    assert(lookup_pascal_hash3("div") == 29);
    assert(lookup_pascal_hash3("goto") == 21);
    assert(lookup_pascal_hash3("while") == 24);
    assert(lookup_pascal_hash3("then") == 8);
    assert(lookup_pascal_hash3("mod") == 33);
    assert(lookup_pascal_hash3("function") == 3);
    assert(lookup_pascal_hash3("type") == 31);
    assert(lookup_pascal_hash3("begin") == 34);
    assert(lookup_pascal_hash3("program") == 11);
    assert(lookup_pascal_hash3("record") == 10);
    assert(lookup_pascal_hash3("end") == 32);
    assert(lookup_pascal_hash3("of") == 20);
    assert(lookup_pascal_hash3("var") == 5);
    assert(lookup_pascal_hash3("and") == 2);
    assert(lookup_pascal_hash3("repeat") == 19);
}

//lookup: name=lookup_pascal_hash_sum0, dataset=pascal, type=hash, hash=hash_sum0
int lookup_pascal_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 64) * 2;
    static constexpr const std::string_view lookup[128] = {
        "label", // 512 (0x200)
        "mod", // 320 (0x140)
        "repeat", // 641 (0x281)
        "",
        "type", // 450 (0x1c2)
        "",
        "nil", // 323 (0x143)
        "div", // 323 (0x143)
        "",
        "",
        "begin", // 517 (0x205)
        "",
        "",
        "",
        "for", // 327 (0x147)
        "",
        "",
        "",
        "var", // 329 (0x149)
        "procedure", // 969 (0x3c9)
        "",
        "",
        "",
        "",
        "set", // 332 (0x14c)
        "",
        "",
        "",
        "",
        "",
        "if", // 207 (0xcf)
        "",
        "",
        "",
        "not", // 337 (0x151)
        "",
        "",
        "",
        "do", // 211 (0xd3)
        "",
        "",
        "",
        "of", // 213 (0xd5)
        "",
        "",
        "",
        "in", // 215 (0xd7)
        "",
        "",
        "",
        "while", // 537 (0x219)
        "",
        "",
        "",
        "downto", // 667 (0x29b)
        "",
        "case", // 412 (0x19c)
        "",
        "",
        "",
        "",
        "",
        "array", // 543 (0x21f)
        "",
        "file", // 416 (0x1a0)
        "",
        "or", // 225 (0xe1)
        "",
        "",
        "",
        "to", // 227 (0xe3)
        "",
        "",
        "",
        "",
        "",
        "function", // 870 (0x366)
        "",
        "const", // 551 (0x227)
        "",
        "packed", // 616 (0x268)
        "",
        "else", // 425 (0x1a9)
        "",
        "",
        "",
        "",
        "",
        "until", // 556 (0x22c)
        "",
        "",
        "",
        "",
        "",
        "then", // 431 (0x1af)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "and", // 307 (0x133)
        "",
        "",
        "",
        "forward", // 757 (0x2f5)
        "",
        "",
        "",
        "end", // 311 (0x137)
        "",
        "program", // 760 (0x2f8)
        "",
        "goto", // 441 (0x1b9)
        "",
        "",
        "",
        "",
        "",
        "with", // 444 (0x1bc)
        "",
        "",
        "",
        "",
        "",
        "record", // 639 (0x27f)
        "",
    };
    static constexpr const int values[128] = {
        17, // 512 (0x200)
        33, // 320 (0x140)
        19, // 641 (0x281)
        -1,
        31, // 450 (0x1c2)
        -1,
        16, // 323 (0x143)
        29, // 323 (0x143)
        -1,
        -1,
        34, // 517 (0x205)
        -1,
        -1,
        -1,
        23, // 327 (0x147)
        -1,
        -1,
        -1,
        5, // 329 (0x149)
        12, // 969 (0x3c9)
        -1,
        -1,
        -1,
        -1,
        9, // 332 (0x14c)
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 207 (0xcf)
        -1,
        -1,
        -1,
        15, // 337 (0x151)
        -1,
        -1,
        -1,
        28, // 211 (0xd3)
        -1,
        -1,
        -1,
        20, // 213 (0xd5)
        -1,
        -1,
        -1,
        18, // 215 (0xd7)
        -1,
        -1,
        -1,
        24, // 537 (0x219)
        -1,
        -1,
        -1,
        27, // 667 (0x29b)
        -1,
        4, // 412 (0x19c)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 543 (0x21f)
        -1,
        25, // 416 (0x1a0)
        -1,
        13, // 225 (0xe1)
        -1,
        -1,
        -1,
        30, // 227 (0xe3)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 870 (0x366)
        -1,
        6, // 551 (0x227)
        -1,
        14, // 616 (0x268)
        -1,
        26, // 425 (0x1a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 556 (0x22c)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 431 (0x1af)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 307 (0x133)
        -1,
        -1,
        -1,
        22, // 757 (0x2f5)
        -1,
        -1,
        -1,
        32, // 311 (0x137)
        -1,
        11, // 760 (0x2f8)
        -1,
        21, // 441 (0x1b9)
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 444 (0x1bc)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 639 (0x27f)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_pascal_hash_sum0, dataset=pascal, type=hash, hash=hash_sum0
void check_pascal_hash_sum0() {
    assert(lookup_pascal_hash_sum0("label") == 17);
    assert(lookup_pascal_hash_sum0("mod") == 33);
    assert(lookup_pascal_hash_sum0("repeat") == 19);
    assert(lookup_pascal_hash_sum0("type") == 31);
    assert(lookup_pascal_hash_sum0("nil") == 16);
    assert(lookup_pascal_hash_sum0("div") == 29);
    assert(lookup_pascal_hash_sum0("begin") == 34);
    assert(lookup_pascal_hash_sum0("for") == 23);
    assert(lookup_pascal_hash_sum0("var") == 5);
    assert(lookup_pascal_hash_sum0("procedure") == 12);
    assert(lookup_pascal_hash_sum0("set") == 9);
    assert(lookup_pascal_hash_sum0("if") == 35);
    assert(lookup_pascal_hash_sum0("not") == 15);
    assert(lookup_pascal_hash_sum0("do") == 28);
    assert(lookup_pascal_hash_sum0("of") == 20);
    assert(lookup_pascal_hash_sum0("in") == 18);
    assert(lookup_pascal_hash_sum0("while") == 24);
    assert(lookup_pascal_hash_sum0("downto") == 27);
    assert(lookup_pascal_hash_sum0("case") == 4);
    assert(lookup_pascal_hash_sum0("array") == 1);
    assert(lookup_pascal_hash_sum0("file") == 25);
    assert(lookup_pascal_hash_sum0("or") == 13);
    assert(lookup_pascal_hash_sum0("to") == 30);
    assert(lookup_pascal_hash_sum0("function") == 3);
    assert(lookup_pascal_hash_sum0("const") == 6);
    assert(lookup_pascal_hash_sum0("packed") == 14);
    assert(lookup_pascal_hash_sum0("else") == 26);
    assert(lookup_pascal_hash_sum0("until") == 7);
    assert(lookup_pascal_hash_sum0("then") == 8);
    assert(lookup_pascal_hash_sum0("and") == 2);
    assert(lookup_pascal_hash_sum0("forward") == 22);
    assert(lookup_pascal_hash_sum0("end") == 32);
    assert(lookup_pascal_hash_sum0("program") == 11);
    assert(lookup_pascal_hash_sum0("goto") == 21);
    assert(lookup_pascal_hash_sum0("with") == 0);
    assert(lookup_pascal_hash_sum0("record") == 10);
}

//lookup: name=lookup_pascal_hash_sumN, dataset=pascal, type=hash, hash=hash_sumN
int lookup_pascal_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 40) * 2;
    static constexpr const std::string_view lookup[80] = {
        "",
        "",
        "until", // 561 (0x231)
        "",
        "begin", // 522 (0x20a)
        "",
        "mod", // 323 (0x143)
        "",
        "forward", // 764 (0x2fc)
        "",
        "record", // 645 (0x285)
        "goto", // 445 (0x1bd)
        "nil", // 326 (0x146)
        "div", // 326 (0x146)
        "program", // 767 (0x2ff)
        "repeat", // 647 (0x287)
        "with", // 448 (0x1c0)
        "",
        "if", // 209 (0xd1)
        "",
        "for", // 330 (0x14a)
        "",
        "",
        "",
        "var", // 332 (0x14c)
        "",
        "do", // 213 (0xd5)
        "",
        "type", // 454 (0x1c6)
        "",
        "set", // 335 (0x14f)
        "of", // 215 (0xd7)
        "case", // 416 (0x1a0)
        "",
        "in", // 217 (0xd9)
        "",
        "procedure", // 978 (0x3d2)
        "",
        "",
        "",
        "not", // 340 (0x154)
        "file", // 420 (0x1a4)
        "",
        "",
        "packed", // 622 (0x26e)
        "while", // 542 (0x21e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "or", // 227 (0xe3)
        "",
        "array", // 548 (0x224)
        "",
        "else", // 429 (0x1ad)
        "to", // 229 (0xe5)
        "and", // 310 (0x136)
        "",
        "",
        "",
        "",
        "",
        "downto", // 673 (0x2a1)
        "",
        "end", // 314 (0x13a)
        "",
        "then", // 435 (0x1b3)
        "",
        "const", // 556 (0x22c)
        "",
        "label", // 517 (0x205)
        "",
        "function", // 878 (0x36e)
        "",
        "",
        "",
    };
    static constexpr const int values[80] = {
        -1,
        -1,
        7, // 561 (0x231)
        -1,
        34, // 522 (0x20a)
        -1,
        33, // 323 (0x143)
        -1,
        22, // 764 (0x2fc)
        -1,
        10, // 645 (0x285)
        21, // 445 (0x1bd)
        16, // 326 (0x146)
        29, // 326 (0x146)
        11, // 767 (0x2ff)
        19, // 647 (0x287)
        0, // 448 (0x1c0)
        -1,
        35, // 209 (0xd1)
        -1,
        23, // 330 (0x14a)
        -1,
        -1,
        -1,
        5, // 332 (0x14c)
        -1,
        28, // 213 (0xd5)
        -1,
        31, // 454 (0x1c6)
        -1,
        9, // 335 (0x14f)
        20, // 215 (0xd7)
        4, // 416 (0x1a0)
        -1,
        18, // 217 (0xd9)
        -1,
        12, // 978 (0x3d2)
        -1,
        -1,
        -1,
        15, // 340 (0x154)
        25, // 420 (0x1a4)
        -1,
        -1,
        14, // 622 (0x26e)
        24, // 542 (0x21e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 227 (0xe3)
        -1,
        1, // 548 (0x224)
        -1,
        26, // 429 (0x1ad)
        30, // 229 (0xe5)
        2, // 310 (0x136)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 673 (0x2a1)
        -1,
        32, // 314 (0x13a)
        -1,
        8, // 435 (0x1b3)
        -1,
        6, // 556 (0x22c)
        -1,
        17, // 517 (0x205)
        -1,
        3, // 878 (0x36e)
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

//check: name=check_pascal_hash_sumN, dataset=pascal, type=hash, hash=hash_sumN
void check_pascal_hash_sumN() {
    assert(lookup_pascal_hash_sumN("until") == 7);
    assert(lookup_pascal_hash_sumN("begin") == 34);
    assert(lookup_pascal_hash_sumN("mod") == 33);
    assert(lookup_pascal_hash_sumN("forward") == 22);
    assert(lookup_pascal_hash_sumN("record") == 10);
    assert(lookup_pascal_hash_sumN("goto") == 21);
    assert(lookup_pascal_hash_sumN("nil") == 16);
    assert(lookup_pascal_hash_sumN("div") == 29);
    assert(lookup_pascal_hash_sumN("program") == 11);
    assert(lookup_pascal_hash_sumN("repeat") == 19);
    assert(lookup_pascal_hash_sumN("with") == 0);
    assert(lookup_pascal_hash_sumN("if") == 35);
    assert(lookup_pascal_hash_sumN("for") == 23);
    assert(lookup_pascal_hash_sumN("var") == 5);
    assert(lookup_pascal_hash_sumN("do") == 28);
    assert(lookup_pascal_hash_sumN("type") == 31);
    assert(lookup_pascal_hash_sumN("set") == 9);
    assert(lookup_pascal_hash_sumN("of") == 20);
    assert(lookup_pascal_hash_sumN("case") == 4);
    assert(lookup_pascal_hash_sumN("in") == 18);
    assert(lookup_pascal_hash_sumN("procedure") == 12);
    assert(lookup_pascal_hash_sumN("not") == 15);
    assert(lookup_pascal_hash_sumN("file") == 25);
    assert(lookup_pascal_hash_sumN("packed") == 14);
    assert(lookup_pascal_hash_sumN("while") == 24);
    assert(lookup_pascal_hash_sumN("or") == 13);
    assert(lookup_pascal_hash_sumN("array") == 1);
    assert(lookup_pascal_hash_sumN("else") == 26);
    assert(lookup_pascal_hash_sumN("to") == 30);
    assert(lookup_pascal_hash_sumN("and") == 2);
    assert(lookup_pascal_hash_sumN("downto") == 27);
    assert(lookup_pascal_hash_sumN("end") == 32);
    assert(lookup_pascal_hash_sumN("then") == 8);
    assert(lookup_pascal_hash_sumN("const") == 6);
    assert(lookup_pascal_hash_sumN("label") == 17);
    assert(lookup_pascal_hash_sumN("function") == 3);
}

//lookup: name=lookup_pascal_hash_djb2, dataset=pascal, type=hash, hash=hash_djb2
int lookup_pascal_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 251) * 1;
    static constexpr const std::string_view lookup[251] = {
        "",
        "packed", // 7083037814161 (0x67125f3ed91)
        "record", // 7083120833416 (0x6712ae6b388)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "array", // 214620347656 (0x31f85e9d08)
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
        "then", // 6504318392 (0x183b005b8)
        "",
        "",
        "",
        "",
        "",
        "of", // 5972574 (0x5b225e)
        "not", // 197094266 (0xbbf6b7a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "goto", // 6503859330 (0x183a90482)
        "or", // 5972586 (0x5b226a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "function", // 7713028246101167 (0x1b66f554c05caf)
        "",
        "",
        "",
        "type", // 6504337259 (0x183b04f6b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "nil", // 197094060 (0xbbf6aac)
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
        "forward", // 233727899299390 (0xd49304696e3e)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "set", // 197099381 (0xbbf7f75)
        "",
        "",
        "",
        "",
        "",
        "and", // 197080060 (0xbbf33fc)
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "program", // 233740927270465 (0xd4960cf07e41)
        "",
        "",
        "",
        "",
        "procedure", // 254543869625698226 (0x388524d00cb07b2)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "do", // 5972220 (0x5b20fc)
        "",
        "until", // 214643924757 (0x31f9c65f15)
        "mod", // 197093161 (0xbbf6729)
        "",
        "downto", // 7082585514852 (0x6710afe6364)
        "repeat", // 7083121289162 (0x6712aeda7ca)
        "",
        "",
        "",
        "",
        "label", // 214632764553 (0x31f91c1489)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "to", // 5972748 (0x5b230c)
        "",
        "",
        "",
        "",
        "begin", // 214621054670 (0x31f86966ce)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "file", // 6503816585 (0x183a85d89)
        "",
        "",
        "while", // 214646069090 (0x31f9e71762)
        "end", // 197084416 (0xbbf4500)
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
        "",
        "",
        "",
        "",
        "",
        "div", // 197083180 (0xbbf402c)
        "",
        "",
        "",
        "",
        "",
        "",
        "var", // 197102514 (0xbbf8bb2)
        "",
        "",
        "",
        "",
    };
    static constexpr const int values[251] = {
        -1,
        14, // 7083037814161 (0x67125f3ed91)
        10, // 7083120833416 (0x6712ae6b388)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 214620347656 (0x31f85e9d08)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 214622607920 (0x31f8811a30)
        -1,
        -1,
        -1,
        8, // 6504318392 (0x183b005b8)
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 5972574 (0x5b225e)
        15, // 197094266 (0xbbf6b7a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 6503859330 (0x183a90482)
        13, // 5972586 (0x5b226a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 7713028246101167 (0x1b66f554c05caf)
        -1,
        -1,
        -1,
        31, // 6504337259 (0x183b04f6b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 197094060 (0xbbf6aac)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 5972376 (0x5b2198)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 5972384 (0x5b21a0)
        -1,
        22, // 233727899299390 (0xd49304696e3e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 197085552 (0xbbf4970)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 197099381 (0xbbf7f75)
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 197080060 (0xbbf33fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 6503700293 (0x183a69745)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 233740927270465 (0xd4960cf07e41)
        -1,
        -1,
        -1,
        -1,
        12, // 254543869625698226 (0x388524d00cb07b2)
        26, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 5972220 (0x5b20fc)
        -1,
        7, // 214643924757 (0x31f9c65f15)
        33, // 197093161 (0xbbf6729)
        -1,
        27, // 7082585514852 (0x6710afe6364)
        19, // 7083121289162 (0x6712aeda7ca)
        -1,
        -1,
        -1,
        -1,
        17, // 214632764553 (0x31f91c1489)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 5972748 (0x5b230c)
        -1,
        -1,
        -1,
        -1,
        34, // 214621054670 (0x31f86966ce)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 6503816585 (0x183a85d89)
        -1,
        -1,
        24, // 214646069090 (0x31f9e71762)
        32, // 197084416 (0xbbf4500)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 6504427781 (0x183b1b105)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 197083180 (0xbbf402c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 197102514 (0xbbf8bb2)
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

//check: name=check_pascal_hash_djb2, dataset=pascal, type=hash, hash=hash_djb2
void check_pascal_hash_djb2() {
    assert(lookup_pascal_hash_djb2("packed") == 14);
    assert(lookup_pascal_hash_djb2("record") == 10);
    assert(lookup_pascal_hash_djb2("array") == 1);
    assert(lookup_pascal_hash_djb2("const") == 6);
    assert(lookup_pascal_hash_djb2("then") == 8);
    assert(lookup_pascal_hash_djb2("of") == 20);
    assert(lookup_pascal_hash_djb2("not") == 15);
    assert(lookup_pascal_hash_djb2("goto") == 21);
    assert(lookup_pascal_hash_djb2("or") == 13);
    assert(lookup_pascal_hash_djb2("function") == 3);
    assert(lookup_pascal_hash_djb2("type") == 31);
    assert(lookup_pascal_hash_djb2("nil") == 16);
    assert(lookup_pascal_hash_djb2("if") == 35);
    assert(lookup_pascal_hash_djb2("in") == 18);
    assert(lookup_pascal_hash_djb2("forward") == 22);
    assert(lookup_pascal_hash_djb2("for") == 23);
    assert(lookup_pascal_hash_djb2("set") == 9);
    assert(lookup_pascal_hash_djb2("and") == 2);
    assert(lookup_pascal_hash_djb2("case") == 4);
    assert(lookup_pascal_hash_djb2("program") == 11);
    assert(lookup_pascal_hash_djb2("procedure") == 12);
    assert(lookup_pascal_hash_djb2("else") == 26);
    assert(lookup_pascal_hash_djb2("do") == 28);
    assert(lookup_pascal_hash_djb2("until") == 7);
    assert(lookup_pascal_hash_djb2("mod") == 33);
    assert(lookup_pascal_hash_djb2("downto") == 27);
    assert(lookup_pascal_hash_djb2("repeat") == 19);
    assert(lookup_pascal_hash_djb2("label") == 17);
    assert(lookup_pascal_hash_djb2("to") == 30);
    assert(lookup_pascal_hash_djb2("begin") == 34);
    assert(lookup_pascal_hash_djb2("file") == 25);
    assert(lookup_pascal_hash_djb2("while") == 24);
    assert(lookup_pascal_hash_djb2("end") == 32);
    assert(lookup_pascal_hash_djb2("with") == 0);
    assert(lookup_pascal_hash_djb2("div") == 29);
    assert(lookup_pascal_hash_djb2("var") == 5);
}

//lookup: name=lookup_pascal_hash_sdb, dataset=pascal, type=hash, hash=hash_sdb
int lookup_pascal_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 203) * 1;
    static constexpr const std::string_view lookup[203] = {
        "",
        "",
        "",
        "goto", // 28996381010759823 (0x67040e0deb108f)
        "end", // 433838622011 (0x6502cc053b)
        "in", // 6881705 (0x6901a9)
        "",
        "",
        "",
        "",
        "",
        "",
        "while", // 431251735916197369 (0x5fc1d2b400e35f9)
        "case", // 27870266342903704 (0x6303dc0d2a0f98)
        "",
        "begin", // 359470621653085937 (0x4fd18a036d22ef1)
        "",
        "",
        "",
        "",
        "of", // 7274931 (0x6f01b3)
        "",
        "",
        "",
        "procedure", // 4771092501595672255 (0x4236535a1423cebf)
        "",
        "then", // 32656028173668737 (0x74047c0f111181)
        "",
        "",
        "",
        "",
        "",
        "or", // 7274943 (0x6f01bf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "label", // 392123862201676148 (0x5711a933a7c3174)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "and", // 416657179927 (0x6102b40517)
        "",
        "",
        "with", // 33500573369569794 (0x7704980f771202)
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
        "",
        "",
        "",
        "for", // 438134048085 (0x6602d30555)
        "var", // 506858898875 (0x76032505bb)
        "",
        "",
        "",
        "",
        "to", // 7602635 (0x7401cb)
        "",
        "div", // 429542933813 (0x6402c10535)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "set", // 493973079470 (0x73031705ae)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "file", // 28714841604886556 (0x6603ff0da4101c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "nil", // 472496539013 (0x6e02fd0585)
        "",
        "",
        "",
        "forward", // 288078416784507285 (0x3ff75cb33e5c195)
        "",
        "record", // 3257106886888234045 (0x2d339174ec739c3d)
        "function", // 10100634927348600308 (0x8c2ca9f372844df4)
        "",
        "",
        "",
        "",
        "",
        "",
        "do", // 6554011 (0x64019b)
        "",
        "",
        "const", // 365663719708962995 (0x5131937388030b3)
        "",
        "",
        "program", // 1869459258466754228 (0x19f1a74a6ef9deb4)
        "",
        "",
        "",
        "",
        "else", // 28433340858241073 (0x6503f90da21031)
        "type", // 32656101195518514 (0x74048d0f821232)
        "",
        "",
        "array", // 359752414477103189 (0x4fe18ea37ff3055)
        "",
        "not", // 472496932255 (0x6e0303059f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "repeat", // 3260766521164930335 (0x2d4091dfed859d1f)
        "",
        "until", // 426185001652401754 (0x5ea1d004017365a)
        "",
        "",
        "",
        "",
        "downto", // 2941841765811721281 (0x28d3857fdc9d9441)
        "",
        "",
        "",
        "",
        "packed", // 3192927327939238088 (0x2c4f8e7ce77498c8)
        "if", // 6881697 (0x6901a1)
        "",
        "",
    };
    static constexpr const int values[203] = {
        -1,
        -1,
        -1,
        21, // 28996381010759823 (0x67040e0deb108f)
        32, // 433838622011 (0x6502cc053b)
        18, // 6881705 (0x6901a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 431251735916197369 (0x5fc1d2b400e35f9)
        4, // 27870266342903704 (0x6303dc0d2a0f98)
        -1,
        34, // 359470621653085937 (0x4fd18a036d22ef1)
        -1,
        -1,
        -1,
        -1,
        20, // 7274931 (0x6f01b3)
        -1,
        -1,
        -1,
        12, // 4771092501595672255 (0x4236535a1423cebf)
        -1,
        8, // 32656028173668737 (0x74047c0f111181)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 7274943 (0x6f01bf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 392123862201676148 (0x5711a933a7c3174)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 416657179927 (0x6102b40517)
        -1,
        -1,
        0, // 33500573369569794 (0x7704980f771202)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 468201571718 (0x6d02fd0586)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 438134048085 (0x6602d30555)
        5, // 506858898875 (0x76032505bb)
        -1,
        -1,
        -1,
        -1,
        30, // 7602635 (0x7401cb)
        -1,
        29, // 429542933813 (0x6402c10535)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 493973079470 (0x73031705ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 28714841604886556 (0x6603ff0da4101c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 472496539013 (0x6e02fd0585)
        -1,
        -1,
        -1,
        22, // 288078416784507285 (0x3ff75cb33e5c195)
        -1,
        10, // 3257106886888234045 (0x2d339174ec739c3d)
        3, // 10100634927348600308 (0x8c2ca9f372844df4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 6554011 (0x64019b)
        -1,
        -1,
        6, // 365663719708962995 (0x5131937388030b3)
        -1,
        -1,
        11, // 1869459258466754228 (0x19f1a74a6ef9deb4)
        -1,
        -1,
        -1,
        -1,
        26, // 28433340858241073 (0x6503f90da21031)
        31, // 32656101195518514 (0x74048d0f821232)
        -1,
        -1,
        1, // 359752414477103189 (0x4fe18ea37ff3055)
        -1,
        15, // 472496932255 (0x6e0303059f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 3260766521164930335 (0x2d4091dfed859d1f)
        -1,
        7, // 426185001652401754 (0x5ea1d004017365a)
        -1,
        -1,
        -1,
        -1,
        27, // 2941841765811721281 (0x28d3857fdc9d9441)
        -1,
        -1,
        -1,
        -1,
        14, // 3192927327939238088 (0x2c4f8e7ce77498c8)
        35, // 6881697 (0x6901a1)
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

//check: name=check_pascal_hash_sdb, dataset=pascal, type=hash, hash=hash_sdb
void check_pascal_hash_sdb() {
    assert(lookup_pascal_hash_sdb("goto") == 21);
    assert(lookup_pascal_hash_sdb("end") == 32);
    assert(lookup_pascal_hash_sdb("in") == 18);
    assert(lookup_pascal_hash_sdb("while") == 24);
    assert(lookup_pascal_hash_sdb("case") == 4);
    assert(lookup_pascal_hash_sdb("begin") == 34);
    assert(lookup_pascal_hash_sdb("of") == 20);
    assert(lookup_pascal_hash_sdb("procedure") == 12);
    assert(lookup_pascal_hash_sdb("then") == 8);
    assert(lookup_pascal_hash_sdb("or") == 13);
    assert(lookup_pascal_hash_sdb("label") == 17);
    assert(lookup_pascal_hash_sdb("and") == 2);
    assert(lookup_pascal_hash_sdb("with") == 0);
    assert(lookup_pascal_hash_sdb("mod") == 33);
    assert(lookup_pascal_hash_sdb("for") == 23);
    assert(lookup_pascal_hash_sdb("var") == 5);
    assert(lookup_pascal_hash_sdb("to") == 30);
    assert(lookup_pascal_hash_sdb("div") == 29);
    assert(lookup_pascal_hash_sdb("set") == 9);
    assert(lookup_pascal_hash_sdb("file") == 25);
    assert(lookup_pascal_hash_sdb("nil") == 16);
    assert(lookup_pascal_hash_sdb("forward") == 22);
    assert(lookup_pascal_hash_sdb("record") == 10);
    assert(lookup_pascal_hash_sdb("function") == 3);
    assert(lookup_pascal_hash_sdb("do") == 28);
    assert(lookup_pascal_hash_sdb("const") == 6);
    assert(lookup_pascal_hash_sdb("program") == 11);
    assert(lookup_pascal_hash_sdb("else") == 26);
    assert(lookup_pascal_hash_sdb("type") == 31);
    assert(lookup_pascal_hash_sdb("array") == 1);
    assert(lookup_pascal_hash_sdb("not") == 15);
    assert(lookup_pascal_hash_sdb("repeat") == 19);
    assert(lookup_pascal_hash_sdb("until") == 7);
    assert(lookup_pascal_hash_sdb("downto") == 27);
    assert(lookup_pascal_hash_sdb("packed") == 14);
    assert(lookup_pascal_hash_sdb("if") == 35);
}
