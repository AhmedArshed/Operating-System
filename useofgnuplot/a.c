#include <stdio.h>
#include <math.h>
#include<time.h>
#include <stdlib.h>
int main(int argc , char const *argv[])
 {
	double total_time;
	clock_t start, end;
	start = clock();
	srand(time(NULL));	
	int STEPS;
	STEPS = atoi(argv[1]);
	
	int count = 0;
	double x, y, z, pi;
	for (int i = 0; i <= STEPS; i++)  
	{
		x = rand()/(double)RAND_MAX; 
		y = rand()/(double)RAND_MAX;
		 z = x*x + y*y;
		if (z <= 1) count++;
	}
	pi = (double)count/STEPS*4;
	printf("%d\t", STEPS);
	printf(" %.20f", pi);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf(" %f\n", total_time);
}

