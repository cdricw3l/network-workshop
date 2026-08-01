/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:17:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/08/01 22:14:15 by cebouhad         ###   ########.fr       */
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

void ft_inet_addr_assert(void)
{
    printf("voici %u and %u\n", ft_inet_addr("192.168.0.0") , inet_addr("192.168.0.0"));
    printf("voici %u and %u\n", ft_inet_addr("192.168.0.1") , inet_addr("192.168.0.1"));
    printf("voici %u and %u\n", ft_inet_addr("192.168.0.2") , inet_addr("192.168.0.2"));
    printf("voici %u and %u\n", ft_inet_addr("192.168.0.255") , inet_addr("192.168.0.255"));
    assert(ft_inet_addr("192.168.0.0") == inet_addr("192.168.0.0"));
    assert(ft_inet_addr("192.168.0.255") == inet_addr("192.168.0.255"));
}

/*
    les reseaux privées sont defini d'apres la rfc 1918

    PRIVATE_1       10.255.255.255  (10/8 prefix)
    PRIVATE_2       172.31.255.255  (172.16/12 prefix)
    PRIVATE_3       192.168.255.255 (192.168/16 prefix)
    ALL             0.0.0.0         (0/0 prefix)
    CUSTOM          plage personalisé
*/






int main(void)
{
    ft_inet_addr_assert();
    //ft_inet_pton_assert();
    
    return (0);
}