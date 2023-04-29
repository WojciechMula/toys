//lookup: dataset=c, name=lookup_c_split, type=split
int lookup_c_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "if") {
                return 0;
            }
            if (s == "do") {
                return 1;
            }
        }
        break;
        case 3: {
            if (s == "int") {
                return 2;
            }
            if (s == "for") {
                return 3;
            }
        }
        break;
        case 4: {
            switch (s[1]) {
                case 'a': { // 0x61
                    if (s == "case") {
                        return 4;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "char") {
                        return 5;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "auto") {
                        return 6;
                    }
                }
                break;
                case 'o': { // 0x6f
                    switch (s[0]) {
                        case 'g': { // 0x67
                            if (s == "goto") {
                                return 7;
                            }
                        }
                        break;
                        case 'l': { // 0x6c
                            if (s == "long") {
                                return 9;
                            }
                        }
                        break;
                        case 'v': { // 0x76
                            if (s == "void") {
                                return 10;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "else") {
                        return 8;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "enum") {
                        return 11;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'f': { // 0x66
                    if (s == "float") {
                        return 12;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "short") {
                        return 13;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "union") {
                        return 14;
                    }
                }
                break;
                case 'b': { // 0x62
                    if (s == "break") {
                        return 15;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "while") {
                        return 16;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "const") {
                        return 17;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[2]) {
                case 'u': { // 0x75
                    if (s == "double") {
                        return 18;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "static") {
                        return 19;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "extern") {
                        return 20;
                    }
                    if (s == "return") {
                        return 22;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "struct") {
                        return 21;
                    }
                }
                break;
                case 'z': { // 0x7a
                    if (s == "sizeof") {
                        return 23;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "switch") {
                        return 24;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "signed") {
                        return 25;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            if (s == "typedef") {
                return 26;
            }
            if (s == "default") {
                return 27;
            }
        }
        break;
        case 8: {
            switch (s[0]) {
                case 'u': { // 0x75
                    if (s == "unsigned") {
                        return 28;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "continue") {
                        return 29;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "register") {
                        return 30;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "volatile") {
                        return 31;
                    }
                }
                break;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=c, name=check_c_split, type=split
void check_c_split() {
    assert(lookup_c_split("if") == 0);
    assert(lookup_c_split("do") == 1);
    assert(lookup_c_split("int") == 2);
    assert(lookup_c_split("for") == 3);
    assert(lookup_c_split("case") == 4);
    assert(lookup_c_split("char") == 5);
    assert(lookup_c_split("auto") == 6);
    assert(lookup_c_split("goto") == 7);
    assert(lookup_c_split("else") == 8);
    assert(lookup_c_split("long") == 9);
    assert(lookup_c_split("void") == 10);
    assert(lookup_c_split("enum") == 11);
    assert(lookup_c_split("float") == 12);
    assert(lookup_c_split("short") == 13);
    assert(lookup_c_split("union") == 14);
    assert(lookup_c_split("break") == 15);
    assert(lookup_c_split("while") == 16);
    assert(lookup_c_split("const") == 17);
    assert(lookup_c_split("double") == 18);
    assert(lookup_c_split("static") == 19);
    assert(lookup_c_split("extern") == 20);
    assert(lookup_c_split("struct") == 21);
    assert(lookup_c_split("return") == 22);
    assert(lookup_c_split("sizeof") == 23);
    assert(lookup_c_split("switch") == 24);
    assert(lookup_c_split("signed") == 25);
    assert(lookup_c_split("typedef") == 26);
    assert(lookup_c_split("default") == 27);
    assert(lookup_c_split("unsigned") == 28);
    assert(lookup_c_split("continue") == 29);
    assert(lookup_c_split("register") == 30);
    assert(lookup_c_split("volatile") == 31);
}
