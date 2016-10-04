.PHONY: all clean speed

FLAGS=-std=c++14 -mavx512f -O3
PERFTESTS=speed_strlen speed_strchr

all: test speed

speed: $(PERFTESTS)

run: test
	sde -cnl -- ./$^

test: test.cpp avx512*.cpp
	$(CXX) $(FLAGS) $< -o $@

speed_strlen: speed_strlen.cpp avx512f-strlen.cpp
	$(CXX) $(FLAGS) $< -o $@

speed_strchr: speed_strchr.cpp avx512f-strchr.cpp
	$(CXX) $(FLAGS) $< -o $@

clean:
	rm -f test $(PERFTESTS)
