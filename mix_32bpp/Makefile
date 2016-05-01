.SUFFIXES:
.PHONY: all clean

FLAGS=-O3 -Wall -pedantic -std=c99
XSCR_DEPS=../Xscr/Xscr.h ../Xscr/Xscr.c
LOADPPM_DEPS=../loadppm/load_ppm.h ../loadppm/load_ppm.c


all: measure

measure: mix
	./mix measure x86 100
	./mix measure SSE4 100
	./mix measure SSE4-2 100

mix: mix_32bpp.c
	$(CC) $(FLAGS) -m32 mix_32bpp.c -o $@

demo: mix_32bpp.c loadppm.o Xscr.o
	$(CC) $(FLAGS) -lX11 mix_32bpp.c Xscr.o loadppm.o -DUSE_Xscr -o $@

Xscr.o: $(XSCR_DEPS)
	$(CC) $(FLAGS) -c -lX11 ../Xscr/Xscr.c -o $@

loadppm.o: $(LOADPPM_DEPS)
	$(CC) $(FLAGS) -c -lX11 -DPPM_ALIGN_MALLOC=16 ../loadppm/load_ppm.c -o $@

clean:
	rm -f demo mix *.o
