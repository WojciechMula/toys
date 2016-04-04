#pragma once

// define in **compiler's command line** if a CPU has BMI2 instruction set
//#define HAVE_BMI2_INSTRUCTIONS

// define in **compiler's command line** if a CPU has AVX2 instruction set
//#define HAVE_AVX2_INSTRUCTIONS

#if defined(HAVE_AVX512_INSTRUCTIONS)
#   if !defined(HAVE_AVX2_INSTRUCTIONS) // AVX512 implies AVX2
#       define HAVE_AVX2_INSTRUCTIONS
#   endif
#endif
