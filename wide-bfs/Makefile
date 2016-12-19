FLAGS=-Wall -Wextra -pedantic -std=c++11 -O3 -mavx512f
ALL=validate

validate: validate.cpp scalar.cpp avx512f.cpp
	$(CXX) $(FLAGS) validate.cpp -o $@

clean:
	rm -f $(ALL)
