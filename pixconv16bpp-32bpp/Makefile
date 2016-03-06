.SUFFIXES:
.PHONY: all measure clean

FLAGS=-O3 -Wall -pedantic -std=c99 -m32
ALL=test320x200 test640x480 test800x600 test1024x768
MEASURE=measure320x200 measure640x480 measure800x600 measure1024x768

all: $(ALL) measure

measure: $(MEASURE)

test320x200: pixconv16bpp-32bpp.c
	gcc $(FLAGS) -DWIDTH=320 -DHEIGHT=200 $^ -o $@

test640x480: pixconv16bpp-32bpp.c
	gcc $(FLAGS) -DWIDTH=640 -DHEIGHT=480 $^ -o $@

test800x600: pixconv16bpp-32bpp.c
	gcc $(FLAGS) -DWIDTH=800 -DHEIGHT=600 $^ -o $@

test1024x768: pixconv16bpp-32bpp.c
	gcc $(FLAGS) -DWIDTH=1024 -DHEIGHT=768 $^ -o $@

measure320x200: test320x200
	bash pixconv16bpp-32bpp.sh $^

measure640x480: test640x480
	bash pixconv16bpp-32bpp.sh $^

measure800x600: test800x600
	bash pixconv16bpp-32bpp.sh $^

measure1024x768: test1024x768
	bash pixconv16bpp-32bpp.sh $^

clean:
	rm -f $(ALL)
	rm -f *.log
