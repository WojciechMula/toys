//lookup: dataset=gpc, name=lookup_gpc_split, type=split
int lookup_gpc_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[0]) {
                case 'D': { // 0x44
                    if (s == "Do") {
                        return 6;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "If") {
                        return 14;
                    }
                    if (s == "In") {
                        return 15;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "Of") {
                        return 20;
                    }
                    if (s == "Or") {
                        return 21;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "To") {
                        return 29;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "And") {
                        return 0;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "Div") {
                        return 5;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "End") {
                        return 9;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "For") {
                        return 11;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "Mod") {
                        return 17;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "Nil") {
                        return 18;
                    }
                    if (s == "Not") {
                        return 19;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "Set") {
                        return 27;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "Var") {
                        return 32;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 'C': { // 0x43
                    if (s == "Case") {
                        return 3;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "Else") {
                        return 8;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "File") {
                        return 10;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "Goto") {
                        return 13;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "Then") {
                        return 28;
                    }
                    if (s == "Type") {
                        return 30;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "With") {
                        return 34;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "Array") {
                        return 1;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "Begin") {
                        return 2;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "Const") {
                        return 4;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "Label") {
                        return 16;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "Until") {
                        return 31;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "While") {
                        return 33;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[3]) {
                case 'n': { // 0x6e
                    if (s == "Downto") {
                        return 7;
                    }
                }
                break;
                case 'k': { // 0x6b
                    if (s == "Packed") {
                        return 22;
                    }
                }
                break;
                case 'o': { // 0x6f
                    if (s == "Record") {
                        return 25;
                    }
                }
                break;
                case 'e': { // 0x65
                    if (s == "Repeat") {
                        return 26;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            if (s == "Program") {
                return 24;
            }
        }
        break;
        case 8: {
            if (s == "Function") {
                return 12;
            }
        }
        break;
        case 9: {
            if (s == "Procedure") {
                return 23;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=gpc, name=check_gpc_split, type=split
void check_gpc_split() {
    assert(lookup_gpc_split("And") == 0);
    assert(lookup_gpc_split("Array") == 1);
    assert(lookup_gpc_split("Begin") == 2);
    assert(lookup_gpc_split("Case") == 3);
    assert(lookup_gpc_split("Const") == 4);
    assert(lookup_gpc_split("Div") == 5);
    assert(lookup_gpc_split("Do") == 6);
    assert(lookup_gpc_split("Downto") == 7);
    assert(lookup_gpc_split("Else") == 8);
    assert(lookup_gpc_split("End") == 9);
    assert(lookup_gpc_split("File") == 10);
    assert(lookup_gpc_split("For") == 11);
    assert(lookup_gpc_split("Function") == 12);
    assert(lookup_gpc_split("Goto") == 13);
    assert(lookup_gpc_split("If") == 14);
    assert(lookup_gpc_split("In") == 15);
    assert(lookup_gpc_split("Label") == 16);
    assert(lookup_gpc_split("Mod") == 17);
    assert(lookup_gpc_split("Nil") == 18);
    assert(lookup_gpc_split("Not") == 19);
    assert(lookup_gpc_split("Of") == 20);
    assert(lookup_gpc_split("Or") == 21);
    assert(lookup_gpc_split("Packed") == 22);
    assert(lookup_gpc_split("Procedure") == 23);
    assert(lookup_gpc_split("Program") == 24);
    assert(lookup_gpc_split("Record") == 25);
    assert(lookup_gpc_split("Repeat") == 26);
    assert(lookup_gpc_split("Set") == 27);
    assert(lookup_gpc_split("Then") == 28);
    assert(lookup_gpc_split("To") == 29);
    assert(lookup_gpc_split("Type") == 30);
    assert(lookup_gpc_split("Until") == 31);
    assert(lookup_gpc_split("Var") == 32);
    assert(lookup_gpc_split("While") == 33);
    assert(lookup_gpc_split("With") == 34);
}
