#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <sys/types.h>

void setsockaddr(struct sockaddr *sa, int fa, char *addr, u_short port);

#endif
