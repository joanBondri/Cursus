#include "push_swap.h"

void	sort_three_num(t_list **a, t_list **b)
{
	int		one;
	int		two;
	int		thr;

	if (ft_lstsize(*a) < 3)
		return ;
	one = *((int*)(*a)->content);
	two = *((int*)((*a)->next)->content);
	thr = *((int*)(((*a)->next)->next)->content);
	if (one > two && one < thr)
		moves(SA, a, b);
	else if (one > two && two > thr)
	{
		moves(SA, a, b);
		sort_three_num(a, b);
	}
	else if (one < two && one > thr)
	{
		moves(RA, a, b);
		moves(SA, a, b);
		moves(RRA, a, b);
		sort_three_num(a, b);
	}
	else if (one > thr && thr > two)
	{
		moves(SA, a, b);
		sort_three_num(a, b);
	}
	else if (two > thr && thr > one)
	{
		moves(RA, a, b);
		moves(SA, a, b);
		moves(RRA, a, b);
	}
}

void	sort_two_num(t_list **a, t_list **b)
{
	int		one;
	int		two;

	if (ft_lstsize(*a) < 2)
		return ;
	one = *((int*)(*a)->content);
	two = *((int*)((*a)->next)->content);
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

