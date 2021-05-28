#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MOT 1,"aaaaaa\n",3

extern int	ft_write(int fd, char *str, int nb);
extern int	ft_read(int fd, char *str, int nb);
extern char	*ft_strdup(char *str);
/*int		main(void)
{
	printf("  ->  %li\n", write(MOT));
	printf("  ->  %i\n", ft_write(MOT));
	return (0);
}*/

int	(void)
{
	printf("str = %s\n", ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscingelit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquambibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Crasvolutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisifelis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellusac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posueretortor, sit amet consequat amet."));
	return (0);
}

int		aaaaaaaaaaaa(void)
{
	char	c1[89];
	char	c2[89];
	
	int		fd = open("pas.txt", O_RDONLY);
	printf("fd = %i\n", fd);
	if (fd < 0)
		return (-1);
	int res = read(fd, c1, 67);
	printf("s = %i\n", res);
	c1[res] = 0;
	printf("read -> %s\n", c1);
	close(fd);

	fd = open("pas.txt", O_RDONLY);
	printf("fd = %i\n", fd);
	if (fd < 0)
		return (-1);
	res = ft_read(fd, c2, 67);
	c2[res] = 0;
	printf("s = %i\n", res);
	printf("ft_read -> %s\n", c2);
	
	return (0);
}
