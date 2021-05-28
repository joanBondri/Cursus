#include "printf.h"

void	print_str(t_printf *s)
{
	int		i;
	t_bool	null_str;
	char	*str;

	str = (char*)s->data;
	null_str = FALSE;
	if (s->precision < -1)
	{
		s->precision = -1;
		s->dot = FALSE;
	}
	if (str == NULL)
	{
		null_str = TRUE;
		str = set_str_null();
	}
	if (s->precision == -1)
		i = s->width - ft_strlen(str);
	else
		i = s->width - ft_min(s->precision, ft_strlen(str));
	if (!(s->minus))
		put_space(i);
	put_s(str, s);
	if (s->minus)
		put_space(i);
	free_data(null_str, (void *)str);
}

void	free_data(t_bool b, void *data)
{
	if (b)
		free(data);
}

void	put_s(char *str, t_printf *s)	
{
	//printf("je suis cheval (precision de %d)\n", s->precision);
	if (s->precision == -1 || ft_strlen(str) < s->precision)
	{
		put_str(str);
	}
	else
		put_len_str(str, s->precision);
}

