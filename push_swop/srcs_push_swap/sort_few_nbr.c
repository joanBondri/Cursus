/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:11:14 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 20:42:25 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_step(int one, int two, int thr, t_couple *c)
{
	if (one > two && one < thr)
		moves(SA, c->a, c->b);
	else if (one > two && two > thr)
	{
		moves(SA, c->a, c->b);
		sort_three_num(c->a, c->b);
	}
	else if (one < two && one > thr)
	{
		moves(RA, c->a, c->b);
		moves(SA, c->a, c->b);
		moves(RRA, c->a, c->b);
		sort_three_num(c->a, c->b);
	}
	else if (one > thr && thr > two)
	{
		moves(SA, c->a, c->b);
		sort_three_num(c->a, c->b);
	}
	else if (two > thr && thr > one)
	{
		moves(RA, c->a, c->b);
		moves(SA, c->a, c->b);
		moves(RRA, c->a, c->b);
	}
}

void	sort_three_num(t_list **a, t_list **b)
{
	int			one;
	int			two;
	int			thr;
	t_couple	yop;

	if (ft_lstsize(*a) < 3)
		return ;
	one = *((int *)(*a)->content);
	two = *((int *)((*a)->next)->content);
	thr = *((int *)(((*a)->next)->next)->content);
	yop = (t_couple){.a = a, .b = b};
	second_step(one, two, thr, &yop);
}

void	sort_two_num(t_list **a, t_list **b)
{
	int		one;
	int		two;

	if (ft_lstsize(*a) < 2)
		return ;
	one = *((int *)(*a)->content);
	two = *((int *)((*a)->next)->content);
	if (one > two)
		moves(SA, a, b);
	return ;
}

void	sort_few_num(t_list **a, t_list **b, int hwmny)
{
	if (hwmny != 2 && hwmny != 3)
		return ;
	if (hwmny == 2)
		return (sort_two_num(a, b));
	return (sort_three_num(a, b));
}
