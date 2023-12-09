#include "dependencias.h"
#include "numero_aleatorio.h"

#ifndef SOCIAL_MEDIA
#define SOCIAL_MEDIA

//
int social_media_effect(int i){
	int follow;
	
	follow = rand_number(100);

	if(follow < INFLUENCER)
		return OPINION_INFLUENCER;
	else
		return i;

}

#endif



