/*
    This file is intended to be included inside a function.

    You have to define macros:

    RUN
    RUN_SSE_TEMPLATE1
    RUN_SSE_TEMPLATE2
    RUN_AVX2_TEMPLATE1
    RUN_AVX2_TEMPLATE2

*/

RUN("improved", base64::scalar::decode_lookup2);
RUN("scalar", base64::scalar::decode_lookup1);

#if defined(HAVE_BMI2_INSTRUCTIONS)
    RUN("scalar_bmi2", base64::scalar::decode_lookup1_bmi2);
#endif

{
using namespace base64::sse;

RUN_SSE_TEMPLATE2("sse/base/naive",                  decode, lookup_base,        pack_naive);
RUN_SSE_TEMPLATE2("sse/blend/naive",                 decode, lookup_byte_blend,  pack_naive);
RUN_SSE_TEMPLATE2("sse/incremental/naive",           decode, lookup_incremental, pack_naive);
RUN_SSE_TEMPLATE2("sse/pshufb/naive",                decode, lookup_pshufb, pack_naive);

RUN_SSE_TEMPLATE2("sse/base/improved",               decode, lookup_base,        pack_improved);
RUN_SSE_TEMPLATE2("sse/blend/improved",              decode, lookup_byte_blend,  pack_improved);
RUN_SSE_TEMPLATE2("sse/incremental/improved",        decode, lookup_incremental, pack_improved);
RUN_SSE_TEMPLATE2("sse/pshufb/improved",             decode, lookup_pshufb, pack_improved);

RUN_SSE_TEMPLATE2("sse/base/madd_improved",          decode, lookup_base,        pack_madd_improved);
RUN_SSE_TEMPLATE2("sse/blend/madd_improved",         decode, lookup_byte_blend,  pack_madd_improved);
RUN_SSE_TEMPLATE2("sse/incremental/madd_improved",   decode, lookup_incremental, pack_madd_improved);
RUN_SSE_TEMPLATE2("sse/pshufb/madd_improved",        decode, lookup_pshufb, pack_madd_improved);

RUN_SSE_TEMPLATE2("sse/base/madd",                   decode, lookup_base,        pack_madd);
RUN_SSE_TEMPLATE2("sse/blend/madd",                  decode, lookup_byte_blend,  pack_madd);
RUN_SSE_TEMPLATE2("sse/incremental/madd",            decode, lookup_incremental, pack_madd);
RUN_SSE_TEMPLATE2("sse/pshufb/madd",                 decode, lookup_pshufb, pack_madd);
}

#if defined(HAVE_BMI2_INSTRUCTIONS)
    {
    using namespace base64::sse;

    RUN_SSE_TEMPLATE1("sse_bmi2/base",          decode_bmi2, lookup_base);
    RUN_SSE_TEMPLATE1("sse_bmi2/blend",         decode_bmi2, lookup_byte_blend);
    RUN_SSE_TEMPLATE1("sse_bmi2/incremental",   decode_bmi2, lookup_incremental);
    }
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
    {
    using namespace base64::avx2;

    RUN_AVX2_TEMPLATE2("avx2/base/naive",            decode, lookup_base,        pack_naive);
    RUN_AVX2_TEMPLATE2("avx2/blend/naive",           decode, lookup_byte_blend,  pack_naive);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/naive",          decode, lookup_pshufb,      pack_naive);

    RUN_AVX2_TEMPLATE2("avx2/base/improved",         decode, lookup_base,        pack_improved);
    RUN_AVX2_TEMPLATE2("avx2/blend/improved",        decode, lookup_byte_blend,  pack_improved);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/improved",       decode, lookup_pshufb,      pack_improved);

    RUN_AVX2_TEMPLATE2("avx2/base/madd_improved",    decode, lookup_base,        pack_madd_improved);
    RUN_AVX2_TEMPLATE2("avx2/blend/madd_improved",   decode, lookup_byte_blend,  pack_madd_improved);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/madd_improved",  decode, lookup_pshufb,      pack_madd_improved);

    RUN_AVX2_TEMPLATE2("avx2/base/madd",             decode, lookup_base,        pack_madd);
    RUN_AVX2_TEMPLATE2("avx2/blend/madd",            decode, lookup_byte_blend,  pack_madd);
    RUN_AVX2_TEMPLATE2("avx2/pshufb/madd",           decode, lookup_pshufb,      pack_madd);
    }

    #if defined(HAVE_BMI2_INSTRUCTIONS)
        {
        using namespace base64::avx2;

        RUN_AVX2_TEMPLATE1("avx2_bmi2/base",  decode_bmi2, lookup_base);
        RUN_AVX2_TEMPLATE1("avx2_bmi2/blend", decode_bmi2, lookup_byte_blend);
        }
    #endif // HAVE_BMI2_INSTRUCTIONS
#endif // HAVE_AVX2_INSTRUCTIONS

#if defined(HAVE_AVX512_INSTRUCTIONS)
    {
    using namespace base64::avx512;

    RUN_AVX2_TEMPLATE2("avx512/gather",      decode, lookup_gather,      pack_identity);
    RUN_AVX2_TEMPLATE2("avx512/comparisons", decode, lookup_comparisons, pack_improved);
    }
#endif // HAVE_AVX512_INSTRUCTIONS

#if defined(HAVE_AVX512BW_INSTRUCTIONS)
    {
    using namespace base64::avx512bw;

    RUN_AVX2_TEMPLATE2("avx512bw", decode, lookup, pack_madd);
    }
#endif // HAVE_AVX512BW_INSTRUCTIONS


