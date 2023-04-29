//lookup: dataset=adadefs, name=lookup_adadefs_split, type=split
int lookup_adadefs_split(std::string_view s) {
    switch (s.size()) {
        case 3: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "aft") {
                        return 15;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "pos") {
                        return 39;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "val") {
                        return 51;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 't': { // 0x74
                    if (s == "true") {
                        return 13;
                    }
                }
                break;
                case 'b': { // 0x62
                    if (s == "base") {
                        return 16;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "emax") {
                        return 22;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "fore") {
                        return 26;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "last") {
                        return 29;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "pred") {
                        return 41;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "size") {
                        return 46;
                    }
                    if (s == "succ") {
                        return 49;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'f': { // 0x66
                    switch (s[1]) {
                        case 'a': { // 0x61
                            if (s == "false") {
                                return 3;
                            }
                        }
                        break;
                        case 'l': { // 0x6c
                            if (s == "float") {
                                return 4;
                            }
                        }
                        break;
                        case 'i': { // 0x69
                            if (s == "first") {
                                return 24;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "count") {
                        return 19;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "delta") {
                        return 20;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "image") {
                        return 27;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "large") {
                        return 28;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "range") {
                        return 42;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "small") {
                        return 47;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "value") {
                        return 52;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "width") {
                        return 53;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[0]) {
                case 's': { // 0x73
                    if (s == "string") {
                        return 11;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "digits") {
                        return 21;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "length") {
                        return 31;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[0]) {
                case 'b': { // 0x62
                    if (s == "boolean") {
                        return 0;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "integer") {
                        return 5;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "natural") {
                        return 6;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "address") {
                        return 14;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "epsilon") {
                        return 23;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "lastbit") {
                        return 30;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[6]) {
                case 'v': { // 0x76
                    if (s == "positive") {
                        return 8;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "callable") {
                        return 17;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "firstbit") {
                        return 25;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "mantissa") {
                        return 38;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "position") {
                        return 40;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            if (s == "character") {
                return 1;
            }
            if (s == "safe_emax") {
                return 43;
            }
        }
        break;
        case 10: {
            switch (s[5]) {
                case 'l': { // 0x6c
                    if (s == "safe_large") {
                        return 44;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "safe_small") {
                        return 45;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "terminated") {
                        return 50;
                    }
                }
                break;
            }
        }
        break;
        case 11: {
            if (s == "constrained") {
                return 18;
            }
        }
        break;
        case 12: {
            switch (s[10]) {
                case 'a': { // 0x61
                    if (s == "machine_emax") {
                        return 32;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "machine_emin") {
                        return 33;
                    }
                }
                break;
                case 'z': { // 0x7a
                    if (s == "storage_size") {
                        return 48;
                    }
                }
                break;
            }
        }
        break;
        case 13: {
            switch (s[0]) {
                case 'n': { // 0x6e
                    if (s == "numeric_error") {
                        return 7;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "program_error") {
                        return 9;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "storage_error") {
                        return 10;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "tasking_error") {
                        return 12;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "machine_radix") {
                        return 36;
                    }
                }
                break;
            }
        }
        break;
        case 14: {
            if (s == "machine_rounds") {
                return 37;
            }
        }
        break;
        case 16: {
            if (s == "constraint_error") {
                return 2;
            }
            if (s == "machine_mantissa") {
                return 34;
            }
        }
        break;
        case 17: {
            if (s == "machine_overflows") {
                return 35;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=adadefs, name=check_adadefs_split, type=split
void check_adadefs_split() {
    assert(lookup_adadefs_split("boolean") == 0);
    assert(lookup_adadefs_split("character") == 1);
    assert(lookup_adadefs_split("constraint_error") == 2);
    assert(lookup_adadefs_split("false") == 3);
    assert(lookup_adadefs_split("float") == 4);
    assert(lookup_adadefs_split("integer") == 5);
    assert(lookup_adadefs_split("natural") == 6);
    assert(lookup_adadefs_split("numeric_error") == 7);
    assert(lookup_adadefs_split("positive") == 8);
    assert(lookup_adadefs_split("program_error") == 9);
    assert(lookup_adadefs_split("storage_error") == 10);
    assert(lookup_adadefs_split("string") == 11);
    assert(lookup_adadefs_split("tasking_error") == 12);
    assert(lookup_adadefs_split("true") == 13);
    assert(lookup_adadefs_split("address") == 14);
    assert(lookup_adadefs_split("aft") == 15);
    assert(lookup_adadefs_split("base") == 16);
    assert(lookup_adadefs_split("callable") == 17);
    assert(lookup_adadefs_split("constrained") == 18);
    assert(lookup_adadefs_split("count") == 19);
    assert(lookup_adadefs_split("delta") == 20);
    assert(lookup_adadefs_split("digits") == 21);
    assert(lookup_adadefs_split("emax") == 22);
    assert(lookup_adadefs_split("epsilon") == 23);
    assert(lookup_adadefs_split("first") == 24);
    assert(lookup_adadefs_split("firstbit") == 25);
    assert(lookup_adadefs_split("fore") == 26);
    assert(lookup_adadefs_split("image") == 27);
    assert(lookup_adadefs_split("large") == 28);
    assert(lookup_adadefs_split("last") == 29);
    assert(lookup_adadefs_split("lastbit") == 30);
    assert(lookup_adadefs_split("length") == 31);
    assert(lookup_adadefs_split("machine_emax") == 32);
    assert(lookup_adadefs_split("machine_emin") == 33);
    assert(lookup_adadefs_split("machine_mantissa") == 34);
    assert(lookup_adadefs_split("machine_overflows") == 35);
    assert(lookup_adadefs_split("machine_radix") == 36);
    assert(lookup_adadefs_split("machine_rounds") == 37);
    assert(lookup_adadefs_split("mantissa") == 38);
    assert(lookup_adadefs_split("pos") == 39);
    assert(lookup_adadefs_split("position") == 40);
    assert(lookup_adadefs_split("pred") == 41);
    assert(lookup_adadefs_split("range") == 42);
    assert(lookup_adadefs_split("safe_emax") == 43);
    assert(lookup_adadefs_split("safe_large") == 44);
    assert(lookup_adadefs_split("safe_small") == 45);
    assert(lookup_adadefs_split("size") == 46);
    assert(lookup_adadefs_split("small") == 47);
    assert(lookup_adadefs_split("storage_size") == 48);
    assert(lookup_adadefs_split("succ") == 49);
    assert(lookup_adadefs_split("terminated") == 50);
    assert(lookup_adadefs_split("val") == 51);
    assert(lookup_adadefs_split("value") == 52);
    assert(lookup_adadefs_split("width") == 53);
}
