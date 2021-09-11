/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:25:44 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 20:42:11 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA 1
# define SB 2
# define SS 3
# define RA 4
# define RB 5
# define RR 6
# define RRA 7
# define RRB 8
# define RRR 9
# define PA 10
# define PB 11
# include "libft.h"
# include <limits.h>

typedef struct s_couple
{
	t_list	**a;
	t_list	**b;
}				t_couple;

void	ft_exit(char *str);
int		ft_pre_atoi(char *s);
void	print_stack(t_list *a, t_list *b);
void	parser(t_list **a, char **argv, int argc);
void	*ft_malloc(size_t i);
void	convert_to_index(t_list **a);
void	moves(int move, t_list **a, t_list **b);
void	sort_three_num(t_list **a, t_list **b);
void	sort_few_num(t_list **a, t_list **b, int hwmny);
int		pop_part(t_list **part);
bool	push_part(t_list **part, int nbr);
void	algo(t_list **a, t_list **b);
int		find_med(t_list **s, int loop);
bool	check_equality_one(t_list *b, int pivot, int hwmny);
bool	check_equality_two(t_list *b, int pivot, int hwmny);

#endif
