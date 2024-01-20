/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:38:41 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 16:38:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_indtoput_fct(t_pile *pile, int val, int res)
{
	ft_printf("to_put = %d\n", get_ind_to_put(pile, val));
	if (get_ind_to_put(pile, val) == res)
		return (1);
	else
		return (0);
}

int	test_getrotations_fct(t_piles *piles, int ia, int ib, t_nbrot res)
{
	t_nbrot	test;

	test = get_rotations(piles, ia, ib);
	ft_printf("rot.a = %d, rot.b = %d\n", test.a, test.b);
	if (test.a == res.a && test.b == res.b)
		return (1);
	else
		return (0);
}

int	test_getindtopush_fct(t_piles *piles, int res)
{
	ft_printf("to_push = %d\n", get_ind_to_push(piles));
	if (get_ind_to_push(piles) == res)
		return (1);
	else
		return (0);
}


void	aff_piles(t_piles *piles)
{
	t_pile	*start;
	t_pile	*other;

	if (ft_pilesize(piles->a) > ft_pilesize(piles->b))
	{
		start = piles->a;
		other = piles->b;
		while (ft_pilesize(start) > ft_pilesize(other))
		{
			ft_printf("%d\n", start->val);
			start = start->next;
		}
		while (start != NULL && other != NULL)
		{
			ft_printf("%d   %d\n", start->val, other->val);
			start = start->next;
			other = other->next;
		}
	}
	else if (ft_pilesize(piles->a) < ft_pilesize(piles->b))
	{
		start = piles->b;
		other = piles->a;
		while (ft_pilesize(start) > ft_pilesize(other))
		{
			ft_printf("    %d\n", start->val);
			start = start->next;
		}
		while (start != NULL && other != NULL)
		{
			ft_printf("%d   %d\n", other->val, start->val);
			start = start->next;
			other = other->next;
		}
	}
	else
	{
		start = piles->a;
		other = piles->b;
		while (start != NULL && other != NULL)
		{
			ft_printf("%d   %d\n", start->val, other->val);
			start = start->next;
			other = other->next;
		}
	}
	ft_printf("-   -\na   b\n");
}