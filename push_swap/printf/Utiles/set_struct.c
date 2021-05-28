/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:01:06 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:01:08 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_null_struct(t_printf *s)
{
	s->start = NULL;
	s->type_conversion = '\0';
	s->data = NULL;
	s->width = -1;
	s->precision = -1;
	s->zero = FALSE;
	s->minus = FALSE;
	s->dot = FALSE;
}
