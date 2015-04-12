.SUFFIXES:
.PHONY: clean all

CC=gcc
CCFLAGS=-std=c99 -O2
ALL=demo print_double

all: $(ALL)

demo: demo.c floor.c ieee_double.h
	$(CC) $(CCFLAGS) $< -o $@

print_double: print_double.c ieee_double.h
	$(CC) $(CCFLAGS) -lm $< -o $@

clean:
	rm -f $(ALL)
