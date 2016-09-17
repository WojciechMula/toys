.PHONY: all run run_speed run_verify clean

FLAGS=-std=c++11 -mavx512f -O3

DEPS=*.cpp
SDE=sde -cnl --

all: speed verify

run: run_verify run_speed

run_speed: speed
	$(SDE) ./speed

run_verify: verify
	$(SDE) ./verify

speed: $(DEPS)
	$(CXX) $(FLAGS) speed.cpp -o speed

verify: $(DEPS)
	$(CXX) $(FLAGS) verify.cpp -o verify

clean:
	rm -f verify speed
