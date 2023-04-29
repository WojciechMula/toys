//lookup: dataset=countries, name=lookup_countries_split, type=split
int lookup_countries_split(std::string_view s) {
    switch (s.size()) {
        case 4: {
            switch (s[0]) {
                case 'C': { // 0x43
                    if (s == "CHAD") {
                        return 9;
                    }
                    if (s == "CUBA") {
                        return 150;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MALI") {
                        return 29;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TOGO") {
                        return 48;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "IRAN") {
                        return 65;
                    }
                    if (s == "IRAQ") {
                        return 66;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LAOS") {
                        return 75;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OMAN") {
                        return 81;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FIJI") {
                        return 167;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "PERU") {
                        return 188;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'B': { // 0x42
                    if (s == "BENIN") {
                        return 2;
                    }
                    if (s == "BURMA") {
                        return 58;
                    }
                }
                break;
                case 'C': { // 0x43
                    switch (s[3]) {
                        case 'G': { // 0x47
                            if (s == "CONGO") {
                                return 11;
                            }
                        }
                        break;
                        case 'N': { // 0x4e
                            if (s == "CHINA") {
                                return 61;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "CHILE") {
                                return 183;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "EGYPT") {
                        return 13;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "GABON") {
                        return 17;
                    }
                    if (s == "GHANA") {
                        return 19;
                    }
                }
                break;
                case 'K': { // 0x4b
                    if (s == "KENYA") {
                        return 23;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LIBYA") {
                        return 26;
                    }
                }
                break;
                case 'N': { // 0x4e
                    switch (s[1]) {
                        case 'I': { // 0x49
                            if (s == "NIGER") {
                                return 35;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "NEPAL") {
                                return 80;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "NAURU") {
                                return 171;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'S': { // 0x53
                    switch (s[1]) {
                        case 'U': { // 0x55
                            if (s == "SUDAN") {
                                return 45;
                            }
                        }
                        break;
                        case 'Y': { // 0x59
                            if (s == "SYRIA") {
                                return 89;
                            }
                        }
                        break;
                        case 'P': { // 0x50
                            if (s == "SPAIN") {
                                return 138;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "SAMOA") {
                                return 175;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "INDIA") {
                        return 63;
                    }
                    if (s == "ITALY") {
                        return 119;
                    }
                }
                break;
                case 'J': { // 0x4a
                    if (s == "JAPAN") {
                        return 68;
                    }
                }
                break;
                case 'Q': { // 0x51
                    if (s == "QATAR") {
                        return 84;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "YEMEN") {
                        return 97;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MALTA") {
                        return 125;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "HAITI") {
                        return 156;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "PALAU") {
                        return 173;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TONGA") {
                        return 177;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[0]) {
                case 'A': { // 0x41
                    if (s == "ANGOLA") {
                        return 1;
                    }
                }
                break;
                case 'G': { // 0x47
                    switch (s[2]) {
                        case 'M': { // 0x4d
                            if (s == "GAMBIA") {
                                return 18;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "GUINEA") {
                                return 20;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "GREECE") {
                                return 115;
                            }
                        }
                        break;
                        case 'Y': { // 0x59
                            if (s == "GUYANA") {
                                return 186;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'M': { // 0x4d
                    switch (s[1]) {
                        case 'A': { // 0x41
                            if (s == "MALAWI") {
                                return 28;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "MONACO") {
                                return 127;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "MEXICO") {
                                return 159;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "RWANDA") {
                        return 37;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "UGANDA") {
                        return 50;
                    }
                }
                break;
                case 'Z': { // 0x5a
                    if (s == "ZAMBIA") {
                        return 51;
                    }
                }
                break;
                case 'B': { // 0x42
                    switch (s[3]) {
                        case 'T': { // 0x54
                            if (s == "BHUTAN") {
                                return 56;
                            }
                        }
                        break;
                        case 'N': { // 0x4e
                            if (s == "BRUNEI") {
                                return 57;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "BELIZE") {
                                return 147;
                            }
                        }
                        break;
                        case 'Z': { // 0x5a
                            if (s == "BRAZIL") {
                                return 182;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "ISRAEL") {
                        return 67;
                    }
                }
                break;
                case 'J': { // 0x4a
                    if (s == "JORDAN") {
                        return 69;
                    }
                }
                break;
                case 'K': { // 0x4b
                    if (s == "KUWAIT") {
                        return 73;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TURKEY") {
                        return 92;
                    }
                    if (s == "TUVALU") {
                        return 178;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "CYPRUS") {
                        return 108;
                    }
                    if (s == "CANADA") {
                        return 148;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FRANCE") {
                        return 112;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LATVIA") {
                        return 120;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NORWAY") {
                        return 130;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "POLAND") {
                        return 131;
                    }
                    if (s == "PANAMA") {
                        return 161;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SERBIA") {
                        return 135;
                    }
                    if (s == "SWEDEN") {
                        return 139;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[4]) {
                case 'R': { // 0x52
                    switch (s[1]) {
                        case 'L': { // 0x4c
                            if (s == "ALGERIA") {
                                return 0;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "COMOROS") {
                                return 10;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "ERITREA") {
                                return 15;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "LIBERIA") {
                                return 25;
                            }
                            if (s == "NIGERIA") {
                                return 36;
                            }
                        }
                        break;
                        case 'N': { // 0x4e
                            if (s == "ANDORRA") {
                                return 99;
                            }
                        }
                        break;
                        case 'U': { // 0x55
                            if (s == "AUSTRIA") {
                                return 101;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "BELARUS") {
                                return 103;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'I': { // 0x49
                    switch (s[1]) {
                        case 'U': { // 0x55
                            if (s == "BURKINA") {
                                return 4;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "BELGIUM") {
                                return 104;
                            }
                        }
                        break;
                        case 'K': { // 0x4b
                            if (s == "UKRAINE") {
                                return 141;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "JAMAICA") {
                                return 158;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'N': { // 0x4e
                    switch (s[1]) {
                        case 'U': { // 0x55
                            if (s == "BURUNDI") {
                                return 5;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "LEBANON") {
                                return 76;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "VIETNAM") {
                                return 96;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "ALBANIA") {
                                return 98;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "ARMENIA") {
                                return 100;
                            }
                        }
                        break;
                        case 'S': { // 0x53
                            if (s == "ESTONIA") {
                                return 110;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "ROMANIA") {
                                return 133;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "LESOTHO") {
                        return 24;
                    }
                    if (s == "CROATIA") {
                        return 107;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "MOROCCO") {
                        return 32;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "NAMIBIA") {
                        return 34;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "SENEGAL") {
                        return 39;
                    }
                    if (s == "GEORGIA") {
                        return 113;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "SOMALIA") {
                        return 42;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "TUNISIA") {
                        return 49;
                    }
                }
                break;
                case 'A': { // 0x41
                    switch (s[0]) {
                        case 'B': { // 0x42
                            if (s == "BAHRAIN") {
                                return 54;
                            }
                        }
                        break;
                        case 'D': { // 0x44
                            if (s == "DENMARK") {
                                return 109;
                            }
                        }
                        break;
                        case 'F': { // 0x46
                            if (s == "FINLAND") {
                                return 111;
                            }
                        }
                        break;
                        case 'G': { // 0x47
                            if (s == "GERMANY") {
                                return 114;
                            }
                            if (s == "GRENADA") {
                                return 154;
                            }
                        }
                        break;
                        case 'H': { // 0x48
                            if (s == "HUNGARY") {
                                return 116;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "ICELAND") {
                                return 117;
                            }
                            if (s == "IRELAND") {
                                return 118;
                            }
                        }
                        break;
                        case 'V': { // 0x56
                            if (s == "VANUATU") {
                                return 179;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MYANMAR") {
                        return 59;
                    }
                    if (s == "BAHAMAS") {
                        return 145;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "MOLDOVA") {
                        return 126;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "BOLIVIA") {
                        return 181;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "ECUADOR") {
                        return 185;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "URUGUAY") {
                        return 190;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[4]) {
                case 'W': { // 0x57
                    if (s == "BOTSWANA") {
                        return 3;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "CAMEROON") {
                        return 6;
                    }
                }
                break;
                case 'O': { // 0x4f
                    switch (s[0]) {
                        case 'D': { // 0x44
                            if (s == "DJIBOUTI") {
                                return 12;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "ETHIOPIA") {
                                return 16;
                            }
                        }
                        break;
                        case 'C': { // 0x43
                            if (s == "CAMBODIA") {
                                return 60;
                            }
                        }
                        break;
                        case 'M': { // 0x4d
                            if (s == "MONGOLIA") {
                                return 79;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'A': { // 0x41
                    switch (s[2]) {
                        case 'N': { // 0x4e
                            if (s == "TANZANIA") {
                                return 47;
                            }
                        }
                        break;
                        case 'M': { // 0x4d
                            if (s == "ZIMBABWE") {
                                return 52;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "BULGARIA") {
                                return 106;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "SLOVAKIA") {
                                return 136;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "BARBADOS") {
                                return 146;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "MALAYSIA") {
                        return 77;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "MALDIVES") {
                        return 78;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "PAKISTAN") {
                        return 82;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "THAILAND") {
                        return 91;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "PORTUGAL") {
                        return 132;
                    }
                    if (s == "HONDURAS") {
                        return 157;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "SLOVENIA") {
                        return 137;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "DOMINICA") {
                        return 151;
                    }
                    if (s == "SURINAME") {
                        return 189;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "KIRIBATI") {
                        return 168;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "COLOMBIA") {
                        return 184;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "PARAGUAY") {
                        return 187;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[3]) {
                case 'R': { // 0x52
                    if (s == "MAURITIUS") {
                        return 31;
                    }
                }
                break;
                case 'Z': { // 0x5a
                    if (s == "SWAZILAND") {
                        return 46;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "INDONESIA") {
                        return 64;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "SINGAPORE") {
                        return 87;
                    }
                }
                break;
                case ' ': { // 0x20
                    if (s == "SRI LANKA") {
                        return 88;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "LITHUANIA") {
                        return 122;
                    }
                }
                break;
                case 'E': { // 0x45
                    switch (s[0]) {
                        case 'M': { // 0x4d
                            if (s == "MACEDONIA") {
                                return 124;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "ARGENTINA") {
                                return 180;
                            }
                        }
                        break;
                        case 'V': { // 0x56
                            if (s == "VENEZUELA") {
                                return 191;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "GUATEMALA") {
                        return 155;
                    }
                    if (s == "AUSTRALIA") {
                        return 166;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "NICARAGUA") {
                        return 160;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            switch (s[7]) {
                case 'R': { // 0x52
                    if (s == "CAPE VERDE") {
                        return 7;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "MADAGASCAR") {
                        return 27;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "MAURITANIA") {
                        return 30;
                    }
                }
                break;
                case 'Q': { // 0x51
                    if (s == "MOZAMBIQUE") {
                        return 33;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "SEYCHELLES") {
                        return 40;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "BANGLADESH") {
                        return 55;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "EAST TIMOR") {
                        return 62;
                    }
                }
                break;
                case 'T': { // 0x54
                    switch (s[2]) {
                        case 'Z': { // 0x5a
                            if (s == "KAZAKHSTAN") {
                                return 70;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "KYRGYZSTAN") {
                                return 74;
                            }
                        }
                        break;
                        case 'J': { // 0x4a
                            if (s == "TAJIKISTAN") {
                                return 90;
                            }
                        }
                        break;
                        case 'B': { // 0x42
                            if (s == "UZBEKISTAN") {
                                return 95;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'J': { // 0x4a
                    if (s == "AZERBAIJAN") {
                        return 102;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "LUXEMBOURG") {
                        return 123;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "MONTENEGRO") {
                        return 128;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "SAN MARINO") {
                        return 134;
                    }
                    if (s == "COSTA RICA") {
                        return 149;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "MICRONESIA") {
                        return 170;
                    }
                }
                break;
            }
        }
        break;
        case 11: {
            switch (s[1]) {
                case 'V': { // 0x56
                    if (s == "IVORY COAST") {
                        return 22;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "SOUTH SUDAN") {
                        return 44;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "AFGHANISTAN") {
                        return 53;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "PHILIPPINES") {
                        return 83;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "NETHERLANDS") {
                        return 129;
                    }
                    if (s == "NEW ZEALAND") {
                        return 172;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "SWITZERLAND") {
                        return 140;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "EL SALVADOR") {
                        return 153;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "SAINT LUCIA") {
                        return 163;
                    }
                }
                break;
            }
        }
        break;
        case 12: {
            switch (s[7]) {
                case 'L': { // 0x4c
                    if (s == "SIERRA LEONE") {
                        return 41;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "SOUTH AFRICA") {
                        return 43;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "KOREA, NORTH") {
                        return 71;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "KOREA, SOUTH") {
                        return 72;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "SAUDI ARABIA") {
                        return 86;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "TURKMENISTAN") {
                        return 93;
                    }
                }
                break;
                case ' ': { // 0x20
                    if (s == "VATICAN CITY") {
                        return 143;
                    }
                }
                break;
            }
        }
        break;
        case 13: {
            if (s == "GUINEA-BISSAU") {
                return 21;
            }
            if (s == "LIECHTENSTEIN") {
                return 121;
            }
        }
        break;
        case 14: {
            if (s == "UNITED KINGDOM") {
                return 142;
            }
        }
        break;
        case 15: {
            if (s == "SOLOMON ISLANDS") {
                return 176;
            }
        }
        break;
        case 16: {
            if (s == "MARSHALL ISLANDS") {
                return 169;
            }
            if (s == "PAPUA NEW GUINEA") {
                return 174;
            }
        }
        break;
        case 17: {
            if (s == "EQUATORIAL GUINEA") {
                return 14;
            }
        }
        break;
        case 18: {
            if (s == "RUSSIAN FEDERATION") {
                return 85;
            }
            if (s == "DOMINICAN REPUBLIC") {
                return 152;
            }
        }
        break;
        case 19: {
            if (s == "ANTIGUA AND BARBUDA") {
                return 144;
            }
            if (s == "TRINIDAD AND TOBAGO") {
                return 165;
            }
        }
        break;
        case 20: {
            if (s == "UNITED ARAB EMIRATES") {
                return 94;
            }
        }
        break;
        case 21: {
            if (s == "SAO TOME AND PRINCIPE") {
                return 38;
            }
            if (s == "SAINT KITTS AND NEVIS") {
                return 162;
            }
        }
        break;
        case 22: {
            if (s == "BOSNIA AND HERZEGOVINA") {
                return 105;
            }
        }
        break;
        case 24: {
            if (s == "CENTRAL AFRICAN REPUBLIC") {
                return 8;
            }
        }
        break;
        case 32: {
            if (s == "SAINT VINCENT AND THE GRENADINES") {
                return 164;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=countries, name=check_countries_split, type=split
void check_countries_split() {
    assert(lookup_countries_split("ALGERIA") == 0);
    assert(lookup_countries_split("ANGOLA") == 1);
    assert(lookup_countries_split("BENIN") == 2);
    assert(lookup_countries_split("BOTSWANA") == 3);
    assert(lookup_countries_split("BURKINA") == 4);
    assert(lookup_countries_split("BURUNDI") == 5);
    assert(lookup_countries_split("CAMEROON") == 6);
    assert(lookup_countries_split("CAPE VERDE") == 7);
    assert(lookup_countries_split("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_split("CHAD") == 9);
    assert(lookup_countries_split("COMOROS") == 10);
    assert(lookup_countries_split("CONGO") == 11);
    assert(lookup_countries_split("DJIBOUTI") == 12);
    assert(lookup_countries_split("EGYPT") == 13);
    assert(lookup_countries_split("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_split("ERITREA") == 15);
    assert(lookup_countries_split("ETHIOPIA") == 16);
    assert(lookup_countries_split("GABON") == 17);
    assert(lookup_countries_split("GAMBIA") == 18);
    assert(lookup_countries_split("GHANA") == 19);
    assert(lookup_countries_split("GUINEA") == 20);
    assert(lookup_countries_split("GUINEA-BISSAU") == 21);
    assert(lookup_countries_split("IVORY COAST") == 22);
    assert(lookup_countries_split("KENYA") == 23);
    assert(lookup_countries_split("LESOTHO") == 24);
    assert(lookup_countries_split("LIBERIA") == 25);
    assert(lookup_countries_split("LIBYA") == 26);
    assert(lookup_countries_split("MADAGASCAR") == 27);
    assert(lookup_countries_split("MALAWI") == 28);
    assert(lookup_countries_split("MALI") == 29);
    assert(lookup_countries_split("MAURITANIA") == 30);
    assert(lookup_countries_split("MAURITIUS") == 31);
    assert(lookup_countries_split("MOROCCO") == 32);
    assert(lookup_countries_split("MOZAMBIQUE") == 33);
    assert(lookup_countries_split("NAMIBIA") == 34);
    assert(lookup_countries_split("NIGER") == 35);
    assert(lookup_countries_split("NIGERIA") == 36);
    assert(lookup_countries_split("RWANDA") == 37);
    assert(lookup_countries_split("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_split("SENEGAL") == 39);
    assert(lookup_countries_split("SEYCHELLES") == 40);
    assert(lookup_countries_split("SIERRA LEONE") == 41);
    assert(lookup_countries_split("SOMALIA") == 42);
    assert(lookup_countries_split("SOUTH AFRICA") == 43);
    assert(lookup_countries_split("SOUTH SUDAN") == 44);
    assert(lookup_countries_split("SUDAN") == 45);
    assert(lookup_countries_split("SWAZILAND") == 46);
    assert(lookup_countries_split("TANZANIA") == 47);
    assert(lookup_countries_split("TOGO") == 48);
    assert(lookup_countries_split("TUNISIA") == 49);
    assert(lookup_countries_split("UGANDA") == 50);
    assert(lookup_countries_split("ZAMBIA") == 51);
    assert(lookup_countries_split("ZIMBABWE") == 52);
    assert(lookup_countries_split("AFGHANISTAN") == 53);
    assert(lookup_countries_split("BAHRAIN") == 54);
    assert(lookup_countries_split("BANGLADESH") == 55);
    assert(lookup_countries_split("BHUTAN") == 56);
    assert(lookup_countries_split("BRUNEI") == 57);
    assert(lookup_countries_split("BURMA") == 58);
    assert(lookup_countries_split("MYANMAR") == 59);
    assert(lookup_countries_split("CAMBODIA") == 60);
    assert(lookup_countries_split("CHINA") == 61);
    assert(lookup_countries_split("EAST TIMOR") == 62);
    assert(lookup_countries_split("INDIA") == 63);
    assert(lookup_countries_split("INDONESIA") == 64);
    assert(lookup_countries_split("IRAN") == 65);
    assert(lookup_countries_split("IRAQ") == 66);
    assert(lookup_countries_split("ISRAEL") == 67);
    assert(lookup_countries_split("JAPAN") == 68);
    assert(lookup_countries_split("JORDAN") == 69);
    assert(lookup_countries_split("KAZAKHSTAN") == 70);
    assert(lookup_countries_split("KOREA, NORTH") == 71);
    assert(lookup_countries_split("KOREA, SOUTH") == 72);
    assert(lookup_countries_split("KUWAIT") == 73);
    assert(lookup_countries_split("KYRGYZSTAN") == 74);
    assert(lookup_countries_split("LAOS") == 75);
    assert(lookup_countries_split("LEBANON") == 76);
    assert(lookup_countries_split("MALAYSIA") == 77);
    assert(lookup_countries_split("MALDIVES") == 78);
    assert(lookup_countries_split("MONGOLIA") == 79);
    assert(lookup_countries_split("NEPAL") == 80);
    assert(lookup_countries_split("OMAN") == 81);
    assert(lookup_countries_split("PAKISTAN") == 82);
    assert(lookup_countries_split("PHILIPPINES") == 83);
    assert(lookup_countries_split("QATAR") == 84);
    assert(lookup_countries_split("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_split("SAUDI ARABIA") == 86);
    assert(lookup_countries_split("SINGAPORE") == 87);
    assert(lookup_countries_split("SRI LANKA") == 88);
    assert(lookup_countries_split("SYRIA") == 89);
    assert(lookup_countries_split("TAJIKISTAN") == 90);
    assert(lookup_countries_split("THAILAND") == 91);
    assert(lookup_countries_split("TURKEY") == 92);
    assert(lookup_countries_split("TURKMENISTAN") == 93);
    assert(lookup_countries_split("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_split("UZBEKISTAN") == 95);
    assert(lookup_countries_split("VIETNAM") == 96);
    assert(lookup_countries_split("YEMEN") == 97);
    assert(lookup_countries_split("ALBANIA") == 98);
    assert(lookup_countries_split("ANDORRA") == 99);
    assert(lookup_countries_split("ARMENIA") == 100);
    assert(lookup_countries_split("AUSTRIA") == 101);
    assert(lookup_countries_split("AZERBAIJAN") == 102);
    assert(lookup_countries_split("BELARUS") == 103);
    assert(lookup_countries_split("BELGIUM") == 104);
    assert(lookup_countries_split("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_split("BULGARIA") == 106);
    assert(lookup_countries_split("CROATIA") == 107);
    assert(lookup_countries_split("CYPRUS") == 108);
    assert(lookup_countries_split("DENMARK") == 109);
    assert(lookup_countries_split("ESTONIA") == 110);
    assert(lookup_countries_split("FINLAND") == 111);
    assert(lookup_countries_split("FRANCE") == 112);
    assert(lookup_countries_split("GEORGIA") == 113);
    assert(lookup_countries_split("GERMANY") == 114);
    assert(lookup_countries_split("GREECE") == 115);
    assert(lookup_countries_split("HUNGARY") == 116);
    assert(lookup_countries_split("ICELAND") == 117);
    assert(lookup_countries_split("IRELAND") == 118);
    assert(lookup_countries_split("ITALY") == 119);
    assert(lookup_countries_split("LATVIA") == 120);
    assert(lookup_countries_split("LIECHTENSTEIN") == 121);
    assert(lookup_countries_split("LITHUANIA") == 122);
    assert(lookup_countries_split("LUXEMBOURG") == 123);
    assert(lookup_countries_split("MACEDONIA") == 124);
    assert(lookup_countries_split("MALTA") == 125);
    assert(lookup_countries_split("MOLDOVA") == 126);
    assert(lookup_countries_split("MONACO") == 127);
    assert(lookup_countries_split("MONTENEGRO") == 128);
    assert(lookup_countries_split("NETHERLANDS") == 129);
    assert(lookup_countries_split("NORWAY") == 130);
    assert(lookup_countries_split("POLAND") == 131);
    assert(lookup_countries_split("PORTUGAL") == 132);
    assert(lookup_countries_split("ROMANIA") == 133);
    assert(lookup_countries_split("SAN MARINO") == 134);
    assert(lookup_countries_split("SERBIA") == 135);
    assert(lookup_countries_split("SLOVAKIA") == 136);
    assert(lookup_countries_split("SLOVENIA") == 137);
    assert(lookup_countries_split("SPAIN") == 138);
    assert(lookup_countries_split("SWEDEN") == 139);
    assert(lookup_countries_split("SWITZERLAND") == 140);
    assert(lookup_countries_split("UKRAINE") == 141);
    assert(lookup_countries_split("UNITED KINGDOM") == 142);
    assert(lookup_countries_split("VATICAN CITY") == 143);
    assert(lookup_countries_split("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_split("BAHAMAS") == 145);
    assert(lookup_countries_split("BARBADOS") == 146);
    assert(lookup_countries_split("BELIZE") == 147);
    assert(lookup_countries_split("CANADA") == 148);
    assert(lookup_countries_split("COSTA RICA") == 149);
    assert(lookup_countries_split("CUBA") == 150);
    assert(lookup_countries_split("DOMINICA") == 151);
    assert(lookup_countries_split("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_split("EL SALVADOR") == 153);
    assert(lookup_countries_split("GRENADA") == 154);
    assert(lookup_countries_split("GUATEMALA") == 155);
    assert(lookup_countries_split("HAITI") == 156);
    assert(lookup_countries_split("HONDURAS") == 157);
    assert(lookup_countries_split("JAMAICA") == 158);
    assert(lookup_countries_split("MEXICO") == 159);
    assert(lookup_countries_split("NICARAGUA") == 160);
    assert(lookup_countries_split("PANAMA") == 161);
    assert(lookup_countries_split("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_split("SAINT LUCIA") == 163);
    assert(lookup_countries_split("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_split("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_split("AUSTRALIA") == 166);
    assert(lookup_countries_split("FIJI") == 167);
    assert(lookup_countries_split("KIRIBATI") == 168);
    assert(lookup_countries_split("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_split("MICRONESIA") == 170);
    assert(lookup_countries_split("NAURU") == 171);
    assert(lookup_countries_split("NEW ZEALAND") == 172);
    assert(lookup_countries_split("PALAU") == 173);
    assert(lookup_countries_split("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_split("SAMOA") == 175);
    assert(lookup_countries_split("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_split("TONGA") == 177);
    assert(lookup_countries_split("TUVALU") == 178);
    assert(lookup_countries_split("VANUATU") == 179);
    assert(lookup_countries_split("ARGENTINA") == 180);
    assert(lookup_countries_split("BOLIVIA") == 181);
    assert(lookup_countries_split("BRAZIL") == 182);
    assert(lookup_countries_split("CHILE") == 183);
    assert(lookup_countries_split("COLOMBIA") == 184);
    assert(lookup_countries_split("ECUADOR") == 185);
    assert(lookup_countries_split("GUYANA") == 186);
    assert(lookup_countries_split("PARAGUAY") == 187);
    assert(lookup_countries_split("PERU") == 188);
    assert(lookup_countries_split("SURINAME") == 189);
    assert(lookup_countries_split("URUGUAY") == 190);
    assert(lookup_countries_split("VENEZUELA") == 191);
}
