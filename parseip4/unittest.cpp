#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

#include "common.cpp"
#include "naive.cpp"
#include "sse.cpp"
#include "glibc_ref.cpp"
#include "go_ref.cpp"
#include "swar.cpp"

#include <immintrin.h>

struct testcase {
    std::string ipv4;
    int err;
    std::string name;
};

void generate_wrong_character_testcases(std::vector<testcase>& tc) {
    static const std::string pat("123");
    static const std::string wrong("?/\xf1");

    for (unsigned i=0; i <= 255; i++) {
        const unsigned l0 = (i >> 2*0) & 0x3;
        const unsigned l1 = (i >> 2*1) & 0x3;
        const unsigned l2 = (i >> 2*2) & 0x3;
        const unsigned l3 = (i >> 2*3) & 0x3;

        if (l0 == 0 || l1 == 0 || l2 == 0 || l3 == 0) {
            continue;
        }

        std::string ipv4;
        ipv4.append(pat.substr(0, l0));
        ipv4.push_back('.');
        ipv4.append(pat.substr(0, l1));
        ipv4.push_back('.');
        ipv4.append(pat.substr(0, l2));
        ipv4.push_back('.');
        ipv4.append(pat.substr(0, l3));

        for (size_t j=0; j < ipv4.size(); j++) {
            if (ipv4[j] == '.') {
                continue;
            }

            const auto orig = ipv4[j];
            for (char c: wrong) {
                ipv4[j] = c;
                tc.push_back({ipv4, errWrongCharacter, "wrong character"});
            }

            ipv4[j] = orig;
        }
    }
}

void generate_leading_zeros_testcases(std::vector<testcase>& tc) {
    static const std::string pat2("123");

    for (unsigned i=0; i <= 255; i++) {
        const unsigned l0 = (i >> 2*0) & 0x3;
        const unsigned l1 = (i >> 2*1) & 0x3;
        const unsigned l2 = (i >> 2*2) & 0x3;
        const unsigned l3 = (i >> 2*3) & 0x3;

        if (l0 == 0 || l1 == 0 || l2 == 0 || l3 == 0) {
            continue;
        }

        bool haszero;
        auto word = [&haszero](unsigned len, bool leading) -> std::string {
            switch (len) {
                case 1:
                    return "1";
                case 2:
                    if (leading) {
                        haszero = true;
                        return "02";
                    } else {
                        return "12";
                    }
                case 3:
                    if (leading) {
                        haszero = true;
                        return "023";
                    } else {
                        return "123";
                    }
            }

            return "?";
        };

        for (unsigned k=1; k < 16; k++) {
            haszero = false;
            std::string ipv4;
            ipv4.append(word(l0, (k & 0x1) != 0));
            ipv4.push_back('.');
            ipv4.append(word(l1, (k & 0x2) != 0));
            ipv4.push_back('.');
            ipv4.append(word(l2, (k & 0x4) != 0));
            ipv4.push_back('.');
            ipv4.append(word(l3, (k & 0x8) != 0));

            if (haszero) {
                tc.push_back({ipv4, errLeadingZeros, "leading zeros"});
            }
        }
    }
}

template <typename T>
bool test_wrong_input(T procedure) {
    std::vector<testcase> testcases = {
        {"ip", errTooShort, "string too short"},
        {"Not an IPv4 at all!!", errTooLong, "string too short"},
        {"123.123.123.124    ", errTooLong, "string too long"},
        {"a.0.0.0", errWrongCharacter, "not a digit"},
        {"0.z.0.0", errWrongCharacter, "not a digit"},
        {"0.0.?.0", errWrongCharacter, "not a digit"},
        {"0.0.0.%", errWrongCharacter, "not a digit"},
        {"1a.0.0.%", errWrongCharacter, "not a digit"},
        {"1.2.3.4.5", errTooManyFields, "too many dots"},
        {"192.168.10", errTooFewFields, "too few dots"},
        {"1.2.3.400", errTooBig, "too big number"},
        {"192.2..4", errEmptyField, "too few chars"},
        {"1.2.11111.4", errTooManyDigits | errTooBig, "too many chars"},
        {"12:.12:.12:.12:", errWrongCharacter, "wrong input"},

        // testcases copied from Go: src/net/netip/netip_test.go
        {"", errInvalidInput, "Empty string"},
        {"bad", errInvalidInput, "Garbage non-IP"},
        {"1234", errInvalidInput, "Single number"},
        {"1.2.3.4%eth0", errInvalidInput, "IPv4 with a zone specifier"},
        {".1.2.3", errInvalidInput, "IPv4 field must have at least one digit (1)"},
        {"1.2.3", errInvalidInput, "IPv4 field must have at least one digit (2)"},
        {"1..2.3", errInvalidInput, "IPv4 field must have at least one digit (3)"},
        {"1.2.3.4.5", errInvalidInput, "IPv4 address too long"},
		{"0300.0250.0214.0377", errInvalidInput, "IPv4 in dotted octal form"},
        {"0xc0.0xa8.0x8c.0xff", errInvalidInput, "IPv4 in dotted hex form"},
		{"192.168.12345", errInvalidInput, "IPv4 in class B form (1)"},
        {"127.0.1", errInvalidInput, "IPv4 in class B form (2)"},
        {"192.1234567", errInvalidInput, "IPv4 in class A form (1)"},
        {"127.1", errInvalidInput, "IPv4 in class A form (2)"},
        {"192.168.300.1", errInvalidInput, "IPv4 field has value >255"},
        {"192.168.0.1.5.6", errInvalidInput, "IPv4 with too many fields"}
    };

    // more auto-generated tests
    generate_wrong_character_testcases(testcases);
    generate_leading_zeros_testcases(testcases);

    bool ok = true;
    for (const auto& tc: testcases) {
        const auto res = procedure(tc.ipv4);
        if ((res.err & tc.err) == 0) {
            printf("Test %s: %s\n", tc.ipv4.c_str(), tc.name.c_str());
            const auto& gs = describeErr(res.err);
            const auto& ws = describeErr(tc.err);
            printf("\tgot : %s\n", gs.c_str());
            printf("\twant: %s\n", ws.c_str());
            ok = false;
            break;
        }
    }

    return ok;
}

std::string ipv4str(uint32_t x) {
    char tmp[16];
    sprintf(tmp, "%d.%d.%d.%d", x & 0xff, (x >> 8) & 0xff, (x >> 16) & 0xff, (x >> 24));

    return tmp;
}


template <typename T>
bool test_valid_inputs(T procedure) {
    int i = 0;
    for (uint64_t tmp = 0; tmp <= 0xffffffff; tmp += 1031) {
        uint32_t ipv4 = tmp;
        const std::string img = ipv4str(ipv4);

        const auto res = procedure(img);
        if (res.err != 0) {
            printf("IPv4: %s\n", img.c_str());
            printf("hex : %08x\n", ipv4);
            printf("reported error: %s\n", describeErr(res.err).c_str());
            return false;
        }

        if (res.ipv4 != uint32_t(ipv4)) {
            printf("IPv4: %s\n", img.c_str());
            printf("got : %08x\n", res.ipv4);
            printf("want: %08x\n", ipv4);
            printf("wrongly parsed\n");
            return false;
        }

        i++;
    }

    return true;
}

int8_t get(__m128i x) {
    return _mm_cvtsi128_si32(x) & 0xff;
}

int main(int argc, char* argv[]) {
    srand(0);

    bool ok = true;

    std::vector<std::string> args;
    for (int i=1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    auto run = [&args](const std::string& name) {
        if (args.empty()) {
            return true;
        }

        for (const auto& s: args) {
            if (name == s) {
                return true;
            }
        }

        return false;
    };

    if (run("go")) {
        puts("go");
        ok = test_wrong_input(go_parse_ipv4) && ok;
        ok = test_valid_inputs(go_parse_ipv4) && ok;
    }

    if (run("glibc")) {
        puts("glibc");
        ok = test_wrong_input(glibc_parse_ipv4) && ok;
        ok = test_valid_inputs(glibc_parse_ipv4) && ok;
    }

    if (run("naive")) {
        puts("naive");
        ok = test_wrong_input(naive_parse_ipv4) && ok;
        ok = test_valid_inputs(naive_parse_ipv4) && ok;
    }

    if (run("naive (no validation)")) {
        puts("naive (no validation)");
        ok = test_valid_inputs(naive_parse_ipv4_no_validation) && ok;
    }

    if (run("SWAR")) {
        puts("swar");
        ok = test_wrong_input(swar_parse_ipv4) && ok;
        ok = test_valid_inputs(swar_parse_ipv4) && ok;
    }

    if (run("SSE")) {
        puts("SSE");
        ok = test_wrong_input(sse_parse_ipv4) && ok;
        ok = test_valid_inputs(sse_parse_ipv4) && ok;
    }

    if (run("SSE (v2)")) {
        puts("SSE (v2)");
        ok = test_wrong_input(sse_parse_ipv4_v2) && ok;
        ok = test_valid_inputs(sse_parse_ipv4_v2) && ok;
    }

    if (run("SSE (v3)")) {
        puts("SSE (v3)");
        ok = test_wrong_input(sse_parse_ipv4_v3) && ok;
        ok = test_valid_inputs(sse_parse_ipv4_v3) && ok;
    }

    if (run("SSE (v4)")) {
        puts("SSE (v4)");
        ok = test_wrong_input(sse_parse_ipv4_v4) && ok;
        ok = test_valid_inputs(sse_parse_ipv4_v4) && ok;
    }

    if (run("SSE (v5)")) {
        puts("SSE (v5)");
        ok = test_wrong_input(sse_parse_ipv4_v5) && ok;
        ok = test_valid_inputs(sse_parse_ipv4_v5) && ok;
    }

    if (run("SSE (v6)")) {
        puts("SSE (v6)");
        ok = test_wrong_input(sse_parse_ipv4_v6) && ok;
        ok = test_valid_inputs(sse_parse_ipv4_v6) && ok;
    }

    if (run("SSE (v7)")) {
        puts("SSE (v7)");
        ok = test_wrong_input(sse_parse_ipv4_v7) && ok;
        ok = test_valid_inputs(sse_parse_ipv4_v7) && ok;
    }

    if (ok) {
        puts("All OK");
    }
}
