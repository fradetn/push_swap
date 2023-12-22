/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:49:02 by nfradet           #+#    #+#             */
/*   Updated: 2023/12/19 21:21:03 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	t_pile	*sec;

	if (ft_pilesize(*pile) > 1)
	{
		sec = (*pile)->next;
		(*pile)->next = sec->next;
		sec->next = (*pile);
		*pile = sec;
	}
}

void	push(t_pile **from, t_pile **to)
{
	t_pile	*tmp;

	if (*from != NULL)
	{
		tmp = *from;
		*from = (*from)->next;
		tmp->next = NULL;
		ft_pileadd_front(to, tmp);
	}
}

void	rotate(t_pile **pile)
{
	t_pile	*tmp;

	if (ft_pilesize(*pile) > 1)
	{
		tmp = *pile;
		*pile = tmp->next;
		tmp->next = NULL;
		ft_pileadd_back(pile, tmp);
	}
}

void	rev_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*av_der;

	if (ft_pilesize(*pile) > 1)
	{
		av_der = *pile;
		while (av_der->next->next != NULL)
			av_der = av_der->next;
		av_der->next = NULL;
		last = ft_pilelast(*pile);
		ft_pileadd_front(pile, last);
	}
}