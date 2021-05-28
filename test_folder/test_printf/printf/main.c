#include "Includes/printf.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str = "|C%*cC|";

	ft_printf("|%0-10.5i|\n", -216);
	printf("|%0-10.5i|\n", -216);
	return (0);
}
