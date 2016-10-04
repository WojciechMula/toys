.PHONY: all clean speed

FLAGS=-std=c++14 -mavx512f -O3
PERFTESTS=speed_strlen

all: test speed

speed: $(PERFTESTS)

run: test
	sde -cnl -- ./$^

test: *.cpp
	$(CXX) $(FLAGS) test.cpp -o $@

speed_strlen: speed_strlen.cpp avx512f-strlen.cpp
	$(CXX) $(FLAGS) $< -o $@

clean:
	rm -f test $(PERFTESTS)
