FLAGS=-Wall -Wextra -pedantic -std=c++17 -mavx512bw
TMP=/dev/shm

demo: *.cpp
	$(CXX) $(FLAGS) demo.cpp -o $@

precalc_factors.cpp: python/precalc_factors.py python/factor.py
	./python/precalc_factors.py > ${TMP}/pf.cpp
	mv ${TMP}/pf.cpp $@
