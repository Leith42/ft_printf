/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_characters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:03:50 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 16:04:09 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		width_pad(len, flags->width, flags->pad_zeroes ? '0' : ' ');
	ft_putnstr(s, len);
	if (flags->got_width && flags->right_pad == TRUE)
		width_pad(len, flags->width, ' ');
	format->written += MAX(flags->width, len);
	format->pos++;
}

void flag_c(t_format *format, va_list arguments, t_flags *flags)
{
	// length == l
	// appel fonction wchar
	if (flags->got_width && flags->right_pad == FALSE)
		width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ');
	ft_putchar(va_arg(arguments, int));
	if (flags->got_width && flags->right_pad == TRUE)
		width_pad(1, flags->width, ' ');
	format->pos++;
	format->written += flags->got_width ? flags->width : sizeof(char);
}
