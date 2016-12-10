FLAGS=-Wall -Wextra -pedantic -std=c++11
ALL=validate_input

all: $(ALL)

validate_input: validate_input.cpp
	$(CXX) $(FLAGS) $^ -o $@

clean:
	rm -f $(ALL)

