/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:51:24 by aazri             #+#    #+#             */
/*   Updated: 2017/03/20 18:18:11 by aazri            ###   ########.fr       */
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
	if (flags->got_width == true && flags->got_precision == true)
	{
		if (hex_double_pad(hex_len, flags, str) == ERROR)
			return (ERROR);
	}
	else if (flags->got_width == true || flags->got_precision == true)
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
	return (true);
}

static size_t	handle_hex(char *hex, t_flags *flags, char spec)
{
	size_t pad_len;
	size_t hex_len;

	hex_len = ft_strlen(hex);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == true && flags->got_width == false)
	{
		flags->pad_zeroes = true;
	}
	if (hex_handle_pad(flags, spec, hex) == ERROR)
		return (ERROR);
	return (print_count(hex_len, pad_len, flags, 0));
}

static char		*assign_prefix(char specifier, t_flags *flags, uintmax_t u_hex)
{
	if ((flags->force_prefix == true) || specifier == 'p')
	{
		if ((specifier == 'x' && u_hex != 0) || (specifier == 'p'))
			return ("0x");
		else if (specifier == 'X' && u_hex != 0)
			return ("0X");
	}
	return (NULL);
}

int				spec_x(t_format *format, va_list arguments, t_flags *flags)
{
	size_t		i;
	uintmax_t	u_hex;
	char		*str_hex;
	char		specifier;
	int			ret;

	i = 0;
	u_hex = unsigned_specifier(arguments, flags, format->string[format->pos]);
	flags->base = BASE_HEXADECIMAL;
	if ((str_hex = ft_utoa_base(u_hex, BASE_HEXADECIMAL)) == NULL)
		return (ERROR);
	while (str_hex[i])
	{
		if (!(ft_isdigit(str_hex[i])))
			str_hex[i] += 7;
		i++;
	}
	specifier = format->string[format->pos];
	flags->sign = assign_prefix(specifier, flags, u_hex);
	ret = handle_hex(str_hex, flags, specifier);
	free(str_hex);
	format->written += ret;
	format->pos++;
	return (ret == ERROR ? ERROR : OK);
}

int				spec_p(t_format *format, va_list arguments, t_flags *flags)
{
	flags->length = z;
	return (spec_x(format, arguments, flags));
}
