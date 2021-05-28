/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:09:03 by jbondri           #+#    #+#             */
/*   Updated: 2021/05/18 10:01:20 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_dep.h"

void	under_three_stack_a(int **a, int **b, int num, t_list **moves)
{
	if ((num == 2 && (*a)[1] < (*a)[2]) ||
			(num == 3 && (*a)[1] < (*a)[2] && (*a)[2] < (*a)[3]))
		return ;
	else if (num == 2 || ((*a)[1] > (*a)[2] && (*a)[1] < (*a)[3]))
		operation("sa", a, b, moves);
	else if ((*a)[1] < (*a)[2] && (*a)[2] > (*a)[3])
		operation("ra\nsa\nrra", a, b, moves);
	else if ((*a)[1] > (*a)[3] && (*a)[1] < (*a)[2])
		operation("ra\nsa\nrra\nsa", a, b, moves);
	else if ((*a)[2] > (*a)[3] && (*a)[2] < (*a)[1])
		operation("sa\nra\nsa\nrra\nsa", a, b, moves);
	else if ((*a)[2] < (*a)[3] && (*a)[3] < (*a)[1])
		operation("sa\nra\nsa\nrra", a, b, moves);

}

int		put_stack_b(int **a, int **b, t_list **moves)
{
	int		med;
	int		i;
	int		total;
	int		res;

	med = (*a)[0] - 2;
	i = 0;
	total = (*a)[0];
	res = 0;
	while (++i <= total && at_least_one_lq(total - i, *b, med))
	{
		if ((*a)[1] <= med)
		{
			operation("pb", a, b, moves);
			res++;
		}
		else if (i != total)
			operation("ra", a, b, moves);
	}
	under_three_stack_a(a, b, a[0], moves);	
	return (res);
}

int		find_med(int *tb,int num)
{
	int		i;
	int		min;
	int		max;
	int		total;

	total = num;
	i = 0;
	if (total == 0)
		return (0);
	min = tb[1];
	max = tb[1];
	while (++i <= total)
	{
		if (tb[i] > max)
			max = tb[i];
		if (tb[i] < min)
			min = tb[i];
	}
	return ((max + min) / 2);
}
//fonction pour envoyer part de fois dans a
int	push_part_to_a(int **a, int **b, t_list **mv, t_list **lst_prt)
{
	int		part;
	int		res;
	int		i;

	i = 0;
	part = extract_part(lst_prt);
	res = part;
	if (part > 3)
	{
		while (++i <= total && at_least_one_mq(total - i, *b, part))
		{
			if ((*b)[1] >= med && total_push++)
				operation("pa", a, b, moves);
			else if (i != total && total_back++)
				operation("rb", a, b, moves);
		}
	}

	while (--part >= 0)
		operation("pa", a, b, mv);
	return res;
}

void	leave_numbers_a(t_ps *ps, t_list **moves, t_list **part, bool f)
{
	int	tot_push;
	int biff;

	if (f)
		ps->count_to_sort = push_med_to_a(ps->a, ps->b, moves, *(ps->b)[0]);
	else
		ps->count_to_sort = push_part_to_a(ps->a, ps->b, moves, part);
	if (ps->count_to_sort > 3)
	{
		buff = push_back_to_b(ps, moves);
		ft_lstadd_front(part, ft_lstnew(buff));
		ps->count_to_sort -= buff;
	}
	under_three_stack_a(ps->a, ps->b, ps->count_to_sort, moves);
	if ((*part)->next != NULL)
		leave_numbers_a(ps, moves, part, false);
}

int		at_least_one_lq(int x, int *b, int med)
{
	while (--x > 0)
	{
		if (b[x + 1] <= med)
			return (true);
	}
	return (false);
}  

int		at_least_one_mq(int x, int *b, int med)
{
	while (--x > 0)
	{
		if (b[x + 1] >= med)
			return (true);
	}
	return (false);
}  

int		push_med_to_a(int **a, int **b, int medi, t_list **moves)
{
	int		med;
	int		total_push;
	int		total;
	int		i;
	int		total_back;

	while (medi <= 3 && medi-- > 0)
		operation("pa", a, b, moves); 
	med = find_med((*b), medi;
	i = 0;
	total = medi;
	total_push = 0;
	total_back = 0;
	//ici je push au dessus de la mediane de B a A
	//il faut implementer untest pour savoir s'il reste un nombre dan le reste de la stack qui doivent etre push
	while (++i <= total && at_least_one_mq(total - i, *b, med))
	{
		if ((*b)[1] >= med)
		{
			operation("pa", a, b, moves);
			total_push++;
		}
		else if (i != total && total_back++)
			operation("rb", a, b, moves);
	}
	while (total_back-- > 0)
		operation("rrb", a, b, moves);
	return (total_push);
}

int	extract_part(t_list **part)
{
	int		*buff;
	t_list	*swp;
	int		res;

	buff = (int*)((*partition)->content);
	res = *buff;
	swp = (*partition);
	(*partition) = (*partition)->next;
	ft_lstdelone(swp, free);
	return (res);
}

int	sort_stack_b(t_ps *ps)
{
	int		med;

	med = find_med((*b), (*b)[0]);
}

int	sorter(t_ps *ps)
{
	t_list		*moves;
	t_list		*partition;
	int			part;

	moves = ft_lstnew(NULL);
	partition = ft_lstnew(NULL);
	check_stacks(ps->a, ps->b, &partition, &moves);
	ft_lstadd_front(&partition, ft_lstnew(ft_intdup(put_stack_b(ps->a, ps->b, &moves))));
	ps->count_to_sort = 0;
	while ((*b)[0] > 0)
		ft_lstadd_front(&partition, ft_lstnew(ft_intdup(sort_stack_b(ps, &moves))));
	part = extract_part(&partition);
}
