#include "dependencias.h"
#include "constantes.h"
#include "social_media.h"
#include "write_relaxation_time.h"
#include "plot_population.h"

#ifndef ITERATION
#define ITERATION

void iteration(int  **M){
	int i, j, k, l,  itr, **m_before, **m_after, chunk, test, aux_x[POPULATION_X], aux_y[POPULATION_Y], num_threads;
	double h, normalizacao, cu;
	
	// obtendo valor do chunk
	chunk = (POPULATION_X-2) * (POPULATION_Y-2);	
	chunk /= (NUM_THREADS);
	//printf("chunk: %d", chunk);

	m_before = malloc(sizeof(int*) * POPULATION_X);
        for(i=0; i< POPULATION_X; i++)
                m_before[i] = malloc(sizeof(int)* POPULATION_Y);
                

	m_after = malloc(sizeof(int*) * POPULATION_X);
        for(i=0; i< POPULATION_X; i++)
                m_after[i] = malloc(sizeof(int)* POPULATION_Y);

	for(i=0; i<POPULATION_X ; i++)
		for (j=0; j<POPULATION_Y; j++){
			m_after[i][j] = m_before[i][j] = M[i][j];
			
	}

	normalizacao = (POPULATION_X-2) * (POPULATION_Y-2);	
	cu = 0;
	
	for(i=1; i < (POPULATION_X-1) ; i++)
        	for(j=1 ; j < (POPULATION_Y-1); j++)
                	cu += m_after[i][j];

	cu /= normalizacao;

	//printf("N: %d\n", (POPULATION_X-2)*(POPULATION_Y-2));
	//printf("cu: %lf\n", cu);		
	itr = 0;

	for(itr =0; itr < STEPS ; itr++) {

	        for(i=1; i < (POPULATION_X-1) ; i++)
                	for(j=1 ; j < (POPULATION_Y-1); j++)
        	                h += m_after[i][j];
	
	        h  /= normalizacao;
		
		for(i=1; i<(POPULATION_X-2); i++){
			for(j=1; j<(POPULATION_Y-2); j++){	

				// populacao interagindo
				test = 	(m_before[i][j] == m_before[i][j+1] == m_before[i+1][j] == m_before[i+1][j+1]);
				if(test)
					m_after[i-1][j] = m_after[i-1][j+1] = m_after[i][j+2] = m_after[i+1][j+2] = m_after[i+2][j+1] = m_after[i+2][j] = m_after[i+1][j-1] = m_after[i][j-1] = m_after[i][j];
				else {
					m_after[i-1][j] = social_media_effect(m_before[i-1][j]);
					m_after[i-1][j+1] = social_media_effect(m_before[i-1][j+1]);
					m_after[i][j+2] = social_media_effect(m_before[i][j+2]);
					m_after[i+1][j+2] = social_media_effect(m_before[i+1][j+2]);
					m_after[i+2][j+1] = social_media_effect(m_before[i+2][j+1]);
					m_after[i+2][j] = social_media_effect(m_before[i+2][j]);
					m_after[i+1][j-1] = social_media_effect(m_before[i+1][j-1]);
					m_after[i][j-1] = social_media_effect(m_before[i][j-1]);
				}
			}
		//plot_population(m_after);		
		}
		for(k=1; k<POPULATION_X-1; k++){
			aux_x[k] = m_after[1][k];
			m_after[1][k] = m_after[POPULATION_X-2][k];
			m_after[POPULATION_X-2][k] = aux_x[k];
		}

		// direita para esquerda e vice-versa
		for(k=1; k<POPULATION_Y-1; k++){
			aux_y[k] = m_after[k][1];
			m_after[k][1] = m_after[k][POPULATION_Y-2];
			m_after[k][POPULATION_Y-2] = aux_y[k];
		}
		
		for(k=0; k<POPULATION_X ; k++)
                for (l=0; l<POPULATION_Y; l++)
                        m_before[k][l] = m_after[k][l];

		//if( (itr % 5) == 0 )
		//	write_population_state(m_before, itr);

		if ( abs(h) >= 1.0){
			//printf("STEPS: %d\n", itr);
			write_relaxation_time(itr, cu);
			itr = STEPS;
		}
	}
	
	free(m_before);
	free(m_after);
        return;
}

#endif
