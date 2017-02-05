FLAGS=-std=c99 -Wall -Wextra -pedantic -O3 -Wfatal-errors
FLAGS+=-mfpu=neon-vfpv4

MAIN=main.c
DEPS=$(MAIN) fpu-proc.c neon-proc-32-bit.c
ALL=fractal

all: $(ALL)

fractal: $(DEPS)
	$(CC) $(FLAGS) $(MAIN) -o $@

clean:
	rm -f $(ALL)
