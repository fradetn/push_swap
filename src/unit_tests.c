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

/*
void	aff_piles(t_piles *piles)
{
	t_pile	*start;
	t_pile	*other;

	ft_printf("\n");
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
	ft_printf("-   -\na   b\n\n");
}*/
