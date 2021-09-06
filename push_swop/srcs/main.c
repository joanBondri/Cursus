#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_list	*a;
	t_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	parser(&a, argv, argc);
	convert_to_index(&a);
	algo(&a, &b);
	return (0);
}
