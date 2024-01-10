/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:33:11 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/10 11:30:30 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*find_lis(t_pile **pile)
// {
// 	int	i;
// 	int	j;
// 	int	*lens;
// 	int	*lis;

// 	lens = malloc(sizeof(int) * ft_pilesize(*pile));
// 	ft_memset(lens, 1, ft_pilesize(*pile));
// 	i = 1;
// 	while (i < ft_pilesize(*pile))
// 	{
// 		j = 0;
// 		while (j < i)
// 		{
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	get_pivot(t_pile *pile)
// {
// 	t_pile *i_pile;
// 	t_pile *j_pile;

// 	while (is_sorted(pile) == 0)
// 	{
// 		i_pile = pile;
// 		while (i_pile->next != NULL)
// 		{
// 			j_pile = i_pile->next;
// 			while (j_pile != NULL)
// 			{
// 				if (i_pile->val > j_pile->val)
// 					bubble_swap(&pile, i_pile->index, j_pile->index);
// 				j_pile = j_pile->next;
// 			}
// 			i_pile = i_pile->next;
// 		}	
// 	}
// 	bubble_swap(&pile, 0, 1);
// 	return 1;
// }


/*
get_ind_to_put :
	cherche dans la pile b ou placer le nombre voulu.
	si c'est le nouveau plus grand ou plus petit, 
	renverra l'index du max de la liste

get_nb_rot :
	renvoie le nombre de rotation necessaires pour 
	ramener le chiffre en haut de la liste.
	(index - 1)

get_nb_revrot :
	renvoie le nombre de rotation inverses pour 
	ramener le chiffre en haut de la pile.
	((last_index - index) + 1)

get_ind_to_push :
	teste pour toutes les valeurs de la pile A 
	en calculant le nombre de coups pour ramener 
	ce chiffre en haut de la pile
	et appelle get_ind_to_put pour savoir le nombre de rotation
	de la pile B sans oublier le push.
*/

void	sort_three(t_pile **a)
{
	(void)a;
}

/*
* renvoie l'index de  l'element dans la pile b 
* qui devra remonter au dessus avant de push
*/
int	get_ind_to_put(t_pile *b, int val)
{
	int		diff;
	int		index;
	int		tmp;

	if (val > get_maxval(b) || val < get_minval(b))
		return (get_index(b, get_maxval(b)));
	diff = val - b->val;
	index = b->index;
	while (b != NULL)
	{
		tmp = val - b->val;
		if (tmp > 0 && tmp < diff)
		{
			diff = tmp;
			index = b->index;
		}
		b = b->next;
	}
	return (index);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*
* Calcule et renvoie le nombre de coup optimal
* pour faire remonter l'index ia en haut de la pile A
* et l'index ib en haut de la pile B.
*/
int	get_nbmoves(t_piles *piles, int ia, int ib)
{
	int	rot_a;
	int	rot_b;
	int	revrot_a;
	int	revrot_b;
	int	nbmoves;

	rot_a = ia - 1;
	rot_b = ib - 1;
	revrot_a = (ft_pilelast(piles->a)->index - ia) + 1;
	revrot_b = (ft_pilelast(piles->b)->index - ib) + 1;
	nbmoves = ft_min(rot_a, revrot_a) + ft_min(rot_b, revrot_b);
	// if (nbmoves > ft_max(rot_a, rot_b))
	// else if (nbmoves > ft_max(revrot_a, revrot_b))
	// else
}

int	get_ind_to_push(t_pile *a)
{
	int	nbmove;
	int	index;

	nbmove = 0;
	index = 0;
	while (a != NULL)
	{

	}
}

void	turk(t_piles *piles)
{
	if (ft_pilesize(piles->a) == 3)
		sort_three(&(piles->a));
	else
	{
		ft_move(piles, "pb");
		ft_move(piles, "pb");
		while (ft_pilesize(piles->a) > 3)
		{
		}
	}
}