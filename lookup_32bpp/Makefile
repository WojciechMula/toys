.SUFFIXES:
.PHONY: all clean

FLAGS=-O3 -Wall -pedantic -std=c99

all: measure

lookup: lookup_32bpp.c
	gcc $(FLAGS) -m32 lookup_32bpp.c -o lookup

lookup_rgba: lookup_32bpp.c
	gcc $(FLAGS) -m32 -DRGBA lookup_32bpp.c -o lookup_rgba

TIME=/usr/bin/time -f "%E"
ITERS=1000
measure: lookup lookup_rgba
	$(TIME) ./lookup naive $(ITERS)
	$(TIME) ./lookup x86   $(ITERS)
	$(TIME) ./lookup sse2  $(ITERS)
	$(TIME) ./lookup sse4  $(ITERS)
	$(TIME) ./lookup_rgba naive $(ITERS)
	$(TIME) ./lookup_rgba x86   $(ITERS)
	$(TIME) ./lookup_rgba sse2  $(ITERS)
	$(TIME) ./lookup_rgba sse4  $(ITERS)

clean:
	rm lookup
