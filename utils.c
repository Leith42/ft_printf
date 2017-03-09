/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:07:34 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:23:29 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *base_convert(uintmax_t nb, unsigned int base)
{
	static const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char buffer[12];
	char *sortie;
	size_t i;

	sortie = NULL;
	i = 12;
	if(base < 2 || base > 36)
		return (NULL);
	buffer[--i] = '\0';
	do
	{
		buffer[--i] = digits[ nb%base ];
		nb /= base;
	}
	while(nb!=0);
	sortie = ft_strdup(buffer + i);
	return (sortie);
}

void width_pad(int nb_len, int width, char padwith, char *sign)
{
	if (sign && padwith == '0')
	{
		ft_putstr(sign);
	}
	while (nb_len < width)
	{
		ft_putchar(padwith);
		nb_len++;
	}
	if (sign && padwith != '0')
	{
		ft_putstr(sign);
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
	{
		ft_putchar(nb + '0');
	}
}

size_t	ft_nblen(intmax_t n, unsigned int base)
{
	char *str;
	size_t len;

	if ((str = ft_itoa_base(n, base)) == NULL)
		return (ERROR);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	ft_nbulen(uintmax_t n, unsigned int base)
{
	char *str;
	size_t len;

	if ((str = base_convert(n, base)) == NULL)
		return (ERROR);
	len = ft_strlen(str);
	free(str);
	return (len);
}
