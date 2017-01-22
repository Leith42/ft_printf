/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:09:48 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:25:36 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = ptr;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (ptr);
}
