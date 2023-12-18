#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RM 1e8
#define N           10

void main(){
	int i, j;
	int R;
	double time_spent = 0.0;
		

	R = RM/N;


	double *A, *B, *C, *D;
	double S, E, MFLOPS;

	A = malloc(sizeof(double)*N);
	B = malloc(sizeof(double)*N);
	C = malloc(sizeof(double)*N);
	D = malloc(sizeof(double)*N);

	i=0;
	do {
		A[i] =  (int) 0;
		B[i] =  (int) 1;
		C[i] =  (int) 2;
		D[i] =  (int) 3;
		i++;
	}while(i<N);
	

	
	clock_t begin = clock();


	j=0;
	do{
		i=0;
		do{	
			A[i] = B[i] + C[i] * D[i];
			i++;	
		}while(i<N);
		j++;
	}while(j<R);

	clock_t end = clock();

	time_spent += (double) (end - begin)/CLOCKS_PER_SEC;

	//printf("Time: %lfs\n", time_spent);
	
	MFLOPS = (R*N*2)/((time_spent*1e6));
	printf("%d %lf\n", N, MFLOPS);

	return;
}
