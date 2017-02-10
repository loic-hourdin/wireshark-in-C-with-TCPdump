#ifndef TCP_H
#define TCP_H

#include <netinet/tcp.h>
#include "constante.h"

struct tcphdr* tcp;

void print_tcp();
void print_tcp_apli();

#endif