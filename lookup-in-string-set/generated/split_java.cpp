//lookup: dataset=java, name=lookup_java_split, type=split
int lookup_java_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            if (s == "if") {
                return 2;
            }
            if (s == "do") {
                return 6;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 't': { // 0x74
                    if (s == "try") {
                        return 19;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "int") {
                        return 22;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "for") {
                        return 40;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "new") {
                        return 41;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 'b': { // 0x62
                    if (s == "byte") {
                        return 15;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "else") {
                        return 16;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "case") {
                        return 20;
                    }
                    if (s == "char") {
                        return 30;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "void") {
                        return 24;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "long") {
                        return 32;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "goto") {
                        return 44;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "this") {
                        return 46;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[4]) {
                case 'w': { // 0x77
                    if (s == "throw") {
                        return 4;
                    }
                }
                break;
                case 'k': { // 0x6b
                    if (s == "break") {
                        return 10;
                    }
                }
                break;
                case 't': { // 0x74
                    switch (s[0]) {
                        case 's': { // 0x73
                            if (s == "short") {
                                return 23;
                            }
                        }
                        break;
                        case 'f': { // 0x66
                            if (s == "float") {
                                return 36;
                            }
                        }
                        break;
                        case 'c': { // 0x63
                            if (s == "const") {
                                return 39;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "catch") {
                        return 25;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "final") {
                        return 26;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "super") {
                        return 33;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "while") {
                        return 34;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "class") {
                        return 35;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[1]) {
                case 'h': { // 0x68
                    if (s == "throws") {
                        return 9;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "double") {
                        return 11;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "import") {
                        return 12;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "public") {
                        return 13;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "return") {
                        return 18;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "static") {
                        return 28;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "native") {
                        return 37;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "switch") {
                        return 38;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[1]) {
                case 'e': { // 0x65
                    if (s == "default") {
                        return 1;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "private") {
                        return 3;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "boolean") {
                        return 5;
                    }
                }
                break;
                case 'x': { // 0x78
                    if (s == "extends") {
                        return 21;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "finally") {
                        return 31;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "package") {
                        return 45;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "abstract") {
                        return 0;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "volatile") {
                        return 29;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "continue") {
                        return 43;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 'p': { // 0x70
                    if (s == "protected") {
                        return 8;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "transient") {
                        return 14;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "interface") {
                        return 27;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            if (s == "implements") {
                return 7;
            }
            if (s == "instanceof") {
                return 17;
            }
        }
        break;
        case 12: {
            if (s == "synchronized") {
                return 42;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=java, name=check_java_split, type=split
void check_java_split() {
    assert(lookup_java_split("abstract") == 0);
    assert(lookup_java_split("default") == 1);
    assert(lookup_java_split("if") == 2);
    assert(lookup_java_split("private") == 3);
    assert(lookup_java_split("throw") == 4);
    assert(lookup_java_split("boolean") == 5);
    assert(lookup_java_split("do") == 6);
    assert(lookup_java_split("implements") == 7);
    assert(lookup_java_split("protected") == 8);
    assert(lookup_java_split("throws") == 9);
    assert(lookup_java_split("break") == 10);
    assert(lookup_java_split("double") == 11);
    assert(lookup_java_split("import") == 12);
    assert(lookup_java_split("public") == 13);
    assert(lookup_java_split("transient") == 14);
    assert(lookup_java_split("byte") == 15);
    assert(lookup_java_split("else") == 16);
    assert(lookup_java_split("instanceof") == 17);
    assert(lookup_java_split("return") == 18);
    assert(lookup_java_split("try") == 19);
    assert(lookup_java_split("case") == 20);
    assert(lookup_java_split("extends") == 21);
    assert(lookup_java_split("int") == 22);
    assert(lookup_java_split("short") == 23);
    assert(lookup_java_split("void") == 24);
    assert(lookup_java_split("catch") == 25);
    assert(lookup_java_split("final") == 26);
    assert(lookup_java_split("interface") == 27);
    assert(lookup_java_split("static") == 28);
    assert(lookup_java_split("volatile") == 29);
    assert(lookup_java_split("char") == 30);
    assert(lookup_java_split("finally") == 31);
    assert(lookup_java_split("long") == 32);
    assert(lookup_java_split("super") == 33);
    assert(lookup_java_split("while") == 34);
    assert(lookup_java_split("class") == 35);
    assert(lookup_java_split("float") == 36);
    assert(lookup_java_split("native") == 37);
    assert(lookup_java_split("switch") == 38);
    assert(lookup_java_split("const") == 39);
    assert(lookup_java_split("for") == 40);
    assert(lookup_java_split("new") == 41);
    assert(lookup_java_split("synchronized") == 42);
    assert(lookup_java_split("continue") == 43);
    assert(lookup_java_split("goto") == 44);
    assert(lookup_java_split("package") == 45);
    assert(lookup_java_split("this") == 46);
}
