/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:08:31 by aazri             #+#    #+#             */
/*   Updated: 2017/01/31 19:12:08 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long n, unsigned int base)
{
	char	nb[12];
	long tmp;
	size_t	i;

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
