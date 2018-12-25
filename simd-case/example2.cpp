#include <cstdio>

int code_block(int x) {

    int result = -1;

    switch (x) {
        case 0:
            puts("zero");
            break;

        case 3:
            puts("one");
            result = 42;
            break;

        case 4:
            puts("two");
            result = 42;
            break;

        case 7:
            puts("three");
            result = 1024;
            break;

        case 8:
            puts("four");
            result = 42;
            break;

        case 11:
            puts("five");
            result = 1024;
            break;
    }

    return result;
}
