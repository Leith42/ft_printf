/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:26:24 by leith             #+#    #+#             */
/*   Updated: 2017/03/20 18:11:06 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(t_format *format, va_list args, t_flags *flags)
{
	char	spec;
	size_t	i;
	t_func	*f_tab;

	i = 0;
	if ((f_tab = get_func_array()) == NULL)
		return (ERROR);
	spec = format->string[format->pos];
	while (f_tab[i].key != ERROR)
	{
		if (f_tab[i].key == spec || ft_toupper(f_tab[i].key) == spec)
		{
			if ((f_tab[i].ptrfunc(format, args, flags) == ERROR))
			{
				free(f_tab);
				return (ERROR);
			}
			break;
		}
		i++;
	}
	if (f_tab[i].key == ERROR)
		f_tab[0].ptrfunc(format, args, flags);
	free(f_tab);
	return (OK);
}

static int	browser(t_format *format, va_list arguments, t_flags *flags)
{
	while (format->string[format->pos])
	{
		if (format->string[format->pos] == '%')
		{
			format->pos++;
			handle_flags(format, arguments, flags);
			if (format->string[format->pos] != '\0')
			{
				if ((handle_specifier(format, arguments, flags)) == ERROR)
					return (ERROR);
			}
		}
		else
		{
			ft_putchar(format->string[format->pos]);
			format->pos++;
			format->written++;
		}
	}
	return (OK);
}

int			ft_printf(const char *string, ...)
{
	va_list		arguments;
	t_format	format;
	t_flags		flags;

	ft_bzero(&format, sizeof(format));
	format.string = string;
	va_start(arguments, string);
	if (browser(&format, arguments, &flags) == ERROR)
	{
		format.written = ERROR;
	}
	va_end(arguments);
	return (format.written);
}
