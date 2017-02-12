/* 
 * Wojciech Mula wojciech_mula[at]poczta.onet.pl
 * 11-12.07.2004
 * public domain
 */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 512
struct {
	int line, column;
} stack[STACK_SIZE];
int stack_pointer = 0;

int sp() {
	return stack_pointer;
}

int full() {
	return stack_pointer == STACK_SIZE;
}

int empty() {
	return stack_pointer == 0;
}

void push(int line, int column) {
	stack[stack_pointer].line	= line;
	stack[stack_pointer].column	= column;
	stack_pointer++;
}

void pop(int *line, int *column) {
	stack_pointer--;
	if (line != NULL)
		*line	= stack[stack_pointer].line;
	if (column != NULL)
		*column	= stack[stack_pointer].column;
}

int check_TeX_parentheses(const char* filename) {
#define size (1024*8)	
	static char buffer[size];
	FILE* f;
	size_t readed;
	
	int line	= 1;
	int column	= 1;
	int comment	= 0;
	int level;
	
	char prev	= 0;
	char *this;

	f = fopen(filename, "rb");	/* read-only */
	if (f==NULL) {
		printf("Can't open file '%s'.\n", filename);
		return 0;
	}

	while (readed = fread(buffer, sizeof(char), size, f)) {
	
	this = buffer;

	while (readed--) {
		if (*this == '\n') {
			comment = 0; /* new line ends comment */
			column  = 1;
			line++;
			
			prev = *this++;
			continue;
		}
	
		/* do not check chars inside comments 
		   nor escaped: \{, \}, \% */
		if (comment || prev == '\\') {
			if (*this == '\\')
				/* without this condition program reports 
				   extra closing bracket for TeX code "\\{ ... }" */
				prev = 0;
				 
			else
				prev = *this;
			this++;
			column++;
			continue;
		}
		
		switch (*this) {
			case '%': /* comment started */
				comment = 1;
				break;	
			case '{': /* new group opened */
				if (!full())
					push(line, column);
				else {
					puts("Stack is full, recompile the program with larger stack (incrase STACK_SIZE).");
					goto error;
				}
				break;
			case  '}': /* toplevel group closed */
				if (!empty())
					pop(NULL, NULL);
				else {
					printf("%s: extra closing bracket at line %d, column %d\n.", filename, line, column);
					goto error;
				}
				break;
		}

		prev = *this++;
		column++;
	}
	}

ok:
	if (!empty()) {
		if (sp() > 1)
			printf("There are some opened groups:\n");
		else
			printf("There is an opened group:\n");

		while (!empty()) {
			level = sp();
			pop(&line, &column);
			printf("%s: level %d, line %d, column %d\n", 
				filename, level, line, column);
		}
	}
	fclose(f);
	return 1;
error:
	fclose(f);
	return 0;
#undef size
}

int main(int argc, char* argv[]) {
	int i;
	for (i=1; i<argc; i++)
		check_TeX_parentheses(argv[i]);
	return 0;
}
