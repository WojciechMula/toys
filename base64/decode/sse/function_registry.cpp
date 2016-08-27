#include <unordered_map>


class Function {

    friend class FunctionRegistry;

public:
    Function(const std::string& n, const std::string& d, const std::string& l, const std::string& p)
        : name(n)
        , display_name(d)
        , lookup_method(l)
        , pack_method(p) {}

public:
    std::string  name;
    std::string  display_name;
    std::string  lookup_method;
    std::string  pack_method;

private:
    std::string image;
    std::string render() const {
        if (lookup_method == "N/A" && pack_method == "N/A") {
            return display_name;
        } else {
            return display_name + " (lookup: " + lookup_method + ", pack: " + pack_method + ")";
        }
    }
};


class FunctionRegistry final {

    std::unordered_map<std::string, Function> registry;
    Function unknown;
    int widest_image;

public:
    FunctionRegistry()
        : unknown({"???", "unknown", "N/A", "N/A"}) {

        build();
    }

    const Function& get(const std::string& name) const {

        const auto it = registry.find(name);
        if (it != registry.end()) {
            return it->second;
        } else {
            return unknown;
        }
    }

    const char* operator[](const std::string& name) const {
        return get(name).image.c_str();
    }

    int get_width() const {
        return widest_image;
    }

private:
    void build();
    void add(const std::string& name, const std::string& display_name, const std::string& lookup_method, const std::string& pack_method);
};


void FunctionRegistry::build() {

    add("improved",             "improved scalar",  "N/A", "N/A");
    add("scalar",               "scalar",           "N/A", "N/A");
#if defined(HAVE_BMI2_INSTRUCTIONS)
    add("scalar_bmi2",          "scalar & BMI2",    "N/A", "N/A");
#endif
    add("sse/base/naive",                   "SSE",              "base",         "naive");
    add("sse/blend/naive",                  "SSE",              "byte blend",   "naive");
    add("sse/incremental/naive",            "SSE",              "incremental",  "naive");
    add("sse/pshufb/naive",                 "SSE",              "pshufb",       "naive");

    add("sse/base/improved",                "SSE",              "base",         "improved");
    add("sse/blend/improved",               "SSE",              "byte blend",   "improved");
    add("sse/incremental/improved",         "SSE",              "incremental",  "improved");
    add("sse/pshufb/improved",              "SSE",              "pshufb",       "improved");

    add("sse/base/madd_improved",           "SSE",              "base",         "improved + mult-add");
    add("sse/blend/madd_improved",          "SSE",              "byte blend",   "improved + mult-add");
    add("sse/incremental/madd_improved",    "SSE",              "incremental",  "improved + mult-add");
    add("sse/pshufb/madd_improved",         "SSE",              "pshufb",       "improved + mult-add");

    add("sse/base/madd",                    "SSE",              "base",         "multiply-add");
    add("sse/blend/madd",                   "SSE",              "byte blend",   "multiply-add");
    add("sse/incremental/madd",             "SSE",              "incremental",  "multiply-add");
    add("sse/pshufb/madd",                  "SSE",              "pshufb",       "multiply-add");

#if defined(HAVE_BMI2_INSTRUCTIONS)
    add("sse_bmi2/base",        "SSE & BMI2",       "base",         "N/A");
    add("sse_bmi2/blend",       "SSE & BMI2",       "byte blend",   "N/A");
    add("sse_bmi2/incremental", "SSE & BMI2",       "incremental",  "N/A");
#endif
#if defined(HAVE_AVX2_INSTRUCTIONS)
    add("avx2/base/naive",                   "AVX2",              "base",         "naive");
    add("avx2/blend/naive",                  "AVX2",              "byte blend",   "naive");
    add("avx2/pshufb/naive",                 "AVX2",              "pshufb",       "naive");

    add("avx2/base/improved",                "AVX2",              "base",         "improved");
    add("avx2/blend/improved",               "AVX2",              "byte blend",   "improved");
    add("avx2/pshufb/improved",              "AVX2",              "pshufb",       "improved");

    add("avx2/base/madd_improved",           "AVX2",              "base",         "improved + mult-add");
    add("avx2/blend/madd_improved",          "AVX2",              "byte blend",   "improved + mult-add");
    add("avx2/pshufb/madd_improved",         "AVX2",              "pshufb",       "improved + mult-add");

    add("avx2/base/madd",                    "AVX2",              "base",         "multiply-add");
    add("avx2/blend/madd",                   "AVX2",              "byte blend",   "multiply-add");
    add("avx2/pshufb/madd",                  "AVX2",              "pshufb",       "multiply-add");

# if defined(HAVE_BMI2_INSTRUCTIONS)
    add("avx2_bmi2/base",       "AVX2 & BMI2",      "base",         "N/A");
    add("avx2_bmi2/blend",      "AVX2 & BMI2",      "byte blend",   "N/A");
#   endif
#endif
#if defined(HAVE_AVX512BW_INSTRUCTIONS)
    add("avx512bw",              "AVX512BW",        "N/A",         "multiply-add");
#endif
    widest_image = 0;
    for (auto& it: registry) {

        it.second.image = it.second.render();
        widest_image = std::max(widest_image, static_cast<int>(it.second.image.size()));
    }
}


void FunctionRegistry::add(const std::string& name, const std::string& display_name, const std::string& lookup, const std::string& pack) {

    registry.insert({name, {name, display_name, lookup, pack}});
}
