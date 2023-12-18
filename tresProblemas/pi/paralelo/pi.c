// libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

// constants
#define R 1
#define A 1
#define B 1
#define N_POINTS 1000000000
#define CHUNK 10000

// eq do circulo (x - a)^2 + (y - b)^2 = r^2
// r=1
// a=1
// b=1

int in_circle(double x, double y) {
    double result = pow(x - A, 2) + pow(y - B, 2);
    if (result <= R)
        return 1;
    else
        return 0;
}

int main() {
    srand(time(NULL));
    int circle_count = 0;
    double pos_x, pos_y, pi;

    #pragma omp parallel private(pos_x, pos_y) reduction(+:circle_count)
    {
        #pragma omp for schedule(dynamic, CHUNK) nowait
        for (int i = 0; i < N_POINTS; i++) {
            pos_x = (float)rand() / RAND_MAX;
            pos_y = (float)rand() / RAND_MAX;

            if (in_circle(pos_x, pos_y))
                circle_count++;
        }
    }

    pi = 4.0 * (double)circle_count / N_POINTS;

    printf("PI_apx: %lf\nPI: %lf\n", pi, M_PI);
    return 0;
}

