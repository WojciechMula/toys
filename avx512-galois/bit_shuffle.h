#pragma once

#include <cstdint>

// Note that bytes are fetched from 7 to 0 during the affine transformation
#define bit_shuffle_const(b0, b1, b2, b3, b4, b5, b6, b7) \
  ((uint64_t(uint8_t(1 << b0)) << (7*8)) | \
   (uint64_t(uint8_t(1 << b1)) << (6*8)) | \
   (uint64_t(uint8_t(1 << b2)) << (5*8)) | \
   (uint64_t(uint8_t(1 << b3)) << (4*8)) | \
   (uint64_t(uint8_t(1 << b4)) << (3*8)) | \
   (uint64_t(uint8_t(1 << b5)) << (2*8)) | \
   (uint64_t(uint8_t(1 << b6)) << (1*8)) | \
   (uint64_t(uint8_t(1 << b7)) << (0*8)))
