#include "all_dep.h"

void	assign_index_tab(int **idx, int **tba)
{
	int		i;
	int		j;
	int		g;
	int		swp;

	i = 0;
	(*idx)[0] = (*tba)[0];
	while (++i <= (*idx)[0])
	{
		j = 0;
		(*idx)[i] = INT_MAX;
		while (++j <= (*tba)[0])
		{
			if ((*tba)[j] < (*idx)[i])
			{
				swp = (*idx)[i];
				(*idx)[i] = (*tba)[j];
				g = 0;
				while (++g < i)
				{
					if ((*idx)[g] == (*idx)[i])
						(*idx)[i] = swp;
				}
			}
		}
	}
}

void	transform_tba(int **a, int **idx)
{
	int		j;
	int		i;

	i = 0;
	while (++i <= (*a)[0])
	{
		j = 0;
		while (++j <= (*idx)[0])
		{
			if ((*a)[i] == (*idx)[j])
				(*a)[i] = j;
		}
	}
	free(*idx);
}

int     main(int argc, char **argv)
{
	int		*tba;
	int		*idx;
	int		*tbb;

	printf("t'envahie mon espace \n");

	assign_arr(argc, argv + 1, &tba, &tbb);
	idx = malloc(sizeof(int) * (tba[0] + 2));
	if (!idx)
		ft_exit(RED"error with malloc"RESET, 2);
	if (argc < 7)
		with_under_five(&tba, &tbb);
	assign_index_tab(&idx, &tba);
	transform_tba(&tba, &idx);
	manage_sort(&tba, &tbb);
    return (0);
}
