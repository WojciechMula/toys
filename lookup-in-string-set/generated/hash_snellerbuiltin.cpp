
//lookup: name=lookup_snellerbuiltin_hash1, dataset=snellerbuiltin, type=hash, hash=hash1
int lookup_snellerbuiltin_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 163) * 3;
    static std::string_view lookup[489] = {
        "TO_UNIX_MICRO", // 2119 (0x847)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEO_HASH", // 1144 (0x478)
        "",
        "",
        "DATE_ADD_MONTH", // 1960 (0x7a8)
        "DATE_EXTRACT_MICROSECOND", // 3264 (0xcc0)
        "DATE_EXTRACT_MILLISECOND", // 3264 (0xcc0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "POW_UINT", // 1312 (0x520)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "POW", // 501 (0x1f5)
        "",
        "",
        "",
        "",
        "",
        "RADIANS", // 1155 (0x483)
        "",
        "",
        "LOG2", // 504 (0x1f8)
        "",
        "",
        "SQRT", // 668 (0x29c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OCTET_LENGTH", // 1812 (0x714)
        "",
        "",
        "UPPER", // 835 (0x343)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_SECOND", // 2312 (0x908)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TABLE_GLOB", // 1500 (0x5dc)
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_DOW", // 2480 (0x9b0)
        "",
        "",
        "ARRAY_SIZE", // 1340 (0x53c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SPLIT_PART", // 1670 (0x686)
        "TYPE_BIT", // 1344 (0x540)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BIT_COUNT", // 1350 (0x546)
        "DATE_DIFF_WEEK", // 2002 (0x7d2)
        "ARRAY_POSITION", // 2002 (0x7d2)
        "DATE_TRUNC_MINUTE", // 2329 (0x919)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEO_DISTANCE", // 1680 (0x690)
        "",
        "",
        "DATE_TRUNC_DOW", // 2170 (0x87a)
        "HASH_REPLACEMENT", // 2496 (0x9c0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ASSERT_ION_TYPE", // 2010 (0x7da)
        "",
        "",
        "TIME_BUCKET", // 1848 (0x738)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_SECOND", // 2176 (0x880)
        "",
        "",
        "CONTAINS_FUZZY_UNICODE", // 2992 (0xbb0)
        "DATE_TRUNC_MICROSECOND", // 2992 (0xbb0)
        "DATE_TRUNC_MILLISECOND", // 2992 (0xbb0)
        "CONTAINS", // 1200 (0x4b0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAR_LENGTH", // 1529 (0x5f9)
        "",
        "",
        "",
        "",
        "",
        "GEO_TILE_ES", // 1694 (0x69e)
        "",
        "",
        "CONTAINS_FUZZY", // 2184 (0x888)
        "",
        "",
        "DATE_ADD_WEEK", // 1859 (0x743)
        "DATE_EXTRACT_QUARTER", // 3000 (0xbb8)
        "",
        "DATE_EXTRACT_DAY", // 2512 (0x9d0)
        "DATE_EXTRACT_DOY", // 2512 (0x9d0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TO_UNIX_EPOCH", // 2028 (0x7ec)
        "SCALAR_REPLACEMENT", // 3006 (0xbbe)
        "STRUCT_REPLACEMENT", // 3006 (0xbbe)
        "CONTAINS_CI", // 1540 (0x604)
        "DATE_DIFF_MINUTE", // 2192 (0x890)
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_MONTH", // 2520 (0x9d8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DEGREES", // 1057 (0x421)
        "DATE_TRUNC_DAY", // 2198 (0x896)
        "IN_REPLACEMENT", // 2198 (0x896)
        "",
        "",
        "",
        "",
        "",
        "",
        "SUBSTRING", // 1386 (0x56a)
        "",
        "",
        "CEIL", // 572 (0x23c)
        "ASIN", // 572 (0x23c)
        "ATAN", // 572 (0x23c)
        "DATE_ADD_SECOND", // 2040 (0x7f8)
        "",
        "",
        "DATE_DIFF_MICROSECOND", // 2856 (0xb28)
        "DATE_DIFF_MILLISECOND", // 2856 (0xb28)
        "DATE_DIFF_DAY", // 2041 (0x7f9)
        "IS_SUBNET_OF", // 1716 (0x6b4)
        "ATAN2", // 575 (0x23f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONCAT", // 906 (0x38a)
        "DATE_ADD_DAY", // 1884 (0x75c)
        "",
        "DATE_TRUNC_QUARTER", // 2700 (0xa8c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXP10", // 585 (0x249)
        "WIDTH_BUCKET", // 2052 (0x804)
        "",
        "",
        "",
        "",
        "ROUND", // 750 (0x2ee)
        "",
        "",
        "GREATEST", // 1240 (0x4d8)
        "DATE_ADD_MINUTE", // 2055 (0x807)
        "",
        "",
        "",
        "",
        "EXPM1", // 590 (0x24e)
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY", // 1896 (0x768)
        "TRUNC", // 755 (0x2f3)
        "ACOS", // 592 (0x250)
        "",
        "",
        "",
        "DATE_DIFF_QUARTER", // 2550 (0x9f6)
        "DATE_EXTRACT_HOUR", // 2550 (0x9f6)
        "DATE_EXTRACT_YEAR", // 2550 (0x9f6)
        "",
        "",
        "",
        "",
        "",
        "",
        "FLOOR", // 760 (0x2f8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MICROSECOND", // 2720 (0xaa0)
        "DATE_ADD_MILLISECOND", // 2720 (0xaa0)
        "",
        "LTRIM", // 765 (0x2fd)
        "",
        "",
        "",
        "",
        "",
        "CBRT", // 604 (0x25c)
        "LOG", // 441 (0x1b9)
        "LIST_REPLACEMENT", // 2560 (0xa00)
        "ARRAY_CONTAINS", // 2072 (0x818)
        "PARTITION_VALUE", // 2235 (0x8bb)
        "",
        "",
        "",
        "",
        "ABS", // 444 (0x1bc)
        "DATE_ADD_QUARTER", // 2400 (0x960)
        "",
        "SIZE", // 608 (0x260)
        "",
        "",
        "",
        "",
        "",
        "EXP", // 447 (0x1bf)
        "DATE_TRUNC_MONTH", // 2240 (0x8c0)
        "",
        "",
        "",
        "",
        "GEO_TILE_X", // 1590 (0x636)
        "",
        "",
        "COS", // 450 (0x1c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HYPOT", // 780 (0x30c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOG10", // 620 (0x26c)
        "DATE_TRUNC_HOUR", // 2250 (0x8ca)
        "DATE_TRUNC_YEAR", // 2250 (0x8ca)
        "",
        "",
        "",
        "ROUND_EVEN", // 1600 (0x640)
        "GEO_TILE_Y", // 1600 (0x640)
        "",
        "",
        "",
        "",
        "LN1P", // 624 (0x270)
        "",
        "",
        "",
        "",
        "",
        "EQUALS_CI", // 1278 (0x4fe)
        "",
        "",
        "LOWER", // 790 (0x316)
        "",
        "",
        "DATE_EXTRACT_SECOND", // 2584 (0xa18)
        "",
        "",
        "",
        "",
        "",
        "MAKE_STRUCT", // 1771 (0x6eb)
        "",
        "",
        "",
        "",
        "",
        "RTRIM", // 795 (0x31b)
        "PI", // 306 (0x132)
        "",
        "DATE_DIFF_HOUR", // 2100 (0x834)
        "DATE_DIFF_MONTH", // 2100 (0x834)
        "DATE_DIFF_YEAR", // 2100 (0x834)
        "LN", // 308 (0x134)
        "MAKE_LIST", // 1449 (0x5a9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LEAST", // 800 (0x320)
        "",
        "",
        "",
        "",
        "",
        "EXP2", // 476 (0x1dc)
        "TABLE_PATTERN", // 2106 (0x83a)
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY_UNICODE", // 2760 (0xac8)
        "IN_SUBQUERY", // 1782 (0x6f6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TRIM", // 644 (0x284)
        "SIGN", // 644 (0x284)
        "",
        "",
        "",
        "",
        "SIN", // 483 (0x1e3)
        "DATE_ADD_HOUR", // 1950 (0x79e)
        "DATE_ADD_YEAR", // 1950 (0x79e)
        "DATE_EXTRACT_MINUTE", // 2603 (0xa2b)
        "",
        "",
        "",
        "",
        "",
        "TAN", // 486 (0x1e6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    static int values[489] = {
        95, // 2119 (0x847)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        96, // 1144 (0x478)
        -1,
        -1,
        60, // 1960 (0x7a8)
        73, // 3264 (0xcc0)
        74, // 3264 (0xcc0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 1312 (0x520)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 501 (0x1f5)
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 1155 (0x483)
        -1,
        -1,
        36, // 504 (0x1f8)
        -1,
        -1,
        26, // 668 (0x29c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 1812 (0x714)
        -1,
        -1,
        4, // 835 (0x343)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        86, // 2312 (0x908)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 1500 (0x5dc)
        -1,
        -1,
        -1,
        -1,
        -1,
        79, // 2480 (0x9b0)
        -1,
        -1,
        103, // 1340 (0x53c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 1670 (0x686)
        116, // 1344 (0x540)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 1350 (0x546)
        69, // 2002 (0x7d2)
        104, // 2002 (0x7d2)
        87, // 2329 (0x919)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        100, // 1680 (0x690)
        -1,
        -1,
        90, // 2170 (0x87a)
        109, // 2496 (0x9c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        117, // 2010 (0x7da)
        -1,
        -1,
        113, // 1848 (0x738)
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 2176 (0x880)
        -1,
        -1,
        12, // 2992 (0xbb0)
        84, // 2992 (0xbb0)
        85, // 2992 (0xbb0)
        6, // 1200 (0x4b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 1529 (0x5f9)
        -1,
        -1,
        -1,
        -1,
        -1,
        99, // 1694 (0x69e)
        -1,
        -1,
        11, // 2184 (0x888)
        -1,
        -1,
        59, // 1859 (0x743)
        82, // 3000 (0xbb8)
        -1,
        78, // 2512 (0x9d0)
        80, // 2512 (0x9d0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        94, // 2028 (0x7ec)
        110, // 3006 (0xbbe)
        111, // 3006 (0xbbe)
        7, // 1540 (0x604)
        66, // 2192 (0x890)
        -1,
        -1,
        -1,
        -1,
        81, // 2520 (0x9d8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 1057 (0x421)
        89, // 2198 (0x896)
        108, // 2198 (0x896)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 1386 (0x56a)
        -1,
        -1,
        25, // 572 (0x23c)
        46, // 572 (0x23c)
        48, // 572 (0x23c)
        55, // 2040 (0x7f8)
        -1,
        -1,
        63, // 2856 (0xb28)
        64, // 2856 (0xb28)
        68, // 2041 (0x7f9)
        15, // 1716 (0x6b4)
        49, // 575 (0x23f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 906 (0x38a)
        58, // 1884 (0x75c)
        -1,
        92, // 2700 (0xa8c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 585 (0x249)
        52, // 2052 (0x804)
        -1,
        -1,
        -1,
        -1,
        21, // 750 (0x2ee)
        -1,
        -1,
        51, // 1240 (0x4d8)
        56, // 2055 (0x807)
        -1,
        -1,
        -1,
        -1,
        29, // 590 (0x24e)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 1896 (0x768)
        23, // 755 (0x2f3)
        47, // 592 (0x250)
        -1,
        -1,
        -1,
        71, // 2550 (0x9f6)
        77, // 2550 (0x9f6)
        83, // 2550 (0x9f6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 760 (0x2f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 2720 (0xaa0)
        54, // 2720 (0xaa0)
        -1,
        2, // 765 (0x2fd)
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 604 (0x25c)
        35, // 441 (0x1b9)
        112, // 2560 (0xa00)
        102, // 2072 (0x818)
        118, // 2235 (0x8bb)
        -1,
        -1,
        -1,
        -1,
        19, // 444 (0x1bc)
        61, // 2400 (0x960)
        -1,
        101, // 608 (0x260)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 447 (0x1bf)
        91, // 2240 (0x8c0)
        -1,
        -1,
        -1,
        -1,
        97, // 1590 (0x636)
        -1,
        -1,
        44, // 450 (0x1c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 780 (0x30c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 620 (0x26c)
        88, // 2250 (0x8ca)
        93, // 2250 (0x8ca)
        -1,
        -1,
        -1,
        22, // 1600 (0x640)
        98, // 1600 (0x640)
        -1,
        -1,
        -1,
        -1,
        34, // 624 (0x270)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 1278 (0x4fe)
        -1,
        -1,
        5, // 790 (0x316)
        -1,
        -1,
        75, // 2584 (0xa18)
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 1771 (0x6eb)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 795 (0x31b)
        40, // 306 (0x132)
        -1,
        67, // 2100 (0x834)
        70, // 2100 (0x834)
        72, // 2100 (0x834)
        33, // 308 (0x134)
        114, // 1449 (0x5a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 800 (0x320)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 476 (0x1dc)
        106, // 2106 (0x83a)
        -1,
        -1,
        -1,
        -1,
        10, // 2760 (0xac8)
        107, // 1782 (0x6f6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 644 (0x284)
        20, // 644 (0x284)
        -1,
        -1,
        -1,
        -1,
        43, // 483 (0x1e3)
        57, // 1950 (0x79e)
        62, // 1950 (0x79e)
        76, // 2603 (0xa2b)
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 486 (0x1e6)
        -1,
        -1,
        -1,
        -1,
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

//check: name=check_snellerbuiltin_hash1, dataset=snellerbuiltin, type=hash, hash=hash1
void check_snellerbuiltin_hash1() {
    assert(lookup_snellerbuiltin_hash1("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_hash1("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash1("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash1("POW") == 38);
    assert(lookup_snellerbuiltin_hash1("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash1("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash1("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash1("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash1("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash1("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash1("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash1("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash1("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash1("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash1("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash1("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash1("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash1("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash1("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash1("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash1("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash1("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash1("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash1("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash1("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash1("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash1("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_hash1("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash1("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash1("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash1("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash1("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash1("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash1("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash1("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash1("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash1("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash1("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash1("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash1("ROUND") == 21);
    assert(lookup_snellerbuiltin_hash1("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash1("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash1("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash1("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash1("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash1("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash1("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash1("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash1("LOG") == 35);
    assert(lookup_snellerbuiltin_hash1("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash1("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash1("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash1("ABS") == 19);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash1("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash1("EXP") == 28);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash1("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash1("COS") == 44);
    assert(lookup_snellerbuiltin_hash1("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash1("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash1("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_hash1("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash1("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash1("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash1("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash1("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash1("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_hash1("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash1("PI") == 40);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash1("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash1("LN") == 33);
    assert(lookup_snellerbuiltin_hash1("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash1("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash1("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash1("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash1("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash1("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash1("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash1("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash1("SIN") == 43);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash1("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash1("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash1("TAN") == 45);
}

//lookup: name=lookup_snellerbuiltin_hash2, dataset=snellerbuiltin, type=hash, hash=hash2
int lookup_snellerbuiltin_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 136) * 3;
    static std::string_view lookup[408] = {
        "",
        "",
        "",
        "LTRIM", // 5849 (0x16d9)
        "RADIANS", // 6801 (0x1a91)
        "",
        "ASSERT_ION_TYPE", // 4490 (0x118a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ROUND", // 5581 (0x15cd)
        "",
        "",
        "",
        "",
        "",
        "ARRAY_SIZE", // 4495 (0x118f)
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY", // 6129 (0x17f1)
        "CONTAINS_FUZZY_UNICODE", // 4633 (0x1219)
        "",
        "",
        "",
        "",
        "SIZE", // 5723 (0x165b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MONTH", // 4910 (0x132e)
        "",
        "",
        "DATE_ADD_SECOND", // 4639 (0x121f)
        "DATE_DIFF_MONTH", // 4911 (0x132f)
        "GEO_DISTANCE", // 4911 (0x132f)
        "DATE_ADD_QUARTER", // 5592 (0x15d8)
        "DATE_TRUNC_MONTH", // 4912 (0x1330)
        "",
        "DATE_DIFF_QUARTER", // 5593 (0x15d9)
        "DATE_EXTRACT_HOUR", // 5593 (0x15d9)
        "DATE_EXTRACT_YEAR", // 5593 (0x15d9)
        "DATE_EXTRACT_MONTH", // 4914 (0x1332)
        "DATE_TRUNC_QUARTER", // 5594 (0x15da)
        "IN_REPLACEMENT", // 6138 (0x17fa)
        "",
        "",
        "",
        "DATE_EXTRACT_QUARTER", // 5596 (0x15dc)
        "",
        "",
        "TABLE_PATTERN", // 6549 (0x1995)
        "",
        "",
        "SCALAR_REPLACEMENT", // 6958 (0x1b2e)
        "STRUCT_REPLACEMENT", // 6958 (0x1b2e)
        "",
        "",
        "",
        "",
        "ARRAY_POSITION", // 5056 (0x13c0)
        "",
        "",
        "FLOOR", // 5737 (0x1669)
        "",
        "",
        "",
        "",
        "",
        "POW", // 6963 (0x1b33)
        "TAN", // 6555 (0x199b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SPLIT_PART", // 6966 (0x1b36)
        "",
        "",
        "",
        "",
        "",
        "SQRT", // 6968 (0x1b38)
        "",
        "",
        "",
        "",
        "",
        "ASIN", // 5066 (0x13ca)
        "ATAN", // 5066 (0x13ca)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UPPER", // 6975 (0x1b3f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CBRT", // 5624 (0x15f8)
        "",
        "",
        "TRUNC", // 5625 (0x15f9)
        "",
        "",
        "CONCAT", // 5626 (0x15fa)
        "",
        "",
        "",
        "",
        "",
        "SUBSTRING", // 5900 (0x170c)
        "DATE_DIFF_MINUTE", // 4676 (0x1244)
        "DATE_EXTRACT_DOW", // 5900 (0x170c)
        "EXP10", // 3317 (0xcf5)
        "DATE_TRUNC_MINUTE", // 4677 (0x1245)
        "GEO_TILE_Y", // 6309 (0x18a5)
        "EXP2", // 3454 (0xd7e)
        "GEO_TILE_ES", // 5902 (0x170e)
        "",
        "DATE_EXTRACT_MINUTE", // 4679 (0x1247)
        "",
        "",
        "CEIL", // 5088 (0x13e0)
        "",
        "",
        "DATE_ADD_WEEK", // 5089 (0x13e1)
        "",
        "",
        "DATE_DIFF_WEEK", // 5090 (0x13e2)
        "DATE_TRUNC_DOW", // 5906 (0x1712)
        "",
        "CHAR_LENGTH", // 4819 (0x12d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RTRIM", // 6319 (0x18af)
        "",
        "",
        "POW_UINT", // 6728 (0x1a48)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DEGREES", // 5643 (0x160b)
        "",
        "",
        "",
        "",
        "",
        "HYPOT", // 6053 (0x17a5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TRIM", // 6464 (0x1940)
        "DATE_ADD_DAY", // 6056 (0x17a8)
        "GEO_HASH", // 5104 (0x13f0)
        "DATE_DIFF_DAY", // 6057 (0x17a9)
        "",
        "",
        "DATE_TRUNC_DAY", // 6058 (0x17aa)
        "",
        "",
        "DATE_ADD_MINUTE", // 4699 (0x125b)
        "",
        "",
        "",
        "",
        "",
        "TO_UNIX_EPOCH", // 6061 (0x17ad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HASH_REPLACEMENT", // 6064 (0x17b0)
        "",
        "",
        "SIN", // 6473 (0x1949)
        "",
        "",
        "IS_SUBNET_OF", // 5114 (0x13fa)
        "LN", // 5930 (0x172a)
        "",
        "EXP", // 5523 (0x1593)
        "",
        "",
        "DATE_EXTRACT_DAY", // 6068 (0x17b4)
        "DATE_EXTRACT_DOY", // 6068 (0x17b4)
        "",
        "MAKE_LIST", // 6477 (0x194d)
        "",
        "",
        "SIGN", // 6478 (0x194e)
        "",
        "",
        "MAKE_STRUCT", // 6479 (0x194f)
        "",
        "",
        "ABS", // 5392 (0x1510)
        "WIDTH_BUCKET", // 7296 (0x1c80)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOG", // 5399 (0x1517)
        "ACOS", // 5399 (0x1517)
        "PARTITION_VALUE", // 5535 (0x159f)
        "",
        "",
        "",
        "BIT_COUNT", // 5537 (0x15a1)
        "TO_UNIX_MICRO", // 6625 (0x19e1)
        "",
        "TABLE_GLOB", // 5538 (0x15a2)
        "",
        "",
        "",
        "",
        "",
        "LN1P", // 6084 (0x17c4)
        "",
        "",
        "ARRAY_CONTAINS", // 5405 (0x151d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OCTET_LENGTH", // 5684 (0x1634)
        "GREATEST", // 5956 (0x1744)
        "",
        "CONTAINS_FUZZY", // 5957 (0x1745)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXPM1", // 3376 (0xd30)
        "LIST_REPLACEMENT", // 6368 (0x18e0)
        "",
        "CONTAINS", // 5553 (0x15b1)
        "",
        "",
        "IN_SUBQUERY", // 6506 (0x196a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOWER", // 6237 (0x185d)
        "LOG10", // 3653 (0xe45)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_CI", // 4880 (0x1310)
        "DATE_DIFF_SECOND", // 4608 (0x1200)
        "",
        "DATE_TRUNC_SECOND", // 4609 (0x1201)
        "",
        "",
        "COS", // 5562 (0x15ba)
        "GEO_TILE_X", // 6242 (0x1862)
        "",
        "DATE_EXTRACT_SECOND", // 4611 (0x1203)
        "",
        "",
        "DATE_ADD_MICROSECOND", // 4612 (0x1204)
        "DATE_ADD_MILLISECOND", // 4612 (0x1204)
        "",
        "EQUALS_FUZZY_UNICODE", // 4749 (0x128d)
        "DATE_DIFF_MICROSECOND", // 4613 (0x1205)
        "DATE_DIFF_MILLISECOND", // 4613 (0x1205)
        "DATE_TRUNC_MICROSECOND", // 4614 (0x1206)
        "DATE_TRUNC_MILLISECOND", // 4614 (0x1206)
        "",
        "ATAN2", // 3255 (0xcb7)
        "",
        "",
        "DATE_EXTRACT_MICROSECOND", // 4616 (0x1208)
        "DATE_EXTRACT_MILLISECOND", // 4616 (0x1208)
        "TYPE_BIT", // 7064 (0x1b98)
        "",
        "",
        "",
        "PI", // 5842 (0x16d2)
        "",
        "",
        "TIME_BUCKET", // 7067 (0x1b9b)
        "",
        "",
        "EQUALS_CI", // 5028 (0x13a4)
        "LOG2", // 3804 (0xedc)
        "",
        "LEAST", // 6389 (0x18f5)
        "DATE_ADD_HOUR", // 5573 (0x15c5)
        "DATE_ADD_YEAR", // 5573 (0x15c5)
        "ROUND_EVEN", // 6390 (0x18f6)
        "DATE_DIFF_HOUR", // 5574 (0x15c6)
        "DATE_DIFF_YEAR", // 5574 (0x15c6)
        "DATE_TRUNC_HOUR", // 5575 (0x15c7)
        "DATE_TRUNC_YEAR", // 5575 (0x15c7)
        "",
    };
    static int values[408] = {
        -1,
        -1,
        -1,
        2, // 5849 (0x16d9)
        42, // 6801 (0x1a91)
        -1,
        117, // 4490 (0x118a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 5581 (0x15cd)
        -1,
        -1,
        -1,
        -1,
        -1,
        103, // 4495 (0x118f)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 6129 (0x17f1)
        12, // 4633 (0x1219)
        -1,
        -1,
        -1,
        -1,
        101, // 5723 (0x165b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 4910 (0x132e)
        -1,
        -1,
        55, // 4639 (0x121f)
        70, // 4911 (0x132f)
        100, // 4911 (0x132f)
        61, // 5592 (0x15d8)
        91, // 4912 (0x1330)
        -1,
        71, // 5593 (0x15d9)
        77, // 5593 (0x15d9)
        83, // 5593 (0x15d9)
        81, // 4914 (0x1332)
        92, // 5594 (0x15da)
        108, // 6138 (0x17fa)
        -1,
        -1,
        -1,
        82, // 5596 (0x15dc)
        -1,
        -1,
        106, // 6549 (0x1995)
        -1,
        -1,
        110, // 6958 (0x1b2e)
        111, // 6958 (0x1b2e)
        -1,
        -1,
        -1,
        -1,
        104, // 5056 (0x13c0)
        -1,
        -1,
        24, // 5737 (0x1669)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 6963 (0x1b33)
        45, // 6555 (0x199b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 6966 (0x1b36)
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 6968 (0x1b38)
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 5066 (0x13ca)
        48, // 5066 (0x13ca)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 6975 (0x1b3f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 5624 (0x15f8)
        -1,
        -1,
        23, // 5625 (0x15f9)
        -1,
        -1,
        0, // 5626 (0x15fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 5900 (0x170c)
        66, // 4676 (0x1244)
        79, // 5900 (0x170c)
        31, // 3317 (0xcf5)
        87, // 4677 (0x1245)
        98, // 6309 (0x18a5)
        30, // 3454 (0xd7e)
        99, // 5902 (0x170e)
        -1,
        76, // 4679 (0x1247)
        -1,
        -1,
        25, // 5088 (0x13e0)
        -1,
        -1,
        59, // 5089 (0x13e1)
        -1,
        -1,
        69, // 5090 (0x13e2)
        90, // 5906 (0x1712)
        -1,
        14, // 4819 (0x12d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 6319 (0x18af)
        -1,
        -1,
        39, // 6728 (0x1a48)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 5643 (0x160b)
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 6053 (0x17a5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 6464 (0x1940)
        58, // 6056 (0x17a8)
        96, // 5104 (0x13f0)
        68, // 6057 (0x17a9)
        -1,
        -1,
        89, // 6058 (0x17aa)
        -1,
        -1,
        56, // 4699 (0x125b)
        -1,
        -1,
        -1,
        -1,
        -1,
        94, // 6061 (0x17ad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 6064 (0x17b0)
        -1,
        -1,
        43, // 6473 (0x1949)
        -1,
        -1,
        15, // 5114 (0x13fa)
        33, // 5930 (0x172a)
        -1,
        28, // 5523 (0x1593)
        -1,
        -1,
        78, // 6068 (0x17b4)
        80, // 6068 (0x17b4)
        -1,
        114, // 6477 (0x194d)
        -1,
        -1,
        20, // 6478 (0x194e)
        -1,
        -1,
        115, // 6479 (0x194f)
        -1,
        -1,
        19, // 5392 (0x1510)
        52, // 7296 (0x1c80)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 5399 (0x1517)
        47, // 5399 (0x1517)
        118, // 5535 (0x159f)
        -1,
        -1,
        -1,
        18, // 5537 (0x15a1)
        95, // 6625 (0x19e1)
        -1,
        105, // 5538 (0x15a2)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 6084 (0x17c4)
        -1,
        -1,
        102, // 5405 (0x151d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 5684 (0x1634)
        51, // 5956 (0x1744)
        -1,
        11, // 5957 (0x1745)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 3376 (0xd30)
        112, // 6368 (0x18e0)
        -1,
        6, // 5553 (0x15b1)
        -1,
        -1,
        107, // 6506 (0x196a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 6237 (0x185d)
        37, // 3653 (0xe45)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 4880 (0x1310)
        65, // 4608 (0x1200)
        -1,
        86, // 4609 (0x1201)
        -1,
        -1,
        44, // 5562 (0x15ba)
        97, // 6242 (0x1862)
        -1,
        75, // 4611 (0x1203)
        -1,
        -1,
        53, // 4612 (0x1204)
        54, // 4612 (0x1204)
        -1,
        10, // 4749 (0x128d)
        63, // 4613 (0x1205)
        64, // 4613 (0x1205)
        84, // 4614 (0x1206)
        85, // 4614 (0x1206)
        -1,
        49, // 3255 (0xcb7)
        -1,
        -1,
        73, // 4616 (0x1208)
        74, // 4616 (0x1208)
        116, // 7064 (0x1b98)
        -1,
        -1,
        -1,
        40, // 5842 (0x16d2)
        -1,
        -1,
        113, // 7067 (0x1b9b)
        -1,
        -1,
        8, // 5028 (0x13a4)
        36, // 3804 (0xedc)
        -1,
        50, // 6389 (0x18f5)
        57, // 5573 (0x15c5)
        62, // 5573 (0x15c5)
        22, // 6390 (0x18f6)
        67, // 5574 (0x15c6)
        72, // 5574 (0x15c6)
        88, // 5575 (0x15c7)
        93, // 5575 (0x15c7)
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_snellerbuiltin_hash2, dataset=snellerbuiltin, type=hash, hash=hash2
void check_snellerbuiltin_hash2() {
    assert(lookup_snellerbuiltin_hash2("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash2("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash2("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash2("ROUND") == 21);
    assert(lookup_snellerbuiltin_hash2("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash2("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash2("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash2("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash2("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash2("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash2("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash2("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash2("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_hash2("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash2("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash2("POW") == 38);
    assert(lookup_snellerbuiltin_hash2("TAN") == 45);
    assert(lookup_snellerbuiltin_hash2("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash2("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash2("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash2("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash2("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash2("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash2("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash2("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash2("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash2("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash2("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash2("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash2("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash2("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash2("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash2("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash2("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash2("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash2("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash2("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash2("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash2("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash2("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash2("SIN") == 43);
    assert(lookup_snellerbuiltin_hash2("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash2("LN") == 33);
    assert(lookup_snellerbuiltin_hash2("EXP") == 28);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash2("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash2("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash2("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_hash2("ABS") == 19);
    assert(lookup_snellerbuiltin_hash2("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash2("LOG") == 35);
    assert(lookup_snellerbuiltin_hash2("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash2("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash2("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash2("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_hash2("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash2("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash2("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash2("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash2("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash2("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash2("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash2("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash2("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash2("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash2("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash2("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash2("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash2("COS") == 44);
    assert(lookup_snellerbuiltin_hash2("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash2("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash2("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash2("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash2("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash2("PI") == 40);
    assert(lookup_snellerbuiltin_hash2("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash2("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash2("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash2("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash2("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash2("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash2("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash2("DATE_TRUNC_YEAR") == 93);
}

//lookup: name=lookup_snellerbuiltin_hash3, dataset=snellerbuiltin, type=hash, hash=hash3
int lookup_snellerbuiltin_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 131) * 3;
    static std::string_view lookup[393] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_CI", // 20307 (0x4f53)
        "ARRAY_SIZE", // 19521 (0x4c41)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_WEEK", // 21097 (0x5269)
        "",
        "",
        "",
        "",
        "",
        "LN1P", // 20706 (0x50e2)
        "LIST_REPLACEMENT", // 23981 (0x5dad)
        "",
        "DATE_ADD_DAY", // 20838 (0x5166)
        "IN_REPLACEMENT", // 22672 (0x5890)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_HOUR", // 21104 (0x5270)
        "DATE_ADD_YEAR", // 21104 (0x5270)
        "",
        "LEAST", // 20974 (0x51ee)
        "DATE_ADD_MONTH", // 21367 (0x5377)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_WEEK", // 21370 (0x537a)
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY", // 21110 (0x5276)
        "SUBSTRING", // 23861 (0x5d35)
        "TYPE_BIT", // 23861 (0x5d35)
        "DATE_DIFF_DAY", // 21111 (0x5277)
        "",
        "",
        "DATE_ADD_SECOND", // 21636 (0x5484)
        "",
        "",
        "LTRIM", // 20982 (0x51f6)
        "LOWER", // 20982 (0x51f6)
        "DATE_ADD_MINUTE", // 21637 (0x5485)
        "",
        "",
        "",
        "DATE_DIFF_HOUR", // 21377 (0x5381)
        "DATE_DIFF_YEAR", // 21377 (0x5381)
        "HASH_REPLACEMENT", // 22949 (0x59a5)
        "DATE_DIFF_MONTH", // 21640 (0x5488)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WIDTH_BUCKET", // 25705 (0x6469)
        "DATE_TRUNC_DOW", // 21382 (0x5386)
        "",
        "EXP2", // 18894 (0x49ce)
        "",
        "",
        "DATE_TRUNC_DAY", // 21384 (0x5388)
        "",
        "",
        "DATE_DIFF_SECOND", // 21909 (0x5595)
        "",
        "",
        "POW_UINT", // 22827 (0x592b)
        "DATE_DIFF_MINUTE", // 21910 (0x5596)
        "",
        "",
        "",
        "",
        "DATE_TRUNC_HOUR", // 21650 (0x5492)
        "DATE_TRUNC_YEAR", // 21650 (0x5492)
        "",
        "DATE_TRUNC_MONTH", // 21913 (0x5599)
        "TIME_BUCKET", // 24664 (0x6058)
        "",
        "ROUND_EVEN", // 23879 (0x5d47)
        "",
        "",
        "SPLIT_PART", // 24142 (0x5e4e)
        "",
        "",
        "EXP10", // 19165 (0x4add)
        "",
        "",
        "EXPM1", // 19166 (0x4ade)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_SECOND", // 22182 (0x56a6)
        "",
        "",
        "DATE_TRUNC_MINUTE", // 22183 (0x56a7)
        "TABLE_PATTERN", // 25196 (0x626c)
        "",
        "",
        "",
        "",
        "DATE_ADD_QUARTER", // 21923 (0x55a3)
        "",
        "",
        "",
        "",
        "",
        "MAKE_LIST", // 22318 (0x572e)
        "",
        "",
        "CEIL", // 18389 (0x47d5)
        "EXP", // 18651 (0x48db)
        "",
        "",
        "",
        "",
        "CONTAINS_FUZZY", // 21142 (0x5296)
        "DATE_EXTRACT_DOW", // 21928 (0x55a8)
        "",
        "TO_UNIX_EPOCH", // 25204 (0x6274)
        "",
        "",
        "DATE_EXTRACT_DAY", // 21930 (0x55aa)
        "DATE_EXTRACT_DOY", // 21930 (0x55aa)
        "",
        "ABS", // 17608 (0x44c8)
        "CBRT", // 18394 (0x47da)
        "",
        "FLOOR", // 19443 (0x4bf3)
        "COS", // 18133 (0x46d5)
        "ARRAY_POSITION", // 20622 (0x508e)
        "",
        "",
        "",
        "DATE_DIFF_QUARTER", // 22196 (0x56b4)
        "DATE_EXTRACT_HOUR", // 22196 (0x56b4)
        "DATE_EXTRACT_YEAR", // 22196 (0x56b4)
        "HYPOT", // 19970 (0x4e02)
        "DATE_EXTRACT_MONTH", // 22459 (0x57bb)
        "ASSERT_ION_TYPE", // 20887 (0x5197)
        "OCTET_LENGTH", // 23639 (0x5c57)
        "TO_UNIX_MICRO", // 25211 (0x627b)
        "",
        "ARRAY_CONTAINS", // 20627 (0x5093)
        "",
        "",
        "ATAN2", // 18139 (0x46db)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TAN", // 22466 (0x57c2)
        "DATE_EXTRACT_SECOND", // 22728 (0x58c8)
        "GEO_HASH", // 20501 (0x5015)
        "ACOS", // 17882 (0x45da)
        "DATE_EXTRACT_MINUTE", // 22729 (0x58c9)
        "",
        "",
        "",
        "",
        "DATE_TRUNC_QUARTER", // 22469 (0x57c5)
        "",
        "",
        "",
        "",
        "",
        "MAKE_STRUCT", // 22864 (0x5950)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MICROSECOND", // 23001 (0x59d9)
        "DATE_ADD_MILLISECOND", // 23001 (0x59d9)
        "",
        "ASIN", // 17893 (0x45e5)
        "",
        "",
        "ATAN", // 17894 (0x45e6)
        "",
        "",
        "SIN", // 22218 (0x56ca)
        "",
        "",
        "",
        "",
        "",
        "PI", // 21172 (0x52b4)
        "SIZE", // 22482 (0x57d2)
        "PARTITION_VALUE", // 24709 (0x6085)
        "",
        "",
        "",
        "DEGREES", // 19471 (0x4c0f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY_UNICODE", // 23274 (0x5aea)
        "DATE_DIFF_MICROSECOND", // 23274 (0x5aea)
        "DATE_DIFF_MILLISECOND", // 23274 (0x5aea)
        "",
        "",
        "",
        "CONCAT", // 18953 (0x4a09)
        "",
        "",
        "SIGN", // 22491 (0x57db)
        "GREATEST", // 20526 (0x502e)
        "DATE_EXTRACT_QUARTER", // 23015 (0x59e7)
        "",
        "",
        "",
        "TRIM", // 22755 (0x58e3)
        "",
        "",
        "TRUNC", // 23018 (0x59ea)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_MICROSECOND", // 23547 (0x5bfb)
        "DATE_TRUNC_MILLISECOND", // 23547 (0x5bfb)
        "",
        "",
        "",
        "",
        "UPPER", // 23287 (0x5af7)
        "",
        "",
        "EQUALS_CI", // 20275 (0x4f33)
        "",
        "",
        "",
        "",
        "",
        "ROUND", // 22504 (0x57e8)
        "GEO_TILE_X", // 21063 (0x5247)
        "",
        "SQRT", // 22505 (0x57e9)
        "GEO_TILE_Y", // 21064 (0x5248)
        "",
        "",
        "",
        "",
        "GEO_DISTANCE", // 21590 (0x5456)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IS_SUBNET_OF", // 22117 (0x5665)
        "GEO_TILE_ES", // 21331 (0x5353)
        "",
        "CONTAINS", // 19498 (0x4c2a)
        "LOG2", // 20677 (0x50c5)
        "",
        "",
        "",
        "",
        "POW", // 21465 (0x53d9)
        "IN_SUBQUERY", // 21858 (0x5562)
        "",
        "SCALAR_REPLACEMENT", // 26313 (0x66c9)
        "",
        "",
        "",
        "",
        "",
        "LN", // 20158 (0x4ebe)
        "",
        "",
        "",
        "",
        "",
        "RTRIM", // 22518 (0x57f6)
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_FUZZY_UNICODE", // 23306 (0x5b0a)
        "LOG10", // 20948 (0x51d4)
        "",
        "LOG", // 20425 (0x4fc9)
        "DATE_EXTRACT_MICROSECOND", // 24093 (0x5e1d)
        "DATE_EXTRACT_MILLISECOND", // 24093 (0x5e1d)
        "",
        "",
        "",
        "BIT_COUNT", // 19510 (0x4c36)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAR_LENGTH", // 20299 (0x4f4b)
        "",
        "",
        "RADIANS", // 23051 (0x5a0b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TABLE_GLOB", // 24365 (0x5f2d)
        "STRUCT_REPLACEMENT", // 26330 (0x66da)
        "",
    };
    static int values[393] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 20307 (0x4f53)
        103, // 19521 (0x4c41)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        59, // 21097 (0x5269)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 20706 (0x50e2)
        112, // 23981 (0x5dad)
        -1,
        58, // 20838 (0x5166)
        108, // 22672 (0x5890)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        57, // 21104 (0x5270)
        62, // 21104 (0x5270)
        -1,
        50, // 20974 (0x51ee)
        60, // 21367 (0x5377)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        69, // 21370 (0x537a)
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 21110 (0x5276)
        16, // 23861 (0x5d35)
        116, // 23861 (0x5d35)
        68, // 21111 (0x5277)
        -1,
        -1,
        55, // 21636 (0x5484)
        -1,
        -1,
        2, // 20982 (0x51f6)
        5, // 20982 (0x51f6)
        56, // 21637 (0x5485)
        -1,
        -1,
        -1,
        67, // 21377 (0x5381)
        72, // 21377 (0x5381)
        109, // 22949 (0x59a5)
        70, // 21640 (0x5488)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 25705 (0x6469)
        90, // 21382 (0x5386)
        -1,
        30, // 18894 (0x49ce)
        -1,
        -1,
        89, // 21384 (0x5388)
        -1,
        -1,
        65, // 21909 (0x5595)
        -1,
        -1,
        39, // 22827 (0x592b)
        66, // 21910 (0x5596)
        -1,
        -1,
        -1,
        -1,
        88, // 21650 (0x5492)
        93, // 21650 (0x5492)
        -1,
        91, // 21913 (0x5599)
        113, // 24664 (0x6058)
        -1,
        22, // 23879 (0x5d47)
        -1,
        -1,
        17, // 24142 (0x5e4e)
        -1,
        -1,
        31, // 19165 (0x4add)
        -1,
        -1,
        29, // 19166 (0x4ade)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        86, // 22182 (0x56a6)
        -1,
        -1,
        87, // 22183 (0x56a7)
        106, // 25196 (0x626c)
        -1,
        -1,
        -1,
        -1,
        61, // 21923 (0x55a3)
        -1,
        -1,
        -1,
        -1,
        -1,
        114, // 22318 (0x572e)
        -1,
        -1,
        25, // 18389 (0x47d5)
        28, // 18651 (0x48db)
        -1,
        -1,
        -1,
        -1,
        11, // 21142 (0x5296)
        79, // 21928 (0x55a8)
        -1,
        94, // 25204 (0x6274)
        -1,
        -1,
        78, // 21930 (0x55aa)
        80, // 21930 (0x55aa)
        -1,
        19, // 17608 (0x44c8)
        27, // 18394 (0x47da)
        -1,
        24, // 19443 (0x4bf3)
        44, // 18133 (0x46d5)
        104, // 20622 (0x508e)
        -1,
        -1,
        -1,
        71, // 22196 (0x56b4)
        77, // 22196 (0x56b4)
        83, // 22196 (0x56b4)
        32, // 19970 (0x4e02)
        81, // 22459 (0x57bb)
        117, // 20887 (0x5197)
        13, // 23639 (0x5c57)
        95, // 25211 (0x627b)
        -1,
        102, // 20627 (0x5093)
        -1,
        -1,
        49, // 18139 (0x46db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 22466 (0x57c2)
        75, // 22728 (0x58c8)
        96, // 20501 (0x5015)
        47, // 17882 (0x45da)
        76, // 22729 (0x58c9)
        -1,
        -1,
        -1,
        -1,
        92, // 22469 (0x57c5)
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 22864 (0x5950)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 23001 (0x59d9)
        54, // 23001 (0x59d9)
        -1,
        46, // 17893 (0x45e5)
        -1,
        -1,
        48, // 17894 (0x45e6)
        -1,
        -1,
        43, // 22218 (0x56ca)
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 21172 (0x52b4)
        101, // 22482 (0x57d2)
        118, // 24709 (0x6085)
        -1,
        -1,
        -1,
        41, // 19471 (0x4c0f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 23274 (0x5aea)
        63, // 23274 (0x5aea)
        64, // 23274 (0x5aea)
        -1,
        -1,
        -1,
        0, // 18953 (0x4a09)
        -1,
        -1,
        20, // 22491 (0x57db)
        51, // 20526 (0x502e)
        82, // 23015 (0x59e7)
        -1,
        -1,
        -1,
        1, // 22755 (0x58e3)
        -1,
        -1,
        23, // 23018 (0x59ea)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        84, // 23547 (0x5bfb)
        85, // 23547 (0x5bfb)
        -1,
        -1,
        -1,
        -1,
        4, // 23287 (0x5af7)
        -1,
        -1,
        8, // 20275 (0x4f33)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 22504 (0x57e8)
        97, // 21063 (0x5247)
        -1,
        26, // 22505 (0x57e9)
        98, // 21064 (0x5248)
        -1,
        -1,
        -1,
        -1,
        100, // 21590 (0x5456)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 22117 (0x5665)
        99, // 21331 (0x5353)
        -1,
        6, // 19498 (0x4c2a)
        36, // 20677 (0x50c5)
        -1,
        -1,
        -1,
        -1,
        38, // 21465 (0x53d9)
        107, // 21858 (0x5562)
        -1,
        110, // 26313 (0x66c9)
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 20158 (0x4ebe)
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 22518 (0x57f6)
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 23306 (0x5b0a)
        37, // 20948 (0x51d4)
        -1,
        35, // 20425 (0x4fc9)
        73, // 24093 (0x5e1d)
        74, // 24093 (0x5e1d)
        -1,
        -1,
        -1,
        18, // 19510 (0x4c36)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 20299 (0x4f4b)
        -1,
        -1,
        42, // 23051 (0x5a0b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 24365 (0x5f2d)
        111, // 26330 (0x66da)
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_snellerbuiltin_hash3, dataset=snellerbuiltin, type=hash, hash=hash3
void check_snellerbuiltin_hash3() {
    assert(lookup_snellerbuiltin_hash3("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash3("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash3("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash3("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash3("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash3("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash3("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash3("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash3("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash3("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash3("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash3("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash3("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash3("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash3("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash3("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash3("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash3("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash3("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash3("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash3("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash3("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash3("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash3("EXP") == 28);
    assert(lookup_snellerbuiltin_hash3("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash3("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash3("ABS") == 19);
    assert(lookup_snellerbuiltin_hash3("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash3("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash3("COS") == 44);
    assert(lookup_snellerbuiltin_hash3("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash3("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash3("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash3("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash3("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_hash3("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash3("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash3("TAN") == 45);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash3("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash3("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash3("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash3("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash3("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash3("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash3("SIN") == 43);
    assert(lookup_snellerbuiltin_hash3("PI") == 40);
    assert(lookup_snellerbuiltin_hash3("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash3("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash3("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash3("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash3("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash3("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash3("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash3("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash3("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash3("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash3("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash3("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash3("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash3("ROUND") == 21);
    assert(lookup_snellerbuiltin_hash3("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash3("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash3("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash3("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash3("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash3("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash3("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash3("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash3("POW") == 38);
    assert(lookup_snellerbuiltin_hash3("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash3("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash3("LN") == 33);
    assert(lookup_snellerbuiltin_hash3("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash3("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash3("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash3("LOG") == 35);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash3("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash3("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash3("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash3("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash3("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash3("STRUCT_REPLACEMENT") == 111);
}

//lookup: name=lookup_snellerbuiltin_hash_sum0, dataset=snellerbuiltin, type=hash, hash=hash_sum0
int lookup_snellerbuiltin_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 264) * 2;
    static std::string_view lookup[528] = {
        "DATE_EXTRACT_YEAR", // 1320 (0x528)
        "",
        "DATE_DIFF_WEEK", // 1057 (0x421)
        "ARRAY_SIZE", // 793 (0x319)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_YEAR", // 1062 (0x426)
        "IN_REPLACEMENT", // 1062 (0x426)
        "GEO_TILE_X", // 799 (0x31f)
        "",
        "EQUALS_FUZZY_UNICODE", // 1592 (0x638)
        "GEO_TILE_Y", // 800 (0x320)
        "",
        "",
        "SPLIT_PART", // 802 (0x322)
        "",
        "DATE_ADD_MONTH", // 1067 (0x42b)
        "",
        "LOG2", // 276 (0x114)
        "",
        "DATE_EXTRACT_HOUR", // 1333 (0x535)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_MINUTE", // 1338 (0x53a)
        "",
        "LN1P", // 283 (0x11b)
        "DATE_DIFF_HOUR", // 1075 (0x433)
        "",
        "",
        "CEIL", // 285 (0x11d)
        "",
        "",
        "",
        "EXP2", // 287 (0x11f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ATAN", // 292 (0x124)
        "",
        "ARRAY_CONTAINS", // 1085 (0x43d)
        "SCALAR_REPLACEMENT", // 1349 (0x545)
        "ACOS", // 294 (0x126)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CBRT", // 299 (0x12b)
        "ASIN", // 299 (0x12b)
        "",
        "",
        "",
        "",
        "DATE_TRUNC_DAY", // 1094 (0x446)
        "",
        "CHAR_LENGTH", // 831 (0x33f)
        "",
        "",
        "",
        "SIGN", // 305 (0x131)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_CI", // 842 (0x34a)
        "DATE_TRUNC_DOW", // 1106 (0x452)
        "SIZE", // 315 (0x13b)
        "ARRAY_POSITION", // 1107 (0x453)
        "TRIM", // 316 (0x13c)
        "TIME_BUCKET", // 844 (0x34c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOG10", // 323 (0x143)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_SECOND", // 1121 (0x461)
        "",
        "SQRT", // 330 (0x14a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_FUZZY", // 1126 (0x466)
        "EXP10", // 334 (0x14e)
        "GEO_TILE_ES", // 863 (0x35f)
        "",
        "",
        "",
        "",
        "",
        "MAKE_STRUCT", // 866 (0x362)
        "",
        "",
        "",
        "STRUCT_REPLACEMENT", // 1396 (0x574)
        "",
        "",
        "",
        "ATAN2", // 342 (0x156)
        "GEO_HASH", // 606 (0x25e)
        "CONTAINS", // 607 (0x25f)
        "GREATEST", // 607 (0x25f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_MONTH", // 1405 (0x57d)
        "",
        "",
        "",
        "DATE_ADD_MINUTE", // 1143 (0x477)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MONTH", // 1147 (0x47b)
        "",
        "",
        "",
        "",
        "",
        "IN_SUBQUERY", // 886 (0x376)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXPM1", // 363 (0x16b)
        "",
        "DATE_TRUNC_QUARTER", // 1420 (0x58c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_DAY", // 899 (0x383)
        "DATE_TRUNC_MILLISECOND", // 1691 (0x69b)
        "",
        "",
        "GEO_DISTANCE", // 901 (0x385)
        "",
        "DATE_TRUNC_MICROSECOND", // 1694 (0x69e)
        "",
        "",
        "",
        "TYPE_BIT", // 640 (0x280)
        "",
        "LEAST", // 377 (0x179)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PARTITION_VALUE", // 1174 (0x496)
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_YEAR", // 1177 (0x499)
        "",
        "FLOOR", // 386 (0x182)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LTRIM", // 392 (0x188)
        "ROUND", // 392 (0x188)
        "LOWER", // 393 (0x189)
        "",
        "",
        "",
        "",
        "",
        "UPPER", // 396 (0x18c)
        "TRUNC", // 396 (0x18c)
        "POW_UINT", // 661 (0x295)
        "WIDTH_BUCKET", // 925 (0x39d)
        "RTRIM", // 398 (0x18e)
        "DATE_TRUNC_HOUR", // 1190 (0x4a6)
        "",
        "",
        "OCTET_LENGTH", // 928 (0x3a0)
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_SECOND", // 1459 (0x5b3)
        "",
        "HYPOT", // 404 (0x194)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_SECOND", // 1201 (0x4b1)
        "",
        "",
        "",
        "HASH_REPLACEMENT", // 1203 (0x4b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ASSERT_ION_TYPE", // 1208 (0x4b8)
        "",
        "PI", // 153 (0x99)
        "",
        "LN", // 154 (0x9a)
        "",
        "",
        "",
        "CONTAINS_FUZZY_UNICODE", // 1740 (0x6cc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_MINUTE", // 1481 (0x5c9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_CI", // 694 (0x2b6)
        "",
        "DATE_DIFF_MINUTE", // 1223 (0x4c7)
        "",
        "IS_SUBNET_OF", // 960 (0x3c0)
        "",
        "DATE_ADD_QUARTER", // 1225 (0x4c9)
        "MAKE_LIST", // 697 (0x2b9)
        "",
        "",
        "LIST_REPLACEMENT", // 1227 (0x4cb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONCAT", // 440 (0x1b8)
        "DATE_ADD_MILLISECOND", // 1496 (0x5d8)
        "SUBSTRING", // 705 (0x2c1)
        "",
        "",
        "",
        "DATE_ADD_MICROSECOND", // 1499 (0x5db)
        "",
        "",
        "",
        "DATE_EXTRACT_DAY", // 1237 (0x4d5)
        "",
        "",
        "",
        "BIT_COUNT", // 711 (0x2c7)
        "",
        "",
        "",
        "DATE_ADD_WEEK", // 977 (0x3d1)
        "",
        "EQUALS_FUZZY", // 978 (0x3d2)
        "",
        "DATE_DIFF_DAY", // 979 (0x3d3)
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_YEAR", // 982 (0x3d6)
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_DOW", // 1249 (0x4e1)
        "",
        "",
        "",
        "DATE_EXTRACT_DOY", // 1251 (0x4e3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_HOUR", // 995 (0x3e3)
        "",
        "",
        "",
        "TABLE_PATTERN", // 997 (0x3e5)
        "",
        "DATE_TRUNC_MONTH", // 1262 (0x4ee)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ABS", // 214 (0xd6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TABLE_GLOB", // 747 (0x2eb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOG", // 226 (0xe2)
        "",
        "TAN", // 227 (0xe3)
        "",
        "",
        "",
        "COS", // 229 (0xe5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIN", // 234 (0xea)
        "",
        "",
        "",
        "",
        "",
        "EXP", // 237 (0xed)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_QUARTER", // 1563 (0x61b)
        "",
        "",
        "",
        "",
        "",
        "POW", // 246 (0xf6)
        "",
        "DEGREES", // 511 (0x1ff)
        "",
        "",
        "",
        "DATE_DIFF_QUARTER", // 1305 (0x519)
        "",
        "RADIANS", // 514 (0x202)
        "DATE_EXTRACT_MILLISECOND", // 1834 (0x72a)
        "",
        "",
        "TO_UNIX_EPOCH", // 1044 (0x414)
        "",
        "DATE_EXTRACT_MICROSECOND", // 1837 (0x72d)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MILLISECOND", // 1576 (0x628)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MICROSECOND", // 1579 (0x62b)
        "",
        "DATE_TRUNC_SECOND", // 1316 (0x524)
        "",
        "ROUND_EVEN", // 789 (0x315)
        "",
        "",
        "",
        "TO_UNIX_MICRO", // 1055 (0x41f)
        "",
    };
    static int values[528] = {
        83, // 1320 (0x528)
        -1,
        69, // 1057 (0x421)
        103, // 793 (0x319)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 1062 (0x426)
        108, // 1062 (0x426)
        97, // 799 (0x31f)
        -1,
        10, // 1592 (0x638)
        98, // 800 (0x320)
        -1,
        -1,
        17, // 802 (0x322)
        -1,
        60, // 1067 (0x42b)
        -1,
        36, // 276 (0x114)
        -1,
        77, // 1333 (0x535)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 1338 (0x53a)
        -1,
        34, // 283 (0x11b)
        67, // 1075 (0x433)
        -1,
        -1,
        25, // 285 (0x11d)
        -1,
        -1,
        -1,
        30, // 287 (0x11f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 292 (0x124)
        -1,
        102, // 1085 (0x43d)
        110, // 1349 (0x545)
        47, // 294 (0x126)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 299 (0x12b)
        46, // 299 (0x12b)
        -1,
        -1,
        -1,
        -1,
        89, // 1094 (0x446)
        -1,
        14, // 831 (0x33f)
        -1,
        -1,
        -1,
        20, // 305 (0x131)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 842 (0x34a)
        90, // 1106 (0x452)
        101, // 315 (0x13b)
        104, // 1107 (0x453)
        1, // 316 (0x13c)
        113, // 844 (0x34c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 323 (0x143)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 1121 (0x461)
        -1,
        26, // 330 (0x14a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 1126 (0x466)
        31, // 334 (0x14e)
        99, // 863 (0x35f)
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 866 (0x362)
        -1,
        -1,
        -1,
        111, // 1396 (0x574)
        -1,
        -1,
        -1,
        49, // 342 (0x156)
        96, // 606 (0x25e)
        6, // 607 (0x25f)
        51, // 607 (0x25f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        81, // 1405 (0x57d)
        -1,
        -1,
        -1,
        56, // 1143 (0x477)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 1147 (0x47b)
        -1,
        -1,
        -1,
        -1,
        -1,
        107, // 886 (0x376)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 363 (0x16b)
        -1,
        92, // 1420 (0x58c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 899 (0x383)
        85, // 1691 (0x69b)
        -1,
        -1,
        100, // 901 (0x385)
        -1,
        84, // 1694 (0x69e)
        -1,
        -1,
        -1,
        116, // 640 (0x280)
        -1,
        50, // 377 (0x179)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        118, // 1174 (0x496)
        -1,
        -1,
        -1,
        -1,
        -1,
        93, // 1177 (0x499)
        -1,
        24, // 386 (0x182)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 392 (0x188)
        21, // 392 (0x188)
        5, // 393 (0x189)
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 396 (0x18c)
        23, // 396 (0x18c)
        39, // 661 (0x295)
        52, // 925 (0x39d)
        3, // 398 (0x18e)
        88, // 1190 (0x4a6)
        -1,
        -1,
        13, // 928 (0x3a0)
        -1,
        -1,
        -1,
        -1,
        -1,
        75, // 1459 (0x5b3)
        -1,
        32, // 404 (0x194)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 1201 (0x4b1)
        -1,
        -1,
        -1,
        109, // 1203 (0x4b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        117, // 1208 (0x4b8)
        -1,
        40, // 153 (0x99)
        -1,
        33, // 154 (0x9a)
        -1,
        -1,
        -1,
        12, // 1740 (0x6cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        76, // 1481 (0x5c9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 694 (0x2b6)
        -1,
        66, // 1223 (0x4c7)
        -1,
        15, // 960 (0x3c0)
        -1,
        61, // 1225 (0x4c9)
        114, // 697 (0x2b9)
        -1,
        -1,
        112, // 1227 (0x4cb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 440 (0x1b8)
        54, // 1496 (0x5d8)
        16, // 705 (0x2c1)
        -1,
        -1,
        -1,
        53, // 1499 (0x5db)
        -1,
        -1,
        -1,
        78, // 1237 (0x4d5)
        -1,
        -1,
        -1,
        18, // 711 (0x2c7)
        -1,
        -1,
        -1,
        59, // 977 (0x3d1)
        -1,
        9, // 978 (0x3d2)
        -1,
        68, // 979 (0x3d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        62, // 982 (0x3d6)
        -1,
        -1,
        -1,
        -1,
        -1,
        79, // 1249 (0x4e1)
        -1,
        -1,
        -1,
        80, // 1251 (0x4e3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        57, // 995 (0x3e3)
        -1,
        -1,
        -1,
        106, // 997 (0x3e5)
        -1,
        91, // 1262 (0x4ee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 214 (0xd6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 747 (0x2eb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 226 (0xe2)
        -1,
        45, // 227 (0xe3)
        -1,
        -1,
        -1,
        44, // 229 (0xe5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 234 (0xea)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 237 (0xed)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        82, // 1563 (0x61b)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 246 (0xf6)
        -1,
        41, // 511 (0x1ff)
        -1,
        -1,
        -1,
        71, // 1305 (0x519)
        -1,
        42, // 514 (0x202)
        74, // 1834 (0x72a)
        -1,
        -1,
        94, // 1044 (0x414)
        -1,
        73, // 1837 (0x72d)
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 1576 (0x628)
        -1,
        -1,
        -1,
        -1,
        -1,
        63, // 1579 (0x62b)
        -1,
        86, // 1316 (0x524)
        -1,
        22, // 789 (0x315)
        -1,
        -1,
        -1,
        95, // 1055 (0x41f)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_snellerbuiltin_hash_sum0, dataset=snellerbuiltin, type=hash, hash=hash_sum0
void check_snellerbuiltin_hash_sum0() {
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash_sum0("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash_sum0("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash_sum0("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash_sum0("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash_sum0("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash_sum0("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash_sum0("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash_sum0("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash_sum0("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash_sum0("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash_sum0("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash_sum0("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash_sum0("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash_sum0("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash_sum0("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash_sum0("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash_sum0("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash_sum0("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash_sum0("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash_sum0("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash_sum0("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash_sum0("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash_sum0("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash_sum0("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash_sum0("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash_sum0("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash_sum0("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash_sum0("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash_sum0("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_hash_sum0("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_hash_sum0("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash_sum0("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash_sum0("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash_sum0("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash_sum0("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash_sum0("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash_sum0("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash_sum0("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash_sum0("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash_sum0("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_hash_sum0("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash_sum0("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash_sum0("ROUND") == 21);
    assert(lookup_snellerbuiltin_hash_sum0("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash_sum0("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash_sum0("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash_sum0("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash_sum0("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash_sum0("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash_sum0("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash_sum0("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash_sum0("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash_sum0("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash_sum0("PI") == 40);
    assert(lookup_snellerbuiltin_hash_sum0("LN") == 33);
    assert(lookup_snellerbuiltin_hash_sum0("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash_sum0("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash_sum0("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash_sum0("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash_sum0("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash_sum0("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash_sum0("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash_sum0("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash_sum0("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash_sum0("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash_sum0("ABS") == 19);
    assert(lookup_snellerbuiltin_hash_sum0("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash_sum0("LOG") == 35);
    assert(lookup_snellerbuiltin_hash_sum0("TAN") == 45);
    assert(lookup_snellerbuiltin_hash_sum0("COS") == 44);
    assert(lookup_snellerbuiltin_hash_sum0("SIN") == 43);
    assert(lookup_snellerbuiltin_hash_sum0("EXP") == 28);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash_sum0("POW") == 38);
    assert(lookup_snellerbuiltin_hash_sum0("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash_sum0("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash_sum0("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash_sum0("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash_sum0("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash_sum0("TO_UNIX_MICRO") == 95);
}

//lookup: name=lookup_snellerbuiltin_hash_sumN, dataset=snellerbuiltin, type=hash, hash=hash_sumN
int lookup_snellerbuiltin_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 293) * 2;
    static std::string_view lookup[586] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "ATAN", // 296 (0x128)
        "",
        "CONTAINS_FUZZY_UNICODE", // 1762 (0x6e2)
        "",
        "ACOS", // 298 (0x12a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CBRT", // 303 (0x12f)
        "ASIN", // 303 (0x12f)
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_SECOND", // 1478 (0x5c6)
        "",
        "",
        "",
        "",
        "",
        "SIGN", // 309 (0x135)
        "",
        "PARTITION_VALUE", // 1189 (0x4a5)
        "",
        "IN_SUBQUERY", // 897 (0x381)
        "",
        "",
        "",
        "DATE_TRUNC_YEAR", // 1192 (0x4a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIZE", // 319 (0x13f)
        "",
        "TRIM", // 320 (0x140)
        "",
        "GEO_HASH", // 614 (0x266)
        "",
        "CONTAINS", // 615 (0x267)
        "GREATEST", // 615 (0x267)
        "",
        "",
        "",
        "",
        "DATE_ADD_DAY", // 911 (0x38f)
        "",
        "DATE_TRUNC_HOUR", // 1205 (0x4b5)
        "",
        "GEO_DISTANCE", // 913 (0x391)
        "",
        "LOG10", // 328 (0x148)
        "DATE_EXTRACT_MINUTE", // 1500 (0x5dc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SQRT", // 334 (0x14e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_SECOND", // 1217 (0x4c1)
        "",
        "EXP10", // 339 (0x153)
        "",
        "HASH_REPLACEMENT", // 1219 (0x4c3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MILLISECOND", // 1516 (0x5ec)
        "ASSERT_ION_TYPE", // 1223 (0x4c7)
        "",
        "",
        "",
        "",
        "ATAN2", // 347 (0x15b)
        "DATE_ADD_MICROSECOND", // 1519 (0x5ef)
        "",
        "",
        "",
        "",
        "",
        "",
        "WIDTH_BUCKET", // 937 (0x3a9)
        "",
        "",
        "",
        "",
        "",
        "OCTET_LENGTH", // 940 (0x3ac)
        "",
        "TYPE_BIT", // 648 (0x288)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MINUTE", // 1239 (0x4d7)
        "",
        "",
        "",
        "DATE_ADD_QUARTER", // 1241 (0x4d9)
        "",
        "",
        "",
        "LIST_REPLACEMENT", // 1243 (0x4db)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXPM1", // 368 (0x170)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_DAY", // 1253 (0x4e5)
        "",
        "",
        "",
        "POW_UINT", // 669 (0x29d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LEAST", // 382 (0x17e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IS_SUBNET_OF", // 972 (0x3cc)
        "DATE_EXTRACT_DOW", // 1265 (0x4f1)
        "",
        "",
        "DATE_EXTRACT_DOY", // 1267 (0x4f3)
        "",
        "",
        "",
        "",
        "",
        "FLOOR", // 391 (0x187)
        "",
        "",
        "",
        "DATE_EXTRACT_MILLISECOND", // 1858 (0x742)
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_MICROSECOND", // 1861 (0x745)
        "",
        "LTRIM", // 397 (0x18d)
        "ROUND", // 397 (0x18d)
        "LOWER", // 398 (0x18e)
        "",
        "DATE_TRUNC_MONTH", // 1278 (0x4fe)
        "",
        "",
        "",
        "UPPER", // 401 (0x191)
        "TRUNC", // 401 (0x191)
        "",
        "",
        "RTRIM", // 403 (0x193)
        "",
        "EQUALS_FUZZY", // 990 (0x3de)
        "DATE_ADD_WEEK", // 990 (0x3de)
        "",
        "",
        "DATE_DIFF_DAY", // 992 (0x3e0)
        "",
        "",
        "",
        "",
        "",
        "HYPOT", // 409 (0x199)
        "DATE_ADD_YEAR", // 995 (0x3e3)
        "EQUALS_CI", // 703 (0x2bf)
        "",
        "DATE_EXTRACT_QUARTER", // 1583 (0x62f)
        "",
        "",
        "",
        "MAKE_LIST", // 706 (0x2c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SUBSTRING", // 714 (0x2ca)
        "",
        "DATE_ADD_HOUR", // 1008 (0x3f0)
        "",
        "",
        "",
        "TABLE_PATTERN", // 1010 (0x3f2)
        "",
        "DATE_DIFF_MILLISECOND", // 1597 (0x63d)
        "",
        "",
        "",
        "BIT_COUNT", // 720 (0x2d0)
        "",
        "DATE_DIFF_MICROSECOND", // 1600 (0x640)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY_UNICODE", // 1612 (0x64c)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_QUARTER", // 1322 (0x52a)
        "",
        "",
        "",
        "",
        "",
        "CONCAT", // 446 (0x1be)
        "",
        "",
        "",
        "PI", // 155 (0x9b)
        "",
        "LN", // 156 (0x9c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_SECOND", // 1333 (0x535)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_YEAR", // 1337 (0x539)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TABLE_GLOB", // 757 (0x2f5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_HOUR", // 1350 (0x546)
        "TO_UNIX_EPOCH", // 1057 (0x421)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_MINUTE", // 1355 (0x54b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TO_UNIX_MICRO", // 1068 (0x42c)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_WEEK", // 1071 (0x42f)
        "",
        "",
        "",
        "",
        "",
        "SCALAR_REPLACEMENT", // 1367 (0x557)
        "",
        "",
        "",
        "DATE_DIFF_YEAR", // 1076 (0x434)
        "IN_REPLACEMENT", // 1076 (0x434)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MONTH", // 1081 (0x439)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_HOUR", // 1089 (0x441)
        "",
        "",
        "",
        "",
        "",
        "ROUND_EVEN", // 799 (0x31f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ABS", // 217 (0xd9)
        "ARRAY_SIZE", // 803 (0x323)
        "",
        "",
        "",
        "",
        "ARRAY_CONTAINS", // 1099 (0x44b)
        "",
        "",
        "",
        "",
        "",
        "GEO_TILE_X", // 809 (0x329)
        "",
        "GEO_TILE_Y", // 810 (0x32a)
        "",
        "DEGREES", // 518 (0x206)
        "",
        "SPLIT_PART", // 812 (0x32c)
        "",
        "",
        "",
        "RADIANS", // 521 (0x209)
        "",
        "LOG", // 229 (0xe5)
        "DATE_TRUNC_DAY", // 1108 (0x454)
        "TAN", // 230 (0xe6)
        "",
        "",
        "",
        "COS", // 232 (0xe8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIN", // 237 (0xed)
        "",
        "",
        "",
        "",
        "",
        "EXP", // 240 (0xf0)
        "",
        "DATE_TRUNC_DOW", // 1120 (0x460)
        "",
        "ARRAY_POSITION", // 1121 (0x461)
        "STRUCT_REPLACEMENT", // 1414 (0x586)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_MILLISECOND", // 1713 (0x6b1)
        "",
        "POW", // 249 (0xf9)
        "",
        "",
        "",
        "DATE_EXTRACT_MONTH", // 1423 (0x58f)
        "DATE_TRUNC_MICROSECOND", // 1716 (0x6b4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAR_LENGTH", // 842 (0x34a)
        "",
        "DATE_ADD_SECOND", // 1136 (0x470)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_FUZZY", // 1140 (0x474)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_QUARTER", // 1438 (0x59e)
        "",
        "CONTAINS_CI", // 853 (0x355)
        "",
        "",
        "",
        "TIME_BUCKET", // 855 (0x357)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MINUTE", // 1158 (0x486)
        "",
        "LOG2", // 280 (0x118)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MONTH", // 1162 (0x48a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LN1P", // 287 (0x11f)
        "",
        "GEO_TILE_ES", // 874 (0x36a)
        "",
        "CEIL", // 289 (0x121)
        "",
        "",
        "",
        "EXP2", // 291 (0x123)
        "MAKE_STRUCT", // 877 (0x36d)
        "",
        "",
    };
    static int values[586] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 296 (0x128)
        -1,
        12, // 1762 (0x6e2)
        -1,
        47, // 298 (0x12a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 303 (0x12f)
        46, // 303 (0x12f)
        -1,
        -1,
        -1,
        -1,
        75, // 1478 (0x5c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 309 (0x135)
        -1,
        118, // 1189 (0x4a5)
        -1,
        107, // 897 (0x381)
        -1,
        -1,
        -1,
        93, // 1192 (0x4a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        101, // 319 (0x13f)
        -1,
        1, // 320 (0x140)
        -1,
        96, // 614 (0x266)
        -1,
        6, // 615 (0x267)
        51, // 615 (0x267)
        -1,
        -1,
        -1,
        -1,
        58, // 911 (0x38f)
        -1,
        88, // 1205 (0x4b5)
        -1,
        100, // 913 (0x391)
        -1,
        37, // 328 (0x148)
        76, // 1500 (0x5dc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 334 (0x14e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 1217 (0x4c1)
        -1,
        31, // 339 (0x153)
        -1,
        109, // 1219 (0x4c3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 1516 (0x5ec)
        117, // 1223 (0x4c7)
        -1,
        -1,
        -1,
        -1,
        49, // 347 (0x15b)
        53, // 1519 (0x5ef)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 937 (0x3a9)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 940 (0x3ac)
        -1,
        116, // 648 (0x288)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        66, // 1239 (0x4d7)
        -1,
        -1,
        -1,
        61, // 1241 (0x4d9)
        -1,
        -1,
        -1,
        112, // 1243 (0x4db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 368 (0x170)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        78, // 1253 (0x4e5)
        -1,
        -1,
        -1,
        39, // 669 (0x29d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 382 (0x17e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 972 (0x3cc)
        79, // 1265 (0x4f1)
        -1,
        -1,
        80, // 1267 (0x4f3)
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 391 (0x187)
        -1,
        -1,
        -1,
        74, // 1858 (0x742)
        -1,
        -1,
        -1,
        -1,
        -1,
        73, // 1861 (0x745)
        -1,
        2, // 397 (0x18d)
        21, // 397 (0x18d)
        5, // 398 (0x18e)
        -1,
        91, // 1278 (0x4fe)
        -1,
        -1,
        -1,
        4, // 401 (0x191)
        23, // 401 (0x191)
        -1,
        -1,
        3, // 403 (0x193)
        -1,
        9, // 990 (0x3de)
        59, // 990 (0x3de)
        -1,
        -1,
        68, // 992 (0x3e0)
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 409 (0x199)
        62, // 995 (0x3e3)
        8, // 703 (0x2bf)
        -1,
        82, // 1583 (0x62f)
        -1,
        -1,
        -1,
        114, // 706 (0x2c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 714 (0x2ca)
        -1,
        57, // 1008 (0x3f0)
        -1,
        -1,
        -1,
        106, // 1010 (0x3f2)
        -1,
        64, // 1597 (0x63d)
        -1,
        -1,
        -1,
        18, // 720 (0x2d0)
        -1,
        63, // 1600 (0x640)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 1612 (0x64c)
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 1322 (0x52a)
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 446 (0x1be)
        -1,
        -1,
        -1,
        40, // 155 (0x9b)
        -1,
        33, // 156 (0x9c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        86, // 1333 (0x535)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        83, // 1337 (0x539)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 757 (0x2f5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        77, // 1350 (0x546)
        94, // 1057 (0x421)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 1355 (0x54b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        95, // 1068 (0x42c)
        -1,
        -1,
        -1,
        -1,
        -1,
        69, // 1071 (0x42f)
        -1,
        -1,
        -1,
        -1,
        -1,
        110, // 1367 (0x557)
        -1,
        -1,
        -1,
        72, // 1076 (0x434)
        108, // 1076 (0x434)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 1081 (0x439)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        67, // 1089 (0x441)
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 799 (0x31f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 217 (0xd9)
        103, // 803 (0x323)
        -1,
        -1,
        -1,
        -1,
        102, // 1099 (0x44b)
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 809 (0x329)
        -1,
        98, // 810 (0x32a)
        -1,
        41, // 518 (0x206)
        -1,
        17, // 812 (0x32c)
        -1,
        -1,
        -1,
        42, // 521 (0x209)
        -1,
        35, // 229 (0xe5)
        89, // 1108 (0x454)
        45, // 230 (0xe6)
        -1,
        -1,
        -1,
        44, // 232 (0xe8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 237 (0xed)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 240 (0xf0)
        -1,
        90, // 1120 (0x460)
        -1,
        104, // 1121 (0x461)
        111, // 1414 (0x586)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        85, // 1713 (0x6b1)
        -1,
        38, // 249 (0xf9)
        -1,
        -1,
        -1,
        81, // 1423 (0x58f)
        84, // 1716 (0x6b4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 842 (0x34a)
        -1,
        55, // 1136 (0x470)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 1140 (0x474)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 1438 (0x59e)
        -1,
        7, // 853 (0x355)
        -1,
        -1,
        -1,
        113, // 855 (0x357)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        56, // 1158 (0x486)
        -1,
        36, // 280 (0x118)
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 1162 (0x48a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 287 (0x11f)
        -1,
        99, // 874 (0x36a)
        -1,
        25, // 289 (0x121)
        -1,
        -1,
        -1,
        30, // 291 (0x123)
        115, // 877 (0x36d)
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

//check: name=check_snellerbuiltin_hash_sumN, dataset=snellerbuiltin, type=hash, hash=hash_sumN
void check_snellerbuiltin_hash_sumN() {
    assert(lookup_snellerbuiltin_hash_sumN("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash_sumN("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash_sumN("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash_sumN("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash_sumN("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash_sumN("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash_sumN("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash_sumN("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_hash_sumN("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash_sumN("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash_sumN("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash_sumN("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash_sumN("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash_sumN("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash_sumN("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash_sumN("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash_sumN("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash_sumN("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash_sumN("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash_sumN("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash_sumN("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash_sumN("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash_sumN("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash_sumN("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash_sumN("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash_sumN("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash_sumN("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash_sumN("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash_sumN("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash_sumN("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash_sumN("ROUND") == 21);
    assert(lookup_snellerbuiltin_hash_sumN("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash_sumN("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash_sumN("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash_sumN("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash_sumN("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash_sumN("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash_sumN("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash_sumN("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash_sumN("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash_sumN("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash_sumN("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash_sumN("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash_sumN("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash_sumN("PI") == 40);
    assert(lookup_snellerbuiltin_hash_sumN("LN") == 33);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash_sumN("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash_sumN("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash_sumN("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash_sumN("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash_sumN("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash_sumN("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash_sumN("ABS") == 19);
    assert(lookup_snellerbuiltin_hash_sumN("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash_sumN("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash_sumN("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash_sumN("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash_sumN("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash_sumN("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash_sumN("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash_sumN("LOG") == 35);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash_sumN("TAN") == 45);
    assert(lookup_snellerbuiltin_hash_sumN("COS") == 44);
    assert(lookup_snellerbuiltin_hash_sumN("SIN") == 43);
    assert(lookup_snellerbuiltin_hash_sumN("EXP") == 28);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash_sumN("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash_sumN("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash_sumN("POW") == 38);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash_sumN("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash_sumN("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash_sumN("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash_sumN("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash_sumN("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash_sumN("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash_sumN("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash_sumN("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash_sumN("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash_sumN("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash_sumN("MAKE_STRUCT") == 115);
}

//lookup: name=lookup_snellerbuiltin_hash_djb2, dataset=snellerbuiltin, type=hash, hash=hash_djb2
int lookup_snellerbuiltin_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 253) * 2;
    static std::string_view lookup[506] = {
        "DATE_EXTRACT_QUARTER", // 10391303716592721252 (0x903553acbcb49d64)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOG", // 197056139 (0xbbed68b)
        "",
        "ABS", // 197043743 (0xbbea61f)
        "",
        "",
        "",
        "DATE_ADD_MINUTE", // 13328913363030685824 (0xb8f9d0158566b880)
        "ASSERT_ION_TYPE", // 17485425673382455841 (0xf2a8b6021874ea21)
        "",
        "",
        "DATE_TRUNC_SECOND", // 17028317222956097453 (0xec50bc4b5cf6dfad)
        "",
        "GEO_TILE_X", // 8397980168744849320 (0x748b9e7814cfcfa8)
        "",
        "DATE_ADD_DAY", // 14104530590385397196 (0xc3bd5bd7cb8d5dcc)
        "GEO_TILE_Y", // 8397980168744849321 (0x748b9e7814cfcfa9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_CI", // 254481952707440575 (0x38819fcd8dfefbf)
        "CBRT", // 6502515444 (0x1839482f4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXP", // 197048822 (0xbbeb9f6)
        "",
        "LOG10", // 214594137036 (0x31f6ceabcc)
        "",
        "SUBSTRING", // 254501789077841354 (0x3882c075cafa5ca)
        "",
        "",
        "",
        "DATE_DIFF_WEEK", // 12142748037306013706 (0xa883b50140b2580a)
        "",
        "DATE_DIFF_SECOND", // 15583855850053362330 (0xd844fa542d52e29a)
        "DATE_DIFF_DAY", // 4280907774341581468 (0x3b68d6f085d68a9c)
        "CONTAINS_CI", // 426520362093206995 (0x5eb4e0270095dd3)
        "",
        "",
        "",
        "DATE_TRUNC_MILLISECOND", // 6328133726100264804 (0x57d20c1893601764)
        "LIST_REPLACEMENT", // 5547522499450210708 (0x4cfcc2523b378994)
        "DATE_TRUNC_MONTH", // 15608800218572467831 (0xd89d99198e0d2e77)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEO_HASH", // 7711643864339751 (0x1b65b3012b1527)
        "",
        "POW_UINT", // 7712040658565118 (0x1b660f63f277fe)
        "MAKE_LIST", // 254492509345418274 (0x3882396c1880c22)
        "CHAR_LENGTH", // 426177152004036936 (0x5ea15dc9c969948)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ROUND_EVEN", // 8398504992314845662 (0x748d7bcb174569de)
        "",
        "",
        "",
        "",
        "",
        "EXP10", // 214586168823 (0x31f65515f7)
        "",
        "",
        "",
        "CONTAINS", // 7711486252824008 (0x1b658e4eca35c8)
        "",
        "SPLIT_PART", // 8398552420811078379 (0x748da6ede5f0faeb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_QUARTER", // 15579027290312916914 (0xd833d2c78137bfb2)
        "",
        "ATAN", // 6502462605 (0x18393b48d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WIDTH_BUCKET", // 15076360816867906662 (0xd139fe48f3079466)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_MICROSECOND", // 6328121331882166311 (0x57d200d2d2688827)
        "",
        "",
        "",
        "",
        "",
        "SCALAR_REPLACEMENT", // 6413607403103045390 (0x5901b5f3cec5c70e)
        "",
        "",
        "",
        "DATE_EXTRACT_DOW", // 15586103763095204938 (0xd84cf6cb37ab344a)
        "",
        "",
        "",
        "DATE_ADD_SECOND", // 13328913363260352458 (0xb8f9d015931727ca)
        "DATE_EXTRACT_DOY", // 15586103763095204940 (0xd84cf6cb37ab344c)
        "GEO_TILE_ES", // 432184462936752776 (0x5ff6d7aaec9c288)
        "",
        "",
        "",
        "POW", // 197060511 (0xbbee79f)
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_HOUR", // 16279334191984013086 (0xe1ebd0322d13ef1e)
        "",
        "ARRAY_SIZE", // 8397720072483787554 (0x748ab1e9b3905322)
        "TABLE_PATTERN", // 12493116991470536974 (0xad6077b65dff890e)
        "",
        "",
        "",
        "",
        "RADIANS", // 233700213470411 (0xd48c923534cb)
        "COS", // 197046350 (0xbbeb04e)
        "SQRT", // 6503106771 (0x1839d88d3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY", // 14179617961067983931 (0xc4c81f68a434b43b)
        "LN", // 5971395 (0x5b1dc3)
        "IN_REPLACEMENT", // 14453860517602301743 (0xc8966d8f98ba972f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TO_UNIX_EPOCH", // 13245551708154701053 (0xb7d1a719c2a124fd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIN", // 197063571 (0xbbef393)
        "",
        "DATE_EXTRACT_YEAR", // 16279334191984612465 (0xe1ebd0322d1d1471)
        "",
        "IN_SUBQUERY", // 435687316407472319 (0x60bdf4e4f9c50bf)
        "",
        "",
        "",
        "PARTITION_VALUE", // 2647146771886283199 (0x24bc8df6be9a99bf)
        "",
        "",
        "",
        "LEAST", // 214593772290 (0x31f6c91b02)
        "",
        "",
        "",
        "CONTAINS_FUZZY", // 17064671364656028111 (0xecd1e431931a59cf)
        "",
        "",
        "",
        "",
        "",
        "SIGN", // 6503097690 (0x1839d655a)
        "",
        "",
        "",
        "",
        "",
        "HASH_REPLACEMENT", // 5911198747805815292 (0x5208cbf137b311fc)
        "",
        "",
        "",
        "EXP2", // 6502611176 (0x18395f8e8)
        "DATE_ADD_MILLISECOND", // 11515510741001238945 (0x9fcf5001d492f9a1)
        "DATE_EXTRACT_DAY", // 15586103763095204478 (0xd84cf6cb37ab327e)
        "",
        "",
        "",
        "DATE_TRUNC_QUARTER", // 8532146144305640437 (0x766845b6870e73f5)
        "",
        "CONTAINS_FUZZY_UNICODE", // 8637819180097755317 (0x77dfb2c777c858b5)
        "",
        "TRIM", // 6503143493 (0x1839e1845)
        "DATE_DIFF_MONTH", // 13329059683186378692 (0xb8fa5529564e07c4)
        "DATE_ADD_HOUR", // 4280907639979476012 (0x3b68d6d13d3b842c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ATAN2", // 214581266015 (0x31f60a465f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RTRIM", // 214601445047 (0x31f73e2eb7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UPPER", // 214604856757 (0x31f7723db5)
        "",
        "ARRAY_CONTAINS", // 4395565058497683494 (0x3d002f21cadfa026)
        "",
        "",
        "",
        "DATE_TRUNC_DOW", // 12142770943062075995 (0xa883c9d66a266a5b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_YEAR", // 4280907639980075391 (0x3b68d6d13d44a97f)
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_MILLISECOND", // 10143496006529671251 (0x8cc4efe019cb6053)
        "",
        "DATE_EXTRACT_MINUTE", // 873880235899463666 (0xc20a571cd05a7f2)
        "",
        "DATE_ADD_MICROSECOND", // 11515498346783140452 (0x9fcf44bc139b6a64)
        "",
        "CONCAT", // 7081254575457 (0x670bba9dd61)
        "HYPOT", // 214589763549 (0x31f68befdd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY_POSITION", // 4395565612720756860 (0x3d002fa2d524987c)
        "",
        "",
        "",
        "DATE_DIFF_HOUR", // 12142748037305486076 (0xa883b50140aa4afc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BIT_COUNT", // 254477392405808304 (0x38815d711b744b0)
        "GREATEST", // 7711660226927400 (0x1b65b6d0745b28)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_FUZZY_UNICODE", // 8867295453479984929 (0x7b0ef63be71c5f21)
        "TAN", // 197064396 (0xbbef6cc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "STRUCT_REPLACEMENT", // 3453491471633002269 (0x2fed44323186af1d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_YEAR", // 12142748037306085455 (0xa883b50140b3704f)
        "GEO_DISTANCE", // 14262086595308421774 (0xc5ed1c31d538028e)
        "DATE_EXTRACT_MICROSECOND", // 10143483612311572758 (0x8cc4e49a58d3d116)
        "",
        "LOWER", // 214594155154 (0x31f6cef292)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MAKE_STRUCT", // 441181571804186475 (0x61f644d54d6476b)
        "",
        "DATE_TRUNC_DAY", // 12142770943062075535 (0xa883c9d66a26688f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OCTET_LENGTH", // 14663556490261749417 (0xcb7f6aefe1ecdea9)
        "DEGREES", // 233682293345672 (0xd4886615cd88)
        "",
        "",
        "",
        "",
        "",
        "",
        "CEIL", // 6502518406 (0x183948e86)
        "",
        "DATE_TRUNC_MINUTE", // 17028317222726430819 (0xec50bc4b4f467063)
        "",
        "",
        "",
        "",
        "",
        "LN1P", // 6502850852 (0x18399a124)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MILLISECOND", // 10424802640765646449 (0x90ac56c4d063f671)
        "",
        "TIME_BUCKET", // 452276728728824085 (0x646cf49dc0ea915)
        "",
        "",
        "",
        "",
        "",
        "TRUNC", // 214603748437 (0x31f7615455)
        "",
        "ROUND", // 214601268785 (0x31f73b7e31)
        "",
        "",
        "",
        "DATE_EXTRACT_SECOND", // 873880236129130300 (0xc20a571dab6173c)
        "DATE_EXTRACT_MONTH", // 2262450197901357094 (0x1f65d677cfec3026)
        "FLOOR", // 214586923435 (0x31f66099ab)
        "EXPM1", // 214586169748 (0x31f6551994)
        "LOG2", // 6502852637 (0x18399a81d)
        "",
        "PI", // 5971522 (0x5b1e42)
        "",
        "",
        "",
        "DATE_DIFF_MINUTE", // 15583855849823695696 (0xd844fa541fa27350)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_QUARTER", // 16205153059644036226 (0xe0e444d962ead482)
        "",
        "SIZE", // 6503098308 (0x1839d67c4)
        "",
        "TO_UNIX_MICRO", // 13245551708163924296 (0xb7d1a719c32de148)
        "",
        "",
        "",
        "ACOS", // 6502444559 (0x183936e0f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_HOUR", // 13329815573148067663 (0xb8fd04a3aef5e74f)
        "",
        "LTRIM", // 214594329521 (0x31f6d19bb1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IS_SUBNET_OF", // 14385339336237080809 (0xc7a2fde8d5dd60e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MICROSECOND", // 10424790246547547956 (0x90ac4b7f0f6c6734)
        "",
        "",
        "",
        "",
        "",
        "TABLE_GLOB", // 8398577313268838388 (0x748dbd91a00b2ff4)
        "",
        "ASIN", // 6502461780 (0x18393b154)
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MONTH", // 12142743603361769204 (0xa883b0f8e50666f4)
        "",
        "DATE_ADD_WEEK", // 4280907639980003642 (0x3b68d6d13d43913a)
        "",
        "",
        "",
        "TYPE_BIT", // 7712223742586601 (0x1b663a049aeee9)
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_YEAR", // 13329815573148667042 (0xb8fd04a3aeff0ca2)
        "",
    };
    static int values[506] = {
        82, // 10391303716592721252 (0x903553acbcb49d64)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 197056139 (0xbbed68b)
        -1,
        19, // 197043743 (0xbbea61f)
        -1,
        -1,
        -1,
        56, // 13328913363030685824 (0xb8f9d0158566b880)
        117, // 17485425673382455841 (0xf2a8b6021874ea21)
        -1,
        -1,
        86, // 17028317222956097453 (0xec50bc4b5cf6dfad)
        -1,
        97, // 8397980168744849320 (0x748b9e7814cfcfa8)
        -1,
        58, // 14104530590385397196 (0xc3bd5bd7cb8d5dcc)
        98, // 8397980168744849321 (0x748b9e7814cfcfa9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 254481952707440575 (0x38819fcd8dfefbf)
        27, // 6502515444 (0x1839482f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 197048822 (0xbbeb9f6)
        -1,
        37, // 214594137036 (0x31f6ceabcc)
        -1,
        16, // 254501789077841354 (0x3882c075cafa5ca)
        -1,
        -1,
        -1,
        69, // 12142748037306013706 (0xa883b50140b2580a)
        -1,
        65, // 15583855850053362330 (0xd844fa542d52e29a)
        68, // 4280907774341581468 (0x3b68d6f085d68a9c)
        7, // 426520362093206995 (0x5eb4e0270095dd3)
        -1,
        -1,
        -1,
        85, // 6328133726100264804 (0x57d20c1893601764)
        112, // 5547522499450210708 (0x4cfcc2523b378994)
        91, // 15608800218572467831 (0xd89d99198e0d2e77)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        96, // 7711643864339751 (0x1b65b3012b1527)
        -1,
        39, // 7712040658565118 (0x1b660f63f277fe)
        114, // 254492509345418274 (0x3882396c1880c22)
        14, // 426177152004036936 (0x5ea15dc9c969948)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 8398504992314845662 (0x748d7bcb174569de)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 214586168823 (0x31f65515f7)
        -1,
        -1,
        -1,
        6, // 7711486252824008 (0x1b658e4eca35c8)
        -1,
        17, // 8398552420811078379 (0x748da6ede5f0faeb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 15579027290312916914 (0xd833d2c78137bfb2)
        -1,
        48, // 6502462605 (0x18393b48d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 15076360816867906662 (0xd139fe48f3079466)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        84, // 6328121331882166311 (0x57d200d2d2688827)
        -1,
        -1,
        -1,
        -1,
        -1,
        110, // 6413607403103045390 (0x5901b5f3cec5c70e)
        -1,
        -1,
        -1,
        79, // 15586103763095204938 (0xd84cf6cb37ab344a)
        -1,
        -1,
        -1,
        55, // 13328913363260352458 (0xb8f9d015931727ca)
        80, // 15586103763095204940 (0xd84cf6cb37ab344c)
        99, // 432184462936752776 (0x5ff6d7aaec9c288)
        -1,
        -1,
        -1,
        38, // 197060511 (0xbbee79f)
        -1,
        -1,
        -1,
        -1,
        -1,
        77, // 16279334191984013086 (0xe1ebd0322d13ef1e)
        -1,
        103, // 8397720072483787554 (0x748ab1e9b3905322)
        106, // 12493116991470536974 (0xad6077b65dff890e)
        -1,
        -1,
        -1,
        -1,
        42, // 233700213470411 (0xd48c923534cb)
        44, // 197046350 (0xbbeb04e)
        26, // 6503106771 (0x1839d88d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 14179617961067983931 (0xc4c81f68a434b43b)
        33, // 5971395 (0x5b1dc3)
        108, // 14453860517602301743 (0xc8966d8f98ba972f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        94, // 13245551708154701053 (0xb7d1a719c2a124fd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 197063571 (0xbbef393)
        -1,
        83, // 16279334191984612465 (0xe1ebd0322d1d1471)
        -1,
        107, // 435687316407472319 (0x60bdf4e4f9c50bf)
        -1,
        -1,
        -1,
        118, // 2647146771886283199 (0x24bc8df6be9a99bf)
        -1,
        -1,
        -1,
        50, // 214593772290 (0x31f6c91b02)
        -1,
        -1,
        -1,
        11, // 17064671364656028111 (0xecd1e431931a59cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 6503097690 (0x1839d655a)
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 5911198747805815292 (0x5208cbf137b311fc)
        -1,
        -1,
        -1,
        30, // 6502611176 (0x18395f8e8)
        54, // 11515510741001238945 (0x9fcf5001d492f9a1)
        78, // 15586103763095204478 (0xd84cf6cb37ab327e)
        -1,
        -1,
        -1,
        92, // 8532146144305640437 (0x766845b6870e73f5)
        -1,
        12, // 8637819180097755317 (0x77dfb2c777c858b5)
        -1,
        1, // 6503143493 (0x1839e1845)
        70, // 13329059683186378692 (0xb8fa5529564e07c4)
        57, // 4280907639979476012 (0x3b68d6d13d3b842c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 214581266015 (0x31f60a465f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 214601445047 (0x31f73e2eb7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 214604856757 (0x31f7723db5)
        -1,
        102, // 4395565058497683494 (0x3d002f21cadfa026)
        -1,
        -1,
        -1,
        90, // 12142770943062075995 (0xa883c9d66a266a5b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        62, // 4280907639980075391 (0x3b68d6d13d44a97f)
        -1,
        -1,
        -1,
        -1,
        -1,
        74, // 10143496006529671251 (0x8cc4efe019cb6053)
        -1,
        76, // 873880235899463666 (0xc20a571cd05a7f2)
        -1,
        53, // 11515498346783140452 (0x9fcf44bc139b6a64)
        -1,
        0, // 7081254575457 (0x670bba9dd61)
        32, // 214589763549 (0x31f68befdd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 4395565612720756860 (0x3d002fa2d524987c)
        -1,
        -1,
        -1,
        67, // 12142748037305486076 (0xa883b50140aa4afc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 254477392405808304 (0x38815d711b744b0)
        51, // 7711660226927400 (0x1b65b6d0745b28)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 8867295453479984929 (0x7b0ef63be71c5f21)
        45, // 197064396 (0xbbef6cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        111, // 3453491471633002269 (0x2fed44323186af1d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 12142748037306085455 (0xa883b50140b3704f)
        100, // 14262086595308421774 (0xc5ed1c31d538028e)
        73, // 10143483612311572758 (0x8cc4e49a58d3d116)
        -1,
        5, // 214594155154 (0x31f6cef292)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 441181571804186475 (0x61f644d54d6476b)
        -1,
        89, // 12142770943062075535 (0xa883c9d66a26688f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 14663556490261749417 (0xcb7f6aefe1ecdea9)
        41, // 233682293345672 (0xd4886615cd88)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 6502518406 (0x183948e86)
        -1,
        87, // 17028317222726430819 (0xec50bc4b4f467063)
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 6502850852 (0x18399a124)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 10424802640765646449 (0x90ac56c4d063f671)
        -1,
        113, // 452276728728824085 (0x646cf49dc0ea915)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 214603748437 (0x31f7615455)
        -1,
        21, // 214601268785 (0x31f73b7e31)
        -1,
        -1,
        -1,
        75, // 873880236129130300 (0xc20a571dab6173c)
        81, // 2262450197901357094 (0x1f65d677cfec3026)
        24, // 214586923435 (0x31f66099ab)
        29, // 214586169748 (0x31f6551994)
        36, // 6502852637 (0x18399a81d)
        -1,
        40, // 5971522 (0x5b1e42)
        -1,
        -1,
        -1,
        66, // 15583855849823695696 (0xd844fa541fa27350)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 16205153059644036226 (0xe0e444d962ead482)
        -1,
        101, // 6503098308 (0x1839d67c4)
        -1,
        95, // 13245551708163924296 (0xb7d1a719c32de148)
        -1,
        -1,
        -1,
        47, // 6502444559 (0x183936e0f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        88, // 13329815573148067663 (0xb8fd04a3aef5e74f)
        -1,
        2, // 214594329521 (0x31f6d19bb1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 14385339336237080809 (0xc7a2fde8d5dd60e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        63, // 10424790246547547956 (0x90ac4b7f0f6c6734)
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 8398577313268838388 (0x748dbd91a00b2ff4)
        -1,
        46, // 6502461780 (0x18393b154)
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 12142743603361769204 (0xa883b0f8e50666f4)
        -1,
        59, // 4280907639980003642 (0x3b68d6d13d43913a)
        -1,
        -1,
        -1,
        116, // 7712223742586601 (0x1b663a049aeee9)
        -1,
        -1,
        -1,
        -1,
        -1,
        93, // 13329815573148667042 (0xb8fd04a3aeff0ca2)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_snellerbuiltin_hash_djb2, dataset=snellerbuiltin, type=hash, hash=hash_djb2
void check_snellerbuiltin_hash_djb2() {
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash_djb2("LOG") == 35);
    assert(lookup_snellerbuiltin_hash_djb2("ABS") == 19);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash_djb2("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash_djb2("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash_djb2("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash_djb2("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash_djb2("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash_djb2("EXP") == 28);
    assert(lookup_snellerbuiltin_hash_djb2("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash_djb2("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash_djb2("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash_djb2("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash_djb2("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash_djb2("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash_djb2("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash_djb2("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash_djb2("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash_djb2("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash_djb2("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash_djb2("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash_djb2("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash_djb2("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash_djb2("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash_djb2("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash_djb2("POW") == 38);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash_djb2("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash_djb2("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash_djb2("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash_djb2("COS") == 44);
    assert(lookup_snellerbuiltin_hash_djb2("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash_djb2("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash_djb2("LN") == 33);
    assert(lookup_snellerbuiltin_hash_djb2("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash_djb2("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash_djb2("SIN") == 43);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash_djb2("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash_djb2("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash_djb2("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash_djb2("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash_djb2("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash_djb2("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash_djb2("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash_djb2("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash_djb2("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash_djb2("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash_djb2("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash_djb2("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash_djb2("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash_djb2("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash_djb2("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash_djb2("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash_djb2("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash_djb2("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash_djb2("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash_djb2("TAN") == 45);
    assert(lookup_snellerbuiltin_hash_djb2("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash_djb2("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash_djb2("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash_djb2("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash_djb2("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash_djb2("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash_djb2("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash_djb2("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash_djb2("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash_djb2("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash_djb2("ROUND") == 21);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash_djb2("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash_djb2("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash_djb2("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash_djb2("PI") == 40);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash_djb2("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash_djb2("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_hash_djb2("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash_djb2("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash_djb2("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash_djb2("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash_djb2("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash_djb2("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash_djb2("DATE_TRUNC_YEAR") == 93);
}

//lookup: name=lookup_snellerbuiltin_hash_sdb, dataset=snellerbuiltin, type=hash, hash=hash_sdb
int lookup_snellerbuiltin_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 1151) * 1;
    static std::string_view lookup[1151] = {
        "",
        "",
        "",
        "RADIANS", // 14361094003356682226 (0xc74cdae8601147f2)
        "TO_UNIX_EPOCH", // 7598257510370282290 (0x69726ef2c9908b32)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GREATEST", // 15773407118129015477 (0xdae66633edb2aab5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_HOUR", // 13392177611847405649 (0xb9da92954b1a9051)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXP", // 296385643461 (0x4501f603c5)
        "SIGN", // 23365945120394357 (0x5303340abe0c75)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_SECOND", // 210009554388546215 (0x2ea1a93b8c472a7)
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_MINUTE", // 11861741136847077055 (0xa49d5eb7bf687ebf)
        "",
        "",
        "",
        "",
        "PARTITION_VALUE", // 13688149332423946424 (0xbdf6134b7fa130b8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_DOW", // 8424187558589952349 (0x74e8b9f38704f15d)
        "DATE_DIFF_WEEK", // 13396400273390539093 (0xb9e993124c639155)
        "DATE_EXTRACT_DOY", // 8424187558589952351 (0x74e8b9f38704f15f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "POW_UINT", // 4610319032230611409 (0x3ffb24bbb95409d1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIST_REPLACEMENT", // 1450326564852863261 (0x142098539a5e111d)
        "TYPE_BIT", // 9060001527595809368 (0x7dbb97632cd83a58)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IN_REPLACEMENT", // 4062171122026837492 (0x385fbb1cf94275f4)
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_YEAR", // 1784188043348989444 (0x18c2b5928850d604)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OCTET_LENGTH", // 12017550858803958186 (0xa6c6ead5993351aa)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_QUARTER", // 6355882598319084959 (0x5834a18c5ae5559f)
        "SIN", // 356519707668 (0x53023b0414)
        "DATE_EXTRACT_MONTH", // 18398513890582626321 (0xff54a6e76b448011)
        "",
        "",
        "",
        "",
        "FLOOR", // 257850591369568816 (0x39411bf27b52230)
        "",
        "",
        "STRUCT_REPLACEMENT", // 13487235492357557160 (0xbb2c4938cc034ba8)
        "",
        "",
        "",
        "",
        "CBRT", // 18861696922618541 (0x43029d08ef0aad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEO_TILE_ES", // 2226099263607414429 (0x1ee4b17c62141e9d)
        "",
        "DATE_TRUNC_DAY", // 10468208584408736396 (0x91468c3e9c60a28c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TABLE_GLOB", // 10730693616100324229 (0x94eb14fd7d363385)
        "",
        "",
        "DATE_EXTRACT_HOUR", // 1779402354539746511 (0x18b1b50386d5d4cf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_YEAR", // 4622735962007726601 (0x402741dd79e4ea09)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY_SIZE", // 18209932659640676355 (0xfcb6ad4609aab003)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ABS", // 279202759522 (0x4101c80362)
        "",
        "",
        "",
        "",
        "",
        "",
        "TRUNC", // 306830742122538852 (0x44214ef2e622764)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MILLISECOND", // 17881794999333731728 (0xf828e5cf61a4bd90)
        "DATE_EXTRACT_MILLISECOND", // 12441474431809281530 (0xaca8ff13f618ddfa)
        "EXP2", // 19424818686790529 (0x4502c509a70b81)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_FUZZY", // 7435717225641275042 (0x6730f96bac99eea2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RTRIM", // 300637893190821592 (0x42c14922da926d8)
        "DATE_TRUNC_HOUR", // 4617950273198483668 (0x4016414e7869e8d4)
        "ARRAY_POSITION", // 4826421933058994095 (0x42fae52d3822afaf)
        "",
        "PI", // 5243193 (0x500139)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MAKE_STRUCT", // 10353466357352905406 (0x8faee6cc07fa3abe)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXP10", // 257850827605353136 (0x39411f6287522b0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ATAN2", // 243212982020743378 (0x36010eb261c20d2)
        "",
        "DATE_TRUNC_MILLISECOND", // 17916192019899409585 (0xf8a319b7d1cae4b1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEO_TILE_X", // 11292449720196993 (0x281e6c56375f81)
        "GEO_TILE_Y", // 11292449720196994 (0x281e6c56375f82)
        "DATE_TRUNC_DOW", // 10468208584409653940 (0x91468c3e9c6ea2b4)
        "",
        "",
        "SPLIT_PART", // 3516280698931888860 (0x30cc56aa6665c2dc)
        "",
        "",
        "ASIN", // 18298742676785903 (0x41029c09160aef)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MONTH", // 16628218942442055093 (0xe6c34d072fae25b5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LOG2", // 21395375460256722 (0x4c02fb0a250bd2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WIDTH_BUCKET", // 8562351859003072415 (0x76d395a685c89f9f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_MINUTE", // 4790716025198555884 (0x427c0ad7b5bb32ec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_SECOND", // 11997136179916145083 (0xa67e63cac5e381bb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_DAY", // 1768630648417191179 (0x188b703441c6850b)
        "",
        "DATE_DIFF_MINUTE", // 4952972185898522193 (0x44bc7df60adf1651)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DEGREES", // 12347073185826416079 (0xab599da518ef25cf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ROUND_EVEN", // 8429486527813101487 (0x74fb8d55f13da7af)
        "",
        "",
        "",
        "",
        "",
        "SUBSTRING", // 10813457272751806225 (0x96111e18f03c5711)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TABLE_PATTERN", // 10763704482648524131 (0x95605c32cb8b8563)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UPPER", // 309645625034614598 (0x44c150e2e712746)
        "",
        "",
        "",
        "SQRT", // 23365979483999460 (0x53033c0af90ce4)
        "",
        "",
        "",
        "",
        "COS", // 287794332571 (0x4301e1039b)
        "DATE_ADD_YEAR", // 17093447161771025040 (0xed381fa0f0456290)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LN", // 4981042 (0x4c0132)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LEAST", // 276147525737521897 (0x3d512b6293022e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS_CI", // 11195433517409491246 (0x9b5e2b77d7b1d92e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONTAINS", // 12412225222062869663 (0xac411513a1338c9f)
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MILLISECOND", // 8000036259923332606 (0x6f05d697a6f98dfe)
        "",
        "",
        "",
        "",
        "DATE_DIFF_MICROSECOND", // 7554977789755136831 (0x68d8ac4594521b3f)
        "DATE_EXTRACT_MICROSECOND", // 2114657222230686633 (0x1d58c58a28c63ba9)
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_QUARTER", // 6384125541002219241 (0x5898f85ae0ef8ee9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TO_UNIX_MICRO", // 7623310316641356997 (0x69cb7057cbfa8cc5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_HOUR", // 17088661472961782107 (0xed271f11eeca615b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MINUTE", // 74614511319478187 (0x1091580b2496fab)
        "",
        "",
        "",
        "",
        "",
        "TIME_BUCKET", // 8494802177444090364 (0x75e39992afc511fc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IN_SUBQUERY", // 6318145110721614386 (0x57ae8f80d3eed232)
        "",
        "GEO_HASH", // 14148683785981826872 (0xc45a38f0bec69738)
        "",
        "",
        "TAN", // 360814543877 (0x5402390405)
        "",
        "",
        "DATE_TRUNC_MICROSECOND", // 7589374810320814688 (0x6952e02e04784260)
        "DATE_ADD_WEEK", // 17092884134504915551 (0xed361f8ef013625f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EXPM1", // 257850827607188229 (0x39411f628912305)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEO_DISTANCE", // 6919008004264942535 (0x6005411f144bdbc7)
        "",
        "",
        "LOG", // 326452577248 (0x4c021703e0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HYPOT", // 268266136208024636 (0x3b912a129f2243c)
        "",
        "CHAR_LENGTH", // 9771999277546124535 (0x879d1d919382b4f7)
        "",
        "IS_SUBNET_OF", // 11145286524834345516 (0x9aac030b48b2f22c)
        "",
        "LN1P", // 21395371163454373 (0x4c02fa0a090ba5)
        "",
        "",
        "",
        "",
        "CONTAINS_FUZZY_UNICODE", // 612827449733771152 (0x881335191fd6f90)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LTRIM", // 280370303255782642 (0x3e4134e2b2124f2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ACOS", // 18298673951410806 (0x41028c08bc0a76)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CEIL", // 18861709808110245 (0x4302a008f80aa5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_QUARTER", // 2640533896302584237 (0x24a50f96aa7e61ad)
        "POW", // 343634019348 (0x50022f0414)
        "",
        "",
        "",
        "",
        "",
        "",
        "ARRAY_CONTAINS", // 12804259763239533917 (0xb1b1de6a2fb83d5d)
        "",
        "",
        "",
        "EQUALS_FUZZY_UNICODE", // 2819987623422990024 (0x27229bcd752016c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_TRUNC_QUARTER", // 16020697013638441840 (0xde54f30d7814ab70)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONCAT", // 1986186759295231044 (0x1b905a5595606444)
        "EQUALS_FUZZY", // 3912218371714939610 (0x364afde199d37ada)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_MICROSECOND", // 16119963124054289325 (0xdfb59d0dd9a6ebad)
        "",
        "",
        "",
        "",
        "",
        "",
        "BIT_COUNT", // 12889374516240283209 (0xb2e041d4e9797649)
        "LOG10", // 278962687839314851 (0x3df13162a4023a3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_ADD_DAY", // 2810096791577545401 (0x26ff7824b671cab9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ATAN", // 18298746971622112 (0x41029d09140ae0)
        "",
        "DATE_TRUNC_SECOND", // 4926111068267623912 (0x445d0feabc3635e8)
        "",
        "",
        "",
        "MAKE_LIST", // 9813289784592966075 (0x882fcf10e8a221bb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ASSERT_ION_TYPE", // 841806668301598254 (0xbaeb2b469abfe2e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_SECOND", // 5088367228967590221 (0x469d8309115a194d)
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_EXTRACT_DAY", // 8424187558589034805 (0x74e8b9f386f6f135)
        "TRIM", // 23647497411955942 (0x5403460b110ce6)
        "",
        "",
        "DATE_TRUNC_MONTH", // 129827431019559968 (0x1cd3d5c5405bc20)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIZE", // 23365945121639589 (0x5303340ad10ca5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUALS_CI", // 11741367675184410966 (0xa2f1b7b1309ef156)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SCALAR_REPLACEMENT", // 9424244330970099827 (0x82c9a44987f63073)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_YEAR", // 13396963300656648582 (0xb9eb93244c959186)
        "",
        "LOWER", // 278962756566394001 (0x3df13262ab42491)
        "",
        "",
        "",
        "",
        "",
        "DATE_DIFF_MONTH", // 13862365394864747159 (0xc06103e17394b297)
        "",
        "",
        "",
        "",
        "",
        "HASH_REPLACEMENT", // 68086925670292573 (0xf1e4b2ba6d1c5d)
        "",
        "ROUND", // 299230337911301746 (0x42714682d392672)
        "",
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
    static int values[1151] = {
        -1,
        -1,
        -1,
        42, // 14361094003356682226 (0xc74cdae8601147f2)
        94, // 7598257510370282290 (0x69726ef2c9908b32)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 15773407118129015477 (0xdae66633edb2aab5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        67, // 13392177611847405649 (0xb9da92954b1a9051)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 296385643461 (0x4501f603c5)
        20, // 23365945120394357 (0x5303340abe0c75)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 210009554388546215 (0x2ea1a93b8c472a7)
        -1,
        -1,
        -1,
        -1,
        76, // 11861741136847077055 (0xa49d5eb7bf687ebf)
        -1,
        -1,
        -1,
        -1,
        118, // 13688149332423946424 (0xbdf6134b7fa130b8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        79, // 8424187558589952349 (0x74e8b9f38704f15d)
        69, // 13396400273390539093 (0xb9e993124c639155)
        80, // 8424187558589952351 (0x74e8b9f38704f15f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 4610319032230611409 (0x3ffb24bbb95409d1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        112, // 1450326564852863261 (0x142098539a5e111d)
        116, // 9060001527595809368 (0x7dbb97632cd83a58)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        108, // 4062171122026837492 (0x385fbb1cf94275f4)
        -1,
        -1,
        -1,
        -1,
        83, // 1784188043348989444 (0x18c2b5928850d604)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 12017550858803958186 (0xa6c6ead5993351aa)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 6355882598319084959 (0x5834a18c5ae5559f)
        43, // 356519707668 (0x53023b0414)
        81, // 18398513890582626321 (0xff54a6e76b448011)
        -1,
        -1,
        -1,
        -1,
        24, // 257850591369568816 (0x39411bf27b52230)
        -1,
        -1,
        111, // 13487235492357557160 (0xbb2c4938cc034ba8)
        -1,
        -1,
        -1,
        -1,
        27, // 18861696922618541 (0x43029d08ef0aad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        99, // 2226099263607414429 (0x1ee4b17c62141e9d)
        -1,
        89, // 10468208584408736396 (0x91468c3e9c60a28c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 10730693616100324229 (0x94eb14fd7d363385)
        -1,
        -1,
        77, // 1779402354539746511 (0x18b1b50386d5d4cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        93, // 4622735962007726601 (0x402741dd79e4ea09)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        103, // 18209932659640676355 (0xfcb6ad4609aab003)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 279202759522 (0x4101c80362)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 306830742122538852 (0x44214ef2e622764)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 17881794999333731728 (0xf828e5cf61a4bd90)
        74, // 12441474431809281530 (0xaca8ff13f618ddfa)
        30, // 19424818686790529 (0x4502c509a70b81)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 7435717225641275042 (0x6730f96bac99eea2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 300637893190821592 (0x42c14922da926d8)
        88, // 4617950273198483668 (0x4016414e7869e8d4)
        104, // 4826421933058994095 (0x42fae52d3822afaf)
        -1,
        40, // 5243193 (0x500139)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 10353466357352905406 (0x8faee6cc07fa3abe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 257850827605353136 (0x39411f6287522b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 243212982020743378 (0x36010eb261c20d2)
        -1,
        85, // 17916192019899409585 (0xf8a319b7d1cae4b1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 11292449720196993 (0x281e6c56375f81)
        98, // 11292449720196994 (0x281e6c56375f82)
        90, // 10468208584409653940 (0x91468c3e9c6ea2b4)
        -1,
        -1,
        17, // 3516280698931888860 (0x30cc56aa6665c2dc)
        -1,
        -1,
        46, // 18298742676785903 (0x41029c09160aef)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 16628218942442055093 (0xe6c34d072fae25b5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 21395375460256722 (0x4c02fb0a250bd2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 8562351859003072415 (0x76d395a685c89f9f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 4790716025198555884 (0x427c0ad7b5bb32ec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        75, // 11997136179916145083 (0xa67e63cac5e381bb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 1768630648417191179 (0x188b703441c6850b)
        -1,
        66, // 4952972185898522193 (0x44bc7df60adf1651)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 12347073185826416079 (0xab599da518ef25cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 8429486527813101487 (0x74fb8d55f13da7af)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 10813457272751806225 (0x96111e18f03c5711)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        106, // 10763704482648524131 (0x95605c32cb8b8563)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 309645625034614598 (0x44c150e2e712746)
        -1,
        -1,
        -1,
        26, // 23365979483999460 (0x53033c0af90ce4)
        -1,
        -1,
        -1,
        -1,
        44, // 287794332571 (0x4301e1039b)
        62, // 17093447161771025040 (0xed381fa0f0456290)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 4981042 (0x4c0132)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 276147525737521897 (0x3d512b6293022e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 11195433517409491246 (0x9b5e2b77d7b1d92e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 12412225222062869663 (0xac411513a1338c9f)
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 8000036259923332606 (0x6f05d697a6f98dfe)
        -1,
        -1,
        -1,
        -1,
        63, // 7554977789755136831 (0x68d8ac4594521b3f)
        73, // 2114657222230686633 (0x1d58c58a28c63ba9)
        -1,
        -1,
        -1,
        -1,
        82, // 6384125541002219241 (0x5898f85ae0ef8ee9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        95, // 7623310316641356997 (0x69cb7057cbfa8cc5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        57, // 17088661472961782107 (0xed271f11eeca615b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        56, // 74614511319478187 (0x1091580b2496fab)
        -1,
        -1,
        -1,
        -1,
        -1,
        113, // 8494802177444090364 (0x75e39992afc511fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        107, // 6318145110721614386 (0x57ae8f80d3eed232)
        -1,
        96, // 14148683785981826872 (0xc45a38f0bec69738)
        -1,
        -1,
        45, // 360814543877 (0x5402390405)
        -1,
        -1,
        84, // 7589374810320814688 (0x6952e02e04784260)
        59, // 17092884134504915551 (0xed361f8ef013625f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 257850827607188229 (0x39411f628912305)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        100, // 6919008004264942535 (0x6005411f144bdbc7)
        -1,
        -1,
        35, // 326452577248 (0x4c021703e0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 268266136208024636 (0x3b912a129f2243c)
        -1,
        14, // 9771999277546124535 (0x879d1d919382b4f7)
        -1,
        15, // 11145286524834345516 (0x9aac030b48b2f22c)
        -1,
        34, // 21395371163454373 (0x4c02fa0a090ba5)
        -1,
        -1,
        -1,
        -1,
        12, // 612827449733771152 (0x881335191fd6f90)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 280370303255782642 (0x3e4134e2b2124f2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 18298673951410806 (0x41028c08bc0a76)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 18861709808110245 (0x4302a008f80aa5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 2640533896302584237 (0x24a50f96aa7e61ad)
        38, // 343634019348 (0x50022f0414)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        102, // 12804259763239533917 (0xb1b1de6a2fb83d5d)
        -1,
        -1,
        -1,
        10, // 2819987623422990024 (0x27229bcd752016c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 16020697013638441840 (0xde54f30d7814ab70)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 1986186759295231044 (0x1b905a5595606444)
        9, // 3912218371714939610 (0x364afde199d37ada)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 16119963124054289325 (0xdfb59d0dd9a6ebad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 12889374516240283209 (0xb2e041d4e9797649)
        37, // 278962687839314851 (0x3df13162a4023a3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 2810096791577545401 (0x26ff7824b671cab9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 18298746971622112 (0x41029d09140ae0)
        -1,
        86, // 4926111068267623912 (0x445d0feabc3635e8)
        -1,
        -1,
        -1,
        114, // 9813289784592966075 (0x882fcf10e8a221bb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        117, // 841806668301598254 (0xbaeb2b469abfe2e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 5088367228967590221 (0x469d8309115a194d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        78, // 8424187558589034805 (0x74e8b9f386f6f135)
        1, // 23647497411955942 (0x5403460b110ce6)
        -1,
        -1,
        91, // 129827431019559968 (0x1cd3d5c5405bc20)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        101, // 23365945121639589 (0x5303340ad10ca5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 11741367675184410966 (0xa2f1b7b1309ef156)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        110, // 9424244330970099827 (0x82c9a44987f63073)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 13396963300656648582 (0xb9eb93244c959186)
        -1,
        5, // 278962756566394001 (0x3df13262ab42491)
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 13862365394864747159 (0xc06103e17394b297)
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 68086925670292573 (0xf1e4b2ba6d1c5d)
        -1,
        21, // 299230337911301746 (0x42714682d392672)
        -1,
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

//check: name=check_snellerbuiltin_hash_sdb, dataset=snellerbuiltin, type=hash, hash=hash_sdb
void check_snellerbuiltin_hash_sdb() {
    assert(lookup_snellerbuiltin_hash_sdb("RADIANS") == 42);
    assert(lookup_snellerbuiltin_hash_sdb("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_hash_sdb("GREATEST") == 51);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_hash_sdb("EXP") == 28);
    assert(lookup_snellerbuiltin_hash_sdb("SIGN") == 20);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_hash_sdb("PARTITION_VALUE") == 118);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_hash_sdb("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_hash_sdb("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_hash_sdb("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_hash_sdb("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_hash_sdb("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_hash_sdb("SIN") == 43);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_hash_sdb("FLOOR") == 24);
    assert(lookup_snellerbuiltin_hash_sdb("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_hash_sdb("CBRT") == 27);
    assert(lookup_snellerbuiltin_hash_sdb("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_hash_sdb("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_hash_sdb("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_hash_sdb("ABS") == 19);
    assert(lookup_snellerbuiltin_hash_sdb("TRUNC") == 23);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_hash_sdb("EXP2") == 30);
    assert(lookup_snellerbuiltin_hash_sdb("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_hash_sdb("RTRIM") == 3);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_hash_sdb("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_hash_sdb("PI") == 40);
    assert(lookup_snellerbuiltin_hash_sdb("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_hash_sdb("EXP10") == 31);
    assert(lookup_snellerbuiltin_hash_sdb("ATAN2") == 49);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_hash_sdb("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_hash_sdb("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_hash_sdb("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_hash_sdb("ASIN") == 46);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_hash_sdb("LOG2") == 36);
    assert(lookup_snellerbuiltin_hash_sdb("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_hash_sdb("DEGREES") == 41);
    assert(lookup_snellerbuiltin_hash_sdb("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_hash_sdb("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_hash_sdb("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_hash_sdb("UPPER") == 4);
    assert(lookup_snellerbuiltin_hash_sdb("SQRT") == 26);
    assert(lookup_snellerbuiltin_hash_sdb("COS") == 44);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_hash_sdb("LN") == 33);
    assert(lookup_snellerbuiltin_hash_sdb("LEAST") == 50);
    assert(lookup_snellerbuiltin_hash_sdb("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_hash_sdb("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_hash_sdb("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_hash_sdb("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_hash_sdb("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_hash_sdb("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_hash_sdb("TAN") == 45);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_hash_sdb("EXPM1") == 29);
    assert(lookup_snellerbuiltin_hash_sdb("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_hash_sdb("LOG") == 35);
    assert(lookup_snellerbuiltin_hash_sdb("HYPOT") == 32);
    assert(lookup_snellerbuiltin_hash_sdb("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_hash_sdb("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_hash_sdb("LN1P") == 34);
    assert(lookup_snellerbuiltin_hash_sdb("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_hash_sdb("LTRIM") == 2);
    assert(lookup_snellerbuiltin_hash_sdb("ACOS") == 47);
    assert(lookup_snellerbuiltin_hash_sdb("CEIL") == 25);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_hash_sdb("POW") == 38);
    assert(lookup_snellerbuiltin_hash_sdb("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_hash_sdb("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_hash_sdb("CONCAT") == 0);
    assert(lookup_snellerbuiltin_hash_sdb("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_hash_sdb("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_hash_sdb("LOG10") == 37);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_hash_sdb("ATAN") == 48);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_hash_sdb("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_hash_sdb("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_hash_sdb("TRIM") == 1);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_hash_sdb("SIZE") == 101);
    assert(lookup_snellerbuiltin_hash_sdb("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_hash_sdb("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_hash_sdb("LOWER") == 5);
    assert(lookup_snellerbuiltin_hash_sdb("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_hash_sdb("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_hash_sdb("ROUND") == 21);
}
