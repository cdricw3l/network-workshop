/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inet_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 21:56:50 by cebouhad          #+#    #+#             */
/*   Updated: 2026/08/01 21:57:50 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libip.h"

int	ipv4_value_check(char **str)
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
