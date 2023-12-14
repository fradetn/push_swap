/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:15 by nfradet           #+#    #+#             */
/*   Updated: 2023/12/12 09:41:15 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	**extract_args(char **argv)
{
	int		i;
	char	**tmp;
	char	**tab;

	i = 1;
	tab = NULL;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		tab = ft_tabjoin(tab, tmp);
		i++;
		free(tmp);
	}
	return (tab);
}

int	is_valid_int(char *val)
{
	int	i;
	
	if (ft_longatoi(val) > 2147483647)
		return (0);
	else if (ft_longatoi(val) < -2147483648)
		return (0);
	i = 0;
	if (val[0] == '-' || val[0] == '+')
		i++;
	while (val[i])
	{
		if (ft_isdigit(val[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	tab_to_pile(char **tab, t_pile **pile)
{
	t_pile	*cur;
	int		i;
	
	i = 0;
	while (tab[i])
	{
		cur = ft_pilenew(ft_atoi(tab[i]));
		ft_pileadd_back(pile, cur);
		i++;
	}
}

int	check_doublons(t_pile **pile)
{
	t_pile	*current;
	t_pile	*next;

	current = *pile;
	while (current)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->val == next->val)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}

int	check_args(char **argv, t_pile **pile)
{
	char	**tab;
	int		i;
	
	i = 0;
	tab = extract_args(argv);
	while (tab[i])
	{
		if (is_valid_int(tab[i]) == 0)
			return (0);
		i++;
	}
	tab_to_pile(tab, pile);
	if (check_doublons(pile) == 0)
		return (0);
	return (1);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_pile	*pile;

	pile = NULL;
	(void) argc;
	if (check_args(argv, &pile) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		while (pile != NULL)
		{
			ft_printf("%d\n", pile->val);
			pile = pile->next;
		}
	}
}
