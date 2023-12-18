#include <stdio.h>
#include <omp.h>

int main() {
	int i, f, a[20], b[20];
	
	
	#pragma omp parallel private(f)
	{
		f=7;
		#pragma omp for
			for (i=0; i<20; i++)
				a[i] = b[i] + f * (i+1);
	}
	return 0;
}
