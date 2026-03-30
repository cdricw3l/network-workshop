/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:17:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 22:37:46 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

void ft_inet_pton_assert(void)
{
    struct in_addr a;

    assert(ft_inet_pton(AF_INET, "192.168.1.10", &a));
    assert(ft_inet_pton(AF_INET, "0.0.0.0", &a));
    assert(ft_inet_pton(AF_INET, "255.255.255.255", &a));
    assert(!ft_inet_pton(AF_INET, "256.255.255.255", &a));
    assert(!ft_inet_pton(AF_INET, "255.256.255.255", &a));
    assert(!ft_inet_pton(AF_INET, "255.255.256.255", &a));
    assert(!ft_inet_pton(AF_INET, "255.255.255.256", &a));
    assert(!ft_inet_pton(AF_INET, "192.168.1.a", &a));
}

int main(void)
{

    ft_inet_pton_assert();
    return (0);
    
}