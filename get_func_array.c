/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:40:44 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 16:52:08 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FUNC_NBR 10

t_func	*get_func_array(void)
{
	t_func *tab;

	if((tab = malloc(sizeof(t_func) * FUNC_NBR)) == NULL)
		return (NULL);
	tab[0].ptrfunc = &spec_c;
	tab[0].key = 'c';
	tab[1].ptrfunc = &spec_s;
	tab[1].key = 's';
	tab[2].ptrfunc = &spec_D;
	tab[2].key = 'i';
	tab[3].ptrfunc = &spec_D;
	tab[3].key = 'd';
	tab[4].ptrfunc = &spec_U;
	tab[4].key = 'u';
	tab[5].ptrfunc = &spec_X;
	tab[5].key = 'x';
	tab[6].ptrfunc = &spec_o;
	tab[6].key = 'o';
	tab[7].ptrfunc = &spec_p;
	tab[7].key = 'p';
	tab[8].ptrfunc = &spec_c;
	tab[8].key = '%';
	tab[9].ptrfunc = NULL;
	tab[9].key = -1;
	return (tab);
}
