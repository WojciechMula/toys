#include "vldi-const.h"
#include <lsxintrin.h>

template <uint32_t x>
constexpr __m128i lsx_splat_u32() {
    constexpr bool is_imm10 = (int32_t(x) < 512) && (int32_t(x) > -512);
    constexpr bool is_vldi  = loongarch64_vldi::const_u32<x>::valid;

    return is_imm10 ? __lsx_vrepli_d(int32_t(x)) :
           is_vldi  ? __lsx_vldi(loongarch64_vldi::const_u32<x>::value) :
                      __lsx_vreplgr2vr_d(x);
}

template <uint16_t x>
constexpr __m128i lsx_splat_u16() {
    constexpr bool is_imm10 = (int16_t(x) < 512) && (int16_t(x) > -512);
    constexpr bool is_vldi  = loongarch64_vldi::const_u16<x>::valid;

    return is_imm10 ? __lsx_vrepli_h(int16_t(x)) :
           is_vldi  ? __lsx_vldi(loongarch64_vldi::const_u16<x>::value) :
                      __lsx_vreplgr2vr_h(x);
}
