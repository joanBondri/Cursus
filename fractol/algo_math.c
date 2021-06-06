/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:49:32 by jbondri           #+#    #+#             */
/*   Updated: 2021/06/06 14:53:04 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	norm(t_comp num)
{
	return ((float)sqrt(pow(num.r, 2) + pow(num.i, 2)));
}

int	time_loop_julia(int time, t_comp num, t_comp c)
{
	t_comp		new;
	double		smooth;

	time++;
	smooth = exp(-1 * sqrt(num.r * num.r + num.i * num.i));
	while (--time > 0 && sqrt(num.r * num.r + num.i * num.i) < 100000000)
	{
		new.r = num.r * num.r - num.i * num.i + c.r;
		new.i = 2 * num.r * num.i + c.i;
		num = new;
		smooth += exp(-1 * sqrt(num.r * num.r + num.i * num.i));
	}
	if (sqrt(num.r * num.r + num.i * num.i) < 2)
		return (0);
	return (hsv_to_hex(smooth, 0.9, 0.8));
}
