/* 
 * Wojciech Mu³a
 * 
 * $Id: sleep.c,v 1.1.1.1 2006-04-03 18:20:33 wojtek Exp $
 */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void help() {
puts(
	"sleep [--version|--help] TIME[s|m|h|d]\n"
	"\n"
	"--version - print version\n"
	"   --help - this help\n"
	"     TIME - an integer number; optional postfixes:\n"
	"            s - seconds (default)\n"
	"            m - minutes\n"
	"            h - hours\n"
	"            d - days\n"
);
}

void handler(int unused) {}

int main(int argc, char* argv[]) {
	unsigned int seconds;
	long int val;
	char *c, *e;

	if (argc < 2) {
		help();
		return 1;
	}
	
	if (strcmp(argv[1], "--version") == 0) {
		puts("no version");
		return 0;
	}
	else
	if (strcmp(argv[1], "--help") == 0) {
		help();
		return 0;
	}

	c = argv[1];
		
	val = strtol(c, &e, 10);
	
	/* invalid string or negative value */
	if ((e == c && val == 0) || (val < 0))
		return 2;

	if (*e == '\0')
		seconds = val;
	else
	if (*(e+1) == '\0')
		switch (*e) {
			case 's':
				seconds = val;
				break;
			case 'm':
				seconds = val*60;
				break;
			case 'h':
				seconds = val*60*60;
				break;
			case 'd':
				seconds = val*24*60*60;
				break;
			default:
				return 2;
		}
	else
		return 2;


	signal(SIGALRM, handler);
	
	alarm(seconds);
	pause();
	return 0;
}
