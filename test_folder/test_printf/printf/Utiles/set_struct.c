#include "printf.h"

void	set_null_struct(t_printf *s)
{
	s->start = NULL;
	s->type_conversion = '\0';
	s->data = NULL;
	s->width = -1;
	s->precision = -1;
	s->zero = FALSE;
	s->minus = FALSE;
	s->dot = FALSE;
}

void	*get_next_param(char c, va_list *list)
{
	long long int	*ch;
	char	*str;
	void	*p;

	if (c == 'c')
	{
		if (!(ch = malloc(sizeof(long long int) * (1))))
			return (NULL);
		*ch = (va_arg(*list, int));
		return ((void *)ch);
	}
	if (c == 's')
	{
		str = va_arg(*list, char*);
		return ((void *)str);
	}
	if (c == 'p')
	{
		p = va_arg(*list, void*);
		return (p);
	}
	return (get_next_param2(c, list));
}

void	*get_next_param2(char c, va_list *list)
{
	unsigned int	*uni;
	int				*a;

	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
	{
		if (!(a = malloc(sizeof(int) * (1))))
			return (NULL);
		*a = va_arg(*list, int);
		return ((void *)a);
	}
	if (c == 'u')
	{
		if (!(uni = malloc(sizeof(unsigned int) * (1))))
			return (NULL);
		*uni = va_arg(*list, unsigned int);
		return ((void *)uni);
	}
	return (NULL);
}

char	*set_str_null(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (7))))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

int		parse_width(char *str, int i, t_printf *a_conv, va_list *list)
{
	int		atoi_buff;

	if (ft_isdigit(str[i]))
	{
		atoi_buff = ft_atoi(str + i);
		if (atoi_buff < 0)
			a_conv->minus = TRUE;
		while (ft_isdigit(str[i]))
			i++;
		a_conv->width = ft_abs(atoi_buff);
	}
	else
	{
		atoi_buff = va_arg(*list, int);
		if (atoi_buff < 0)
			a_conv->minus = TRUE;
		a_conv->width = ft_abs(atoi_buff);
		i++;
	}
	return (i);
}

int		parse_precision(char *str, int i, t_printf *a_conv, va_list *list)
{
	int		atoi_buff;

	a_conv->dot = TRUE;
	i++;
	if (ft_isdigit(str[i]))
	{
		atoi_buff = ft_atoi(str + i);
		a_conv->precision = atoi_buff;
		while (ft_isdigit(str[i]))
			i++;
		i += size_of_number(a_conv->precision, INIT);
	}
	else if (str[i] == '*')
	{
		a_conv->precision = va_arg(*list, int);
		i++;
	}
	else
		a_conv->precision = 0;
	return (i);
}

void	get_flags_and_next_param(t_printf *a_conv, va_list *list)
{
	char	*str;
	int		i;

	str = a_conv->start;
	i = 0;
	while ((str[i] == '0' || str[i] == '-'))
	{
		if (str[i] == '0')
			a_conv->zero = TRUE;
		if (str[i] == '-')
			a_conv->minus = TRUE;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = parse_width(str, i, a_conv, list);
	if (str[i] == '.')
		i = parse_precision(str, i, a_conv, list);
	a_conv->data = get_next_param(a_conv->type_conversion, list);
}