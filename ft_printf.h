/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:22:19 by leith             #+#    #+#             */
/*   Updated: 2017/02/15 18:21:04 by aazri            ###   ########.fr       */
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
	void (*ptrfunc)(t_format *, va_list, t_flags *);
	char key;
}               t_func;

int	ft_printf(const char * format, ...);

int	valid_format(t_format format, va_list arguments);

int		handle_flags(t_format *format, va_list arguments, t_flags *flags);
char	parse_flags(t_format *s, t_flags *flags);
char	parse_width(t_format *f, va_list list, t_flags *flags);
char	parse_precision(t_format *f, va_list list, t_flags *flags);
char	parse_length(t_format *f, t_flags *flags);

size_t	ft_nbulen(unsigned long n, unsigned int base);
size_t	ft_nblen(long n, unsigned int base);
void	ft_putnstr(char *s, size_t max);
void	print_base(uintmax_t nb, unsigned int base);

void width_pad(int nb_len, int width, char padwith);
void flag_D(t_format *format, va_list arguments, t_flags *flags);
void flag_U(t_format *format, va_list arguments, t_flags *flags);
void flag_o(t_format *format, va_list arguments, t_flags *flags);
void flag_O(t_format *format, va_list arguments, t_flags *flags);
void flag_X(t_format *format, va_list arguments, t_flags *flags);
void flag_c(t_format *format, va_list arguments, t_flags *flags);
void flag_s(t_format *format, va_list arguments, t_flags *flags);
void flag_p(t_format *format, va_list arguments, t_flags *flags);

size_t handle_integer(uintmax_t nb, t_flags *flags, unsigned int base, char sign);

intmax_t signed_specifier(va_list arguments, t_flags *flags);
uintmax_t unsigned_specifier(va_list arguments, t_flags *flags);

t_func	*get_func_array(void);
#endif
