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
	t_pile	*pilea;
	t_pile	*pileb;
	t_pile	*first;
	t_piles	piles;

	(void)argc;
	pilea = NULL;
	pileb = NULL;
	if (check_args(argv, &pilea) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		ft_printf("pile a : \n");
		piles.a = pilea;
		piles.b = pileb;
		// ft_move(&piles, "pb");
		// // ft_move(&piles, "pb");
		// ft_move(&piles, "rb");
		// ft_move(&piles, "sb");
		// ft_move(&piles, "ss");

		// turk(&piles);

		// set_val(&pilea, 3, -10);
		// ft_printf("%d\n", is_sorted(pilea));
		// ft_printf("%d", choose_pivot(&pilea, get_val(&pilea, 0), get_val(&pilea, ft_pilesize(pilea) - 1)));
		// push(&pilea, &pileb);
		// push(&pileb, &pilea);
		// bubble_swap(&pilea, 0, 2);
		// get_pivot(pilea);
		ft_printf("%d\n\n", get_ind_to_put(piles.a, 5));
		first = piles.a;
		while (first != NULL)
		{
			ft_printf("a[%d] = %d\n", first->index, first->val);
			first = first->next;
		}

		first = piles.b;
		ft_printf("\npile b : \n");
		while (first != NULL)
		{
			ft_printf("pileb[%d] = %d\n", first->index, first->val);
			first = first->next;
		}
	}
}
