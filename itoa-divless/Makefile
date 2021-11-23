FLAGS=-Wall -Wextra -std=c++11 -march=native -O3


ALL: verify verify_sse verify_bcd_add

verify: verify.cpp itoa_divless.o
	$(CXX) $(FLAGS) itoa_divless.o verify.cpp -o verify

itoa_divless.o: itoa_divless_table.h itoa_divless.h itoa_divless.cpp
	$(CXX) $(FLAGS) -c itoa_divless.cpp -o itoa_divless.o

itoa_divless_table.h: itoa_divless.py
	./itoa_divless.py

verify_sse: verify_sse.cpp itoa_divless_sse.o
	$(CXX) $(FLAGS) itoa_divless_sse.o verify_sse.cpp -o verify_sse

itoa_divless_sse.o: itoa_divless_sse_table.h itoa_divless_sse.h itoa_divless_sse.cpp
	$(CXX) $(FLAGS) -c itoa_divless_sse.cpp -o itoa_divless_sse.o

itoa_divless_sse_table.h: itoa_divless_sse.py
	./itoa_divless_sse.py

verify_bcd_add: verify_bcd_add.cpp 
	$(CXX) $(FLAGS) verify_bcd_add.cpp -o $@

clean:
	$(RM) verify verify_sse itoa_divless.o itoa_divless_sse.o
