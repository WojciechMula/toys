        
        // row #0
        const __m128i A_0_shuf = _mm_setr_epi8(0, 1, 2, 3, -1, -1, -1, -1, -1, -1, 4, 5, 6, 7, -1, -1);
        const __m128i A_0 = _mm_shuffle_epi8(A, A_0_shuf);
        const __m128i B_0_shuf = _mm_setr_epi8(-1, -1, -1, -1, 0, 1, -1, -1, 2, 3, -1, -1, -1, -1, 4, 5);
        const __m128i B_0 = _mm_shuffle_epi8(B, B_0_shuf);
        __m128i row0 = _mm_or_si128(A_0, B_0);
        row0 = _mm_insert_epi16(row0, _mm_extract_epi16(C, 0), 3);
        
        // row #1
        const __m128i A_1_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, 9, 10, 11);
        const __m128i A_1 = _mm_shuffle_epi8(A, A_1_shuf);
        const __m128i C_1_shuf = _mm_setr_epi8(2, 3, -1, -1, -1, -1, -1, -1, 4, 5, -1, -1, -1, -1, -1, -1);
        const __m128i C_1 = _mm_shuffle_epi8(C, C_1_shuf);
        __m128i row1 = _mm_or_si128(A_1, C_1);
        const __m128i D_1_shuf = _mm_setr_epi8(-1, -1, 0, 1, -1, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i D_1 = _mm_shuffle_epi8(D, D_1_shuf);
        row1 = _mm_or_si128(row1, D_1);
        row1 = _mm_insert_epi16(row1, _mm_extract_epi16(B, 3), 5);
        row1 = _mm_insert_epi16(row1, _mm_extract_epi16(E, 0), 2);
        
        // row #2
        const __m128i E_2_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 2, 3, -1, -1, -1, -1, -1, -1, 4, 5);
        const __m128i E_2 = _mm_shuffle_epi8(E, E_2_shuf);
        const __m128i F_2_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 0, 1, -1, -1, 2, 3, -1, -1);
        const __m128i F_2 = _mm_shuffle_epi8(F, F_2_shuf);
        __m128i row2 = _mm_or_si128(E_2, F_2);
        row2 = _mm_insert_epi16(row2, _mm_extract_epi16(B, 4), 0);
        row2 = _mm_insert_epi16(row2, _mm_extract_epi16(C, 3), 1);
        row2 = _mm_insert_epi16(row2, _mm_extract_epi16(D, 2), 2);
        row2 = _mm_insert_epi16(row2, _mm_extract_epi16(G, 0), 5);
        
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
        const __m128i C_5_shuf = _mm_setr_epi8(-1, -1, 12, 13, -1, -1, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i C_5 = _mm_shuffle_epi8(C, C_5_shuf);
        const __m128i D_5_shuf = _mm_setr_epi8(10, 11, -1, -1, -1, -1, -1, -1, 12, 13, -1, -1, -1, -1, -1, -1);
        const __m128i D_5 = _mm_shuffle_epi8(D, D_5_shuf);
        __m128i row5 = _mm_or_si128(C_5, D_5);
        row5 = _mm_insert_epi16(row5, _mm_extract_epi16(B, 7), 2);
        row5 = _mm_insert_epi16(row5, _mm_extract_epi16(E, 5), 5);
        row5 = _mm_insert_epi16(row5, _mm_extract_epi16(F, 4), 6);
        row5 = _mm_insert_epi16(row5, _mm_extract_epi16(G, 3), 7);
        
        // row #6
        const __m128i E_6_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, 12, 13, -1, -1, 14, 15, -1, -1);
        const __m128i E_6 = _mm_shuffle_epi8(E, E_6_shuf);
        const __m128i F_6_shuf = _mm_setr_epi8(-1, -1, -1, -1, -1, -1, 10, 11, -1, -1, -1, -1, -1, -1, 12, 13);
        const __m128i F_6 = _mm_shuffle_epi8(F, F_6_shuf);
        __m128i row6 = _mm_or_si128(E_6, F_6);
        const __m128i H_6_shuf = _mm_setr_epi8(4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i H_6 = _mm_shuffle_epi8(H, H_6_shuf);
        row6 = _mm_or_si128(row6, H_6);
        row6 = _mm_insert_epi16(row6, _mm_extract_epi16(D, 7), 5);
        row6 = _mm_insert_epi16(row6, _mm_extract_epi16(G, 4), 2);
        
        // row #7
        const __m128i G_7_shuf = _mm_setr_epi8(10, 11, -1, -1, -1, -1, 12, 13, -1, -1, 14, 15, -1, -1, -1, -1);
        const __m128i G_7 = _mm_shuffle_epi8(G, G_7_shuf);
        const __m128i H_7_shuf = _mm_setr_epi8(-1, -1, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, 12, 13, 14, 15);
        const __m128i H_7 = _mm_shuffle_epi8(H, H_7_shuf);
        __m128i row7 = _mm_or_si128(G_7, H_7);
        row7 = _mm_insert_epi16(row7, _mm_extract_epi16(F, 7), 4);