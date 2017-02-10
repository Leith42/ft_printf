/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:43:44 by aazri             #+#    #+#             */
/*   Updated: 2017/02/09 18:46:46 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t type_modifier(va_list arguments, t_flags *flags)
{
	intmax_t nb;

	nb = va_arg(arguments, intmax_t);
	if (flags->length == hh)
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
	else
		nb = (int)nb;
	return (nb);
}

void force_prefix(uintmax_t nb, char *base, t_flags *flags, char *prefix)
{
	unsigned int nb_len;
	size_t nb_cut;

	nb_len = prefix ? ft_nblen(nb, 10) + ft_strlen(prefix) : ft_nblen(nb, 10);
	nb_cut = prefix ? ft_strlen(prefix) : 0;
	if (flags->got_width == TRUE && flags->right_pad == FALSE && flags->pad_zeroes == FALSE)
	{
		width_pad(nb_len, flags->width, ' ');
		if (flags->width - nb_len > 0)
			nb_cut = flags->width - nb_len;
		else
			nb_cut = 0;
		flags->got_width = 0;
	}
	else if (flags->got_width == TRUE)
		flags->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	//handle_uint()
}

void	flag_D(t_format *format, va_list arguments, t_flags *flags)
{
	intmax_t integer;
	char	*str;

	integer = type_modifier(arguments, flags);
	str = NULL;
	if (flags->force_sign == TRUE || flags->blank_sign == TRUE)
	{
		if (integer >= 0 && flags->force_sign == TRUE)
			str = "+";
		else if (integer <= 0 && flags->force_sign == TRUE)
			str = "-";
		else if (flags->blank_sign == TRUE)
			str = " ";
		force_prefix(integer, "0123456789", flags, str);
	}
	ft_putlnbr(integer);
	format->pos++;
	format->written += ft_nblen(integer, 10);
}

/*
void flag_D(t_format *format, va_list arguments, t_flags *flags)
{
	long nb;
	size_t len;

	nb = va_arg(arguments, long);
	len = ft_nblen(nb, 10);
//	flags->force_sign == TRUE ? len++ : 0;
	if (flags->got_precision && flags->precision > len)
		width_pad(len, flags->precision, '0');
	if (flags->got_width == TRUE && flags->right_pad == FALSE)
	{
		if (flags->force_sign == TRUE && flags->pad_zeroes == TRUE)
			ft_putchar('+');
		width_pad(len, flags->width, flags->pad_zeroes ? '0' : ' ');
		if (flags->force_sign == TRUE && flags->pad_zeroes == FALSE)
			ft_putchar('+');
		flags->force_sign = FALSE;
	}
	if (flags->force_sign == TRUE && nb >= 0)
		ft_putchar('+');
	printf("%ld", nb);
	if (flags->got_width && flags->right_pad == TRUE)
		width_pad(len, flags->width, ' ');
	if (flags->got_precision == TRUE && flags->precision > len)
		format->written += flags->precision;
	format->written += flags->force_sign ? ++len : len;
	format->pos++;
}*/
