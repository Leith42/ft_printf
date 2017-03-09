/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:22:19 by leith             #+#    #+#             */
/*   Updated: 2017/03/09 16:54:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ABS(x) ((x < 0)) ? -(x) : (x)
# define MIN(x, y) ((x < y)) ? (x) : (y)
# define MAX(x, y) ((x > y)) ? (x) : (y)

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"

# define	FALSE	0
# define	TRUE	!FALSE
# define	OK		TRUE
# define	ERROR	-1

/** STRUCT **/
typedef struct		s_flags
{
	bool			force_prefix;
	bool			pad_zeroes;
	bool			right_pad;
	bool			force_sign;
	bool			blank_sign;
	bool			got_width;
	bool			got_precision;
	unsigned int	width;
	unsigned int	precision;
	enum { none, hh, h, l, ll, j, z } length;
} 					t_flags;

typedef struct	s_format
{
	const char	*string;
	size_t		pos;
	size_t		written;
}				t_format;

typedef struct   s_func
{
	int (*ptrfunc)(t_format *, va_list, t_flags *);
	char key;
}               t_func;

/** Obviously **/
int	ft_printf(const char * format, ...);

/** Handle errors **/
int	valid_format(t_format format);

/** Parsing **/
int		handle_flags(t_format *format, va_list arguments, t_flags *flags);
void	parse_flags(t_format *s, t_flags *flags);
void	parse_width(t_format *f, va_list list, t_flags *flags);
void	parse_precision(t_format *f, va_list list, t_flags *flags);
void	parse_length(t_format *f, t_flags *flags);

/** Utils **/
void width_pad(int nb_len, int width, char padwith, char *sign);
size_t	ft_nbulen(unsigned long n, unsigned int base);
size_t	ft_nblen(long n, unsigned int base);
void	ft_putnstr(char *s, size_t max);
void	print_base(uintmax_t nb, unsigned int base);
unsigned int adapt_width(t_flags *flags, char *sign, size_t precision, uintmax_t nb, size_t *nb_len);
unsigned int adapt_precision(t_flags *flags, size_t nb_len);
int print_count(size_t nb_len, size_t pad_len, t_flags *flags, char *prefix, uintmax_t nb);
char *base_convert(uintmax_t nb, unsigned int base);
char *get_str_to_print(char *hex, char specifier);

/** Handle specifier **/
int spec_D(t_format *format, va_list arguments, t_flags *flags);
int spec_U(t_format *format, va_list arguments, t_flags *flags);
int spec_o(t_format *format, va_list arguments, t_flags *flags);
int spec_O(t_format *format, va_list arguments, t_flags *flags);
int spec_X(t_format *format, va_list arguments, t_flags *flags);
int spec_c(t_format *format, va_list arguments, t_flags *flags);
int spec_s(t_format *format, va_list arguments, t_flags *flags);
int spec_p(t_format *format, va_list arguments, t_flags *flags);

/** Handle base 10 & base 8 integer **/
size_t handle_integer(uintmax_t nb, t_flags *flags, unsigned int base, char *sign);
void handle_pad(size_t nb_len, t_flags *flags, char *sign, uintmax_t nb, int base);

/** Handle base 16 integer **/
int hex_handle_pad(t_flags *flags, char *prefix, char specifier, char *hex);

/** Handle length **/
intmax_t signed_specifier(va_list arguments, t_flags *flags);
uintmax_t unsigned_specifier(va_list arguments, t_flags *flags, char spec);

/** Get an array of functions **/
t_func	*get_func_array(void);

/** Utils for wide characters **/
void ft_putwchar(wint_t wchar);
void ft_putnwstr(wchar_t *wstring, unsigned int max);
unsigned int wchar_len(wchar_t wchar);
size_t ft_wstrlen(wchar_t *wstring);

#endif
