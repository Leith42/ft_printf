/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:08:31 by aazri             #+#    #+#             */
/*   Updated: 2017/03/20 14:42:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t n, unsigned int base)
{
	char	buff[24];
	char	*str;
	int		i;
	intmax_t	n_tmp;

	i = 0;
	n_tmp = n;
	if (n < 0)
		n_tmp = -n;
	while (n_tmp)
	{
		buff[i++] = n_tmp % base + '0';
		n_tmp = n_tmp / base;
	}
	if (n < 0)
		buff[i++] = '-';
	if (!(str = ft_memalloc(i + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (--i >= 0)
		str[n_tmp++] = buff[i];
	return (str);
}
