/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:47:44 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/23 15:04:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_maxval(t_pile *pile)
{
	int		max;

	max = pile->val;
	while (pile != NULL)
	{
		if (pile->val > max)
			max = pile->val;
		pile = pile->next;
	}
	return (max);
}

int	get_minval(t_pile *pile)
{
	int		min;

	min = pile->val;
	while (pile != NULL)
	{
		if (pile->val < min)
			min = pile->val;
		pile = pile->next;
	}
	return (min);
}

int	get_nbmoves(t_nbrot rot)
{
	if (rot.a <= 0 && rot.b <= 0)
		return (ft_max(-rot.a, -rot.b));
	else if (rot.a >= 0 && rot.b >= 0)
		return (ft_max(rot.a, rot.b));
	else
		return (ft_abs(rot.a) + ft_abs(rot.b));
}

/*
* Return 1 if sec cost you less move
* else return 0
*/
int	is_less_cost(t_nbrot first, t_nbrot sec)
{
	if (get_nbmoves(first) > get_nbmoves(sec))
		return (1);
	else
		return (0);
}

int	is_sorted(t_pile *pile)
{
	t_pile	*j_pile;

	while (pile != NULL)
	{
		j_pile = pile->next;
		while (j_pile != NULL)
		{
			if (j_pile->val < pile->val)
				return (0);
			j_pile = j_pile->next;
		}
		pile = pile->next;
	}
	return (1);
}
