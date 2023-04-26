
//lookup: name=lookup_ada_pred_hash1, dataset=ada-pred, hash=hash1
int lookup_ada_pred_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 99) * 2;
    static std::string_view lookup[198] = {
        "",
        "",
        "float", // 1090 (0x442)
        "first", // 1090 (0x442)
        "",
        "",
        "digits", // 1290 (0x50a)
        "",
        "base", // 796 (0x31c)
        "",
        "last", // 896 (0x380)
        "",
        "value", // 1095 (0x447)
        "",
        "storage_error", // 2977 (0xba1)
        "machine_radix", // 2977 (0xba1)
        "",
        "",
        "",
        "",
        "",
        "",
        "constrained", // 2189 (0x88d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "callable", // 1600 (0x640)
        "",
        "",
        "",
        "storage_size", // 2592 (0xa20)
        "",
        "",
        "",
        "tasking_error", // 2990 (0xbae)
        "fore", // 812 (0x32c)
        "positive", // 1704 (0x6a8)
        "string", // 1308 (0x51c)
        "",
        "",
        "",
        "",
        "",
        "",
        "false", // 1015 (0x3f7)
        "",
        "small", // 1115 (0x45b)
        "width", // 1115 (0x45b)
        "",
        "",
        "",
        "",
        "machine_mantissa", // 3296 (0xce0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "character", // 1917 (0x77d)
        "safe_emax", // 2115 (0x843)
        "",
        "",
        "",
        "",
        "",
        "",
        "image", // 1030 (0x406)
        "",
        "natural", // 1526 (0x5f6)
        "numeric_error", // 2912 (0xb60)
        "constraint_error", // 3408 (0xd50)
        "",
        "",
        "",
        "",
        "",
        "aft", // 639 (0x27f)
        "",
        "machine_overflows", // 3808 (0xee0)
        "",
        "",
        "",
        "integer", // 1533 (0x5fd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "safe_small", // 2230 (0x8b6)
        "",
        "",
        "",
        "machine_emin", // 2628 (0xa44)
        "",
        "large", // 1045 (0x415)
        "",
        "pred", // 848 (0x350)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "firstbit", // 1744 (0x6d0)
        "",
        "",
        "",
        "",
        "",
        "mantissa", // 1648 (0x670)
        "succ", // 856 (0x358)
        "",
        "",
        "",
        "",
        "program_error", // 2938 (0xb7a)
        "machine_rounds", // 3136 (0xc40)
        "",
        "",
        "",
        "",
        "boolean", // 1456 (0x5b0)
        "",
        "",
        "",
        "size", // 864 (0x360)
        "",
        "",
        "",
        "",
        "",
        "machine_emax", // 2748 (0xabc)
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
        "safe_large", // 2160 (0x870)
        "terminated", // 2160 (0x870)
        "",
        "",
        "lastbit", // 1568 (0x620)
        "",
        "length", // 1272 (0x4f8)
        "val", // 678 (0x2a6)
        "count", // 1075 (0x433)
        "range", // 1075 (0x433)
        "",
        "",
        "pos", // 681 (0x2a9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "epsilon", // 1477 (0x5c5)
        "",
        "emax", // 884 (0x374)
        "",
        "position", // 1776 (0x6f0)
        "",
        "delta", // 985 (0x3d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "address", // 1484 (0x5cc)
        "",
    };
    static int values[198] = {
        -1,
        -1,
        4, // 1090 (0x442)
        24, // 1090 (0x442)
        -1,
        -1,
        21, // 1290 (0x50a)
        -1,
        16, // 796 (0x31c)
        -1,
        29, // 896 (0x380)
        -1,
        52, // 1095 (0x447)
        -1,
        10, // 2977 (0xba1)
        36, // 2977 (0xba1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 2189 (0x88d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 1600 (0x640)
        -1,
        -1,
        -1,
        48, // 2592 (0xa20)
        -1,
        -1,
        -1,
        12, // 2990 (0xbae)
        26, // 812 (0x32c)
        8, // 1704 (0x6a8)
        11, // 1308 (0x51c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 1015 (0x3f7)
        -1,
        47, // 1115 (0x45b)
        53, // 1115 (0x45b)
        -1,
        -1,
        -1,
        -1,
        34, // 3296 (0xce0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 1917 (0x77d)
        43, // 2115 (0x843)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 1030 (0x406)
        -1,
        6, // 1526 (0x5f6)
        7, // 2912 (0xb60)
        2, // 3408 (0xd50)
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 639 (0x27f)
        -1,
        35, // 3808 (0xee0)
        -1,
        -1,
        -1,
        5, // 1533 (0x5fd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 2230 (0x8b6)
        -1,
        -1,
        -1,
        33, // 2628 (0xa44)
        -1,
        28, // 1045 (0x415)
        -1,
        41, // 848 (0x350)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1744 (0x6d0)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 1648 (0x670)
        49, // 856 (0x358)
        -1,
        -1,
        -1,
        -1,
        9, // 2938 (0xb7a)
        37, // 3136 (0xc40)
        -1,
        -1,
        -1,
        -1,
        0, // 1456 (0x5b0)
        -1,
        -1,
        -1,
        46, // 864 (0x360)
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 2748 (0xabc)
        -1,
        13, // 868 (0x364)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 2160 (0x870)
        50, // 2160 (0x870)
        -1,
        -1,
        30, // 1568 (0x620)
        -1,
        31, // 1272 (0x4f8)
        51, // 678 (0x2a6)
        19, // 1075 (0x433)
        42, // 1075 (0x433)
        -1,
        -1,
        39, // 681 (0x2a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 1477 (0x5c5)
        -1,
        22, // 884 (0x374)
        -1,
        40, // 1776 (0x6f0)
        -1,
        20, // 985 (0x3d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 1484 (0x5cc)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_ada_pred_hash1, dataset=ada-pred, hash=hash1
void check_ada_pred_hash1() {
    assert(lookup_ada_pred_hash1("float") == 4);
    assert(lookup_ada_pred_hash1("first") == 24);
    assert(lookup_ada_pred_hash1("digits") == 21);
    assert(lookup_ada_pred_hash1("base") == 16);
    assert(lookup_ada_pred_hash1("last") == 29);
    assert(lookup_ada_pred_hash1("value") == 52);
    assert(lookup_ada_pred_hash1("storage_error") == 10);
    assert(lookup_ada_pred_hash1("machine_radix") == 36);
    assert(lookup_ada_pred_hash1("constrained") == 18);
    assert(lookup_ada_pred_hash1("callable") == 17);
    assert(lookup_ada_pred_hash1("storage_size") == 48);
    assert(lookup_ada_pred_hash1("tasking_error") == 12);
    assert(lookup_ada_pred_hash1("fore") == 26);
    assert(lookup_ada_pred_hash1("positive") == 8);
    assert(lookup_ada_pred_hash1("string") == 11);
    assert(lookup_ada_pred_hash1("false") == 3);
    assert(lookup_ada_pred_hash1("small") == 47);
    assert(lookup_ada_pred_hash1("width") == 53);
    assert(lookup_ada_pred_hash1("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash1("character") == 1);
    assert(lookup_ada_pred_hash1("safe_emax") == 43);
    assert(lookup_ada_pred_hash1("image") == 27);
    assert(lookup_ada_pred_hash1("natural") == 6);
    assert(lookup_ada_pred_hash1("numeric_error") == 7);
    assert(lookup_ada_pred_hash1("constraint_error") == 2);
    assert(lookup_ada_pred_hash1("aft") == 15);
    assert(lookup_ada_pred_hash1("machine_overflows") == 35);
    assert(lookup_ada_pred_hash1("integer") == 5);
    assert(lookup_ada_pred_hash1("safe_small") == 45);
    assert(lookup_ada_pred_hash1("machine_emin") == 33);
    assert(lookup_ada_pred_hash1("large") == 28);
    assert(lookup_ada_pred_hash1("pred") == 41);
    assert(lookup_ada_pred_hash1("firstbit") == 25);
    assert(lookup_ada_pred_hash1("mantissa") == 38);
    assert(lookup_ada_pred_hash1("succ") == 49);
    assert(lookup_ada_pred_hash1("program_error") == 9);
    assert(lookup_ada_pred_hash1("machine_rounds") == 37);
    assert(lookup_ada_pred_hash1("boolean") == 0);
    assert(lookup_ada_pred_hash1("size") == 46);
    assert(lookup_ada_pred_hash1("machine_emax") == 32);
    assert(lookup_ada_pred_hash1("true") == 13);
    assert(lookup_ada_pred_hash1("safe_large") == 44);
    assert(lookup_ada_pred_hash1("terminated") == 50);
    assert(lookup_ada_pred_hash1("lastbit") == 30);
    assert(lookup_ada_pred_hash1("length") == 31);
    assert(lookup_ada_pred_hash1("val") == 51);
    assert(lookup_ada_pred_hash1("count") == 19);
    assert(lookup_ada_pred_hash1("range") == 42);
    assert(lookup_ada_pred_hash1("pos") == 39);
    assert(lookup_ada_pred_hash1("epsilon") == 23);
    assert(lookup_ada_pred_hash1("emax") == 22);
    assert(lookup_ada_pred_hash1("position") == 40);
    assert(lookup_ada_pred_hash1("delta") == 20);
    assert(lookup_ada_pred_hash1("address") == 14);
}

//lookup: name=lookup_ada_pred_hash2, dataset=ada-pred, hash=hash2
int lookup_ada_pred_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 69) * 2;
    static std::string_view lookup[138] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "large", // 10905 (0x2a99)
        "",
        "positive", // 11320 (0x2c38)
        "succ", // 11389 (0x2c7d)
        "storage_error", // 13115 (0x333b)
        "",
        "",
        "",
        "",
        "",
        "aft", // 11255 (0x2bf7)
        "mantissa", // 10565 (0x2945)
        "",
        "",
        "safe_small", // 12430 (0x308e)
        "",
        "storage_size", // 11603 (0x2d53)
        "",
        "",
        "",
        "safe_large", // 11605 (0x2d55)
        "",
        "",
        "",
        "boolean", // 10779 (0x2a1b)
        "",
        "program_error", // 12781 (0x31ed)
        "",
        "fore", // 10298 (0x283a)
        "",
        "false", // 10299 (0x283b)
        "terminated", // 11610 (0x2d5a)
        "natural", // 11887 (0x2e6f)
        "size", // 11611 (0x2d5b)
        "",
        "",
        "",
        "",
        "",
        "",
        "constraint_error", // 11270 (0x2c06)
        "",
        "",
        "",
        "firstbit", // 11824 (0x2e30)
        "",
        "pred", // 11204 (0x2bc4)
        "",
        "count", // 11481 (0x2cd9)
        "",
        "constrained", // 9895 (0x26a7)
        "",
        "machine_overflows", // 12518 (0x30e6)
        "",
        "width", // 12381 (0x305d)
        "",
        "",
        "",
        "machine_mantissa", // 10589 (0x295d)
        "",
        "",
        "",
        "",
        "",
        "base", // 9902 (0x26ae)
        "machine_emax", // 13076 (0x3314)
        "integer", // 11973 (0x2ec5)
        "machine_radix", // 13077 (0x3315)
        "delta", // 9697 (0x25e1)
        "",
        "float", // 11837 (0x2e3d)
        "first", // 11837 (0x2e3d)
        "",
        "",
        "numeric_error", // 12529 (0x30f1)
        "",
        "",
        "",
        "tasking_error", // 13221 (0x33a5)
        "",
        "image", // 10600 (0x2968)
        "last", // 12532 (0x30f4)
        "string", // 11843 (0x2e43)
        "digits", // 11498 (0x2cea)
        "",
        "",
        "lastbit", // 12535 (0x30f7)
        "position", // 12328 (0x3028)
        "address", // 11156 (0x2b94)
        "value", // 11915 (0x2e8b)
        "character", // 11295 (0x2c1f)
        "machine_rounds", // 12537 (0x30f9)
        "emax", // 12124 (0x2f5c)
        "pos", // 12883 (0x3253)
        "",
        "",
        "true", // 11712 (0x2dc0)
        "val", // 12747 (0x31cb)
        "",
        "",
        "",
        "",
        "",
        "",
        "callable", // 9991 (0x2707)
        "",
        "",
        "",
        "machine_emin", // 11994 (0x2eda)
        "",
        "",
        "",
        "",
        "",
        "length", // 11238 (0x2be6)
        "",
        "",
        "",
        "safe_emax", // 13793 (0x35e1)
        "",
        "",
        "",
        "",
        "",
        "epsilon", // 11105 (0x2b61)
        "range", // 11519 (0x2cff)
        "small", // 12417 (0x3081)
        "",
        "",
        "",
        "",
        "",
    };
    static int values[138] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 10905 (0x2a99)
        -1,
        8, // 11320 (0x2c38)
        49, // 11389 (0x2c7d)
        10, // 13115 (0x333b)
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 11255 (0x2bf7)
        38, // 10565 (0x2945)
        -1,
        -1,
        45, // 12430 (0x308e)
        -1,
        48, // 11603 (0x2d53)
        -1,
        -1,
        -1,
        44, // 11605 (0x2d55)
        -1,
        -1,
        -1,
        0, // 10779 (0x2a1b)
        -1,
        9, // 12781 (0x31ed)
        -1,
        26, // 10298 (0x283a)
        -1,
        3, // 10299 (0x283b)
        50, // 11610 (0x2d5a)
        6, // 11887 (0x2e6f)
        46, // 11611 (0x2d5b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 11270 (0x2c06)
        -1,
        -1,
        -1,
        25, // 11824 (0x2e30)
        -1,
        41, // 11204 (0x2bc4)
        -1,
        19, // 11481 (0x2cd9)
        -1,
        18, // 9895 (0x26a7)
        -1,
        35, // 12518 (0x30e6)
        -1,
        53, // 12381 (0x305d)
        -1,
        -1,
        -1,
        34, // 10589 (0x295d)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 9902 (0x26ae)
        32, // 13076 (0x3314)
        5, // 11973 (0x2ec5)
        36, // 13077 (0x3315)
        20, // 9697 (0x25e1)
        -1,
        4, // 11837 (0x2e3d)
        24, // 11837 (0x2e3d)
        -1,
        -1,
        7, // 12529 (0x30f1)
        -1,
        -1,
        -1,
        12, // 13221 (0x33a5)
        -1,
        27, // 10600 (0x2968)
        29, // 12532 (0x30f4)
        11, // 11843 (0x2e43)
        21, // 11498 (0x2cea)
        -1,
        -1,
        30, // 12535 (0x30f7)
        40, // 12328 (0x3028)
        14, // 11156 (0x2b94)
        52, // 11915 (0x2e8b)
        1, // 11295 (0x2c1f)
        37, // 12537 (0x30f9)
        22, // 12124 (0x2f5c)
        39, // 12883 (0x3253)
        -1,
        -1,
        13, // 11712 (0x2dc0)
        51, // 12747 (0x31cb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 9991 (0x2707)
        -1,
        -1,
        -1,
        33, // 11994 (0x2eda)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 11238 (0x2be6)
        -1,
        -1,
        -1,
        43, // 13793 (0x35e1)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 11105 (0x2b61)
        42, // 11519 (0x2cff)
        47, // 12417 (0x3081)
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

//check: name=check_ada_pred_hash2, dataset=ada-pred, hash=hash2
void check_ada_pred_hash2() {
    assert(lookup_ada_pred_hash2("large") == 28);
    assert(lookup_ada_pred_hash2("positive") == 8);
    assert(lookup_ada_pred_hash2("succ") == 49);
    assert(lookup_ada_pred_hash2("storage_error") == 10);
    assert(lookup_ada_pred_hash2("aft") == 15);
    assert(lookup_ada_pred_hash2("mantissa") == 38);
    assert(lookup_ada_pred_hash2("safe_small") == 45);
    assert(lookup_ada_pred_hash2("storage_size") == 48);
    assert(lookup_ada_pred_hash2("safe_large") == 44);
    assert(lookup_ada_pred_hash2("boolean") == 0);
    assert(lookup_ada_pred_hash2("program_error") == 9);
    assert(lookup_ada_pred_hash2("fore") == 26);
    assert(lookup_ada_pred_hash2("false") == 3);
    assert(lookup_ada_pred_hash2("terminated") == 50);
    assert(lookup_ada_pred_hash2("natural") == 6);
    assert(lookup_ada_pred_hash2("size") == 46);
    assert(lookup_ada_pred_hash2("constraint_error") == 2);
    assert(lookup_ada_pred_hash2("firstbit") == 25);
    assert(lookup_ada_pred_hash2("pred") == 41);
    assert(lookup_ada_pred_hash2("count") == 19);
    assert(lookup_ada_pred_hash2("constrained") == 18);
    assert(lookup_ada_pred_hash2("machine_overflows") == 35);
    assert(lookup_ada_pred_hash2("width") == 53);
    assert(lookup_ada_pred_hash2("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash2("base") == 16);
    assert(lookup_ada_pred_hash2("machine_emax") == 32);
    assert(lookup_ada_pred_hash2("integer") == 5);
    assert(lookup_ada_pred_hash2("machine_radix") == 36);
    assert(lookup_ada_pred_hash2("delta") == 20);
    assert(lookup_ada_pred_hash2("float") == 4);
    assert(lookup_ada_pred_hash2("first") == 24);
    assert(lookup_ada_pred_hash2("numeric_error") == 7);
    assert(lookup_ada_pred_hash2("tasking_error") == 12);
    assert(lookup_ada_pred_hash2("image") == 27);
    assert(lookup_ada_pred_hash2("last") == 29);
    assert(lookup_ada_pred_hash2("string") == 11);
    assert(lookup_ada_pred_hash2("digits") == 21);
    assert(lookup_ada_pred_hash2("lastbit") == 30);
    assert(lookup_ada_pred_hash2("position") == 40);
    assert(lookup_ada_pred_hash2("address") == 14);
    assert(lookup_ada_pred_hash2("value") == 52);
    assert(lookup_ada_pred_hash2("character") == 1);
    assert(lookup_ada_pred_hash2("machine_rounds") == 37);
    assert(lookup_ada_pred_hash2("emax") == 22);
    assert(lookup_ada_pred_hash2("pos") == 39);
    assert(lookup_ada_pred_hash2("true") == 13);
    assert(lookup_ada_pred_hash2("val") == 51);
    assert(lookup_ada_pred_hash2("callable") == 17);
    assert(lookup_ada_pred_hash2("machine_emin") == 33);
    assert(lookup_ada_pred_hash2("length") == 31);
    assert(lookup_ada_pred_hash2("safe_emax") == 43);
    assert(lookup_ada_pred_hash2("epsilon") == 23);
    assert(lookup_ada_pred_hash2("range") == 42);
    assert(lookup_ada_pred_hash2("small") == 47);
}

//lookup: name=lookup_ada_pred_hash3, dataset=ada-pred, hash=hash3
int lookup_ada_pred_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 333) * 1;
    static std::string_view lookup[333] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "pred", // 29978 (0x751a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "epsilon", // 27989 (0x6d55)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "true", // 31003 (0x791b)
        "machine_radix", // 31670 (0x7bb6)
        "false", // 27675 (0x6c1b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "integer", // 29015 (0x7157)
        "",
        "",
        "character", // 28019 (0x6d73)
        "",
        "",
        "",
        "",
        "",
        "small", // 31022 (0x792e)
        "",
        "",
        "",
        "",
        "",
        "first", // 27698 (0x6c32)
        "",
        "",
        "float", // 27701 (0x6c35)
        "",
        "",
        "",
        "",
        "safe_large", // 32368 (0x7e70)
        "",
        "",
        "width", // 32038 (0x7d26)
        "base", // 26378 (0x670a)
        "",
        "",
        "safe_small", // 32375 (0x7e77)
        "",
        "",
        "",
        "",
        "",
        "pos", // 29717 (0x7415)
        "",
        "",
        "",
        "",
        "machine_emin", // 31387 (0x7a9b)
        "",
        "callable", // 27726 (0x6c4e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_emax", // 31397 (0x7aa5)
        "",
        "",
        "",
        "positive", // 31068 (0x795c)
        "",
        "",
        "size", // 30738 (0x7812)
        "",
        "",
        "",
        "",
        "",
        "position", // 31077 (0x7965)
        "",
        "fore", // 27416 (0x6b18)
        "range", // 30747 (0x781b)
        "succ", // 30748 (0x781c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_overflows", // 32757 (0x7ff5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "lastbit", // 29772 (0x744c)
        "value", // 31771 (0x7c1b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "safe_emax", // 32114 (0x7d72)
        "",
        "program_error", // 32449 (0x7ec1)
        "",
        "image", // 28455 (0x6f27)
        "",
        "digits", // 27458 (0x6b42)
        "",
        "",
        "",
        "tasking_error", // 33456 (0x82b0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_mantissa", // 32466 (0x7ed2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "length", // 29491 (0x7333)
        "",
        "",
        "delta", // 27163 (0x6a1b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "emax", // 27177 (0x6a29)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "firstbit", // 28517 (0x6f65)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "aft", // 25869 (0x650d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "large", // 29211 (0x721b)
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
        "",
        "storage_error", // 33219 (0x81c3)
        "constrained", // 28558 (0x6f8e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "val", // 31232 (0x7a00)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "count", // 26936 (0x6938)
        "",
        "",
        "storage_size", // 32933 (0x80a5)
        "constraint_error", // 29937 (0x74f1)
        "",
        "",
        "machine_rounds", // 31938 (0x7cc2)
        "",
        "numeric_error", // 31940 (0x7cc4)
        "natural", // 30276 (0x7644)
        "",
        "",
        "",
        "",
        "",
        "mantissa", // 30282 (0x764a)
        "",
        "",
        "last", // 28953 (0x7119)
        "",
        "",
        "address", // 26958 (0x694e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "terminated", // 32627 (0x7f73)
        "",
        "string", // 31297 (0x7a41)
        "",
        "",
        "",
        "",
    };
    static int values[333] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 29978 (0x751a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 27989 (0x6d55)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 31003 (0x791b)
        36, // 31670 (0x7bb6)
        3, // 27675 (0x6c1b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 29015 (0x7157)
        -1,
        -1,
        1, // 28019 (0x6d73)
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 31022 (0x792e)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 27698 (0x6c32)
        -1,
        -1,
        4, // 27701 (0x6c35)
        -1,
        -1,
        -1,
        -1,
        44, // 32368 (0x7e70)
        -1,
        -1,
        53, // 32038 (0x7d26)
        16, // 26378 (0x670a)
        -1,
        -1,
        45, // 32375 (0x7e77)
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 29717 (0x7415)
        -1,
        -1,
        -1,
        -1,
        33, // 31387 (0x7a9b)
        -1,
        17, // 27726 (0x6c4e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 31397 (0x7aa5)
        -1,
        -1,
        -1,
        8, // 31068 (0x795c)
        -1,
        -1,
        46, // 30738 (0x7812)
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 31077 (0x7965)
        -1,
        26, // 27416 (0x6b18)
        42, // 30747 (0x781b)
        49, // 30748 (0x781c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 32757 (0x7ff5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 29772 (0x744c)
        52, // 31771 (0x7c1b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 32114 (0x7d72)
        -1,
        9, // 32449 (0x7ec1)
        -1,
        27, // 28455 (0x6f27)
        -1,
        21, // 27458 (0x6b42)
        -1,
        -1,
        -1,
        12, // 33456 (0x82b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 32466 (0x7ed2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 29491 (0x7333)
        -1,
        -1,
        20, // 27163 (0x6a1b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 27177 (0x6a29)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 28517 (0x6f65)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 25869 (0x650d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 29211 (0x721b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 27220 (0x6a54)
        -1,
        -1,
        -1,
        -1,
        10, // 33219 (0x81c3)
        18, // 28558 (0x6f8e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 31232 (0x7a00)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 26936 (0x6938)
        -1,
        -1,
        48, // 32933 (0x80a5)
        2, // 29937 (0x74f1)
        -1,
        -1,
        37, // 31938 (0x7cc2)
        -1,
        7, // 31940 (0x7cc4)
        6, // 30276 (0x7644)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 30282 (0x764a)
        -1,
        -1,
        29, // 28953 (0x7119)
        -1,
        -1,
        14, // 26958 (0x694e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 32627 (0x7f73)
        -1,
        11, // 31297 (0x7a41)
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

//check: name=check_ada_pred_hash3, dataset=ada-pred, hash=hash3
void check_ada_pred_hash3() {
    assert(lookup_ada_pred_hash3("pred") == 41);
    assert(lookup_ada_pred_hash3("epsilon") == 23);
    assert(lookup_ada_pred_hash3("true") == 13);
    assert(lookup_ada_pred_hash3("machine_radix") == 36);
    assert(lookup_ada_pred_hash3("false") == 3);
    assert(lookup_ada_pred_hash3("integer") == 5);
    assert(lookup_ada_pred_hash3("character") == 1);
    assert(lookup_ada_pred_hash3("small") == 47);
    assert(lookup_ada_pred_hash3("first") == 24);
    assert(lookup_ada_pred_hash3("float") == 4);
    assert(lookup_ada_pred_hash3("safe_large") == 44);
    assert(lookup_ada_pred_hash3("width") == 53);
    assert(lookup_ada_pred_hash3("base") == 16);
    assert(lookup_ada_pred_hash3("safe_small") == 45);
    assert(lookup_ada_pred_hash3("pos") == 39);
    assert(lookup_ada_pred_hash3("machine_emin") == 33);
    assert(lookup_ada_pred_hash3("callable") == 17);
    assert(lookup_ada_pred_hash3("machine_emax") == 32);
    assert(lookup_ada_pred_hash3("positive") == 8);
    assert(lookup_ada_pred_hash3("size") == 46);
    assert(lookup_ada_pred_hash3("position") == 40);
    assert(lookup_ada_pred_hash3("fore") == 26);
    assert(lookup_ada_pred_hash3("range") == 42);
    assert(lookup_ada_pred_hash3("succ") == 49);
    assert(lookup_ada_pred_hash3("machine_overflows") == 35);
    assert(lookup_ada_pred_hash3("lastbit") == 30);
    assert(lookup_ada_pred_hash3("value") == 52);
    assert(lookup_ada_pred_hash3("safe_emax") == 43);
    assert(lookup_ada_pred_hash3("program_error") == 9);
    assert(lookup_ada_pred_hash3("image") == 27);
    assert(lookup_ada_pred_hash3("digits") == 21);
    assert(lookup_ada_pred_hash3("tasking_error") == 12);
    assert(lookup_ada_pred_hash3("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash3("length") == 31);
    assert(lookup_ada_pred_hash3("delta") == 20);
    assert(lookup_ada_pred_hash3("emax") == 22);
    assert(lookup_ada_pred_hash3("firstbit") == 25);
    assert(lookup_ada_pred_hash3("aft") == 15);
    assert(lookup_ada_pred_hash3("large") == 28);
    assert(lookup_ada_pred_hash3("boolean") == 0);
    assert(lookup_ada_pred_hash3("storage_error") == 10);
    assert(lookup_ada_pred_hash3("constrained") == 18);
    assert(lookup_ada_pred_hash3("val") == 51);
    assert(lookup_ada_pred_hash3("count") == 19);
    assert(lookup_ada_pred_hash3("storage_size") == 48);
    assert(lookup_ada_pred_hash3("constraint_error") == 2);
    assert(lookup_ada_pred_hash3("machine_rounds") == 37);
    assert(lookup_ada_pred_hash3("numeric_error") == 7);
    assert(lookup_ada_pred_hash3("natural") == 6);
    assert(lookup_ada_pred_hash3("mantissa") == 38);
    assert(lookup_ada_pred_hash3("last") == 29);
    assert(lookup_ada_pred_hash3("address") == 14);
    assert(lookup_ada_pred_hash3("terminated") == 50);
    assert(lookup_ada_pred_hash3("string") == 11);
}

//lookup: name=lookup_ada_pred_hash_sum0, dataset=ada-pred, hash=hash_sum0
int lookup_ada_pred_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 84) * 2;
    static std::string_view lookup[168] = {
        "",
        "",
        "",
        "",
        "constrained", // 1178 (0x49a)
        "pos", // 338 (0x152)
        "natural", // 759 (0x2f7)
        "",
        "machine_mantissa", // 1684 (0x694)
        "",
        "",
        "",
        "epsilon", // 762 (0x2fa)
        "",
        "emax", // 427 (0x1ab)
        "pred", // 427 (0x1ab)
        "fore", // 428 (0x1ac)
        "",
        "",
        "",
        "succ", // 430 (0x1ae)
        "",
        "image", // 515 (0x203)
        "",
        "machine_radix", // 1356 (0x54c)
        "",
        "safe_emax", // 937 (0x3a9)
        "",
        "",
        "",
        "",
        "",
        "last", // 436 (0x1b4)
        "",
        "character", // 941 (0x3ad)
        "",
        "delta", // 522 (0x20a)
        "",
        "false", // 523 (0x20b)
        "large", // 523 (0x20b)
        "",
        "",
        "range", // 525 (0x20d)
        "",
        "",
        "",
        "size", // 443 (0x1bb)
        "",
        "mantissa", // 864 (0x360)
        "",
        "safe_large", // 1033 (0x409)
        "",
        "",
        "",
        "",
        "",
        "true", // 448 (0x1c0)
        "",
        "",
        "",
        "float", // 534 (0x216)
        "",
        "firstbit", // 871 (0x367)
        "",
        "",
        "",
        "small", // 537 (0x219)
        "",
        "",
        "",
        "storage_size", // 1295 (0x50f)
        "",
        "",
        "",
        "value", // 541 (0x21d)
        "",
        "",
        "",
        "safe_small", // 1047 (0x417)
        "",
        "width", // 544 (0x220)
        "",
        "",
        "",
        "",
        "",
        "positive", // 883 (0x373)
        "",
        "",
        "",
        "position", // 885 (0x375)
        "",
        "",
        "",
        "",
        "",
        "first", // 552 (0x228)
        "",
        "count", // 553 (0x229)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "length", // 642 (0x282)
        "",
        "machine_overflows", // 1819 (0x71b)
        "",
        "digits", // 644 (0x284)
        "",
        "",
        "",
        "tasking_error", // 1402 (0x57a)
        "",
        "machine_rounds", // 1487 (0x5cf)
        "",
        "numeric_error", // 1404 (0x57c)
        "callable", // 816 (0x330)
        "terminated", // 1069 (0x42d)
        "",
        "constraint_error", // 1742 (0x6ce)
        "storage_error", // 1406 (0x57e)
        "aft", // 315 (0x13b)
        "",
        "boolean", // 736 (0x2e0)
        "",
        "program_error", // 1409 (0x581)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_emin", // 1245 (0x4dd)
        "",
        "address", // 742 (0x2e6)
        "",
        "machine_emax", // 1247 (0x4df)
        "val", // 323 (0x143)
        "",
        "",
        "",
        "",
        "",
        "",
        "string", // 663 (0x297)
        "base", // 411 (0x19b)
        "",
        "",
        "",
        "",
        "integer", // 750 (0x2ee)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "lastbit", // 755 (0x2f3)
        "",
    };
    static int values[168] = {
        -1,
        -1,
        -1,
        -1,
        18, // 1178 (0x49a)
        39, // 338 (0x152)
        6, // 759 (0x2f7)
        -1,
        34, // 1684 (0x694)
        -1,
        -1,
        -1,
        23, // 762 (0x2fa)
        -1,
        22, // 427 (0x1ab)
        41, // 427 (0x1ab)
        26, // 428 (0x1ac)
        -1,
        -1,
        -1,
        49, // 430 (0x1ae)
        -1,
        27, // 515 (0x203)
        -1,
        36, // 1356 (0x54c)
        -1,
        43, // 937 (0x3a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 436 (0x1b4)
        -1,
        1, // 941 (0x3ad)
        -1,
        20, // 522 (0x20a)
        -1,
        3, // 523 (0x20b)
        28, // 523 (0x20b)
        -1,
        -1,
        42, // 525 (0x20d)
        -1,
        -1,
        -1,
        46, // 443 (0x1bb)
        -1,
        38, // 864 (0x360)
        -1,
        44, // 1033 (0x409)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 448 (0x1c0)
        -1,
        -1,
        -1,
        4, // 534 (0x216)
        -1,
        25, // 871 (0x367)
        -1,
        -1,
        -1,
        47, // 537 (0x219)
        -1,
        -1,
        -1,
        48, // 1295 (0x50f)
        -1,
        -1,
        -1,
        52, // 541 (0x21d)
        -1,
        -1,
        -1,
        45, // 1047 (0x417)
        -1,
        53, // 544 (0x220)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 883 (0x373)
        -1,
        -1,
        -1,
        40, // 885 (0x375)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 552 (0x228)
        -1,
        19, // 553 (0x229)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 642 (0x282)
        -1,
        35, // 1819 (0x71b)
        -1,
        21, // 644 (0x284)
        -1,
        -1,
        -1,
        12, // 1402 (0x57a)
        -1,
        37, // 1487 (0x5cf)
        -1,
        7, // 1404 (0x57c)
        17, // 816 (0x330)
        50, // 1069 (0x42d)
        -1,
        2, // 1742 (0x6ce)
        10, // 1406 (0x57e)
        15, // 315 (0x13b)
        -1,
        0, // 736 (0x2e0)
        -1,
        9, // 1409 (0x581)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 1245 (0x4dd)
        -1,
        14, // 742 (0x2e6)
        -1,
        32, // 1247 (0x4df)
        51, // 323 (0x143)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 663 (0x297)
        16, // 411 (0x19b)
        -1,
        -1,
        -1,
        -1,
        5, // 750 (0x2ee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 755 (0x2f3)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_ada_pred_hash_sum0, dataset=ada-pred, hash=hash_sum0
void check_ada_pred_hash_sum0() {
    assert(lookup_ada_pred_hash_sum0("constrained") == 18);
    assert(lookup_ada_pred_hash_sum0("pos") == 39);
    assert(lookup_ada_pred_hash_sum0("natural") == 6);
    assert(lookup_ada_pred_hash_sum0("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash_sum0("epsilon") == 23);
    assert(lookup_ada_pred_hash_sum0("emax") == 22);
    assert(lookup_ada_pred_hash_sum0("pred") == 41);
    assert(lookup_ada_pred_hash_sum0("fore") == 26);
    assert(lookup_ada_pred_hash_sum0("succ") == 49);
    assert(lookup_ada_pred_hash_sum0("image") == 27);
    assert(lookup_ada_pred_hash_sum0("machine_radix") == 36);
    assert(lookup_ada_pred_hash_sum0("safe_emax") == 43);
    assert(lookup_ada_pred_hash_sum0("last") == 29);
    assert(lookup_ada_pred_hash_sum0("character") == 1);
    assert(lookup_ada_pred_hash_sum0("delta") == 20);
    assert(lookup_ada_pred_hash_sum0("false") == 3);
    assert(lookup_ada_pred_hash_sum0("large") == 28);
    assert(lookup_ada_pred_hash_sum0("range") == 42);
    assert(lookup_ada_pred_hash_sum0("size") == 46);
    assert(lookup_ada_pred_hash_sum0("mantissa") == 38);
    assert(lookup_ada_pred_hash_sum0("safe_large") == 44);
    assert(lookup_ada_pred_hash_sum0("true") == 13);
    assert(lookup_ada_pred_hash_sum0("float") == 4);
    assert(lookup_ada_pred_hash_sum0("firstbit") == 25);
    assert(lookup_ada_pred_hash_sum0("small") == 47);
    assert(lookup_ada_pred_hash_sum0("storage_size") == 48);
    assert(lookup_ada_pred_hash_sum0("value") == 52);
    assert(lookup_ada_pred_hash_sum0("safe_small") == 45);
    assert(lookup_ada_pred_hash_sum0("width") == 53);
    assert(lookup_ada_pred_hash_sum0("positive") == 8);
    assert(lookup_ada_pred_hash_sum0("position") == 40);
    assert(lookup_ada_pred_hash_sum0("first") == 24);
    assert(lookup_ada_pred_hash_sum0("count") == 19);
    assert(lookup_ada_pred_hash_sum0("length") == 31);
    assert(lookup_ada_pred_hash_sum0("machine_overflows") == 35);
    assert(lookup_ada_pred_hash_sum0("digits") == 21);
    assert(lookup_ada_pred_hash_sum0("tasking_error") == 12);
    assert(lookup_ada_pred_hash_sum0("machine_rounds") == 37);
    assert(lookup_ada_pred_hash_sum0("numeric_error") == 7);
    assert(lookup_ada_pred_hash_sum0("callable") == 17);
    assert(lookup_ada_pred_hash_sum0("terminated") == 50);
    assert(lookup_ada_pred_hash_sum0("constraint_error") == 2);
    assert(lookup_ada_pred_hash_sum0("storage_error") == 10);
    assert(lookup_ada_pred_hash_sum0("aft") == 15);
    assert(lookup_ada_pred_hash_sum0("boolean") == 0);
    assert(lookup_ada_pred_hash_sum0("program_error") == 9);
    assert(lookup_ada_pred_hash_sum0("machine_emin") == 33);
    assert(lookup_ada_pred_hash_sum0("address") == 14);
    assert(lookup_ada_pred_hash_sum0("machine_emax") == 32);
    assert(lookup_ada_pred_hash_sum0("val") == 51);
    assert(lookup_ada_pred_hash_sum0("string") == 11);
    assert(lookup_ada_pred_hash_sum0("base") == 16);
    assert(lookup_ada_pred_hash_sum0("integer") == 5);
    assert(lookup_ada_pred_hash_sum0("lastbit") == 30);
}

//lookup: name=lookup_ada_pred_hash_sumN, dataset=ada-pred, hash=hash_sumN
int lookup_ada_pred_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 83) * 2;
    static std::string_view lookup[166] = {
        "base", // 415 (0x19f)
        "terminated", // 1079 (0x437)
        "",
        "",
        "address", // 749 (0x2ed)
        "",
        "",
        "",
        "tasking_error", // 1415 (0x587)
        "",
        "string", // 669 (0x29d)
        "",
        "numeric_error", // 1417 (0x589)
        "",
        "machine_rounds", // 1501 (0x5dd)
        "",
        "storage_error", // 1419 (0x58b)
        "",
        "pos", // 341 (0x155)
        "",
        "integer", // 757 (0x2f5)
        "machine_overflows", // 1836 (0x72c)
        "program_error", // 1422 (0x58e)
        "",
        "machine_emin", // 1257 (0x4e9)
        "",
        "",
        "",
        "machine_emax", // 1259 (0x4eb)
        "",
        "constraint_error", // 1758 (0x6de)
        "lastbit", // 762 (0x2fa)
        "emax", // 431 (0x1af)
        "pred", // 431 (0x1af)
        "fore", // 432 (0x1b0)
        "",
        "",
        "",
        "natural", // 766 (0x2fe)
        "succ", // 434 (0x1b2)
        "",
        "",
        "",
        "",
        "epsilon", // 769 (0x301)
        "image", // 520 (0x208)
        "",
        "",
        "",
        "",
        "last", // 440 (0x1b8)
        "",
        "",
        "",
        "constrained", // 1189 (0x4a5)
        "",
        "",
        "",
        "delta", // 527 (0x20f)
        "",
        "false", // 528 (0x210)
        "large", // 528 (0x210)
        "",
        "",
        "range", // 530 (0x212)
        "size", // 447 (0x1bf)
        "safe_emax", // 946 (0x3b2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "character", // 950 (0x3b6)
        "true", // 452 (0x1c4)
        "",
        "",
        "",
        "",
        "machine_mantissa", // 1700 (0x6a4)
        "",
        "float", // 539 (0x21b)
        "machine_radix", // 1369 (0x559)
        "mantissa", // 872 (0x368)
        "",
        "",
        "",
        "small", // 542 (0x21e)
        "",
        "",
        "",
        "",
        "",
        "safe_large", // 1043 (0x413)
        "",
        "value", // 546 (0x222)
        "",
        "firstbit", // 879 (0x36f)
        "",
        "",
        "",
        "width", // 549 (0x225)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "first", // 557 (0x22d)
        "",
        "count", // 558 (0x22e)
        "",
        "positive", // 891 (0x37b)
        "safe_small", // 1057 (0x421)
        "storage_size", // 1307 (0x51b)
        "",
        "position", // 893 (0x37d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "length", // 648 (0x288)
        "",
        "",
        "",
        "aft", // 318 (0x13e)
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
        "callable", // 824 (0x338)
        "val", // 326 (0x146)
        "",
        "",
        "boolean", // 743 (0x2e7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[166] = {
        16, // 415 (0x19f)
        50, // 1079 (0x437)
        -1,
        -1,
        14, // 749 (0x2ed)
        -1,
        -1,
        -1,
        12, // 1415 (0x587)
        -1,
        11, // 669 (0x29d)
        -1,
        7, // 1417 (0x589)
        -1,
        37, // 1501 (0x5dd)
        -1,
        10, // 1419 (0x58b)
        -1,
        39, // 341 (0x155)
        -1,
        5, // 757 (0x2f5)
        35, // 1836 (0x72c)
        9, // 1422 (0x58e)
        -1,
        33, // 1257 (0x4e9)
        -1,
        -1,
        -1,
        32, // 1259 (0x4eb)
        -1,
        2, // 1758 (0x6de)
        30, // 762 (0x2fa)
        22, // 431 (0x1af)
        41, // 431 (0x1af)
        26, // 432 (0x1b0)
        -1,
        -1,
        -1,
        6, // 766 (0x2fe)
        49, // 434 (0x1b2)
        -1,
        -1,
        -1,
        -1,
        23, // 769 (0x301)
        27, // 520 (0x208)
        -1,
        -1,
        -1,
        -1,
        29, // 440 (0x1b8)
        -1,
        -1,
        -1,
        18, // 1189 (0x4a5)
        -1,
        -1,
        -1,
        20, // 527 (0x20f)
        -1,
        3, // 528 (0x210)
        28, // 528 (0x210)
        -1,
        -1,
        42, // 530 (0x212)
        46, // 447 (0x1bf)
        43, // 946 (0x3b2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 950 (0x3b6)
        13, // 452 (0x1c4)
        -1,
        -1,
        -1,
        -1,
        34, // 1700 (0x6a4)
        -1,
        4, // 539 (0x21b)
        36, // 1369 (0x559)
        38, // 872 (0x368)
        -1,
        -1,
        -1,
        47, // 542 (0x21e)
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 1043 (0x413)
        -1,
        52, // 546 (0x222)
        -1,
        25, // 879 (0x36f)
        -1,
        -1,
        -1,
        53, // 549 (0x225)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 557 (0x22d)
        -1,
        19, // 558 (0x22e)
        -1,
        8, // 891 (0x37b)
        45, // 1057 (0x421)
        48, // 1307 (0x51b)
        -1,
        40, // 893 (0x37d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 648 (0x288)
        -1,
        -1,
        -1,
        15, // 318 (0x13e)
        21, // 650 (0x28a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 824 (0x338)
        51, // 326 (0x146)
        -1,
        -1,
        0, // 743 (0x2e7)
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

//check: name=check_ada_pred_hash_sumN, dataset=ada-pred, hash=hash_sumN
void check_ada_pred_hash_sumN() {
    assert(lookup_ada_pred_hash_sumN("base") == 16);
    assert(lookup_ada_pred_hash_sumN("terminated") == 50);
    assert(lookup_ada_pred_hash_sumN("address") == 14);
    assert(lookup_ada_pred_hash_sumN("tasking_error") == 12);
    assert(lookup_ada_pred_hash_sumN("string") == 11);
    assert(lookup_ada_pred_hash_sumN("numeric_error") == 7);
    assert(lookup_ada_pred_hash_sumN("machine_rounds") == 37);
    assert(lookup_ada_pred_hash_sumN("storage_error") == 10);
    assert(lookup_ada_pred_hash_sumN("pos") == 39);
    assert(lookup_ada_pred_hash_sumN("integer") == 5);
    assert(lookup_ada_pred_hash_sumN("machine_overflows") == 35);
    assert(lookup_ada_pred_hash_sumN("program_error") == 9);
    assert(lookup_ada_pred_hash_sumN("machine_emin") == 33);
    assert(lookup_ada_pred_hash_sumN("machine_emax") == 32);
    assert(lookup_ada_pred_hash_sumN("constraint_error") == 2);
    assert(lookup_ada_pred_hash_sumN("lastbit") == 30);
    assert(lookup_ada_pred_hash_sumN("emax") == 22);
    assert(lookup_ada_pred_hash_sumN("pred") == 41);
    assert(lookup_ada_pred_hash_sumN("fore") == 26);
    assert(lookup_ada_pred_hash_sumN("natural") == 6);
    assert(lookup_ada_pred_hash_sumN("succ") == 49);
    assert(lookup_ada_pred_hash_sumN("epsilon") == 23);
    assert(lookup_ada_pred_hash_sumN("image") == 27);
    assert(lookup_ada_pred_hash_sumN("last") == 29);
    assert(lookup_ada_pred_hash_sumN("constrained") == 18);
    assert(lookup_ada_pred_hash_sumN("delta") == 20);
    assert(lookup_ada_pred_hash_sumN("false") == 3);
    assert(lookup_ada_pred_hash_sumN("large") == 28);
    assert(lookup_ada_pred_hash_sumN("range") == 42);
    assert(lookup_ada_pred_hash_sumN("size") == 46);
    assert(lookup_ada_pred_hash_sumN("safe_emax") == 43);
    assert(lookup_ada_pred_hash_sumN("character") == 1);
    assert(lookup_ada_pred_hash_sumN("true") == 13);
    assert(lookup_ada_pred_hash_sumN("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash_sumN("float") == 4);
    assert(lookup_ada_pred_hash_sumN("machine_radix") == 36);
    assert(lookup_ada_pred_hash_sumN("mantissa") == 38);
    assert(lookup_ada_pred_hash_sumN("small") == 47);
    assert(lookup_ada_pred_hash_sumN("safe_large") == 44);
    assert(lookup_ada_pred_hash_sumN("value") == 52);
    assert(lookup_ada_pred_hash_sumN("firstbit") == 25);
    assert(lookup_ada_pred_hash_sumN("width") == 53);
    assert(lookup_ada_pred_hash_sumN("first") == 24);
    assert(lookup_ada_pred_hash_sumN("count") == 19);
    assert(lookup_ada_pred_hash_sumN("positive") == 8);
    assert(lookup_ada_pred_hash_sumN("safe_small") == 45);
    assert(lookup_ada_pred_hash_sumN("storage_size") == 48);
    assert(lookup_ada_pred_hash_sumN("position") == 40);
    assert(lookup_ada_pred_hash_sumN("length") == 31);
    assert(lookup_ada_pred_hash_sumN("aft") == 15);
    assert(lookup_ada_pred_hash_sumN("digits") == 21);
    assert(lookup_ada_pred_hash_sumN("callable") == 17);
    assert(lookup_ada_pred_hash_sumN("val") == 51);
    assert(lookup_ada_pred_hash_sumN("boolean") == 0);
}

//lookup: name=lookup_ada_pred_hash_djb2, dataset=ada-pred, hash=hash_djb2
int lookup_ada_pred_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 329) * 1;
    static std::string_view lookup[329] = {
        "",
        "",
        "",
        "count", // 214622615378 (0x31f8813752)
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
        "",
        "first", // 214625954417 (0x31f8b42a71)
        "",
        "",
        "",
        "delta", // 214623432307 (0x31f88dae73)
        "",
        "",
        "",
        "",
        "small", // 214641496386 (0x31f9a15142)
        "program_error", // 6400591984886456458 (0x58d3787f9b5ea08a)
        "position", // 7713446884515614 (0x1b6756cd8b9f1e)
        "",
        "",
        "",
        "",
        "",
        "",
        "firstbit", // 7713012923994032 (0x1b66f1c37b8fb0)
        "last", // 6504023741 (0x183ab86bd)
        "machine_radix", // 519362979000615637 (0x73525e0b0d202d5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "epsilon", // 233726647661507 (0xd492b9cef3c3)
        "",
        "address", // 233720994692047 (0xd49168dd7bcf)
        "",
        "range", // 214639893206 (0x31f988dad6)
        "mantissa", // 7713300765618985 (0x1b6734c82e3329)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "succ", // 6504296535 (0x183afb057)
        "",
        "",
        "",
        "",
        "machine_emin", // 16226513367168564614 (0xe13027ef8935bd86)
        "safe_large", // 8400062641945642802 (0x74930477a8330732)
        "",
        "",
        "false", // 214625660372 (0x31f8afadd4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "pos", // 197096443 (0xbbf73fb)
        "image", // 214629637004 (0x31f8ec5b8c)
        "",
        "",
        "",
        "",
        "constrained", // 477062450862805987 (0x69eddc57f5ad3e3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "width", // 214646099849 (0x31f9e78f89)
        "",
        "",
        "safe_emax", // 254547352785992562 (0x3885577fd533b72)
        "",
        "true", // 6504329801 (0x183b03249)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "emax", // 6503784660 (0x183a7e0d4)
        "",
        "",
        "",
        "",
        "",
        "integer", // 233731736298999 (0xd493e91d65f7)
        "",
        "",
        "storage_error", // 11505831605533690471 (0x9facece27d4c4a67)
        "",
        "",
        "",
        "",
        "",
        "",
        "value", // 214644635174 (0x31f9d13626)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "lastbit", // 233735101290620 (0xd494b1af187c)
        "",
        "",
        "",
        "terminated", // 8400115201211305078 (0x74933445108f0c76)
        "",
        "machine_emax", // 16226513367168564360 (0xe13027ef8935bc88)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "boolean", // 233722729478249 (0xd491d0443869)
        "",
        "",
        "",
        "",
        "",
        "",
        "natural", // 233737685465568 (0xd4954bb679e0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_rounds", // 17138978307037534744 (0xedd9e1f6cc191a18)
        "length", // 7082886407723 (0x6711ceda62b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "safe_small", // 8400062641954357152 (0x74930477a8b7ffa0)
        "digits", // 7082577818893 (0x6710a88f50d)
        "",
        "",
        "",
        "",
        "large", // 214632782036 (0x31f91c58d4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "callable", // 7712874493124825 (0x1b66d1885c20d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "base", // 6503664356 (0x183a60ae4)
        "val", // 197102508 (0xbbf8bac)
        "positive", // 7713446884515836 (0x1b6756cd8b9ffc)
        "",
        "tasking_error", // 12219234084457092739 (0xa99370a8d7691683)
        "",
        "aft", // 197079812 (0xbbf3304)
        "",
        "",
        "",
        "",
        "",
        "",
        "storage_size", // 16559436658882635608 (0xe5ceefe7d547e758)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_overflows", // 5125538978265733892 (0x4721928b61f29b04)
        "",
        "",
        "",
        "",
        "",
        "",
        "pred", // 6504185524 (0x183adfeb4)
        "",
        "",
        "",
        "size", // 6504284228 (0x183af8044)
        "",
        "string", // 7083178290016 (0x6712e536b60)
        "",
        "",
        "",
        "",
        "",
        "",
        "numeric_error", // 3213283621615198309 (0x2c97e06ddcf46065)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "fore", // 6503823317 (0x183a877d5)
        "",
        "machine_mantissa", // 14689117612079237341 (0xcbda3aa453eac8dd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "constraint_error", // 3036081388655583159 (0x2a2253efe7fd9fb7)
        "",
        "",
        "character", // 254525142630929526 (0x3884144c8ec1476)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[329] = {
        -1,
        -1,
        -1,
        19, // 214622615378 (0x31f8813752)
        -1,
        -1,
        -1,
        4, // 214626058367 (0x31f8b5c07f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 214625954417 (0x31f8b42a71)
        -1,
        -1,
        -1,
        20, // 214623432307 (0x31f88dae73)
        -1,
        -1,
        -1,
        -1,
        47, // 214641496386 (0x31f9a15142)
        9, // 6400591984886456458 (0x58d3787f9b5ea08a)
        40, // 7713446884515614 (0x1b6756cd8b9f1e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 7713012923994032 (0x1b66f1c37b8fb0)
        29, // 6504023741 (0x183ab86bd)
        36, // 519362979000615637 (0x73525e0b0d202d5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 233726647661507 (0xd492b9cef3c3)
        -1,
        14, // 233720994692047 (0xd49168dd7bcf)
        -1,
        42, // 214639893206 (0x31f988dad6)
        38, // 7713300765618985 (0x1b6734c82e3329)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 6504296535 (0x183afb057)
        -1,
        -1,
        -1,
        -1,
        33, // 16226513367168564614 (0xe13027ef8935bd86)
        44, // 8400062641945642802 (0x74930477a8330732)
        -1,
        -1,
        3, // 214625660372 (0x31f8afadd4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 197096443 (0xbbf73fb)
        27, // 214629637004 (0x31f8ec5b8c)
        -1,
        -1,
        -1,
        -1,
        18, // 477062450862805987 (0x69eddc57f5ad3e3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 214646099849 (0x31f9e78f89)
        -1,
        -1,
        43, // 254547352785992562 (0x3885577fd533b72)
        -1,
        13, // 6504329801 (0x183b03249)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 6503784660 (0x183a7e0d4)
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 233731736298999 (0xd493e91d65f7)
        -1,
        -1,
        10, // 11505831605533690471 (0x9facece27d4c4a67)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 214644635174 (0x31f9d13626)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 233735101290620 (0xd494b1af187c)
        -1,
        -1,
        -1,
        50, // 8400115201211305078 (0x74933445108f0c76)
        -1,
        32, // 16226513367168564360 (0xe13027ef8935bc88)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 233722729478249 (0xd491d0443869)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 233737685465568 (0xd4954bb679e0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 17138978307037534744 (0xedd9e1f6cc191a18)
        31, // 7082886407723 (0x6711ceda62b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 8400062641954357152 (0x74930477a8b7ffa0)
        21, // 7082577818893 (0x6710a88f50d)
        -1,
        -1,
        -1,
        -1,
        28, // 214632782036 (0x31f91c58d4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 7712874493124825 (0x1b66d1885c20d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 6503664356 (0x183a60ae4)
        51, // 197102508 (0xbbf8bac)
        8, // 7713446884515836 (0x1b6756cd8b9ffc)
        -1,
        12, // 12219234084457092739 (0xa99370a8d7691683)
        -1,
        15, // 197079812 (0xbbf3304)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 16559436658882635608 (0xe5ceefe7d547e758)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 5125538978265733892 (0x4721928b61f29b04)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 6504185524 (0x183adfeb4)
        -1,
        -1,
        -1,
        46, // 6504284228 (0x183af8044)
        -1,
        11, // 7083178290016 (0x6712e536b60)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 3213283621615198309 (0x2c97e06ddcf46065)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 6503823317 (0x183a877d5)
        -1,
        34, // 14689117612079237341 (0xcbda3aa453eac8dd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 3036081388655583159 (0x2a2253efe7fd9fb7)
        -1,
        -1,
        1, // 254525142630929526 (0x3884144c8ec1476)
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

//check: name=check_ada_pred_hash_djb2, dataset=ada-pred, hash=hash_djb2
void check_ada_pred_hash_djb2() {
    assert(lookup_ada_pred_hash_djb2("count") == 19);
    assert(lookup_ada_pred_hash_djb2("float") == 4);
    assert(lookup_ada_pred_hash_djb2("first") == 24);
    assert(lookup_ada_pred_hash_djb2("delta") == 20);
    assert(lookup_ada_pred_hash_djb2("small") == 47);
    assert(lookup_ada_pred_hash_djb2("program_error") == 9);
    assert(lookup_ada_pred_hash_djb2("position") == 40);
    assert(lookup_ada_pred_hash_djb2("firstbit") == 25);
    assert(lookup_ada_pred_hash_djb2("last") == 29);
    assert(lookup_ada_pred_hash_djb2("machine_radix") == 36);
    assert(lookup_ada_pred_hash_djb2("epsilon") == 23);
    assert(lookup_ada_pred_hash_djb2("address") == 14);
    assert(lookup_ada_pred_hash_djb2("range") == 42);
    assert(lookup_ada_pred_hash_djb2("mantissa") == 38);
    assert(lookup_ada_pred_hash_djb2("succ") == 49);
    assert(lookup_ada_pred_hash_djb2("machine_emin") == 33);
    assert(lookup_ada_pred_hash_djb2("safe_large") == 44);
    assert(lookup_ada_pred_hash_djb2("false") == 3);
    assert(lookup_ada_pred_hash_djb2("pos") == 39);
    assert(lookup_ada_pred_hash_djb2("image") == 27);
    assert(lookup_ada_pred_hash_djb2("constrained") == 18);
    assert(lookup_ada_pred_hash_djb2("width") == 53);
    assert(lookup_ada_pred_hash_djb2("safe_emax") == 43);
    assert(lookup_ada_pred_hash_djb2("true") == 13);
    assert(lookup_ada_pred_hash_djb2("emax") == 22);
    assert(lookup_ada_pred_hash_djb2("integer") == 5);
    assert(lookup_ada_pred_hash_djb2("storage_error") == 10);
    assert(lookup_ada_pred_hash_djb2("value") == 52);
    assert(lookup_ada_pred_hash_djb2("lastbit") == 30);
    assert(lookup_ada_pred_hash_djb2("terminated") == 50);
    assert(lookup_ada_pred_hash_djb2("machine_emax") == 32);
    assert(lookup_ada_pred_hash_djb2("boolean") == 0);
    assert(lookup_ada_pred_hash_djb2("natural") == 6);
    assert(lookup_ada_pred_hash_djb2("machine_rounds") == 37);
    assert(lookup_ada_pred_hash_djb2("length") == 31);
    assert(lookup_ada_pred_hash_djb2("safe_small") == 45);
    assert(lookup_ada_pred_hash_djb2("digits") == 21);
    assert(lookup_ada_pred_hash_djb2("large") == 28);
    assert(lookup_ada_pred_hash_djb2("callable") == 17);
    assert(lookup_ada_pred_hash_djb2("base") == 16);
    assert(lookup_ada_pred_hash_djb2("val") == 51);
    assert(lookup_ada_pred_hash_djb2("positive") == 8);
    assert(lookup_ada_pred_hash_djb2("tasking_error") == 12);
    assert(lookup_ada_pred_hash_djb2("aft") == 15);
    assert(lookup_ada_pred_hash_djb2("storage_size") == 48);
    assert(lookup_ada_pred_hash_djb2("machine_overflows") == 35);
    assert(lookup_ada_pred_hash_djb2("pred") == 41);
    assert(lookup_ada_pred_hash_djb2("size") == 46);
    assert(lookup_ada_pred_hash_djb2("string") == 11);
    assert(lookup_ada_pred_hash_djb2("numeric_error") == 7);
    assert(lookup_ada_pred_hash_djb2("fore") == 26);
    assert(lookup_ada_pred_hash_djb2("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash_djb2("constraint_error") == 2);
    assert(lookup_ada_pred_hash_djb2("character") == 1);
}

//lookup: name=lookup_ada_pred_hash_sdb, dataset=ada-pred, hash=hash_sdb
int lookup_ada_pred_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 371) * 1;
    static std::string_view lookup[371] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "true", // 32656071128322562 (0x7404860f5d1202)
        "machine_radix", // 13508794376645403484 (0xbb78e0e9b3be635c)
        "",
        "",
        "",
        "numeric_error", // 1142939715639992146 (0xfdc899da6685f52)
        "",
        "",
        "",
        "",
        "natural", // 1155610267083000813 (0x10098d6a4c46cbed)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "integer", // 720438270612195334 (0x9ff82ca426fc806)
        "position", // 17315596584987105521 (0xf04d5b5a221f98f1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "pos", // 481087653296 (0x70030f05b0)
        "",
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
        "firstbit", // 8431996963205952601 (0x750478903b103459)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "character", // 574292453540303105 (0x7f84bf19a751101)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "address", // 17647442383516640296 (0xf4e84f58ffaea428)
        "",
        "",
        "",
        "constraint_error", // 10941706443240163014 (0x97d8c009d9eec6c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_overflows", // 1459647589315833205 (0x1441b5bfba6ced75)
        "",
        "",
        "",
        "mantissa", // 12700953376086054238 (0xb042d9cd9268555e)
        "",
        "",
        "",
        "",
        "",
        "pred", // 31530016594530661 (0x7004620ee11165)
        "",
        "storage_size", // 14700899927095250945 (0xcc04169851141001)
        "",
        "",
        "",
        "",
        "",
        "string", // 3337332448022864709 (0x2e50962df5c9a345)
        "",
        "",
        "",
        "",
        "",
        "",
        "fore", // 28714867377442916 (0x6604050dce1064)
        "",
        "",
        "",
        "safe_emax", // 1358897211261743225 (0x12dbc5d05b867079)
        "",
        "",
        "",
        "",
        "storage_error", // 8792594590925466832 (0x7a059231fe222cd0)
        "",
        "succ", // 32374570380038602 (0x7304800f4211ca)
        "",
        "",
        "",
        "tasking_error", // 2790505366269099030 (0x26b9ddd88c4a7c16)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_rounds", // 1444910069590536369 (0x140d5a0d865430b1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "range", // 412391503681172421 (0x5b91be33d4e33c5)
        "size", // 32374518837219749 (0x7304740f1111a5)
        "",
        "false", // 371856315221159947 (0x5291959383e300b)
        "lastbit", // 847947341259588959 (0xbc4839d4003c55f)
        "",
        "",
        "",
        "safe_small", // 18377976130564544033 (0xff0bafeb88e85621)
        "",
        "",
        "",
        "",
        "float", // 374952978071105832 (0x53419bf39673128)
        "base", // 27588752709717885 (0x6203d30d0f0f7d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_emax", // 13110709763847583071 (0xb5f299111361755f)
        "",
        "",
        "last", // 30403889041576090 (0x6c042d0e1d109a)
        "",
        "",
        "",
        "callable", // 4640975160336382464 (0x40680e51c342fa00)
        "",
        "length", // 3108200057060497270 (0x2b228b7be3f09776)
        "",
        "image", // 385368226537157051 (0x5591a5c3a7831bb)
        "delta", // 366226506442289108 (0x515191137d32fd4)
        "",
        "positive", // 17315596584987564285 (0xf04d5b5a222698fd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "constrained", // 2226830678447835430 (0x1ee74ab42bd34926)
        "",
        "",
        "",
        "emax", // 28433345152421911 (0x6503fa0d961017)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "small", // 419147543095883003 (0x5d11c783eb534fb)
        "",
        "boolean", // 18113585239123538960 (0xfb6061ce1ab7b410)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "width", // 431533228073104898 (0x5fd1d2f40133602)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "terminated", // 6621207051929619975 (0x5be340bbaa938e07)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "aft", // 416656655631 (0x6102ac050f)
        "safe_large", // 18350952518396236585 (0xfeabae1685115329)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "machine_mantissa", // 3611986464301350 (0xcd51522236126)
        "",
        "machine_emin", // 13110709763848107373 (0xb5f299111369756d)
        "",
        "epsilon", // 160847406491614954 (0x23b71dd2ef9beea)
        "",
        "count", // 365663749776158947 (0x513193e38a530e3)
        "",
        "",
        "",
        "",
        "",
        "program_error", // 4989394982411156093 (0x453de44d32bbba7d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "val", // 506858898869 (0x76032505b5)
        "",
        "",
        "",
        "",
        "value", // 425903221714728225 (0x5e91cb93f003521)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "large", // 392123930927575555 (0x5711aa33ade3203)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "first", // 374108450058809640 (0x53119a7393a3128)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[371] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 32656071128322562 (0x7404860f5d1202)
        36, // 13508794376645403484 (0xbb78e0e9b3be635c)
        -1,
        -1,
        -1,
        7, // 1142939715639992146 (0xfdc899da6685f52)
        -1,
        -1,
        -1,
        -1,
        6, // 1155610267083000813 (0x10098d6a4c46cbed)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 720438270612195334 (0x9ff82ca426fc806)
        40, // 17315596584987105521 (0xf04d5b5a221f98f1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 481087653296 (0x70030f05b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 2917069936268906626 (0x287b83a6d8479082)
        -1,
        -1,
        -1,
        -1,
        25, // 8431996963205952601 (0x750478903b103459)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 574292453540303105 (0x7f84bf19a751101)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 17647442383516640296 (0xf4e84f58ffaea428)
        -1,
        -1,
        -1,
        2, // 10941706443240163014 (0x97d8c009d9eec6c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 1459647589315833205 (0x1441b5bfba6ced75)
        -1,
        -1,
        -1,
        38, // 12700953376086054238 (0xb042d9cd9268555e)
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 31530016594530661 (0x7004620ee11165)
        -1,
        48, // 14700899927095250945 (0xcc04169851141001)
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 3337332448022864709 (0x2e50962df5c9a345)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 28714867377442916 (0x6604050dce1064)
        -1,
        -1,
        -1,
        43, // 1358897211261743225 (0x12dbc5d05b867079)
        -1,
        -1,
        -1,
        -1,
        10, // 8792594590925466832 (0x7a059231fe222cd0)
        -1,
        49, // 32374570380038602 (0x7304800f4211ca)
        -1,
        -1,
        -1,
        12, // 2790505366269099030 (0x26b9ddd88c4a7c16)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 1444910069590536369 (0x140d5a0d865430b1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 412391503681172421 (0x5b91be33d4e33c5)
        46, // 32374518837219749 (0x7304740f1111a5)
        -1,
        3, // 371856315221159947 (0x5291959383e300b)
        30, // 847947341259588959 (0xbc4839d4003c55f)
        -1,
        -1,
        -1,
        45, // 18377976130564544033 (0xff0bafeb88e85621)
        -1,
        -1,
        -1,
        -1,
        4, // 374952978071105832 (0x53419bf39673128)
        16, // 27588752709717885 (0x6203d30d0f0f7d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 13110709763847583071 (0xb5f299111361755f)
        -1,
        -1,
        29, // 30403889041576090 (0x6c042d0e1d109a)
        -1,
        -1,
        -1,
        17, // 4640975160336382464 (0x40680e51c342fa00)
        -1,
        31, // 3108200057060497270 (0x2b228b7be3f09776)
        -1,
        27, // 385368226537157051 (0x5591a5c3a7831bb)
        20, // 366226506442289108 (0x515191137d32fd4)
        -1,
        8, // 17315596584987564285 (0xf04d5b5a222698fd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 2226830678447835430 (0x1ee74ab42bd34926)
        -1,
        -1,
        -1,
        22, // 28433345152421911 (0x6503fa0d961017)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 419147543095883003 (0x5d11c783eb534fb)
        -1,
        0, // 18113585239123538960 (0xfb6061ce1ab7b410)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 431533228073104898 (0x5fd1d2f40133602)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 6621207051929619975 (0x5be340bbaa938e07)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 416656655631 (0x6102ac050f)
        44, // 18350952518396236585 (0xfeabae1685115329)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 3611986464301350 (0xcd51522236126)
        -1,
        33, // 13110709763848107373 (0xb5f299111369756d)
        -1,
        23, // 160847406491614954 (0x23b71dd2ef9beea)
        -1,
        19, // 365663749776158947 (0x513193e38a530e3)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 4989394982411156093 (0x453de44d32bbba7d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 506858898869 (0x76032505b5)
        -1,
        -1,
        -1,
        -1,
        52, // 425903221714728225 (0x5e91cb93f003521)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 392123930927575555 (0x5711aa33ade3203)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 374108450058809640 (0x53119a7393a3128)
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

//check: name=check_ada_pred_hash_sdb, dataset=ada-pred, hash=hash_sdb
void check_ada_pred_hash_sdb() {
    assert(lookup_ada_pred_hash_sdb("true") == 13);
    assert(lookup_ada_pred_hash_sdb("machine_radix") == 36);
    assert(lookup_ada_pred_hash_sdb("numeric_error") == 7);
    assert(lookup_ada_pred_hash_sdb("natural") == 6);
    assert(lookup_ada_pred_hash_sdb("integer") == 5);
    assert(lookup_ada_pred_hash_sdb("position") == 40);
    assert(lookup_ada_pred_hash_sdb("pos") == 39);
    assert(lookup_ada_pred_hash_sdb("digits") == 21);
    assert(lookup_ada_pred_hash_sdb("firstbit") == 25);
    assert(lookup_ada_pred_hash_sdb("character") == 1);
    assert(lookup_ada_pred_hash_sdb("address") == 14);
    assert(lookup_ada_pred_hash_sdb("constraint_error") == 2);
    assert(lookup_ada_pred_hash_sdb("machine_overflows") == 35);
    assert(lookup_ada_pred_hash_sdb("mantissa") == 38);
    assert(lookup_ada_pred_hash_sdb("pred") == 41);
    assert(lookup_ada_pred_hash_sdb("storage_size") == 48);
    assert(lookup_ada_pred_hash_sdb("string") == 11);
    assert(lookup_ada_pred_hash_sdb("fore") == 26);
    assert(lookup_ada_pred_hash_sdb("safe_emax") == 43);
    assert(lookup_ada_pred_hash_sdb("storage_error") == 10);
    assert(lookup_ada_pred_hash_sdb("succ") == 49);
    assert(lookup_ada_pred_hash_sdb("tasking_error") == 12);
    assert(lookup_ada_pred_hash_sdb("machine_rounds") == 37);
    assert(lookup_ada_pred_hash_sdb("range") == 42);
    assert(lookup_ada_pred_hash_sdb("size") == 46);
    assert(lookup_ada_pred_hash_sdb("false") == 3);
    assert(lookup_ada_pred_hash_sdb("lastbit") == 30);
    assert(lookup_ada_pred_hash_sdb("safe_small") == 45);
    assert(lookup_ada_pred_hash_sdb("float") == 4);
    assert(lookup_ada_pred_hash_sdb("base") == 16);
    assert(lookup_ada_pred_hash_sdb("machine_emax") == 32);
    assert(lookup_ada_pred_hash_sdb("last") == 29);
    assert(lookup_ada_pred_hash_sdb("callable") == 17);
    assert(lookup_ada_pred_hash_sdb("length") == 31);
    assert(lookup_ada_pred_hash_sdb("image") == 27);
    assert(lookup_ada_pred_hash_sdb("delta") == 20);
    assert(lookup_ada_pred_hash_sdb("positive") == 8);
    assert(lookup_ada_pred_hash_sdb("constrained") == 18);
    assert(lookup_ada_pred_hash_sdb("emax") == 22);
    assert(lookup_ada_pred_hash_sdb("small") == 47);
    assert(lookup_ada_pred_hash_sdb("boolean") == 0);
    assert(lookup_ada_pred_hash_sdb("width") == 53);
    assert(lookup_ada_pred_hash_sdb("terminated") == 50);
    assert(lookup_ada_pred_hash_sdb("aft") == 15);
    assert(lookup_ada_pred_hash_sdb("safe_large") == 44);
    assert(lookup_ada_pred_hash_sdb("machine_mantissa") == 34);
    assert(lookup_ada_pred_hash_sdb("machine_emin") == 33);
    assert(lookup_ada_pred_hash_sdb("epsilon") == 23);
    assert(lookup_ada_pred_hash_sdb("count") == 19);
    assert(lookup_ada_pred_hash_sdb("program_error") == 9);
    assert(lookup_ada_pred_hash_sdb("val") == 51);
    assert(lookup_ada_pred_hash_sdb("value") == 52);
    assert(lookup_ada_pred_hash_sdb("large") == 28);
    assert(lookup_ada_pred_hash_sdb("first") == 24);
}
