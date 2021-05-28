#include "printf.h"

void		put_char(long long int c)
{
	write(1, &c, 1);
	get_number_char(1);
	return ;
}

int		get_number_char(int n)
{
	static int		size_printf = 0;
	int				buff;

	if (n == 1)
		size_printf++;
	else if (n == 0)
	{
		buff = size_printf;
		size_printf = 0;
		return (buff);
	}
	return (size_printf);
}

void	put_str(char *str)
{
	int			i;

	if (str == NULL)
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

void	put_unbr(unsigned int n)
{
	if (n / 10)
		put_unbr(n / 10);
	put_char(n % 10 + '0');
	return ;
}

void	put_pointer(unsigned long int n, int count)
{
	
	if (count < LEN_PTR)
		put_pointer(n / 16, count + 1);
	put_char(get_lower_hexa(n % 16));
	return ;
}

void	put_hexa(unsigned int n, char (*char_hexa)(unsigned int))
{
	if (n / 16)
		put_hexa(n / 16, (*char_hexa));
	put_char((*char_hexa)(n % 16));
	return ;
}

char	get_upper_hexa(unsigned int n)
{
	if (n < 10)
		return (n + '0');
	else if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	return ('0');
}
char	get_lower_hexa(unsigned int n)
{
	if (n < 10)
		return (n + '0');
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	return ('0');
}

void	put_nbr(int n)
{
	if (n == -2147483648)
		return (put_str("-2147483648"));
	if (n < 0)
	{
		put_char('-');
		put_nbr(n * -1);
		return ;
	}
	if (n / 10)
		put_nbr(n / 10);
	put_char(n % 10 + '0');
	return ;
}

void	put_space(int i)
{
	while (--i >= 0)
		put_char(' ');
}
