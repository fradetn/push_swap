/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:21:16 by nfradet           #+#    #+#             */
/*   Updated: 2023/12/12 13:51:04 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_pilelast(t_pile *pile)
{
	if (pile == NULL)
		return (NULL);
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile);
}

t_pile	*ft_pilenew(int	val)
{
	t_pile	*nod;

	nod = (t_pile *)malloc(sizeof(t_pile));
	if (!nod)
		return (NULL);
	nod->val = val;
	nod->next = NULL;
	return (nod);
}

void	ft_pileadd_back(t_pile **pile, t_pile *new)
{
	t_pile	*last;

	last = ft_pilelast(*pile);
	if (last == NULL)
		*pile = new;
	else
		last->next = new;
}

void	ft_pileadd_front(t_pile **pile, t_pile *new)
{
	if (pile == NULL)
	{
		*pile = new;
		return ;
	}
	new->next = *pile;
	*pile = new;
}

int	ft_pilesize(t_pile *pile)
{
	int	len;

	len = 0;
	while (pile != NULL)
	{
		pile = pile->next;
		len++;
	}
	return (len);
}
