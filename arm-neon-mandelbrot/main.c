/*
    Mandelbrot fractal generator --- ARM Neon implementation

    Author: Wojciech Muła
    e-mail: wojciech_mula@poczta.onet.pl
    www:    http://0x80.pl/

    License: BSD

    Usage:

        run program without arguments to read help

*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <sys/time.h>
#include <stdarg.h>

//=== helper functions ===================================================
uint32_t get_time(void) {
    static struct timeval T;
    gettimeofday(&T, NULL);
    return (T.tv_sec * 1000000) + T.tv_usec;
}


void die(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    putchar('\n');
    va_end(ap);

    exit(EXIT_FAILURE);
}


#include "fpu-proc.c"
#include "neon-proc-32-bit.c"


//=== main program =======================================================
#define WIDTH  (512*4)
#define HEIGHT (512*4)

uint8_t image[WIDTH][HEIGHT];


void help(char* progname) {

    printf("%s procedure [Remin Immin Remax Immax [threshold] [maxiters]] [--dry-run]\n", progname);
    puts("");
    puts("FPU - select FPU procedure");
    puts("Neon - select ARM Neon procedure");
    puts("fma - select ARM Neon procedure, that use FMA instructions");
    puts("");
    puts("Parameters:");
    puts("");
    puts("Remin Immin Remax Immax - define area of calculations; default -2.0 -2.0 +2.0 +2.0");
    puts("threshold - define max radius, greater than 0; default 20.0");
    puts("maxiters  - define max number of iterations; default 255");
    puts("");
    puts("Options:");
    puts("");
    puts("--dry-run - do not save any file");
    exit(EXIT_FAILURE);
}



int main(int argc, char* argv[]) {
    FILE* f = NULL;

    uint32_t t1, t2;

    // parameters
    float Re_min = -2.0, Re_max = +2.0;
    float Im_min = -2.0, Im_max = +2.0;
    float threshold = 20.0;
    int   maxiters  = 255;

    enum {
        FPUprocedure,
        NeonProcedure,
        NeonFMAProcedure
    } function;

    // parse command line
    char *err;
    if (argc == 1) {
        help(argv[0]);
    }


    // 1. function name
    if (strcasecmp(argv[1], "FPU") == 0) {
        function = FPUprocedure;
    } else if (strcasecmp(argv[1], "Neon") == 0) {
        function = NeonProcedure;
    } else if (strcasecmp(argv[1], "FMA") == 0) {
        function = NeonFMAProcedure;
    } else {
        help(argv[0]);
    }


    // 2. optional area of calculations
    if (argc >= 6) {
        Re_min = strtod(argv[2], &err);
        if (*err != '\0') die("Invalid Remin value");

        Im_min = strtod(argv[3], &err);
        if (*err != '\0') die("Invalid Immin value");

        Re_max = strtod(argv[4], &err);
        if (*err != '\0') die("Invalid Remax value");

        Im_max = strtod(argv[5], &err);
        if (*err != '\0') die("Invalid Immax value");
    }

    // 3. optional threshold value
    if (argc >= 7) {
        threshold = strtod(argv[6], &err);
        if (*err != '\0') die("Invalid threshold value");
        if (threshold <= 0)
            die("threshold must be greater than 0");
    }

    // 4. optional maxiters values
    if (argc >= 8) {
        maxiters = strtol(argv[7], &err, 10);
        if (*err != '\0') die("Invalid maxiters value");
        if (maxiters <= 0)
            die("maxiters must be greater than 0");
    }


    // check for options
    char dry_run = 0;
    for (int i=1; i < argc; i++) {
        if (strcmp(argv[i], "--dry-run") == 0) {
            dry_run = 1;
            break;
        }
    }


    // print summary
    printf("Image %d x %d, Area [(%0.5f,%0.5f), (%0.5f, %0.5f)], thresold=%0.2f, maxiters=%d\n",
        WIDTH, HEIGHT,
        Re_min, Im_min, Re_max, Im_max,
        threshold,
        maxiters
    );


    // run selected function
    switch (function) {
        case FPUprocedure:
            printf("FPU ");
            fflush(stdout);
            t1 = get_time();
            FPU_mandelbrot(
                Re_min, Re_max,
                Im_min, Im_max,
                threshold, maxiters,
                WIDTH, HEIGHT,
                &image[0][0]
            );
            t2 = get_time();
            printf("%d us\n", t2-t1);
            break;

        case NeonProcedure:
            printf("ARM Neon ");
            fflush(stdout);
            t1 = get_time();
            Neon_mandelbrot(
                Re_min, Re_max,
                Im_min, Im_max,
                threshold, maxiters,
                WIDTH, HEIGHT,
                &image[0][0]
            );
            t2 = get_time();
            printf("%d us\n", t2-t1);
            break;

        case NeonFMAProcedure:
            printf("ARM Neon (FMA) ");
            fflush(stdout);
            t1 = get_time();
            NeonFMA_mandelbrot(
                Re_min, Re_max,
                Im_min, Im_max,
                threshold, maxiters,
                WIDTH, HEIGHT,
                &image[0][0]
            );
            t2 = get_time();
            printf("%d us\n", t2-t1);
            break;
    }

    // save image
    if (!dry_run) {
        f = fopen("fractal.pgm", "wb");
        fprintf(f, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
        fwrite(image, WIDTH*HEIGHT, 1, f);
        fclose(f);
    }
    return 0;
}

