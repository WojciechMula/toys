#include <pthread.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sched.h>

#ifndef THREAD_NUM
#	define THREAD_NUM 8
#endif

pthread_mutex_t	mutex;
pthread_cond_t  cond;
pthread_t threads[THREAD_NUM];	// protected by mutex

int thread_count = 0;

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


void* thread(void* sec) {
	Job *job;
	double dRe, dIm;
	double Cre, Cim, Xre, Xim, Tre, Tim;
	int x, y, i;

	job = (Job*)sec;

#ifdef DEBUG
	printf("thread #%u -> CPU#%d\n", pthread_self(), sched_getcpu());
//	printf("begin thread %u [%f,%f]-[%f,%f]\n",
//		pthread_self(), job->Re1, job->Im1, job->Re2, job->Im2);
#endif
#if 1

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

#endif

#ifdef DEBUG
	printf("thread %u finished\n", pthread_self());
#endif

	pthread_mutex_lock(&mutex);
	threads[job->id] = 0;		// mark associated entry as free
	thread_count -= 1;
	pthread_cond_broadcast(&cond);	// resume main thread
	pthread_mutex_unlock(&mutex);

	pthread_detach(pthread_self());	// free thread resources
	pthread_exit(0);
}


int main() {
	Job jobs[JOBS_COUNT];

	memset(Image, 127, sizeof(Image));

	int x, y, i, j, k;
	int status;
	FILE* f;

	double Re_min = -2.0;
	double Re_max =  0.5;
	double Im_min = -1.0;
	double Im_max =  1.0;
	double ti1, ti2, tr1, tr2;

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
			jobs[i].threshold = 100.0;

			i += 1;
		}
	}

	// initialize threads list
	for (i=0; i < THREAD_NUM; i++)
		threads[i] = 0;

	// initialize mutex & condition var
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);


	// issue jobs
	
	printf("image dimensions %d x %d\n", WIDTH, HEIGHT);
	printf("image splitted into %d pieces size %d x %d\n",
		JOBS_COUNT, /*SUBIMG_*/SIZE, /*SUBIMG_*/SIZE);
	printf("up to %d thread(s) will be run\n", THREAD_NUM);

	j = 0;
	k = 0;
	while (k < THREAD_NUM) {
		pthread_mutex_lock(&mutex);
		if (j < JOBS_COUNT) {
			for (i=0; i < THREAD_NUM; i++) {
				if (threads[i] != 0 || j == JOBS_COUNT)
					continue;

				jobs[j].id = i;
				status = pthread_create(&threads[i], NULL, thread, (void*)&jobs[j]);
				if (status != 0) {
					printf("ERROR: can't create thread for job %d/%d: %s\n",
						j, JOBS_COUNT, strerror(status));
				}
				else {
#ifdef DEBUG
					printf("job %d/%d commited\n", j+1, JOBS_COUNT);
#endif
					j++;
					thread_count += 1;
				}
			}
		}
		else {
			k = 0;
			for (i=0; i < THREAD_NUM; i++)
				if (threads[i] == 0)
					k += 1;
		}

		if (k < THREAD_NUM)
			pthread_cond_wait(&cond, &mutex);
		pthread_mutex_unlock(&mutex);
	}


	while (1) {
		pthread_mutex_lock(&mutex);
		printf("thread_count = %d\n", thread_count);
		if (thread_count == 0) {
			pthread_mutex_unlock(&mutex);
			break;
		}
		
		pthread_cond_wait(&cond, &mutex);
		pthread_mutex_unlock(&mutex);
	}

	// save image
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
