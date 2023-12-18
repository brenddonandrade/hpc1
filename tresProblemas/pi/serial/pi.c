// libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// constants
#define R 1
#define A 1
#define B 1
// #define N_POINTS 1000000000
#define N_POINTS 1000000000


// eq do circulo (x - a)^2 + (y - b)^2 = r^2
// r=1
// a=1
// b=1



int in_circle(double x, double y){
	double result;	
	result = pow(x-A, 2) + pow(y-B, 2);
	if(result <= R)
		return 1;
	else
		return 0;
}

int main(){
	
	srand(time(NULL));
	int circle_count = 0, count=0;
	double pos_x, pos_y, pi;
	
	do {
		pos_x = (float) rand() /RAND_MAX;
		pos_y = (float) rand() /RAND_MAX;
		
		if (in_circle(pos_x, pos_y))
			circle_count++;

		count++;
	}while(count  < N_POINTS);
	
	pi = 4.0 * (float)circle_count/N_POINTS;

	printf("PI_apx: %lf\nPI: %lf\n", pi, M_PI);
	return 0;

}
