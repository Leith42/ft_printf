/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:23:14 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 15:23:23 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_count(size_t nb_len, size_t pad_len, t_flags *flags, char *prefix, uintmax_t nb)
{
	if (flags->got_width == TRUE || flags->got_precision == TRUE)
	{
		if (flags->width > 0 || flags->precision > 0)
		{
			if (pad_len == flags->precision && pad_len > nb_len)
			{
				return (pad_len + ft_strlen(prefix));
			}
			else if (pad_len == flags->width && pad_len > nb_len)
			{
				return (pad_len);
			}
		}
		else if (prefix && *prefix == '0')
		{
			return (pad_len + ft_strlen(prefix));
		}
		else
		{
			return (nb != 0 ? nb_len + ft_strlen(prefix) : 0);
		}
	}
	return (nb_len + ft_strlen(prefix));
}
