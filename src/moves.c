/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:49:02 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/10 08:00:58 by nfradet          ###   ########.fr       */
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
		(*pile)->prev = sec;
		if (sec->next != NULL)
			(sec->next)->prev = (*pile);
		sec->next = (*pile);
		sec->prev = NULL;
		*pile = sec;
		reajust_index(pile);
	}
}

void	push(t_pile **from, t_pile **to)
{
	t_pile	*tmp;

	if (*from != NULL)
	{
		tmp = *from;
		*from = (*from)->next;
		if (*from != NULL)
			(*from)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_pileadd_front(to, tmp);
		reajust_index(from);
	}
}

void	rotate(t_pile **pile)
{
	t_pile	*tmp;

	if (ft_pilesize(*pile) > 1)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		(*pile)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_pileadd_back(pile, tmp);
		reajust_index(pile);
	}
}

void	rev_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*av_der;

	if (ft_pilesize(*pile) > 1)
	{
		last = ft_pilelast(*pile);
		av_der = *pile;
		while (av_der->next->next != NULL)
			av_der = av_der->next;
		av_der->next = NULL;
		last->prev = NULL;
		ft_pileadd_front(pile, last);
	}
}