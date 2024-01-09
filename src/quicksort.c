/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:33:11 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/09 10:14:44 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*find_lis(t_pile **pile)
// {
// 	int	i;
// 	int	j;
// 	int	*lens;
// 	int	*lis;

// 	lens = malloc(sizeof(int) * ft_pilesize(*pile));
// 	ft_memset(lens, 1, ft_pilesize(*pile));
// 	i = 1;
// 	while (i < ft_pilesize(*pile))
// 	{
// 		j = 0;
// 		while (j < i)
// 		{
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	get_pivot(t_pile *pile)
// {
// 	t_pile *i_pile;
// 	t_pile *j_pile;

// 	while (is_sorted(pile) == 0)
// 	{
// 		i_pile = pile;
// 		while (i_pile->next != NULL)
// 		{
// 			j_pile = i_pile->next;
// 			while (j_pile != NULL)
// 			{
// 				if (i_pile->val > j_pile->val)
// 					bubble_swap(&pile, i_pile->index, j_pile->index);
// 				j_pile = j_pile->next;
// 			}
// 			i_pile = i_pile->next;
// 		}	
// 	}
// 	bubble_swap(&pile, 0, 1);
// 	return 1;
// }

void	turk(t_pile **pile)
{
	
}