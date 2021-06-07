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
		position /= 2;
	}
}

int	main(int argc, char **argv)
{
	char	*s;
	int		pid;
	int		i;

	if (argc == 1)
	{
		printf("\033[31mERROR\033[m : PID missing\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	s = NULL;
	while (get_next_line(0, &s) > -1)
	{
		i = -1;
		while (s[++i])
			push_char(s[i], pid);
		push_char('\n', pid);
		free(s);
		s = NULL;
	}

	(void)argc;
	return (0);
}
