//lookup: dataset=jscript, name=lookup_jscript_split, type=split
int lookup_jscript_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[1]) {
                case 'o': { // 0x6f
                    if (s == "do") {
                        return 11;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "if") {
                        return 22;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "in") {
                        return 25;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'f': { // 0x66
                    if (s == "for") {
                        return 19;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "int") {
                        return 27;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "new") {
                        return 31;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "try") {
                        return 48;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "var") {
                        return 49;
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
                        return 3;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "case") {
                        return 4;
                    }
                    if (s == "char") {
                        return 6;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "else") {
                        return 13;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "goto") {
                        return 21;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "long") {
                        return 29;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "null") {
                        return 32;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "this") {
                        return 43;
                    }
                    if (s == "true") {
                        return 47;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "void") {
                        return 50;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "with") {
                        return 52;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[2]) {
                case 'e': { // 0x65
                    if (s == "break") {
                        return 2;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "catch") {
                        return 5;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "class") {
                        return 7;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "const") {
                        return 8;
                    }
                    if (s == "final") {
                        return 16;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "false") {
                        return 15;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "float") {
                        return 18;
                    }
                    if (s == "short") {
                        return 38;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "super") {
                        return 40;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "throw") {
                        return 44;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "while") {
                        return 51;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[1]) {
                case 'o': { // 0x6f
                    if (s == "double") {
                        return 12;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "import") {
                        return 24;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "native") {
                        return 30;
                    }
                }
                break;
                case 'u': { // 0x75
                    if (s == "public") {
                        return 36;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "return") {
                        return 37;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "static") {
                        return 39;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "switch") {
                        return 41;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "throws") {
                        return 45;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[1]) {
                case 'o': { // 0x6f
                    if (s == "boolean") {
                        return 1;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "default") {
                        return 10;
                    }
                }
                break;
                case 'x': { // 0x78
                    if (s == "extends") {
                        return 14;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "finally") {
                        return 17;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "package") {
                        return 33;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "private") {
                        return 34;
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
                case 'c': { // 0x63
                    if (s == "continue") {
                        return 9;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "function") {
                        return 20;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 'i': { // 0x69
                    if (s == "interface") {
                        return 28;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "protected") {
                        return 35;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "transient") {
                        return 46;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            if (s == "implements") {
                return 23;
            }
            if (s == "instanceof") {
                return 26;
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

//check: dataset=jscript, name=check_jscript_split, type=split
void check_jscript_split() {
    assert(lookup_jscript_split("abstract") == 0);
    assert(lookup_jscript_split("boolean") == 1);
    assert(lookup_jscript_split("break") == 2);
    assert(lookup_jscript_split("byte") == 3);
    assert(lookup_jscript_split("case") == 4);
    assert(lookup_jscript_split("catch") == 5);
    assert(lookup_jscript_split("char") == 6);
    assert(lookup_jscript_split("class") == 7);
    assert(lookup_jscript_split("const") == 8);
    assert(lookup_jscript_split("continue") == 9);
    assert(lookup_jscript_split("default") == 10);
    assert(lookup_jscript_split("do") == 11);
    assert(lookup_jscript_split("double") == 12);
    assert(lookup_jscript_split("else") == 13);
    assert(lookup_jscript_split("extends") == 14);
    assert(lookup_jscript_split("false") == 15);
    assert(lookup_jscript_split("final") == 16);
    assert(lookup_jscript_split("finally") == 17);
    assert(lookup_jscript_split("float") == 18);
    assert(lookup_jscript_split("for") == 19);
    assert(lookup_jscript_split("function") == 20);
    assert(lookup_jscript_split("goto") == 21);
    assert(lookup_jscript_split("if") == 22);
    assert(lookup_jscript_split("implements") == 23);
    assert(lookup_jscript_split("import") == 24);
    assert(lookup_jscript_split("in") == 25);
    assert(lookup_jscript_split("instanceof") == 26);
    assert(lookup_jscript_split("int") == 27);
    assert(lookup_jscript_split("interface") == 28);
    assert(lookup_jscript_split("long") == 29);
    assert(lookup_jscript_split("native") == 30);
    assert(lookup_jscript_split("new") == 31);
    assert(lookup_jscript_split("null") == 32);
    assert(lookup_jscript_split("package") == 33);
    assert(lookup_jscript_split("private") == 34);
    assert(lookup_jscript_split("protected") == 35);
    assert(lookup_jscript_split("public") == 36);
    assert(lookup_jscript_split("return") == 37);
    assert(lookup_jscript_split("short") == 38);
    assert(lookup_jscript_split("static") == 39);
    assert(lookup_jscript_split("super") == 40);
    assert(lookup_jscript_split("switch") == 41);
    assert(lookup_jscript_split("synchronized") == 42);
    assert(lookup_jscript_split("this") == 43);
    assert(lookup_jscript_split("throw") == 44);
    assert(lookup_jscript_split("throws") == 45);
    assert(lookup_jscript_split("transient") == 46);
    assert(lookup_jscript_split("true") == 47);
    assert(lookup_jscript_split("try") == 48);
    assert(lookup_jscript_split("var") == 49);
    assert(lookup_jscript_split("void") == 50);
    assert(lookup_jscript_split("while") == 51);
    assert(lookup_jscript_split("with") == 52);
}
