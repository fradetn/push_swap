/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:33:11 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/05 06:09:51 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_pivot(t_pile **pile, int low, int high)
{
    int mid;

	mid = get_val(pile, ft_pilesize(*pile) / 2);
	if ((low < mid && mid < high) || (high < mid && mid < low))
		return (mid);
	else if ((mid < low && low < high) || (high < low && low < mid))
		return (low);
	else
		return (high);
}
