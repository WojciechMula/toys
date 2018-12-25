FLAGS=$(CXXFLAGS) -O3 -march=skylake -c

ALL=example1.o\
    example2.o\
    example1-avx.o\
    example2-avx.o

all: $(ALL)

example1.o: example1.cpp
	$(CXX) $(FLAGS) $< -o $@

example2.o: example2.cpp
	$(CXX) $(FLAGS) $< -o $@

example1-avx.o: example1-avx.cpp
	$(CXX) $(FLAGS) $< -o $@

example2-avx.o: example2-avx.cpp
	$(CXX) $(FLAGS) $< -o $@

example1.s: example1.cpp
	$(CXX) $(FLAGS) $< -S

example2.s: example2.cpp
	$(CXX) $(FLAGS) $< -S

clean:
	$(RM) $(ALL)
