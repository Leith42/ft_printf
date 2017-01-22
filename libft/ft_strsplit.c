/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:34:49 by aazri             #+#    #+#             */
/*   Updated: 2016/11/17 17:32:24 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		words++;
	}
	if (s[i - 1] == c && words >= 1)
		words--;
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
	}
	return (len);
}

static char		**ft_filltab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		if (!(tab[i] = ft_strnew(ft_wordlen(&s[j], c) + 1)))
			tab[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (!s ||
		!(tab = (char **)malloc(sizeof(*tab) * (ft_countwords(s, c) + 1))))
		return (NULL);
	if (ft_wordlen(&s[0], c) == 0)
	{
		tab[0] = NULL;
		return (tab);
	}
	return (ft_filltab(s, c, tab));
}
