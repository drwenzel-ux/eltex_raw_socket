#include "l1nk.h"
#include "network.h"
#include "transport.h"
#include "utils.h"

#define DEVICE "docker0"

#define SOURCE_PORT 7001
#define DEST_PORT 7000

#define SOURCE_IP "172.17.0.1"
#define DEST_IP "172.17.0.2"

#define SMAC0 0x02
#define SMAC1 0x42
#define SMAC2 0x1B
#define SMAC3 0x24
#define SMAC4 0x2D
#define SMAC5 0xA0

#define DMAC0 0x02
#define DMAC1 0x42
#define DMAC2 0xAC
#define DMAC3 0x11
#define DMAC4 0x00
#define DMAC5 0x02

void err(const char *m) {
  perror(m);
  exit(1);
}

int main(int argc, char const *argv[]) {
  int fd;
  size_t tot_len = 0;
  struct sockaddr_ll sa;
  u_char *dgram, *packet, *frame;

  fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP));
  if (fd == -1)
    err("socket failed");

  char message[] = "hello, from raw client!";
  tot_len += sizeof(message);

  sa.sll_family = AF_PACKET;
  sa.sll_ifindex = if_nametoindex(DEVICE);
  sa.sll_halen = ETH_ALEN;

  dgram = udp_builder(SOURCE_PORT, DEST_PORT, message, sizeof(message));
  tot_len += sizeof(struct udphdr);

  packet = ipv4_builder(SOURCE_IP, DEST_IP, dgram, tot_len);
  tot_len += sizeof(struct iphdr);

  u_char source[] = {SMAC0, SMAC1, SMAC2, SMAC3, SMAC4, SMAC5};
  u_char dest[] = {DMAC0, DMAC1, DMAC2, DMAC3, DMAC4, DMAC5};

  frame = eth_builder(dest, source, packet, tot_len);
  tot_len += sizeof(struct ethhdr);

  int ret = sendto(fd, frame, tot_len, 0, (struct sockaddr *)&sa, sizeof(sa));

  if (ret == -1)
    perror("sendto failed");

  free(frame);
  close(fd);
  return 0;
}
