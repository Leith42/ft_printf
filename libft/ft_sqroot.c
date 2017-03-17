/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqroot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:28:26 by aazri             #+#    #+#             */
/*   Updated: 2017/03/17 16:47:09 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqroot(int n)
{
	int size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}
