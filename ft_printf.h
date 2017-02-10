/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:22:19 by leith             #+#    #+#             */
/*   Updated: 2017/02/09 14:58:02 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"

# define	OK		1
# define	TRUE	1
# define	FALSE	0
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
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
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

void width_pad(int nbrstrlen, int width, char padwith);

void	flag_D(t_format *format, va_list arguments, t_flags *flags);
#endif
