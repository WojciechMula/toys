#include <cstring>
#include <cstdint>

long int find_authority_delimiter_special_better(uint64_t word) noexcept {
  auto broadcast = [](uint8_t v) -> uint64_t { return 0x101010101010101 * v; };

  uint64_t mask = broadcast(0x7f);
  uint64_t lo7bits = word & mask;

  uint64_t x0 = (lo7bits ^ broadcast('@')) + mask;
  uint64_t x1 = (lo7bits ^ broadcast('/')) + mask;
  uint64_t x2 = (lo7bits ^ broadcast('?')) + mask;
  uint64_t x3 = (lo7bits ^ broadcast('\\')) + mask;

  uint64_t t0 = ((x0 & x1 & x2 & x3) | word);
  uint64_t t1 = t0 & broadcast(0x80);
  uint64_t t2 = t1 ^ broadcast(0x80);

  if (t2 != 0) {
    return __builtin_ctzl(t2) / 8;
  }

  return -1;
}
