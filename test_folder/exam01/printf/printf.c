void	p_int(char *str, va_list *lst)
{
	int	width;
	int	prec;
	int	i;
	char	*s;

	i = 0;
	if (in(str[i], "0123456789"))
		width = ft_atoi(str + i);
	else
		width = -1;
	while (in(str[i], "0123456789"))
		i++;
	if (str[i] == '.')
		prec = ft_atoi(str + i);
	else
		prec = -1;
	s = va_arg(lst, (char*));
}

void	p_hex(char *str, va_list *lst)
{
	int	width;
	int	prec;
	int	i;
	char	*s;

	i = 0;
	if (in(str[i], "0123456789"))
		width = ft_atoi(str + i);
	else
		width = -1;
	while (in(str[i], "0123456789"))
		i++;
	if (str[i] == '.')
		prec = ft_atoi(str + i);
	else
		prec = -1;
	s = va_arg(lst, (char*));
}

void	p_str(char *str, va_list *lst)
{
	int	width;
	int	prec;
	int	i;
	char	*s;

	i = 0;
	if (in(str[i], "0123456789"))
		width = ft_atoi(str + i);
	else
		width = -1;
	while (in(str[i], "0123456789"))
		i++;
	if (str[i] == '.')
		prec = ft_atoi(str + i);
	else
		prec = -1;
	s = va_arg(lst, (char*));
}

int	special(char *str, int ind, va_list *lst)
{
	int	i;

	i = 0;
	if(in(str + i, "0123456789."))
		i++;
	if (!in(str[i], "sdx"))
	{
		ft_putchar(str[ind]);
		return (ind++);
	}
	if (str[i] == 's')
		p_str(str + ind, lst);
	else if (str[i] == 'd')
		p_int(str + ind, lst);
	else
		p_hex(str, ind, lst);
	return (++i);
}

int	printf(const char *str, ...)
{
	va_list		lst;
	char		*prin;
	int		i;

	prin = (char*)str;
	i = 0;
	va_start(lst, str);
	while (prin[i])
	{
		if (prin[i] == '%')
			special(prin, i, &lst);
		else
			ft_putchar(prin[i]);
		i++;
	}
	return (get_nu(0));
}
