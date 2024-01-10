/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:51:41 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/10 09:02:20 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move2(t_piles *piles, char *move)
{
	if (ft_strncmp(move, "rra", 3) == 0)
		rev_rotate(&(piles->a));
	else if (ft_strncmp(move, "rrb", 3) == 0)
		rev_rotate(&(piles->b));
	else if (ft_strncmp(move, "rrr", 3) == 0)
	{
		rev_rotate(&(piles->a));
		rev_rotate(&(piles->b));
	}
	ft_printf("%s\n", move);
}

void	ft_move(t_piles *piles, char *move)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		swap(&(piles->a));
	else if (ft_strncmp(move, "sb", 2) == 0)
		swap(&(piles->b));
	else if (ft_strncmp(move, "ss", 2) == 0)
	{
		swap(&(piles->a));
		swap(&(piles->b));
	}
	else if (ft_strncmp(move, "pa", 2) == 0)
		push(&(piles->b), &(piles->a));
	else if (ft_strncmp(move, "pb", 2) == 0)
		push(&(piles->a), &(piles->b));
	else if (ft_strncmp(move, "ra", 2) == 0)
		rotate(&(piles->a));
	else if (ft_strncmp(move, "rb", 2) == 0)
		rotate(&(piles->b));
	else if (ft_strncmp(move, "rr", 2) == 0)
	{
		rotate(&(piles->a));
		rotate(&(piles->b));
	}
	ft_move2(piles, move);
}

int	get_index(t_pile *pile, int val)
{
	while (pile != NULL)
	{
		if (pile->val == val)
			return (pile->index);
		pile = pile->next;
	}
	return (-1);
}