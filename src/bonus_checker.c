/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:33:43 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 14:33:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_move(char *move)
{
	if (ft_strncmp("sa", move, 4) == 0 || ft_strncmp("sb", move, 4) == 0)
		return (0);
	if (ft_strncmp("ss", move, 4) == 0 || ft_strncmp("ra", move, 4) == 0)
		return (0);
	if (ft_strncmp("rb", move, 4) == 0 || ft_strncmp("rr", move, 4) == 0)
		return (0);
	if (ft_strncmp("pa", move, 4) == 0 || ft_strncmp("pb", move, 4) == 0)
		return (0);
	if (ft_strncmp("rra", move, 4) == 0)
		return (0);
	if (ft_strncmp("rrb", move, 4) == 0)
		return (0);
	if (ft_strncmp("rrr", move, 4) == 0)
		return (0);
	return (1);
}

int	checker(t_piles *piles)
{
	char	*move;
	char	*tmp;

	tmp = get_next_line(STDIN_FILENO);
	while (tmp)
	{
		move = ft_strdup_no_nl(tmp);
		free(tmp);
		if (is_valid_move(move) == 0)
			ft_move(piles, move, 0);
		else
		{
			write(STDERR_FILENO, "Error\n", 6);
			get_next_line(-1);
			ft_free_piles(piles);
			return (free(move), -1);
		}
		free(move);
		tmp = get_next_line(STDIN_FILENO);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_piles	piles;

	piles.a = NULL;
	piles.b = NULL;
	if (argc < 2)
		return (0);
	else if (check_args(argv, &(piles.a)) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		if (checker(&piles) == -1)
			return (0);
		if (piles.b == NULL && is_sorted(piles.a) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_free_piles(&piles);
}
