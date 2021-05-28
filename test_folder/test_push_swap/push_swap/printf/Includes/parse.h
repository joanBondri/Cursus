#ifndef PARSE_H
# define PARSE_H
# include "basic_elem.h"

void	*get_next_param(char c, va_list *list);
void	*get_next_param2(char c, va_list *list);
char	*set_str_null(void);
int		parse_width(char *str, int i, t_printf *a_conv, va_list *list);
void	parse_precision(char *str, t_printf *a_conv, va_list *list);
void	get_flags_and_next_param(t_printf *a_conv, va_list *list);

#endif
