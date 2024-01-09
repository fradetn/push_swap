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

int			main(int argc, char **argv);
int			ft_tablen(char **tab);
char		**extract_args(char **argv);
char		**ft_tabjoin(char **t1, char **t2);
void		ft_freetab(char **tab);
int			check_args(char **argv, t_pile **pile);
int			get_val(t_pile **pile, int indice);
int			set_val(t_pile **pile, int index, int val);

t_pile		*ft_pilelast(t_pile *pile);
t_pile		*ft_pilenew(int	val);
void		ft_pileadd_back(t_pile **pile, t_pile *new);
void		ft_pileadd_front(t_pile **pile, t_pile *new);
int			ft_pilesize(t_pile *pile);
void		ft_pileclear(t_pile **pile);
void		reajust_index(t_pile **pile);
long int	ft_longatoi(const char *str);


void		swap(t_pile **pile);
void		push(t_pile **from, t_pile **to);
void		rotate(t_pile **pile);
void		rev_rotate(t_pile **pile);

// int			get_pivot(t_pile *pile);
int			is_sorted(t_pile *pile);
// void		bubble_swap(t_pile **pile, int i1, int i2);


#endif