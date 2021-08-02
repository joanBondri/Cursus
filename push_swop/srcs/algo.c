#include "push_swap.h"

int	push_to_a(t_list **a, t_list **b, int hwmny)
{
	int		pivot;
	int		res;

	printf("PUSH TO A\n");
	if (hwmny == -1)
		hwmny = ft_lstsize(*b);
	pivot = find_med(b, hwmny);
	res = 0;
	while (hwmny--)
	{
		if (*((int*)(*b)->content) >= pivot)
		{
			res++;
			moves(PA, a, b);
		}
		else
			moves(RB, a, b);
	}
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
	printf(GRN"PUSH BACK TO B\n"RESET);
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
		if (*((int*)(*a)->content) <= pivot)
		{
			res++;
			moves(PB, a, b);
		}
		else
			moves(RA, a, b);
	}
	push_part(part, res);
	sort_few_num(a, b, ft_lstsize(*a));
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
		res = push_to_a(a, b, res);
		while (res > 3)
			res -= push_back_to_b(a, b, res, &part);
		sort_few_num(a, b, res);
	}
}
