/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:03:50 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:03:05 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_wchar(t_format *format, va_list arguments, t_flags *flags)
{
	wchar_t wchar;

	wchar = va_arg(arguments, wint_t);
	if (flags->got_width && flags->right_pad == false)
	{
		width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
	}
	ft_putwchar(wchar);
	if (flags->got_width && flags->right_pad == true)
	{
		width_pad(1, flags->width, ' ', 0);
	}
	format->written += MAX(flags->width, wchar_len(wchar));
}

int		spec_c(t_format *format, va_list arguments, t_flags *flags)
{
	char spec;

	spec = format->string[format->pos];
	if (flags->length == l || spec == 'C')
	{
		handle_wchar(format, arguments, flags);
	}
	else
	{
		if (flags->got_width && flags->right_pad == false)
		{
			width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
		}
		spec != 'c' ? ft_putchar(spec) : ft_putchar(va_arg(arguments, int));
		if (flags->got_width && flags->right_pad == true)
		{
			width_pad(1, flags->width, ' ', 0);
		}
		format->written += flags->got_width ? flags->width : sizeof(char);
	}
	format->pos++;
	return (OK);
}
