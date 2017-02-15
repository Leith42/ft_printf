/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:40:44 by aazri             #+#    #+#             */
/*   Updated: 2017/02/15 18:18:52 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FUNC_NBR 9

t_func	*get_func_array(void)
{
	t_func *tab;

	if((tab = malloc(sizeof(t_func) * FUNC_NBR)) == NULL)
		return (NULL);
	tab[0].ptrfunc = &flag_c;
	tab[0].key = 'c';
	tab[1].ptrfunc = &flag_s;
	tab[1].key = 's';
	tab[2].ptrfunc = &flag_D;
	tab[2].key = 'i';
	tab[3].ptrfunc = &flag_D;
	tab[3].key = 'd';
	tab[4].ptrfunc = &flag_U;
	tab[4].key = 'u';
	tab[5].ptrfunc = &flag_X;
	tab[5].key = 'x';
	tab[6].ptrfunc = &flag_o;
	tab[6].key = 'o';
	tab[7].ptrfunc = &flag_p;
	tab[7].key = 'p';
	tab[8].ptrfunc = NULL;
	tab[8].key = -1;
	return (tab);
}
