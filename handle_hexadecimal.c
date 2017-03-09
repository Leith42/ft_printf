/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:43:06 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:06:22 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t handle_hex(char *hex, t_flags *flags, char specifier, char *prefix)
{
	size_t pad_len;
	size_t hex_len;

	hex_len = ft_strlen(hex);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == TRUE && flags->got_width == FALSE)
	{
		flags->pad_zeroes = TRUE;
	}
	hex_handle_pad(flags, prefix, specifier, hex);
	return (print_count(hex_len, pad_len, flags, prefix, 0));
}

static char *assign_prefix(char specifier, t_flags *flags, uintmax_t u_hex)
{
	char *prefix;

	prefix = NULL;
	if ((flags->force_prefix == TRUE && u_hex != 0) || specifier == 'p')
	{
		if (specifier == 'x' || specifier == 'p')
		{
			prefix = "0x";
		}
		else if (specifier == 'X')
		{
			prefix = "0X";
		}
	}
	else if (flags->blank_sign == TRUE)
	{
		prefix = " ";
	}
	return (prefix);
}

int spec_X(t_format *format, va_list arguments, t_flags *flags)
{
	char *str_hex;
	char *prefix;
	char specifier;
	uintmax_t u_hex;
	int ret;

	u_hex = unsigned_specifier(arguments, flags, format->string[format->pos]);
	if((str_hex = base_convert(u_hex, 16)) == NULL)
		return (ERROR);
	specifier = format->string[format->pos];
	prefix = assign_prefix(specifier, flags, u_hex);
	ret = handle_hex(str_hex, flags, specifier, prefix);
	format->written += ret;
	format->pos++;
	free(str_hex);
	return (ret == ERROR ? ERROR : OK);
}

int spec_p(t_format *format, va_list arguments, t_flags *flags)
{
	flags->length = z;
	return(spec_X(format, arguments, flags));
}
