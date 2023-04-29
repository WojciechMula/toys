//lookup: dataset=irc, name=lookup_irc_split, type=split
int lookup_irc_split(std::string_view s) {
    switch (s.size()) {
        case 3: {
            switch (s[0]) {
                case 'M': { // 0x4d
                    if (s == "MSG") {
                        return 1;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WHO") {
                        return 3;
                    }
                }
                break;
                case 'D': { // 0x44
                    if (s == "DIE") {
                        return 25;
                    }
                }
                break;
            }
        }
        break;
        case 4: {
            switch (s[0]) {
                case 'N': { // 0x4e
                    if (s == "NICK") {
                        return 0;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "USER") {
                        return 5;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LIST") {
                        return 7;
                    }
                }
                break;
                case 'Q': { // 0x51
                    if (s == "QUIT") {
                        return 12;
                    }
                }
                break;
                case 'K': { // 0x4b
                    if (s == "KILL") {
                        return 14;
                    }
                }
                break;
                case 'I': { // 0x49
                    if (s == "INFO") {
                        return 15;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "HELP") {
                        return 22;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "AWAY") {
                        return 24;
                    }
                }
                break;
                case 'P': { // 0x50
                    switch (s[1]) {
                        case 'I': { // 0x49
                            if (s == "PING") {
                                return 27;
                            }
                        }
                        break;
                        case 'O': { // 0x4f
                            if (s == "PONG") {
                                return 28;
                            }
                        }
                        break;
                        case 'A': { // 0x41
                            if (s == "PASS") {
                                return 30;
                            }
                        }
                        break;
                    }
                }
                break;
                case 'O': { // 0x4f
                    if (s == "OPER") {
                        return 29;
                    }
                }
                break;
                case 'W': { // 0x57
                    if (s == "WALL") {
                        return 31;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TIME") {
                        return 32;
                    }
                }
                break;
                case 'G': { // 0x47
                    if (s == "GRPH") {
                        return 42;
                    }
                }
                break;
                case 'X': { // 0x58
                    if (s == "XTRA") {
                        return 43;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "MOTD") {
                        return 44;
                    }
                }
                break;
            }
        }
        break;
        case 5: {
            switch (s[0]) {
                case 'W': { // 0x57
                    if (s == "WHOIS") {
                        return 4;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "TOPIC") {
                        return 8;
                    }
                    if (s == "TRACE") {
                        return 37;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "SQUIT") {
                        return 13;
                    }
                    if (s == "STATS") {
                        return 18;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LINKS") {
                        return 16;
                    }
                }
                break;
                case 'U': { // 0x55
                    if (s == "USERS") {
                        return 19;
                    }
                }
                break;
                case 'E': { // 0x45
                    if (s == "ERROR") {
                        return 23;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NAMES") {
                        return 34;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "ADMIN") {
                        return 36;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "VOICE") {
                        return 41;
                    }
                }
                break;
            }
        }
        break;
        case 6: {
            switch (s[2]) {
                case 'R': { // 0x52
                    if (s == "SERVER") {
                        return 6;
                    }
                }
                break;
                case 'V': { // 0x56
                    if (s == "INVITE") {
                        return 9;
                    }
                }
                break;
                case 'M': { // 0x4d
                    if (s == "SUMMON") {
                        return 17;
                    }
                }
                break;
                case 'H': { // 0x48
                    if (s == "REHASH") {
                        return 33;
                    }
                }
                break;
                case 'T': { // 0x54
                    if (s == "NOTICE") {
                        return 39;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "LUSERS") {
                        return 40;
                    }
                }
                break;
            }
        }
        break;
        case 7: {
            switch (s[2]) {
                case 'I': { // 0x49
                    if (s == "PRIVMSG") {
                        return 2;
                    }
                }
                break;
                case 'A': { // 0x41
                    if (s == "CHANNEL") {
                        return 10;
                    }
                }
                break;
                case 'R': { // 0x52
                    if (s == "VERSION") {
                        return 11;
                    }
                }
                break;
                case 'S': { // 0x53
                    if (s == "RESTART") {
                        return 20;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "CONNECT") {
                        return 26;
                    }
                }
                break;
            }
        }
        break;
        case 8: {
            switch (s[0]) {
                case 'W': { // 0x57
                    if (s == "WHOREPLY") {
                        return 21;
                    }
                }
                break;
                case 'N': { // 0x4e
                    if (s == "NAMREPLY") {
                        return 35;
                    }
                }
                break;
                case 'L': { // 0x4c
                    if (s == "LINREPLY") {
                        return 38;
                    }
                }
                break;
            }
        }
        break;
    }
    return -1;
}

//check: dataset=irc, name=check_irc_split, type=split
void check_irc_split() {
    assert(lookup_irc_split("NICK") == 0);
    assert(lookup_irc_split("MSG") == 1);
    assert(lookup_irc_split("PRIVMSG") == 2);
    assert(lookup_irc_split("WHO") == 3);
    assert(lookup_irc_split("WHOIS") == 4);
    assert(lookup_irc_split("USER") == 5);
    assert(lookup_irc_split("SERVER") == 6);
    assert(lookup_irc_split("LIST") == 7);
    assert(lookup_irc_split("TOPIC") == 8);
    assert(lookup_irc_split("INVITE") == 9);
    assert(lookup_irc_split("CHANNEL") == 10);
    assert(lookup_irc_split("VERSION") == 11);
    assert(lookup_irc_split("QUIT") == 12);
    assert(lookup_irc_split("SQUIT") == 13);
    assert(lookup_irc_split("KILL") == 14);
    assert(lookup_irc_split("INFO") == 15);
    assert(lookup_irc_split("LINKS") == 16);
    assert(lookup_irc_split("SUMMON") == 17);
    assert(lookup_irc_split("STATS") == 18);
    assert(lookup_irc_split("USERS") == 19);
    assert(lookup_irc_split("RESTART") == 20);
    assert(lookup_irc_split("WHOREPLY") == 21);
    assert(lookup_irc_split("HELP") == 22);
    assert(lookup_irc_split("ERROR") == 23);
    assert(lookup_irc_split("AWAY") == 24);
    assert(lookup_irc_split("DIE") == 25);
    assert(lookup_irc_split("CONNECT") == 26);
    assert(lookup_irc_split("PING") == 27);
    assert(lookup_irc_split("PONG") == 28);
    assert(lookup_irc_split("OPER") == 29);
    assert(lookup_irc_split("PASS") == 30);
    assert(lookup_irc_split("WALL") == 31);
    assert(lookup_irc_split("TIME") == 32);
    assert(lookup_irc_split("REHASH") == 33);
    assert(lookup_irc_split("NAMES") == 34);
    assert(lookup_irc_split("NAMREPLY") == 35);
    assert(lookup_irc_split("ADMIN") == 36);
    assert(lookup_irc_split("TRACE") == 37);
    assert(lookup_irc_split("LINREPLY") == 38);
    assert(lookup_irc_split("NOTICE") == 39);
    assert(lookup_irc_split("LUSERS") == 40);
    assert(lookup_irc_split("VOICE") == 41);
    assert(lookup_irc_split("GRPH") == 42);
    assert(lookup_irc_split("XTRA") == 43);
    assert(lookup_irc_split("MOTD") == 44);
}
