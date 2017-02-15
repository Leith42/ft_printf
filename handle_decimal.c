/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:43:44 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 18:15:47 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t handle_integer(uintmax_t nb, t_flags *flags, unsigned int base, char sign)
{
	size_t nb_len;
	size_t pad_len;

	nb_len = sign ? ft_nbulen(nb, base) + 1 : ft_nbulen(nb, base);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == TRUE)
		flags->pad_zeroes = TRUE;
	if ((flags->got_width || flags->got_precision) && flags->right_pad == FALSE)
		width_pad(nb_len, pad_len, flags->pad_zeroes ? '0' : ' ');
	if (sign)
		ft_putchar(sign);
	print_base(nb, base);
	if ((flags->got_width || flags->got_precision) && flags->right_pad == TRUE)
		width_pad(nb_len, pad_len, flags->pad_zeroes ? '0' : ' ');
	return (MAX(nb_len, pad_len));
}

void	flag_D(t_format *format, va_list arguments, t_flags *flags)
{
	intmax_t integer;
	char sign;

	if (format->string[format->pos] == 'D' && flags->length == none)
		flags->length = l;
	integer = signed_specifier(arguments, flags);
	sign = '\0';
	if (integer < 0 || flags->force_sign == TRUE || flags->blank_sign == TRUE)
	{
		if (integer >= 0 && flags->force_sign == TRUE)
			sign = '+';
		else if (integer < 0)
			sign = '-';
		else if (flags->blank_sign == TRUE)
			sign = ' ';
	}
	format->written += handle_integer(ABS(integer), flags, 10, sign);
	format->pos++;
}

void flag_U(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t u_integer;
	char blank;

	u_integer = unsigned_specifier(arguments, flags);
	blank = '\0';
	if (flags->blank_sign == TRUE)
		blank = ' ';
	format->written += handle_integer(u_integer, flags, 10, blank);
	format->pos++;
}
