/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:17:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 12:21:57 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

uint16_t ft_htons_v1(uint16_t port)
{
    uint16_t p3;

    p3 = 0;
    p3 |= port >> 8;
    p3 |= port << 8;
    
    return (p3);
}

uint16_t ft_htons_v2(uint16_t port)
{
    return ((port >> 8) | (port << 8));
}



int main(void)
{
    uint16_t p = htons(9090);
    assert(ft_htons_v1(9090) == p && p == ft_htons_v2(9090));

    printf("byte order %d and %d\n", __BYTE_ORDER__, __ORDER_LITTLE_ENDIAN__);
}