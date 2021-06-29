#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_list	*a;
	t_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	parser(&a, argv);
	convert_to_index(&a);
	print_stack(a, b);
	return (0);
}
