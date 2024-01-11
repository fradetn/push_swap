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
	t_pile	*first;
	t_piles	piles;
	t_nbrot	nbrot;
	int		topush;
	int		toput;


	piles.a = NULL;
	piles.b = NULL;
	(void)argc;
	if (check_args(argv, &(piles.a)) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		ft_move(&piles, "pb");
		ft_move(&piles, "pb");
		ft_move(&piles, "pb");
		
		topush = get_ind_to_push(&piles);
		toput = get_ind_to_put(piles.b, get_val(&(piles.a), topush));
		nbrot = get_rotations(&piles, topush, toput);
		ft_printf("index a push : %d\n", topush);
		ft_printf("where to put : %d\n", toput);
		ft_printf("rot_a = %d, rot_b = %d", nbrot.a, nbrot.b);

		// turk(&piles);
		// ft_printf("%d\n\n", get_ind_to_put(piles.a, 5));
		ft_printf("\npile a : \n");
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
