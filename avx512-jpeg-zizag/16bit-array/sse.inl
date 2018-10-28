        
        // row #0
        const __m128i A_0_shuf = _mm_setr_epi8(0, 1, 2, 3, -1, -1, -1, -1, -1, -1, 4, 5, 6, 7, -1, -1);
        const __m128i A_0 = _mm_shuffle_epi8(A, A_0_shuf);
        const __m128i B_0_shuf = _mm_setr_epi8(-1, -1, -1, -1, 0, 1, -1, -1, 2, 3, -1, -1, -1, -1, 4, 5);
        const __m128i B_0 = _mm_shuffle_epi8(B, B_0_shuf);
        __m128i row0 = _mm_or_si128(A_0, B_0);
        const __m128i C_0_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 0, 1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i C_0 = _mm_shuffle_epi8(C, C_0_shuf);
        row0 = _mm_or_si128(row0, C_0);
        
        // row #1
        const __m128i A_1_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, 9, 10, 11);
        const __m128i A_1 = _mm_shuffle_epi8(A, A_1_shuf);
        const __m128i B_1_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, 7, -1, -1, -1, -1);
        const __m128i B_1 = _mm_shuffle_epi8(B, B_1_shuf);
        __m128i row1 = _mm_or_si128(A_1, B_1);
        const __m128i C_1_shuf = _mm_setr_epi8(2, 3, -1, -1, -1, -1, -1, -1, 4, 5, -1, -1, -1, -1, -1, -1);
        const __m128i C_1 = _mm_shuffle_epi8(C, C_1_shuf);
        row1 = _mm_or_si128(row1, C_1);
        const __m128i D_1_shuf = _mm_setr_epi8(-1, -1, 0, 1, -1, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i D_1 = _mm_shuffle_epi8(D, D_1_shuf);
        row1 = _mm_or_si128(row1, D_1);
        const __m128i E_1_shuf = _mm_setr_epi8(-1, -1, -1, -1, 0, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i E_1 = _mm_shuffle_epi8(E, E_1_shuf);
        row1 = _mm_or_si128(row1, E_1);
        
        // row #2
        const __m128i B_2_shuf = _mm_setr_epi8(8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i B_2 = _mm_shuffle_epi8(B, B_2_shuf);
        const __m128i C_2_shuf = _mm_setr_epi8(-1, -1, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i C_2 = _mm_shuffle_epi8(C, C_2_shuf);
        __m128i row2 = _mm_or_si128(B_2, C_2);
        const __m128i D_2_shuf = _mm_setr_epi8(-1, -1, -1, -1, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i D_2 = _mm_shuffle_epi8(D, D_2_shuf);
        row2 = _mm_or_si128(row2, D_2);
        const __m128i E_2_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 2, 3, -1, -1, -1, -1, -1, -1, 4, 5);
        const __m128i E_2 = _mm_shuffle_epi8(E, E_2_shuf);
        row2 = _mm_or_si128(row2, E_2);
        const __m128i F_2_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 0, 1, -1, -1, 2, 3, -1, -1);
        const __m128i F_2 = _mm_shuffle_epi8(F, F_2_shuf);
        row2 = _mm_or_si128(row2, F_2);
        const __m128i G_2_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, -1, -1, -1, -1);
        const __m128i G_2 = _mm_shuffle_epi8(G, G_2_shuf);
        row2 = _mm_or_si128(row2, G_2);
        
        // row #3
        const __m128i A_3_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1);
        const __m128i A_3 = _mm_shuffle_epi8(A, A_3_shuf);
        const __m128i B_3_shuf = _mm_setr_epi8(-1, -1, -1, -1, 10, 11, -1, -1, -1, -1, 12, 13, -1, -1, -1, -1);
        const __m128i B_3 = _mm_shuffle_epi8(B, B_3_shuf);
        __m128i row3 = _mm_or_si128(A_3, B_3);
        const __m128i C_3_shuf = _mm_setr_epi8(-1, -1, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, 10, 11, -1, -1);
        const __m128i C_3 = _mm_shuffle_epi8(C, C_3_shuf);
        row3 = _mm_or_si128(row3, C_3);
        const __m128i D_3_shuf = _mm_setr_epi8(6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, 9);
        const __m128i D_3 = _mm_shuffle_epi8(D, D_3_shuf);
        row3 = _mm_or_si128(row3, D_3);
        
        // row #4
        const __m128i E_4_shuf = _mm_setr_epi8(6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, 9);
        const __m128i E_4 = _mm_shuffle_epi8(E, E_4_shuf);
        const __m128i F_4_shuf = _mm_setr_epi8(-1, -1, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, 6, 7, -1, -1);
        const __m128i F_4 = _mm_shuffle_epi8(F, F_4_shuf);
        __m128i row4 = _mm_or_si128(E_4, F_4);
        const __m128i G_4_shuf = _mm_setr_epi8(-1, -1, -1, -1, 2, 3, -1, -1, -1, -1, 4, 5, -1, -1, -1, -1);
        const __m128i G_4 = _mm_shuffle_epi8(G, G_4_shuf);
        row4 = _mm_or_si128(row4, G_4);
        const __m128i H_4_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 0, 1, 2, 3, -1, -1, -1, -1, -1, -1);
        const __m128i H_4 = _mm_shuffle_epi8(H, H_4_shuf);
        row4 = _mm_or_si128(row4, H_4);
        
        // row #5
        const __m128i B_5_shuf = _mm_setr_epi8(-1, -1, -1, -1, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i B_5 = _mm_shuffle_epi8(B, B_5_shuf);
        const __m128i C_5_shuf = _mm_setr_epi8(-1, -1, 12, 13, -1, -1, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i C_5 = _mm_shuffle_epi8(C, C_5_shuf);
        __m128i row5 = _mm_or_si128(B_5, C_5);
        const __m128i D_5_shuf = _mm_setr_epi8(10, 11, -1, -1, -1, -1, -1, -1, 12, 13, -1, -1, -1, -1, -1, -1);
        const __m128i D_5 = _mm_shuffle_epi8(D, D_5_shuf);
        row5 = _mm_or_si128(row5, D_5);
        const __m128i E_5_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 10, 11, -1, -1, -1, -1);
        const __m128i E_5 = _mm_shuffle_epi8(E, E_5_shuf);
        row5 = _mm_or_si128(row5, E_5);
        const __m128i F_5_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, 9, -1, -1);
        const __m128i F_5 = _mm_shuffle_epi8(F, F_5_shuf);
        row5 = _mm_or_si128(row5, F_5);
        const __m128i G_5_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, 7);
        const __m128i G_5 = _mm_shuffle_epi8(G, G_5_shuf);
        row5 = _mm_or_si128(row5, G_5);
        
        // row #6
        const __m128i D_6_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14, 15, -1, -1, -1, -1);
        const __m128i D_6 = _mm_shuffle_epi8(D, D_6_shuf);
        const __m128i E_6_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 12, 13, -1, -1, 14, 15, -1, -1);
        const __m128i E_6 = _mm_shuffle_epi8(E, E_6_shuf);
        __m128i row6 = _mm_or_si128(D_6, E_6);
        const __m128i F_6_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 10, 11, -1, -1, -1, -1, -1, -1, 12, 13);
        const __m128i F_6 = _mm_shuffle_epi8(F, F_6_shuf);
        row6 = _mm_or_si128(row6, F_6);
        const __m128i G_6_shuf = _mm_setr_epi8(-1, -1, -1, -1, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i G_6 = _mm_shuffle_epi8(G, G_6_shuf);
        row6 = _mm_or_si128(row6, G_6);
        const __m128i H_6_shuf = _mm_setr_epi8(4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i H_6 = _mm_shuffle_epi8(H, H_6_shuf);
        row6 = _mm_or_si128(row6, H_6);
        
        // row #7
        const __m128i F_7_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 14, 15, -1, -1, -1, -1, -1, -1);
        const __m128i F_7 = _mm_shuffle_epi8(F, F_7_shuf);
        const __m128i G_7_shuf = _mm_setr_epi8(10, 11, -1, -1, -1, -1, 12, 13, -1, -1, 14, 15, -1, -1, -1, -1);
        const __m128i G_7 = _mm_shuffle_epi8(G, G_7_shuf);
        __m128i row7 = _mm_or_si128(F_7, G_7);
        const __m128i H_7_shuf = _mm_setr_epi8(-1, -1, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, 12, 13, 14, 15);
        const __m128i H_7 = _mm_shuffle_epi8(H, H_7_shuf);
        row7 = _mm_or_si128(row7, H_7);