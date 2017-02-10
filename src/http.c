#include "http.h"

void print_http(){
    int i;
	switch (verb)
        {   
        case 1:
        	printf("| ");
        	couleur("33");
            printf("HTTP: ");
            couleur("0");
            i=0;
            if(memcmp(http, "GET", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("GET ");
            	couleur("0");
            }
            else if(memcmp(http, "HEAD", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("HEAD ");
            	couleur("0");
            }
            else if(memcmp(http, "POST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("POST ");
            	couleur("0");
            }
            else if(memcmp(http, "OPTIONS", 7)==0){
            	couleur("31");
            	couleur("1");
            	printf("OPTIONS ");
            	couleur("0");
            }
            else if(memcmp(http, "CONNECT", 7)==0){
            	couleur("31");
            	couleur("1");
            	printf("CONNECT ");
            	couleur("0");
            }
            else if(memcmp(http, "TRACE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("TRACE ");
            	couleur("0");
            }
            else if(memcmp(http, "PUT", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("PUT ");
            	couleur("0");
            }
            else if(memcmp(http, "PATCH", 5)==0){
            	couleur("31");
            	couleur("1");
            	printf("PATCH ");
            	couleur("0");
            }
            else if(memcmp(http, "DELETE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("DELETE ");
            	couleur("0");
            }
            else if(memcmp(http, "HTTP", 4)==0){
            	i=0;

            	while (http[i]!=' '){
            		i++;
            	}
            	printf("reponse");
            	couleur("1");
            	couleur("31");
            	printf(" %c%c%c ",http[i+1],http[i+2],http[i+3]);
            	couleur("0");
            }
            else printf("suite du message");
            
            /*do{
                
              printf("%c",http[i]);
              i++;
               
            }while(http[i]!=' ' && http[i]!='\n'&& i<size_http);*/
            break;
        case 2:
        	couleur("33");
            couleur("1");
            printf("HTTP:: ");
            couleur("0");
            i=0;
            int tmp_affiche=1;
            if(memcmp(http, "GET", 3)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("GET");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(http, "HEAD", 4)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("HEAD");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(http, "POST", 4)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("POST ");
            	couleur("0");
            	i=5;
            }
            else if(memcmp(http, "OPTIONS", 7)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("OPTIONS ");
            	couleur("0");
            	i=7;
            }
            else if(memcmp(http, "CONNECT", 7)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("CONNECT ");
            	couleur("0");
            	i=7;
            }
            else if(memcmp(http, "TRACE", 4)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("TRACE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(http, "PUT", 3)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("PUT ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(http, "PATCH", 5)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("PATCH ");
            	couleur("0");
            	i=5;
            }
            else if(memcmp(http, "DELETE", 4)==0){
            	tmp_affiche=1;
            	couleur("31");
            	couleur("1");
            	printf("DELETE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(http, "HTTP", 4)==0){
            	i=0;
            	tmp_affiche=1;
            	while (http[i]!=' '){
            		i++;
            		printf("%c",http[i]);
            	}
            	printf(" ");
            	couleur("1");
            	couleur("31");
            	printf(" %c%c%c ",http[i+1],http[i+2],http[i+3]);
            	couleur("0");
            	i+=4;
            }
            else {
            	tmp_affiche=0;
            	printf("(suite du message)\n");
            }
            if (tmp_affiche){
            	while(http[i]!=0x0d){
            		printf("%c",http[i]);
            		i++;
            	}
            }
            break;
        case 3:
        printf("--------------");
        couleur("33");
        couleur("1");
        printf("HTTP");
        couleur("0");
        printf("--------------------\n");
         if(memcmp(http, "GET", 3)==0){
        	couleur("31");
        	couleur("1");
        	printf("GET");
        	couleur("0");
        	i=3;
        }
        else if(memcmp(http, "HEAD", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("HEAD");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(http, "POST", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("POST ");
        	couleur("0");
        	i=5;
        }
        else if(memcmp(http, "OPTIONS", 7)==0){
        	couleur("31");
        	couleur("1");
        	printf("OPTIONS ");
        	couleur("0");
        	i=7;
        }
        else if(memcmp(http, "CONNECT", 7)==0){
        	couleur("31");
        	couleur("1");
        	printf("CONNECT ");
        	couleur("0");
        	i=7;
        }
        else if(memcmp(http, "TRACE", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("TRACE ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(http, "PUT", 3)==0){
        	couleur("31");
        	couleur("1");
        	printf("PUT ");
        	couleur("0");
        	i=3;
        }
        else if(memcmp(http, "PATCH", 5)==0){
        	couleur("31");
        	couleur("1");
        	printf("PATCH ");
        	couleur("0");
        	i=5;
        }
        else if(memcmp(http, "DELETE", 4)==0){
        	couleur("31");
        	couleur("1");
        	printf("DELETE ");
        	couleur("0");
        	i=4;
        }
        else if(memcmp(http, "HTTP", 4)==0){
        	i=0;
        	while (http[i]!=' '){
        		i++;
        		printf("%c",http[i]);
        	}
        	printf(" ");
        	couleur("1");
        	couleur("31");
        	printf(" %c%c%c ",http[i+1],http[i+2],http[i+3]);
        	couleur("0");
        	i+=4;
        }
        else printf("suite du message:\n");
        char affichable=1;
        int tmp=i;
        for(i=i;i<size_http;i++){
            if(http[i]<0){
            	affichable=0;
            	break;
            }
        }
        int tmp2=i;
        for(i=tmp;i<tmp2;i++){
            	printf("%c",http[i]);
        }
        
        if(!affichable) printf(" ...(donnée impossible a affiché en ascii)\n");
        /*for(i=tmp2;i<size_http;i+=2){
            	printf("%.2x",http[i]);
            	printf("%.2x ",http[i+1]);
            	if((i-tmp2)%16==0)printf("\n");
        }
        if(i==size_http){
        	printf("%.2x",http[i-1]);
        }*/

        printf("\n");
        
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}