//lookup: dataset=sneller, name=lookup_sneller_split, type=split
int lookup_sneller_split(std::string_view s) {
    switch (s.size()) {
        case 2: {
            switch (s[1]) {
                case 'S': { // 0x53
                    if (s == "AS") {
                        return 2;
                    }
                    if (s == "IS") {
                        return 36;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "AT") {
                        return 3;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "OR") {
                        return 16;
                    }
                }
                break;
                case 'N': { // 0x4e
                    switch (s[0]) {
                        case 'O': { // 0x4f
                            if (s == "ON") {
                                return 17;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "IN") {
                                return 37;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "LN") {
                                return 154;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "BY") {
                        return 23;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "TO") {
                        return 30;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "GV") {
                        return 92;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "PI") {
                        return 161;
                    }
                }
                break;
            }
        }
        break;
        case 3: {
            switch (s[1]) {
                case 'N': { // 0x4e
                    if (s == "AND") {
                        return 1;
                    }
                    if (s == "END") {
                        return 53;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "ASC") {
                        return 4;
                    }
                }
                break;
                case 'O': { // 0x4f
                    switch (s[0]) {
                        case 'N': { // 0x4e
                            if (s == "NOT") {
                                return 39;
                            }
                        }
                        break;
                        case 'D': { // 0x44
                            if (s == "DOW") {
                                return 117;
                            }
                            if (s == "DOY") {
                                return 118;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "LOG") {
                                return 156;
                            }
                        }
                        break;
                        case 'P': { // 0x50
                            if (s == "POW") {
                                return 159;
                            }
                        }
                        break;
                        case 'C': { // 0x43
                            if (s == "COS") {
                                return 165;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "ALL") {
                        return 40;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "SUM") {
                        return 68;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "MIN") {
                        return 69;
                    }
                    if (s == "SIN") {
                        return 164;
                    }
                }
                break;
                case 'A': { // 0x41
                    switch (s[0]) {
                        case 'M': { // 0x4d
                            if (s == "MAX") {
                                return 70;
                            }
                        }
                        break;
                        case 'D': { // 0x44
                            if (s == "DAY") {
                                return 116;
                            }
                        }
                        break;
                        case 'T': { // 0x54
                            if (s == "TAN") {
                                return 166;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "AVG") {
                        return 76;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "ABS") {
                        return 140;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "EXP") {
                        return 149;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 'C': { // 0x43
                    switch (s[1]) {
                        case 'A': { // 0x41
                            if (s == "CAST") {
                                return 5;
                            }
                            if (s == "CASE") {
                                return 49;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "CEIL") {
                                return 146;
                            }
                        }
                        break;
                        case 'B': { // 0x42
                            if (s == "CBRT") {
                                return 148;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DESC") {
                        return 10;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OVER") {
                        return 18;
                    }
                }
                break;
                case 'F': { // 0x46
                    if (s == "FROM") {
                        return 19;
                    }
                }
                break;
                case 'L': { // 0x4c
                    switch (s[1]) {
                        case 'I': { // 0x49
                            if (s == "LIKE") {
                                return 28;
                            }
                            if (s == "LIST") {
                                return 91;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "LEFT") {
                                return 41;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "LAST") {
                                return 56;
                            }
                        }
                        break;
                        case 'N': { // 0x4e
                            if (s == "LN1P") {
                                return 155;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "LOG2") {
                                return 157;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NULL") {
                        return 31;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "INTO") {
                        return 38;
                    }
                }
                break;
                case 'J': { // 0x4a
                    if (s == "JOIN") {
                        return 44;
                    }
                }
                break;
                case 'T': { // 0x54
                    switch (s[2]) {
                        case 'U': { // 0x55
                            if (s == "TRUE") {
                                return 46;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "THEN") {
                                return 51;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "TRIM") {
                                return 61;
                            }
                        }
                        break;
                        case 'X': { // 0x58
                            if (s == "TEXT") {
                                return 90;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'W': { // 0x57
                    switch (s[1]) {
                        case 'H': { // 0x48
                            if (s == "WHEN") {
                                return 50;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "WITH") {
                                return 58;
                            }
                        }
                        break;
                        case 'E': { // 0x45
                            if (s == "WEEK") {
                                return 119;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "ELSE") {
                        return 52;
                    }
                    if (s == "EXP2") {
                        return 151;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "BOTH") {
                        return 64;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "RANK") {
                        return 85;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "HOUR") {
                        return 115;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "YEAR") {
                        return 122;
                    }
                }
                break;
                case 'S': { // 0x53
                    switch (s[2]) {
                        case 'G': { // 0x47
                            if (s == "SIGN") {
                                return 141;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "SQRT") {
                                return 147;
                            }
                        }
                        break;
                        case 'Z': { // 0x5a
                            if (s == "SIZE") {
                                return 222;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'A': { // 0x41
                    switch (s[1]) {
                        case 'S': { // 0x53
                            if (s == "ASIN") {
                                return 167;
                            }
                        }
                        break;
                        case 'C': { // 0x43
                            if (s == "ACOS") {
                                return 168;
                            }
                        }
                        break;
                        case 'T': { // 0x54
                            if (s == "ATAN") {
                                return 169;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'U': { // 0x55
                    if (s == "UNION") {
                        return 15;
                    }
                    if (s == "UPPER") {
                        return 125;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WHERE") {
                        return 20;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "GROUP") {
                        return 21;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "ORDER") {
                        return 22;
                    }
                }
                break;
                case 'L': { // 0x4c
                    switch (s[2]) {
                        case 'M': { // 0x4d
                            if (s == "LIMIT") {
                                return 25;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "LTRIM") {
                                return 123;
                            }
                        }
                        break;
                        case 'W': { // 0x57
                            if (s == "LOWER") {
                                return 126;
                            }
                        }
                        break;
                        case 'G': { // 0x47
                            if (s == "LOG10") {
                                return 158;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "LEAST") {
                                return 171;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "ILIKE") {
                        return 27;
                    }
                    if (s == "INNER") {
                        return 45;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NULLS") {
                        return 32;
                    }
                }
                break;
                case 'R': { // 0x52
                    switch (s[1]) {
                        case 'I': { // 0x49
                            if (s == "RIGHT") {
                                return 42;
                            }
                        }
                        break;
                        case 'T': { // 0x54
                            if (s == "RTRIM") {
                                return 124;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "ROUND") {
                                return 142;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "CROSS") {
                        return 43;
                    }
                    if (s == "COUNT") {
                        return 67;
                    }
                }
                break;
                case 'F': { // 0x46
                    switch (s[1]) {
                        case 'A': { // 0x41
                            if (s == "FALSE") {
                                return 47;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "FIRST") {
                                return 55;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "FLOAT") {
                                return 95;
                            }
                            if (s == "FLOOR") {
                                return 145;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "VALUE") {
                        return 54;
                    }
                }
                break;
                case 'E': { // 0x45
                    switch (s[3]) {
                        case 'R': { // 0x52
                            if (s == "EVERY") {
                                return 73;
                            }
                        }
                        break;
                        case 'M': { // 0x4d
                            if (s == "EXPM1") {
                                return 150;
                            }
                        }
                        break;
                        case '1': { // 0x31
                            if (s == "EXP10") {
                                return 152;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MONTH") {
                        return 120;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TRUNC") {
                        return 144;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "HYPOT") {
                        return 153;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "ATAN2") {
                        return 170;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[3]) {
                case 'E': { // 0x45
                    if (s == "SELECT") {
                        return 0;
                    }
                    if (s == "LATEST") {
                        return 72;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "CONCAT") {
                        return 6;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "EXISTS") {
                        return 14;
                    }
                    if (s == "OFFSET") {
                        return 26;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "HAVING") {
                        return 24;
                    }
                    if (s == "STRING") {
                        return 98;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "NULLIF") {
                        return 33;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "UTCNOW") {
                        return 57;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "FILTER") {
                        return 59;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "ESCAPE") {
                        return 66;
                    }
                }
                break;
                case 'D': { // 0x44
                    switch (s[1]) {
                        case 'T': { // 0x54
                            if (s == "STDDEV") {
                                return 79;
                            }
                        }
                        break;
                        case 'U': { // 0x55
                            if (s == "SUNDAY") {
                                return 102;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "MONDAY") {
                                return 103;
                            }
                        }
                        break;
                        case 'R': { // 0x52
                            if (s == "FRIDAY") {
                                return 107;
                            }
                        }
                        break;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "BIT_OR") {
                        return 82;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "STRUCT") {
                        return 100;
                    }
                    if (s == "MINUTE") {
                        return 114;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "SYMBOL") {
                        return 101;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "SECOND") {
                        return 113;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[4]) {
                case 'A': { // 0x41
                    switch (s[3]) {
                        case 'R': { // 0x52
                            if (s == "EXTRACT") {
                                return 13;
                            }
                        }
                        break;
                        case 'L': { // 0x4c
                            if (s == "EXPLAIN") {
                                return 65;
                            }
                        }
                        break;
                        case '_': { // 0x5f
                            if (s == "BIT_AND") {
                                return 81;
                            }
                        }
                        break;
                        case 'I': { // 0x49
                            if (s == "RADIANS") {
                                return 163;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "SIMILAR") {
                        return 29;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "MISSING") {
                        return 35;
                    }
                    if (s == "LEADING") {
                        return 62;
                    }
                }
                break;
                case 'E': { // 0x45
                    switch (s[2]) {
                        case 'T': { // 0x54
                            if (s == "BETWEEN") {
                                return 48;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "BOOLEAN") {
                                return 96;
                            }
                        }
                        break;
                        case 'G': { // 0x47
                            if (s == "DEGREES") {
                                return 162;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "UNPIVOT") {
                        return 60;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "BOOL_OR") {
                        return 75;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "BIT_XOR") {
                        return 83;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "DEFAULT") {
                        return 89;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "INTEGER") {
                        return 94;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "DECIMAL") {
                        return 99;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "TUESDAY") {
                        return 104;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "QUARTER") {
                        return 121;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[2]) {
                case 'A': { // 0x41
                    switch (s[0]) {
                        case 'C': { // 0x43
                            if (s == "COALESCE") {
                                return 7;
                            }
                        }
                        break;
                        case 'T': { // 0x54
                            if (s == "TRAILING") {
                                return 63;
                            }
                        }
                        break;
                        case 'G': { // 0x47
                            if (s == "GRAPHVIZ") {
                                return 93;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "DATE_ADD") {
                        return 8;
                    }
                    if (s == "SATURDAY") {
                        return 108;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "DISTINCT") {
                        return 11;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "EARLIEST") {
                        return 71;
                    }
                    if (s == "VARIANCE") {
                        return 77;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "BOOL_AND") {
                        return 74;
                    }
                    if (s == "GEO_HASH") {
                        return 217;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "THURSDAY") {
                        return 106;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "CONTAINS") {
                        return 127;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "POW_UINT") {
                        return 160;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "GREATEST") {
                        return 172;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "TYPE_BIT") {
                        return 237;
                    }
                }
                break;
            }
        }
        break;
        case 9: {
            switch (s[0]) {
                case 'D': { // 0x44
                    if (s == "DATE_DIFF") {
                        return 9;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "PARTITION") {
                        return 34;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TIMESTAMP") {
                        return 97;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WEDNESDAY") {
                        return 105;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "EQUALS_CI") {
                        return 129;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SUBSTRING") {
                        return 137;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "BIT_COUNT") {
                        return 139;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MAKE_LIST") {
                        return 235;
                    }
                }
                break;
            }
        }
        break;
        case 10: {
            switch (s[9]) {
                case 'C': { // 0x43
                    if (s == "DATE_TRUNC") {
                        return 12;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "STDDEV_POP") {
                        return 80;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "ROW_NUMBER") {
                        return 84;
                    }
                }
                break;
                case 'K': { // 0x4b
                    if (s == "DENSE_RANK") {
                        return 86;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "SPLIT_PART") {
                        return 138;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "ROUND_EVEN") {
                        return 143;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "GEO_TILE_X") {
                        return 218;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "GEO_TILE_Y") {
                        return 219;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "ARRAY_SIZE") {
                        return 224;
                    }
                }
                break;
                case 'B': { // 0x42
                    if (s == "TABLE_GLOB") {
                        return 226;
                    }
                }
                break;
            }
        }
        break;
        case 11: {
            switch (s[2]) {
                case 'C': { // 0x43
                    if (s == "MICROSECOND") {
                        return 109;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "MILLISECOND") {
                        return 111;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "CONTAINS_CI") {
                        return 128;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "CHAR_LENGTH") {
                        return 135;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "GEO_TILE_ES") {
                        return 220;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "IN_SUBQUERY") {
                        return 228;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "TIME_BUCKET") {
                        return 234;
                    }
                }
                break;
                case 'K': { // 0x4b
                    if (s == "MAKE_STRUCT") {
                        return 236;
                    }
                }
                break;
            }
        }
        break;
        case 12: {
            switch (s[4]) {
                case 'A': { // 0x41
                    if (s == "VARIANCE_POP") {
                        return 78;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "MICROSECONDS") {
                        return 110;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "MILLISECONDS") {
                        return 112;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "EQUALS_FUZZY") {
                        return 130;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "OCTET_LENGTH") {
                        return 134;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "IS_SUBNET_OF") {
                        return 136;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "WIDTH_BUCKET") {
                        return 173;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "DATE_ADD_DAY") {
                        return 179;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "GEO_DISTANCE") {
                        return 221;
                    }
                }
                break;
            }
        }
        break;
        case 13: {
            switch (s[9]) {
                case 'H': { // 0x48
                    if (s == "DATE_ADD_HOUR") {
                        return 178;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "DATE_ADD_WEEK") {
                        return 180;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_ADD_YEAR") {
                        return 183;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "DATE_DIFF_DAY") {
                        return 189;
                    }
                }
                break;
                case 'P': { // 0x50
                    if (s == "TO_UNIX_EPOCH") {
                        return 215;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "TO_UNIX_MICRO") {
                        return 216;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TABLE_PATTERN") {
                        return 227;
                    }
                }
                break;
            }
        }
        break;
        case 14: {
            switch (s[10]) {
                case 'U': { // 0x55
                    if (s == "CONTAINS_FUZZY") {
                        return 132;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "DATE_ADD_MONTH") {
                        return 181;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_DIFF_HOUR") {
                        return 188;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "DATE_DIFF_WEEK") {
                        return 190;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_DIFF_YEAR") {
                        return 193;
                    }
                }
                break;
                case '_': { // 0x5f
                    if (s == "DATE_TRUNC_DAY") {
                        return 210;
                    }
                    if (s == "DATE_TRUNC_DOW") {
                        return 211;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "ARRAY_CONTAINS") {
                        return 223;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "ARRAY_POSITION") {
                        return 225;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "IN_REPLACEMENT") {
                        return 229;
                    }
                }
                break;
            }
        }
        break;
        case 15: {
            switch (s[11]) {
                case 'C': { // 0x43
                    if (s == "DATE_ADD_SECOND") {
                        return 176;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "DATE_ADD_MINUTE") {
                        return 177;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "DATE_DIFF_MONTH") {
                        return 191;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_TRUNC_HOUR") {
                        return 209;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_TRUNC_YEAR") {
                        return 214;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "ASSERT_ION_TYPE") {
                        return 238;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "PARTITION_VALUE") {
                        return 239;
                    }
                }
                break;
            }
        }
        break;
        case 16: {
            switch (s[15]) {
                case 'R': { // 0x52
                    if (s == "DATE_ADD_QUARTER") {
                        return 182;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DATE_DIFF_SECOND") {
                        return 186;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "DATE_DIFF_MINUTE") {
                        return 187;
                    }
                }
                break;
                case 'Y': { // 0x59
                    if (s == "DATE_EXTRACT_DAY") {
                        return 199;
                    }
                    if (s == "DATE_EXTRACT_DOY") {
                        return 201;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "DATE_EXTRACT_DOW") {
                        return 200;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "DATE_TRUNC_MONTH") {
                        return 212;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "HASH_REPLACEMENT") {
                        return 230;
                    }
                    if (s == "LIST_REPLACEMENT") {
                        return 233;
                    }
                }
                break;
            }
        }
        break;
        case 17: {
            switch (s[15]) {
                case 'P': { // 0x50
                    if (s == "SNELLER_DATASHAPE") {
                        return 88;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "DATE_DIFF_QUARTER") {
                        return 192;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "DATE_EXTRACT_HOUR") {
                        return 198;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "DATE_EXTRACT_YEAR") {
                        return 204;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "DATE_TRUNC_SECOND") {
                        return 207;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "DATE_TRUNC_MINUTE") {
                        return 208;
                    }
                }
                break;
            }
        }
        break;
        case 18: {
            switch (s[1]) {
                case 'A': { // 0x41
                    if (s == "DATE_EXTRACT_MONTH") {
                        return 202;
                    }
                    if (s == "DATE_TRUNC_QUARTER") {
                        return 213;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "SCALAR_REPLACEMENT") {
                        return 231;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "STRUCT_REPLACEMENT") {
                        return 232;
                    }
                }
                break;
            }
        }
        break;
        case 19: {
            if (s == "DATE_EXTRACT_SECOND") {
                return 196;
            }
            if (s == "DATE_EXTRACT_MINUTE") {
                return 197;
            }
        }
        break;
        case 20: {
            switch (s[11]) {
                case 'Y': { // 0x59
                    if (s == "EQUALS_FUZZY_UNICODE") {
                        return 131;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "DATE_ADD_MICROSECOND") {
                        return 174;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "DATE_ADD_MILLISECOND") {
                        return 175;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "DATE_EXTRACT_QUARTER") {
                        return 203;
                    }
                }
                break;
            }
        }
        break;
        case 21: {
            switch (s[12]) {
                case '_': { // 0x5f
                    if (s == "APPROX_COUNT_DISTINCT") {
                        return 87;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "DATE_DIFF_MICROSECOND") {
                        return 184;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "DATE_DIFF_MILLISECOND") {
                        return 185;
                    }
                }
                break;
            }
        }
        break;
        case 22: {
            switch (s[13]) {
                case 'Y': { // 0x59
                    if (s == "CONTAINS_FUZZY_UNICODE") {
                        return 133;
                    }
                }
                break;
                case 'C': { // 0x43
                    if (s == "DATE_TRUNC_MICROSECOND") {
                        return 205;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "DATE_TRUNC_MILLISECOND") {
                        return 206;
                    }
                }
                break;
            }
        }
        break;
        case 24: {
            if (s == "DATE_EXTRACT_MICROSECOND") {
                return 194;
            }
            if (s == "DATE_EXTRACT_MILLISECOND") {
                return 195;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=sneller, name=check_sneller_split, type=split
void check_sneller_split() {
    assert(lookup_sneller_split("SELECT") == 0);
    assert(lookup_sneller_split("AND") == 1);
    assert(lookup_sneller_split("AS") == 2);
    assert(lookup_sneller_split("AT") == 3);
    assert(lookup_sneller_split("ASC") == 4);
    assert(lookup_sneller_split("CAST") == 5);
    assert(lookup_sneller_split("CONCAT") == 6);
    assert(lookup_sneller_split("COALESCE") == 7);
    assert(lookup_sneller_split("DATE_ADD") == 8);
    assert(lookup_sneller_split("DATE_DIFF") == 9);
    assert(lookup_sneller_split("DESC") == 10);
    assert(lookup_sneller_split("DISTINCT") == 11);
    assert(lookup_sneller_split("DATE_TRUNC") == 12);
    assert(lookup_sneller_split("EXTRACT") == 13);
    assert(lookup_sneller_split("EXISTS") == 14);
    assert(lookup_sneller_split("UNION") == 15);
    assert(lookup_sneller_split("OR") == 16);
    assert(lookup_sneller_split("ON") == 17);
    assert(lookup_sneller_split("OVER") == 18);
    assert(lookup_sneller_split("FROM") == 19);
    assert(lookup_sneller_split("WHERE") == 20);
    assert(lookup_sneller_split("GROUP") == 21);
    assert(lookup_sneller_split("ORDER") == 22);
    assert(lookup_sneller_split("BY") == 23);
    assert(lookup_sneller_split("HAVING") == 24);
    assert(lookup_sneller_split("LIMIT") == 25);
    assert(lookup_sneller_split("OFFSET") == 26);
    assert(lookup_sneller_split("ILIKE") == 27);
    assert(lookup_sneller_split("LIKE") == 28);
    assert(lookup_sneller_split("SIMILAR") == 29);
    assert(lookup_sneller_split("TO") == 30);
    assert(lookup_sneller_split("NULL") == 31);
    assert(lookup_sneller_split("NULLS") == 32);
    assert(lookup_sneller_split("NULLIF") == 33);
    assert(lookup_sneller_split("PARTITION") == 34);
    assert(lookup_sneller_split("MISSING") == 35);
    assert(lookup_sneller_split("IS") == 36);
    assert(lookup_sneller_split("IN") == 37);
    assert(lookup_sneller_split("INTO") == 38);
    assert(lookup_sneller_split("NOT") == 39);
    assert(lookup_sneller_split("ALL") == 40);
    assert(lookup_sneller_split("LEFT") == 41);
    assert(lookup_sneller_split("RIGHT") == 42);
    assert(lookup_sneller_split("CROSS") == 43);
    assert(lookup_sneller_split("JOIN") == 44);
    assert(lookup_sneller_split("INNER") == 45);
    assert(lookup_sneller_split("TRUE") == 46);
    assert(lookup_sneller_split("FALSE") == 47);
    assert(lookup_sneller_split("BETWEEN") == 48);
    assert(lookup_sneller_split("CASE") == 49);
    assert(lookup_sneller_split("WHEN") == 50);
    assert(lookup_sneller_split("THEN") == 51);
    assert(lookup_sneller_split("ELSE") == 52);
    assert(lookup_sneller_split("END") == 53);
    assert(lookup_sneller_split("VALUE") == 54);
    assert(lookup_sneller_split("FIRST") == 55);
    assert(lookup_sneller_split("LAST") == 56);
    assert(lookup_sneller_split("UTCNOW") == 57);
    assert(lookup_sneller_split("WITH") == 58);
    assert(lookup_sneller_split("FILTER") == 59);
    assert(lookup_sneller_split("UNPIVOT") == 60);
    assert(lookup_sneller_split("TRIM") == 61);
    assert(lookup_sneller_split("LEADING") == 62);
    assert(lookup_sneller_split("TRAILING") == 63);
    assert(lookup_sneller_split("BOTH") == 64);
    assert(lookup_sneller_split("EXPLAIN") == 65);
    assert(lookup_sneller_split("ESCAPE") == 66);
    assert(lookup_sneller_split("COUNT") == 67);
    assert(lookup_sneller_split("SUM") == 68);
    assert(lookup_sneller_split("MIN") == 69);
    assert(lookup_sneller_split("MAX") == 70);
    assert(lookup_sneller_split("EARLIEST") == 71);
    assert(lookup_sneller_split("LATEST") == 72);
    assert(lookup_sneller_split("EVERY") == 73);
    assert(lookup_sneller_split("BOOL_AND") == 74);
    assert(lookup_sneller_split("BOOL_OR") == 75);
    assert(lookup_sneller_split("AVG") == 76);
    assert(lookup_sneller_split("VARIANCE") == 77);
    assert(lookup_sneller_split("VARIANCE_POP") == 78);
    assert(lookup_sneller_split("STDDEV") == 79);
    assert(lookup_sneller_split("STDDEV_POP") == 80);
    assert(lookup_sneller_split("BIT_AND") == 81);
    assert(lookup_sneller_split("BIT_OR") == 82);
    assert(lookup_sneller_split("BIT_XOR") == 83);
    assert(lookup_sneller_split("ROW_NUMBER") == 84);
    assert(lookup_sneller_split("RANK") == 85);
    assert(lookup_sneller_split("DENSE_RANK") == 86);
    assert(lookup_sneller_split("APPROX_COUNT_DISTINCT") == 87);
    assert(lookup_sneller_split("SNELLER_DATASHAPE") == 88);
    assert(lookup_sneller_split("DEFAULT") == 89);
    assert(lookup_sneller_split("TEXT") == 90);
    assert(lookup_sneller_split("LIST") == 91);
    assert(lookup_sneller_split("GV") == 92);
    assert(lookup_sneller_split("GRAPHVIZ") == 93);
    assert(lookup_sneller_split("INTEGER") == 94);
    assert(lookup_sneller_split("FLOAT") == 95);
    assert(lookup_sneller_split("BOOLEAN") == 96);
    assert(lookup_sneller_split("TIMESTAMP") == 97);
    assert(lookup_sneller_split("STRING") == 98);
    assert(lookup_sneller_split("DECIMAL") == 99);
    assert(lookup_sneller_split("STRUCT") == 100);
    assert(lookup_sneller_split("SYMBOL") == 101);
    assert(lookup_sneller_split("SUNDAY") == 102);
    assert(lookup_sneller_split("MONDAY") == 103);
    assert(lookup_sneller_split("TUESDAY") == 104);
    assert(lookup_sneller_split("WEDNESDAY") == 105);
    assert(lookup_sneller_split("THURSDAY") == 106);
    assert(lookup_sneller_split("FRIDAY") == 107);
    assert(lookup_sneller_split("SATURDAY") == 108);
    assert(lookup_sneller_split("MICROSECOND") == 109);
    assert(lookup_sneller_split("MICROSECONDS") == 110);
    assert(lookup_sneller_split("MILLISECOND") == 111);
    assert(lookup_sneller_split("MILLISECONDS") == 112);
    assert(lookup_sneller_split("SECOND") == 113);
    assert(lookup_sneller_split("MINUTE") == 114);
    assert(lookup_sneller_split("HOUR") == 115);
    assert(lookup_sneller_split("DAY") == 116);
    assert(lookup_sneller_split("DOW") == 117);
    assert(lookup_sneller_split("DOY") == 118);
    assert(lookup_sneller_split("WEEK") == 119);
    assert(lookup_sneller_split("MONTH") == 120);
    assert(lookup_sneller_split("QUARTER") == 121);
    assert(lookup_sneller_split("YEAR") == 122);
    assert(lookup_sneller_split("LTRIM") == 123);
    assert(lookup_sneller_split("RTRIM") == 124);
    assert(lookup_sneller_split("UPPER") == 125);
    assert(lookup_sneller_split("LOWER") == 126);
    assert(lookup_sneller_split("CONTAINS") == 127);
    assert(lookup_sneller_split("CONTAINS_CI") == 128);
    assert(lookup_sneller_split("EQUALS_CI") == 129);
    assert(lookup_sneller_split("EQUALS_FUZZY") == 130);
    assert(lookup_sneller_split("EQUALS_FUZZY_UNICODE") == 131);
    assert(lookup_sneller_split("CONTAINS_FUZZY") == 132);
    assert(lookup_sneller_split("CONTAINS_FUZZY_UNICODE") == 133);
    assert(lookup_sneller_split("OCTET_LENGTH") == 134);
    assert(lookup_sneller_split("CHAR_LENGTH") == 135);
    assert(lookup_sneller_split("IS_SUBNET_OF") == 136);
    assert(lookup_sneller_split("SUBSTRING") == 137);
    assert(lookup_sneller_split("SPLIT_PART") == 138);
    assert(lookup_sneller_split("BIT_COUNT") == 139);
    assert(lookup_sneller_split("ABS") == 140);
    assert(lookup_sneller_split("SIGN") == 141);
    assert(lookup_sneller_split("ROUND") == 142);
    assert(lookup_sneller_split("ROUND_EVEN") == 143);
    assert(lookup_sneller_split("TRUNC") == 144);
    assert(lookup_sneller_split("FLOOR") == 145);
    assert(lookup_sneller_split("CEIL") == 146);
    assert(lookup_sneller_split("SQRT") == 147);
    assert(lookup_sneller_split("CBRT") == 148);
    assert(lookup_sneller_split("EXP") == 149);
    assert(lookup_sneller_split("EXPM1") == 150);
    assert(lookup_sneller_split("EXP2") == 151);
    assert(lookup_sneller_split("EXP10") == 152);
    assert(lookup_sneller_split("HYPOT") == 153);
    assert(lookup_sneller_split("LN") == 154);
    assert(lookup_sneller_split("LN1P") == 155);
    assert(lookup_sneller_split("LOG") == 156);
    assert(lookup_sneller_split("LOG2") == 157);
    assert(lookup_sneller_split("LOG10") == 158);
    assert(lookup_sneller_split("POW") == 159);
    assert(lookup_sneller_split("POW_UINT") == 160);
    assert(lookup_sneller_split("PI") == 161);
    assert(lookup_sneller_split("DEGREES") == 162);
    assert(lookup_sneller_split("RADIANS") == 163);
    assert(lookup_sneller_split("SIN") == 164);
    assert(lookup_sneller_split("COS") == 165);
    assert(lookup_sneller_split("TAN") == 166);
    assert(lookup_sneller_split("ASIN") == 167);
    assert(lookup_sneller_split("ACOS") == 168);
    assert(lookup_sneller_split("ATAN") == 169);
    assert(lookup_sneller_split("ATAN2") == 170);
    assert(lookup_sneller_split("LEAST") == 171);
    assert(lookup_sneller_split("GREATEST") == 172);
    assert(lookup_sneller_split("WIDTH_BUCKET") == 173);
    assert(lookup_sneller_split("DATE_ADD_MICROSECOND") == 174);
    assert(lookup_sneller_split("DATE_ADD_MILLISECOND") == 175);
    assert(lookup_sneller_split("DATE_ADD_SECOND") == 176);
    assert(lookup_sneller_split("DATE_ADD_MINUTE") == 177);
    assert(lookup_sneller_split("DATE_ADD_HOUR") == 178);
    assert(lookup_sneller_split("DATE_ADD_DAY") == 179);
    assert(lookup_sneller_split("DATE_ADD_WEEK") == 180);
    assert(lookup_sneller_split("DATE_ADD_MONTH") == 181);
    assert(lookup_sneller_split("DATE_ADD_QUARTER") == 182);
    assert(lookup_sneller_split("DATE_ADD_YEAR") == 183);
    assert(lookup_sneller_split("DATE_DIFF_MICROSECOND") == 184);
    assert(lookup_sneller_split("DATE_DIFF_MILLISECOND") == 185);
    assert(lookup_sneller_split("DATE_DIFF_SECOND") == 186);
    assert(lookup_sneller_split("DATE_DIFF_MINUTE") == 187);
    assert(lookup_sneller_split("DATE_DIFF_HOUR") == 188);
    assert(lookup_sneller_split("DATE_DIFF_DAY") == 189);
    assert(lookup_sneller_split("DATE_DIFF_WEEK") == 190);
    assert(lookup_sneller_split("DATE_DIFF_MONTH") == 191);
    assert(lookup_sneller_split("DATE_DIFF_QUARTER") == 192);
    assert(lookup_sneller_split("DATE_DIFF_YEAR") == 193);
    assert(lookup_sneller_split("DATE_EXTRACT_MICROSECOND") == 194);
    assert(lookup_sneller_split("DATE_EXTRACT_MILLISECOND") == 195);
    assert(lookup_sneller_split("DATE_EXTRACT_SECOND") == 196);
    assert(lookup_sneller_split("DATE_EXTRACT_MINUTE") == 197);
    assert(lookup_sneller_split("DATE_EXTRACT_HOUR") == 198);
    assert(lookup_sneller_split("DATE_EXTRACT_DAY") == 199);
    assert(lookup_sneller_split("DATE_EXTRACT_DOW") == 200);
    assert(lookup_sneller_split("DATE_EXTRACT_DOY") == 201);
    assert(lookup_sneller_split("DATE_EXTRACT_MONTH") == 202);
    assert(lookup_sneller_split("DATE_EXTRACT_QUARTER") == 203);
    assert(lookup_sneller_split("DATE_EXTRACT_YEAR") == 204);
    assert(lookup_sneller_split("DATE_TRUNC_MICROSECOND") == 205);
    assert(lookup_sneller_split("DATE_TRUNC_MILLISECOND") == 206);
    assert(lookup_sneller_split("DATE_TRUNC_SECOND") == 207);
    assert(lookup_sneller_split("DATE_TRUNC_MINUTE") == 208);
    assert(lookup_sneller_split("DATE_TRUNC_HOUR") == 209);
    assert(lookup_sneller_split("DATE_TRUNC_DAY") == 210);
    assert(lookup_sneller_split("DATE_TRUNC_DOW") == 211);
    assert(lookup_sneller_split("DATE_TRUNC_MONTH") == 212);
    assert(lookup_sneller_split("DATE_TRUNC_QUARTER") == 213);
    assert(lookup_sneller_split("DATE_TRUNC_YEAR") == 214);
    assert(lookup_sneller_split("TO_UNIX_EPOCH") == 215);
    assert(lookup_sneller_split("TO_UNIX_MICRO") == 216);
    assert(lookup_sneller_split("GEO_HASH") == 217);
    assert(lookup_sneller_split("GEO_TILE_X") == 218);
    assert(lookup_sneller_split("GEO_TILE_Y") == 219);
    assert(lookup_sneller_split("GEO_TILE_ES") == 220);
    assert(lookup_sneller_split("GEO_DISTANCE") == 221);
    assert(lookup_sneller_split("SIZE") == 222);
    assert(lookup_sneller_split("ARRAY_CONTAINS") == 223);
    assert(lookup_sneller_split("ARRAY_SIZE") == 224);
    assert(lookup_sneller_split("ARRAY_POSITION") == 225);
    assert(lookup_sneller_split("TABLE_GLOB") == 226);
    assert(lookup_sneller_split("TABLE_PATTERN") == 227);
    assert(lookup_sneller_split("IN_SUBQUERY") == 228);
    assert(lookup_sneller_split("IN_REPLACEMENT") == 229);
    assert(lookup_sneller_split("HASH_REPLACEMENT") == 230);
    assert(lookup_sneller_split("SCALAR_REPLACEMENT") == 231);
    assert(lookup_sneller_split("STRUCT_REPLACEMENT") == 232);
    assert(lookup_sneller_split("LIST_REPLACEMENT") == 233);
    assert(lookup_sneller_split("TIME_BUCKET") == 234);
    assert(lookup_sneller_split("MAKE_LIST") == 235);
    assert(lookup_sneller_split("MAKE_STRUCT") == 236);
    assert(lookup_sneller_split("TYPE_BIT") == 237);
    assert(lookup_sneller_split("ASSERT_ION_TYPE") == 238);
    assert(lookup_sneller_split("PARTITION_VALUE") == 239);
}
