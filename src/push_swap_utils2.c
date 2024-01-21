/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:51:41 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/21 13:36:00 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move2(t_piles *piles, char *move)
{
	int	len;

	len = ft_strlen(move);
	if (ft_strncmp(move, "rr", len) == 0)
	{
		rotate(&(piles->a));
		rotate(&(piles->b));
	}
	else if (ft_strncmp(move, "rra", len) == 0)
		rev_rotate(&(piles->a));
	else if (ft_strncmp(move, "rrb", len) == 0)
		rev_rotate(&(piles->b));
	else if (ft_strncmp(move, "rrr", len) == 0)
	{
		rev_rotate(&(piles->a));
		rev_rotate(&(piles->b));
	}
	ft_printf("%s\n", move);
}

void	ft_move(t_piles *piles, char *move)
{
	int	len;

	len = ft_strlen(move);
	if (ft_strncmp(move, "sa", len) == 0)
		swap(&(piles->a));
	else if (ft_strncmp(move, "sb", len) == 0)
		swap(&(piles->b));
	else if (ft_strncmp(move, "ss", len) == 0)
	{
		swap(&(piles->a));
		swap(&(piles->b));
	}
	else if (ft_strncmp(move, "pa", len) == 0)
		push(&(piles->b), &(piles->a));
	else if (ft_strncmp(move, "pb", len) == 0)
		push(&(piles->a), &(piles->b));
	else if (ft_strncmp(move, "ra", len) == 0)
		rotate(&(piles->a));
	else if (ft_strncmp(move, "rb", len) == 0)
		rotate(&(piles->b));
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

char	**ft_tabdup(char **tab)
{
	char	**cpy;
	int		i;

	if (tab == NULL)
		return (NULL);
	cpy = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (tab != NULL && tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
