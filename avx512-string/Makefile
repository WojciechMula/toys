.PHONY: all clean speed

FLAGS=-std=c++14 -mavx512f -O3 -Wall -Wextra -pedantic
PERFTESTS=speed_strlen speed_strchr speed_strrchr speed_strcmp
DEPS=common.h

all: test speed

speed: $(PERFTESTS)

run: test
	sde -cnl -- ./$^

test: test.cpp avx512*.cpp common.h
	$(CXX) $(FLAGS) $< -o $@

speed_strlen: speed_strlen.cpp avx512f-strlen.cpp scalar-strlen.cpp
	$(CXX) $(FLAGS) $< -o $@

speed_strchr: speed_strchr.cpp avx512f-strchr.cpp scalar-strchr.cpp
	$(CXX) $(FLAGS) $< -o $@

speed_strrchr: speed_strrchr.cpp avx512f-strrchr.cpp
	$(CXX) $(FLAGS) $< -o $@

speed_strcmp: speed_strcmp.cpp avx512f-strcmp.cpp common.h
	$(CXX) $(FLAGS) $< -o $@

clean:
	rm -f test $(PERFTESTS)
