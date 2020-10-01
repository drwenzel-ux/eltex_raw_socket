#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err(const char *m) {
  perror(m);
  exit(1);
}

int main() {
  int fd;

  fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd == -1)
    err("socket return -1");

  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  sa.sin_port = htons(7000);
  sa.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  socklen_t size = sizeof(sa);

  if (bind(fd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
    perror("bind failed");
    return -1;
  }

  char buffer[23];
  read(fd, buffer, sizeof(buffer));
  printf("server: %s\n", buffer);

  close(fd);
  return 0;
}