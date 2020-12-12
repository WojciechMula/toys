DEPS_H=naive.h \
       binary_search.h \
       binary_search_inline.h \
       avx2.h \

DEPS_CPP=naive.cpp \
         binary_search.cpp \
         binary_search_inline.cpp \
         avx2.cpp \

DEPS=$(DEPS_H) $(DEPS_CPP)

FLAGS=$(CXXFLAGS) -Wall -Wextra -pedantic -Werror -mavx

all: unittests benchmark

unittests: unittests.cpp $(DEPS)
	$(CXX) $(FLAGS) $(DEPS_CPP) unittests.cpp -o unittests

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $(DEPS_CPP) benchmark.cpp -o benchmark
