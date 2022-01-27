#pragma once
/*
Author: Geoff Langdale, https://branchfree.org/

The algorithm was described in the following tweets:

- https://twitter.com/geofflangdale/status/1484460241240539137
- https://twitter.com/geofflangdale/status/1484460243778097159
- https://twitter.com/geofflangdale/status/1484460245560684550
- https://twitter.com/geofflangdale/status/1484460247368355842
*/

#include <cstdint>

uint64_t hex_to_u64_sse_geoff(const char* string, bool& ok);
