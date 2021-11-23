def proof_carry():
    for carry in [0, 1]:    # carry from the previous position
        for a in range(10):
            for b in range(10):
                # expected
                S = a + b + carry
                carry_expected = S // 10     # carry for the next position

                # modified
                S1 = (255 - 9 + a) + b + carry
                carry_result = S1 >> 8

                assert carry_expected == carry_result


def proof_digit():
    for carry in [0, 1]:    # carry from the previous position
        for a in range(10):
            for b in range(10):
                # expected
                S = a + b + carry
                digit_expected = S % 10
                next_carry = S // 10

                # modified
                S1 = (255 - 9 + a) + b + carry
                byte = S1 & 0xff
                digit_result = byte

                if next_carry:
                    assert digit_expected == digit_result
                else:
                    assert digit_expected == (digit_result - (255 - 9))


if __name__ == '__main__':
    proof_carry()
    proof_digit()
    print("All OK")
