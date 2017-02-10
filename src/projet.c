#include "projet.h"
//http://www.tcpdump.org/pcap.html



void got_packet(u_char *args, const struct pcap_pkthdr *hdr, const u_char *truepacket)
{

parser(truepacket);
aff(hdr);

}



void parser(const u_char* truepacket){

ethernet=(struct ether_header*)truepacket;
switch (ntohs(ethernet->ether_type))
    {   
    case 0x0800:
    	//IP
        ip=(struct ip*)(truepacket+14);
        switch (ip->ip_p)
        {   
            case 6:
            	//TCP
                tcp=(struct tcphdr*)(truepacket+14+(4*ip->ip_hl));
                switch ((unsigned short int)ntohs(tcp->dest))
			        {   
			            
			            case 80:
			            	//bootp server
			                http=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_http=ntohs(ip->ip_len)-tcp->doff*4-20;
			               
			                break;
			            case 20:
			            	//bootp server
			                ftp=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_ftp=ntohs(ip->ip_len)-tcp->doff*4-20;
			                
			                break;
			            case 21:
			            	//bootp server
			                ftp=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_ftp=ntohs(ip->ip_len)-tcp->doff*4-20;
			                
			                break;
			            case 23:
			            	//bootp server
			                telnet=(unsigned char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_telnet=ntohs(ip->ip_len)-tcp->doff*4-20;
			                
			                break;
			            case 25:
			            	//bootp server
			                smtp=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_smtp=ntohs(ip->ip_len)-tcp->doff*4-20;
			               
			                break;
			            case 110:
			            	//bootp server
			                pop=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_pop=ntohs(ip->ip_len)-tcp->doff*4-20;
			               
			                break;
			            case 143:
			            	//bootp server
			                imap=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_imap=ntohs(ip->ip_len)-tcp->doff*4-20;
			                break;
			            default:
			                
			            	break;
			        }
                switch ((unsigned short int)ntohs(tcp->source))
			        {   
			            
			            case 80:
			            	//bootp server
			                http=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_http=ntohs(ip->ip_len)-tcp->doff*4-20;
			               
			                break;
			            case 20:
			            	//bootp server
			                ftp=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_ftp=ntohs(ip->ip_len)-tcp->doff*4-20;
			                
			                break;
			            case 21:
			            	//bootp server
			                ftp=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_ftp=ntohs(ip->ip_len)-tcp->doff*4-20;
			                
			                break;
			            case 23:
			            	//bootp server
			                telnet=(unsigned char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_telnet=ntohs(ip->ip_len)-tcp->doff*4-20;
			            case 25:
			            	//bootp server
			                smtp=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_smtp=ntohs(ip->ip_len)-tcp->doff*4-20;
			           	case 110:
			            	//bootp server
			                pop=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_pop=ntohs(ip->ip_len)-tcp->doff*4-20;
			                break;
			            case 143:
			            	//bootp server
			                imap=(char*)(truepacket+(4*ip->ip_hl)+14+tcp->doff*4);
			                size_imap=ntohs(ip->ip_len)-tcp->doff*4-20;
			                break;    

			            default:
			                
			                break;
			        }
                break;
            case 17:
            	//UDP
            	udp=(struct udphdr*)(truepacket+(4*ip->ip_hl)+14);
                switch ((unsigned short int)ntohs(udp->dest))
			        {   
			            case 67:
			            	//bootp server
			                bootp=(struct bootp*)(truepacket+(4*ip->ip_hl)+14+8);
			                
			                break;
			            default:
			                
			                break;
			        }
                break;
            default:
                
                break;
        }
        break;
    case 0x0806:
    	//arp
        arp=(struct arphdr*)(truepacket+14);
        
        break;  
    default:
        
        break;
    }


}

void aff(const struct pcap_pkthdr *hdr){
	numero++;
	if(verb==3){
		printf("-----------------------------------------------------------\n");
		couleur("31");
        couleur("1");
		printf("\t\t Packet n°%i\n",numero);
		couleur("0");
		printf("-----------------------------------------------------------\n");
		print_paquet((u_char*) ethernet,hdr);
	}
	if(verb==2){
		couleur("31");
		printf("Packet n°%i\n",numero);
		couleur("0");
	}
	if(verb==1){
		printf("%4i",numero);
	}
	char not_print=0;

	print_ethernet();
	switch (ntohs(ethernet->ether_type))
	    {   
	    case 0x0800:
	    	//IP
	        print_ip();
	        switch (ip->ip_p)
	        {   
	            case 6:
	            	//TCP
	                print_tcp();
	                switch ((unsigned short int)ntohs(tcp->dest))
			        {   
			          
			            case 80:
			            	//smtp

			                if(size_http>0)print_http();
			                else print_tcp_apli();
			                not_print=1;
			                break;
			            case 20:
			            	//smtp
			                if(size_ftp>0)print_ftp_data();
			                else print_tcp_apli();
			                not_print=1;
			                break;
			            case 21:
			            	//smtp
			                if(size_ftp>0) print_ftp();
			                else print_tcp_apli();
			                not_print=1;
			                break;
			            case 23:
			            	if(size_telnet>0) print_telnet();
			            	else print_tcp_apli();
			            	not_print=1;
			            	break;
			            case 25:
			            	//smtp

			                if(size_smtp>0) print_smtp();
			                else print_tcp_apli();
			                not_print=1;
			                break;
			            case 53:
			            	//smtp
			            	if(verb==1){
			            		printf("| ");
					            couleur("33");
					            printf("DNS ");
					            couleur("0");
					            not_print=1;
			            	}
			            	break;
			            case 110:
			            	//smtp
			                if(size_pop>0) print_pop();
			                else print_tcp_apli();
			                not_print=1;
			                break;
			            case 143:
			            	//smtp
			                if(size_imap>0) print_imap();
			                else print_tcp_apli();
			                not_print=1;
			                break;
			            default:
			                
			            	break;
			        }
			    if(not_print==0){

                switch ((unsigned short int)ntohs(tcp->source))
			        {   
			            
			            case 80:
			            	//smtp

			                if(size_http>0)print_http();
			                else print_tcp_apli();

			                break;
			            case 20:
			            	//smtp
			                if(size_ftp>0)print_ftp_data();
			                else print_tcp_apli();
			                break;
			            case 21:
			            	//smtp
			                if(size_ftp>0)print_ftp();
			                else print_tcp_apli();
			                break;
			            case 23:
			            	if(size_telnet>0)print_telnet();
			            	else print_tcp_apli();
			            	break;
			            case 25:
			            	//smtp
			                if(size_smtp>0)print_smtp();
			                else print_tcp_apli();
			                break;

			                
            			case 53:
			            	//smtp
			            	if(verb==1){
			            		printf("| ");
					            couleur("33");
					            printf("DNS ");
					            couleur("0");
					            not_print=1;
			            	}
			            	break;

			            case 110:
			            	//smtp
			                if(size_pop>0)print_pop();
			                else print_tcp_apli();
			                break;
			            case 143:
			            	//smtp
			                if(size_imap>0)print_imap();
			                else print_tcp_apli();
			                break;
			            default:
			            	print_tcp_apli();
			                
			                break;
			        }
                break;
	                break;
	            case 17:
	            	//UDP
	            	print_udp();
	                switch (ntohs(udp->dest))
			        {   
			            case 67:
			            	//bootp server
			                print_bootp();
			                not_print=1;
			                break;
			            case 53:
			            	if(verb==1){
			            		printf("| ");
					            couleur("33");
					            printf("DNS ");
					            couleur("0");
					            not_print=1;
			            	}
			            	break;
			                
			            default:
			                
			                break;
			        }
			        if(!not_print){
			        	switch (ntohs(udp->source))
				        {   
				            case 67:
				            	//bootp server
				                print_bootp();
				                
				                break;
				            case 53:
				            	if(verb==1){
				            		printf("| ");
						            couleur("33");
						            printf("DNS ");
						            couleur("0");
						            not_print=1;
				            	}
				            	break;
				            default:
				            	print_udp_apli();
				                
				                break;
			        	}
			        }
			    }
	                break;
	            default:
	            	print_ip_apli();	                
	                break;
	        }

			
	        
	        break;
	    case 0x0806:
    		//arp
        	print_arp();
        	break;
       	case 0x86dd:
       		if(verb==1){
       			printf("|---------------|---------------|------|------| ");
    		couleur("35");
           	couleur("1");
           	printf("IPV6");
           	couleur("0");
           	}       		
        	break;
       	case 0x8035:
       		if(verb==1){
       			printf("|---------------|---------------|------|------| ");
    		couleur("35");
           	couleur("1");
           	printf("RARP");
           	couleur("0");
           	}       		
        	break;
        case 0x8100:
       		if(verb==1){
       			printf("|---------------|---------------|------|------| ");
    		couleur("35");
           	couleur("1");
           	printf("IPV6");
           	couleur("0");
           	}       		
        	break;
	    default:
	        if(verb==1){
       			printf("|---------------|---------------|------|------| ");
    		
           	printf("protocole réseau inconue");
           	couleur("0");
           	} 
	        break;
	    }
	    printf("\n");


}








int main (int argc, char *argv[]){
	if (!(argc==1||argc==3||argc==5||argc==7||argc==9)){
		fprintf(stderr,"::erreur:: nbr d'arguments %d\ncommande de type: annalyseur -i <interface> -o <fichier> -f <filtre> -v <1..3>\n",argc);
		return 2;
	}
	
	struct bpf_program fp;		/* The compiled filter expression */
	pcap_t *capture;
	char* interface=NULL;
	char* fichier=NULL;
	char* filtre=NULL;
	char* verbo=NULL;
	char* errbuf=NULL;
	char *  dev;
	verb=1;
	numero=0;
	
	int i;
	for(i=1;i<argc;i=i+2){
		
		if(strcmp(argv[i],"-i")==0){
			interface=argv[i+1];
		}
		else if(strcmp(argv[i],"-o")==0){
			fichier=argv[i+1];
		}
		else if(strcmp(argv[i],"-f")==0){
			filtre=argv[i+1];
		}
		else if (strcmp(argv[i],"-v")==0){
			verbo=argv[i+1];
			verb=atoi(verbo);
		}
		else{
			fprintf(stderr,"::erreur:: mauvais argument %s\ncommande de type: annalyseur -i <interface> -o <fichier> -f <filtre> -v <1..3>\n",argv[i]);
			return 2;
		}
		
	
	}
	if(fichier==NULL && interface!=NULL){
		printf("::warning:: programme doit utilisé les droits root pour fonctionnè \n");
		capture= pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
		if(capture==NULL){
			fprintf(stderr, "::erreur:: impossible d'ouvrir l'interface %s: %s\n", interface, errbuf);
			return 2;
		}
	}
	else if(interface==NULL && fichier==NULL){
		printf("::warning:: programme doit utilisé les droits root pour fonctionnè \n");
		dev = pcap_lookupdev(errbuf);
		if (dev == NULL) {
			fprintf(stderr, "::erreur:: imposible de trouvé une interface par défaut: %s\n", errbuf);
			return(2);
		}
		printf("%s\n",dev );
		capture= pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
		if(capture==NULL){
			fprintf(stderr, "::erreur:: impossible d'ouvrir l'interface %s: %s\n", interface, errbuf);
			return 2;
		}
	}
	else{
		FILE* f = NULL;
    	f = fopen(fichier, "r");
    	if(f==NULL){
    		perror("::erreur:: imposible de lire le fichier");
    		return 2;
    	} 
		capture= pcap_fopen_offline(f, errbuf);
		if(capture==NULL){
			fprintf(stderr, "::erreur:: impossible d'ouvrir l'interface %s: %s\n", interface, errbuf);
			return 2;
		}
	}
	if(filtre!=NULL){
		 if (pcap_compile(capture, &fp, filtre, 0, 0) == -1) {
		 fprintf(stderr, "::erreur:: imposible de parser le filtre %s: %s\n", filtre, pcap_geterr(capture));
		 return(2);
		 }
		 if (pcap_setfilter(capture, &fp) == -1) {
			 fprintf(stderr, "::erreur:: imposible d'instaler le filtre %s: %s\n", filtre, pcap_geterr(capture));
			 return(2);
		 }
	}	
	//printf("lecture en live de l'interface %s\n",interface);
	if(verb==1){
		printf("n°  | IP source     | IP destination|port s|port d| information\n");
		printf("---------------------------------------------------------------------\n");
	}
	pcap_loop(capture, 0, got_packet,NULL);
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
}
