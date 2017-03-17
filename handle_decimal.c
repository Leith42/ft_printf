/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:43:44 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:03:07 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned		adapt_width(t_flags *f, size_t preci, uintmax_t n, size_t *nlen)
{
	unsigned int width;

	width = f->width;
	width -= preci;
	width -= ft_strlen(f->sign);
	if (n == 0 && f->got_precision && preci == 0)
	{
		*nlen = 0;
	}
	return (width);
}

unsigned int	adapt_precision(t_flags *flags, size_t nb_len)
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

size_t			handle_integer(uintmax_t nb, t_flags *flags)
{
	size_t nb_len;
	size_t pad_len;

	nb_len = ft_nbulen(nb, flags->base);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->base == BASE_OCTAL && nb == 0 && flags->sign)
	{
		nb_len--;
	}
	if (flags->got_precision == TRUE && flags->got_width == FALSE)
	{
		flags->pad_zeroes = TRUE;
	}
	handle_pad(nb_len, flags, nb);
	return (print_count(nb_len, pad_len, flags, nb));
}

int				spec_d(t_format *format, va_list arguments, t_flags *flags)
{
	intmax_t	integer;

	if (format->string[format->pos] == 'D')
	{
		flags->length = l;
	}
	flags->base = BASE_DECIMAL;
	integer = signed_specifier(arguments, flags);
	if (integer < 0 || flags->force_sign == TRUE || flags->blank_sign == TRUE)
	{
		if (integer >= 0 && flags->force_sign == TRUE)
			flags->sign = "+";
		else if (integer < 0)
			flags->sign = "-";
		else if (flags->blank_sign == TRUE)
			flags->sign = " ";
	}
	format->written += handle_integer(ABS(integer), flags);
	format->pos++;
	return (OK);
}

int				spec_u(t_format *format, va_list arguments, t_flags *flags)
{
	char		specifier;
	uintmax_t	u_integer;

	specifier = format->string[format->pos];
	u_integer = unsigned_specifier(arguments, flags, specifier);
	flags->base = BASE_DECIMAL;
	format->written += handle_integer(u_integer, flags);
	format->pos++;
	return (OK);
}
