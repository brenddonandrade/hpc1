#include "dependencias.h"
#include "constantes.h"

#ifndef WRITE_POPULATION_STATE
#define WRITE_POPULATION_STATE

void write_population_state(int **M){
	int i, j;
	FILE *arquivo;

	arquivo = fopen("populationState.dat", "w");


	for(i=0; i<POPULATION; i++){
		for(j =0; j<POPULATION; j++)
			fprintf(arquivo, "%d ", M[i][j]);
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
	return;
}

#endif



