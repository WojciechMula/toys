
//lookup: name=lookup_cplusplus_hash1, dataset=cplusplus, hash=hash1
int lookup_cplusplus_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 127) * 4;
    static std::string_view lookup[508] = {
        "",
        "",
        "",
        "",
        "static_cast", // 2541 (0x9ed)
        "xor_eq", // 1398 (0x576)
        "",
        "",
        "typedef", // 1526 (0x5f6)
        "",
        "",
        "",
        "protected", // 1908 (0x774)
        "",
        "",
        "",
        "__asm", // 1020 (0x3fc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "break", // 1025 (0x401)
        "",
        "",
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
        "for", // 648 (0x288)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "compl", // 1035 (0x40b)
        "",
        "",
        "",
        "signed", // 1290 (0x50a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "operator", // 1800 (0x708)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "typeid", // 1296 (0x510)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "int", // 663 (0x297)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__complex", // 1935 (0x78f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "export", // 1302 (0x516)
        "sizeof", // 1302 (0x516)
        "throw", // 1175 (0x497)
        "",
        "if", // 414 (0x19e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "this", // 924 (0x39c)
        "",
        "",
        "",
        "__signed", // 1560 (0x618)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 800 (0x320)
        "typeof", // 1308 (0x51c)
        "",
        "",
        "signature", // 1944 (0x798)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "do", // 422 (0x1a6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "not", // 678 (0x2a6)
        "",
        "",
        "",
        "__inline", // 1568 (0x620)
        "bitor", // 1060 (0x424)
        "switch", // 1314 (0x522)
        "",
        "__imag", // 1188 (0x4a4)
        "bitand", // 1188 (0x4a4)
        "",
        "",
        "else", // 808 (0x328)
        "register", // 1824 (0x720)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__typeof", // 1576 (0x628)
        "dynamic_cast", // 2592 (0xa20)
        "new", // 687 (0x2af)
        "",
        "",
        "",
        "",
        "",
        "class", // 1070 (0x42e)
        "",
        "",
        "",
        "__volatile", // 1960 (0x7a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute__", // 2470 (0x9a6)
        "__extension__", // 2470 (0x9a6)
        "__signature__", // 2470 (0x9a6)
        "",
        "__alignof__", // 2090 (0x82a)
        "__complex__", // 2090 (0x82a)
        "virtual", // 1582 (0x62e)
        "",
        "__const__", // 1710 (0x6ae)
        "__label__", // 1710 (0x6ae)
        "__sigof__", // 1710 (0x6ae)
        "const", // 1075 (0x433)
        "__asm__", // 1330 (0x532)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "bool", // 824 (0x338)
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "xor", // 702 (0x2be)
        "",
        "",
        "",
        "not_eq", // 1338 (0x53a)
        "",
        "",
        "",
        "friend", // 1212 (0x4bc)
        "or", // 450 (0x1c2)
        "sigof", // 1085 (0x43d)
        "",
        "auto", // 832 (0x340)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "mutable", // 1470 (0x5be)
        "",
        "",
        "",
        "float", // 1090 (0x442)
        "return", // 1344 (0x540)
        "",
        "",
        "__null", // 1218 (0x4c2)
        "__real", // 1218 (0x4c2)
        "",
        "",
        "continue", // 1600 (0x640)
        "try", // 711 (0x2c7)
        "",
        "",
        "",
        "",
        "",
        "",
        "__restrict", // 2110 (0x83e)
        "enum", // 840 (0x348)
        "",
        "",
        "",
        "",
        "",
        "",
        "__const", // 1477 (0x5c5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "long", // 844 (0x34c)
        "",
        "",
        "",
        "and", // 591 (0x24f)
        "",
        "",
        "",
        "using", // 1100 (0x44c)
        "while", // 1100 (0x44c)
        "",
        "",
        "explicit", // 1736 (0x6c8)
        "template", // 1736 (0x6c8)
        "typename", // 1736 (0x6c8)
        "unsigned", // 1736 (0x6c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "inline", // 1236 (0x4d4)
        "",
        "",
        "",
        "goto", // 856 (0x358)
        "private", // 1491 (0x5d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "volatile", // 1752 (0x6d8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "or_eq", // 1120 (0x460)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "true", // 868 (0x364)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "asm", // 618 (0x26a)
        "void", // 872 (0x368)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "struct", // 1386 (0x56a)
        "",
        "",
        "",
        "and_eq", // 1260 (0x4ec)
        "",
        "",
        "",
        "const_cast", // 2150 (0x866)
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
        "__restrict__", // 2280 (0x8e8)
        "__volatile__", // 2280 (0x8e8)
        "__wchar_t", // 1899 (0x76b)
        "namespace", // 1899 (0x76b)
        "__alignof", // 1773 (0x6ed)
        "__inline__", // 1900 (0x76c)
        "__signed__", // 1900 (0x76c)
        "__typeof__", // 1900 (0x76c)
        "__imag__", // 1520 (0x5f0)
        "__real__", // 1520 (0x5f0)
        "extern", // 1266 (0x4f2)
        "public", // 1266 (0x4f2)
        "__attribute", // 2156 (0x86c)
        "reinterpret_cast", // 3680 (0xe60)
        "",
        "",
        "",
        "",
        "",
        "",
        "catch", // 1015 (0x3f7)
        "false", // 1015 (0x3f7)
        "",
        "",
    };
    static int values[508] = {
        -1,
        -1,
        -1,
        -1,
        85, // 2541 (0x9ed)
        105, // 1398 (0x576)
        -1,
        -1,
        93, // 1526 (0x5f6)
        -1,
        -1,
        -1,
        74, // 1908 (0x774)
        -1,
        -1,
        -1,
        2, // 1020 (0x3fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 1025 (0x401)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        79, // 1155 (0x483)
        -1,
        -1,
        -1,
        58, // 648 (0x288)
        -1,
        -1,
        -1,
        84, // 1284 (0x504)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 1035 (0x40b)
        -1,
        -1,
        -1,
        81, // 1290 (0x50a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 1800 (0x708)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        95, // 1296 (0x510)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        63, // 663 (0x297)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 1935 (0x78f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 1302 (0x516)
        83, // 1302 (0x516)
        90, // 1175 (0x497)
        -1,
        61, // 414 (0x19e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 924 (0x39c)
        -1,
        -1,
        -1,
        22, // 1560 (0x618)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 800 (0x320)
        96, // 1308 (0x51c)
        -1,
        -1,
        80, // 1944 (0x798)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 422 (0x1a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 678 (0x2a6)
        -1,
        -1,
        -1,
        13, // 1568 (0x620)
        35, // 1060 (0x424)
        87, // 1314 (0x522)
        -1,
        11, // 1188 (0x4a4)
        34, // 1188 (0x4a4)
        -1,
        -1,
        51, // 808 (0x328)
        76, // 1824 (0x720)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1576 (0x628)
        50, // 2592 (0xa20)
        67, // 687 (0x2af)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 1070 (0x42e)
        -1,
        -1,
        -1,
        27, // 1960 (0x7a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 2470 (0x9a6)
        10, // 2470 (0x9a6)
        21, // 2470 (0x9a6)
        -1,
        1, // 2090 (0x82a)
        7, // 2090 (0x82a)
        100, // 1582 (0x62e)
        -1,
        9, // 1710 (0x6ae)
        15, // 1710 (0x6ae)
        24, // 1710 (0x6ae)
        43, // 1075 (0x433)
        3, // 1330 (0x532)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 824 (0x338)
        -1,
        -1,
        -1,
        47, // 1206 (0x4b6)
        49, // 1206 (0x4b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 702 (0x2be)
        -1,
        -1,
        -1,
        69, // 1338 (0x53a)
        -1,
        -1,
        -1,
        59, // 1212 (0x4bc)
        71, // 450 (0x1c2)
        82, // 1085 (0x43d)
        -1,
        33, // 832 (0x340)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 1470 (0x5be)
        -1,
        -1,
        -1,
        57, // 1090 (0x442)
        78, // 1344 (0x540)
        -1,
        -1,
        16, // 1218 (0x4c2)
        17, // 1218 (0x4c2)
        -1,
        -1,
        45, // 1600 (0x640)
        92, // 711 (0x2c7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 2110 (0x83e)
        52, // 840 (0x348)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 1477 (0x5c5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 844 (0x34c)
        -1,
        -1,
        -1,
        31, // 591 (0x24f)
        -1,
        -1,
        -1,
        99, // 1100 (0x44c)
        103, // 1100 (0x44c)
        -1,
        -1,
        53, // 1736 (0x6c8)
        88, // 1736 (0x6c8)
        94, // 1736 (0x6c8)
        98, // 1736 (0x6c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 852 (0x354)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        62, // 1236 (0x4d4)
        -1,
        -1,
        -1,
        60, // 856 (0x358)
        73, // 1491 (0x5d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        102, // 1752 (0x6d8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 1120 (0x460)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        91, // 868 (0x364)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 618 (0x26a)
        101, // 872 (0x368)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 1512 (0x5e8)
        -1,
        -1,
        -1,
        86, // 1386 (0x56a)
        -1,
        -1,
        -1,
        32, // 1260 (0x4ec)
        -1,
        -1,
        -1,
        44, // 2150 (0x866)
        -1,
        -1,
        -1,
        97, // 1135 (0x46f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 2280 (0x8e8)
        28, // 2280 (0x8e8)
        29, // 1899 (0x76b)
        66, // 1899 (0x76b)
        0, // 1773 (0x6ed)
        14, // 1900 (0x76c)
        23, // 1900 (0x76c)
        26, // 1900 (0x76c)
        12, // 1520 (0x5f0)
        18, // 1520 (0x5f0)
        55, // 1266 (0x4f2)
        75, // 1266 (0x4f2)
        4, // 2156 (0x86c)
        77, // 3680 (0xe60)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 1015 (0x3f7)
        56, // 1015 (0x3f7)
        -1,
        -1,
    };
    for (int i=0; i < 4; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cplusplus_hash1, dataset=cplusplus, hash=hash1
void check_cplusplus_hash1() {
    assert(lookup_cplusplus_hash1("static_cast") == 85);
    assert(lookup_cplusplus_hash1("xor_eq") == 105);
    assert(lookup_cplusplus_hash1("typedef") == 93);
    assert(lookup_cplusplus_hash1("protected") == 74);
    assert(lookup_cplusplus_hash1("__asm") == 2);
    assert(lookup_cplusplus_hash1("break") == 37);
    assert(lookup_cplusplus_hash1("short") == 79);
    assert(lookup_cplusplus_hash1("for") == 58);
    assert(lookup_cplusplus_hash1("static") == 84);
    assert(lookup_cplusplus_hash1("compl") == 42);
    assert(lookup_cplusplus_hash1("signed") == 81);
    assert(lookup_cplusplus_hash1("operator") == 70);
    assert(lookup_cplusplus_hash1("typeid") == 95);
    assert(lookup_cplusplus_hash1("int") == 63);
    assert(lookup_cplusplus_hash1("__complex") == 6);
    assert(lookup_cplusplus_hash1("export") == 54);
    assert(lookup_cplusplus_hash1("sizeof") == 83);
    assert(lookup_cplusplus_hash1("throw") == 90);
    assert(lookup_cplusplus_hash1("if") == 61);
    assert(lookup_cplusplus_hash1("this") == 89);
    assert(lookup_cplusplus_hash1("__signed") == 22);
    assert(lookup_cplusplus_hash1("case") == 38);
    assert(lookup_cplusplus_hash1("typeof") == 96);
    assert(lookup_cplusplus_hash1("signature") == 80);
    assert(lookup_cplusplus_hash1("do") == 48);
    assert(lookup_cplusplus_hash1("not") == 68);
    assert(lookup_cplusplus_hash1("__inline") == 13);
    assert(lookup_cplusplus_hash1("bitor") == 35);
    assert(lookup_cplusplus_hash1("switch") == 87);
    assert(lookup_cplusplus_hash1("__imag") == 11);
    assert(lookup_cplusplus_hash1("bitand") == 34);
    assert(lookup_cplusplus_hash1("else") == 51);
    assert(lookup_cplusplus_hash1("register") == 76);
    assert(lookup_cplusplus_hash1("__typeof") == 25);
    assert(lookup_cplusplus_hash1("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash1("new") == 67);
    assert(lookup_cplusplus_hash1("class") == 41);
    assert(lookup_cplusplus_hash1("__volatile") == 27);
    assert(lookup_cplusplus_hash1("__attribute__") == 5);
    assert(lookup_cplusplus_hash1("__extension__") == 10);
    assert(lookup_cplusplus_hash1("__signature__") == 21);
    assert(lookup_cplusplus_hash1("__alignof__") == 1);
    assert(lookup_cplusplus_hash1("__complex__") == 7);
    assert(lookup_cplusplus_hash1("virtual") == 100);
    assert(lookup_cplusplus_hash1("__const__") == 9);
    assert(lookup_cplusplus_hash1("__label__") == 15);
    assert(lookup_cplusplus_hash1("__sigof__") == 24);
    assert(lookup_cplusplus_hash1("const") == 43);
    assert(lookup_cplusplus_hash1("__asm__") == 3);
    assert(lookup_cplusplus_hash1("bool") == 36);
    assert(lookup_cplusplus_hash1("delete") == 47);
    assert(lookup_cplusplus_hash1("double") == 49);
    assert(lookup_cplusplus_hash1("xor") == 104);
    assert(lookup_cplusplus_hash1("not_eq") == 69);
    assert(lookup_cplusplus_hash1("friend") == 59);
    assert(lookup_cplusplus_hash1("or") == 71);
    assert(lookup_cplusplus_hash1("sigof") == 82);
    assert(lookup_cplusplus_hash1("auto") == 33);
    assert(lookup_cplusplus_hash1("mutable") == 65);
    assert(lookup_cplusplus_hash1("float") == 57);
    assert(lookup_cplusplus_hash1("return") == 78);
    assert(lookup_cplusplus_hash1("__null") == 16);
    assert(lookup_cplusplus_hash1("__real") == 17);
    assert(lookup_cplusplus_hash1("continue") == 45);
    assert(lookup_cplusplus_hash1("try") == 92);
    assert(lookup_cplusplus_hash1("__restrict") == 19);
    assert(lookup_cplusplus_hash1("enum") == 52);
    assert(lookup_cplusplus_hash1("__const") == 8);
    assert(lookup_cplusplus_hash1("long") == 64);
    assert(lookup_cplusplus_hash1("and") == 31);
    assert(lookup_cplusplus_hash1("using") == 99);
    assert(lookup_cplusplus_hash1("while") == 103);
    assert(lookup_cplusplus_hash1("explicit") == 53);
    assert(lookup_cplusplus_hash1("template") == 88);
    assert(lookup_cplusplus_hash1("typename") == 94);
    assert(lookup_cplusplus_hash1("unsigned") == 98);
    assert(lookup_cplusplus_hash1("char") == 40);
    assert(lookup_cplusplus_hash1("inline") == 62);
    assert(lookup_cplusplus_hash1("goto") == 60);
    assert(lookup_cplusplus_hash1("private") == 73);
    assert(lookup_cplusplus_hash1("volatile") == 102);
    assert(lookup_cplusplus_hash1("or_eq") == 72);
    assert(lookup_cplusplus_hash1("true") == 91);
    assert(lookup_cplusplus_hash1("asm") == 30);
    assert(lookup_cplusplus_hash1("void") == 101);
    assert(lookup_cplusplus_hash1("default") == 46);
    assert(lookup_cplusplus_hash1("struct") == 86);
    assert(lookup_cplusplus_hash1("and_eq") == 32);
    assert(lookup_cplusplus_hash1("const_cast") == 44);
    assert(lookup_cplusplus_hash1("union") == 97);
    assert(lookup_cplusplus_hash1("__restrict__") == 20);
    assert(lookup_cplusplus_hash1("__volatile__") == 28);
    assert(lookup_cplusplus_hash1("__wchar_t") == 29);
    assert(lookup_cplusplus_hash1("namespace") == 66);
    assert(lookup_cplusplus_hash1("__alignof") == 0);
    assert(lookup_cplusplus_hash1("__inline__") == 14);
    assert(lookup_cplusplus_hash1("__signed__") == 23);
    assert(lookup_cplusplus_hash1("__typeof__") == 26);
    assert(lookup_cplusplus_hash1("__imag__") == 12);
    assert(lookup_cplusplus_hash1("__real__") == 18);
    assert(lookup_cplusplus_hash1("extern") == 55);
    assert(lookup_cplusplus_hash1("public") == 75);
    assert(lookup_cplusplus_hash1("__attribute") == 4);
    assert(lookup_cplusplus_hash1("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash1("catch") == 39);
    assert(lookup_cplusplus_hash1("false") == 56);
}

//lookup: name=lookup_cplusplus_hash2, dataset=cplusplus, hash=hash2
int lookup_cplusplus_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 109) * 3;
    static std::string_view lookup[327] = {
        "",
        "",
        "",
        "asm", // 10574 (0x294e)
        "namespace", // 11119 (0x2b6f)
        "",
        "and", // 9703 (0x25e7)
        "long", // 11120 (0x2b70)
        "operator", // 12646 (0x3166)
        "__asm", // 10358 (0x2876)
        "or_eq", // 12538 (0x30fa)
        "return", // 12538 (0x30fa)
        "__wchar_t", // 11013 (0x2b05)
        "enum", // 11013 (0x2b05)
        "",
        "__restrict", // 11014 (0x2b06)
        "mutable", // 11014 (0x2b06)
        "union", // 12867 (0x3243)
        "",
        "",
        "",
        "compl", // 10689 (0x29c1)
        "",
        "",
        "or", // 12652 (0x316c)
        "",
        "",
        "__signed", // 9492 (0x2514)
        "new", // 13089 (0x3321)
        "",
        "__const", // 11019 (0x2b0b)
        "not", // 12763 (0x31db)
        "",
        "",
        "",
        "",
        "__null", // 10258 (0x2812)
        "__real", // 10258 (0x2812)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "bool", // 10588 (0x295c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "break", // 10483 (0x28f3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "if", // 10708 (0x29d4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "volatile", // 11910 (0x2e86)
        "",
        "",
        "inline", // 10603 (0x296b)
        "",
        "",
        "",
        "",
        "",
        "void", // 11804 (0x2e1c)
        "while", // 12022 (0x2ef6)
        "",
        "const_cast", // 11478 (0x2cd6)
        "register", // 13004 (0x32cc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "const", // 11481 (0x2cd9)
        "",
        "",
        "static_cast", // 13335 (0x3417)
        "",
        "",
        "this", // 13336 (0x3418)
        "",
        "",
        "short", // 13337 (0x3419)
        "",
        "",
        "struct", // 13338 (0x341a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "unsigned", // 11708 (0x2dbc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "true", // 11712 (0x2dc0)
        "",
        "",
        "xor_eq", // 13566 (0x34fe)
        "",
        "",
        "bitor", // 11169 (0x2ba1)
        "export", // 11714 (0x2dc2)
        "reinterpret_cast", // 13240 (0x33b8)
        "class", // 11388 (0x2c7c)
        "signature", // 11606 (0x2d56)
        "typeid", // 11606 (0x2d56)
        "default", // 11607 (0x2d57)
        "false", // 10299 (0x283b)
        "signed", // 11498 (0x2cea)
        "",
        "",
        "",
        "catch", // 10301 (0x283d)
        "char", // 11282 (0x2c12)
        "static", // 11391 (0x2c7f)
        "",
        "",
        "",
        "__complex", // 11393 (0x2c81)
        "",
        "",
        "dynamic_cast", // 11612 (0x2d5c)
        "xor", // 13683 (0x3573)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "explicit", // 11724 (0x2dcc)
        "template", // 11724 (0x2dcc)
        "typename", // 11724 (0x2dcc)
        "",
        "",
        "",
        "",
        "",
        "",
        "using", // 12054 (0x2f16)
        "",
        "",
        "float", // 11837 (0x2e3d)
        "",
        "",
        "typeof", // 11838 (0x2e3e)
        "",
        "",
        "and_eq", // 10967 (0x2ad7)
        "throw", // 13801 (0x35e9)
        "typedef", // 11839 (0x2e3f)
        "else", // 10205 (0x27dd)
        "",
        "",
        "friend", // 10206 (0x27de)
        "sizeof", // 11732 (0x2dd4)
        "",
        "delete", // 10098 (0x2772)
        "double", // 10098 (0x2772)
        "",
        "",
        "",
        "",
        "continue", // 9991 (0x2707)
        "sigof", // 11735 (0x2dd7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "case", // 9995 (0x270b)
        "",
        "",
        "for", // 11631 (0x2d6f)
        "",
        "",
        "",
        "",
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
        "int", // 12183 (0x2f97)
        "",
        "",
        "public", // 11094 (0x2b56)
        "switch", // 11966 (0x2ebe)
        "",
        "",
        "",
        "",
        "try", // 14039 (0x36d7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__imag", // 9791 (0x263f)
        "__typeof", // 9682 (0x25d2)
        "",
        "__alignof", // 9683 (0x25d3)
        "protected", // 11209 (0x2bc9)
        "",
        "__asm__", // 9030 (0x2346)
        "private", // 11319 (0x2c37)
        "",
        "do", // 11102 (0x2b5e)
        "",
        "",
        "__const__", // 9032 (0x2348)
        "__label__", // 9032 (0x2348)
        "__sigof__", // 9032 (0x2348)
        "__imag__", // 9033 (0x2349)
        "__real__", // 9033 (0x2349)
        "extern", // 11104 (0x2b60)
        "__alignof__", // 9034 (0x234a)
        "__complex__", // 9034 (0x234a)
        "",
        "__inline__", // 9035 (0x234b)
        "__signed__", // 9035 (0x234b)
        "__typeof__", // 9035 (0x234b)
        "__attribute__", // 9036 (0x234c)
        "__extension__", // 9036 (0x234c)
        "__signature__", // 9036 (0x234c)
        "__restrict__", // 9037 (0x234d)
        "__volatile__", // 9037 (0x234d)
        "",
        "",
        "",
        "",
        "__attribute", // 9584 (0x2570)
        "goto", // 11437 (0x2cad)
        "",
        "__volatile", // 9585 (0x2571)
        "",
        "",
        "",
        "",
        "",
        "__inline", // 9587 (0x2573)
        "",
        "",
        "bitand", // 9806 (0x264e)
        "",
        "",
        "",
        "",
        "",
        "not_eq", // 12424 (0x3088)
        "virtual", // 12751 (0x31cf)
        "",
        "",
        "",
        "",
    };
    static int values[327] = {
        -1,
        -1,
        -1,
        30, // 10574 (0x294e)
        66, // 11119 (0x2b6f)
        -1,
        31, // 9703 (0x25e7)
        64, // 11120 (0x2b70)
        70, // 12646 (0x3166)
        2, // 10358 (0x2876)
        72, // 12538 (0x30fa)
        78, // 12538 (0x30fa)
        29, // 11013 (0x2b05)
        52, // 11013 (0x2b05)
        -1,
        19, // 11014 (0x2b06)
        65, // 11014 (0x2b06)
        97, // 12867 (0x3243)
        -1,
        -1,
        -1,
        42, // 10689 (0x29c1)
        -1,
        -1,
        71, // 12652 (0x316c)
        -1,
        -1,
        22, // 9492 (0x2514)
        67, // 13089 (0x3321)
        -1,
        8, // 11019 (0x2b0b)
        68, // 12763 (0x31db)
        -1,
        -1,
        -1,
        -1,
        16, // 10258 (0x2812)
        17, // 10258 (0x2812)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 10588 (0x295c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 10483 (0x28f3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 10708 (0x29d4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        102, // 11910 (0x2e86)
        -1,
        -1,
        62, // 10603 (0x296b)
        -1,
        -1,
        -1,
        -1,
        -1,
        101, // 11804 (0x2e1c)
        103, // 12022 (0x2ef6)
        -1,
        44, // 11478 (0x2cd6)
        76, // 13004 (0x32cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 11481 (0x2cd9)
        -1,
        -1,
        85, // 13335 (0x3417)
        -1,
        -1,
        89, // 13336 (0x3418)
        -1,
        -1,
        79, // 13337 (0x3419)
        -1,
        -1,
        86, // 13338 (0x341a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        98, // 11708 (0x2dbc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        91, // 11712 (0x2dc0)
        -1,
        -1,
        105, // 13566 (0x34fe)
        -1,
        -1,
        35, // 11169 (0x2ba1)
        54, // 11714 (0x2dc2)
        77, // 13240 (0x33b8)
        41, // 11388 (0x2c7c)
        80, // 11606 (0x2d56)
        95, // 11606 (0x2d56)
        46, // 11607 (0x2d57)
        56, // 10299 (0x283b)
        81, // 11498 (0x2cea)
        -1,
        -1,
        -1,
        39, // 10301 (0x283d)
        40, // 11282 (0x2c12)
        84, // 11391 (0x2c7f)
        -1,
        -1,
        -1,
        6, // 11393 (0x2c81)
        -1,
        -1,
        50, // 11612 (0x2d5c)
        104, // 13683 (0x3573)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 11724 (0x2dcc)
        88, // 11724 (0x2dcc)
        94, // 11724 (0x2dcc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        99, // 12054 (0x2f16)
        -1,
        -1,
        57, // 11837 (0x2e3d)
        -1,
        -1,
        96, // 11838 (0x2e3e)
        -1,
        -1,
        32, // 10967 (0x2ad7)
        90, // 13801 (0x35e9)
        93, // 11839 (0x2e3f)
        51, // 10205 (0x27dd)
        -1,
        -1,
        59, // 10206 (0x27de)
        83, // 11732 (0x2dd4)
        -1,
        47, // 10098 (0x2772)
        49, // 10098 (0x2772)
        -1,
        -1,
        -1,
        -1,
        45, // 9991 (0x2707)
        82, // 11735 (0x2dd7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 9995 (0x270b)
        -1,
        -1,
        58, // 11631 (0x2d6f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 10763 (0x2a0b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        63, // 12183 (0x2f97)
        -1,
        -1,
        75, // 11094 (0x2b56)
        87, // 11966 (0x2ebe)
        -1,
        -1,
        -1,
        -1,
        92, // 14039 (0x36d7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 9791 (0x263f)
        25, // 9682 (0x25d2)
        -1,
        0, // 9683 (0x25d3)
        74, // 11209 (0x2bc9)
        -1,
        3, // 9030 (0x2346)
        73, // 11319 (0x2c37)
        -1,
        48, // 11102 (0x2b5e)
        -1,
        -1,
        9, // 9032 (0x2348)
        15, // 9032 (0x2348)
        24, // 9032 (0x2348)
        12, // 9033 (0x2349)
        18, // 9033 (0x2349)
        55, // 11104 (0x2b60)
        1, // 9034 (0x234a)
        7, // 9034 (0x234a)
        -1,
        14, // 9035 (0x234b)
        23, // 9035 (0x234b)
        26, // 9035 (0x234b)
        5, // 9036 (0x234c)
        10, // 9036 (0x234c)
        21, // 9036 (0x234c)
        20, // 9037 (0x234d)
        28, // 9037 (0x234d)
        -1,
        -1,
        -1,
        -1,
        4, // 9584 (0x2570)
        60, // 11437 (0x2cad)
        -1,
        27, // 9585 (0x2571)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 9587 (0x2573)
        -1,
        -1,
        34, // 9806 (0x264e)
        -1,
        -1,
        -1,
        -1,
        -1,
        69, // 12424 (0x3088)
        100, // 12751 (0x31cf)
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cplusplus_hash2, dataset=cplusplus, hash=hash2
void check_cplusplus_hash2() {
    assert(lookup_cplusplus_hash2("asm") == 30);
    assert(lookup_cplusplus_hash2("namespace") == 66);
    assert(lookup_cplusplus_hash2("and") == 31);
    assert(lookup_cplusplus_hash2("long") == 64);
    assert(lookup_cplusplus_hash2("operator") == 70);
    assert(lookup_cplusplus_hash2("__asm") == 2);
    assert(lookup_cplusplus_hash2("or_eq") == 72);
    assert(lookup_cplusplus_hash2("return") == 78);
    assert(lookup_cplusplus_hash2("__wchar_t") == 29);
    assert(lookup_cplusplus_hash2("enum") == 52);
    assert(lookup_cplusplus_hash2("__restrict") == 19);
    assert(lookup_cplusplus_hash2("mutable") == 65);
    assert(lookup_cplusplus_hash2("union") == 97);
    assert(lookup_cplusplus_hash2("compl") == 42);
    assert(lookup_cplusplus_hash2("or") == 71);
    assert(lookup_cplusplus_hash2("__signed") == 22);
    assert(lookup_cplusplus_hash2("new") == 67);
    assert(lookup_cplusplus_hash2("__const") == 8);
    assert(lookup_cplusplus_hash2("not") == 68);
    assert(lookup_cplusplus_hash2("__null") == 16);
    assert(lookup_cplusplus_hash2("__real") == 17);
    assert(lookup_cplusplus_hash2("bool") == 36);
    assert(lookup_cplusplus_hash2("break") == 37);
    assert(lookup_cplusplus_hash2("if") == 61);
    assert(lookup_cplusplus_hash2("volatile") == 102);
    assert(lookup_cplusplus_hash2("inline") == 62);
    assert(lookup_cplusplus_hash2("void") == 101);
    assert(lookup_cplusplus_hash2("while") == 103);
    assert(lookup_cplusplus_hash2("const_cast") == 44);
    assert(lookup_cplusplus_hash2("register") == 76);
    assert(lookup_cplusplus_hash2("const") == 43);
    assert(lookup_cplusplus_hash2("static_cast") == 85);
    assert(lookup_cplusplus_hash2("this") == 89);
    assert(lookup_cplusplus_hash2("short") == 79);
    assert(lookup_cplusplus_hash2("struct") == 86);
    assert(lookup_cplusplus_hash2("unsigned") == 98);
    assert(lookup_cplusplus_hash2("true") == 91);
    assert(lookup_cplusplus_hash2("xor_eq") == 105);
    assert(lookup_cplusplus_hash2("bitor") == 35);
    assert(lookup_cplusplus_hash2("export") == 54);
    assert(lookup_cplusplus_hash2("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash2("class") == 41);
    assert(lookup_cplusplus_hash2("signature") == 80);
    assert(lookup_cplusplus_hash2("typeid") == 95);
    assert(lookup_cplusplus_hash2("default") == 46);
    assert(lookup_cplusplus_hash2("false") == 56);
    assert(lookup_cplusplus_hash2("signed") == 81);
    assert(lookup_cplusplus_hash2("catch") == 39);
    assert(lookup_cplusplus_hash2("char") == 40);
    assert(lookup_cplusplus_hash2("static") == 84);
    assert(lookup_cplusplus_hash2("__complex") == 6);
    assert(lookup_cplusplus_hash2("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash2("xor") == 104);
    assert(lookup_cplusplus_hash2("explicit") == 53);
    assert(lookup_cplusplus_hash2("template") == 88);
    assert(lookup_cplusplus_hash2("typename") == 94);
    assert(lookup_cplusplus_hash2("using") == 99);
    assert(lookup_cplusplus_hash2("float") == 57);
    assert(lookup_cplusplus_hash2("typeof") == 96);
    assert(lookup_cplusplus_hash2("and_eq") == 32);
    assert(lookup_cplusplus_hash2("throw") == 90);
    assert(lookup_cplusplus_hash2("typedef") == 93);
    assert(lookup_cplusplus_hash2("else") == 51);
    assert(lookup_cplusplus_hash2("friend") == 59);
    assert(lookup_cplusplus_hash2("sizeof") == 83);
    assert(lookup_cplusplus_hash2("delete") == 47);
    assert(lookup_cplusplus_hash2("double") == 49);
    assert(lookup_cplusplus_hash2("continue") == 45);
    assert(lookup_cplusplus_hash2("sigof") == 82);
    assert(lookup_cplusplus_hash2("case") == 38);
    assert(lookup_cplusplus_hash2("for") == 58);
    assert(lookup_cplusplus_hash2("auto") == 33);
    assert(lookup_cplusplus_hash2("int") == 63);
    assert(lookup_cplusplus_hash2("public") == 75);
    assert(lookup_cplusplus_hash2("switch") == 87);
    assert(lookup_cplusplus_hash2("try") == 92);
    assert(lookup_cplusplus_hash2("__imag") == 11);
    assert(lookup_cplusplus_hash2("__typeof") == 25);
    assert(lookup_cplusplus_hash2("__alignof") == 0);
    assert(lookup_cplusplus_hash2("protected") == 74);
    assert(lookup_cplusplus_hash2("__asm__") == 3);
    assert(lookup_cplusplus_hash2("private") == 73);
    assert(lookup_cplusplus_hash2("do") == 48);
    assert(lookup_cplusplus_hash2("__const__") == 9);
    assert(lookup_cplusplus_hash2("__label__") == 15);
    assert(lookup_cplusplus_hash2("__sigof__") == 24);
    assert(lookup_cplusplus_hash2("__imag__") == 12);
    assert(lookup_cplusplus_hash2("__real__") == 18);
    assert(lookup_cplusplus_hash2("extern") == 55);
    assert(lookup_cplusplus_hash2("__alignof__") == 1);
    assert(lookup_cplusplus_hash2("__complex__") == 7);
    assert(lookup_cplusplus_hash2("__inline__") == 14);
    assert(lookup_cplusplus_hash2("__signed__") == 23);
    assert(lookup_cplusplus_hash2("__typeof__") == 26);
    assert(lookup_cplusplus_hash2("__attribute__") == 5);
    assert(lookup_cplusplus_hash2("__extension__") == 10);
    assert(lookup_cplusplus_hash2("__signature__") == 21);
    assert(lookup_cplusplus_hash2("__restrict__") == 20);
    assert(lookup_cplusplus_hash2("__volatile__") == 28);
    assert(lookup_cplusplus_hash2("__attribute") == 4);
    assert(lookup_cplusplus_hash2("goto") == 60);
    assert(lookup_cplusplus_hash2("__volatile") == 27);
    assert(lookup_cplusplus_hash2("__inline") == 13);
    assert(lookup_cplusplus_hash2("bitand") == 34);
    assert(lookup_cplusplus_hash2("not_eq") == 69);
    assert(lookup_cplusplus_hash2("virtual") == 100);
}

//lookup: name=lookup_cplusplus_hash3, dataset=cplusplus, hash=hash3
int lookup_cplusplus_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 132) * 3;
    static std::string_view lookup[396] = {
        "compl", // 26928 (0x6930)
        "throw", // 31284 (0x7a34)
        "volatile", // 32604 (0x7f5c)
        "sizeof", // 31285 (0x7a35)
        "",
        "",
        "",
        "",
        "",
        "asm", // 25875 (0x6513)
        "bitand", // 26931 (0x6933)
        "",
        "class", // 26932 (0x6934)
        "extern", // 27724 (0x6c4c)
        "",
        "short", // 31025 (0x7931)
        "",
        "",
        "template", // 32082 (0x7d52)
        "unsigned", // 32346 (0x7e5a)
        "",
        "typeid", // 31555 (0x7b43)
        "",
        "",
        "bitor", // 26672 (0x6830)
        "const", // 26936 (0x6938)
        "default", // 27728 (0x6c50)
        "static", // 31293 (0x7a3d)
        "typeof", // 31557 (0x7b45)
        "",
        "break", // 26674 (0x6832)
        "export", // 27730 (0x6c52)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "auto", // 26152 (0x6628)
        "",
        "",
        "__asm", // 25889 (0x6521)
        "switch", // 31301 (0x7a45)
        "",
        "or", // 29190 (0x7206)
        "typedef", // 31830 (0x7c56)
        "",
        "",
        "",
        "",
        "__imag", // 26156 (0x662c)
        "continue", // 27740 (0x6c5c)
        "",
        "__asm__", // 26421 (0x6735)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__null", // 26161 (0x6631)
        "__real", // 26161 (0x6631)
        "",
        "struct", // 31310 (0x7a4e)
        "typename", // 32102 (0x7d66)
        "",
        "new", // 29199 (0x720f)
        "signature", // 32103 (0x7d67)
        "",
        "explicit", // 28276 (0x6e74)
        "",
        "",
        "and_eq", // 26693 (0x6845)
        "",
        "",
        "__imag__", // 26694 (0x6846)
        "__real__", // 26694 (0x6846)
        "",
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
        "public", // 30526 (0x773e)
        "",
        "__signed", // 26699 (0x684b)
        "register", // 31583 (0x7b5f)
        "",
        "__inline", // 26700 (0x684c)
        "",
        "",
        "__typeof", // 26701 (0x684d)
        "",
        "",
        "",
        "",
        "",
        "__const__", // 26967 (0x6957)
        "__label__", // 26967 (0x6957)
        "__sigof__", // 26967 (0x6957)
        "",
        "",
        "",
        "",
        "",
        "",
        "__const", // 26442 (0x674a)
        "if", // 27630 (0x6bee)
        "private", // 30798 (0x784e)
        "",
        "",
        "",
        "or_eq", // 30008 (0x7538)
        "",
        "",
        "",
        "",
        "",
        "__alignof", // 26974 (0x695e)
        "long", // 28954 (0x711a)
        "",
        "",
        "",
        "",
        "__inline__", // 27240 (0x6a68)
        "__signed__", // 27240 (0x6a68)
        "__typeof__", // 27240 (0x6a68)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "const_cast", // 28301 (0x6e8d)
        "",
        "",
        "__volatile", // 27246 (0x6a6e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__alignof__", // 27513 (0x6b79)
        "__complex__", // 27513 (0x6b79)
        "",
        "not_eq", // 30022 (0x7546)
        "",
        "",
        "namespace", // 30815 (0x785f)
        "protected", // 31343 (0x7a6f)
        "",
        "__wchar_t", // 26988 (0x696c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute", // 27519 (0x6b7f)
        "",
        "",
        "__complex", // 26992 (0x6970)
        "",
        "",
        "",
        "",
        "",
        "__restrict__", // 27786 (0x6c8a)
        "__volatile__", // 27786 (0x6c8a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__restrict", // 27261 (0x6a7d)
        "mutable", // 30033 (0x7551)
        "",
        "operator", // 30826 (0x786a)
        "",
        "",
        "static_cast", // 32675 (0x7fa3)
        "",
        "",
        "",
        "",
        "",
        "dynamic_cast", // 29113 (0x71b9)
        "int", // 27925 (0x6d15)
        "",
        "",
        "",
        "",
        "__attribute__", // 28059 (0x6d9b)
        "__extension__", // 28059 (0x6d9b)
        "__signature__", // 28059 (0x6d9b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "xor", // 31764 (0x7c14)
        "",
        "",
        "inline", // 28729 (0x7039)
        "",
        "",
        "",
        "",
        "",
        "false", // 27675 (0x6c1b)
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
        "",
        "",
        "",
        "",
        "goto", // 27682 (0x6c22)
        "",
        "",
        "void", // 31511 (0x7b17)
        "",
        "",
        "for", // 27156 (0x6a14)
        "",
        "",
        "else", // 27157 (0x6a15)
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
        "",
        "",
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
        "",
        "",
        "",
        "enum", // 27167 (0x6a1f)
        "",
        "",
        "",
        "",
        "",
        "reinterpret_cast", // 33769 (0x83e9)
        "",
        "",
        "xor_eq", // 32582 (0x7f46)
        "",
        "",
        "",
        "",
        "",
        "friend", // 27964 (0x6d3c)
        "",
        "",
        "float", // 27701 (0x6c35)
        "",
        "",
        "catch", // 26910 (0x691e)
        "",
        "",
        "true", // 31003 (0x791b)
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
        "this", // 31007 (0x791f)
        "using", // 31535 (0x7b2f)
        "",
        "",
        "",
        "",
        "and", // 25861 (0x6505)
        "union", // 31537 (0x7b31)
        "",
        "char", // 26654 (0x681e)
        "",
        "",
        "",
        "",
        "",
        "sigof", // 31012 (0x7924)
        "virtual", // 32332 (0x7e4c)
        "",
        "",
        "",
        "",
        "double", // 27450 (0x6b3a)
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
        "bool", // 26399 (0x671f)
        "signed", // 31283 (0x7a33)
        "",
    };
    static int values[396] = {
        42, // 26928 (0x6930)
        90, // 31284 (0x7a34)
        102, // 32604 (0x7f5c)
        83, // 31285 (0x7a35)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 25875 (0x6513)
        34, // 26931 (0x6933)
        -1,
        41, // 26932 (0x6934)
        55, // 27724 (0x6c4c)
        -1,
        79, // 31025 (0x7931)
        -1,
        -1,
        88, // 32082 (0x7d52)
        98, // 32346 (0x7e5a)
        -1,
        95, // 31555 (0x7b43)
        -1,
        -1,
        35, // 26672 (0x6830)
        43, // 26936 (0x6938)
        46, // 27728 (0x6c50)
        84, // 31293 (0x7a3d)
        96, // 31557 (0x7b45)
        -1,
        37, // 26674 (0x6832)
        54, // 27730 (0x6c52)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        78, // 31033 (0x7939)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 26152 (0x6628)
        -1,
        -1,
        2, // 25889 (0x6521)
        87, // 31301 (0x7a45)
        -1,
        71, // 29190 (0x7206)
        93, // 31830 (0x7c56)
        -1,
        -1,
        -1,
        -1,
        11, // 26156 (0x662c)
        45, // 27740 (0x6c5c)
        -1,
        3, // 26421 (0x6735)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 26161 (0x6631)
        17, // 26161 (0x6631)
        -1,
        86, // 31310 (0x7a4e)
        94, // 32102 (0x7d66)
        -1,
        67, // 29199 (0x720f)
        80, // 32103 (0x7d67)
        -1,
        53, // 28276 (0x6e74)
        -1,
        -1,
        32, // 26693 (0x6845)
        -1,
        -1,
        12, // 26694 (0x6846)
        18, // 26694 (0x6846)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 29206 (0x7216)
        75, // 30526 (0x773e)
        -1,
        22, // 26699 (0x684b)
        76, // 31583 (0x7b5f)
        -1,
        13, // 26700 (0x684c)
        -1,
        -1,
        25, // 26701 (0x684d)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 26967 (0x6957)
        15, // 26967 (0x6957)
        24, // 26967 (0x6957)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 26442 (0x674a)
        61, // 27630 (0x6bee)
        73, // 30798 (0x784e)
        -1,
        -1,
        -1,
        72, // 30008 (0x7538)
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 26974 (0x695e)
        64, // 28954 (0x711a)
        -1,
        -1,
        -1,
        -1,
        14, // 27240 (0x6a68)
        23, // 27240 (0x6a68)
        26, // 27240 (0x6a68)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 28301 (0x6e8d)
        -1,
        -1,
        27, // 27246 (0x6a6e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 27513 (0x6b79)
        7, // 27513 (0x6b79)
        -1,
        69, // 30022 (0x7546)
        -1,
        -1,
        66, // 30815 (0x785f)
        74, // 31343 (0x7a6f)
        -1,
        29, // 26988 (0x696c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 27519 (0x6b7f)
        -1,
        -1,
        6, // 26992 (0x6970)
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 27786 (0x6c8a)
        28, // 27786 (0x6c8a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 27261 (0x6a7d)
        65, // 30033 (0x7551)
        -1,
        70, // 30826 (0x786a)
        -1,
        -1,
        85, // 32675 (0x7fa3)
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 29113 (0x71b9)
        63, // 27925 (0x6d15)
        -1,
        -1,
        -1,
        -1,
        5, // 28059 (0x6d9b)
        10, // 28059 (0x6d9b)
        21, // 28059 (0x6d9b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 31764 (0x7c14)
        -1,
        -1,
        62, // 28729 (0x7039)
        -1,
        -1,
        -1,
        -1,
        -1,
        56, // 27675 (0x6c1b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        103, // 32034 (0x7d22)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 27682 (0x6c22)
        -1,
        -1,
        101, // 31511 (0x7b17)
        -1,
        -1,
        58, // 27156 (0x6a14)
        -1,
        -1,
        51, // 27157 (0x6a15)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 26368 (0x6700)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 26634 (0x680a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 27167 (0x6a1f)
        -1,
        -1,
        -1,
        -1,
        -1,
        77, // 33769 (0x83e9)
        -1,
        -1,
        105, // 32582 (0x7f46)
        -1,
        -1,
        -1,
        -1,
        -1,
        59, // 27964 (0x6d3c)
        -1,
        -1,
        57, // 27701 (0x6c35)
        -1,
        -1,
        39, // 26910 (0x691e)
        -1,
        -1,
        91, // 31003 (0x791b)
        -1,
        -1,
        47, // 27440 (0x6b30)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 31007 (0x791f)
        99, // 31535 (0x7b2f)
        -1,
        -1,
        -1,
        -1,
        31, // 25861 (0x6505)
        97, // 31537 (0x7b31)
        -1,
        40, // 26654 (0x681e)
        -1,
        -1,
        -1,
        -1,
        -1,
        82, // 31012 (0x7924)
        100, // 32332 (0x7e4c)
        -1,
        -1,
        -1,
        -1,
        49, // 27450 (0x6b3a)
        92, // 30750 (0x781e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 26399 (0x671f)
        81, // 31283 (0x7a33)
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cplusplus_hash3, dataset=cplusplus, hash=hash3
void check_cplusplus_hash3() {
    assert(lookup_cplusplus_hash3("compl") == 42);
    assert(lookup_cplusplus_hash3("throw") == 90);
    assert(lookup_cplusplus_hash3("volatile") == 102);
    assert(lookup_cplusplus_hash3("sizeof") == 83);
    assert(lookup_cplusplus_hash3("asm") == 30);
    assert(lookup_cplusplus_hash3("bitand") == 34);
    assert(lookup_cplusplus_hash3("class") == 41);
    assert(lookup_cplusplus_hash3("extern") == 55);
    assert(lookup_cplusplus_hash3("short") == 79);
    assert(lookup_cplusplus_hash3("template") == 88);
    assert(lookup_cplusplus_hash3("unsigned") == 98);
    assert(lookup_cplusplus_hash3("typeid") == 95);
    assert(lookup_cplusplus_hash3("bitor") == 35);
    assert(lookup_cplusplus_hash3("const") == 43);
    assert(lookup_cplusplus_hash3("default") == 46);
    assert(lookup_cplusplus_hash3("static") == 84);
    assert(lookup_cplusplus_hash3("typeof") == 96);
    assert(lookup_cplusplus_hash3("break") == 37);
    assert(lookup_cplusplus_hash3("export") == 54);
    assert(lookup_cplusplus_hash3("return") == 78);
    assert(lookup_cplusplus_hash3("auto") == 33);
    assert(lookup_cplusplus_hash3("__asm") == 2);
    assert(lookup_cplusplus_hash3("switch") == 87);
    assert(lookup_cplusplus_hash3("or") == 71);
    assert(lookup_cplusplus_hash3("typedef") == 93);
    assert(lookup_cplusplus_hash3("__imag") == 11);
    assert(lookup_cplusplus_hash3("continue") == 45);
    assert(lookup_cplusplus_hash3("__asm__") == 3);
    assert(lookup_cplusplus_hash3("__null") == 16);
    assert(lookup_cplusplus_hash3("__real") == 17);
    assert(lookup_cplusplus_hash3("struct") == 86);
    assert(lookup_cplusplus_hash3("typename") == 94);
    assert(lookup_cplusplus_hash3("new") == 67);
    assert(lookup_cplusplus_hash3("signature") == 80);
    assert(lookup_cplusplus_hash3("explicit") == 53);
    assert(lookup_cplusplus_hash3("and_eq") == 32);
    assert(lookup_cplusplus_hash3("__imag__") == 12);
    assert(lookup_cplusplus_hash3("__real__") == 18);
    assert(lookup_cplusplus_hash3("not") == 68);
    assert(lookup_cplusplus_hash3("public") == 75);
    assert(lookup_cplusplus_hash3("__signed") == 22);
    assert(lookup_cplusplus_hash3("register") == 76);
    assert(lookup_cplusplus_hash3("__inline") == 13);
    assert(lookup_cplusplus_hash3("__typeof") == 25);
    assert(lookup_cplusplus_hash3("__const__") == 9);
    assert(lookup_cplusplus_hash3("__label__") == 15);
    assert(lookup_cplusplus_hash3("__sigof__") == 24);
    assert(lookup_cplusplus_hash3("__const") == 8);
    assert(lookup_cplusplus_hash3("if") == 61);
    assert(lookup_cplusplus_hash3("private") == 73);
    assert(lookup_cplusplus_hash3("or_eq") == 72);
    assert(lookup_cplusplus_hash3("__alignof") == 0);
    assert(lookup_cplusplus_hash3("long") == 64);
    assert(lookup_cplusplus_hash3("__inline__") == 14);
    assert(lookup_cplusplus_hash3("__signed__") == 23);
    assert(lookup_cplusplus_hash3("__typeof__") == 26);
    assert(lookup_cplusplus_hash3("const_cast") == 44);
    assert(lookup_cplusplus_hash3("__volatile") == 27);
    assert(lookup_cplusplus_hash3("__alignof__") == 1);
    assert(lookup_cplusplus_hash3("__complex__") == 7);
    assert(lookup_cplusplus_hash3("not_eq") == 69);
    assert(lookup_cplusplus_hash3("namespace") == 66);
    assert(lookup_cplusplus_hash3("protected") == 74);
    assert(lookup_cplusplus_hash3("__wchar_t") == 29);
    assert(lookup_cplusplus_hash3("__attribute") == 4);
    assert(lookup_cplusplus_hash3("__complex") == 6);
    assert(lookup_cplusplus_hash3("__restrict__") == 20);
    assert(lookup_cplusplus_hash3("__volatile__") == 28);
    assert(lookup_cplusplus_hash3("__restrict") == 19);
    assert(lookup_cplusplus_hash3("mutable") == 65);
    assert(lookup_cplusplus_hash3("operator") == 70);
    assert(lookup_cplusplus_hash3("static_cast") == 85);
    assert(lookup_cplusplus_hash3("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash3("int") == 63);
    assert(lookup_cplusplus_hash3("__attribute__") == 5);
    assert(lookup_cplusplus_hash3("__extension__") == 10);
    assert(lookup_cplusplus_hash3("__signature__") == 21);
    assert(lookup_cplusplus_hash3("xor") == 104);
    assert(lookup_cplusplus_hash3("inline") == 62);
    assert(lookup_cplusplus_hash3("false") == 56);
    assert(lookup_cplusplus_hash3("while") == 103);
    assert(lookup_cplusplus_hash3("goto") == 60);
    assert(lookup_cplusplus_hash3("void") == 101);
    assert(lookup_cplusplus_hash3("for") == 58);
    assert(lookup_cplusplus_hash3("else") == 51);
    assert(lookup_cplusplus_hash3("do") == 48);
    assert(lookup_cplusplus_hash3("case") == 38);
    assert(lookup_cplusplus_hash3("enum") == 52);
    assert(lookup_cplusplus_hash3("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash3("xor_eq") == 105);
    assert(lookup_cplusplus_hash3("friend") == 59);
    assert(lookup_cplusplus_hash3("float") == 57);
    assert(lookup_cplusplus_hash3("catch") == 39);
    assert(lookup_cplusplus_hash3("true") == 91);
    assert(lookup_cplusplus_hash3("delete") == 47);
    assert(lookup_cplusplus_hash3("this") == 89);
    assert(lookup_cplusplus_hash3("using") == 99);
    assert(lookup_cplusplus_hash3("and") == 31);
    assert(lookup_cplusplus_hash3("union") == 97);
    assert(lookup_cplusplus_hash3("char") == 40);
    assert(lookup_cplusplus_hash3("sigof") == 82);
    assert(lookup_cplusplus_hash3("virtual") == 100);
    assert(lookup_cplusplus_hash3("double") == 49);
    assert(lookup_cplusplus_hash3("try") == 92);
    assert(lookup_cplusplus_hash3("bool") == 36);
    assert(lookup_cplusplus_hash3("signed") == 81);
}

//lookup: name=lookup_cplusplus_hash_sum0, dataset=cplusplus, hash=hash_sum0
int lookup_cplusplus_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 116) * 3;
    static std::string_view lookup[348] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__const__", // 931 (0x3a3)
        "try", // 351 (0x15f)
        "",
        "",
        "",
        "",
        "__asm__", // 701 (0x2bd)
        "",
        "",
        "__wchar_t", // 934 (0x3a6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute", // 1170 (0x492)
        "__volatile", // 1054 (0x41e)
        "static_cast", // 1170 (0x492)
        "",
        "",
        "",
        "__signed", // 824 (0x338)
        "",
        "",
        "namespace", // 941 (0x3ad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__inline", // 829 (0x33d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__complex", // 950 (0x3b6)
        "",
        "",
        "",
        "",
        "",
        "__imag", // 604 (0x25c)
        "",
        "",
        "",
        "",
        "",
        "__restrict", // 1070 (0x42e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "const_cast", // 1073 (0x431)
        "",
        "",
        "__real", // 610 (0x262)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "and_eq", // 616 (0x268)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__typeof", // 853 (0x355)
        "",
        "",
        "protected", // 970 (0x3ca)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__const", // 741 (0x2e5)
        "default", // 741 (0x2e5)
        "",
        "bitand", // 626 (0x272)
        "",
        "",
        "__asm", // 511 (0x1ff)
        "delete", // 627 (0x273)
        "",
        "template", // 860 (0x35c)
        "",
        "",
        "unsigned", // 861 (0x35d)
        "",
        "",
        "mutable", // 746 (0x2ea)
        "signature", // 978 (0x3d2)
        "",
        "catch", // 515 (0x203)
        "",
        "",
        "friend", // 632 (0x278)
        "volatile", // 864 (0x360)
        "",
        "__null", // 633 (0x279)
        "break", // 517 (0x205)
        "",
        "explicit", // 866 (0x362)
        "signed", // 634 (0x27a)
        "",
        "double", // 635 (0x27b)
        "typename", // 867 (0x363)
        "",
        "",
        "",
        "",
        "continue", // 869 (0x365)
        "register", // 869 (0x365)
        "typedef", // 753 (0x2f1)
        "",
        "",
        "",
        "false", // 523 (0x20b)
        "inline", // 639 (0x27f)
        "public", // 639 (0x27f)
        "",
        "",
        "",
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
        "operator", // 876 (0x36c)
        "",
        "",
        "",
        "",
        "char", // 414 (0x19e)
        "not_eq", // 646 (0x286)
        "",
        "private", // 763 (0x2fb)
        "",
        "",
        "static", // 648 (0x288)
        "",
        "",
        "",
        "",
        "",
        "class", // 534 (0x216)
        "float", // 534 (0x216)
        "or_eq", // 534 (0x216)
        "",
        "",
        "",
        "__alignof__", // 1116 (0x45c)
        "sigof", // 536 (0x218)
        "",
        "while", // 537 (0x219)
        "",
        "",
        "xor_eq", // 654 (0x28e)
        "",
        "",
        "and", // 307 (0x133)
        "compl", // 539 (0x21b)
        "typeid", // 655 (0x28f)
        "sizeof", // 656 (0x290)
        "",
        "",
        "else", // 425 (0x1a9)
        "",
        "",
        "switch", // 658 (0x292)
        "",
        "",
        "virtual", // 775 (0x307)
        "",
        "",
        "__label__", // 892 (0x37c)
        "bitor", // 544 (0x220)
        "bool", // 428 (0x1ac)
        "",
        "",
        "",
        "__signature__", // 1358 (0x54e)
        "extern", // 662 (0x296)
        "",
        "typeof", // 663 (0x297)
        "",
        "",
        "__attribute__", // 1360 (0x550)
        "__volatile__", // 1244 (0x4dc)
        "long", // 432 (0x1b0)
        "",
        "",
        "",
        "__signed__", // 1014 (0x3f6)
        "using", // 550 (0x226)
        "void", // 434 (0x1b2)
        "const", // 551 (0x227)
        "",
        "",
        "",
        "",
        "",
        "asm", // 321 (0x141)
        "enum", // 437 (0x1b5)
        "union", // 553 (0x229)
        "",
        "",
        "",
        "__inline__", // 1019 (0x3fb)
        "if", // 207 (0xcf)
        "",
        "return", // 672 (0x2a0)
        "this", // 440 (0x1b8)
        "",
        "__extension__", // 1369 (0x559)
        "auto", // 441 (0x1b9)
        "goto", // 441 (0x1b9)
        "export", // 674 (0x2a2)
        "",
        "",
        "do", // 211 (0xd3)
        "for", // 327 (0x147)
        "",
        "__complex__", // 1140 (0x474)
        "short", // 560 (0x230)
        "",
        "struct", // 677 (0x2a5)
        "",
        "",
        "__imag__", // 794 (0x31a)
        "new", // 330 (0x14a)
        "",
        "int", // 331 (0x14b)
        "",
        "",
        "__restrict__", // 1260 (0x4ec)
        "throw", // 564 (0x234)
        "true", // 448 (0x1c0)
        "",
        "",
        "",
        "reinterpret_cast", // 1726 (0x6be)
        "",
        "",
        "dynamic_cast", // 1263 (0x4ef)
        "",
        "",
        "__real__", // 800 (0x320)
        "__sigof__", // 916 (0x394)
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
        "or", // 225 (0xe1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "xor", // 345 (0x159)
        "",
        "",
        "__alignof", // 926 (0x39e)
        "",
        "",
        "__typeof__", // 1043 (0x413)
        "",
        "",
    };
    static int values[348] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 931 (0x3a3)
        92, // 351 (0x15f)
        -1,
        -1,
        -1,
        -1,
        3, // 701 (0x2bd)
        -1,
        -1,
        29, // 934 (0x3a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 1170 (0x492)
        27, // 1054 (0x41e)
        85, // 1170 (0x492)
        -1,
        -1,
        -1,
        22, // 824 (0x338)
        -1,
        -1,
        66, // 941 (0x3ad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 829 (0x33d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 950 (0x3b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 604 (0x25c)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 1070 (0x42e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 1073 (0x431)
        -1,
        -1,
        17, // 610 (0x262)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 616 (0x268)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 853 (0x355)
        -1,
        -1,
        74, // 970 (0x3ca)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 741 (0x2e5)
        46, // 741 (0x2e5)
        -1,
        34, // 626 (0x272)
        -1,
        -1,
        2, // 511 (0x1ff)
        47, // 627 (0x273)
        -1,
        88, // 860 (0x35c)
        -1,
        -1,
        98, // 861 (0x35d)
        -1,
        -1,
        65, // 746 (0x2ea)
        80, // 978 (0x3d2)
        -1,
        39, // 515 (0x203)
        -1,
        -1,
        59, // 632 (0x278)
        102, // 864 (0x360)
        -1,
        16, // 633 (0x279)
        37, // 517 (0x205)
        -1,
        53, // 866 (0x362)
        81, // 634 (0x27a)
        -1,
        49, // 635 (0x27b)
        94, // 867 (0x363)
        -1,
        -1,
        -1,
        -1,
        45, // 869 (0x365)
        76, // 869 (0x365)
        93, // 753 (0x2f1)
        -1,
        -1,
        -1,
        56, // 523 (0x20b)
        62, // 639 (0x27f)
        75, // 639 (0x27f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 412 (0x19c)
        70, // 876 (0x36c)
        -1,
        -1,
        -1,
        -1,
        40, // 414 (0x19e)
        69, // 646 (0x286)
        -1,
        73, // 763 (0x2fb)
        -1,
        -1,
        84, // 648 (0x288)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 534 (0x216)
        57, // 534 (0x216)
        72, // 534 (0x216)
        -1,
        -1,
        -1,
        1, // 1116 (0x45c)
        82, // 536 (0x218)
        -1,
        103, // 537 (0x219)
        -1,
        -1,
        105, // 654 (0x28e)
        -1,
        -1,
        31, // 307 (0x133)
        42, // 539 (0x21b)
        95, // 655 (0x28f)
        83, // 656 (0x290)
        -1,
        -1,
        51, // 425 (0x1a9)
        -1,
        -1,
        87, // 658 (0x292)
        -1,
        -1,
        100, // 775 (0x307)
        -1,
        -1,
        15, // 892 (0x37c)
        35, // 544 (0x220)
        36, // 428 (0x1ac)
        -1,
        -1,
        -1,
        21, // 1358 (0x54e)
        55, // 662 (0x296)
        -1,
        96, // 663 (0x297)
        -1,
        -1,
        5, // 1360 (0x550)
        28, // 1244 (0x4dc)
        64, // 432 (0x1b0)
        -1,
        -1,
        -1,
        23, // 1014 (0x3f6)
        99, // 550 (0x226)
        101, // 434 (0x1b2)
        43, // 551 (0x227)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 321 (0x141)
        52, // 437 (0x1b5)
        97, // 553 (0x229)
        -1,
        -1,
        -1,
        14, // 1019 (0x3fb)
        61, // 207 (0xcf)
        -1,
        78, // 672 (0x2a0)
        89, // 440 (0x1b8)
        -1,
        10, // 1369 (0x559)
        33, // 441 (0x1b9)
        60, // 441 (0x1b9)
        54, // 674 (0x2a2)
        -1,
        -1,
        48, // 211 (0xd3)
        58, // 327 (0x147)
        -1,
        7, // 1140 (0x474)
        79, // 560 (0x230)
        -1,
        86, // 677 (0x2a5)
        -1,
        -1,
        12, // 794 (0x31a)
        67, // 330 (0x14a)
        -1,
        63, // 331 (0x14b)
        -1,
        -1,
        20, // 1260 (0x4ec)
        90, // 564 (0x234)
        91, // 448 (0x1c0)
        -1,
        -1,
        -1,
        77, // 1726 (0x6be)
        -1,
        -1,
        50, // 1263 (0x4ef)
        -1,
        -1,
        18, // 800 (0x320)
        24, // 916 (0x394)
        -1,
        68, // 337 (0x151)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 225 (0xe1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 345 (0x159)
        -1,
        -1,
        0, // 926 (0x39e)
        -1,
        -1,
        26, // 1043 (0x413)
        -1,
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cplusplus_hash_sum0, dataset=cplusplus, hash=hash_sum0
void check_cplusplus_hash_sum0() {
    assert(lookup_cplusplus_hash_sum0("__const__") == 9);
    assert(lookup_cplusplus_hash_sum0("try") == 92);
    assert(lookup_cplusplus_hash_sum0("__asm__") == 3);
    assert(lookup_cplusplus_hash_sum0("__wchar_t") == 29);
    assert(lookup_cplusplus_hash_sum0("__attribute") == 4);
    assert(lookup_cplusplus_hash_sum0("__volatile") == 27);
    assert(lookup_cplusplus_hash_sum0("static_cast") == 85);
    assert(lookup_cplusplus_hash_sum0("__signed") == 22);
    assert(lookup_cplusplus_hash_sum0("namespace") == 66);
    assert(lookup_cplusplus_hash_sum0("__inline") == 13);
    assert(lookup_cplusplus_hash_sum0("__complex") == 6);
    assert(lookup_cplusplus_hash_sum0("__imag") == 11);
    assert(lookup_cplusplus_hash_sum0("__restrict") == 19);
    assert(lookup_cplusplus_hash_sum0("const_cast") == 44);
    assert(lookup_cplusplus_hash_sum0("__real") == 17);
    assert(lookup_cplusplus_hash_sum0("and_eq") == 32);
    assert(lookup_cplusplus_hash_sum0("__typeof") == 25);
    assert(lookup_cplusplus_hash_sum0("protected") == 74);
    assert(lookup_cplusplus_hash_sum0("__const") == 8);
    assert(lookup_cplusplus_hash_sum0("default") == 46);
    assert(lookup_cplusplus_hash_sum0("bitand") == 34);
    assert(lookup_cplusplus_hash_sum0("__asm") == 2);
    assert(lookup_cplusplus_hash_sum0("delete") == 47);
    assert(lookup_cplusplus_hash_sum0("template") == 88);
    assert(lookup_cplusplus_hash_sum0("unsigned") == 98);
    assert(lookup_cplusplus_hash_sum0("mutable") == 65);
    assert(lookup_cplusplus_hash_sum0("signature") == 80);
    assert(lookup_cplusplus_hash_sum0("catch") == 39);
    assert(lookup_cplusplus_hash_sum0("friend") == 59);
    assert(lookup_cplusplus_hash_sum0("volatile") == 102);
    assert(lookup_cplusplus_hash_sum0("__null") == 16);
    assert(lookup_cplusplus_hash_sum0("break") == 37);
    assert(lookup_cplusplus_hash_sum0("explicit") == 53);
    assert(lookup_cplusplus_hash_sum0("signed") == 81);
    assert(lookup_cplusplus_hash_sum0("double") == 49);
    assert(lookup_cplusplus_hash_sum0("typename") == 94);
    assert(lookup_cplusplus_hash_sum0("continue") == 45);
    assert(lookup_cplusplus_hash_sum0("register") == 76);
    assert(lookup_cplusplus_hash_sum0("typedef") == 93);
    assert(lookup_cplusplus_hash_sum0("false") == 56);
    assert(lookup_cplusplus_hash_sum0("inline") == 62);
    assert(lookup_cplusplus_hash_sum0("public") == 75);
    assert(lookup_cplusplus_hash_sum0("case") == 38);
    assert(lookup_cplusplus_hash_sum0("operator") == 70);
    assert(lookup_cplusplus_hash_sum0("char") == 40);
    assert(lookup_cplusplus_hash_sum0("not_eq") == 69);
    assert(lookup_cplusplus_hash_sum0("private") == 73);
    assert(lookup_cplusplus_hash_sum0("static") == 84);
    assert(lookup_cplusplus_hash_sum0("class") == 41);
    assert(lookup_cplusplus_hash_sum0("float") == 57);
    assert(lookup_cplusplus_hash_sum0("or_eq") == 72);
    assert(lookup_cplusplus_hash_sum0("__alignof__") == 1);
    assert(lookup_cplusplus_hash_sum0("sigof") == 82);
    assert(lookup_cplusplus_hash_sum0("while") == 103);
    assert(lookup_cplusplus_hash_sum0("xor_eq") == 105);
    assert(lookup_cplusplus_hash_sum0("and") == 31);
    assert(lookup_cplusplus_hash_sum0("compl") == 42);
    assert(lookup_cplusplus_hash_sum0("typeid") == 95);
    assert(lookup_cplusplus_hash_sum0("sizeof") == 83);
    assert(lookup_cplusplus_hash_sum0("else") == 51);
    assert(lookup_cplusplus_hash_sum0("switch") == 87);
    assert(lookup_cplusplus_hash_sum0("virtual") == 100);
    assert(lookup_cplusplus_hash_sum0("__label__") == 15);
    assert(lookup_cplusplus_hash_sum0("bitor") == 35);
    assert(lookup_cplusplus_hash_sum0("bool") == 36);
    assert(lookup_cplusplus_hash_sum0("__signature__") == 21);
    assert(lookup_cplusplus_hash_sum0("extern") == 55);
    assert(lookup_cplusplus_hash_sum0("typeof") == 96);
    assert(lookup_cplusplus_hash_sum0("__attribute__") == 5);
    assert(lookup_cplusplus_hash_sum0("__volatile__") == 28);
    assert(lookup_cplusplus_hash_sum0("long") == 64);
    assert(lookup_cplusplus_hash_sum0("__signed__") == 23);
    assert(lookup_cplusplus_hash_sum0("using") == 99);
    assert(lookup_cplusplus_hash_sum0("void") == 101);
    assert(lookup_cplusplus_hash_sum0("const") == 43);
    assert(lookup_cplusplus_hash_sum0("asm") == 30);
    assert(lookup_cplusplus_hash_sum0("enum") == 52);
    assert(lookup_cplusplus_hash_sum0("union") == 97);
    assert(lookup_cplusplus_hash_sum0("__inline__") == 14);
    assert(lookup_cplusplus_hash_sum0("if") == 61);
    assert(lookup_cplusplus_hash_sum0("return") == 78);
    assert(lookup_cplusplus_hash_sum0("this") == 89);
    assert(lookup_cplusplus_hash_sum0("__extension__") == 10);
    assert(lookup_cplusplus_hash_sum0("auto") == 33);
    assert(lookup_cplusplus_hash_sum0("goto") == 60);
    assert(lookup_cplusplus_hash_sum0("export") == 54);
    assert(lookup_cplusplus_hash_sum0("do") == 48);
    assert(lookup_cplusplus_hash_sum0("for") == 58);
    assert(lookup_cplusplus_hash_sum0("__complex__") == 7);
    assert(lookup_cplusplus_hash_sum0("short") == 79);
    assert(lookup_cplusplus_hash_sum0("struct") == 86);
    assert(lookup_cplusplus_hash_sum0("__imag__") == 12);
    assert(lookup_cplusplus_hash_sum0("new") == 67);
    assert(lookup_cplusplus_hash_sum0("int") == 63);
    assert(lookup_cplusplus_hash_sum0("__restrict__") == 20);
    assert(lookup_cplusplus_hash_sum0("throw") == 90);
    assert(lookup_cplusplus_hash_sum0("true") == 91);
    assert(lookup_cplusplus_hash_sum0("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash_sum0("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash_sum0("__real__") == 18);
    assert(lookup_cplusplus_hash_sum0("__sigof__") == 24);
    assert(lookup_cplusplus_hash_sum0("not") == 68);
    assert(lookup_cplusplus_hash_sum0("or") == 71);
    assert(lookup_cplusplus_hash_sum0("xor") == 104);
    assert(lookup_cplusplus_hash_sum0("__alignof") == 0);
    assert(lookup_cplusplus_hash_sum0("__typeof__") == 26);
}

//lookup: name=lookup_cplusplus_hash_sumN, dataset=cplusplus, hash=hash_sumN
int lookup_cplusplus_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 117) * 3;
    static std::string_view lookup[351] = {
        "__typeof__", // 1053 (0x41d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "try", // 354 (0x162)
        "",
        "",
        "__const__", // 940 (0x3ac)
        "",
        "",
        "",
        "",
        "",
        "__asm__", // 708 (0x2c4)
        "",
        "",
        "__wchar_t", // 943 (0x3af)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute", // 1181 (0x49d)
        "__volatile", // 1064 (0x428)
        "static_cast", // 1181 (0x49d)
        "",
        "",
        "",
        "__signed", // 832 (0x340)
        "",
        "",
        "namespace", // 950 (0x3b6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__inline", // 837 (0x345)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__complex", // 959 (0x3bf)
        "",
        "",
        "",
        "",
        "",
        "__imag", // 610 (0x262)
        "",
        "",
        "",
        "",
        "",
        "__restrict", // 1080 (0x438)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "const_cast", // 1083 (0x43b)
        "",
        "",
        "__real", // 616 (0x268)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "and_eq", // 622 (0x26e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__typeof", // 861 (0x35d)
        "",
        "",
        "protected", // 979 (0x3d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__const", // 748 (0x2ec)
        "default", // 748 (0x2ec)
        "",
        "bitand", // 632 (0x278)
        "",
        "",
        "__asm", // 516 (0x204)
        "delete", // 633 (0x279)
        "",
        "template", // 868 (0x364)
        "",
        "",
        "unsigned", // 869 (0x365)
        "",
        "",
        "mutable", // 753 (0x2f1)
        "signature", // 987 (0x3db)
        "",
        "catch", // 520 (0x208)
        "",
        "",
        "friend", // 638 (0x27e)
        "volatile", // 872 (0x368)
        "",
        "__null", // 639 (0x27f)
        "break", // 522 (0x20a)
        "",
        "explicit", // 874 (0x36a)
        "signed", // 640 (0x280)
        "",
        "double", // 641 (0x281)
        "typename", // 875 (0x36b)
        "",
        "",
        "",
        "",
        "continue", // 877 (0x36d)
        "register", // 877 (0x36d)
        "typedef", // 760 (0x2f8)
        "",
        "",
        "",
        "false", // 528 (0x210)
        "inline", // 645 (0x285)
        "public", // 645 (0x285)
        "",
        "",
        "",
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
        "operator", // 884 (0x374)
        "",
        "",
        "",
        "",
        "char", // 418 (0x1a2)
        "not_eq", // 652 (0x28c)
        "",
        "private", // 770 (0x302)
        "",
        "",
        "static", // 654 (0x28e)
        "",
        "",
        "",
        "",
        "",
        "class", // 539 (0x21b)
        "float", // 539 (0x21b)
        "or_eq", // 539 (0x21b)
        "",
        "",
        "",
        "sigof", // 541 (0x21d)
        "",
        "",
        "__alignof__", // 1127 (0x467)
        "while", // 542 (0x21e)
        "",
        "xor_eq", // 660 (0x294)
        "",
        "",
        "and", // 310 (0x136)
        "compl", // 544 (0x220)
        "typeid", // 661 (0x295)
        "sizeof", // 662 (0x296)
        "",
        "",
        "else", // 429 (0x1ad)
        "",
        "",
        "switch", // 664 (0x298)
        "",
        "",
        "virtual", // 782 (0x30e)
        "",
        "",
        "bitor", // 549 (0x225)
        "bool", // 432 (0x1b0)
        "",
        "__label__", // 901 (0x385)
        "",
        "",
        "extern", // 668 (0x29c)
        "",
        "",
        "__signature__", // 1371 (0x55b)
        "typeof", // 669 (0x29d)
        "",
        "long", // 436 (0x1b4)
        "",
        "",
        "__attribute__", // 1373 (0x55d)
        "__volatile__", // 1256 (0x4e8)
        "",
        "using", // 555 (0x22b)
        "void", // 438 (0x1b6)
        "",
        "__signed__", // 1024 (0x400)
        "const", // 556 (0x22c)
        "",
        "",
        "",
        "",
        "asm", // 324 (0x144)
        "enum", // 441 (0x1b9)
        "union", // 558 (0x22e)
        "",
        "",
        "",
        "if", // 209 (0xd1)
        "",
        "",
        "__inline__", // 1029 (0x405)
        "return", // 678 (0x2a6)
        "this", // 444 (0x1bc)
        "auto", // 445 (0x1bd)
        "goto", // 445 (0x1bd)
        "",
        "__extension__", // 1382 (0x566)
        "export", // 680 (0x2a8)
        "",
        "do", // 213 (0xd5)
        "for", // 330 (0x14a)
        "",
        "short", // 565 (0x235)
        "",
        "",
        "__complex__", // 1151 (0x47f)
        "struct", // 683 (0x2ab)
        "",
        "new", // 333 (0x14d)
        "",
        "",
        "__imag__", // 802 (0x322)
        "int", // 334 (0x14e)
        "",
        "throw", // 569 (0x239)
        "true", // 452 (0x1c4)
        "",
        "__restrict__", // 1272 (0x4f8)
        "",
        "",
        "",
        "",
        "",
        "reinterpret_cast", // 1742 (0x6ce)
        "",
        "",
        "dynamic_cast", // 1275 (0x4fb)
        "",
        "",
        "__real__", // 808 (0x328)
        "__sigof__", // 925 (0x39d)
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
        "or", // 227 (0xe3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "xor", // 348 (0x15c)
        "",
        "",
        "",
        "",
        "",
        "__alignof", // 935 (0x3a7)
        "",
        "",
    };
    static int values[351] = {
        26, // 1053 (0x41d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 354 (0x162)
        -1,
        -1,
        9, // 940 (0x3ac)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 708 (0x2c4)
        -1,
        -1,
        29, // 943 (0x3af)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 1181 (0x49d)
        27, // 1064 (0x428)
        85, // 1181 (0x49d)
        -1,
        -1,
        -1,
        22, // 832 (0x340)
        -1,
        -1,
        66, // 950 (0x3b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 837 (0x345)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 959 (0x3bf)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 610 (0x262)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 1080 (0x438)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 1083 (0x43b)
        -1,
        -1,
        17, // 616 (0x268)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 622 (0x26e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 861 (0x35d)
        -1,
        -1,
        74, // 979 (0x3d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 748 (0x2ec)
        46, // 748 (0x2ec)
        -1,
        34, // 632 (0x278)
        -1,
        -1,
        2, // 516 (0x204)
        47, // 633 (0x279)
        -1,
        88, // 868 (0x364)
        -1,
        -1,
        98, // 869 (0x365)
        -1,
        -1,
        65, // 753 (0x2f1)
        80, // 987 (0x3db)
        -1,
        39, // 520 (0x208)
        -1,
        -1,
        59, // 638 (0x27e)
        102, // 872 (0x368)
        -1,
        16, // 639 (0x27f)
        37, // 522 (0x20a)
        -1,
        53, // 874 (0x36a)
        81, // 640 (0x280)
        -1,
        49, // 641 (0x281)
        94, // 875 (0x36b)
        -1,
        -1,
        -1,
        -1,
        45, // 877 (0x36d)
        76, // 877 (0x36d)
        93, // 760 (0x2f8)
        -1,
        -1,
        -1,
        56, // 528 (0x210)
        62, // 645 (0x285)
        75, // 645 (0x285)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 416 (0x1a0)
        70, // 884 (0x374)
        -1,
        -1,
        -1,
        -1,
        40, // 418 (0x1a2)
        69, // 652 (0x28c)
        -1,
        73, // 770 (0x302)
        -1,
        -1,
        84, // 654 (0x28e)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 539 (0x21b)
        57, // 539 (0x21b)
        72, // 539 (0x21b)
        -1,
        -1,
        -1,
        82, // 541 (0x21d)
        -1,
        -1,
        1, // 1127 (0x467)
        103, // 542 (0x21e)
        -1,
        105, // 660 (0x294)
        -1,
        -1,
        31, // 310 (0x136)
        42, // 544 (0x220)
        95, // 661 (0x295)
        83, // 662 (0x296)
        -1,
        -1,
        51, // 429 (0x1ad)
        -1,
        -1,
        87, // 664 (0x298)
        -1,
        -1,
        100, // 782 (0x30e)
        -1,
        -1,
        35, // 549 (0x225)
        36, // 432 (0x1b0)
        -1,
        15, // 901 (0x385)
        -1,
        -1,
        55, // 668 (0x29c)
        -1,
        -1,
        21, // 1371 (0x55b)
        96, // 669 (0x29d)
        -1,
        64, // 436 (0x1b4)
        -1,
        -1,
        5, // 1373 (0x55d)
        28, // 1256 (0x4e8)
        -1,
        99, // 555 (0x22b)
        101, // 438 (0x1b6)
        -1,
        23, // 1024 (0x400)
        43, // 556 (0x22c)
        -1,
        -1,
        -1,
        -1,
        30, // 324 (0x144)
        52, // 441 (0x1b9)
        97, // 558 (0x22e)
        -1,
        -1,
        -1,
        61, // 209 (0xd1)
        -1,
        -1,
        14, // 1029 (0x405)
        78, // 678 (0x2a6)
        89, // 444 (0x1bc)
        33, // 445 (0x1bd)
        60, // 445 (0x1bd)
        -1,
        10, // 1382 (0x566)
        54, // 680 (0x2a8)
        -1,
        48, // 213 (0xd5)
        58, // 330 (0x14a)
        -1,
        79, // 565 (0x235)
        -1,
        -1,
        7, // 1151 (0x47f)
        86, // 683 (0x2ab)
        -1,
        67, // 333 (0x14d)
        -1,
        -1,
        12, // 802 (0x322)
        63, // 334 (0x14e)
        -1,
        90, // 569 (0x239)
        91, // 452 (0x1c4)
        -1,
        20, // 1272 (0x4f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        77, // 1742 (0x6ce)
        -1,
        -1,
        50, // 1275 (0x4fb)
        -1,
        -1,
        18, // 808 (0x328)
        24, // 925 (0x39d)
        68, // 340 (0x154)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 227 (0xe3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 348 (0x15c)
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 935 (0x3a7)
        -1,
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cplusplus_hash_sumN, dataset=cplusplus, hash=hash_sumN
void check_cplusplus_hash_sumN() {
    assert(lookup_cplusplus_hash_sumN("__typeof__") == 26);
    assert(lookup_cplusplus_hash_sumN("try") == 92);
    assert(lookup_cplusplus_hash_sumN("__const__") == 9);
    assert(lookup_cplusplus_hash_sumN("__asm__") == 3);
    assert(lookup_cplusplus_hash_sumN("__wchar_t") == 29);
    assert(lookup_cplusplus_hash_sumN("__attribute") == 4);
    assert(lookup_cplusplus_hash_sumN("__volatile") == 27);
    assert(lookup_cplusplus_hash_sumN("static_cast") == 85);
    assert(lookup_cplusplus_hash_sumN("__signed") == 22);
    assert(lookup_cplusplus_hash_sumN("namespace") == 66);
    assert(lookup_cplusplus_hash_sumN("__inline") == 13);
    assert(lookup_cplusplus_hash_sumN("__complex") == 6);
    assert(lookup_cplusplus_hash_sumN("__imag") == 11);
    assert(lookup_cplusplus_hash_sumN("__restrict") == 19);
    assert(lookup_cplusplus_hash_sumN("const_cast") == 44);
    assert(lookup_cplusplus_hash_sumN("__real") == 17);
    assert(lookup_cplusplus_hash_sumN("and_eq") == 32);
    assert(lookup_cplusplus_hash_sumN("__typeof") == 25);
    assert(lookup_cplusplus_hash_sumN("protected") == 74);
    assert(lookup_cplusplus_hash_sumN("__const") == 8);
    assert(lookup_cplusplus_hash_sumN("default") == 46);
    assert(lookup_cplusplus_hash_sumN("bitand") == 34);
    assert(lookup_cplusplus_hash_sumN("__asm") == 2);
    assert(lookup_cplusplus_hash_sumN("delete") == 47);
    assert(lookup_cplusplus_hash_sumN("template") == 88);
    assert(lookup_cplusplus_hash_sumN("unsigned") == 98);
    assert(lookup_cplusplus_hash_sumN("mutable") == 65);
    assert(lookup_cplusplus_hash_sumN("signature") == 80);
    assert(lookup_cplusplus_hash_sumN("catch") == 39);
    assert(lookup_cplusplus_hash_sumN("friend") == 59);
    assert(lookup_cplusplus_hash_sumN("volatile") == 102);
    assert(lookup_cplusplus_hash_sumN("__null") == 16);
    assert(lookup_cplusplus_hash_sumN("break") == 37);
    assert(lookup_cplusplus_hash_sumN("explicit") == 53);
    assert(lookup_cplusplus_hash_sumN("signed") == 81);
    assert(lookup_cplusplus_hash_sumN("double") == 49);
    assert(lookup_cplusplus_hash_sumN("typename") == 94);
    assert(lookup_cplusplus_hash_sumN("continue") == 45);
    assert(lookup_cplusplus_hash_sumN("register") == 76);
    assert(lookup_cplusplus_hash_sumN("typedef") == 93);
    assert(lookup_cplusplus_hash_sumN("false") == 56);
    assert(lookup_cplusplus_hash_sumN("inline") == 62);
    assert(lookup_cplusplus_hash_sumN("public") == 75);
    assert(lookup_cplusplus_hash_sumN("case") == 38);
    assert(lookup_cplusplus_hash_sumN("operator") == 70);
    assert(lookup_cplusplus_hash_sumN("char") == 40);
    assert(lookup_cplusplus_hash_sumN("not_eq") == 69);
    assert(lookup_cplusplus_hash_sumN("private") == 73);
    assert(lookup_cplusplus_hash_sumN("static") == 84);
    assert(lookup_cplusplus_hash_sumN("class") == 41);
    assert(lookup_cplusplus_hash_sumN("float") == 57);
    assert(lookup_cplusplus_hash_sumN("or_eq") == 72);
    assert(lookup_cplusplus_hash_sumN("sigof") == 82);
    assert(lookup_cplusplus_hash_sumN("__alignof__") == 1);
    assert(lookup_cplusplus_hash_sumN("while") == 103);
    assert(lookup_cplusplus_hash_sumN("xor_eq") == 105);
    assert(lookup_cplusplus_hash_sumN("and") == 31);
    assert(lookup_cplusplus_hash_sumN("compl") == 42);
    assert(lookup_cplusplus_hash_sumN("typeid") == 95);
    assert(lookup_cplusplus_hash_sumN("sizeof") == 83);
    assert(lookup_cplusplus_hash_sumN("else") == 51);
    assert(lookup_cplusplus_hash_sumN("switch") == 87);
    assert(lookup_cplusplus_hash_sumN("virtual") == 100);
    assert(lookup_cplusplus_hash_sumN("bitor") == 35);
    assert(lookup_cplusplus_hash_sumN("bool") == 36);
    assert(lookup_cplusplus_hash_sumN("__label__") == 15);
    assert(lookup_cplusplus_hash_sumN("extern") == 55);
    assert(lookup_cplusplus_hash_sumN("__signature__") == 21);
    assert(lookup_cplusplus_hash_sumN("typeof") == 96);
    assert(lookup_cplusplus_hash_sumN("long") == 64);
    assert(lookup_cplusplus_hash_sumN("__attribute__") == 5);
    assert(lookup_cplusplus_hash_sumN("__volatile__") == 28);
    assert(lookup_cplusplus_hash_sumN("using") == 99);
    assert(lookup_cplusplus_hash_sumN("void") == 101);
    assert(lookup_cplusplus_hash_sumN("__signed__") == 23);
    assert(lookup_cplusplus_hash_sumN("const") == 43);
    assert(lookup_cplusplus_hash_sumN("asm") == 30);
    assert(lookup_cplusplus_hash_sumN("enum") == 52);
    assert(lookup_cplusplus_hash_sumN("union") == 97);
    assert(lookup_cplusplus_hash_sumN("if") == 61);
    assert(lookup_cplusplus_hash_sumN("__inline__") == 14);
    assert(lookup_cplusplus_hash_sumN("return") == 78);
    assert(lookup_cplusplus_hash_sumN("this") == 89);
    assert(lookup_cplusplus_hash_sumN("auto") == 33);
    assert(lookup_cplusplus_hash_sumN("goto") == 60);
    assert(lookup_cplusplus_hash_sumN("__extension__") == 10);
    assert(lookup_cplusplus_hash_sumN("export") == 54);
    assert(lookup_cplusplus_hash_sumN("do") == 48);
    assert(lookup_cplusplus_hash_sumN("for") == 58);
    assert(lookup_cplusplus_hash_sumN("short") == 79);
    assert(lookup_cplusplus_hash_sumN("__complex__") == 7);
    assert(lookup_cplusplus_hash_sumN("struct") == 86);
    assert(lookup_cplusplus_hash_sumN("new") == 67);
    assert(lookup_cplusplus_hash_sumN("__imag__") == 12);
    assert(lookup_cplusplus_hash_sumN("int") == 63);
    assert(lookup_cplusplus_hash_sumN("throw") == 90);
    assert(lookup_cplusplus_hash_sumN("true") == 91);
    assert(lookup_cplusplus_hash_sumN("__restrict__") == 20);
    assert(lookup_cplusplus_hash_sumN("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash_sumN("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash_sumN("__real__") == 18);
    assert(lookup_cplusplus_hash_sumN("__sigof__") == 24);
    assert(lookup_cplusplus_hash_sumN("not") == 68);
    assert(lookup_cplusplus_hash_sumN("or") == 71);
    assert(lookup_cplusplus_hash_sumN("xor") == 104);
    assert(lookup_cplusplus_hash_sumN("__alignof") == 0);
}

//lookup: name=lookup_cplusplus_hash_djb2, dataset=cplusplus, hash=hash_djb2
int lookup_cplusplus_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 677) * 1;
    static std::string_view lookup[677] = {
        "",
        "sizeof", // 7083165528057 (0x6712d90aff9)
        "",
        "",
        "",
        "void", // 6504398011 (0x183b13cbb)
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
        "",
        "",
        "sigof", // 214641359265 (0x31f99f39a1)
        "for", // 197085552 (0xbbf4970)
        "",
        "",
        "mutable", // 233737175969651 (0xd4952d582f73)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "friend", // 7082666830273 (0x6710fd729c1)
        "",
        "",
        "inline", // 7082779604936 (0x671168ff7c8)
        "",
        "",
        "__alignof", // 254519133205282311 (0x3883bcd9b3dbe07)
        "",
        "",
        "",
        "__const__", // 254519135911991276 (0x3883bce3c92d7ec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__asm__", // 233718212565350 (0xd490c3099966)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "false", // 214625660372 (0x31f8afadd4)
        "",
        "",
        "",
        "",
        "",
        "typename", // 7713630150592940 (0x1b6781790e09ac)
        "",
        "",
        "union", // 214643912978 (0x31f9c63112)
        "",
        "unsigned", // 7713658684800454 (0x1b67881dd37dc6)
        "",
        "or", // 5972586 (0x5b226a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__alignof__", // 470174954909165669 (0x68665a161a56865)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__asm", // 214617275080 (0x31f82fbac8)
        "",
        "class", // 214622485951 (0x31f87f3dbf)
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
        "private", // 233740920676100 (0xd4960c8bdf04)
        "__typeof", // 7712701765459518 (0x1b66a950fd1e3e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__extension__", // 13965134545096009730 (0xc1ce1fe0d8fbe802)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "true", // 6504329801 (0x183b03249)
        "export", // 7082635073003 (0x6710df295eb)
        "",
        "",
        "",
        "",
        "",
        "else", // 6503784146 (0x183a7ded2)
        "",
        "",
        "",
        "",
        "and_eq", // 7082466223121 (0x67103e22411)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "explicit", // 7712989590604139 (0x1b66ec54b4496b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__inline__", // 8399131739424563012 (0x748fb5d1061c1f44)
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute", // 470175310486966715 (0x68665f42bbc11bb)
        "goto", // 6503859330 (0x183a90482)
        "",
        "",
        "",
        "const", // 214622607920 (0x31f8811a30)
        "",
        "",
        "",
        "",
        "",
        "__inline", // 7712701321785638 (0x1b66a9368b3126)
        "operator", // 7713405019647573 (0x1b674d0e346e55)
        "",
        "",
        "",
        "",
        "",
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
        "not_eq", // 7082976744143 (0x671225012cf)
        "",
        "",
        "",
        "static_cast", // 501781516559673083 (0x6f6afa1796566fb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "namespace", // 254540329807277846 (0x3884f14d32c6f16)
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
        "",
        "return", // 7083121450889 (0x6712af01f89)
        "",
        "case", // 6503700293 (0x183a69745)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "signed", // 7083164854723 (0x6712d8669c3)
        "new", // 197093939 (0xbbf6a33)
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
        "default", // 233724910009454 (0xd492523c7c6e)
        "",
        "",
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
        "",
        "auto", // 6503650242 (0x183a5d3c2)
        "break", // 214621519406 (0x31f8707e2e)
        "",
        "",
        "",
        "",
        "",
        "using", // 214644092623 (0x31f9c8eecf)
        "",
        "",
        "",
        "",
        "extern", // 7082635205855 (0x6710df49cdf)
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
        "or_eq", // 214636929983 (0x31f95ba3bf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__signature__", // 13985862562142013239 (0xc217c3e665e8c737)
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
        "bitor", // 214621212777 (0x31f86bd069)
        "",
        "",
        "",
        "compl", // 214622606724 (0x31f8811584)
        "",
        "",
        "register", // 7713518737072878 (0x1b6767884aa2ee)
        "",
        "",
        "",
        "",
        "",
        "__complex", // 254519135910689055 (0x3883bce3c7ef91f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__complex__", // 470177901097109885 (0x686684f5821c97d)
        "",
        "",
        "",
        "",
        "enum", // 6503786398 (0x183a7e79e)
        "",
        "",
        "do", // 5972220 (0x5b20fc)
        "",
        "",
        "",
        "",
        "",
        "this", // 6504318529 (0x183b00641)
        "",
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
        "typeid", // 7083223278616 (0x6713101e418)
        "",
        "",
        "",
        "signature", // 254547695380143035 (0x38855c7c1871bbb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "bool", // 6503679477 (0x183a645f5)
        "",
        "__real__", // 7712701662938345 (0x1b66a94ae0c4e9)
        "",
        "bitand", // 7082500006363 (0x67105e5a1db)
        "",
        "",
        "",
        "__signed__", // 8399132158961581055 (0x748fb632b476fbff)
        "",
        "__signed", // 7712701707035425 (0x1b66a94d81a321)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "try", // 197100904 (0xbbf8568)
        "",
        "",
        "",
        "",
        "",
        "",
        "__null", // 7082370547074 (0x670fe2e3d82)
        "",
        "",
        "",
        "__wchar_t", // 254519161263961391 (0x3883bd423ab352f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__imag__", // 7712701320201731 (0x1b66a936730603)
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute__", // 13958823130148862233 (0xc1b7b3ae0b077919)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__sigof__", // 254519156332205981 (0x3883bd2fdb6979d)
        "",
        "",
        "",
        "",
        "__real", // 7082370673035 (0x670fe30298b)
        "",
        "",
        "",
        "",
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
        "double", // 7082585429636 (0x6710afd1684)
        "",
        "",
        "",
        "",
        "",
        "",
        "char", // 6503707335 (0x183a6b2c7)
        "protected", // 254543870290962451 (0x388524d28722813)
        "int", // 197088788 (0xbbf5614)
        "",
        "continue", // 7712892661735406 (0x1b66d5c34b1fee)
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
        "",
        "",
        "",
        "__typeof__", // 8399132222585418332 (0x748fb64184bdb25c)
        "",
        "",
        "",
        "__const", // 233718214795214 (0xd490c32b9fce)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "const_cast", // 8399340107750442362 (0x749073538e28057a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__label__", // 254519146972564613 (0x3883bd0cfd5cc85)
        "",
        "reinterpret_cast", // 11226082634868115847 (0x9bcb0ead967ec987)
        "",
        "",
        "",
        "",
        "__volatile", // 8399132294746522727 (0x748fb65251e0c467)
        "__imag", // 7082370358309 (0x670fe2b5c25)
        "",
        "",
        "",
        "",
        "",
        "",
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
        "virtual", // 233748327887952 (0xd497c60cf450)
        "and", // 197080060 (0xbbf33fc)
        "",
        "__restrict__", // 15516553105499827157 (0xd755ded6d7cd2bd5)
        "",
        "",
        "",
        "__volatile__", // 15516752492735203013 (0xd756942e4d2386c5)
        "",
        "typeof", // 7083223278816 (0x6713101e4e0)
        "",
        "",
        "while", // 214646069090 (0x31f9e71762)
        "",
        "",
        "",
        "",
        "",
        "dynamic_cast", // 15808893149597540504 (0xdb64788f79de2098)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__restrict", // 8399132111654479223 (0x748fb627b0bde577)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "delete", // 7082573250524 (0x6710a433fdc)
        "",
        "",
        "",
        "",
        "",
        "",
        "short", // 214641332153 (0x31f99ecfb9)
        "",
        "xor", // 197105154 (0xbbf9602)
        "",
        "",
        "",
        "",
        "",
        "",
        "xor_eq", // 7083368026199 (0x67139a29057)
        "",
        "float", // 214626058367 (0x31f8b5c07f)
        "",
    };
    static int values[677] = {
        -1,
        83, // 7083165528057 (0x6712d90aff9)
        -1,
        -1,
        -1,
        101, // 6504398011 (0x183b13cbb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 214622110796 (0x31f879844c)
        -1,
        -1,
        -1,
        -1,
        82, // 214641359265 (0x31f99f39a1)
        58, // 197085552 (0xbbf4970)
        -1,
        -1,
        65, // 233737175969651 (0xd4952d582f73)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        93, // 233746368189018 (0xd497513e525a)
        -1,
        -1,
        -1,
        59, // 7082666830273 (0x6710fd729c1)
        -1,
        -1,
        62, // 7082779604936 (0x671168ff7c8)
        -1,
        -1,
        0, // 254519133205282311 (0x3883bcd9b3dbe07)
        -1,
        -1,
        -1,
        9, // 254519135911991276 (0x3883bce3c92d7ec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 233718212565350 (0xd490c3099966)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        56, // 214625660372 (0x31f8afadd4)
        -1,
        -1,
        -1,
        -1,
        -1,
        94, // 7713630150592940 (0x1b6781790e09ac)
        -1,
        -1,
        97, // 214643912978 (0x31f9c63112)
        -1,
        98, // 7713658684800454 (0x1b67881dd37dc6)
        -1,
        71, // 5972586 (0x5b226a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 470174954909165669 (0x68665a161a56865)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 214617275080 (0x31f82fbac8)
        -1,
        41, // 214622485951 (0x31f87f3dbf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 197080234 (0xbbf34aa)
        -1,
        -1,
        -1,
        -1,
        -1,
        73, // 233740920676100 (0xd4960c8bdf04)
        25, // 7712701765459518 (0x1b66a950fd1e3e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 13965134545096009730 (0xc1ce1fe0d8fbe802)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        91, // 6504329801 (0x183b03249)
        54, // 7082635073003 (0x6710df295eb)
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 6503784146 (0x183a7ded2)
        -1,
        -1,
        -1,
        -1,
        32, // 7082466223121 (0x67103e22411)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 7712989590604139 (0x1b66ec54b4496b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 8399131739424563012 (0x748fb5d1061c1f44)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 470175310486966715 (0x68665f42bbc11bb)
        60, // 6503859330 (0x183a90482)
        -1,
        -1,
        -1,
        43, // 214622607920 (0x31f8811a30)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 7712701321785638 (0x1b66a9368b3126)
        70, // 7713405019647573 (0x1b674d0e346e55)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 7083181535963 (0x6712e84f2db)
        -1,
        -1,
        69, // 7082976744143 (0x671225012cf)
        -1,
        -1,
        -1,
        85, // 501781516559673083 (0x6f6afa1796566fb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        66, // 254540329807277846 (0x3884f14d32c6f16)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        90, // 214642521245 (0x31f9b0f49d)
        -1,
        -1,
        -1,
        -1,
        78, // 7083121450889 (0x6712af01f89)
        -1,
        38, // 6503700293 (0x183a69745)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        81, // 7083164854723 (0x6712d8669c3)
        67, // 197093939 (0xbbf6a33)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 6504038809 (0x183abc199)
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 233724910009454 (0xd492523c7c6e)
        -1,
        -1,
        -1,
        -1,
        88, // 7713604216800869 (0x1b677b6f47c665)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 6503650242 (0x183a5d3c2)
        37, // 214621519406 (0x31f8707e2e)
        -1,
        -1,
        -1,
        -1,
        -1,
        99, // 214644092623 (0x31f9c8eecf)
        -1,
        -1,
        -1,
        -1,
        55, // 7082635205855 (0x6710df49cdf)
        -1,
        -1,
        75, // 7083061497864 (0x671275d5008)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 214636929983 (0x31f95ba3bf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 13985862562142013239 (0xc217c3e665e8c737)
        -1,
        86, // 7083178302734 (0x6712e539d0e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 214621212777 (0x31f86bd069)
        -1,
        -1,
        -1,
        42, // 214622606724 (0x31f8811584)
        -1,
        -1,
        76, // 7713518737072878 (0x1b6767884aa2ee)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 254519135910689055 (0x3883bce3c7ef91f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 470177901097109885 (0x686684f5821c97d)
        -1,
        -1,
        -1,
        -1,
        52, // 6503786398 (0x183a7e79e)
        -1,
        -1,
        48, // 5972220 (0x5b20fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 6504318529 (0x183b00641)
        -1,
        102, // 7713702311738249 (0x1b67924631bb89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        95, // 7083223278616 (0x6713101e418)
        -1,
        -1,
        -1,
        80, // 254547695380143035 (0x38855c7c1871bbb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 6503679477 (0x183a645f5)
        -1,
        18, // 7712701662938345 (0x1b66a94ae0c4e9)
        -1,
        34, // 7082500006363 (0x67105e5a1db)
        -1,
        -1,
        -1,
        23, // 8399132158961581055 (0x748fb632b476fbff)
        -1,
        22, // 7712701707035425 (0x1b66a94d81a321)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 197100904 (0xbbf8568)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 7082370547074 (0x670fe2e3d82)
        -1,
        -1,
        -1,
        29, // 254519161263961391 (0x3883bd423ab352f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 7712701320201731 (0x1b66a936730603)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 13958823130148862233 (0xc1b7b3ae0b077919)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 254519156332205981 (0x3883bd2fdb6979d)
        -1,
        -1,
        -1,
        -1,
        17, // 7082370673035 (0x670fe30298b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        84, // 7083177690897 (0x6712e4a4711)
        -1,
        -1,
        49, // 7082585429636 (0x6710afd1684)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 6503707335 (0x183a6b2c7)
        74, // 254543870290962451 (0x388524d28722813)
        63, // 197088788 (0xbbf5614)
        -1,
        45, // 7712892661735406 (0x1b66d5c34b1fee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 5972376 (0x5b2198)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 8399132222585418332 (0x748fb64184bdb25c)
        -1,
        -1,
        -1,
        8, // 233718214795214 (0xd490c32b9fce)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 8399340107750442362 (0x749073538e28057a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 254519146972564613 (0x3883bd0cfd5cc85)
        -1,
        77, // 11226082634868115847 (0x9bcb0ead967ec987)
        -1,
        -1,
        -1,
        -1,
        27, // 8399132294746522727 (0x748fb65251e0c467)
        11, // 7082370358309 (0x670fe2b5c25)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 197094266 (0xbbf6b7a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        100, // 233748327887952 (0xd497c60cf450)
        31, // 197080060 (0xbbf33fc)
        -1,
        20, // 15516553105499827157 (0xd755ded6d7cd2bd5)
        -1,
        -1,
        -1,
        28, // 15516752492735203013 (0xd756942e4d2386c5)
        -1,
        96, // 7083223278816 (0x6713101e4e0)
        -1,
        -1,
        103, // 214646069090 (0x31f9e71762)
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 15808893149597540504 (0xdb64788f79de2098)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 8399132111654479223 (0x748fb627b0bde577)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 7082573250524 (0x6710a433fdc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        79, // 214641332153 (0x31f99ecfb9)
        -1,
        104, // 197105154 (0xbbf9602)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 7083368026199 (0x67139a29057)
        -1,
        57, // 214626058367 (0x31f8b5c07f)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_cplusplus_hash_djb2, dataset=cplusplus, hash=hash_djb2
void check_cplusplus_hash_djb2() {
    assert(lookup_cplusplus_hash_djb2("sizeof") == 83);
    assert(lookup_cplusplus_hash_djb2("void") == 101);
    assert(lookup_cplusplus_hash_djb2("catch") == 39);
    assert(lookup_cplusplus_hash_djb2("sigof") == 82);
    assert(lookup_cplusplus_hash_djb2("for") == 58);
    assert(lookup_cplusplus_hash_djb2("mutable") == 65);
    assert(lookup_cplusplus_hash_djb2("typedef") == 93);
    assert(lookup_cplusplus_hash_djb2("friend") == 59);
    assert(lookup_cplusplus_hash_djb2("inline") == 62);
    assert(lookup_cplusplus_hash_djb2("__alignof") == 0);
    assert(lookup_cplusplus_hash_djb2("__const__") == 9);
    assert(lookup_cplusplus_hash_djb2("__asm__") == 3);
    assert(lookup_cplusplus_hash_djb2("false") == 56);
    assert(lookup_cplusplus_hash_djb2("typename") == 94);
    assert(lookup_cplusplus_hash_djb2("union") == 97);
    assert(lookup_cplusplus_hash_djb2("unsigned") == 98);
    assert(lookup_cplusplus_hash_djb2("or") == 71);
    assert(lookup_cplusplus_hash_djb2("__alignof__") == 1);
    assert(lookup_cplusplus_hash_djb2("__asm") == 2);
    assert(lookup_cplusplus_hash_djb2("class") == 41);
    assert(lookup_cplusplus_hash_djb2("asm") == 30);
    assert(lookup_cplusplus_hash_djb2("private") == 73);
    assert(lookup_cplusplus_hash_djb2("__typeof") == 25);
    assert(lookup_cplusplus_hash_djb2("__extension__") == 10);
    assert(lookup_cplusplus_hash_djb2("true") == 91);
    assert(lookup_cplusplus_hash_djb2("export") == 54);
    assert(lookup_cplusplus_hash_djb2("else") == 51);
    assert(lookup_cplusplus_hash_djb2("and_eq") == 32);
    assert(lookup_cplusplus_hash_djb2("explicit") == 53);
    assert(lookup_cplusplus_hash_djb2("__inline__") == 14);
    assert(lookup_cplusplus_hash_djb2("__attribute") == 4);
    assert(lookup_cplusplus_hash_djb2("goto") == 60);
    assert(lookup_cplusplus_hash_djb2("const") == 43);
    assert(lookup_cplusplus_hash_djb2("__inline") == 13);
    assert(lookup_cplusplus_hash_djb2("operator") == 70);
    assert(lookup_cplusplus_hash_djb2("switch") == 87);
    assert(lookup_cplusplus_hash_djb2("not_eq") == 69);
    assert(lookup_cplusplus_hash_djb2("static_cast") == 85);
    assert(lookup_cplusplus_hash_djb2("namespace") == 66);
    assert(lookup_cplusplus_hash_djb2("throw") == 90);
    assert(lookup_cplusplus_hash_djb2("return") == 78);
    assert(lookup_cplusplus_hash_djb2("case") == 38);
    assert(lookup_cplusplus_hash_djb2("signed") == 81);
    assert(lookup_cplusplus_hash_djb2("new") == 67);
    assert(lookup_cplusplus_hash_djb2("long") == 64);
    assert(lookup_cplusplus_hash_djb2("default") == 46);
    assert(lookup_cplusplus_hash_djb2("template") == 88);
    assert(lookup_cplusplus_hash_djb2("auto") == 33);
    assert(lookup_cplusplus_hash_djb2("break") == 37);
    assert(lookup_cplusplus_hash_djb2("using") == 99);
    assert(lookup_cplusplus_hash_djb2("extern") == 55);
    assert(lookup_cplusplus_hash_djb2("public") == 75);
    assert(lookup_cplusplus_hash_djb2("or_eq") == 72);
    assert(lookup_cplusplus_hash_djb2("__signature__") == 21);
    assert(lookup_cplusplus_hash_djb2("struct") == 86);
    assert(lookup_cplusplus_hash_djb2("bitor") == 35);
    assert(lookup_cplusplus_hash_djb2("compl") == 42);
    assert(lookup_cplusplus_hash_djb2("register") == 76);
    assert(lookup_cplusplus_hash_djb2("__complex") == 6);
    assert(lookup_cplusplus_hash_djb2("__complex__") == 7);
    assert(lookup_cplusplus_hash_djb2("enum") == 52);
    assert(lookup_cplusplus_hash_djb2("do") == 48);
    assert(lookup_cplusplus_hash_djb2("this") == 89);
    assert(lookup_cplusplus_hash_djb2("volatile") == 102);
    assert(lookup_cplusplus_hash_djb2("typeid") == 95);
    assert(lookup_cplusplus_hash_djb2("signature") == 80);
    assert(lookup_cplusplus_hash_djb2("bool") == 36);
    assert(lookup_cplusplus_hash_djb2("__real__") == 18);
    assert(lookup_cplusplus_hash_djb2("bitand") == 34);
    assert(lookup_cplusplus_hash_djb2("__signed__") == 23);
    assert(lookup_cplusplus_hash_djb2("__signed") == 22);
    assert(lookup_cplusplus_hash_djb2("try") == 92);
    assert(lookup_cplusplus_hash_djb2("__null") == 16);
    assert(lookup_cplusplus_hash_djb2("__wchar_t") == 29);
    assert(lookup_cplusplus_hash_djb2("__imag__") == 12);
    assert(lookup_cplusplus_hash_djb2("__attribute__") == 5);
    assert(lookup_cplusplus_hash_djb2("__sigof__") == 24);
    assert(lookup_cplusplus_hash_djb2("__real") == 17);
    assert(lookup_cplusplus_hash_djb2("static") == 84);
    assert(lookup_cplusplus_hash_djb2("double") == 49);
    assert(lookup_cplusplus_hash_djb2("char") == 40);
    assert(lookup_cplusplus_hash_djb2("protected") == 74);
    assert(lookup_cplusplus_hash_djb2("int") == 63);
    assert(lookup_cplusplus_hash_djb2("continue") == 45);
    assert(lookup_cplusplus_hash_djb2("if") == 61);
    assert(lookup_cplusplus_hash_djb2("__typeof__") == 26);
    assert(lookup_cplusplus_hash_djb2("__const") == 8);
    assert(lookup_cplusplus_hash_djb2("const_cast") == 44);
    assert(lookup_cplusplus_hash_djb2("__label__") == 15);
    assert(lookup_cplusplus_hash_djb2("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash_djb2("__volatile") == 27);
    assert(lookup_cplusplus_hash_djb2("__imag") == 11);
    assert(lookup_cplusplus_hash_djb2("not") == 68);
    assert(lookup_cplusplus_hash_djb2("virtual") == 100);
    assert(lookup_cplusplus_hash_djb2("and") == 31);
    assert(lookup_cplusplus_hash_djb2("__restrict__") == 20);
    assert(lookup_cplusplus_hash_djb2("__volatile__") == 28);
    assert(lookup_cplusplus_hash_djb2("typeof") == 96);
    assert(lookup_cplusplus_hash_djb2("while") == 103);
    assert(lookup_cplusplus_hash_djb2("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash_djb2("__restrict") == 19);
    assert(lookup_cplusplus_hash_djb2("delete") == 47);
    assert(lookup_cplusplus_hash_djb2("short") == 79);
    assert(lookup_cplusplus_hash_djb2("xor") == 104);
    assert(lookup_cplusplus_hash_djb2("xor_eq") == 105);
    assert(lookup_cplusplus_hash_djb2("float") == 57);
}

//lookup: name=lookup_cplusplus_hash_sdb, dataset=cplusplus, hash=hash_sdb
int lookup_cplusplus_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 997) * 1;
    static std::string_view lookup[997] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "union", // 426184954403829259 (0x5ea1cf53fdb360b)
        "",
        "",
        "",
        "__attribute", // 9169915419439701480 (0x7f42157d5c149de8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "extern", // 2996732478728017764 (0x2996884fe1759764)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "signed", // 3297078571319795376 (0x2dc1937df0119eb0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__extension__", // 10941353563955398691 (0x97d77f18bd840823)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "or_eq", // 407043376047272988 (0x5a61bcb3d79341c)
        "",
        "",
        "",
        "",
        "",
        "this", // 32656028173930898 (0x74047c0f151192)
        "",
        "and_eq", // 2857113287978946148 (0x27a68165d5088e64)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "typename", // 3489680910931776129 (0x306dd64ca38cd281)
        "",
        "",
        "",
        "__typeof__", // 12619805793118379413 (0xaf228e81993cdd95)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__label__", // 16209435960614218980 (0xe0f37c1ff9da6ce4)
        "",
        "",
        "not_eq", // 3194336236197485756 (0x2c548fe1ebb59cbc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__const", // 17212546999951989095 (0xeedf404cebda9967)
        "",
        "",
        "bitor", // 360596732025909224 (0x50118d137922fe8)
        "",
        "__imag__", // 1072334072835002266 (0xee1b22863e0cf9a)
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__const__", // 15240571718574040603 (0xd381633ae378661b)
        "",
        "",
        "",
        "xor_eq", // 3447112284647826948 (0x2fd69a5bfb51a604)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__restrict", // 8111279973310962608 (0x70910e290af09bb0)
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "reinterpret_cast", // 7369002456448243904 (0x6643f4b1059418c0)
        "",
        "",
        "friend", // 2998702146399343922 (0x299d87b6df559532)
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
        "private", // 1853414300009618939 (0x19b8a67c6db3ddfb)
        "",
        "",
        "",
        "",
        "static_cast", // 1812738561257685108 (0x1928241dfe6ac074)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__asm", // 347647719114943811 (0x4d317c234d22d43)
        "",
        "",
        "__alignof__", // 855745130061836788 (0xbe037a96f9b31f4)
        "",
        "",
        "",
        "",
        "",
        "",
        "for", // 438134048085 (0x6602d30555)
        "",
        "",
        "__complex__", // 11736994935275229624 (0xa2e22eb557a391b8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__typeof", // 1395764931901579153 (0x135ec0cf7bf0df91)
        "",
        "",
        "not", // 472496932255 (0x6e0303059f)
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
        "__signed__", // 9189356093952925864 (0x7f8726ae1ea2a0a8)
        "",
        "",
        "",
        "using", // 427592522569692808 (0x5ef1d2240613688)
        "",
        "",
        "",
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
        "__complex", // 15236349211656152412 (0xd37262e1e291655c)
        "",
        "",
        "",
        "",
        "",
        "asm", // 416657507631 (0x6102b9052f)
        "",
        "inline", // 3062036700571998013 (0x2a7e8a27e2cd973d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "void", // 33219085507826168 (0x7604950f7511f8)
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
        "",
        "",
        "",
        "",
        "struct", // 3337332499566470045 (0x2e509639f606a39d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "virtual", // 2567257810834155947 (0x23a0bb60859de9ab)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__restrict__", // 6124997494552427180 (0x55005cc508f47aac)
        "",
        "",
        "template", // 410239291073665550 (0x5b17676315a9a0e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__signed", // 1313850533795387596 (0x123bbc1972d4d8cc)
        "",
        "",
        "",
        "",
        "",
        "",
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
        "namespace", // 1788312692352551751 (0x18d15ceb36ff0b47)
        "",
        "",
        "",
        "",
        "",
        "",
        "sizeof", // 3302427291692736640 (0x2dd4941ff1e6a080)
        "",
        "",
        "",
        "typeid", // 3378992969425593697 (0x2ee49833f927a561)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "bitand", // 2870061763993702290 (0x27d481f7d6468f92)
        "",
        "sigof", // 418021514335499464 (0x5cd1c5a3e7034c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "bool", // 27588812844503030 (0x6203e10d5f0ff6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__volatile", // 12582355911269993968 (0xae9d820980c8cdf0)
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
        "",
        "",
        "",
        "export", // 2995606467148879704 (0x29928835e1459758)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "continue", // 6848942472000841643 (0x5f0c54e41ab227ab)
        "",
        "",
        "static", // 3332546763507343818 (0x2e3f959ff43ba1ca)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "double", // 2941278687000499069 (0x28d18561dc17937d)
        "",
        "while", // 431251735916197369 (0x5fc1d2b400e35f9)
        "",
        "",
        "const_cast", // 8103601803756267423 (0x7075c6e7e21b679f)
        "",
        "const", // 365663719708962995 (0x5131937388030b3)
        "",
        "",
        "",
        "",
        "",
        "explicit", // 9836609092843360584 (0x8882a7da754e5148)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__imag", // 2757184126298720430 (0x26437c5acc6188ae)
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
        "__asm__", // 17206917186876381399 (0xeecb4003eb5498d7)
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
        "",
        "__volatile__", // 12721372598870359788 (0xb08b64fa5b0e3eec)
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
        "throw", // 421117979607119218 (0x5d81c923f033572)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "public", // 3260204451718471445 (0x2d3e92acefd39f15)
        "",
        "int", // 451020064111 (0x6902e4056f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "true", // 32656071128322562 (0x7404860f5d1202)
        "",
        "__wchar_t", // 17951264101882302434 (0xf91fb3973dea8fe2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__inline__", // 2081643364776435101 (0x1ce37b9c7a8c5d9d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "else", // 28433340858241073 (0x6503f90da21031)
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
        "__inline", // 1078808663047590233 (0xef8b2c36590d159)
        "float", // 374952978071105832 (0x53419bf39673128)
        "",
        "",
        "",
        "",
        "register", // 17087298121750970967 (0xed22471bfe2a8257)
        "",
        "",
        "",
        "mutable", // 1504656371223091582 (0x14e19cff63c7d97e)
        "",
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
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__null", // 2758591728828254627 (0x26487c8fcd2389a3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "or", // 7274943 (0x6f01bf)
        "",
        "",
        "",
        "dynamic_cast", // 1933816627910765911 (0x1ad64bfa2f5d6d57)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__signature__", // 4199880449128727428 (0x3a48f9043d6d0384)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "signature", // 8133910499702850260 (0x70e17481119bc2d4)
        "",
        "__real__", // 1273315809210127818 (0x11abb9fb6edbd5ca)
        "",
        "",
        "__alignof", // 14840298736401341112 (0xcdf35512cfe15ab8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "delete", // 2904965760630034323 (0x285082f7d7068f93)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "typeof", // 3378992969425986933 (0x2ee49833f92da575)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "long", // 30403949176295676 (0x6c043b0e6c10fc)
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
        "short", // 417740035065394444 (0x5cc1c593e88350c)
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
        "unsigned", // 2703208532253982581 (0x2583b9d67ecdbf75)
        "__real", // 2759717714634508638 (0x264c7ca3cd24895e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "__sigof__", // 17495823931358481112 (0xf2cda72b31668ad8)
        "",
        "",
        "",
        "",
        "",
        "",
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
        "",
        "",
        "",
        "",
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
        "",
        "compl", // 365663715413405849 (0x513193638773099)
        "enum", // 28433349449093201 (0x6503fb0db01051)
        "",
        "",
        "",
        "",
        "",
        "",
        "__attribute__", // 6221590720219221668 (0x565787cbf0888ea4)
        "",
        "",
        "",
    };
    static int values[997] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 426184954403829259 (0x5ea1cf53fdb360b)
        -1,
        -1,
        -1,
        4, // 9169915419439701480 (0x7f42157d5c149de8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 2996732478728017764 (0x2996884fe1759764)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        81, // 3297078571319795376 (0x2dc1937df0119eb0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 515450537463 (0x78033f05f7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 10941353563955398691 (0x97d77f18bd840823)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 407043376047272988 (0x5a61bcb3d79341c)
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 32656028173930898 (0x74047c0f151192)
        -1,
        32, // 2857113287978946148 (0x27a68165d5088e64)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        94, // 3489680910931776129 (0x306dd64ca38cd281)
        -1,
        -1,
        -1,
        26, // 12619805793118379413 (0xaf228e81993cdd95)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 16209435960614218980 (0xe0f37c1ff9da6ce4)
        -1,
        -1,
        69, // 3194336236197485756 (0x2c548fe1ebb59cbc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 17212546999951989095 (0xeedf404cebda9967)
        -1,
        -1,
        35, // 360596732025909224 (0x50118d137922fe8)
        -1,
        12, // 1072334072835002266 (0xee1b22863e0cf9a)
        -1,
        -1,
        -1,
        87, // 3344932667539956616 (0x2e6b9689f651a388)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 15240571718574040603 (0xd381633ae378661b)
        -1,
        -1,
        -1,
        105, // 3447112284647826948 (0x2fd69a5bfb51a604)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 8111279973310962608 (0x70910e290af09bb0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 364819122969718764 (0x510190f37e12fec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        77, // 7369002456448243904 (0x6643f4b1059418c0)
        -1,
        -1,
        59, // 2998702146399343922 (0x299d87b6df559532)
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
        73, // 1853414300009618939 (0x19b8a67c6db3ddfb)
        -1,
        -1,
        -1,
        -1,
        85, // 1812738561257685108 (0x1928241dfe6ac074)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 347647719114943811 (0x4d317c234d22d43)
        -1,
        -1,
        1, // 855745130061836788 (0xbe037a96f9b31f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 438134048085 (0x6602d30555)
        -1,
        -1,
        7, // 11736994935275229624 (0xa2e22eb557a391b8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1395764931901579153 (0x135ec0cf7bf0df91)
        -1,
        -1,
        68, // 472496932255 (0x6e0303059f)
        -1,
        78, // 3261892644424556104 (0x2d449213ee629e48)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 9189356093952925864 (0x7f8726ae1ea2a0a8)
        -1,
        -1,
        -1,
        99, // 427592522569692808 (0x5ef1d2240613688)
        -1,
        -1,
        -1,
        -1,
        -1,
        93, // 2657618279341420639 (0x24e1c1be90baf05f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 15236349211656152412 (0xd37262e1e291655c)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 416657507631 (0x6102b9052f)
        -1,
        62, // 3062036700571998013 (0x2a7e8a27e2cd973d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        101, // 33219085507826168 (0x7604950f7511f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 27870296409247662 (0x6303e30d420fae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        86, // 3337332499566470045 (0x2e509639f606a39d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 6881697 (0x6901a1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        100, // 2567257810834155947 (0x23a0bb60859de9ab)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 6124997494552427180 (0x55005cc508f47aac)
        -1,
        -1,
        88, // 410239291073665550 (0x5b17676315a9a0e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 1313850533795387596 (0x123bbc1972d4d8cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 16339972781482018612 (0xe2c33eabffc98734)
        -1,
        -1,
        -1,
        -1,
        -1,
        66, // 1788312692352551751 (0x18d15ceb36ff0b47)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        83, // 3302427291692736640 (0x2dd4941ff1e6a080)
        -1,
        -1,
        -1,
        95, // 3378992969425593697 (0x2ee49833f927a561)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 2870061763993702290 (0x27d481f7d6468f92)
        -1,
        82, // 418021514335499464 (0x5cd1c5a3e7034c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 27588812844503030 (0x6203e10d5f0ff6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 12582355911269993968 (0xae9d820980c8cdf0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 363130290293256227 (0x50a1913381d3023)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 2995606467148879704 (0x29928835e1459758)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 6848942472000841643 (0x5f0c54e41ab227ab)
        -1,
        -1,
        84, // 3332546763507343818 (0x2e3f959ff43ba1ca)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 2941278687000499069 (0x28d18561dc17937d)
        -1,
        103, // 431251735916197369 (0x5fc1d2b400e35f9)
        -1,
        -1,
        44, // 8103601803756267423 (0x7075c6e7e21b679f)
        -1,
        43, // 365663719708962995 (0x5131937388030b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 9836609092843360584 (0x8882a7da754e5148)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 2757184126298720430 (0x26437c5acc6188ae)
        74, // 5201487412384685718 (0x482f653e2edade96)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 17206917186876381399 (0xeecb4003eb5498d7)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 27307324983808035 (0x6103de0d6d1023)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 12721372598870359788 (0xb08b64fa5b0e3eec)
        -1,
        -1,
        -1,
        -1,
        39, // 361722554615476019 (0x50518bf371a2f33)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 416657179927 (0x6102b40517)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        90, // 421117979607119218 (0x5d81c923f033572)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        75, // 3260204451718471445 (0x2d3e92acefd39f15)
        -1,
        63, // 451020064111 (0x6902e4056f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        91, // 32656071128322562 (0x7404860f5d1202)
        -1,
        29, // 17951264101882302434 (0xf91fb3973dea8fe2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 2081643364776435101 (0x1ce37b9c7a8c5d9d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 6554011 (0x64019b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 28433340858241073 (0x6503f90da21031)
        46, // 18130751609074855161 (0xfb9d5e8711bfacf9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 1078808663047590233 (0xef8b2c36590d159)
        57, // 374952978071105832 (0x53419bf39673128)
        -1,
        -1,
        -1,
        -1,
        76, // 17087298121750970967 (0xed22471bfe2a8257)
        -1,
        -1,
        -1,
        65, // 1504656371223091582 (0x14e19cff63c7d97e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 498269292003 (0x74032a05e3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 2758591728828254627 (0x26487c8fcd2389a3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 7274943 (0x6f01bf)
        -1,
        -1,
        -1,
        50, // 1933816627910765911 (0x1ad64bfa2f5d6d57)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 4199880449128727428 (0x3a48f9043d6d0384)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        80, // 8133910499702850260 (0x70e17481119bc2d4)
        -1,
        18, // 1273315809210127818 (0x11abb9fb6edbd5ca)
        -1,
        -1,
        0, // 14840298736401341112 (0xcdf35512cfe15ab8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 2904965760630034323 (0x285082f7d7068f93)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        96, // 3378992969425986933 (0x2ee49833f92da575)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 30403949176295676 (0x6c043b0e6c10fc)
        102, // 3452512564192461556 (0x2fe9c9e28b43c2f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        79, // 417740035065394444 (0x5cc1c593e88350c)
        56, // 371856315221159947 (0x5291959383e300b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        98, // 2703208532253982581 (0x2583b9d67ecdbf75)
        17, // 2759717714634508638 (0x264c7ca3cd24895e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 17495823931358481112 (0xf2cda72b31668ad8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        67, // 472496276868 (0x6e02f90584)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 27870266342903704 (0x6303dc0d2a0f98)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 365663715413405849 (0x513193638773099)
        52, // 28433349449093201 (0x6503fb0db01051)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 6221590720219221668 (0x565787cbf0888ea4)
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

//check: name=check_cplusplus_hash_sdb, dataset=cplusplus, hash=hash_sdb
void check_cplusplus_hash_sdb() {
    assert(lookup_cplusplus_hash_sdb("union") == 97);
    assert(lookup_cplusplus_hash_sdb("__attribute") == 4);
    assert(lookup_cplusplus_hash_sdb("extern") == 55);
    assert(lookup_cplusplus_hash_sdb("signed") == 81);
    assert(lookup_cplusplus_hash_sdb("xor") == 104);
    assert(lookup_cplusplus_hash_sdb("__extension__") == 10);
    assert(lookup_cplusplus_hash_sdb("or_eq") == 72);
    assert(lookup_cplusplus_hash_sdb("this") == 89);
    assert(lookup_cplusplus_hash_sdb("and_eq") == 32);
    assert(lookup_cplusplus_hash_sdb("typename") == 94);
    assert(lookup_cplusplus_hash_sdb("__typeof__") == 26);
    assert(lookup_cplusplus_hash_sdb("__label__") == 15);
    assert(lookup_cplusplus_hash_sdb("not_eq") == 69);
    assert(lookup_cplusplus_hash_sdb("__const") == 8);
    assert(lookup_cplusplus_hash_sdb("bitor") == 35);
    assert(lookup_cplusplus_hash_sdb("__imag__") == 12);
    assert(lookup_cplusplus_hash_sdb("switch") == 87);
    assert(lookup_cplusplus_hash_sdb("__const__") == 9);
    assert(lookup_cplusplus_hash_sdb("xor_eq") == 105);
    assert(lookup_cplusplus_hash_sdb("__restrict") == 19);
    assert(lookup_cplusplus_hash_sdb("class") == 41);
    assert(lookup_cplusplus_hash_sdb("reinterpret_cast") == 77);
    assert(lookup_cplusplus_hash_sdb("friend") == 59);
    assert(lookup_cplusplus_hash_sdb("goto") == 60);
    assert(lookup_cplusplus_hash_sdb("private") == 73);
    assert(lookup_cplusplus_hash_sdb("static_cast") == 85);
    assert(lookup_cplusplus_hash_sdb("__asm") == 2);
    assert(lookup_cplusplus_hash_sdb("__alignof__") == 1);
    assert(lookup_cplusplus_hash_sdb("for") == 58);
    assert(lookup_cplusplus_hash_sdb("__complex__") == 7);
    assert(lookup_cplusplus_hash_sdb("__typeof") == 25);
    assert(lookup_cplusplus_hash_sdb("not") == 68);
    assert(lookup_cplusplus_hash_sdb("return") == 78);
    assert(lookup_cplusplus_hash_sdb("__signed__") == 23);
    assert(lookup_cplusplus_hash_sdb("using") == 99);
    assert(lookup_cplusplus_hash_sdb("typedef") == 93);
    assert(lookup_cplusplus_hash_sdb("__complex") == 6);
    assert(lookup_cplusplus_hash_sdb("asm") == 30);
    assert(lookup_cplusplus_hash_sdb("inline") == 62);
    assert(lookup_cplusplus_hash_sdb("void") == 101);
    assert(lookup_cplusplus_hash_sdb("char") == 40);
    assert(lookup_cplusplus_hash_sdb("struct") == 86);
    assert(lookup_cplusplus_hash_sdb("if") == 61);
    assert(lookup_cplusplus_hash_sdb("virtual") == 100);
    assert(lookup_cplusplus_hash_sdb("__restrict__") == 20);
    assert(lookup_cplusplus_hash_sdb("template") == 88);
    assert(lookup_cplusplus_hash_sdb("__signed") == 22);
    assert(lookup_cplusplus_hash_sdb("operator") == 70);
    assert(lookup_cplusplus_hash_sdb("namespace") == 66);
    assert(lookup_cplusplus_hash_sdb("sizeof") == 83);
    assert(lookup_cplusplus_hash_sdb("typeid") == 95);
    assert(lookup_cplusplus_hash_sdb("bitand") == 34);
    assert(lookup_cplusplus_hash_sdb("sigof") == 82);
    assert(lookup_cplusplus_hash_sdb("bool") == 36);
    assert(lookup_cplusplus_hash_sdb("__volatile") == 27);
    assert(lookup_cplusplus_hash_sdb("break") == 37);
    assert(lookup_cplusplus_hash_sdb("export") == 54);
    assert(lookup_cplusplus_hash_sdb("continue") == 45);
    assert(lookup_cplusplus_hash_sdb("static") == 84);
    assert(lookup_cplusplus_hash_sdb("double") == 49);
    assert(lookup_cplusplus_hash_sdb("while") == 103);
    assert(lookup_cplusplus_hash_sdb("const_cast") == 44);
    assert(lookup_cplusplus_hash_sdb("const") == 43);
    assert(lookup_cplusplus_hash_sdb("explicit") == 53);
    assert(lookup_cplusplus_hash_sdb("__imag") == 11);
    assert(lookup_cplusplus_hash_sdb("protected") == 74);
    assert(lookup_cplusplus_hash_sdb("__asm__") == 3);
    assert(lookup_cplusplus_hash_sdb("auto") == 33);
    assert(lookup_cplusplus_hash_sdb("__volatile__") == 28);
    assert(lookup_cplusplus_hash_sdb("catch") == 39);
    assert(lookup_cplusplus_hash_sdb("and") == 31);
    assert(lookup_cplusplus_hash_sdb("throw") == 90);
    assert(lookup_cplusplus_hash_sdb("public") == 75);
    assert(lookup_cplusplus_hash_sdb("int") == 63);
    assert(lookup_cplusplus_hash_sdb("true") == 91);
    assert(lookup_cplusplus_hash_sdb("__wchar_t") == 29);
    assert(lookup_cplusplus_hash_sdb("__inline__") == 14);
    assert(lookup_cplusplus_hash_sdb("do") == 48);
    assert(lookup_cplusplus_hash_sdb("else") == 51);
    assert(lookup_cplusplus_hash_sdb("default") == 46);
    assert(lookup_cplusplus_hash_sdb("__inline") == 13);
    assert(lookup_cplusplus_hash_sdb("float") == 57);
    assert(lookup_cplusplus_hash_sdb("register") == 76);
    assert(lookup_cplusplus_hash_sdb("mutable") == 65);
    assert(lookup_cplusplus_hash_sdb("try") == 92);
    assert(lookup_cplusplus_hash_sdb("__null") == 16);
    assert(lookup_cplusplus_hash_sdb("or") == 71);
    assert(lookup_cplusplus_hash_sdb("dynamic_cast") == 50);
    assert(lookup_cplusplus_hash_sdb("__signature__") == 21);
    assert(lookup_cplusplus_hash_sdb("signature") == 80);
    assert(lookup_cplusplus_hash_sdb("__real__") == 18);
    assert(lookup_cplusplus_hash_sdb("__alignof") == 0);
    assert(lookup_cplusplus_hash_sdb("delete") == 47);
    assert(lookup_cplusplus_hash_sdb("typeof") == 96);
    assert(lookup_cplusplus_hash_sdb("long") == 64);
    assert(lookup_cplusplus_hash_sdb("volatile") == 102);
    assert(lookup_cplusplus_hash_sdb("short") == 79);
    assert(lookup_cplusplus_hash_sdb("false") == 56);
    assert(lookup_cplusplus_hash_sdb("unsigned") == 98);
    assert(lookup_cplusplus_hash_sdb("__real") == 17);
    assert(lookup_cplusplus_hash_sdb("__sigof__") == 24);
    assert(lookup_cplusplus_hash_sdb("new") == 67);
    assert(lookup_cplusplus_hash_sdb("case") == 38);
    assert(lookup_cplusplus_hash_sdb("compl") == 42);
    assert(lookup_cplusplus_hash_sdb("enum") == 52);
    assert(lookup_cplusplus_hash_sdb("__attribute__") == 5);
}
