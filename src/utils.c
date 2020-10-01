#include "utils.h"

void setsockaddr(struct sockaddr *sa, int fa, char *addr, u_short port) {
  struct sockaddr_in *sa_in;

  sa_in = (struct sockaddr_in *)sa;
  sa_in->sin_family = fa;
  sa_in->sin_port = htons(port);
  sa_in->sin_addr.s_addr = inet_addr(addr);
}