#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void julia(int *frame, int resolution, int max_itter, double complex c)
{
	double x_step = 4.0/((float)resolution);
	double y_step = 4.0/((float)resolution);
	for(int y = 0; y < resolution; y++)
	{
		for(int x = 0; x < resolution; x++)
		{
			double complex z = (-2.0+(x*x_step)) + (-2.0+(y*y_step))*I;
			int i = 0;
			for( ; i < max_itter; i++)
			{
				z = (z * z) + c;
				if(cabs(z) > 2)
				{
					break;
				}
			}
			frame[y*resolution+x] = i;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Error: Expecting 3 params!\n");
		return 1;
	}

	int resolution = atoi(argv[1]);
	char *ptr;
	double complex c = strtod(argv[2],&ptr) + strtod(argv[3],&ptr)*I;

	int *frame = malloc(sizeof(int[resolution][resolution]));
	if(frame == NULL)
	{
		printf("Error: Could not allocate frame!\n");
		return 1;
	}

	julia(frame, resolution, 150, c);

	FILE *fp = fopen("julia.dat", "w");
	if(fp == NULL)
	{
		printf("Error: Could not open file!\n");
		return 1;
	}

	for(int i = 0; i < resolution*resolution; i++)
	{
		fprintf(fp,"%d\n",frame[i]);
	}

	free(frame);

	return 0;
}