#include "utf8_visitor.h"

enum STATE {
    START_BYTE,

    SEQ2_BYTE2,

    SEQ3_BYTE2,
    SEQ3_BYTE3,

    SEQ4_BYTE2,
    SEQ4_BYTE3,
    SEQ4_BYTE4,
};

void utf8_visit(Visitor& visitor, const uint8_t* bytes, size_t size) {
    STATE state = START_BYTE;
    for (size_t i=0; i < size; i++) {
        const uint8_t byte = bytes[i];
        if ((byte & 0x80) == 0x00) {
            if (state == START_BYTE) {
                visitor.ansi(i, byte);
                continue;
            }
        }

        if ((byte & 0xf8) == 0xf0) {
            if (state == START_BYTE) {
                visitor.seq4_head(i, byte);
                state = SEQ4_BYTE2;
                continue;
            }
        }

        if ((byte & 0xf0) == 0xe0) {
            if (state == START_BYTE) {
                visitor.seq3_head(i, byte);
                state = SEQ3_BYTE2;
                continue;
            }
        }

        if ((byte & 0xe0) == 0xc0) {
            if (state == START_BYTE) {
                visitor.seq2_head(i, byte);
                state = SEQ2_BYTE2;
                continue;
            }
        }

        if ((byte & 0xc0) == 0x80) {
            switch (state) {
                case SEQ2_BYTE2:
                    visitor.tail(i, byte);
                    state = START_BYTE;
                    continue;

                case SEQ3_BYTE2:
                    visitor.tail(i, byte);
                    state = SEQ3_BYTE3;
                    continue;

                case SEQ3_BYTE3:
                    visitor.tail(i, byte);
                    state = START_BYTE;
                    continue;

                case SEQ4_BYTE2:
                    visitor.tail(i, byte);
                    state = SEQ4_BYTE3;
                    continue;

                case SEQ4_BYTE3:
                    visitor.tail(i, byte);
                    state = SEQ4_BYTE4;
                    continue;

                case SEQ4_BYTE4:
                    visitor.tail(i, byte);
                    state = START_BYTE;
                    continue;
            }
        }

        // no match
        visitor.invalid(i, byte);
        state == START_BYTE;
    }

    // we may detect a truncated sequence (when state != START_BYTE)
    visitor.eos();
}

