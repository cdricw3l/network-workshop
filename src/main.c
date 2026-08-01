/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:17:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/08/01 21:44:24 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

void ft_inet_pton_assert(void)
{
    struct in_addr a;
    struct in_addr b;

    assert(ft_inet_pton(AF_INET, "192.168.1.10", &a) == inet_pton(AF_INET, "192.168.1.10", &b));
    assert(a.s_addr == b.s_addr);
    assert(ft_inet_pton(AF_INET, "0.0.0.0", &a) == inet_pton(AF_INET, "0.0.0.0", &b));
    assert(a.s_addr == b.s_addr);
    assert(ft_inet_pton(AF_INET, "10.12.5.1", &a) == inet_pton(AF_INET, "10.12.5.1", &b));
    assert(a.s_addr == b.s_addr);
    assert(ft_inet_pton(AF_INET, "255.255.255.255", &a) == inet_pton(AF_INET, "255.255.255.255", &b));
    assert(!ft_inet_pton(AF_INET, "256.255.255.255", &a));
    assert(!ft_inet_pton(AF_INET, "255.256.255.255", &a));
    assert(!ft_inet_pton(AF_INET, "255.255.256.255", &a));
    assert(!ft_inet_pton(AF_INET, "255.255.255.256", &a));
    assert(!ft_inet_pton(AF_INET, "192.168.1.a", &a));
}

/*
    les reseaux privées sont defini d'apres la rfc 1918

    PRIVATE_1       10.255.255.255  (10/8 prefix)
    PRIVATE_2       172.31.255.255  (172.16/12 prefix)
    PRIVATE_3       192.168.255.255 (192.168/16 prefix)
    ALL             0.0.0.0         (0/0 prefix)
    CUSTOM          plage personalisé
*/



t_ip_range range_initialisation(int network_type)
{
    t_ip_range ip_range;
    
    memset(&ip_range, 0, sizeof(t_ip_range));
    if(network_type == PRIVATE_1)
    {
        ip_range.a = 10;
    }
    else if (network_type == PRIVATE_2)
    {
        ip_range.a = 172;
        ip_range.b = 31;
    }
    else if (network_type == PRIVATE_3)
    {
        ip_range.a = 192;
        ip_range.b = 168;
    }
    return (ip_range);
}

int generate_range_ip(int type)
{
    t_ip_range ip;

    ip = range_initialisation(type);
    if (type == PRIVATE_1)
        assert(ip.a == 10 && ip.b == 0 && ip.c == 0 && ip.d == 0);
    if (type == PRIVATE_2)
        assert(ip.a == 172 && ip.b == 31 && ip.c == 0 && ip.d == 0);
    if (type == PRIVATE_3)
        assert(ip.a == 192 && ip.b == 168 && ip.c == 0 && ip.d == 0);
    if (type == ALL)
        assert(ip.a == 0 && ip.b == 0 && ip.c == 0 && ip.d == 0);

    


    return (OK);
}


int main(void)
{
    ft_inet_pton_assert();
    generate_range_ip(PRIVATE_1);

    in_addr_t add;
    struct in_addr a;

    add = inet_addr("192.168.1.1");
    ft_inet_pton(AF_INET, "192.168.1.1", &a);
    printf("A: %d\n", add);
    printf("A: %d\n", a.s_addr);

    return (0);
}