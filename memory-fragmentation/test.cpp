#include <malloc.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cassert>


class Application {
    const size_t memory_usage_limit;
    const size_t min_alloc;
    const size_t max_alloc;
    size_t sum_allocated;
    size_t malloc_calls;

public:
    Application(size_t memory_usage_limit_, size_t min_alloc_, size_t max_alloc_)
        : memory_usage_limit(memory_usage_limit_)
        , min_alloc(min_alloc_)
        , max_alloc(max_alloc_) 
        , sum_allocated(0)
        , malloc_calls(0) {
    
        assert(memory_usage_limit > 0);
        assert(min_alloc > 0);
        assert(max_alloc > 0);
        assert(min_alloc <= max_alloc);
        assert(memory_usage_limit > max_alloc);
    }

    void run() {
        perform_allocations();
        struct mallinfo mi = mallinfo();

        const int allocated = mi.uordblks;
        const int free      = mi.fordblks;

        printf("%lu %lu %lu %lu %lu %d %d\n",
                memory_usage_limit,
                min_alloc,
                max_alloc,
                sum_allocated,
                malloc_calls,
                allocated,
                free);
    }

private:
    void perform_allocations() {
        while (sum_allocated < memory_usage_limit) {
            const size_t s = get_size();
            if (malloc(s) == NULL) {
                sum_allocated = 0;
                malloc_calls = 0;
            }
            sum_allocated += s;
            malloc_calls += 1;
        }
    }

    size_t get_size() const {
        return rand() % (max_alloc - min_alloc + 1) + min_alloc;
    }
};

int main(int argc, char* argv[]) {

    size_t memory_usage_limit = 1024 * 1024;
    size_t min_alloc = 32;
    size_t max_alloc = 64;

    if (argc > 1) {
        memory_usage_limit = atoi(argv[1]);
    }

    if (argc > 2) {
        min_alloc = atoi(argv[2]);
        max_alloc = min_alloc;
    }

    if (argc > 3) {
        max_alloc = atoi(argv[3]);
    }

    Application app(memory_usage_limit, min_alloc, max_alloc);
    app.run();
}
