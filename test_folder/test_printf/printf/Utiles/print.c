/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri </var/mail/jbondri>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:46:43 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/25 11:47:09 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print(char c, t_printf *s)
{
	if (c == 'd' || c == 'i')
		print_int(s);
	else if (c == 'u')
		print_uint(s);
	else if (c == 'x' || c == 'X')
		print_hexa(s);
	else if (c == 'c')
		print_char(s);
	else if (c == 's')
		print_str(s);
	else if (c == '%')
		print_percent(s);
	else if (c == 'p')
		print_pointer(s);
	return ;
}

int		ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int		ft_max(int i_1, int i_2)
{
	if (i_1 > i_2)
		return (i_1);
	return (i_2);
}

int		ft_min(int i_1, int i_2)
{
	if (i_1 < i_2)
		return (i_1);
	return (i_2);
}
