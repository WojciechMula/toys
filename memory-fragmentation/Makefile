FLAGS=$(CXXFLAGS) -O0 -Wall -Wextra -std=c++11

ALL=test

all: $(ALL)

clean:
	$(RM) $(ALL)

test: test.cpp
	$(CXX) $(FLAGS) $< -o $@
