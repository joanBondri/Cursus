#ifndef UTILS_H
# define UTILS_H

void	print_stack(int *a, int *b);

void	ft_exit(char *str, int fd);
void	check_args_part_two(int *tba, int *tbb);
void	check_args_part_one(char **argv, int argc);
void	assign_arr(int argc, char **argv, int **tba, int **tbb);

void	operation(char *str, int **a, int **b, t_list **moves);
void	s_op(char *str, int **a, int **b);
void	rr_op(char *str, int **a, int **b);
void	r_op(char *str, int **a, int **b);
void	p_op(char *str, int **a, int **b);

#endif
