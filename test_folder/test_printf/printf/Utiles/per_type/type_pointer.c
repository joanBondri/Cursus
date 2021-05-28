#include "printf.h"

void	print_pointer(t_printf *s)
{
	if ((unsigned long int)s->data == 0)
		return (print_nil(s));
	if (s->zero && !s->minus && !s->dot)
	{
		s->precision = s->width;
		print_precision_pointer(s);
	}
	else
	{
		if (!(s->minus))
			print_space_precision_pointer(s);
		print_precision_pointer(s);
		if (s->minus)
			print_space_precision_pointer(s);
	}
	return ;
}

void	print_precision_pointer(t_printf *s)
{
	int						i;
	unsigned long int		data_int;

	data_int = (unsigned long int)(s->data);
	if (LEN_PTR < s->precision)
	{
		i = s->precision - LEN_PTR;
		while (--i >= 0)
			put_char('0');
	}
	put_str("0x");
	return (put_pointer(data_int, INIT));
}

void	print_nil(t_printf *s)
{
	int		i;

	if (s->width != -1 || s->precision != -1)
		i = ft_max(s->precision, s->width) - LEN_NIL;
	else
		i = 0;
	if (!(s->minus))
		put_space(i);
	put_str("0x0");
	if (s->minus)
		put_space(i);
}

void	print_space_precision_pointer(t_printf *s)
{
	int						i;

	if (LEN_PTR + 2 > s->precision)
		i = LEN_PTR + 2;
	else
		i = s->precision;
	put_space(s->width - ++i);
}
