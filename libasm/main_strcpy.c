#include <string.h>
#include <stdio.h>


extern char	*ft_strcpy(char *dest, char *src);
int		main(void)
{
	char *dest = "QWERTYUIOPASDFGHJKL;ZXCVBNM";
	printf("nan je segfault pas pour aucune raison\n");
	printf("dest = %s\n", ft_strcpy(dest, "la drogue\0"));
	return (0);
}
