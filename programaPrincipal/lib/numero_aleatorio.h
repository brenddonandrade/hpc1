// Incluindo as dependencias
#include "dependencias.h"

#ifndef NUMERO_ALEATORIO
#define NUMERO_ALEATORIO

int rand_number(int max){
	int value;
	
	
	value = rand() % (max);
	return value;	
}
#endif
