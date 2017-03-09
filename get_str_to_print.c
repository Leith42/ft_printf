/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:09:29 by aazri             #+#    #+#             */
/*   Updated: 2017/03/09 14:25:10 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *get_str_to_print(char *hex, char specifier)
{
	char *str;

	if((str = malloc(sizeof(char))) == NULL)
	{
		return (NULL);
	}
	if (specifier == 'x' || specifier == 'p')
	{
		if ((str = ft_strjoin(str, ft_strtolower(hex))) == NULL)
		{
			return (NULL);
		}
	}
	else if (specifier == 'X')
	{
		if ((str = ft_strjoin(str, hex)) == NULL)
		{
			return (NULL);
		}
	}
	return (str);
}
