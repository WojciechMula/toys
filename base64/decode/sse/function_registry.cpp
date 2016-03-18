#include <unordered_map>


class Function {

    friend class FunctionRegistry;

public:
    Function(const std::string& n, const std::string& d, const std::string& l)
        : name(n)
        , display_name(d)
        , lookup_method(l) {}

public:
    std::string  name;
    std::string  display_name;
    std::string  lookup_method;

private:
    std::string image;
    std::string render() const {
        if (lookup_method == "N/A") {
            return display_name;
        } else {
            return display_name + " (lookup: " + lookup_method + ")";
        }
    }
};


class FunctionRegistry final {

    std::unordered_map<std::string, Function> registry;
    Function unknown;
    int widest_image;

public:
    FunctionRegistry()
        : unknown({"???", "unknown", "N/A"}) {

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
    void add(const std::string& name, const std::string& display_name, const std::string& lookup_method);
};


void FunctionRegistry::build() {
    
    add("improved",             "improved scalar",  "N/A");
    add("scalar",               "scalar",           "N/A");
#if defined(HAVE_BMI2_INSTRUCTIONS)
    add("scalar_bmi2",          "scalar & BMI2",    "N/A");
#endif
    add("sse/base",             "SSE",              "base");
    add("sse/blend",            "SSE",              "byte blend");
    add("sse/incremental",      "SSE",              "incremental");
#if defined(HAVE_BMI2_INSTRUCTIONS)
    add("sse_bmi2/base",        "SSE & BMI2",       "base");
    add("sse_bmi2/blend",       "SSE & BMI2",       "byte blend");
    add("sse_bmi2/incremental", "SSE & BMI2",       "incremental");
#endif
#if defined(HAVE_AVX2_INSTRUCTIONS)
    add("avx2/base",            "AVX2",             "base");
    add("avx2/blend",           "AVX2",             "byte blend");
#   if defined(HAVE_BMI2_INSTRUCTIONS)
    add("avx2_bmi2/base",       "AVX2 & BMI2",      "base");
    add("avx2_bmi2/blend",      "AVX2 & BMI2",      "byte blend");
#   endif
#endif

    widest_image = 0;
    for (auto& it: registry) {
        
        it.second.image = it.second.render();
        widest_image = std::max(widest_image, static_cast<int>(it.second.image.size()));
    }
}


void FunctionRegistry::add(const std::string& name, const std::string& display_name, const std::string& lookup) {

    registry.insert({name, {name, display_name, lookup}});
}
