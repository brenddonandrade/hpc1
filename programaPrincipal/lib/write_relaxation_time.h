#include "dependencias.h"
#include "constantes.h"
#include <time.h>

#ifndef WRITE_RELAXATION_TIME
#define WRITE_RELAXATION_TIME
void write_relaxation_time(int steps, double cu){
	FILE *arquivo;

	 // Obtém o tempo atual
	time_t t;
	struct tm *info;
	time(&t);
	info = localtime(&t);

	// Formata a data e hora
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d--%H:%M:%S", info);
	
	// relation_time-steps.dat
	arquivo = fopen("relatorio-programa.txt", "a");
    
	if (arquivo == NULL){
		printf("ERROR! Falha ao abrir arquivo.\n");
		return;
    		}

	fprintf(arquivo, "steps: %d\t cu: %.2lf\t dia: %s\t malha: %d\n", steps, cu, buffer, (POPULATION_X-2)*(POPULATION_Y-2));
	fclose(arquivo);
	return ;
}
#endif
