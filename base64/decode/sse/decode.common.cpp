#include <cstdint>

namespace base64 {

    static const char* lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    class invalid_input final {
        
    public:
        invalid_input(size_t ofs, uint8_t b)
            : offset(ofs)
            , byte(b) {}

        const size_t offset;
        const uint8_t byte;
    };

} // namespace base64
