#include "bootp.h"

void print_bootp(){
	int i;
	int tmp_type_dhcp = 0;
	switch (verb)
		{
			
            if(bootp->bp_vend[0]==99 && bootp->bp_vend[1]==130 && bootp->bp_vend[2]==83  && bootp->bp_vend[3]==99){
			int tmp=4;
			u_int8_t opt_lenght;
			u_int8_t opt_id;
            while(tmp<64){
				opt_id=bootp->bp_vend[tmp];
				tmp++;
				if(opt_id!=0){
					opt_lenght=bootp->bp_vend[tmp];
					
					tmp=tmp+opt_lenght;
					switch (opt_id)
						{
				        case 53:
				        	tmp_type_dhcp=bootp->bp_vend[tmp];
				            break;
				        
				        
				        }
				    tmp++;
					}
				}
			}
			printf("| ");
        	couleur("33");
            
			if(tmp_type_dhcp==1)printf("| DHCP Discover\t");
            if(tmp_type_dhcp==2)printf("| DHCP Offer\t");
            if(tmp_type_dhcp==3)printf("| DHCP Request\t");
            if(tmp_type_dhcp==4)printf("| DHCP Decline\t");
            if(tmp_type_dhcp==5)printf("| DHCP Ack\t");
            if(tmp_type_dhcp==6)printf("| DHCP Nack\t");
            if(tmp_type_dhcp==7)printf("| DHCP Release\t");
            if(tmp_type_dhcp==0){
           	if(bootp->bp_op==1)printf("| Boot request\t");
            else if(bootp->bp_op==2)printf("| Boot reply\t");
           }
            couleur("0");

            break;
        case 2:
            couleur("33");
        	couleur("1");
            printf("BOOTP:: ");
            couleur("0");
            if(bootp->bp_op==1)printf("Boot request\t");
            else if(bootp->bp_op==2)printf("Boot reply\t");
            printf("Client IP: %s\t",inet_ntoa(bootp->bp_ciaddr));
            printf("Server IP: %s\t",inet_ntoa(bootp->bp_siaddr));
            if(bootp->bp_vend[0]==99 && bootp->bp_vend[1]==130 && bootp->bp_vend[2]==83  && bootp->bp_vend[3]==99){
			int tmp=4;
			u_int8_t opt_lenght;
			u_int8_t opt_id;
            while(tmp<64){
				opt_id=bootp->bp_vend[tmp];
				tmp++;
				if(opt_id!=0){
					opt_lenght=bootp->bp_vend[tmp];
					
					tmp=tmp+opt_lenght;
					printf("\t");
					//printf("opt_id:%u opt_lenght:%u",opt_id,opt_lenght);
					switch (opt_id)
						{
				        case 50:
				           printf("request IP: %s\t",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp])));
				            break;
				        case 53:
				           if(bootp->bp_vend[tmp]==1)printf("DHCP Discover\t");
				           if(bootp->bp_vend[tmp]==2)printf("DHCP Offer\t");
				           if(bootp->bp_vend[tmp]==3)printf("DHCP Request\t");
				           if(bootp->bp_vend[tmp]==4)printf("DHCP Decline\t");
				           if(bootp->bp_vend[tmp]==5)printf("DHCP Ack\t");
				           if(bootp->bp_vend[tmp]==6)printf("DHCP Nack\t");
				           if(bootp->bp_vend[tmp]==7)printf("DHCP Release\t");
				            break;
				        
				        
				        }
				    tmp++;
					}
				}
			}
			printf("\n");
            break;
        case 3:
            printf("--------------");
        	couleur("33");
        	couleur("1");
            printf("BOOTP");
            couleur("0");
            printf("--------------\n");
            if(bootp->bp_op==1)printf("Messagetype: Boot request(1)\n");
            else if(bootp->bp_op==2)printf("Messagetype: Boot reply(2)\n");
            else printf("Messagetype: %u\n",bootp->bp_op);
            if(bootp->bp_htype==1)printf("\tHardware type: ethernet(1)\n");
            else printf("Hardware type: %u\n",bootp->bp_htype);
            printf("Hardware address length: %u\n",bootp->bp_hlen);
            printf("Hop:%u\n",bootp->bp_hops);
            printf("Transaction ID 0x%08X\n",ntohl(bootp->bp_xid));
			printf("Second elapsed: %u\n", ntohs(bootp->bp_secs));
			printf("Flags: 0x%02x", ntohs(bootp->bp_flags));
			if(bootp->bp_flags & 1<<15)printf("(Broadcast)\n");
			else printf("(unicast)\n");
			printf("Client IP address: %s\n",inet_ntoa(bootp->bp_ciaddr));
			printf("Your IP address: %s\n",inet_ntoa(bootp->bp_yiaddr));
			printf("Server IP address: %s\n",inet_ntoa(bootp->bp_siaddr));
			printf("Gateway IP address: %s\n",inet_ntoa(bootp->bp_giaddr));
			printf("Client MAC address: %s\n",ether_ntoa((struct ether_addr*)bootp->bp_chaddr) );
			printf("Server name: ");
			for(i=0;i<64;i++){
				if (bootp->bp_sname[i]>20) printf("%c",bootp->bp_sname[i]);
	   			else if (bootp->bp_sname[i]==0)break;
	  			else printf("." );
			}
			printf("\n");
			printf("Boot file name: ");
			for(i=0;i<128;i++){
				if (bootp->bp_file[i]>20) printf("%c",bootp->bp_file[i]);
	   			else if (bootp->bp_file[i]==0)break;
	  			else printf(".");
			}
			printf("\n");
			printf("Option:\n");
			if(bootp->bp_vend[0]==99 && bootp->bp_vend[1]==130 && bootp->bp_vend[2]==83  && bootp->bp_vend[3]==99){
			int tmp=4;
			u_int8_t opt_lenght;
			u_int8_t opt_id;
			while(tmp<64){
				opt_id=bootp->bp_vend[tmp];
				tmp++;
				if(opt_id!=0){
					opt_lenght=bootp->bp_vend[tmp];
					
					tmp=tmp+opt_lenght;
					printf("\t");
					//printf("opt_id:%u opt_lenght:%u",opt_id,opt_lenght);
					switch (opt_id)
						{
						case 1:
				            printf("Subnet mask:%s\n",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp])));
				            break;
				        case 2:
				            printf("Time offset:%u\n",ntohl(bootp->bp_vend[tmp]));
				            break;
				        case 3:
				            printf("Routeur: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp+i])));
				            }
				            printf("\n");
				            break;
				        case 4:
				            printf("Time server: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp+i])));
				            }
				            printf("\n");
				            break;
				        case 5:
				            printf("Name server: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp-i])));
				            }
				            printf("\n");
				        case 6:
				            printf("Domaine name server: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp+i])));
				            }
				            printf("\n");
				            break;
				        case 7:
				            printf("Domaine name server: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp+i])));
				            }
				            printf("\n");
				            break;
				        case 8:
				            printf("Log server: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp+i])));
				            }
				            printf("\n");
				            break;
				        case 12:
				            printf("Host name: ");
				            for(i=0;i>opt_lenght;i++){
				            	printf("%c;",bootp->bp_vend[tmp+i]);
				            }
				            printf("\n");
				            break;
				        case 15:
				            printf("Domaine name: ");
				            for(i=0;i>opt_lenght;i++){
				            	printf("%c;",bootp->bp_vend[tmp+i]);
				            }
				            printf("\n");
				            break;
				        case 28:
				            printf("Broadcast address: %s\n",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp])));
				            break;
				        case 44:
				           printf("netbios over TCP/IP name server: ");
				            for(i=0;i<opt_lenght;i=i+4){
				            	printf("%s;",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp+i])));
				            }
				            printf("\n");
				            break;
				        case 47:
				           printf("netbios over TCP/IP scope: ");
				            for(i=0;i<opt_lenght;i++){
				            	printf("%02x;",(bootp->bp_vend[tmp+i]));
				            }
				            printf("\n");
				            break;
				        case 50:
				           printf("request IP address: %s\n",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp])));
				            break;
				        case 51:
				           printf("lease time: %i\n",(u_int32_t) bootp->bp_vend[tmp]);
				            break;
				        case 53:
				           if(bootp->bp_vend[tmp]==1)printf("DHCP message type: Discover\n");
				           if(bootp->bp_vend[tmp]==2)printf("DHCP message type: Offer\n");
				           if(bootp->bp_vend[tmp]==3)printf("DHCP message type: Request\n");
				           if(bootp->bp_vend[tmp]==4)printf("DHCP message type: Decline\n");
				           if(bootp->bp_vend[tmp]==5)printf("DHCP message type: Ack\n");
				           if(bootp->bp_vend[tmp]==6)printf("DHCP message type: Nack\n");
				           if(bootp->bp_vend[tmp]==7)printf("DHCP message type: Release\n");
				            break;
				        case 54:
				           printf("server identifier: %s\n",inet_ntoa(*(struct in_addr*)&(bootp->bp_vend[tmp])));
				            break;
				        case 55:
				           printf("parameter request liste: ");
				            for(i=0;i<opt_lenght;i++){
				            	printf("%02x",(bootp->bp_vend[tmp+i]));
				            }
				            printf("\n");
				            break;
				        case 61:
				           printf("parameter request liste: ");
				            for(i=0;i<opt_lenght;i++){
				            	printf("%02x ",(bootp->bp_vend[tmp+i]));
				            }
				            printf("\n");
				            break;
				        default:
				           	printf("code %i : ",opt_id);
				            for(i=0;i<opt_lenght;i++){
				            	printf("%02x ",(bootp->bp_vend[tmp+i]));
				            }
				            printf("\n");
				            break;
				        
				        }
				    tmp++;
				}
			}
			}

		
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
}