#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

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
int parser(t_list *a, t_list *b, char **argv);
void	*ft_malloc(size_t i);


#endif
