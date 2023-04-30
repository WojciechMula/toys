
//lookup: name=lookup_gpc_hash1, dataset=gpc, type=hash, hash=hash1
int lookup_gpc_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 55) * 2;
    constexpr const std::string_view lookup[110] = {
        "And", // 495 (0x1ef)
        "Begin", // 880 (0x370)
        "Or", // 386 (0x182)
        "",
        "For", // 552 (0x228)
        "",
        "Program", // 1323 (0x52b)
        "",
        "",
        "",
        "To", // 390 (0x186)
        "While", // 940 (0x3ac)
        "Then", // 776 (0x308)
        "",
        "",
        "",
        "Div", // 558 (0x22e)
        "Nil", // 558 (0x22e)
        "",
        "",
        "Function", // 1440 (0x5a0)
        "",
        "",
        "",
        "Case", // 672 (0x2a0)
        "End", // 507 (0x1fb)
        "Goto", // 728 (0x2d8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Else", // 680 (0x2a8)
        "If", // 350 (0x15e)
        "",
        "",
        "",
        "",
        "",
        "",
        "File", // 684 (0x2ac)
        "",
        "Type", // 740 (0x2e4)
        "",
        "",
        "",
        "",
        "",
        "Do", // 358 (0x166)
        "",
        "Downto", // 1074 (0x432)
        "",
        "Until", // 965 (0x3c5)
        "",
        "",
        "",
        "Not", // 582 (0x246)
        "Of", // 362 (0x16a)
        "Repeat", // 1188 (0x4a4)
        "",
        "Procedure", // 1629 (0x65d)
        "",
        "Const", // 915 (0x393)
        "Packed", // 1080 (0x438)
        "In", // 366 (0x16e)
        "Mod", // 531 (0x213)
        "",
        "",
        "",
        "",
        "",
        "",
        "Label", // 920 (0x398)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Record", // 1092 (0x444)
        "Set", // 597 (0x255)
        "",
        "",
        "With", // 764 (0x2fc)
        "",
        "Array", // 930 (0x3a2)
        "Var", // 600 (0x258)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[110] = {
        0, // 495 (0x1ef)
        2, // 880 (0x370)
        21, // 386 (0x182)
        -1,
        11, // 552 (0x228)
        -1,
        24, // 1323 (0x52b)
        -1,
        -1,
        -1,
        29, // 390 (0x186)
        33, // 940 (0x3ac)
        28, // 776 (0x308)
        -1,
        -1,
        -1,
        5, // 558 (0x22e)
        18, // 558 (0x22e)
        -1,
        -1,
        12, // 1440 (0x5a0)
        -1,
        -1,
        -1,
        3, // 672 (0x2a0)
        9, // 507 (0x1fb)
        13, // 728 (0x2d8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 680 (0x2a8)
        14, // 350 (0x15e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 684 (0x2ac)
        -1,
        30, // 740 (0x2e4)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 358 (0x166)
        -1,
        7, // 1074 (0x432)
        -1,
        31, // 965 (0x3c5)
        -1,
        -1,
        -1,
        19, // 582 (0x246)
        20, // 362 (0x16a)
        26, // 1188 (0x4a4)
        -1,
        23, // 1629 (0x65d)
        -1,
        4, // 915 (0x393)
        22, // 1080 (0x438)
        15, // 366 (0x16e)
        17, // 531 (0x213)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 920 (0x398)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 1092 (0x444)
        27, // 597 (0x255)
        -1,
        -1,
        34, // 764 (0x2fc)
        -1,
        1, // 930 (0x3a2)
        32, // 600 (0x258)
        -1,
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

//check: name=check_gpc_hash1, dataset=gpc, type=hash, hash=hash1
void check_gpc_hash1() {
    assert(lookup_gpc_hash1("And") == 0);
    assert(lookup_gpc_hash1("Begin") == 2);
    assert(lookup_gpc_hash1("Or") == 21);
    assert(lookup_gpc_hash1("For") == 11);
    assert(lookup_gpc_hash1("Program") == 24);
    assert(lookup_gpc_hash1("To") == 29);
    assert(lookup_gpc_hash1("While") == 33);
    assert(lookup_gpc_hash1("Then") == 28);
    assert(lookup_gpc_hash1("Div") == 5);
    assert(lookup_gpc_hash1("Nil") == 18);
    assert(lookup_gpc_hash1("Function") == 12);
    assert(lookup_gpc_hash1("Case") == 3);
    assert(lookup_gpc_hash1("End") == 9);
    assert(lookup_gpc_hash1("Goto") == 13);
    assert(lookup_gpc_hash1("Else") == 8);
    assert(lookup_gpc_hash1("If") == 14);
    assert(lookup_gpc_hash1("File") == 10);
    assert(lookup_gpc_hash1("Type") == 30);
    assert(lookup_gpc_hash1("Do") == 6);
    assert(lookup_gpc_hash1("Downto") == 7);
    assert(lookup_gpc_hash1("Until") == 31);
    assert(lookup_gpc_hash1("Not") == 19);
    assert(lookup_gpc_hash1("Of") == 20);
    assert(lookup_gpc_hash1("Repeat") == 26);
    assert(lookup_gpc_hash1("Procedure") == 23);
    assert(lookup_gpc_hash1("Const") == 4);
    assert(lookup_gpc_hash1("Packed") == 22);
    assert(lookup_gpc_hash1("In") == 15);
    assert(lookup_gpc_hash1("Mod") == 17);
    assert(lookup_gpc_hash1("Label") == 16);
    assert(lookup_gpc_hash1("Record") == 25);
    assert(lookup_gpc_hash1("Set") == 27);
    assert(lookup_gpc_hash1("With") == 34);
    assert(lookup_gpc_hash1("Array") == 1);
    assert(lookup_gpc_hash1("Var") == 32);
}

//lookup: name=lookup_gpc_hash2, dataset=gpc, type=hash, hash=hash2
int lookup_gpc_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 197) * 1;
    constexpr const std::string_view lookup[197] = {
        "",
        "",
        "And", // 6503 (0x1967)
        "",
        "",
        "Goto", // 7885 (0x1ecd)
        "",
        "",
        "End", // 6903 (0x1af7)
        "Type", // 8480 (0x2120)
        "",
        "",
        "Procedure", // 8089 (0x1f99)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Mod", // 7703 (0x1e17)
        "",
        "",
        "",
        "",
        "Function", // 7708 (0x1e1c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Program", // 8727 (0x2217)
        "Downto", // 7546 (0x1d7a)
        "",
        "Repeat", // 9518 (0x252e)
        "",
        "Do", // 7550 (0x1d7e)
        "Case", // 6763 (0x1a6b)
        "",
        "To", // 9326 (0x246e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Else", // 6973 (0x1b3d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Const", // 7769 (0x1e59)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "For", // 7983 (0x1f2f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Until", // 9177 (0x23d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "While", // 8790 (0x2256)
        "",
        "",
        "",
        "Packed", // 8006 (0x1f46)
        "",
        "",
        "Record", // 8206 (0x200e)
        "",
        "",
        "",
        "",
        "",
        "",
        "Label", // 8213 (0x2015)
        "",
        "",
        "Or", // 9004 (0x232c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Div", // 8027 (0x1f5b)
        "In", // 8028 (0x1f5c)
        "",
        "",
        "",
        "",
        "Nil", // 8427 (0x20eb)
        "Var", // 9807 (0x264f)
        "If", // 7444 (0x1d14)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Begin", // 7257 (0x1c59)
        "",
        "",
        "",
        "",
        "",
        "File", // 7066 (0x1b9a)
        "",
        "",
        "",
        "Set", // 9631 (0x259f)
        "Of", // 8056 (0x1f78)
        "",
        "",
        "",
        "",
        "",
        "Then", // 9244 (0x241c)
        "",
        "",
        "Array", // 7868 (0x1ebc)
        "Not", // 9051 (0x235b)
        "With", // 9052 (0x235c)
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
    constexpr const int values[197] = {
        -1,
        -1,
        0, // 6503 (0x1967)
        -1,
        -1,
        13, // 7885 (0x1ecd)
        -1,
        -1,
        9, // 6903 (0x1af7)
        30, // 8480 (0x2120)
        -1,
        -1,
        23, // 8089 (0x1f99)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 7703 (0x1e17)
        -1,
        -1,
        -1,
        -1,
        12, // 7708 (0x1e1c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 8727 (0x2217)
        7, // 7546 (0x1d7a)
        -1,
        26, // 9518 (0x252e)
        -1,
        6, // 7550 (0x1d7e)
        3, // 6763 (0x1a6b)
        -1,
        29, // 9326 (0x246e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 6973 (0x1b3d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 7769 (0x1e59)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 7983 (0x1f2f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 9177 (0x23d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 8790 (0x2256)
        -1,
        -1,
        -1,
        22, // 8006 (0x1f46)
        -1,
        -1,
        25, // 8206 (0x200e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 8213 (0x2015)
        -1,
        -1,
        21, // 9004 (0x232c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 8027 (0x1f5b)
        15, // 8028 (0x1f5c)
        -1,
        -1,
        -1,
        -1,
        18, // 8427 (0x20eb)
        32, // 9807 (0x264f)
        14, // 7444 (0x1d14)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 7257 (0x1c59)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 7066 (0x1b9a)
        -1,
        -1,
        -1,
        27, // 9631 (0x259f)
        20, // 8056 (0x1f78)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 9244 (0x241c)
        -1,
        -1,
        1, // 7868 (0x1ebc)
        19, // 9051 (0x235b)
        34, // 9052 (0x235c)
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

//check: name=check_gpc_hash2, dataset=gpc, type=hash, hash=hash2
void check_gpc_hash2() {
    assert(lookup_gpc_hash2("And") == 0);
    assert(lookup_gpc_hash2("Goto") == 13);
    assert(lookup_gpc_hash2("End") == 9);
    assert(lookup_gpc_hash2("Type") == 30);
    assert(lookup_gpc_hash2("Procedure") == 23);
    assert(lookup_gpc_hash2("Mod") == 17);
    assert(lookup_gpc_hash2("Function") == 12);
    assert(lookup_gpc_hash2("Program") == 24);
    assert(lookup_gpc_hash2("Downto") == 7);
    assert(lookup_gpc_hash2("Repeat") == 26);
    assert(lookup_gpc_hash2("Do") == 6);
    assert(lookup_gpc_hash2("Case") == 3);
    assert(lookup_gpc_hash2("To") == 29);
    assert(lookup_gpc_hash2("Else") == 8);
    assert(lookup_gpc_hash2("Const") == 4);
    assert(lookup_gpc_hash2("For") == 11);
    assert(lookup_gpc_hash2("Until") == 31);
    assert(lookup_gpc_hash2("While") == 33);
    assert(lookup_gpc_hash2("Packed") == 22);
    assert(lookup_gpc_hash2("Record") == 25);
    assert(lookup_gpc_hash2("Label") == 16);
    assert(lookup_gpc_hash2("Or") == 21);
    assert(lookup_gpc_hash2("Div") == 5);
    assert(lookup_gpc_hash2("In") == 15);
    assert(lookup_gpc_hash2("Nil") == 18);
    assert(lookup_gpc_hash2("Var") == 32);
    assert(lookup_gpc_hash2("If") == 14);
    assert(lookup_gpc_hash2("Begin") == 2);
    assert(lookup_gpc_hash2("File") == 10);
    assert(lookup_gpc_hash2("Set") == 27);
    assert(lookup_gpc_hash2("Of") == 20);
    assert(lookup_gpc_hash2("Then") == 28);
    assert(lookup_gpc_hash2("Array") == 1);
    assert(lookup_gpc_hash2("Not") == 19);
    assert(lookup_gpc_hash2("With") == 34);
}

//lookup: name=lookup_gpc_hash3, dataset=gpc, type=hash, hash=hash3
int lookup_gpc_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 187) * 1;
    constexpr const std::string_view lookup[187] = {
        "",
        "",
        "",
        "",
        "Type", // 22818 (0x5922)
        "",
        "In", // 19454 (0x4bfe)
        "Downto", // 19268 (0x4b44)
        "",
        "",
        "",
        "With", // 23573 (0x5c15)
        "",
        "",
        "",
        "",
        "",
        "Record", // 22831 (0x592f)
        "",
        "To", // 22272 (0x5700)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Of", // 20974 (0x51ee)
        "Set", // 22284 (0x570c)
        "",
        "Repeat", // 22847 (0x593f)
        "",
        "",
        "",
        "Do", // 18176 (0x4700)
        "",
        "",
        "",
        "",
        "Goto", // 19490 (0x4c22)
        "",
        "Const", // 18744 (0x4938)
        "Var", // 23046 (0x5a06)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Or", // 20998 (0x5206)
        "",
        "Nil", // 21000 (0x5208)
        "",
        "",
        "",
        "",
        "",
        "Packed", // 22315 (0x572b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Not", // 21014 (0x5216)
        "",
        "",
        "",
        "",
        "",
        "",
        "For", // 18964 (0x4a14)
        "Else", // 18965 (0x4a15)
        "",
        "",
        "",
        "Label", // 21026 (0x5222)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "And", // 17669 (0x4505)
        "",
        "While", // 23842 (0x5d22)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Array", // 18240 (0x4740)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Case", // 18442 (0x480a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Div", // 18450 (0x4812)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Function", // 20331 (0x4f6b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "File", // 19218 (0x4b12)
        "",
        "Begin", // 18472 (0x4828)
        "",
        "",
        "",
        "",
        "Procedure", // 23152 (0x5a70)
        "",
        "",
        "",
        "Until", // 23343 (0x5b2f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Mod", // 20742 (0x5106)
        "",
        "Program", // 22614 (0x5856)
        "",
        "",
        "If", // 19438 (0x4bee)
        "",
        "",
        "End", // 18693 (0x4905)
        "",
        "",
        "Then", // 22810 (0x591a)
        "",
        "",
        "",
    };
    constexpr const int values[187] = {
        -1,
        -1,
        -1,
        -1,
        30, // 22818 (0x5922)
        -1,
        15, // 19454 (0x4bfe)
        7, // 19268 (0x4b44)
        -1,
        -1,
        -1,
        34, // 23573 (0x5c15)
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 22831 (0x592f)
        -1,
        29, // 22272 (0x5700)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 20974 (0x51ee)
        27, // 22284 (0x570c)
        -1,
        26, // 22847 (0x593f)
        -1,
        -1,
        -1,
        6, // 18176 (0x4700)
        -1,
        -1,
        -1,
        -1,
        13, // 19490 (0x4c22)
        -1,
        4, // 18744 (0x4938)
        32, // 23046 (0x5a06)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 20998 (0x5206)
        -1,
        18, // 21000 (0x5208)
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 22315 (0x572b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 21014 (0x5216)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 18964 (0x4a14)
        8, // 18965 (0x4a15)
        -1,
        -1,
        -1,
        16, // 21026 (0x5222)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 17669 (0x4505)
        -1,
        33, // 23842 (0x5d22)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 18240 (0x4740)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 18442 (0x480a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 18450 (0x4812)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 20331 (0x4f6b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 19218 (0x4b12)
        -1,
        2, // 18472 (0x4828)
        -1,
        -1,
        -1,
        -1,
        23, // 23152 (0x5a70)
        -1,
        -1,
        -1,
        31, // 23343 (0x5b2f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 20742 (0x5106)
        -1,
        24, // 22614 (0x5856)
        -1,
        -1,
        14, // 19438 (0x4bee)
        -1,
        -1,
        9, // 18693 (0x4905)
        -1,
        -1,
        28, // 22810 (0x591a)
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

//check: name=check_gpc_hash3, dataset=gpc, type=hash, hash=hash3
void check_gpc_hash3() {
    assert(lookup_gpc_hash3("Type") == 30);
    assert(lookup_gpc_hash3("In") == 15);
    assert(lookup_gpc_hash3("Downto") == 7);
    assert(lookup_gpc_hash3("With") == 34);
    assert(lookup_gpc_hash3("Record") == 25);
    assert(lookup_gpc_hash3("To") == 29);
    assert(lookup_gpc_hash3("Of") == 20);
    assert(lookup_gpc_hash3("Set") == 27);
    assert(lookup_gpc_hash3("Repeat") == 26);
    assert(lookup_gpc_hash3("Do") == 6);
    assert(lookup_gpc_hash3("Goto") == 13);
    assert(lookup_gpc_hash3("Const") == 4);
    assert(lookup_gpc_hash3("Var") == 32);
    assert(lookup_gpc_hash3("Or") == 21);
    assert(lookup_gpc_hash3("Nil") == 18);
    assert(lookup_gpc_hash3("Packed") == 22);
    assert(lookup_gpc_hash3("Not") == 19);
    assert(lookup_gpc_hash3("For") == 11);
    assert(lookup_gpc_hash3("Else") == 8);
    assert(lookup_gpc_hash3("Label") == 16);
    assert(lookup_gpc_hash3("And") == 0);
    assert(lookup_gpc_hash3("While") == 33);
    assert(lookup_gpc_hash3("Array") == 1);
    assert(lookup_gpc_hash3("Case") == 3);
    assert(lookup_gpc_hash3("Div") == 5);
    assert(lookup_gpc_hash3("Function") == 12);
    assert(lookup_gpc_hash3("File") == 10);
    assert(lookup_gpc_hash3("Begin") == 2);
    assert(lookup_gpc_hash3("Procedure") == 23);
    assert(lookup_gpc_hash3("Until") == 31);
    assert(lookup_gpc_hash3("Mod") == 17);
    assert(lookup_gpc_hash3("Program") == 24);
    assert(lookup_gpc_hash3("If") == 14);
    assert(lookup_gpc_hash3("End") == 9);
    assert(lookup_gpc_hash3("Then") == 28);
}

//lookup: name=lookup_gpc_hash_sum0, dataset=gpc, type=hash, hash=hash_sum0
int lookup_gpc_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 50) * 2;
    constexpr const std::string_view lookup[100] = {
        "Set", // 300 (0x12c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Not", // 305 (0x131)
        "While", // 505 (0x1f9)
        "",
        "",
        "Record", // 607 (0x25f)
        "",
        "",
        "",
        "Goto", // 409 (0x199)
        "Repeat", // 609 (0x261)
        "",
        "",
        "Array", // 511 (0x1ff)
        "",
        "With", // 412 (0x19c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Type", // 418 (0x1a2)
        "",
        "Const", // 519 (0x207)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Until", // 524 (0x20c)
        "",
        "And", // 275 (0x113)
        "If", // 175 (0xaf)
        "",
        "",
        "",
        "",
        "Program", // 728 (0x2d8)
        "",
        "Do", // 179 (0xb3)
        "End", // 279 (0x117)
        "Case", // 380 (0x17c)
        "Label", // 480 (0x1e0)
        "Of", // 181 (0xb5)
        "",
        "",
        "",
        "In", // 183 (0xb7)
        "",
        "File", // 384 (0x180)
        "Packed", // 584 (0x248)
        "Begin", // 485 (0x1e5)
        "Downto", // 635 (0x27b)
        "",
        "",
        "Procedure", // 937 (0x3a9)
        "",
        "Function", // 838 (0x346)
        "Mod", // 288 (0x120)
        "",
        "",
        "",
        "",
        "Div", // 291 (0x123)
        "Nil", // 291 (0x123)
        "",
        "",
        "Else", // 393 (0x189)
        "Or", // 193 (0xc1)
        "",
        "",
        "For", // 295 (0x127)
        "To", // 195 (0xc3)
        "",
        "",
        "Var", // 297 (0x129)
        "",
        "",
        "",
        "Then", // 399 (0x18f)
        "",
    };
    constexpr const int values[100] = {
        27, // 300 (0x12c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 305 (0x131)
        33, // 505 (0x1f9)
        -1,
        -1,
        25, // 607 (0x25f)
        -1,
        -1,
        -1,
        13, // 409 (0x199)
        26, // 609 (0x261)
        -1,
        -1,
        1, // 511 (0x1ff)
        -1,
        34, // 412 (0x19c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 418 (0x1a2)
        -1,
        4, // 519 (0x207)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 524 (0x20c)
        -1,
        0, // 275 (0x113)
        14, // 175 (0xaf)
        -1,
        -1,
        -1,
        -1,
        24, // 728 (0x2d8)
        -1,
        6, // 179 (0xb3)
        9, // 279 (0x117)
        3, // 380 (0x17c)
        16, // 480 (0x1e0)
        20, // 181 (0xb5)
        -1,
        -1,
        -1,
        15, // 183 (0xb7)
        -1,
        10, // 384 (0x180)
        22, // 584 (0x248)
        2, // 485 (0x1e5)
        7, // 635 (0x27b)
        -1,
        -1,
        23, // 937 (0x3a9)
        -1,
        12, // 838 (0x346)
        17, // 288 (0x120)
        -1,
        -1,
        -1,
        -1,
        5, // 291 (0x123)
        18, // 291 (0x123)
        -1,
        -1,
        8, // 393 (0x189)
        21, // 193 (0xc1)
        -1,
        -1,
        11, // 295 (0x127)
        29, // 195 (0xc3)
        -1,
        -1,
        32, // 297 (0x129)
        -1,
        -1,
        -1,
        28, // 399 (0x18f)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_gpc_hash_sum0, dataset=gpc, type=hash, hash=hash_sum0
void check_gpc_hash_sum0() {
    assert(lookup_gpc_hash_sum0("Set") == 27);
    assert(lookup_gpc_hash_sum0("Not") == 19);
    assert(lookup_gpc_hash_sum0("While") == 33);
    assert(lookup_gpc_hash_sum0("Record") == 25);
    assert(lookup_gpc_hash_sum0("Goto") == 13);
    assert(lookup_gpc_hash_sum0("Repeat") == 26);
    assert(lookup_gpc_hash_sum0("Array") == 1);
    assert(lookup_gpc_hash_sum0("With") == 34);
    assert(lookup_gpc_hash_sum0("Type") == 30);
    assert(lookup_gpc_hash_sum0("Const") == 4);
    assert(lookup_gpc_hash_sum0("Until") == 31);
    assert(lookup_gpc_hash_sum0("And") == 0);
    assert(lookup_gpc_hash_sum0("If") == 14);
    assert(lookup_gpc_hash_sum0("Program") == 24);
    assert(lookup_gpc_hash_sum0("Do") == 6);
    assert(lookup_gpc_hash_sum0("End") == 9);
    assert(lookup_gpc_hash_sum0("Case") == 3);
    assert(lookup_gpc_hash_sum0("Label") == 16);
    assert(lookup_gpc_hash_sum0("Of") == 20);
    assert(lookup_gpc_hash_sum0("In") == 15);
    assert(lookup_gpc_hash_sum0("File") == 10);
    assert(lookup_gpc_hash_sum0("Packed") == 22);
    assert(lookup_gpc_hash_sum0("Begin") == 2);
    assert(lookup_gpc_hash_sum0("Downto") == 7);
    assert(lookup_gpc_hash_sum0("Procedure") == 23);
    assert(lookup_gpc_hash_sum0("Function") == 12);
    assert(lookup_gpc_hash_sum0("Mod") == 17);
    assert(lookup_gpc_hash_sum0("Div") == 5);
    assert(lookup_gpc_hash_sum0("Nil") == 18);
    assert(lookup_gpc_hash_sum0("Else") == 8);
    assert(lookup_gpc_hash_sum0("Or") == 21);
    assert(lookup_gpc_hash_sum0("For") == 11);
    assert(lookup_gpc_hash_sum0("To") == 29);
    assert(lookup_gpc_hash_sum0("Var") == 32);
    assert(lookup_gpc_hash_sum0("Then") == 28);
}

//lookup: name=lookup_gpc_hash_sumN, dataset=gpc, type=hash, hash=hash_sumN
int lookup_gpc_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 40) * 2;
    constexpr const std::string_view lookup[80] = {
        "",
        "",
        "Downto", // 641 (0x281)
        "",
        "End", // 282 (0x11a)
        "",
        "Then", // 403 (0x193)
        "",
        "Const", // 524 (0x20c)
        "",
        "Label", // 485 (0x1e5)
        "",
        "Function", // 846 (0x34e)
        "",
        "",
        "",
        "",
        "",
        "Until", // 529 (0x211)
        "",
        "Begin", // 490 (0x1ea)
        "",
        "Mod", // 291 (0x123)
        "",
        "",
        "",
        "Goto", // 413 (0x19d)
        "Record", // 613 (0x265)
        "Div", // 294 (0x126)
        "Nil", // 294 (0x126)
        "Program", // 735 (0x2df)
        "Repeat", // 615 (0x267)
        "With", // 416 (0x1a0)
        "",
        "If", // 177 (0xb1)
        "",
        "For", // 298 (0x12a)
        "",
        "",
        "",
        "Var", // 300 (0x12c)
        "",
        "Do", // 181 (0xb5)
        "",
        "Type", // 422 (0x1a6)
        "",
        "Of", // 183 (0xb7)
        "Set", // 303 (0x12f)
        "Case", // 384 (0x180)
        "",
        "In", // 185 (0xb9)
        "",
        "Procedure", // 946 (0x3b2)
        "",
        "",
        "",
        "File", // 388 (0x184)
        "Not", // 308 (0x134)
        "",
        "",
        "Packed", // 590 (0x24e)
        "While", // 510 (0x1fe)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Or", // 195 (0xc3)
        "",
        "Array", // 516 (0x204)
        "",
        "Else", // 397 (0x18d)
        "To", // 197 (0xc5)
        "And", // 278 (0x116)
        "",
        "",
        "",
    };
    constexpr const int values[80] = {
        -1,
        -1,
        7, // 641 (0x281)
        -1,
        9, // 282 (0x11a)
        -1,
        28, // 403 (0x193)
        -1,
        4, // 524 (0x20c)
        -1,
        16, // 485 (0x1e5)
        -1,
        12, // 846 (0x34e)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 529 (0x211)
        -1,
        2, // 490 (0x1ea)
        -1,
        17, // 291 (0x123)
        -1,
        -1,
        -1,
        13, // 413 (0x19d)
        25, // 613 (0x265)
        5, // 294 (0x126)
        18, // 294 (0x126)
        24, // 735 (0x2df)
        26, // 615 (0x267)
        34, // 416 (0x1a0)
        -1,
        14, // 177 (0xb1)
        -1,
        11, // 298 (0x12a)
        -1,
        -1,
        -1,
        32, // 300 (0x12c)
        -1,
        6, // 181 (0xb5)
        -1,
        30, // 422 (0x1a6)
        -1,
        20, // 183 (0xb7)
        27, // 303 (0x12f)
        3, // 384 (0x180)
        -1,
        15, // 185 (0xb9)
        -1,
        23, // 946 (0x3b2)
        -1,
        -1,
        -1,
        10, // 388 (0x184)
        19, // 308 (0x134)
        -1,
        -1,
        22, // 590 (0x24e)
        33, // 510 (0x1fe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 195 (0xc3)
        -1,
        1, // 516 (0x204)
        -1,
        8, // 397 (0x18d)
        29, // 197 (0xc5)
        0, // 278 (0x116)
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

//check: name=check_gpc_hash_sumN, dataset=gpc, type=hash, hash=hash_sumN
void check_gpc_hash_sumN() {
    assert(lookup_gpc_hash_sumN("Downto") == 7);
    assert(lookup_gpc_hash_sumN("End") == 9);
    assert(lookup_gpc_hash_sumN("Then") == 28);
    assert(lookup_gpc_hash_sumN("Const") == 4);
    assert(lookup_gpc_hash_sumN("Label") == 16);
    assert(lookup_gpc_hash_sumN("Function") == 12);
    assert(lookup_gpc_hash_sumN("Until") == 31);
    assert(lookup_gpc_hash_sumN("Begin") == 2);
    assert(lookup_gpc_hash_sumN("Mod") == 17);
    assert(lookup_gpc_hash_sumN("Goto") == 13);
    assert(lookup_gpc_hash_sumN("Record") == 25);
    assert(lookup_gpc_hash_sumN("Div") == 5);
    assert(lookup_gpc_hash_sumN("Nil") == 18);
    assert(lookup_gpc_hash_sumN("Program") == 24);
    assert(lookup_gpc_hash_sumN("Repeat") == 26);
    assert(lookup_gpc_hash_sumN("With") == 34);
    assert(lookup_gpc_hash_sumN("If") == 14);
    assert(lookup_gpc_hash_sumN("For") == 11);
    assert(lookup_gpc_hash_sumN("Var") == 32);
    assert(lookup_gpc_hash_sumN("Do") == 6);
    assert(lookup_gpc_hash_sumN("Type") == 30);
    assert(lookup_gpc_hash_sumN("Of") == 20);
    assert(lookup_gpc_hash_sumN("Set") == 27);
    assert(lookup_gpc_hash_sumN("Case") == 3);
    assert(lookup_gpc_hash_sumN("In") == 15);
    assert(lookup_gpc_hash_sumN("Procedure") == 23);
    assert(lookup_gpc_hash_sumN("File") == 10);
    assert(lookup_gpc_hash_sumN("Not") == 19);
    assert(lookup_gpc_hash_sumN("Packed") == 22);
    assert(lookup_gpc_hash_sumN("While") == 33);
    assert(lookup_gpc_hash_sumN("Or") == 21);
    assert(lookup_gpc_hash_sumN("Array") == 1);
    assert(lookup_gpc_hash_sumN("Else") == 8);
    assert(lookup_gpc_hash_sumN("To") == 29);
    assert(lookup_gpc_hash_sumN("And") == 0);
}

//lookup: name=lookup_gpc_hash_djb2, dataset=gpc, type=hash, hash=hash_djb2
int lookup_gpc_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 117) * 1;
    constexpr const std::string_view lookup[117] = {
        "Until", // 214605975285 (0x31f7834ef5)
        "",
        "File", // 6502666601 (0x18396d169)
        "Var", // 197067666 (0xbbf0392)
        "",
        "",
        "For", // 197050704 (0xbbec150)
        "",
        "Case", // 6502550309 (0x183950b25)
        "",
        "Mod", // 197058313 (0xbbedf09)
        "",
        "To", // 5971692 (0x5b1eec)
        "And", // 197045212 (0xbbeabdc)
        "",
        "Downto", // 7081333182276 (0x670c0594f44)
        "",
        "",
        "",
        "",
        "Begin", // 214583105198 (0x31f62656ae)
        "",
        "Packed", // 7081785481585 (0x670db4ed971)
        "",
        "",
        "",
        "Type", // 6503187275 (0x1839ec34b)
        "",
        "",
        "Set", // 197064533 (0xbbef755)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Array", // 214582398184 (0x31f61b8ce8)
        "",
        "",
        "End", // 197049568 (0xbbebce0)
        "",
        "Goto", // 6502709346 (0x183977862)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Record", // 7081868500840 (0x670e0419f68)
        "",
        "",
        "",
        "",
        "",
        "",
        "Not", // 197059418 (0xbbee35a)
        "",
        "",
        "",
        "",
        "",
        "",
        "Do", // 5971164 (0x5b1cdc)
        "",
        "",
        "Of", // 5971518 (0x5b1e3e)
        "",
        "While", // 214608119618 (0x31f7a40742)
        "Label", // 214594815081 (0x31f6d90469)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Function", // 7711664455925903 (0x1b65b7cc85c08f)
        "Or", // 5971530 (0x5b1e4a)
        "",
        "Repeat", // 7081868956586 (0x670e04893aa)
        "",
        "Program", // 233699600295457 (0xd48c6da8e621)
        "Else", // 6502634162 (0x1839652b2)
        "Nil", // 197059212 (0xbbee28c)
        "Div", // 197048332 (0xbbeb80c)
        "",
        "",
        "",
        "Const", // 214584658448 (0x31f63e0a10)
        "",
        "",
        "",
        "",
        "",
        "Procedure", // 254498864549914514 (0x388295e713ce792)
        "",
        "",
        "",
        "",
        "",
        "With", // 6503277797 (0x183a024e5)
        "If", // 5971320 (0x5b1d78)
        "",
        "",
        "",
        "",
        "Then", // 6503168408 (0x1839e7998)
        "",
        "",
        "In", // 5971328 (0x5b1d80)
    };
    constexpr const int values[117] = {
        31, // 214605975285 (0x31f7834ef5)
        -1,
        10, // 6502666601 (0x18396d169)
        32, // 197067666 (0xbbf0392)
        -1,
        -1,
        11, // 197050704 (0xbbec150)
        -1,
        3, // 6502550309 (0x183950b25)
        -1,
        17, // 197058313 (0xbbedf09)
        -1,
        29, // 5971692 (0x5b1eec)
        0, // 197045212 (0xbbeabdc)
        -1,
        7, // 7081333182276 (0x670c0594f44)
        -1,
        -1,
        -1,
        -1,
        2, // 214583105198 (0x31f62656ae)
        -1,
        22, // 7081785481585 (0x670db4ed971)
        -1,
        -1,
        -1,
        30, // 6503187275 (0x1839ec34b)
        -1,
        -1,
        27, // 197064533 (0xbbef755)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 214582398184 (0x31f61b8ce8)
        -1,
        -1,
        9, // 197049568 (0xbbebce0)
        -1,
        13, // 6502709346 (0x183977862)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 7081868500840 (0x670e0419f68)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 197059418 (0xbbee35a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 5971164 (0x5b1cdc)
        -1,
        -1,
        20, // 5971518 (0x5b1e3e)
        -1,
        33, // 214608119618 (0x31f7a40742)
        16, // 214594815081 (0x31f6d90469)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 7711664455925903 (0x1b65b7cc85c08f)
        21, // 5971530 (0x5b1e4a)
        -1,
        26, // 7081868956586 (0x670e04893aa)
        -1,
        24, // 233699600295457 (0xd48c6da8e621)
        8, // 6502634162 (0x1839652b2)
        18, // 197059212 (0xbbee28c)
        5, // 197048332 (0xbbeb80c)
        -1,
        -1,
        -1,
        4, // 214584658448 (0x31f63e0a10)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 254498864549914514 (0x388295e713ce792)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 6503277797 (0x183a024e5)
        14, // 5971320 (0x5b1d78)
        -1,
        -1,
        -1,
        -1,
        28, // 6503168408 (0x1839e7998)
        -1,
        -1,
        15, // 5971328 (0x5b1d80)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_gpc_hash_djb2, dataset=gpc, type=hash, hash=hash_djb2
void check_gpc_hash_djb2() {
    assert(lookup_gpc_hash_djb2("Until") == 31);
    assert(lookup_gpc_hash_djb2("File") == 10);
    assert(lookup_gpc_hash_djb2("Var") == 32);
    assert(lookup_gpc_hash_djb2("For") == 11);
    assert(lookup_gpc_hash_djb2("Case") == 3);
    assert(lookup_gpc_hash_djb2("Mod") == 17);
    assert(lookup_gpc_hash_djb2("To") == 29);
    assert(lookup_gpc_hash_djb2("And") == 0);
    assert(lookup_gpc_hash_djb2("Downto") == 7);
    assert(lookup_gpc_hash_djb2("Begin") == 2);
    assert(lookup_gpc_hash_djb2("Packed") == 22);
    assert(lookup_gpc_hash_djb2("Type") == 30);
    assert(lookup_gpc_hash_djb2("Set") == 27);
    assert(lookup_gpc_hash_djb2("Array") == 1);
    assert(lookup_gpc_hash_djb2("End") == 9);
    assert(lookup_gpc_hash_djb2("Goto") == 13);
    assert(lookup_gpc_hash_djb2("Record") == 25);
    assert(lookup_gpc_hash_djb2("Not") == 19);
    assert(lookup_gpc_hash_djb2("Do") == 6);
    assert(lookup_gpc_hash_djb2("Of") == 20);
    assert(lookup_gpc_hash_djb2("While") == 33);
    assert(lookup_gpc_hash_djb2("Label") == 16);
    assert(lookup_gpc_hash_djb2("Function") == 12);
    assert(lookup_gpc_hash_djb2("Or") == 21);
    assert(lookup_gpc_hash_djb2("Repeat") == 26);
    assert(lookup_gpc_hash_djb2("Program") == 24);
    assert(lookup_gpc_hash_djb2("Else") == 8);
    assert(lookup_gpc_hash_djb2("Nil") == 18);
    assert(lookup_gpc_hash_djb2("Div") == 5);
    assert(lookup_gpc_hash_djb2("Const") == 4);
    assert(lookup_gpc_hash_djb2("Procedure") == 23);
    assert(lookup_gpc_hash_djb2("With") == 34);
    assert(lookup_gpc_hash_djb2("If") == 14);
    assert(lookup_gpc_hash_djb2("Then") == 28);
    assert(lookup_gpc_hash_djb2("In") == 15);
}

//lookup: name=lookup_gpc_hash_sdb, dataset=gpc, type=hash, hash=hash_sdb
int lookup_gpc_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 219) * 1;
    constexpr const std::string_view lookup[219] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "Repeat", // 2450081478871449279 (0x2200701fbae57ebf)
        "",
        "And", // 279205643255 (0x4101f403f7)
        "",
        "",
        "",
        "",
        "",
        "Not", // 335045395583 (0x4e0243047f)
        "Function", // 3011267752186035348 (0x29ca2c10f4a33c94)
        "Record", // 2446421844594752989 (0x21f36fb4b9d37ddd)
        "",
        "",
        "",
        "",
        "Downto", // 2131156723518240225 (0x1d9363bfa9fd75e1)
        "",
        "",
        "",
        "",
        "Const", // 257569906722088595 (0x39312772b002693)
        "",
        "",
        "",
        "",
        "",
        "Procedure", // 11325528118436862623 (0x9d2c5bd189209a9f)
        "",
        "",
        "",
        "",
        "For", // 300682511413 (0x4602130435)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Set", // 356521542798 (0x530257048e)
        "",
        "",
        "Var", // 369407362203 (0x560265049b)
        "",
        "",
        "Then", // 23647591911722529 (0x54035c0bb10e21)
        "Type", // 23647664933572306 (0x54036d0c220ed2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "With", // 24492137107623586 (0x5703780c170ea2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "While", // 323157922929322969 (0x47c166b328e2bd9)
        "",
        "",
        "Of", // 5177683 (0x4f0153)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Nil", // 335045002341 (0x4e023d0465)
        "Or", // 5177695 (0x4f015f)
        "",
        "",
        "",
        "",
        "",
        "Until", // 318091188665527354 (0x46a164032972c3a)
        "",
        "End", // 296387085339 (0x45020c041b)
        "",
        "",
        "",
        "",
        "",
        "File", // 19706405342940348 (0x4602df0a440cbc)
        "",
        "Do", // 4456763 (0x44013b)
        "Else", // 19424904596294865 (0x4502d90a420cd1)
        "",
        "Label", // 284030049214801748 (0x3f113d32cfc2754)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Mod", // 330750035046 (0x4d023d0466)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Case", // 18861830080957496 (0x4302bc09ca0c38)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "To", // 5505387 (0x54016b)
        "Goto", // 19987944748813615 (0x4702ee0a8b0d2f)
        "",
        "",
        "",
        "Packed", // 2382242285645757032 (0x210f6cbcb4d47a68)
        "",
        "",
        "",
        "",
        "If", // 4784449 (0x490141)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "In", // 4784457 (0x490149)
        "",
        "",
        "Program", // 15452148743230030740 (0xd6710f69b8b98394)
        "",
        "",
        "",
        "",
        "Begin", // 251376808666211537 (0x37d11e0295224d1)
        "Div", // 292091397141 (0x4402010415)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "Array", // 251658601490228789 (0x37e122a2a7f2635)
        "",
        "",
        "",
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
    constexpr const int values[219] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 2450081478871449279 (0x2200701fbae57ebf)
        -1,
        0, // 279205643255 (0x4101f403f7)
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 335045395583 (0x4e0243047f)
        12, // 3011267752186035348 (0x29ca2c10f4a33c94)
        25, // 2446421844594752989 (0x21f36fb4b9d37ddd)
        -1,
        -1,
        -1,
        -1,
        7, // 2131156723518240225 (0x1d9363bfa9fd75e1)
        -1,
        -1,
        -1,
        -1,
        4, // 257569906722088595 (0x39312772b002693)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 11325528118436862623 (0x9d2c5bd189209a9f)
        -1,
        -1,
        -1,
        -1,
        11, // 300682511413 (0x4602130435)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 356521542798 (0x530257048e)
        -1,
        -1,
        32, // 369407362203 (0x560265049b)
        -1,
        -1,
        28, // 23647591911722529 (0x54035c0bb10e21)
        30, // 23647664933572306 (0x54036d0c220ed2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 24492137107623586 (0x5703780c170ea2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 323157922929322969 (0x47c166b328e2bd9)
        -1,
        -1,
        20, // 5177683 (0x4f0153)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 335045002341 (0x4e023d0465)
        21, // 5177695 (0x4f015f)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 318091188665527354 (0x46a164032972c3a)
        -1,
        9, // 296387085339 (0x45020c041b)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 19706405342940348 (0x4602df0a440cbc)
        -1,
        6, // 4456763 (0x44013b)
        8, // 19424904596294865 (0x4502d90a420cd1)
        -1,
        16, // 284030049214801748 (0x3f113d32cfc2754)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 330750035046 (0x4d023d0466)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 18861830080957496 (0x4302bc09ca0c38)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 5505387 (0x54016b)
        13, // 19987944748813615 (0x4702ee0a8b0d2f)
        -1,
        -1,
        -1,
        22, // 2382242285645757032 (0x210f6cbcb4d47a68)
        -1,
        -1,
        -1,
        -1,
        14, // 4784449 (0x490141)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 4784457 (0x490149)
        -1,
        -1,
        24, // 15452148743230030740 (0xd6710f69b8b98394)
        -1,
        -1,
        -1,
        -1,
        2, // 251376808666211537 (0x37d11e0295224d1)
        5, // 292091397141 (0x4402010415)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 251658601490228789 (0x37e122a2a7f2635)
        -1,
        -1,
        -1,
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

//check: name=check_gpc_hash_sdb, dataset=gpc, type=hash, hash=hash_sdb
void check_gpc_hash_sdb() {
    assert(lookup_gpc_hash_sdb("Repeat") == 26);
    assert(lookup_gpc_hash_sdb("And") == 0);
    assert(lookup_gpc_hash_sdb("Not") == 19);
    assert(lookup_gpc_hash_sdb("Function") == 12);
    assert(lookup_gpc_hash_sdb("Record") == 25);
    assert(lookup_gpc_hash_sdb("Downto") == 7);
    assert(lookup_gpc_hash_sdb("Const") == 4);
    assert(lookup_gpc_hash_sdb("Procedure") == 23);
    assert(lookup_gpc_hash_sdb("For") == 11);
    assert(lookup_gpc_hash_sdb("Set") == 27);
    assert(lookup_gpc_hash_sdb("Var") == 32);
    assert(lookup_gpc_hash_sdb("Then") == 28);
    assert(lookup_gpc_hash_sdb("Type") == 30);
    assert(lookup_gpc_hash_sdb("With") == 34);
    assert(lookup_gpc_hash_sdb("While") == 33);
    assert(lookup_gpc_hash_sdb("Of") == 20);
    assert(lookup_gpc_hash_sdb("Nil") == 18);
    assert(lookup_gpc_hash_sdb("Or") == 21);
    assert(lookup_gpc_hash_sdb("Until") == 31);
    assert(lookup_gpc_hash_sdb("End") == 9);
    assert(lookup_gpc_hash_sdb("File") == 10);
    assert(lookup_gpc_hash_sdb("Do") == 6);
    assert(lookup_gpc_hash_sdb("Else") == 8);
    assert(lookup_gpc_hash_sdb("Label") == 16);
    assert(lookup_gpc_hash_sdb("Mod") == 17);
    assert(lookup_gpc_hash_sdb("Case") == 3);
    assert(lookup_gpc_hash_sdb("To") == 29);
    assert(lookup_gpc_hash_sdb("Goto") == 13);
    assert(lookup_gpc_hash_sdb("Packed") == 22);
    assert(lookup_gpc_hash_sdb("If") == 14);
    assert(lookup_gpc_hash_sdb("In") == 15);
    assert(lookup_gpc_hash_sdb("Program") == 24);
    assert(lookup_gpc_hash_sdb("Begin") == 2);
    assert(lookup_gpc_hash_sdb("Div") == 5);
    assert(lookup_gpc_hash_sdb("Array") == 1);
}
