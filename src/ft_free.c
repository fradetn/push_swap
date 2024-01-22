/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:28:30 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/23 15:11:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pileclear(t_pile **pile)
{
	if (pile && *pile)
	{
		ft_pileclear(&(*pile)->next);
		if (*pile != NULL)
			free(*pile);
		*pile = NULL;
	}
}

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab[i]);
		free(tab);
	}
}

void	ft_free_piles(t_piles *piles)
{
	if (piles->a != NULL)
		ft_pileclear(&piles->a);
	if (piles->b != NULL)
		ft_pileclear(&piles->b);
}
