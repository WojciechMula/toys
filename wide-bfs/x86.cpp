uint64_t x86_bfs(const uint64_t* data, size_t n) {

    uint64_t ptr;

    asm volatile (
        "mov  %[data], %[ptr]           \n"
        "sub  $8, %[ptr]                \n"
        "0:                             \n" // main loop
        "add  $8, %[ptr]                \n"
        "cmp  %[ptr], %[end]            \n"
        "je   2f                        \n"

        "bsf  (%[ptr]), %%rax           \n"
        "jz   0b                        \n" // goto main loop

        "sub  %[data], %[ptr]           \n"
        "shl  $3, %[ptr]                \n" // (ptr - data) * 8
        "add  %[ptr], %%rax             \n" // + bsf
        "ret                            \n"

        "2:\n"
        "mov  $-1, %%rax                \n"
        "ret                            \n"

        : [ptr]     "+r" (ptr)
        : [data]    "r" (data)
        , [end]     "r" (data + n)
        : "cc", "rax"
    );
}
