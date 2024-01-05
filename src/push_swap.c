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
	t_pile	*new;
	// t_pile	*pileb;

	(void)argc;
	pilea = NULL;
	// pileb = NULL;
	if (check_args(argv, &pilea) == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		ft_printf("pile a : \n");
		// ft_printf("%d", choose_pivot(&pilea, get_val(&pilea, 0), get_val(&pilea, ft_pilesize(pilea) - 1)));
		new = ft_pilenew(100);
		ft_pileadd_back(&pilea, new);
		last = ft_pilelast(pilea);
		while (last != NULL)
		{
			ft_printf("pile[%d] = %d\n", last->index, last->val);
			last = last->prev;
		}
		// ft_printf("pile b : \n");
		// while (pileb != NULL)
		// {
		// 	ft_printf("%d\n", pileb->val);
		// 	pileb = pileb->next;
		// }
	}
}