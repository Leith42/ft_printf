/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:07:34 by aazri             #+#    #+#             */
/*   Updated: 2017/02/21 16:03:42 by aazri            ###   ########.fr       */
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

int print_count(size_t nb_len, size_t pad_len, t_flags *flags, char *prefix, uintmax_t nb)
{
	if (flags->got_width == TRUE || flags->got_precision == TRUE)
	{
		if (flags->width > 0 || flags->precision > 0)
		{
			if (pad_len == flags->precision && pad_len > nb_len)
			{
				return (pad_len + ft_strlen(prefix));
			}
			else if (pad_len == flags->width && pad_len > nb_len)
			{
				return (pad_len);
			}
		}
		else if (prefix && *prefix == '0')
		{
			return (pad_len + ft_strlen(prefix));
		}
		else
		{
			return (nb != 0 ? nb_len + ft_strlen(prefix) : 0);
		}
	}
	return (nb_len + ft_strlen(prefix));
}

void width_pad(int nb_len, int width, char padwith, char *sign)
{
	if (sign && padwith == '0')
		ft_putstr(sign);
	while (nb_len < width)
	{
		ft_putchar(padwith);
		nb_len++;
	}
	if (sign && padwith != '0')
		ft_putstr(sign);
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

	str = base_convert(n, base);
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
