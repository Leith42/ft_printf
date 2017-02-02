/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:30:17 by aazri             #+#    #+#             */
/*   Updated: 2017/01/31 18:30:28 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_utoa_base(unsigned long n, unsigned int base)
{
	char			*p;
	unsigned int	x;
	int				i;

	i = 0;
	x = n;
	while (x >= 10)
	{
		x /= 10;
		i++;
	}
	if ((p = ft_strnew(i)))
	{
		while (i >= 0)
		{
			x = n % base;
			p[i] = '0' + x;
			n = n / base;
			i--;
		}
	}
	return (p);
}
