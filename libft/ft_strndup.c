/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:09:00 by aazri             #+#    #+#             */
/*   Updated: 2016/11/23 16:19:24 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	char	*dest;

	if(!(dest = malloc(sizeof(*src) * (n + 1))))
        return (NULL);
    dest = ft_strncpy(dest, src, n);
    dest[n] = '\0';
	return (dest);
}
