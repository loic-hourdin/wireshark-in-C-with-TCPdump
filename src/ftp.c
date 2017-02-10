#include "ftp.h"

void print_ftp(){
    int i;
	switch (verb)
        {   
        case 1:
        	printf("| ");
        	couleur("33");
            printf("FTP: ");
            couleur("0");
            i=0;
            if(memcmp(ftp, "USER", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("USER ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "PASS", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PASS ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "ACCT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("ACCT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "CWD", 3)==0){
            	couleur("31");
	           	couleur("1");
            	printf("CWD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "CDUP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("CDUP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "QUIT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("QUIT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "PORT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PORT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "PASV", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PASV ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "TYPE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("TYPE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RETR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RETR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "STOR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("STOR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "APPE", 4)==0){
            	couleur("1");
            	printf("APPE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "REST", 4)==0){
            	couleur("31");
	           	couleur("1");
            	printf("REST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RNFR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RNFR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RNTO", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RNTO ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "ABOR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("ABOR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "DELE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("DELE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RMD", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("RMD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "MKD", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("MKD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "PWD", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("PWD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "LIST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("LIST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "SYST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("SYST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "STAT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("STAT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "HELP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("HELP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "NOOP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("NOOP ");
            	couleur("0");
            	i=4;
            }
            else if(ftp[0]>='0' && ftp[0]<='9'){
            	//printf("reponse: ");
            	couleur("31");
            	couleur("1");
            	printf("%c%c%c ",ftp[0],ftp[1],ftp[2]);
            	couleur("0");
            	i=3;
            }
            do{
          	  printf("%c",ftp[i]);
              i++;
              
            }while(ftp[i]!=0x0d && ftp[i]!='\n' && i<size_ftp && (!(ftp[i]==' ' && i>30)));
            if((ftp[i]==' ' && i>30))printf("...");




            break;
        case 2:
            /*printf("FTP:: ");
            if(ftp[0]>'0' && ftp[0]<'9')printf("reponse: ");
        	else printf("request: ");
            i=-1;
            do{
                i++;
              printf("%c",ftp[i]);
              
            }while(ftp[i]!='\n' && i<size_ftp);
            printf("\n");*/

        	
        	couleur("33");
        	couleur("1");
            printf("FTP:: ");
            couleur("0");
            int size_text_sup=0;
            i=0;
            if(memcmp(ftp, "USER", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("USER ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "PASS", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PASS ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "ACCT", 4)==0){
            	couleur("1");
            	couleur("31");
            	printf("ACCT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "CWD", 3)==0){
            	couleur("31");
	           	couleur("1");
            	printf("CWD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "CDUP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("CDUP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "QUIT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("QUIT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "PORT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PORT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "PASV", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("PASV ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "TYPE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("TYPE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RETR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RETR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "STOR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("STOR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "APPE", 4)==0){
            	couleur("1");
            	printf("APPE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "REST", 4)==0){
            	couleur("31");
	           	couleur("1");
            	printf("REST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RNFR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RNFR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RNTO", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("RNTO ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "ABOR", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("ABOR ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "DELE", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("DELE ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "RMD", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("RMD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "MKD", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("MKD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "PWD", 3)==0){
            	couleur("31");
            	couleur("1");
            	printf("PWD ");
            	couleur("0");
            	i=3;
            }
            else if(memcmp(ftp, "LIST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("LIST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "SYST", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("SYST ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "STAT", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("STAT ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "HELP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("HELP ");
            	couleur("0");
            	i=4;
            }
            else if(memcmp(ftp, "NOOP", 4)==0){
            	couleur("31");
            	couleur("1");
            	printf("NOOP ");
            	couleur("0");
            	i=4;
            }
            else if(ftp[0]>='0' && ftp[0]<='9'){
            	//printf("reponse: ");
            	couleur("31");
            	couleur("1");
            	printf("%c%c%c ",ftp[0],ftp[1],ftp[2]);
            	couleur("0");
            	printf("(rep");
            	if(ftp[1]=='0'){printf(" syntaxe");size_text_sup+=8;}
            	if(ftp[1]=='1'){printf(" info");size_text_sup+=5;}
            	if(ftp[1]=='2'){printf(" connexion");size_text_sup+=10;}
            	if(ftp[1]=='3'){printf(" auth");size_text_sup+=5;}
            	if(ftp[1]=='5'){printf(" syntaxe fichier");size_text_sup+=16;}
            	if(ftp[0]=='1'){printf(" positif en cour");size_text_sup+=16;}
            	if(ftp[0]=='2'){printf(" positif réalisé");size_text_sup+=16;}
            	if(ftp[0]=='3'){printf(" intermèdiare pos");size_text_sup+=17;}
            	if(ftp[0]=='4'){printf(" négative");size_text_sup+=8;}
            	if(ftp[0]=='5'){printf(" impossible");size_text_sup+=10;}
            	printf(")");
            	i=3;
            }
            while(ftp[i]!=0x0d && ftp[i]!=0x0a && ftp[i]!='\r' && ftp[i]!='\n' && i<size_ftp && (!(ftp[i]==' ' && i>(80-size_text_sup)))){
          	  printf("%c",ftp[i]);
              i++;
              
            }
            if(i>(80-size_text_sup))printf("...");
            printf("\n");




            break;
        case 3:
        /*
	        printf("--------------FTP--------------------\n");
	        if(ftp[0]>'0' && ftp[0]<'9')printf("reponse: \n");
	        else printf("request: \n");
	        for(i=0;i<size_ftp;i++){
	            printf("%c",ftp[i]);
	        }
	        printf("\n");  
        */	
        	printf("--------------");
        	couleur("33");
        	couleur("1");
            printf("FTP");
            couleur("0");
            printf("--------------\n");
            i=0;
            if(memcmp(ftp, "USER", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("USER ");
            	couleur("0");
            	printf("(identification de l’utilisateur )\n");
            	i=4;
            }
            else if(memcmp(ftp, "PASS", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("PASS ");
            	couleur("0");
            	printf("(mot de passe de l’utilisateur )\n");
            	i=4;
            }
            else if(memcmp(ftp, "ACCT", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("ACCT ");
            	couleur("0");
            	printf("(e compte (account) de l’utilisateur)\n");
            	i=4;
            }
            else if(memcmp(ftp, "CWD", 3)==0){
            	printf("commande: ");
            	couleur("31");
	           	couleur("1");
            	printf("CWD ");
            	couleur("0");
            	printf("(changer le répertoire courant)\n");
            	i=3;
            }
            else if(memcmp(ftp, "CDUP", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("CDUP ");
            	couleur("0");
            	printf("(remonter au répertoire)\n");
            	i=4;
            }
            else if(memcmp(ftp, "QUIT", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("QUIT ");
            	couleur("0");
            	printf("(terminer la session en cours )\n");
            	i=4;
            }
            else if(memcmp(ftp, "PORT", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("PORT ");
            	couleur("0");
            	printf("(numéro de port à utiliser)\n");
            	i=4;
            }
            else if(memcmp(ftp, "PASV", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("PASV ");
            	couleur("0");
            	printf("(mode passif )\n");
            	i=4;
            }
            else if(memcmp(ftp, "TYPE", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("TYPE ");
            	couleur("0");
            	printf("(type de format dans lequel les données seront envoyées)\n");
            	i=4;
            }
            else if(memcmp(ftp, "RETR", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("RETR ");
            	couleur("0");
            	printf("(demande au serveur une copie du fichier dont le chemin d’accès est passé en paramètre)\n");
            	i=4;
            }
            else if(memcmp(ftp, "STOR", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("STOR ");
            	couleur("0");
            	printf("(emande au serveur d’accepter les données envoyées sur le canal de données)\n");
            	i=4;
            }
            else if(memcmp(ftp, "APPE", 4)==0){
            	printf("commande: ");
            	couleur("1");
            	printf("APPE ");
            	couleur("0");
            	printf("(les données envoyées sont concaténées dans le fichier portant le nom passé en paramètre s’il existe déjà\n");
            	i=4;
            }
            else if(memcmp(ftp, "REST", 4)==0){
            	printf("commande: ");
            	couleur("31");
	           	couleur("1");
            	printf("REST ");
            	couleur("0");
            	printf("(reprendre un transfert là où il s’était arrêté)\n");
            	i=4;
            }
            else if(memcmp(ftp, "RNFR", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("RNFR ");
            	couleur("0");
            	printf("(renommer un fichier)\n");
            	i=4;
            }
            else if(memcmp(ftp, "RNTO", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("RNTO ");
            	couleur("0");
            	printf("(renommer un fichier)\n");
            	i=4;
            }
            else if(memcmp(ftp, "ABOR", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("ABOR ");
            	couleur("0");
            	printf("(abandonner tous les transferts associés à la commande précédente)\n");
            	i=4;
            }
            else if(memcmp(ftp, "DELE", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("DELE ");
            	couleur("0");
            	printf("(supprimer le fichier dont le nom est passé en paramètre)\n");
            	i=4;
            }
            else if(memcmp(ftp, "RMD", 3)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("RMD ");
            	couleur("0");
            	printf("(supprimer un répertoire)\n");
            	i=3;
            }
            else if(memcmp(ftp, "MKD", 3)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("MKD ");
            	couleur("0");
            	printf("(créer un répertoire)\n");
            	i=3;
            }
            else if(memcmp(ftp, "PWD", 3)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("PWD ");
            	couleur("0");
            	printf("(chemin complet du répertoire courant)\n");
            	i=3;
            }
            else if(memcmp(ftp, "LIST", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("LIST ");
            	couleur("0");
            	printf("(envoyer la liste des fichiers et répertoires présents dans le répertoire courant)\n");
            	i=4;
            }
            else if(memcmp(ftp, "SYST", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("SYST ");
            	couleur("0");
            	printf("(informations sur le serveur distant)\n");
            	i=4;
            }
            else if(memcmp(ftp, "STAT", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("STAT ");
            	couleur("0");
            	printf("(état du serveur)\n");
            	i=4;
            }
            else if(memcmp(ftp, "HELP", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("HELP ");
            	couleur("0");
            	printf("(ensemble des commandes comprises par le serveur)\n");
            	i=4;
            }
            else if(memcmp(ftp, "NOOP", 4)==0){
            	printf("commande: ");
            	couleur("31");
            	couleur("1");
            	printf("NOOP ");
            	couleur("0");
            	printf("(obtenir une commande OK du serveur)\n");
            	i=4;
            }
            else if(ftp[0]>='0' && ftp[0]<='9'){
            	printf("reponse: ");
            	couleur("31");
            	couleur("1");
            	printf("%c%c%c ",ftp[0],ftp[1],ftp[2]);
            	couleur("0");
            	printf("(rep");
            	size_text_sup=0;
            	if(ftp[1]=='0'){printf(" syntaxe");size_text_sup+=8;}
            	if(ftp[1]=='1'){printf(" info");size_text_sup+=5;}
            	if(ftp[1]=='2'){printf(" connexion");size_text_sup+=10;}
            	if(ftp[1]=='3'){printf(" auth");size_text_sup+=5;}
            	if(ftp[1]=='5'){printf(" syntaxe fichier");size_text_sup+=16;}
            	if(ftp[0]=='1'){printf(" positif en cour");size_text_sup+=16;}
            	if(ftp[0]=='2'){printf(" positif réalisé");size_text_sup+=16;}
            	if(ftp[0]=='3'){printf(" intermèdiare pos");size_text_sup+=17;}
            	if(ftp[0]=='4'){printf(" négative");size_text_sup+=8;}
            	if(ftp[0]=='5'){printf(" impossible");size_text_sup+=10;}
            	printf(")\n");

            	i=3;
            }
            i=0;
            printf("donné:\n");
            while(ftp[i]!=0x0d && ftp[i]!=0x0a && ftp[i]!='\r' && ftp[i]!='\n' && i<size_ftp && (!(ftp[i]==' ' && i>(80-size_text_sup)))){
          	  printf("%c",ftp[i]);
              i++;
              
            }
            if(i>(80-size_text_sup))printf("...");
            printf("\n");
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}

void print_ftp_data(){
    int i;
	switch (verb)
        {   
        case 1:
        	printf("| ");
        	couleur("33");
        	couleur("1");
            printf("FTP-DATA ");
            couleur("0");
            i=0;
            




            break;
        case 2:
            

        	printf("| ");
        	couleur("33");
        	couleur("1");
            printf("FTP-DATA: ");
            couleur("0");
            
            printf("donné de ftp\n");

            break;
        case 3:
        	printf("--------------");
        	couleur("33");
        	couleur("1");
            printf("FTP-DATA");
            couleur("0");
            printf("--------------\n");
	        printf("data:\n");
	        for(i=0;i<size_ftp;i++){
	            printf("%.2x ",ftp[i]);
	        }
	        printf("\n");  
        
            break;
        default:
            printf("::error::verbo superieur a 3\n");
            break;
        }
        

}