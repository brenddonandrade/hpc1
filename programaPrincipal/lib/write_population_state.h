#include "dependencias.h"
#include "constantes.h"

#ifndef WRITE_POPULATION_STATE
#define WRITE_POPULATION_STATE

void write_population_state(int **M, int itr){
	int i, j, result;
	FILE *arquivo;
	arquivo = fopen("./../source-gnu/dados-matrizes/populationState.dat", "w");
	
	char comando[120];

	sprintf(comando, "mv ./../source-gnu/dados-matrizes/populationState.dat ./../source-gnu/dados-matrizes/populationState-%d.dat", itr);	
	
	result = system(comando);

	for(i=1; i<POPULATION_X-1; i++){
		for(j =1; j<POPULATION_Y-1; j++)
			fprintf(arquivo, "%d ", M[i][j]);
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
	return;
}

#endif



