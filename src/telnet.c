#include "telnet.h"


void print_telnet(){
    int i;
    int taille, err;
	switch (verb)
    {   
        case 1:
	        taille=0;
	        printf("| ");
        	couleur("33");
            printf("Telnet: ");
            couleur("0");
	        if(size_telnet!=0){
	        	i=0;
	        	err=0;
	        	while(telnet[i]==255 && i<size_telnet && err==0 && taille<25){
	        		i++;

	        		switch(telnet[i])
	        		{
	        			case 251:
	        				printf("will ");
	        				taille +=5;
	        				break;
	        			case 252:
	        				printf("won't ");
	        				taille +=6;
	        				break;
	        			case 253:
	        				printf("do ");
	        				taille +=4;
	        				break;
	        			case 254:
	        				printf("don't ");
	        				taille +=6;
	        				break;
	        			default:
				            err=1;
				            break;

	        		}

	        		if(err==0){
	        			i++;
	        			switch(telnet[i])
	        			{
		        			case 1:
		        				printf("echo ");
		        				taille +=5;
		        				break;
		        			case 0:
		        				printf("binary ");
		        				taille +=7;

		        				break;
		        			case 3:
		        				printf("supresse go head ");
		        				taille +=17;

		        				break;
		        			case 24:
		        				printf("terminal type ");
		        				taille +=14;
		        				break;
		        			case 31:
		        				printf("window size ");
		        				taille +=11;
		        				break;
		        			case 32:
		        				printf("terminal speed ");
		        				taille +=16;
		        				break;
		        			case 34:
		        				printf("line mode ");
		        				taille +=12;
		        				break;
		        			case 36:
		        				printf("env option ");
		        				taille +=11;
		        				break;
		        			case 39:
		        				printf("new env option ");
		        				taille +=14;
		        				break;
		        			default:
					            printf("option n°%u ",telnet[i] );
					            taille +=14;
					            break;

	        			}
	        			while(telnet[i]==255 && i<size_telnet){
	        				if(telnet[i]=='\n')printf("\\n");
	        				else if(telnet[i]==0xd);
	        				else printf("%c",telnet[i]);
	        				i++;
	        				taille++;
	        			}
	        			i++;
	        			printf("   ");
	        			taille+=3;
	        		}
	        		else i--;
	        	}
	        	while(i<size_telnet && taille<30){
	        		if(telnet[i]=='\n')printf("\\n");
	        		else if(telnet[i]==0xd);
	        		else printf("%c",telnet[i]);
	        		taille++;
	        		i++;
	        	}
	        	if(taille>25) printf("(...)");
	        }


            break;
        case 2:
	        taille=0;
	        couleur("33");
	        couleur("1");
            printf("Telnet:: ");
            couleur("0");
	        if(size_telnet!=0){
	        	i=0;
	        	err=0;
	        	while(telnet[i]==255 && i<size_telnet && err==0 && taille<50){
	        		i++;

	        		switch(telnet[i])
	        		{
	        			case 251:
	        				printf("will ");
	        				taille +=5;
	        				break;
	        			case 252:
	        				printf("won't ");
	        				taille +=6;
	        				break;
	        			case 253:
	        				printf("do ");
	        				taille +=4;
	        				break;
	        			case 254:
	        				printf("don't ");
	        				taille +=6;
	        				break;
	        			default:
				            err=1;
				            break;

	        		}

	        		if(err==0){
	        			i++;
	        			switch(telnet[i])
	        			{
		        			case 1:
		        				printf("echo ");
		        				taille +=5;
		        				break;
		        			case 0:
		        				printf("binary ");
		        				taille +=7;

		        				break;
		        			case 3:
		        				printf("supresse go head ");
		        				taille +=17;

		        				break;
		        			case 24:
		        				printf("terminal type ");
		        				taille +=14;
		        				break;
		        			case 31:
		        				printf("window size ");
		        				taille +=11;
		        				break;
		        			case 32:
		        				printf("terminal speed ");
		        				taille +=16;
		        				break;
		        			case 34:
		        				printf("line mode ");
		        				taille +=12;
		        				break;
		        			case 36:
		        				printf("env option ");
		        				taille +=11;
		        				break;
		        			case 39:
		        				printf("new env option ");
		        				taille +=14;
		        				break;
		        			default:
					            printf("option n°%u ",telnet[i] );
					            taille +=14;
					            break;

	        			}
	        			while(telnet[i]==255 && i<size_telnet){
	        				if(telnet[i]=='\n')printf("\\n");
	        				else if(telnet[i]==0xd);
	        				else printf("%c",telnet[i]);
	        				i++;
	        				taille++;
	        			}
	        			i++;
	        			printf("\n");
	        		}
	        		else i--;

	        	}
	        	while(i<size_telnet && taille<60){
	        		if(telnet[i]=='\n')printf("\\n");
	        		else if(telnet[i]==0xd);
	        		else printf("%c",telnet[i]);
	        		taille++;
	        		i++;
	        	}
	        	if(taille>50) printf("(...)");
	        	printf("\n");


	        }
            
            break;
        case 3:
        printf("--------------");
        	couleur("33");
        	couleur("1");
            printf("TELNET");
            couleur("0");
            printf("--------------\n");
        
	        if(size_telnet!=0){
	        	i=0;
	        	err=0;
	        	while(telnet[i]==255 && i<size_telnet && err==0){
	        		i++;
	        		switch(telnet[i])
	        		{
	        			case 251:
	        				printf("will\t");
	        				break;
	        			case 252:
	        				printf("won't\t");
	        				break;
	        			case 253:
	        				printf("do\t");
	        				break;
	        			case 254:
	        				printf("don't\t");
	        				break;
	        			default:
				            err=1;
				            break;

	        		}

	        		if(err==0){
	        			i++;
	        			switch(telnet[i])
	        			{
		        			case 1:
		        				printf("echo ");
		        				break;
		        			case 0:
		        				printf("binary ");
		        				break;
		        			case 3:
		        				printf("supresse go head ");
		        				break;
		        			case 24:
		        				printf("terminal type ");
		        				break;
		        			case 31:
		        				printf("window size ");
		        				break;
		        			case 32:
		        				printf("terminal speed ");
		        				break;
		        			case 34:
		        				printf("line mode ");
		        				break;
		        			case 36:
		        				printf("env option ");
		        				break;
		        			case 39:
		        				printf("new env option ");
		        				break;
		        			default:
					            printf("option n°%u ",telnet[i] );
					            break;

	        			}
	        			while(telnet[i]==255 && i<size_telnet){
	        				printf("%c",telnet[i]);
	        				i++;
	        			}
	        			i++;
	        			printf("\n");
	        		}
	        		else i--;
	        	}
	        	while(i<size_telnet){
	        		printf("%c",telnet[i]);
	        		i++;
	        	}


	        }
        
            break;
        default:
            printf("::error::verbo superieur a 3 \n");
            break;
    }
}

