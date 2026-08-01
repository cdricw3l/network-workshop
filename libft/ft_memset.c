/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:13:14 by cbouhadr          #+#    #+#             */
/*   Updated: 2026/08/01 20:59:49 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && len == 0)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)dst)[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
