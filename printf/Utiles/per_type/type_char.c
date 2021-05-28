/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:01:28 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:01:30 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(t_printf *s)
{
	int		i;
	char	*c;

	i = 0;
	c = (char *)s->data;
	if (!(s->minus))
	{
		while (++i < s->width)
			put_char(' ');
	}
	put_char(*c);
	if (s->minus)
	{
		while (++i < s->width)
			put_char(' ');
	}
	free(s->data);
}
