#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <pthread.h>

#define THREAD_COUNT 4

typedef struct
{
	int *frame;
	double p_x;
	double p_y;
	double radius;
	int resolution;
	int max_itter;
	double complex c;
	int y_start;
	int y_end;
} arg_struct;
	
void* compute(void *args)
{

	int *frame = ((arg_struct*)args)->frame;
	double p_x = ((arg_struct*)args)->p_x;
	double p_y = ((arg_struct*)args)->p_y;
	double radius = ((arg_struct*)args)->radius;
	int resolution = ((arg_struct*)args)->resolution;
	int max_itter = ((arg_struct*)args)->max_itter;
	double complex c = ((arg_struct*)args)->c;
	int y_start = ((arg_struct*)args)->y_start;
	int y_end = ((arg_struct*)args)->y_end;

	double x_min = p_x-radius;
	double x_max = p_x+radius;

	double y_min = p_y-radius;
	double y_max = p_y+radius;

	double x_step = (x_max-x_min)/((float)resolution);
	double y_step = (y_max-y_min)/((float)resolution);

	for(int y = y_start; y < y_end; y++)
	{
		for(int x = 0; x < resolution; x++)
		{
			double complex z = (x_min+(x*x_step)) + (y_max-(y*y_step))*I;
			int i = 0;
			for( ; i < max_itter; i++)
			{
				z = (z *z ) + c;
				if(cabs(z) > 2)
				{
					break;
				}
			}
			frame[y*resolution+x] = i;
		}
	}
	return NULL;
}

void julia(int *frame, double p_x, double p_y, double radius, int resolution, int max_itter, double complex c)
{

	arg_struct args[THREAD_COUNT];
	for(int i = 0; i < THREAD_COUNT; i++)
	{
		args[i].frame = frame;
		args[i].p_x = p_x;
		args[i].p_y = p_y;
		args[i].radius = radius;
		args[i].resolution = resolution;
		args[i].max_itter = max_itter;
		args[i].c = c;
	}

	for(int i = 0; i < THREAD_COUNT; i++)
	{
		args[i].y_start = i*(resolution/THREAD_COUNT);
		args[i].y_end= (i+1)*(resolution/THREAD_COUNT);
	}

	pthread_t threads[THREAD_COUNT];
	for(int i = 0; i < THREAD_COUNT; i++)
	{
		pthread_create(&threads[i], NULL, compute, &args[i]);
	}

	for(int i = 0; i < THREAD_COUNT; i++)
	{
		pthread_join(threads[i],NULL);
	}
	
}

int main(int argc, char *argv[])
{
	if(argc != 8)
	{
		printf("Error: Expecting 7 params!\n");
		return 1;
	}

	char *ptr;
	double p_x = strtod(argv[1],&ptr);
	double p_y = strtod(argv[2],&ptr);
	double radius = strtod(argv[3],&ptr);
	int resolution = atoi(argv[4]);
	int max_itter = atoi(argv[5]);
	double complex c = strtod(argv[6],&ptr) + strtod(argv[7],&ptr)*I;

	int *frame = malloc(sizeof(int[resolution][resolution]));
	if(frame == NULL)
	{
		printf("Error: Could not allocate frame!\n");
		return 1;
	}

	julia(frame, p_x, p_y, radius, resolution, max_itter, c);

	FILE *fp = fopen("julia.dat", "w");
	if(fp == NULL)
	{
		printf("Error: Could not open file!\n");
		return 1;
	}

	for(int y = 0; y < resolution; y++)
	{
		for(int x = 0; x < resolution - 1; x++)
		{
			fprintf(fp,"%d,",frame[y*resolution+x]);
		}
		fprintf(fp,"%d\n",frame[y*resolution+resolution-1]);
	}

	free(frame);

	return 0;
}