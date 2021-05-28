#include "printf.h"

void	put_char(char c)
{
	ft_putchar_fd(c, 1);
	get_number_char(1);
	return ;
}

int		get_number_char(int n)
{
	static int		size_printf = 0;

	if (n == 1)
		size_printf++;
	return (size_printf);
}

void	put_str(char *str)
{
	int			i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		put_char(str[i]);
	return ;
}

void	put_len_str(char *str, int len)
{
	int		i;

	i = -1;
	while (str[++i] && i < len)
		put_char(str[i]);
	return ;
}
