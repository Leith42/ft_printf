/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:07:34 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 18:29:33 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void width_pad(int nb_len, int width, char padwith)
{
	while (nb_len < width)
	{
		ft_putchar(padwith);
		nb_len++;
	}
}

void	print_base(uintmax_t nb, unsigned int base)
{
	if (nb >= base)
	{
		print_base(nb / base, base);
		print_base(nb % base, base);
	}
	else
		ft_putchar(nb + '0');
}

size_t	ft_nblen(intmax_t n, unsigned int base)
{
	char *str;
	size_t len;

	str = ft_itoa_base(n, base);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	ft_nbulen(uintmax_t n, unsigned int base)
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
