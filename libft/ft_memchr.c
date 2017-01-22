/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:07:18 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:21:45 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int tofind, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;
	size_t			i;

	i = 0;
	c = (unsigned char)tofind;
	ptr = (unsigned char *)str;
	while (n--)
	{
		if (ptr[i] == c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
