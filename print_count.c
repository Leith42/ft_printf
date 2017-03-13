/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:23:14 by aazri             #+#    #+#             */
/*   Updated: 2017/03/13 18:41:40 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hex_print_count(size_t nb_len, size_t pad_len, t_flags *flags, char *prefix)
{
	if (flags->got_width == TRUE || flags->got_precision == TRUE)
	{
		if (pad_len == flags->precision && pad_len > nb_len)
			return (pad_len + ft_strlen(prefix));
		else if (pad_len == flags->width && pad_len > nb_len)
		{
			return (pad_len);
		}
	}
	return (nb_len + ft_strlen(prefix));
}

int print_count(size_t nb_len, size_t pad_len, t_flags *flags, char *prefix, uintmax_t nb)
{
	if (flags->got_width == TRUE || flags->got_precision == TRUE)
	{
		if (flags->width > 0 || flags->precision > 0)
		{
			if (pad_len == flags->precision && pad_len > nb_len)
				return (pad_len + ft_strlen(prefix));
			else if (pad_len == flags->width && pad_len > nb_len)
			{
				if (prefix && *prefix == '0' && pad_len - 1 == nb_len)
					pad_len++;
				return (pad_len);
			}
		}
		else
		{
			if (prefix)
				return (nb ? nb_len + ft_strlen(prefix) : ft_strlen(prefix));
			return (nb ? nb_len : 0);
		}
	}
	return (nb_len + ft_strlen(prefix));
}
