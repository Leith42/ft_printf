/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:40:04 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:43:05 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>

typedef struct	s_flags
{
	bool		force_prefix;
	bool		pad_zeroes;
	bool		right_pad;
	bool		force_sign;
	bool		blank_sign;
	bool		got_width;
	bool		got_precision;
	unsigned	width;
	unsigned	precision;
	unsigned	base;
	char		*sign;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			length;
}				t_flags;

typedef struct	s_format
{
	const char	*string;
	size_t		pos;
	size_t		written;
}				t_format;

typedef struct	s_func
{
	int			(*ptrfunc)(t_format *, va_list, t_flags *);
	char		key;
}				t_func;

#endif
