#include "minitalk.h"

void	push_char(char c, int pid)
{
	int		position;

	position = 128;
	while (position)
	{
		if (position <= c)
		{
			kill(SIGUSR1, pid);
			c -= position;
		}
		else
			kill(SIGUSR2, pid);
		position /= 2;
	}
}

int	main(int argc, char **argv)
{
	char	*s;
	int		pid;

	pid = ft_atoi(argv[1]);
	
	return (0);
}
