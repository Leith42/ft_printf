/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:59:12 by aazri             #+#    #+#             */
/*   Updated: 2017/02/07 15:59:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void width_pad(int nbrstrlen, int width, char padwith)
{
	while (nbrstrlen < width)
	{
		ft_putchar(padwith);
		nbrstrlen++;
	}
}
