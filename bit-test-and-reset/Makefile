FLAGS=-O3 -march=skylake

ALL=loop-gcc.txt loop-clang.txt test-and-set-gcc.txt test-and-set-clang.txt

DISASM=objdump -D -j .text

all: $(ALL)

loop-gcc.txt: loop-gcc.o
	$(DISASM) $^ > $@

loop-clang.txt: loop-clang.o
	$(DISASM) $^ > $@

loop-gcc.o: loop.cpp
	g++ $(FLAGS) loop.cpp -c -o $@

loop-clang.o: loop.cpp
	clang++ $(FLAGS) loop.cpp -c -o $@

test-and-set-gcc.txt: test-and-set-gcc.o
	$(DISASM) $^ > $@

test-and-set-clang.txt: test-and-set-clang.o
	$(DISASM) $^ > $@

test-and-set-gcc.o: test-and-set.cpp
	g++ $(FLAGS) test-and-set.cpp -c -o $@

test-and-set-clang.o: test-and-set.cpp
	clang++ $(FLAGS) test-and-set.cpp -c -o $@

clean:
	$(RM) *.o
