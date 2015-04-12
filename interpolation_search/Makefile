.SUFFIXES:

CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pedantic
DEPS=search.cpp common.cpp
ALL=demo speed speed-sse speed.png avgcmp.png betteravg.png

all: $(ALL)

demo: demo.cpp $(DEPS)
	$(CC) $(FLAGS) $< -o $@

speed: speed.cpp $(DEPS)
	$(CC) $(FLAGS) -O2 -DNDEBUG $< -o $@

speed-sse: speed.cpp $(DEPS)
	$(CC) $(FLAGS) -O2 -msse -mfpmath=sse -ffast-math -DNDEBUG $< -o $@

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
	rm -f $(ALL) *.results *.png betteravg.gnuplot
