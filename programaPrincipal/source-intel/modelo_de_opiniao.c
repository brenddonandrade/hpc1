#include "../lib/modelo_de_opiniao.h"

void main(int argc, char *argv[]){

	int thread, ox;
	char compilador[15];
	
	strcpy(compilador, argv[3]);
	thread = atoi(argv[1]);
	ox = atoi(argv[2]);
	int time_cost;
	FILE *arquivo;	
	time_t inicio, fim;
	
	arquivo = fopen("relatorio-programa.txt","a");
	
	time(&inicio);
	inicialize();
	time(&fim);

	printf("Tempo (ini): %ld\n", inicio); 
	
	time_cost = fim - inicio;

	fprintf(arquivo, "Tempo (acima) %d\t treads: %d\t ox: %d\t cc: %s\n", time_cost, thread, ox, compilador);

	fclose(arquivo);

	return ;
}
