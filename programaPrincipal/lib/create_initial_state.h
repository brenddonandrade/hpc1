#include "dependencias.h"
#include "constantes.h"
#include "numero_aleatorio.h"

#ifndef CREATE_INITIAL_STATE
#define CREATE_INITIAL_STATE


// define the initial state of the population
int **create_initial_state(){
	int i, j, test;
        int **M;
        M = malloc(sizeof(int*) * POPULATION_X);
        for(i=0; i< POPULATION_X; i++)
                M[i] = malloc(sizeof(int)* POPULATION_Y);

        switch(INITIAL_STATE){
                case 0:
                        for(i=0; i< POPULATION_X; i++)
                                for(j=0; j<POPULATION_Y; j++)
                                        M[i][j] = -1;
                        break;

                case 1:
                        for(i=0; i<POPULATION_X; i++)
                                for(j=0; j<POPULATION_Y; j++)
                                        M[i][j] = 1;
                        break;
                case 2:
                        for(i=0; i<POPULATION_X; i++)
                                for(j=0; j<POPULATION_Y; j++)     {

                                        test =  rand_number(100);
                                        if (test < MAN)
                                                M[i][j] = 1;
                                        else
                                                M[i][j] = -1;
                                }
        }
        return M;
}
#endif
