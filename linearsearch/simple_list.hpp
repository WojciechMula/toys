#ifndef SIMPLE_LIST_H_INCLUDED__
#define SIMPLE_LIST_H_INCLUDED__

#include <cstdint>


template <typename Value>
class simple_list {

    struct item_type {
        const uint32_t  key;
        const Value     value;
        item_type*      next;

        item_type(uint32_t key, const Value value)
            : key(key)
            , value(value)
            , next(nullptr) {}
    };

    item_type* root;
    item_type* last;

public:
    simple_list()
        : root(nullptr)
        , last(nullptr) {}

public:
    void add(uint32_t key, const Value& value) {

        auto new_item = new item_type(key, value);

        if (root == nullptr) {
            root = last = new_item;
        } else {
            last->next = new_item;
            last = new_item;
        }
    }


    int find(uint32_t key) {

        if (root == nullptr) {
            return -1;
        }

        int result = 0;
        auto node = root;
        while (node != nullptr) {
            if (node->key == key) {
                return result;
            }

            node = node->next;
            result += 1;
        }

        return -1;
    }
};

#endif
