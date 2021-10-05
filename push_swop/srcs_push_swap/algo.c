#include "push_swap.h"

bool	pain(t_list *a, int st, int end)
{
	t_list	*swp;

	swp = a;
	while (swp)
	{
		if (*((int *)(swp)->content) >= st && *((int *)(swp)->content) <= end)
			return (true);
		swp = swp->next;
	}
	return (false);
}

void	push_to_b(t_list **a, t_list **b, int start, int end)
{
	int		count;

	count = 0;
	while (pain(*a, start, end))
	{
		if (*((int *)(*a)->content) >= start && *((int *)(*a)->content) <= end)
			moves(PB, a, b);
		else
		{
			count++;
			moves(RA, a, b);
		}
	}
	while (count--)
		moves(RRA, a, b);
}

int	push_back_sorted_a(t_list **a, t_list **b)
{
	int		count;

	count = 0;
	while (*b)
	{
		if (find_max(*b) == (*(int *)(*b)->content))
		{
			count++;
			moves(PA, a, b);
		}
		else if (find_idx_max(*b) + 1 > ft_lstsize(*b) / 2)
			moves(RRB, a, b);
		else
			moves(RB, a, b);
	}
	return (count);
}

void	final_algo(t_list **a, t_list **b, double prt)
{
	double	start;
	double	end;
	int		count;
	double	size;

	size = (double)ft_lstsize(*a);
	start = 1;
	end = size / prt;
	while (!check_stack(a, b) && start <= size)
	{
		push_to_b(a, b, (int)start, (int)end);
		count = push_back_sorted_a(a, b);
		while (count--)
			moves(RA, a, b);
		start += size / prt;
		end += size / prt;
	}
}

void	algo(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 10)
		return (algo10(a, b));
	else if (ft_lstsize(*a) < 300)
		return (final_algo(a, b, 4));
	return (final_algo(a, b, 8));
}
