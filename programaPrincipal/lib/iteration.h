#include "dependencias.h"
#include "constantes.h"
#include "social_media.h"

#ifndef ITERATION
#define ITERATION

void iteration(int  ***M){
        int i, j, itr, pos_rand_x, pos_rand_y, test;
	int **m = *M;
	double s;
	
	itr = 0;
    do {
		s = 0;

		pos_rand_x = rand_number(POPULATION-1);
		pos_rand_y = rand_number(POPULATION-1);
		
		for(i=0; i<POPULATION ; i++){
			for(j=0; j<POPULATION; j++){
				s +=  m[i][j];
			}
		}
		s =  s/((POPULATION)*(POPULATION));
		printf("itr: %d\ts: %lf\n", itr, s);

		if((pos_rand_x < (POPULATION-2)) && (pos_rand_x > 0)  && (pos_rand_y > 0) && (pos_rand_y < (POPULATION -2))){
			test = 	(m[pos_rand_x][pos_rand_y] == m[pos_rand_x][pos_rand_y+1] == m[pos_rand_x+1][pos_rand_y] == m[pos_rand_x+1][pos_rand_y+1]);
			if(test){
				m[pos_rand_x-1][pos_rand_y] = m[pos_rand_x-1][pos_rand_y+1] = m[pos_rand_x][pos_rand_y+2] = m[pos_rand_x+1][pos_rand_y+2] = m[pos_rand_x+2][pos_rand_y+1] = m[pos_rand_x+2][pos_rand_y] = m[pos_rand_x+1][pos_rand_y-1] = m[pos_rand_x][pos_rand_y-1] = m[pos_rand_x][pos_rand_y];
			} else {
				m[pos_rand_x-1][pos_rand_y] = social_media_effect();
				m[pos_rand_x-1][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x][pos_rand_y+2] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y+2] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y-1] = social_media_effect();
				m[pos_rand_x][pos_rand_y-1] = social_media_effect();
			}
		} else if((pos_rand_x == (POPULATION -1)) && (pos_rand_y > 0) && (pos_rand_y < (POPULATION -1))){
			test = 	(m[pos_rand_x][pos_rand_y] == m[pos_rand_x][pos_rand_y+1] == m[0][pos_rand_y] == m[0][pos_rand_y+1]);
			if(test){
				m[1][pos_rand_y] = m[1][pos_rand_y+1] = m[0][pos_rand_y+2] = m[pos_rand_x][pos_rand_y+2] = m[pos_rand_x-1][pos_rand_y+1] = m[pos_rand_x-1][pos_rand_y] = m[pos_rand_x][pos_rand_y-1] = m[0][pos_rand_y-1] = m[pos_rand_x][pos_rand_y];
			} else {
				m[1][pos_rand_y] = social_media_effect();
				m[1][pos_rand_y+1] = social_media_effect();
				m[0][pos_rand_y+2] = social_media_effect();
				m[pos_rand_x][pos_rand_y+2] = social_media_effect();
				m[pos_rand_x-1][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x-1][pos_rand_y] = social_media_effect();
				m[pos_rand_x][pos_rand_y-1] = social_media_effect();
				m[0][pos_rand_y-1] = social_media_effect();
			}
		} else if((pos_rand_y == (POPULATION -1)) && (pos_rand_x > 0) && (pos_rand_x < (POPULATION - 1))) {
			test = 	(m[pos_rand_x][pos_rand_y] == m[pos_rand_x+1][pos_rand_y] == m[pos_rand_x][0] == m[pos_rand_x+1][0]);
			if(test){
				m[pos_rand_x-1][pos_rand_y] = m[pos_rand_x-1][0] = m[pos_rand_x][1] = m[pos_rand_x+1][1] = m[pos_rand_x+2][0] = m[pos_rand_x +2][pos_rand_y] = m[pos_rand_x][pos_rand_y-1] = m[pos_rand_x+1][pos_rand_y-1] = m[pos_rand_x][pos_rand_y];
			} else {
				m[pos_rand_x-1][pos_rand_y] = social_media_effect();
				m[pos_rand_x-1][0] = social_media_effect();
				m[pos_rand_x][1] = social_media_effect();
				m[pos_rand_x+1][1] = social_media_effect();
				m[pos_rand_x+2][0] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y] = social_media_effect();
				m[pos_rand_x][pos_rand_y-1] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y-1] = social_media_effect();
			}
		} else if((pos_rand_x == 0) && (pos_rand_y < (POPULATION-1)) && (pos_rand_y > 0)) {
			test = 	(m[pos_rand_x][pos_rand_y] == m[pos_rand_x + 1][pos_rand_y] == m[pos_rand_x][pos_rand_y+1] == m[pos_rand_x+1][pos_rand_y + 1]);
			if(test){
				m[POPULATION-1][pos_rand_y] = m[pos_rand_x][pos_rand_y-1] = m[pos_rand_x][pos_rand_y+2] = m[POPULATION-1][pos_rand_y+1] = m[pos_rand_x+1][pos_rand_y-1] = m[pos_rand_x+2][pos_rand_y] = m[pos_rand_x+2][pos_rand_y+1] = m[pos_rand_x+1][pos_rand_y+2] = m[pos_rand_x][pos_rand_y];
			} else {
					
				m[POPULATION-1][pos_rand_y] = social_media_effect();
				m[pos_rand_x][pos_rand_y-1] = social_media_effect();
				m[pos_rand_x][pos_rand_y+2] = social_media_effect();
				m[POPULATION-1][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y-1] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y+2] = social_media_effect();
			}
		} else if((pos_rand_y == 0) && (pos_rand_x < (POPULATION-1)) && (pos_rand_x > 0)) {
			test = 	(m[pos_rand_x][pos_rand_y] == m[pos_rand_x + 1][pos_rand_y] == m[pos_rand_x][pos_rand_y+1] == m[pos_rand_x+1][pos_rand_y + 1]);
			if(test){
				m[pos_rand_x-1][pos_rand_y] = m[pos_rand_x-1][pos_rand_y+1] = m[pos_rand_x][pos_rand_y+2] = m[pos_rand_x+1][pos_rand_y+2] = m[pos_rand_x+2][pos_rand_y+1] = m[pos_rand_x+2][pos_rand_y] = m[pos_rand_x][POPULATION-1] = m[pos_rand_x+1][POPULATION-1] = m[pos_rand_x][pos_rand_y];
			}else {
                                m[pos_rand_x-1][pos_rand_y] = social_media_effect();
                                m[pos_rand_x-1][pos_rand_y+1] = social_media_effect();
                                m[pos_rand_x][pos_rand_y+2] = social_media_effect();
                                m[pos_rand_x+1][pos_rand_y+2] = social_media_effect();
                                m[pos_rand_x+2][pos_rand_y+1] = social_media_effect();
                                m[pos_rand_x+2][pos_rand_y] = social_media_effect();
                                m[pos_rand_x][POPULATION-1] = social_media_effect();
                                m[pos_rand_x+1][POPULATION-1] = social_media_effect();	
			}
		}else if((pos_rand_x == (POPULATION-1) && (pos_rand_y == (POPULATION-1)))){
			test = (m[POPULATION-1][POPULATION-1] == m[POPULATION-1][0] == m[0][POPULATION-1] == m[0][0]);
			if(test) {
				m[POPULATION-2][POPULATION-1] = m[POPULATION -2][0] = m[POPULATION-1][1] = m[0][1] = m[1][0] = m[1][POPULATION -1] = m[0][POPULATION-2] = m[POPULATION-1][POPULATION-2] = m[pos_rand_x][pos_rand_y];
			} else {
				
                                m[POPULATION-2][POPULATION-1] = social_media_effect();
                                m[POPULATION-2][0] = social_media_effect();
                                m[POPULATION-1][1] = social_media_effect();
                                m[0][1] = social_media_effect();
                                m[1][0] = social_media_effect();
                                m[1][POPULATION-1] = social_media_effect();
                                m[0][POPULATION-2] = social_media_effect();
                                m[POPULATION-1][POPULATION-2] = social_media_effect();
			}
		} else if((pos_rand_x == 0) && (pos_rand_y == (POPULATION-1))){
			test = (m[0][POPULATION-1] == m[0][0] == m[1][POPULATION-1] == m[1][0]);
			if(test){
				m[POPULATION-1][POPULATION-1] = m[POPULATION-1][0] = m[0][1] = m[1][1] = m[2][0] = m[2][POPULATION-1] = m[1][POPULATION-2] = m[0][POPULATION-2] = m[pos_rand_x][pos_rand_y];
			}else {
                                m[POPULATION-1][POPULATION-1] = social_media_effect();
                                m[POPULATION-1][0] = social_media_effect();
                                m[0][1] = social_media_effect();
                                m[1][1] = social_media_effect();
                                m[2][0] = social_media_effect();
                                m[2][POPULATION-1] = social_media_effect();
                                m[1][POPULATION-2] = social_media_effect();
                                m[0][POPULATION-2] = social_media_effect();

			}
		} else if((pos_rand_x == 0) && (pos_rand_y == 0)){
			test = (m[0][0] == m[0][1] == m[1][0] == m[1][1]);
			if(test) {
				m[POPULATION-1][0] = m[POPULATION -1][1] = m[0][2] = m[1][2] = m[2][0] = m[2][1] = m[1][POPULATION-1] = m[0][POPULATION -1] = m[pos_rand_x][pos_rand_y];
			} else {
                                m[POPULATION-1][0] = social_media_effect();
                                m[POPULATION-1][1] = social_media_effect();
                                m[0][2] = social_media_effect();
                                m[1][2] = social_media_effect();
                                m[2][0] = social_media_effect();
                                m[2][1] = social_media_effect();
                                m[1][POPULATION-1] = social_media_effect();
                                m[0][POPULATION-1] = social_media_effect();
			}
		} else if ((pos_rand_x == (POPULATION-1) && (pos_rand_y == 0))) {
			test = (m[POPULATION-1][0] == m[POPULATION-1][1] == m[0][0] == m[0][1]);
			if(test) {
				m[POPULATION-2][0] = m[POPULATION-2][1] = m[POPULATION-1][2] = m[0][2] = m[1][1] = m[1][0] = m[0][POPULATION-1] = m[POPULATION-1][POPULATION-1] = m[pos_rand_x][pos_rand_y];
			} else {
                                m[POPULATION -2][0] = social_media_effect();
                                m[POPULATION -2][1] = social_media_effect();
                                m[POPULATION -1][2] = social_media_effect();
                                m[0][2] = social_media_effect();
                                m[1][1] = social_media_effect();
                                m[1][0] = social_media_effect();
                                m[0][POPULATION-1] = social_media_effect();
                                m[POPULATION-1][POPULATION-1] = social_media_effect();
			}
		}else if ((pos_rand_x == (POPULATION - 2)) && (pos_rand_y > 0) &&(pos_rand_y < (POPULATION-2))){
			test = (m[POPULATION-2][pos_rand_y] == m[POPULATION-2][pos_rand_y+1] == m[POPULATION-1][pos_rand_y] == m[POPULATION-1][pos_rand_y] == m[POPULATION-1][pos_rand_y+1]);
			if (test){
				m[POPULATION-3][pos_rand_y] = m[POPULATION-3][pos_rand_y+1] = m[POPULATION-2][pos_rand_y+2] = m[POPULATION-1][pos_rand_y+2] = m[0][pos_rand_y+1] = m[0][pos_rand_y] = m[POPULATION-1][pos_rand_y-1] = m[POPULATION-2][pos_rand_y-1] = m[pos_rand_x][pos_rand_y];
			}else {
				m[POPULATION-3][pos_rand_y] = social_media_effect();
				m[POPULATION-3][pos_rand_y+1] = social_media_effect();
				m[POPULATION-2][pos_rand_y+2] = social_media_effect();
				m[POPULATION-1][pos_rand_y+2] = social_media_effect();
				m[0][pos_rand_y+1] = social_media_effect();
				m[0][pos_rand_y] = social_media_effect();
				m[POPULATION-1][pos_rand_y-1] = social_media_effect();
				m[POPULATION-2][pos_rand_y-1] = social_media_effect();
			}
		}else if((pos_rand_x > 0)  && (pos_rand_x<(POPULATION-2	)) && (pos_rand_y == (POPULATION-2))){
			test = (m[pos_rand_x][pos_rand_y] == m[pos_rand_x][pos_rand_y+1] == m[pos_rand_x+1][pos_rand_y] == m[pos_rand_x+1][pos_rand_y+1]);
			if (test){
				m[pos_rand_x-1][pos_rand_y] = m[pos_rand_x-1][pos_rand_y+1] = m[pos_rand_x][0] = m[pos_rand_x+1][0] = m[pos_rand_x+2][pos_rand_y+1] = m[pos_rand_x+2][pos_rand_y] = m[pos_rand_x+1][pos_rand_y-1] = m[pos_rand_x][pos_rand_y-1] = m[pos_rand_x][pos_rand_y];
			}else {
				m[pos_rand_x-1][pos_rand_y] = social_media_effect();
				m[pos_rand_x-1][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x][0] = social_media_effect();
				m[pos_rand_x+1][0] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x+2][pos_rand_y] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y-1] = social_media_effect();
				m[pos_rand_x][pos_rand_y-1] = social_media_effect();

			}
		} else if((pos_rand_x == (POPULATION-2)) && (pos_rand_y == (POPULATION-2))){
			test = (m[pos_rand_x][pos_rand_y] == m[pos_rand_x][pos_rand_y+1] == m[pos_rand_x+1][pos_rand_y] == m[pos_rand_x+1][pos_rand_y+1]);
			if (test){
				m[pos_rand_x-1][pos_rand_y] = m[pos_rand_x-1][pos_rand_y+1] = m[pos_rand_x][0] = m[pos_rand_x+1][0] = m[0][pos_rand_y+1] = m[0][pos_rand_y] = m[pos_rand_x+1][pos_rand_y-1] = m[pos_rand_x][pos_rand_y-1] = m[pos_rand_x][pos_rand_y];
			}else {
				m[pos_rand_x-1][pos_rand_y] = social_media_effect();
				m[pos_rand_x-1][pos_rand_y+1] = social_media_effect();
				m[pos_rand_x][0] = social_media_effect();
				m[pos_rand_x+1][0] = social_media_effect();
				m[0][pos_rand_y+1] = social_media_effect();
				m[0	][pos_rand_y] = social_media_effect();
				m[pos_rand_x+1][pos_rand_y-1] = social_media_effect();
				m[pos_rand_x][pos_rand_y-1] = social_media_effect();
				// Ate aqui ok
			}
		}
		
		itr++;
	}while (itr < STEPS);
        return;
}

#endif
