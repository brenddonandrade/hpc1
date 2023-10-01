#include "dependencias.h"
#include "numero_aleatorio.h"

#ifndef SOCIAL_MEDIA
#define SOCIAL_MEDIA

//
int social_media_effect(){
	int follow;
	
	follow = rand_number(99);

	if(follow < INFLUENCER)
		return 1;
	else
		return -1;
}

#endif



