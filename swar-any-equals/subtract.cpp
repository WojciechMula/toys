/*
    This method is authored by Laurent Poirrier https://www.poirrier.ca
    Sent via e-mail.

    Basically, instead of looking for bytes 0x00, we look for 0xff.
    This is slightly faster approach.
*/

#include <cstring>
#include <cstdint>

long int find_authority_delimiter_special_subtract(uint64_t word) noexcept {
  auto broadcast = [](uint8_t v) -> uint64_t { return 0x101010101010101 * v; };

  uint64_t v80 = broadcast(0x80);
  uint64_t v7f = broadcast(0x7f);

  uint64_t x0 = (v80 | (word ^ ~broadcast('@')))  - v7f;
  uint64_t x1 = (v80 | (word ^ ~broadcast('/')))  - v7f;
  uint64_t x2 = (v80 | (word ^ ~broadcast('?')))  - v7f;
  uint64_t x3 = (v80 | (word ^ ~broadcast('\\'))) - v7f;

  uint64_t t0 = (x0 | x1 | x2 | x3);
  uint64_t t1 = t0 & ~word;
  uint64_t t2 = t1 & v80;

  if (t2 != 0) {
    return __builtin_ctzl(t2) / 8;
  }

  return -1;
}
