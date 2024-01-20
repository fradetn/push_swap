/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:24 by nfradet           #+#    #+#             */
/*   Updated: 2023/12/12 09:41:24 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				val;
	int				index;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;

typedef struct s_piles
{
	t_pile	*a;
	t_pile	*b;
}	t_piles;

typedef struct s_nbrot
{
	int	a;
	int	b;
}	t_nbrot;

/*Utils main and free*/
int			main(int argc, char **argv);
int			ft_tablen(char **tab);
char		**extract_args(char **argv);
char		**ft_tabjoin(char **t1, char **t2);
void		ft_freetab(char **tab);
int			check_args(char **argv, t_pile **pile);
int			get_val(t_pile **pile, int indice);
int			set_val(t_pile **pile, int index, int val);
int			get_index(t_pile *pile, int val);

/*To manage pile structure*/
t_pile		*ft_pilelast(t_pile *pile);
t_pile		*ft_pilenew(int	val);
void		ft_pileadd_back(t_pile **pile, t_pile *new);
void		ft_pileadd_front(t_pile **pile, t_pile *new);
int			ft_pilesize(t_pile *pile);
void		ft_pileclear(t_pile **pile);
void		reajust_index(t_pile **pile);
long int	ft_longatoi(const char *str);

/*For the moves*/
void		swap(t_pile **pile);
void		push(t_pile **from, t_pile **to);
void		rotate(t_pile **pile);
void		rev_rotate(t_pile **pile);
void		ft_move(t_piles *piles, char *move);

/*algo and utils for algo*/
void		turk(t_piles *pile);
int			is_sorted(t_pile *pile);
int			get_maxval(t_pile *pile);
int			get_minval(t_pile *pile);
int			get_ind_to_put(t_pile *b, int val);
int			get_ind_to_push(t_piles *piles);
t_nbrot		get_rotations(t_piles *piles, int ia, int ib);
int			get_nbmoves(t_nbrot rot);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_abs(int nbr);
int			ft_min_abs(int a, int b);
int			ft_max_abs(int a, int b);
void		do_moves(t_piles *piles, t_nbrot rot);



/*Tests functions*/
int			test_indtoput_fct(t_pile *pile, int val, int res);
int			test_getrotations_fct(t_piles *piles, int ia, int ib, t_nbrot res);
int			test_getindtopush_fct(t_piles *piles, int res);
void		aff_piles(t_piles *piles);

#endif