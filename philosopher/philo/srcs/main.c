#include "philosopher.h"

void	print_error(void)
{
	printf("Error\n");
}

int	main(int argc, char **argv)
{
	t_data_philo	*data;

	data = malloc(sizeof(t_data_philo) * 1);
	if (!data)
	{
		print_error();
		return (0);
	}
	if (parser(argc, argv, data))
	{
		free(data);
		print_error();
		return (1);
	}
	algo(data);
	return (0);	
}
