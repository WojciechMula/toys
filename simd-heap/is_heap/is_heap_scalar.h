#pragma once

#include <iterator>

template <typename ForwardIterator, typename Compare = std::less<>>
bool is_heap_fwd(ForwardIterator start, ForwardIterator end, Compare cmp) {
    if (start == end)
        return true;

    auto parent  = start;
    auto current = std::next(start);
    while (current != end) {
        if (cmp(*parent, *current))
            return false;

        current = std::next(current);
        if (current == end)
            break;

        if (cmp(*parent, *current))
            return false;

        parent = std::next(parent);
        current = std::next(current);
    }

    return true;
}


template <typename RandomIterator, typename Compare = std::less<>>
bool is_heap_rnd(RandomIterator start, RandomIterator end, Compare cmp) {
    const size_t count = end - start;
    if (count <= 1)
        return true;

    size_t parent_idx = 0;
    size_t child_idx = 1;
    for (size_t i=0; i < count/2; i++) {
        const auto parent = start[parent_idx];
        if (cmp(parent, start[child_idx]) or cmp(parent, start[child_idx + 1]))
            return false;

        parent_idx += 1;
        child_idx += 2;
    }

    if (count % 2 == 1) {
        const size_t i = count - 1;
        const auto parent = start[(i - 1)/2];
        const auto child  = start[i];

        return not cmp(parent, child);
    }
    else
        return true;
}
