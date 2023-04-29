//lookup: dataset=ada, name=lookup_ada_split, type=split
int lookup_ada_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[1]) {
                case 't': { // 0x74
                    if (s == "at") {
                        return 32;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "do") {
                        return 43;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "of") {
                        return 45;
                    }
                    if (s == "if") {
                        return 54;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "or") {
                        return 46;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "in") {
                        return 52;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "is") {
                        return 53;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'e': { // 0x65
                    if (s == "end") {
                        return 8;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "not") {
                        return 11;
                    }
                    if (s == "new") {
                        return 27;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "for") {
                        return 21;
                    }
                }
                break;
                case 'a': { // 0x61
                    switch (s[1]) {
                        case 'n': { // 0x6e
                            if (s == "and") {
                                return 35;
                            }
                        }
                        break;
                        case 'b': { // 0x62
                            if (s == "abs") {
                                return 38;
                            }
                        }
                        break;
                        case 'l': { // 0x6c
                            if (s == "all") {
                                return 47;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "use") {
                        return 41;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "out") {
                        return 42;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "rem") {
                        return 55;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "mod") {
                        return 56;
                    }
                }
                break;
                case 'x': { // 0x78
                    if (s == "xor") {
                        return 59;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[3]) {
                case 'e': { // 0x65
                    switch (s[0]) {
                        case 'e': { // 0x65
                            if (s == "else") {
                                return 0;
                            }
                        }
                        break;
                        case 't': { // 0x74
                            if (s == "type") {
                                return 3;
                            }
                        }
                        break;
                        case 'c': { // 0x63
                            if (s == "case") {
                                return 30;
                            }
                        }
                        break;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "exit") {
                        return 1;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "then") {
                        return 12;
                    }
                    if (s == "when") {
                        return 26;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "loop") {
                        return 49;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "null") {
                        return 50;
                    }
                }
                break;
                case 'k': { // 0x6b
                    if (s == "task") {
                        return 51;
                    }
                }
                break;
                case 'y': { // 0x79
                    if (s == "body") {
                        return 58;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "goto") {
                        return 60;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "with") {
                        return 62;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[2]) {
                case 'i': { // 0x69
                    if (s == "raise") {
                        return 4;
                    }
                    if (s == "while") {
                        return 25;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "range") {
                        return 5;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "elsif") {
                        return 19;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "entry") {
                        return 28;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "delay") {
                        return 29;
                    }
                    if (s == "delta") {
                        return 36;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "abort") {
                        return 33;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "array") {
                        return 40;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "begin") {
                        return 57;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[2]) {
                case 'c': { // 0x63
                    switch (s[4]) {
                        case 'r': { // 0x72
                            if (s == "record") {
                                return 9;
                            }
                        }
                        break;
                        case 'p': { // 0x70
                            if (s == "accept") {
                                return 34;
                            }
                        }
                        break;
                        case 's': { // 0x73
                            if (s == "access") {
                                return 37;
                            }
                        }
                        break;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "return") {
                        return 13;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "select") {
                        return 15;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "digits") {
                        return 16;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "pragma") {
                        return 39;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "others") {
                        return 44;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[3]) {
                case 'e': { // 0x65
                    if (s == "reverse") {
                        return 6;
                    }
                    if (s == "generic") {
                        return 61;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "declare") {
                        return 7;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "renames") {
                        return 17;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "subtype") {
                        return 18;
                    }
                }
                break;
                case 'k': { // 0x6b
                    if (s == "package") {
                        return 22;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "private") {
                        return 24;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "limited") {
                        return 48;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[0]) {
                case 's': { // 0x73
                    if (s == "separate") {
                        return 14;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "function") {
                        return 20;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "constant") {
                        return 31;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 't': { // 0x74
                    if (s == "terminate") {
                        return 2;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "exception") {
                        return 10;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "procedure") {
                        return 23;
                    }
                }
                break;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=ada, name=check_ada_split, type=split
void check_ada_split() {
    assert(lookup_ada_split("else") == 0);
    assert(lookup_ada_split("exit") == 1);
    assert(lookup_ada_split("terminate") == 2);
    assert(lookup_ada_split("type") == 3);
    assert(lookup_ada_split("raise") == 4);
    assert(lookup_ada_split("range") == 5);
    assert(lookup_ada_split("reverse") == 6);
    assert(lookup_ada_split("declare") == 7);
    assert(lookup_ada_split("end") == 8);
    assert(lookup_ada_split("record") == 9);
    assert(lookup_ada_split("exception") == 10);
    assert(lookup_ada_split("not") == 11);
    assert(lookup_ada_split("then") == 12);
    assert(lookup_ada_split("return") == 13);
    assert(lookup_ada_split("separate") == 14);
    assert(lookup_ada_split("select") == 15);
    assert(lookup_ada_split("digits") == 16);
    assert(lookup_ada_split("renames") == 17);
    assert(lookup_ada_split("subtype") == 18);
    assert(lookup_ada_split("elsif") == 19);
    assert(lookup_ada_split("function") == 20);
    assert(lookup_ada_split("for") == 21);
    assert(lookup_ada_split("package") == 22);
    assert(lookup_ada_split("procedure") == 23);
    assert(lookup_ada_split("private") == 24);
    assert(lookup_ada_split("while") == 25);
    assert(lookup_ada_split("when") == 26);
    assert(lookup_ada_split("new") == 27);
    assert(lookup_ada_split("entry") == 28);
    assert(lookup_ada_split("delay") == 29);
    assert(lookup_ada_split("case") == 30);
    assert(lookup_ada_split("constant") == 31);
    assert(lookup_ada_split("at") == 32);
    assert(lookup_ada_split("abort") == 33);
    assert(lookup_ada_split("accept") == 34);
    assert(lookup_ada_split("and") == 35);
    assert(lookup_ada_split("delta") == 36);
    assert(lookup_ada_split("access") == 37);
    assert(lookup_ada_split("abs") == 38);
    assert(lookup_ada_split("pragma") == 39);
    assert(lookup_ada_split("array") == 40);
    assert(lookup_ada_split("use") == 41);
    assert(lookup_ada_split("out") == 42);
    assert(lookup_ada_split("do") == 43);
    assert(lookup_ada_split("others") == 44);
    assert(lookup_ada_split("of") == 45);
    assert(lookup_ada_split("or") == 46);
    assert(lookup_ada_split("all") == 47);
    assert(lookup_ada_split("limited") == 48);
    assert(lookup_ada_split("loop") == 49);
    assert(lookup_ada_split("null") == 50);
    assert(lookup_ada_split("task") == 51);
    assert(lookup_ada_split("in") == 52);
    assert(lookup_ada_split("is") == 53);
    assert(lookup_ada_split("if") == 54);
    assert(lookup_ada_split("rem") == 55);
    assert(lookup_ada_split("mod") == 56);
    assert(lookup_ada_split("begin") == 57);
    assert(lookup_ada_split("body") == 58);
    assert(lookup_ada_split("xor") == 59);
    assert(lookup_ada_split("goto") == 60);
    assert(lookup_ada_split("generic") == 61);
    assert(lookup_ada_split("with") == 62);
}
