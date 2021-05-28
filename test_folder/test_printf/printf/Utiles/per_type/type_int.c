#include "printf.h"

void	print_int(t_printf *s)
{
		if (s->precision < -1)
	{
		s->precision = -1;
		s->dot = FALSE;
	}
	if (s->zero && !s->minus && !s->dot)
		print_zero_nbr(s);
	else
	{
		if (!(s->minus))
			print_space_precision_nbr(s);
		print_precision_nbr(s);
		if (s->minus)
			print_space_precision_nbr(s);
	}
	free(s->data);
	return ;
}

void	print_zero_nbr(t_printf *s)
{
	int		i;
	int		*data_int;

	data_int = (int *)(s->data);
		if (*data_int < 0)
		put_char('-');
	if (size_of_number(*data_int, INIT) < s->width)
	{
		i = s->width - size_of_number(*data_int, INIT);
		while (--i >= 0)
			put_char('0');
	}
	if (*data_int == INT_MINIMUM)
		return (put_str("2147483648"));
	put_nbr(ft_abs(*data_int));
}

void	print_precision_nbr(t_printf *s)
{
	int		i;
	int		*data_int;

	data_int = (int *)(s->data);
	if (*data_int < 0)
		put_char('-');
	if (s->precision == 0 && *data_int == 0)
	{
		if(s->width > 0)
			put_char(' ');
		return ;
	}
	if (size_of_number(*data_int, INIT) < s->precision)
	{
		i = s->precision - size_of_number(*data_int, INIT);
		if (*data_int < 0)
			i++;
		while (--i >= 0)
			put_char('0');
	}
	if (*data_int == INT_MINIMUM)
		return (put_str("2147483648"));
	put_nbr(ft_abs(*data_int));
}

int		size_of_number(int i, int n)
{
	if (i == 0 && n == INIT)
		return (1);
	if (i == INT_MINIMUM)
		return (11);
	if (i < 0)
		return (1 + size_of_number(i * -1, n + 1));
	if (i > 0)
		return (1 + size_of_number(i / 10, n + 1));
	else
		return (0);
}

void	print_space_precision_nbr(t_printf *s)
{
	int		i;
	int		*data_int;

	data_int = (int *)(s->data);
	if (size_of_number(*data_int, INIT) > s->precision)
		i = size_of_number(*data_int, INIT);
	else
		i = s->precision;
	if (i == s->precision && *data_int < 0)
		i++;
	while (++i <= s->width)
		put_char(' ');
}

