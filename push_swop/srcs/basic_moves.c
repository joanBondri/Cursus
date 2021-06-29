#include "push_swap.h"

void	moves(int move, t_list **a, t_list **b)
{
	static char	tb[] = {"sa", "sb", "ss", "ra", "rb",
		"rr", "rra", "rrb", "rrr", "pa", "pb"};
	bool		res;

	if (move < 1 || move > 11)
		return ;
	printf("%s\n", tb[move]);
	if (move == SA || move == SB || move == SS)
		res = move_s(move, a, b);
	else if (move == RA || move == RB || move == RR)
		res = move_r(move, a, b);
	else if (move == RRA || move == RRB || move == RRR)
		res = move_rrr(move, a, b);
	else
		res = move_p(move, a, b);
	if (res)
		printf("%s\n", tb[move]);
}

bool	move_rr(int move, t_list **a, t_list **b)
{
	t_list	*buff;

	if (move == RRA)
	{
		if (ft_lstsize(*a) < 2)
			return (false);
		buff = (*a);
		*a = buff->next;
		ft_lstadd_back(a, buff);
		return (true);
	}
	else if (move == RRB)
	{
		if (ft_lstsize(*b) < 2)
			return (false);
		buff = (*b);
		*b = buff->next;
		ft_lstadd_back(b, buff);
		return (true);
	}
	else
		return (move_s(RRA, a, b) || move_s(RRB, a, b));
	
}

bool	move_r(int move, t_list **a, t_list **b)
{
	t_list	*buff;

	if (move == RA)
	{
		if (ft_lstsize(*a) < 2)
			return (false);
		buff = (*a);
		*a = buff->next;
		ft_lstadd_back(a, buff);
		return (true);
	}
	else if (move == RB)
	{
		if (ft_lstsize(*b) < 2)
			return (false);
		buff = (*b);
		*b = buff->next;
		ft_lstadd_back(b, buff);
		return (true);
	}
	else
		return (move_s(RA, a, b) || move_s(RB, a, b));
	
}

bool	move_s(int move, t_list **a, t_list **b)
{
	t_list	*buff;

	if (move == SA)
	{
		if (ft_lstsize(*a) < 2)
			return (false);
		buff = (*a)->next;
		(*a)->next = buff->next;
		buff->next = (*a);
		*a = buff;
		return (true);
	}
	else if (move == SB)
	{
		if (ft_lstsize(*b) < 2)
			return (false);
		buff = (*b)->next;
		(*b)->next = buff->next;
		buff->next = (*b);
		*b = buff;
		return (true);
	}
	else
		return (move_s(SA, a, b) || move_s(SB, a, b));
}
