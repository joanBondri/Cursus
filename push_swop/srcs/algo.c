#include "push_swap.h"

void	push_to_a(t_list **a, t_list **b, int hwmny)
{
	int		pivot;
	int		res;
	t_list	buff;

	if (hwmny == -1)
		hwmny = ft_lstsize(*b);
	pivot = find_med(b, hwmny);
	res = 0;
	buff = *b;
	while (--hwmny && buff)
	{
		if (*((int)buff->content) > pivot)
		{
			res++;
			moves(PA, a, b);
		}
		else
			moves(RB, a, b);
		buff = buff->next;
	}
}

void	initial_push(t_list **a, t_list **b, t_list **part)
{
	int		pivot;
	int		size;
	int		res;
	t_list	buff;

	size = ft_lstsize(*a);
	pivot = size - 3;
	buff = *a;
	res = 0;
	while (size-- && buff)
	{
		if (*((int)buff->content) < pivot)
		{
			res++;
			moves(PB, a, b);
		}
		else
			moves(RA, a, b);
		buff = buff->next;
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
	while (check_stacks(a, b))
	{
		res = push_to_a(a, b, pop_part(&part));
		while (res > 3)
			res -= push_back_to_b(a, b, res, &part);
		sort_few_num(a, b, res);
	}
}
