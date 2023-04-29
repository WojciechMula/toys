//lookup: dataset=modula2, name=lookup_modula2_split, type=split
int lookup_modula2_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[0]) {
                case 'B': { // 0x42
                    if (s == "BY") {
                        return 3;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DO") {
                        return 8;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "IF") {
                        return 16;
                    }
                    if (s == "IN") {
                        return 19;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OF") {
                        return 24;
                    }
                    if (s == "OR") {
                        return 25;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TO") {
                        return 34;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "AND") {
                        return 0;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DIV") {
                        return 7;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "END") {
                        return 11;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FOR") {
                        return 14;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MOD") {
                        return 21;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NOT") {
                        return 23;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SET") {
                        return 32;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "VAR") {
                        return 37;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[1]) {
                case 'A': { // 0x41
                    if (s == "CASE") {
                        return 4;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "ELSE") {
                        return 9;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "EXIT") {
                        return 12;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "FROM") {
                        return 15;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "LOOP") {
                        return 20;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "THEN") {
                        return 33;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "TYPE") {
                        return 35;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "WITH") {
                        return 39;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "ARRAY") {
                        return 1;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "BEGIN") {
                        return 2;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "CONST") {
                        return 5;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "ELSIF") {
                        return 10;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "UNTIL") {
                        return 36;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WHILE") {
                        return 38;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[0]) {
                case 'E': { // 0x45
                    if (s == "EXPORT") {
                        return 13;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "IMPORT") {
                        return 18;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MODULE") {
                        return 22;
                    }
                }
                break;
                case 'R': { // 0x52
                    switch (s[2]) {
                        case 'C': { // 0x43
                            if (s == "RECORD") {
                                return 29;
                            }
                        }
                        break;
                        case 'P': { // 0x50
                            if (s == "REPEAT") {
                                return 30;
                            }
                        }
                        break;
                        case 'T': { // 0x54
                            if (s == "RETURN") {
                                return 31;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            if (s == "POINTER") {
                return 26;
            }
        }
        break;
        case 9: {
            if (s == "PROCEDURE") {
                return 27;
            }
            if (s == "QUALIFIED") {
                return 28;
            }
        }
        break;
        case 10: {
            if (s == "DEFINITION") {
                return 6;
            }
        }
        break;
        case 14: {
            if (s == "IMPLEMENTATION") {
                return 17;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=modula2, name=check_modula2_split, type=split
void check_modula2_split() {
    assert(lookup_modula2_split("AND") == 0);
    assert(lookup_modula2_split("ARRAY") == 1);
    assert(lookup_modula2_split("BEGIN") == 2);
    assert(lookup_modula2_split("BY") == 3);
    assert(lookup_modula2_split("CASE") == 4);
    assert(lookup_modula2_split("CONST") == 5);
    assert(lookup_modula2_split("DEFINITION") == 6);
    assert(lookup_modula2_split("DIV") == 7);
    assert(lookup_modula2_split("DO") == 8);
    assert(lookup_modula2_split("ELSE") == 9);
    assert(lookup_modula2_split("ELSIF") == 10);
    assert(lookup_modula2_split("END") == 11);
    assert(lookup_modula2_split("EXIT") == 12);
    assert(lookup_modula2_split("EXPORT") == 13);
    assert(lookup_modula2_split("FOR") == 14);
    assert(lookup_modula2_split("FROM") == 15);
    assert(lookup_modula2_split("IF") == 16);
    assert(lookup_modula2_split("IMPLEMENTATION") == 17);
    assert(lookup_modula2_split("IMPORT") == 18);
    assert(lookup_modula2_split("IN") == 19);
    assert(lookup_modula2_split("LOOP") == 20);
    assert(lookup_modula2_split("MOD") == 21);
    assert(lookup_modula2_split("MODULE") == 22);
    assert(lookup_modula2_split("NOT") == 23);
    assert(lookup_modula2_split("OF") == 24);
    assert(lookup_modula2_split("OR") == 25);
    assert(lookup_modula2_split("POINTER") == 26);
    assert(lookup_modula2_split("PROCEDURE") == 27);
    assert(lookup_modula2_split("QUALIFIED") == 28);
    assert(lookup_modula2_split("RECORD") == 29);
    assert(lookup_modula2_split("REPEAT") == 30);
    assert(lookup_modula2_split("RETURN") == 31);
    assert(lookup_modula2_split("SET") == 32);
    assert(lookup_modula2_split("THEN") == 33);
    assert(lookup_modula2_split("TO") == 34);
    assert(lookup_modula2_split("TYPE") == 35);
    assert(lookup_modula2_split("UNTIL") == 36);
    assert(lookup_modula2_split("VAR") == 37);
    assert(lookup_modula2_split("WHILE") == 38);
    assert(lookup_modula2_split("WITH") == 39);
}
