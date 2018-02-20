.PHONY: clean

FLAGS=-O2 -std=c++11 -Wall -Wextra -pedantic $(CXXFLAGS)
SCRIPT=scripts/print_table.py

test: main.cpp bitvector.h
	$(CXX) $(FLAGS) main.cpp -o $@

README.rst: README.txt core-i5-m540.txt skylake-i7-6700.txt
	python scripts/include.py README.txt > tmp
	mv tmp $@

core-i5-m540.txt: core-i5-m540.csv $(SCRIPT)
	python $(SCRIPT) $< > tmp
	mv tmp $@

skylake-i7-6700.txt: skylake-i7-6700.csv $(SCRIPT)
	python $(SCRIPT) $< > tmp
	mv tmp $@

clean:
	$(RM) test

