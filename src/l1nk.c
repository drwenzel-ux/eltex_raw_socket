#include "l1nk.h"

u_char *eth_builder(u_char *dest, u_char *source, u_char *data, u_short len) {
  u_char *frame;
  struct ethhdr *header;

  frame = calloc(sizeof(*header) + len, 1);
  memcpy(frame + sizeof(*header), data, len);

  header = (struct ethhdr *)frame;
  memcpy(header->h_dest, dest, 6);
  memcpy(header->h_source, source, 6);
  header->h_proto = htons(ETH_P_IP);

  free(data);
  return frame;
}
