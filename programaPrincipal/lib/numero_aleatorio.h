// Incluindo as dependencias
#include "dependencias.h"

#ifndef NUMERO_ALEATORIO
#define NUMERO_ALEATORIO

int rand_number(int max){
	int value;
	
	value = rand() % (max+1);
	return value;	
}
#endif
