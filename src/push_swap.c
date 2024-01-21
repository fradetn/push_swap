/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:20 by nfradet           #+#    #+#             */
/*   Updated: 2023/12/12 09:41:20 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (is_sorted(piles.a) == 1)
			return (ft_free_piles(&piles), 0);
		else
		{
			if (ft_pilesize(piles.a) <= 4)
				spec_cases(&piles);
			else
				first_part(&piles);
		}
	}
	ft_free_piles(&piles);
}
