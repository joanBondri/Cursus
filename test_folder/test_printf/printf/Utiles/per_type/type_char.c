/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri </var/mail/jbondri>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:47:42 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/25 11:49:09 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(t_printf *s)
{
	int		i;
	long long int	*c;

	i = 0;
	c = (long long int *)s->data;
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
