#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../../cmdline.cpp"
#include "../../fnv32.cpp"

#include "decode.common.cpp"
#include "decode.scalar.cpp"
#include "decode.sse.cpp"

#include "application.cpp"

class Application final: public ApplicationBase {

    bool all_ok;

public:
    Application(const CommandLine& c)
        : ApplicationBase(c)
        , all_ok(true) {}

    int run() {
        uint32_t valid_hash = 0;

        if (cmd.empty() || cmd.has("scalar1")) {
            valid_hash = check("scalar1", base64::scalar::decode_lookup1, valid_hash);
        }

        if (cmd.empty() || cmd.has("scalar2")) {
            check("scalar2", base64::scalar::decode_lookup2, valid_hash);
        }

        if (cmd.empty() || cmd.has("sse")) {
            check("SSE", base64::sse::decode, valid_hash);
        }

        if (cmd.empty()) {
            
            puts(all_ok ? "all OK" : "!!!ERRORS!!!");
        }

        return 0;
    }

private:
    template<typename T>
    uint32_t check(const char* name, T callback, uint32_t valid_hash) {

        initialize();

        printf("%20s... ", name);
        fflush(stdout);

        clear_output();
        callback(input.get(), get_input_size(), output.get());

        const uint32_t hash = FNV32::get(reinterpret_cast<const char*>(output.get()), get_output_size());
        printf("hash: %08x", hash);
        if (valid_hash != 0) {
            const bool ok = (hash == valid_hash);
            printf(" %s", ok ? "OK" : "!!!ERROR!!!");
            all_ok = all_ok && ok;
        }

        putchar('\n');

        return hash;
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}


