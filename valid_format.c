/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:01:39 by aazri             #+#    #+#             */
/*   Updated: 2017/03/06 10:17:25 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void error_with_conversion(char specifier)
{
	ft_putendl_fd("{ERROR with the conversion '", 2);
	ft_putchar_fd(specifier, 2);
	ft_putendl_fd("'}", 2);
}

void unknown_conversion (const char *ptr)
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

static int check_format(const char *ptr)
{
	int i;
	char *tab;

	i = 0;
	tab = "+-#. 0123456789sSpdDioOuUxXcChljzt%";
	while (tab[i])
	{
		if (*ptr == tab[i])
		{
			while (ft_isdigit(*ptr))
			{
				ptr++;
				if (ft_isalpha(*ptr) || *ptr == '%')
				{
					return (check_format(ptr));
				}
			}
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
		if (check_format(ptr) == ERROR)
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
