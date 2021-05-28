/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:02:59 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:03:01 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(t_printf *s)
{
	int		i;
	t_bool	null_str;

	null_str = FALSE;
	if (s->precision < -1)
	{
		s->precision = -1;
		s->dot = FALSE;
	}
	if ((char*)s->data == NULL)
	{
		null_str = TRUE;
		s->data = (void*)ft_strdup("(null)");
	}
	if (s->precision == -1)
		i = s->width - ft_strlen((char*)s->data);
	else
		i = s->width - ft_min(s->precision, ft_strlen((char*)s->data));
	if (!(s->minus))
		put_space(i);
	put_s((char*)s->data, s->precision);
	if (s->minus)
		put_space(i);
	free_data(null_str, s->data);
}

void	free_data(t_bool b, void *data)
{
	if (b)
		free(data);
}

void	put_s(char *str, int precision)
{
	if (precision == -1 || ft_strlen(str) < precision)
		put_str(str);
	else
		put_len_str(str, precision);
}
