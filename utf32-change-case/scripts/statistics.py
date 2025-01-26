upper_1_char  = 0
upper_2_chars = 0
upper_3_chars = 0
lower_1_char  = 0
lower_2_chars = 0
lower_3_chars = 0

for src_code in range(0x1_ffff):
    src = chr(src_code)
    dst = src.upper()
    if dst != src:
        if len(dst) == 1:
            upper_1_char += 1
        elif len(dst) == 2:
            upper_2_chars += 1
        elif len(dst) == 3:
            upper_3_chars += 1

    dst = src.lower()
    if dst != src:
        if len(dst) == 1:
            lower_1_char += 1
        elif len(dst) == 2:
            lower_2_chars += 1
        elif len(dst) == 3:
            lower_3_chars += 1


print("uppercase")
print(f"- 1 char : {upper_1_char}")
print(f"- 2 chars: {upper_2_chars}")
print(f"- 3 chars: {upper_3_chars}")
print(f"- total  : {upper_1_char + upper_2_chars + upper_3_chars}")

print()
print("lowercase")
print(f"- 1 char : {lower_1_char}")
print(f"- 2 chars: {lower_2_chars}")
print(f"- 3 chars: {lower_3_chars}")
print(f"- total  : {lower_1_char + lower_2_chars + lower_3_chars}")
