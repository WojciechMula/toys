/*
  bmp2ascii
  
  Wojciech Mu³a (wojciech_mula@poczta.onet.pl)
  
  29-30.10.2002 -- Linux version
  
  compile:
  	g++ -O2 -o bmp2ascii bmp2ascii.cc
 */

#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <cstdint>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <sys/kd.h>

extern int errno;

// size of character cell (standard 80x25 EGA mode)
#define cellx 8
#define celly 16

// predefined sets of chars using to build ASCII-image
const char* set_l = "abcdefghijklmnopqrstuvwxyz";
const char* set_L = "ABCDEFGHIJKLMNOPQRSTUVWXZY";
const char* set_n = "012345678";
const char* set_s = "+-|=)([]@#$%^&*_~,.:;\"'`\\/?><";


unsigned char font[256][32];  // font data
char filename[256] = ""; // filename

int  width  = -1;        // width and 
int  height = -1;        // height of image in pixels
int  cx, cy;             // in character cells

int  negate = 0;         // image will be negate
char set[512] = "";      // set of characters using

unsigned char image_row[celly][2048]; // one image row (using by ASCII)
char char_row[2048+1];                // the character representation

// gets bitmap fonts frome EGA card
void get_EGA_font(unsigned char font[256][32]);

// guess
void parse_opt(int argc, char* argv[]);

// convert data from `image_row' (pixels) into `char_row' (characters)
void ASCII();

int main(int argc, char* argv[])
{
 parse_opt(argc, argv);
 get_EGA_font(font);

 cx = (width  + cellx-1)/cellx; // size of output image
 cy = (height + celly-1)/celly; // in character cells

 errno = 0;
 FILE *file = fopen(filename, "r");
 if (errno)
 	{
	 printf("open: %s\n",strerror(errno));
	 exit(1);
	}

 struct stat buf;
 stat(filename, &buf);
 if (errno)
 	{
	 printf("stat: %s\n", strerror(errno));
	 exit(1);
	}
	
 // skip header, in fact input data can be any bin file
 fseek(file, buf.st_size-(width*height)/cellx, SEEK_SET);
 if (errno)
 	{
	 printf("seek: %s\n", strerror(errno));
	 exit(1);
	}
 
 char_row[cx] = '\0';
 for (int y=0; y<cy; y++)
 	{
	 for (int n=0; n<celly; n++)
	 	{
		 memset(image_row[n], 0, sizeof(image_row[0]));
		 if (height--)
 	    	    fread(image_row[n], cx, 1, file);
		}

	 ASCII();

	 puts(char_row);
	}
 fclose(file);
 
 return 0;
}

void ASCII()
{
 static unsigned int diff[256];
 static unsigned int min;
 
 uint8_t *s;
 for (int i=0; i<cx; i++)
 	{
	 s = (uint8_t*)set;
	 while (*s)
	 	{
		 diff[*s] = 0;
		 for (int j=0; j<celly; j++)
		 	if (negate)
				diff[*s] += ~image_row[j][i] ^ font[*s][j];
			else
				diff[*s] += image_row[j][i] ^ font[*s][j];
		 s++;
		}
		
	 s   = (uint8_t*)set;
	 min = diff[uint8_t(char_row[cx-i-1] = *s)];
	 while (*s)
	 	{
		 if (diff[*s] < min)
			 min = diff[uint8_t(char_row[cx-i-1] = *s)];
		 s++;
		}
	}
}

void print_help()
{
 puts("bmp2ascii usage:\n"
      "-w=width   -- width of image\n"
      "-h=height  -- height of image\n"
      "-s=lLns    -- sets of chars using to build image\n"
      "              * l - small leters\n"
      "              * L - big letters\n"
      "              * n - numbers\n"
      "              * s - symbols\n"
      "              If no option specified all sets will be used.\n"
      "-f=name    -- filename\n"
      "-n         -- negate image\n"
      "--help     -- this info\n"
      "--version  -- info about bmp2ascii\n"
      "\n"
      "You can also set variable ASCII_SET to specify your own set of characters.\n"
     );
}

void print_version()
{
 puts("bmp2ascii by Wojciech Mula (wojciech_mula@poczta.onet.pl)");
}

void parse_opt(int argc, char* argv[])
{
 char *err;
 for (int i=1; i<argc; i++)
 	{
	 if (strcmp(argv[i], "--version") == 0)
	 	{
		 print_version();
		 exit(0);
		}
	 else
	 if (strcmp(argv[i], "--help") == 0)
	 	{
		 print_help();
		 exit(0);
		}
	 else	
	 if (strncmp(argv[i], "-h=", 3) == 0)
	 	{
		 height = strtol(&argv[i][3], &err, 10);
		 if (*err != '\0')
		 	{
			 puts("bad height");
			 exit(1);
			}
		}
	 else
	 if (strncmp(argv[i], "-w=", 3) == 0)
	 	{
		 width = strtol(&argv[i][3], &err, 10);
		 if (*err != '\0')
		 	{
			 puts("bad width");
			 exit(1);
			}
		}
	 else
	 if (strncmp(argv[i], "-f=", 3) == 0)
	 	{
		 strcpy(filename, &argv[i][3]);
		}
	 else
	 if (strcmp(argv[i], "-n") == 0)
	 	{
		 negate = 1;
		}
	 else
	 if (strncmp(argv[i], "-s=", 3) == 0)
	 	{
		 char *c = &argv[i][3];
		 while (*c)
		 	{
			 switch (*c) {
			  case 'l': strcat(set, set_l); break;
			  case 'L': strcat(set, set_L); break;
			  case 'n': strcat(set, set_n); break;
			  case 's': strcat(set, set_s); break;
			  default : puts("bad set\n");
			            print_help();
			            exit(1);
			  }
			 c++;
			}
		}
	 else
	 	{
		 printf("bad option `%s'\n\n", argv[i]);
		 print_help();
		 exit(1);
		}
	 
	}

 if ((width < 0 || width > 2048) || height < 0)
 	{
 	 puts("bad width or height\n");
	 print_help();
	 exit(1);
	}
 if (*filename == '\0')
 	{
	 puts("no filename\n");
	 print_help();
	 exit(1);
	}
 if (*set == '\0')
 	{
	 char *env = getenv("ASCII_SET");

	 if (env != NULL)
	 	 strcpy(set, env);
	 else
	 	{
		 strcpy(set, set_l);
		 strcat(set, set_L);
		 strcat(set, set_n);
		 strcat(set, set_s);
		}
	}
 strcat(set, " ");
 width = ((width+cellx-1)/cellx)*cellx;
}

void get_EGA_font(unsigned char font[256][32])
// The EGA fonts has got size 8x32 pixels.
{
 errno = 0;
 int tty = open("/dev/tty", O_RDWR);
 if (errno) goto error;

 ioctl(tty, GIO_FONT, font);
 if (errno) goto error;
 
 close(tty);
 if (errno) goto error;
 
 return;
error:
 printf("Loading font error: %s\n", strerror(errno));
 exit(1);
}
