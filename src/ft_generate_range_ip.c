/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_range_ip.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:43:50 by cdric.b           #+#    #+#             */
/*   Updated: 2026/08/02 10:07:42 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

/*
    les reseaux privées sont defini d'apres la rfc 1918

    PRIVATE_1       10.255.255.255  (10/8 prefix)
    PRIVATE_2       172.31.255.255  (172.16/12 prefix)
    PRIVATE_3       192.168.255.255 (192.168/16 prefix)
    ALL             0.0.0.0         (0/0 prefix)
    CUSTOM          plage personalisé
*/


t_ip_range get_range_start(int network_type)
{
    t_ip_range range;

    memset(&range, 0, sizeof(t_ip_range));
    if (network_type == PRIVATE_1)
    {
        range.a = 10;
    }
    else if(network_type == PRIVATE_2)
    {
        range.a = 172;
        range.b = 31;
    }
    else if(network_type == PRIVATE_3)
    {
        range.a = 192;
        range.b = 168;
    }
    return (range);
}

// void generate_private_1(void)
// {
//     t_ip_range range_start;

//     range_start = get_range_start(PRIVATE_1);
//     assert(range_start.a = 10 && range_start.b == 0 && range_start.c == 0 && range_start.d == 0);
        
// }
// void generate_private_2(void)
// {
//     t_ip_range range_start;

//     range_start = get_range_start(PRIVATE_2);
//     assert(range_start.a = 172 && range_start.b == 10 && range_start.c == 0 && range_start.d == 0);

        
// }

// void generate_private_3(void)
// {
//     t_ip_range range_start;

//     range_start = get_range_start(PRIVATE_3);
//     assert(range_start.a = 192 && range_start.b == 168 && range_start.c == 0 && range_start.d == 0);
//     /* the number of adress n ths range  = 256 ^ 2 */
        
// }

// void generate_all(void)
// {
//     t_ip_range range_start;

//     range_start = get_range_start(ALL);
//     assert(range_start.a = 0 && range_start.b == 0 && range_start.c == 0 && range_start.d == 0);
// }


/* check the validity of the range */

int check_range(t_ip_range start, t_ip_range end)
{
    if(start.a > 255 || end.a > 255)
        return (ERR);
    if(start.b > 255 || end.b > 255)
        return (ERR);
    if(start.c > 255 || end.c > 255)
        return (ERR);
    if(start.d > 255 || end.d > 255)
        return (ERR);
    if(start.a > end.a)
        return (ERR);
    if(start.b > end.b && start.a == end.a)
        return (ERR);
    if(start.c > end.c && start.a == end.a && start.b == end.b)
        return (ERR);
    if(start.d > end.d && start.a == end.a && start.b == end.b && start.c == end.c)
        return (ERR);
    return (OK);
}

t_ip_range get_range(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    t_ip_range range;

    range.a = a;
    range.b = b;
    range.c = c;
    range.d = d;
    return (range);
}

uint32_t *generate_ipv4_range(t_ip_range start, t_ip_range end, int cidr)
{
    (void)cidr;
    (void)end;
    (void)start;

    assert(check_range(get_range(0,0,255,255),get_range(0,0,25,255)) == ERR);
    assert(check_range(get_range(0,0,255,255),get_range(10,0,25,255)) == OK);
    assert(check_range(get_range(0,0,255,255),get_range(0,10,25,25)) == OK);
    assert(check_range(get_range(0,100,255,255),get_range(0,100,25,255)) == ERR);
    assert(check_range(get_range(0,25,255,255),get_range(0,100,25,0)) == OK);
    assert(check_range(get_range(0,0,0,255),get_range(0,0,0,165)) == ERR);
    assert(check_range(get_range(0,0,0,0),get_range(0,0,0,165)) == OK);

    return (0);
}
