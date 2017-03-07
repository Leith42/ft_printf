/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:43:44 by aazri             #+#    #+#             */
/*   Updated: 2017/03/07 13:13:13 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t adapt_width(t_flags *flags, char *sign, size_t precision, uintmax_t nb, size_t *nb_len)
{
	size_t width;

	width = flags->width;
	width -= precision;
	width -= ft_strlen(sign);
	if (nb == 0 && precision == 0)
	{
		*nb_len = 0;
	}
	return (width);
}

size_t adapt_precision(t_flags *flags, size_t nb_len)
{
	size_t precision;

	precision = flags->precision;
	if (precision > nb_len)
	{
		precision -= nb_len;
	}
	else
	{
		precision = 0;
	}
	return (precision);
}

void double_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	size_t width;
	size_t precision;

	if (flags->width > flags->precision)
	{
		precision = adapt_precision(flags, nb_len);
		width = adapt_width(flags, sign, precision, nb, &nb_len);
		if (flags->right_pad == FALSE)
		{
			width_pad(nb_len, width,  ' ', precision ? NULL : sign);
			width_pad(0, precision, '0', sign);
			if (precision != 0 || nb != 0)
				print_base(nb, base);
		}
		else if (flags->right_pad == TRUE)
		{
			width_pad(0, precision, '0', sign);
			print_base(nb, base);
			width_pad(nb_len, width, ' ', 0);
		}
	}
	else
	{
		width_pad(nb_len, flags->precision, '0', sign);
		print_base(nb, base);
	}
}

void right_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	char pad_with;
	size_t sign_len;

	sign_len = ft_strlen(sign);
	pad_with = flags->pad_zeroes ? '0' : ' ';
	if (sign && (*sign == '-' || *sign == '0'))
	{
		ft_putstr(sign);
		print_base(nb, base);
		width_pad(nb_len, flags->width - sign_len, pad_with, 0);
	}
	else
	{
		print_base(nb, base);
		width_pad(nb_len, flags->width - sign_len, pad_with, sign);
	}
}

void simple_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base)
{
	char pad_with;
	size_t sign_len;

	pad_with = flags->pad_zeroes ? '0' : ' ';
	sign_len = ft_strlen(sign);
	if (flags->got_width == TRUE)
	{
		if (flags->right_pad == TRUE)
			right_pad(nb_len, flags, sign, nb, base);
		else if (flags->right_pad == FALSE)
		{
			width_pad(nb_len, flags->width - sign_len, pad_with, sign);
			print_base(nb, base);
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
			ft_putstr(sign);
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

size_t handle_integer(uintmax_t nb, t_flags *flags, unsigned int base, char *sign)
{
	size_t nb_len;
	size_t pad_len;

	nb_len = ft_nbulen(nb, base);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == TRUE && flags->got_width == FALSE)
	{
		flags->pad_zeroes = TRUE;
	}
	handle_pad(nb_len, flags, sign, nb, base);
	return (print_count(nb_len, pad_len, flags, sign, nb));
}

int	flag_D(t_format *format, va_list arguments, t_flags *flags)
{
	intmax_t integer;
	char *sign;

	if (format->string[format->pos] == 'D' && flags->length == none)
	{
		flags->length = l;
	}
	integer = signed_specifier(arguments, flags);
	sign = NULL;
	if (integer < 0 || flags->force_sign == TRUE || flags->blank_sign == TRUE)
	{
		if (integer >= 0 && flags->force_sign == TRUE)
			sign = "+";
		else if (integer < 0)
			sign = "-";
		else if (flags->blank_sign == TRUE)
			sign = " ";
	}
	format->written += handle_integer(ABS(integer), flags, 10, sign);
	format->pos++;
	return (OK);
}

int flag_U(t_format *format, va_list arguments, t_flags *flags)
{
	char specifier;
	uintmax_t u_integer;

	specifier = format->string[format->pos];
	u_integer = unsigned_specifier(arguments, flags, specifier);
	format->written += handle_integer(u_integer, flags, 10, NULL);
	format->pos++;
	return (OK);
}
