/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:08:31 by aazri             #+#    #+#             */
/*   Updated: 2017/02/13 14:21:24 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t n, unsigned int base)
{
	char nb[12];
	intmax_t tmp;
	size_t i;

	i = 12;
	nb[0] = (n < 0) ? '-' : '+';
	if (n <= 0)
	{
		nb[--i] = '0' - (n % base);
		n /= -base;
	}
	while (n != 0)
	{
		tmp = n % base;
		if (tmp < 10)
			nb[--i] = '0' + tmp;
		else
			nb[--i] = '7' + tmp;
		n /= base;
	}
	if (nb[0] == '-')
		nb[--i] = '-';
	return (ft_strndup(nb + i, 12 - i));
}
