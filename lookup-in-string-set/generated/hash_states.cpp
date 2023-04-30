
//lookup: name=lookup_states_hash1, dataset=states, type=hash, hash=hash1
int lookup_states_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 81) * 2;
    static constexpr const std::string_view lookup[162] = {
        "TENNESSEE", // 1377 (0x561)
        "",
        "MAINE", // 730 (0x2da)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW YORK", // 1224 (0x4c8)
        "",
        "NEBRASKA", // 1144 (0x478)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NORTH DAKOTA", // 1716 (0x6b4)
        "",
        "KENTUCKY", // 1312 (0x520)
        "",
        "",
        "",
        "OKLAHOMA", // 1152 (0x480)
        "RHODE ISLAND", // 1800 (0x708)
        "ALABAMA", // 910 (0x38e)
        "ARIZONA", // 910 (0x38e)
        "",
        "",
        "",
        "",
        "MONTANA", // 994 (0x3e2)
        "",
        "",
        "",
        "CALIFORNIA", // 1320 (0x528)
        "",
        "MICHIGAN", // 1240 (0x4d8)
        "TEXAS", // 835 (0x343)
        "MARYLAND", // 1160 (0x488)
        "",
        "WISCONSIN", // 1485 (0x5cd)
        "",
        "",
        "",
        "",
        "",
        "MISSISSIPPI", // 1650 (0x672)
        "WASHINGTON", // 1650 (0x672)
        "IDAHO", // 760 (0x2f8)
        "NEW MEXICO", // 1570 (0x622)
        "WEST VIRGINIA", // 1976 (0x7b8)
        "",
        "ILLINOIS", // 1248 (0x4e0)
        "",
        "COLORADO", // 1168 (0x490)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PENNSYLVANIA", // 1740 (0x6cc)
        "",
        "",
        "",
        "CONNECTICUT", // 1661 (0x67d)
        "",
        "",
        "",
        "DELAWARE", // 1096 (0x448)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH CAROLINA", // 2072 (0x818)
        "",
        "NEVADA", // 858 (0x35a)
        "NEW HAMPSHIRE", // 1911 (0x777)
        "",
        "",
        "ARKANSAS", // 1184 (0x4a0)
        "NEW JERSEY", // 1670 (0x686)
        "ALASKA", // 780 (0x30c)
        "OREGON", // 942 (0x3ae)
        "",
        "",
        "WYOMING", // 1106 (0x452)
        "",
        "FLORIDA", // 945 (0x3b1)
        "LOUISIANA", // 1269 (0x4f5)
        "MASSACHUSETTS", // 2080 (0x820)
        "",
        "VERMONT", // 1190 (0x4a6)
        "",
        "KANSAS", // 948 (0x3b4)
        "",
        "NORTH CAROLINA", // 2002 (0x7d2)
        "",
        "",
        "",
        "HAWAII", // 870 (0x366)
        "",
        "GEORGIA", // 952 (0x3b8)
        "UTAH", // 628 (0x274)
        "",
        "",
        "MINNESOTA", // 1278 (0x4fe)
        "",
        "",
        "",
        "OHIO", // 632 (0x278)
        "",
        "IOWA", // 552 (0x228)
        "MISSOURI", // 1200 (0x4b0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIRGINIA", // 1208 (0x4b8)
        "",
        "INDIANA", // 966 (0x3c6)
        "SOUTH DAKOTA", // 1776 (0x6f0)
        "",
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
    static constexpr const int values[162] = {
        41, // 1377 (0x561)
        -1,
        18, // 730 (0x2da)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 1224 (0x4c8)
        -1,
        26, // 1144 (0x478)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 1716 (0x6b4)
        -1,
        16, // 1312 (0x520)
        -1,
        -1,
        -1,
        35, // 1152 (0x480)
        38, // 1800 (0x708)
        0, // 910 (0x38e)
        2, // 910 (0x38e)
        -1,
        -1,
        -1,
        -1,
        25, // 994 (0x3e2)
        -1,
        -1,
        -1,
        4, // 1320 (0x528)
        -1,
        21, // 1240 (0x4d8)
        42, // 835 (0x343)
        19, // 1160 (0x488)
        -1,
        48, // 1485 (0x5cd)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 1650 (0x672)
        46, // 1650 (0x672)
        11, // 760 (0x2f8)
        30, // 1570 (0x622)
        47, // 1976 (0x7b8)
        -1,
        12, // 1248 (0x4e0)
        -1,
        5, // 1168 (0x490)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 1740 (0x6cc)
        -1,
        -1,
        -1,
        6, // 1661 (0x67d)
        -1,
        -1,
        -1,
        7, // 1096 (0x448)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 2072 (0x818)
        -1,
        27, // 858 (0x35a)
        28, // 1911 (0x777)
        -1,
        -1,
        3, // 1184 (0x4a0)
        29, // 1670 (0x686)
        1, // 780 (0x30c)
        36, // 942 (0x3ae)
        -1,
        -1,
        49, // 1106 (0x452)
        -1,
        8, // 945 (0x3b1)
        17, // 1269 (0x4f5)
        20, // 2080 (0x820)
        -1,
        44, // 1190 (0x4a6)
        -1,
        15, // 948 (0x3b4)
        -1,
        32, // 2002 (0x7d2)
        -1,
        -1,
        -1,
        10, // 870 (0x366)
        -1,
        9, // 952 (0x3b8)
        43, // 628 (0x274)
        -1,
        -1,
        22, // 1278 (0x4fe)
        -1,
        -1,
        -1,
        34, // 632 (0x278)
        -1,
        14, // 552 (0x228)
        24, // 1200 (0x4b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 1208 (0x4b8)
        -1,
        13, // 966 (0x3c6)
        40, // 1776 (0x6f0)
        -1,
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
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_states_hash1, dataset=states, type=hash, hash=hash1
void check_states_hash1() {
    assert(lookup_states_hash1("TENNESSEE") == 41);
    assert(lookup_states_hash1("MAINE") == 18);
    assert(lookup_states_hash1("NEW YORK") == 31);
    assert(lookup_states_hash1("NEBRASKA") == 26);
    assert(lookup_states_hash1("NORTH DAKOTA") == 33);
    assert(lookup_states_hash1("KENTUCKY") == 16);
    assert(lookup_states_hash1("OKLAHOMA") == 35);
    assert(lookup_states_hash1("RHODE ISLAND") == 38);
    assert(lookup_states_hash1("ALABAMA") == 0);
    assert(lookup_states_hash1("ARIZONA") == 2);
    assert(lookup_states_hash1("MONTANA") == 25);
    assert(lookup_states_hash1("CALIFORNIA") == 4);
    assert(lookup_states_hash1("MICHIGAN") == 21);
    assert(lookup_states_hash1("TEXAS") == 42);
    assert(lookup_states_hash1("MARYLAND") == 19);
    assert(lookup_states_hash1("WISCONSIN") == 48);
    assert(lookup_states_hash1("MISSISSIPPI") == 23);
    assert(lookup_states_hash1("WASHINGTON") == 46);
    assert(lookup_states_hash1("IDAHO") == 11);
    assert(lookup_states_hash1("NEW MEXICO") == 30);
    assert(lookup_states_hash1("WEST VIRGINIA") == 47);
    assert(lookup_states_hash1("ILLINOIS") == 12);
    assert(lookup_states_hash1("COLORADO") == 5);
    assert(lookup_states_hash1("PENNSYLVANIA") == 37);
    assert(lookup_states_hash1("CONNECTICUT") == 6);
    assert(lookup_states_hash1("DELAWARE") == 7);
    assert(lookup_states_hash1("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash1("NEVADA") == 27);
    assert(lookup_states_hash1("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash1("ARKANSAS") == 3);
    assert(lookup_states_hash1("NEW JERSEY") == 29);
    assert(lookup_states_hash1("ALASKA") == 1);
    assert(lookup_states_hash1("OREGON") == 36);
    assert(lookup_states_hash1("WYOMING") == 49);
    assert(lookup_states_hash1("FLORIDA") == 8);
    assert(lookup_states_hash1("LOUISIANA") == 17);
    assert(lookup_states_hash1("MASSACHUSETTS") == 20);
    assert(lookup_states_hash1("VERMONT") == 44);
    assert(lookup_states_hash1("KANSAS") == 15);
    assert(lookup_states_hash1("NORTH CAROLINA") == 32);
    assert(lookup_states_hash1("HAWAII") == 10);
    assert(lookup_states_hash1("GEORGIA") == 9);
    assert(lookup_states_hash1("UTAH") == 43);
    assert(lookup_states_hash1("MINNESOTA") == 22);
    assert(lookup_states_hash1("OHIO") == 34);
    assert(lookup_states_hash1("IOWA") == 14);
    assert(lookup_states_hash1("MISSOURI") == 24);
    assert(lookup_states_hash1("VIRGINIA") == 45);
    assert(lookup_states_hash1("INDIANA") == 13);
    assert(lookup_states_hash1("SOUTH DAKOTA") == 40);
}

//lookup: name=lookup_states_hash2, dataset=states, type=hash, hash=hash2
int lookup_states_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 73) * 2;
    static constexpr const std::string_view lookup[146] = {
        "",
        "",
        "ARKANSAS", // 5403 (0x151b)
        "",
        "CONNECTICUT", // 5623 (0x15f7)
        "NEW YORK", // 5842 (0x16d2)
        "SOUTH CAROLINA", // 5405 (0x151d)
        "WASHINGTON", // 6792 (0x1a88)
        "IOWA", // 4749 (0x128d)
        "VERMONT", // 7231 (0x1c3f)
        "INDIANA", // 4750 (0x128e)
        "SOUTH DAKOTA", // 5407 (0x151f)
        "HAWAII", // 5262 (0x148e)
        "WISCONSIN", // 6795 (0x1a8b)
        "",
        "",
        "MISSOURI", // 5629 (0x15fd)
        "",
        "GEORGIA", // 4608 (0x1200)
        "MISSISSIPPI", // 5630 (0x15fe)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OKLAHOMA", // 5127 (0x1407)
        "",
        "",
        "",
        "FLORIDA", // 4545 (0x11c1)
        "NORTH CAROLINA", // 5056 (0x13c0)
        "",
        "",
        "NORTH DAKOTA", // 5058 (0x13c2)
        "",
        "",
        "",
        "",
        "",
        "RHODE ISLAND", // 5572 (0x15c4)
        "",
        "NEBRASKA", // 5062 (0x13c6)
        "",
        "KANSAS", // 6231 (0x1857)
        "",
        "NEVADA", // 5064 (0x13c8)
        "",
        "DELAWARE", // 4700 (0x125c)
        "MICHIGAN", // 6014 (0x177e)
        "COLORADO", // 5285 (0x14a5)
        "PENNSYLVANIA", // 5212 (0x145c)
        "",
        "",
        "",
        "",
        "MINNESOTA", // 4996 (0x1384)
        "OREGON", // 6164 (0x1814)
        "",
        "",
        "TEXAS", // 6969 (0x1b39)
        "",
        "",
        "",
        "NEW MEXICO", // 6168 (0x1818)
        "",
        "WEST VIRGINIA", // 5658 (0x161a)
        "",
        "MONTANA", // 5002 (0x138a)
        "TENNESSEE", // 5805 (0x16ad)
        "",
        "",
        "KENTUCKY", // 6683 (0x1a1b)
        "OHIO", // 6245 (0x1865)
        "",
        "",
        "LOUISIANA", // 4933 (0x1345)
        "",
        "MASSACHUSETTS", // 6394 (0x18fa)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIRGINIA", // 5598 (0x15de)
        "WYOMING", // 6182 (0x1826)
        "",
        "",
        "",
        "",
        "",
        "",
        "CALIFORNIA", // 4361 (0x1109)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW HAMPSHIRE", // 5387 (0x150b)
        "",
        "",
        "",
        "MAINE", // 5316 (0x14c4)
        "",
        "MARYLAND", // 5244 (0x147c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ILLINOIS", // 6051 (0x17a3)
        "UTAH", // 6124 (0x17ec)
        "",
        "",
        "",
        "",
        "IDAHO", // 5762 (0x1682)
        "",
        "ALABAMA", // 4230 (0x1086)
        "ARIZONA", // 4230 (0x1086)
        "ALASKA", // 4231 (0x1087)
        "NEW JERSEY", // 6932 (0x1b14)
        "",
        "",
        "",
        "",
    };
    static constexpr const int values[146] = {
        -1,
        -1,
        3, // 5403 (0x151b)
        -1,
        6, // 5623 (0x15f7)
        31, // 5842 (0x16d2)
        39, // 5405 (0x151d)
        46, // 6792 (0x1a88)
        14, // 4749 (0x128d)
        44, // 7231 (0x1c3f)
        13, // 4750 (0x128e)
        40, // 5407 (0x151f)
        10, // 5262 (0x148e)
        48, // 6795 (0x1a8b)
        -1,
        -1,
        24, // 5629 (0x15fd)
        -1,
        9, // 4608 (0x1200)
        23, // 5630 (0x15fe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 5127 (0x1407)
        -1,
        -1,
        -1,
        8, // 4545 (0x11c1)
        32, // 5056 (0x13c0)
        -1,
        -1,
        33, // 5058 (0x13c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 5572 (0x15c4)
        -1,
        26, // 5062 (0x13c6)
        -1,
        15, // 6231 (0x1857)
        -1,
        27, // 5064 (0x13c8)
        -1,
        7, // 4700 (0x125c)
        21, // 6014 (0x177e)
        5, // 5285 (0x14a5)
        37, // 5212 (0x145c)
        -1,
        -1,
        -1,
        -1,
        22, // 4996 (0x1384)
        36, // 6164 (0x1814)
        -1,
        -1,
        42, // 6969 (0x1b39)
        -1,
        -1,
        -1,
        30, // 6168 (0x1818)
        -1,
        47, // 5658 (0x161a)
        -1,
        25, // 5002 (0x138a)
        41, // 5805 (0x16ad)
        -1,
        -1,
        16, // 6683 (0x1a1b)
        34, // 6245 (0x1865)
        -1,
        -1,
        17, // 4933 (0x1345)
        -1,
        20, // 6394 (0x18fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 5598 (0x15de)
        49, // 6182 (0x1826)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 4361 (0x1109)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 5387 (0x150b)
        -1,
        -1,
        -1,
        18, // 5316 (0x14c4)
        -1,
        19, // 5244 (0x147c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 6051 (0x17a3)
        43, // 6124 (0x17ec)
        -1,
        -1,
        -1,
        -1,
        11, // 5762 (0x1682)
        -1,
        0, // 4230 (0x1086)
        2, // 4230 (0x1086)
        1, // 4231 (0x1087)
        29, // 6932 (0x1b14)
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

//check: name=check_states_hash2, dataset=states, type=hash, hash=hash2
void check_states_hash2() {
    assert(lookup_states_hash2("ARKANSAS") == 3);
    assert(lookup_states_hash2("CONNECTICUT") == 6);
    assert(lookup_states_hash2("NEW YORK") == 31);
    assert(lookup_states_hash2("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash2("WASHINGTON") == 46);
    assert(lookup_states_hash2("IOWA") == 14);
    assert(lookup_states_hash2("VERMONT") == 44);
    assert(lookup_states_hash2("INDIANA") == 13);
    assert(lookup_states_hash2("SOUTH DAKOTA") == 40);
    assert(lookup_states_hash2("HAWAII") == 10);
    assert(lookup_states_hash2("WISCONSIN") == 48);
    assert(lookup_states_hash2("MISSOURI") == 24);
    assert(lookup_states_hash2("GEORGIA") == 9);
    assert(lookup_states_hash2("MISSISSIPPI") == 23);
    assert(lookup_states_hash2("OKLAHOMA") == 35);
    assert(lookup_states_hash2("FLORIDA") == 8);
    assert(lookup_states_hash2("NORTH CAROLINA") == 32);
    assert(lookup_states_hash2("NORTH DAKOTA") == 33);
    assert(lookup_states_hash2("RHODE ISLAND") == 38);
    assert(lookup_states_hash2("NEBRASKA") == 26);
    assert(lookup_states_hash2("KANSAS") == 15);
    assert(lookup_states_hash2("NEVADA") == 27);
    assert(lookup_states_hash2("DELAWARE") == 7);
    assert(lookup_states_hash2("MICHIGAN") == 21);
    assert(lookup_states_hash2("COLORADO") == 5);
    assert(lookup_states_hash2("PENNSYLVANIA") == 37);
    assert(lookup_states_hash2("MINNESOTA") == 22);
    assert(lookup_states_hash2("OREGON") == 36);
    assert(lookup_states_hash2("TEXAS") == 42);
    assert(lookup_states_hash2("NEW MEXICO") == 30);
    assert(lookup_states_hash2("WEST VIRGINIA") == 47);
    assert(lookup_states_hash2("MONTANA") == 25);
    assert(lookup_states_hash2("TENNESSEE") == 41);
    assert(lookup_states_hash2("KENTUCKY") == 16);
    assert(lookup_states_hash2("OHIO") == 34);
    assert(lookup_states_hash2("LOUISIANA") == 17);
    assert(lookup_states_hash2("MASSACHUSETTS") == 20);
    assert(lookup_states_hash2("VIRGINIA") == 45);
    assert(lookup_states_hash2("WYOMING") == 49);
    assert(lookup_states_hash2("CALIFORNIA") == 4);
    assert(lookup_states_hash2("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash2("MAINE") == 18);
    assert(lookup_states_hash2("MARYLAND") == 19);
    assert(lookup_states_hash2("ILLINOIS") == 12);
    assert(lookup_states_hash2("UTAH") == 43);
    assert(lookup_states_hash2("IDAHO") == 11);
    assert(lookup_states_hash2("ALABAMA") == 0);
    assert(lookup_states_hash2("ARIZONA") == 2);
    assert(lookup_states_hash2("ALASKA") == 1);
    assert(lookup_states_hash2("NEW JERSEY") == 29);
}

//lookup: name=lookup_states_hash3, dataset=states, type=hash, hash=hash3
int lookup_states_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 303) * 1;
    static constexpr const std::string_view lookup[303] = {
        "",
        "MAINE", // 21211 (0x52db)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CALIFORNIA", // 20012 (0x4e2c)
        "",
        "",
        "CONNECTICUT", // 20318 (0x4f5e)
        "",
        "",
        "",
        "NEW HAMPSHIRE", // 23655 (0x5c67)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KENTUCKY", // 21542 (0x5426)
        "",
        "",
        "",
        "",
        "WISCONSIN", // 24880 (0x6130)
        "DELAWARE", // 19730 (0x4d12)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NORTH DAKOTA", // 23388 (0x5b5c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH CAROLINA", // 25214 (0x627e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MASSACHUSETTS", // 23409 (0x5b71)
        "KANSAS", // 20986 (0x51fa)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIRGINIA", // 24338 (0x5f12)
        "",
        "",
        "",
        "COLORADO", // 19494 (0x4c26)
        "WYOMING", // 24343 (0x5f17)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW MEXICO", // 22846 (0x593e)
        "",
        "",
        "ILLINOIS", // 21031 (0x5227)
        "SOUTH DAKOTA", // 24668 (0x605c)
        "OKLAHOMA", // 22548 (0x5814)
        "",
        "",
        "",
        "",
        "NEW JERSEY", // 22856 (0x5948)
        "",
        "",
        "",
        "",
        "MISSISSIPPI", // 22861 (0x594d)
        "",
        "INDIANA", // 20742 (0x5106)
        "",
        "",
        "",
        "",
        "VERMONT", // 24080 (0x5e10)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TENNESSEE", // 24099 (0x5e23)
        "",
        "",
        "",
        "",
        "NEBRASKA", // 22286 (0x570e)
        "RHODE ISLAND", // 24408 (0x5f58)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW YORK", // 22296 (0x5718)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MINNESOTA", // 22307 (0x5723)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WEST VIRGINIA", // 25955 (0x6563)
        "",
        "IDAHO", // 20200 (0x4ee8)
        "ARKANSAS", // 18989 (0x4a2d)
        "",
        "",
        "OREGON", // 22022 (0x5606)
        "",
        "",
        "ALABAMA", // 18692 (0x4904)
        "HAWAII", // 20208 (0x4ef0)
        "",
        "",
        "MARYLAND", // 22029 (0x560d)
        "",
        "ARIZONA", // 18698 (0x490a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEORGIA", // 20221 (0x4efd)
        "",
        "",
        "MISSOURI", // 22042 (0x561a)
        "NEVADA", // 21740 (0x54ec)
        "",
        "IOWA", // 19924 (0x4dd4)
        "",
        "MICHIGAN", // 22047 (0x561f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALASKA", // 18419 (0x47f3)
        "",
        "LOUISIANA", // 22057 (0x5629)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MONTANA", // 21767 (0x5507)
        "",
        "PENNSYLVANIA", // 23890 (0x5d52)
        "OHIO", // 21467 (0x53db)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FLORIDA", // 19972 (0x4e04)
        "",
        "",
        "",
        "",
        "",
        "UTAH", // 23008 (0x59e0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TEXAS", // 23021 (0x59ed)
        "",
        "",
        "WASHINGTON", // 25145 (0x6239)
        "NORTH CAROLINA", // 23934 (0x5d7e)
        "",
        "",
    };
    static constexpr const int values[303] = {
        -1,
        18, // 21211 (0x52db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 20012 (0x4e2c)
        -1,
        -1,
        6, // 20318 (0x4f5e)
        -1,
        -1,
        -1,
        28, // 23655 (0x5c67)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 21542 (0x5426)
        -1,
        -1,
        -1,
        -1,
        48, // 24880 (0x6130)
        7, // 19730 (0x4d12)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 23388 (0x5b5c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 25214 (0x627e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 23409 (0x5b71)
        15, // 20986 (0x51fa)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 24338 (0x5f12)
        -1,
        -1,
        -1,
        5, // 19494 (0x4c26)
        49, // 24343 (0x5f17)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 22846 (0x593e)
        -1,
        -1,
        12, // 21031 (0x5227)
        40, // 24668 (0x605c)
        35, // 22548 (0x5814)
        -1,
        -1,
        -1,
        -1,
        29, // 22856 (0x5948)
        -1,
        -1,
        -1,
        -1,
        23, // 22861 (0x594d)
        -1,
        13, // 20742 (0x5106)
        -1,
        -1,
        -1,
        -1,
        44, // 24080 (0x5e10)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 24099 (0x5e23)
        -1,
        -1,
        -1,
        -1,
        26, // 22286 (0x570e)
        38, // 24408 (0x5f58)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 22296 (0x5718)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 22307 (0x5723)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 25955 (0x6563)
        -1,
        11, // 20200 (0x4ee8)
        3, // 18989 (0x4a2d)
        -1,
        -1,
        36, // 22022 (0x5606)
        -1,
        -1,
        0, // 18692 (0x4904)
        10, // 20208 (0x4ef0)
        -1,
        -1,
        19, // 22029 (0x560d)
        -1,
        2, // 18698 (0x490a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 20221 (0x4efd)
        -1,
        -1,
        24, // 22042 (0x561a)
        27, // 21740 (0x54ec)
        -1,
        14, // 19924 (0x4dd4)
        -1,
        21, // 22047 (0x561f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 18419 (0x47f3)
        -1,
        17, // 22057 (0x5629)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 21767 (0x5507)
        -1,
        37, // 23890 (0x5d52)
        34, // 21467 (0x53db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 19972 (0x4e04)
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 23008 (0x59e0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 23021 (0x59ed)
        -1,
        -1,
        46, // 25145 (0x6239)
        32, // 23934 (0x5d7e)
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

//check: name=check_states_hash3, dataset=states, type=hash, hash=hash3
void check_states_hash3() {
    assert(lookup_states_hash3("MAINE") == 18);
    assert(lookup_states_hash3("CALIFORNIA") == 4);
    assert(lookup_states_hash3("CONNECTICUT") == 6);
    assert(lookup_states_hash3("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash3("KENTUCKY") == 16);
    assert(lookup_states_hash3("WISCONSIN") == 48);
    assert(lookup_states_hash3("DELAWARE") == 7);
    assert(lookup_states_hash3("NORTH DAKOTA") == 33);
    assert(lookup_states_hash3("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash3("MASSACHUSETTS") == 20);
    assert(lookup_states_hash3("KANSAS") == 15);
    assert(lookup_states_hash3("VIRGINIA") == 45);
    assert(lookup_states_hash3("COLORADO") == 5);
    assert(lookup_states_hash3("WYOMING") == 49);
    assert(lookup_states_hash3("NEW MEXICO") == 30);
    assert(lookup_states_hash3("ILLINOIS") == 12);
    assert(lookup_states_hash3("SOUTH DAKOTA") == 40);
    assert(lookup_states_hash3("OKLAHOMA") == 35);
    assert(lookup_states_hash3("NEW JERSEY") == 29);
    assert(lookup_states_hash3("MISSISSIPPI") == 23);
    assert(lookup_states_hash3("INDIANA") == 13);
    assert(lookup_states_hash3("VERMONT") == 44);
    assert(lookup_states_hash3("TENNESSEE") == 41);
    assert(lookup_states_hash3("NEBRASKA") == 26);
    assert(lookup_states_hash3("RHODE ISLAND") == 38);
    assert(lookup_states_hash3("NEW YORK") == 31);
    assert(lookup_states_hash3("MINNESOTA") == 22);
    assert(lookup_states_hash3("WEST VIRGINIA") == 47);
    assert(lookup_states_hash3("IDAHO") == 11);
    assert(lookup_states_hash3("ARKANSAS") == 3);
    assert(lookup_states_hash3("OREGON") == 36);
    assert(lookup_states_hash3("ALABAMA") == 0);
    assert(lookup_states_hash3("HAWAII") == 10);
    assert(lookup_states_hash3("MARYLAND") == 19);
    assert(lookup_states_hash3("ARIZONA") == 2);
    assert(lookup_states_hash3("GEORGIA") == 9);
    assert(lookup_states_hash3("MISSOURI") == 24);
    assert(lookup_states_hash3("NEVADA") == 27);
    assert(lookup_states_hash3("IOWA") == 14);
    assert(lookup_states_hash3("MICHIGAN") == 21);
    assert(lookup_states_hash3("ALASKA") == 1);
    assert(lookup_states_hash3("LOUISIANA") == 17);
    assert(lookup_states_hash3("MONTANA") == 25);
    assert(lookup_states_hash3("PENNSYLVANIA") == 37);
    assert(lookup_states_hash3("OHIO") == 34);
    assert(lookup_states_hash3("FLORIDA") == 8);
    assert(lookup_states_hash3("UTAH") == 43);
    assert(lookup_states_hash3("TEXAS") == 42);
    assert(lookup_states_hash3("WASHINGTON") == 46);
    assert(lookup_states_hash3("NORTH CAROLINA") == 32);
}

//lookup: name=lookup_states_hash_sum0, dataset=states, type=hash, hash=hash_sum0
int lookup_states_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 225) * 1;
    static constexpr const std::string_view lookup[225] = {
        "",
        "",
        "LOUISIANA", // 677 (0x2a5)
        "",
        "",
        "",
        "",
        "TENNESSEE", // 682 (0x2aa)
        "OREGON", // 458 (0x1ca)
        "",
        "",
        "MINNESOTA", // 686 (0x2ae)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PENNSYLVANIA", // 920 (0x398)
        "",
        "",
        "",
        "",
        "",
        "WISCONSIN", // 701 (0x2bd)
        "",
        "",
        "ALABAMA", // 479 (0x1df)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW HAMPSHIRE", // 939 (0x3ab)
        "",
        "",
        "",
        "",
        "NEW MEXICO", // 719 (0x2cf)
        "",
        "",
        "",
        "",
        "",
        "INDIANA", // 500 (0x1f4)
        "",
        "",
        "CALIFORNIA", // 728 (0x2d8)
        "",
        "",
        "WEST VIRGINIA", // 956 (0x3bc)
        "NEW JERSEY", // 732 (0x2dc)
        "",
        "",
        "GEORGIA", // 510 (0x1fe)
        "",
        "",
        "FLORIDA", // 513 (0x201)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MONTANA", // 526 (0x20e)
        "",
        "OHIO", // 303 (0x12f)
        "IOWA", // 304 (0x130)
        "",
        "UTAH", // 306 (0x132)
        "ARIZONA", // 532 (0x214)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WASHINGTON", // 770 (0x302)
        "",
        "",
        "",
        "",
        "MASSACHUSETTS", // 1000 (0x3e8)
        "",
        "",
        "",
        "WYOMING", // 554 (0x22a)
        "VERMONT", // 555 (0x22b)
        "",
        "",
        "",
        "",
        "",
        "",
        "NORTH CAROLINA", // 1012 (0x3f4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH CAROLINA", // 1020 (0x3fc)
        "",
        "",
        "",
        "",
        "",
        "MICHIGAN", // 576 (0x240)
        "",
        "",
        "",
        "",
        "DELAWARE", // 581 (0x245)
        "IDAHO", // 357 (0x165)
        "NEBRASKA", // 583 (0x247)
        "",
        "",
        "",
        "MAINE", // 362 (0x16a)
        "OKLAHOMA", // 588 (0x24c)
        "",
        "",
        "NEW YORK", // 591 (0x24f)
        "",
        "",
        "",
        "COLORADO", // 595 (0x253)
        "ARKANSAS", // 596 (0x254)
        "",
        "",
        "",
        "MARYLAND", // 600 (0x258)
        "VIRGINIA", // 601 (0x259)
        "",
        "",
        "",
        "",
        "CONNECTICUT", // 831 (0x33f)
        "",
        "",
        "",
        "",
        "ILLINOIS", // 611 (0x263)
        "",
        "",
        "TEXAS", // 389 (0x185)
        "",
        "",
        "",
        "",
        "",
        "RHODE ISLAND", // 845 (0x34d)
        "",
        "KENTUCKY", // 622 (0x26e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MISSOURI", // 635 (0x27b)
        "MISSISSIPPI", // 861 (0x35d)
        "",
        "NORTH DAKOTA", // 863 (0x35f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH DAKOTA", // 871 (0x367)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALASKA", // 429 (0x1ad)
        "",
        "NEVADA", // 431 (0x1af)
        "",
        "",
        "",
        "HAWAII", // 435 (0x1b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KANSAS", // 449 (0x1c1)
    };
    static constexpr const int values[225] = {
        -1,
        -1,
        17, // 677 (0x2a5)
        -1,
        -1,
        -1,
        -1,
        41, // 682 (0x2aa)
        36, // 458 (0x1ca)
        -1,
        -1,
        22, // 686 (0x2ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 920 (0x398)
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 701 (0x2bd)
        -1,
        -1,
        0, // 479 (0x1df)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 939 (0x3ab)
        -1,
        -1,
        -1,
        -1,
        30, // 719 (0x2cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 500 (0x1f4)
        -1,
        -1,
        4, // 728 (0x2d8)
        -1,
        -1,
        47, // 956 (0x3bc)
        29, // 732 (0x2dc)
        -1,
        -1,
        9, // 510 (0x1fe)
        -1,
        -1,
        8, // 513 (0x201)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 526 (0x20e)
        -1,
        34, // 303 (0x12f)
        14, // 304 (0x130)
        -1,
        43, // 306 (0x132)
        2, // 532 (0x214)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 770 (0x302)
        -1,
        -1,
        -1,
        -1,
        20, // 1000 (0x3e8)
        -1,
        -1,
        -1,
        49, // 554 (0x22a)
        44, // 555 (0x22b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 1012 (0x3f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 1020 (0x3fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 576 (0x240)
        -1,
        -1,
        -1,
        -1,
        7, // 581 (0x245)
        11, // 357 (0x165)
        26, // 583 (0x247)
        -1,
        -1,
        -1,
        18, // 362 (0x16a)
        35, // 588 (0x24c)
        -1,
        -1,
        31, // 591 (0x24f)
        -1,
        -1,
        -1,
        5, // 595 (0x253)
        3, // 596 (0x254)
        -1,
        -1,
        -1,
        19, // 600 (0x258)
        45, // 601 (0x259)
        -1,
        -1,
        -1,
        -1,
        6, // 831 (0x33f)
        -1,
        -1,
        -1,
        -1,
        12, // 611 (0x263)
        -1,
        -1,
        42, // 389 (0x185)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 845 (0x34d)
        -1,
        16, // 622 (0x26e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 635 (0x27b)
        23, // 861 (0x35d)
        -1,
        33, // 863 (0x35f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 871 (0x367)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 429 (0x1ad)
        -1,
        27, // 431 (0x1af)
        -1,
        -1,
        -1,
        10, // 435 (0x1b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 449 (0x1c1)
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_states_hash_sum0, dataset=states, type=hash, hash=hash_sum0
void check_states_hash_sum0() {
    assert(lookup_states_hash_sum0("LOUISIANA") == 17);
    assert(lookup_states_hash_sum0("TENNESSEE") == 41);
    assert(lookup_states_hash_sum0("OREGON") == 36);
    assert(lookup_states_hash_sum0("MINNESOTA") == 22);
    assert(lookup_states_hash_sum0("PENNSYLVANIA") == 37);
    assert(lookup_states_hash_sum0("WISCONSIN") == 48);
    assert(lookup_states_hash_sum0("ALABAMA") == 0);
    assert(lookup_states_hash_sum0("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash_sum0("NEW MEXICO") == 30);
    assert(lookup_states_hash_sum0("INDIANA") == 13);
    assert(lookup_states_hash_sum0("CALIFORNIA") == 4);
    assert(lookup_states_hash_sum0("WEST VIRGINIA") == 47);
    assert(lookup_states_hash_sum0("NEW JERSEY") == 29);
    assert(lookup_states_hash_sum0("GEORGIA") == 9);
    assert(lookup_states_hash_sum0("FLORIDA") == 8);
    assert(lookup_states_hash_sum0("MONTANA") == 25);
    assert(lookup_states_hash_sum0("OHIO") == 34);
    assert(lookup_states_hash_sum0("IOWA") == 14);
    assert(lookup_states_hash_sum0("UTAH") == 43);
    assert(lookup_states_hash_sum0("ARIZONA") == 2);
    assert(lookup_states_hash_sum0("WASHINGTON") == 46);
    assert(lookup_states_hash_sum0("MASSACHUSETTS") == 20);
    assert(lookup_states_hash_sum0("WYOMING") == 49);
    assert(lookup_states_hash_sum0("VERMONT") == 44);
    assert(lookup_states_hash_sum0("NORTH CAROLINA") == 32);
    assert(lookup_states_hash_sum0("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash_sum0("MICHIGAN") == 21);
    assert(lookup_states_hash_sum0("DELAWARE") == 7);
    assert(lookup_states_hash_sum0("IDAHO") == 11);
    assert(lookup_states_hash_sum0("NEBRASKA") == 26);
    assert(lookup_states_hash_sum0("MAINE") == 18);
    assert(lookup_states_hash_sum0("OKLAHOMA") == 35);
    assert(lookup_states_hash_sum0("NEW YORK") == 31);
    assert(lookup_states_hash_sum0("COLORADO") == 5);
    assert(lookup_states_hash_sum0("ARKANSAS") == 3);
    assert(lookup_states_hash_sum0("MARYLAND") == 19);
    assert(lookup_states_hash_sum0("VIRGINIA") == 45);
    assert(lookup_states_hash_sum0("CONNECTICUT") == 6);
    assert(lookup_states_hash_sum0("ILLINOIS") == 12);
    assert(lookup_states_hash_sum0("TEXAS") == 42);
    assert(lookup_states_hash_sum0("RHODE ISLAND") == 38);
    assert(lookup_states_hash_sum0("KENTUCKY") == 16);
    assert(lookup_states_hash_sum0("MISSOURI") == 24);
    assert(lookup_states_hash_sum0("MISSISSIPPI") == 23);
    assert(lookup_states_hash_sum0("NORTH DAKOTA") == 33);
    assert(lookup_states_hash_sum0("SOUTH DAKOTA") == 40);
    assert(lookup_states_hash_sum0("ALASKA") == 1);
    assert(lookup_states_hash_sum0("NEVADA") == 27);
    assert(lookup_states_hash_sum0("HAWAII") == 10);
    assert(lookup_states_hash_sum0("KANSAS") == 15);
}

//lookup: name=lookup_states_hash_sumN, dataset=states, type=hash, hash=hash_sumN
int lookup_states_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 187) * 1;
    static constexpr const std::string_view lookup[187] = {
        "WYOMING", // 561 (0x231)
        "VERMONT", // 562 (0x232)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW HAMPSHIRE", // 952 (0x3b8)
        "",
        "",
        "TEXAS", // 394 (0x18a)
        "",
        "",
        "MICHIGAN", // 584 (0x248)
        "",
        "",
        "",
        "",
        "DELAWARE", // 589 (0x24d)
        "",
        "NEBRASKA", // 591 (0x24f)
        "",
        "WASHINGTON", // 780 (0x30c)
        "",
        "WEST VIRGINIA", // 969 (0x3c9)
        "OKLAHOMA", // 596 (0x254)
        "",
        "",
        "NEW YORK", // 599 (0x257)
        "",
        "",
        "",
        "COLORADO", // 603 (0x25b)
        "ARKANSAS", // 604 (0x25c)
        "",
        "",
        "",
        "MARYLAND", // 608 (0x260)
        "VIRGINIA", // 609 (0x261)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ILLINOIS", // 619 (0x26b)
        "",
        "",
        "ALASKA", // 435 (0x1b3)
        "",
        "NEVADA", // 437 (0x1b5)
        "",
        "",
        "",
        "HAWAII", // 441 (0x1b9)
        "",
        "KENTUCKY", // 630 (0x276)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MASSACHUSETTS", // 1013 (0x3f5)
        "",
        "",
        "KANSAS", // 455 (0x1c7)
        "MISSOURI", // 643 (0x283)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OREGON", // 464 (0x1d0)
        "NORTH CAROLINA", // 1026 (0x402)
        "",
        "",
        "CONNECTICUT", // 842 (0x34a)
        "",
        "",
        "",
        "",
        "SOUTH CAROLINA", // 1034 (0x40a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RHODE ISLAND", // 857 (0x359)
        "",
        "",
        "ALABAMA", // 486 (0x1e6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OHIO", // 307 (0x133)
        "IOWA", // 308 (0x134)
        "",
        "UTAH", // 310 (0x136)
        "MISSISSIPPI", // 872 (0x368)
        "LOUISIANA", // 686 (0x2ae)
        "",
        "NORTH DAKOTA", // 875 (0x36b)
        "",
        "",
        "TENNESSEE", // 691 (0x2b3)
        "",
        "",
        "INDIANA", // 507 (0x1fb)
        "MINNESOTA", // 695 (0x2b7)
        "SOUTH DAKOTA", // 883 (0x373)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GEORGIA", // 517 (0x205)
        "",
        "",
        "FLORIDA", // 520 (0x208)
        "",
        "",
        "WISCONSIN", // 710 (0x2c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MONTANA", // 533 (0x215)
        "",
        "",
        "",
        "",
        "",
        "ARIZONA", // 539 (0x21b)
        "",
        "",
        "NEW MEXICO", // 729 (0x2d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "IDAHO", // 362 (0x16a)
        "",
        "CALIFORNIA", // 738 (0x2e2)
        "",
        "",
        "MAINE", // 367 (0x16f)
        "NEW JERSEY", // 742 (0x2e6)
        "",
        "",
        "PENNSYLVANIA", // 932 (0x3a4)
        "",
        "",
    };
    static constexpr const int values[187] = {
        49, // 561 (0x231)
        44, // 562 (0x232)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 952 (0x3b8)
        -1,
        -1,
        42, // 394 (0x18a)
        -1,
        -1,
        21, // 584 (0x248)
        -1,
        -1,
        -1,
        -1,
        7, // 589 (0x24d)
        -1,
        26, // 591 (0x24f)
        -1,
        46, // 780 (0x30c)
        -1,
        47, // 969 (0x3c9)
        35, // 596 (0x254)
        -1,
        -1,
        31, // 599 (0x257)
        -1,
        -1,
        -1,
        5, // 603 (0x25b)
        3, // 604 (0x25c)
        -1,
        -1,
        -1,
        19, // 608 (0x260)
        45, // 609 (0x261)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 619 (0x26b)
        -1,
        -1,
        1, // 435 (0x1b3)
        -1,
        27, // 437 (0x1b5)
        -1,
        -1,
        -1,
        10, // 441 (0x1b9)
        -1,
        16, // 630 (0x276)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 1013 (0x3f5)
        -1,
        -1,
        15, // 455 (0x1c7)
        24, // 643 (0x283)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 464 (0x1d0)
        32, // 1026 (0x402)
        -1,
        -1,
        6, // 842 (0x34a)
        -1,
        -1,
        -1,
        -1,
        39, // 1034 (0x40a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 857 (0x359)
        -1,
        -1,
        0, // 486 (0x1e6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 307 (0x133)
        14, // 308 (0x134)
        -1,
        43, // 310 (0x136)
        23, // 872 (0x368)
        17, // 686 (0x2ae)
        -1,
        33, // 875 (0x36b)
        -1,
        -1,
        41, // 691 (0x2b3)
        -1,
        -1,
        13, // 507 (0x1fb)
        22, // 695 (0x2b7)
        40, // 883 (0x373)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 517 (0x205)
        -1,
        -1,
        8, // 520 (0x208)
        -1,
        -1,
        48, // 710 (0x2c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 533 (0x215)
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 539 (0x21b)
        -1,
        -1,
        30, // 729 (0x2d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 362 (0x16a)
        -1,
        4, // 738 (0x2e2)
        -1,
        -1,
        18, // 367 (0x16f)
        29, // 742 (0x2e6)
        -1,
        -1,
        37, // 932 (0x3a4)
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

//check: name=check_states_hash_sumN, dataset=states, type=hash, hash=hash_sumN
void check_states_hash_sumN() {
    assert(lookup_states_hash_sumN("WYOMING") == 49);
    assert(lookup_states_hash_sumN("VERMONT") == 44);
    assert(lookup_states_hash_sumN("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash_sumN("TEXAS") == 42);
    assert(lookup_states_hash_sumN("MICHIGAN") == 21);
    assert(lookup_states_hash_sumN("DELAWARE") == 7);
    assert(lookup_states_hash_sumN("NEBRASKA") == 26);
    assert(lookup_states_hash_sumN("WASHINGTON") == 46);
    assert(lookup_states_hash_sumN("WEST VIRGINIA") == 47);
    assert(lookup_states_hash_sumN("OKLAHOMA") == 35);
    assert(lookup_states_hash_sumN("NEW YORK") == 31);
    assert(lookup_states_hash_sumN("COLORADO") == 5);
    assert(lookup_states_hash_sumN("ARKANSAS") == 3);
    assert(lookup_states_hash_sumN("MARYLAND") == 19);
    assert(lookup_states_hash_sumN("VIRGINIA") == 45);
    assert(lookup_states_hash_sumN("ILLINOIS") == 12);
    assert(lookup_states_hash_sumN("ALASKA") == 1);
    assert(lookup_states_hash_sumN("NEVADA") == 27);
    assert(lookup_states_hash_sumN("HAWAII") == 10);
    assert(lookup_states_hash_sumN("KENTUCKY") == 16);
    assert(lookup_states_hash_sumN("MASSACHUSETTS") == 20);
    assert(lookup_states_hash_sumN("KANSAS") == 15);
    assert(lookup_states_hash_sumN("MISSOURI") == 24);
    assert(lookup_states_hash_sumN("OREGON") == 36);
    assert(lookup_states_hash_sumN("NORTH CAROLINA") == 32);
    assert(lookup_states_hash_sumN("CONNECTICUT") == 6);
    assert(lookup_states_hash_sumN("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash_sumN("RHODE ISLAND") == 38);
    assert(lookup_states_hash_sumN("ALABAMA") == 0);
    assert(lookup_states_hash_sumN("OHIO") == 34);
    assert(lookup_states_hash_sumN("IOWA") == 14);
    assert(lookup_states_hash_sumN("UTAH") == 43);
    assert(lookup_states_hash_sumN("MISSISSIPPI") == 23);
    assert(lookup_states_hash_sumN("LOUISIANA") == 17);
    assert(lookup_states_hash_sumN("NORTH DAKOTA") == 33);
    assert(lookup_states_hash_sumN("TENNESSEE") == 41);
    assert(lookup_states_hash_sumN("INDIANA") == 13);
    assert(lookup_states_hash_sumN("MINNESOTA") == 22);
    assert(lookup_states_hash_sumN("SOUTH DAKOTA") == 40);
    assert(lookup_states_hash_sumN("GEORGIA") == 9);
    assert(lookup_states_hash_sumN("FLORIDA") == 8);
    assert(lookup_states_hash_sumN("WISCONSIN") == 48);
    assert(lookup_states_hash_sumN("MONTANA") == 25);
    assert(lookup_states_hash_sumN("ARIZONA") == 2);
    assert(lookup_states_hash_sumN("NEW MEXICO") == 30);
    assert(lookup_states_hash_sumN("IDAHO") == 11);
    assert(lookup_states_hash_sumN("CALIFORNIA") == 4);
    assert(lookup_states_hash_sumN("MAINE") == 18);
    assert(lookup_states_hash_sumN("NEW JERSEY") == 29);
    assert(lookup_states_hash_sumN("PENNSYLVANIA") == 37);
}

//lookup: name=lookup_states_hash_djb2, dataset=states, type=hash, hash=hash_djb2
int lookup_states_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 268) * 1;
    static constexpr const std::string_view lookup[268] = {
        "",
        "",
        "",
        "UTAH", // 6503181339 (0x1839eac1b)
        "",
        "",
        "ALASKA", // 7081172297462 (0x670b6c266f6)
        "",
        "NORTH DAKOTA", // 14631321011629941992 (0xcb0ce4f0a4e964e8)
        "",
        "",
        "",
        "NEVADA", // 7081673490968 (0x670d4a20218)
        "",
        "",
        "",
        "",
        "",
        "KANSAS", // 7081551073130 (0x670cd560f6a)
        "",
        "",
        "INDIANA", // 233689099018781 (0xd489fbbc221d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ILLINOIS", // 7711737998235596 (0x1b65c8ebfc57cc)
        "",
        "",
        "",
        "",
        "CALIFORNIA", // 8397788740364588993 (0x748af05db034d7c1)
        "",
        "",
        "",
        "SOUTH CAROLINA", // 12620681192459438085 (0xaf25aaad63ff8805)
        "",
        "",
        "",
        "",
        "IDAHO", // 214590178222 (0x31f69243ae)
        "",
        "ALABAMA", // 233678685194888 (0xd4878f05ca88)
        "",
        "",
        "",
        "",
        "IOWA", // 6502745369 (0x183980519)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIRGINIA", // 7712288395850114 (0x1b6649123d7182)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DELAWARE", // 7711515856566030 (0x1b6595334f770e)
        "WASHINGTON", // 8398717267206092619 (0x748e3cdb30c2374b)
        "MISSOURI", // 7711904883453316 (0x1b65efc71ead84)
        "MASSACHUSETTS", // 844245281438330769 (0xbb75c9c476e6f91)
        "",
        "",
        "",
        "",
        "RHODE ISLAND", // 14822606520158615510 (0xcdb47a18b77177d6)
        "MAINE", // 214594822995 (0x31f6d92353)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW JERSEY", // 8398305308324857157 (0x748cc62e89fb0545)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VERMONT", // 233705552645748 (0xd48dd0728e74)
        "ARKANSAS", // 7711404750880925 (0x1b657b54e5409d)
        "WISCONSIN", // 254506924613725158 (0x38830b3127a6be6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MISSISSIPPI", // 441564683192740006 (0x620c0bd670fa8a6)
        "GEORGIA", // 233686177239239 (0xd4894d9550c7)
        "",
        "MARYLAND", // 7711894519559969 (0x1b65ed5d623721)
        "",
        "MINNESOTA", // 254492854489008695 (0x38823e71db14a37)
        "SOUTH DAKOTA", // 14884170778651781936 (0xce8f3276a5c9eb30)
        "ARIZONA", // 233678930372381 (0xd4879da2e71d)
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW HAMPSHIRE", // 2718072318567981556 (0x25b8885f6e1121f4)
        "",
        "LOUISIANA", // 254491712651875214 (0x38822dd42e5538e)
        "",
        "",
        "",
        "",
        "",
        "",
        "MICHIGAN", // 7711904244010473 (0x1b65efa1018de9)
        "",
        "",
        "OHIO", // 6502952920 (0x1839b2fd8)
        "",
        "",
        "",
        "NEBRASKA", // 7711941669031280 (0x1b65f857b60d70)
        "",
        "",
        "TENNESSEE", // 254502528875568339 (0x3882cb39c111cd3)
        "",
        "",
        "",
        "",
        "COLORADO", // 7711486169225500 (0x1b658e49ce991c)
        "",
        "",
        "",
        "",
        "NORTH CAROLINA", // 13968446011319013309 (0xc1d9e3a3a8e44fbd)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TEXAS", // 214603284110 (0x31f75a3e8e)
        "MONTANA", // 233694316280567 (0xd48b32b53af7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OKLAHOMA", // 7711992407722613 (0x1b660427f90a75)
        "",
        "OREGON", // 7081727439315 (0x670d7d931d3)
        "",
        "",
        "",
        "",
        "CONNECTICUT", // 426520111320334920 (0x5eb4dc80ccf0248)
        "",
        "",
        "",
        "",
        "",
        "FLORIDA", // 233685159721034 (0xd48910ef384a)
        "",
        "",
        "",
        "",
        "",
        "NEW MEXICO", // 8398305308442467992 (0x748cc62e90fd9e98)
        "",
        "",
        "",
        "",
        "",
        "",
        "WYOMING", // 233707623257267 (0xd48e4bdd94b3)
        "",
        "PENNSYLVANIA", // 14716895893169607521 (0xcc3cead764c79361)
        "",
        "",
        "HAWAII", // 7081433971036 (0x670c65b395c)
        "",
        "",
        "KENTUCKY", // 7711814286400247 (0x1b65daaf1d5af7)
        "",
        "",
        "",
        "",
        "NEW YORK", // 7711942432436856 (0x1b65f88536b278)
        "WEST VIRGINIA", // 17725309667933471781 (0xf5fcf33af2f8c425)
        "",
        "",
    };
    static constexpr const int values[268] = {
        -1,
        -1,
        -1,
        43, // 6503181339 (0x1839eac1b)
        -1,
        -1,
        1, // 7081172297462 (0x670b6c266f6)
        -1,
        33, // 14631321011629941992 (0xcb0ce4f0a4e964e8)
        -1,
        -1,
        -1,
        27, // 7081673490968 (0x670d4a20218)
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 7081551073130 (0x670cd560f6a)
        -1,
        -1,
        13, // 233689099018781 (0xd489fbbc221d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 7711737998235596 (0x1b65c8ebfc57cc)
        -1,
        -1,
        -1,
        -1,
        4, // 8397788740364588993 (0x748af05db034d7c1)
        -1,
        -1,
        -1,
        39, // 12620681192459438085 (0xaf25aaad63ff8805)
        -1,
        -1,
        -1,
        -1,
        11, // 214590178222 (0x31f69243ae)
        -1,
        0, // 233678685194888 (0xd4878f05ca88)
        -1,
        -1,
        -1,
        -1,
        14, // 6502745369 (0x183980519)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 7712288395850114 (0x1b6649123d7182)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 7711515856566030 (0x1b6595334f770e)
        46, // 8398717267206092619 (0x748e3cdb30c2374b)
        24, // 7711904883453316 (0x1b65efc71ead84)
        20, // 844245281438330769 (0xbb75c9c476e6f91)
        -1,
        -1,
        -1,
        -1,
        38, // 14822606520158615510 (0xcdb47a18b77177d6)
        18, // 214594822995 (0x31f6d92353)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 8398305308324857157 (0x748cc62e89fb0545)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 233705552645748 (0xd48dd0728e74)
        3, // 7711404750880925 (0x1b657b54e5409d)
        48, // 254506924613725158 (0x38830b3127a6be6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 441564683192740006 (0x620c0bd670fa8a6)
        9, // 233686177239239 (0xd4894d9550c7)
        -1,
        19, // 7711894519559969 (0x1b65ed5d623721)
        -1,
        22, // 254492854489008695 (0x38823e71db14a37)
        40, // 14884170778651781936 (0xce8f3276a5c9eb30)
        2, // 233678930372381 (0xd4879da2e71d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 2718072318567981556 (0x25b8885f6e1121f4)
        -1,
        17, // 254491712651875214 (0x38822dd42e5538e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 7711904244010473 (0x1b65efa1018de9)
        -1,
        -1,
        34, // 6502952920 (0x1839b2fd8)
        -1,
        -1,
        -1,
        26, // 7711941669031280 (0x1b65f857b60d70)
        -1,
        -1,
        41, // 254502528875568339 (0x3882cb39c111cd3)
        -1,
        -1,
        -1,
        -1,
        5, // 7711486169225500 (0x1b658e49ce991c)
        -1,
        -1,
        -1,
        -1,
        32, // 13968446011319013309 (0xc1d9e3a3a8e44fbd)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 214603284110 (0x31f75a3e8e)
        25, // 233694316280567 (0xd48b32b53af7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 7711992407722613 (0x1b660427f90a75)
        -1,
        36, // 7081727439315 (0x670d7d931d3)
        -1,
        -1,
        -1,
        -1,
        6, // 426520111320334920 (0x5eb4dc80ccf0248)
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 233685159721034 (0xd48910ef384a)
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 8398305308442467992 (0x748cc62e90fd9e98)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 233707623257267 (0xd48e4bdd94b3)
        -1,
        37, // 14716895893169607521 (0xcc3cead764c79361)
        -1,
        -1,
        10, // 7081433971036 (0x670c65b395c)
        -1,
        -1,
        16, // 7711814286400247 (0x1b65daaf1d5af7)
        -1,
        -1,
        -1,
        -1,
        31, // 7711942432436856 (0x1b65f88536b278)
        47, // 17725309667933471781 (0xf5fcf33af2f8c425)
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

//check: name=check_states_hash_djb2, dataset=states, type=hash, hash=hash_djb2
void check_states_hash_djb2() {
    assert(lookup_states_hash_djb2("UTAH") == 43);
    assert(lookup_states_hash_djb2("ALASKA") == 1);
    assert(lookup_states_hash_djb2("NORTH DAKOTA") == 33);
    assert(lookup_states_hash_djb2("NEVADA") == 27);
    assert(lookup_states_hash_djb2("KANSAS") == 15);
    assert(lookup_states_hash_djb2("INDIANA") == 13);
    assert(lookup_states_hash_djb2("ILLINOIS") == 12);
    assert(lookup_states_hash_djb2("CALIFORNIA") == 4);
    assert(lookup_states_hash_djb2("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash_djb2("IDAHO") == 11);
    assert(lookup_states_hash_djb2("ALABAMA") == 0);
    assert(lookup_states_hash_djb2("IOWA") == 14);
    assert(lookup_states_hash_djb2("VIRGINIA") == 45);
    assert(lookup_states_hash_djb2("DELAWARE") == 7);
    assert(lookup_states_hash_djb2("WASHINGTON") == 46);
    assert(lookup_states_hash_djb2("MISSOURI") == 24);
    assert(lookup_states_hash_djb2("MASSACHUSETTS") == 20);
    assert(lookup_states_hash_djb2("RHODE ISLAND") == 38);
    assert(lookup_states_hash_djb2("MAINE") == 18);
    assert(lookup_states_hash_djb2("NEW JERSEY") == 29);
    assert(lookup_states_hash_djb2("VERMONT") == 44);
    assert(lookup_states_hash_djb2("ARKANSAS") == 3);
    assert(lookup_states_hash_djb2("WISCONSIN") == 48);
    assert(lookup_states_hash_djb2("MISSISSIPPI") == 23);
    assert(lookup_states_hash_djb2("GEORGIA") == 9);
    assert(lookup_states_hash_djb2("MARYLAND") == 19);
    assert(lookup_states_hash_djb2("MINNESOTA") == 22);
    assert(lookup_states_hash_djb2("SOUTH DAKOTA") == 40);
    assert(lookup_states_hash_djb2("ARIZONA") == 2);
    assert(lookup_states_hash_djb2("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash_djb2("LOUISIANA") == 17);
    assert(lookup_states_hash_djb2("MICHIGAN") == 21);
    assert(lookup_states_hash_djb2("OHIO") == 34);
    assert(lookup_states_hash_djb2("NEBRASKA") == 26);
    assert(lookup_states_hash_djb2("TENNESSEE") == 41);
    assert(lookup_states_hash_djb2("COLORADO") == 5);
    assert(lookup_states_hash_djb2("NORTH CAROLINA") == 32);
    assert(lookup_states_hash_djb2("TEXAS") == 42);
    assert(lookup_states_hash_djb2("MONTANA") == 25);
    assert(lookup_states_hash_djb2("OKLAHOMA") == 35);
    assert(lookup_states_hash_djb2("OREGON") == 36);
    assert(lookup_states_hash_djb2("CONNECTICUT") == 6);
    assert(lookup_states_hash_djb2("FLORIDA") == 8);
    assert(lookup_states_hash_djb2("NEW MEXICO") == 30);
    assert(lookup_states_hash_djb2("WYOMING") == 49);
    assert(lookup_states_hash_djb2("PENNSYLVANIA") == 37);
    assert(lookup_states_hash_djb2("HAWAII") == 10);
    assert(lookup_states_hash_djb2("KENTUCKY") == 16);
    assert(lookup_states_hash_djb2("NEW YORK") == 31);
    assert(lookup_states_hash_djb2("WEST VIRGINIA") == 47);
}

//lookup: name=lookup_states_hash_sdb, dataset=states, type=hash, hash=hash_sdb
int lookup_states_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 274) * 1;
    static constexpr const std::string_view lookup[274] = {
        "",
        "CONNECTICUT", // 6880868369768491963 (0x5f7dc1536e45abbb)
        "",
        "",
        "",
        "",
        "",
        "",
        "MONTANA", // 13992636146360666944 (0xc22fd4705f1e4b40)
        "",
        "GEORGIA", // 12830101765377831150 (0xb20dad942d7530ee)
        "",
        "",
        "",
        "",
        "",
        "",
        "NEW MEXICO", // 6608456252466856905 (0x5bb5f3f2d1ff03c9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DELAWARE", // 11581556388507579087 (0xa0b9f42c732672cf)
        "",
        "",
        "",
        "TEXAS", // 303171077776352777 (0x435147d2d082609)
        "",
        "",
        "",
        "ILLINOIS", // 16660075603158348667 (0xe7347a7e0167b37b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WYOMING", // 15767399651709514010 (0xdad10e71a7c3711a)
        "",
        "ARKANSAS", // 11135700682730273994 (0x9a89f4c57f367cca)
        "NEVADA", // 2233332526500179015 (0x1efe6419a35e6c47)
        "",
        "",
        "",
        "WISCONSIN", // 272938902478223003 (0x3c9ac7c5799769b)
        "",
        "RHODE ISLAND", // 3353026692530643551 (0x2e88580302b1225f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MINNESOTA", // 16795472280822443986 (0xe915810d9d576fd2)
        "",
        "IOWA", // 20550834561747904 (0x4902e009e40bc0)
        "",
        "WASHINGTON", // 1655899912373640900 (0x16faf0326ca19ec4)
        "ALABAMA", // 12043633595867471925 (0xa72394f20ea42035)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MAINE", // 278399437223174904 (0x3dd12d0295b22f8)
        "",
        "",
        "",
        "NORTH CAROLINA", // 9184721153559411594 (0x7f76af39f6ecbb8a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OKLAHOMA", // 2820638147662176436 (0x2724eb736f51e0b4)
        "NEW HAMPSHIRE", // 9399569598683788115 (0x8271fabfbb1bb353)
        "",
        "",
        "PENNSYLVANIA", // 6495559916817274566 (0x5a24dd545328d6c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "NEBRASKA", // 912739619889070679 (0xcaab3d92fe9c257)
        "MARYLAND", // 18385558008839454818 (0xff269f992236c062)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UTAH", // 23929019635338486 (0x5503510b300cf6)
        "",
        "",
        "",
        "",
        "",
        "MASSACHUSETTS", // 10948979493369205346 (0x97f296d6cb4ed262)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FLORIDA", // 12855437421065352381 (0xb267b03932dd34bd)
        "INDIANA", // 13322419448647269014 (0xb8e2bde741603a96)
        "",
        "",
        "",
        "",
        "",
        "",
        "VERMONT", // 15118853615111199867 (0xd1d0f54283d55c7b)
        "",
        "",
        "",
        "",
        "",
        "COLORADO", // 12349453446040947333 (0xab62127a9d7e8a85)
        "",
        "",
        "",
        "IDAHO", // 265732217136095669 (0x3b0120b27c621b5)
        "",
        "",
        "",
        "MISSOURI", // 1160738526810134349 (0x101bc58a4fa0d74d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "WEST VIRGINIA", // 6076126914224478050 (0x5452bd3c5c8a5762)
        "",
        "",
        "",
        "CALIFORNIA", // 1905690934427542112 (0x1a725fcede3c6260)
        "",
        "TENNESSEE", // 3522764316158525704 (0x30e35f7b2c0d0108)
        "",
        "",
        "",
        "",
        "",
        "ARIZONA", // 12229416881875790712 (0xa9b79ddc1e5f2b78)
        "NORTH DAKOTA", // 7074195289287635309 (0x622c972289bb316d)
        "",
        "",
        "OREGON", // 2297793839606493168 (0x1fe36752a8d36ff0)
        "",
        "",
        "",
        "",
        "",
        "",
        "KANSAS", // 2141567045412612093 (0x1db85fe19c8067fd)
        "",
        "SOUTH DAKOTA", // 14409207444294310909 (0xc7f7c9d3cc139bfd)
        "KENTUCKY", // 17281866222126544480 (0xefd585c409acb660)
        "NEW YORK", // 1282611406117652727 (0x11ccc0473e81c8f7)
        "",
        "",
        "",
        "HAWAII", // 2068098868080305539 (0x1cb35cf698506583)
        "",
        "",
        "",
        "LOUISIANA", // 288168163366837107 (0x3ffc76af50e9b73)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIRGINIA", // 8275211616246439533 (0x72d7751efb8e1e6d)
        "",
        "",
        "",
        "",
        "NEW JERSEY", // 6530765490906464440 (0x5aa1f09cccdc00b8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MISSISSIPPI", // 2245237043399206525 (0x1f28af31f85ba67d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OHIO", // 22239886292421639 (0x4f030f0a4e0c07)
        "",
        "",
        "",
        "ALASKA", // 1921725540679377063 (0x1aab57328ffd60a7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH CAROLINA", // 9663440672952711834 (0x861b7017cb687a9a)
        "",
        "MICHIGAN", // 716549615513879380 (0x9f1b21430a5c354)
        "",
    };
    static constexpr const int values[274] = {
        -1,
        6, // 6880868369768491963 (0x5f7dc1536e45abbb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 13992636146360666944 (0xc22fd4705f1e4b40)
        -1,
        9, // 12830101765377831150 (0xb20dad942d7530ee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 6608456252466856905 (0x5bb5f3f2d1ff03c9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 11581556388507579087 (0xa0b9f42c732672cf)
        -1,
        -1,
        -1,
        42, // 303171077776352777 (0x435147d2d082609)
        -1,
        -1,
        -1,
        12, // 16660075603158348667 (0xe7347a7e0167b37b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 15767399651709514010 (0xdad10e71a7c3711a)
        -1,
        3, // 11135700682730273994 (0x9a89f4c57f367cca)
        27, // 2233332526500179015 (0x1efe6419a35e6c47)
        -1,
        -1,
        -1,
        48, // 272938902478223003 (0x3c9ac7c5799769b)
        -1,
        38, // 3353026692530643551 (0x2e88580302b1225f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 16795472280822443986 (0xe915810d9d576fd2)
        -1,
        14, // 20550834561747904 (0x4902e009e40bc0)
        -1,
        46, // 1655899912373640900 (0x16faf0326ca19ec4)
        0, // 12043633595867471925 (0xa72394f20ea42035)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 278399437223174904 (0x3dd12d0295b22f8)
        -1,
        -1,
        -1,
        32, // 9184721153559411594 (0x7f76af39f6ecbb8a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 2820638147662176436 (0x2724eb736f51e0b4)
        28, // 9399569598683788115 (0x8271fabfbb1bb353)
        -1,
        -1,
        37, // 6495559916817274566 (0x5a24dd545328d6c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 912739619889070679 (0xcaab3d92fe9c257)
        19, // 18385558008839454818 (0xff269f992236c062)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 23929019635338486 (0x5503510b300cf6)
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 10948979493369205346 (0x97f296d6cb4ed262)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 12855437421065352381 (0xb267b03932dd34bd)
        13, // 13322419448647269014 (0xb8e2bde741603a96)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 15118853615111199867 (0xd1d0f54283d55c7b)
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 12349453446040947333 (0xab62127a9d7e8a85)
        -1,
        -1,
        -1,
        11, // 265732217136095669 (0x3b0120b27c621b5)
        -1,
        -1,
        -1,
        24, // 1160738526810134349 (0x101bc58a4fa0d74d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 6076126914224478050 (0x5452bd3c5c8a5762)
        -1,
        -1,
        -1,
        4, // 1905690934427542112 (0x1a725fcede3c6260)
        -1,
        41, // 3522764316158525704 (0x30e35f7b2c0d0108)
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 12229416881875790712 (0xa9b79ddc1e5f2b78)
        33, // 7074195289287635309 (0x622c972289bb316d)
        -1,
        -1,
        36, // 2297793839606493168 (0x1fe36752a8d36ff0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 2141567045412612093 (0x1db85fe19c8067fd)
        -1,
        40, // 14409207444294310909 (0xc7f7c9d3cc139bfd)
        16, // 17281866222126544480 (0xefd585c409acb660)
        31, // 1282611406117652727 (0x11ccc0473e81c8f7)
        -1,
        -1,
        -1,
        10, // 2068098868080305539 (0x1cb35cf698506583)
        -1,
        -1,
        -1,
        17, // 288168163366837107 (0x3ffc76af50e9b73)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 8275211616246439533 (0x72d7751efb8e1e6d)
        -1,
        -1,
        -1,
        -1,
        29, // 6530765490906464440 (0x5aa1f09cccdc00b8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 2245237043399206525 (0x1f28af31f85ba67d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 22239886292421639 (0x4f030f0a4e0c07)
        -1,
        -1,
        -1,
        1, // 1921725540679377063 (0x1aab57328ffd60a7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 9663440672952711834 (0x861b7017cb687a9a)
        -1,
        21, // 716549615513879380 (0x9f1b21430a5c354)
        -1,
    };
    for (int i=0; i < 1; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_states_hash_sdb, dataset=states, type=hash, hash=hash_sdb
void check_states_hash_sdb() {
    assert(lookup_states_hash_sdb("CONNECTICUT") == 6);
    assert(lookup_states_hash_sdb("MONTANA") == 25);
    assert(lookup_states_hash_sdb("GEORGIA") == 9);
    assert(lookup_states_hash_sdb("NEW MEXICO") == 30);
    assert(lookup_states_hash_sdb("DELAWARE") == 7);
    assert(lookup_states_hash_sdb("TEXAS") == 42);
    assert(lookup_states_hash_sdb("ILLINOIS") == 12);
    assert(lookup_states_hash_sdb("WYOMING") == 49);
    assert(lookup_states_hash_sdb("ARKANSAS") == 3);
    assert(lookup_states_hash_sdb("NEVADA") == 27);
    assert(lookup_states_hash_sdb("WISCONSIN") == 48);
    assert(lookup_states_hash_sdb("RHODE ISLAND") == 38);
    assert(lookup_states_hash_sdb("MINNESOTA") == 22);
    assert(lookup_states_hash_sdb("IOWA") == 14);
    assert(lookup_states_hash_sdb("WASHINGTON") == 46);
    assert(lookup_states_hash_sdb("ALABAMA") == 0);
    assert(lookup_states_hash_sdb("MAINE") == 18);
    assert(lookup_states_hash_sdb("NORTH CAROLINA") == 32);
    assert(lookup_states_hash_sdb("OKLAHOMA") == 35);
    assert(lookup_states_hash_sdb("NEW HAMPSHIRE") == 28);
    assert(lookup_states_hash_sdb("PENNSYLVANIA") == 37);
    assert(lookup_states_hash_sdb("NEBRASKA") == 26);
    assert(lookup_states_hash_sdb("MARYLAND") == 19);
    assert(lookup_states_hash_sdb("UTAH") == 43);
    assert(lookup_states_hash_sdb("MASSACHUSETTS") == 20);
    assert(lookup_states_hash_sdb("FLORIDA") == 8);
    assert(lookup_states_hash_sdb("INDIANA") == 13);
    assert(lookup_states_hash_sdb("VERMONT") == 44);
    assert(lookup_states_hash_sdb("COLORADO") == 5);
    assert(lookup_states_hash_sdb("IDAHO") == 11);
    assert(lookup_states_hash_sdb("MISSOURI") == 24);
    assert(lookup_states_hash_sdb("WEST VIRGINIA") == 47);
    assert(lookup_states_hash_sdb("CALIFORNIA") == 4);
    assert(lookup_states_hash_sdb("TENNESSEE") == 41);
    assert(lookup_states_hash_sdb("ARIZONA") == 2);
    assert(lookup_states_hash_sdb("NORTH DAKOTA") == 33);
    assert(lookup_states_hash_sdb("OREGON") == 36);
    assert(lookup_states_hash_sdb("KANSAS") == 15);
    assert(lookup_states_hash_sdb("SOUTH DAKOTA") == 40);
    assert(lookup_states_hash_sdb("KENTUCKY") == 16);
    assert(lookup_states_hash_sdb("NEW YORK") == 31);
    assert(lookup_states_hash_sdb("HAWAII") == 10);
    assert(lookup_states_hash_sdb("LOUISIANA") == 17);
    assert(lookup_states_hash_sdb("VIRGINIA") == 45);
    assert(lookup_states_hash_sdb("NEW JERSEY") == 29);
    assert(lookup_states_hash_sdb("MISSISSIPPI") == 23);
    assert(lookup_states_hash_sdb("OHIO") == 34);
    assert(lookup_states_hash_sdb("ALASKA") == 1);
    assert(lookup_states_hash_sdb("SOUTH CAROLINA") == 39);
    assert(lookup_states_hash_sdb("MICHIGAN") == 21);
}
