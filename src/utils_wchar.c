/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:09:26 by aazri             #+#    #+#             */
/*   Updated: 2017/03/20 19:20:24 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 11000010 10101100
// 11000010 00000010
//
//
//

void			ft_putwchar(wint_t wchar)
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

void			ft_putnwstr(wchar_t *wstring, unsigned int max)
{
	unsigned int i;
	unsigned int wide_i;

	i = 0;
	wide_i = 0;
	while (wstring[i] && i < max && wide_i < max)
	{
		ft_putwchar(wstring[i]);
		wide_i += wchar_len(wstring[i]);
		i++;
	}
}

unsigned int	wchar_len(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0xFFFF)
		return (3);
	else if (wchar <= 0x10FFFF)
		return (4);
	return (0);
}

size_t			ft_wstrlen(wchar_t *wstring)
{
	size_t i;
	size_t wlen;

	i = 0;
	wlen = 0;
	while (wstring[i])
	{
		if (ft_isascii(wstring[i]) == true)
		{
			wlen++;
		}
		else
		{
			wlen += wchar_len(wstring[i]);
		}
		i++;
	}
	return (wlen);
}
