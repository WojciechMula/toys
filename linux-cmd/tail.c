/* 
 * Wojciech Mu³a
 *
 * $Id: tail.c,v 1.1.1.1 2006-04-03 18:20:33 wojtek Exp $
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
#define SIZE (1024*8)
	static char buffer[SIZE];
	size_t	readed;
	size_t	off = 0;
	
	int	n = 0;
	int	k = 0;
	int	i = 0;
	long	*offsets;
	char	*p;
	FILE	*f;
	
	if (argc != 3)
		return 1;

	n = strtol(argv[1], &p, 10);
	if ((*p != '\0') || (n < 0))
		return 2;
	n++;

	offsets = (long*)malloc(n*sizeof(long));
	if (offsets == NULL)
		return 3;
	
	f = fopen(argv[2], "r");
	if (!f) {
		free(offsets);
		return 4;
	}

	while ((readed = fread(buffer, sizeof(char), SIZE, f))) {
	p = buffer;
	while (readed--) {
		if (*p++ == '\n') {
			offsets[i] = off+1;
			i = (i+1) % n;
			if (k < n) k++;
		}
		off++;
	}
	}


	if (k < n)
		rewind(f);
	else {
		fseek(f, offsets[i], SEEK_SET);
	}

	while ((readed = fread(buffer, sizeof(char), SIZE, f)))
		fwrite(buffer, sizeof(char), readed, stdout);
	
	free(offsets);
	fclose(f);

	return 0;
}
