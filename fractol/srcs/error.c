#include "fractol.h"

void	print_error_text(void)
{
	int		fd;
	char	*s;

	s = NULL;
	fd = open("error.txt", O_RDWR);
	ft_putendl_fd("\033[0;31mError\033[0m with parameter", 0);
	while (get_next_line(fd, &s) == 1)
	{
		ft_putendl_fd(s, 0);
		free(s);
		s = NULL;
	}
	free(s);
	exit(0);
}
