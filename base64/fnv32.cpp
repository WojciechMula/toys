class FNV32 final {
public:
    static uint32_t get(const char* str, size_t size) {

        const uint32_t offset_basis = 2166136261u;
        const uint32_t prime = 16777619u;

        uint32_t hash = offset_basis;
        uint8_t *byte = (uint8_t*)str;

        for (size_t i=0; i < size; i++) {
            hash = hash ^ byte[i];
            hash = hash * prime;
        }

        return hash;
    }
};

