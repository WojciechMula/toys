.SUFFIXES:

FLAGS=$(CXXFLAGS) -mavx512vbmi -mbmi2 -Wall -Wextra -pedantic -std=c++11 -Wno-implicit-fallthrough

DEPS=all.cpp scalar.cpp avx512vbmi*.cpp aqrit.cpp application_base.cpp

ALL=unittest test benchmark speed

all: $(ALL)

unittest: unittest.cpp $(DEPS)
	$(CXX) $(FLAGS) $< -o $@

test: test.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $< -o $@

benchmark: benchmark.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $< -o $@

speed: speed.cpp $(DEPS)
	$(CXX) $(FLAGS) -O3 $< -o $@

# The Adventures of Tom Sawyer by M.Twain
tom-sawyer.txt:
	wget http://www.gutenberg.org/files/74/74-0.txt -O $@

run_speed: speed tom-sawyer.txt
	./speed tom-sawyer.txt

run_test: test tom-sawyer.txt
	./test tom-sawyer.txt
	@cmp scalar.out avx512.out

# Cannon Lake plot
cnl.data cnl.gnuplot: scripts/gnuplot.py scripts/parse.py results/cnl.txt
	python scripts/gnuplot.py results/cnl.txt cnl.data cnl.gnuplot cnl.png "Cannon Lake"

cnl.png: cnl.data cnl.gnuplot
	gnuplot cnl.gnuplot

cnl.rst: scripts/format.py scripts/parse.py results/cnl.txt
	python scripts/format.py results/cnl.txt > /tmp/cnl.rst
	mv /tmp/cnl.rst $@

clean:
	$(RM) $(ALL)
