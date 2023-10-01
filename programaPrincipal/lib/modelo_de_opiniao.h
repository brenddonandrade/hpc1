// Autor: Brenddon Oliveira
// Data: 15/09 ver: 0.1


//Dependecies
#include "./numero_aleatorio.h"
#include "./create_initial_state.h"
#include "./constantes.h"
#include "./plot_population_state.h"
#include "./write_population_state.h"
#include "./hamiltoniana.h"
#include "./social_media.h"
#include "./iteration.h"


#ifndef MODELO_DE_OPINIAO
#define MODELO_DE_OPINIAO

void inicialize(){
	int i, j, itr;
	int  **M;

	M = create_initial_state();
	iteration(&M);
	//plot_population_state(M);
	write_population_state(M);
}
#endif
