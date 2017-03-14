/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:01:39 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 16:48:07 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void unknown_conversion (const char *ptr)
{
	if ((!(ft_isprint(*ptr))) || *ptr + 1 == ' ')
	{
		ft_putendl_fd("ft_printf: '%' must be followed by a conversion type character.", 2);
	}
	else
	{
		ft_putstr_fd("ft_printf: unknown conversion type character '%", 2);
		ft_putchar_fd(*ptr, 2);
		ft_putendl_fd("' in format.", 2);
	}
}

static const char *skip_flags(const char *ptr)
{
	while (*ptr == '+'
	|| *ptr == '-'
	|| *ptr == '#'
	|| *ptr == '.'
	|| *ptr == ' '
	|| *ptr == 'h'
	|| *ptr == 'l'
	|| *ptr == 'j'
	|| *ptr == 'z'
	|| *ptr == 't'
	|| ft_isdigit(*ptr))
	{
		ptr++;
	}
	return (ptr);
}

static int check_format(const char **ptr)
{
	int i;
	char *tab;

	i = 0;
	tab = "sSpdDioOuUxXcC%";
	*ptr = skip_flags(*ptr);
	while (tab[i])
	{
		if (tab[i] == **ptr)
		{
			return (OK);
		}
		i++;
	}
	return (ERROR);
}

int	valid_format(t_format format)
{
	const char *ptr;

	ptr = format.string;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		ptr++;
		if (check_format(&ptr) == ERROR)
		{
			unknown_conversion(ptr);
			return (ERROR);
		}
		if (*ptr == '%')
		{
			ptr++;
		}
	}
	return (OK);
}
