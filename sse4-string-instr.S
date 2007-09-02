/*
    Some functions that use SSE4 string instructions:
      * strcmp
      * strncmp
      * strchr
      * strrchr

    Warning: these function were not tested yet!
    However they **should** work fine.
    
    Author: Wojciech Mula
    e-mail: wojciech_mula@poczta.onet.pl
    www:    http://www.mula.w.pl
    
    License: public domain

    Compile:
        gcc -c {other flgs} sse4-string-instr.S

*/


/* imm8 defs: */
#define SSESTR_PACKED_UBYTE     0               /* element size */
#define SSESTR_PACKED_UWORD     0b01
#define SSESTR_PACKED_SBYTE     0b10
#define SSESTR_PACKED_SWORD     0b11

#define SSESTR_EQUAL_ANY        0               /* equal type */
#define SSESTR_EQUAL_EACH       0b1000
#define SSESTR_EQUAL_ORDERED    0b1100
#define SSESTR_RANGES           0b0100

#define SSESTR_UNCHANGED        0               /* IntRes1 polariy */
#define SSESTR_NEGATED          0b010000
#define SSESTR_NEGATED_VALID    0b110000

#define SSESTR_BITMASK          0               /* output selection */
#define SSESTR_BYTEMASK         0b1000000       /* for PCMPxSTRM */

#define SSESTR_FIRSTBIT         0               /* output selection */
#define SSESTR_LASTBIT          0b1000000       /* for PCMPxSTRI */


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
        movups  (%edi), %xmm2           # from s1 & s2
        add     $16,    %esi
        add     $16,    %edi

        # implict length string compare for equal

        pcmpistri $imm8, %xmm2, %xmm1
        # sample 1 (strings different):
        #       xmm1 -> "string\0..."
        #       xmm2 -> "strXng\0..."
        #
        #       IntRes1 -> 000000001110111
        #       IntRes2 -> 000000000001000 (negated valid)
        #       ECX     := bfs(IntRes2) = 3
        #       CF      := 1 (IntRes2 <> 0)
        #       ZF      := 0
        #
        # sample 2 (strings equal, but null byte found):
        #       xmm1 -> "string\0..."
        #       xmm2 -> "string\0..."
        #
        #       IntRes1 -> 000000001111111
        #       IntRes2 -> 000000000000000 (negated valid)
        #       ECX     := 16 (no bits in IntRes2)
        #       CF      := 0 (IntRes2 == 0, no diffs)
        #       ZF      := 1 (EOS, i.e. null byte in xmm2)

        jc  L(diff_found)
        jnz L(mainloop)

    L(null_found):
        # get EOS position
        pxor     %xmm0, %xmm0
        pcmpeqb  %xmm2, %xmm0
        pmovmskb %xmm0, %ecx
        bsf      %ecx,  %ecx
    L(diff_found):
        movzbl  -16(%edi, %ecx), %edx
        movzbl  -16(%esi, %ecx), %eax
        sub     %edx, %eax
        ret



#undef L
#define L(name) .L_b##name

/* int strncmp(const char s1, const char* s2, size_t n);

   inputs:
   - %esi -- s1
   - %edi -- s2
   - %eax -- n

   result
   - %eax
 */
strncmp:
        imm8 = SSESTR_PACKED_UBYTE  | \
               SSESTR_EQUAL_EACH    | \
               SSESTR_NEGATED_VALID | \
               SSESTR_FIRSTBIT


        xor  %ecx, %ecx
        test %eax, %eax  # n == 0 ?
        jz   L(diff_found)
       
        # n > 0 
        add  $16,  %eax
        mov  %eax, %edx  # make length of both strings equal
    
    L(mainloop):
        movups  (%esi), %xmm1           # load 16 bytes
        movups  (%edi), %xmm2           # from s1 & s2
        add     $16,    %esi
        add     $16,    %edi
        
        sub     $16,    %eax            # dec. length

        # explicit length string compare for equal

        pcmpestri $imm8, %xmm2, %xmm1
        # for some samples see comments in strcmp

        jc  L(diff_found)
        jnz L(mainloop)

    L(null_found):
        # get EOS position
        pxor     %xmm0, %xmm0
        pcmpeqb  %xmm2, %xmm0
        pmovmskb %xmm0, %ecx
        bsf      %ecx,  %ecx
    L(diff_found):
        movzbl  -16(%edi, %ecx), %edx
        movzbl  -16(%esi, %ecx), %eax
        sub     %edx, %eax
        ret



#undef L
#define L(name) .L_c##name

/* char* strchr(const char s, int c);

   inputs:
   - %esi -- s
   - %eax -- c

   result
   - %eax

   comment:
     If c > 256 then one can search for up to four chars; for
     example strchr(s, (int)'a' | ((int)'A' << 8) will
     find 'a' case insensitive.  It is not C-function feature!
 */
strchr:
        imm8 = SSESTR_PACKED_UBYTE | \
               SSESTR_EQUAL_ANY    | \
               SSESTR_UNCHANGED    | \
               SSESTR_FIRSTBIT

        movd    %eax, %xmm0     # xmm1 := string of length 1 contains char c

    L(mainloop):
        add $16, %esi
        
        # implict string length - find first occurence of c or EOS
        pcmpistri $imm8, -16(%esi), %xmm0
        # sample 1 (char found)
        #       c       -> 's'
        #       mem     -> "Sunrise\0"
        #       
        #                  .........esirnuS <- '.' = invalid
        #       IntRes2 -> 0000000000100000b
        #       ECX     -> bsf(IntRes2) = 5
        #       CF      -> 1 (IntRes2 <> 0)
        #       ZF      -> 1 (there is a null byte)
        #       
        # sample 2 (null found)
        #       c       -> 'x'
        #       mem     -> "assembler\0"
        #       
        #                  .......relbmessa <- '.' = invalid
        #       IntRes2 -> 0000000000000000b
        #       ECX     -> 16 (IntRes2 = 0)
        #       CF      -> 0
        #       ZF      -> 1 (there is a null byte)

        jc  L(char_found)
        jnz L(mainloop)
    
    L(null_found):
        xor %eax, %eax  # eax := NULL
        ret

    L(char_found):
        lea -16(%esi, %ecx), %eax
        ret



#undef L
#define L(name) .L_d##name

/* char* strrchr(const char s, int c);

   inputs:
   - %esi -- s
   - %eax -- c

   result
   - %eax

   comment:
     If c > 256 then one can search for up to four chars; for
     example strrchr(s, (int)'a' | ((int)'A' << 8) will
     find 'a' case insensitive.  It is not C-function feature!
 */
strrchr:
        imm8 = SSESTR_PACKED_UBYTE | \
               SSESTR_EQUAL_ANY    | \
               SSESTR_UNCHANGED    | \
               SSESTR_LASTBIT

        movd    %eax, %xmm0     # xmm1 := string of length 1 contains char c
        xor     %eax, %eax      # eax  := NULL

    L(mainloop):
        add $16, %esi
        
        # implict string length - find last occurence of c or EOS
        pcmpistri $imm8, -16(%esi), %xmm0
        # sample 1 (char found)
        #       c       -> 's'
        #       mem     -> "cat catch scarab"
        #
        #                  baracs hctac tac
        #       IntRes2 -> 0000100010010001b
        #       ECX     -> bsr(IntRes2) = 11
        #       CF      -> 1 (IntRes2 <> 0)
        #       ZF      -> 0
        #       
        # sample 2 (null found)
        #       c       -> 's'
        #       mem     -> "assembler\0"
        #       
        #                  .......relbmessa <- '.' = invalid
        #       IntRes2 -> 0000000000000110b
        #       ECX     -> bsr(IntRes2) = 2
        #       CF      -> 1 (IntRes2 <> 0)
        #       ZF      -> 1 (there is a null byte)

        jz   L(null_found)
        jnc  L(mainloop)
    L(update):
        lea -16(%esi, %ecx), %eax  # update: last char pos.
        jmp  L(mainloop)


    L(null_found):
        jnc  L(end)     # CF = 0, no update needed
        lea -16(%esi, %ecx), %eax  # update: last char pos.
    L(end):
        ret



#undef L
#define L(name) .L_e##name
