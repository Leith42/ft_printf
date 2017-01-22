/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:44:35 by aazri             #+#    #+#             */
/*   Updated: 2016/11/16 20:38:44 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int letter)
{
	char *ret;

	ret = 0;
	while (*str)
	{
		if (*str == letter)
			ret = (char *)str;
		str++;
	}
	if (*str == letter)
		ret = (char *)str;
	return (ret);
}
