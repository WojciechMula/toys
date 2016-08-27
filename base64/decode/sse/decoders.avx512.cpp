#include "lookup.avx512.cpp"
#include "decode.avx512.cpp"

namespace base64 {

    namespace avx512 {

        void prepare_lookups() {

            initalize_lookup();
            initalize_decode();
        }

    } // namespace avx512

} // namespace base64
