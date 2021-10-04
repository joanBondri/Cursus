#include "all_dep.h"

void	loop_print(int *a, int *b)
{
	int		num;
	int		i;
	int		pada;
	int		padb;

	num = b[0];
	pada = num - a[0];
	padb = 0;
	if (a[0] > b[0])
	{
		num = a[0];
		padb = num - b[0];
		pada = 0;
	}
	i = 0;
	while (++i <= num)
	{
		if (i - pada < 1)
			printf("%10s|%10i|\n", "", b[i]);
		else if (i - padb < 1)
			printf("%10i|%10s|\n", a[i], "");
		else
			printf("%10i|%10i|\n", a[i - pada], b[i - padb]);
	}
	usleep(50000);
}

void	print_stack(int *a, int *b)
{
	static int	index = 0;

	printf("\033[2J\033[H#%i\n%10s|%10s|\n", ++index, "A", "B");
	printf("%.22s\n", "___________________________");
	loop_print(a, b);
}
