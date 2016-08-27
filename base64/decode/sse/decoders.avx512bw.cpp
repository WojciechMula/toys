#include "pack.avx512bw.cpp"
#include "lookup.avx512bw.cpp"
#include "decode.avx512bw.cpp"

namespace base64 {

    namespace avx512bw {

        void prepare_lookups() {

            initalize_lookup();
            initalize_decode();
        }

    } // namespace avx512bw

} // namespace base64
