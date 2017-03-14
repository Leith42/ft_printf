/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:03:05 by aazri             #+#    #+#             */
/*   Updated: 2017/03/13 16:03:02 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void hex_left_double_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex, char *str)
{
	unsigned int precision;
	unsigned int width;

	precision = adapt_precision(flags, hex_len);
	width = adapt_width(flags, prefix, precision, ft_atoi(hex), &hex_len);
	if (precision == 0 && ft_atoi(hex) == 0)
	{
		hex_len = 0;
		str = NULL;
	}
	width_pad(hex_len, width, ' ', prefix);
	width_pad(0, precision, '0', 0);
	ft_putstr(str);
}

static void hex_right_pad(size_t hex_len, t_flags *flags, char *prefix, char *hex)
{
	char pad_with;
	unsigned int prefix_len;

	pad_with = flags->pad_zeroes ? '0' : ' ';
	prefix_len = ft_strlen(prefix);
	if (prefix)
	{
		ft_putstr(prefix);
	}
	ft_putstr(hex);
	width_pad(hex_len, flags->width - prefix_len, pad_with, 0);
}

static int hex_double_pad(size_t hex_len, t_flags *flags, char *prefix, char specifier, char *hex)
{
	char *str;

	if((str = get_str_to_print(hex, specifier)) == NULL)
	{
		return (ERROR);
	}
	if (flags->width > flags->precision)
	{
		if (flags->right_pad == TRUE)
		{
			hex_right_pad(hex_len, flags, prefix, hex);
		}
		else
		{
			hex_left_double_pad(hex_len, flags, prefix, hex, str);
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
		{
			ft_putstr(prefix);
		}
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
	else if (flags->got_precision == TRUE)
	{
		if (prefix)
		{
			ft_putstr(prefix);
		}
		width_pad(hex_len, flags->precision, '0', 0);
		if (flags->precision != 0)
		{
			ft_putstr(hex);
		}
	}
}

int hex_handle_pad(t_flags *flags, char *prefix, char specifier, char *hex)
{
	char *str;
	size_t hex_len;

	if((str = get_str_to_print(hex, specifier)) == NULL)
		return (ERROR);
	hex_len = ft_strlen(str);
	if (flags->got_width && flags->got_precision)
	{
		if((hex_double_pad(hex_len, flags, prefix, specifier, hex)) == ERROR)
			return (ERROR);
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
		ft_putstr(str);
	}
	free(str);
	return (OK);
}
