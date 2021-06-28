#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

typedef enum	e_move{

	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
}				t_move;
void	print_stack(t_list *a, t_list *b);
int		parser(t_list **a, t_list **b, char **argv);
void	*ft_malloc(size_t i);
void	convert_to_index(t_list *a);


#endif
