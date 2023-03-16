#include "go_ref.h"

/*
func parseIPv4(s string) (ip Addr, err error) {
	var fields [4]uint8
	var val, pos int
	var digLen int // number of digits in current octet
	for i := 0; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			if digLen == 1 && val == 0 {
				return Addr{}, parseAddrError{in: s, msg: "IPv4 field has octet with leading zero"}
			}
			val = val*10 + int(s[i]) - '0'
			digLen++
			if val > 255 {
				return Addr{}, parseAddrError{in: s, msg: "IPv4 field has value >255"}
			}
		} else if s[i] == '.' {
			// .1.2.3
			// 1.2.3.
			// 1..2.3
			if i == 0 || i == len(s)-1 || s[i-1] == '.' {
				return Addr{}, parseAddrError{in: s, msg: "IPv4 field must have at least one digit", at: s[i:]}
			}
			// 1.2.3.4.5
			if pos == 3 {
				return Addr{}, parseAddrError{in: s, msg: "IPv4 address too long"}
			}
			fields[pos] = uint8(val)
			pos++
			val = 0
			digLen = 0
		} else {
			return Addr{}, parseAddrError{in: s, msg: "unexpected character", at: s[i:]}
		}
	}
	if pos < 3 {
		return Addr{}, parseAddrError{in: s, msg: "IPv4 address too short"}
	}
	fields[3] = uint8(val)
	return AddrFrom4(fields), nil
}
*/

result go_parse_ipv4(const std::string& s) {
    result r;
    r.err = 0;
    union {
        uint8_t fields[4];
        uint32_t u32;
    };

    int val = 0;
    int pos = 0;
    int digiLen = 0;

    for (size_t i=0; i < s.size(); i++) {
        const uint8_t b = s[i];
        if (b >= '0' && b <= '9') {
            if (digiLen == 1 && val == 0) {
                r.err = errLeadingZeros;
                return r;
            }

            val = val*10 + b - '0';
            digiLen++;
            if (val > 255) {
                r.err = errTooBig;
                return r;
            }
        } else if (b == '.') {
            if (i == 0 || i == s.size() - 1 || s[i-1] == '.') {
                r.err = errInvalidInput;
                return r;
            }

            if (pos == 3) {
                r.err = errTooManyFields;
                return r;
            }

            fields[pos] = val;
            pos++;
            val = 0;
            digiLen = 0;
        } else {
            r.err = errInvalidInput;
            return r;
        }
    }

	if (pos < 3) {
        r.err = errTooFewFields;
        return r;
	}
	fields[3] = val;

    r.ipv4 = u32;

    return r;
}
