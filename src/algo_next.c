/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:29:09 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/21 12:19:57 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_cost(t_pile *a, int ind)
{
	return (ft_min_abs(-((ft_pilelast(a)->index - ind) + 1), ind -1));
}

int	get_ind_to_pa(t_pile *a, int val)
{
	int	index;
	int	diff;
	int	tmp;

	if (val > get_maxval(a) || val < get_minval(a))
		return (get_index(a, get_minval(a)));
	diff = a->val - val;
	index = a->index;
	while(a != NULL)
	{
		tmp = a->val - val;
		if ((tmp > 0 && diff < 0) || (tmp > 0 && tmp < diff))
		{
			diff = tmp;
			index = a->index;
		}
		a = a->next;
	}
	return (index);
}

void	sec_part(t_piles *piles)
{
	int		toput;
	t_nbrot	rot;

	rot.b = 0;
	if (ft_pilesize(piles->a) == 3)
		sort_three(piles);
	while (piles->b != NULL)
	{
		toput = get_ind_to_pa(piles->a, piles->b->val);
		rot.a = get_cost(piles->a, toput);
		do_moves(piles, rot);
		ft_move(piles, "pa");
	}
	rot.a = get_cost(piles->a, get_index(piles->a, get_minval(piles->a)));
	do_moves(piles, rot);
}	
