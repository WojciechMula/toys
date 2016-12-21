uint64_t __attribute__((never_inline)) x86_bfs(const uint64_t* data, size_t n) {

    uint64_t ptr;
    uint64_t res;

    asm volatile (
        "mov   %[data], %[ptr]              \n"
        "sub   $8, %[ptr]                   \n"
        "0:\n" // main loop
        "add   $8, %[ptr]                   \n"
        "cmp   %[ptr], %[end]               \n"
        "je    2f                           \n"

        "tzcnt (%[ptr]), %[res]             \n"
        "jz    0b                           \n" // goto main loop

        "sub   %[data], %[ptr]              \n" // ptr -= data
        "lea   (%[res], %[ptr], 8), %[res]  \n" // return ptr*8 + bfs
        "jmp   3f                           \n"

        "2:\n" // end of the loop
        "mov   $-1, %[res]                   \n"
        "3:\n"

        : [ptr]     "+r" (ptr)
        , [res]     "+r" (res)

        : [data]    "r" (data)
        , [end]     "r" (data + n)

        : "cc"
    );

    return res;
}
