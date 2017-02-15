/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:47:06 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 18:04:30 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t signed_specifier(va_list arguments, t_flags *flags)
{
	intmax_t nb;

	nb = va_arg(arguments, intmax_t);
	if (flags->length == none)
		nb = (int)nb;
	else if (flags->length == hh)
		nb = (char)nb;
	else if (flags->length == h)
		nb = (short int)nb;
	else if (flags->length == l)
		nb = (long int)nb;
	else if (flags->length == ll)
		nb = (long long int)nb;
	else if (flags->length == j)
		nb = (intmax_t)nb;
	else if (flags->length == z)
		nb = (size_t)nb;
	return (nb);
}

uintmax_t unsigned_specifier(va_list arguments, t_flags *flags)
{
	uintmax_t nb;

	nb = va_arg(arguments, uintmax_t);
	if (flags->length == none)
		nb = (unsigned int)nb;
	else if (flags->length == hh)
		nb = (unsigned char)nb;
	else if (flags->length == h)
		nb = (unsigned short int)nb;
	else if (flags->length == l)
		nb = (unsigned long int)nb;
	else if (flags->length == ll)
		nb = (unsigned long long int)nb;
	else if (flags->length == j)
		nb = (uintmax_t)nb;
	else if (flags->length == z)
		nb = (size_t)nb;
	return (nb);
}