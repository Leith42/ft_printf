/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_characters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:03:50 by aazri             #+#    #+#             */
/*   Updated: 2017/03/03 18:22:20 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_percent(t_format *format, va_list arguments, t_flags *flags)
{
	(void)arguments;
	(void)flags;
	ft_putchar('%');
	format->written++;
	format->pos++;
}

void ft_putwchar(wchar_t wchar)
{
	if (wchar <= 0x7F)
	{
		ft_putchar(wchar);
	}
	else if (wchar <= 0x7FF)
	{
		ft_putchar((wchar >> 6) + 0xC0);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	else if (wchar <= 0xFFFF)
	{
		ft_putchar((wchar >> 12) + 0xE0);
		ft_putchar(((wchar >> 6) & 0x3F) + 0x80);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	else if (wchar <= 0x10FFFF)
	{
		ft_putchar((wchar >> 18) + 0xF0);
		ft_putchar(((wchar >> 12) & 0x3F) + 0x80);
		ft_putchar(((wchar >> 6) & 0x3F) + 0x80);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
}

unsigned int wchar_len(wchar_t wchar)
{
	if (wchar <= 0x7F)
	{
		return (1);
	}
	else if (wchar <= 0x7FF)
	{
		return (2);
	}
	else if (wchar <= 0xFFFF)
	{
		return (3);
	}
	else if (wchar <= 0x10FFFF)
	{
		return (4);
	}
	return (0);
}

void handle_wchar(t_format *format, va_list arguments, t_flags *flags)
{
	wchar_t wchar;

	wchar = va_arg(arguments, wchar_t);
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

void flag_s(t_format *format, va_list arguments, t_flags *flags)
{
	char *s;
	size_t len;

	// length == l
	// appel fonction wchar *
	if ((s = va_arg(arguments, char *)) == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->got_precision && flags->precision < len)
		len = flags->precision;
	if (flags->got_width && flags->right_pad == FALSE)
		width_pad(len, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
	ft_putnstr(s, len);
	if (flags->got_width && flags->right_pad == TRUE)
		width_pad(len, flags->width, ' ', 0);
	format->written += MAX(flags->width, len);
	format->pos++;
}

void flag_c(t_format *format, va_list arguments, t_flags *flags)
{
	if (flags->length == l)
	{
		handle_wchar(format, arguments, flags);
	}
	else
	{
		if (flags->got_width && flags->right_pad == FALSE)
		{
			width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ', 0);
		}
		ft_putchar(va_arg(arguments, int));
		if (flags->got_width && flags->right_pad == TRUE)
		{
			width_pad(1, flags->width, ' ', 0);
		}
		format->written += flags->got_width ? flags->width : sizeof(char);
	}
	format->pos++;
}
