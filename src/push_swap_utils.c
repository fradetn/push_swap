/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:04:25 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/23 15:11:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tabjoin(char **t1, char **t2)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_tablen(t1) + ft_tablen(t2) + 1));
	if (tab == NULL)
		return (NULL);
	while (t1 && *t1)
		tab[i++] = ft_strdup(*t1++);
	while (t2 && *t2)
		tab[i++] = ft_strdup(*t2++);
	tab[i] = '\0';
	return (tab);
}

int	get_val(t_pile **pile, int indice)
{
	int		i;
	t_pile	*cur;

	i = 1;
	cur = *pile;
	while (cur != NULL && i++ < indice)
		cur = cur->next;
	return (cur->val);
}

int	set_val(t_pile **pile, int index, int val)
{
	int		i;
	t_pile	*cur;

	i = 0;
	cur = *pile;
	while (cur != NULL && i++ < index)
		cur = cur->next;
	if (cur == NULL)
		return (0);
	else
		cur->val = val;
	return (1);
}

void	reajust_index(t_pile **pile)
{
	int		i;
	t_pile	*cur;

	i = 1;
	cur = *pile;
	while (cur != NULL)
	{
		cur->index = i;
		i++;
		cur = cur->next;
	}
}
