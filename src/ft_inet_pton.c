/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inet_pton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:44:28 by cdric.b           #+#    #+#             */
/*   Updated: 2026/08/01 20:50:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

static int	ipv4_value_check(char **str)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			if (!ft_isdigit(str[i][j++]))
				return (0);
		value = ft_atoi(str[i++]);
		if (value > 255 || value < 0)
			return (0);
	}
	return (i - 1);
}

int	get_ipv4(char *addr_str, struct in_addr *addr)
{
	int		len;
	char	**split;

	/* split the ip string with the dot delimiter*/
	split = ft_split(addr_str, '.');
	if (!split)
	{
		write(STDERR_FILENO, "Split creation error\n", ft_strlen("Split creation error\n"));
		return (ERR);
	}
	/* check the forma of every split part */
	len = ipv4_value_check(split);
	/* if the split index max != 3 --> return err */
	if (len != 3)
	{
		write(STDERR_FILENO, "Wrong format address\n", ft_strlen("Wrong format address\n"));
		ft_split_clean(&split);
		return (ERR);
	}
	ft_bzero(addr, sizeof(struct in_addr));
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
		addr->s_addr |= ft_atoi(split[len--]);
		//ft_print_bit_32(addr->s_addr);
		if (len >= 0)
			addr->s_addr = addr->s_addr << 8;
	}
	ft_split_clean(&split);
	return (OK);
}

/*
	convert ip string format to an uint32 value;
*/
int	ft_inet_pton(int familly, char *addr_str, struct in_addr *addr)
{
	/* convert ipv4 to uint32*/
	if (familly == AF_INET)
		return (get_ipv4(addr_str, addr));
	return (OK);
}
