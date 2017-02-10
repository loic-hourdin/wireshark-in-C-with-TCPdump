#include "ethernet.h"

void print_ethernet(){
	switch (verb)
    {   
        case 1:
            
            break;
        case 2:
        	couleur("33");
        	printf("ethernet:: ");
        	couleur("0");
            printf("mac dest: %.2x %.2x %.2x %.2x %.2x %.2x\t\t",ethernet->ether_dhost[0],ethernet->ether_dhost[1],ethernet->ether_dhost[2],ethernet->ether_dhost[3],ethernet->ether_dhost[4],ethernet->ether_dhost[5]);
			printf("mac source: %.2x %.2x %.2x %.2x %.2x %.2x\n",ethernet->ether_shost[0],ethernet->ether_shost[1],ethernet->ether_shost[2],ethernet->ether_shost[3],ethernet->ether_shost[4],ethernet->ether_shost[5]);
            break;
        case 3:
	        printf("--------------");
	        couleur("33");
	        printf("ETHERNET");
	        couleur("0");
	        printf("--------------------\n");
            printf("mac adresse destination: %.2x %.2x %.2x %.2x %.2x %.2x\n",ethernet->ether_dhost[0],ethernet->ether_dhost[1],ethernet->ether_dhost[2],ethernet->ether_dhost[3],ethernet->ether_dhost[4],ethernet->ether_dhost[5]);
			printf("mac adresse source: %.2x %.2x %.2x %.2x %.2x %.2x\n",ethernet->ether_shost[0],ethernet->ether_shost[1],ethernet->ether_shost[2],ethernet->ether_shost[3],ethernet->ether_shost[4],ethernet->ether_shost[5]);
			if(ntohs(ethernet->ether_type)==0x0200){
				printf("type de protocole réseaux: Xerox PUP\n");
			}
			else if(ntohs(ethernet->ether_type)==0x8035){
				printf("type de protocole réseaux: Reverse ARP\n");
			}
			else if(ntohs(ethernet->ether_type)==0x0800){
				printf("type de protocole réseaux: IP\n");
			}
			else if(ntohs(ethernet->ether_type)==0x0806){
				printf("type de protocole réseaux: ARP\n");
			}
			else if(ntohs(ethernet->ether_type)==0x86DD){
				printf("type de protocole réseaux: IPV6\n");
			}
			else if(ntohs(ethernet->ether_type)==0x809b){
				printf("type de protocole réseaux: AppleTalk\n");
			}
			else if(ntohs(ethernet->ether_type)==0x8100){
				printf("type de protocole réseaux: VLAN\n");
			}
			else {
				printf("type de protocole réseaux non connue: %x\n",ethernet->ether_type);
			}
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
    }
}