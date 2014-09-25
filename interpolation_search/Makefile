.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic
DEPS=search.cpp common.cpp

all: demo speed speed-sse speed.png avgcmp.png betteravg.png

demo: demo.cpp $(DEPS)
	$(CC) $(FLAGS) demo.cpp -o $@

speed: speed.cpp $(DEPS)
	$(CC) $(FLAGS) -O2 -DNDEBUG speed.cpp -o $@

speed-sse: speed.cpp $(DEPS)
	$(CC) $(FLAGS) -O2 -msse -mfpmath=sse -ffast-math -DNDEBUG speed.cpp -o $@

avgcmp.results: demo graphs/demoresults2text.py
	./demo 10000 | python graphs/demoresults2text.py > avgcmp.results

avgcmp.png: avgcmp.results graphs/avgcmp.gnuplot
	gnuplot graphs/avgcmp.gnuplot

speed.results: speed graphs/speedresults2text.py
	./speed 100000 | python graphs/speedresults2text.py > speed.results

speed.png: speed.results graphs/speed.gnuplot
	gnuplot graphs/speed.gnuplot

betteravg.png: avgcmp.results graphs/betteravg.gnuplot.pattern graphs/betteravg.gnuplot.py
	python graphs/betteravg.gnuplot.py < avgcmp.results > betteravg.gnuplot
	gnuplot betteravg.gnuplot

clean:
	rm -f demo speed speed-sse *.results *.png betteravg.gnuplot
