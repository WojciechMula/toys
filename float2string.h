#include <cstdio>
#include <cstdint>
#include <cmath>
#include <cstring>
#include <assert.h>


namespace fp {

template <typename FP_TYPE>
struct traits;


template <>
struct traits<float> {
    
    using type = float;

    static const unsigned mantissa_bits = 23;
    static const unsigned exponent_bits = 8;
    static const int      exp_shift     = 127;
 
    union proxy {
        type        value;
        uint32_t    raw;

        explicit proxy(type v) : value(v) {}
        explicit proxy(uint32_t r) : raw(r) {}

        bool is_negative() const {
            
            return raw & 0x80000000u;
        }

        int get_exponent() const {

            return int((raw >> mantissa_bits) & ((uint32_t(1) << exponent_bits) - 1)) - exp_shift;
        }

        uint32_t get_mantissa() const {

            const uint32_t implicit_one = (uint32_t(1) << mantissa_bits);

            return (raw & (implicit_one - 1));
        }

        uint32_t get_normalized_mantissa() const {

            const uint32_t implicit_one = (uint32_t(1) << mantissa_bits);

            return (raw & (implicit_one - 1)) | implicit_one;
        }
    };

};


template <typename FP_TYPE>
class tostring;


template <>
class tostring<float> {

    using proxy = traits<float>::proxy;

    const proxy p;

    static const int fraction_bin_digits = 64;

    static const int max_fraction_dec_digits = 8;   // 2^-23 \approx 10^8
    static const int max_integer_dec_digits  = 20;  // ceil(log_10(2^54))

    char integer_part[max_fraction_dec_digits];
    char fraction_part[max_integer_dec_digits];

    static const char nullchar = '\0';

public:

    /// sign [1], integer part [20], decimal dot [1], fraction part [8]
    static const unsigned min_buffer_size = 1 + 20 + 1 + 8;

    bool always_show_sign;
    char decimal_dot;

public:
    tostring(float v)
        : p(v)
        , always_show_sign(false)
        , decimal_dot('.') {
        
        fraction_part[max_fraction_dec_digits] = nullchar;
        integer_part[max_integer_dec_digits]   = nullchar;
    }

    
    int operator()(const char* buffer) {

        const auto cls = std::fpclassify(p.value);

        switch (cls) {
            case FP_INFINITE:
            case FP_NAN:
            case FP_SUBNORMAL:   
                return 0;

            case FP_ZERO: {
                
                char* dest = const_cast<char*>(buffer);

                if (p.is_negative()) {
                    *dest++ = '-';
                } else if (always_show_sign) {
                    *dest++ = '+';
                }

                *dest++ = '0';
                *dest++ = decimal_dot;
                *dest++ = '0';
                *dest++ = nullchar;

                return dest - buffer - 1;
            }

            case FP_NORMAL:
                break;

            default:
                return 0;
        }

        if (can_convert_integer() && can_convert_fraction()) {

            char* dest = const_cast<char*>(buffer);

            if (p.is_negative()) {
                *dest++ = '-';
            }
            
            if (const auto digits = convert_integer()) {
                memcpy(dest, integer_part + max_integer_dec_digits - digits, digits);
                dest += digits;
            } else {
                *dest++ = '0';
            }

            *dest++ = decimal_dot;

            if (const auto digits = convert_fraction()) {
                memcpy(dest, fraction_part, digits);
                dest += digits;
            } else {
                *dest++ = '0';
            }

            *dest++ = 0;

            return dest - buffer;

        } else {
            return 0;
        }
    }

private:

    bool can_convert_integer() const {

        const int exp = p.get_exponent() - traits<float>::mantissa_bits;

        if (exp > 0) {
            // shift left, check if won't exceed 64 bits
            return exp < 64;
        }

        return true;
    }

    int convert_integer() {

        const int exp = p.get_exponent() - traits<float>::mantissa_bits;

        const uint64_t mantissa = p.get_normalized_mantissa();

        uint64_t integer;

        if (exp > 0) {
            integer = mantissa << exp;
        } else if (exp < 0) {

            if (-exp > 23) {
                // fast path: integer part is zero
                integer_part[max_integer_dec_digits - 1] = '0';
                return 1;
            }

            integer = mantissa >> (-exp);
        }

        // naive conversion
        int k = 0;
        while (integer) {

            const auto digit = integer % 10;

            integer_part[max_integer_dec_digits - 1 - k] = digit + '0';

            integer /= 10;
            k += 1;
        }

        return k;
    }


    bool can_convert_fraction() const {

        return true;
    }
    
    /* returns number of converted digits */
    int convert_fraction() {

        const int exp = p.get_exponent() - traits<float>::mantissa_bits;

        uint64_t fraction;

        const auto shift = (fraction_bin_digits + exp - 4);

        if (shift >= fraction_bin_digits - 4 || shift < 0) {
            // fraction is zero
            return 0;
        } else {
            fraction = uint64_t(p.get_normalized_mantissa()) << shift;
        }

        int k = 0;
        int digits = 0;
        char* c = fraction_part;
    
        while (fraction && k < max_fraction_dec_digits) {
            fraction &= 0x0fffffffffffffffllu;
            fraction *= 10;

            int digit = fraction >> (fraction_bin_digits - 4);

            *c++ = digit + '0';
            k += 1;

            if (digit > 0) {
                digits = k;
            }
        }

        return digits;
    }
};


} // namespace fp
