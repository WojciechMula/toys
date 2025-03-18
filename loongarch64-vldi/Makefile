FLAGS=-O3 -Wall -Wextra -pedantic

ALL=vldi-const  \
    check-lsx   \
    check-lasx

.PHONY: ALL
all: $(ALL)

vldi-const: vldi-const.cpp
	$(CXX) $(FLAGS) -march=native vldi-const.cpp -o $@

.PHONY:
check-lsx: lsx-const-demo.s
	grep vrepli.d   $^ | grep -q -- "-8"    # const 0xfffffff8
	grep vldi       $^ | grep -q -- "-2238" # const 0x42ffff
	grep vreplgr2vr.d $^ -q                 # const 0x424344

.PHONY:
check-lasx: lasx-const-demo.s
	grep vrepli.d   $^ | grep -q -- "-8"    # const 0xfffffff8
	grep vldi       $^ | grep -q -- "-2238" # const 0x42ffff
	grep vreplgr2vr.d $^ -q                 # const 0x424344

lsx-const-demo.s: lsx-const-demo.cpp lsx-const.h
	loongarch64-linux-gnu-g++-14 $(FLAGS) -S lsx-const-demo.cpp

lasx-const-demo.s: lasx-const-demo.cpp lasx-const.h
	loongarch64-linux-gnu-g++-14 $(FLAGS) -march=la664 -S lasx-const-demo.cpp

.PHONY: clean
clean:
	$(RM) vldi-const lasx-const-demo.s lsx-const-demo.s
