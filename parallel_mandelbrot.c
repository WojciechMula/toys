/*
	Multithread Mandelbrot set generator, $Revision: 1.6 $

	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://www.republika.pl/wmula/

	License: BSD

	initial release 20-06-2008, last update $Date: 2008-06-25 17:15:53 $

	----------------------------------------------------------------------

	Program splits image into N independent pices and create threads
	that do calculations.  Program don't use full producer-consument scheme ---
	all pieces parameters are precalculated and then issued to execute.
	Condition variables are used to synchronization.

	With reasonable number of pieces speedup on 2 CPU machine is 2 (well, 1.99).

	Compilation:

		gcc -std=c99 -Wall -pedantic -lpthread -O3 parallel_mandelbrot.c -o your_favorite_name

	Usage:

		Program do not accept any argument, however following parameters
		can be set during compile time via following definitions:
		- WIDTH		- number, width of output image
		- HEIGHT	- number, height of output image
		- SIZE		- number, size of piece
		- THREAD_NUM	- number, max. number of threads
		- DEBUG		- be verbose

*/
#include <pthread.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sched.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>


#ifndef THREAD_NUM
#	define THREAD_NUM 8
#endif

pthread_mutex_t	mutex;
pthread_t threads[THREAD_NUM];

#ifndef WIDTH
#	define WIDTH (1024*4)
#endif
#ifndef HEIGHT
#	define HEIGHT (1024*4)
#endif
#ifndef SIZE
#	define SIZE 256
#endif


#if WIDTH % SIZE != 0
#	error "WIDTH must be multiply of SIZE"
#endif
#if HEIGHT % SIZE != 0
#	error "HEIGHT must be multiply of SIZE"
#endif

#define JOBS_COUNT ((WIDTH)/SIZE * (HEIGHT)/SIZE)


uint8_t Image[HEIGHT][WIDTH];

typedef struct {
	int id;
	double Re1, Im1, Re2, Im2;
	double threshold;
	int xo, yo;
	int width, height;
	int maxiters;
} Job;

Job jobs[JOBS_COUNT];	// protected by mutex
int free_job_idx = 0;	// protected by mutex


void* thread(void* sec) {
	Job *job;
	double dRe, dIm;
	double Cre, Cim, Xre, Xim, Tre, Tim;
	int x, y, i;

	int processed = 0;	// number of pieces already processed

#ifdef DEBUG
	printf("starting thread #%u\n", pthread_self());
#endif

	while (1) {	
		// get free job, or return if none left
		pthread_mutex_lock(&mutex);
		if (free_job_idx == JOBS_COUNT) {
			pthread_mutex_unlock(&mutex);
			break;
		}
		else {
			job = &jobs[free_job_idx];
			free_job_idx += 1;
		}
		pthread_mutex_unlock(&mutex);
		processed += 1;

#ifdef DEBUG
		printf("thread #%u: processing next part...\n");
#endif

		// process piece
		dRe = (job->Re2 - job->Re1)/job->width;
		dIm = (job->Im2 - job->Im1)/job->height;

		Cim = job->Im1;

		for (y=0; y < job->height; y++) {
			Cre = job->Re1;
			for (x=0; x < job->width; x++) {
				Xre = 0.0;
				Xim = 0.0;
				for (i=0; i < job->maxiters; i++) {
					Tre = Xre*Xre - Xim*Xim + Cre;
					Tim = 2*Xre*Xim + Cim;

					if (Tre*Tre + Tim*Tim > job->threshold)
						break;

					Xre = Tre;
					Xim = Tim;
				}

				// we are sure, that writes from different threads
				// do not overlap -- no synchronization needed
				Image[job->yo + y][job->xo + x] = (job->maxiters - i);
				Cre += dRe;
			}

			Cim += dIm;
		}
	} // while

#ifdef DEBUG
	printf("thread %u finished; num of pieces proceseed: %d\n", pthread_self(), processed);
#endif

	return (void*)(processed);
}


uint32_t get_time(void) {
	struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}


int main() {

	memset(Image, 127, sizeof(Image));

	int x, y, i;
	int status;
	FILE* f;

	double Re_min = -2.0;
	double Re_max =  0.5;
	double Im_min = -1.0;
	double Im_max =  1.0;
	double ti1, ti2, tr1, tr2;

	uint32_t time1, time2;

	// prepare jobs
	i = 0;
	for (y=0; y < HEIGHT; y += SIZE) {
		ti1 = ((double)y)/HEIGHT;
		ti2 = ((double)y + SIZE)/HEIGHT;
		for (x=0; x < WIDTH; x += SIZE) {
			tr1 = ((double)x)/WIDTH;
			tr2 = ((double)x + SIZE)/WIDTH;

			jobs[i].Re1 = Re_min + tr1 * (Re_max - Re_min);
			jobs[i].Im1 = Im_min + ti1 * (Im_max - Im_min);
			jobs[i].Re2 = Re_min + tr2 * (Re_max - Re_min);
			jobs[i].Im2 = Im_min + ti2 * (Im_max - Im_min);
			jobs[i].xo  = x;
			jobs[i].yo  = y;
			jobs[i].width  = SIZE;
			jobs[i].height = SIZE;
			jobs[i].maxiters = 255;
			jobs[i].threshold = 20.0;

			i += 1;
		}
	}
	
	// initialize mutex
	pthread_mutex_init(&mutex, NULL);
	
	
	//
	printf("image dimensions %d x %d\n", WIDTH, HEIGHT);
	printf("image splitted into %d pieces size %d x %d\n",
		JOBS_COUNT, /*SUBIMG_*/SIZE, /*SUBIMG_*/SIZE);
	printf("%d thread(s) will be run\n", THREAD_NUM);

	time1 = get_time();

	// run threads
	for (i=0; i < THREAD_NUM; i++) {
		threads[i] = 0;
		status = pthread_create(&threads[i], NULL, thread, NULL);
#ifdef DEBUG
		if (status == 0)
			printf("thread %d/%d created\n", i+1, THREAD_NUM);
		else
			printf("ERROR: can't create thread: %s\n", strerror(status));
#endif
	}

	// wait for completion
	for (i=0; i < THREAD_NUM; i++)
		pthread_join(threads[i], NULL);

	time2 = get_time();
	printf("all thread finished after %0.3fs, saving image\n", (time2-time1)/1000000.0);


	// save image (PGM)
	f = fopen("mandelbrot.pgm", "wb");
	if (f != NULL) {
		fprintf(f, "P5\n%d %d 255\n", (int)WIDTH, (int)HEIGHT);
		fwrite(Image, sizeof(Image), 1, f);
		fclose(f);
		return 0;
	}
	else {
		puts("ERROR: Can't open file for writing!");
		return 1;
	}

}

// eof

