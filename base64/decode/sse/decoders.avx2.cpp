#include "lookup.avx2.cpp"
#include "decode.avx2.cpp"

namespace base64 {

    namespace avx2 {

        void decode_with_lookup_base(const uint8_t* input, size_t size, uint8_t* output) {
            avx2_templates::decode(lookup_base, input, size, output);
        }


        void decode_with_lookup_byte_blend(const uint8_t* input, size_t size, uint8_t* output) {
            avx2_templates::decode(lookup_byte_blend, input, size, output);
        }

#if defined(HAVE_BMI2_INSTRUCTIONS)
        namespace bmi2 {

            void decode_with_lookup_base(const uint8_t* input, size_t size, uint8_t* output) {
                avx2_templates::decode_bmi2(lookup_base, input, size, output);
            }


            void decode_with_lookup_byte_blend(const uint8_t* input, size_t size, uint8_t* output) {
                avx2_templates::decode_bmi2(lookup_byte_blend, input, size, output);
            }

        } // namespace bmi
#endif
    }

} // namespace base64
