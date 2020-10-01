#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "utils.h"
#include <netinet/ip.h>

#define IP_HLEN 20

u_char *ipv4_builder(char *source, char *dest, u_char *data, u_short len);
u_short ipv4_checksum(u_char *header);

#endif