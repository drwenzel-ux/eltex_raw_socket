#ifndef __TRANSPORT_H__
#define __TRANSPORT_H__

#include "utils.h"
#include <netinet/udp.h>

#define UDP_HLEN 8

u_char *udp_builder(u_short source, u_short dest, char *data, u_short len);

#endif