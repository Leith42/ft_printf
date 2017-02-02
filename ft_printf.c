/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:26:24 by leith             #+#    #+#             */
/*   Updated: 2017/02/01 17:13:55 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int main()
{
/*	int a,b;

	a = printf("%d%s yea yea as,dfa,%% %ld %d %x\n", 16185, "lololool", 89895615646, 5415815, 255954859);
	b = ft_printf("%d%s yea yea as,dfa,%% %D %d %x\n", 16185, "lololool", 89895615646, 5415815, 255954859);

	printf("\n%d, %d", a, b);*/
	int pd = -412945;
	printf("printf: %d\n", pd);
	//ft_printf("ft_printf : %o\n", pd);
	return 0;
}

size_t	ft_nblen(long n, unsigned int base)
{
	char *str;
	size_t len;

	str = ft_ltoa_base(n, base);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	ft_nbulen(unsigned long n, unsigned int base)
{
	char *str;
	size_t len;

	str = ft_utoa_base(n, base);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void	flag_d(t_format *format, va_list arguments)
{
	int d;

	d = va_arg(arguments, int);
	ft_putnbr(d);
	format->pos++;
	format->written += ft_nblen(d, 10);
}

void	flag_D(t_format *format, va_list arguments)
{
	long D;

	D = va_arg(arguments, long);
	ft_putlnbr(D);
	format->pos++;
	format->written += ft_nblen(D, 10);
}

void flag_s(t_format *format, va_list arguments)
{
	char *s;

	s = va_arg(arguments, char *);
	ft_putstr(s);
	format->pos++;
	format->written += ft_strlen(s);
}

void flag_c(t_format *format, va_list arguments)
{
	ft_putchar(va_arg(arguments, int));
	format->pos++;
	format->written++;
}

void flag_u(t_format *format, va_list arguments)
{
	unsigned int i;

	i = va_arg(arguments, unsigned int);
	ft_putlnbr(i);
	format->pos++;
	format->written += ft_nblen(i, 10);
}

void flag_U(t_format *format, va_list arguments)
{
	unsigned long i;

	i = va_arg(arguments, unsigned long);
	ft_putulnbr(i);
	format->pos++;
	format->written += ft_nbulen(i, 10);
}

void flag_x(t_format *format, va_list arguments)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, unsigned int), 16);
	ft_putstr(ft_strtolower(str));
	format->pos++;
	format->written += ft_strlen(str);
}

void flag_X(t_format *format, va_list arguments)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, unsigned int), 16);
	ft_putstr(str);
	format->pos++;
	format->written += ft_strlen(str);
}

void flag_p(t_format *format, va_list arguments)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, long), 16);
	ft_putstr("0x");
	ft_putstr(ft_strtolower(str));
	format->pos++;
	format->written += ft_strlen(str) + 2;
}

void flag_O(t_format *format, va_list arguments)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, long), 8);
	ft_putstr(ft_strtolower(str));
	format->pos++;
	format->written += ft_strlen(str);
}

static void manage_conversion(t_format *format, va_list arguments)
{
	size_t  i = 0;
	t_func f_tab[] =
	{
		{&flag_c, 'c'},
		{&flag_s, 's'},
		{&flag_d, 'i'},
		{&flag_d, 'd'},
		{&flag_D, 'D'},
		{&flag_u, 'u'},
		{&flag_U, 'U'},
		{&flag_x, 'x'},
		{&flag_X, 'X'},
		{&flag_p, 'p'},
		{&flag_O, 'o'},
		{&flag_O, 'O'},
		{NULL, -1}
	};

	while (f_tab[i].key != -1)
	{
		if (format->string[format->pos])

		if (f_tab[i].key == format->string[format->pos])
			f_tab[i].ptrfunc(format, arguments);
		i++;
	}
}

static void browser(t_format *format, va_list arguments)
{
	while (format->string[format->pos])
	{
		if (format->string[format->pos] == '%')
		{
			format->pos++;
			if (format->string[format->pos] != '%')
				manage_conversion(format, arguments);
			else
			{
				ft_putchar(format->string[format->pos++]);
				format->written++;
			}
		}
		else
		{
			ft_putchar(format->string[format->pos++]);
			format->written++;
		}
	}
}

int	ft_printf(const char *string, ...)
{
	va_list arguments;
	va_list args_cpy;
	t_format format;

	ft_bzero(&format, sizeof(format));
	format.string = string;
	va_start (arguments, string);
	va_copy (args_cpy, arguments);
	if (valid_format(format, args_cpy) == OK)
		browser(&format, arguments);
	va_end(arguments);
	return(format.written);
}
