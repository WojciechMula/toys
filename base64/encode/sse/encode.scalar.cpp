
namespace base64 {

    namespace scalar {

        /*
            Note: function doesn't encode few tail bytes as the
                  single step is 3 bytes. The method is not intended
                  to be production-ready. Sorry for that.
        */
        void encode32(uint8_t* input, size_t bytes, uint8_t* output) {

            static const char* lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 3) {

                const uint32_t dword = *reinterpret_cast<uint32_t*>(input + i);

                const auto a = dword & 0x3f;
                const auto b = (dword >> 1*6) & 0x3f;
                const auto c = (dword >> 2*6) & 0x3f;
                const auto d = (dword >> 3*6) & 0x3f;

                *out++ = lookup[a];
                *out++ = lookup[b];
                *out++ = lookup[c];
                *out++ = lookup[d];
            }
        }

        void encode64(uint8_t* input, size_t bytes, uint8_t* output) {

            static const char* lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 6) {

                const uint64_t dword = *reinterpret_cast<uint64_t*>(input + i);

                const auto a = dword & 0x3f;
                const auto b = (dword >> 1*6) & 0x3f;
                const auto c = (dword >> 2*6) & 0x3f;
                const auto d = (dword >> 3*6) & 0x3f;
                const auto e = (dword >> 4*6) & 0x3f;
                const auto f = (dword >> 5*6) & 0x3f;
                const auto g = (dword >> 6*6) & 0x3f;
                const auto h = (dword >> 7*6) & 0x3f;

                *out++ = lookup[a];
                *out++ = lookup[b];
                *out++ = lookup[c];
                *out++ = lookup[d];
                *out++ = lookup[e];
                *out++ = lookup[f];
                *out++ = lookup[g];
                *out++ = lookup[h];
            }
        }
    }

} // namespace base64
