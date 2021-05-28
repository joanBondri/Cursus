/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:03:10 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:03:14 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_uint(t_printf *s)
{
	if (s->zero && !s->minus && !s->dot)
	{
		s->precision = s->width;
		print_precision_unbr(s);
	}
	else
	{
		if (!(s->minus))
			print_space_precision_unbr(s);
		print_precision_unbr(s);
		if (s->minus)
			print_space_precision_unbr(s);
	}
	free(s->data);
	return ;
}

void	print_precision_unbr(t_printf *s)
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
	if (size_of_unumber(*data_int, INIT) < s->precision)
	{
		i = s->precision - size_of_unumber(*data_int, INIT);
		while (--i >= 0)
			put_char('0');
	}
	put_unbr(*data_int);
}

int		size_of_unumber(unsigned int i, int n)
{
	if (i == 0 && n == INIT)
		return (1);
	if (i > 0)
		return (1 + size_of_unumber(i / 10, n + 1));
	else
		return (0);
}

void	print_space_precision_unbr(t_printf *s)
{
	int		i;
	int		*data_int;

	data_int = (int *)(s->data);
	if (size_of_unumber(*data_int, INIT) > s->precision)
		i = size_of_unumber(*data_int, INIT);
	else
		i = s->precision;
	while (++i <= s->width)
		put_char(' ');
}
