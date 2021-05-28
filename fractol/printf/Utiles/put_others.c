/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_thgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:00:47 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:00:49 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_pointer(unsigned long int n, int count)
{
	if (count < LEN_PTR)
		put_pointer(n / 16, count + 1);
	put_char(get_lower_hexa(n % 16));
	return ;
}

void	put_space(int i)
{
	while (--i >= 0)
		put_char(' ');
}
