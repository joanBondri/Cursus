#include "all_dep.h"

void	s_op(char *str, int **a, int **b)
{
	int	swap;

	if (!ft_strncmp(str, "sa", 3))
	{
		if ((*a)[0] < 2)
			return ;
		swap = (*a)[1];
		(*a)[1] = (*a)[2];
		(*a)[2] = swap;
	}
	else if (!ft_strncmp(str, "sb", 3))
	{
		if ((*b)[0] < 2)
			return ;
		swap = (*b)[1];
		(*b)[1] = (*b)[2];
		(*b)[2] = swap;
	}
}

void	rr_op(char *str, int **a, int **b)
{
	int	num;
	int	swp;
	int	i;
	int	*tb;

	if (!ft_strncmp(str, "rra", 4))
		tb = *a;
	else if (!ft_strncmp(str, "rrb", 4))
		tb = *b;
	else
	{
		rr_op("rra", a, b);
		rr_op("rrb", a, b);
		return ;
	}
	num = tb[0];
	swp = tb[num];
	i = num + 1;
	if (num < 2)
		return ;
	while (--i > 1)
		tb[i] = tb[i - 1];
	tb[i] = swp;
}

void	r_op(char *str, int **a, int **b)
{
	int	num;
	int	swp;
	int	i;
	int	*tb;

	if (!ft_strncmp(str, "ra", 3))
		tb = *a;
	else if (!ft_strncmp(str, "rb", 2))
		tb = *b;
	else
	{
		r_op("ra", a, b);
		r_op("rb", a, b);
		return ;
	}
	num = tb[0];
	swp = tb[1];
	if (num < 2)
		return ;
	i = 0;
	while (++i < num)
		tb[i] = tb[i + 1];
	tb[i] = swp;
}

void	p_op(char *str, int **a, int **b)
{
	int	*src;
	int	*dest;
	int	i;
	int	swp;

	src = *a;
	dest = *b;
	if (!ft_strncmp(str, "pa", 3))
	{
		src = *b;
		dest = *a;
	}
	if (src[0] == 0)
		return ;
	swp = src[1];
	i = 0;
	while (++i < src[0])
		src[i] = src[i + 1];
	i = dest[0] + 1;
	while (--i > 0)
		dest[i + 1] = dest[i];
	dest[1] = swp;
	dest[0] += 1;
	src[0] -= 1;
}

void	operation(char *str, int **a, int **b, t_list **moves)
{
	if (!ft_strncmp(str, "sa", 3) || !ft_strncmp(str, "sb", 3)
		|| !ft_strncmp(str, "ss", 3))
		s_op(str, a, b);
	else if (!ft_strncmp(str, "pa", 3) || !ft_strncmp(str, "pb", 3))
		p_op(str, a, b);
	else if (!ft_strncmp(str, "ra", 3) || !ft_strncmp(str, "rb", 3)
		|| !ft_strncmp(str, "rr", 3))
		r_op(str, a, b);
	else if (!ft_strncmp(str, "rra", 4) || !ft_strncmp(str, "rrb", 4)
		|| !ft_strncmp(str, "rrr", 4))
		rr_op(str, a, b);
	else
		return ;
	ft_lstadd_back(moves, ft_lstnew(ft_strdup(str)));
}
