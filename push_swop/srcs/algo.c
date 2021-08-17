#include "push_swap.h"

int	push_to_a(t_list **a, t_list **b, t_list **part, int hwmny)
{
	int		pivot;
	int		res;
	int		ros;

	//printf(GRN"PUSH TO A\n"RESET);
	if (hwmny < 0)
		hwmny = ft_lstsize(*b);
	if (hwmny == 0)
		exit (0);
	pivot = find_med(b, hwmny);
	if (hwmny <= 3)
		pivot = -1;
	//printf(BLU"hwmny = %i, med = %i\n"RESET, hwmny, pivot);
	res = 0;
	ros = 0;
	while (hwmny--)
	{
		if (*((int*)(*b)->content) >= pivot)
		{
			res++;
			moves(PA, a, b);
		}
		else
		{
			ros++;
			moves(RB, a, b);
		}
	}
	push_part(part, pop_part(part) + ros);
	while (ros--)
		moves(RRB, a, b);
	//print_stack(*a, *b);
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
		if (*((int*)buff->content) > *((int*)(buff->next)->content))
			return (false);
		buff = buff->next;
	}
	return (true);
}

int		push_back_to_b(t_list **a, t_list **b, int hmny, t_list **part)
{
	int		pivot;
	int		res;
	int		rop;

	pivot = find_med(a, hmny);
	res = 0;
	rop = 0;
	//printf(GRN"PUSH BACK TO B\n"RESET);
	while (hmny--)
	{
		if (*((int*)(*a)->content) <= pivot)
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
	//print_stack(*a, *b);
	return (res);
}

void	initial_push(t_list **a, t_list **b, t_list **part)
{
	int		pivot;
	int		size;
	int		ros;
	int		res;

	size = ft_lstsize(*a);
	pivot = size - 3;
	res = 0;
	ros = 0;
	while (size--)
	{
		if (*((int*)(*a)->content) <= pivot)
		{
			res++;
			moves(PB, a, b);
		}
		else
		{
			ros++;
			moves(RA, a, b);
		}
	}
	if (ros--)
		moves(RRA, a, b);
	push_part(part, res);
	sort_few_num(a, b, ft_lstsize(*a));
	//print_stack(*a, *b);
}

//il faut faire une condition pour moins de 5 nombres dans la stack A
void	algo(t_list **a, t_list **b)
{
	t_list	*part;
	int		res;

	if (ft_lstsize(*a) < 3)
		exit(1);
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
