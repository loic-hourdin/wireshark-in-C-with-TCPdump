#include "imap.h"


void print_imap(){
    int i;
	switch (verb)
        {   
        case 1:

            printf("| ");
            couleur("33");
            printf("IMAP: ");
            couleur("0");
            if(imap[0]>'0' && imap[0]<'9')printf("reponse: ");
        	else printf("request: ");
            i=0;
            do{
                
              printf("%c",imap[i]);
              i++;
               
            }while((!(imap[i]==' ' && i>30))&& imap[i]!='\n'&& i<size_imap);
            if((imap[i]==' ' && i>30))printf(" (...)");
            break;
        case 2:
            couleur("33");
            couleur("1");
            printf("IMAP:: ");
            couleur("0");
            if(imap[0]>'0' && imap[0]<'9')printf("reponse: ");
        	else printf("request: ");
            i=-1;
            do{
                i++;
              printf("%c",imap[i]);
              
            }while(imap[i]!='\n' && i<size_imap);
            printf("\n");
            break;
        case 3:
        printf("--------------");
            couleur("33");
            couleur("1");
            printf("IMAP");
            couleur("0");
            printf("--------------\n");
        if(imap[0]>'0' && imap[0]<'9')printf("reponse: \n");
        else printf("request: \n");
        for(i=0;i<size_imap;i++){
            printf("%c",imap[i]);
        }
        printf("\n");  
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}