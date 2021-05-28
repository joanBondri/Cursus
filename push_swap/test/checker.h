#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

void	ft_exit(char *str, int fd);
void	s_op(char *str, int **a, int **b);
void	rr_op(char *str, int **a, int **b);
void	r_op(char *str, int **a, int **b);
void	p_op(char *str, int **a, int **b);
void	check_args(int *tba, int *tbb);

#endif
