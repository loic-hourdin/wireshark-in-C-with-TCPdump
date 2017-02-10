#include "arp.h"

void print_arp(){
	switch (verb)
    {   
        case 1:
       		printf("|---------------|---------------|------|------| ");
    		couleur("35");
           	couleur("1");
           	printf("ARP: ");
           	couleur("0");
            if(ntohs(arp->ar_op)==1){
            	printf("who is ");
            	if(arp->ar_pln==4)printf("%s",inet_ntoa(*(struct in_addr*)((void*)arp+20+arp->ar_pln)) );
				//else if(arp->ar_pln==16)printf("0x%016X",*(arp+16+arp->ar_pln));
       		}
			else if(ntohs(arp->ar_op)==2){
				printf("réponse ");
				if(arp->ar_pln==4)printf("%s",inet_ntoa(*(struct in_addr*)((void*)arp+14)) );
				//else if(arp->ar_pln==16)printf("0x%016X",*(arp+12+arp->ar_pln));
				printf(" is %s",ether_ntoa((struct ether_addr*)((void*)arp+8)));
			}
            break;
        case 2:
    		couleur("35");
           	couleur("1");
           	printf("ARP:: ");
           	couleur("0");
            if(ntohs(arp->ar_op)==1){
            	printf("who is ");
            	if(arp->ar_pln==4)printf("%s",inet_ntoa(*(struct in_addr*)((void*)arp+20+arp->ar_pln)) );
            	else printf("IPv6\n");
				//else if(arp->ar_pln==16)printf("0x%016X",*(arp+16+arp->ar_pln));
       		}
			else if(ntohs(arp->ar_op)==2){
				printf("réponse ");
				if(arp->ar_pln==4){
					printf("%s",inet_ntoa(*(struct in_addr*)((void*)arp+14)) );
					//else if(arp->ar_pln==16)printf("0x%016X",*(arp+12+arp->ar_pln));
					printf(" is %s\n",ether_ntoa((struct ether_addr*)((void*)arp+8)));
				}
				else printf("IPv6\n");
			}

            break;
        case 3:
        	printf("--------------");
        	couleur("1");
        	couleur("35");
            printf("ARP");
            couleur("0");
            printf("--------------\n");
            if(ntohs(arp->ar_hrd)==1)printf("Hardware type: ethernet(1)\n");
			else printf("Hardware type: Inconue(%u)\n",ntohs(arp->ar_hrd));
			if(ntohs(arp->ar_pro)==0x0800)printf("Protocol type: ethernet(0x0800)\n");
			else printf("Protocol type: Inconue(0x%04X)\n",ntohs(arp->ar_pro));
			if(arp->ar_hln==1)printf("Hardware Address Length: 1 (Token ring)\n");
			else if(arp->ar_hln==6) printf("Hardware Address Length: 6 (Ethernet)\n");
			else printf("Hardware Address Length: %u \n",arp->ar_hln);
			if(arp->ar_pln==4)printf("Protocol Address Length: 4 (IP v4)\n");
			else if(arp->ar_pln==16) printf("Protocol Address Length: 6 (IP v6)\n");
			else printf("ar_op Address Length: %u \n",arp->ar_pln);
			if(ntohs(arp->ar_op)==1)printf("Operation: Request requête(1)\n");
			else if(ntohs(arp->ar_op)==2)printf("Operation: Reply réponse(2)\n");
			else printf("Operation: Inconue(%u)\n",ntohs(arp->ar_op));
			printf("Mac source:%s\n",ether_ntoa((struct ether_addr*)((void*)arp+8)));
			if(arp->ar_pln==4)printf("IP source: %s\n",inet_ntoa(*(struct in_addr*)((void*)arp+14)) );
			//else if(arp->ar_pln==16)printf("IP source:0x%016X\n",*((void*)arp+14));
			printf("Mac destination:%s\n",ether_ntoa((struct ether_addr*)((void*)arp+14+arp->ar_pln)) );
			if(arp->ar_pln==4)printf("IP destination: %s\n",inet_ntoa(*(struct in_addr*)((void*)arp+20+arp->ar_pln)) );
			//else if(arp->ar_pln==16)printf("IP destination: 0x%016X\n",*((void*)arp+18+arp->ar_pln));	
			
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
    }
}