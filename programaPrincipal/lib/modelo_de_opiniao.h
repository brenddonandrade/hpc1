// Autor: Brenddon Oliveira
// Data: 15/09 ver: 0.1


//Dependecies
#include "./numero_aleatorio.h"
#include "./create_initial_state.h"
#include "./constantes.h"
#include "./write_population_state.h"
#include "./social_media.h"
#include "./iteration.h"


#ifndef MODELO_DE_OPINIAO
#define MODELO_DE_OPINIAO

void inicialize(){
	int i, j, itr;
	int  **M;

	M = create_initial_state();
	iteration(M);
}
#endif
