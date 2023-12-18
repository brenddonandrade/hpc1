#include <stdio.h>
#include <omp.h>

int main(){
	int nthreads, tid;

	#pragma omp parallel private(nthreads, tid)
	{
		// obtain and print thread id
		tid = omp_get_thread_num();
		printf("Hello World from thread = %d\n", tid);
		
		// Only master thread does this
		if(tid == 0){
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n" ,nthreads);
		}
		
	}
	
	return 0;
}
