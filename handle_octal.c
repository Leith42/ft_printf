/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:52:32 by aazri             #+#    #+#             */
/*   Updated: 2017/03/13 16:50:22 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *assign_prefix(t_flags *flags, uintmax_t octal)
{
	(void)octal;
	if (flags->force_prefix == TRUE)
	{
		return ("0");
	}
	return (NULL);
}

int spec_o(t_format *format, va_list arguments, t_flags *flags)
{
	uintmax_t octal;
	char *prefix;

	if (format->string[format->pos] == 'O')
	{
		flags->length = l;
	}
	octal = unsigned_specifier(arguments, flags, format->string[format->pos]);
	prefix = assign_prefix(flags, octal);
	format->written += handle_integer(octal, flags, 8, prefix);
	format->pos++;
	return (OK);
}
