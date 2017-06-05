/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:18:51 by aazri             #+#    #+#             */
/*   Updated: 2017/03/20 20:07:12 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags(t_format *format, va_list arguments, t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	parse_flags(format, flags);
	parse_width(format, arguments, flags);
	parse_precision(format, arguments, flags);
	parse_length(format, flags);
	return (OK);
}

void	parse_flags(t_format *f, t_flags *flags)
{
	if (f->string[f->pos] == '#' || f->string[f->pos] == '0'
	|| f->string[f->pos] == '-' || f->string[f->pos] == '+'
	|| f->string[f->pos] == ' ')
	{
		if (f->string[f->pos] == '#')
			flags->force_prefix = true;
		else if (f->string[f->pos] == '0')
			flags->pad_zeroes = true;
		else if (f->string[f->pos] == '-')
			flags->right_pad = true;
		else if (f->string[f->pos] == '+')
			flags->force_sign = true;
		else if (f->string[f->pos] == ' ')
			flags->blank_sign = true;
		f->pos++;
		if (flags->right_pad == true)
			flags->pad_zeroes = false;
		parse_flags(f, flags);
	}
}

void	parse_width(t_format *f, va_list list, t_flags *flags)
{
	int	width_from_arg;

	while (f->string[f->pos] == '*' || ft_isdigit(f->string[f->pos]))
	{
		if (f->string[f->pos] == '*')
		{
			f->pos++;
			if ((width_from_arg = va_arg(list, int)) >= 0)
			{
				flags->got_width = true;
				flags->width = width_from_arg;
			}
		}
		else
		{
			while (ft_isdigit(f->string[f->pos]))
			{
				flags->width = flags->width * 10 + (f->string[f->pos] - '0');
				f->pos++;
			}
			flags->got_width = true;
		}
	}
}

void	parse_precision(t_format *f, va_list list, t_flags *fl)
{
	int prec_from_arg;

	if (f->string[f->pos] == '.')
	{
		f->pos++;
		if (f->string[f->pos] == '*')
		{
			f->pos++;
			if ((prec_from_arg = va_arg(list, int)) >= 0)
			{
				fl->got_precision = true;
				fl->precision = prec_from_arg;
			}
		}
		else
		{
			while (ft_isdigit(f->string[f->pos]))
			{
				fl->precision = fl->precision * 10 + (f->string[f->pos] - '0');
				f->pos++;
			}
			fl->got_precision = true;
		}
	}
}

void	parse_length(t_format *f, t_flags *flags)
{
	if (f->string[f->pos] == 'h' && f->string[f->pos + 1] == 'h')
	{
		flags->length = hh;
		f->pos += 2;
	}
	else if (f->string[f->pos] == 'l' && f->string[f->pos + 1] == 'l')
	{
		flags->length = ll;
		f->pos += 2;
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
	}
	else
		flags->length = none;
}
