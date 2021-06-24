#include "push_swap.h"

void	ft_exit(void)
{
	exit(0);
}

void	*ft_malloc(t_size i)
{
	void	*ptr;

	ptr = malloc(i);
	if (!ptr)
		ft_exit();
	return (ptr);
}

int parser(char **argv, t_list *a, t_list *b)
{	
	while (++*argv)
	{
		if (!ft_loop_strchr(*argv, "0123456789"))
			ft_exit();
		ft_lstadd_back(&a, ft_lstnew(int_to_ptr(ft_atoi(*argv))));
	}
}
