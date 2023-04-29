//lookup: dataset=snellerbuiltin, name=lookup_snellerbuiltin_split, type=split
int lookup_snellerbuiltin_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "LN") {
                return 33;
            }
            if (s == "PI") {
                return 40;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "ABS") {
                        return 19;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "EXP") {
                        return 28;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LOG") {
                        return 35;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "POW") {
                        return 38;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SIN") {
                        return 43;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "COS") {
                        return 44;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TAN") {
                        return 45;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[1]) {
                case 'R': { // 0x52
                    if (s == "TRIM") {
                        return 1;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "SIGN") {
                        return 20;
                    }
                    if (s == "SIZE") {
                        return 101;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "CEIL") {
                        return 25;
                    }
                }
                break;
                case 'Q': { // 0x51
                    if (s == "SQRT") {
                        return 26;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "CBRT") {
                        return 27;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "EXP2") {
                        return 30;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "LN1P") {
                        return 34;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "LOG2") {
                        return 36;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "ASIN") {
                        return 46;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "ACOS") {
                        return 47;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "ATAN") {
                        return 48;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'L': { // 0x4c
                    switch (s[2]) {
                        case 'R': { // 0x52
                            if (s == "LTRIM") {
                                return 2;
                            }
                        }
                        break;
                        case 'W': { // 0x57
                            if (s == "LOWER") {
                                return 5;
                            }
                        }
                        break;
                        case 'G': { // 0x47
                            if (s == "LOG10") {
                                return 37;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "LEAST") {
                                return 50;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "RTRIM") {
                        return 3;
                    }
                    if (s == "ROUND") {
                        return 21;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "UPPER") {
                        return 4;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TRUNC") {
                        return 23;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FLOOR") {
                        return 24;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "EXPM1") {
                        return 29;
                    }
                    if (s == "EXP10") {
                        return 31;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "HYPOT") {
                        return 32;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "ATAN2") {
                        return 49;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            if (s == "CONCAT") {
                return 0;
            }
        }
        break;
        case 7: {
            if (s == "DEGREES") {
                return 41;
            }
            if (s == "RADIANS") {
                return 42;
            }
        }
        break;
        case 8: {
            switch (s[2]) {
                case 'N': { // 0x4e
                    if (s == "CONTAINS") {
                        return 6;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "POW_UINT") {
                        return 39;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "GREATEST") {
                        return 51;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "GEO_HASH") {
                        return 96;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "TYPE_BIT") {
                        return 116;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 'E': { // 0x45
                    if (s == "EQUALS_CI") {
                        return 8;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SUBSTRING") {
                        return 16;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "BIT_COUNT") {
                        return 18;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MAKE_LIST") {
                        return 114;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            switch (s[9]) {
                case 'T': { // 0x54
                    if (s == "SPLIT_PART") {
                        return 17;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "ROUND_EVEN") {
                        return 22;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "GEO_TILE_X") {
                        return 97;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "GEO_TILE_Y") {
                        return 98;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "ARRAY_SIZE") {
                        return 103;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "TABLE_GLOB") {
                        return 105;
                    }
                }
                break;
            }
        }
        break;
        case 11: {
            switch (s[1]) {
                case 'O': { // 0x4f
                    if (s == "CONTAINS_CI") {
                        return 7;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "CHAR_LENGTH") {
                        return 14;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "GEO_TILE_ES") {
                        return 99;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "IN_SUBQUERY") {
                        return 107;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "TIME_BUCKET") {
                        return 113;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "MAKE_STRUCT") {
                        return 115;
                    }
                }
                break;
            }
        }
        break;
        case 12: {
            switch (s[0]) {
                case 'E': { // 0x45
                    if (s == "EQUALS_FUZZY") {
                        return 9;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OCTET_LENGTH") {
                        return 13;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "IS_SUBNET_OF") {
                        return 15;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WIDTH_BUCKET") {
                        return 52;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DATE_ADD_DAY") {
                        return 58;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "GEO_DISTANCE") {
                        return 100;
                    }
                }
                break;
            }
        }
        break;
        case 13: {
            switch (s[9]) {
                case 'H': { // 0x48
                    if (s == "DATE_ADD_HOUR") {
                        return 57;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "DATE_ADD_WEEK") {
                        return 59;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_ADD_YEAR") {
                        return 62;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "DATE_DIFF_DAY") {
                        return 68;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "TO_UNIX_EPOCH") {
                        return 94;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "TO_UNIX_MICRO") {
                        return 95;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TABLE_PATTERN") {
                        return 106;
                    }
                }
                break;
            }
        }
        break;
        case 14: {
            switch (s[10]) {
                case 'U': { // 0x55
                    if (s == "CONTAINS_FUZZY") {
                        return 11;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "DATE_ADD_MONTH") {
                        return 60;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_DIFF_HOUR") {
                        return 67;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "DATE_DIFF_WEEK") {
                        return 69;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_DIFF_YEAR") {
                        return 72;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "DATE_TRUNC_DAY") {
                        return 89;
                    }
                    if (s == "DATE_TRUNC_DOW") {
                        return 90;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "ARRAY_CONTAINS") {
                        return 102;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "ARRAY_POSITION") {
                        return 104;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "IN_REPLACEMENT") {
                        return 108;
                    }
                }
                break;
            }
        }
        break;
        case 15: {
            switch (s[11]) {
                case 'C': { // 0x43
                    if (s == "DATE_ADD_SECOND") {
                        return 55;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "DATE_ADD_MINUTE") {
                        return 56;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "DATE_DIFF_MONTH") {
                        return 70;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_TRUNC_HOUR") {
                        return 88;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_TRUNC_YEAR") {
                        return 93;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "ASSERT_ION_TYPE") {
                        return 117;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "PARTITION_VALUE") {
                        return 118;
                    }
                }
                break;
            }
        }
        break;
        case 16: {
            switch (s[15]) {
                case 'R': { // 0x52
                    if (s == "DATE_ADD_QUARTER") {
                        return 61;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DATE_DIFF_SECOND") {
                        return 65;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "DATE_DIFF_MINUTE") {
                        return 66;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_EXTRACT_DAY") {
                        return 78;
                    }
                    if (s == "DATE_EXTRACT_DOY") {
                        return 80;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "DATE_EXTRACT_DOW") {
                        return 79;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_TRUNC_MONTH") {
                        return 91;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "HASH_REPLACEMENT") {
                        return 109;
                    }
                    if (s == "LIST_REPLACEMENT") {
                        return 112;
                    }
                }
                break;
            }
        }
        break;
        case 17: {
            switch (s[13]) {
                case 'R': { // 0x52
                    if (s == "DATE_DIFF_QUARTER") {
                        return 71;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_EXTRACT_HOUR") {
                        return 77;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_EXTRACT_YEAR") {
                        return 83;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "DATE_TRUNC_SECOND") {
                        return 86;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "DATE_TRUNC_MINUTE") {
                        return 87;
                    }
                }
                break;
            }
        }
        break;
        case 18: {
            switch (s[1]) {
                case 'A': { // 0x41
                    if (s == "DATE_EXTRACT_MONTH") {
                        return 81;
                    }
                    if (s == "DATE_TRUNC_QUARTER") {
                        return 92;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "SCALAR_REPLACEMENT") {
                        return 110;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "STRUCT_REPLACEMENT") {
                        return 111;
                    }
                }
                break;
            }
        }
        break;
        case 19: {
            if (s == "DATE_EXTRACT_SECOND") {
                return 75;
            }
            if (s == "DATE_EXTRACT_MINUTE") {
                return 76;
            }
        }
        break;
        case 20: {
            switch (s[11]) {
                case 'Y': { // 0x59
                    if (s == "EQUALS_FUZZY_UNICODE") {
                        return 10;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "DATE_ADD_MICROSECOND") {
                        return 53;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "DATE_ADD_MILLISECOND") {
                        return 54;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "DATE_EXTRACT_QUARTER") {
                        return 82;
                    }
                }
                break;
            }
        }
        break;
        case 21: {
            if (s == "DATE_DIFF_MICROSECOND") {
                return 63;
            }
            if (s == "DATE_DIFF_MILLISECOND") {
                return 64;
            }
        }
        break;
        case 22: {
            switch (s[13]) {
                case 'Y': { // 0x59
                    if (s == "CONTAINS_FUZZY_UNICODE") {
                        return 12;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "DATE_TRUNC_MICROSECOND") {
                        return 84;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "DATE_TRUNC_MILLISECOND") {
                        return 85;
                    }
                }
                break;
            }
        }
        break;
        case 24: {
            if (s == "DATE_EXTRACT_MICROSECOND") {
                return 73;
            }
            if (s == "DATE_EXTRACT_MILLISECOND") {
                return 74;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=snellerbuiltin, name=check_snellerbuiltin_split, type=split
void check_snellerbuiltin_split() {
    assert(lookup_snellerbuiltin_split("CONCAT") == 0);
    assert(lookup_snellerbuiltin_split("TRIM") == 1);
    assert(lookup_snellerbuiltin_split("LTRIM") == 2);
    assert(lookup_snellerbuiltin_split("RTRIM") == 3);
    assert(lookup_snellerbuiltin_split("UPPER") == 4);
    assert(lookup_snellerbuiltin_split("LOWER") == 5);
    assert(lookup_snellerbuiltin_split("CONTAINS") == 6);
    assert(lookup_snellerbuiltin_split("CONTAINS_CI") == 7);
    assert(lookup_snellerbuiltin_split("EQUALS_CI") == 8);
    assert(lookup_snellerbuiltin_split("EQUALS_FUZZY") == 9);
    assert(lookup_snellerbuiltin_split("EQUALS_FUZZY_UNICODE") == 10);
    assert(lookup_snellerbuiltin_split("CONTAINS_FUZZY") == 11);
    assert(lookup_snellerbuiltin_split("CONTAINS_FUZZY_UNICODE") == 12);
    assert(lookup_snellerbuiltin_split("OCTET_LENGTH") == 13);
    assert(lookup_snellerbuiltin_split("CHAR_LENGTH") == 14);
    assert(lookup_snellerbuiltin_split("IS_SUBNET_OF") == 15);
    assert(lookup_snellerbuiltin_split("SUBSTRING") == 16);
    assert(lookup_snellerbuiltin_split("SPLIT_PART") == 17);
    assert(lookup_snellerbuiltin_split("BIT_COUNT") == 18);
    assert(lookup_snellerbuiltin_split("ABS") == 19);
    assert(lookup_snellerbuiltin_split("SIGN") == 20);
    assert(lookup_snellerbuiltin_split("ROUND") == 21);
    assert(lookup_snellerbuiltin_split("ROUND_EVEN") == 22);
    assert(lookup_snellerbuiltin_split("TRUNC") == 23);
    assert(lookup_snellerbuiltin_split("FLOOR") == 24);
    assert(lookup_snellerbuiltin_split("CEIL") == 25);
    assert(lookup_snellerbuiltin_split("SQRT") == 26);
    assert(lookup_snellerbuiltin_split("CBRT") == 27);
    assert(lookup_snellerbuiltin_split("EXP") == 28);
    assert(lookup_snellerbuiltin_split("EXPM1") == 29);
    assert(lookup_snellerbuiltin_split("EXP2") == 30);
    assert(lookup_snellerbuiltin_split("EXP10") == 31);
    assert(lookup_snellerbuiltin_split("HYPOT") == 32);
    assert(lookup_snellerbuiltin_split("LN") == 33);
    assert(lookup_snellerbuiltin_split("LN1P") == 34);
    assert(lookup_snellerbuiltin_split("LOG") == 35);
    assert(lookup_snellerbuiltin_split("LOG2") == 36);
    assert(lookup_snellerbuiltin_split("LOG10") == 37);
    assert(lookup_snellerbuiltin_split("POW") == 38);
    assert(lookup_snellerbuiltin_split("POW_UINT") == 39);
    assert(lookup_snellerbuiltin_split("PI") == 40);
    assert(lookup_snellerbuiltin_split("DEGREES") == 41);
    assert(lookup_snellerbuiltin_split("RADIANS") == 42);
    assert(lookup_snellerbuiltin_split("SIN") == 43);
    assert(lookup_snellerbuiltin_split("COS") == 44);
    assert(lookup_snellerbuiltin_split("TAN") == 45);
    assert(lookup_snellerbuiltin_split("ASIN") == 46);
    assert(lookup_snellerbuiltin_split("ACOS") == 47);
    assert(lookup_snellerbuiltin_split("ATAN") == 48);
    assert(lookup_snellerbuiltin_split("ATAN2") == 49);
    assert(lookup_snellerbuiltin_split("LEAST") == 50);
    assert(lookup_snellerbuiltin_split("GREATEST") == 51);
    assert(lookup_snellerbuiltin_split("WIDTH_BUCKET") == 52);
    assert(lookup_snellerbuiltin_split("DATE_ADD_MICROSECOND") == 53);
    assert(lookup_snellerbuiltin_split("DATE_ADD_MILLISECOND") == 54);
    assert(lookup_snellerbuiltin_split("DATE_ADD_SECOND") == 55);
    assert(lookup_snellerbuiltin_split("DATE_ADD_MINUTE") == 56);
    assert(lookup_snellerbuiltin_split("DATE_ADD_HOUR") == 57);
    assert(lookup_snellerbuiltin_split("DATE_ADD_DAY") == 58);
    assert(lookup_snellerbuiltin_split("DATE_ADD_WEEK") == 59);
    assert(lookup_snellerbuiltin_split("DATE_ADD_MONTH") == 60);
    assert(lookup_snellerbuiltin_split("DATE_ADD_QUARTER") == 61);
    assert(lookup_snellerbuiltin_split("DATE_ADD_YEAR") == 62);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_MICROSECOND") == 63);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_MILLISECOND") == 64);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_SECOND") == 65);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_MINUTE") == 66);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_HOUR") == 67);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_DAY") == 68);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_WEEK") == 69);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_MONTH") == 70);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_QUARTER") == 71);
    assert(lookup_snellerbuiltin_split("DATE_DIFF_YEAR") == 72);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_MICROSECOND") == 73);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_MILLISECOND") == 74);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_SECOND") == 75);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_MINUTE") == 76);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_HOUR") == 77);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_DAY") == 78);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_DOW") == 79);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_DOY") == 80);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_MONTH") == 81);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_QUARTER") == 82);
    assert(lookup_snellerbuiltin_split("DATE_EXTRACT_YEAR") == 83);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_MICROSECOND") == 84);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_MILLISECOND") == 85);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_SECOND") == 86);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_MINUTE") == 87);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_HOUR") == 88);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_DAY") == 89);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_DOW") == 90);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_MONTH") == 91);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_QUARTER") == 92);
    assert(lookup_snellerbuiltin_split("DATE_TRUNC_YEAR") == 93);
    assert(lookup_snellerbuiltin_split("TO_UNIX_EPOCH") == 94);
    assert(lookup_snellerbuiltin_split("TO_UNIX_MICRO") == 95);
    assert(lookup_snellerbuiltin_split("GEO_HASH") == 96);
    assert(lookup_snellerbuiltin_split("GEO_TILE_X") == 97);
    assert(lookup_snellerbuiltin_split("GEO_TILE_Y") == 98);
    assert(lookup_snellerbuiltin_split("GEO_TILE_ES") == 99);
    assert(lookup_snellerbuiltin_split("GEO_DISTANCE") == 100);
    assert(lookup_snellerbuiltin_split("SIZE") == 101);
    assert(lookup_snellerbuiltin_split("ARRAY_CONTAINS") == 102);
    assert(lookup_snellerbuiltin_split("ARRAY_SIZE") == 103);
    assert(lookup_snellerbuiltin_split("ARRAY_POSITION") == 104);
    assert(lookup_snellerbuiltin_split("TABLE_GLOB") == 105);
    assert(lookup_snellerbuiltin_split("TABLE_PATTERN") == 106);
    assert(lookup_snellerbuiltin_split("IN_SUBQUERY") == 107);
    assert(lookup_snellerbuiltin_split("IN_REPLACEMENT") == 108);
    assert(lookup_snellerbuiltin_split("HASH_REPLACEMENT") == 109);
    assert(lookup_snellerbuiltin_split("SCALAR_REPLACEMENT") == 110);
    assert(lookup_snellerbuiltin_split("STRUCT_REPLACEMENT") == 111);
    assert(lookup_snellerbuiltin_split("LIST_REPLACEMENT") == 112);
    assert(lookup_snellerbuiltin_split("TIME_BUCKET") == 113);
    assert(lookup_snellerbuiltin_split("MAKE_LIST") == 114);
    assert(lookup_snellerbuiltin_split("MAKE_STRUCT") == 115);
    assert(lookup_snellerbuiltin_split("TYPE_BIT") == 116);
    assert(lookup_snellerbuiltin_split("ASSERT_ION_TYPE") == 117);
    assert(lookup_snellerbuiltin_split("PARTITION_VALUE") == 118);
}
