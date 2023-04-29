//lookup: dataset=states, name=lookup_states_split, type=split
int lookup_states_split(std::string_view s) {
    switch (s.size()) {
        case 4: {
            switch (s[0]) {
                case 'I': { // 0x49
                    if (s == "IOWA") {
                        return 14;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OHIO") {
                        return 34;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "UTAH") {
                        return 43;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'I': { // 0x49
                    if (s == "IDAHO") {
                        return 11;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MAINE") {
                        return 18;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TEXAS") {
                        return 42;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "ALASKA") {
                        return 1;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "HAWAII") {
                        return 10;
                    }
                }
                break;
                case 'K': { // 0x4b
                    if (s == "KANSAS") {
                        return 15;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NEVADA") {
                        return 27;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OREGON") {
                        return 36;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "ALABAMA") {
                        return 0;
                    }
                    if (s == "ARIZONA") {
                        return 2;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FLORIDA") {
                        return 8;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "GEORGIA") {
                        return 9;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "INDIANA") {
                        return 13;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MONTANA") {
                        return 25;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "VERMONT") {
                        return 44;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WYOMING") {
                        return 49;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[3]) {
                case 'A': { // 0x41
                    switch (s[0]) {
                        case 'A': { // 0x41
                            if (s == "ARKANSAS") {
                                return 3;
                            }
                        }
                        break;
                        case 'D': { // 0x44
                            if (s == "DELAWARE") {
                                return 7;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "OKLAHOMA") {
                                return 35;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "COLORADO") {
                        return 5;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "ILLINOIS") {
                        return 12;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "KENTUCKY") {
                        return 16;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "MARYLAND") {
                        return 19;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "MICHIGAN") {
                        return 21;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "MISSOURI") {
                        return 24;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "NEBRASKA") {
                        return 26;
                    }
                }
                break;
                case ' ': { // 0x20
                    if (s == "NEW YORK") {
                        return 31;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "VIRGINIA") {
                        return 45;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 'L': { // 0x4c
                    if (s == "LOUISIANA") {
                        return 17;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MINNESOTA") {
                        return 22;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TENNESSEE") {
                        return 41;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WISCONSIN") {
                        return 48;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            switch (s[4]) {
                case 'F': { // 0x46
                    if (s == "CALIFORNIA") {
                        return 4;
                    }
                }
                break;
                case 'J': { // 0x4a
                    if (s == "NEW JERSEY") {
                        return 29;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "NEW MEXICO") {
                        return 30;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "WASHINGTON") {
                        return 46;
                    }
                }
                break;
            }
        }
        break;
        case 11: {
            if (s == "CONNECTICUT") {
                return 6;
            }
            if (s == "MISSISSIPPI") {
                return 23;
            }
        }
        break;
        case 12: {
            switch (s[0]) {
                case 'N': { // 0x4e
                    if (s == "NORTH DAKOTA") {
                        return 33;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "PENNSYLVANIA") {
                        return 37;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "RHODE ISLAND") {
                        return 38;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SOUTH DAKOTA") {
                        return 40;
                    }
                }
                break;
            }
        }
        break;
        case 13: {
            switch (s[0]) {
                case 'M': { // 0x4d
                    if (s == "MASSACHUSETTS") {
                        return 20;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NEW HAMPSHIRE") {
                        return 28;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WEST VIRGINIA") {
                        return 47;
                    }
                }
                break;
            }
        }
        break;
        case 14: {
            if (s == "NORTH CAROLINA") {
                return 32;
            }
            if (s == "SOUTH CAROLINA") {
                return 39;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=states, name=check_states_split, type=split
void check_states_split() {
    assert(lookup_states_split("ALABAMA") == 0);
    assert(lookup_states_split("ALASKA") == 1);
    assert(lookup_states_split("ARIZONA") == 2);
    assert(lookup_states_split("ARKANSAS") == 3);
    assert(lookup_states_split("CALIFORNIA") == 4);
    assert(lookup_states_split("COLORADO") == 5);
    assert(lookup_states_split("CONNECTICUT") == 6);
    assert(lookup_states_split("DELAWARE") == 7);
    assert(lookup_states_split("FLORIDA") == 8);
    assert(lookup_states_split("GEORGIA") == 9);
    assert(lookup_states_split("HAWAII") == 10);
    assert(lookup_states_split("IDAHO") == 11);
    assert(lookup_states_split("ILLINOIS") == 12);
    assert(lookup_states_split("INDIANA") == 13);
    assert(lookup_states_split("IOWA") == 14);
    assert(lookup_states_split("KANSAS") == 15);
    assert(lookup_states_split("KENTUCKY") == 16);
    assert(lookup_states_split("LOUISIANA") == 17);
    assert(lookup_states_split("MAINE") == 18);
    assert(lookup_states_split("MARYLAND") == 19);
    assert(lookup_states_split("MASSACHUSETTS") == 20);
    assert(lookup_states_split("MICHIGAN") == 21);
    assert(lookup_states_split("MINNESOTA") == 22);
    assert(lookup_states_split("MISSISSIPPI") == 23);
    assert(lookup_states_split("MISSOURI") == 24);
    assert(lookup_states_split("MONTANA") == 25);
    assert(lookup_states_split("NEBRASKA") == 26);
    assert(lookup_states_split("NEVADA") == 27);
    assert(lookup_states_split("NEW HAMPSHIRE") == 28);
    assert(lookup_states_split("NEW JERSEY") == 29);
    assert(lookup_states_split("NEW MEXICO") == 30);
    assert(lookup_states_split("NEW YORK") == 31);
    assert(lookup_states_split("NORTH CAROLINA") == 32);
    assert(lookup_states_split("NORTH DAKOTA") == 33);
    assert(lookup_states_split("OHIO") == 34);
    assert(lookup_states_split("OKLAHOMA") == 35);
    assert(lookup_states_split("OREGON") == 36);
    assert(lookup_states_split("PENNSYLVANIA") == 37);
    assert(lookup_states_split("RHODE ISLAND") == 38);
    assert(lookup_states_split("SOUTH CAROLINA") == 39);
    assert(lookup_states_split("SOUTH DAKOTA") == 40);
    assert(lookup_states_split("TENNESSEE") == 41);
    assert(lookup_states_split("TEXAS") == 42);
    assert(lookup_states_split("UTAH") == 43);
    assert(lookup_states_split("VERMONT") == 44);
    assert(lookup_states_split("VIRGINIA") == 45);
    assert(lookup_states_split("WASHINGTON") == 46);
    assert(lookup_states_split("WEST VIRGINIA") == 47);
    assert(lookup_states_split("WISCONSIN") == 48);
    assert(lookup_states_split("WYOMING") == 49);
}
