#ifndef SIMD_LIST_HPP_INCLUDED__
#define SIMD_LIST_HPP_INCLUDED__

#include <cstdint>
#include <emmintrin.h>

template <typename Value, int Count>
class block_list {

protected:
    struct item_type {
        uint32_t    keys[Count];
        Value       values[Count];
        int         count;
        item_type*  next;

        item_type() : count(0), next(nullptr) {}
    };

    item_type* root;
    item_type* last;

public:
    block_list()
        : root(nullptr)
        , last(nullptr) {}

public:
    void add(uint32_t key, const Value& value) {

        if (root == nullptr) {
            auto new_item = new item_type();

            root = last = new_item;
        }

        if (last->count == Count) {
            auto new_item = new item_type();

            last->next = new_item;
            last = new_item;
        }

        last->keys[last->count] = key;
        last->values[last->count] = value;

        last->count += 1;
    }


    int find(uint32_t key) {

        if (root == nullptr) {
            return -1;
        }

        int result = 0;
        auto node = root;

        while (node != nullptr) {
            for (int i=0; i < Count; i++, result++) {
                if (node->keys[i] == key) {
                    return result;
                }
            }

            node = node->next;
        }

        return -1;
    }
};


template <typename Value>
class simd_list: public block_list<Value, 4> {

    typedef block_list<Value, 4> super;

public:
    int find(uint32_t key) {

        if (super::root == nullptr) {
            return -1;
        }

        int result = 0;
        auto node = super::root;

        __m128i key4 = _mm_set_epi32(key, key, key, key);

        while (node != nullptr) {
            const __m128i k = _mm_loadu_si128((const __m128i*)&node->keys[0]);

            const auto mask = _mm_movemask_epi8(_mm_cmpeq_epi32(key4, k));
            if (mask != 0) {
                return result = __builtin_ctz(mask)/4 + result;
            }

            node = node->next;
            result += 4;
        }

        return -1;
    }
};


template <typename Value>
class simd2_list: public block_list<Value, 8> {

    typedef block_list<Value, 8> super;

public:
    int find(uint32_t key) {

        if (super::root == nullptr) {
            return -1;
        }

        int result = 0;
        auto node = super::root;

        __m128i key4 = _mm_set_epi32(key, key, key, key);

        while (node != nullptr) {
            const __m128i k1 = _mm_loadu_si128((const __m128i*)&node->keys[0]);
            const __m128i k2 = _mm_loadu_si128((const __m128i*)&node->keys[4]);

            const __m128i k  = _mm_or_si128(_mm_cmpeq_epi32(k1, key4), _mm_cmpeq_epi32(k2, key4));

            const auto mask = _mm_movemask_epi8(k);
            if (mask != 0) {
                const auto mask2 = _mm_movemask_epi8(_mm_cmpeq_epi32(k2, key4));
                if (mask2 != 0) {
                    return result = __builtin_ctz(mask2)/4 + result + 4;
                } else {
                    return result = __builtin_ctz(mask)/4 + result;
                }
            }

            node = node->next;
            result += 8;
        }

        return -1;
    }
};

#endif
