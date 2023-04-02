/* Code generated automatically; DO NOT EDIT */
uint32_t tmp;
    switch (code) {
        case 0x55: // [1, 1, 1, 1]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            res.byte[2] = (data[4] - '0');
            res.byte[3] = (data[6] - '0');
            break;
        case 0x56: // [1, 1, 1, 2]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            res.byte[2] = (data[4] - '0');
            res.byte[3]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x57: // [1, 1, 1, 3]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            res.byte[2] = (data[4] - '0');
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x59: // [1, 1, 2, 1]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            res.byte[2]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[7] - '0');
            break;
        case 0x5a: // [1, 1, 2, 2]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            res.byte[2]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x5b: // [1, 1, 2, 3]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            res.byte[2]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x5d: // [1, 1, 3, 1]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[8] - '0');
            break;
        case 0x5e: // [1, 1, 3, 2]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x5f: // [1, 1, 3, 3]
            res.byte[0] = (data[0] - '0');
            res.byte[1] = (data[2] - '0');
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x65: // [1, 2, 1, 1]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[5] - '0');
            res.byte[3] = (data[7] - '0');
            break;
        case 0x66: // [1, 2, 1, 2]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[5] - '0');
            res.byte[3]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x67: // [1, 2, 1, 3]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[5] - '0');
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x69: // [1, 2, 2, 1]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[5] - '0') + (data[6] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[8] - '0');
            break;
        case 0x6a: // [1, 2, 2, 2]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[5] - '0') + (data[6] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x6b: // [1, 2, 2, 3]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[5] - '0') + (data[6] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x6d: // [1, 2, 3, 1]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[9] - '0');
            break;
        case 0x6e: // [1, 2, 3, 2]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x6f: // [1, 2, 3, 3]
            res.byte[0] = (data[0] - '0');
            res.byte[1]  = 10 * (data[2] - '0') + (data[3] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x75: // [1, 3, 1, 1]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[6] - '0');
            res.byte[3] = (data[8] - '0');
            break;
        case 0x76: // [1, 3, 1, 2]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[6] - '0');
            res.byte[3]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x77: // [1, 3, 1, 3]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[6] - '0');
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x79: // [1, 3, 2, 1]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[9] - '0');
            break;
        case 0x7a: // [1, 3, 2, 2]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x7b: // [1, 3, 2, 3]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x7d: // [1, 3, 3, 1]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[10] - '0');
            break;
        case 0x7e: // [1, 3, 3, 2]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[10] - '0') + (data[11] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x7f: // [1, 3, 3, 3]
            res.byte[0] = (data[0] - '0');
            tmp = (data[2] - '0');
            tmp = 10 * tmp + (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x95: // [2, 1, 1, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            res.byte[2] = (data[5] - '0');
            res.byte[3] = (data[7] - '0');
            break;
        case 0x96: // [2, 1, 1, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            res.byte[2] = (data[5] - '0');
            res.byte[3]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x97: // [2, 1, 1, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            res.byte[2] = (data[5] - '0');
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x99: // [2, 1, 2, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            res.byte[2]  = 10 * (data[5] - '0') + (data[6] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[8] - '0');
            break;
        case 0x9a: // [2, 1, 2, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            res.byte[2]  = 10 * (data[5] - '0') + (data[6] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x9b: // [2, 1, 2, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            res.byte[2]  = 10 * (data[5] - '0') + (data[6] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0x9d: // [2, 1, 3, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            tmp = (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[9] - '0');
            break;
        case 0x9e: // [2, 1, 3, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            tmp = (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0x9f: // [2, 1, 3, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1] = (data[3] - '0');
            tmp = (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xa5: // [2, 2, 1, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[6] - '0');
            res.byte[3] = (data[8] - '0');
            break;
        case 0xa6: // [2, 2, 1, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[6] - '0');
            res.byte[3]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xa7: // [2, 2, 1, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[6] - '0');
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xa9: // [2, 2, 2, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[9] - '0');
            break;
        case 0xaa: // [2, 2, 2, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xab: // [2, 2, 2, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xad: // [2, 2, 3, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[10] - '0');
            break;
        case 0xae: // [2, 2, 3, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[10] - '0') + (data[11] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xaf: // [2, 2, 3, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            res.byte[1]  = 10 * (data[3] - '0') + (data[4] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xb5: // [2, 3, 1, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[7] - '0');
            res.byte[3] = (data[9] - '0');
            break;
        case 0xb6: // [2, 3, 1, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[7] - '0');
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xb7: // [2, 3, 1, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[7] - '0');
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xb9: // [2, 3, 2, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[10] - '0');
            break;
        case 0xba: // [2, 3, 2, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[10] - '0') + (data[11] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xbb: // [2, 3, 2, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xbd: // [2, 3, 3, 1]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[11] - '0');
            break;
        case 0xbe: // [2, 3, 3, 2]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[11] - '0') + (data[12] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xbf: // [2, 3, 3, 3]
            res.byte[0]  = 10 * (data[0] - '0') + (data[1] - '0');
            if (res.byte[0] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[3] - '0');
            tmp = 10 * tmp + (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            tmp = 10 * tmp + (data[13] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xd5: // [3, 1, 1, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            res.byte[2] = (data[6] - '0');
            res.byte[3] = (data[8] - '0');
            break;
        case 0xd6: // [3, 1, 1, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            res.byte[2] = (data[6] - '0');
            res.byte[3]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xd7: // [3, 1, 1, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            res.byte[2] = (data[6] - '0');
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xd9: // [3, 1, 2, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[9] - '0');
            break;
        case 0xda: // [3, 1, 2, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xdb: // [3, 1, 2, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            res.byte[2]  = 10 * (data[6] - '0') + (data[7] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xdd: // [3, 1, 3, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[10] - '0');
            break;
        case 0xde: // [3, 1, 3, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[10] - '0') + (data[11] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xdf: // [3, 1, 3, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1] = (data[4] - '0');
            tmp = (data[6] - '0');
            tmp = 10 * tmp + (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xe5: // [3, 2, 1, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[7] - '0');
            res.byte[3] = (data[9] - '0');
            break;
        case 0xe6: // [3, 2, 1, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[7] - '0');
            res.byte[3]  = 10 * (data[9] - '0') + (data[10] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xe7: // [3, 2, 1, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2] = (data[7] - '0');
            tmp = (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xe9: // [3, 2, 2, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[10] - '0');
            break;
        case 0xea: // [3, 2, 2, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[10] - '0') + (data[11] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xeb: // [3, 2, 2, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            res.byte[2]  = 10 * (data[7] - '0') + (data[8] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xed: // [3, 2, 3, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[11] - '0');
            break;
        case 0xee: // [3, 2, 3, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[11] - '0') + (data[12] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xef: // [3, 2, 3, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            res.byte[1]  = 10 * (data[4] - '0') + (data[5] - '0');
            if (res.byte[1] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[7] - '0');
            tmp = 10 * tmp + (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            tmp = 10 * tmp + (data[13] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xf5: // [3, 3, 1, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[8] - '0');
            res.byte[3] = (data[10] - '0');
            break;
        case 0xf6: // [3, 3, 1, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[8] - '0');
            res.byte[3]  = 10 * (data[10] - '0') + (data[11] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xf7: // [3, 3, 1, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2] = (data[8] - '0');
            tmp = (data[10] - '0');
            tmp = 10 * tmp + (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xf9: // [3, 3, 2, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3] = (data[11] - '0');
            break;
        case 0xfa: // [3, 3, 2, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            res.byte[3]  = 10 * (data[11] - '0') + (data[12] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xfb: // [3, 3, 2, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            res.byte[2]  = 10 * (data[8] - '0') + (data[9] - '0');
            if (res.byte[2] < 10) { res.err = errLeadingZeros; break; }
            tmp = (data[11] - '0');
            tmp = 10 * tmp + (data[12] - '0');
            tmp = 10 * tmp + (data[13] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
        case 0xfd: // [3, 3, 3, 1]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3] = (data[12] - '0');
            break;
        case 0xfe: // [3, 3, 3, 2]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            res.byte[3]  = 10 * (data[12] - '0') + (data[13] - '0');
            if (res.byte[3] < 10) { res.err = errLeadingZeros; break; }
            break;
        case 0xff: // [3, 3, 3, 3]
            tmp = (data[0] - '0');
            tmp = 10 * tmp + (data[1] - '0');
            tmp = 10 * tmp + (data[2] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[0] = tmp;
            tmp = (data[4] - '0');
            tmp = 10 * tmp + (data[5] - '0');
            tmp = 10 * tmp + (data[6] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[1] = tmp;
            tmp = (data[8] - '0');
            tmp = 10 * tmp + (data[9] - '0');
            tmp = 10 * tmp + (data[10] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[2] = tmp;
            tmp = (data[12] - '0');
            tmp = 10 * tmp + (data[13] - '0');
            tmp = 10 * tmp + (data[14] - '0');
            if (tmp < 100) { res.err = errLeadingZeros; break; }
            if (tmp > 255) { res.err = errTooBig; break; }
            res.byte[3] = tmp;
            break;
    }
