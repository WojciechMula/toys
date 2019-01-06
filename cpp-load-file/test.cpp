#include <string>
#include <chrono>
#include <algorithm>
#include <memory>

#include <fstream>
#include <sstream>

#include <cstdio>
#include <cstdlib>

std::string load1(const std::string& path) {
    std::ifstream file(path);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}


std::string load2(const std::string& path) {
    auto ss = std::ostringstream{};
    std::ifstream file(path);
    ss << file.rdbuf();
    return ss.str();
}


std::string load3(const std::string& path) {

    auto close_file = [](FILE* f){fclose(f);};

    auto holder = std::unique_ptr<FILE, decltype(close_file)>(fopen(path.c_str(), "rb"), close_file);
    if (!holder)
      return "";

    FILE* f = holder.get();

    if (fseek(f, 0, SEEK_END) < 0)
      return "";

    const long size = ftell(f);
    if (size < 0)
      return "";

    if (fseek(f, 0, SEEK_SET) < 0)
        return "";

    std::string res;
    res.resize(size);

    // C++17 defines .data() which returns a non-const pointer
    fread(const_cast<char*>(res.data()), 1, size, f);

    return res;
}

// --------------------------------------------------------------------------------

class Test {
    const std::string path;
    const int k = 10;
    uint64_t ref_time = 0;

public:
    Test(const std::string& p) : path(p) {}

    void run() {
        measure("C++ istreambuf_iterator",  load1);
        measure("C++ stream::rdbuf",        load2);
        measure("libc fread",               load3);
    }

private:
    template <typename FUNCTION>
    void measure(const char* name, FUNCTION load_function) {

        auto load = [this, &load_function]() {return load_function(path);};

        printf("%-30s: ", name); fflush(stdout);
        uint64_t time = -1;
        for (int i=0; i < k; i++) {
          time = std::min(time, measure(load));
          putchar('.'); fflush(stdout);
        }

        printf(" %10lu us", time);
        if (ref_time == 0)
            ref_time = time;
        else {
            printf(" (%0.2f)", ref_time/double(time));
        }

        putchar('\n');
    }


    template <typename FUNCTION, typename time_type = std::chrono::microseconds>
    uint64_t measure(FUNCTION fun) {
        const auto ts = std::chrono::high_resolution_clock::now();
        const auto s  = fun();
        const auto te = std::chrono::high_resolution_clock::now();

        static volatile size_t size = s.size();

        return std::chrono::duration_cast<time_type>(te - ts).count();
    }
};


int main(int argc, char* argv[]) {

    for (int i=1; i < argc; i++) {
        const std::string path = argv[i];
        printf("File %s\n", path.c_str());

        Test test(path);
        test.run();
    }

    return 0;
}
