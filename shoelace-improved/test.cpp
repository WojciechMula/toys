#include <memory>
#include <immintrin.h>
#include <cstdint>
#include <cstring>
#include "time_utils.h"

// --------------------------------------------------

#define BACK_CW 0
#define BACK_CCW 1
#define FRONT_CW 2
#define FRONT_CCW 3

#define SIZE 1000000 // to match with Intel's code

#include "intel.cpp"
#include "improved.cpp"

class Application
{
    using aligned_array = std::unique_ptr<float[], decltype(&free)>;

    aligned_array x0;
    aligned_array x1;
    aligned_array x2;
    aligned_array y0;
    aligned_array y1;
    aligned_array y2;

public:
    Application()
        : x0(allocate(), &free)
        , x1(allocate(), &free)
        , x2(allocate(), &free)
        , y0(allocate(), &free)
        , y1(allocate(), &free)
        , y2(allocate(), &free)
    {
        prepare_decent_floats(x0.get(), SIZE);
        prepare_decent_floats(x1.get(), SIZE);
        prepare_decent_floats(x2.get(), SIZE);
        prepare_decent_floats(y0.get(), SIZE);
        prepare_decent_floats(y1.get(), SIZE);
        prepare_decent_floats(y2.get(), SIZE);
    }

    struct Data {
        int function_result;
        Clock::time_point::rep time;
    };

    int run()
    {
        const int repeat_count = 3;

        Data original;
        auto original_fn = [this, &original]() -> bool {
            Manual_AVX_SoA(x0.get(), x1.get(), x2.get(),
                           y0.get(), y1.get(), y2.get(),
                           BACK_CCW, original.function_result);
            return true;
        };

        original.time = measure_total_time("Manual_AVX_SoA (original): ", original_fn, repeat_count);

        Data improved;
        auto improved_fn = [this, &improved]() -> bool {
            Manual_AVX_SoA_improved(
                           x0.get(), x1.get(), x2.get(),
                           y0.get(), y1.get(), y2.get(),
                           BACK_CCW, improved.function_result);
            return true;
        };

        improved.time = measure_total_time("Manual_AVX_SoA (improved): ", improved_fn, repeat_count);
        
        printf("Speed-up: %0.2f\n", double(original.time) / improved.time);

        if (improved.function_result != original.function_result) {
            printf("Wrong result: original = %d, improved = %d\n",
                   original.function_result, improved.function_result);
            return EXIT_FAILURE;
        }
        else
            return EXIT_SUCCESS;
    }

private:
    void prepare_decent_floats(float* data, size_t size)
    {
        for (size_t i=0; i < size; i++)
            data[i] = get_random();
    }

    float get_random() {
        return (rand()/float(RAND_MAX) - 0.5) * 1000;
    }

    static float* allocate()
    {
        void* ptr;
        if (posix_memalign(&ptr, 4096, SIZE * sizeof(float))) {
            throw std::bad_alloc();
        }

        return reinterpret_cast<float*>(ptr);
    }
};

int main()
{
    Application app{};
    return app.run();
}
