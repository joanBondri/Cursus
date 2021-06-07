#include "minitalk.h"

void	print_char(bool signal)
{
	static int	c = 0;
	static int	position = 128;

	c += position * signal;
	position /= 2;
	if (!position)
	{
		write(1, &c, 1);
		position = 128;
		c = 0;
	}
}

int	signal_two(int delay)
{
	print_char(false);
	(void)delay;
	return (0);
}

int	signal_one(int delay)
{
	print_char(true);
	(void)delay;
	return (0);
}

int	main(int ac, char **av)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, &signal_one);
	signal(SIGUSR2, &signal_two);
	while (1)
	{
		(void)ac;
		(void)av;
	}
	return (0);
}
