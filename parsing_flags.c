/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:18:51 by aazri             #+#    #+#             */
/*   Updated: 2017/02/07 16:05:47 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_flags(t_format *format, va_list arguments, t_flags *flags)
{
	//format->pos++;
	ft_bzero(flags, sizeof(t_flags));
	if (format->string[format->pos] == '\0')
		return (0);
	if (parse_flags(format, flags) == '\0')
		return (ERROR);
	if (parse_width(format, arguments, flags) == '\0')
		return (ERROR);
	if (parse_precision(format, arguments, flags) == '\0')
		return (ERROR);
	if (parse_length(format, flags) == '\0')
		return (ERROR);
	if (format->string[format->pos] == '\0')
		return (0);
	return (OK);
}

char	parse_flags(t_format *f, t_flags *flags)
{
	if (f->string[f->pos] == '#' || f->string[f->pos] == '0'
	|| f->string[f->pos] == '-' || f->string[f->pos] == '+'
	|| f->string[f->pos] == ' ')
	{
		if (f->string[f->pos] == '#')
			flags->force_prefix = 1;
		else if (f->string[f->pos] == '0')
			flags->pad_zeroes = 1;
		else if (f->string[f->pos] == '-')
			flags->right_pad = 1;
		else if (f->string[f->pos] == '+')
			flags->force_sign = 1;
		else if (f->string[f->pos] == ' ')
			flags->blank_sign = 1;
		f->pos++;
		if (flags->right_pad)
			flags->pad_zeroes = 0;
		return (parse_flags(f, flags));
	}
	else
		return (f->string[f->pos]);
}

char	parse_width(t_format *f, va_list list, t_flags *flags)
{
	int	got;

	flags->width = 0;
	while (f->string[f->pos] == '*' || ft_isdigit(f->string[f->pos]))
	{
		if (f->string[f->pos] == '*')
		{
			f->pos++;
			got = va_arg(list, int);
			if (got < 0)
				flags->right_pad = 1;
			flags->width = got < 0 ? -got : got;
			flags->got_width = 1;
		}
		if (ft_isdigit(f->string[f->pos]))
		{
			flags->got_width = 1;
			flags->width = 0;
			while (ft_isdigit(f->string[f->pos]))
				flags->width = flags->width * 10 + (f->string[f->pos++] - '0');
		}
	}
	return (f->string[f->pos]);
}

char parse_precision(t_format *f, va_list list, t_flags *flags)
{
	int prec;

	if (f->string[f->pos] == '.')
	{
		f->pos++;
		if (f->string[f->pos] == '*')
		{
			f->pos++;
			if ((prec = va_arg(list, int)) >= 0)
			{
				flags->got_precision = 1;
				flags->precision = prec;
			}
			return (f->string[f->pos]);
		}
		else
		{
			while (ft_isdigit(f->string[f->pos]))
				flags->precision = flags->precision * 10 + (f->string[f->pos++] - '0');
			flags->got_precision = 1;
			return (f->string[f->pos]);
		}
	}
	else
		return (f->string[f->pos]);
}

char	parse_length(t_format *f, t_flags *flags)
{
	if (f->string[f->pos] == 'h' && f->string[f->pos + 1] == 'h')
	{
		flags->length = hh;
		f->pos =+ 2;
		return (f->string[f->pos]);
	}
	else if (f->string[f->pos] == 'l' && f->string[f->pos + 1] == 'l')
	{
		flags->length = ll;
		f->pos += 2;
		return (f->string[f->pos]);
	}
	else if (f->string[f->pos] == 'h' || f->string[f->pos] == 'l' ||
			f->string[f->pos] == 'j' || f->string[f->pos] == 'z')
	{
		if (f->string[f->pos] == 'h')
			flags->length = h;
		else if (f->string[f->pos] == 'l')
			flags->length = l;
		else if (f->string[f->pos] == 'j')
			flags->length = j;
		else if (f->string[f->pos] == 'z')
			flags->length = z;
		f->pos++;
		return (f->string[f->pos]);
	}
	else
		return (f->string[f->pos]);
}
