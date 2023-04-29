//lookup: dataset=go, name=lookup_go_split, type=split
int lookup_go_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "go") {
                return 11;
            }
            if (s == "if") {
                return 13;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'f': { // 0x66
                    if (s == "for") {
                        return 9;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "map") {
                        return 16;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "var") {
                        return 24;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[1]) {
                case 'a': { // 0x61
                    if (s == "case") {
                        return 1;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "chan") {
                        return 2;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "else") {
                        return 7;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "func") {
                        return 10;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "goto") {
                        return 12;
                    }
                }
                break;
                case 'y': { // 0x79
                    if (s == "type") {
                        return 23;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'b': { // 0x62
                    if (s == "break") {
                        return 0;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "const") {
                        return 3;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "defer") {
                        return 6;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "range") {
                        return 18;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[2]) {
                case 'p': { // 0x70
                    if (s == "import") {
                        return 14;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "return") {
                        return 19;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "select") {
                        return 20;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "struct") {
                        return 21;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "switch") {
                        return 22;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            if (s == "default") {
                return 5;
            }
            if (s == "package") {
                return 17;
            }
        }
        break;
        case 8: {
            if (s == "continue") {
                return 4;
            }
        }
        break;
        case 9: {
            if (s == "interface") {
                return 15;
            }
        }
        break;
        case 11: {
            if (s == "fallthrough") {
                return 8;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=go, name=check_go_split, type=split
void check_go_split() {
    assert(lookup_go_split("break") == 0);
    assert(lookup_go_split("case") == 1);
    assert(lookup_go_split("chan") == 2);
    assert(lookup_go_split("const") == 3);
    assert(lookup_go_split("continue") == 4);
    assert(lookup_go_split("default") == 5);
    assert(lookup_go_split("defer") == 6);
    assert(lookup_go_split("else") == 7);
    assert(lookup_go_split("fallthrough") == 8);
    assert(lookup_go_split("for") == 9);
    assert(lookup_go_split("func") == 10);
    assert(lookup_go_split("go") == 11);
    assert(lookup_go_split("goto") == 12);
    assert(lookup_go_split("if") == 13);
    assert(lookup_go_split("import") == 14);
    assert(lookup_go_split("interface") == 15);
    assert(lookup_go_split("map") == 16);
    assert(lookup_go_split("package") == 17);
    assert(lookup_go_split("range") == 18);
    assert(lookup_go_split("return") == 19);
    assert(lookup_go_split("select") == 20);
    assert(lookup_go_split("struct") == 21);
    assert(lookup_go_split("switch") == 22);
    assert(lookup_go_split("type") == 23);
    assert(lookup_go_split("var") == 24);
}
