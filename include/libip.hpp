#ifndef LIBIP_H
#define LIBIP_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <iostream>
#include <assert.h>
#include <array>
#include <string.h>
#include "libft.h"


#define ALL       0
#define PRIVATE_1 1
#define PRIVATE_2 2
#define PRIVATE_3 3
#define CUSTOM    4

#define LOW 0
#define UP 1

using namespace std;

uint32_t    ft_inet_addr(const char *addr);
uint32_t    ft_reverse_bit(uint32_t n);
uint32_t    ft_reverse_octets(uint32_t n);
uint32_t    get_network_size(string ip_start, string ip_end);

void        get_ip_range(uint32_t range[2], int net_type, const char *ip_start, const char *ip_end);
uint32_t    *gnr_range_ip(int network_type, const char *ip_start, const char *ip_end, uint32_t *size);
char        *decimal_to_hex(size_t n, int up);

#endif