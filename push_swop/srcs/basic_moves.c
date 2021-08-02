#include "push_swap.h"

bool	move_rr(int move, t_list **a, t_list **b)
{
	t_list	*buff;

	if (move == RRA)
	{
		if (ft_lstsize(*a) < 2)
			return (false);
		buff = ft_lstuntie_last(*a);
		ft_lstadd_front(a, buff);
		return (true);
	}
	else if (move == RRB)
	{
		if (ft_lstsize(*b) < 2)
			return (false);
		buff = ft_lstuntie_last(*b);
		ft_lstadd_front(b, buff);
		return (true);
	}
	else
		return (move_rr(RRA, a, b) || move_rr(RRB, a, b));
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
		return (move_r(RA, a, b) || move_r(RB, a, b));
	
}

bool	move_p(int move, t_list **a, t_list **b)
{
	t_list	*buff;

	if (move == PA)
	{
		if (ft_lstsize(*b) < 1)
			return (false);
		buff = *b;
		*b = buff->next;
		ft_lstadd_front(a, buff);
		return (true);
	}
	else
	{
		if (ft_lstsize(*a) < 1)
			return (false);
		buff = *a;
		*a = buff->next;
		ft_lstadd_front(b, buff);
		return (true);
	}
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

void	moves(int move, t_list **a, t_list **b)
{
	static char	*tb[] = {"sa", "sb", "ss", "ra", "rb",
		"rr", "rra", "rrb", "rrr", "pa", "pb"};
	bool		res;

	if (move < 1 || move > 11)
		return ;
	if (move == SA || move == SB || move == SS)
		res = move_s(move, a, b);
	else if (move == RA || move == RB || move == RR)
		res = move_r(move, a, b);
	else if (move == RRA || move == RRB || move == RRR)
		res = move_rr(move, a, b);
	else
		res = move_p(move, a, b);
	if (res)
		printf("%s\n", tb[move - 1]);	
	static int	i = 0;	
	printf("#%i\n", i++);
	print_stack(*a, *b);
	sleep(1);
}
