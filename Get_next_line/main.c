#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int		get_next_line(int fd, char **line);
int		main(void)
{
	int fd = open("42TESTERS-GNL/files/empty_lines", O_RDONLY);
	int	res;
	char *line;
	if (fd == -1)
	{
		printf("pute\n");
	}
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("iiiiiiiiiiih ... c'est fini");
	return (0);
}
