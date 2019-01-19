FLAGS=$(CXXFLAGS) -O0 -Wall -Wextra -std=c++11
TMP=/dev/shm

ALL=out1.rst out2.rst

all: $(ALL)

clean:
	$(RM) $(ALL)

test: test.cpp
	$(CXX) $(FLAGS) $< -o $@

out1.txt: experiment1.sh test
	./experiment1.sh > ${TMP}/out1.txt
	${TMP}/out1.txt $@

out2.txt: experiment2.sh test
	./experiment2.sh > ${TMP}/out2.txt
	${TMP}/out2.txt $@

out1.rst: out1.txt scripts/format.py
	python scripts/format.py out1.txt > ${TMP}/out1.rst
	mv ${TMP}/out1.rst $@

out2.rst: out2.txt scripts/format.py
	python scripts/format.py out2.txt > ${TMP}/out2.rst
	mv ${TMP}/out2.rst $@

