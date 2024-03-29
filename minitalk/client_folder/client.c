#include "minitalk.h"

void	push_char(char c, int pid)
{
	int		position;

	position = 128;
	while (position)
	{
		if (position <= c)
		{
			kill(pid, SIGUSR1);
			c -= position;
		}
		else
			kill(pid, SIGUSR2);
		usleep(60);
		position /= 2;
	}
}

int	main(int argc, char **argv)
{
	char	*s;
	int		pid;
	int		i;

	if (argc < 3 || argc > 3 || !ft_loop_strchr("0123456789", argv[1]))
	{
		if (argc < 3)
			printf("\033[31mERROR\033[m : Too few arguments\n");
		else if (argc > 3)
			printf("\033[31mERROR\033[m : Too many arguments\n");
		else
			printf("\033[31mERROR\033[m : Wrong PID\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	s = argv[2];
	i = -1;
	while (s[++i])
		push_char(s[i], pid);
	(void)argc;
	return (0);
}
