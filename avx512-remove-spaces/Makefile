.SUFFIXES:

FLAGS=$(CXXFLAGS) -mavx512vbmi -Wall -Wextra -pedantic -std=c++11

DEPS=all.cpp scalar.cpp avx512vbmi.cpp

ALL=unittest benchmark speed

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $< -o $@

speed: speed.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $< -o $@

# The Adventures of Tom Sawyer by M.Twain
tom-sawyer.txt:
	wget http://www.gutenberg.org/files/74/74-0.txt -O $@

run: speed tom-sawyer.txt
	./speed tom-sawyer.txt

clean:
	$(RM) $(ALL)
