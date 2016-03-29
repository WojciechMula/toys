class ApplicationBase {

protected:
    const CommandLine& cmd;
    const unsigned count;
    const unsigned iterations;
    bool initialized;

    std::unique_ptr<uint8_t> input;
    std::unique_ptr<uint8_t> output;
public:
    ApplicationBase(const CommandLine& c)
        : cmd(c)
        , count(1*1024*1024)
        , iterations(10)
        , initialized(false) {}

    void initialize() {

        if (initialized) {
            return;
        }

        input.reset (new uint8_t[get_input_size()]);
        output.reset(new uint8_t[get_output_size()]);

        printf("input size: %lu\n", get_input_size());

        fill_input();

        initialized = true;
    }

protected:
    size_t get_input_size() const {
        return 3*count;
    }

    size_t get_output_size() const {
        return 4*count;
    }

    void fill_input() {
        for (unsigned i=0; i < get_input_size(); i++) {
            input.get()[i] = i * 71;
        }
    }

    void clear_output() {
        memset(output.get(), 0, get_output_size());
    }
};

