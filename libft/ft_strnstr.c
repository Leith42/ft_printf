/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:27:35 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:38:05 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		c;

	i = 0;
	c = 0;
	if (*find == '\0')
		return (char*)(str);
	while (i < len && str[i])
	{
		j = i;
		c = 0;
		while (str[j] == find[c] && j < len)
		{
			j++;
			c++;
			if (find[c] == '\0')
				return (char*)(&str[i]);
		}
		i++;
	}
	return (NULL);
}
