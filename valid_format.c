/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:01:39 by aazri             #+#    #+#             */
/*   Updated: 2017/02/01 14:05:13 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if the conversions types are valid if not print and returns an error.
*/

#include "ft_printf.h"

static void handle_error (const char *ptr, va_list arguments)
{
	if ((!(ft_isprint(*ptr))) || *ptr == ' ')
		ft_putendl_fd("ft_printf: '%' must be followed by a conversion type character.", 2);
	else
	{
		ft_putstr_fd("ft_printf: unknown conversion type character '%", 2);
		ft_putchar_fd(*ptr, 2);
		ft_putendl_fd("' in format.", 2);
	}
	ft_putendl_fd("{ %d %i | Signed decimal integer }", 2);
	ft_putendl_fd("{ %D | Signed decimal long integer }", 2);
	ft_putendl_fd("{ %u | Unsigned decimal integer }", 2);
	ft_putendl_fd("{ %U | Unsigned decimal long integer }", 2);
	ft_putendl_fd("{ %c | Character }", 2);
	ft_putendl_fd("{ %C | Wide character }", 2);
	ft_putendl_fd("{ %s | String of characters }", 2);
	ft_putendl_fd("{ %S | String of wide characters }", 2);
	ft_putendl_fd("{ %x | Unsigned hexadecimal integer }", 2);
	ft_putendl_fd("{ %X | Unsigned hexadecimal integer (uppercase) }", 2);
	ft_putendl_fd("{ %o | Unsigned octal integer }", 2);
	ft_putendl_fd("{ %O | Unsigned octal long integer }", 2);
	ft_putendl_fd("{ %p | Pointer address }", 2);
}

static int check_format(const char *ptr)
{
	int i;
	char *tab;

	i = 0;
	tab = "+-# 0123456789sSpdDioOuUxXcC%";
	while (tab[i])
	{
		if (*ptr == tab[i])
		{
			while (ft_isdigit(*ptr))
			{
				ptr++;
				if (ft_isalpha(*ptr))
					return (check_format(ptr));
			}
			return (OK);
		}
		i++;
	}
	return (ERROR);
}

int	valid_format(t_format format, va_list arguments)
{
	const char *ptr;

	ptr = format.string;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		ptr++;
		if (check_format(ptr) == ERROR)
		{
			handle_error(ptr, arguments);
			return (ERROR);
		}
		*ptr == '%' ? ptr++ : ptr;
	}
	return (OK);
}
