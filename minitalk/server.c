#include "minitalk.h"

void	test(int y)
{
	printf("je suis un signal = %d\n", y);
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, &test);
	signal(SIGUSR2, &test);
	while (1)
	{
		(void)6;
	}
	return (0);
}
