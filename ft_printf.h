/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:22:19 by leith             #+#    #+#             */
/*   Updated: 2017/02/01 18:06:27 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdio.h>

# define	OK		1
# define	TRUE	1
# define	FALSE	0
# define	ERROR	-1

typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
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
} 					t_arg;

typedef struct	s_format
{
	const char	*string;
	size_t		pos;
	size_t		written;
}				t_format;

typedef struct   s_func
{
	void (*ptrfunc)(t_format *, va_list);
	char key;
}               t_func;

int	ft_printf(const char * format, ...);
char *ft_itoa_base(long int nb, unsigned int base);
int	valid_format(t_format format, va_list arguments);

#endif
