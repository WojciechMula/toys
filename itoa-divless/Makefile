FLAGS=-Wall -Wextra -std=c++11 -O3

verify: verify.cpp itoa_divless.o
	$(CXX) $(FLAGS) itoa_divless.o verify.cpp -o verify

itoa_divless.o: itoa_divless_table.h itoa_divless.h itoa_divless.cpp
	$(CXX) $(FALSG) -c itoa_divless.cpp -o itoa_divless.o

itoa_divless_table.h: itoa_divless.py
	./itoa_divless.py

clean:
	$(RM) verify itoa_divless.o
