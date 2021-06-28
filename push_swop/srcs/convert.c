#include "push_swap.h"

void	put_min_in_tb(int *tb, t_list *a)
{
	static int	index = 1;
	t_list		*buff;
	int			i;
	int			min;

	min = INT_MAX;
	buff = a->next;
	i = 0;
	while (buff && ++i)
	{
		if (*((int*)buff->content) < min && tb[i] == 0)
			min = *((int*)buff->content);
		buff = buff->next;
	}
	i = -1;
	buff = a->next;
	while (buff)
	{
		i++;
		if (*((int*)buff->content) == min)
			break ;
		buff = buff->next;
	}
	tb[i] = index;
	index++;
}

void	convert_to_index(t_list *a)
{
	int			i;
	t_list		*buff;
	int			*tb;
	int			size;

	size = ft_lstsize(a);
	tb = (int*)ft_malloc(sizeof(int) * (size + 1));
	tb = (int*){0};
	int yop = 0;
	printf("tb = %p\n", tb);
	while (++yop < size)
		printf("%i : %i\n", yop, tb[yop]);
	i = 0;
	while (++i < size)
		put_min_in_tb(tb, a);
	i = 0;
	buff = a->next;
	while (++i < size && buff)
	{
		*((int*)buff->content) = tb[i];
		buff = buff->next;
	}
	free(tb);
}
