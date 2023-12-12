/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:19:27 by nfradet           #+#    #+#             */
/*   Updated: 2023/10/10 19:44:23 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_head;

	lst_head = NULL;
	while (lst)
	{
		lst_new = ft_lstnew(f(lst->content));
		if (!lst_new)
		{
			ft_lstclear(&lst_head, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_head, lst_new);
		lst = lst->next;
	}
	return (lst_head);
}
