/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:03:05 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:06:46 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_left_double_pad(size_t hex_len, t_flags *flags, char *h)
{
	bool zero;
	unsigned int precision;
	unsigned int width;

	zero = h[0] == 0x30 && h[1] == '\0' ? 0 : 1;
	precision = adapt_precision(flags, hex_len);
	width = adapt_width(flags, precision, zero, &hex_len);
	if (precision == 0 && zero == 0)
	{
		h = NULL;
		hex_len = 0;
	}
	width_pad(hex_len, width, ' ', flags->sign);
	width_pad(0, precision, '0', 0);
	ft_putstr(h);
}

static void	hex_right_pad(size_t hex_len, t_flags *flags, char *hex)
{
	char			pad_with;
	unsigned int	prefix_len;

	pad_with = flags->pad_zeroes ? '0' : ' ';
	prefix_len = ft_strlen(flags->sign);
	if (flags->sign)
	{
		ft_putstr(flags->sign);
	}
	ft_putstr(hex);
	width_pad(hex_len, flags->width - prefix_len, pad_with, 0);
}

int			hex_double_pad(size_t hex_len, t_flags *flags, char *to_print)
{
	if (flags->width > flags->precision)
	{
		if (flags->right_pad == true)
		{
			hex_right_pad(hex_len, flags, to_print);
		}
		else
		{
			hex_left_double_pad(hex_len, flags, to_print);
		}
	}
	else
	{
		width_pad(hex_len, flags->precision, '0', flags->sign);
		ft_putstr(to_print);
	}
	return (OK);
}

static void	hex_left_pad(size_t hex_len, t_flags *flags, char *hex)
{
	size_t prefix_len;

	prefix_len = ft_strlen(flags->sign);
	if (flags->pad_zeroes == true)
	{
		if (flags->sign)
		{
			ft_putstr(flags->sign);
		}
		width_pad(hex_len, flags->width - prefix_len, '0', 0);
		ft_putstr(hex);
	}
	else
	{
		width_pad(hex_len, flags->width - prefix_len, ' ', 0);
		if (flags->sign)
		{
			ft_putstr(flags->sign);
		}
		ft_putstr(hex);
	}
}

void		hex_simple_pad(size_t hex_len, t_flags *flags, char *hex)
{
	if (flags->got_width == true)
	{
		if (flags->right_pad == true)
		{
			hex_right_pad(hex_len, flags, hex);
		}
		else
		{
			hex_left_pad(hex_len, flags, hex);
		}
	}
	else if (flags->got_precision == true)
	{
		if (flags->sign)
		{
			ft_putstr(flags->sign);
		}
		width_pad(hex_len, flags->precision, '0', 0);
		if (flags->precision != 0)
		{
			ft_putstr(hex);
		}
	}
}
