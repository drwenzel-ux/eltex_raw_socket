#ifndef __L1NK_H__
#define __L1NK_H__

#include "utils.h"
#include <netinet/ether.h>

u_char *eth_builder(u_char *source, u_char *dest, u_char *data, u_short len);

#endif