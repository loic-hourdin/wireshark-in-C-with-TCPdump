#include "udp.h"

void print_udp(){
	switch (verb)
        {   
        case 1:
            printf("|%6u",ntohs(udp->source));
            printf("|%6u",ntohs(udp->dest));
            break;
        case 2:
            couleur("34");
            couleur("1");
            printf("UDP:: ");
            couleur("0");
            printf("port source :%u\t",ntohs(udp->source));
            printf("port destination :%u\n",ntohs(udp->dest));
            break;
        case 3:
        printf("--------------");
            couleur("34");
            couleur("1");
            printf("UDP");
            couleur("0");
            printf("--------------\n");
        printf("port source :%u\n",ntohs(udp->source));
        printf("port destination :%u\n",ntohs(udp->dest));
        printf("taille :%u\n",ntohs(udp->len));
        printf("checksum :%u\n",ntohs(udp->check));
        
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}

void print_udp_apli(){
    switch (verb)
        {   
        case 1:
            printf("| ");
            couleur("34");
            printf("UDP ");
            couleur("0");
            break;
        case 2:
          
            break;
        case 3:    
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}

