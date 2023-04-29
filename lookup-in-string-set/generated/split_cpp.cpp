//lookup: dataset=cpp, name=lookup_cpp_split, type=split
int lookup_cpp_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "do") {
                return 11;
            }
            if (s == "if") {
                return 20;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "asm") {
                        return 0;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "for") {
                        return 17;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "int") {
                        return 22;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "new") {
                        return 24;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "auto") {
                        return 1;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "case") {
                        return 3;
                    }
                    if (s == "char") {
                        return 5;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "else") {
                        return 13;
                    }
                    if (s == "enum") {
                        return 14;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "goto") {
                        return 19;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "long") {
                        return 23;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "this") {
                        return 39;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "void") {
                        return 44;
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
                        return 2;
                    }
                }
                break;
                case 'c': { // 0x63
                    switch (s[1]) {
                        case 'a': { // 0x61
                            if (s == "catch") {
                                return 4;
                            }
                        }
                        break;
                        case 'l': { // 0x6c
                            if (s == "class") {
                                return 6;
                            }
                        }
                        break;
                        case 'o': { // 0x6f
                            if (s == "const") {
                                return 7;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "float") {
                        return 16;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "short") {
                        return 32;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "union") {
                        return 41;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "while") {
                        return 46;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[1]) {
                case 'e': { // 0x65
                    if (s == "delete") {
                        return 10;
                    }
                    if (s == "return") {
                        return 31;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "double") {
                        return 12;
                    }
                }
                break;
                case 'x': { // 0x78
                    if (s == "extern") {
                        return 15;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "friend") {
                        return 18;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "inline") {
                        return 21;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "public") {
                        return 29;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "signed") {
                        return 33;
                    }
                    if (s == "sizeof") {
                        return 34;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "static") {
                        return 35;
                    }
                    if (s == "struct") {
                        return 36;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "switch") {
                        return 37;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[0]) {
                case 'd': { // 0x64
                    if (s == "default") {
                        return 9;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "private") {
                        return 27;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "typedef") {
                        return 40;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "virtual") {
                        return 43;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[0]) {
                case 'c': { // 0x63
                    if (s == "continue") {
                        return 8;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "operator") {
                        return 25;
                    }
                    if (s == "overload") {
                        return 26;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "register") {
                        return 30;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "template") {
                        return 38;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "unsigned") {
                        return 42;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "volatile") {
                        return 45;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            if (s == "protected") {
                return 28;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=cpp, name=check_cpp_split, type=split
void check_cpp_split() {
    assert(lookup_cpp_split("asm") == 0);
    assert(lookup_cpp_split("auto") == 1);
    assert(lookup_cpp_split("break") == 2);
    assert(lookup_cpp_split("case") == 3);
    assert(lookup_cpp_split("catch") == 4);
    assert(lookup_cpp_split("char") == 5);
    assert(lookup_cpp_split("class") == 6);
    assert(lookup_cpp_split("const") == 7);
    assert(lookup_cpp_split("continue") == 8);
    assert(lookup_cpp_split("default") == 9);
    assert(lookup_cpp_split("delete") == 10);
    assert(lookup_cpp_split("do") == 11);
    assert(lookup_cpp_split("double") == 12);
    assert(lookup_cpp_split("else") == 13);
    assert(lookup_cpp_split("enum") == 14);
    assert(lookup_cpp_split("extern") == 15);
    assert(lookup_cpp_split("float") == 16);
    assert(lookup_cpp_split("for") == 17);
    assert(lookup_cpp_split("friend") == 18);
    assert(lookup_cpp_split("goto") == 19);
    assert(lookup_cpp_split("if") == 20);
    assert(lookup_cpp_split("inline") == 21);
    assert(lookup_cpp_split("int") == 22);
    assert(lookup_cpp_split("long") == 23);
    assert(lookup_cpp_split("new") == 24);
    assert(lookup_cpp_split("operator") == 25);
    assert(lookup_cpp_split("overload") == 26);
    assert(lookup_cpp_split("private") == 27);
    assert(lookup_cpp_split("protected") == 28);
    assert(lookup_cpp_split("public") == 29);
    assert(lookup_cpp_split("register") == 30);
    assert(lookup_cpp_split("return") == 31);
    assert(lookup_cpp_split("short") == 32);
    assert(lookup_cpp_split("signed") == 33);
    assert(lookup_cpp_split("sizeof") == 34);
    assert(lookup_cpp_split("static") == 35);
    assert(lookup_cpp_split("struct") == 36);
    assert(lookup_cpp_split("switch") == 37);
    assert(lookup_cpp_split("template") == 38);
    assert(lookup_cpp_split("this") == 39);
    assert(lookup_cpp_split("typedef") == 40);
    assert(lookup_cpp_split("union") == 41);
    assert(lookup_cpp_split("unsigned") == 42);
    assert(lookup_cpp_split("virtual") == 43);
    assert(lookup_cpp_split("void") == 44);
    assert(lookup_cpp_split("volatile") == 45);
    assert(lookup_cpp_split("while") == 46);
}
