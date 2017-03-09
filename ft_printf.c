/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:26:24 by leith             #+#    #+#             */
/*   Updated: 2017/03/09 11:20:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stddef.h>
#include <limits.h>

/*int main()
{
	int a,b,i = 0;
	wint_t c = L'ย';
	wchar_t *str1 = L"ยՇ ςђคภﻮє Շђє ՇєאՇ, Շђєภ ς๏קץ Շђє ยภเς๏๔є คภ๔ קครՇє เՇ";
	wchar_t *str2 = L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	char *str3 = "Je suis une string tout a fait normale !";

	a =	ft_printf("%-10.5o", 2500);
	puts("");
	b =	printf("%-10.5o", 2500);
	puts("");
	printf("%d %d\n", a, b);
}*/

static int handle_specifier(t_format *format, va_list arguments, t_flags *flags)
{
	char spec;
	size_t i;
	t_func *f_tab;

	i = 0;
	spec = format->string[format->pos];
	if((spec == '\0') || (f_tab = get_func_array()) == NULL)
		return (ERROR);
	if (spec == '%')
		spec = 'c';
	while (f_tab[i].key != -1)
	{
		if (f_tab[i].key == spec || ft_toupper(f_tab[i].key) == spec)
		{
			if((f_tab[i].ptrfunc(format, arguments, flags) == ERROR))
				return (ERROR);
		}
		i++;
	}
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
			{
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

void puts_stuff(t_flags flags)
{
	printf("\nforce prefix : %d\npad zeroes : %d\nright pad : %d\nforce_sign : %d\nblank sign : %d\ngot width : %d\ngot precision : %d\nlength : %d\nwidth : %u\nprecision : %u\n\n",
	flags.force_prefix, flags.pad_zeroes, flags.right_pad, flags.force_sign, flags.blank_sign, flags.got_width, flags.got_precision, flags.length, flags.width, flags.precision);
}

int	ft_printf(const char *string, ...)
{
	va_list		arguments;
	t_format	format;
	t_flags		flags;

	setlocale (LC_ALL, "");
	ft_bzero(&format, sizeof(format));
	format.string = string;
	va_start(arguments, string);
//	va_copy(copy, arguments);
/*	if (valid_format(format) == ERROR)
	{
		return (ERROR);
	}*/
	browser(&format, arguments, &flags);
//	puts_stuff(flags);
	va_end(arguments);
	return(format.written);
}
