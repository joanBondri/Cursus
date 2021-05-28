#include "libft.h"
#include <stdlib.h>

int		*ft_intdup(int num)
{
	int		*ptr;

	ptr = malloc(sizeof(int) * 1);
	if (!ptr)
		return (NULL);
	*ptr = num;
	return (ptr);
}
