/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:17:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/08/01 23:18:10 by cebouhad         ###   ########.fr       */
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

    assert(ft_inet_addr("192.168.0.0") == inet_addr("192.168.0.0"));
    assert(ft_inet_addr("192.168.0.255") == inet_addr("192.168.0.255"));
}








int main(void)
{

    ft_inet_addr_assert();
    //ft_inet_pton_assert();

    t_ip_range start;
    t_ip_range end;

    start.a = 10;
    start.b = 12;
    start.c = 0;
    start.d = 0;
    
    end.a = 10;
    end.b = 12;
    end.c = 255;
    end.d = 255;

    generate_ipv4_range(start, end, 12);
    return (0);
}