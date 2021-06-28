#include "push_swap.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	*ft_malloc(size_t i)
{
	void	*ptr;

	ptr = malloc(i);
	if (!ptr)
		ft_exit("MALLOC : "RED"failed"RESET);
	return (ptr);
}

void	print_stack(t_list *a, t_list *b)
{
	t_list	*stack;
	t_list	*stock;

	printf("|%10s|%10s|\n", "A", "B");
	stack = a->next;
	stock = b->next;
	while (stack || stock)
	{
		if (stack && stock)
			printf("|%10i|%10i|\n", *((int*)stack->content), *((int*)stock->content));
		else if (stack)
			printf("|%10i|%10s|\n", *((int*)stack->content), "");
		else if (stock)
			printf("|%10s|%10i|\n", "", *((int*)stock->content));
		if (stack)
			stack = stack->next;
		if (stock)
			stock = stock->next;
	}
}

int parser(t_list *a, t_list *b, char **argv)
{	
	a = ft_lstnew(NULL);
	b = ft_lstnew(NULL);
	while (*(++(argv)))
	{
		if (!ft_loop_strchr("0123456789", *argv))
			ft_exit("PARSING : "RED"failed"RESET);
		if (!a)
			a = ft_lstnew(int_to_ptr(ft_atoi(*argv)));
		else
			ft_lstadd_back(&a, ft_lstnew(int_to_ptr(ft_atoi(*argv))));
	}
	print_stack(a, b);
	return (0);
}
