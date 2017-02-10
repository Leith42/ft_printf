/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:26:24 by leith             #+#    #+#             */
/*   Updated: 2017/02/09 18:30:49 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int a,b = 0;
	intmax_t c = -5000;

	a = printf("%ld\n", c);
	b = ft_printf("%+d\n", -1);
	printf("\n%d, %d\n", a, b);
	return 0;
}

void flag_s(t_format *format, va_list arguments, t_flags *flags)
{
	char *s;
	size_t len;

	// length == l
	// appel fonction wchar *
	if((s = va_arg(arguments, char *)) == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->got_precision && flags->precision < len)
		len = flags->precision;
	if (flags->got_width && flags->right_pad == FALSE)
		width_pad(len, flags->width, flags->pad_zeroes ? '0' : ' ');
	ft_putnstr(s, len);
	if (flags->got_width && flags->right_pad == TRUE)
		width_pad(len, flags->width, ' ');
	format->written += flags->width > len ? flags->width : len;
	format->pos++;
}

void flag_c(t_format *format, va_list arguments, t_flags *flags)
{
	// length == l
	// appel fonction wchar
	if (flags->got_width && flags->right_pad == FALSE)
		width_pad(1, flags->width, flags->pad_zeroes ? '0' : ' ');
	ft_putchar(va_arg(arguments, int));
	if (flags->got_width && flags->right_pad == TRUE)
		width_pad(1, flags->width, ' ');
	format->pos++;
	format->written += flags->got_width ? flags->width : sizeof(char);
}

void flag_U(t_format *format, va_list arguments, t_flags *flags)
{
	unsigned long i;

	i = va_arg(arguments, unsigned long);
	ft_putulnbr(i);
	format->pos++;
	format->written += ft_nbulen(i, 10);
}

void flag_x(t_format *format, va_list arguments, t_flags *flags)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, unsigned int), 16);
	ft_putstr(ft_strtolower(str));
	format->pos++;
	format->written += ft_strlen(str);
}

void flag_X(t_format *format, va_list arguments, t_flags *flags)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, unsigned int), 16);
	ft_putstr(str);
	format->pos++;
	format->written += ft_strlen(str);
}

void flag_p(t_format *format, va_list arguments, t_flags *flags)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, long), 16);
	ft_putstr("0x");
	ft_putstr(ft_strtolower(str));
	format->pos++;
	format->written += ft_strlen(str) + 2;
}

void flag_O(t_format *format, va_list arguments, t_flags *flags)
{
	char *str;

	str = ft_ltoa_base(va_arg (arguments, long), 8);
	ft_putstr(ft_strtolower(str));
	format->pos++;
	format->written += ft_strlen(str);
}

static void handle_conversion(t_format *format, va_list arguments, t_flags *flags)
{
	size_t  i = 0;
	t_func f_tab[] =
	{
		{&flag_c, 'c'},
		{&flag_s, 's'},
		{&flag_D, 'i'},
		{&flag_D, 'd'},
		{&flag_D, 'D'},
		{&flag_U, 'u'},
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
		if (f_tab[i].key == format->string[format->pos])
			f_tab[i].ptrfunc(format, arguments, flags);
		i++;
	}
}

static void browser(t_format *format, va_list arguments, t_flags *flags)
{
	while (format->string[format->pos])
	{
		if (format->string[format->pos] == '%')
		{
			format->pos++;
			if (format->string[format->pos] != '%')
			{
				handle_flags(format, arguments, flags);
				handle_conversion(format, arguments, flags);
			}
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

void puts_stuff(va_list args, t_format format, t_flags flags)
{
	printf("\nforce prefix : %d\npad zeroes : %d\nright pad : %d\nforce_sign : %d\nblank sign : %d\ngot width : %d\ngot precision : %d\nlength : %d\nwidth : %u\nprecision : %u\n",
	flags.force_prefix, flags.pad_zeroes, flags.right_pad, flags.force_sign, flags.blank_sign, flags.got_width, flags.got_precision, flags.length, flags.width, flags.precision);
}

int	ft_printf(const char *string, ...)
{
	va_list		arguments;
	t_format	format;
	t_flags		flags;

	ft_bzero(&format, sizeof(format));
	format.string = string;
	va_start (arguments, string);
	browser(&format, arguments, &flags);
	va_end(arguments);
	puts_stuff(arguments, format, flags);
	return(format.written);
}
