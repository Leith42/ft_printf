/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:10 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 19:28:03 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	buff[12];
	char	*str;
	int		i;
	int		n_tmp;

	i = 0;
	n_tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n_tmp = -n;
	while (n_tmp)
	{
		buff[i++] = n_tmp % 10 + '0';
		n_tmp = n_tmp / 10;
	}
	if (n < 0)
		buff[i++] = '-';
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (--i >= 0)
		str[n_tmp++] = buff[i];
	return (str);
}
