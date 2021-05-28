#define BUFFER_SIZE 100
#include <stdio.h>
#include <stdlib.h>

int	create_new_line(char **new, char ***line)
{
	int	i;

	i = 0;
	while ((**line)[i])
		i++;
	if (!(*new = malloc(sizeof(char) * (i + 1))))
		return (-1);
	i = -1;
	while ((**line)[++i])
		(*new)[i] = (**line)[i];
	(*new)[i] = 0;
	return (1);
}

int	assign(char ***line, char *x)
{
	int	i;
	int	j;
	char	*new;

	if(-1 == (create_new_line(&new, line)))
		return (-1);
	i = 0;
	while (new[i])
		i++;
	j = 0;
	while (x[j] && x[j] != '\n')
		j++;
	free(**line);
	if (!(**line = malloc(sizeof(char) * (i + j + 1))))
		return (-1);
	(**line)[i + j] = 0;
	i = -1;
	while (new[++i])
		(**line)[i] = new[i];
	j = -1;
	while (x[++j] && x[j] != '\n')
		(**line)[i + j] = x[j];
	if(x[j] == '\n')
		return (j + 1);
	return (0);
}

int	recurs(char **line, int fd)
{
	static char	x[BUFFER_SIZE + 1] = "";
	int	res;
	int	i;

	res = assign(&line, (char*)&x);
	if (!res)
	{
		res = read(fd, x, BUFFER_SIZE);
		x[res] = 0;
		if (res == 0)
			return (0);
		return (recurs(line, fd));
	}
	if (res == -1)
		return -1;
	i = -1;
	while (res + ++i < BUFFER_SIZE)
		x[i] = x[res + i];
	while (i < BUFFER_SIZE)
	{
		x[i] = 0;
		i++;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	if (!line || fd < 0)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	(*line)[0] = 0;
	return (recurs(line, fd));
}
