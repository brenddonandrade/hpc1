#include "dependencias.h"
#include "constantes.h"

#ifndef PLOT_POPULATION_STATE
#define PLOT_POPULATION_STATE


// Plot state of the population
void plot_population_state(int **M){
	int i, j;

	for(i=0; i<POPULATION; i++){
		printf("\t");
		for(j=0; j<POPULATION; j++){
			printf("%d\t", M[i][j]);
		}
		puts("");
	}
}
#endif

