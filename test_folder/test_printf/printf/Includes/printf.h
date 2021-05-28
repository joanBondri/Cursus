#ifndef PRINTF_H
# define PRINTF_H
# define TRUE 1
# define FALSE 0
# define INIT 0
# define INT_MINIMUM -2147483648
# define LEN_PTR 8
# define LEN_NIL 3
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef int		t_bool;
typedef struct	s_printf
{
	char	*start;
	char	type_conversion;
	void	*data;
	int		width;
	int		precision;
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
}				t_printf;
void	print(char c, t_printf *s);
void	print_uint(t_printf *s);
void	print_pointer(t_printf *s);
void	print_upper_hexa(t_printf *s);
void	print_lower_hexa(t_printf *s);
void	print_percent(t_printf *s);
void	print_zero_percent(t_printf *s);
void	print_str(t_printf *s);
void	print_char(t_printf *s);
void	print_int(t_printf *s);
void	print_precision_unbr(t_printf *s);
void	print_zero_nbr(t_printf *s);
void	print_precision_nbr(t_printf *s);
void	put_s(char *str, t_printf *s);
int		size_of_unumber(unsigned int i, int n);
int		size_of_number(int i, int n);
int		ft_abs(int i);
int		ft_max(int i_1, int i_2);
int		ft_min(int i_1, int i_2);
void	print_space_precision_nbr(t_printf *s);

void	put_pointer(unsigned long int n, int count);
void	print_pointer(t_printf *s);
void	print_precision_pointer(t_printf *s);
void	print_space_precision_pointer(t_printf *s);
void	print_nil(t_printf *s);

void	print_hexa(t_printf *s);
void	print_precision_hexa(t_printf *s);
int		size_of_hexa(unsigned int i, int n);
void	print_space_precision_hexa(t_printf *s);

void	print_uint(t_printf *s);
void	print_precision_unbr(t_printf *s);
int		size_of_unumber(unsigned int i, int n);
void	print_space_precision_unbr(t_printf *s);

void	put_char(long long int c);
int		get_number_char(int n);
void	put_str(char *str);
void	put_len_str(char *str, int len);
void	put_nbr(int n);
void	put_unbr(unsigned int n);
void	put_hexa(unsigned int n, char (*char_hexa)(unsigned int));
char	get_upper_hexa(unsigned int n);
char	get_lower_hexa(unsigned int n);
void	put_space(int i);

void	set_null_struct(t_printf *s);
void	*get_next_param(char c, va_list *list);
void	*get_next_param2(char c, va_list *list);
char	*set_str_null(void);
void	get_flags_and_next_param(t_printf *a_conv, va_list *list);

t_bool	is_valid_flags(char c);
t_bool	is_convert_letter(char c);
int		ft_printf(const char *prin, ...);
int		special_case(char *prin, int i, va_list *list, t_printf *data);
int		parse_width(char *s, int i, t_printf *a_conv, va_list *list);
int		parse_width(char *s, int i, t_printf *a_conv, va_list *list);
void	free_data(t_bool b, void *data);

#endif
