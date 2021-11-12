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
	int		size;
	size = data.size + 1;
		printf("data : \n{\n\tsize : %d,\n\tloop : %d,\n\teat : %d,\n\tdie : %d,\n\tsleep : %d,\n\tplatons : %p\n}\n", data.size, data.loop, data.eat, data.die, data.sleep, data.tb);
	while (--size)
	{
		printf("philo : \n{\n\tid : %d,\n\tlast_sleep : %ld,\n\tforch_left : %p,\n\tforch_right : %p\n}\n", data.tb[size - 1].id, data.tb[size - 1].last_sleep, data.tb[size - 1].forch_left, data.tb[size - 1].forch_right);
	}
	free(data.tb);
	return (0);	
}
