#include "printf.h"

void	*get_next_param(char c, va_list *list)
{
	char		*ch;
	char		*str;
	void		*p;

	if (c == 'c')
	{
		if (!(ch = malloc(sizeof(char) * (1))))
			return (NULL);
		ch[0] = (char)(va_arg(*list, int));
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

	if (ft_strchr("dixX", c))
	{
		if (!(a = malloc(sizeof(int) * (1))))
			return (NULL);
		a[0] = va_arg(*list, int);
		return ((void *)a);
	}
	if (c == 'u')
	{
		if (!(uni = malloc(sizeof(unsigned int) * (1))))
			return (NULL);
		uni[0] = va_arg(*list, unsigned int);
		return ((void *)uni);
	}
	return (NULL);
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

void	parse_precision(char *str, t_printf *a_conv, va_list *list)
{
	a_conv->dot = TRUE;
	if (ft_isdigit(*str))
		a_conv->precision = ft_atoi(str);
	else if (*str == '*')
		a_conv->precision = va_arg(*list, int);
	else
		a_conv->precision = 0;
	return ;
}

void	get_flags_and_next_param(t_printf *a_conv, va_list *list)
{
	char	*str;
	int		i;

	str = a_conv->start;
	i = 0;
	while (ft_strchr("0-", str[i]))
	{
		if (str[i] == '0')
			a_conv->zero = TRUE;
		if (str[i] == '-')
			a_conv->minus = TRUE;
		i++;
	}
	if (ft_strchr("0123456789*", str[i]))
		i = parse_width(str, i, a_conv, list);
	if (str[i] == '.')
		parse_precision(str + i + 1, a_conv, list);
	a_conv->data = get_next_param(a_conv->type_conversion, list);
}
