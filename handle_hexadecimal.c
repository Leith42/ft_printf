/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:51:24 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:45:56 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				hex_handle_pad(t_flags *flags, char spec, char *hex)
{
	char	*str;
	size_t	hex_len;

	if ((str = get_str_to_print(hex, spec)) == NULL)
		return (ERROR);
	hex_len = ft_strlen(str);
	if (flags->got_width && flags->got_precision)
	{
		if ((hex_double_pad(hex_len, flags, spec, hex)) == ERROR)
			return (ERROR);
	}
	else if (flags->got_width || flags->got_precision)
	{
		hex_simple_pad(hex_len, flags, hex);
	}
	else
	{
		if (flags->sign)
		{
			ft_putstr(flags->sign);
		}
		ft_putstr(str);
	}
	free(str);
	return (OK);
}

static size_t	handle_hex(char *hex, t_flags *flags, char spec)
{
	size_t pad_len;
	size_t hex_len;

	hex_len = ft_strlen(hex);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == TRUE && flags->got_width == FALSE)
	{
		flags->pad_zeroes = TRUE;
	}
	hex_handle_pad(flags, spec, hex);
	return (print_count(hex_len, pad_len, flags, 0));
}

static char		*assign_prefix(char specifier, t_flags *flags, uintmax_t u_hex)
{
	if ((flags->force_prefix == TRUE) || specifier == 'p')
	{
		if ((specifier == 'x' && u_hex != 0) || (specifier == 'p'))
		{
			return ("0x");
		}
		else if (specifier == 'X' && u_hex != 0)
		{
			return ("0X");
		}
	}
	return (NULL);
}

int				spec_x(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t	u_hex;
	char		*str_hex;
	char		specifier;
	int			ret;

	u_hex = unsigned_specifier(arguments, flags, format->string[format->pos]);
	flags->base = BASE_HEXADECIMAL;
	if ((str_hex = base_convert(u_hex, BASE_HEXADECIMAL)) == NULL)
		return (ERROR);
	specifier = format->string[format->pos];
	flags->sign = assign_prefix(specifier, flags, u_hex);
	ret = handle_hex(str_hex, flags, specifier);
	format->written += ret;
	format->pos++;
	free(str_hex);
	return (ret == ERROR ? ERROR : OK);
}

int				spec_p(t_format *format, va_list arguments, t_flags *flags)
{
	flags->length = z;
	return (spec_x(format, arguments, flags));
}
