#ifndef LIBIP_H
#define LIBIP_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "../libft/libft.h"


#define ERR  0
#define OK   1
#define ALL       0
#define PRIVATE_1 1
#define PRIVATE_2 2
#define PRIVATE_3 3
#define CUSTOM    4

#define LOW 0
#define UP 1


typedef struct s_ip_range
{
   uint8_t a;
   uint8_t b;
   uint8_t c;
   uint8_t d;

} t_ip_range;

uint16_t ft_htons_v2(uint16_t port);
uint16_t ft_htons_v1(uint16_t port);

/* utils */

int	   ipv4_value_check(char **str);
int      ft_inet_pton(int familly, char *addr_str, struct in_addr *addr);
uint32_t ft_inet_addr(char *addr_str);
uint32_t *generate_ipv4_range(t_ip_range start, t_ip_range end, int cidr);



#endif