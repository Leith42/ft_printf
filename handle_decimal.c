/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:43:44 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:29:18 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned adapt_width(t_flags *flags, char *sign, size_t precision, uintmax_t nb, size_t *nb_len)
{
	unsigned int width;

	width = flags->width;
	width -= precision;
	width -= ft_strlen(sign);
	if (nb == 0 && precision == 0)
	{
		*nb_len = 0;
	}
	return (width);
}

unsigned int adapt_precision(t_flags *flags, size_t nb_len)
{
	unsigned int precision;

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

int	spec_D(t_format *format, va_list arguments, t_flags *flags)
{
	intmax_t integer;
	char *sign;

	if (format->string[format->pos] == 'D')
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

int spec_U(t_format *format, va_list arguments, t_flags *flags)
{
	char specifier;
	uintmax_t u_integer;

	specifier = format->string[format->pos];
	u_integer = unsigned_specifier(arguments, flags, specifier);
	format->written += handle_integer(u_integer, flags, 10, NULL);
	format->pos++;
	return (OK);
}
