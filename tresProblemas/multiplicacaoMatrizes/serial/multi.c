#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constantes
#define NL 500

#define CHUNK 10000


void multMatrizes(double m1[][NL], double m2[][NL], double result[][NL], int l1, int c1, int l2, int c2){
    int i, j, k;

    for(i=0;  i<l1 ; i++){
        for(j=0; j<c2 ; j++){
            result[i][j] = 0;
            for(k=0; k<c1 ; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void preencherMatrizNL(double M[][NL], int nl, int nc, int valorMaximo) {
	srand(time(NULL));

	for (int i = 0; i < nl; i++) {
		for (int j = 0; j < nc; j++) {
		       	M[i][j] = rand() % (valorMaximo + 1);
        	}
    	}
}

int main(){
	double m1[NL][NL];
	double m2[NL][NL];
    	double m3[NL][NL];
	
	printf("pt1");
    	preencherMatrizNL(m1, NL, NL, 10);
    	preencherMatrizNL(m2, NL, NL, 10);
	printf("pt2");
	multMatrizes(m1, m2, m3, NL, NL, NL, NL);

	
	return 0;
}
