#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct	s_ps
{
	int		**a;
	int		**b;
	int		count_to_sort;
}				t_ps;

void	assign_index_tab(int **idx, int **tba);

int		find_med(int *tb);
int		under_three_stack_b(int **a, int **b, t_list **moves);
int		sort_stack_b(int **a, int **b, t_list **moves);
int		put_stack_b(int **a, int **b, t_list **moves);
void	vide(void *i);
void	check_stacks(int **a, int **b, t_list **partition, t_list **moves);
void	manage_sort(int **a, int **b);

void	with_under_five(int **a, int **b);
void	print_moves(t_list **moves);
int		ft_min_tab(int *a);
int		under_three_stack_a(int **a, int **b, t_list **moves);


#endif
