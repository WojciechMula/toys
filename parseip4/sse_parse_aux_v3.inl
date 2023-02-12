    uint32_t val0;
    uint32_t val1;
    uint32_t val2;
    uint32_t val3;
    switch (ipv4.size()) {
        case 7: // 1 case(s)
            switch (dotmask & 0x7f) {
                case 0x2a:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[6] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 8: // 4 case(s)
            switch (dotmask & 0xff) {
                case 0x2a:
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
                case 0x4a:
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
                case 0x52:
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
                case 0x54:
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
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 9: // 10 case(s)
            switch (dotmask & 0x1ff) {
                case 0x2a:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[6] - '0');
                    val3 = 10 * val3 + (byte[7] - '0');
                    val3 = 10 * val3 + (byte[8] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x4a:
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
                case 0x8a:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[4] - '0');
                    val2 = 10 * val2 + (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[8] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x52:
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
                case 0x92:
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
                case 0xa2:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[8] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x54:
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
                case 0x94:
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
                case 0xa4:
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
                case 0xa8:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[8] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 10: // 16 case(s)
            switch (dotmask & 0x3ff) {
                case 0x4a:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x8a:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[4] - '0');
                    val2 = 10 * val2 + (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x52:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x92:
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
                case 0x112:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0xa2:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x122:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x54:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x94:
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
                case 0x114:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0xa4:
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
                case 0x124:
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
                case 0x144:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0xa8:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                case 0x128:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                case 0x148:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 11: // 19 case(s)
            switch (dotmask & 0x7ff) {
                case 0x8a:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[4] - '0');
                    val2 = 10 * val2 + (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[8] - '0');
                    val3 = 10 * val3 + (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x92:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x112:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0xa2:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[8] - '0');
                    val3 = 10 * val3 + (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x122:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x222:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x94:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x114:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0xa4:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x124:
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
                case 0x224:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x144:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[9] - '0') + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x244:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0xa8:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[8] - '0');
                    val3 = 10 * val3 + (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x128:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                case 0x228:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x148:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                case 0x248:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                case 0x288:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[8] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 12: // 16 case(s)
            switch (dotmask & 0xfff) {
                case 0x112:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1  = 10 * (byte[2] - '0') + (byte[3] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x122:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[6] - '0') + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x222:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x114:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[5] - '0');
                    val2 = 10 * val2 + (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x124:
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x224:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x144:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[9] - '0');
                    val3 = 10 * val3 + (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x244:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x444:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[11] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x128:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x228:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x148:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x248:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                case 0x448:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[11] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x288:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[8] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[10] - '0') + (byte[11] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x488:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[11] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 13: // 10 case(s)
            switch (dotmask & 0x1fff) {
                case 0x222:
                    val0 = (byte[0] - '0');
                    res.ipv4 = val0;
                    val1 = (byte[2] - '0');
                    val1 = 10 * val1 + (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x224:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1  = 10 * (byte[3] - '0') + (byte[4] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x244:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[7] - '0') + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x444:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[11] - '0') + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x228:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[6] - '0');
                    val2 = 10 * val2 + (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x248:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
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
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x448:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[11] - '0') + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x288:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[8] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[10] - '0');
                    val3 = 10 * val3 + (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x488:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[11] - '0') + (byte[12] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x888:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    val2 = 10 * val2 + (byte[10] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[12] - '0');
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 14: // 4 case(s)
            switch (dotmask & 0x3fff) {
                case 0x444:
                    val0  = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = val0;
                    val1 = (byte[3] - '0');
                    val1 = 10 * val1 + (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    val3 = 10 * val3 + (byte[13] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x448:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1  = 10 * (byte[4] - '0') + (byte[5] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[7] - '0');
                    val2 = 10 * val2 + (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    val3 = 10 * val3 + (byte[13] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x488:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2  = 10 * (byte[8] - '0') + (byte[9] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[11] - '0');
                    val3 = 10 * val3 + (byte[12] - '0');
                    val3 = 10 * val3 + (byte[13] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                case 0x888:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    val2 = 10 * val2 + (byte[10] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3  = 10 * (byte[12] - '0') + (byte[13] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
        case 15: // 1 case(s)
            switch (dotmask & 0x7fff) {
                case 0x888:
                    val0 = (byte[0] - '0');
                    val0 = 10 * val0 + (byte[1] - '0');
                    val0 = 10 * val0 + (byte[2] - '0');
                    if (val0 < 10) { res.err = errLeadingZeros; break; }
                    if (val0 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = val0;
                    val1 = (byte[4] - '0');
                    val1 = 10 * val1 + (byte[5] - '0');
                    val1 = 10 * val1 + (byte[6] - '0');
                    if (val1 < 10) { res.err = errLeadingZeros; break; }
                    if (val1 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val1;
                    val2 = (byte[8] - '0');
                    val2 = 10 * val2 + (byte[9] - '0');
                    val2 = 10 * val2 + (byte[10] - '0');
                    if (val2 < 10) { res.err = errLeadingZeros; break; }
                    if (val2 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val2;
                    val3 = (byte[12] - '0');
                    val3 = 10 * val3 + (byte[13] - '0');
                    val3 = 10 * val3 + (byte[14] - '0');
                    if (val3 < 10) { res.err = errLeadingZeros; break; }
                    if (val3 > 255) { res.err = errTooBig; break; }
                    res.ipv4 = (res.ipv4 << 8) | val3;
                    break;
                default:
                    res.err = errInvalidInput;
                    return res;
            }
            break;
    }
