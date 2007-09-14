/*
    Some functions that use SSE4 string instructions:
      * strcmp [2007-09-02]
      * memcmp [2007-09-02]
      * strchr [2007-09-02] (implict string length)
      * strchr2 [2007-09-08] (explicit string length)
      * strrchr [2007-09-02]
      * is_sxdigit [2007-09-02] -- validate string
      * strtolower [2007-09-02] -- change case of ASCII encoded string

    Warning: these functions were not tested yet!
    However they **should** work fine.
    
    Author: Wojciech Mula
    e-mail: wojciech_mula@poczta.onet.pl
    www:    http://www.mula.w.pl
    
    License: public domain

    Compile:
        gcc -c {maybe other flags} sse4-string-instr.S

    $Date: 2007-09-14 11:53:13 $, $Revision: 1.11 $
*/


/* imm8 defs: */
#define SSESTR_PACKED_UBYTE     0               /* element size */
#define SSESTR_PACKED_UWORD     0b01
#define SSESTR_PACKED_SBYTE     0b10
#define SSESTR_PACKED_SWORD     0b11

#define SSESTR_EQUAL_ANY        0               /* compare method */
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

.text


#undef L
#define L(name) .L_a##name
/* int strcmp(const char* s1, const char* s2);

   inputs:
   - %esi -- s1
   - %edi -- s2

   result:
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
        #       xmm1 -> "string are diff"
        #       xmm2 -> "strXng are equa"
        #
        #       IntRes1 -> 111011111110111b
        #       IntRes2 -> 000100000001000b (negated valid)
        #       ECX     := bfs(IntRes2) = 3
        #       CF      := 1 (IntRes2 <> 0)
        #       ZF      := 0
        #
        # sample 2 (strings equal, but null byte found):
        #       xmm1 -> "string\0..."
        #       xmm2 -> "string\0..."
        #
        #       IntRes1 -> 000000001111111b
        #       IntRes2 -> 000000000000000b (negated valid)
        #       ECX     := 16 (there isn't any bit set in IntRes2)
        #       CF      := 0 (IntRes2 == 0, no diffs)
        #       ZF      := 1 (EOS, i.e. null byte in xmm2)

        ja  L(main_loop)  # CF=0 and ZF=0 (no diff, no null byte)

        jc  L(diff_found) # CF=1 -> offset is given
    L(null_found):
        # ZF=1 -> # calculate EOS position
        pxor     %xmm0, %xmm0
        pcmpeqb  %xmm2, %xmm0
        pmovmskb %xmm0, %ecx
        bsf      %ecx,  %ecx
    L(diff_found):
        movzbl  -16(%edi, %ecx), %edx
        movzbl  -16(%esi, %ecx), %eax
        sub     %edx, %eax
        ret
#eof



#undef L
#define L(name) .L_b##name
/* int memcmp(const char* s1, const char* s2, size_t n);

   inputs:
   - %esi -- s1
   - %edi -- s2
   - %eax -- n

   result:
   - %eax
 */
memcmp:
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
        
        sub     $16,    %eax            # decrement
        sub     $16,    %edx            # both lengths

        # explicit length string compare for equal

        pcmpestri $imm8, %xmm2, %xmm1
        # for some samples see comments in strcmp

        ja  L(mainloop)
        jc  L(diff_found)

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
#eof



#undef L
#define L(name) .L_c##name
/* char* strchr(const char* s, int c);
   
   comment:
     If c > 256 then one can search for up to four chars; for
     example strchr(s, (int)'a' | ((int)'A' << 8) will
     find 'a' case insensitive.  It is not C-function feature!

   inputs:
   - %esi -- s
   - %eax -- c

   result:
   - %eax
 */
strchr:
        imm8 = SSESTR_PACKED_UBYTE | \
               SSESTR_EQUAL_ANY    | \
               SSESTR_UNCHANGED    | \
               SSESTR_FIRSTBIT

        movd    %eax, %xmm0     # xmm1 := string of length 1 contains char c
        xor     %edx, %edx      # edx  := NULL

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

        ja L(mainloop)  # CF=0 and ZF=0 (no char, no null found)
   
        lea -16(%esi, %ecx), %eax # eax := char address (valid if CF=1, i.e. char found)
        cmovnc %edx, %eax         # eax := NULL (if CF=0)
        ret
#eof



#undef L
#define L(name) .L_g##name
/* char* strchr2(const char* s, int c);
   
   inputs:
   - %esi -- s
   - %eax -- c

   result:
   - %eax
 */
strchr2:
        imm8 = SSESTR_PACKED_UBYTE | \
               SSESTR_EQUAL_ANY    | \
               SSESTR_UNCHANGED    | \
               SSESTR_FIRSTBIT

        movd    %eax, %xmm0     # xmm1 := string contains 'c' and '\0'
        mov     $2,   %eax      # eax  := length(xmm1) = 2
        mov     $16,  %edx      # edx  := length(xmm2/mem) = 16 (we'll
                                #         process all chars)

    L(mainloop):
        add $16, %esi
        
        # explicit string length - find first occurence of c or EOS
        pcmpestri $imm8, -16(%esi), %xmm0
        # sample (char or null found)
        #       c       -> 's'
        #       mem     -> "Sunrise0s00ssA0s"
        #       
        #                  s\0Ass\0\0s\0esirnuS
        #       IntRes2 -> 1 1011 1 11 10100000b
        #       ECX     -> bsf(IntRes2) = 5
        #       CF      -> 1 (IntRes2 <> 0)

        jnc L(mainloop)  # CF=0 (no char, no null found)
  
        mov    $0, %edx           # edx := NULL
        lea -16(%esi, %ecx), %eax # eax := char address
                                  # (valid if CF=1, i.e. char or null found)
        cmovnc %edx, %eax         # eax := NULL (if CF=0)
        ret
#eof



#undef L
#define L(name) .L_d##name
/* char* strrchr(const char* s, int c);

   comment:
     If c > 256 then one can search for up to four chars; for
     example strrchr(s, (int)'a' | ((int)'A' << 8) will
     find 'a' case insensitive.  It is not C-function feature!

   inputs:
   - %esi -- s
   - %eax -- c

   result:
   - %eax
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
        #       c       -> 'c'
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

        ja   L(mainloop)   # CF=0 and ZF=0 (no char, no null found)
        jz   L(null_found) # ZF=1 -> null byte
    L(update): # CF=1 -> position update needed
        lea -16(%esi, %ecx), %eax  # update: last char pos.
        jmp  L(mainloop)


        # XXX: use conditional moves?
    L(null_found):
        jnc  L(end)     # CF = 0, no update needed
        lea -16(%esi, %ecx), %eax  # update last char pos.
    L(end):
        ret
#eof



#undef L
#define L(name) .L_e##name
/* int is_sxdigit(const char* s);

   comment:
     Function test if all chars from s matches [0-9A-Fa-f]
     (sxdigit describe pattern).

   inputs:
   - %esi -- s

   result:
   - %eax (0 or 1)

   destroy:
   - %xmm0, %xmm1
 */
is_sxdigit:
        imm8 = SSESTR_PACKED_UBYTE  | \
               SSESTR_RANGES        | \
               SSESTR_NEGATED_VALID | \
               SSESTR_BITMASK

        movaps  sxdigit, %xmm1
    L(mainloop):
        add     $16, %eax

        # implict string length - test if all chars in range or EOS occured
        pcmpistrm $imm8, -16(%eax), %xmm1
        # sample 1 (not all chars match):
        #       mem   -> "10 x 1af7\0"
        #       xmm1  -> "09AZaz"
        #       
        #                 .......7fa1 x 01 <- '.' = invalid
        #       IntRes1 = 0000000111100011b
        #       IntRes2 = 0000000000011100b (negated valid)
        #       CF      = 1 (IntRes2 <> 0)
        #       ZF      = 1 (null in mem) 
        #       
        # sample 2 (all chars match, no null byte):
        #       mem   -> "5afffefff00011fb"
        #       xmm1  -> "09AZaz"
        #
        #                 bf11000fffefffa51
        #       IntRes1 = 1111111111111111b
        #       IntRes2 = 0000000000000000b (negated valid)
        #       CF      = 0 (IntRes2 == 0)
        #       ZF      = 0
        #
        # sample 3 (all chars match):
        #       mem   -> "5afffefff\0"
        #       xmm1  -> "09AZaz"
        #
        #                 .......fffefffa51 <- '.' = invalid
        #       IntRes2 = 0000000111111111b
        #       IntRes2 = 0000000000000000b
        #       CF      = 0 (IntRes2 == 0)
        #       ZF      = 1 (null byte in mem)

        ja      L(main_loop)    # CF=0 and ZF=0 (all match, no EOS)

    L(end_of_string):
        mov     $1,   %eax
        mov     $0,   %edx
        cmovc   %edx, %eax      # eax := CF ? 0 : 1
        ret
#eof



#undef L
#define L(name) .L_f##name
/* void strtolower(const char* s);

   comment:
     Function modify s; encoding of string is ASCII.
     Initial value of eax (see line marked with X)
     determine action preformed by function:
     * 0x00005a41 ("AZ")    - to lower
     * 0x00007a61 ("az")    - to upper
     * 0x7a615a41 ("azAZ")  - swap case

   inputs:
   - %eax -- s
 */
strtolower:
        imm8 = SSESTR_PACKED_UBYTE  | \
               SSESTR_RANGES        | \
               SSESTR_UNCHANGED     | \
               SSESTR_BYTEMASK

        mov     $0x00005a41, %edx       # 0x5a41 := 'AZ' (X)
        movd    %edx, %xmm1             # xmm1 -> range [A-Z]
        movd    pb_0x20, %xmm3          # xmm3 := packed_byte(0x20)

    L(mainloop):
        movaps  (%eax), %xmm2
        add     $16, %eax

        # implict string length - make mask for chars [A-Z] or locate EOS
        pcmpistrm $imm8, %xmm2, %xmm1
        # sample: 
        #       xmm2 -> "REAd SoME TEXt\0" (length 15)
        #       
        #       
        #                   ..tEXT EMoS dAER   <- '.' = invalid
        #       IntRest2 := 0001110110100111b
        #       xmm0     := |000000ff|ffff00ff|ff00ff00|00ffffff|
        #       CF       := 1 (IntRes2 <> 0)
        #       ZF       := 1 (null byte in mem)

        ja L(mainloop)    # CF=0 and ZF=0 (no update needed, no EOS)
       
    L(update):
        pand %xmm3, %xmm0 # xmm0 := |00000020|20200020|20002000|00202020|
        pxor %xmm0, %xmm2 # reset 5th bit in big letters
                          # xmm2 -> "read some text\0"
        movups %xmm2, -16(%eax) # write back modified fragment
        jnz L(mainloop)

        ret
#eof



.data
        .align 16
        sxdigit:
                .byte '0','9','A','F','a','f'
                .rept 10
                        .byte 0
                .endr
        pb_0x20:
                .rept 16
                        .byte 0x20
                .endr

/*
   vim: et nowrap
*/
