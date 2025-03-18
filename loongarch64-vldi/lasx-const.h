#include "vldi-const.h"
#include <lasxintrin.h>

template <uint16_t x>
constexpr __m256i lasx_splat_u16() {
    constexpr bool is_imm10 = (int16_t(x) < 512) && (int16_t(x) > -512);
    constexpr bool is_vldi  = loongarch64_vldi::const_u16<x>::valid;

    return is_imm10 ? __lasx_xvrepli_h(int16_t(x)) :
           is_vldi  ? __lasx_xvldi(loongarch64_vldi::const_u16<x>::value) :
                      __lasx_xvreplgr2vr_h(x);

}

template <uint32_t x>
constexpr __m256i lasx_splat_u32() {
    constexpr bool is_imm10 = (int32_t(x) < 512) && (int32_t(x) > -512);
    constexpr bool is_vldi  = loongarch64_vldi::const_u32<x>::valid;

    return is_imm10 ? __lasx_xvrepli_d(int32_t(x)) :
           is_vldi  ? __lasx_xvldi(loongarch64_vldi::const_u32<x>::value) :
                      __lasx_xvreplgr2vr_d(x);

}
