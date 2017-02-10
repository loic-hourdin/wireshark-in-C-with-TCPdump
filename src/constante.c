#include "constante.h"

void* inv (char *v, int taille){
	int i;
	char tmp;
	for(i=0;i<taille/2;i++){
		tmp=v[i];
		v[i]=v[(taille-i-1)];
		v[(taille-i-1)]=tmp;
	}
	return(v);
}