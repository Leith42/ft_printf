/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:30:42 by aazri             #+#    #+#             */
/*   Updated: 2016/11/17 16:33:41 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*new;
	t_list	*tmp;

	result = NULL;
	if (f && lst)
	{
		new = f(lst);
		if ((result = ft_lstnew(new->content, new->content_size)))
		{
			tmp = result;
			lst = lst->next;
			while (lst)
			{
				new = f(lst);
				if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
					return (NULL);
				tmp = tmp->next;
				lst = lst->next;
			}
		}
	}
	return (result);
}
