#include <cstring>
#include <cstdint>

// from ada
int find_authority_delimiter_special_reference(uint64_t word) noexcept {
  auto has_zero_byte = [](uint64_t v) {
    return ((v - 0x0101010101010101) & ~(v)&0x8080808080808080);
  };
  auto index_of_first_set_byte = [](uint64_t v) {
    return ((((v - 1) & 0x101010101010101) * 0x101010101010101) >> 56) - 1;
  };
  auto broadcast = [](uint8_t v) -> uint64_t { return 0x101010101010101 * v; };
  uint64_t mask1 = broadcast('@');
  uint64_t mask2 = broadcast('/');
  uint64_t mask3 = broadcast('?');
  uint64_t mask4 = broadcast('\\');

  uint64_t xor1 = word ^ mask1;
  uint64_t xor2 = word ^ mask2;
  uint64_t xor3 = word ^ mask3;
  uint64_t xor4 = word ^ mask4;
  uint64_t is_match = has_zero_byte(xor1) | has_zero_byte(xor2) | has_zero_byte(xor3) | has_zero_byte(xor4);

  if (is_match) {
      return index_of_first_set_byte(is_match);
  }

  return -1;
}
