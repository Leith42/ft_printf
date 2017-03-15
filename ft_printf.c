/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:26:24 by leith             #+#    #+#             */
/*   Updated: 2017/03/15 16:42:03 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stddef.h>
#include <limits.h>

/*int main()
{
	//setlocale(LC_ALL, "");
	int a,b,i = 0;
	wint_t c = L'ย';
	wchar_t *str1 = L"ยՇ ςђคภﻮє Շђє ՇєאՇ, Շђєภ ς๏קץ Շђє ยภเς๏๔є คภ๔ קครՇє เՇ";
	wchar_t *str2 = L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	char *str3 = "Je suis une string tout a fait normale !";

	a =	 printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	puts("");
	b =	 ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	puts("");
	printf("%d %d\n", a, b);
}*/

static int handle_specifier(t_format *format, va_list arguments, t_flags *flags)
{
	char spec;
	size_t i;
	t_func *f_tab;

	i = 0;
	if ((spec = format->string[format->pos]) == '\0')
		return (FALSE);
	if ((f_tab = get_func_array()) == NULL)
		return (ERROR);
	while (f_tab[i].key != -1 && spec != OK)
	{
		if (f_tab[i].key == spec || ft_toupper(f_tab[i].key) == spec)
		{
			spec = OK;
			if ((f_tab[i].ptrfunc(format, arguments, flags) == ERROR))
			{
				free(f_tab);
				return (ERROR);
			}
		}
		i++;
	}
	if (spec != OK)
		f_tab[0].ptrfunc(format, arguments, flags);
	free(f_tab);
	return (OK);
}

static int browser(t_format *format, va_list arguments, t_flags *flags)
{
	while (format->string[format->pos])
	{
		if (format->string[format->pos] == '%')
		{
			format->pos++;
			handle_flags(format, arguments, flags);
			if ((handle_specifier(format, arguments, flags)) == ERROR)
				return (ERROR);
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

int	ft_printf(const char *string, ...)
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
	return(format.written);
}
