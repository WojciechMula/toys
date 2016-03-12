#include "lookup.sse.cpp"
#include "decode.sse.cpp"

namespace base64 {

    namespace sse {

        void decode_with_lookup_base(const uint8_t* input, size_t size, uint8_t* output) {
            sse_templates::decode(lookup_base, input, size, output);
        }


        void decode_with_lookup_byte_blend(const uint8_t* input, size_t size, uint8_t* output) {
            sse_templates::decode(lookup_byte_blend, input, size, output);
        }


        void decode_with_lookup_incremental(const uint8_t* input, size_t size, uint8_t* output) {
            sse_templates::decode(lookup_incremental, input, size, output);
        }

#if defined(HAVE_BMI2_INSTRUCTIONS)
        namespace bmi2 {

            void decode_with_lookup_base(const uint8_t* input, size_t size, uint8_t* output) {
                sse_templates::decode_bmi2(lookup_base, input, size, output);
            }


            void decode_with_lookup_byte_blend(const uint8_t* input, size_t size, uint8_t* output) {
                sse_templates::decode_bmi2(lookup_byte_blend, input, size, output);
            }


            void decode_with_lookup_incremental(const uint8_t* input, size_t size, uint8_t* output) {
                sse_templates::decode_bmi2(lookup_incremental, input, size, output);
            }
        } // namespace bmi
#endif
    } // namespace sse

} // namespace base64
