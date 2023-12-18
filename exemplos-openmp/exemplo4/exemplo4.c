#include <omp.h>
#define CHUNK 100
#define N 1000

int main(){
	int i, n , chunk;
	double a[N], b[N], c[N];
	
	for (i=0; i<N ; i++)
		a[i] = b[i] = i*1.0;
	
	n=N;
	
	#pragma omp parallel shared(a,b,c,n,chunk) private(i) 
	{
		#pragma omp for schedule(dynamic, chunk) nowait 
		for( i=0; i<n; i++)
			c[i] = a[i] + b[i];
		
	}
	return 0;
}
