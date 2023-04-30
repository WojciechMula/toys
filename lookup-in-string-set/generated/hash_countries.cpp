
//lookup: name=lookup_countries_hash1, dataset=countries, type=hash, hash=hash1
int lookup_countries_hash1(std::string_view s) {
    const uint64_t idx = (hash1(s) % 193) * 5;
    constexpr const std::string_view lookup[965] = {
        "",
        "",
        "",
        "",
        "",
        "FINLAND", // 966 (0x3c6)
        "SWEDEN", // 966 (0x3c6)
        "PARAGUAY", // 1352 (0x548)
        "",
        "",
        "CAMEROON", // 1160 (0x488)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PAPUA NEW GUINEA", // 2320 (0x910)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ANGOLA", // 780 (0x30c)
        "BURUNDI", // 973 (0x3cd)
        "SWAZILAND", // 1359 (0x54f)
        "JAMAICA", // 973 (0x3cd)
        "VENEZUELA", // 1359 (0x54f)
        "CAPE VERDE", // 1360 (0x550)
        "TRINIDAD AND TOBAGO", // 3097 (0xc19)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SAINT KITTS AND NEVIS", // 3486 (0xd9e)
        "AUSTRALIA", // 1170 (0x492)
        "ARGENTINA", // 1170 (0x492)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TURKMENISTAN", // 1944 (0x798)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MONTENEGRO", // 1560 (0x618)
        "",
        "",
        "",
        "",
        "SINGAPORE", // 1368 (0x558)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CANADA", // 792 (0x318)
        "",
        "",
        "",
        "",
        "MALI", // 600 (0x258)
        "",
        "",
        "",
        "",
        "LIBERIA", // 987 (0x3db)
        "ICELAND", // 987 (0x3db)
        "IRELAND", // 987 (0x3db)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IRAN", // 604 (0x25c)
        "",
        "",
        "",
        "",
        "SLOVAKIA", // 1184 (0x4a0)
        "SLOVENIA", // 1184 (0x4a0)
        "KIRIBATI", // 1184 (0x4a0)
        "",
        "",
        "KOREA, NORTH", // 1764 (0x6e4)
        "KOREA, SOUTH", // 1764 (0x6e4)
        "",
        "",
        "",
        "NIGER", // 800 (0x320)
        "",
        "",
        "",
        "",
        "AFGHANISTAN", // 1573 (0x625)
        "BANGLADESH", // 1380 (0x564)
        "MOLDOVA", // 994 (0x3e2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SUDAN", // 805 (0x325)
        "SPAIN", // 805 (0x325)
        "",
        "",
        "",
        "SOUTH SUDAN", // 1771 (0x6eb)
        "TANZANIA", // 1192 (0x4a8)
        "NETHERLANDS", // 1771 (0x6eb)
        "BARBADOS", // 1192 (0x4a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "NAMIBIA", // 1001 (0x3e9)
        "NIGERIA", // 1001 (0x3e9)
        "BELGIUM", // 1001 (0x3e9)
        "DENMARK", // 1001 (0x3e9)
        "",
        "IRAQ", // 616 (0x268)
        "NORWAY", // 1002 (0x3ea)
        "",
        "",
        "",
        "ITALY", // 810 (0x32a)
        "BELIZE", // 810 (0x32a)
        "",
        "",
        "",
        "SOUTH AFRICA", // 1776 (0x6f0)
        "SAUDI ARABIA", // 1776 (0x6f0)
        "VANUATU", // 1197 (0x4ad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BAHRAIN", // 1008 (0x3f0)
        "QATAR", // 815 (0x32f)
        "NAURU", // 815 (0x32f)
        "",
        "",
        "GAMBIA", // 816 (0x330)
        "GUINEA", // 816 (0x330)
        "GUYANA", // 816 (0x330)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MADAGASCAR", // 1590 (0x636)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OMAN", // 628 (0x274)
        "TUVALU", // 1014 (0x3f6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MARSHALL ISLANDS", // 2560 (0xa00)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PALAU", // 825 (0x339)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PHILIPPINES", // 1793 (0x701)
        "",
        "",
        "",
        "",
        "LAOS", // 636 (0x27c)
        "",
        "",
        "",
        "",
        "THAILAND", // 1216 (0x4c0)
        "SURINAME", // 1216 (0x4c0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "URUGUAY", // 1218 (0x4c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BRUNEI", // 834 (0x342)
        "FRANCE", // 834 (0x342)
        "NEW ZEALAND", // 1606 (0x646)
        "",
        "",
        "YEMEN", // 835 (0x343)
        "",
        "",
        "",
        "",
        "ROMANIA", // 1029 (0x405)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GUATEMALA", // 1224 (0x4c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GREECE", // 840 (0x348)
        "",
        "",
        "",
        "",
        "MAURITANIA", // 1420 (0x58c)
        "MICRONESIA", // 1420 (0x58c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOMALIA", // 1036 (0x40c)
        "",
        "",
        "",
        "",
        "LIECHTENSTEIN", // 2002 (0x7d2)
        "",
        "",
        "",
        "",
        "TOGO", // 652 (0x28c)
        "TURKEY", // 1038 (0x40e)
        "",
        "",
        "",
        "LATVIA", // 846 (0x34e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BURMA", // 655 (0x28f)
        "TAJIKISTAN", // 1620 (0x654)
        "SAN MARINO", // 1620 (0x654)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TUNISIA", // 1043 (0x413)
        "BELARUS", // 1043 (0x413)
        "BAHAMAS", // 1043 (0x413)
        "",
        "",
        "UNITED ARAB EMIRATES", // 3360 (0xd20)
        "AZERBAIJAN", // 1430 (0x596)
        "",
        "",
        "",
        "BRAZIL", // 852 (0x354)
        "",
        "",
        "",
        "",
        "CHINA", // 660 (0x294)
        "PERU", // 660 (0x294)
        "",
        "",
        "",
        "HONDURAS", // 1240 (0x4d8)
        "",
        "",
        "",
        "",
        "BOTSWANA", // 1048 (0x418)
        "BULGARIA", // 1048 (0x418)
        "",
        "",
        "",
        "INDONESIA", // 1242 (0x4da)
        "SAINT LUCIA", // 1628 (0x65c)
        "",
        "",
        "",
        "COMOROS", // 1050 (0x41a)
        "",
        "",
        "",
        "",
        "UZBEKISTAN", // 1630 (0x65e)
        "",
        "",
        "",
        "",
        "SIERRA LEONE", // 1824 (0x720)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MAURITIUS", // 1440 (0x5a0)
        "",
        "",
        "",
        "",
        "PORTUGAL", // 1248 (0x4e0)
        "",
        "",
        "",
        "",
        "CAMBODIA", // 1056 (0x420)
        "COLOMBIA", // 1056 (0x420)
        "",
        "",
        "",
        "BHUTAN", // 864 (0x360)
        "ECUADOR", // 1057 (0x421)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GUINEA-BISSAU", // 2028 (0x7ec)
        "PANAMA", // 870 (0x366)
        "",
        "",
        "",
        "DOMINICA", // 1064 (0x428)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GHANA", // 680 (0x2a8)
        "SAINT VINCENT AND THE GRENADINES", // 5312 (0x14c0)
        "CHILE", // 680 (0x2a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SAO TOME AND PRINCIPE", // 3192 (0xc78)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PAKISTAN", // 1264 (0x4f0)
        "",
        "",
        "",
        "",
        "ETHIOPIA", // 1072 (0x430)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOZAMBIQUE", // 1460 (0x5b4)
        "",
        "",
        "",
        "",
        "RWANDA", // 882 (0x372)
        "",
        "",
        "",
        "",
        "INDIA", // 690 (0x2b2)
        "LITHUANIA", // 1269 (0x4f5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LEBANON", // 1078 (0x436)
        "UKRAINE", // 1078 (0x436)
        "",
        "",
        "",
        "ZIMBABWE", // 1272 (0x4f8)
        "DOMINICAN REPUBLIC", // 2430 (0x97e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SEYCHELLES", // 1660 (0x67c)
        "POLAND", // 888 (0x378)
        "SERBIA", // 888 (0x378)
        "",
        "",
        "SWITZERLAND", // 1661 (0x67d)
        "EL SALVADOR", // 1661 (0x67d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LUXEMBOURG", // 1470 (0x5be)
        "",
        "",
        "",
        "",
        "LESOTHO", // 1085 (0x43d)
        "MACEDONIA", // 1278 (0x4fe)
        "",
        "",
        "",
        "KENYA", // 700 (0x2bc)
        "",
        "",
        "",
        "",
        "ISRAEL", // 894 (0x37e)
        "MALDIVES", // 1280 (0x500)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIBYA", // 705 (0x2c1)
        "",
        "",
        "",
        "",
        "MOROCCO", // 1092 (0x444)
        "",
        "",
        "",
        "",
        "CENTRAL AFRICAN REPUBLIC", // 3216 (0xc90)
        "MALAWI", // 900 (0x384)
        "UGANDA", // 900 (0x384)
        "CYPRUS", // 900 (0x384)
        "",
        "NICARAGUA", // 1287 (0x507)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MALTA", // 710 (0x2c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALGERIA", // 910 (0x38e)
        "ALBANIA", // 910 (0x38e)
        "ANDORRA", // 910 (0x38e)
        "ARMENIA", // 910 (0x38e)
        "AUSTRIA", // 910 (0x38e)
        "",
        "",
        "",
        "",
        "",
        "JORDAN", // 912 (0x390)
        "",
        "",
        "",
        "",
        "BENIN", // 720 (0x2d0)
        "",
        "",
        "",
        "",
        "CUBA", // 528 (0x210)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BURKINA", // 917 (0x395)
        "UNITED KINGDOM", // 2268 (0x8dc)
        "BOLIVIA", // 917 (0x395)
        "",
        "",
        "HAITI", // 725 (0x2d5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SENEGAL", // 1113 (0x459)
        "MYANMAR", // 1113 (0x459)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONGO", // 730 (0x2da)
        "",
        "",
        "",
        "",
        "CROATIA", // 924 (0x39c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAD", // 540 (0x21c)
        "ANTIGUA AND BARBUDA", // 2470 (0x9a6)
        "",
        "",
        "",
        "EQUATORIAL GUINEA", // 2278 (0x8e6)
        "GERMANY", // 1120 (0x460)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ZAMBIA", // 930 (0x3a2)
        "",
        "",
        "",
        "",
        "EAST TIMOR", // 1510 (0x5e6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SYRIA", // 740 (0x2e4)
        "SAMOA", // 740 (0x2e4)
        "",
        "",
        "",
        "HUNGARY", // 1127 (0x467)
        "COSTA RICA", // 1320 (0x528)
        "",
        "",
        "",
        "DJIBOUTI", // 1128 (0x468)
        "",
        "",
        "",
        "",
        "MONACO", // 936 (0x3a8)
        "MEXICO", // 936 (0x3a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ERITREA", // 938 (0x3aa)
        "GABON", // 745 (0x2e9)
        "ESTONIA", // 938 (0x3aa)
        "TONGA", // 745 (0x2e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VATICAN CITY", // 2100 (0x834)
        "",
        "",
        "",
        "",
        "MALAYSIA", // 1136 (0x470)
        "MONGOLIA", // 1136 (0x470)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SRI LANKA", // 1332 (0x534)
        "SOLOMON ISLANDS", // 2490 (0x9ba)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIETNAM", // 1141 (0x475)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RUSSIAN FEDERATION", // 2880 (0xb40)
        "",
        "",
        "",
        "",
        "KAZAKHSTAN", // 1530 (0x5fa)
        "KYRGYZSTAN", // 1530 (0x5fa)
        "",
        "",
        "",
        "BOSNIA AND HERZEGOVINA", // 2882 (0xb42)
        "GEORGIA", // 952 (0x3b8)
        "GRENADA", // 952 (0x3b8)
        "",
        "",
        "JAPAN", // 760 (0x2f8)
        "",
        "",
        "",
        "",
        "KUWAIT", // 954 (0x3ba)
        "",
        "",
        "",
        "",
        "IVORY COAST", // 1727 (0x6bf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EGYPT", // 765 (0x2fd)
        "FIJI", // 572 (0x23c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NEPAL", // 770 (0x302)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[965] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        111, // 966 (0x3c6)
        139, // 966 (0x3c6)
        187, // 1352 (0x548)
        -1,
        -1,
        6, // 1160 (0x488)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        174, // 2320 (0x910)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 780 (0x30c)
        5, // 973 (0x3cd)
        46, // 1359 (0x54f)
        158, // 973 (0x3cd)
        191, // 1359 (0x54f)
        7, // 1360 (0x550)
        165, // 3097 (0xc19)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        162, // 3486 (0xd9e)
        166, // 1170 (0x492)
        180, // 1170 (0x492)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        93, // 1944 (0x798)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        128, // 1560 (0x618)
        -1,
        -1,
        -1,
        -1,
        87, // 1368 (0x558)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        148, // 792 (0x318)
        -1,
        -1,
        -1,
        -1,
        29, // 600 (0x258)
        -1,
        -1,
        -1,
        -1,
        25, // 987 (0x3db)
        117, // 987 (0x3db)
        118, // 987 (0x3db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 604 (0x25c)
        -1,
        -1,
        -1,
        -1,
        136, // 1184 (0x4a0)
        137, // 1184 (0x4a0)
        168, // 1184 (0x4a0)
        -1,
        -1,
        71, // 1764 (0x6e4)
        72, // 1764 (0x6e4)
        -1,
        -1,
        -1,
        35, // 800 (0x320)
        -1,
        -1,
        -1,
        -1,
        53, // 1573 (0x625)
        55, // 1380 (0x564)
        126, // 994 (0x3e2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 805 (0x325)
        138, // 805 (0x325)
        -1,
        -1,
        -1,
        44, // 1771 (0x6eb)
        47, // 1192 (0x4a8)
        129, // 1771 (0x6eb)
        146, // 1192 (0x4a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 1001 (0x3e9)
        36, // 1001 (0x3e9)
        104, // 1001 (0x3e9)
        109, // 1001 (0x3e9)
        -1,
        66, // 616 (0x268)
        130, // 1002 (0x3ea)
        -1,
        -1,
        -1,
        119, // 810 (0x32a)
        147, // 810 (0x32a)
        -1,
        -1,
        -1,
        43, // 1776 (0x6f0)
        86, // 1776 (0x6f0)
        179, // 1197 (0x4ad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 1008 (0x3f0)
        84, // 815 (0x32f)
        171, // 815 (0x32f)
        -1,
        -1,
        18, // 816 (0x330)
        20, // 816 (0x330)
        186, // 816 (0x330)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        27, // 1590 (0x636)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        81, // 628 (0x274)
        178, // 1014 (0x3f6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        169, // 2560 (0xa00)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        173, // 825 (0x339)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        83, // 1793 (0x701)
        -1,
        -1,
        -1,
        -1,
        75, // 636 (0x27c)
        -1,
        -1,
        -1,
        -1,
        91, // 1216 (0x4c0)
        189, // 1216 (0x4c0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        190, // 1218 (0x4c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        57, // 834 (0x342)
        112, // 834 (0x342)
        172, // 1606 (0x646)
        -1,
        -1,
        97, // 835 (0x343)
        -1,
        -1,
        -1,
        -1,
        133, // 1029 (0x405)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        155, // 1224 (0x4c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 840 (0x348)
        -1,
        -1,
        -1,
        -1,
        30, // 1420 (0x58c)
        170, // 1420 (0x58c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 1036 (0x40c)
        -1,
        -1,
        -1,
        -1,
        121, // 2002 (0x7d2)
        -1,
        -1,
        -1,
        -1,
        48, // 652 (0x28c)
        92, // 1038 (0x40e)
        -1,
        -1,
        -1,
        120, // 846 (0x34e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        58, // 655 (0x28f)
        90, // 1620 (0x654)
        134, // 1620 (0x654)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 1043 (0x413)
        103, // 1043 (0x413)
        145, // 1043 (0x413)
        -1,
        -1,
        94, // 3360 (0xd20)
        102, // 1430 (0x596)
        -1,
        -1,
        -1,
        182, // 852 (0x354)
        -1,
        -1,
        -1,
        -1,
        61, // 660 (0x294)
        188, // 660 (0x294)
        -1,
        -1,
        -1,
        157, // 1240 (0x4d8)
        -1,
        -1,
        -1,
        -1,
        3, // 1048 (0x418)
        106, // 1048 (0x418)
        -1,
        -1,
        -1,
        64, // 1242 (0x4da)
        163, // 1628 (0x65c)
        -1,
        -1,
        -1,
        10, // 1050 (0x41a)
        -1,
        -1,
        -1,
        -1,
        95, // 1630 (0x65e)
        -1,
        -1,
        -1,
        -1,
        41, // 1824 (0x720)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 1440 (0x5a0)
        -1,
        -1,
        -1,
        -1,
        132, // 1248 (0x4e0)
        -1,
        -1,
        -1,
        -1,
        60, // 1056 (0x420)
        184, // 1056 (0x420)
        -1,
        -1,
        -1,
        56, // 864 (0x360)
        185, // 1057 (0x421)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 2028 (0x7ec)
        161, // 870 (0x366)
        -1,
        -1,
        -1,
        151, // 1064 (0x428)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 680 (0x2a8)
        164, // 5312 (0x14c0)
        183, // 680 (0x2a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 3192 (0xc78)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        82, // 1264 (0x4f0)
        -1,
        -1,
        -1,
        -1,
        16, // 1072 (0x430)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        33, // 1460 (0x5b4)
        -1,
        -1,
        -1,
        -1,
        37, // 882 (0x372)
        -1,
        -1,
        -1,
        -1,
        63, // 690 (0x2b2)
        122, // 1269 (0x4f5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        76, // 1078 (0x436)
        141, // 1078 (0x436)
        -1,
        -1,
        -1,
        52, // 1272 (0x4f8)
        152, // 2430 (0x97e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 1660 (0x67c)
        131, // 888 (0x378)
        135, // 888 (0x378)
        -1,
        -1,
        140, // 1661 (0x67d)
        153, // 1661 (0x67d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        123, // 1470 (0x5be)
        -1,
        -1,
        -1,
        -1,
        24, // 1085 (0x43d)
        124, // 1278 (0x4fe)
        -1,
        -1,
        -1,
        23, // 700 (0x2bc)
        -1,
        -1,
        -1,
        -1,
        67, // 894 (0x37e)
        78, // 1280 (0x500)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 705 (0x2c1)
        -1,
        -1,
        -1,
        -1,
        32, // 1092 (0x444)
        -1,
        -1,
        -1,
        -1,
        8, // 3216 (0xc90)
        28, // 900 (0x384)
        50, // 900 (0x384)
        108, // 900 (0x384)
        -1,
        160, // 1287 (0x507)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        125, // 710 (0x2c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 910 (0x38e)
        98, // 910 (0x38e)
        99, // 910 (0x38e)
        100, // 910 (0x38e)
        101, // 910 (0x38e)
        -1,
        -1,
        -1,
        -1,
        -1,
        69, // 912 (0x390)
        -1,
        -1,
        -1,
        -1,
        2, // 720 (0x2d0)
        -1,
        -1,
        -1,
        -1,
        150, // 528 (0x210)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 917 (0x395)
        142, // 2268 (0x8dc)
        181, // 917 (0x395)
        -1,
        -1,
        156, // 725 (0x2d5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 1113 (0x459)
        59, // 1113 (0x459)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 730 (0x2da)
        -1,
        -1,
        -1,
        -1,
        107, // 924 (0x39c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 540 (0x21c)
        144, // 2470 (0x9a6)
        -1,
        -1,
        -1,
        14, // 2278 (0x8e6)
        114, // 1120 (0x460)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 930 (0x3a2)
        -1,
        -1,
        -1,
        -1,
        62, // 1510 (0x5e6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 740 (0x2e4)
        175, // 740 (0x2e4)
        -1,
        -1,
        -1,
        116, // 1127 (0x467)
        149, // 1320 (0x528)
        -1,
        -1,
        -1,
        12, // 1128 (0x468)
        -1,
        -1,
        -1,
        -1,
        127, // 936 (0x3a8)
        159, // 936 (0x3a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 938 (0x3aa)
        17, // 745 (0x2e9)
        110, // 938 (0x3aa)
        177, // 745 (0x2e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        143, // 2100 (0x834)
        -1,
        -1,
        -1,
        -1,
        77, // 1136 (0x470)
        79, // 1136 (0x470)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        88, // 1332 (0x534)
        176, // 2490 (0x9ba)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        96, // 1141 (0x475)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        85, // 2880 (0xb40)
        -1,
        -1,
        -1,
        -1,
        70, // 1530 (0x5fa)
        74, // 1530 (0x5fa)
        -1,
        -1,
        -1,
        105, // 2882 (0xb42)
        113, // 952 (0x3b8)
        154, // 952 (0x3b8)
        -1,
        -1,
        68, // 760 (0x2f8)
        -1,
        -1,
        -1,
        -1,
        73, // 954 (0x3ba)
        -1,
        -1,
        -1,
        -1,
        22, // 1727 (0x6bf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 765 (0x2fd)
        167, // 572 (0x23c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        80, // 770 (0x302)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 5; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash1, dataset=countries, type=hash, hash=hash1
void check_countries_hash1() {
    assert(lookup_countries_hash1("FINLAND") == 111);
    assert(lookup_countries_hash1("SWEDEN") == 139);
    assert(lookup_countries_hash1("PARAGUAY") == 187);
    assert(lookup_countries_hash1("CAMEROON") == 6);
    assert(lookup_countries_hash1("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash1("ANGOLA") == 1);
    assert(lookup_countries_hash1("BURUNDI") == 5);
    assert(lookup_countries_hash1("SWAZILAND") == 46);
    assert(lookup_countries_hash1("JAMAICA") == 158);
    assert(lookup_countries_hash1("VENEZUELA") == 191);
    assert(lookup_countries_hash1("CAPE VERDE") == 7);
    assert(lookup_countries_hash1("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash1("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash1("AUSTRALIA") == 166);
    assert(lookup_countries_hash1("ARGENTINA") == 180);
    assert(lookup_countries_hash1("TURKMENISTAN") == 93);
    assert(lookup_countries_hash1("MONTENEGRO") == 128);
    assert(lookup_countries_hash1("SINGAPORE") == 87);
    assert(lookup_countries_hash1("CANADA") == 148);
    assert(lookup_countries_hash1("MALI") == 29);
    assert(lookup_countries_hash1("LIBERIA") == 25);
    assert(lookup_countries_hash1("ICELAND") == 117);
    assert(lookup_countries_hash1("IRELAND") == 118);
    assert(lookup_countries_hash1("IRAN") == 65);
    assert(lookup_countries_hash1("SLOVAKIA") == 136);
    assert(lookup_countries_hash1("SLOVENIA") == 137);
    assert(lookup_countries_hash1("KIRIBATI") == 168);
    assert(lookup_countries_hash1("KOREA, NORTH") == 71);
    assert(lookup_countries_hash1("KOREA, SOUTH") == 72);
    assert(lookup_countries_hash1("NIGER") == 35);
    assert(lookup_countries_hash1("AFGHANISTAN") == 53);
    assert(lookup_countries_hash1("BANGLADESH") == 55);
    assert(lookup_countries_hash1("MOLDOVA") == 126);
    assert(lookup_countries_hash1("SUDAN") == 45);
    assert(lookup_countries_hash1("SPAIN") == 138);
    assert(lookup_countries_hash1("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash1("TANZANIA") == 47);
    assert(lookup_countries_hash1("NETHERLANDS") == 129);
    assert(lookup_countries_hash1("BARBADOS") == 146);
    assert(lookup_countries_hash1("NAMIBIA") == 34);
    assert(lookup_countries_hash1("NIGERIA") == 36);
    assert(lookup_countries_hash1("BELGIUM") == 104);
    assert(lookup_countries_hash1("DENMARK") == 109);
    assert(lookup_countries_hash1("IRAQ") == 66);
    assert(lookup_countries_hash1("NORWAY") == 130);
    assert(lookup_countries_hash1("ITALY") == 119);
    assert(lookup_countries_hash1("BELIZE") == 147);
    assert(lookup_countries_hash1("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash1("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash1("VANUATU") == 179);
    assert(lookup_countries_hash1("BAHRAIN") == 54);
    assert(lookup_countries_hash1("QATAR") == 84);
    assert(lookup_countries_hash1("NAURU") == 171);
    assert(lookup_countries_hash1("GAMBIA") == 18);
    assert(lookup_countries_hash1("GUINEA") == 20);
    assert(lookup_countries_hash1("GUYANA") == 186);
    assert(lookup_countries_hash1("MADAGASCAR") == 27);
    assert(lookup_countries_hash1("OMAN") == 81);
    assert(lookup_countries_hash1("TUVALU") == 178);
    assert(lookup_countries_hash1("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash1("PALAU") == 173);
    assert(lookup_countries_hash1("PHILIPPINES") == 83);
    assert(lookup_countries_hash1("LAOS") == 75);
    assert(lookup_countries_hash1("THAILAND") == 91);
    assert(lookup_countries_hash1("SURINAME") == 189);
    assert(lookup_countries_hash1("URUGUAY") == 190);
    assert(lookup_countries_hash1("BRUNEI") == 57);
    assert(lookup_countries_hash1("FRANCE") == 112);
    assert(lookup_countries_hash1("NEW ZEALAND") == 172);
    assert(lookup_countries_hash1("YEMEN") == 97);
    assert(lookup_countries_hash1("ROMANIA") == 133);
    assert(lookup_countries_hash1("GUATEMALA") == 155);
    assert(lookup_countries_hash1("GREECE") == 115);
    assert(lookup_countries_hash1("MAURITANIA") == 30);
    assert(lookup_countries_hash1("MICRONESIA") == 170);
    assert(lookup_countries_hash1("SOMALIA") == 42);
    assert(lookup_countries_hash1("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash1("TOGO") == 48);
    assert(lookup_countries_hash1("TURKEY") == 92);
    assert(lookup_countries_hash1("LATVIA") == 120);
    assert(lookup_countries_hash1("BURMA") == 58);
    assert(lookup_countries_hash1("TAJIKISTAN") == 90);
    assert(lookup_countries_hash1("SAN MARINO") == 134);
    assert(lookup_countries_hash1("TUNISIA") == 49);
    assert(lookup_countries_hash1("BELARUS") == 103);
    assert(lookup_countries_hash1("BAHAMAS") == 145);
    assert(lookup_countries_hash1("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash1("AZERBAIJAN") == 102);
    assert(lookup_countries_hash1("BRAZIL") == 182);
    assert(lookup_countries_hash1("CHINA") == 61);
    assert(lookup_countries_hash1("PERU") == 188);
    assert(lookup_countries_hash1("HONDURAS") == 157);
    assert(lookup_countries_hash1("BOTSWANA") == 3);
    assert(lookup_countries_hash1("BULGARIA") == 106);
    assert(lookup_countries_hash1("INDONESIA") == 64);
    assert(lookup_countries_hash1("SAINT LUCIA") == 163);
    assert(lookup_countries_hash1("COMOROS") == 10);
    assert(lookup_countries_hash1("UZBEKISTAN") == 95);
    assert(lookup_countries_hash1("SIERRA LEONE") == 41);
    assert(lookup_countries_hash1("MAURITIUS") == 31);
    assert(lookup_countries_hash1("PORTUGAL") == 132);
    assert(lookup_countries_hash1("CAMBODIA") == 60);
    assert(lookup_countries_hash1("COLOMBIA") == 184);
    assert(lookup_countries_hash1("BHUTAN") == 56);
    assert(lookup_countries_hash1("ECUADOR") == 185);
    assert(lookup_countries_hash1("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash1("PANAMA") == 161);
    assert(lookup_countries_hash1("DOMINICA") == 151);
    assert(lookup_countries_hash1("GHANA") == 19);
    assert(lookup_countries_hash1("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash1("CHILE") == 183);
    assert(lookup_countries_hash1("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash1("PAKISTAN") == 82);
    assert(lookup_countries_hash1("ETHIOPIA") == 16);
    assert(lookup_countries_hash1("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash1("RWANDA") == 37);
    assert(lookup_countries_hash1("INDIA") == 63);
    assert(lookup_countries_hash1("LITHUANIA") == 122);
    assert(lookup_countries_hash1("LEBANON") == 76);
    assert(lookup_countries_hash1("UKRAINE") == 141);
    assert(lookup_countries_hash1("ZIMBABWE") == 52);
    assert(lookup_countries_hash1("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash1("SEYCHELLES") == 40);
    assert(lookup_countries_hash1("POLAND") == 131);
    assert(lookup_countries_hash1("SERBIA") == 135);
    assert(lookup_countries_hash1("SWITZERLAND") == 140);
    assert(lookup_countries_hash1("EL SALVADOR") == 153);
    assert(lookup_countries_hash1("LUXEMBOURG") == 123);
    assert(lookup_countries_hash1("LESOTHO") == 24);
    assert(lookup_countries_hash1("MACEDONIA") == 124);
    assert(lookup_countries_hash1("KENYA") == 23);
    assert(lookup_countries_hash1("ISRAEL") == 67);
    assert(lookup_countries_hash1("MALDIVES") == 78);
    assert(lookup_countries_hash1("LIBYA") == 26);
    assert(lookup_countries_hash1("MOROCCO") == 32);
    assert(lookup_countries_hash1("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash1("MALAWI") == 28);
    assert(lookup_countries_hash1("UGANDA") == 50);
    assert(lookup_countries_hash1("CYPRUS") == 108);
    assert(lookup_countries_hash1("NICARAGUA") == 160);
    assert(lookup_countries_hash1("MALTA") == 125);
    assert(lookup_countries_hash1("ALGERIA") == 0);
    assert(lookup_countries_hash1("ALBANIA") == 98);
    assert(lookup_countries_hash1("ANDORRA") == 99);
    assert(lookup_countries_hash1("ARMENIA") == 100);
    assert(lookup_countries_hash1("AUSTRIA") == 101);
    assert(lookup_countries_hash1("JORDAN") == 69);
    assert(lookup_countries_hash1("BENIN") == 2);
    assert(lookup_countries_hash1("CUBA") == 150);
    assert(lookup_countries_hash1("BURKINA") == 4);
    assert(lookup_countries_hash1("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash1("BOLIVIA") == 181);
    assert(lookup_countries_hash1("HAITI") == 156);
    assert(lookup_countries_hash1("SENEGAL") == 39);
    assert(lookup_countries_hash1("MYANMAR") == 59);
    assert(lookup_countries_hash1("CONGO") == 11);
    assert(lookup_countries_hash1("CROATIA") == 107);
    assert(lookup_countries_hash1("CHAD") == 9);
    assert(lookup_countries_hash1("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash1("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash1("GERMANY") == 114);
    assert(lookup_countries_hash1("ZAMBIA") == 51);
    assert(lookup_countries_hash1("EAST TIMOR") == 62);
    assert(lookup_countries_hash1("SYRIA") == 89);
    assert(lookup_countries_hash1("SAMOA") == 175);
    assert(lookup_countries_hash1("HUNGARY") == 116);
    assert(lookup_countries_hash1("COSTA RICA") == 149);
    assert(lookup_countries_hash1("DJIBOUTI") == 12);
    assert(lookup_countries_hash1("MONACO") == 127);
    assert(lookup_countries_hash1("MEXICO") == 159);
    assert(lookup_countries_hash1("ERITREA") == 15);
    assert(lookup_countries_hash1("GABON") == 17);
    assert(lookup_countries_hash1("ESTONIA") == 110);
    assert(lookup_countries_hash1("TONGA") == 177);
    assert(lookup_countries_hash1("VATICAN CITY") == 143);
    assert(lookup_countries_hash1("MALAYSIA") == 77);
    assert(lookup_countries_hash1("MONGOLIA") == 79);
    assert(lookup_countries_hash1("SRI LANKA") == 88);
    assert(lookup_countries_hash1("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash1("VIETNAM") == 96);
    assert(lookup_countries_hash1("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash1("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash1("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash1("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash1("GEORGIA") == 113);
    assert(lookup_countries_hash1("GRENADA") == 154);
    assert(lookup_countries_hash1("JAPAN") == 68);
    assert(lookup_countries_hash1("KUWAIT") == 73);
    assert(lookup_countries_hash1("IVORY COAST") == 22);
    assert(lookup_countries_hash1("EGYPT") == 13);
    assert(lookup_countries_hash1("FIJI") == 167);
    assert(lookup_countries_hash1("NEPAL") == 80);
}

//lookup: name=lookup_countries_hash2, dataset=countries, type=hash, hash=hash2
int lookup_countries_hash2(std::string_view s) {
    const uint64_t idx = (hash2(s) % 192) * 5;
    constexpr const std::string_view lookup[960] = {
        "GEORGIA", // 4608 (0x1200)
        "GRENADA", // 4608 (0x1200)
        "PAPUA NEW GUINEA", // 5184 (0x1440)
        "",
        "",
        "GAMBIA", // 4609 (0x1201)
        "GUINEA", // 4609 (0x1201)
        "GUYANA", // 4609 (0x1201)
        "",
        "",
        "GHANA", // 4610 (0x1202)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MACEDONIA", // 4996 (0x1384)
        "",
        "",
        "",
        "",
        "CAPE VERDE", // 4613 (0x1205)
        "MALAYSIA", // 4997 (0x1385)
        "MONGOLIA", // 4997 (0x1385)
        "",
        "",
        "ALGERIA", // 4230 (0x1086)
        "ALBANIA", // 4230 (0x1086)
        "ANDORRA", // 4230 (0x1086)
        "ARMENIA", // 4230 (0x1086)
        "AUSTRIA", // 4230 (0x1086)
        "ANGOLA", // 4231 (0x1087)
        "MAURITANIA", // 4999 (0x1387)
        "MICRONESIA", // 4999 (0x1387)
        "",
        "",
        "MALTA", // 5000 (0x1388)
        "AUSTRALIA", // 4232 (0x1088)
        "ARGENTINA", // 4232 (0x1088)
        "",
        "",
        "JAPAN", // 5769 (0x1689)
        "VANUATU", // 7305 (0x1c89)
        "",
        "",
        "",
        "JORDAN", // 5770 (0x168a)
        "MOLDOVA", // 5002 (0x138a)
        "CHILE", // 4618 (0x120a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DOMINICA", // 4428 (0x114c)
        "",
        "",
        "",
        "",
        "JAMAICA", // 4813 (0x12cd)
        "",
        "",
        "",
        "",
        "GUATEMALA", // 4622 (0x120e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HONDURAS", // 5968 (0x1750)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TAJIKISTAN", // 6546 (0x1992)
        "ANTIGUA AND BARBUDA", // 4242 (0x1092)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOMALIA", // 5396 (0x1514)
        "BRUNEI", // 4820 (0x12d4)
        "KOREA, NORTH", // 5396 (0x1514)
        "KOREA, SOUTH", // 5396 (0x1514)
        "TURKMENISTAN", // 6548 (0x1994)
        "BURUNDI", // 4821 (0x12d5)
        "SERBIA", // 5397 (0x1515)
        "",
        "",
        "",
        "OMAN", // 6166 (0x1816)
        "SYRIA", // 5398 (0x1516)
        "PANAMA", // 5206 (0x1456)
        "SAMOA", // 5398 (0x1516)
        "",
        "SAN MARINO", // 6551 (0x1997)
        "",
        "",
        "",
        "",
        "FRANCE", // 4824 (0x12d8)
        "NORWAY", // 6936 (0x1b18)
        "SAINT LUCIA", // 5400 (0x1518)
        "PARAGUAY", // 7128 (0x1bd8)
        "",
        "",
        "",
        "",
        "",
        "",
        "SRI LANKA", // 5402 (0x151a)
        "",
        "",
        "",
        "",
        "YEMEN", // 6939 (0x1b1b)
        "SLOVAKIA", // 5403 (0x151b)
        "SLOVENIA", // 5403 (0x151b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LUXEMBOURG", // 5406 (0x151e)
        "BRAZIL", // 5022 (0x139e)
        "",
        "",
        "",
        "SOUTH AFRICA", // 5407 (0x151f)
        "SAUDI ARABIA", // 5407 (0x151f)
        "UNITED KINGDOM", // 6559 (0x199f)
        "VENEZUELA", // 5599 (0x15df)
        "",
        "",
        "",
        "",
        "",
        "",
        "EGYPT", // 5793 (0x16a1)
        "",
        "",
        "",
        "",
        "CAMEROON", // 5218 (0x1462)
        "TUVALU", // 7138 (0x1be2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MARSHALL ISLANDS", // 6375 (0x18e7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RUSSIAN FEDERATION", // 6382 (0x18ee)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MALI", // 5617 (0x15f1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LESOTHO", // 6003 (0x1773)
        "MALAWI", // 5619 (0x15f3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NIGER", // 6393 (0x18f9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MAURITIUS", // 6398 (0x18fe)
        "",
        "",
        "",
        "",
        "MALDIVES", // 6399 (0x18ff)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ERITREA", // 4482 (0x1182)
        "ESTONIA", // 4482 (0x1182)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AZERBAIJAN", // 5060 (0x13c4)
        "",
        "",
        "",
        "",
        "BURKINA", // 4293 (0x10c5)
        "SWAZILAND", // 5637 (0x1605)
        "AFGHANISTAN", // 5061 (0x13c5)
        "BOLIVIA", // 4293 (0x10c5)
        "",
        "POLAND", // 5446 (0x1546)
        "",
        "",
        "",
        "",
        "BURMA", // 4295 (0x10c7)
        "SWITZERLAND", // 5639 (0x1607)
        "NICARAGUA", // 5063 (0x13c7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NAMIBIA", // 5065 (0x13c9)
        "NIGERIA", // 5065 (0x13c9)
        "",
        "",
        "",
        "BOTSWANA", // 4298 (0x10ca)
        "ZIMBABWE", // 6218 (0x184a)
        "BULGARIA", // 4298 (0x10ca)
        "URUGUAY", // 7562 (0x1d8a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ETHIOPIA", // 4493 (0x118d)
        "HAITI", // 5261 (0x148d)
        "",
        "",
        "",
        "KENYA", // 4878 (0x130e)
        "",
        "",
        "",
        "",
        "HUNGARY", // 6415 (0x190f)
        "",
        "",
        "",
        "",
        "EAST TIMOR", // 5648 (0x1610)
        "KAZAKHSTAN", // 5840 (0x16d0)
        "KYRGYZSTAN", // 5840 (0x16d0)
        "",
        "",
        "CENTRAL AFRICAN REPUBLIC", // 4497 (0x1191)
        "EL SALVADOR", // 5649 (0x1611)
        "TONGA", // 5457 (0x1551)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TUNISIA", // 5459 (0x1553)
        "",
        "",
        "",
        "",
        "EQUATORIAL GUINEA", // 4500 (0x1194)
        "BOSNIA AND HERZEGOVINA", // 4308 (0x10d4)
        "PERU", // 6804 (0x1a94)
        "",
        "",
        "PALAU", // 6805 (0x1a95)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VIETNAM", // 6617 (0x19d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TANZANIA", // 5468 (0x155c)
        "ZAMBIA", // 5852 (0x16dc)
        "",
        "",
        "",
        "BELGIUM", // 5085 (0x13dd)
        "ECUADOR", // 5661 (0x161d)
        "",
        "",
        "",
        "GUINEA-BISSAU", // 6046 (0x179e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BELARUS", // 5473 (0x1561)
        "BAHAMAS", // 5473 (0x1561)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NAURU", // 6627 (0x19e3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GREECE", // 4901 (0x1325)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONGO", // 5288 (0x14a8)
        "TOGO", // 6632 (0x19e8)
        "PAKISTAN", // 6248 (0x1868)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DENMARK", // 5099 (0x13eb)
        "KIRIBATI", // 5483 (0x156b)
        "",
        "",
        "",
        "UZBEKISTAN", // 6636 (0x19ec)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UKRAINE", // 5870 (0x16ee)
        "BARBADOS", // 5486 (0x156e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FIJI", // 5106 (0x13f2)
        "",
        "",
        "",
        "",
        "NEW ZEALAND", // 5299 (0x14b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "QATAR", // 6647 (0x19f7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IRAN", // 5690 (0x163a)
        "",
        "",
        "",
        "",
        "PHILIPPINES", // 6651 (0x19fb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TRINIDAD AND TOBAGO", // 6655 (0x19ff)
        "",
        "",
        "",
        "",
        "INDONESIA", // 4736 (0x1280)
        "",
        "",
        "",
        "",
        "SOUTH SUDAN", // 6465 (0x1941)
        "NETHERLANDS", // 6465 (0x1941)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOROCCO", // 6084 (0x17c4)
        "CROATIA", // 4356 (0x1104)
        "",
        "",
        "",
        "LITHUANIA", // 4933 (0x1345)
        "MONACO", // 6085 (0x17c5)
        "CANADA", // 4357 (0x1105)
        "MEXICO", // 6085 (0x17c5)
        "",
        "CHINA", // 4358 (0x1106)
        "",
        "",
        "",
        "",
        "CUBA", // 4359 (0x1107)
        "",
        "",
        "",
        "",
        "CHAD", // 4552 (0x11c8)
        "PORTUGAL", // 6088 (0x17c8)
        "",
        "",
        "",
        "LIBYA", // 4937 (0x1349)
        "MONTENEGRO", // 6089 (0x17c9)
        "COSTA RICA", // 4361 (0x1109)
        "SAINT VINCENT AND THE GRENADINES", // 6857 (0x1ac9)
        "",
        "SAO TOME AND PRINCIPE", // 5706 (0x164a)
        "LATVIA", // 4938 (0x134a)
        "",
        "",
        "",
        "LIBERIA", // 4939 (0x134b)
        "MOZAMBIQUE", // 5323 (0x14cb)
        "CAMBODIA", // 4363 (0x110b)
        "COLOMBIA", // 4363 (0x110b)
        "",
        "INDIA", // 4748 (0x128c)
        "SWEDEN", // 6476 (0x194c)
        "BELIZE", // 4556 (0x11cc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SUDAN", // 6479 (0x194f)
        "SPAIN", // 6479 (0x194f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIERRA LEONE", // 5715 (0x1653)
        "UGANDA", // 5523 (0x1593)
        "",
        "",
        "",
        "RWANDA", // 5332 (0x14d4)
        "",
        "",
        "",
        "",
        "ROMANIA", // 5333 (0x14d5)
        "",
        "",
        "",
        "",
        "SINGAPORE", // 5718 (0x1656)
        "",
        "",
        "",
        "",
        "SURINAME", // 5719 (0x1657)
        "",
        "",
        "",
        "",
        "THAILAND", // 5720 (0x1658)
        "",
        "",
        "",
        "",
        "BENIN", // 5145 (0x1419)
        "",
        "",
        "",
        "",
        "BANGLADESH", // 4762 (0x129a)
        "BHUTAN", // 5146 (0x141a)
        "KUWAIT", // 6298 (0x189a)
        "",
        "",
        "BAHRAIN", // 5147 (0x141b)
        "UNITED ARAB EMIRATES", // 7067 (0x1b9b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IRAQ", // 5917 (0x171d)
        "",
        "",
        "",
        "",
        "DOMINICAN REPUBLIC", // 4574 (0x11de)
        "",
        "",
        "",
        "",
        "FINLAND", // 4767 (0x129f)
        "",
        "",
        "",
        "",
        "MADAGASCAR", // 6304 (0x18a0)
        "LAOS", // 6304 (0x18a0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SENEGAL", // 6307 (0x18a3)
        "SEYCHELLES", // 6883 (0x1ae3)
        "ICELAND", // 4963 (0x1363)
        "IRELAND", // 4963 (0x1363)
        "",
        "ITALY", // 6500 (0x1964)
        "",
        "",
        "",
        "",
        "LIECHTENSTEIN", // 5925 (0x1725)
        "",
        "",
        "",
        "",
        "SOLOMON ISLANDS", // 6886 (0x1ae6)
        "",
        "",
        "",
        "",
        "GABON", // 5543 (0x15a7)
        "",
        "",
        "",
        "",
        "GERMANY", // 6312 (0x18a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ISRAEL", // 5546 (0x15aa)
        "VATICAN CITY", // 7658 (0x1dea)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DJIBOUTI", // 4972 (0x136c)
        "",
        "",
        "",
        "",
        "MYANMAR", // 6317 (0x18ad)
        "NEPAL", // 5933 (0x172d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LEBANON", // 5935 (0x172f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TURKEY", // 7474 (0x1d32)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SAINT KITTS AND NEVIS", // 6908 (0x1afc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "COMOROS", // 5566 (0x15be)
        "",
        "",
        "",
        "",
        "IVORY COAST", // 6143 (0x17ff)
        "CYPRUS", // 5567 (0x15bf)
        "",
        "",
        "",
    };
    constexpr const int values[960] = {
        113, // 4608 (0x1200)
        154, // 4608 (0x1200)
        174, // 5184 (0x1440)
        -1,
        -1,
        18, // 4609 (0x1201)
        20, // 4609 (0x1201)
        186, // 4609 (0x1201)
        -1,
        -1,
        19, // 4610 (0x1202)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        124, // 4996 (0x1384)
        -1,
        -1,
        -1,
        -1,
        7, // 4613 (0x1205)
        77, // 4997 (0x1385)
        79, // 4997 (0x1385)
        -1,
        -1,
        0, // 4230 (0x1086)
        98, // 4230 (0x1086)
        99, // 4230 (0x1086)
        100, // 4230 (0x1086)
        101, // 4230 (0x1086)
        1, // 4231 (0x1087)
        30, // 4999 (0x1387)
        170, // 4999 (0x1387)
        -1,
        -1,
        125, // 5000 (0x1388)
        166, // 4232 (0x1088)
        180, // 4232 (0x1088)
        -1,
        -1,
        68, // 5769 (0x1689)
        179, // 7305 (0x1c89)
        -1,
        -1,
        -1,
        69, // 5770 (0x168a)
        126, // 5002 (0x138a)
        183, // 4618 (0x120a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        151, // 4428 (0x114c)
        -1,
        -1,
        -1,
        -1,
        158, // 4813 (0x12cd)
        -1,
        -1,
        -1,
        -1,
        155, // 4622 (0x120e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        157, // 5968 (0x1750)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        90, // 6546 (0x1992)
        144, // 4242 (0x1092)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 5396 (0x1514)
        57, // 4820 (0x12d4)
        71, // 5396 (0x1514)
        72, // 5396 (0x1514)
        93, // 6548 (0x1994)
        5, // 4821 (0x12d5)
        135, // 5397 (0x1515)
        -1,
        -1,
        -1,
        81, // 6166 (0x1816)
        89, // 5398 (0x1516)
        161, // 5206 (0x1456)
        175, // 5398 (0x1516)
        -1,
        134, // 6551 (0x1997)
        -1,
        -1,
        -1,
        -1,
        112, // 4824 (0x12d8)
        130, // 6936 (0x1b18)
        163, // 5400 (0x1518)
        187, // 7128 (0x1bd8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        88, // 5402 (0x151a)
        -1,
        -1,
        -1,
        -1,
        97, // 6939 (0x1b1b)
        136, // 5403 (0x151b)
        137, // 5403 (0x151b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        123, // 5406 (0x151e)
        182, // 5022 (0x139e)
        -1,
        -1,
        -1,
        43, // 5407 (0x151f)
        86, // 5407 (0x151f)
        142, // 6559 (0x199f)
        191, // 5599 (0x15df)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 5793 (0x16a1)
        -1,
        -1,
        -1,
        -1,
        6, // 5218 (0x1462)
        178, // 7138 (0x1be2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        169, // 6375 (0x18e7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        85, // 6382 (0x18ee)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 5617 (0x15f1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        24, // 6003 (0x1773)
        28, // 5619 (0x15f3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 6393 (0x18f9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 6398 (0x18fe)
        -1,
        -1,
        -1,
        -1,
        78, // 6399 (0x18ff)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 4482 (0x1182)
        110, // 4482 (0x1182)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        102, // 5060 (0x13c4)
        -1,
        -1,
        -1,
        -1,
        4, // 4293 (0x10c5)
        46, // 5637 (0x1605)
        53, // 5061 (0x13c5)
        181, // 4293 (0x10c5)
        -1,
        131, // 5446 (0x1546)
        -1,
        -1,
        -1,
        -1,
        58, // 4295 (0x10c7)
        140, // 5639 (0x1607)
        160, // 5063 (0x13c7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        34, // 5065 (0x13c9)
        36, // 5065 (0x13c9)
        -1,
        -1,
        -1,
        3, // 4298 (0x10ca)
        52, // 6218 (0x184a)
        106, // 4298 (0x10ca)
        190, // 7562 (0x1d8a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 4493 (0x118d)
        156, // 5261 (0x148d)
        -1,
        -1,
        -1,
        23, // 4878 (0x130e)
        -1,
        -1,
        -1,
        -1,
        116, // 6415 (0x190f)
        -1,
        -1,
        -1,
        -1,
        62, // 5648 (0x1610)
        70, // 5840 (0x16d0)
        74, // 5840 (0x16d0)
        -1,
        -1,
        8, // 4497 (0x1191)
        153, // 5649 (0x1611)
        177, // 5457 (0x1551)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 5459 (0x1553)
        -1,
        -1,
        -1,
        -1,
        14, // 4500 (0x1194)
        105, // 4308 (0x10d4)
        188, // 6804 (0x1a94)
        -1,
        -1,
        173, // 6805 (0x1a95)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        96, // 6617 (0x19d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 5468 (0x155c)
        51, // 5852 (0x16dc)
        -1,
        -1,
        -1,
        104, // 5085 (0x13dd)
        185, // 5661 (0x161d)
        -1,
        -1,
        -1,
        21, // 6046 (0x179e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        103, // 5473 (0x1561)
        145, // 5473 (0x1561)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        171, // 6627 (0x19e3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 4901 (0x1325)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 5288 (0x14a8)
        48, // 6632 (0x19e8)
        82, // 6248 (0x1868)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 5099 (0x13eb)
        168, // 5483 (0x156b)
        -1,
        -1,
        -1,
        95, // 6636 (0x19ec)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        141, // 5870 (0x16ee)
        146, // 5486 (0x156e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        167, // 5106 (0x13f2)
        -1,
        -1,
        -1,
        -1,
        172, // 5299 (0x14b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        84, // 6647 (0x19f7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 5690 (0x163a)
        -1,
        -1,
        -1,
        -1,
        83, // 6651 (0x19fb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        165, // 6655 (0x19ff)
        -1,
        -1,
        -1,
        -1,
        64, // 4736 (0x1280)
        -1,
        -1,
        -1,
        -1,
        44, // 6465 (0x1941)
        129, // 6465 (0x1941)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 6084 (0x17c4)
        107, // 4356 (0x1104)
        -1,
        -1,
        -1,
        122, // 4933 (0x1345)
        127, // 6085 (0x17c5)
        148, // 4357 (0x1105)
        159, // 6085 (0x17c5)
        -1,
        61, // 4358 (0x1106)
        -1,
        -1,
        -1,
        -1,
        150, // 4359 (0x1107)
        -1,
        -1,
        -1,
        -1,
        9, // 4552 (0x11c8)
        132, // 6088 (0x17c8)
        -1,
        -1,
        -1,
        26, // 4937 (0x1349)
        128, // 6089 (0x17c9)
        149, // 4361 (0x1109)
        164, // 6857 (0x1ac9)
        -1,
        38, // 5706 (0x164a)
        120, // 4938 (0x134a)
        -1,
        -1,
        -1,
        25, // 4939 (0x134b)
        33, // 5323 (0x14cb)
        60, // 4363 (0x110b)
        184, // 4363 (0x110b)
        -1,
        63, // 4748 (0x128c)
        139, // 6476 (0x194c)
        147, // 4556 (0x11cc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        45, // 6479 (0x194f)
        138, // 6479 (0x194f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 5715 (0x1653)
        50, // 5523 (0x1593)
        -1,
        -1,
        -1,
        37, // 5332 (0x14d4)
        -1,
        -1,
        -1,
        -1,
        133, // 5333 (0x14d5)
        -1,
        -1,
        -1,
        -1,
        87, // 5718 (0x1656)
        -1,
        -1,
        -1,
        -1,
        189, // 5719 (0x1657)
        -1,
        -1,
        -1,
        -1,
        91, // 5720 (0x1658)
        -1,
        -1,
        -1,
        -1,
        2, // 5145 (0x1419)
        -1,
        -1,
        -1,
        -1,
        55, // 4762 (0x129a)
        56, // 5146 (0x141a)
        73, // 6298 (0x189a)
        -1,
        -1,
        54, // 5147 (0x141b)
        94, // 7067 (0x1b9b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        66, // 5917 (0x171d)
        -1,
        -1,
        -1,
        -1,
        152, // 4574 (0x11de)
        -1,
        -1,
        -1,
        -1,
        111, // 4767 (0x129f)
        -1,
        -1,
        -1,
        -1,
        27, // 6304 (0x18a0)
        75, // 6304 (0x18a0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        39, // 6307 (0x18a3)
        40, // 6883 (0x1ae3)
        117, // 4963 (0x1363)
        118, // 4963 (0x1363)
        -1,
        119, // 6500 (0x1964)
        -1,
        -1,
        -1,
        -1,
        121, // 5925 (0x1725)
        -1,
        -1,
        -1,
        -1,
        176, // 6886 (0x1ae6)
        -1,
        -1,
        -1,
        -1,
        17, // 5543 (0x15a7)
        -1,
        -1,
        -1,
        -1,
        114, // 6312 (0x18a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        67, // 5546 (0x15aa)
        143, // 7658 (0x1dea)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 4972 (0x136c)
        -1,
        -1,
        -1,
        -1,
        59, // 6317 (0x18ad)
        80, // 5933 (0x172d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        76, // 5935 (0x172f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 7474 (0x1d32)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        162, // 6908 (0x1afc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 5566 (0x15be)
        -1,
        -1,
        -1,
        -1,
        22, // 6143 (0x17ff)
        108, // 5567 (0x15bf)
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 5; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash2, dataset=countries, type=hash, hash=hash2
void check_countries_hash2() {
    assert(lookup_countries_hash2("GEORGIA") == 113);
    assert(lookup_countries_hash2("GRENADA") == 154);
    assert(lookup_countries_hash2("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash2("GAMBIA") == 18);
    assert(lookup_countries_hash2("GUINEA") == 20);
    assert(lookup_countries_hash2("GUYANA") == 186);
    assert(lookup_countries_hash2("GHANA") == 19);
    assert(lookup_countries_hash2("MACEDONIA") == 124);
    assert(lookup_countries_hash2("CAPE VERDE") == 7);
    assert(lookup_countries_hash2("MALAYSIA") == 77);
    assert(lookup_countries_hash2("MONGOLIA") == 79);
    assert(lookup_countries_hash2("ALGERIA") == 0);
    assert(lookup_countries_hash2("ALBANIA") == 98);
    assert(lookup_countries_hash2("ANDORRA") == 99);
    assert(lookup_countries_hash2("ARMENIA") == 100);
    assert(lookup_countries_hash2("AUSTRIA") == 101);
    assert(lookup_countries_hash2("ANGOLA") == 1);
    assert(lookup_countries_hash2("MAURITANIA") == 30);
    assert(lookup_countries_hash2("MICRONESIA") == 170);
    assert(lookup_countries_hash2("MALTA") == 125);
    assert(lookup_countries_hash2("AUSTRALIA") == 166);
    assert(lookup_countries_hash2("ARGENTINA") == 180);
    assert(lookup_countries_hash2("JAPAN") == 68);
    assert(lookup_countries_hash2("VANUATU") == 179);
    assert(lookup_countries_hash2("JORDAN") == 69);
    assert(lookup_countries_hash2("MOLDOVA") == 126);
    assert(lookup_countries_hash2("CHILE") == 183);
    assert(lookup_countries_hash2("DOMINICA") == 151);
    assert(lookup_countries_hash2("JAMAICA") == 158);
    assert(lookup_countries_hash2("GUATEMALA") == 155);
    assert(lookup_countries_hash2("HONDURAS") == 157);
    assert(lookup_countries_hash2("TAJIKISTAN") == 90);
    assert(lookup_countries_hash2("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash2("SOMALIA") == 42);
    assert(lookup_countries_hash2("BRUNEI") == 57);
    assert(lookup_countries_hash2("KOREA, NORTH") == 71);
    assert(lookup_countries_hash2("KOREA, SOUTH") == 72);
    assert(lookup_countries_hash2("TURKMENISTAN") == 93);
    assert(lookup_countries_hash2("BURUNDI") == 5);
    assert(lookup_countries_hash2("SERBIA") == 135);
    assert(lookup_countries_hash2("OMAN") == 81);
    assert(lookup_countries_hash2("SYRIA") == 89);
    assert(lookup_countries_hash2("PANAMA") == 161);
    assert(lookup_countries_hash2("SAMOA") == 175);
    assert(lookup_countries_hash2("SAN MARINO") == 134);
    assert(lookup_countries_hash2("FRANCE") == 112);
    assert(lookup_countries_hash2("NORWAY") == 130);
    assert(lookup_countries_hash2("SAINT LUCIA") == 163);
    assert(lookup_countries_hash2("PARAGUAY") == 187);
    assert(lookup_countries_hash2("SRI LANKA") == 88);
    assert(lookup_countries_hash2("YEMEN") == 97);
    assert(lookup_countries_hash2("SLOVAKIA") == 136);
    assert(lookup_countries_hash2("SLOVENIA") == 137);
    assert(lookup_countries_hash2("LUXEMBOURG") == 123);
    assert(lookup_countries_hash2("BRAZIL") == 182);
    assert(lookup_countries_hash2("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash2("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash2("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash2("VENEZUELA") == 191);
    assert(lookup_countries_hash2("EGYPT") == 13);
    assert(lookup_countries_hash2("CAMEROON") == 6);
    assert(lookup_countries_hash2("TUVALU") == 178);
    assert(lookup_countries_hash2("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash2("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash2("MALI") == 29);
    assert(lookup_countries_hash2("LESOTHO") == 24);
    assert(lookup_countries_hash2("MALAWI") == 28);
    assert(lookup_countries_hash2("NIGER") == 35);
    assert(lookup_countries_hash2("MAURITIUS") == 31);
    assert(lookup_countries_hash2("MALDIVES") == 78);
    assert(lookup_countries_hash2("ERITREA") == 15);
    assert(lookup_countries_hash2("ESTONIA") == 110);
    assert(lookup_countries_hash2("AZERBAIJAN") == 102);
    assert(lookup_countries_hash2("BURKINA") == 4);
    assert(lookup_countries_hash2("SWAZILAND") == 46);
    assert(lookup_countries_hash2("AFGHANISTAN") == 53);
    assert(lookup_countries_hash2("BOLIVIA") == 181);
    assert(lookup_countries_hash2("POLAND") == 131);
    assert(lookup_countries_hash2("BURMA") == 58);
    assert(lookup_countries_hash2("SWITZERLAND") == 140);
    assert(lookup_countries_hash2("NICARAGUA") == 160);
    assert(lookup_countries_hash2("NAMIBIA") == 34);
    assert(lookup_countries_hash2("NIGERIA") == 36);
    assert(lookup_countries_hash2("BOTSWANA") == 3);
    assert(lookup_countries_hash2("ZIMBABWE") == 52);
    assert(lookup_countries_hash2("BULGARIA") == 106);
    assert(lookup_countries_hash2("URUGUAY") == 190);
    assert(lookup_countries_hash2("ETHIOPIA") == 16);
    assert(lookup_countries_hash2("HAITI") == 156);
    assert(lookup_countries_hash2("KENYA") == 23);
    assert(lookup_countries_hash2("HUNGARY") == 116);
    assert(lookup_countries_hash2("EAST TIMOR") == 62);
    assert(lookup_countries_hash2("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash2("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash2("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash2("EL SALVADOR") == 153);
    assert(lookup_countries_hash2("TONGA") == 177);
    assert(lookup_countries_hash2("TUNISIA") == 49);
    assert(lookup_countries_hash2("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash2("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash2("PERU") == 188);
    assert(lookup_countries_hash2("PALAU") == 173);
    assert(lookup_countries_hash2("VIETNAM") == 96);
    assert(lookup_countries_hash2("TANZANIA") == 47);
    assert(lookup_countries_hash2("ZAMBIA") == 51);
    assert(lookup_countries_hash2("BELGIUM") == 104);
    assert(lookup_countries_hash2("ECUADOR") == 185);
    assert(lookup_countries_hash2("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash2("BELARUS") == 103);
    assert(lookup_countries_hash2("BAHAMAS") == 145);
    assert(lookup_countries_hash2("NAURU") == 171);
    assert(lookup_countries_hash2("GREECE") == 115);
    assert(lookup_countries_hash2("CONGO") == 11);
    assert(lookup_countries_hash2("TOGO") == 48);
    assert(lookup_countries_hash2("PAKISTAN") == 82);
    assert(lookup_countries_hash2("DENMARK") == 109);
    assert(lookup_countries_hash2("KIRIBATI") == 168);
    assert(lookup_countries_hash2("UZBEKISTAN") == 95);
    assert(lookup_countries_hash2("UKRAINE") == 141);
    assert(lookup_countries_hash2("BARBADOS") == 146);
    assert(lookup_countries_hash2("FIJI") == 167);
    assert(lookup_countries_hash2("NEW ZEALAND") == 172);
    assert(lookup_countries_hash2("QATAR") == 84);
    assert(lookup_countries_hash2("IRAN") == 65);
    assert(lookup_countries_hash2("PHILIPPINES") == 83);
    assert(lookup_countries_hash2("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash2("INDONESIA") == 64);
    assert(lookup_countries_hash2("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash2("NETHERLANDS") == 129);
    assert(lookup_countries_hash2("MOROCCO") == 32);
    assert(lookup_countries_hash2("CROATIA") == 107);
    assert(lookup_countries_hash2("LITHUANIA") == 122);
    assert(lookup_countries_hash2("MONACO") == 127);
    assert(lookup_countries_hash2("CANADA") == 148);
    assert(lookup_countries_hash2("MEXICO") == 159);
    assert(lookup_countries_hash2("CHINA") == 61);
    assert(lookup_countries_hash2("CUBA") == 150);
    assert(lookup_countries_hash2("CHAD") == 9);
    assert(lookup_countries_hash2("PORTUGAL") == 132);
    assert(lookup_countries_hash2("LIBYA") == 26);
    assert(lookup_countries_hash2("MONTENEGRO") == 128);
    assert(lookup_countries_hash2("COSTA RICA") == 149);
    assert(lookup_countries_hash2("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash2("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash2("LATVIA") == 120);
    assert(lookup_countries_hash2("LIBERIA") == 25);
    assert(lookup_countries_hash2("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash2("CAMBODIA") == 60);
    assert(lookup_countries_hash2("COLOMBIA") == 184);
    assert(lookup_countries_hash2("INDIA") == 63);
    assert(lookup_countries_hash2("SWEDEN") == 139);
    assert(lookup_countries_hash2("BELIZE") == 147);
    assert(lookup_countries_hash2("SUDAN") == 45);
    assert(lookup_countries_hash2("SPAIN") == 138);
    assert(lookup_countries_hash2("SIERRA LEONE") == 41);
    assert(lookup_countries_hash2("UGANDA") == 50);
    assert(lookup_countries_hash2("RWANDA") == 37);
    assert(lookup_countries_hash2("ROMANIA") == 133);
    assert(lookup_countries_hash2("SINGAPORE") == 87);
    assert(lookup_countries_hash2("SURINAME") == 189);
    assert(lookup_countries_hash2("THAILAND") == 91);
    assert(lookup_countries_hash2("BENIN") == 2);
    assert(lookup_countries_hash2("BANGLADESH") == 55);
    assert(lookup_countries_hash2("BHUTAN") == 56);
    assert(lookup_countries_hash2("KUWAIT") == 73);
    assert(lookup_countries_hash2("BAHRAIN") == 54);
    assert(lookup_countries_hash2("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash2("IRAQ") == 66);
    assert(lookup_countries_hash2("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash2("FINLAND") == 111);
    assert(lookup_countries_hash2("MADAGASCAR") == 27);
    assert(lookup_countries_hash2("LAOS") == 75);
    assert(lookup_countries_hash2("SENEGAL") == 39);
    assert(lookup_countries_hash2("SEYCHELLES") == 40);
    assert(lookup_countries_hash2("ICELAND") == 117);
    assert(lookup_countries_hash2("IRELAND") == 118);
    assert(lookup_countries_hash2("ITALY") == 119);
    assert(lookup_countries_hash2("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash2("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash2("GABON") == 17);
    assert(lookup_countries_hash2("GERMANY") == 114);
    assert(lookup_countries_hash2("ISRAEL") == 67);
    assert(lookup_countries_hash2("VATICAN CITY") == 143);
    assert(lookup_countries_hash2("DJIBOUTI") == 12);
    assert(lookup_countries_hash2("MYANMAR") == 59);
    assert(lookup_countries_hash2("NEPAL") == 80);
    assert(lookup_countries_hash2("LEBANON") == 76);
    assert(lookup_countries_hash2("TURKEY") == 92);
    assert(lookup_countries_hash2("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash2("COMOROS") == 10);
    assert(lookup_countries_hash2("IVORY COAST") == 22);
    assert(lookup_countries_hash2("CYPRUS") == 108);
}

//lookup: name=lookup_countries_hash3, dataset=countries, type=hash, hash=hash3
int lookup_countries_hash3(std::string_view s) {
    const uint64_t idx = (hash3(s) % 207) * 3;
    constexpr const std::string_view lookup[621] = {
        "NICARAGUA", // 22563 (0x5823)
        "",
        "",
        "SPAIN", // 22771 (0x58f3)
        "",
        "",
        "KIRIBATI", // 21530 (0x541a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DENMARK", // 19463 (0x4c07)
        "",
        "",
        "SUDAN", // 22776 (0x58f8)
        "",
        "",
        "",
        "",
        "",
        "CAMBODIA", // 19466 (0x4c0a)
        "",
        "",
        "MAURITANIA", // 22572 (0x582c)
        "MARSHALL ISLANDS", // 24228 (0x5ea4)
        "",
        "UKRAINE", // 23815 (0x5d07)
        "",
        "",
        "",
        "",
        "",
        "RWANDA", // 22782 (0x58fe)
        "SAINT KITTS AND NEVIS", // 27129 (0x69f9)
        "",
        "GHANA", // 19678 (0x4cde)
        "TANZANIA", // 23818 (0x5d0a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MICRONESIA", // 22580 (0x5834)
        "",
        "",
        "",
        "",
        "",
        "GABON", // 19684 (0x4ce4)
        "",
        "",
        "",
        "",
        "",
        "CAMEROON", // 19479 (0x4c17)
        "SAUDI ARABIA", // 24654 (0x604e)
        "",
        "COLOMBIA", // 19480 (0x4c18)
        "",
        "",
        "THAILAND", // 23828 (0x5d14)
        "",
        "",
        "CHINA", // 18654 (0x48de)
        "HUNGARY", // 20517 (0x5025)
        "",
        "UZBEKISTAN", // 24658 (0x6052)
        "",
        "",
        "MADAGASCAR", // 22589 (0x583d)
        "",
        "",
        "MOZAMBIQUE", // 22590 (0x583e)
        "",
        "",
        "ANTIGUA AND BARBUDA", // 21970 (0x55d2)
        "CHILE", // 18658 (0x48e2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOLDOVA", // 21767 (0x5507)
        "",
        "",
        "SIERRA LEONE", // 24666 (0x605a)
        "",
        "",
        "ICELAND", // 20734 (0x50fe)
        "",
        "",
        "CENTRAL AFRICAN REPUBLIC", // 23840 (0x5d20)
        "MALI", // 20942 (0x51ce)
        "SOUTH AFRICA", // 24668 (0x605c)
        "TONGA", // 23013 (0x59e5)
        "",
        "",
        "PAKISTAN", // 22807 (0x5917)
        "MONTENEGRO", // 22600 (0x5848)
        "URUGUAY", // 23842 (0x5d22)
        "",
        "",
        "",
        "JORDAN", // 20739 (0x5103)
        "NORWAY", // 21774 (0x550e)
        "",
        "PHILIPPINES", // 23638 (0x5c56)
        "",
        "",
        "",
        "",
        "",
        "SINGAPORE", // 23847 (0x5d27)
        "BELIZE", // 18672 (0x48f0)
        "",
        "SERBIA", // 23020 (0x59ec)
        "",
        "",
        "FRANCE", // 19709 (0x4cfd)
        "SOLOMON ISLANDS", // 25505 (0x63a1)
        "",
        "CONGO", // 18675 (0x48f3)
        "",
        "",
        "MOROCCO", // 21781 (0x5515)
        "",
        "",
        "SRI LANKA", // 23852 (0x5d2c)
        "",
        "",
        "EAST TIMOR", // 20541 (0x503d)
        "PARAGUAY", // 22818 (0x5922)
        "",
        "IRELAND", // 20749 (0x510d)
        "PORTUGAL", // 22819 (0x5923)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIBYA", // 20959 (0x51df)
        "",
        "",
        "PALAU", // 21995 (0x55eb)
        "",
        "",
        "BHUTAN", // 18684 (0x48fc)
        "",
        "",
        "SWAZILAND", // 23860 (0x5d34)
        "",
        "",
        "",
        "",
        "",
        "ERITREA", // 19722 (0x4d0a)
        "UNITED ARAB EMIRATES", // 27381 (0x6af5)
        "",
        "ESTONIA", // 19723 (0x4d0b)
        "",
        "",
        "BRUNEI", // 18689 (0x4901)
        "MYANMAR", // 21794 (0x5522)
        "ECUADOR", // 19724 (0x4d0c)
        "",
        "",
        "",
        "",
        "",
        "",
        "ALGERIA", // 18692 (0x4904)
        "ALBANIA", // 18692 (0x4904)
        "BRAZIL", // 18692 (0x4904)
        "HAITI", // 19935 (0x4ddf)
        "",
        "",
        "KOREA, NORTH", // 22627 (0x5863)
        "KOREA, SOUTH", // 22627 (0x5863)
        "ANDORRA", // 18694 (0x4906)
        "VIETNAM", // 24077 (0x5e0d)
        "VANUATU", // 24077 (0x5e0d)
        "",
        "",
        "",
        "",
        "NAMIBIA", // 22009 (0x55f9)
        "",
        "",
        "IRAN", // 19940 (0x4de4)
        "ARMENIA", // 18698 (0x490a)
        "",
        "BOSNIA AND HERZEGOVINA", // 23046 (0x5a06)
        "UNITED KINGDOM", // 25737 (0x6489)
        "",
        "ROMANIA", // 23047 (0x5a07)
        "",
        "",
        "IRAQ", // 19943 (0x4de7)
        "AUSTRIA", // 18701 (0x490d)
        "DOMINICA", // 19736 (0x4d18)
        "GAMBIA", // 19944 (0x4de8)
        "",
        "",
        "",
        "",
        "",
        "DJIBOUTI", // 19739 (0x4d1b)
        "SWEDEN", // 23051 (0x5a0b)
        "",
        "NIGERIA", // 22017 (0x5601)
        "",
        "",
        "",
        "",
        "",
        "YEMEN", // 24296 (0x5ee8)
        "",
        "",
        "HONDURAS", // 20778 (0x512a)
        "JAMAICA", // 20985 (0x51f9)
        "",
        "",
        "",
        "",
        "AZERBAIJAN", // 19538 (0x4c52)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CANADA", // 18920 (0x49e8)
        "GUATEMALA", // 20783 (0x512f)
        "",
        "MALAYSIA", // 22026 (0x560a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GUINEA", // 19964 (0x4dfc)
        "GUYANA", // 19964 (0x4dfc)
        "",
        "GREECE", // 19965 (0x4dfd)
        "MALTA", // 21207 (0x52d7)
        "",
        "",
        "",
        "",
        "EQUATORIAL GUINEA", // 22451 (0x57b3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BANGLADESH", // 19763 (0x4d33)
        "MONGOLIA", // 22040 (0x5618)
        "",
        "QATAR", // 22248 (0x56e8)
        "PANAMA", // 22248 (0x56e8)
        "",
        "KUWAIT", // 21007 (0x520f)
        "FINLAND", // 19972 (0x4e04)
        "",
        "",
        "",
        "",
        "MALDIVES", // 22044 (0x561c)
        "",
        "",
        "TURKMENISTAN", // 24943 (0x616f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LITHUANIA", // 22051 (0x5623)
        "",
        "",
        "LATVIA", // 21224 (0x52e8)
        "SAN MARINO", // 24122 (0x5e3a)
        "",
        "",
        "",
        "",
        "ZIMBABWE", // 25366 (0x6316)
        "DOMINICAN REPUBLIC", // 22468 (0x57c4)
        "",
        "BAHRAIN", // 18950 (0x4a06)
        "",
        "",
        "FIJI", // 19158 (0x4ad6)
        "BOLIVIA", // 18951 (0x4a07)
        "",
        "",
        "",
        "",
        "BELGIUM", // 18953 (0x4a09)
        "POLAND", // 22265 (0x56f9)
        "",
        "INDIA", // 20196 (0x4ee4)
        "SAINT VINCENT AND THE GRENADINES", // 30132 (0x75b4)
        "",
        "SEYCHELLES", // 24130 (0x5e42)
        "BAHAMAS", // 18955 (0x4a0b)
        "",
        "SOMALIA", // 23303 (0x5b07)
        "",
        "",
        "BURKINA", // 18957 (0x4a0d)
        "SENEGAL", // 23304 (0x5b08)
        "",
        "",
        "",
        "",
        "BELARUS", // 18959 (0x4a0f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ETHIOPIA", // 19997 (0x4e1d)
        "CYPRUS", // 18962 (0x4a12)
        "EL SALVADOR", // 20825 (0x5159)
        "IVORY COAST", // 21861 (0x5565)
        "AFGHANISTAN", // 19791 (0x4d4f)
        "",
        "",
        "",
        "",
        "BURUNDI", // 18965 (0x4a15)
        "TUVALU", // 23312 (0x5b10)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KAZAKHSTAN", // 22073 (0x5639)
        "NEW ZEALAND", // 23108 (0x5a44)
        "",
        "TURKEY", // 23316 (0x5b14)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PAPUA NEW GUINEA", // 24978 (0x6192)
        "",
        "",
        "",
        "",
        "",
        "EGYPT", // 19184 (0x4af0)
        "",
        "",
        "",
        "",
        "",
        "GEORGIA", // 20221 (0x4efd)
        "",
        "",
        "UGANDA", // 23534 (0x5bee)
        "",
        "",
        "CAPE VERDE", // 20016 (0x4e30)
        "",
        "",
        "",
        "",
        "",
        "NETHERLANDS", // 23123 (0x5a53)
        "",
        "",
        "ITALY", // 20226 (0x4f02)
        "",
        "",
        "",
        "",
        "",
        "TRINIDAD AND TOBAGO", // 26852 (0x68e4)
        "",
        "",
        "OMAN", // 21471 (0x53df)
        "MACEDONIA", // 22299 (0x571b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "COSTA RICA", // 20026 (0x4e3a)
        "",
        "",
        "KYRGYZSTAN", // 22097 (0x5651)
        "GRENADA", // 20234 (0x4f0a)
        "",
        "",
        "",
        "",
        "NEPAL", // 21478 (0x53e6)
        "",
        "",
        "TAJIKISTAN", // 24377 (0x5f39)
        "",
        "",
        "",
        "",
        "",
        "GUINEA-BISSAU", // 21895 (0x5587)
        "",
        "",
        "",
        "",
        "",
        "SAINT LUCIA", // 24381 (0x5f3d)
        "NAURU", // 21483 (0x53eb)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "JAPAN", // 20452 (0x4fe4)
        "CROATIA", // 19210 (0x4b0a)
        "GERMANY", // 20245 (0x4f15)
        "MALAWI", // 21488 (0x53f0)
        "NIGER", // 21488 (0x53f0)
        "",
        "CHAD", // 18384 (0x47d0)
        "MAURITIUS", // 22317 (0x572d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TUNISIA", // 23565 (0x5c0d)
        "INDONESIA", // 21288 (0x5328)
        "",
        "ZAMBIA", // 24808 (0x60e8)
        "",
        "",
        "",
        "",
        "",
        "MEXICO", // 21498 (0x53fa)
        "",
        "",
        "CUBA", // 18394 (0x47da)
        "",
        "",
        "LIECHTENSTEIN", // 23156 (0x5a74)
        "",
        "",
        "BOTSWANA", // 19224 (0x4b18)
        "SAMOA", // 22743 (0x58d7)
        "",
        "COMOROS", // 19225 (0x4b19)
        "VENEZUELA", // 24607 (0x601f)
        "",
        "SLOVAKIA", // 23573 (0x5c15)
        "SLOVENIA", // 23573 (0x5c15)
        "",
        "",
        "",
        "",
        "LIBERIA", // 21505 (0x5401)
        "BARBADOS", // 19228 (0x4b1c)
        "",
        "",
        "",
        "",
        "BULGARIA", // 19230 (0x4b1e)
        "",
        "",
        "MONACO", // 21508 (0x5404)
        "SWITZERLAND", // 24406 (0x5f56)
        "",
        "",
        "",
        "",
        "SOUTH SUDAN", // 24408 (0x5f58)
        "",
        "",
        "",
        "",
        "",
        "TOGO", // 22754 (0x58e2)
        "",
        "",
        "BENIN", // 18408 (0x47e8)
        "VATICAN CITY", // 25446 (0x6366)
        "",
        "LEBANON", // 21514 (0x540a)
        "LUXEMBOURG", // 22342 (0x5746)
        "",
        "LESOTHO", // 21515 (0x540b)
        "RUSSIAN FEDERATION", // 26069 (0x65d5)
        "",
        "BURMA", // 18411 (0x47eb)
        "SURINAME", // 23586 (0x5c22)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PERU", // 21726 (0x54de)
        "",
        "",
        "ISRAEL", // 20485 (0x5005)
        "",
        "",
        "ARGENTINA", // 19244 (0x4b2c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LAOS", // 20696 (0x50d8)
        "AUSTRALIA", // 19247 (0x4b2f)
        "",
        "SYRIA", // 22767 (0x58ef)
        "",
        "",
        "ANGOLA", // 18421 (0x47f5)
        "SAO TOME AND PRINCIPE", // 27115 (0x69eb)
        "",
        "KENYA", // 20699 (0x50db)
        "",
        "",
    };
    constexpr const int values[621] = {
        160, // 22563 (0x5823)
        -1,
        -1,
        138, // 22771 (0x58f3)
        -1,
        -1,
        168, // 21530 (0x541a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 19463 (0x4c07)
        -1,
        -1,
        45, // 22776 (0x58f8)
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 19466 (0x4c0a)
        -1,
        -1,
        30, // 22572 (0x582c)
        169, // 24228 (0x5ea4)
        -1,
        141, // 23815 (0x5d07)
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 22782 (0x58fe)
        162, // 27129 (0x69f9)
        -1,
        19, // 19678 (0x4cde)
        47, // 23818 (0x5d0a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        170, // 22580 (0x5834)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 19684 (0x4ce4)
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 19479 (0x4c17)
        86, // 24654 (0x604e)
        -1,
        184, // 19480 (0x4c18)
        -1,
        -1,
        91, // 23828 (0x5d14)
        -1,
        -1,
        61, // 18654 (0x48de)
        116, // 20517 (0x5025)
        -1,
        95, // 24658 (0x6052)
        -1,
        -1,
        27, // 22589 (0x583d)
        -1,
        -1,
        33, // 22590 (0x583e)
        -1,
        -1,
        144, // 21970 (0x55d2)
        183, // 18658 (0x48e2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        126, // 21767 (0x5507)
        -1,
        -1,
        41, // 24666 (0x605a)
        -1,
        -1,
        117, // 20734 (0x50fe)
        -1,
        -1,
        8, // 23840 (0x5d20)
        29, // 20942 (0x51ce)
        43, // 24668 (0x605c)
        177, // 23013 (0x59e5)
        -1,
        -1,
        82, // 22807 (0x5917)
        128, // 22600 (0x5848)
        190, // 23842 (0x5d22)
        -1,
        -1,
        -1,
        69, // 20739 (0x5103)
        130, // 21774 (0x550e)
        -1,
        83, // 23638 (0x5c56)
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 23847 (0x5d27)
        147, // 18672 (0x48f0)
        -1,
        135, // 23020 (0x59ec)
        -1,
        -1,
        112, // 19709 (0x4cfd)
        176, // 25505 (0x63a1)
        -1,
        11, // 18675 (0x48f3)
        -1,
        -1,
        32, // 21781 (0x5515)
        -1,
        -1,
        88, // 23852 (0x5d2c)
        -1,
        -1,
        62, // 20541 (0x503d)
        187, // 22818 (0x5922)
        -1,
        118, // 20749 (0x510d)
        132, // 22819 (0x5923)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 20959 (0x51df)
        -1,
        -1,
        173, // 21995 (0x55eb)
        -1,
        -1,
        56, // 18684 (0x48fc)
        -1,
        -1,
        46, // 23860 (0x5d34)
        -1,
        -1,
        -1,
        -1,
        -1,
        15, // 19722 (0x4d0a)
        94, // 27381 (0x6af5)
        -1,
        110, // 19723 (0x4d0b)
        -1,
        -1,
        57, // 18689 (0x4901)
        59, // 21794 (0x5522)
        185, // 19724 (0x4d0c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 18692 (0x4904)
        98, // 18692 (0x4904)
        182, // 18692 (0x4904)
        156, // 19935 (0x4ddf)
        -1,
        -1,
        71, // 22627 (0x5863)
        72, // 22627 (0x5863)
        99, // 18694 (0x4906)
        96, // 24077 (0x5e0d)
        179, // 24077 (0x5e0d)
        -1,
        -1,
        -1,
        -1,
        34, // 22009 (0x55f9)
        -1,
        -1,
        65, // 19940 (0x4de4)
        100, // 18698 (0x490a)
        -1,
        105, // 23046 (0x5a06)
        142, // 25737 (0x6489)
        -1,
        133, // 23047 (0x5a07)
        -1,
        -1,
        66, // 19943 (0x4de7)
        101, // 18701 (0x490d)
        151, // 19736 (0x4d18)
        18, // 19944 (0x4de8)
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 19739 (0x4d1b)
        139, // 23051 (0x5a0b)
        -1,
        36, // 22017 (0x5601)
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 24296 (0x5ee8)
        -1,
        -1,
        157, // 20778 (0x512a)
        158, // 20985 (0x51f9)
        -1,
        -1,
        -1,
        -1,
        102, // 19538 (0x4c52)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        148, // 18920 (0x49e8)
        155, // 20783 (0x512f)
        -1,
        77, // 22026 (0x560a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 19964 (0x4dfc)
        186, // 19964 (0x4dfc)
        -1,
        115, // 19965 (0x4dfd)
        125, // 21207 (0x52d7)
        -1,
        -1,
        -1,
        -1,
        14, // 22451 (0x57b3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        55, // 19763 (0x4d33)
        79, // 22040 (0x5618)
        -1,
        84, // 22248 (0x56e8)
        161, // 22248 (0x56e8)
        -1,
        73, // 21007 (0x520f)
        111, // 19972 (0x4e04)
        -1,
        -1,
        -1,
        -1,
        78, // 22044 (0x561c)
        -1,
        -1,
        93, // 24943 (0x616f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        122, // 22051 (0x5623)
        -1,
        -1,
        120, // 21224 (0x52e8)
        134, // 24122 (0x5e3a)
        -1,
        -1,
        -1,
        -1,
        52, // 25366 (0x6316)
        152, // 22468 (0x57c4)
        -1,
        54, // 18950 (0x4a06)
        -1,
        -1,
        167, // 19158 (0x4ad6)
        181, // 18951 (0x4a07)
        -1,
        -1,
        -1,
        -1,
        104, // 18953 (0x4a09)
        131, // 22265 (0x56f9)
        -1,
        63, // 20196 (0x4ee4)
        164, // 30132 (0x75b4)
        -1,
        40, // 24130 (0x5e42)
        145, // 18955 (0x4a0b)
        -1,
        42, // 23303 (0x5b07)
        -1,
        -1,
        4, // 18957 (0x4a0d)
        39, // 23304 (0x5b08)
        -1,
        -1,
        -1,
        -1,
        103, // 18959 (0x4a0f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 19997 (0x4e1d)
        108, // 18962 (0x4a12)
        153, // 20825 (0x5159)
        22, // 21861 (0x5565)
        53, // 19791 (0x4d4f)
        -1,
        -1,
        -1,
        -1,
        5, // 18965 (0x4a15)
        178, // 23312 (0x5b10)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 22073 (0x5639)
        172, // 23108 (0x5a44)
        -1,
        92, // 23316 (0x5b14)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        174, // 24978 (0x6192)
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 19184 (0x4af0)
        -1,
        -1,
        -1,
        -1,
        -1,
        113, // 20221 (0x4efd)
        -1,
        -1,
        50, // 23534 (0x5bee)
        -1,
        -1,
        7, // 20016 (0x4e30)
        -1,
        -1,
        -1,
        -1,
        -1,
        129, // 23123 (0x5a53)
        -1,
        -1,
        119, // 20226 (0x4f02)
        -1,
        -1,
        -1,
        -1,
        -1,
        165, // 26852 (0x68e4)
        -1,
        -1,
        81, // 21471 (0x53df)
        124, // 22299 (0x571b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        149, // 20026 (0x4e3a)
        -1,
        -1,
        74, // 22097 (0x5651)
        154, // 20234 (0x4f0a)
        -1,
        -1,
        -1,
        -1,
        80, // 21478 (0x53e6)
        -1,
        -1,
        90, // 24377 (0x5f39)
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 21895 (0x5587)
        -1,
        -1,
        -1,
        -1,
        -1,
        163, // 24381 (0x5f3d)
        171, // 21483 (0x53eb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 20452 (0x4fe4)
        107, // 19210 (0x4b0a)
        114, // 20245 (0x4f15)
        28, // 21488 (0x53f0)
        35, // 21488 (0x53f0)
        -1,
        9, // 18384 (0x47d0)
        31, // 22317 (0x572d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 23565 (0x5c0d)
        64, // 21288 (0x5328)
        -1,
        51, // 24808 (0x60e8)
        -1,
        -1,
        -1,
        -1,
        -1,
        159, // 21498 (0x53fa)
        -1,
        -1,
        150, // 18394 (0x47da)
        -1,
        -1,
        121, // 23156 (0x5a74)
        -1,
        -1,
        3, // 19224 (0x4b18)
        175, // 22743 (0x58d7)
        -1,
        10, // 19225 (0x4b19)
        191, // 24607 (0x601f)
        -1,
        136, // 23573 (0x5c15)
        137, // 23573 (0x5c15)
        -1,
        -1,
        -1,
        -1,
        25, // 21505 (0x5401)
        146, // 19228 (0x4b1c)
        -1,
        -1,
        -1,
        -1,
        106, // 19230 (0x4b1e)
        -1,
        -1,
        127, // 21508 (0x5404)
        140, // 24406 (0x5f56)
        -1,
        -1,
        -1,
        -1,
        44, // 24408 (0x5f58)
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 22754 (0x58e2)
        -1,
        -1,
        2, // 18408 (0x47e8)
        143, // 25446 (0x6366)
        -1,
        76, // 21514 (0x540a)
        123, // 22342 (0x5746)
        -1,
        24, // 21515 (0x540b)
        85, // 26069 (0x65d5)
        -1,
        58, // 18411 (0x47eb)
        189, // 23586 (0x5c22)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        188, // 21726 (0x54de)
        -1,
        -1,
        67, // 20485 (0x5005)
        -1,
        -1,
        180, // 19244 (0x4b2c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        75, // 20696 (0x50d8)
        166, // 19247 (0x4b2f)
        -1,
        89, // 22767 (0x58ef)
        -1,
        -1,
        1, // 18421 (0x47f5)
        38, // 27115 (0x69eb)
        -1,
        23, // 20699 (0x50db)
        -1,
        -1,
    };
    for (int i=0; i < 3; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash3, dataset=countries, type=hash, hash=hash3
void check_countries_hash3() {
    assert(lookup_countries_hash3("NICARAGUA") == 160);
    assert(lookup_countries_hash3("SPAIN") == 138);
    assert(lookup_countries_hash3("KIRIBATI") == 168);
    assert(lookup_countries_hash3("DENMARK") == 109);
    assert(lookup_countries_hash3("SUDAN") == 45);
    assert(lookup_countries_hash3("CAMBODIA") == 60);
    assert(lookup_countries_hash3("MAURITANIA") == 30);
    assert(lookup_countries_hash3("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash3("UKRAINE") == 141);
    assert(lookup_countries_hash3("RWANDA") == 37);
    assert(lookup_countries_hash3("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash3("GHANA") == 19);
    assert(lookup_countries_hash3("TANZANIA") == 47);
    assert(lookup_countries_hash3("MICRONESIA") == 170);
    assert(lookup_countries_hash3("GABON") == 17);
    assert(lookup_countries_hash3("CAMEROON") == 6);
    assert(lookup_countries_hash3("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash3("COLOMBIA") == 184);
    assert(lookup_countries_hash3("THAILAND") == 91);
    assert(lookup_countries_hash3("CHINA") == 61);
    assert(lookup_countries_hash3("HUNGARY") == 116);
    assert(lookup_countries_hash3("UZBEKISTAN") == 95);
    assert(lookup_countries_hash3("MADAGASCAR") == 27);
    assert(lookup_countries_hash3("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash3("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash3("CHILE") == 183);
    assert(lookup_countries_hash3("MOLDOVA") == 126);
    assert(lookup_countries_hash3("SIERRA LEONE") == 41);
    assert(lookup_countries_hash3("ICELAND") == 117);
    assert(lookup_countries_hash3("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash3("MALI") == 29);
    assert(lookup_countries_hash3("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash3("TONGA") == 177);
    assert(lookup_countries_hash3("PAKISTAN") == 82);
    assert(lookup_countries_hash3("MONTENEGRO") == 128);
    assert(lookup_countries_hash3("URUGUAY") == 190);
    assert(lookup_countries_hash3("JORDAN") == 69);
    assert(lookup_countries_hash3("NORWAY") == 130);
    assert(lookup_countries_hash3("PHILIPPINES") == 83);
    assert(lookup_countries_hash3("SINGAPORE") == 87);
    assert(lookup_countries_hash3("BELIZE") == 147);
    assert(lookup_countries_hash3("SERBIA") == 135);
    assert(lookup_countries_hash3("FRANCE") == 112);
    assert(lookup_countries_hash3("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash3("CONGO") == 11);
    assert(lookup_countries_hash3("MOROCCO") == 32);
    assert(lookup_countries_hash3("SRI LANKA") == 88);
    assert(lookup_countries_hash3("EAST TIMOR") == 62);
    assert(lookup_countries_hash3("PARAGUAY") == 187);
    assert(lookup_countries_hash3("IRELAND") == 118);
    assert(lookup_countries_hash3("PORTUGAL") == 132);
    assert(lookup_countries_hash3("LIBYA") == 26);
    assert(lookup_countries_hash3("PALAU") == 173);
    assert(lookup_countries_hash3("BHUTAN") == 56);
    assert(lookup_countries_hash3("SWAZILAND") == 46);
    assert(lookup_countries_hash3("ERITREA") == 15);
    assert(lookup_countries_hash3("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash3("ESTONIA") == 110);
    assert(lookup_countries_hash3("BRUNEI") == 57);
    assert(lookup_countries_hash3("MYANMAR") == 59);
    assert(lookup_countries_hash3("ECUADOR") == 185);
    assert(lookup_countries_hash3("ALGERIA") == 0);
    assert(lookup_countries_hash3("ALBANIA") == 98);
    assert(lookup_countries_hash3("BRAZIL") == 182);
    assert(lookup_countries_hash3("HAITI") == 156);
    assert(lookup_countries_hash3("KOREA, NORTH") == 71);
    assert(lookup_countries_hash3("KOREA, SOUTH") == 72);
    assert(lookup_countries_hash3("ANDORRA") == 99);
    assert(lookup_countries_hash3("VIETNAM") == 96);
    assert(lookup_countries_hash3("VANUATU") == 179);
    assert(lookup_countries_hash3("NAMIBIA") == 34);
    assert(lookup_countries_hash3("IRAN") == 65);
    assert(lookup_countries_hash3("ARMENIA") == 100);
    assert(lookup_countries_hash3("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash3("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash3("ROMANIA") == 133);
    assert(lookup_countries_hash3("IRAQ") == 66);
    assert(lookup_countries_hash3("AUSTRIA") == 101);
    assert(lookup_countries_hash3("DOMINICA") == 151);
    assert(lookup_countries_hash3("GAMBIA") == 18);
    assert(lookup_countries_hash3("DJIBOUTI") == 12);
    assert(lookup_countries_hash3("SWEDEN") == 139);
    assert(lookup_countries_hash3("NIGERIA") == 36);
    assert(lookup_countries_hash3("YEMEN") == 97);
    assert(lookup_countries_hash3("HONDURAS") == 157);
    assert(lookup_countries_hash3("JAMAICA") == 158);
    assert(lookup_countries_hash3("AZERBAIJAN") == 102);
    assert(lookup_countries_hash3("CANADA") == 148);
    assert(lookup_countries_hash3("GUATEMALA") == 155);
    assert(lookup_countries_hash3("MALAYSIA") == 77);
    assert(lookup_countries_hash3("GUINEA") == 20);
    assert(lookup_countries_hash3("GUYANA") == 186);
    assert(lookup_countries_hash3("GREECE") == 115);
    assert(lookup_countries_hash3("MALTA") == 125);
    assert(lookup_countries_hash3("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash3("BANGLADESH") == 55);
    assert(lookup_countries_hash3("MONGOLIA") == 79);
    assert(lookup_countries_hash3("QATAR") == 84);
    assert(lookup_countries_hash3("PANAMA") == 161);
    assert(lookup_countries_hash3("KUWAIT") == 73);
    assert(lookup_countries_hash3("FINLAND") == 111);
    assert(lookup_countries_hash3("MALDIVES") == 78);
    assert(lookup_countries_hash3("TURKMENISTAN") == 93);
    assert(lookup_countries_hash3("LITHUANIA") == 122);
    assert(lookup_countries_hash3("LATVIA") == 120);
    assert(lookup_countries_hash3("SAN MARINO") == 134);
    assert(lookup_countries_hash3("ZIMBABWE") == 52);
    assert(lookup_countries_hash3("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash3("BAHRAIN") == 54);
    assert(lookup_countries_hash3("FIJI") == 167);
    assert(lookup_countries_hash3("BOLIVIA") == 181);
    assert(lookup_countries_hash3("BELGIUM") == 104);
    assert(lookup_countries_hash3("POLAND") == 131);
    assert(lookup_countries_hash3("INDIA") == 63);
    assert(lookup_countries_hash3("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash3("SEYCHELLES") == 40);
    assert(lookup_countries_hash3("BAHAMAS") == 145);
    assert(lookup_countries_hash3("SOMALIA") == 42);
    assert(lookup_countries_hash3("BURKINA") == 4);
    assert(lookup_countries_hash3("SENEGAL") == 39);
    assert(lookup_countries_hash3("BELARUS") == 103);
    assert(lookup_countries_hash3("ETHIOPIA") == 16);
    assert(lookup_countries_hash3("CYPRUS") == 108);
    assert(lookup_countries_hash3("EL SALVADOR") == 153);
    assert(lookup_countries_hash3("IVORY COAST") == 22);
    assert(lookup_countries_hash3("AFGHANISTAN") == 53);
    assert(lookup_countries_hash3("BURUNDI") == 5);
    assert(lookup_countries_hash3("TUVALU") == 178);
    assert(lookup_countries_hash3("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash3("NEW ZEALAND") == 172);
    assert(lookup_countries_hash3("TURKEY") == 92);
    assert(lookup_countries_hash3("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash3("EGYPT") == 13);
    assert(lookup_countries_hash3("GEORGIA") == 113);
    assert(lookup_countries_hash3("UGANDA") == 50);
    assert(lookup_countries_hash3("CAPE VERDE") == 7);
    assert(lookup_countries_hash3("NETHERLANDS") == 129);
    assert(lookup_countries_hash3("ITALY") == 119);
    assert(lookup_countries_hash3("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash3("OMAN") == 81);
    assert(lookup_countries_hash3("MACEDONIA") == 124);
    assert(lookup_countries_hash3("COSTA RICA") == 149);
    assert(lookup_countries_hash3("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash3("GRENADA") == 154);
    assert(lookup_countries_hash3("NEPAL") == 80);
    assert(lookup_countries_hash3("TAJIKISTAN") == 90);
    assert(lookup_countries_hash3("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash3("SAINT LUCIA") == 163);
    assert(lookup_countries_hash3("NAURU") == 171);
    assert(lookup_countries_hash3("JAPAN") == 68);
    assert(lookup_countries_hash3("CROATIA") == 107);
    assert(lookup_countries_hash3("GERMANY") == 114);
    assert(lookup_countries_hash3("MALAWI") == 28);
    assert(lookup_countries_hash3("NIGER") == 35);
    assert(lookup_countries_hash3("CHAD") == 9);
    assert(lookup_countries_hash3("MAURITIUS") == 31);
    assert(lookup_countries_hash3("TUNISIA") == 49);
    assert(lookup_countries_hash3("INDONESIA") == 64);
    assert(lookup_countries_hash3("ZAMBIA") == 51);
    assert(lookup_countries_hash3("MEXICO") == 159);
    assert(lookup_countries_hash3("CUBA") == 150);
    assert(lookup_countries_hash3("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash3("BOTSWANA") == 3);
    assert(lookup_countries_hash3("SAMOA") == 175);
    assert(lookup_countries_hash3("COMOROS") == 10);
    assert(lookup_countries_hash3("VENEZUELA") == 191);
    assert(lookup_countries_hash3("SLOVAKIA") == 136);
    assert(lookup_countries_hash3("SLOVENIA") == 137);
    assert(lookup_countries_hash3("LIBERIA") == 25);
    assert(lookup_countries_hash3("BARBADOS") == 146);
    assert(lookup_countries_hash3("BULGARIA") == 106);
    assert(lookup_countries_hash3("MONACO") == 127);
    assert(lookup_countries_hash3("SWITZERLAND") == 140);
    assert(lookup_countries_hash3("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash3("TOGO") == 48);
    assert(lookup_countries_hash3("BENIN") == 2);
    assert(lookup_countries_hash3("VATICAN CITY") == 143);
    assert(lookup_countries_hash3("LEBANON") == 76);
    assert(lookup_countries_hash3("LUXEMBOURG") == 123);
    assert(lookup_countries_hash3("LESOTHO") == 24);
    assert(lookup_countries_hash3("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash3("BURMA") == 58);
    assert(lookup_countries_hash3("SURINAME") == 189);
    assert(lookup_countries_hash3("PERU") == 188);
    assert(lookup_countries_hash3("ISRAEL") == 67);
    assert(lookup_countries_hash3("ARGENTINA") == 180);
    assert(lookup_countries_hash3("LAOS") == 75);
    assert(lookup_countries_hash3("AUSTRALIA") == 166);
    assert(lookup_countries_hash3("SYRIA") == 89);
    assert(lookup_countries_hash3("ANGOLA") == 1);
    assert(lookup_countries_hash3("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash3("KENYA") == 23);
}

//lookup: name=lookup_countries_hash_sum0, dataset=countries, type=hash, hash=hash_sum0
int lookup_countries_hash_sum0(std::string_view s) {
    const uint64_t idx = (hash_sum0(s) % 192) * 4;
    constexpr const std::string_view lookup[768] = {
        "UZBEKISTAN", // 768 (0x300)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MARSHALL ISLANDS", // 1154 (0x482)
        "",
        "",
        "",
        "ITALY", // 387 (0x183)
        "",
        "",
        "",
        "DOMINICA", // 580 (0x244)
        "",
        "",
        "",
        "THAILAND", // 581 (0x245)
        "",
        "",
        "",
        "COLOMBIA", // 582 (0x246)
        "",
        "",
        "",
        "BULGARIA", // 583 (0x247)
        "",
        "",
        "",
        "SYRIA", // 392 (0x188)
        "",
        "",
        "",
        "EGYPT", // 393 (0x189)
        "NEW ZEALAND", // 777 (0x309)
        "",
        "",
        "LUXEMBOURG", // 778 (0x30a)
        "",
        "",
        "",
        "NAURU", // 395 (0x18b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EL SALVADOR", // 781 (0x30d)
        "SAINT LUCIA", // 781 (0x30d)
        "",
        "",
        "",
        "",
        "",
        "",
        "LIECHTENSTEIN", // 975 (0x3cf)
        "KIRIBATI", // 591 (0x24f)
        "",
        "",
        "",
        "",
        "",
        "",
        "ZIMBABWE", // 593 (0x251)
        "MALAYSIA", // 593 (0x251)
        "BOSNIA AND HERZEGOVINA", // 1553 (0x611)
        "",
        "",
        "",
        "",
        "",
        "ETHIOPIA", // 595 (0x253)
        "",
        "",
        "",
        "CAMEROON", // 596 (0x254)
        "",
        "",
        "",
        "MALDIVES", // 597 (0x255)
        "",
        "",
        "",
        "TANZANIA", // 598 (0x256)
        "MONGOLIA", // 598 (0x256)
        "",
        "",
        "",
        "",
        "",
        "",
        "CANADA", // 408 (0x198)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DJIBOUTI", // 602 (0x25a)
        "SLOVAKIA", // 602 (0x25a)
        "PARAGUAY", // 602 (0x25a)
        "",
        "PAKISTAN", // 603 (0x25b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BOTSWANA", // 607 (0x25f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GAMBIA", // 417 (0x1a1)
        "SLOVENIA", // 609 (0x261)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AFGHANISTAN", // 804 (0x324)
        "HONDURAS", // 612 (0x264)
        "SURINAME", // 612 (0x264)
        "",
        "",
        "",
        "",
        "",
        "KYRGYZSTAN", // 806 (0x326)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GREECE", // 427 (0x1ab)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH SUDAN", // 814 (0x32e)
        "PORTUGAL", // 622 (0x26e)
        "PANAMA", // 430 (0x1ae)
        "",
        "FRANCE", // 431 (0x1af)
        "",
        "",
        "",
        "UGANDA", // 432 (0x1b0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ANGOLA", // 434 (0x1b2)
        "UNITED KINGDOM", // 1010 (0x3f2)
        "",
        "",
        "IVORY COAST", // 819 (0x333)
        "",
        "",
        "",
        "ZAMBIA", // 436 (0x1b4)
        "",
        "",
        "",
        "SRI LANKA", // 629 (0x275)
        "",
        "",
        "",
        "SAUDI ARABIA", // 822 (0x336)
        "SERBIA", // 438 (0x1b6)
        "",
        "",
        "",
        "",
        "",
        "",
        "NETHERLANDS", // 824 (0x338)
        "",
        "",
        "",
        "GUINEA", // 441 (0x1b9)
        "UNITED ARAB EMIRATES", // 1401 (0x579)
        "",
        "",
        "",
        "",
        "",
        "",
        "MALAWI", // 443 (0x1bb)
        "BELIZE", // 443 (0x1bb)
        "",
        "",
        "",
        "",
        "",
        "",
        "RWANDA", // 445 (0x1bd)
        "MONACO", // 445 (0x1bd)
        "",
        "",
        "JORDAN", // 446 (0x1be)
        "POLAND", // 446 (0x1be)
        "",
        "",
        "",
        "",
        "",
        "",
        "ISRAEL", // 448 (0x1c0)
        "",
        "",
        "",
        "LATVIA", // 449 (0x1c1)
        "MACEDONIA", // 641 (0x281)
        "",
        "",
        "BHUTAN", // 450 (0x1c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BRAZIL", // 452 (0x1c4)
        "",
        "",
        "",
        "BRUNEI", // 453 (0x1c5)
        "PHILIPPINES", // 837 (0x345)
        "MEXICO", // 453 (0x1c5)
        "GUYANA", // 453 (0x1c5)
        "SWEDEN", // 454 (0x1c6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KOREA, NORTH", // 841 (0x349)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NICARAGUA", // 651 (0x28b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAD", // 272 (0x110)
        "EQUATORIAL GUINEA", // 1232 (0x4d0)
        "",
        "",
        "KOREA, SOUTH", // 849 (0x351)
        "GUATEMALA", // 657 (0x291)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KUWAIT", // 469 (0x1d5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SWITZERLAND", // 855 (0x357)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIERRA LEONE", // 857 (0x359)
        "SOUTH AFRICA", // 857 (0x359)
        "ARGENTINA", // 665 (0x299)
        "",
        "INDONESIA", // 666 (0x29a)
        "",
        "",
        "",
        "CUBA", // 283 (0x11b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LITHUANIA", // 671 (0x29f)
        "VATICAN CITY", // 863 (0x35f)
        "",
        "",
        "NORWAY", // 480 (0x1e0)
        "",
        "",
        "",
        "TUVALU", // 481 (0x1e1)
        "",
        "",
        "",
        "FIJI", // 290 (0x122)
        "",
        "",
        "",
        "MALI", // 291 (0x123)
        "",
        "",
        "",
        "TURKEY", // 484 (0x1e4)
        "",
        "",
        "",
        "SAO TOME AND PRINCIPE", // 1445 (0x5a5)
        "",
        "",
        "",
        "CYPRUS", // 486 (0x1e6)
        "JAMAICA", // 486 (0x1e6)
        "AUSTRALIA", // 678 (0x2a6)
        "",
        "",
        "",
        "",
        "",
        "SINGAPORE", // 680 (0x2a8)
        "ALBANIA", // 488 (0x1e8)
        "",
        "",
        "",
        "",
        "",
        "",
        "IRAN", // 298 (0x12a)
        "SAINT VINCENT AND THE GRENADINES", // 2218 (0x8aa)
        "",
        "",
        "OMAN", // 299 (0x12b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SWAZILAND", // 685 (0x2ad)
        "IRAQ", // 301 (0x12d)
        "BAHAMAS", // 493 (0x1ed)
        "",
        "",
        "",
        "",
        "",
        "CAPE VERDE", // 687 (0x2af)
        "LAOS", // 303 (0x12f)
        "VENEZUELA", // 687 (0x2af)
        "",
        "ICELAND", // 496 (0x1f0)
        "",
        "",
        "",
        "NAMIBIA", // 497 (0x1f1)
        "",
        "",
        "",
        "GRENADA", // 498 (0x1f2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALGERIA", // 501 (0x1f5)
        "BAHRAIN", // 501 (0x1f5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIBERIA", // 504 (0x1f8)
        "",
        "",
        "",
        "TOGO", // 313 (0x139)
        "COSTA RICA", // 697 (0x2b9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FINLAND", // 508 (0x1fc)
        "PERU", // 316 (0x13c)
        "",
        "",
        "ARMENIA", // 509 (0x1fd)
        "",
        "",
        "",
        "GEORGIA", // 510 (0x1fe)
        "",
        "",
        "",
        "NIGERIA", // 511 (0x1ff)
        "SENEGAL", // 511 (0x1ff)
        "LEBANON", // 511 (0x1ff)
        "IRELAND", // 511 (0x1ff)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DENMARK", // 514 (0x202)
        "",
        "",
        "",
        "MAURITIUS", // 707 (0x2c3)
        "CROATIA", // 515 (0x203)
        "ECUADOR", // 515 (0x203)
        "",
        "MADAGASCAR", // 708 (0x2c4)
        "",
        "",
        "",
        "BELGIUM", // 517 (0x205)
        "",
        "",
        "",
        "SOMALIA", // 518 (0x206)
        "SAINT KITTS AND NEVIS", // 1478 (0x5c6)
        "BOLIVIA", // 518 (0x206)
        "",
        "ANDORRA", // 519 (0x207)
        "ROMANIA", // 519 (0x207)
        "",
        "",
        "SAN MARINO", // 712 (0x2c8)
        "DOMINICAN REPUBLIC", // 1288 (0x508)
        "",
        "",
        "BANGLADESH", // 713 (0x2c9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BURKINA", // 524 (0x20c)
        "ERITREA", // 524 (0x20c)
        "",
        "",
        "ANTIGUA AND BARBUDA", // 1293 (0x50d)
        "",
        "",
        "",
        "BELARUS", // 526 (0x20e)
        "",
        "",
        "",
        "UKRAINE", // 527 (0x20f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOROCCO", // 530 (0x212)
        "MOLDOVA", // 530 (0x212)
        "",
        "",
        "CENTRAL AFRICAN REPUBLIC", // 1683 (0x693)
        "ESTONIA", // 531 (0x213)
        "GERMANY", // 531 (0x213)
        "",
        "VIETNAM", // 532 (0x214)
        "",
        "",
        "",
        "MYANMAR", // 533 (0x215)
        "SOLOMON ISLANDS", // 1109 (0x455)
        "",
        "",
        "",
        "",
        "",
        "",
        "AZERBAIJAN", // 727 (0x2d7)
        "",
        "",
        "",
        "EAST TIMOR", // 728 (0x2d8)
        "",
        "",
        "",
        "BURUNDI", // 537 (0x219)
        "AUSTRIA", // 537 (0x219)
        "",
        "",
        "PAPUA NEW GUINEA", // 1114 (0x45a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TUNISIA", // 541 (0x21d)
        "",
        "",
        "",
        "LESOTHO", // 542 (0x21e)
        "HUNGARY", // 542 (0x21e)
        "TRINIDAD AND TOBAGO", // 1310 (0x51e)
        "",
        "GHANA", // 351 (0x15f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "COMOROS", // 546 (0x222)
        "",
        "",
        "",
        "CHINA", // 355 (0x163)
        "",
        "",
        "",
        "VANUATU", // 548 (0x224)
        "",
        "",
        "",
        "INDIA", // 357 (0x165)
        "TURKMENISTAN", // 933 (0x3a5)
        "CHILE", // 357 (0x165)
        "",
        "RUSSIAN FEDERATION", // 1318 (0x526)
        "",
        "",
        "",
        "GABON", // 359 (0x167)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "JAPAN", // 362 (0x16a)
        "MICRONESIA", // 746 (0x2ea)
        "",
        "",
        "MAURITANIA", // 747 (0x2eb)
        "",
        "",
        "",
        "BENIN", // 364 (0x16c)
        "",
        "",
        "",
        "GUINEA-BISSAU", // 941 (0x3ad)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MALTA", // 367 (0x16f)
        "HAITI", // 367 (0x16f)
        "",
        "",
        "CAMBODIA", // 560 (0x230)
        "KAZAKHSTAN", // 752 (0x2f0)
        "NEPAL", // 368 (0x170)
        "",
        "LIBYA", // 369 (0x171)
        "SEYCHELLES", // 753 (0x2f1)
        "SAMOA", // 369 (0x171)
        "",
        "TAJIKISTAN", // 754 (0x2f2)
        "URUGUAY", // 562 (0x232)
        "",
        "",
        "PALAU", // 371 (0x173)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NIGER", // 373 (0x175)
        "",
        "",
        "",
        "CONGO", // 374 (0x176)
        "",
        "",
        "",
        "BURMA", // 375 (0x177)
        "",
        "",
        "",
        "KENYA", // 376 (0x178)
        "",
        "",
        "",
        "QATAR", // 377 (0x179)
        "TONGA", // 377 (0x179)
        "",
        "",
        "MOZAMBIQUE", // 762 (0x2fa)
        "",
        "",
        "",
        "SUDAN", // 379 (0x17b)
        "SPAIN", // 379 (0x17b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "YEMEN", // 382 (0x17e)
        "MONTENEGRO", // 766 (0x2fe)
        "BARBADOS", // 574 (0x23e)
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[768] = {
        95, // 768 (0x300)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        169, // 1154 (0x482)
        -1,
        -1,
        -1,
        119, // 387 (0x183)
        -1,
        -1,
        -1,
        151, // 580 (0x244)
        -1,
        -1,
        -1,
        91, // 581 (0x245)
        -1,
        -1,
        -1,
        184, // 582 (0x246)
        -1,
        -1,
        -1,
        106, // 583 (0x247)
        -1,
        -1,
        -1,
        89, // 392 (0x188)
        -1,
        -1,
        -1,
        13, // 393 (0x189)
        172, // 777 (0x309)
        -1,
        -1,
        123, // 778 (0x30a)
        -1,
        -1,
        -1,
        171, // 395 (0x18b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        153, // 781 (0x30d)
        163, // 781 (0x30d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        121, // 975 (0x3cf)
        168, // 591 (0x24f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        52, // 593 (0x251)
        77, // 593 (0x251)
        105, // 1553 (0x611)
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 595 (0x253)
        -1,
        -1,
        -1,
        6, // 596 (0x254)
        -1,
        -1,
        -1,
        78, // 597 (0x255)
        -1,
        -1,
        -1,
        47, // 598 (0x256)
        79, // 598 (0x256)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        148, // 408 (0x198)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 602 (0x25a)
        136, // 602 (0x25a)
        187, // 602 (0x25a)
        -1,
        82, // 603 (0x25b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 607 (0x25f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        18, // 417 (0x1a1)
        137, // 609 (0x261)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 804 (0x324)
        157, // 612 (0x264)
        189, // 612 (0x264)
        -1,
        -1,
        -1,
        -1,
        -1,
        74, // 806 (0x326)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        115, // 427 (0x1ab)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 814 (0x32e)
        132, // 622 (0x26e)
        161, // 430 (0x1ae)
        -1,
        112, // 431 (0x1af)
        -1,
        -1,
        -1,
        50, // 432 (0x1b0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 434 (0x1b2)
        142, // 1010 (0x3f2)
        -1,
        -1,
        22, // 819 (0x333)
        -1,
        -1,
        -1,
        51, // 436 (0x1b4)
        -1,
        -1,
        -1,
        88, // 629 (0x275)
        -1,
        -1,
        -1,
        86, // 822 (0x336)
        135, // 438 (0x1b6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        129, // 824 (0x338)
        -1,
        -1,
        -1,
        20, // 441 (0x1b9)
        94, // 1401 (0x579)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 443 (0x1bb)
        147, // 443 (0x1bb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 445 (0x1bd)
        127, // 445 (0x1bd)
        -1,
        -1,
        69, // 446 (0x1be)
        131, // 446 (0x1be)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        67, // 448 (0x1c0)
        -1,
        -1,
        -1,
        120, // 449 (0x1c1)
        124, // 641 (0x281)
        -1,
        -1,
        56, // 450 (0x1c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        182, // 452 (0x1c4)
        -1,
        -1,
        -1,
        57, // 453 (0x1c5)
        83, // 837 (0x345)
        159, // 453 (0x1c5)
        186, // 453 (0x1c5)
        139, // 454 (0x1c6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 841 (0x349)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        160, // 651 (0x28b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 272 (0x110)
        14, // 1232 (0x4d0)
        -1,
        -1,
        72, // 849 (0x351)
        155, // 657 (0x291)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        73, // 469 (0x1d5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        140, // 855 (0x357)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 857 (0x359)
        43, // 857 (0x359)
        180, // 665 (0x299)
        -1,
        64, // 666 (0x29a)
        -1,
        -1,
        -1,
        150, // 283 (0x11b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        122, // 671 (0x29f)
        143, // 863 (0x35f)
        -1,
        -1,
        130, // 480 (0x1e0)
        -1,
        -1,
        -1,
        178, // 481 (0x1e1)
        -1,
        -1,
        -1,
        167, // 290 (0x122)
        -1,
        -1,
        -1,
        29, // 291 (0x123)
        -1,
        -1,
        -1,
        92, // 484 (0x1e4)
        -1,
        -1,
        -1,
        38, // 1445 (0x5a5)
        -1,
        -1,
        -1,
        108, // 486 (0x1e6)
        158, // 486 (0x1e6)
        166, // 678 (0x2a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 680 (0x2a8)
        98, // 488 (0x1e8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        65, // 298 (0x12a)
        164, // 2218 (0x8aa)
        -1,
        -1,
        81, // 299 (0x12b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 685 (0x2ad)
        66, // 301 (0x12d)
        145, // 493 (0x1ed)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 687 (0x2af)
        75, // 303 (0x12f)
        191, // 687 (0x2af)
        -1,
        117, // 496 (0x1f0)
        -1,
        -1,
        -1,
        34, // 497 (0x1f1)
        -1,
        -1,
        -1,
        154, // 498 (0x1f2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 501 (0x1f5)
        54, // 501 (0x1f5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 504 (0x1f8)
        -1,
        -1,
        -1,
        48, // 313 (0x139)
        149, // 697 (0x2b9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        111, // 508 (0x1fc)
        188, // 316 (0x13c)
        -1,
        -1,
        100, // 509 (0x1fd)
        -1,
        -1,
        -1,
        113, // 510 (0x1fe)
        -1,
        -1,
        -1,
        36, // 511 (0x1ff)
        39, // 511 (0x1ff)
        76, // 511 (0x1ff)
        118, // 511 (0x1ff)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 514 (0x202)
        -1,
        -1,
        -1,
        31, // 707 (0x2c3)
        107, // 515 (0x203)
        185, // 515 (0x203)
        -1,
        27, // 708 (0x2c4)
        -1,
        -1,
        -1,
        104, // 517 (0x205)
        -1,
        -1,
        -1,
        42, // 518 (0x206)
        162, // 1478 (0x5c6)
        181, // 518 (0x206)
        -1,
        99, // 519 (0x207)
        133, // 519 (0x207)
        -1,
        -1,
        134, // 712 (0x2c8)
        152, // 1288 (0x508)
        -1,
        -1,
        55, // 713 (0x2c9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        4, // 524 (0x20c)
        15, // 524 (0x20c)
        -1,
        -1,
        144, // 1293 (0x50d)
        -1,
        -1,
        -1,
        103, // 526 (0x20e)
        -1,
        -1,
        -1,
        141, // 527 (0x20f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 530 (0x212)
        126, // 530 (0x212)
        -1,
        -1,
        8, // 1683 (0x693)
        110, // 531 (0x213)
        114, // 531 (0x213)
        -1,
        96, // 532 (0x214)
        -1,
        -1,
        -1,
        59, // 533 (0x215)
        176, // 1109 (0x455)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        102, // 727 (0x2d7)
        -1,
        -1,
        -1,
        62, // 728 (0x2d8)
        -1,
        -1,
        -1,
        5, // 537 (0x219)
        101, // 537 (0x219)
        -1,
        -1,
        174, // 1114 (0x45a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        49, // 541 (0x21d)
        -1,
        -1,
        -1,
        24, // 542 (0x21e)
        116, // 542 (0x21e)
        165, // 1310 (0x51e)
        -1,
        19, // 351 (0x15f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 546 (0x222)
        -1,
        -1,
        -1,
        61, // 355 (0x163)
        -1,
        -1,
        -1,
        179, // 548 (0x224)
        -1,
        -1,
        -1,
        63, // 357 (0x165)
        93, // 933 (0x3a5)
        183, // 357 (0x165)
        -1,
        85, // 1318 (0x526)
        -1,
        -1,
        -1,
        17, // 359 (0x167)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 362 (0x16a)
        170, // 746 (0x2ea)
        -1,
        -1,
        30, // 747 (0x2eb)
        -1,
        -1,
        -1,
        2, // 364 (0x16c)
        -1,
        -1,
        -1,
        21, // 941 (0x3ad)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        125, // 367 (0x16f)
        156, // 367 (0x16f)
        -1,
        -1,
        60, // 560 (0x230)
        70, // 752 (0x2f0)
        80, // 368 (0x170)
        -1,
        26, // 369 (0x171)
        40, // 753 (0x2f1)
        175, // 369 (0x171)
        -1,
        90, // 754 (0x2f2)
        190, // 562 (0x232)
        -1,
        -1,
        173, // 371 (0x173)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        35, // 373 (0x175)
        -1,
        -1,
        -1,
        11, // 374 (0x176)
        -1,
        -1,
        -1,
        58, // 375 (0x177)
        -1,
        -1,
        -1,
        23, // 376 (0x178)
        -1,
        -1,
        -1,
        84, // 377 (0x179)
        177, // 377 (0x179)
        -1,
        -1,
        33, // 762 (0x2fa)
        -1,
        -1,
        -1,
        45, // 379 (0x17b)
        138, // 379 (0x17b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 382 (0x17e)
        128, // 766 (0x2fe)
        146, // 574 (0x23e)
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 4; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash_sum0, dataset=countries, type=hash, hash=hash_sum0
void check_countries_hash_sum0() {
    assert(lookup_countries_hash_sum0("UZBEKISTAN") == 95);
    assert(lookup_countries_hash_sum0("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash_sum0("ITALY") == 119);
    assert(lookup_countries_hash_sum0("DOMINICA") == 151);
    assert(lookup_countries_hash_sum0("THAILAND") == 91);
    assert(lookup_countries_hash_sum0("COLOMBIA") == 184);
    assert(lookup_countries_hash_sum0("BULGARIA") == 106);
    assert(lookup_countries_hash_sum0("SYRIA") == 89);
    assert(lookup_countries_hash_sum0("EGYPT") == 13);
    assert(lookup_countries_hash_sum0("NEW ZEALAND") == 172);
    assert(lookup_countries_hash_sum0("LUXEMBOURG") == 123);
    assert(lookup_countries_hash_sum0("NAURU") == 171);
    assert(lookup_countries_hash_sum0("EL SALVADOR") == 153);
    assert(lookup_countries_hash_sum0("SAINT LUCIA") == 163);
    assert(lookup_countries_hash_sum0("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash_sum0("KIRIBATI") == 168);
    assert(lookup_countries_hash_sum0("ZIMBABWE") == 52);
    assert(lookup_countries_hash_sum0("MALAYSIA") == 77);
    assert(lookup_countries_hash_sum0("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash_sum0("ETHIOPIA") == 16);
    assert(lookup_countries_hash_sum0("CAMEROON") == 6);
    assert(lookup_countries_hash_sum0("MALDIVES") == 78);
    assert(lookup_countries_hash_sum0("TANZANIA") == 47);
    assert(lookup_countries_hash_sum0("MONGOLIA") == 79);
    assert(lookup_countries_hash_sum0("CANADA") == 148);
    assert(lookup_countries_hash_sum0("DJIBOUTI") == 12);
    assert(lookup_countries_hash_sum0("SLOVAKIA") == 136);
    assert(lookup_countries_hash_sum0("PARAGUAY") == 187);
    assert(lookup_countries_hash_sum0("PAKISTAN") == 82);
    assert(lookup_countries_hash_sum0("BOTSWANA") == 3);
    assert(lookup_countries_hash_sum0("GAMBIA") == 18);
    assert(lookup_countries_hash_sum0("SLOVENIA") == 137);
    assert(lookup_countries_hash_sum0("AFGHANISTAN") == 53);
    assert(lookup_countries_hash_sum0("HONDURAS") == 157);
    assert(lookup_countries_hash_sum0("SURINAME") == 189);
    assert(lookup_countries_hash_sum0("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash_sum0("GREECE") == 115);
    assert(lookup_countries_hash_sum0("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash_sum0("PORTUGAL") == 132);
    assert(lookup_countries_hash_sum0("PANAMA") == 161);
    assert(lookup_countries_hash_sum0("FRANCE") == 112);
    assert(lookup_countries_hash_sum0("UGANDA") == 50);
    assert(lookup_countries_hash_sum0("ANGOLA") == 1);
    assert(lookup_countries_hash_sum0("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash_sum0("IVORY COAST") == 22);
    assert(lookup_countries_hash_sum0("ZAMBIA") == 51);
    assert(lookup_countries_hash_sum0("SRI LANKA") == 88);
    assert(lookup_countries_hash_sum0("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash_sum0("SERBIA") == 135);
    assert(lookup_countries_hash_sum0("NETHERLANDS") == 129);
    assert(lookup_countries_hash_sum0("GUINEA") == 20);
    assert(lookup_countries_hash_sum0("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash_sum0("MALAWI") == 28);
    assert(lookup_countries_hash_sum0("BELIZE") == 147);
    assert(lookup_countries_hash_sum0("RWANDA") == 37);
    assert(lookup_countries_hash_sum0("MONACO") == 127);
    assert(lookup_countries_hash_sum0("JORDAN") == 69);
    assert(lookup_countries_hash_sum0("POLAND") == 131);
    assert(lookup_countries_hash_sum0("ISRAEL") == 67);
    assert(lookup_countries_hash_sum0("LATVIA") == 120);
    assert(lookup_countries_hash_sum0("MACEDONIA") == 124);
    assert(lookup_countries_hash_sum0("BHUTAN") == 56);
    assert(lookup_countries_hash_sum0("BRAZIL") == 182);
    assert(lookup_countries_hash_sum0("BRUNEI") == 57);
    assert(lookup_countries_hash_sum0("PHILIPPINES") == 83);
    assert(lookup_countries_hash_sum0("MEXICO") == 159);
    assert(lookup_countries_hash_sum0("GUYANA") == 186);
    assert(lookup_countries_hash_sum0("SWEDEN") == 139);
    assert(lookup_countries_hash_sum0("KOREA, NORTH") == 71);
    assert(lookup_countries_hash_sum0("NICARAGUA") == 160);
    assert(lookup_countries_hash_sum0("CHAD") == 9);
    assert(lookup_countries_hash_sum0("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash_sum0("KOREA, SOUTH") == 72);
    assert(lookup_countries_hash_sum0("GUATEMALA") == 155);
    assert(lookup_countries_hash_sum0("KUWAIT") == 73);
    assert(lookup_countries_hash_sum0("SWITZERLAND") == 140);
    assert(lookup_countries_hash_sum0("SIERRA LEONE") == 41);
    assert(lookup_countries_hash_sum0("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash_sum0("ARGENTINA") == 180);
    assert(lookup_countries_hash_sum0("INDONESIA") == 64);
    assert(lookup_countries_hash_sum0("CUBA") == 150);
    assert(lookup_countries_hash_sum0("LITHUANIA") == 122);
    assert(lookup_countries_hash_sum0("VATICAN CITY") == 143);
    assert(lookup_countries_hash_sum0("NORWAY") == 130);
    assert(lookup_countries_hash_sum0("TUVALU") == 178);
    assert(lookup_countries_hash_sum0("FIJI") == 167);
    assert(lookup_countries_hash_sum0("MALI") == 29);
    assert(lookup_countries_hash_sum0("TURKEY") == 92);
    assert(lookup_countries_hash_sum0("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash_sum0("CYPRUS") == 108);
    assert(lookup_countries_hash_sum0("JAMAICA") == 158);
    assert(lookup_countries_hash_sum0("AUSTRALIA") == 166);
    assert(lookup_countries_hash_sum0("SINGAPORE") == 87);
    assert(lookup_countries_hash_sum0("ALBANIA") == 98);
    assert(lookup_countries_hash_sum0("IRAN") == 65);
    assert(lookup_countries_hash_sum0("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash_sum0("OMAN") == 81);
    assert(lookup_countries_hash_sum0("SWAZILAND") == 46);
    assert(lookup_countries_hash_sum0("IRAQ") == 66);
    assert(lookup_countries_hash_sum0("BAHAMAS") == 145);
    assert(lookup_countries_hash_sum0("CAPE VERDE") == 7);
    assert(lookup_countries_hash_sum0("LAOS") == 75);
    assert(lookup_countries_hash_sum0("VENEZUELA") == 191);
    assert(lookup_countries_hash_sum0("ICELAND") == 117);
    assert(lookup_countries_hash_sum0("NAMIBIA") == 34);
    assert(lookup_countries_hash_sum0("GRENADA") == 154);
    assert(lookup_countries_hash_sum0("ALGERIA") == 0);
    assert(lookup_countries_hash_sum0("BAHRAIN") == 54);
    assert(lookup_countries_hash_sum0("LIBERIA") == 25);
    assert(lookup_countries_hash_sum0("TOGO") == 48);
    assert(lookup_countries_hash_sum0("COSTA RICA") == 149);
    assert(lookup_countries_hash_sum0("FINLAND") == 111);
    assert(lookup_countries_hash_sum0("PERU") == 188);
    assert(lookup_countries_hash_sum0("ARMENIA") == 100);
    assert(lookup_countries_hash_sum0("GEORGIA") == 113);
    assert(lookup_countries_hash_sum0("NIGERIA") == 36);
    assert(lookup_countries_hash_sum0("SENEGAL") == 39);
    assert(lookup_countries_hash_sum0("LEBANON") == 76);
    assert(lookup_countries_hash_sum0("IRELAND") == 118);
    assert(lookup_countries_hash_sum0("DENMARK") == 109);
    assert(lookup_countries_hash_sum0("MAURITIUS") == 31);
    assert(lookup_countries_hash_sum0("CROATIA") == 107);
    assert(lookup_countries_hash_sum0("ECUADOR") == 185);
    assert(lookup_countries_hash_sum0("MADAGASCAR") == 27);
    assert(lookup_countries_hash_sum0("BELGIUM") == 104);
    assert(lookup_countries_hash_sum0("SOMALIA") == 42);
    assert(lookup_countries_hash_sum0("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash_sum0("BOLIVIA") == 181);
    assert(lookup_countries_hash_sum0("ANDORRA") == 99);
    assert(lookup_countries_hash_sum0("ROMANIA") == 133);
    assert(lookup_countries_hash_sum0("SAN MARINO") == 134);
    assert(lookup_countries_hash_sum0("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash_sum0("BANGLADESH") == 55);
    assert(lookup_countries_hash_sum0("BURKINA") == 4);
    assert(lookup_countries_hash_sum0("ERITREA") == 15);
    assert(lookup_countries_hash_sum0("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash_sum0("BELARUS") == 103);
    assert(lookup_countries_hash_sum0("UKRAINE") == 141);
    assert(lookup_countries_hash_sum0("MOROCCO") == 32);
    assert(lookup_countries_hash_sum0("MOLDOVA") == 126);
    assert(lookup_countries_hash_sum0("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash_sum0("ESTONIA") == 110);
    assert(lookup_countries_hash_sum0("GERMANY") == 114);
    assert(lookup_countries_hash_sum0("VIETNAM") == 96);
    assert(lookup_countries_hash_sum0("MYANMAR") == 59);
    assert(lookup_countries_hash_sum0("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash_sum0("AZERBAIJAN") == 102);
    assert(lookup_countries_hash_sum0("EAST TIMOR") == 62);
    assert(lookup_countries_hash_sum0("BURUNDI") == 5);
    assert(lookup_countries_hash_sum0("AUSTRIA") == 101);
    assert(lookup_countries_hash_sum0("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash_sum0("TUNISIA") == 49);
    assert(lookup_countries_hash_sum0("LESOTHO") == 24);
    assert(lookup_countries_hash_sum0("HUNGARY") == 116);
    assert(lookup_countries_hash_sum0("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash_sum0("GHANA") == 19);
    assert(lookup_countries_hash_sum0("COMOROS") == 10);
    assert(lookup_countries_hash_sum0("CHINA") == 61);
    assert(lookup_countries_hash_sum0("VANUATU") == 179);
    assert(lookup_countries_hash_sum0("INDIA") == 63);
    assert(lookup_countries_hash_sum0("TURKMENISTAN") == 93);
    assert(lookup_countries_hash_sum0("CHILE") == 183);
    assert(lookup_countries_hash_sum0("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash_sum0("GABON") == 17);
    assert(lookup_countries_hash_sum0("JAPAN") == 68);
    assert(lookup_countries_hash_sum0("MICRONESIA") == 170);
    assert(lookup_countries_hash_sum0("MAURITANIA") == 30);
    assert(lookup_countries_hash_sum0("BENIN") == 2);
    assert(lookup_countries_hash_sum0("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash_sum0("MALTA") == 125);
    assert(lookup_countries_hash_sum0("HAITI") == 156);
    assert(lookup_countries_hash_sum0("CAMBODIA") == 60);
    assert(lookup_countries_hash_sum0("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash_sum0("NEPAL") == 80);
    assert(lookup_countries_hash_sum0("LIBYA") == 26);
    assert(lookup_countries_hash_sum0("SEYCHELLES") == 40);
    assert(lookup_countries_hash_sum0("SAMOA") == 175);
    assert(lookup_countries_hash_sum0("TAJIKISTAN") == 90);
    assert(lookup_countries_hash_sum0("URUGUAY") == 190);
    assert(lookup_countries_hash_sum0("PALAU") == 173);
    assert(lookup_countries_hash_sum0("NIGER") == 35);
    assert(lookup_countries_hash_sum0("CONGO") == 11);
    assert(lookup_countries_hash_sum0("BURMA") == 58);
    assert(lookup_countries_hash_sum0("KENYA") == 23);
    assert(lookup_countries_hash_sum0("QATAR") == 84);
    assert(lookup_countries_hash_sum0("TONGA") == 177);
    assert(lookup_countries_hash_sum0("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash_sum0("SUDAN") == 45);
    assert(lookup_countries_hash_sum0("SPAIN") == 138);
    assert(lookup_countries_hash_sum0("YEMEN") == 97);
    assert(lookup_countries_hash_sum0("MONTENEGRO") == 128);
    assert(lookup_countries_hash_sum0("BARBADOS") == 146);
}

//lookup: name=lookup_countries_hash_sumN, dataset=countries, type=hash, hash=hash_sumN
int lookup_countries_hash_sumN(std::string_view s) {
    const uint64_t idx = (hash_sumN(s) % 192) * 4;
    constexpr const std::string_view lookup[768] = {
        "SUDAN", // 384 (0x180)
        "SPAIN", // 384 (0x180)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "YEMEN", // 387 (0x183)
        "",
        "",
        "",
        "MOZAMBIQUE", // 772 (0x304)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BARBADOS", // 582 (0x246)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ITALY", // 392 (0x188)
        "MONTENEGRO", // 776 (0x308)
        "",
        "",
        "",
        "",
        "",
        "",
        "UZBEKISTAN", // 778 (0x30a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DOMINICA", // 588 (0x24c)
        "",
        "",
        "",
        "SYRIA", // 397 (0x18d)
        "THAILAND", // 589 (0x24d)
        "",
        "",
        "EGYPT", // 398 (0x18e)
        "COLOMBIA", // 590 (0x24e)
        "",
        "",
        "BULGARIA", // 591 (0x24f)
        "",
        "",
        "",
        "NAURU", // 400 (0x190)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MARSHALL ISLANDS", // 1170 (0x492)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LUXEMBOURG", // 788 (0x314)
        "NEW ZEALAND", // 788 (0x314)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KIRIBATI", // 599 (0x257)
        "",
        "",
        "",
        "EL SALVADOR", // 792 (0x318)
        "SAINT LUCIA", // 792 (0x318)
        "",
        "",
        "ZIMBABWE", // 601 (0x259)
        "MALAYSIA", // 601 (0x259)
        "",
        "",
        "",
        "",
        "",
        "",
        "ETHIOPIA", // 603 (0x25b)
        "",
        "",
        "",
        "CAMEROON", // 604 (0x25c)
        "LIECHTENSTEIN", // 988 (0x3dc)
        "",
        "",
        "MALDIVES", // 605 (0x25d)
        "",
        "",
        "",
        "TANZANIA", // 606 (0x25e)
        "MONGOLIA", // 606 (0x25e)
        "CANADA", // 414 (0x19e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DJIBOUTI", // 610 (0x262)
        "SLOVAKIA", // 610 (0x262)
        "PARAGUAY", // 610 (0x262)
        "",
        "PAKISTAN", // 611 (0x263)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BOTSWANA", // 615 (0x267)
        "GAMBIA", // 423 (0x1a7)
        "BOSNIA AND HERZEGOVINA", // 1575 (0x627)
        "",
        "",
        "",
        "",
        "",
        "SLOVENIA", // 617 (0x269)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HONDURAS", // 620 (0x26c)
        "SURINAME", // 620 (0x26c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AFGHANISTAN", // 815 (0x32f)
        "",
        "",
        "",
        "KYRGYZSTAN", // 816 (0x330)
        "",
        "",
        "",
        "GREECE", // 433 (0x1b1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PANAMA", // 436 (0x1b4)
        "",
        "",
        "",
        "FRANCE", // 437 (0x1b5)
        "",
        "",
        "",
        "UGANDA", // 438 (0x1b6)
        "PORTUGAL", // 630 (0x276)
        "",
        "",
        "",
        "",
        "",
        "",
        "ANGOLA", // 440 (0x1b8)
        "",
        "",
        "",
        "SOUTH SUDAN", // 825 (0x339)
        "",
        "",
        "",
        "ZAMBIA", // 442 (0x1ba)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SERBIA", // 444 (0x1bc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IVORY COAST", // 830 (0x33e)
        "SRI LANKA", // 638 (0x27e)
        "",
        "",
        "GUINEA", // 447 (0x1bf)
        "",
        "",
        "",
        "UNITED KINGDOM", // 1024 (0x400)
        "",
        "",
        "",
        "MALAWI", // 449 (0x1c1)
        "BELIZE", // 449 (0x1c1)
        "",
        "",
        "SAUDI ARABIA", // 834 (0x342)
        "",
        "",
        "",
        "RWANDA", // 451 (0x1c3)
        "MONACO", // 451 (0x1c3)
        "NETHERLANDS", // 835 (0x343)
        "",
        "JORDAN", // 452 (0x1c4)
        "POLAND", // 452 (0x1c4)
        "",
        "",
        "",
        "",
        "",
        "",
        "ISRAEL", // 454 (0x1c6)
        "",
        "",
        "",
        "LATVIA", // 455 (0x1c7)
        "",
        "",
        "",
        "BHUTAN", // 456 (0x1c8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MACEDONIA", // 650 (0x28a)
        "BRAZIL", // 458 (0x1ca)
        "",
        "",
        "BRUNEI", // 459 (0x1cb)
        "MEXICO", // 459 (0x1cb)
        "GUYANA", // 459 (0x1cb)
        "",
        "SWEDEN", // 460 (0x1cc)
        "",
        "",
        "",
        "UNITED ARAB EMIRATES", // 1421 (0x58d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PHILIPPINES", // 848 (0x350)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAD", // 276 (0x114)
        "NICARAGUA", // 660 (0x294)
        "",
        "",
        "KOREA, NORTH", // 853 (0x355)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GUATEMALA", // 666 (0x29a)
        "",
        "",
        "",
        "KUWAIT", // 475 (0x1db)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KOREA, SOUTH", // 861 (0x35d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CUBA", // 287 (0x11f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EQUATORIAL GUINEA", // 1249 (0x4e1)
        "",
        "",
        "",
        "SWITZERLAND", // 866 (0x362)
        "ARGENTINA", // 674 (0x2a2)
        "",
        "",
        "INDONESIA", // 675 (0x2a3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIERRA LEONE", // 869 (0x365)
        "SOUTH AFRICA", // 869 (0x365)
        "",
        "",
        "NORWAY", // 486 (0x1e6)
        "FIJI", // 294 (0x126)
        "",
        "",
        "MALI", // 295 (0x127)
        "TUVALU", // 487 (0x1e7)
        "",
        "",
        "LITHUANIA", // 680 (0x2a8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TURKEY", // 490 (0x1ea)
        "",
        "",
        "",
        "VATICAN CITY", // 875 (0x36b)
        "",
        "",
        "",
        "CYPRUS", // 492 (0x1ec)
        "",
        "",
        "",
        "JAMAICA", // 493 (0x1ed)
        "",
        "",
        "",
        "IRAN", // 302 (0x12e)
        "",
        "",
        "",
        "OMAN", // 303 (0x12f)
        "ALBANIA", // 495 (0x1ef)
        "AUSTRALIA", // 687 (0x2af)
        "",
        "",
        "",
        "",
        "",
        "IRAQ", // 305 (0x131)
        "SINGAPORE", // 689 (0x2b1)
        "",
        "",
        "",
        "",
        "",
        "",
        "LAOS", // 307 (0x133)
        "",
        "",
        "",
        "BAHAMAS", // 500 (0x1f4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SWAZILAND", // 694 (0x2b6)
        "",
        "",
        "",
        "ICELAND", // 503 (0x1f7)
        "",
        "",
        "",
        "NAMIBIA", // 504 (0x1f8)
        "VENEZUELA", // 696 (0x2b8)
        "",
        "",
        "CAPE VERDE", // 697 (0x2b9)
        "GRENADA", // 505 (0x1f9)
        "",
        "",
        "SAO TOME AND PRINCIPE", // 1466 (0x5ba)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALGERIA", // 508 (0x1fc)
        "BAHRAIN", // 508 (0x1fc)
        "",
        "",
        "TOGO", // 317 (0x13d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIBERIA", // 511 (0x1ff)
        "",
        "",
        "",
        "PERU", // 320 (0x140)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FINLAND", // 515 (0x203)
        "COSTA RICA", // 707 (0x2c3)
        "",
        "",
        "ARMENIA", // 516 (0x204)
        "",
        "",
        "",
        "GEORGIA", // 517 (0x205)
        "",
        "",
        "",
        "NIGERIA", // 518 (0x206)
        "SENEGAL", // 518 (0x206)
        "LEBANON", // 518 (0x206)
        "IRELAND", // 518 (0x206)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DENMARK", // 521 (0x209)
        "",
        "",
        "",
        "CROATIA", // 522 (0x20a)
        "SAINT VINCENT AND THE GRENADINES", // 2250 (0x8ca)
        "ECUADOR", // 522 (0x20a)
        "",
        "",
        "",
        "",
        "",
        "MAURITIUS", // 716 (0x2cc)
        "BELGIUM", // 524 (0x20c)
        "",
        "",
        "SOMALIA", // 525 (0x20d)
        "BOLIVIA", // 525 (0x20d)
        "",
        "",
        "MADAGASCAR", // 718 (0x2ce)
        "ANDORRA", // 526 (0x20e)
        "ROMANIA", // 526 (0x20e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SAN MARINO", // 722 (0x2d2)
        "",
        "",
        "",
        "BURKINA", // 531 (0x213)
        "ERITREA", // 531 (0x213)
        "BANGLADESH", // 723 (0x2d3)
        "",
        "",
        "",
        "",
        "",
        "BELARUS", // 533 (0x215)
        "",
        "",
        "",
        "UKRAINE", // 534 (0x216)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOROCCO", // 537 (0x219)
        "MOLDOVA", // 537 (0x219)
        "",
        "",
        "ESTONIA", // 538 (0x21a)
        "GERMANY", // 538 (0x21a)
        "DOMINICAN REPUBLIC", // 1306 (0x51a)
        "",
        "VIETNAM", // 539 (0x21b)
        "SAINT KITTS AND NEVIS", // 1499 (0x5db)
        "",
        "",
        "MYANMAR", // 540 (0x21c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BURUNDI", // 544 (0x220)
        "AUSTRIA", // 544 (0x220)
        "ANTIGUA AND BARBUDA", // 1312 (0x520)
        "",
        "AZERBAIJAN", // 737 (0x2e1)
        "",
        "",
        "",
        "EAST TIMOR", // 738 (0x2e2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GHANA", // 356 (0x164)
        "TUNISIA", // 548 (0x224)
        "SOLOMON ISLANDS", // 1124 (0x464)
        "",
        "LESOTHO", // 549 (0x225)
        "HUNGARY", // 549 (0x225)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHINA", // 360 (0x168)
        "",
        "",
        "",
        "COMOROS", // 553 (0x229)
        "",
        "",
        "",
        "INDIA", // 362 (0x16a)
        "PAPUA NEW GUINEA", // 1130 (0x46a)
        "CHILE", // 362 (0x16a)
        "",
        "CENTRAL AFRICAN REPUBLIC", // 1707 (0x6ab)
        "VANUATU", // 555 (0x22b)
        "",
        "",
        "GABON", // 364 (0x16c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "JAPAN", // 367 (0x16f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BENIN", // 369 (0x171)
        "TURKMENISTAN", // 945 (0x3b1)
        "TRINIDAD AND TOBAGO", // 1329 (0x531)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MALTA", // 372 (0x174)
        "HAITI", // 372 (0x174)
        "MICRONESIA", // 756 (0x2f4)
        "",
        "MAURITANIA", // 757 (0x2f5)
        "NEPAL", // 373 (0x175)
        "",
        "",
        "LIBYA", // 374 (0x176)
        "SAMOA", // 374 (0x176)
        "",
        "",
        "",
        "",
        "",
        "",
        "CAMBODIA", // 568 (0x238)
        "RUSSIAN FEDERATION", // 1336 (0x538)
        "PALAU", // 376 (0x178)
        "",
        "URUGUAY", // 569 (0x239)
        "",
        "",
        "",
        "GUINEA-BISSAU", // 954 (0x3ba)
        "NIGER", // 378 (0x17a)
        "KAZAKHSTAN", // 762 (0x2fa)
        "",
        "CONGO", // 379 (0x17b)
        "SEYCHELLES", // 763 (0x2fb)
        "",
        "",
        "BURMA", // 380 (0x17c)
        "TAJIKISTAN", // 764 (0x2fc)
        "",
        "",
        "KENYA", // 381 (0x17d)
        "",
        "",
        "",
        "QATAR", // 382 (0x17e)
        "TONGA", // 382 (0x17e)
        "",
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[768] = {
        45, // 384 (0x180)
        138, // 384 (0x180)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 387 (0x183)
        -1,
        -1,
        -1,
        33, // 772 (0x304)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        146, // 582 (0x246)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        119, // 392 (0x188)
        128, // 776 (0x308)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        95, // 778 (0x30a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        151, // 588 (0x24c)
        -1,
        -1,
        -1,
        89, // 397 (0x18d)
        91, // 589 (0x24d)
        -1,
        -1,
        13, // 398 (0x18e)
        184, // 590 (0x24e)
        -1,
        -1,
        106, // 591 (0x24f)
        -1,
        -1,
        -1,
        171, // 400 (0x190)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        169, // 1170 (0x492)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        123, // 788 (0x314)
        172, // 788 (0x314)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        168, // 599 (0x257)
        -1,
        -1,
        -1,
        153, // 792 (0x318)
        163, // 792 (0x318)
        -1,
        -1,
        52, // 601 (0x259)
        77, // 601 (0x259)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 603 (0x25b)
        -1,
        -1,
        -1,
        6, // 604 (0x25c)
        121, // 988 (0x3dc)
        -1,
        -1,
        78, // 605 (0x25d)
        -1,
        -1,
        -1,
        47, // 606 (0x25e)
        79, // 606 (0x25e)
        148, // 414 (0x19e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        12, // 610 (0x262)
        136, // 610 (0x262)
        187, // 610 (0x262)
        -1,
        82, // 611 (0x263)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        3, // 615 (0x267)
        18, // 423 (0x1a7)
        105, // 1575 (0x627)
        -1,
        -1,
        -1,
        -1,
        -1,
        137, // 617 (0x269)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        157, // 620 (0x26c)
        189, // 620 (0x26c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 815 (0x32f)
        -1,
        -1,
        -1,
        74, // 816 (0x330)
        -1,
        -1,
        -1,
        115, // 433 (0x1b1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        161, // 436 (0x1b4)
        -1,
        -1,
        -1,
        112, // 437 (0x1b5)
        -1,
        -1,
        -1,
        50, // 438 (0x1b6)
        132, // 630 (0x276)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 440 (0x1b8)
        -1,
        -1,
        -1,
        44, // 825 (0x339)
        -1,
        -1,
        -1,
        51, // 442 (0x1ba)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        135, // 444 (0x1bc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 830 (0x33e)
        88, // 638 (0x27e)
        -1,
        -1,
        20, // 447 (0x1bf)
        -1,
        -1,
        -1,
        142, // 1024 (0x400)
        -1,
        -1,
        -1,
        28, // 449 (0x1c1)
        147, // 449 (0x1c1)
        -1,
        -1,
        86, // 834 (0x342)
        -1,
        -1,
        -1,
        37, // 451 (0x1c3)
        127, // 451 (0x1c3)
        129, // 835 (0x343)
        -1,
        69, // 452 (0x1c4)
        131, // 452 (0x1c4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        67, // 454 (0x1c6)
        -1,
        -1,
        -1,
        120, // 455 (0x1c7)
        -1,
        -1,
        -1,
        56, // 456 (0x1c8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        124, // 650 (0x28a)
        182, // 458 (0x1ca)
        -1,
        -1,
        57, // 459 (0x1cb)
        159, // 459 (0x1cb)
        186, // 459 (0x1cb)
        -1,
        139, // 460 (0x1cc)
        -1,
        -1,
        -1,
        94, // 1421 (0x58d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        83, // 848 (0x350)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 276 (0x114)
        160, // 660 (0x294)
        -1,
        -1,
        71, // 853 (0x355)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        155, // 666 (0x29a)
        -1,
        -1,
        -1,
        73, // 475 (0x1db)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 861 (0x35d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        150, // 287 (0x11f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 1249 (0x4e1)
        -1,
        -1,
        -1,
        140, // 866 (0x362)
        180, // 674 (0x2a2)
        -1,
        -1,
        64, // 675 (0x2a3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 869 (0x365)
        43, // 869 (0x365)
        -1,
        -1,
        130, // 486 (0x1e6)
        167, // 294 (0x126)
        -1,
        -1,
        29, // 295 (0x127)
        178, // 487 (0x1e7)
        -1,
        -1,
        122, // 680 (0x2a8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 490 (0x1ea)
        -1,
        -1,
        -1,
        143, // 875 (0x36b)
        -1,
        -1,
        -1,
        108, // 492 (0x1ec)
        -1,
        -1,
        -1,
        158, // 493 (0x1ed)
        -1,
        -1,
        -1,
        65, // 302 (0x12e)
        -1,
        -1,
        -1,
        81, // 303 (0x12f)
        98, // 495 (0x1ef)
        166, // 687 (0x2af)
        -1,
        -1,
        -1,
        -1,
        -1,
        66, // 305 (0x131)
        87, // 689 (0x2b1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        75, // 307 (0x133)
        -1,
        -1,
        -1,
        145, // 500 (0x1f4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 694 (0x2b6)
        -1,
        -1,
        -1,
        117, // 503 (0x1f7)
        -1,
        -1,
        -1,
        34, // 504 (0x1f8)
        191, // 696 (0x2b8)
        -1,
        -1,
        7, // 697 (0x2b9)
        154, // 505 (0x1f9)
        -1,
        -1,
        38, // 1466 (0x5ba)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 508 (0x1fc)
        54, // 508 (0x1fc)
        -1,
        -1,
        48, // 317 (0x13d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        25, // 511 (0x1ff)
        -1,
        -1,
        -1,
        188, // 320 (0x140)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        111, // 515 (0x203)
        149, // 707 (0x2c3)
        -1,
        -1,
        100, // 516 (0x204)
        -1,
        -1,
        -1,
        113, // 517 (0x205)
        -1,
        -1,
        -1,
        36, // 518 (0x206)
        39, // 518 (0x206)
        76, // 518 (0x206)
        118, // 518 (0x206)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 521 (0x209)
        -1,
        -1,
        -1,
        107, // 522 (0x20a)
        164, // 2250 (0x8ca)
        185, // 522 (0x20a)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 716 (0x2cc)
        104, // 524 (0x20c)
        -1,
        -1,
        42, // 525 (0x20d)
        181, // 525 (0x20d)
        -1,
        -1,
        27, // 718 (0x2ce)
        99, // 526 (0x20e)
        133, // 526 (0x20e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        134, // 722 (0x2d2)
        -1,
        -1,
        -1,
        4, // 531 (0x213)
        15, // 531 (0x213)
        55, // 723 (0x2d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        103, // 533 (0x215)
        -1,
        -1,
        -1,
        141, // 534 (0x216)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 537 (0x219)
        126, // 537 (0x219)
        -1,
        -1,
        110, // 538 (0x21a)
        114, // 538 (0x21a)
        152, // 1306 (0x51a)
        -1,
        96, // 539 (0x21b)
        162, // 1499 (0x5db)
        -1,
        -1,
        59, // 540 (0x21c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 544 (0x220)
        101, // 544 (0x220)
        144, // 1312 (0x520)
        -1,
        102, // 737 (0x2e1)
        -1,
        -1,
        -1,
        62, // 738 (0x2e2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        19, // 356 (0x164)
        49, // 548 (0x224)
        176, // 1124 (0x464)
        -1,
        24, // 549 (0x225)
        116, // 549 (0x225)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        61, // 360 (0x168)
        -1,
        -1,
        -1,
        10, // 553 (0x229)
        -1,
        -1,
        -1,
        63, // 362 (0x16a)
        174, // 1130 (0x46a)
        183, // 362 (0x16a)
        -1,
        8, // 1707 (0x6ab)
        179, // 555 (0x22b)
        -1,
        -1,
        17, // 364 (0x16c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        68, // 367 (0x16f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 369 (0x171)
        93, // 945 (0x3b1)
        165, // 1329 (0x531)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        125, // 372 (0x174)
        156, // 372 (0x174)
        170, // 756 (0x2f4)
        -1,
        30, // 757 (0x2f5)
        80, // 373 (0x175)
        -1,
        -1,
        26, // 374 (0x176)
        175, // 374 (0x176)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        60, // 568 (0x238)
        85, // 1336 (0x538)
        173, // 376 (0x178)
        -1,
        190, // 569 (0x239)
        -1,
        -1,
        -1,
        21, // 954 (0x3ba)
        35, // 378 (0x17a)
        70, // 762 (0x2fa)
        -1,
        11, // 379 (0x17b)
        40, // 763 (0x2fb)
        -1,
        -1,
        58, // 380 (0x17c)
        90, // 764 (0x2fc)
        -1,
        -1,
        23, // 381 (0x17d)
        -1,
        -1,
        -1,
        84, // 382 (0x17e)
        177, // 382 (0x17e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 4; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash_sumN, dataset=countries, type=hash, hash=hash_sumN
void check_countries_hash_sumN() {
    assert(lookup_countries_hash_sumN("SUDAN") == 45);
    assert(lookup_countries_hash_sumN("SPAIN") == 138);
    assert(lookup_countries_hash_sumN("YEMEN") == 97);
    assert(lookup_countries_hash_sumN("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash_sumN("BARBADOS") == 146);
    assert(lookup_countries_hash_sumN("ITALY") == 119);
    assert(lookup_countries_hash_sumN("MONTENEGRO") == 128);
    assert(lookup_countries_hash_sumN("UZBEKISTAN") == 95);
    assert(lookup_countries_hash_sumN("DOMINICA") == 151);
    assert(lookup_countries_hash_sumN("SYRIA") == 89);
    assert(lookup_countries_hash_sumN("THAILAND") == 91);
    assert(lookup_countries_hash_sumN("EGYPT") == 13);
    assert(lookup_countries_hash_sumN("COLOMBIA") == 184);
    assert(lookup_countries_hash_sumN("BULGARIA") == 106);
    assert(lookup_countries_hash_sumN("NAURU") == 171);
    assert(lookup_countries_hash_sumN("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash_sumN("LUXEMBOURG") == 123);
    assert(lookup_countries_hash_sumN("NEW ZEALAND") == 172);
    assert(lookup_countries_hash_sumN("KIRIBATI") == 168);
    assert(lookup_countries_hash_sumN("EL SALVADOR") == 153);
    assert(lookup_countries_hash_sumN("SAINT LUCIA") == 163);
    assert(lookup_countries_hash_sumN("ZIMBABWE") == 52);
    assert(lookup_countries_hash_sumN("MALAYSIA") == 77);
    assert(lookup_countries_hash_sumN("ETHIOPIA") == 16);
    assert(lookup_countries_hash_sumN("CAMEROON") == 6);
    assert(lookup_countries_hash_sumN("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash_sumN("MALDIVES") == 78);
    assert(lookup_countries_hash_sumN("TANZANIA") == 47);
    assert(lookup_countries_hash_sumN("MONGOLIA") == 79);
    assert(lookup_countries_hash_sumN("CANADA") == 148);
    assert(lookup_countries_hash_sumN("DJIBOUTI") == 12);
    assert(lookup_countries_hash_sumN("SLOVAKIA") == 136);
    assert(lookup_countries_hash_sumN("PARAGUAY") == 187);
    assert(lookup_countries_hash_sumN("PAKISTAN") == 82);
    assert(lookup_countries_hash_sumN("BOTSWANA") == 3);
    assert(lookup_countries_hash_sumN("GAMBIA") == 18);
    assert(lookup_countries_hash_sumN("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash_sumN("SLOVENIA") == 137);
    assert(lookup_countries_hash_sumN("HONDURAS") == 157);
    assert(lookup_countries_hash_sumN("SURINAME") == 189);
    assert(lookup_countries_hash_sumN("AFGHANISTAN") == 53);
    assert(lookup_countries_hash_sumN("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash_sumN("GREECE") == 115);
    assert(lookup_countries_hash_sumN("PANAMA") == 161);
    assert(lookup_countries_hash_sumN("FRANCE") == 112);
    assert(lookup_countries_hash_sumN("UGANDA") == 50);
    assert(lookup_countries_hash_sumN("PORTUGAL") == 132);
    assert(lookup_countries_hash_sumN("ANGOLA") == 1);
    assert(lookup_countries_hash_sumN("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash_sumN("ZAMBIA") == 51);
    assert(lookup_countries_hash_sumN("SERBIA") == 135);
    assert(lookup_countries_hash_sumN("IVORY COAST") == 22);
    assert(lookup_countries_hash_sumN("SRI LANKA") == 88);
    assert(lookup_countries_hash_sumN("GUINEA") == 20);
    assert(lookup_countries_hash_sumN("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash_sumN("MALAWI") == 28);
    assert(lookup_countries_hash_sumN("BELIZE") == 147);
    assert(lookup_countries_hash_sumN("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash_sumN("RWANDA") == 37);
    assert(lookup_countries_hash_sumN("MONACO") == 127);
    assert(lookup_countries_hash_sumN("NETHERLANDS") == 129);
    assert(lookup_countries_hash_sumN("JORDAN") == 69);
    assert(lookup_countries_hash_sumN("POLAND") == 131);
    assert(lookup_countries_hash_sumN("ISRAEL") == 67);
    assert(lookup_countries_hash_sumN("LATVIA") == 120);
    assert(lookup_countries_hash_sumN("BHUTAN") == 56);
    assert(lookup_countries_hash_sumN("MACEDONIA") == 124);
    assert(lookup_countries_hash_sumN("BRAZIL") == 182);
    assert(lookup_countries_hash_sumN("BRUNEI") == 57);
    assert(lookup_countries_hash_sumN("MEXICO") == 159);
    assert(lookup_countries_hash_sumN("GUYANA") == 186);
    assert(lookup_countries_hash_sumN("SWEDEN") == 139);
    assert(lookup_countries_hash_sumN("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash_sumN("PHILIPPINES") == 83);
    assert(lookup_countries_hash_sumN("CHAD") == 9);
    assert(lookup_countries_hash_sumN("NICARAGUA") == 160);
    assert(lookup_countries_hash_sumN("KOREA, NORTH") == 71);
    assert(lookup_countries_hash_sumN("GUATEMALA") == 155);
    assert(lookup_countries_hash_sumN("KUWAIT") == 73);
    assert(lookup_countries_hash_sumN("KOREA, SOUTH") == 72);
    assert(lookup_countries_hash_sumN("CUBA") == 150);
    assert(lookup_countries_hash_sumN("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash_sumN("SWITZERLAND") == 140);
    assert(lookup_countries_hash_sumN("ARGENTINA") == 180);
    assert(lookup_countries_hash_sumN("INDONESIA") == 64);
    assert(lookup_countries_hash_sumN("SIERRA LEONE") == 41);
    assert(lookup_countries_hash_sumN("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash_sumN("NORWAY") == 130);
    assert(lookup_countries_hash_sumN("FIJI") == 167);
    assert(lookup_countries_hash_sumN("MALI") == 29);
    assert(lookup_countries_hash_sumN("TUVALU") == 178);
    assert(lookup_countries_hash_sumN("LITHUANIA") == 122);
    assert(lookup_countries_hash_sumN("TURKEY") == 92);
    assert(lookup_countries_hash_sumN("VATICAN CITY") == 143);
    assert(lookup_countries_hash_sumN("CYPRUS") == 108);
    assert(lookup_countries_hash_sumN("JAMAICA") == 158);
    assert(lookup_countries_hash_sumN("IRAN") == 65);
    assert(lookup_countries_hash_sumN("OMAN") == 81);
    assert(lookup_countries_hash_sumN("ALBANIA") == 98);
    assert(lookup_countries_hash_sumN("AUSTRALIA") == 166);
    assert(lookup_countries_hash_sumN("IRAQ") == 66);
    assert(lookup_countries_hash_sumN("SINGAPORE") == 87);
    assert(lookup_countries_hash_sumN("LAOS") == 75);
    assert(lookup_countries_hash_sumN("BAHAMAS") == 145);
    assert(lookup_countries_hash_sumN("SWAZILAND") == 46);
    assert(lookup_countries_hash_sumN("ICELAND") == 117);
    assert(lookup_countries_hash_sumN("NAMIBIA") == 34);
    assert(lookup_countries_hash_sumN("VENEZUELA") == 191);
    assert(lookup_countries_hash_sumN("CAPE VERDE") == 7);
    assert(lookup_countries_hash_sumN("GRENADA") == 154);
    assert(lookup_countries_hash_sumN("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash_sumN("ALGERIA") == 0);
    assert(lookup_countries_hash_sumN("BAHRAIN") == 54);
    assert(lookup_countries_hash_sumN("TOGO") == 48);
    assert(lookup_countries_hash_sumN("LIBERIA") == 25);
    assert(lookup_countries_hash_sumN("PERU") == 188);
    assert(lookup_countries_hash_sumN("FINLAND") == 111);
    assert(lookup_countries_hash_sumN("COSTA RICA") == 149);
    assert(lookup_countries_hash_sumN("ARMENIA") == 100);
    assert(lookup_countries_hash_sumN("GEORGIA") == 113);
    assert(lookup_countries_hash_sumN("NIGERIA") == 36);
    assert(lookup_countries_hash_sumN("SENEGAL") == 39);
    assert(lookup_countries_hash_sumN("LEBANON") == 76);
    assert(lookup_countries_hash_sumN("IRELAND") == 118);
    assert(lookup_countries_hash_sumN("DENMARK") == 109);
    assert(lookup_countries_hash_sumN("CROATIA") == 107);
    assert(lookup_countries_hash_sumN("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash_sumN("ECUADOR") == 185);
    assert(lookup_countries_hash_sumN("MAURITIUS") == 31);
    assert(lookup_countries_hash_sumN("BELGIUM") == 104);
    assert(lookup_countries_hash_sumN("SOMALIA") == 42);
    assert(lookup_countries_hash_sumN("BOLIVIA") == 181);
    assert(lookup_countries_hash_sumN("MADAGASCAR") == 27);
    assert(lookup_countries_hash_sumN("ANDORRA") == 99);
    assert(lookup_countries_hash_sumN("ROMANIA") == 133);
    assert(lookup_countries_hash_sumN("SAN MARINO") == 134);
    assert(lookup_countries_hash_sumN("BURKINA") == 4);
    assert(lookup_countries_hash_sumN("ERITREA") == 15);
    assert(lookup_countries_hash_sumN("BANGLADESH") == 55);
    assert(lookup_countries_hash_sumN("BELARUS") == 103);
    assert(lookup_countries_hash_sumN("UKRAINE") == 141);
    assert(lookup_countries_hash_sumN("MOROCCO") == 32);
    assert(lookup_countries_hash_sumN("MOLDOVA") == 126);
    assert(lookup_countries_hash_sumN("ESTONIA") == 110);
    assert(lookup_countries_hash_sumN("GERMANY") == 114);
    assert(lookup_countries_hash_sumN("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash_sumN("VIETNAM") == 96);
    assert(lookup_countries_hash_sumN("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash_sumN("MYANMAR") == 59);
    assert(lookup_countries_hash_sumN("BURUNDI") == 5);
    assert(lookup_countries_hash_sumN("AUSTRIA") == 101);
    assert(lookup_countries_hash_sumN("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash_sumN("AZERBAIJAN") == 102);
    assert(lookup_countries_hash_sumN("EAST TIMOR") == 62);
    assert(lookup_countries_hash_sumN("GHANA") == 19);
    assert(lookup_countries_hash_sumN("TUNISIA") == 49);
    assert(lookup_countries_hash_sumN("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash_sumN("LESOTHO") == 24);
    assert(lookup_countries_hash_sumN("HUNGARY") == 116);
    assert(lookup_countries_hash_sumN("CHINA") == 61);
    assert(lookup_countries_hash_sumN("COMOROS") == 10);
    assert(lookup_countries_hash_sumN("INDIA") == 63);
    assert(lookup_countries_hash_sumN("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash_sumN("CHILE") == 183);
    assert(lookup_countries_hash_sumN("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash_sumN("VANUATU") == 179);
    assert(lookup_countries_hash_sumN("GABON") == 17);
    assert(lookup_countries_hash_sumN("JAPAN") == 68);
    assert(lookup_countries_hash_sumN("BENIN") == 2);
    assert(lookup_countries_hash_sumN("TURKMENISTAN") == 93);
    assert(lookup_countries_hash_sumN("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash_sumN("MALTA") == 125);
    assert(lookup_countries_hash_sumN("HAITI") == 156);
    assert(lookup_countries_hash_sumN("MICRONESIA") == 170);
    assert(lookup_countries_hash_sumN("MAURITANIA") == 30);
    assert(lookup_countries_hash_sumN("NEPAL") == 80);
    assert(lookup_countries_hash_sumN("LIBYA") == 26);
    assert(lookup_countries_hash_sumN("SAMOA") == 175);
    assert(lookup_countries_hash_sumN("CAMBODIA") == 60);
    assert(lookup_countries_hash_sumN("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash_sumN("PALAU") == 173);
    assert(lookup_countries_hash_sumN("URUGUAY") == 190);
    assert(lookup_countries_hash_sumN("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash_sumN("NIGER") == 35);
    assert(lookup_countries_hash_sumN("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash_sumN("CONGO") == 11);
    assert(lookup_countries_hash_sumN("SEYCHELLES") == 40);
    assert(lookup_countries_hash_sumN("BURMA") == 58);
    assert(lookup_countries_hash_sumN("TAJIKISTAN") == 90);
    assert(lookup_countries_hash_sumN("KENYA") == 23);
    assert(lookup_countries_hash_sumN("QATAR") == 84);
    assert(lookup_countries_hash_sumN("TONGA") == 177);
}

//lookup: name=lookup_countries_hash_djb2, dataset=countries, type=hash, hash=hash_djb2
int lookup_countries_hash_djb2(std::string_view s) {
    const uint64_t idx = (hash_djb2(s) % 557) * 2;
    constexpr const std::string_view lookup[1114] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOMALIA", // 233702063231471 (0xd48d007651ef)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LIBYA", // 214593917306 (0x31f6cb517a)
        "GERMANY", // 233686180610972 (0xd4894dc8c39c)
        "ARMENIA", // 233678934360134 (0xd4879ddfc046)
        "",
        "VIETNAM", // 233705694020381 (0xd48dd8dfc31d)
        "",
        "",
        "",
        "",
        "",
        "MAURITIUS", // 254492522743055372 (0x3882399e017c40c)
        "ZIMBABWE", // 7712458667715354 (0x1b6670b73beb1a)
        "",
        "",
        "",
        "",
        "GAMBIA", // 7081394477354 (0x670c400992a)
        "",
        "LEBANON", // 233692618559016 (0xd48acd840e28)
        "ANTIGUA AND BARBUDA", // 2697843713614760758 (0x2570aa9051874b36)
        "",
        "",
        "",
        "",
        "",
        "",
        "GUYANA", // 7081418626094 (0x670c571142e)
        "",
        "",
        "",
        "ETHIOPIA", // 7711577699702876 (0x1b65a39972d85c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MONTENEGRO", // 8398272644331501703 (0x748ca8795c427887)
        "SAINT KITTS AND NEVIS", // 8101194521765875087 (0x706d397ede320d8f)
        "",
        "",
        "",
        "",
        "",
        "",
        "PAPUA NEW GUINEA", // 15352752483354764707 (0xd50fef0a8edb65a3)
        "",
        "HUNGARY", // 233688093286055 (0xd489bfc9dea7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VENEZUELA", // 254505341365547480 (0x3882f42718871d8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SWAZILAND", // 254501873283937622 (0x3882c1af7c2b556)
        "",
        "",
        "",
        "",
        "",
        "SAUDI ARABIA", // 14862706212841011359 (0xce42f08df961389f)
        "",
        "",
        "",
        "",
        "",
        "BOSNIA AND HERZEGOVINA", // 2357854173977438074 (0x20b8c7e0f818e77a)
        "",
        "",
        "",
        "TUNISIA", // 233703590992838 (0xd48d5b861bc6)
        "",
        "PANAMA", // 7081746730871 (0x670d8ff8f77)
        "",
        "",
        "",
        "",
        "",
        "SLOVENIA", // 7712164315163978 (0x1b662c2e746d4a)
        "",
        "PORTUGAL", // 7712040449840407 (0x1b660f57819517)
        "",
        "",
        "",
        "CUBA", // 6502535588 (0x18394d1a4)
        "",
        "",
        "",
        "CAMEROON", // 7711468115965725 (0x1b658a15bfb71d)
        "UGANDA", // 7081949070041 (0x670e50f02d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "THAILAND", // 7712201204660174 (0x1b6634c53d77ce)
        "",
        "ECUADOR", // 233683522534060 (0xd488af59baac)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VANUATU", // 233705391632941 (0xd48dc6d9b22d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "FINLAND", // 233685040904933 (0xd48909da3ae5)
        "",
        "",
        "",
        "IRELAND", // 233689256854088 (0xd48a05248248)
        "",
        "BOTSWANA", // 7711443868789352 (0x1b658470812a68)
        "",
        "MONACO", // 7081645927270 (0x670d2fd6b66)
        "",
        "",
        "",
        "UNITED ARAB EMIRATES", // 13227005159675093698 (0xb78fc31cf0b162c2)
        "",
        "",
        "",
        "",
        "",
        "NEPAL", // 214596159865 (0x31f6ed8979)
        "SLOVAKIA", // 7712164315016963 (0x1b662c2e722f03)
        "",
        "",
        "",
        "",
        "",
        "",
        "NORWAY", // 7081685230313 (0x670d55522e9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NIGERIA", // 233695364114024 (0xd48b7129e668)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "COLOMBIA", // 7711486169047055 (0x1b658e49cbe00f)
        "",
        "TAJIKISTAN", // 8398577650551139899 (0x748dbde027a2ae3b)
        "",
        "",
        "",
        "CANADA", // 7081237970465 (0x670baac7e21)
        "",
        "",
        "",
        "",
        "",
        "KIRIBATI", // 7711819595083864 (0x1b65dbeb897058)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DOMINICAN REPUBLIC", // 10611873900262964113 (0x9344f3169269bb91)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MALDIVES", // 7711894259758046 (0x1b65ed4de5f3de)
        "",
        "INDIA", // 214590540878 (0x31f697cc4e)
        "",
        "",
        "",
        "",
        "",
        "CAPE VERDE", // 8397788904193182552 (0x748af083d526cb58)
        "SOLOMON ISLANDS", // 13846990923427813118 (0xc02a64e15ef916fe)
        "",
        "",
        "",
        "",
        "",
        "",
        "BAHRAIN", // 233679555049854 (0xd487c2deb97e)
        "",
        "",
        "",
        "",
        "",
        "COMOROS", // 233681400253835 (0xd48830da4d8b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MARSHALL ISLANDS", // 13846202505931840139 (0xc02797d19e30da8b)
        "",
        "",
        "",
        "EL SALVADOR", // 429379548321865654 (0x5f5766c9b8adfb6)
        "",
        "",
        "",
        "MALTA", // 214594826456 (0x31f6d930d8)
        "",
        "",
        "",
        "TURKMENISTAN", // 14943750728223988782 (0xcf62de1ca7c69c2e)
        "URUGUAY", // 233704773286139 (0xd48da1fe78fb)
        "",
        "",
        "BANGLADESH", // 8397742411751833938 (0x748ac63af7b34152)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BENIN", // 214581926901 (0x31f6145bf5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MOROCCO", // 233694320846395 (0xd48b32fae63b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "QATAR", // 214599578242 (0x31f721b282)
        "",
        "",
        "",
        "GHANA", // 214587950312 (0x31f67044e8)
        "KENYA", // 214592600705 (0x31f6b73a81)
        "BARBADOS", // 7711425689019047 (0x1b658034e7e2a7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HONDURAS", // 7711699326792269 (0x1b65bfeafcf24d)
        "",
        "EQUATORIAL GUINEA", // 18150271316864093881 (0xfbe2b79932a54eb9)
        "",
        "BURKINA", // 233680349374229 (0xd487f2372715)
        "CAMBODIA", // 7711468112287961 (0x1b658a158798d9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IVORY COAST", // 436036066944798780 (0x60d1c7e1f80d03c)
        "",
        "IRAN", // 6502747923 (0x183980f13)
        "",
        "",
        "",
        "SAN MARINO", // 8398531356659059057 (0x748d93c584a48971)
        "",
        "IRAQ", // 6502747926 (0x183980f16)
        "",
        "",
        "",
        "CHILE", // 214583215278 (0x31f62804ae)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NICARAGUA", // 254494246197480596 (0x388252b25fb4c94)
        "",
        "",
        "",
        "",
        "",
        "TANZANIA", // 7712192692923839 (0x1b6632c9e6adbf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH SUDAN", // 451035478159462551 (0x6426660b0cb1097)
        "ANDORRA", // 233678767509296 (0xd48793edcf30)
        "",
        "",
        "",
        "",
        "BRUNEI", // 7081219261486 (0x670b98f042e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SEYCHELLES", // 8398537496106637754 (0x748d995af83c19ba)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LITHUANIA", // 254491455612712328 (0x38822a16a2af588)
        "",
        "UNITED KINGDOM", // 9746439861154065819 (0x87424f6a34cbad9b)
        "",
        "",
        "",
        "",
        "",
        "SAO TOME AND PRINCIPE", // 8279457700207647278 (0x72e68ae971bfda2e)
        "",
        "MOLDOVA", // 233694313349243 (0xd48b3288807b)
        "",
        "",
        "",
        "BAHAMAS", // 233679554451734 (0xd487c2d59916)
        "",
        "",
        "",
        "",
        "",
        "MYANMAR", // 233694692014558 (0xd48b491a79de)
        "",
        "",
        "",
        "KAZAKHSTAN", // 8398160618753680281 (0x748c42965f7ce399)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VATICAN CITY", // 15014292940298210120 (0xd05d7be14c214b48)
        "",
        "",
        "",
        "MACEDONIA", // 254492498981767562 (0x388239457cf498a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALBANIA", // 233678686358897 (0xd4878f178d71)
        "CYPRUS", // 7081266523535 (0x670bc602d8f)
        "",
        "",
        "",
        "",
        "CHINA", // 214583215340 (0x31f62804ec)
        "",
        "MICRONESIA", // 8398263734885350259 (0x748ca05ef7e2fb73)
        "",
        "",
        "",
        "",
        "",
        "AUSTRIA", // 233679059425250 (0xd487a55417e2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CONGO", // 214583472127 (0x31f62befff)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SERBIA", // 7081869025439 (0x670e049a09f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BELGIUM", // 233679715948910 (0xd487cc75d96e)
        "",
        "NAMIBIA", // 233695058272730 (0xd48b5eef21da)
        "",
        "",
        "",
        "LAOS", // 6502837688 (0x183996db8)
        "",
        "GUINEA-BISSAU", // 10278952053202876278 (0x8ea62c6ea26df776)
        "GREECE", // 7081414353588 (0x670c52fe2b4)
        "SRI LANKA", // 254501668256790206 (0x3882beb3b30b6be)
        "BOLIVIA", // 233680107388463 (0xd487e3cabe2f)
        "",
        "",
        "",
        "",
        "MALAYSIA", // 7711894256772122 (0x1b65ed4db8641a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TONGA", // 214603632770 (0x31f75f9082)
        "",
        "",
        "",
        "",
        "",
        "SYRIA", // 214602810641 (0x31f7530511)
        "",
        "",
        "",
        "",
        "",
        "TOGO", // 6503140162 (0x1839e0b42)
        "",
        "KOREA, NORTH", // 14479673311734692562 (0xc8f2222911a67ad2)
        "",
        "",
        "",
        "",
        "",
        "PALAU", // 214598383612 (0x31f70f77fc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PERU", // 6502985893 (0x1839bb0a5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BELIZE", // 7081203516324 (0x670b89ec3a4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AUSTRALIA", // 254476495713824207 (0x38815064ab56dcf)
        "",
        "",
        "",
        "",
        "",
        "MALAWI", // 7081629253156 (0x670d1fefe24)
        "",
        "SWITZERLAND", // 451389917824180064 (0x643a8bd1b1a5f60)
        "",
        "ZAMBIA", // 7082138049821 (0x670f0529d1d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EGYPT", // 214585568754 (0x31f64bedf2)
        "BURMA", // 214582506368 (0x31f61d3380)
        "JAPAN", // 214591272435 (0x31f6a2f5f3)
        "",
        "",
        "",
        "AFGHANISTAN", // 423029144671152429 (0x5dee6c409c2e92d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DOMINICA", // 7711528819553261 (0x1b659837f6f3ed)
        "",
        "SWEDEN", // 7081889906895 (0x670e18840cf)
        "NEW ZEALAND", // 442914089720082578 (0x6258c0497c7f092)
        "SUDAN", // 214602651396 (0x31f7509704)
        "",
        "",
        "",
        "",
        "",
        "SINGAPORE", // 254501292661918833 (0x3882b93c7fdcc71)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GUINEA", // 7081418064962 (0x670c5688442)
        "",
        "SPAIN", // 214602468708 (0x31f74dcd64)
        "SURINAME", // 7712176040674317 (0x1b662ee959840d)
        "GUATEMALA", // 254484910904112602 (0x3881cad9b22f5da)
        "",
        "UZBEKISTAN", // 8398658876137582185 (0x748e07bff5dcae69)
        "",
        "",
        "",
        "CHAD", // 6502521401 (0x183949a39)
        "",
        "",
        "",
        "BHUTAN", // 7081207408683 (0x670b8da282b)
        "SAMOA", // 214601942906 (0x31f745c77a)
        "GEORGIA", // 233686177239239 (0xd4894d9550c7)
        "",
        "PARAGUAY", // 7712022346268483 (0x1b660b2072ff43)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "OMAN", // 6502958100 (0x1839b4414)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIERRA LEONE", // 14874236375579355426 (0xce6be72d2f99e922)
        "RUSSIAN FEDERATION", // 6024590181781515695 (0x539ba4d9c664adaf)
        "",
        "",
        "BULGARIA", // 7711451289510704 (0x1b65862ad06330)
        "",
        "LIBERIA", // 233692775248481 (0xd48ad6daf261)
        "PAKISTAN", // 7712022082238244 (0x1b660b10b63724)
        "MONGOLIA", // 7711912422343007 (0x1b65f18879015f)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KYRGYZSTAN", // 8398194039931024143 (0x748c60fbd8e4330f)
        "ITALY", // 214590753356 (0x31f69b0a4c)
        "",
        "",
        "BRAZIL", // 7081218555949 (0x670b984402d)
        "",
        "",
        "",
        "BURUNDI", // 233680349738722 (0xd487f23cb6e2)
        "",
        "FIJI", // 6502630603 (0x1839644cb)
        "",
        "GABON", // 214587699888 (0x31f66c72b0)
        "GRENADA", // 233686673989691 (0xd4896b31203b)
        "ERITREA", // 233684096031605 (0xd488d1889b75)
        "",
        "LESOTHO", // 233692639229095 (0xd48acebf74a7)
        "SENEGAL", // 233701673201512 (0xd48ce936ef68)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SAINT LUCIA", // 450368600253071798 (0x64007db141301b6)
        "",
        "ISRAEL", // 7081494273193 (0x670c9f35ca9)
        "",
        "",
        "",
        "ICELAND", // 233688669823193 (0xd489e22720d9)
        "",
        "",
        "",
        "",
        "",
        "ARGENTINA", // 254476351769784770 (0x38814e4c6f9b1c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CENTRAL AFRICAN REPUBLIC", // 205063864518748092 (0x2d8887f90e8a7bc)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH AFRICA", // 14884170778540549826 (0xce8f32769f28a6c2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "AZERBAIJAN", // 8397730790731879488 (0x748abba93cef1440)
        "MEXICO", // 7081634436142 (0x670d24e142e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "TUVALU", // 7081927278346 (0x670e3c27f0a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HAITI", // 214588893592 (0x31f67ea998)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MALI", // 6502873516 (0x18399f9ac)
        "",
        "",
        "",
        "TRINIDAD AND TOBAGO", // 2093761886293560615 (0x1d0e8957a4c78d27)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MAURITANIA", // 8398253250520531892 (0x748c96d5e30bc3b4)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CROATIA", // 233681519530700 (0xd48837f652cc)
        "",
        "",
        "",
        "LUXEMBOURG", // 8398235078410446131 (0x748c864edce12533)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "POLAND", // 7081763261927 (0x670d9fbcde7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UKRAINE", // 233704495552344 (0xd48d91709758)
        "",
        "",
        "",
        "TURKEY", // 7081927145261 (0x670e3c0772d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KUWAIT", // 7081575095646 (0x670cec49d5e)
        "JAMAICA", // 233689892120783 (0xd48a2b01e8cf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "YEMEN", // 214609201863 (0x31f7b48ac7)
        "",
        "",
        "",
        "",
        "",
        "LIECHTENSTEIN", // 18005262567986607416 (0xf9df8ae8dc7ab538)
        "NAURU", // 214596022132 (0x31f6eb6f74)
        "JORDAN", // 7081528668039 (0x670cc002f87)
        "",
        "NIGER", // 214596293950 (0x31f6ef953e)
        "ESTONIA", // 233684148028220 (0xd488d4a2033c)
        "",
        "",
        "SAINT VINCENT AND THE GRENADINES", // 16166763452833851475 (0xe05be1b485ede853)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DENMARK", // 233682301463499 (0xd4886691abcb)
        "",
        "DJIBOUTI", // 7711522197419971 (0x1b6596ad4137c3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LATVIA", // 7081590427658 (0x670cfae900a)
        "",
        "MADAGASCAR", // 8398252503951877165 (0x748c96281016242d)
        "",
        "",
        "",
        "EAST TIMOR", // 8397881874387101761 (0x748b45122488e841)
        "",
        "",
        "",
        "INDONESIA", // 254487429081380483 (0x3881ef7ea32b683)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ANGOLA", // 7081174880603 (0x670b6e9d15b)
        "",
        "",
        "",
        "NETHERLANDS", // 442911548632543361 (0x62589b4f3293081)
        "",
        "",
        "",
        "ALGERIA", // 233678692436606 (0xd4878f744a7e)
        "",
        "",
        "",
        "COSTA RICA", // 8397808742369071970 (0x748b028ec4941362)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PHILIPPINES", // 446098646127881678 (0x630dc5ae93c2dce)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BELARUS", // 233679715743095 (0xd487cc72b577)
        "",
        "",
        "",
        "",
        "",
        "FRANCE", // 7081375084248 (0x670c2d8aed8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "RWANDA", // 7081850638598 (0x670df311106)
        "ROMANIA", // 233700771765680 (0xd48cb37c1db0)
        "MOZAMBIQUE", // 8398273131513932835 (0x748ca8eaca986c23)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KOREA, SOUTH", // 14479673311740625434 (0xc8f222291201021a)
        "",
    };
    constexpr const int values[1114] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        42, // 233702063231471 (0xd48d007651ef)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        26, // 214593917306 (0x31f6cb517a)
        114, // 233686180610972 (0xd4894dc8c39c)
        100, // 233678934360134 (0xd4879ddfc046)
        -1,
        96, // 233705694020381 (0xd48dd8dfc31d)
        -1,
        -1,
        -1,
        -1,
        -1,
        31, // 254492522743055372 (0x3882399e017c40c)
        52, // 7712458667715354 (0x1b6670b73beb1a)
        -1,
        -1,
        -1,
        -1,
        18, // 7081394477354 (0x670c400992a)
        -1,
        76, // 233692618559016 (0xd48acd840e28)
        144, // 2697843713614760758 (0x2570aa9051874b36)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        186, // 7081418626094 (0x670c571142e)
        -1,
        -1,
        -1,
        16, // 7711577699702876 (0x1b65a39972d85c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        128, // 8398272644331501703 (0x748ca8795c427887)
        162, // 8101194521765875087 (0x706d397ede320d8f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        174, // 15352752483354764707 (0xd50fef0a8edb65a3)
        -1,
        116, // 233688093286055 (0xd489bfc9dea7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        191, // 254505341365547480 (0x3882f42718871d8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 254501873283937622 (0x3882c1af7c2b556)
        -1,
        -1,
        -1,
        -1,
        -1,
        86, // 14862706212841011359 (0xce42f08df961389f)
        -1,
        -1,
        -1,
        -1,
        -1,
        105, // 2357854173977438074 (0x20b8c7e0f818e77a)
        -1,
        -1,
        -1,
        49, // 233703590992838 (0xd48d5b861bc6)
        -1,
        161, // 7081746730871 (0x670d8ff8f77)
        -1,
        -1,
        -1,
        -1,
        -1,
        137, // 7712164315163978 (0x1b662c2e746d4a)
        -1,
        132, // 7712040449840407 (0x1b660f57819517)
        -1,
        -1,
        -1,
        150, // 6502535588 (0x18394d1a4)
        -1,
        -1,
        -1,
        6, // 7711468115965725 (0x1b658a15bfb71d)
        50, // 7081949070041 (0x670e50f02d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        91, // 7712201204660174 (0x1b6634c53d77ce)
        -1,
        185, // 233683522534060 (0xd488af59baac)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        179, // 233705391632941 (0xd48dc6d9b22d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        111, // 233685040904933 (0xd48909da3ae5)
        -1,
        -1,
        -1,
        118, // 233689256854088 (0xd48a05248248)
        -1,
        3, // 7711443868789352 (0x1b658470812a68)
        -1,
        127, // 7081645927270 (0x670d2fd6b66)
        -1,
        -1,
        -1,
        94, // 13227005159675093698 (0xb78fc31cf0b162c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        80, // 214596159865 (0x31f6ed8979)
        136, // 7712164315016963 (0x1b662c2e722f03)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        130, // 7081685230313 (0x670d55522e9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 233695364114024 (0xd48b7129e668)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        184, // 7711486169047055 (0x1b658e49cbe00f)
        -1,
        90, // 8398577650551139899 (0x748dbde027a2ae3b)
        -1,
        -1,
        -1,
        148, // 7081237970465 (0x670baac7e21)
        -1,
        -1,
        -1,
        -1,
        -1,
        168, // 7711819595083864 (0x1b65dbeb897058)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        152, // 10611873900262964113 (0x9344f3169269bb91)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        78, // 7711894259758046 (0x1b65ed4de5f3de)
        -1,
        63, // 214590540878 (0x31f697cc4e)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 8397788904193182552 (0x748af083d526cb58)
        176, // 13846990923427813118 (0xc02a64e15ef916fe)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        54, // 233679555049854 (0xd487c2deb97e)
        -1,
        -1,
        -1,
        -1,
        -1,
        10, // 233681400253835 (0xd48830da4d8b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        169, // 13846202505931840139 (0xc02797d19e30da8b)
        -1,
        -1,
        -1,
        153, // 429379548321865654 (0x5f5766c9b8adfb6)
        -1,
        -1,
        -1,
        125, // 214594826456 (0x31f6d930d8)
        -1,
        -1,
        -1,
        93, // 14943750728223988782 (0xcf62de1ca7c69c2e)
        190, // 233704773286139 (0xd48da1fe78fb)
        -1,
        -1,
        55, // 8397742411751833938 (0x748ac63af7b34152)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 214581926901 (0x31f6145bf5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 233694320846395 (0xd48b32fae63b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        84, // 214599578242 (0x31f721b282)
        -1,
        -1,
        -1,
        19, // 214587950312 (0x31f67044e8)
        23, // 214592600705 (0x31f6b73a81)
        146, // 7711425689019047 (0x1b658034e7e2a7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        157, // 7711699326792269 (0x1b65bfeafcf24d)
        -1,
        14, // 18150271316864093881 (0xfbe2b79932a54eb9)
        -1,
        4, // 233680349374229 (0xd487f2372715)
        60, // 7711468112287961 (0x1b658a158798d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        22, // 436036066944798780 (0x60d1c7e1f80d03c)
        -1,
        65, // 6502747923 (0x183980f13)
        -1,
        -1,
        -1,
        134, // 8398531356659059057 (0x748d93c584a48971)
        -1,
        66, // 6502747926 (0x183980f16)
        -1,
        -1,
        -1,
        183, // 214583215278 (0x31f62804ae)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        160, // 254494246197480596 (0x388252b25fb4c94)
        -1,
        -1,
        -1,
        -1,
        -1,
        47, // 7712192692923839 (0x1b6632c9e6adbf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        44, // 451035478159462551 (0x6426660b0cb1097)
        99, // 233678767509296 (0xd48793edcf30)
        -1,
        -1,
        -1,
        -1,
        57, // 7081219261486 (0x670b98f042e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        40, // 8398537496106637754 (0x748d995af83c19ba)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        122, // 254491455612712328 (0x38822a16a2af588)
        -1,
        142, // 9746439861154065819 (0x87424f6a34cbad9b)
        -1,
        -1,
        -1,
        -1,
        -1,
        38, // 8279457700207647278 (0x72e68ae971bfda2e)
        -1,
        126, // 233694313349243 (0xd48b3288807b)
        -1,
        -1,
        -1,
        145, // 233679554451734 (0xd487c2d59916)
        -1,
        -1,
        -1,
        -1,
        -1,
        59, // 233694692014558 (0xd48b491a79de)
        -1,
        -1,
        -1,
        70, // 8398160618753680281 (0x748c42965f7ce399)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        143, // 15014292940298210120 (0xd05d7be14c214b48)
        -1,
        -1,
        -1,
        124, // 254492498981767562 (0x388239457cf498a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        98, // 233678686358897 (0xd4878f178d71)
        108, // 7081266523535 (0x670bc602d8f)
        -1,
        -1,
        -1,
        -1,
        61, // 214583215340 (0x31f62804ec)
        -1,
        170, // 8398263734885350259 (0x748ca05ef7e2fb73)
        -1,
        -1,
        -1,
        -1,
        -1,
        101, // 233679059425250 (0xd487a55417e2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        11, // 214583472127 (0x31f62befff)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        135, // 7081869025439 (0x670e049a09f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 233679715948910 (0xd487cc75d96e)
        -1,
        34, // 233695058272730 (0xd48b5eef21da)
        -1,
        -1,
        -1,
        75, // 6502837688 (0x183996db8)
        -1,
        21, // 10278952053202876278 (0x8ea62c6ea26df776)
        115, // 7081414353588 (0x670c52fe2b4)
        88, // 254501668256790206 (0x3882beb3b30b6be)
        181, // 233680107388463 (0xd487e3cabe2f)
        -1,
        -1,
        -1,
        -1,
        77, // 7711894256772122 (0x1b65ed4db8641a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        177, // 214603632770 (0x31f75f9082)
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 214602810641 (0x31f7530511)
        -1,
        -1,
        -1,
        -1,
        -1,
        48, // 6503140162 (0x1839e0b42)
        -1,
        71, // 14479673311734692562 (0xc8f2222911a67ad2)
        -1,
        -1,
        -1,
        -1,
        -1,
        173, // 214598383612 (0x31f70f77fc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        188, // 6502985893 (0x1839bb0a5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        147, // 7081203516324 (0x670b89ec3a4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        166, // 254476495713824207 (0x38815064ab56dcf)
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 7081629253156 (0x670d1fefe24)
        -1,
        140, // 451389917824180064 (0x643a8bd1b1a5f60)
        -1,
        51, // 7082138049821 (0x670f0529d1d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 214585568754 (0x31f64bedf2)
        58, // 214582506368 (0x31f61d3380)
        68, // 214591272435 (0x31f6a2f5f3)
        -1,
        -1,
        -1,
        53, // 423029144671152429 (0x5dee6c409c2e92d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        151, // 7711528819553261 (0x1b659837f6f3ed)
        -1,
        139, // 7081889906895 (0x670e18840cf)
        172, // 442914089720082578 (0x6258c0497c7f092)
        45, // 214602651396 (0x31f7509704)
        -1,
        -1,
        -1,
        -1,
        -1,
        87, // 254501292661918833 (0x3882b93c7fdcc71)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        20, // 7081418064962 (0x670c5688442)
        -1,
        138, // 214602468708 (0x31f74dcd64)
        189, // 7712176040674317 (0x1b662ee959840d)
        155, // 254484910904112602 (0x3881cad9b22f5da)
        -1,
        95, // 8398658876137582185 (0x748e07bff5dcae69)
        -1,
        -1,
        -1,
        9, // 6502521401 (0x183949a39)
        -1,
        -1,
        -1,
        56, // 7081207408683 (0x670b8da282b)
        175, // 214601942906 (0x31f745c77a)
        113, // 233686177239239 (0xd4894d9550c7)
        -1,
        187, // 7712022346268483 (0x1b660b2072ff43)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        81, // 6502958100 (0x1839b4414)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 14874236375579355426 (0xce6be72d2f99e922)
        85, // 6024590181781515695 (0x539ba4d9c664adaf)
        -1,
        -1,
        106, // 7711451289510704 (0x1b65862ad06330)
        -1,
        25, // 233692775248481 (0xd48ad6daf261)
        82, // 7712022082238244 (0x1b660b10b63724)
        79, // 7711912422343007 (0x1b65f18879015f)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        74, // 8398194039931024143 (0x748c60fbd8e4330f)
        119, // 214590753356 (0x31f69b0a4c)
        -1,
        -1,
        182, // 7081218555949 (0x670b984402d)
        -1,
        -1,
        -1,
        5, // 233680349738722 (0xd487f23cb6e2)
        -1,
        167, // 6502630603 (0x1839644cb)
        -1,
        17, // 214587699888 (0x31f66c72b0)
        154, // 233686673989691 (0xd4896b31203b)
        15, // 233684096031605 (0xd488d1889b75)
        -1,
        24, // 233692639229095 (0xd48acebf74a7)
        39, // 233701673201512 (0xd48ce936ef68)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        163, // 450368600253071798 (0x64007db141301b6)
        -1,
        67, // 7081494273193 (0x670c9f35ca9)
        -1,
        -1,
        -1,
        117, // 233688669823193 (0xd489e22720d9)
        -1,
        -1,
        -1,
        -1,
        -1,
        180, // 254476351769784770 (0x38814e4c6f9b1c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 205063864518748092 (0x2d8887f90e8a7bc)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 14884170778540549826 (0xce8f32769f28a6c2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        102, // 8397730790731879488 (0x748abba93cef1440)
        159, // 7081634436142 (0x670d24e142e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        178, // 7081927278346 (0x670e3c27f0a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        156, // 214588893592 (0x31f67ea998)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        29, // 6502873516 (0x18399f9ac)
        -1,
        -1,
        -1,
        165, // 2093761886293560615 (0x1d0e8957a4c78d27)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        30, // 8398253250520531892 (0x748c96d5e30bc3b4)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        107, // 233681519530700 (0xd48837f652cc)
        -1,
        -1,
        -1,
        123, // 8398235078410446131 (0x748c864edce12533)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        131, // 7081763261927 (0x670d9fbcde7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        141, // 233704495552344 (0xd48d91709758)
        -1,
        -1,
        -1,
        92, // 7081927145261 (0x670e3c0772d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        73, // 7081575095646 (0x670cec49d5e)
        158, // 233689892120783 (0xd48a2b01e8cf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 214609201863 (0x31f7b48ac7)
        -1,
        -1,
        -1,
        -1,
        -1,
        121, // 18005262567986607416 (0xf9df8ae8dc7ab538)
        171, // 214596022132 (0x31f6eb6f74)
        69, // 7081528668039 (0x670cc002f87)
        -1,
        35, // 214596293950 (0x31f6ef953e)
        110, // 233684148028220 (0xd488d4a2033c)
        -1,
        -1,
        164, // 16166763452833851475 (0xe05be1b485ede853)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 233682301463499 (0xd4886691abcb)
        -1,
        12, // 7711522197419971 (0x1b6596ad4137c3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        120, // 7081590427658 (0x670cfae900a)
        -1,
        27, // 8398252503951877165 (0x748c96281016242d)
        -1,
        -1,
        -1,
        62, // 8397881874387101761 (0x748b45122488e841)
        -1,
        -1,
        -1,
        64, // 254487429081380483 (0x3881ef7ea32b683)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 7081174880603 (0x670b6e9d15b)
        -1,
        -1,
        -1,
        129, // 442911548632543361 (0x62589b4f3293081)
        -1,
        -1,
        -1,
        0, // 233678692436606 (0xd4878f744a7e)
        -1,
        -1,
        -1,
        149, // 8397808742369071970 (0x748b028ec4941362)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        83, // 446098646127881678 (0x630dc5ae93c2dce)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        103, // 233679715743095 (0xd487cc72b577)
        -1,
        -1,
        -1,
        -1,
        -1,
        112, // 7081375084248 (0x670c2d8aed8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        37, // 7081850638598 (0x670df311106)
        133, // 233700771765680 (0xd48cb37c1db0)
        33, // 8398273131513932835 (0x748ca8eaca986c23)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 14479673311740625434 (0xc8f222291201021a)
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash_djb2, dataset=countries, type=hash, hash=hash_djb2
void check_countries_hash_djb2() {
    assert(lookup_countries_hash_djb2("SOMALIA") == 42);
    assert(lookup_countries_hash_djb2("LIBYA") == 26);
    assert(lookup_countries_hash_djb2("GERMANY") == 114);
    assert(lookup_countries_hash_djb2("ARMENIA") == 100);
    assert(lookup_countries_hash_djb2("VIETNAM") == 96);
    assert(lookup_countries_hash_djb2("MAURITIUS") == 31);
    assert(lookup_countries_hash_djb2("ZIMBABWE") == 52);
    assert(lookup_countries_hash_djb2("GAMBIA") == 18);
    assert(lookup_countries_hash_djb2("LEBANON") == 76);
    assert(lookup_countries_hash_djb2("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash_djb2("GUYANA") == 186);
    assert(lookup_countries_hash_djb2("ETHIOPIA") == 16);
    assert(lookup_countries_hash_djb2("MONTENEGRO") == 128);
    assert(lookup_countries_hash_djb2("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash_djb2("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash_djb2("HUNGARY") == 116);
    assert(lookup_countries_hash_djb2("VENEZUELA") == 191);
    assert(lookup_countries_hash_djb2("SWAZILAND") == 46);
    assert(lookup_countries_hash_djb2("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash_djb2("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash_djb2("TUNISIA") == 49);
    assert(lookup_countries_hash_djb2("PANAMA") == 161);
    assert(lookup_countries_hash_djb2("SLOVENIA") == 137);
    assert(lookup_countries_hash_djb2("PORTUGAL") == 132);
    assert(lookup_countries_hash_djb2("CUBA") == 150);
    assert(lookup_countries_hash_djb2("CAMEROON") == 6);
    assert(lookup_countries_hash_djb2("UGANDA") == 50);
    assert(lookup_countries_hash_djb2("THAILAND") == 91);
    assert(lookup_countries_hash_djb2("ECUADOR") == 185);
    assert(lookup_countries_hash_djb2("VANUATU") == 179);
    assert(lookup_countries_hash_djb2("FINLAND") == 111);
    assert(lookup_countries_hash_djb2("IRELAND") == 118);
    assert(lookup_countries_hash_djb2("BOTSWANA") == 3);
    assert(lookup_countries_hash_djb2("MONACO") == 127);
    assert(lookup_countries_hash_djb2("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash_djb2("NEPAL") == 80);
    assert(lookup_countries_hash_djb2("SLOVAKIA") == 136);
    assert(lookup_countries_hash_djb2("NORWAY") == 130);
    assert(lookup_countries_hash_djb2("NIGERIA") == 36);
    assert(lookup_countries_hash_djb2("COLOMBIA") == 184);
    assert(lookup_countries_hash_djb2("TAJIKISTAN") == 90);
    assert(lookup_countries_hash_djb2("CANADA") == 148);
    assert(lookup_countries_hash_djb2("KIRIBATI") == 168);
    assert(lookup_countries_hash_djb2("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash_djb2("MALDIVES") == 78);
    assert(lookup_countries_hash_djb2("INDIA") == 63);
    assert(lookup_countries_hash_djb2("CAPE VERDE") == 7);
    assert(lookup_countries_hash_djb2("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash_djb2("BAHRAIN") == 54);
    assert(lookup_countries_hash_djb2("COMOROS") == 10);
    assert(lookup_countries_hash_djb2("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash_djb2("EL SALVADOR") == 153);
    assert(lookup_countries_hash_djb2("MALTA") == 125);
    assert(lookup_countries_hash_djb2("TURKMENISTAN") == 93);
    assert(lookup_countries_hash_djb2("URUGUAY") == 190);
    assert(lookup_countries_hash_djb2("BANGLADESH") == 55);
    assert(lookup_countries_hash_djb2("BENIN") == 2);
    assert(lookup_countries_hash_djb2("MOROCCO") == 32);
    assert(lookup_countries_hash_djb2("QATAR") == 84);
    assert(lookup_countries_hash_djb2("GHANA") == 19);
    assert(lookup_countries_hash_djb2("KENYA") == 23);
    assert(lookup_countries_hash_djb2("BARBADOS") == 146);
    assert(lookup_countries_hash_djb2("HONDURAS") == 157);
    assert(lookup_countries_hash_djb2("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash_djb2("BURKINA") == 4);
    assert(lookup_countries_hash_djb2("CAMBODIA") == 60);
    assert(lookup_countries_hash_djb2("IVORY COAST") == 22);
    assert(lookup_countries_hash_djb2("IRAN") == 65);
    assert(lookup_countries_hash_djb2("SAN MARINO") == 134);
    assert(lookup_countries_hash_djb2("IRAQ") == 66);
    assert(lookup_countries_hash_djb2("CHILE") == 183);
    assert(lookup_countries_hash_djb2("NICARAGUA") == 160);
    assert(lookup_countries_hash_djb2("TANZANIA") == 47);
    assert(lookup_countries_hash_djb2("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash_djb2("ANDORRA") == 99);
    assert(lookup_countries_hash_djb2("BRUNEI") == 57);
    assert(lookup_countries_hash_djb2("SEYCHELLES") == 40);
    assert(lookup_countries_hash_djb2("LITHUANIA") == 122);
    assert(lookup_countries_hash_djb2("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash_djb2("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash_djb2("MOLDOVA") == 126);
    assert(lookup_countries_hash_djb2("BAHAMAS") == 145);
    assert(lookup_countries_hash_djb2("MYANMAR") == 59);
    assert(lookup_countries_hash_djb2("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash_djb2("VATICAN CITY") == 143);
    assert(lookup_countries_hash_djb2("MACEDONIA") == 124);
    assert(lookup_countries_hash_djb2("ALBANIA") == 98);
    assert(lookup_countries_hash_djb2("CYPRUS") == 108);
    assert(lookup_countries_hash_djb2("CHINA") == 61);
    assert(lookup_countries_hash_djb2("MICRONESIA") == 170);
    assert(lookup_countries_hash_djb2("AUSTRIA") == 101);
    assert(lookup_countries_hash_djb2("CONGO") == 11);
    assert(lookup_countries_hash_djb2("SERBIA") == 135);
    assert(lookup_countries_hash_djb2("BELGIUM") == 104);
    assert(lookup_countries_hash_djb2("NAMIBIA") == 34);
    assert(lookup_countries_hash_djb2("LAOS") == 75);
    assert(lookup_countries_hash_djb2("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash_djb2("GREECE") == 115);
    assert(lookup_countries_hash_djb2("SRI LANKA") == 88);
    assert(lookup_countries_hash_djb2("BOLIVIA") == 181);
    assert(lookup_countries_hash_djb2("MALAYSIA") == 77);
    assert(lookup_countries_hash_djb2("TONGA") == 177);
    assert(lookup_countries_hash_djb2("SYRIA") == 89);
    assert(lookup_countries_hash_djb2("TOGO") == 48);
    assert(lookup_countries_hash_djb2("KOREA, NORTH") == 71);
    assert(lookup_countries_hash_djb2("PALAU") == 173);
    assert(lookup_countries_hash_djb2("PERU") == 188);
    assert(lookup_countries_hash_djb2("BELIZE") == 147);
    assert(lookup_countries_hash_djb2("AUSTRALIA") == 166);
    assert(lookup_countries_hash_djb2("MALAWI") == 28);
    assert(lookup_countries_hash_djb2("SWITZERLAND") == 140);
    assert(lookup_countries_hash_djb2("ZAMBIA") == 51);
    assert(lookup_countries_hash_djb2("EGYPT") == 13);
    assert(lookup_countries_hash_djb2("BURMA") == 58);
    assert(lookup_countries_hash_djb2("JAPAN") == 68);
    assert(lookup_countries_hash_djb2("AFGHANISTAN") == 53);
    assert(lookup_countries_hash_djb2("DOMINICA") == 151);
    assert(lookup_countries_hash_djb2("SWEDEN") == 139);
    assert(lookup_countries_hash_djb2("NEW ZEALAND") == 172);
    assert(lookup_countries_hash_djb2("SUDAN") == 45);
    assert(lookup_countries_hash_djb2("SINGAPORE") == 87);
    assert(lookup_countries_hash_djb2("GUINEA") == 20);
    assert(lookup_countries_hash_djb2("SPAIN") == 138);
    assert(lookup_countries_hash_djb2("SURINAME") == 189);
    assert(lookup_countries_hash_djb2("GUATEMALA") == 155);
    assert(lookup_countries_hash_djb2("UZBEKISTAN") == 95);
    assert(lookup_countries_hash_djb2("CHAD") == 9);
    assert(lookup_countries_hash_djb2("BHUTAN") == 56);
    assert(lookup_countries_hash_djb2("SAMOA") == 175);
    assert(lookup_countries_hash_djb2("GEORGIA") == 113);
    assert(lookup_countries_hash_djb2("PARAGUAY") == 187);
    assert(lookup_countries_hash_djb2("OMAN") == 81);
    assert(lookup_countries_hash_djb2("SIERRA LEONE") == 41);
    assert(lookup_countries_hash_djb2("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash_djb2("BULGARIA") == 106);
    assert(lookup_countries_hash_djb2("LIBERIA") == 25);
    assert(lookup_countries_hash_djb2("PAKISTAN") == 82);
    assert(lookup_countries_hash_djb2("MONGOLIA") == 79);
    assert(lookup_countries_hash_djb2("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash_djb2("ITALY") == 119);
    assert(lookup_countries_hash_djb2("BRAZIL") == 182);
    assert(lookup_countries_hash_djb2("BURUNDI") == 5);
    assert(lookup_countries_hash_djb2("FIJI") == 167);
    assert(lookup_countries_hash_djb2("GABON") == 17);
    assert(lookup_countries_hash_djb2("GRENADA") == 154);
    assert(lookup_countries_hash_djb2("ERITREA") == 15);
    assert(lookup_countries_hash_djb2("LESOTHO") == 24);
    assert(lookup_countries_hash_djb2("SENEGAL") == 39);
    assert(lookup_countries_hash_djb2("SAINT LUCIA") == 163);
    assert(lookup_countries_hash_djb2("ISRAEL") == 67);
    assert(lookup_countries_hash_djb2("ICELAND") == 117);
    assert(lookup_countries_hash_djb2("ARGENTINA") == 180);
    assert(lookup_countries_hash_djb2("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash_djb2("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash_djb2("AZERBAIJAN") == 102);
    assert(lookup_countries_hash_djb2("MEXICO") == 159);
    assert(lookup_countries_hash_djb2("TUVALU") == 178);
    assert(lookup_countries_hash_djb2("HAITI") == 156);
    assert(lookup_countries_hash_djb2("MALI") == 29);
    assert(lookup_countries_hash_djb2("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash_djb2("MAURITANIA") == 30);
    assert(lookup_countries_hash_djb2("CROATIA") == 107);
    assert(lookup_countries_hash_djb2("LUXEMBOURG") == 123);
    assert(lookup_countries_hash_djb2("POLAND") == 131);
    assert(lookup_countries_hash_djb2("UKRAINE") == 141);
    assert(lookup_countries_hash_djb2("TURKEY") == 92);
    assert(lookup_countries_hash_djb2("KUWAIT") == 73);
    assert(lookup_countries_hash_djb2("JAMAICA") == 158);
    assert(lookup_countries_hash_djb2("YEMEN") == 97);
    assert(lookup_countries_hash_djb2("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash_djb2("NAURU") == 171);
    assert(lookup_countries_hash_djb2("JORDAN") == 69);
    assert(lookup_countries_hash_djb2("NIGER") == 35);
    assert(lookup_countries_hash_djb2("ESTONIA") == 110);
    assert(lookup_countries_hash_djb2("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash_djb2("DENMARK") == 109);
    assert(lookup_countries_hash_djb2("DJIBOUTI") == 12);
    assert(lookup_countries_hash_djb2("LATVIA") == 120);
    assert(lookup_countries_hash_djb2("MADAGASCAR") == 27);
    assert(lookup_countries_hash_djb2("EAST TIMOR") == 62);
    assert(lookup_countries_hash_djb2("INDONESIA") == 64);
    assert(lookup_countries_hash_djb2("ANGOLA") == 1);
    assert(lookup_countries_hash_djb2("NETHERLANDS") == 129);
    assert(lookup_countries_hash_djb2("ALGERIA") == 0);
    assert(lookup_countries_hash_djb2("COSTA RICA") == 149);
    assert(lookup_countries_hash_djb2("PHILIPPINES") == 83);
    assert(lookup_countries_hash_djb2("BELARUS") == 103);
    assert(lookup_countries_hash_djb2("FRANCE") == 112);
    assert(lookup_countries_hash_djb2("RWANDA") == 37);
    assert(lookup_countries_hash_djb2("ROMANIA") == 133);
    assert(lookup_countries_hash_djb2("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash_djb2("KOREA, SOUTH") == 72);
}

//lookup: name=lookup_countries_hash_sdb, dataset=countries, type=hash, hash=hash_sdb
int lookup_countries_hash_sdb(std::string_view s) {
    const uint64_t idx = (hash_sdb(s) % 482) * 2;
    constexpr const std::string_view lookup[964] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PANAMA", // 2268236505955265580 (0x1f7a6515a4096c2c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LUXEMBOURG", // 2937274125308621990 (0x28c34b412ef774a6)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "UGANDA", // 2411514012356342220 (0x21776b37ad6071cc)
        "BHUTAN", // 1939177998586110570 (0x1ae9581d91fa626a)
        "",
        "",
        "",
        "",
        "LIBYA", // 277273584566018909 (0x3d912db29a8235d)
        "TUNISIA", // 15205554960473809995 (0xd304fbac8fb8644b)
        "EAST TIMOR", // 5795393089389016048 (0x506d5f4f3ac933f0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BENIN", // 242368265018155024 (0x35d10a7253c2010)
        "SAN MARINO", // 14933094467224129292 (0xcf3d024c8c3ecf0c)
        "TOGO", // 23647484525743303 (0x5403430afd0cc7)
        "",
        "",
        "",
        "",
        "",
        "EQUATORIAL GUINEA", // 11794992648420906134 (0xa3b03b523978d496)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BURUNDI", // 12486414122935989085 (0xad48a77d2c05335d)
        "",
        "DJIBOUTI", // 12266689103813115498 (0xaa3c08bf8aef7e6a)
        "",
        "UKRAINE", // 15115477165266263499 (0xd1c4f66586395dcb)
        "NICARAGUA", // 216613628594315195 (0x30190f291df5fbb)
        "ALBANIA", // 12046730069729550548 (0xa72e952c0f3f20d4)
        "BELARUS", // 12055173756373049484 (0xa74c94a90e3a208c)
        "GERMANY", // 12838827966407586123 (0xb22cae032e13314b)
        "",
        "ERITREA", // 12835734636580451898 (0xb221b0a5348e363a)
        "",
        "ITALY", // 270236435267330939 (0x3c0129b297a237b)
        "",
        "HONDURAS", // 16353826009526809740 (0xe2f4761c0063b48c)
        "",
        "",
        "",
        "SINGAPORE", // 2692685431464657244 (0x255e57222a52015c)
        "VIETNAM", // 15178246725008055472 (0xd2a3f6fa85575cb0)
        "",
        "",
        "",
        "",
        "SEYCHELLES", // 7344454000506893083 (0x65ecbe003968f31b)
        "",
        "",
        "",
        "GHANA", // 260102408357552515 (0x39c11c327602183)
        "",
        "HUNGARY", // 13380971385036685690 (0xb9b2c2944ac7417a)
        "SAINT KITTS AND NEVIS", // 1827309520702999342 (0x195be853dc310b2e)
        "SAO TOME AND PRINCIPE", // 1037287225660664489 (0xe652f3c678deaa9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BAHAMAS", // 11940326377984891667 (0xa5b48f9406041b13)
        "",
        "PORTUGAL", // 4446492237566443862 (0x3db51d21acae0156)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "POLAND", // 2314964521870717034 (0x202067f7a9bc706a)
        "",
        "",
        "",
        "MONGOLIA", // 1905544005850292068 (0x1a71da2d6494df64)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CYPRUS", // 2020529167551719526 (0x1c0a5c929a3c6866)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "DENMARK", // 12369311122070775674 (0xaba89eee1b51277a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CAMEROON", // 10212984214525993230 (0x8dbbcf084b7e610e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SYRIA", // 305423393012590500 (0x43d14f52e9c27a4)
        "",
        "GAMBIA", // 2039949828472136579 (0x1c4f5b8f95b36383)
        "",
        "",
        "",
        "",
        "",
        "AFGHANISTAN", // 4083990487775330492 (0x38ad3fb5f1ec40bc)
        "SURINAME", // 7713385033157715900 (0x6b0b72d2052e27bc)
        "",
        "",
        "",
        "",
        "ESTONIA", // 12896818207019252233 (0xb2fab3d43a2c3a09)
        "",
        "",
        "",
        "",
        "",
        "KENYA", // 272769649921762060 (0x3c9128d2918230c)
        "",
        "BAHRAIN", // 11945112058205248645 (0xa5c59021078f1c85)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CENTRAL AFRICAN REPUBLIC", // 7491503129927575355 (0x67f72a67ad0f673b)
        "",
        "",
        "",
        "",
        "",
        "DOMINICA", // 13151397220034908648 (0xb6832617b03d91e8)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CHAD", // 18861722693667488 (0x4302a309020aa0)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NETHERLANDS", // 1562961236367705520 (0x15b0c0f6ab6705b0)
        "",
        "",
        "",
        "CAMBODIA", // 10202005831409557320 (0x8d94ce4049a15f48)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ETHIOPIA", // 14583021231927764061 (0xca614c8bd908a45d)
        "SPAIN", // 302889697292789285 (0x43414932d432625)
        "",
        "",
        "SOLOMON ISLANDS", // 8556839618118383895 (0x76c0004bedef7917)
        "ECUADOR", // 12490912383710538105 (0xad58a2a21f982979)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KOREA, NORTH", // 8507835181125950955 (0x7611e70552955deb)
        "",
        "UZBEKISTAN", // 12064003036003429724 (0xa76bf2d7ea37ed5c)
        "",
        "",
        "",
        "",
        "",
        "CAPE VERDE", // 3546995390735341063 (0x31397583dcba5607)
        "",
        "",
        "",
        "MALDIVES", // 18161773547939214443 (0xfc0b94d11000b46b)
        "ANDORRA", // 12108094956231206165 (0xa808983614dc2515)
        "LIBERIA", // 13643873183679004126 (0xbd58c65f49aa3dde)
        "AUSTRALIA", // 18251070137591118004 (0xfd48d39781dbb8b4)
        "OMAN", // 22239907768699931 (0x4f03140a640c1b)
        "",
        "",
        "",
        "MALAYSIA", // 18156143958216848647 (0xfbf794bc105eb507)
        "",
        "JORDAN", // 2164650171125033816 (0x1e0a61dca0e56b58)
        "",
        "",
        "",
        "TANZANIA", // 5423783978064148462 (0x4b4526caa6f7f7ee)
        "",
        "",
        "",
        "SOMALIA", // 14895919738350361176 (0xceb8f0147f1a5a58)
        "",
        "VATICAN CITY", // 2181397504312141115 (0x1e45e178fe72e53b)
        "",
        "",
        "",
        "",
        "",
        "SERBIA", // 2358876014121480370 (0x20bc693caae670b2)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MARSHALL ISLANDS", // 9692484638058847776 (0x86829f6ce26d9e20)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BARBADOS", // 9526730701876451878 (0x8435bf193c275a26)
        "",
        "",
        "",
        "",
        "",
        "GABON", // 258131817220677855 (0x395118526aa20df)
        "",
        "",
        "",
        "LIECHTENSTEIN", // 14929545242498179381 (0xcf30664c453a2135)
        "",
        "",
        "",
        "SENEGAL", // 14647084627344904541 (0xcb44e5dd6ffa515d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "IRELAND", // 13427977551489351431 (0xba59c27048713f07)
        "",
        "",
        "",
        "IVORY COAST", // 8038371346522406039 (0x6f8e08268a257c97)
        "",
        "",
        "",
        "MONACO", // 2239525826421353905 (0x1f1464dfa5286db1)
        "",
        "",
        "",
        "BURMA", // 246872500330832355 (0x36d113b270821e3)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "LEBANON", // 13541411481678526881 (0xbbecc1ff42d839a1)
        "",
        "COLOMBIA", // 12348045882170706440 (0xab5d124e9d028a08)
        "",
        "LAOS", // 21395315325733773 (0x4c02ed09d90b8d)
        "TURKMENISTAN", // 3541533609896217487 (0x31260e0de9f88b8f)
        "IRAN", // 20550847446387622 (0x4902e309e00ba6)
        "",
        "VENEZUELA", // 11027056986113258029 (0x9907f9e7af45322d)
        "",
        "",
        "",
        "IRAQ", // 20550847446387625 (0x4902e309e00ba9)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MYANMAR", // 14200373080295821397 (0xc511dc14690d5055)
        "",
        "NEPAL", // 282903453478429652 (0x3ed13312a5023d4)
        "JAMAICA", // 13173229666319348544 (0xb6d0b696359a3340)
        "",
        "",
        "",
        "",
        "MALTA", // 278399450109649697 (0x3dd12d329732321)
        "",
        "SOUTH SUDAN", // 2510868520141055232 (0x22d8659dacb7e500)
        "GRENADA", // 13124537166945925482 (0xb623b9043d39396a)
        "PAKISTAN", // 2103410782259826585 (0x1d30d0f64d52cf99)
        "",
        "",
        "",
        "",
        "",
        "YEMEN", // 320060688806848322 (0x47115802ee62742)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KIRIBATI", // 17948702660196614157 (0xf91699f92020c00d)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ROMANIA", // 14743918041036511121 (0xcc9ceb5779745791)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "EGYPT", // 253065134501470647 (0x383116626ff21b7)
        "",
        "",
        "",
        "GUINEA", // 2106382458600253899 (0x1d3b5faf9dfb69cb)
        "",
        "MOZAMBIQUE", // 16624674139976707254 (0xe6b6b50c8bef2cb6)
        "SAUDI ARABIA", // 8055479184896978462 (0x6fcacfa38f566e1e)
        "",
        "",
        "FINLAND", // 12774368650533155018 (0xb147ac9b2cea30ca)
        "",
        "MAURITIUS", // 11590585254707545203 (0xa0da07e12db94473)
        "",
        "PERU", // 22521387040115752 (0x5003150a600c28)
        "",
        "FRANCE", // 2068662646995445515 (0x1cb55db79a48670b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ZAMBIA", // 2521294072333890956 (0x22fd6f99b3c2758c)
        "JAPAN", // 268265672322327078 (0x3b9123528342226)
        "",
        "",
        "",
        "",
        "INDIA", // 268547366354100947 (0x3ba126828e722d3)
        "",
        "",
        "",
        "",
        "",
        "INDONESIA", // 3995670110812641760 (0x377378cbbaa219e0)
        "",
        "ZIMBABWE", // 11321414165609003311 (0x9d1dbe334033392f)
        "LATVIA", // 2168590047670004147 (0x1e1861289ed169b3)
        "",
        "",
        "NAMIBIA", // 13783488568935989071 (0xbf48c9d34d163f4f)
        "SAINT LUCIA", // 7391980340885088703 (0x669596f4a52069bf)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BELGIUM", // 12056862799513919703 (0xa75294d60ea620d7)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SWITZERLAND", // 5873750666325421483 (0x5183c11c4d8a6dab)
        "",
        "",
        "",
        "ARGENTINA", // 13644867643100852059 (0xbd5c4ed3ea3f6f5b)
        "",
        "",
        "",
        "UNITED ARAB EMIRATES", // 7635924166488901711 (0x69f840929364484f)
        "",
        "",
        "",
        "PHILIPPINES", // 15073076137082670473 (0xd12e52e2d73acd89)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NORWAY", // 2265985883023568858 (0x1f726627a7ab6fda)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SWEDEN", // 2416019115285640472 (0x21876c95b1277518)
        "",
        "",
        "",
        "BURKINA", // 12483598965127983672 (0xad3ea71e2ae33238)
        "GEORGIA", // 12830101765377831150 (0xb20dad942d7530ee)
        "BOSNIA AND HERZEGOVINA", // 3499832317096021469 (0x3091e6f311f0cddd)
        "",
        "",
        "",
        "MACEDONIA", // 8506916545024426677 (0x760ea386b01302b5)
        "",
        "",
        "",
        "AUSTRIA", // 12337508852235841765 (0xab37a2ef26c130e5)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "COSTA RICA", // 7163657610147401841 (0x636a6ca4495c1071)
        "",
        "ICELAND", // 13047968937914282186 (0xb513b29e30b630ca)
        "TRINIDAD AND TOBAGO", // 8420108167620321266 (0x74da3bc44d5fdff2)
        "BELIZE", // 1926510533672591459 (0x1abc571f8f9a6063)
        "",
        "",
        "",
        "KUWAIT", // 2211659223912115899 (0x1eb16458a57f6ebb)
        "",
        "DOMINICAN REPUBLIC", // 3765998108509689354 (0x344383539a83560a)
        "",
        "SAMOA", // 298667044339721473 (0x42514182bfc2501)
        "",
        "ISRAEL", // 2152827977290902424 (0x1de061a3a0f26b98)
        "",
        "",
        "",
        "",
        "",
        "NEW ZEALAND", // 2409398079756183961 (0x216fe6c9ba602999)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SOUTH AFRICA", // 14352065949517519629 (0xc72cc7f0c9f89b0d)
        "",
        "FIJI", // 19706267889175322 (0x4602bf09620b1a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "GUINEA-BISSAU", // 5434608031764229089 (0x4b6b9b360acaabe1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ALGERIA", // 12064745799722935033 (0xa76e966211df22f9)
        "TONGA", // 305986171154998973 (0x43f14cd2de026bd)
        "",
        "",
        "BRUNEI", // 1972957289372607845 (0x1b615a3396126565)
        "",
        "",
        "",
        "RWANDA", // 2389559196134765571 (0x21296b6daf617403)
        "",
        "TAJIKISTAN", // 16739783457566388092 (0xe84fa85d0d346f7c)
        "UNITED KINGDOM", // 15445222657001468542 (0xd658742c9b63327e)
        "",
        "",
        "",
        "",
        "",
        "",
        "MOROCCO", // 14004740313408097276 (0xc25ad51d60484bfc)
        "",
        "",
        "",
        "PAPUA NEW GUINEA", // 894379896144960944 (0xc6979c6e3f89db0)
        "",
        "",
        "",
        "",
        "",
        "SWAZILAND", // 12395953508527204235 (0xac07460a1805678b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "MEXICO", // 2208561680557698013 (0x1ea66325a22e6bdd)
        "",
        "",
        "",
        "MAURITANIA", // 16890544853045398629 (0xea67450dcc92cc65)
        "",
        "",
        "",
        "SUDAN", // 304297278344275631 (0x43914c32dd426af)
        "EL SALVADOR", // 4116905557478285075 (0x39222fcacf531f13)
        "URUGUAY", // 15304637446578071134 (0xd464feab936d665e)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "PARAGUAY", // 2250346522711937670 (0x1f3ad63d53c7d286)
        "",
        "SLOVENIA", // 6310747501968232145 (0x5794476ad2000ed1)
        "",
        "",
        "",
        "CHINA", // 246590716097077383 (0x36c10f325e02087)
        "CUBA", // 18861778533419797 (0x4302b009510b15)
        "COMOROS", // 12467833660514381468 (0xad06a4a8259e2e9c)
        "",
        "GUYANA", // 2110886620892130081 (0x1d4b60329f666b21)
        "",
        "",
        "",
        "GREECE", // 2095122570441615385 (0x1d135ee09c136819)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KOREA, SOUTH", // 8524724852291231643 (0x764de81654c35f9b)
        "",
        "LESOTHO", // 13602777536464109726 (0xbcc6c6194b9b409e)
        "MOLDOVA", // 13981376125053585796 (0xc207d3825cf24984)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BOLIVIA", // 12310764958335904464 (0xaad89f811ef02ad0)
        "",
        "",
        "",
        "CANADA", // 1938895707522949050 (0x1ae8575f8f6f5fba)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "ANTIGUA AND BARBUDA", // 6440912936946601671 (0x5962b830d3eb8ec7)
        "CHILE", // 246590716096946309 (0x36c10f325de2085)
        "CONGO", // 248561333005721962 (0x373113726b4216a)
        "MICRONESIA", // 14855793358131233804 (0xce2a61599005040c)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "NIGERIA", // 13964766253767345445 (0xc1ccd0eb572a4525)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "BULGARIA", // 12431651092951699287 (0xac8618cda6fb8f57)
        "",
        "",
        "",
        "",
        "",
        "ANGOLA", // 1930170468608795082 (0x1ac957d0916061ca)
        "",
        "BOTSWANA", // 11769040524877007725 (0xa354080098788b6d)
        "PALAU", // 288533245075923951 (0x40113752aa423ef)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "SIERRA LEONE", // 827019416819844763 (0xb7a29c721e5c69b)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "VANUATU", // 15006258307131987928 (0xd040f06c7c5b57d8)
        "",
        "",
        "",
        "MADAGASCAR", // 630675433247933524 (0x8c09bf70f4f0454)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "KAZAKHSTAN", // 2284997557278289176 (0x1fb5f12c02352d18)
        "",
        "BANGLADESH", // 4508469893019803775 (0x3e914d7b15fd207f)
        "",
        "",
        "",
        "SRI LANKA", // 8159620334812536001 (0x713ccb76868e1cc1)
        "",
        "",
        "",
        "",
        "",
        "TURKEY", // 2438256866844571410 (0x21d66db3b36d7712)
        "",
        "MALI", // 21676828958722965 (0x4d02f609f10b95)
        "AZERBAIJAN", // 3482788586664631755 (0x305559c457ee1dcb)
        "",
        "",
        "",
        "",
        "",
        "",
        "MALAWI", // 2191671755974535491 (0x1e6a61d99f1e6943)
        "ARMENIA", // 12237016817906559597 (0xa9d29df61dcd2a6d)
        "",
        "",
        "CROATIA", // 12546650064266801291 (0xae1ea7c229c1308b)
        "GUATEMALA", // 1563411207299341317 (0x15b25a35b0f11c05)
        "",
        "",
        "LITHUANIA", // 13774059574522176661 (0xbf274a3476766495)
        "",
        "",
        "",
        "",
        "",
        "SLOVAKIA", // 6309621434549407306 (0x57904743d1820e4a)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "QATAR", // 291911211094647941 (0x40d13b32b402485)
        "",
        "",
        "",
        "NIGER", // 284029469353190401 (0x3f1134c2a8a2401)
        "",
        "KYRGYZSTAN", // 15371060835802248170 (0xd550fa640ae973ea)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "HAITI", // 261509778944369017 (0x3a111c227452179)
        "",
        "",
        "",
        "",
        "",
        "RUSSIAN FEDERATION", // 12856974203656438748 (0xb26d25eb474d83dc)
        "BRAZIL", // 1967327068253479876 (0x1b4d598b944263c4)
        "THAILAND", // 6104126876940827371 (0x54b6370db3f8faeb)
        "",
        "MONTENEGRO", // 9773402655646676924 (0x87a219ef00adf7bc)
        "",
        "TUVALU", // 2439382878424168245 (0x21da6dcdb3a47735)
        "",
        "SAINT VINCENT AND THE GRENADINES", // 12780678882658700934 (0xb15e17ba95354e86)
        "",
        "NAURU", // 281777420423603153 (0x3e913122a1323d1)
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    constexpr const int values[964] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        161, // 2268236505955265580 (0x1f7a6515a4096c2c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        123, // 2937274125308621990 (0x28c34b412ef774a6)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        50, // 2411514012356342220 (0x21776b37ad6071cc)
        56, // 1939177998586110570 (0x1ae9581d91fa626a)
        -1,
        -1,
        -1,
        -1,
        26, // 277273584566018909 (0x3d912db29a8235d)
        49, // 15205554960473809995 (0xd304fbac8fb8644b)
        62, // 5795393089389016048 (0x506d5f4f3ac933f0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        2, // 242368265018155024 (0x35d10a7253c2010)
        134, // 14933094467224129292 (0xcf3d024c8c3ecf0c)
        48, // 23647484525743303 (0x5403430afd0cc7)
        -1,
        -1,
        -1,
        -1,
        -1,
        14, // 11794992648420906134 (0xa3b03b523978d496)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        5, // 12486414122935989085 (0xad48a77d2c05335d)
        -1,
        12, // 12266689103813115498 (0xaa3c08bf8aef7e6a)
        -1,
        141, // 15115477165266263499 (0xd1c4f66586395dcb)
        160, // 216613628594315195 (0x30190f291df5fbb)
        98, // 12046730069729550548 (0xa72e952c0f3f20d4)
        103, // 12055173756373049484 (0xa74c94a90e3a208c)
        114, // 12838827966407586123 (0xb22cae032e13314b)
        -1,
        15, // 12835734636580451898 (0xb221b0a5348e363a)
        -1,
        119, // 270236435267330939 (0x3c0129b297a237b)
        -1,
        157, // 16353826009526809740 (0xe2f4761c0063b48c)
        -1,
        -1,
        -1,
        87, // 2692685431464657244 (0x255e57222a52015c)
        96, // 15178246725008055472 (0xd2a3f6fa85575cb0)
        -1,
        -1,
        -1,
        -1,
        40, // 7344454000506893083 (0x65ecbe003968f31b)
        -1,
        -1,
        -1,
        19, // 260102408357552515 (0x39c11c327602183)
        -1,
        116, // 13380971385036685690 (0xb9b2c2944ac7417a)
        162, // 1827309520702999342 (0x195be853dc310b2e)
        38, // 1037287225660664489 (0xe652f3c678deaa9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        145, // 11940326377984891667 (0xa5b48f9406041b13)
        -1,
        132, // 4446492237566443862 (0x3db51d21acae0156)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        131, // 2314964521870717034 (0x202067f7a9bc706a)
        -1,
        -1,
        -1,
        79, // 1905544005850292068 (0x1a71da2d6494df64)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        108, // 2020529167551719526 (0x1c0a5c929a3c6866)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        109, // 12369311122070775674 (0xaba89eee1b51277a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        6, // 10212984214525993230 (0x8dbbcf084b7e610e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        89, // 305423393012590500 (0x43d14f52e9c27a4)
        -1,
        18, // 2039949828472136579 (0x1c4f5b8f95b36383)
        -1,
        -1,
        -1,
        -1,
        -1,
        53, // 4083990487775330492 (0x38ad3fb5f1ec40bc)
        189, // 7713385033157715900 (0x6b0b72d2052e27bc)
        -1,
        -1,
        -1,
        -1,
        110, // 12896818207019252233 (0xb2fab3d43a2c3a09)
        -1,
        -1,
        -1,
        -1,
        -1,
        23, // 272769649921762060 (0x3c9128d2918230c)
        -1,
        54, // 11945112058205248645 (0xa5c59021078f1c85)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        8, // 7491503129927575355 (0x67f72a67ad0f673b)
        -1,
        -1,
        -1,
        -1,
        -1,
        151, // 13151397220034908648 (0xb6832617b03d91e8)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        9, // 18861722693667488 (0x4302a309020aa0)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        129, // 1562961236367705520 (0x15b0c0f6ab6705b0)
        -1,
        -1,
        -1,
        60, // 10202005831409557320 (0x8d94ce4049a15f48)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        16, // 14583021231927764061 (0xca614c8bd908a45d)
        138, // 302889697292789285 (0x43414932d432625)
        -1,
        -1,
        176, // 8556839618118383895 (0x76c0004bedef7917)
        185, // 12490912383710538105 (0xad58a2a21f982979)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        71, // 8507835181125950955 (0x7611e70552955deb)
        -1,
        95, // 12064003036003429724 (0xa76bf2d7ea37ed5c)
        -1,
        -1,
        -1,
        -1,
        -1,
        7, // 3546995390735341063 (0x31397583dcba5607)
        -1,
        -1,
        -1,
        78, // 18161773547939214443 (0xfc0b94d11000b46b)
        99, // 12108094956231206165 (0xa808983614dc2515)
        25, // 13643873183679004126 (0xbd58c65f49aa3dde)
        166, // 18251070137591118004 (0xfd48d39781dbb8b4)
        81, // 22239907768699931 (0x4f03140a640c1b)
        -1,
        -1,
        -1,
        77, // 18156143958216848647 (0xfbf794bc105eb507)
        -1,
        69, // 2164650171125033816 (0x1e0a61dca0e56b58)
        -1,
        -1,
        -1,
        47, // 5423783978064148462 (0x4b4526caa6f7f7ee)
        -1,
        -1,
        -1,
        42, // 14895919738350361176 (0xceb8f0147f1a5a58)
        -1,
        143, // 2181397504312141115 (0x1e45e178fe72e53b)
        -1,
        -1,
        -1,
        -1,
        -1,
        135, // 2358876014121480370 (0x20bc693caae670b2)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        169, // 9692484638058847776 (0x86829f6ce26d9e20)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        146, // 9526730701876451878 (0x8435bf193c275a26)
        -1,
        -1,
        -1,
        -1,
        -1,
        17, // 258131817220677855 (0x395118526aa20df)
        -1,
        -1,
        -1,
        121, // 14929545242498179381 (0xcf30664c453a2135)
        -1,
        -1,
        -1,
        39, // 14647084627344904541 (0xcb44e5dd6ffa515d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        118, // 13427977551489351431 (0xba59c27048713f07)
        -1,
        -1,
        -1,
        22, // 8038371346522406039 (0x6f8e08268a257c97)
        -1,
        -1,
        -1,
        127, // 2239525826421353905 (0x1f1464dfa5286db1)
        -1,
        -1,
        -1,
        58, // 246872500330832355 (0x36d113b270821e3)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        76, // 13541411481678526881 (0xbbecc1ff42d839a1)
        -1,
        184, // 12348045882170706440 (0xab5d124e9d028a08)
        -1,
        75, // 21395315325733773 (0x4c02ed09d90b8d)
        93, // 3541533609896217487 (0x31260e0de9f88b8f)
        65, // 20550847446387622 (0x4902e309e00ba6)
        -1,
        191, // 11027056986113258029 (0x9907f9e7af45322d)
        -1,
        -1,
        -1,
        66, // 20550847446387625 (0x4902e309e00ba9)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        59, // 14200373080295821397 (0xc511dc14690d5055)
        -1,
        80, // 282903453478429652 (0x3ed13312a5023d4)
        158, // 13173229666319348544 (0xb6d0b696359a3340)
        -1,
        -1,
        -1,
        -1,
        125, // 278399450109649697 (0x3dd12d329732321)
        -1,
        44, // 2510868520141055232 (0x22d8659dacb7e500)
        154, // 13124537166945925482 (0xb623b9043d39396a)
        82, // 2103410782259826585 (0x1d30d0f64d52cf99)
        -1,
        -1,
        -1,
        -1,
        -1,
        97, // 320060688806848322 (0x47115802ee62742)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        168, // 17948702660196614157 (0xf91699f92020c00d)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        133, // 14743918041036511121 (0xcc9ceb5779745791)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        13, // 253065134501470647 (0x383116626ff21b7)
        -1,
        -1,
        -1,
        20, // 2106382458600253899 (0x1d3b5faf9dfb69cb)
        -1,
        33, // 16624674139976707254 (0xe6b6b50c8bef2cb6)
        86, // 8055479184896978462 (0x6fcacfa38f566e1e)
        -1,
        -1,
        111, // 12774368650533155018 (0xb147ac9b2cea30ca)
        -1,
        31, // 11590585254707545203 (0xa0da07e12db94473)
        -1,
        188, // 22521387040115752 (0x5003150a600c28)
        -1,
        112, // 2068662646995445515 (0x1cb55db79a48670b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        51, // 2521294072333890956 (0x22fd6f99b3c2758c)
        68, // 268265672322327078 (0x3b9123528342226)
        -1,
        -1,
        -1,
        -1,
        63, // 268547366354100947 (0x3ba126828e722d3)
        -1,
        -1,
        -1,
        -1,
        -1,
        64, // 3995670110812641760 (0x377378cbbaa219e0)
        -1,
        52, // 11321414165609003311 (0x9d1dbe334033392f)
        120, // 2168590047670004147 (0x1e1861289ed169b3)
        -1,
        -1,
        34, // 13783488568935989071 (0xbf48c9d34d163f4f)
        163, // 7391980340885088703 (0x669596f4a52069bf)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        104, // 12056862799513919703 (0xa75294d60ea620d7)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        140, // 5873750666325421483 (0x5183c11c4d8a6dab)
        -1,
        -1,
        -1,
        180, // 13644867643100852059 (0xbd5c4ed3ea3f6f5b)
        -1,
        -1,
        -1,
        94, // 7635924166488901711 (0x69f840929364484f)
        -1,
        -1,
        -1,
        83, // 15073076137082670473 (0xd12e52e2d73acd89)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        130, // 2265985883023568858 (0x1f726627a7ab6fda)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        139, // 2416019115285640472 (0x21876c95b1277518)
        -1,
        -1,
        -1,
        4, // 12483598965127983672 (0xad3ea71e2ae33238)
        113, // 12830101765377831150 (0xb20dad942d7530ee)
        105, // 3499832317096021469 (0x3091e6f311f0cddd)
        -1,
        -1,
        -1,
        124, // 8506916545024426677 (0x760ea386b01302b5)
        -1,
        -1,
        -1,
        101, // 12337508852235841765 (0xab37a2ef26c130e5)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        149, // 7163657610147401841 (0x636a6ca4495c1071)
        -1,
        117, // 13047968937914282186 (0xb513b29e30b630ca)
        165, // 8420108167620321266 (0x74da3bc44d5fdff2)
        147, // 1926510533672591459 (0x1abc571f8f9a6063)
        -1,
        -1,
        -1,
        73, // 2211659223912115899 (0x1eb16458a57f6ebb)
        -1,
        152, // 3765998108509689354 (0x344383539a83560a)
        -1,
        175, // 298667044339721473 (0x42514182bfc2501)
        -1,
        67, // 2152827977290902424 (0x1de061a3a0f26b98)
        -1,
        -1,
        -1,
        -1,
        -1,
        172, // 2409398079756183961 (0x216fe6c9ba602999)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        43, // 14352065949517519629 (0xc72cc7f0c9f89b0d)
        -1,
        167, // 19706267889175322 (0x4602bf09620b1a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        21, // 5434608031764229089 (0x4b6b9b360acaabe1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        0, // 12064745799722935033 (0xa76e966211df22f9)
        177, // 305986171154998973 (0x43f14cd2de026bd)
        -1,
        -1,
        57, // 1972957289372607845 (0x1b615a3396126565)
        -1,
        -1,
        -1,
        37, // 2389559196134765571 (0x21296b6daf617403)
        -1,
        90, // 16739783457566388092 (0xe84fa85d0d346f7c)
        142, // 15445222657001468542 (0xd658742c9b63327e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        32, // 14004740313408097276 (0xc25ad51d60484bfc)
        -1,
        -1,
        -1,
        174, // 894379896144960944 (0xc6979c6e3f89db0)
        -1,
        -1,
        -1,
        -1,
        -1,
        46, // 12395953508527204235 (0xac07460a1805678b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        159, // 2208561680557698013 (0x1ea66325a22e6bdd)
        -1,
        -1,
        -1,
        30, // 16890544853045398629 (0xea67450dcc92cc65)
        -1,
        -1,
        -1,
        45, // 304297278344275631 (0x43914c32dd426af)
        153, // 4116905557478285075 (0x39222fcacf531f13)
        190, // 15304637446578071134 (0xd464feab936d665e)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        187, // 2250346522711937670 (0x1f3ad63d53c7d286)
        -1,
        137, // 6310747501968232145 (0x5794476ad2000ed1)
        -1,
        -1,
        -1,
        61, // 246590716097077383 (0x36c10f325e02087)
        150, // 18861778533419797 (0x4302b009510b15)
        10, // 12467833660514381468 (0xad06a4a8259e2e9c)
        -1,
        186, // 2110886620892130081 (0x1d4b60329f666b21)
        -1,
        -1,
        -1,
        115, // 2095122570441615385 (0x1d135ee09c136819)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        72, // 8524724852291231643 (0x764de81654c35f9b)
        -1,
        24, // 13602777536464109726 (0xbcc6c6194b9b409e)
        126, // 13981376125053585796 (0xc207d3825cf24984)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        181, // 12310764958335904464 (0xaad89f811ef02ad0)
        -1,
        -1,
        -1,
        148, // 1938895707522949050 (0x1ae8575f8f6f5fba)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        144, // 6440912936946601671 (0x5962b830d3eb8ec7)
        183, // 246590716096946309 (0x36c10f325de2085)
        11, // 248561333005721962 (0x373113726b4216a)
        170, // 14855793358131233804 (0xce2a61599005040c)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        36, // 13964766253767345445 (0xc1ccd0eb572a4525)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        106, // 12431651092951699287 (0xac8618cda6fb8f57)
        -1,
        -1,
        -1,
        -1,
        -1,
        1, // 1930170468608795082 (0x1ac957d0916061ca)
        -1,
        3, // 11769040524877007725 (0xa354080098788b6d)
        173, // 288533245075923951 (0x40113752aa423ef)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        41, // 827019416819844763 (0xb7a29c721e5c69b)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        179, // 15006258307131987928 (0xd040f06c7c5b57d8)
        -1,
        -1,
        -1,
        27, // 630675433247933524 (0x8c09bf70f4f0454)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        70, // 2284997557278289176 (0x1fb5f12c02352d18)
        -1,
        55, // 4508469893019803775 (0x3e914d7b15fd207f)
        -1,
        -1,
        -1,
        88, // 8159620334812536001 (0x713ccb76868e1cc1)
        -1,
        -1,
        -1,
        -1,
        -1,
        92, // 2438256866844571410 (0x21d66db3b36d7712)
        -1,
        29, // 21676828958722965 (0x4d02f609f10b95)
        102, // 3482788586664631755 (0x305559c457ee1dcb)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        28, // 2191671755974535491 (0x1e6a61d99f1e6943)
        100, // 12237016817906559597 (0xa9d29df61dcd2a6d)
        -1,
        -1,
        107, // 12546650064266801291 (0xae1ea7c229c1308b)
        155, // 1563411207299341317 (0x15b25a35b0f11c05)
        -1,
        -1,
        122, // 13774059574522176661 (0xbf274a3476766495)
        -1,
        -1,
        -1,
        -1,
        -1,
        136, // 6309621434549407306 (0x57904743d1820e4a)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        84, // 291911211094647941 (0x40d13b32b402485)
        -1,
        -1,
        -1,
        35, // 284029469353190401 (0x3f1134c2a8a2401)
        -1,
        74, // 15371060835802248170 (0xd550fa640ae973ea)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        156, // 261509778944369017 (0x3a111c227452179)
        -1,
        -1,
        -1,
        -1,
        -1,
        85, // 12856974203656438748 (0xb26d25eb474d83dc)
        182, // 1967327068253479876 (0x1b4d598b944263c4)
        91, // 6104126876940827371 (0x54b6370db3f8faeb)
        -1,
        128, // 9773402655646676924 (0x87a219ef00adf7bc)
        -1,
        178, // 2439382878424168245 (0x21da6dcdb3a47735)
        -1,
        164, // 12780678882658700934 (0xb15e17ba95354e86)
        -1,
        171, // 281777420423603153 (0x3e913122a1323d1)
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    for (int i=0; i < 2; i++) {
        if (lookup[idx + i] == s) {
            return values[idx + i];
        }
    }
    return -1;
}

//check: name=check_countries_hash_sdb, dataset=countries, type=hash, hash=hash_sdb
void check_countries_hash_sdb() {
    assert(lookup_countries_hash_sdb("PANAMA") == 161);
    assert(lookup_countries_hash_sdb("LUXEMBOURG") == 123);
    assert(lookup_countries_hash_sdb("UGANDA") == 50);
    assert(lookup_countries_hash_sdb("BHUTAN") == 56);
    assert(lookup_countries_hash_sdb("LIBYA") == 26);
    assert(lookup_countries_hash_sdb("TUNISIA") == 49);
    assert(lookup_countries_hash_sdb("EAST TIMOR") == 62);
    assert(lookup_countries_hash_sdb("BENIN") == 2);
    assert(lookup_countries_hash_sdb("SAN MARINO") == 134);
    assert(lookup_countries_hash_sdb("TOGO") == 48);
    assert(lookup_countries_hash_sdb("EQUATORIAL GUINEA") == 14);
    assert(lookup_countries_hash_sdb("BURUNDI") == 5);
    assert(lookup_countries_hash_sdb("DJIBOUTI") == 12);
    assert(lookup_countries_hash_sdb("UKRAINE") == 141);
    assert(lookup_countries_hash_sdb("NICARAGUA") == 160);
    assert(lookup_countries_hash_sdb("ALBANIA") == 98);
    assert(lookup_countries_hash_sdb("BELARUS") == 103);
    assert(lookup_countries_hash_sdb("GERMANY") == 114);
    assert(lookup_countries_hash_sdb("ERITREA") == 15);
    assert(lookup_countries_hash_sdb("ITALY") == 119);
    assert(lookup_countries_hash_sdb("HONDURAS") == 157);
    assert(lookup_countries_hash_sdb("SINGAPORE") == 87);
    assert(lookup_countries_hash_sdb("VIETNAM") == 96);
    assert(lookup_countries_hash_sdb("SEYCHELLES") == 40);
    assert(lookup_countries_hash_sdb("GHANA") == 19);
    assert(lookup_countries_hash_sdb("HUNGARY") == 116);
    assert(lookup_countries_hash_sdb("SAINT KITTS AND NEVIS") == 162);
    assert(lookup_countries_hash_sdb("SAO TOME AND PRINCIPE") == 38);
    assert(lookup_countries_hash_sdb("BAHAMAS") == 145);
    assert(lookup_countries_hash_sdb("PORTUGAL") == 132);
    assert(lookup_countries_hash_sdb("POLAND") == 131);
    assert(lookup_countries_hash_sdb("MONGOLIA") == 79);
    assert(lookup_countries_hash_sdb("CYPRUS") == 108);
    assert(lookup_countries_hash_sdb("DENMARK") == 109);
    assert(lookup_countries_hash_sdb("CAMEROON") == 6);
    assert(lookup_countries_hash_sdb("SYRIA") == 89);
    assert(lookup_countries_hash_sdb("GAMBIA") == 18);
    assert(lookup_countries_hash_sdb("AFGHANISTAN") == 53);
    assert(lookup_countries_hash_sdb("SURINAME") == 189);
    assert(lookup_countries_hash_sdb("ESTONIA") == 110);
    assert(lookup_countries_hash_sdb("KENYA") == 23);
    assert(lookup_countries_hash_sdb("BAHRAIN") == 54);
    assert(lookup_countries_hash_sdb("CENTRAL AFRICAN REPUBLIC") == 8);
    assert(lookup_countries_hash_sdb("DOMINICA") == 151);
    assert(lookup_countries_hash_sdb("CHAD") == 9);
    assert(lookup_countries_hash_sdb("NETHERLANDS") == 129);
    assert(lookup_countries_hash_sdb("CAMBODIA") == 60);
    assert(lookup_countries_hash_sdb("ETHIOPIA") == 16);
    assert(lookup_countries_hash_sdb("SPAIN") == 138);
    assert(lookup_countries_hash_sdb("SOLOMON ISLANDS") == 176);
    assert(lookup_countries_hash_sdb("ECUADOR") == 185);
    assert(lookup_countries_hash_sdb("KOREA, NORTH") == 71);
    assert(lookup_countries_hash_sdb("UZBEKISTAN") == 95);
    assert(lookup_countries_hash_sdb("CAPE VERDE") == 7);
    assert(lookup_countries_hash_sdb("MALDIVES") == 78);
    assert(lookup_countries_hash_sdb("ANDORRA") == 99);
    assert(lookup_countries_hash_sdb("LIBERIA") == 25);
    assert(lookup_countries_hash_sdb("AUSTRALIA") == 166);
    assert(lookup_countries_hash_sdb("OMAN") == 81);
    assert(lookup_countries_hash_sdb("MALAYSIA") == 77);
    assert(lookup_countries_hash_sdb("JORDAN") == 69);
    assert(lookup_countries_hash_sdb("TANZANIA") == 47);
    assert(lookup_countries_hash_sdb("SOMALIA") == 42);
    assert(lookup_countries_hash_sdb("VATICAN CITY") == 143);
    assert(lookup_countries_hash_sdb("SERBIA") == 135);
    assert(lookup_countries_hash_sdb("MARSHALL ISLANDS") == 169);
    assert(lookup_countries_hash_sdb("BARBADOS") == 146);
    assert(lookup_countries_hash_sdb("GABON") == 17);
    assert(lookup_countries_hash_sdb("LIECHTENSTEIN") == 121);
    assert(lookup_countries_hash_sdb("SENEGAL") == 39);
    assert(lookup_countries_hash_sdb("IRELAND") == 118);
    assert(lookup_countries_hash_sdb("IVORY COAST") == 22);
    assert(lookup_countries_hash_sdb("MONACO") == 127);
    assert(lookup_countries_hash_sdb("BURMA") == 58);
    assert(lookup_countries_hash_sdb("LEBANON") == 76);
    assert(lookup_countries_hash_sdb("COLOMBIA") == 184);
    assert(lookup_countries_hash_sdb("LAOS") == 75);
    assert(lookup_countries_hash_sdb("TURKMENISTAN") == 93);
    assert(lookup_countries_hash_sdb("IRAN") == 65);
    assert(lookup_countries_hash_sdb("VENEZUELA") == 191);
    assert(lookup_countries_hash_sdb("IRAQ") == 66);
    assert(lookup_countries_hash_sdb("MYANMAR") == 59);
    assert(lookup_countries_hash_sdb("NEPAL") == 80);
    assert(lookup_countries_hash_sdb("JAMAICA") == 158);
    assert(lookup_countries_hash_sdb("MALTA") == 125);
    assert(lookup_countries_hash_sdb("SOUTH SUDAN") == 44);
    assert(lookup_countries_hash_sdb("GRENADA") == 154);
    assert(lookup_countries_hash_sdb("PAKISTAN") == 82);
    assert(lookup_countries_hash_sdb("YEMEN") == 97);
    assert(lookup_countries_hash_sdb("KIRIBATI") == 168);
    assert(lookup_countries_hash_sdb("ROMANIA") == 133);
    assert(lookup_countries_hash_sdb("EGYPT") == 13);
    assert(lookup_countries_hash_sdb("GUINEA") == 20);
    assert(lookup_countries_hash_sdb("MOZAMBIQUE") == 33);
    assert(lookup_countries_hash_sdb("SAUDI ARABIA") == 86);
    assert(lookup_countries_hash_sdb("FINLAND") == 111);
    assert(lookup_countries_hash_sdb("MAURITIUS") == 31);
    assert(lookup_countries_hash_sdb("PERU") == 188);
    assert(lookup_countries_hash_sdb("FRANCE") == 112);
    assert(lookup_countries_hash_sdb("ZAMBIA") == 51);
    assert(lookup_countries_hash_sdb("JAPAN") == 68);
    assert(lookup_countries_hash_sdb("INDIA") == 63);
    assert(lookup_countries_hash_sdb("INDONESIA") == 64);
    assert(lookup_countries_hash_sdb("ZIMBABWE") == 52);
    assert(lookup_countries_hash_sdb("LATVIA") == 120);
    assert(lookup_countries_hash_sdb("NAMIBIA") == 34);
    assert(lookup_countries_hash_sdb("SAINT LUCIA") == 163);
    assert(lookup_countries_hash_sdb("BELGIUM") == 104);
    assert(lookup_countries_hash_sdb("SWITZERLAND") == 140);
    assert(lookup_countries_hash_sdb("ARGENTINA") == 180);
    assert(lookup_countries_hash_sdb("UNITED ARAB EMIRATES") == 94);
    assert(lookup_countries_hash_sdb("PHILIPPINES") == 83);
    assert(lookup_countries_hash_sdb("NORWAY") == 130);
    assert(lookup_countries_hash_sdb("SWEDEN") == 139);
    assert(lookup_countries_hash_sdb("BURKINA") == 4);
    assert(lookup_countries_hash_sdb("GEORGIA") == 113);
    assert(lookup_countries_hash_sdb("BOSNIA AND HERZEGOVINA") == 105);
    assert(lookup_countries_hash_sdb("MACEDONIA") == 124);
    assert(lookup_countries_hash_sdb("AUSTRIA") == 101);
    assert(lookup_countries_hash_sdb("COSTA RICA") == 149);
    assert(lookup_countries_hash_sdb("ICELAND") == 117);
    assert(lookup_countries_hash_sdb("TRINIDAD AND TOBAGO") == 165);
    assert(lookup_countries_hash_sdb("BELIZE") == 147);
    assert(lookup_countries_hash_sdb("KUWAIT") == 73);
    assert(lookup_countries_hash_sdb("DOMINICAN REPUBLIC") == 152);
    assert(lookup_countries_hash_sdb("SAMOA") == 175);
    assert(lookup_countries_hash_sdb("ISRAEL") == 67);
    assert(lookup_countries_hash_sdb("NEW ZEALAND") == 172);
    assert(lookup_countries_hash_sdb("SOUTH AFRICA") == 43);
    assert(lookup_countries_hash_sdb("FIJI") == 167);
    assert(lookup_countries_hash_sdb("GUINEA-BISSAU") == 21);
    assert(lookup_countries_hash_sdb("ALGERIA") == 0);
    assert(lookup_countries_hash_sdb("TONGA") == 177);
    assert(lookup_countries_hash_sdb("BRUNEI") == 57);
    assert(lookup_countries_hash_sdb("RWANDA") == 37);
    assert(lookup_countries_hash_sdb("TAJIKISTAN") == 90);
    assert(lookup_countries_hash_sdb("UNITED KINGDOM") == 142);
    assert(lookup_countries_hash_sdb("MOROCCO") == 32);
    assert(lookup_countries_hash_sdb("PAPUA NEW GUINEA") == 174);
    assert(lookup_countries_hash_sdb("SWAZILAND") == 46);
    assert(lookup_countries_hash_sdb("MEXICO") == 159);
    assert(lookup_countries_hash_sdb("MAURITANIA") == 30);
    assert(lookup_countries_hash_sdb("SUDAN") == 45);
    assert(lookup_countries_hash_sdb("EL SALVADOR") == 153);
    assert(lookup_countries_hash_sdb("URUGUAY") == 190);
    assert(lookup_countries_hash_sdb("PARAGUAY") == 187);
    assert(lookup_countries_hash_sdb("SLOVENIA") == 137);
    assert(lookup_countries_hash_sdb("CHINA") == 61);
    assert(lookup_countries_hash_sdb("CUBA") == 150);
    assert(lookup_countries_hash_sdb("COMOROS") == 10);
    assert(lookup_countries_hash_sdb("GUYANA") == 186);
    assert(lookup_countries_hash_sdb("GREECE") == 115);
    assert(lookup_countries_hash_sdb("KOREA, SOUTH") == 72);
    assert(lookup_countries_hash_sdb("LESOTHO") == 24);
    assert(lookup_countries_hash_sdb("MOLDOVA") == 126);
    assert(lookup_countries_hash_sdb("BOLIVIA") == 181);
    assert(lookup_countries_hash_sdb("CANADA") == 148);
    assert(lookup_countries_hash_sdb("ANTIGUA AND BARBUDA") == 144);
    assert(lookup_countries_hash_sdb("CHILE") == 183);
    assert(lookup_countries_hash_sdb("CONGO") == 11);
    assert(lookup_countries_hash_sdb("MICRONESIA") == 170);
    assert(lookup_countries_hash_sdb("NIGERIA") == 36);
    assert(lookup_countries_hash_sdb("BULGARIA") == 106);
    assert(lookup_countries_hash_sdb("ANGOLA") == 1);
    assert(lookup_countries_hash_sdb("BOTSWANA") == 3);
    assert(lookup_countries_hash_sdb("PALAU") == 173);
    assert(lookup_countries_hash_sdb("SIERRA LEONE") == 41);
    assert(lookup_countries_hash_sdb("VANUATU") == 179);
    assert(lookup_countries_hash_sdb("MADAGASCAR") == 27);
    assert(lookup_countries_hash_sdb("KAZAKHSTAN") == 70);
    assert(lookup_countries_hash_sdb("BANGLADESH") == 55);
    assert(lookup_countries_hash_sdb("SRI LANKA") == 88);
    assert(lookup_countries_hash_sdb("TURKEY") == 92);
    assert(lookup_countries_hash_sdb("MALI") == 29);
    assert(lookup_countries_hash_sdb("AZERBAIJAN") == 102);
    assert(lookup_countries_hash_sdb("MALAWI") == 28);
    assert(lookup_countries_hash_sdb("ARMENIA") == 100);
    assert(lookup_countries_hash_sdb("CROATIA") == 107);
    assert(lookup_countries_hash_sdb("GUATEMALA") == 155);
    assert(lookup_countries_hash_sdb("LITHUANIA") == 122);
    assert(lookup_countries_hash_sdb("SLOVAKIA") == 136);
    assert(lookup_countries_hash_sdb("QATAR") == 84);
    assert(lookup_countries_hash_sdb("NIGER") == 35);
    assert(lookup_countries_hash_sdb("KYRGYZSTAN") == 74);
    assert(lookup_countries_hash_sdb("HAITI") == 156);
    assert(lookup_countries_hash_sdb("RUSSIAN FEDERATION") == 85);
    assert(lookup_countries_hash_sdb("BRAZIL") == 182);
    assert(lookup_countries_hash_sdb("THAILAND") == 91);
    assert(lookup_countries_hash_sdb("MONTENEGRO") == 128);
    assert(lookup_countries_hash_sdb("TUVALU") == 178);
    assert(lookup_countries_hash_sdb("SAINT VINCENT AND THE GRENADINES") == 164);
    assert(lookup_countries_hash_sdb("NAURU") == 171);
}
