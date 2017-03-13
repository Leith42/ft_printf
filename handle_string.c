/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:07:14 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:17:40 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void handle_wstring(t_format *format, va_list arguments, t_flags *flags)
{
	wchar_t *wstring;
	size_t len;

	if ((wstring = va_arg(arguments, wchar_t *)) == NULL)
	{
		wstring = L"(null)";
	}
	len = ft_wstrlen(wstring);
	if (flags->got_precision == TRUE && flags->precision < len)
	{
		len = flags->precision;
	}
	if (flags->got_width == TRUE && flags->right_pad == FALSE)
	{
		width_pad(len, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
	}
	ft_putnwstr(wstring, len);
	if (flags->got_width == TRUE && flags->right_pad == TRUE)
	{
		width_pad(len, flags->width, ' ', 0);
	}
	format->written += MAX(flags->width, len);
	format->pos++;
}

int spec_s(t_format *format, va_list arguments, t_flags *flags)
{
	char specifier;
	char *s;
	size_t len;

	specifier = format->string[format->pos];
	if (flags->length == l || specifier == 'S')
	{
		handle_wstring(format, arguments, flags);
	}
	else
	{
		if ((s = va_arg(arguments, char *)) == NULL)
			s = "(null)";
		len = ft_strlen(s);
		if (flags->got_precision == TRUE && flags->precision < len)
			len = flags->precision;
		if (flags->got_width == TRUE && flags->right_pad == FALSE)
			width_pad(len, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
		ft_putnstr(s, len);
		if (flags->got_width == TRUE && flags->right_pad == TRUE)
			width_pad(len, flags->width, ' ', 0);
		format->written += MAX(flags->width, len);
		format->pos++;
	}
	return (OK);
}
