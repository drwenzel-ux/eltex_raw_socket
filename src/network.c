#include "network.h"

u_char *ipv4_builder(char *source, char *dest, u_char *data, u_short len) {
  u_char *packet;
  struct iphdr *header;

  packet = calloc(sizeof(*header) + len, 1);
  memcpy(packet + sizeof(*header), data, len);

  header = (struct iphdr *)packet;
  header->ihl = 0x5;
  header->version = IPVERSION;
  header->protocol = IPPROTO_UDP;
  header->tot_len = htons(sizeof(*header) + len);
  header->ttl = 64;
  header->saddr = inet_addr(source);
  header->daddr = inet_addr(dest);
  header->check = htons(ipv4_checksum((u_char *)header));

  free(data);
  return packet;
}

u_short ipv4_checksum(u_char *header) {
  int sum;
  size_t i, len;

  sum = 0;
  len = sizeof(struct iphdr);
  for (i = 0; i < len; i += 2) {
    if (i == 10)
      continue;
    sum += (header[i] << 8) | header[i + 1];
  }

  sum += (sum >> 16);
  return (u_short)~sum;
}
