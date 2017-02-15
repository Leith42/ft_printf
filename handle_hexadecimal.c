/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:43:06 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 16:31:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t handle_hex(char *hex, t_flags *flags, char *prefix, char specifier)
{
	size_t hex_len;
	size_t pad_len;

	hex_len = prefix ? ft_strlen(hex) + ft_strlen(prefix) : ft_strlen(hex);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == TRUE)
		flags->pad_zeroes = TRUE;
	if ((flags->got_width || flags->got_precision) && flags->right_pad == FALSE)
		width_pad(hex_len, pad_len, flags->pad_zeroes ? '0' : ' ');
	if (specifier == 'x')
	{
		if (prefix)
			ft_putstr(prefix);
		ft_putstr(ft_strtolower(hex));
	}
	else if (specifier == 'X')
	{
		if (prefix)
			ft_putstr(prefix);
		ft_putstr(hex);
	}
	if ((flags->got_width || flags->got_precision) && flags->right_pad == TRUE)
		width_pad(hex_len, pad_len, flags->pad_zeroes ? '0' : ' ');
	return (MAX(hex_len, pad_len));
}

void flag_X(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t u_hex;
	char *prefix;
	char *str_hex;
	char specifier;

	u_hex = unsigned_specifier(arguments, flags);
	str_hex = ft_utoa_base(u_hex, 16);
	prefix = NULL;
	specifier = format->string[format->pos];
	if (flags->force_prefix == TRUE && u_hex != 0)
	{
		if (specifier == 'x')
			prefix = "0x";
		else if (specifier == 'X')
			prefix = "0X";
	}
	else if (flags->blank_sign == TRUE)
		prefix = " ";
	format->written += handle_hex(str_hex, flags, prefix, specifier);
	format->pos++;
	free(str_hex);
}

void flag_p(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t arg;
	char *adress;

	adress = "(null)";
	if((arg = va_arg(arguments, uintmax_t)))
	{
		adress = ft_utoa_base(arg, 16);
		format->written += handle_hex(adress, flags, "0x", 'x');
		format->pos++;
		free(adress);
	}
	else
	{
		ft_putstr(adress);
		format->written += ft_strlen(adress);
		format->pos++;
	}
}
