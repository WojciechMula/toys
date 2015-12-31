#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include "gettime.cpp"
#include "tolower.cpp"
#include "fnv32.cpp"

class CommandLine;

class Application final {

    const CommandLine& cmd;

public:
    class Terminate {};

public:
    Application(const CommandLine& cmd);

    void run();

private:
    char* load_file(const char* path, size_t size);
    void usage();
};


class CommandLine final {

    int argc;
    char** argv;

public:
    CommandLine(int argc, char** argv);

    unsigned count() const;

    const char* get(int index) const;
    bool has(const char* cmd) const;
};


int main(int argc, char* argv[]) {

    try {
        CommandLine cmd(argc, argv);
        Application app(cmd);
        app.run();

    } catch (Application::Terminate&) {
        return 1;
    }

    return 0;
}


Application::Application(const CommandLine& cmd)
    : cmd(cmd) {}


char* Application::load_file(const char* path, size_t size) {

    char* buf = new char[size];

    printf("loading file %s... ",  path); std::fflush(stdout);

    FILE* f = fopen(path, "rb");
    if (f == nullptr) {
        printf("cannot load the file");
        throw Terminate();
    }

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

    const bool test_scalar = cmd.has("scalar") || cmd.has("both");
    const bool test_swar   = cmd.has("swar") || cmd.has("both");

    if (cmd.count() != 2 || (test_scalar == false && test_swar == false)) {
        usage();

        throw Terminate();
    }

    const size_t MiB   = 1024*1024;
    const size_t count = 100;
    const size_t size  = count*MiB;

    char* buf = load_file(cmd.get(0), size);
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


void Application::usage() {
    puts("usage:");
    puts("");
    puts("test FILE option");
    puts("");
    puts("options:");
    puts("- scalar - test the scalar code");
    puts("- swar   - test the SWAR code");
    puts("- both   - test both implementations");
}


CommandLine::CommandLine(int argc, char** argv)
    : argc(argc)
    , argv(argv) {}


unsigned CommandLine::count() const {

    return argc - 1;
}


const char* CommandLine::get(int index) const {

    if (index < 0 || index >= argc - 1) {
        return nullptr;
    }

    return argv[index + 1];
}


bool CommandLine::has(const char* value) const {

    for (int i=1; i < argc; i++) {
        if (strcmp(value, argv[i]) == 0) {
            return true;
        }
    }

    return false;
}
