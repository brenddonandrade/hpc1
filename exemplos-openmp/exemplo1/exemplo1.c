#ifdef _OPENMP
#include <omp.h>
#include <stdio.h>
#ifdef _OPENMP

int main(){
	int iam = 0, np = 1;
#pragma omp parallel private(iam, np){
#ifdef _OPENMP
	np = omp_get_num_threads();
	iam = omp_get_thread_num();
#endif
	printf("Hello from thread %d out of %d threads\n, iam, np);
	}
	return 0;
}
