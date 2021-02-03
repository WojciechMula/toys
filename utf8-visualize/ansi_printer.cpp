#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <stdexcept>

#include "utf8_visitor.h"

class ANSIPrinter: public Visitor {
protected:
    static constexpr int RESET = 0;
    static constexpr int RED = 31;
    static constexpr int GREEN = 32;
    static constexpr int BROWN = 33;
    static constexpr int CYAN = 36;
    static constexpr int field_width = 8 + 1;

protected:
    void ecma48(int param) {
        printf("\x1b[%dm", param);
    }
};

class BinPrinter: public ANSIPrinter {
public:
    virtual void ansi(size_t, uint8_t byte) override {
        print_bits(byte, 1, CYAN, GREEN);
    }

    virtual void seq2_head(size_t, uint8_t byte) override {
        print_bits(byte, 3, CYAN, GREEN);
    }

    virtual void seq3_head(size_t, uint8_t byte) override {
        print_bits(byte, 4, CYAN, GREEN);
    }

    virtual void seq4_head(size_t, uint8_t byte) override {
        print_bits(byte, 5, CYAN, GREEN);
    }

    virtual void tail(size_t, uint8_t byte) override {
        print_bits(byte, 2, BROWN, GREEN);
    }

    virtual void invalid(size_t, uint8_t byte) override {
        putchar('|');

        ecma48(RED);

        int i;
        for (i=0; i < 4; i++)
            putchar(revbit(byte, i) ? '1' : '0');

        putchar(' ');

        for (/**/; i < 8; i++)
            putchar(revbit(byte, i) ? '1' : '0');

        ecma48(RESET);
    }

    virtual void eos() override {
        putchar('|');
        putchar('\n');
    }
private:
    void print_bits(uint8_t byte, int header, int head_color, int tail_color) {
        int i;
        putchar('|');

        ecma48(head_color);
        for (i=0; i < header; i++)
            putchar(revbit(byte, i) ? '1' : '0');
        ecma48(RESET);

        if (header > 0)
            putchar('.');

        ecma48(tail_color);
        for (/**/; i < 8; i++)
            putchar(revbit(byte, i) ? '1' : '0');
        ecma48(RESET);
    }

    bool revbit(uint8_t byte, int k) const {
        assert((k >= 0) && (k <= 7));
        return (byte & (1 << (7 - k))) != 0;
    }
};

class HexPrinter: public ANSIPrinter {

public:
    virtual void ansi(size_t, uint8_t byte) override {
        print_char(byte);
    }

    virtual void seq2_head(size_t, uint8_t byte) override {
        print_char(byte);
    }

    virtual void seq3_head(size_t, uint8_t byte) override {
        print_char(byte);
    }

    virtual void seq4_head(size_t, uint8_t byte) override {
        print_char(byte);
    }

    virtual void tail(size_t, uint8_t byte) override {
        print_char(byte, BROWN);
    }

    virtual void invalid(size_t, uint8_t byte) override {
        print_char(byte, RED);
    }

    virtual void eos() override {
        putchar('|');
        putchar('\n');
    }
private:
    void print_char(uint8_t byte, int color) {
        printf("|");

        ecma48(color);
        printf("%*X", field_width, byte);
        ecma48(RESET);
    }

    void print_char(uint8_t byte) {
        print_char(byte, RESET);
    }
};

void print_utf8(const std::string& s) {
    HexPrinter hex;
    utf8_visit(hex, reinterpret_cast<const uint8_t*>(s.data()), s.size());
    BinPrinter bin;
    utf8_visit(bin, reinterpret_cast<const uint8_t*>(s.data()), s.size());
}

char ansihex_to_nibble(char c) {
    if ((c >= '0') and (c <= '9'))
        return c - '0';

    if ((c >= 'a') and (c <= 'f'))
        return c - 'a' + 10;

    if ((c >= 'A') and (c <= 'F'))
        return c - 'A' + 10;

    throw std::invalid_argument("wrong hex digit");
}

std::string transcode(const char* s) {
    std::string result;
    const char* c = s;
    while (*c) {
        if (*c == '\\') {
            c++;
            if (*c != 'x')
                throw std::invalid_argument(R"(expected 'x' after '\n')");
            c++;
            const uint8_t d1 = ansihex_to_nibble(*c++);
            const uint8_t d0 = ansihex_to_nibble(*c++);
            result.push_back(d1 * 16 + d0);
        }
        else
            result.push_back(*c++);
    }

    return result;
}

int main(int argc, char* argv[]) {
    for (int i=1; i < argc; i++) {
        print_utf8(transcode(argv[i]));
    }
}
