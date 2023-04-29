//lookup: dataset=cplusplus, name=lookup_cplusplus_split, type=split
int lookup_cplusplus_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[0]) {
                case 'd': { // 0x64
                    if (s == "do") {
                        return 48;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "if") {
                        return 61;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "or") {
                        return 71;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'a': { // 0x61
                    if (s == "asm") {
                        return 30;
                    }
                    if (s == "and") {
                        return 31;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "for") {
                        return 58;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "int") {
                        return 63;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "new") {
                        return 67;
                    }
                    if (s == "not") {
                        return 68;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "try") {
                        return 92;
                    }
                }
                break;
                case 'x': { // 0x78
                    if (s == "xor") {
                        return 104;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[3]) {
                case 'o': { // 0x6f
                    if (s == "auto") {
                        return 33;
                    }
                    if (s == "goto") {
                        return 60;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "bool") {
                        return 36;
                    }
                }
                break;
                case 'e': { // 0x65
                    switch (s[0]) {
                        case 'c': { // 0x63
                            if (s == "case") {
                                return 38;
                            }
                        }
                        break;
                        case 'e': { // 0x65
                            if (s == "else") {
                                return 51;
                            }
                        }
                        break;
                        case 't': { // 0x74
                            if (s == "true") {
                                return 91;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "char") {
                        return 40;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "enum") {
                        return 52;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "long") {
                        return 64;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "this") {
                        return 89;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "void") {
                        return 101;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[4]) {
                case 'm': { // 0x6d
                    if (s == "__asm") {
                        return 2;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "bitor") {
                        return 35;
                    }
                }
                break;
                case 'k': { // 0x6b
                    if (s == "break") {
                        return 37;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "catch") {
                        return 39;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "class") {
                        return 41;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "compl") {
                        return 42;
                    }
                }
                break;
                case 't': { // 0x74
                    switch (s[0]) {
                        case 'c': { // 0x63
                            if (s == "const") {
                                return 43;
                            }
                        }
                        break;
                        case 'f': { // 0x66
                            if (s == "float") {
                                return 57;
                            }
                        }
                        break;
                        case 's': { // 0x73
                            if (s == "short") {
                                return 79;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "false") {
                        return 56;
                    }
                    if (s == "while") {
                        return 103;
                    }
                }
                break;
                case 'q': { // 0x71
                    if (s == "or_eq") {
                        return 72;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "sigof") {
                        return 82;
                    }
                }
                break;
                case 'w': { // 0x77
                    if (s == "throw") {
                        return 90;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "union") {
                        return 97;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "using") {
                        return 99;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[0]) {
                case '_': { // 0x5f
                    switch (s[2]) {
                        case 'i': { // 0x69
                            if (s == "__imag") {
                                return 11;
                            }
                        }
                        break;
                        case 'n': { // 0x6e
                            if (s == "__null") {
                                return 16;
                            }
                        }
                        break;
                        case 'r': { // 0x72
                            if (s == "__real") {
                                return 17;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "and_eq") {
                        return 32;
                    }
                }
                break;
                case 'b': { // 0x62
                    if (s == "bitand") {
                        return 34;
                    }
                }
                break;
                case 'd': { // 0x64
                    if (s == "delete") {
                        return 47;
                    }
                    if (s == "double") {
                        return 49;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "export") {
                        return 54;
                    }
                    if (s == "extern") {
                        return 55;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "friend") {
                        return 59;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "inline") {
                        return 62;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "not_eq") {
                        return 69;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "public") {
                        return 75;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "return") {
                        return 78;
                    }
                }
                break;
                case 's': { // 0x73
                    switch (s[2]) {
                        case 'g': { // 0x67
                            if (s == "signed") {
                                return 81;
                            }
                        }
                        break;
                        case 'z': { // 0x7a
                            if (s == "sizeof") {
                                return 83;
                            }
                        }
                        break;
                        case 'a': { // 0x61
                            if (s == "static") {
                                return 84;
                            }
                        }
                        break;
                        case 'r': { // 0x72
                            if (s == "struct") {
                                return 86;
                            }
                        }
                        break;
                        case 'i': { // 0x69
                            if (s == "switch") {
                                return 87;
                            }
                        }
                        break;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "typeid") {
                        return 95;
                    }
                    if (s == "typeof") {
                        return 96;
                    }
                }
                break;
                case 'x': { // 0x78
                    if (s == "xor_eq") {
                        return 105;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[2]) {
                case 'a': { // 0x61
                    if (s == "__asm__") {
                        return 3;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "__const") {
                        return 8;
                    }
                }
                break;
                case 'f': { // 0x66
                    if (s == "default") {
                        return 46;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "mutable") {
                        return 65;
                    }
                }
                break;
                case 'i': { // 0x69
                    if (s == "private") {
                        return 73;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "typedef") {
                        return 93;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "virtual") {
                        return 100;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[3]) {
                case 'm': { // 0x6d
                    if (s == "__imag__") {
                        return 12;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "__inline") {
                        return 13;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "__real__") {
                        return 18;
                    }
                    if (s == "typename") {
                        return 94;
                    }
                }
                break;
                case 'i': { // 0x69
                    switch (s[0]) {
                        case '_': { // 0x5f
                            if (s == "__signed") {
                                return 22;
                            }
                        }
                        break;
                        case 'r': { // 0x72
                            if (s == "register") {
                                return 76;
                            }
                        }
                        break;
                        case 'u': { // 0x75
                            if (s == "unsigned") {
                                return 98;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'y': { // 0x79
                    if (s == "__typeof") {
                        return 25;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "continue") {
                        return 45;
                    }
                }
                break;
                case 'l': { // 0x6c
                    if (s == "explicit") {
                        return 53;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "operator") {
                        return 70;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "template") {
                        return 88;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "volatile") {
                        return 102;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[4]) {
                case 'i': { // 0x69
                    if (s == "__alignof") {
                        return 0;
                    }
                }
                break;
                case 'm': { // 0x6d
                    if (s == "__complex") {
                        return 6;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "__const__") {
                        return 9;
                    }
                }
                break;
                case 'b': { // 0x62
                    if (s == "__label__") {
                        return 15;
                    }
                }
                break;
                case 'g': { // 0x67
                    if (s == "__sigof__") {
                        return 24;
                    }
                }
                break;
                case 'h': { // 0x68
                    if (s == "__wchar_t") {
                        return 29;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "namespace") {
                        return 66;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "protected") {
                        return 74;
                    }
                }
                break;
                case 'a': { // 0x61
                    if (s == "signature") {
                        return 80;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            switch (s[2]) {
                case 'i': { // 0x69
                    if (s == "__inline__") {
                        return 14;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "__restrict") {
                        return 19;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "__signed__") {
                        return 23;
                    }
                }
                break;
                case 't': { // 0x74
                    if (s == "__typeof__") {
                        return 26;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "__volatile") {
                        return 27;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "const_cast") {
                        return 44;
                    }
                }
                break;
            }
        }
        break;
        case 11: {
            switch (s[5]) {
                case 'g': { // 0x67
                    if (s == "__alignof__") {
                        return 1;
                    }
                }
                break;
                case 'r': { // 0x72
                    if (s == "__attribute") {
                        return 4;
                    }
                }
                break;
                case 'p': { // 0x70
                    if (s == "__complex__") {
                        return 7;
                    }
                }
                break;
                case 'c': { // 0x63
                    if (s == "static_cast") {
                        return 85;
                    }
                }
                break;
            }
        }
        break;
        case 12: {
            switch (s[2]) {
                case 'r': { // 0x72
                    if (s == "__restrict__") {
                        return 20;
                    }
                }
                break;
                case 'v': { // 0x76
                    if (s == "__volatile__") {
                        return 28;
                    }
                }
                break;
                case 'n': { // 0x6e
                    if (s == "dynamic_cast") {
                        return 50;
                    }
                }
                break;
            }
        }
        break;
        case 13: {
            switch (s[2]) {
                case 'a': { // 0x61
                    if (s == "__attribute__") {
                        return 5;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "__extension__") {
                        return 10;
                    }
                }
                break;
                case 's': { // 0x73
                    if (s == "__signature__") {
                        return 21;
                    }
                }
                break;
            }
        }
        break;
        case 16: {
            if (s == "reinterpret_cast") {
                return 77;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=cplusplus, name=check_cplusplus_split, type=split
void check_cplusplus_split() {
    assert(lookup_cplusplus_split("__alignof") == 0);
    assert(lookup_cplusplus_split("__alignof__") == 1);
    assert(lookup_cplusplus_split("__asm") == 2);
    assert(lookup_cplusplus_split("__asm__") == 3);
    assert(lookup_cplusplus_split("__attribute") == 4);
    assert(lookup_cplusplus_split("__attribute__") == 5);
    assert(lookup_cplusplus_split("__complex") == 6);
    assert(lookup_cplusplus_split("__complex__") == 7);
    assert(lookup_cplusplus_split("__const") == 8);
    assert(lookup_cplusplus_split("__const__") == 9);
    assert(lookup_cplusplus_split("__extension__") == 10);
    assert(lookup_cplusplus_split("__imag") == 11);
    assert(lookup_cplusplus_split("__imag__") == 12);
    assert(lookup_cplusplus_split("__inline") == 13);
    assert(lookup_cplusplus_split("__inline__") == 14);
    assert(lookup_cplusplus_split("__label__") == 15);
    assert(lookup_cplusplus_split("__null") == 16);
    assert(lookup_cplusplus_split("__real") == 17);
    assert(lookup_cplusplus_split("__real__") == 18);
    assert(lookup_cplusplus_split("__restrict") == 19);
    assert(lookup_cplusplus_split("__restrict__") == 20);
    assert(lookup_cplusplus_split("__signature__") == 21);
    assert(lookup_cplusplus_split("__signed") == 22);
    assert(lookup_cplusplus_split("__signed__") == 23);
    assert(lookup_cplusplus_split("__sigof__") == 24);
    assert(lookup_cplusplus_split("__typeof") == 25);
    assert(lookup_cplusplus_split("__typeof__") == 26);
    assert(lookup_cplusplus_split("__volatile") == 27);
    assert(lookup_cplusplus_split("__volatile__") == 28);
    assert(lookup_cplusplus_split("__wchar_t") == 29);
    assert(lookup_cplusplus_split("asm") == 30);
    assert(lookup_cplusplus_split("and") == 31);
    assert(lookup_cplusplus_split("and_eq") == 32);
    assert(lookup_cplusplus_split("auto") == 33);
    assert(lookup_cplusplus_split("bitand") == 34);
    assert(lookup_cplusplus_split("bitor") == 35);
    assert(lookup_cplusplus_split("bool") == 36);
    assert(lookup_cplusplus_split("break") == 37);
    assert(lookup_cplusplus_split("case") == 38);
    assert(lookup_cplusplus_split("catch") == 39);
    assert(lookup_cplusplus_split("char") == 40);
    assert(lookup_cplusplus_split("class") == 41);
    assert(lookup_cplusplus_split("compl") == 42);
    assert(lookup_cplusplus_split("const") == 43);
    assert(lookup_cplusplus_split("const_cast") == 44);
    assert(lookup_cplusplus_split("continue") == 45);
    assert(lookup_cplusplus_split("default") == 46);
    assert(lookup_cplusplus_split("delete") == 47);
    assert(lookup_cplusplus_split("do") == 48);
    assert(lookup_cplusplus_split("double") == 49);
    assert(lookup_cplusplus_split("dynamic_cast") == 50);
    assert(lookup_cplusplus_split("else") == 51);
    assert(lookup_cplusplus_split("enum") == 52);
    assert(lookup_cplusplus_split("explicit") == 53);
    assert(lookup_cplusplus_split("export") == 54);
    assert(lookup_cplusplus_split("extern") == 55);
    assert(lookup_cplusplus_split("false") == 56);
    assert(lookup_cplusplus_split("float") == 57);
    assert(lookup_cplusplus_split("for") == 58);
    assert(lookup_cplusplus_split("friend") == 59);
    assert(lookup_cplusplus_split("goto") == 60);
    assert(lookup_cplusplus_split("if") == 61);
    assert(lookup_cplusplus_split("inline") == 62);
    assert(lookup_cplusplus_split("int") == 63);
    assert(lookup_cplusplus_split("long") == 64);
    assert(lookup_cplusplus_split("mutable") == 65);
    assert(lookup_cplusplus_split("namespace") == 66);
    assert(lookup_cplusplus_split("new") == 67);
    assert(lookup_cplusplus_split("not") == 68);
    assert(lookup_cplusplus_split("not_eq") == 69);
    assert(lookup_cplusplus_split("operator") == 70);
    assert(lookup_cplusplus_split("or") == 71);
    assert(lookup_cplusplus_split("or_eq") == 72);
    assert(lookup_cplusplus_split("private") == 73);
    assert(lookup_cplusplus_split("protected") == 74);
    assert(lookup_cplusplus_split("public") == 75);
    assert(lookup_cplusplus_split("register") == 76);
    assert(lookup_cplusplus_split("reinterpret_cast") == 77);
    assert(lookup_cplusplus_split("return") == 78);
    assert(lookup_cplusplus_split("short") == 79);
    assert(lookup_cplusplus_split("signature") == 80);
    assert(lookup_cplusplus_split("signed") == 81);
    assert(lookup_cplusplus_split("sigof") == 82);
    assert(lookup_cplusplus_split("sizeof") == 83);
    assert(lookup_cplusplus_split("static") == 84);
    assert(lookup_cplusplus_split("static_cast") == 85);
    assert(lookup_cplusplus_split("struct") == 86);
    assert(lookup_cplusplus_split("switch") == 87);
    assert(lookup_cplusplus_split("template") == 88);
    assert(lookup_cplusplus_split("this") == 89);
    assert(lookup_cplusplus_split("throw") == 90);
    assert(lookup_cplusplus_split("true") == 91);
    assert(lookup_cplusplus_split("try") == 92);
    assert(lookup_cplusplus_split("typedef") == 93);
    assert(lookup_cplusplus_split("typename") == 94);
    assert(lookup_cplusplus_split("typeid") == 95);
    assert(lookup_cplusplus_split("typeof") == 96);
    assert(lookup_cplusplus_split("union") == 97);
    assert(lookup_cplusplus_split("unsigned") == 98);
    assert(lookup_cplusplus_split("using") == 99);
    assert(lookup_cplusplus_split("virtual") == 100);
    assert(lookup_cplusplus_split("void") == 101);
    assert(lookup_cplusplus_split("volatile") == 102);
    assert(lookup_cplusplus_split("while") == 103);
    assert(lookup_cplusplus_split("xor") == 104);
    assert(lookup_cplusplus_split("xor_eq") == 105);
}
