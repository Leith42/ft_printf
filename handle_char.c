/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_characters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:03:50 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:16:39 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void handle_wchar(t_format *format, va_list arguments, t_flags *flags)
{
	wchar_t wchar;

	wchar = va_arg(arguments, wint_t);
	if (flags->got_width && flags->right_pad == FALSE)
	{
		width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
	}
	ft_putwchar(wchar);
	if (flags->got_width && flags->right_pad == TRUE)
	{
		width_pad(1, flags->width, ' ', 0);
	}
	format->written += MAX(flags->width, wchar_len(wchar));
}

int spec_c(t_format *format, va_list arguments, t_flags *flags)
{
	char specifier;

	specifier = format->string[format->pos];
	if (flags->length == l || specifier == 'C')
	{
		handle_wchar(format, arguments, flags);
	}
	else
	{
		if (flags->got_width && flags->right_pad == FALSE)
		{
			width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
		}
		specifier == '%' ? ft_putchar('%') : ft_putchar(va_arg(arguments, int));
		if (flags->got_width && flags->right_pad == TRUE)
		{
			width_pad(1, flags->width, ' ', 0);
		}
		format->written += flags->got_width ? flags->width : sizeof(char);
	}
	format->pos++;
	return (OK);
}
