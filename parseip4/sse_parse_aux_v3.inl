/* Code generated automatically; DO NOT EDIT */
    uint32_t tmp;
    switch (ipv4.size()) {
        case 7: // 1 case(s)
            switch (dotmask & 0x7f) {
                case 0x2a: // [1, 1, 1, 1]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    res.byte[2] = (byte[4] - '0');
                    res.byte[3] = (byte[6] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 8: // 4 case(s)
            switch (dotmask & 0xff) {
                case 0x2a: // [1, 1, 1, 2]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    res.byte[2] = (byte[4] - '0');
                    res.byte[3]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x4a: // [1, 1, 2, 1]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    res.byte[2]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[7] - '0');
                    break;
                case 0x52: // [1, 2, 1, 1]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[5] - '0');
                    res.byte[3] = (byte[7] - '0');
                    break;
                case 0x54: // [2, 1, 1, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    res.byte[2] = (byte[5] - '0');
                    res.byte[3] = (byte[7] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 9: // 10 case(s)
            switch (dotmask & 0x1ff) {
                case 0x2a: // [1, 1, 1, 3]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    res.byte[2] = (byte[4] - '0');
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x4a: // [1, 1, 2, 2]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    res.byte[2]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x8a: // [1, 1, 3, 1]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[8] - '0');
                    break;
                case 0x52: // [1, 2, 1, 2]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[5] - '0');
                    res.byte[3]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x92: // [1, 2, 2, 1]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[5] - '0') + (byte[6] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[8] - '0');
                    break;
                case 0xa2: // [1, 3, 1, 1]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[6] - '0');
                    res.byte[3] = (byte[8] - '0');
                    break;
                case 0x54: // [2, 1, 1, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    res.byte[2] = (byte[5] - '0');
                    res.byte[3]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x94: // [2, 1, 2, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    res.byte[2]  = 10 * (byte[5] - '0') + (byte[6] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[8] - '0');
                    break;
                case 0xa4: // [2, 2, 1, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[6] - '0');
                    res.byte[3] = (byte[8] - '0');
                    break;
                case 0xa8: // [3, 1, 1, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    res.byte[2] = (byte[6] - '0');
                    res.byte[3] = (byte[8] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 10: // 16 case(s)
            switch (dotmask & 0x3ff) {
                case 0x4a: // [1, 1, 2, 3]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    res.byte[2]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x8a: // [1, 1, 3, 2]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x52: // [1, 2, 1, 3]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[5] - '0');
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x92: // [1, 2, 2, 2]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[5] - '0') + (byte[6] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x112: // [1, 2, 3, 1]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[9] - '0');
                    break;
                case 0xa2: // [1, 3, 1, 2]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[6] - '0');
                    res.byte[3]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x122: // [1, 3, 2, 1]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[9] - '0');
                    break;
                case 0x54: // [2, 1, 1, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    res.byte[2] = (byte[5] - '0');
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x94: // [2, 1, 2, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    res.byte[2]  = 10 * (byte[5] - '0') + (byte[6] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x114: // [2, 1, 3, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    tmp = (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[9] - '0');
                    break;
                case 0xa4: // [2, 2, 1, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[6] - '0');
                    res.byte[3]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x124: // [2, 2, 2, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[9] - '0');
                    break;
                case 0x144: // [2, 3, 1, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[7] - '0');
                    res.byte[3] = (byte[9] - '0');
                    break;
                case 0xa8: // [3, 1, 1, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    res.byte[2] = (byte[6] - '0');
                    res.byte[3]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x128: // [3, 1, 2, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[9] - '0');
                    break;
                case 0x148: // [3, 2, 1, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[7] - '0');
                    res.byte[3] = (byte[9] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 11: // 19 case(s)
            switch (dotmask & 0x7ff) {
                case 0x8a: // [1, 1, 3, 3]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1] = (byte[2] - '0');
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x92: // [1, 2, 2, 3]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[5] - '0') + (byte[6] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x112: // [1, 2, 3, 2]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0xa2: // [1, 3, 1, 3]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[6] - '0');
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x122: // [1, 3, 2, 2]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x222: // [1, 3, 3, 1]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[10] - '0');
                    break;
                case 0x94: // [2, 1, 2, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    res.byte[2]  = 10 * (byte[5] - '0') + (byte[6] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x114: // [2, 1, 3, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    tmp = (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0xa4: // [2, 2, 1, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[6] - '0');
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x124: // [2, 2, 2, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x224: // [2, 2, 3, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[10] - '0');
                    break;
                case 0x144: // [2, 3, 1, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[7] - '0');
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x244: // [2, 3, 2, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[10] - '0');
                    break;
                case 0xa8: // [3, 1, 1, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    res.byte[2] = (byte[6] - '0');
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x128: // [3, 1, 2, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x228: // [3, 1, 3, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[10] - '0');
                    break;
                case 0x148: // [3, 2, 1, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[7] - '0');
                    res.byte[3]  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x248: // [3, 2, 2, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[10] - '0');
                    break;
                case 0x288: // [3, 3, 1, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[8] - '0');
                    res.byte[3] = (byte[10] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 12: // 16 case(s)
            switch (dotmask & 0xfff) {
                case 0x112: // [1, 2, 3, 3]
                    res.byte[0] = (byte[0] - '0');
                    res.byte[1]  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x122: // [1, 3, 2, 3]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x222: // [1, 3, 3, 2]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x114: // [2, 1, 3, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1] = (byte[3] - '0');
                    tmp = (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x124: // [2, 2, 2, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x224: // [2, 2, 3, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x144: // [2, 3, 1, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[7] - '0');
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x244: // [2, 3, 2, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x444: // [2, 3, 3, 1]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[11] - '0');
                    break;
                case 0x128: // [3, 1, 2, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    res.byte[2]  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x228: // [3, 1, 3, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x148: // [3, 2, 1, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2] = (byte[7] - '0');
                    tmp = (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x248: // [3, 2, 2, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x448: // [3, 2, 3, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[11] - '0');
                    break;
                case 0x288: // [3, 3, 1, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[8] - '0');
                    res.byte[3]  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x488: // [3, 3, 2, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3] = (byte[11] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 13: // 10 case(s)
            switch (dotmask & 0x1fff) {
                case 0x222: // [1, 3, 3, 3]
                    res.byte[0] = (byte[0] - '0');
                    tmp = (byte[2] - '0');
                    tmp = 10 * tmp + (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x224: // [2, 2, 3, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[1]  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x244: // [2, 3, 2, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x444: // [2, 3, 3, 2]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[11] - '0') + (byte[12] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x228: // [3, 1, 3, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1] = (byte[4] - '0');
                    tmp = (byte[6] - '0');
                    tmp = 10 * tmp + (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x248: // [3, 2, 2, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[2]  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x448: // [3, 2, 3, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[11] - '0') + (byte[12] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x288: // [3, 3, 1, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2] = (byte[8] - '0');
                    tmp = (byte[10] - '0');
                    tmp = 10 * tmp + (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x488: // [3, 3, 2, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    res.byte[3]  = 10 * (byte[11] - '0') + (byte[12] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                case 0x888: // [3, 3, 3, 1]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3] = (byte[12] - '0');
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 14: // 4 case(s)
            switch (dotmask & 0x3fff) {
                case 0x444: // [2, 3, 3, 3]
                    res.byte[0]  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[3] - '0');
                    tmp = 10 * tmp + (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    tmp = 10 * tmp + (byte[13] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x448: // [3, 2, 3, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    res.byte[1]  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[7] - '0');
                    tmp = 10 * tmp + (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    tmp = 10 * tmp + (byte[13] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x488: // [3, 3, 2, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    res.byte[2]  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
                    tmp = (byte[11] - '0');
                    tmp = 10 * tmp + (byte[12] - '0');
                    tmp = 10 * tmp + (byte[13] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                case 0x888: // [3, 3, 3, 2]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    res.byte[3]  = 10 * (byte[12] - '0') + (byte[13] - '0');
                    if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 15: // 1 case(s)
            switch (dotmask & 0x7fff) {
                case 0x888: // [3, 3, 3, 3]
                    tmp = (byte[0] - '0');
                    tmp = 10 * tmp + (byte[1] - '0');
                    tmp = 10 * tmp + (byte[2] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[0] = tmp;
                    tmp = (byte[4] - '0');
                    tmp = 10 * tmp + (byte[5] - '0');
                    tmp = 10 * tmp + (byte[6] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[1] = tmp;
                    tmp = (byte[8] - '0');
                    tmp = 10 * tmp + (byte[9] - '0');
                    tmp = 10 * tmp + (byte[10] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[2] = tmp;
                    tmp = (byte[12] - '0');
                    tmp = 10 * tmp + (byte[13] - '0');
                    tmp = 10 * tmp + (byte[14] - '0');
                    if (tmp < 100) { res.err = errLeadingZeros; break; }
                    if (tmp > 255) { res.err = errTooBig; break; }
                    res.byte[3] = tmp;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
    }
