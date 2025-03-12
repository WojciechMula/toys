constexpr char base32_alphabet[33]      = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
constexpr char base32_hex_alphabet[33]  = "0123456789ABCDEFGHIJKLMNOPQRSTUV";

enum class Base32Alphabet {
    Default,
    Hex
};
