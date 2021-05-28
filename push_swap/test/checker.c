#include "checker.h"

void	print_stack(int *a, int *b)
{
	int		num;
	int		i;
	int		pada;
	int		padb;

	ft_printf("stack:	a			b\n");
	ft_printf("	   --------------------------------------\n");
	if (a[0] > b[0])
	{
		num = a[0];
		padb = num - b[0];
		pada = 0;
	}
	else
	{
		num = b[0];
		pada = num - a[0];
		padb = 0;
	}
	i = 0;
	while (++i <= num)
	{
		if (i - pada < 1)
			ft_printf("					%i\n", b[i]);
		else if (i - padb < 1)
			ft_printf("	%i\n", a[i]);
		else
			ft_printf("	%i			%i\n",a[i - pada], b[i - padb]);
	}
}

void	ft_exit(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\n", fd);
}

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
		(*b)[2] = (*b)[1];
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
    int i;
    int num;
    int swp;

	if (!ft_strncmp(str, "pa", 3))
	{
		src = *b;
		dest = *a;
	}
	else if (!ft_strncmp(str, "pb", 3))
	{
		src = *a;
		dest = *b;
	}
	if (src[0] == 0)
		return ;
	num = src[0];
	swp = src[1];
	i = 0;
	while (++i < num)
		src[i] = src[i + 1];
	i = dest[0] + 1;
	while (--i > 0)
		dest[i + 1] = dest[i];
	dest[1] = swp;
	dest[0] += 1;
	src[0] -= 1;
}

void	check_args(int *tba, int *tbb)
{
	int	nbr;
	int	i;
	int	j;

	nbr = tbb[0];
	i = 0;
	while (++i <= nbr)
	{
		j = 0;
		while (++j < i)
		{
			if (tbb[j] == tbb[i])
			{
				free(tba);
				free(tbb);
				ft_exit("same number twice", 2);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int	*tba;
	int	*tbb;
	int	count;

	if (argc < 2)
		ft_exit("too few argument", 1);
	tba = malloc(sizeof(int) * argc + 1);
	tbb = malloc(sizeof(int) * argc + 1);
	if (!tbb || !tba)
		ft_exit("Malloc_error", 2);
	printf("argc = %i\n", argc);
    count  = argc;
	while (--count > 0)
	{
		tba[count] = ft_atoi(argv[count]);
		printf("arg suivant %i : %i\n", count, tba[count]);
	}
	check_args(tba, tbb);
	tba[0] = argc - 1;
	tbb[0] = 0;
	str = NULL;
	while (get_next_line(0, &str) != -1)
	{
		if (str[0] == 0)
			break ;
		if (!ft_strncmp(str, "sa", 3) || !ft_strncmp(str, "sb", 3) ||
				!ft_strncmp(str, "ss", 3))
			s_op(str, &tba, &tbb);
		else if (!ft_strncmp(str, "pa", 3) || !ft_strncmp(str, "pb", 3))
			p_op(str, &tba, &tbb);
		else if (!ft_strncmp(str, "ra", 3) || !ft_strncmp(str, "rb", 3) ||
				!ft_strncmp(str, "rr", 3))
			r_op(str, &tba, &tbb);
		else if (!ft_strncmp(str, "rra", 4) || !ft_strncmp(str, "rrb", 4) ||
				!ft_strncmp(str, "rrr", 4))
			rr_op(str, &tba, &tbb);

		else if (!ft_strncmp(str, "prt", 6))
			print_stack(tba, tbb);

		else
			ft_exit("unknown command", 2);
		free(str);
		str = NULL;
	}
	count = 0;
	printf("a = %i b = %i\n", tba[0], tbb[0]);
	print_stack(tba, tbb);
	if (tbb[0] > 0)
	{
		ft_exit("KO", 1);
	}
	while (++count < tba[0])
	{
		if (tba[count] >= tba[count + 1])
		{
			ft_exit("KO", 1);
		}
	}
	ft_exit("OK", 1);
	return (0);
}
