/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:07:34 by aazri             #+#    #+#             */
/*   Updated: 2017/02/07 18:06:21 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nblen(long n, unsigned int base)
{
	char *str;
	size_t len;

	str = ft_ltoa_base(n, base);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	ft_nbulen(unsigned long n, unsigned int base)
{
	char *str;
	size_t len;

	str = ft_utoa_base(n, base);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void ft_putnstr(char *s, size_t max)
{
	size_t i;

	i = 0;
	while (s[i] && i < max)
	{
		ft_putchar(s[i]);
		i++;
	}
}
