#include "ip.h"

void print_ip(){
	
	switch (verb)
    {   
        case 1:
            printf("|%15s",inet_ntoa(ip->ip_src));
			printf("|%15s",inet_ntoa(ip->ip_dst));
            break;
        case 2:
        	couleur("35");
        	couleur("1");
        	printf("IP::");
        	couleur("0");
            printf(" source:%s\t",inet_ntoa(ip->ip_src));
			printf("destination:%s\t",inet_ntoa(ip->ip_dst));
			printf("Id:%u\t",*(u_int16_t*)inv((char*)&ip->ip_id,2));
			printf("fragment n°:%u",ip->ip_off);
			if(ip->ip_off & (1 << 1))printf("(end)");
			printf("\n");
            break;
        case 3:
       		 printf("--------------");
        	couleur("35");
        	couleur("1");
            printf("IP");
            couleur("0");
            printf("--------------\n");
            printf("version:%d\n",ip->ip_v);
			printf("IHL:%d\n",ip->ip_hl);
			printf("type de service:%u\n",ip->ip_tos);
			printf("Taille :%u\n",ntohs(ip->ip_len));
			printf("Identication :%u\n",ntohs(ip->ip_id));
			printf("Don't fragment :%u\n",ip->ip_off & (1));
			printf("More fragment :%u\n",ip->ip_off & (1 << 1));
			printf("fragment n°:%u\n",ntohs(ip->ip_off & ~(111)));
			printf("time to live:%u\n",ip->ip_ttl);
			if(ip->ip_p==6){
				printf("protocole TCP\n");
			}
			else if(ip->ip_p==1){
				printf("protocole ICMP\n");
			}
			else if(ip->ip_p==2){
				printf("protocole IGMP (Internet Group Management Protocol)\n");
			}
			else if(ip->ip_p==3){
				printf("protocole GGP (Gateway-to-Gateway Protocol)\n");
			}
			else if(ip->ip_p==4){
				printf("protocole IP-in-IP\n");
			}
			else if(ip->ip_p==5){
				printf("protocole ST (Internet Stream Protocol)\n");
			}
			else if(ip->ip_p==17){
				printf("protocole UDP\n");
			}
			else {
				printf("protocole inconue: %.2x\n",ip->ip_p);
			}
			printf("header Checksum :%u\n",ntohs(ip->ip_sum));
			printf("IP source:%s\n",inet_ntoa(ip->ip_src));
			printf("IP destination:%s\n",inet_ntoa(ip->ip_dst));
			/*if(verb>3 && ip->ip_hl>5){
				printf("option:\n");
				for(i=5;i>=ip->ip_hl;i++){
					printf("--n°%i",i-5);
					printf("\tcopie:%i",*((int*)ip+(8*i)) & (1));
					printf("\tclasse:")
					

			}*/
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
    }
}

void print_ip_apli(){
	
	switch (verb)
    {   
        case 1:
        	printf("|------|------| ");
        	couleur("34");
            if(ip->ip_p==6){
				printf("TCP ");
			}
			else if(ip->ip_p==1){
				printf("ICMP ");
			}
			else if(ip->ip_p==2){
				printf("IGMP (Internet Group Management Protocol) ");
			}
			else if(ip->ip_p==3){
				printf("GGP (Gateway-to-Gateway Protocol) ");
			}
			else if(ip->ip_p==4){
				printf("IP-in-IP ");
			}
			else if(ip->ip_p==5){
				printf("ST (Internet Stream Protocol) ");
			}
			else if(ip->ip_p==17){
				printf("UDP ");
			}
			else {
				printf("protocole inconue: %.2x ",ip->ip_p);
			}
			couleur("0");
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default:
            printf("::error::verbo superieur a 3 \n");
            break;
    }
}

