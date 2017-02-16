FLAGS=-O2

ALL=test demo

all: $(ALL)

test: test.c x86.c mmx.c
	$(CC) $(FLAGS) -m32 $< -o $@

demo: demo.c x86.c mmx.c
	$(CC) $(FLAGS) -I../Xscr -I../loadppm $< ../Xscr/Xscr.c ../loadppm/load_ppm.c -lX11 -o $@

clean:
	rm -f $(ALL)
