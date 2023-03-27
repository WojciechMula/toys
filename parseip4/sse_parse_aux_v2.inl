/* Code generated automatically; DO NOT EDIT */
    uint32_t val0;
    uint32_t val1;
    uint32_t val2;
    uint32_t val3;
    switch (code) {
        case 0x55: // [1, 1, 1, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x56: // [1, 1, 1, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x57: // [1, 1, 1, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[6] - '0');
            val3 = 10 * val3 + (byte[7] - '0');
            val3 = 10 * val3 + (byte[8] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x59: // [1, 1, 2, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x5a: // [1, 1, 2, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x5b: // [1, 1, 2, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[7] - '0');
            val3 = 10 * val3 + (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x5d: // [1, 1, 3, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[4] - '0');
            val2 = 10 * val2 + (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x5e: // [1, 1, 3, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[4] - '0');
            val2 = 10 * val2 + (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x5f: // [1, 1, 3, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[4] - '0');
            val2 = 10 * val2 + (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x65: // [1, 2, 1, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x66: // [1, 2, 1, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x67: // [1, 2, 1, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[7] - '0');
            val3 = 10 * val3 + (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x69: // [1, 2, 2, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[5] - '0') + (byte[6] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x6a: // [1, 2, 2, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[5] - '0') + (byte[6] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x6b: // [1, 2, 2, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[5] - '0') + (byte[6] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x6d: // [1, 2, 3, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x6e: // [1, 2, 3, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x6f: // [1, 2, 3, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x75: // [1, 3, 1, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x76: // [1, 3, 1, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x77: // [1, 3, 1, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x79: // [1, 3, 2, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x7a: // [1, 3, 2, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x7b: // [1, 3, 2, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x7d: // [1, 3, 3, 1]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x7e: // [1, 3, 3, 2]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x7f: // [1, 3, 3, 3]
            val0 = (byte[0] - '0');
            res.ipv4 = val0;
            val1 = (byte[2] - '0');
            val1 = 10 * val1 + (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x95: // [2, 1, 1, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x96: // [2, 1, 1, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x97: // [2, 1, 1, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[7] - '0');
            val3 = 10 * val3 + (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x99: // [2, 1, 2, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[5] - '0') + (byte[6] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x9a: // [2, 1, 2, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[5] - '0') + (byte[6] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x9b: // [2, 1, 2, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[5] - '0') + (byte[6] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x9d: // [2, 1, 3, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x9e: // [2, 1, 3, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0x9f: // [2, 1, 3, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[5] - '0');
            val2 = 10 * val2 + (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xa5: // [2, 2, 1, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xa6: // [2, 2, 1, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xa7: // [2, 2, 1, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xa9: // [2, 2, 2, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xaa: // [2, 2, 2, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xab: // [2, 2, 2, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xad: // [2, 2, 3, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xae: // [2, 2, 3, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xaf: // [2, 2, 3, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xb5: // [2, 3, 1, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xb6: // [2, 3, 1, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xb7: // [2, 3, 1, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xb9: // [2, 3, 2, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xba: // [2, 3, 2, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xbb: // [2, 3, 2, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xbd: // [2, 3, 3, 1]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[11] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xbe: // [2, 3, 3, 2]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[11] - '0') + (byte[12] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xbf: // [2, 3, 3, 3]
            val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
            if (val0 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = val0;
            val1 = (byte[3] - '0');
            val1 = 10 * val1 + (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            val3 = 10 * val3 + (byte[13] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xd5: // [3, 1, 1, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xd6: // [3, 1, 1, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xd7: // [3, 1, 1, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[8] - '0');
            val3 = 10 * val3 + (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xd9: // [3, 1, 2, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xda: // [3, 1, 2, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xdb: // [3, 1, 2, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xdd: // [3, 1, 3, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xde: // [3, 1, 3, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xdf: // [3, 1, 3, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[6] - '0');
            val2 = 10 * val2 + (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xe5: // [3, 2, 1, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xe6: // [3, 2, 1, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xe7: // [3, 2, 1, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[9] - '0');
            val3 = 10 * val3 + (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xe9: // [3, 2, 2, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xea: // [3, 2, 2, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xeb: // [3, 2, 2, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xed: // [3, 2, 3, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[11] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xee: // [3, 2, 3, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[11] - '0') + (byte[12] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xef: // [3, 2, 3, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
            if (val1 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[7] - '0');
            val2 = 10 * val2 + (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            val3 = 10 * val3 + (byte[13] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xf5: // [3, 3, 1, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xf6: // [3, 3, 1, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xf7: // [3, 3, 1, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[8] - '0');
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[10] - '0');
            val3 = 10 * val3 + (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xf9: // [3, 3, 2, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[11] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xfa: // [3, 3, 2, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[11] - '0') + (byte[12] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xfb: // [3, 3, 2, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2  = 10 * (byte[8] - '0') + (byte[9] - '0');
            if (val2 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[11] - '0');
            val3 = 10 * val3 + (byte[12] - '0');
            val3 = 10 * val3 + (byte[13] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xfd: // [3, 3, 3, 1]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            val2 = 10 * val2 + (byte[10] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[12] - '0');
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xfe: // [3, 3, 3, 2]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            val2 = 10 * val2 + (byte[10] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3  = 10 * (byte[12] - '0') + (byte[13] - '0');
            if (val3 < 10) { res.err = errLeadingZeros; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
        case 0xff: // [3, 3, 3, 3]
            val0 = (byte[0] - '0');
            val0 = 10 * val0 + (byte[1] - '0');
            val0 = 10 * val0 + (byte[2] - '0');
            if (val0 < 100) { res.err = errLeadingZeros; break; }
            if (val0 > 255) { res.err = errTooBig; break; }
            res.ipv4 = val0;
            val1 = (byte[4] - '0');
            val1 = 10 * val1 + (byte[5] - '0');
            val1 = 10 * val1 + (byte[6] - '0');
            if (val1 < 100) { res.err = errLeadingZeros; break; }
            if (val1 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val1;
            val2 = (byte[8] - '0');
            val2 = 10 * val2 + (byte[9] - '0');
            val2 = 10 * val2 + (byte[10] - '0');
            if (val2 < 100) { res.err = errLeadingZeros; break; }
            if (val2 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val2;
            val3 = (byte[12] - '0');
            val3 = 10 * val3 + (byte[13] - '0');
            val3 = 10 * val3 + (byte[14] - '0');
            if (val3 < 100) { res.err = errLeadingZeros; break; }
            if (val3 > 255) { res.err = errTooBig; break; }
            res.ipv4 = (res.ipv4 << 8) | val3;
            break;
    }
