/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:43:06 by aazri             #+#    #+#             */
/*   Updated: 2017/03/06 11:19:58 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void hex_right_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex);
static void hex_left_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex);

static char *get_str_to_print(char *hex, char specifier)
{
	char *str;
	if(!(str = malloc(sizeof(char))))
		return (NULL);
	if (specifier == 'x')
	{
		if (!(str = ft_strjoin(str, ft_strtolower(hex))))
			return (NULL);
	}
	else if (specifier == 'X')
	{
		if (!(str = ft_strjoin(str, hex)))
		 return (NULL);
	}
	return (str);
}

static int hex_double_pad(size_t hex_len, t_flags *flags, char *prefix, char specifier, char *hex)
{
	size_t width;
	size_t precision;
	char *str;

	if(!(str = get_str_to_print(hex, specifier)))
		return (ERROR);
	if (flags->width > flags->precision)
	{
		precision = adapt_precision(flags, hex_len);
		width = adapt_width(flags, prefix, precision, ft_atoi(str), &hex_len);
		if (flags->right_pad == FALSE)
		{
			//hex_left_pad(hex_len, flags, prefix, hex);
			if (precision == 0 && ft_atoi(hex) == 0)
			{
				hex_len = 0;
				str = NULL;
			}
			width_pad(hex_len, width,  ' ', prefix);
			width_pad(0, precision, '0', 0);
			ft_putstr(str);
		}
		else if (flags->right_pad == TRUE)
		{
			hex_right_pad(hex_len, flags, prefix, hex);
		}
	}
	else
	{
		width_pad(hex_len, flags->precision, '0', prefix);
		ft_putstr(str);
	}
	free(str);
	return (OK);
}

static void hex_right_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex)
{
	char pad_with;
	size_t prefix_len;

	pad_with = flags->pad_zeroes ? '0' : ' ';
	prefix_len = ft_strlen(prefix);
	if (prefix)
	{
		ft_putstr(prefix);
	}
	ft_putstr(hex);
	width_pad(hex_len, flags->width - prefix_len, pad_with, 0);
}

static void hex_left_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex)
{
	size_t prefix_len;

	prefix_len = ft_strlen(prefix);
	if (flags->pad_zeroes == TRUE)
	{
		if (prefix)
		{
			ft_putstr(prefix);
		}
		width_pad(hex_len, flags->width - prefix_len, '0', 0);
		ft_putstr(hex);
	}
	else
	{
		width_pad(hex_len, flags->width - prefix_len, ' ', 0);
		if (prefix)
			ft_putstr(prefix);
		ft_putstr(hex);
	}
}

void hex_simple_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex)
{
	if (flags->got_width == TRUE)
	{
		if (flags->right_pad == TRUE)
		{
			hex_right_pad(hex_len, flags, prefix, hex);
		}
		else
		{
			hex_left_pad(hex_len, flags, prefix, hex);
		}
	}
	else if (flags->got_precision == TRUE && ft_atoi(hex) != 0)
	{
		if (prefix)
			ft_putstr(prefix);
		width_pad(hex_len, flags->precision, '0', 0);
		ft_putstr(hex);
	}
}

static int hex_handle_pad(size_t hex_len, t_flags *flags, char *prefix, char specifier, char *hex)
{
	char *str;

	if(!(str = get_str_to_print(hex, specifier)))
		return (ERROR);
	hex_len = ft_strlen(str);
	if (flags->got_width && flags->got_precision)
	{
		hex_double_pad(hex_len, flags, prefix, specifier, hex);
	}
	else if (flags->got_width || flags->got_precision)
	{
		hex_simple_pad(hex_len, flags, prefix, hex);
	}
	else
	{
		if (prefix)
		{
			ft_putstr(prefix);
		}
		ft_putstr(hex);
	}
	free(str);
	return (OK);
}

static size_t handle_hex(char *hex, t_flags *flags, char specifier, char *prefix)
{
	size_t hex_len;
	size_t pad_len;
	char *str;

	hex_len = ft_strlen(hex);
	pad_len = MAX(flags->width, flags->precision);
	if (flags->got_precision == TRUE && flags->got_width == FALSE)
		flags->pad_zeroes = TRUE;
	if (flags->got_width || flags->got_precision)
		hex_handle_pad(hex_len, flags, prefix, specifier, hex);
	else
	{
		if(!(str = get_str_to_print(hex, specifier)))
			return (ERROR);
		if (prefix)
			ft_putstr(prefix);
		ft_putstr(str);
		free(str);
	}
	return (print_count(hex_len, pad_len, flags, prefix, 0));
}

void flag_X(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t u_hex;
	char *prefix;
	char *str_hex;
	char specifier;

	u_hex = unsigned_specifier(arguments, flags, format->string[format->pos]);
	str_hex = base_convert(u_hex, 16);
	prefix = NULL;
	specifier = format->string[format->pos];
	if (flags->force_prefix == TRUE && u_hex != 0)
	{
		if (specifier == 'x' || specifier == 'p')
			prefix = "0x";
		else if (specifier == 'X')
			prefix = "0X";
	}
	else if (flags->blank_sign == TRUE)
		prefix = " ";
	format->written += handle_hex(str_hex, flags, specifier, prefix);
	format->pos++;
	free(str_hex);
}

void flag_p(t_format *format, va_list arguments, t_flags *flags)
{
	flag_X(format, arguments, flags);
}
