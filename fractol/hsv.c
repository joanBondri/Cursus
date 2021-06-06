/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:02:21 by jbondri           #+#    #+#             */
/*   Updated: 2021/06/06 15:33:41 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hsv_to_hex(double h, float s, float v)
{
	float	ix;
	float	em;
	float	ce;

	ce = v * s;
	ix = ce * (1 - fabs(fmod((h / 60.0), 2.0) - 1));
	em = v - ce;
	if (h < 60)
		return ((ce + em) * 16711680 + (ix + em) * 65280 + (0) * 255);
	else if (h < 120)
		return ((ix + em) * 16711680 + (ce + em) * 65280 + (0) * 255);
	else if (h < 180)
		return ((0) * 16711680 + (ce + em) * 65280 + (ix + em) * 255);
	else if (h < 240)
		return ((0) * 16711680 + (ix + em) * 65280 + (ce + em) * 255);
	else if (h < 300)
		return ((ix + em) * 16711680 + (0) * 65280 + (ce + em) * 255);
	return ((ce + em) * 16711680 + (0) * 65280 + (ix + em) * 255);
}
