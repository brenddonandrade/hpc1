#include "dependencias.h"
#include "constantes.h"

#ifndef CREATE_INITIAL_STATE
#define CREATE_INITIAL_STATE


// define the initial state of the population
int **create_initial_state(){
	int i, j, test;
        int **M;
        M = malloc(sizeof(int*) * POPULATION);
        for(i=0; i< POPULATION; i++)
                M[i] = malloc(sizeof(int)* POPULATION);

        switch(INITIAL_STATE){
                case 0:
                        for(i=0; i< POPULATION; i++)
                                for(j=0; j<POPULATION; j++)
                                        M[i][j] = -1;
                        break;

                case 1:
                        for(i=0; i<POPULATION; i++)
                                for(j=0; j<POPULATION; j++)
                                        M[i][j] = 1;
                        break;
                case 2:
                        for(i=0; i<POPULATION; i++)
                                for(j=0; j<POPULATION; j++)     {

                                        test =  rand_number(99);
                                        if (test < MAN)
                                                M[i][j] = 1;
                                        else
                                                M[i][j] = -1;
                                }
        }
        return M;
}
#endif
