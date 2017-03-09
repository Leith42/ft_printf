/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_pad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:53:29 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:04:52 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void right_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	size_t width;
	size_t precision;

	precision = adapt_precision(flags, nb_len);
	width = adapt_width(flags, sign, precision, nb, &nb_len);
	width_pad(0, precision, '0', sign);
	print_base(nb, base);
	width_pad(nb_len, width, ' ', 0);
}

static void left_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	unsigned int width;
	unsigned int precision;
	unsigned int sign_len;
	char pad_with;

	if (flags->got_precision == TRUE && flags->got_width == TRUE)
	{
		precision = adapt_precision(flags, nb_len);
		width = adapt_width(flags, sign, precision, nb, &nb_len);
		width_pad(nb_len, width,  ' ', precision ? NULL : sign);
		width_pad(0, precision, '0', sign);
		if (precision != 0 || nb != 0)
		{
			print_base(nb, base);
		}
	}
	else
	{
		sign_len = ft_strlen(sign);
		pad_with = flags->pad_zeroes ? '0' : ' ';
		width_pad(nb_len, flags->width - sign_len, pad_with, sign);
		print_base(nb, base);
	}
}

static void double_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	if (flags->width > flags->precision)
	{
		if (flags->right_pad == TRUE)
		{
			right_pad(nb_len, flags, sign, nb, base);
		}
		else
		{
			left_pad(nb_len, flags, sign, nb, base);
		}
	}
	else
	{
		width_pad(nb_len, flags->precision, '0', sign);
		print_base(nb, base);
	}
}

static void simple_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	if (flags->got_width == TRUE)
	{
		if (flags->right_pad == TRUE)
		{
			right_pad(nb_len, flags, sign, nb, base);
		}
		else
		{
			left_pad(nb_len, flags, sign, nb, base);
		}
	}
	else if (flags->got_precision == TRUE)
	{
		if (nb != 0)
		{
			width_pad(nb_len, flags->precision, '0', sign);
			print_base(nb, base);
		}
		else if (base == 8 && sign)
		{
			ft_putstr(sign);
		}
	}
}

void handle_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	if (flags->got_width && flags->got_precision)
	{
		double_pad(nb_len, flags, sign, nb, base);
	}
	else if (flags->got_width || flags->got_precision)
	{
		simple_pad(nb_len, flags, sign, nb, base);
	}
	else
	{
		if (sign)
		{
			ft_putstr(sign);
		}
		print_base(nb, base);
	}
}
