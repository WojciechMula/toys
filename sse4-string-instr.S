/*

    compile: gcc -c {other flgs} sse4-string-instr.S

*/


/* imm8 defs: */
#define SSESTR_PACKED_UBYTE     0
#define SSESTR_PACKED_UWORD     0b01
#define SSESTR_PACKED_SBYTE     0b10
#define SSESTR_PACKED_SWORD     0b11

#define SSESTR_EQUAL_ANY        0
#define SSESTR_EQUAL_EACH       0b1000
#define SSESTR_EQUAL_ORDERED    0b1100
#define SSESTR_RANGES           0b0100

#define SSESTR_UNCHANGED        0
#define SSESTR_NEGATED          0b010000
#define SSESTR_NEGATED_VALID    0b110000

#define SSESTR_BITMASK          0
#define SSESTR_BYTEMASK         0b1000000

#define SSESTR_FIRSTBIT         0
#define SSESTR_LASTBIT          0b1000000


#undef L
#define L(name) .L_a##name

/* int strcmp(const char s1, const char* s2);

   inputs:
   - %esi -- s1
   - %edi -- s2

   result
   - %eax
 */
strcmp:
    imm8 = SSESTR_PACKED_UBYTE  | \
           SSESTR_EQUAL_EACH    | \
           SSESTR_NEGATED_VALID | \
           SSESTR_FIRSTBIT

    L(mainloop):
        movups  (%esi), %xmm1           # load 16 bytes
        movups  (%esi), %xmm2           # from s1 & s2
        add     $16,    %esi
        add     $16,    %edi

        # implict length string compare for equal

        pcmpistri $imm8, %xmm2, %xmm1
        # sample 1 (strings different):
        #       xmm1 -> "string\0..."
        #       xmm2 -> "strXng\0..."
        #
        #       IntRes1 -> 000000011110111
        #       IntRes2 -> 000000000001000 (negated valid)
        #       ECX     := bfs(IntRes2) = 3
        #       CF      := 1 (IntRes2 <> 0)
        #       ZF      := 0
        #
        # sample 2 (strings equal, but null byte found):
        #       xmm1 -> "string\0..."
        #       xmm2 -> "string\0..."
        #
        #       IntRes1 -> 000000011111111
        #       IntRes2 -> 000000000000000 (negated valid)
        #       ECX     := 16 (no bits in IntRes2)
        #       CF      := 0 (IntRes2 == 0, no diffs)
        #       ZF      := 1 (EOS, i.e. null byte in xmm2)

        jc  L(diff_found)
        jnz L(mainloop)

    L(null_found):
        # we have to find null position
        pxor     %xmm0, %xmm0
        pcmpeqb  %xmm2, %xmm0
        pmovmskb %xmm0, %ecx
        bsf      %ecx,  %ecx
    L(diff_found):
        movb    -16(%edi, %ecx), %edx
        movb    -16(%esi, %ecx), %eax
        sub     %edx, %eax
        ret



#undef L
#define L(name) .L_b##name
