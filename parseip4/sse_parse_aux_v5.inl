/* Code generated automatically; DO NOT EDIT */
    const unsigned max_hash = 137;
    static const int8_t patterns[max_hash + 1][16] = {
        /* 000 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 001 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 002 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 003 */ {0, 3, 7, 9, -1, 2, 6, -1, -1, -1, 5, -1, -1, -1, -1, 3},
        /* 004 */ {0, 3, 7, 10, -1, 2, 6, 9, -1, -1, 5, -1, -1, -1, -1, 3},
        /* 005 */ {0, 3, 7, 11, -1, 2, 6, 10, -1, -1, 5, 9, -1, -1, -1, 3},
        /* 006 */ {1, 3, 7, 9, 0, -1, 6, -1, -1, -1, 5, -1, -1, -1, -1, 3},
        /* 007 */ {1, 3, 7, 10, 0, -1, 6, 9, -1, -1, 5, -1, -1, -1, -1, 3},
        /* 008 */ {1, 3, 7, 11, 0, -1, 6, 10, -1, -1, 5, 9, -1, -1, -1, 3},
        /* 009 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 010 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 011 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 012 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 013 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 014 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 015 */ {0, 4, 7, 9, -1, 3, 6, -1, -1, 2, -1, -1, -1, -1, -1, 3},
        /* 016 */ {0, 4, 7, 10, -1, 3, 6, 9, -1, 2, -1, -1, -1, -1, -1, 3},
        /* 017 */ {0, 4, 7, 11, -1, 3, 6, 10, -1, 2, -1, 9, -1, -1, -1, 3},
        /* 018 */ {1, 4, 7, 9, 0, 3, 6, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 019 */ {1, 4, 7, 10, 0, 3, 6, 9, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 020 */ {1, 4, 7, 11, 0, 3, 6, 10, -1, -1, -1, 9, -1, -1, -1, 3},
        /* 021 */ {2, 4, 7, 9, 1, -1, 6, -1, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 022 */ {2, 4, 7, 10, 1, -1, 6, 9, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 023 */ {2, 4, 7, 11, 1, -1, 6, 10, 0, -1, -1, 9, -1, -1, -1, 3},
        /* 024 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 025 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 026 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 027 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 028 */ {0, 4, 8, 10, -1, 3, 7, -1, -1, 2, 6, -1, -1, -1, -1, 3},
        /* 029 */ {0, 4, 8, 11, -1, 3, 7, 10, -1, 2, 6, -1, -1, -1, -1, 3},
        /* 030 */ {0, 4, 8, 12, -1, 3, 7, 11, -1, 2, 6, 10, -1, -1, -1, 3},
        /* 031 */ {1, 4, 8, 10, 0, 3, 7, -1, -1, -1, 6, -1, -1, -1, -1, 3},
        /* 032 */ {1, 4, 8, 11, 0, 3, 7, 10, -1, -1, 6, -1, -1, -1, -1, 3},
        /* 033 */ {1, 4, 8, 12, 0, 3, 7, 11, -1, -1, 6, 10, -1, -1, -1, 3},
        /* 034 */ {2, 4, 8, 10, 1, -1, 7, -1, 0, -1, 6, -1, -1, -1, -1, 3},
        /* 035 */ {2, 4, 8, 11, 1, -1, 7, 10, 0, -1, 6, -1, -1, -1, -1, 3},
        /* 036 */ {2, 4, 8, 12, 1, -1, 7, 11, 0, -1, 6, 10, -1, -1, -1, 3},
        /* 037 */ {0, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1},
        /* 038 */ {0, 2, 4, 7, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 039 */ {0, 2, 4, 8, -1, -1, -1, 7, -1, -1, -1, 6, -1, -1, -1, 3},
        /* 040 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 041 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 042 */ {1, 5, 7, 9, 0, 4, -1, -1, -1, 3, -1, -1, -1, -1, -1, 3},
        /* 043 */ {1, 5, 7, 10, 0, 4, -1, 9, -1, 3, -1, -1, -1, -1, -1, 3},
        /* 044 */ {1, 5, 7, 11, 0, 4, -1, 10, -1, 3, -1, 9, -1, -1, -1, 3},
        /* 045 */ {2, 5, 7, 9, 1, 4, -1, -1, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 046 */ {2, 5, 7, 10, 1, 4, -1, 9, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 047 */ {2, 5, 7, 11, 1, 4, -1, 10, 0, -1, -1, 9, -1, -1, -1, 3},
        /* 048 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 049 */ {1, 5, 9, 11, 0, 4, 8, -1, -1, 3, 7, -1, -1, -1, -1, 3},
        /* 050 */ {1, 5, 9, 12, 0, 4, 8, 11, -1, 3, 7, -1, -1, -1, -1, 3},
        /* 051 */ {1, 5, 9, 13, 0, 4, 8, 12, -1, 3, 7, 11, -1, -1, -1, 3},
        /* 052 */ {2, 5, 9, 11, 1, 4, 8, -1, 0, -1, 7, -1, -1, -1, -1, 3},
        /* 053 */ {2, 5, 9, 12, 1, 4, 8, 11, 0, -1, 7, -1, -1, -1, -1, 3},
        /* 054 */ {2, 5, 9, 13, 1, 4, 8, 12, 0, -1, 7, 11, -1, -1, -1, 3},
        /* 055 */ {1, 5, 8, 10, 0, 4, 7, -1, -1, 3, -1, -1, -1, -1, -1, 3},
        /* 056 */ {1, 5, 8, 11, 0, 4, 7, 10, -1, 3, -1, -1, -1, -1, -1, 3},
        /* 057 */ {1, 5, 8, 12, 0, 4, 7, 11, -1, 3, -1, 10, -1, -1, -1, 3},
        /* 058 */ {2, 5, 8, 10, 1, 4, 7, -1, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 059 */ {2, 5, 8, 11, 1, 4, 7, 10, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 060 */ {2, 5, 8, 12, 1, 4, 7, 11, 0, -1, -1, 10, -1, -1, -1, 3},
        /* 061 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 062 */ {0, 2, 5, 7, -1, -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 063 */ {0, 2, 5, 8, -1, -1, 4, 7, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 064 */ {0, 2, 5, 9, -1, -1, 4, 8, -1, -1, -1, 7, -1, -1, -1, 3},
        /* 065 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 066 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 067 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 068 */ {0, 3, 5, 7, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 069 */ {0, 3, 5, 8, -1, 2, -1, 7, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 070 */ {0, 3, 5, 9, -1, 2, -1, 8, -1, -1, -1, 7, -1, -1, -1, 3},
        /* 071 */ {1, 3, 5, 7, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 072 */ {1, 3, 5, 8, 0, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 073 */ {1, 3, 5, 9, 0, -1, -1, 8, -1, -1, -1, 7, -1, -1, -1, 3},
        /* 074 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 075 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 076 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 077 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 078 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 079 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 080 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 081 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 082 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 083 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 084 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 085 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 086 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 087 */ {2, 6, 10, 12, 1, 5, 9, -1, 0, 4, 8, -1, -1, -1, -1, 3},
        /* 088 */ {2, 6, 10, 13, 1, 5, 9, 12, 0, 4, 8, -1, -1, -1, -1, 3},
        /* 089 */ {2, 6, 10, 14, 1, 5, 9, 13, 0, 4, 8, 12, -1, -1, -1, 3},
        /* 090 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 091 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 092 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 093 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 094 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 095 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 096 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 097 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 098 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 099 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 100 */ {2, 6, 9, 11, 1, 5, 8, -1, 0, 4, -1, -1, -1, -1, -1, 3},
        /* 101 */ {2, 6, 9, 12, 1, 5, 8, 11, 0, 4, -1, -1, -1, -1, -1, 3},
        /* 102 */ {2, 6, 9, 13, 1, 5, 8, 12, 0, 4, -1, 11, -1, -1, -1, 3},
        /* 103 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 104 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 105 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 106 */ {2, 6, 8, 10, 1, 5, -1, -1, 0, 4, -1, -1, -1, -1, -1, 3},
        /* 107 */ {2, 6, 8, 11, 1, 5, -1, 10, 0, 4, -1, -1, -1, -1, -1, 3},
        /* 108 */ {2, 6, 8, 12, 1, 5, -1, 11, 0, 4, -1, 10, -1, -1, -1, 3},
        /* 109 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 110 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 111 */ {0, 2, 6, 8, -1, -1, 5, -1, -1, -1, 4, -1, -1, -1, -1, 3},
        /* 112 */ {0, 2, 6, 9, -1, -1, 5, 8, -1, -1, 4, -1, -1, -1, -1, 3},
        /* 113 */ {0, 2, 6, 10, -1, -1, 5, 9, -1, -1, 4, 8, -1, -1, -1, 3},
        /* 114 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 115 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 116 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 117 */ {0, 3, 6, 8, -1, 2, 5, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 118 */ {0, 3, 6, 9, -1, 2, 5, 8, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 119 */ {0, 3, 6, 10, -1, 2, 5, 9, -1, -1, -1, 8, -1, -1, -1, 3},
        /* 120 */ {1, 3, 6, 8, 0, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 121 */ {1, 3, 6, 9, 0, -1, 5, 8, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 122 */ {1, 3, 6, 10, 0, -1, 5, 9, -1, -1, -1, 8, -1, -1, -1, 3},
        /* 123 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 124 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 125 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 126 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 127 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 128 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* 129 */ {0, 4, 6, 8, -1, 3, -1, -1, -1, 2, -1, -1, -1, -1, -1, 3},
        /* 130 */ {0, 4, 6, 9, -1, 3, -1, 8, -1, 2, -1, -1, -1, -1, -1, 3},
        /* 131 */ {0, 4, 6, 10, -1, 3, -1, 9, -1, 2, -1, 8, -1, -1, -1, 3},
        /* 132 */ {1, 4, 6, 8, 0, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 133 */ {1, 4, 6, 9, 0, 3, -1, 8, -1, -1, -1, -1, -1, -1, -1, 2},
        /* 134 */ {1, 4, 6, 10, 0, 3, -1, 9, -1, -1, -1, 8, -1, -1, -1, 3},
        /* 135 */ {2, 4, 6, 8, 1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 136 */ {2, 4, 6, 9, 1, -1, -1, 8, 0, -1, -1, -1, -1, -1, -1, 3},
        /* 137 */ {2, 4, 6, 10, 1, -1, -1, 9, 0, -1, -1, 8, -1, -1, -1, 3},
    };
