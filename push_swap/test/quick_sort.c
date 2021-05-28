#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	int		total;
	int		i;
	int		tb[argc];

	if (argc < 2)
		return (0);
	total = argc - 1;
	i = 0;
	while (++i <= total)
		tb[i - 1] = atoi(argv[i]);
	i = -1;
	while (++i < total)
		printf("tb[%i] = %6i\n", i, tb[i]);
	return (0);
}
