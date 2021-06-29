#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA 1
# define SB 2
# define SS 3
# define RA 4
# define RB 5
# define RR 6
# define RRA 7
# define RRB 8
# define RRR 9
# define PA 10
# define PB 11
# include "libft.h"
# include <limits.h>

void	print_stack(t_list *a, t_list *b);
int		parser(t_list **a, char **argv);
void	*ft_malloc(size_t i);
void	convert_to_index(t_list **a);


#endif
