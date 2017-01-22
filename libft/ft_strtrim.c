/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:50:45 by aazri             #+#    #+#             */
/*   Updated: 2016/11/17 17:32:38 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_fill(size_t i, size_t len, char *buff, char const *s)
{
	size_t b;

	b = 0;
	if (*s == '\0')
		return ((char *)s);
	while (i <= len)
	{
		buff[b] = s[i];
		i++;
		b++;
	}
	buff[b] = '\0';
	return (buff);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*buff;

	if (s)
	{
		i = 0;
		len = ft_strlen((char *)s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == len + 1)
			return ("");
		buff = (char *)malloc(sizeof(char) * (len - i + 1));
		if (!buff)
			return (NULL);
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		return (ft_fill(i, len, buff, s));
	}
	return (NULL);
}
