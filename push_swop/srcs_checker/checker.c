#include "all_dep.h"

int	main(int argc, char **argv)
{
	char	*str;
	int	*tba;
	int	*tbb;
	int	count;
	t_flags		flags;

	flags.view = false;
	if (!ft_strncmp(argv[1], "-v", 3) || !ft_strncmp(argv[1], "--view", 7))
	{
		flags.view = true;
		argv++;
		argc--;
	}
	assign_arr(argc - 1, argv + 1, &tba, &tbb);
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
		else
		{
			ft_putendl_fd(RED"unknown command"RESET, 2);
			free(str);
			str = NULL;
			continue ;
		}
		if (flags.view)
			print_stack(tba, tbb);
		free(str);
		str = NULL;
	}
	count = 0;
	if (tbb[0] > 0)
		ft_exit(RED"KO"RESET, 1);
	while (++count < tba[0])
	{
		if (tba[count] >= tba[count + 1])
			ft_exit(RED"KO"RESET, 1);
	}
	ft_exit(GRN"OK"RESET, 1);
	return (0);
}
