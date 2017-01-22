/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:40:41 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:36:11 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t num)
{
	size_t i;
	size_t b;

	i = 0;
	b = 0;
	while (dest[i])
		i++;
	while (src[b] && num--)
	{
		dest[i] = src[b];
		b++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
