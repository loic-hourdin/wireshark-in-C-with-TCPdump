#include "pop.h"


void print_pop(){
    int i;
    char affiche=1;

	switch (verb)
        {   
        case 1:

            printf("| ");
        	couleur("33");
            printf("POP: ");
            couleur("0");
            i=0;
            if(memcmp(pop, "USER", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("USER ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "PASS", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PASS ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "STAT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("STAT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "LIST", 4)==0){
            	couleur("31");
	           	couleur("1");
            	printf("LIST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "UIDL", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("UIDL ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "RETR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RETR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "DELE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("DELE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "TOP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("TOP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "LAST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("LAST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "RSET", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RSET ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "NOOP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("NOOP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "QUIT", 4)==0){
            	couleur("1");
            	couleur("31");
            	printf("QUIT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "+OK", 3)==0){
            	couleur("1");
            	couleur("31");
            	printf("+OK ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(pop, "AUTH", 4)==0){
            	couleur("1");
            	couleur("31");
            	printf("AUTH ");
            	couleur("0");
            	i=4;
            }

            /*else if(pop[0]>='A' && pop[0]<='Z'){
            	//printf("reponse: ");
            	couleur("31");
            	couleur("1");
            	printf("%c%c%c%c ",pop[0],pop[1],pop[2],pop[3]);
            	couleur("0");
            	i=4;
            }*/
            else {
            	printf("(commande inconue ou suite message)");
            	affiche=0;
            }
            if(affiche){
            	do{
	          	  printf("%c",pop[i]);
	              i++;
	              
	            }while(pop[i]!=0x0d && pop[i]!='\n' && i<size_pop && (!(pop[i]==' ' && i>30)));
	            if((pop[i]==' ' && i>30))printf("...");
            }
            
            
            /*

            if(pop[0]>'0' && pop[0]<'9')printf("reponse: ");
        	else printf("request: ");
            i=0;
            do{
                
              printf("%c",pop[i]);
              i++;
               
            }while((!(pop[i]==' ' && i>30))&& pop[i]!='\n'&& i<size_pop);
            if((pop[i]==' ' && i>30))printf(" (...)");*/
            break;
        case 2:
            couleur("33");
            couleur("1");
            printf("POP:: ");
            couleur("0");

			int size_text_sup=0;
            if(memcmp(pop, "USER", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("USER ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "PASS", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PASS ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "STAT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("STAT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "LIST", 4)==0){
            	couleur("31");
	           	couleur("1");
            	printf("LIST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "UIDL", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("UIDL ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "RETR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RETR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "DELE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("DELE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "TOP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("TOP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "LAST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("LAST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "RSET", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RSET ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "NOOP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("NOOP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "QUIT", 4)==0){
            	couleur("1");
            	couleur("31");
            	printf("QUIT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(pop, "+OK", 3)==0){
            	couleur("1");
            	couleur("31");
            	printf("+OK ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(pop, "AUTH", 4)==0){
            	couleur("1");
            	couleur("31");
            	printf("AUTH ");
            	couleur("0");
            	i=4;
            }
            else {
            	printf("(commande inconue ou suite message)");
            	affiche=0;
            	i=0;

            }

            /*else if(pop[0]>='A' && pop[0]<='Z'){
            	//printf("reponse: ");
            	couleur("31");
            	couleur("1");
            	printf("%c%c%c%c ",pop[0],pop[1],pop[2],pop[3]);
            	couleur("0");
            	i=4;
            }*/
            
            if(affiche){
            	while(pop[i]!=0x0d && pop[i]!=0x0a && pop[i]!='\r' && pop[i]!='\n' && i<size_pop && (!(pop[i]==' ' && i>(80-size_text_sup)))){
	          	  printf("%c",pop[i]);
	              i++;
	              
	            }
            	if(i>(80-size_text_sup))printf("...");
            }
        	

            /*
            if(pop[0]>'0' && pop[0]<'9')printf("reponse: ");
        	else printf("request: ");
            i=-1;
            do{
                i++;
              printf("%c",pop[i]);
              
            }while(pop[i]!='\n' && i<size_pop);*/
            printf("\n");
            break;
        case 3:
        printf("--------------");
        	couleur("33");
        	couleur("1");
            printf("POP");
            couleur("0");
            printf("--------------\n");
           i=0;
        if(memcmp(pop, "USER", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("USER ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "PASS", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("PASS ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "STAT", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("STAT ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "LIST", 4)==0){
        	couleur("31");
           	couleur("1");
        	printf("LIST ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "UIDL", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("UIDL ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "RETR", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("RETR ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "DELE", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("DELE ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "TOP", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("TOP ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "LAST", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("LAST ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "RSET", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("RSET ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "NOOP", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("NOOP ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "QUIT", 4)==0){
        	couleur("1");
        	couleur("31");
        	printf("QUIT ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(pop, "+OK", 3)==0){
        	couleur("1");
        	couleur("31");
        	printf("+OK ");
        	couleur("0");
        	i=3;
        }
        else if(memcmp(pop, "AUTH", 4)==0){
        	couleur("1");
        	couleur("31");
        	printf("AUTH ");
        	couleur("0");
        	i=4;
        }
        
        int tmp=i;
        for(i=tmp;i<size_pop;i++){
            printf("%c",pop[i]);
        }
        printf("\n");  
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}