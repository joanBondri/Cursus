#include "all_dep.h"

int		find_med(int *tb)
{
	int		i;
	int		res;
	int		total;

	total = tb[0];
	i = 0;
	if (total == 0)
		return (0);
	res = tb[1];
	while (++i <= total)
	{
		if (tb[i] < res)
			res = tb[i];
	}
	res += total / 2;
	return (res);
}

int		under_three_stack_a(int **a, int **b, t_list **moves)
{
	int		total;

	total = (*a)[0];
	if (total < 2)
		return (0);
	else if (total == 2)
	{
		if ((*a)[1] > (*a)[2])
			operation("sa", a, b, moves);
		return (0);
	}
	else if (total == 3)
	{
		if ((*a)[1] > (*a)[2] && (*a)[2] > (*a)[3])
		{
			operation("sa", a, b, moves);
			operation("rra", a, b, moves);
		}
		else if ((*a)[2] > (*a)[1] && (*a)[1] > (*a)[3])
			operation("rra", a, b, moves);
		else if ((*a)[1] > (*a)[3] && (*a)[3] > (*a)[2])
			operation("ra", a, b, moves);
		else if ((*a)[3] > (*a)[1] && (*a)[1] > (*a)[2])
			operation("sa", a, b, moves);
		else if ((*a)[2] > (*a)[3] && (*a)[3] > (*a)[1])
		{
			operation("rra", a, b, moves);
			operation("sa", a, b, moves);
		}
	}
	return (0);
}

int		under_three_stack_b(int **a, int **b, t_list **moves)
{
	int		total;
	int		i;

	total = (*b)[0];
	if (total == 0)
		return (0);
	else if (total == 1)
	{
		operation("pa", a, b, moves);
		return (1);
	}
	else if (total == 2)
	{
		if ((*b)[1] < (*b)[2])
			operation("sb", a, b, moves);
		operation("pa", a, b, moves);
		operation("pa", a, b, moves);
		return (2);
	}
	else if (total == 3)
	{
		if ((*b)[1] < (*b)[2] && (*b)[2] < (*b)[3])
		{
			operation("sb", a, b, moves);
			operation("rrb", a, b, moves);
		}
		else if ((*b)[2] < (*b)[1] && (*b)[1] < (*b)[3])
			operation("rrb", a, b, moves);
		else if ((*b)[1] < (*b)[3] && (*b)[3] < (*b)[2])
			operation("rb", a, b, moves);
		else if ((*b)[3] < (*b)[1] && (*b)[1] < (*b)[2])
			operation("sb", a, b, moves);
		else if ((*b)[2] < (*b)[3] && (*b)[3] < (*b)[1])
		{
			operation("rrb", a, b, moves);
			operation("sb", a, b, moves);
		}
		i = -1;
		while (++i < 3)
			operation("pa", a, b, moves);
		return (3);
	}
	return (0);
}

int		sort_stack_b(int **a, int **b, t_list **moves)
{
	int		med;
	int		i;
	int		total;
	int		res;

	med = find_med(*b);
	i = 0;
	total = (*b)[0];
	if (total <= 3)
		return (under_three_stack_b(a, b, moves));
	res = 0;
	while (++i <= total)
	{
		if ((*b)[1] < med)
		{
			operation("pa", a, b, moves);
			res++;
		}
		else
			operation("rb", a, b, moves);
	}
	return (res);
}

int		put_stack_b(int **a, int **b, t_list **moves)
{
	int		med;
	int		i;
	int		total;
	int		res;

	med = find_med(*a);
	i = 0;
	total = (*a)[0];
	res = 0;
	while (++i <= total)
	{
		if ((*a)[1] < med)
		{
			operation("pb", a, b, moves);
			res++;
		}
		else
			operation("ra", a, b, moves);
	}
	return (res);
}

void	check_stacks(int **a, int **b, t_list **partition, t_list **moves)
{
	int		count;

	count = 0;
	if ((*b)[0] != 0)
		return ;
	while (++count < (*a)[0])
	{
		if ((*a)[count] >= (*a)[count + 1])
			return ;
	}
	ft_lstclear(partition, free);
	print_moves(moves);
	free(*a);
	free(*b);
	exit(0);
}

int		ft_min_tab(int *a)
{
	int		total;
	int		i;
	int		res;

	total = a[0];
	i = 0;
	res = INT_MAX;
	while (++i <= total)
	{
		if (res > a[i])
			res = a[i];
	}
	return (res);

}

void	print_moves(t_list **moves)
{
	t_list		*defil;

	defil = *moves;
	while (defil)
	{
		ft_putendl_fd((char*)defil->content, 1);
		defil = defil->next;
	}
	ft_lstclear(moves, free);
}

void	with_under_five(int **a, int **b)
{
	t_list		*moves;
	int			i;
	int			swp;

	moves = ft_lstnew(NULL);
	i = 0;
	while ((*a)[0] > 3)
	{
		i++;
		swp = ft_min_tab(*a);
		while((*a)[1] != swp)
			operation("ra", a, b , &moves);
		operation("pb", a, b , &moves);
	}
	under_three_stack_a(a, b, &moves);
	while (--i >= 0)
		operation("pa", a, b, &moves);
	print_moves(&moves);
	free(*a);
	free(*b);
	exit(0);
}

void	manage_sort(int **a, int **b)
{
	t_list		*moves;
	t_list		*partition;
	t_list		*swp;
	int			*buff;
	int			part;

	moves = ft_lstnew(NULL);
	partition = ft_lstnew(NULL);
	check_stacks(a, b, &partition, &moves);
	ft_lstadd_front(&partition, ft_lstnew(ft_intdup(put_stack_b(a, b, &moves))));
	while (true)
	{
		while ((*b)[0] > 0)
			ft_lstadd_front(&partition, ft_lstnew(ft_intdup(sort_stack_b(a, b, &moves))));
		buff = (int*)(partition->content);
		part = *buff;
		swp = partition;
		partition = partition->next;
		ft_lstdelone(swp, free);
		part++;
		while (--part > 0)
			operation("ra", a, b, &moves);
		check_stacks(a, b, &partition, &moves);
		buff = (int*)(partition->content);
        part = *buff;
		swp = partition;
		partition = partition->next;
		ft_lstdelone(swp, free);
		part++;
		while (--part > 0)
			operation("pb", a, b, &moves);
	}
}
