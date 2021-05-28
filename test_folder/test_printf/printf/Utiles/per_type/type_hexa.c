#include "printf.h"

void	print_hexa(t_printf *s)
{
	if (s->zero && !s->minus && !s->dot)
	{
		s->precision = s->width;
		print_precision_hexa(s);
	}
	else
	{
		if (!(s->minus))
			print_space_precision_hexa(s);
		print_precision_hexa(s);
		if (s->minus)
			print_space_precision_hexa(s);
	}
	free(s->data);
	return ;
}

void	print_precision_hexa(t_printf *s)
{
	int					i;
	unsigned int		*data_int;

	data_int = (unsigned int *)(s->data);
	if (s->precision == 0 && *data_int == 0)
	{
		if (s->width > 0)
			put_char(' ');
		return ;
	}
	if (size_of_hexa(*data_int, INIT) < s->precision)
	{
		i = s->precision - size_of_hexa(*data_int, INIT);
		while (--i >= 0)
			put_char('0');
	}
	if (s->type_conversion == 'x')
		return (put_hexa(*data_int, get_lower_hexa));
	return (put_hexa(*data_int, get_upper_hexa));
}

int		size_of_hexa(unsigned int i, int n)
{
	if (i == 0 && n == INIT)
		return (1);
	if (i > 0)
		return (1 + size_of_hexa(i / 16, n + 1));
	else
		return (0);
}

void	print_space_precision_hexa(t_printf *s)
{
	int					i;
	unsigned int		*data_int;

	data_int = (unsigned int *)(s->data);
	if (size_of_hexa(*data_int, INIT) > s->precision)
		i = size_of_hexa(*data_int, INIT);
	else
		i = s->precision;
	put_space(s->width - i);
}
