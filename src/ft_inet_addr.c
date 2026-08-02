/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inet_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 21:54:24 by cebouhad          #+#    #+#             */
/*   Updated: 2026/08/02 10:16:17 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"


static in_addr_t get_ipv4_addr(char *addr_str)
{
	int		    len;
	char	    **split;
    in_addr_t   addr;
    
	/* split the ip string with the dot delimiter*/
	split = ft_split(addr_str, '.');
	if (!split)
	{
		write(STDERR_FILENO, "Split creation error\n", ft_strlen("Split creation error\n"));
		return (-1);
	}
	/* check the forma of every split part */
	len = ipv4_value_check(split);
	/* if the split index max != 3 --> return err */
	if (len != 3)
	{
		write(STDERR_FILENO, "Wrong format address\n", ft_strlen("Wrong format address\n"));
		ft_split_clean(&split);
		return (-1);
	}
    addr = 0;
	while (len >= 0)
	{
		//printf("addr: %d split: %d\n",addr->s_addr , ft_atoi(split[len]));
		//ft_print_bit_8(ft_atoi(split[len]));
		/*
			every split converted in uint8 as a 8 bit value between 0 and 256.
			every 8bit value in injected in uint32 starting by the last element of the split.
			Exemple: 192.168.0.10 is processed in this order 10 --> 0 --> 168 --> 192.
			We are using the operator | who compare the firt 8 bit of the uint32 and uint8 and active the 1 bit of th uint8 value in the uint32 value.
			Exemple : s_addr = 00000000 00000000 00000000 00000000 and ft_atoi(split[len]) = 00001010
			00000000 00000000 00000000 00000000 |= 00001010 -> 00000000 00000000 00000000 00001010
			after the injection we can decale bit from 8 to the left
			exemple 00000000 00000000 00000000 00001010 << 8 = 00000000 00000000 00001010 00000000  
		*/
		addr |= ft_atoi(split[len--]);
		//ft_print_bit_32(addr->s_addr);
		if (len >= 0)
			addr = addr << 8;
	}
	ft_split_clean(&split);
	return (addr);
}

/*
	convert ip string format to an uint32 value;
*/
in_addr_t ft_inet_addr(char *addr_str)
{
	/* convert ipv4 to uint32*/
	return (get_ipv4_addr(addr_str));
}