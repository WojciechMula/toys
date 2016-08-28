// define if a CPU have BMI2 instruction set
//#define HAVE_BMI2_INSTRUCTIONS

// define in **command line** if a CPU support AVX2 instruction set
//#define HAVE_AVX2_INSTRUCTIONS

#if (defined(HAVE_AVX512_INSTRUCTIONS) || defined(HAVE_AVX512BW_INSTRUCTIONS)) && !defined(HAVE_AVX2_INSTRUCTIONS)
#   define HAVE_AVX2_INSTRUCTIONS 1
#endif
