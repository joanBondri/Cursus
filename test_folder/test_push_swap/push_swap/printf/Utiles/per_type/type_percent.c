/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:02:03 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:02:05 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_percent(t_printf *s)
{
	char	*c;

	if (s->zero && !s->minus)
		return (print_zero_percent(s));
	if (!(c = malloc(sizeof(char) * (1))))
		return ;
	c[0] = '%';
	s->data = (void*)c;
	s->type_conversion = 'c';
	print_char(s);
}

void	print_zero_percent(t_printf *s)
{
	int		i;

	i = 0;
	while (++i < s->width)
		put_char('0');
	put_char('%');
}
