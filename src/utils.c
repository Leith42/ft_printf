/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:07:34 by aazri             #+#    #+#             */
/*   Updated: 2017/03/20 19:23:40 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_pad(size_t nb_len, size_t width, char padwith, char *sign)
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
	char	*str;
	size_t	len;

	if ((str = ft_itoa_base(n, base)) == NULL)
		return (ERROR);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	ft_nbulen(uintmax_t n, unsigned int base)
{
	char	*str;
	size_t	len;

	if ((str = ft_utoa_base(n, base)) == NULL)
		return (ERROR);
	len = ft_strlen(str);
	free(str);
	return (len);
}
