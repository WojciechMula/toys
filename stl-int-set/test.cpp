#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include "benchmark.h"

volatile size_t sink;

constexpr size_t count = 1024*1024;

template <typename Container, uint32_t Max>
void test_insert_aux(size_t count, std::mt19937& re) {
    std::uniform_int_distribution<uint32_t> random_u32(0, Max);
    Container c;
    for (size_t i=0; i < count; i++) {
        const auto key = random_u32(re);
        c.insert(key);
    }

    sink = c.size();
}

template <typename Container, uint32_t Max>
void test_insert_and_remove_aux(size_t count, std::mt19937& re) {
    std::uniform_int_distribution<uint32_t> random_u32(0, Max);
    std::uniform_int_distribution<uint32_t> remove(0, 9);
    Container c;
    for (size_t i=0; i < count; i++) {
        const auto key = random_u32(re);
        if (remove(re) > 7) {
            c.erase(key);
        } else {
            c.insert(key);
        }
    }

    sink = c.size();
}

struct SetOfBitsets {
    std::map<uint32_t, uint64_t> map;

    void insert(uint32_t key) {
        map[key >> 6] |= 1 << (key & 0x3f);
    }

    void erase(uint32_t key) {
        auto it = map.find(key >> 6);
        if (it != map.end()) {
            it->second &= ~(uint32_t(1) << key & 0x3f);
            if (it->second == 0) {
                map.erase(it);
            }
        }
    }

    size_t size() const {
        return map.size();
    }
};

struct HashSetOfBitsets {
    std::unordered_map<uint32_t, uint64_t> map;

    void insert(uint32_t key) {
        map[key >> 6] |= 1 << (key & 0x3f);
    }

    void erase(uint32_t key) {
        auto it = map.find(key >> 6);
        if (it != map.end()) {
            it->second &= ~(uint32_t(1) << key & 0x3f);
            if (it->second == 0) {
                map.erase(it);
            }
        }
    }

    size_t size() const {
        return map.size();
    }
};

template <typename Container, uint32_t Max>
void test_insert(const char* name) {
    std::mt19937 random_engine{42};

    auto aux = [](size_t count, std::mt19937& re) {
        test_insert_aux<Container, Max>(count, re);
    };

    BEST_TIME(/**/, aux(count, random_engine), name, 1, count);
}

template <typename Container, uint32_t Max>
void test_insert_and_remove(const char* name) {
    std::mt19937 random_engine{42};

    auto aux = [](size_t count, std::mt19937& re) {
        test_insert_and_remove_aux<Container, Max>(count, re);
    };

    BEST_TIME(/**/, aux(count, random_engine), name, 1, count);
}

template <uint32_t Max>
void test_insert_all() {
    printf("%lu insertions of values in range 0 .. %u\n", count, Max);
    test_insert<std::set<uint32_t>, Max>("std::set");
    test_insert<std::unordered_set<uint32_t>, Max>("std::unordered_set");
    test_insert<SetOfBitsets, Max>("set of bitsets");
    test_insert<HashSetOfBitsets, Max>("hashset of bitsets");
}

template <uint32_t Max>
void test_insert_and_remove_all() {
    printf("%lu insertions/deletions of values in range 0 .. %u\n", count, Max);
    test_insert_and_remove<std::set<uint32_t>, Max>("std::set");
    test_insert_and_remove<std::unordered_set<uint32_t>, Max>("std::unordered_set");
    test_insert_and_remove<SetOfBitsets, Max>("set of bitsets");
    test_insert_and_remove<HashSetOfBitsets, Max>("hashset of bitsets");
}

int main() {
    test_insert_all<count>();
    test_insert_all<count*10>();
    test_insert_all<std::numeric_limits<uint32_t>::max()>();

    test_insert_and_remove_all<count>();
    test_insert_and_remove_all<count*10>();
    test_insert_and_remove_all<std::numeric_limits<uint32_t>::max()>();
}
