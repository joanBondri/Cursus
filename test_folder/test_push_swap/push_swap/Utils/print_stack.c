#include "all_dep.h"

void	print_stack(int *a, int *b)
{
	int		num;
	int		i;
	int		pada;
	int		padb;

	ft_printf("\033[2J\033[H");
	ft_printf("%10s|%10s|\n", "A", "B");
	ft_printf("%.22s\n","___________________________");
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
			ft_printf("%10s|%10i|\n", "", b[i]);
		else if (i - padb < 1)
			ft_printf("%10i|%10s|\n", a[i], "");
		else
			ft_printf("%10i|%10i|\n",a[i - pada], b[i - padb]);
	}
	usleep(50000);
}

