/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:33:11 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/21 23:12:48 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_three_val(t_pile *p, int *a, int *b, int *c)
{
	*a = get_val(&p, 1);
	*b = get_val(&p, 2);
	*c = get_val(&p, 3);
}

void	sort_three(t_piles *piles)
{
	int	a;
	int	b;
	int	c;

	get_three_val(piles->a, &a, &b, &c);
	if (a > b && b < c && c < a)
		ft_move(piles, "rra");
	get_three_val(piles->a, &a, &b, &c);
	if ((a > b && b < c && c > a) || (a > b && b > c && c < a))
		ft_move(piles, "sa");
	get_three_val(piles->a, &a, &b, &c);
	if (a < b && b > c)
	{
		ft_move(piles, "rra");
		if (a < c)
			ft_move(piles, "sa");
	}
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
		if ((tmp > 0 && diff < 0) || (tmp > 0 && tmp < diff))
		{
			diff = tmp;
			index = b->index;
		}
		b = b->next;
	}
	return (index);
}

/*
* Calcule et renvoie le nombre de coup optimal
* pour faire remonter l'index ia en haut de la pile A
* et l'index ib en haut de la pile B.
*/
t_nbrot	get_rotations(t_piles *piles, int ia, int ib)
{
	t_nbrot	nbrot;
	t_nbrot	rev;
	int		nbmoves;

	rev.a = -((ft_pilelast(piles->a)->index - ia) + 1);
	rev.b = -((ft_pilelast(piles->b)->index - ib) + 1);
	nbrot.a = ft_min_abs(ia - 1, rev.a);
	nbrot.b = ft_min_abs(ib - 1, rev.b);
	nbmoves = get_nbmoves(nbrot);
	if (nbmoves > ft_max(ia - 1, ib - 1))
	{
		nbrot.a = ia - 1;
		nbrot.b = ib - 1;
		nbmoves = get_nbmoves(nbrot);
	}
	if (nbmoves > ft_max(ft_abs(rev.a), ft_abs(rev.b)))
	{
		nbrot.a = rev.a;
		nbrot.b = rev.b;
		nbmoves = get_nbmoves(nbrot);
	}
	return (nbrot);
}

int	get_ind_to_push(t_piles *piles)
{
	int		index;
	int		ib;
	t_nbrot	rot;
	t_nbrot	tmp;
	t_pile	*a;

	index = 1;
	a = piles->a;
	ib = get_ind_to_put(piles->b, a->val);
	rot = get_rotations(piles, a->index, ib);
	a = a->next;
	while (a != NULL)
	{
		ib = get_ind_to_put(piles->b, a->val);
		tmp = get_rotations(piles, a->index, ib);
		if (get_nbmoves(rot) > get_nbmoves(tmp))
		{
			index = a->index;
			rot = tmp;
		}
		a = a->next;
	}
	return (index);
}

void	do_moves_indep(t_piles *piles, t_nbrot rot)
{
	while (rot.a > 0)
	{
		ft_move(piles, "ra");
		rot.a -= 1;
	}
	while (rot.a < 0)
	{
		ft_move(piles, "rra");
		rot.a += 1;
	}
	while (rot.b < 0)
	{
		ft_move(piles, "rrb");
		rot.b += 1;
	}
	while (rot.b > 0)
	{
		ft_move(piles, "rb");
		rot.b -= 1;
	}
}

void	do_moves(t_piles *piles, t_nbrot rot)
{
	while (rot.a < 0 && rot.b < 0)
	{
		ft_move(piles, "rrr");
		rot.a += 1;
		rot.b += 1;
	}
	while (rot.a > 0 && rot.b > 0)
	{
		ft_move(piles, "rr");
		rot.a -= 1;
		rot.b -= 1;
	}
	do_moves_indep(piles, rot);
}

void	first_part(t_piles *piles)
{
	int		topush;
	int		toput;
	t_nbrot	rot;

	ft_move(piles, "pb");
	ft_move(piles, "pb");
	while (ft_pilesize(piles->a) > 3)
	{
		topush = get_ind_to_push(piles);
		toput = get_ind_to_put(piles->b, get_val(&piles->a, topush));
		rot = get_rotations(piles, topush, toput);
		do_moves(piles, rot);
		ft_move(piles, "pb");
	}
	sec_part(piles);
}

void	spec_cases(t_piles *piles)
{
	if (ft_pilesize(piles->a) == 2)
		ft_move(piles, "sa");
	else if (ft_pilesize(piles->a) == 4)
	{
		ft_move(piles, "pb");
		sec_part(piles);
	}
	else if (ft_pilesize(piles->a) == 3)
		sort_three(piles);
}