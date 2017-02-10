#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <netinet/in.h>
#include <netinet/ether.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pcap.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#define couleur(param) printf("\033[%sm",param)
//permet de géré la couleur d'affichage d'un texte


char verb;
int numero;

void* inv (char *v, int taille);

#endif