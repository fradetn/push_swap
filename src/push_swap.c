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
	t_pile	*last;
	// t_pile	*pileb;

	(void)argc;
	pilea = NULL;
	// pileb = NULL;
	if (check_args(argv, &pilea) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		ft_printf("pile a : \n");
		// set_val(&pilea, 3, -10);
		// ft_printf("%d\n", is_sorted(pilea));
		// ft_printf("%d", choose_pivot(&pilea, get_val(&pilea, 0), get_val(&pilea, ft_pilesize(pilea) - 1)));
		// push(&pilea, &pileb);
		// push(&pileb, &pilea);
		// bubble_swap(&pilea, 0, 2);
		get_pivot(pilea);
		last = ft_pilelast(pilea);
		while (last != NULL)
		{
			ft_printf("pilea[%d] = %d\n", last->index, last->val);
			last = last->prev;
		}

		// last = ft_pilelast(pileb);
		// ft_printf("pile b : \n");
		// while (last != NULL)
		// {
		// 	ft_printf("pileb[%d] = %d\n", last->index, last->val);
		// 	last = last->prev;
		// }
	}
}