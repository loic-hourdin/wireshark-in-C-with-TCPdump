#include "smtp.h"

void print_smtp(){
    int i;
    int size_text_sup=0;
	switch (verb)
        {   
        case 1:
            printf("| ");
            couleur("33");
            printf("SMTP: ");
            couleur("0");
            i=0;
            if(memcmp(smtp, "HELO", 4)==0){
                couleur("31");
                couleur("1");
                printf("HELO ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "MAIL", 4)==0){
                couleur("31");
                couleur("1");
                printf("MAIL ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "RCPT", 4)==0){
                couleur("31");
                couleur("1");
                printf("RCPT ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "DATA", 4)==0){
                couleur("31");
                couleur("1");
                printf("DATA ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "QUIT", 4)==0){
                couleur("31");
                couleur("1");
                printf("QUIT ");
                couleur("0");
                i=4;
            }
            else if(smtp[0]>='0' && smtp[0]<='9'){
                //printf("reponse: ");
                couleur("31");
                couleur("1");
                printf("%c%c%c ",smtp[0],smtp[1],smtp[2]);
                couleur("0");
                i=3;
            }
            do{
              printf("%c",smtp[i]);
              i++;
              
            }while(smtp[i]!=0x0d && smtp[i]!='\n' && i<size_smtp && (!(smtp[i]==' ' && i>30)));
            if((smtp[i]==' ' && i>30))printf("...");            
            break;
        case 2:
            couleur("33");
            couleur("1");
            printf("SMTP:: ");
            couleur("0");
            i=0;
            if(memcmp(smtp, "HELO", 4)==0){
                couleur("31");
                couleur("1");
                printf("HELO ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "MAIL", 4)==0){
                couleur("31");
                couleur("1");
                printf("MAIL ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "RCPT", 4)==0){
                couleur("31");
                couleur("1");
                printf("RCPT ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "DATA", 4)==0){
                couleur("31");
                couleur("1");
                printf("DATA ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "QUIT", 4)==0){
                couleur("31");
                couleur("1");
                printf("QUIT ");
                couleur("0");
                i=4;
            }
            else if(smtp[0]>='0' && smtp[0]<='9'){
                //printf("reponse: ");
                couleur("31");
                couleur("1");
                printf("%c%c%c",smtp[0],smtp[1],smtp[2]);
                couleur("0");
                if(smtp[0]=='2'||smtp[0]=='3'||smtp[0]=='4'||smtp[0]=='5') printf("(");
                if(smtp[0]=='2'){printf("executé)");size_text_sup+=9;}
                if(smtp[0]=='3'){printf("en cours)");size_text_sup+=11;}
                if(smtp[0]=='4'){printf("erreur tmp)");size_text_sup+=12;}
                if(smtp[0]=='5'){printf("impossible)");size_text_sup+=12;}
                
                i=3;
            }
            while(smtp[i]!=0x0d && smtp[i]!=0x0a && smtp[i]!='\r' && smtp[i]!='\n' && i<size_smtp && (!(smtp[i]==' ' && i>(80-size_text_sup)))){
              printf("%c",smtp[i]);
              i++;
              
            }
            if(i>(80-size_text_sup))printf("...");
            printf("\n");
/*
            do{
                i++;
              printf("%c",smtp[i]);
              
            }while(smtp[i]!='\n' && i<size_smtp);
            printf("\n");*/
            break;
        case 3:
        printf("--------------");
            couleur("33");
            couleur("1");
            printf("SMTP");
            couleur("0");
            printf("--------------\n");
        if(memcmp(smtp, "HELO", 4)==0){
                printf("Commande: ");
                couleur("31");
                couleur("1");
                printf("HELO ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "MAIL", 4)==0){
                printf("Commande: ");
                couleur("31");
                couleur("1");
                printf("MAIL ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "RCPT", 4)==0){
                printf("Commande: ");
                couleur("31");
                couleur("1");
                printf("RCPT ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "DATA", 4)==0){
                printf("Commande: ");
                couleur("31");
                couleur("1");
                printf("DATA ");
                couleur("0");
                i=4;
            }
            else if(memcmp(smtp, "QUIT", 4)==0){
                printf("Commande: ");
                couleur("31");
                couleur("1");
                printf("QUIT ");
                couleur("0");
                i=4;
            }
            else if(smtp[0]>='0' && smtp[0]<='9'){
                printf("Reponse: ");
                couleur("31");
                couleur("1");
                printf("%c%c%c",smtp[0],smtp[1],smtp[2]);
                couleur("0");
                if(smtp[0]=='2'||smtp[0]=='3'||smtp[0]=='4'||smtp[0]=='5') printf(" (");
                if(smtp[0]=='2'){printf("executé)");size_text_sup+=9;}
                if(smtp[0]=='3'){printf("en cours)");size_text_sup+=11;}
                if(smtp[0]=='4'){printf("erreur tmp)");size_text_sup+=12;}
                if(smtp[0]=='5'){printf("impossible)");size_text_sup+=12;}
                
                i=3;
            }
        printf("\n");
        printf("Donné: \n");
        for(i=0;i<size_smtp;i++){
            printf("%c",smtp[i]);
        }
        printf("\n");    
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}
