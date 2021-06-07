#include "minitalk.h"

void	print_char_yop(bool signal)
{
	static char	c = 0;
	static int	position = 128;

	if (signal)
		c+= position;
	printf("%d\n", position);
	position /= 2;
	if (!position)
	{
		write(1, &c, 1);
		position = 128;
		c = 0;
	}
}

void	signal_two(int delay)
{
	print_char_yop(true);
	(void)delay;
}

void	signal_one(int delay)
{
	print_char_yop(false);
	(void)delay;
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
