#include "transport.h"

u_char *udp_builder(u_short source, u_short dest, char *data, u_short len) {
  u_char *dgram;
  struct udphdr *header;

  dgram = calloc(sizeof(*header) + len, 1);
  memcpy(dgram + sizeof(*header), data, len);

  header = (struct udphdr *)dgram;
  header->source = htons(source);
  header->dest = htons(dest);
  header->len = htons(sizeof(*header) + len);

  return dgram;
}
