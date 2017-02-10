#include "paquet.h"

void print_paquet(u_char* packet,const struct pcap_pkthdr *hdr){
	int i,j,k;
if (verb>2){
	printf(", Len: %i (0x%x)\n",hdr->caplen,hdr->caplen);
	 
	for (i=0;i<=hdr->caplen/16;i++)
	{
	 	if(i*16 != hdr->caplen)printf("0x%.2x  ",i*16); 
	 	k =(((i+1)*16)>hdr->caplen)?hdr->caplen-(i*16):16;
	 
	 	for (j=0;j<k;j=j+2)
	  	{
	  		printf("%.2x",*packet);
	  		packet++;
	  		printf("%.2x ",*packet);
	  		packet++;
	  	}
	 
	 	if (k != 16)
	  	for (j=k;j<16;j++)
	   		printf("   " );
	 
	 	printf("  " );
	 	packet-=k;
	 
	 	for (j=0;j<k;j++)
	  	{
	  		if (*packet>=32 && *packet<=128)
	   			printf("%c",*packet);
	  		else
	   			printf("." );
	  		packet++;
   		}
	 
	 	if (i*16 != hdr->caplen)
	  		printf("\n" );
	 	}
	}
printf("\n");
}

