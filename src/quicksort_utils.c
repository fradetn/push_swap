/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:28:07 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/09 09:57:45 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	bubble_swap(t_pile **pile, int i1, int i2)
// {
// 	int	tmp;

// 	tmp = get_val(pile, i1);
// 	set_val(pile, i1, get_val(pile, i2));
// 	set_val(pile, i2, tmp);
// }