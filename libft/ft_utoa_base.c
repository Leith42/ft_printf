/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:30:17 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 13:07:22 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(uintmax_t n, unsigned int base)
{
	char nb[12];
	uintmax_t tmp;
	size_t i;

	i = 12;
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
	return (ft_strndup(nb + i, 12 - i));
}
