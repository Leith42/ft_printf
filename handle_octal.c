/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:52:32 by aazri             #+#    #+#             */
/*   Updated: 2017/03/06 13:19:56 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_o(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t octal;
	char *prefix;

	if (format->string[format->pos] == 'O' && flags->length == none)
		flags->length = l;
	octal = unsigned_specifier(arguments, flags, format->string[format->pos]);
	prefix = NULL;
	if (flags->force_prefix == TRUE)
	{
		prefix = "0";
	}
	else if (flags->blank_sign == TRUE)
	{
		prefix = " ";
	}
	format->written += handle_integer(octal, flags, 8, prefix);
	format->pos++;
}
