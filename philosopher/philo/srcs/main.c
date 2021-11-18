#include "philosopher.h"

void	print_error(void)
{
	printf("Error\n");
}

int	main(int argc, char **argv)
{
	t_data_philo	data;

	if (parser(argc, argv, &data))
	{
		print_error();
		return (1);
	}
	algo(&data);
	return (0);	
}
