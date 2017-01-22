/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:27:54 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:24:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (s2 <= s1)
		while (n)
		{
			n--;
			((char *)s1)[n] = ((char *)s2)[n];
		}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
