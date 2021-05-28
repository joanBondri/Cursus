#include <stdio.h>
#include <string.h>

int		main(void)
{
	int		i;

	i = -1;
	while (++i < 134)
	{
		perror("huit\n");
		printf("i : %i\t-> %s\n", i, strerror(i));
	}
}
