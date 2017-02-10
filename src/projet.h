#ifndef PROJET_H
#define PROJET_H




#include "constante.h"
#include "ethernet.h"
#include "ip.h"
#include "tcp.h"
#include "udp.h"
#include "bootp.h"
#include "smtp.h"
#include "http.h"
#include "ftp.h"
#include "pop.h"
#include "imap.h"
#include "arp.h"
#include "telnet.h"
#include "paquet.h"


void got_packet(u_char *args, const struct pcap_pkthdr *hdr, const u_char *truepacket);
void parser(const u_char* truepacket);
void aff(const struct pcap_pkthdr *hdr);

#endif