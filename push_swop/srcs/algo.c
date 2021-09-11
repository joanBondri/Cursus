/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:51:57 by jbondri           #+#    #+#             */
/*   Updated: 2021/09/11 19:52:04 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_a(t_list **a, t_list **b, t_list **part, int hwmny)
{
	int		pivot;
	int		res;
	int		ros;

	if (hwmny < 0)
		hwmny = ft_lstsize(*b);
	if (hwmny == 0)
		exit (0);
	pivot = find_med(b, hwmny);
	if (hwmny <= 3)
		pivot = -1;
	res = 0;
	ros = 0;
	while (check_equality_one(*b, pivot, hwmny) && hwmny--)
	{
		if (*((int *)(*b)->content) >= pivot && ++res)
			moves(PA, a, b);
		else if (++ros)
			moves(RB, a, b);
	}
	push_part(part, pop_part(part) + ros + hwmny);
	while (ros--)
		moves(RRB, a, b);
	return (res);
}

bool	check_stack(t_list **a, t_list **b)
{
	t_list	*buff;

	if (!b || !a || *b)
		return (false);
	buff = *a;
	while (buff && buff->next)
	{
		if (*((int *)buff->content) > *((int *)(buff->next)->content))
			return (false);
		buff = buff->next;
	}
	return (true);
}

int	push_back_to_b(t_list **a, t_list **b, int hmny, t_list **part)
{
	int		pivot;
	int		res;
	int		rop;

	pivot = find_med(a, hmny);
	res = 0;
	rop = 0;
	while (check_equality_two(*a, pivot, hmny) && hmny--)
	{
		if (*((int *)(*a)->content) <= pivot)
		{
			res++;
			moves(PB, a, b);
		}
		else
		{
			rop++;
			moves(RA, a, b);
		}
	}
	while (rop--)
		moves(RRA, a, b);
	push_part(part, res);
	return (res);
}

void	initial_push(t_list **a, t_list **b, t_list **part)
{
	int		pivot;
	int		size;
	int		res;

	size = ft_lstsize(*a);
	pivot = size - 3;
	res = 0;
	while (size--)
	{
		if (*((int *)(*a)->content) <= pivot && ++res)
			moves(PB, a, b);
		else
			moves(RA, a, b);
	}
	push_part(part, res);
	sort_few_num(a, b, ft_lstsize(*a));
}

void	algo(t_list **a, t_list **b)
{
	t_list	*part;
	int		res;

	if (ft_lstsize(*a) < 4)
		return (sort_few_num(a, b, ft_lstsize(*a)));
	initial_push(a, b, &part);
	while (!check_stack(a, b))
	{
		res = pop_part(&part);
		if (res == 0)
			exit (0);
		res = push_to_a(a, b, &part, res);
		while (res > 3)
			res -= push_back_to_b(a, b, res, &part);
		sort_few_num(a, b, res);
	}
}
