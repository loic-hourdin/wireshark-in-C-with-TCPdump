#include "tcp.h"

void print_tcp(){
	int i, j;
	switch (verb)
		{
		case 1:
            printf("|%6u",ntohs(tcp->source));
			printf("|%6u",ntohs(tcp->dest));
            break;
        case 2:
        	couleur("34");
            couleur("1");
            printf("TCP:: ");
            couleur("0");
            printf("source:%u\t",ntohs(tcp->source));
			printf("dest:%u\t",ntohs(tcp->dest));
			printf("Sequence N° :%u\t",ntohl(tcp->seq));
			printf("Aquitement :%u\t",ntohl(tcp->ack_seq));
			printf("Flags:");
			if(tcp->urg)printf("URG ");
			if(tcp->ack)printf("ACK ");
			if(tcp->psh)printf("PSH ");
			if(tcp->rst)printf("RST ");
			if(tcp->syn){
				couleur("31");
        		couleur("1");
				printf("SYN ");
				couleur("0");
			}
			if(tcp->fin){
				couleur("31");
        		couleur("1");
        		printf("FIN ");
        		couleur("0");
			}
			printf("\n");
            break;
        case 3:
             printf("--------------");
            couleur("34");
            couleur("1");
            printf("TCP");
            couleur("0");
            printf("--------------\n");
			printf("port source:%u\n",ntohs(tcp->source));
			printf("port destination:%u\n",ntohs(tcp->dest));
			printf("Sequence Number :%u\n",ntohl(tcp->seq));
			printf("Aquitement :%u\n",ntohl(tcp->ack_seq));
			printf("Data Offset :%u\n",tcp->doff);
			
			printf("Flags:");
			if(tcp->urg)printf("URG ");
			if(tcp->ack)printf("ACK ");
			if(tcp->psh)printf("PSH ");
			if(tcp->rst)printf("RST ");
			if(tcp->syn){
				couleur("31");
        		couleur("1");
				printf("SYN ");
				couleur("0");
			}
			if(tcp->fin){
				couleur("31");
        		couleur("1");
        		printf("FIN ");
        		couleur("0");
			}
			printf("\n");
			
			printf("fenêtre :%u\n",ntohs(tcp->window));
			printf("Checksum :%u\n",ntohs(tcp->check));
			printf("Pointeur urgent :%u\n",ntohs(tcp->urg_ptr));
			
			if(tcp->doff>5){
				printf("option:\n");
				i=5*4;
				u_char a,b;
				while(i<tcp->doff*4){
					if(*((u_char*)tcp+i)==1){
						printf(" ¤ No-Operation\n");
						i++;
					}
					else if (*((u_char*)tcp+i)==0){
						printf("lol\n");
						break;
					}
					else if (*((u_char*)tcp+i)!=0){
						printf(" ¤ ");
						a=*((u_char*)tcp+i);
						i++;
						b=*((u_char*)tcp+i);
						if(a==2)printf("Maximum Segment Size : ");
						else if(a==3)printf("Window Scale : ");
						else if(a==4)printf("SACK Permitted");
						else if(a==5)printf("SACK:");
						else if(a==8)printf("Timestamps:");
						else printf("n°%u:",a);
						i=i+b-2;
						if(b>2){
							if(a==3)printf("%u",*((u_char*)tcp+i));
							if(a==4||a==5)printf("%u",ntohs(*((unsigned int*)tcp+i)));
							if(a<5)	printf("(");
							for(j=b-2-1;j>=0;j--){
								printf("%.2x ",*((u_char*)tcp+i-j));
							}
							if(a<5)	printf(")");								
						}
						i++;


					printf("\n");
					}

				}
			}	
		
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
}

void print_tcp_apli(){
	
	switch (verb)
		{
		case 1:
			printf("| ");
			couleur("34");
        	printf("TCP: ");
        	couleur("0");
            if(tcp->urg)printf("URG ");
			if(tcp->ack)printf("ACK ");
			if(tcp->psh)printf("PSH ");
			if(tcp->rst)printf("RST ");
			if(tcp->syn){
				couleur("31");
        		couleur("1");
				printf("SYN ");
				couleur("0");
			}
			if(tcp->fin){
				couleur("31");
        		couleur("1");
        		printf("FIN ");
        		couleur("0");
			}
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