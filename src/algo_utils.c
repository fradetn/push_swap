/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:47:44 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/10 09:48:01 by nfradet          ###   ########.fr       */
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