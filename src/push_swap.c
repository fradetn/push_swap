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
	// t_pile	*first;
	t_piles	piles;

	piles.a = NULL;
	piles.b = NULL;
	(void)argc;
	if (check_args(argv, &(piles.a)) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		// ft_printf("toput = %d\n", get_ind_to_put(piles.a, 1));
		// aff_piles(&piles);


		turk(&piles);
	}
}
