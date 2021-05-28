#include <stdio.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);
int		main(int argc, char **argv)
{
	int		fd;
	char	x[100] = "";
	char	*line;
	int	res;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	res = get_next_line(fd, &line);
	free(line);
	while ((res = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", (line));
		free(line);
	}
	if (argc == 2)
		close(fd);
}
