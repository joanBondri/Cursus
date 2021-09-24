#include "all_dep.h"

void	ft_exit(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	exit(1);
}
void	check_args_part_two(int *tba, int *tbb)
{
	int	nbr;
	int	i;
	int	j;

	nbr = tba[0];
	i = 0;
	while (++i <= nbr)
	{
		j = 0;
		while (++j < i)
		{
			if (tba[j] == tba[i])
			{
				free(tba);
				free(tbb);
				ft_exit(RED"same number twice"RESET, 2);
			}
		}
	}
}

void	check_args_part_one(char **argv, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_strchr("-+0123456789", argv[i][j]))
			{
				printf("je suis le petit con qui fait tout beuguee : %s\n", argv[i]);
				ft_exit(RED"wrong argument"RESET, 2);
			}
		}
	}
}

void	special_input(char **argv, int **a, int **b)
{
	char	**strs;
	int		cpt;

	strs = ft_split(argv[0], " ");
	cpt = 0;
	while (strs[cpt])
		cpt++;
	assign_arr(cpt, strs, a, b);
	cpt = -1;
	while (strs[++cpt])
		free(strs[cpt]);
	free(strs);
}

void	assign_arr(int argc, char **argv, int **tba, int **tbb)
{
	int		count;

	if (argc == 1)
		return (special_input(argv, tba, tbb));
	check_args_part_one(argv, argc);
	if (argc < 1)
		ft_exit(RED"too few argument"RESET, 1);
	*tba = malloc(sizeof(int) * argc + 1);
	*tbb = malloc(sizeof(int) * argc + 1);
	if (!(*tbb) || !(*tba))
		ft_exit(RED"Malloc_error"RESET, 2);
    count  = argc;
	while (--count >= 0)
		(*tba)[count + 1] = ft_atoi(argv[count]);
	(*tba)[0] = argc;
	(*tbb)[0] = 0;
	check_args_part_two(*tba, *tbb);
}
