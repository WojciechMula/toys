class ApplicationBase {

protected:
    const CommandLine& cmd;
    const FunctionRegistry& names;
    const unsigned count;
    const unsigned iterations;
    bool initialized;
    bool quiet;

    std::unique_ptr<uint8_t> input;
    std::unique_ptr<uint8_t> output;
public:
    ApplicationBase(const CommandLine& c, const FunctionRegistry& names)
        : cmd(c)
        , names(names)
        , count(64*1024*1024)
        , iterations(10)
        , initialized(false)
        , quiet(false) {}

protected:
    void initialize() {

        if (initialized) {
            return;
        }

        base64::scalar::prepare_lookup();
        base64::scalar::prepare_lookup32();
#if defined(HAVE_AVX512_INSTRUCTIONS)
        base64::avx512::prepare_lookups();
#endif // HAVE_AVX512_INSTRUCTIONS

        input.reset (new uint8_t[get_input_size()]);
        output.reset(new uint8_t[get_output_size()]);

        if (!quiet) {
            printf("input size: %lu\n", get_input_size());
        }

        fill_input();

        initialized = true;
    }

    size_t get_input_size() const {
        return count;
    }

    size_t get_output_size() const {
        return (3*count)/4;
    }

    void fill_input() {
        for (unsigned i=0; i < get_input_size(); i++) {
            const uint8_t idx = i * 71;
            input.get()[i] = base64::lookup[idx % 64];
        }
    }

    void clear_output() {
        memset(output.get(), 0, get_output_size());
    }
};
