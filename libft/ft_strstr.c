/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:19:45 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:47:51 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	c = 0;
	if (*find == '\0')
		return (char*)(str);
	while (str[i])
	{
		j = i;
		c = 0;
		while (str[j] == find[c])
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
