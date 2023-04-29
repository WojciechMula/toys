//lookup: dataset=modula, name=lookup_modula_split, type=split
int lookup_modula_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[0]) {
                case 'B': { // 0x42
                    if (s == "BY") {
                        return 4;
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
                        return 20;
                    }
                    if (s == "IN") {
                        return 23;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OF") {
                        return 31;
                    }
                    if (s == "OR") {
                        return 32;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TO") {
                        return 42;
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
                        return 18;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MOD") {
                        return 27;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NOT") {
                        return 29;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "REF") {
                        return 37;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SET") {
                        return 40;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TRY") {
                        return 43;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "VAR") {
                        return 50;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[1]) {
                case 'I': { // 0x49
                    if (s == "BITS") {
                        return 3;
                    }
                    if (s == "WITH") {
                        return 52;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "CASE") {
                        return 5;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "ELSE") {
                        return 9;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "EVAL") {
                        return 12;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "EXIT") {
                        return 15;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "FROM") {
                        return 19;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "LOCK") {
                        return 25;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "THEN") {
                        return 41;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "TYPE") {
                        return 44;
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
                        return 6;
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
                        return 47;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "VALUE") {
                        return 49;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WHILE") {
                        return 51;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[4]) {
                case 'P': { // 0x50
                    if (s == "EXCEPT") {
                        return 13;
                    }
                }
                break;
                case 'R': { // 0x52
                    switch (s[2]) {
                        case 'P': { // 0x50
                            if (s == "IMPORT") {
                                return 21;
                            }
                        }
                        break;
                        case 'C': { // 0x43
                            if (s == "RECORD") {
                                return 36;
                            }
                        }
                        break;
                        case 'T': { // 0x54
                            if (s == "RETURN") {
                                return 39;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "INLINE") {
                        return 24;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "MODULE") {
                        return 28;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "OBJECT") {
                        return 30;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "RAISES") {
                        return 34;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "REPEAT") {
                        return 38;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "UNSAFE") {
                        return 46;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[0]) {
                case 'E': { // 0x45
                    if (s == "EXPORTS") {
                        return 16;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FINALLY") {
                        return 17;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "METHODS") {
                        return 26;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[0]) {
                case 'R': { // 0x52
                    if (s == "READONLY") {
                        return 35;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TYPECASE") {
                        return 45;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "UNTRACED") {
                        return 48;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 'E': { // 0x45
                    if (s == "EXCEPTION") {
                        return 14;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "INTERFACE") {
                        return 22;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "PROCEDURE") {
                        return 33;
                    }
                }
                break;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=modula, name=check_modula_split, type=split
void check_modula_split() {
    assert(lookup_modula_split("AND") == 0);
    assert(lookup_modula_split("ARRAY") == 1);
    assert(lookup_modula_split("BEGIN") == 2);
    assert(lookup_modula_split("BITS") == 3);
    assert(lookup_modula_split("BY") == 4);
    assert(lookup_modula_split("CASE") == 5);
    assert(lookup_modula_split("CONST") == 6);
    assert(lookup_modula_split("DIV") == 7);
    assert(lookup_modula_split("DO") == 8);
    assert(lookup_modula_split("ELSE") == 9);
    assert(lookup_modula_split("ELSIF") == 10);
    assert(lookup_modula_split("END") == 11);
    assert(lookup_modula_split("EVAL") == 12);
    assert(lookup_modula_split("EXCEPT") == 13);
    assert(lookup_modula_split("EXCEPTION") == 14);
    assert(lookup_modula_split("EXIT") == 15);
    assert(lookup_modula_split("EXPORTS") == 16);
    assert(lookup_modula_split("FINALLY") == 17);
    assert(lookup_modula_split("FOR") == 18);
    assert(lookup_modula_split("FROM") == 19);
    assert(lookup_modula_split("IF") == 20);
    assert(lookup_modula_split("IMPORT") == 21);
    assert(lookup_modula_split("INTERFACE") == 22);
    assert(lookup_modula_split("IN") == 23);
    assert(lookup_modula_split("INLINE") == 24);
    assert(lookup_modula_split("LOCK") == 25);
    assert(lookup_modula_split("METHODS") == 26);
    assert(lookup_modula_split("MOD") == 27);
    assert(lookup_modula_split("MODULE") == 28);
    assert(lookup_modula_split("NOT") == 29);
    assert(lookup_modula_split("OBJECT") == 30);
    assert(lookup_modula_split("OF") == 31);
    assert(lookup_modula_split("OR") == 32);
    assert(lookup_modula_split("PROCEDURE") == 33);
    assert(lookup_modula_split("RAISES") == 34);
    assert(lookup_modula_split("READONLY") == 35);
    assert(lookup_modula_split("RECORD") == 36);
    assert(lookup_modula_split("REF") == 37);
    assert(lookup_modula_split("REPEAT") == 38);
    assert(lookup_modula_split("RETURN") == 39);
    assert(lookup_modula_split("SET") == 40);
    assert(lookup_modula_split("THEN") == 41);
    assert(lookup_modula_split("TO") == 42);
    assert(lookup_modula_split("TRY") == 43);
    assert(lookup_modula_split("TYPE") == 44);
    assert(lookup_modula_split("TYPECASE") == 45);
    assert(lookup_modula_split("UNSAFE") == 46);
    assert(lookup_modula_split("UNTIL") == 47);
    assert(lookup_modula_split("UNTRACED") == 48);
    assert(lookup_modula_split("VALUE") == 49);
    assert(lookup_modula_split("VAR") == 50);
    assert(lookup_modula_split("WHILE") == 51);
    assert(lookup_modula_split("WITH") == 52);
}
