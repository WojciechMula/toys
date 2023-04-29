//lookup: dataset=pascal, name=lookup_pascal_split, type=split
int lookup_pascal_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[0]) {
                case 'o': { // 0x6f
                    if (s == "or") {
                        return 13;
                    }
                    if (s == "of") {
                        return 20;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "in") {
                        return 18;
                    }
                    if (s == "if") {
                        return 35;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "do") {
                        return 28;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "to") {
                        return 30;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "and") {
                        return 2;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "var") {
                        return 5;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "set") {
                        return 9;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "not") {
                        return 15;
                    }
                    if (s == "nil") {
                        return 16;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "for") {
                        return 23;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "div") {
                        return 29;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "end") {
                        return 32;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "mod") {
                        return 33;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 'w': { // 0x77
                    if (s == "with") {
                        return 0;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "case") {
                        return 4;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "then") {
                        return 8;
                    }
                    if (s == "type") {
                        return 31;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "goto") {
                        return 21;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "file") {
                        return 25;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "else") {
                        return 26;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "array") {
                        return 1;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "const") {
                        return 6;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "until") {
                        return 7;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "label") {
                        return 17;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "while") {
                        return 24;
                    }
                }
                break;
                case 'b': { // 0x62
                    if (s == "begin") {
                        return 34;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[3]) {
                case 'o': { // 0x6f
                    if (s == "record") {
                        return 10;
                    }
                }
                break;
                case 'k': { // 0x6b
                    if (s == "packed") {
                        return 14;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "repeat") {
                        return 19;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "downto") {
                        return 27;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            if (s == "program") {
                return 11;
            }
            if (s == "forward") {
                return 22;
            }
        }
        break;
        case 8: {
            if (s == "function") {
                return 3;
            }
        }
        break;
        case 9: {
            if (s == "procedure") {
                return 12;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=pascal, name=check_pascal_split, type=split
void check_pascal_split() {
    assert(lookup_pascal_split("with") == 0);
    assert(lookup_pascal_split("array") == 1);
    assert(lookup_pascal_split("and") == 2);
    assert(lookup_pascal_split("function") == 3);
    assert(lookup_pascal_split("case") == 4);
    assert(lookup_pascal_split("var") == 5);
    assert(lookup_pascal_split("const") == 6);
    assert(lookup_pascal_split("until") == 7);
    assert(lookup_pascal_split("then") == 8);
    assert(lookup_pascal_split("set") == 9);
    assert(lookup_pascal_split("record") == 10);
    assert(lookup_pascal_split("program") == 11);
    assert(lookup_pascal_split("procedure") == 12);
    assert(lookup_pascal_split("or") == 13);
    assert(lookup_pascal_split("packed") == 14);
    assert(lookup_pascal_split("not") == 15);
    assert(lookup_pascal_split("nil") == 16);
    assert(lookup_pascal_split("label") == 17);
    assert(lookup_pascal_split("in") == 18);
    assert(lookup_pascal_split("repeat") == 19);
    assert(lookup_pascal_split("of") == 20);
    assert(lookup_pascal_split("goto") == 21);
    assert(lookup_pascal_split("forward") == 22);
    assert(lookup_pascal_split("for") == 23);
    assert(lookup_pascal_split("while") == 24);
    assert(lookup_pascal_split("file") == 25);
    assert(lookup_pascal_split("else") == 26);
    assert(lookup_pascal_split("downto") == 27);
    assert(lookup_pascal_split("do") == 28);
    assert(lookup_pascal_split("div") == 29);
    assert(lookup_pascal_split("to") == 30);
    assert(lookup_pascal_split("type") == 31);
    assert(lookup_pascal_split("end") == 32);
    assert(lookup_pascal_split("mod") == 33);
    assert(lookup_pascal_split("begin") == 34);
    assert(lookup_pascal_split("if") == 35);
}
