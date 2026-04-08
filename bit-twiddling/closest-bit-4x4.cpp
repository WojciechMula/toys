/*
    The problem is given as follows:

    There's a 4x4 array of bits (a 16-bit value), never empty, never full.
    Let call it A.

    There's a point P=(x, y) at this grid. The point may be seen
    as another 4x4 bit array having exactly one bit set.

    The point is ALWAYS located at zero bit in A. In terms of bitmask,
    bit-and of A and point is always zero.

    We want to find a set bit in A which is closest to the given point.
    If there are more than one bits having the minium distance, return
    all. Distance is measured using the Manhattan distance.

    Example:

        A:             P:               distances:
            0 1 0 0         0 0 0 0     2 1 2 3
            1 0 0 1         0 1 0 0     1 0 1 2
            1 0 1 0         0 0 0 0     2 1 2 3
            1 1 1 1         0 0 0 0     3 2 3 4

        the closest bits having distance = 1:

            0 1 0 0
            1 0 0 0
            0 0 0 0
            0 0 0 0
*/

/*
    The proposed solution uses the following approach. There are only 16 possible
    positions of the point P. For each of them we calculate the set of bitmasks,
    marking bits having distance 1, 2, 3, 4, 5 or 6 (thus, we have 6 masks x 16 possible
    points).

    We then check sequentially these mask against the array A, and if any
    bit-and result is non-zero we return the first bit set.
*/

#include <cstdint>
#include <cassert>
#include <cstdlib>
#include <cstdio>

class App {
    uint16_t bitmasks [16][6];

public:
    App() {
        for (int pos=0; pos < 16; pos++) {
            for (int mask=0; mask < 6; mask++) {
                bitmasks[pos][mask] = 0;
            }
        }

        for (int px=0; px < 4; px++) {
            for (int py=0; py < 4; py++) {
                precalculate_aux(px, py);
            }
        }
    }

    void run() {
        srand(42);

        const int N = 10;

        for (int i=0; i < N; i++) {
            const uint16_t a = random_array();
            const int      p_index = random_point(a);
            const uint16_t p = 1 << p_index;

            assert((p & a) == 0);

            const uint16_t closest = find_closest(a, p_index);

            if (i > 0) {
                putchar('\n');
            }
            show(a, p, closest);
        }
    }

private:
    uint16_t random_array() {
        while (true) {
            const uint16_t result = rand();
            if (result != 0 and result != 0xffff) {
                return result;
            }
        }
    }

    int random_point(uint16_t a) {
        while (true) {
            const int index = rand() % 16;
            const uint16_t bit = 1 << index;

            if ((bit & a) == 0) {
                return index;
            }
        }
    }

    uint16_t find_closest(uint16_t a, int p_index) {
        assert(a != 0);
        assert(p_index >= 0);
        assert(p_index < 16);

        for (int mask_idx=0; mask_idx < 6; mask_idx++) {
            const uint16_t mask = bitmasks[p_index][mask_idx];
            const uint16_t res = a & mask;
            if (res != 0) {
                return res;
            }
        }

        assert(false);
    }

    void show(uint16_t a, uint16_t p, uint16_t s) {
        printf("A:          p:           result:\n");

        for (int y=0; y < 4; y++) {
            printf("  ");
            show_row(a, y);

            printf("    ");
            show_row(p, y);

            printf("  ");
            show_row(s, y);

            putchar('\n');
        }
    }

    void show_row(uint16_t mask, int y) {
        for (int x=0; x < 4; x++) {
            printf(" %c", get_bit(mask, x, y) ? '1' : '0');
        }
    }

private:
    int absdiff(int a, int b) {
        return a >= b ? a - b : b - a;
    }

    int distance(int x1, int y1, int x2, int y2) {
        const int dx = absdiff(x1, x2);
        const int dy = absdiff(y1, y2);

        return dx + dy;
    }

    void precalculate_aux(int px, int py) {
        const int set_id = px + py * 4;

        for (int x=0; x < 4; x++) {
            for (int y=0; y < 4; y++) {
                const int d = distance(px, py, x, y);
                if (d > 0) {
                    assert(d <= 6);
                    set_bit(bitmasks[set_id][d - 1], x, y);
                }
            }
        }
    }

    void set_bit(uint16_t& bitmask, int x, int y) {
        const uint16_t bit = 1 << (x + y * 4);

        bitmask |= bit;
    }

    bool get_bit(uint16_t bitmask, int x, int y) {
        const uint16_t bit = 1 << (x + y * 4);

        return bitmask & bit;
    }
};

int main() {
    App app;

    app.run();

    return 0;
}
