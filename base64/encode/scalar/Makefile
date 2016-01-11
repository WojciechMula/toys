run: speed
	./speed

speed: speed.cpp encode.cpp ../../gettime.cpp ../../cmdline.cpp
	g++ -std=c++11 -O3 -Wall -pedantic speed.cpp -o speed

clean:
	rm -f speed
