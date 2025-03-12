FLAGS_COMMON=-Wall -Wextra -pedantic -std=c++17 -ggdb # -Werror
FLAGS=$(FLAGS_COMMON) -march=native

DEPS=common.h \
     scalar_encoding.cpp

ALL: encoding \
     verify_sse_encoding

all: $(ALL)

encoding: encoding.cpp $(DEPS)
	$(CXX) $(FLAGS) encoding.cpp -o $@

verify_sse_encoding: verify_sse_encoding.cpp sse_encoding.cpp common.h
	$(CXX) $(FLAGS) verify_sse_encoding.cpp -o $@
