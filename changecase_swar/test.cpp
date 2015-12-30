#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include "gettime.cpp"
#include "tolower.cpp"
#include "fnv32.cpp"

class Application final {

    bool test_scalar;
    bool test_swar;

public:
    Application(int argc, char** argv);

    void run();

private:
    char* load_file(const char* path, size_t size);
};


int main(int argc, char* argv[]) {
 
    Application app(argc, argv);
    app.run();

    return 0;
}


Application::Application(int argc, char** argv)
    : test_scalar(false)
    , test_swar(false) {

    for (int i=1; i < argc; i++) {
        if (strcmp(argv[i], "scalar") == 0) {
            test_scalar = true;
        } else if (strcmp(argv[i], "swar") == 0) {
            test_swar = true;
        } else if (strcmp(argv[i], "all") == 0) {
            test_scalar = true;
            test_swar = true;
        }
    }
}


char* Application::load_file(const char* path, size_t size) {

    char* buf = new char[size];

    printf("loading file %s... ",  path); std::fflush(stdout);

    FILE* f = fopen(path, "rb");
    assert(f != nullptr);

    const size_t readed = fread(buf, 1, size, f);
    fclose(f);

    if (readed < size) {
        size_t i = readed;
        for (/**/; i < size - readed; i += readed) {
            memcpy(buf + i, buf + 0, readed);
        }

        memcpy(buf + i, buf + 0, size - i);
    }

    printf("done\n");

    return buf;
}


void Application::run() {

    const size_t MiB   = 1024*1024;
    const size_t count = 100;
    const size_t size  = count*MiB;

    if (!(test_scalar || test_swar)) {
        return;
    }

    char* buf = load_file("data", size);
    double ts = 0.0;

    if (test_scalar) {

        printf("testing scalar... "); std::fflush(stdout);

        const auto t1 = time();
        scalar::to_lower_inplace(buf, size);
        const auto t2 = time();
        ts = (t2 - t1)/1000000.0;

        printf("%0.4f (hash: %08x)\n", ts, FNV32::get(buf, size));
    }

    if (test_swar) {

        printf("testing SWAR...   "); std::fflush(stdout);

        const auto t1 = time();
        swar::to_lower_inplace(buf, size);
        const auto t2 = time();
        const double t = (t2 - t1)/1000000.0;

        printf("%0.4f (hash: %08x)", t, FNV32::get(buf, size));
        if (test_scalar) {
            printf(" speedup = %0.2f", (ts/t));
        }

        putchar('\n');
    }

    delete buf;
}


