#include "constantes.h"

#ifndef HAMILTONIANA
#define HAMILTONIANA


// calculate energy of the system
int hamiltoniana(int **m){
        // h = hamiltoniana do sistema
        int h=0, i, j;

        for(i=0; i<(POPULATION -1) ; i++)
                for(j=0 ; j<(POPULATION -1); j++){
                        h += m[i][j];
                }
        return h;
}

#endif




