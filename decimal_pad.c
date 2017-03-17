/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_pad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:53:29 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:15:57 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	right_pad(size_t nb_len, t_flags *flags, uintmax_t nb)
{
	size_t width;
	size_t precision;

	precision = adapt_precision(flags, nb_len);
	width = adapt_width(flags, precision, nb, &nb_len);
	width_pad(0, precision, '0', flags->sign);
	print_base(nb, flags->base);
	width_pad(nb_len, width, ' ', 0);
}

static void	left_pad(size_t nb_len, t_flags *flags, uintmax_t nb)
{
	unsigned int	width;
	unsigned int	precision;
	unsigned int	sign_len;
	char			pad_with;

	if (flags->got_precision == TRUE && flags->got_width == TRUE)
	{
		precision = adapt_precision(flags, nb_len);
		width = adapt_width(flags, precision, nb, &nb_len);
		width_pad(nb_len, width, ' ', precision ? NULL : flags->sign);
		width_pad(0, precision, '0', precision ? flags->sign : NULL);
		if (precision != 0 || nb != 0)
		{
			print_base(nb, flags->base);
		}
	}
	else
	{
		sign_len = ft_strlen(flags->sign);
		pad_with = flags->pad_zeroes ? '0' : ' ';
		width_pad(nb_len, flags->width - sign_len, pad_with, flags->sign);
		print_base(nb, flags->base);
	}
}

static void	double_pad(size_t nb_len, t_flags *flags, uintmax_t nb)
{
	if (flags->width > flags->precision)
	{
		if (flags->right_pad == TRUE)
		{
			right_pad(nb_len, flags, nb);
		}
		else
		{
			left_pad(nb_len, flags, nb);
		}
	}
	else
	{
		width_pad(nb_len, flags->precision, '0', flags->sign);
		print_base(nb, flags->base);
	}
}

static void	simple_pad(size_t nb_len, t_flags *flags, uintmax_t nb)
{
	if (flags->got_width == TRUE)
	{
		if (flags->right_pad == TRUE)
		{
			right_pad(nb_len, flags, nb);
		}
		else
		{
			left_pad(nb_len, flags, nb);
		}
	}
	else if (flags->got_precision == TRUE)
	{
		if (nb != 0)
		{
			width_pad(nb_len, flags->precision, '0', flags->sign);
			print_base(nb, flags->base);
		}
		else if (flags->base == BASE_OCTAL && flags->sign)
		{
			ft_putstr(flags->sign);
		}
	}
}

void		handle_pad(size_t nb_len, t_flags *flags, uintmax_t nb)
{
	if (flags->got_width && flags->got_precision)
	{
		double_pad(nb_len, flags, nb);
	}
	else if (flags->got_width || flags->got_precision)
	{
		simple_pad(nb_len, flags, nb);
	}
	else
	{
		if ((flags->base == BASE_DECIMAL) || (flags->base == BASE_OCTAL && nb))
		{
			ft_putstr(flags->sign);
		}
		print_base(nb, flags->base);
	}
}
