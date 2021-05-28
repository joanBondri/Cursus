/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:58:53 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:58:54 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_UINT_H
# define TYPE_UINT_H
# include "basic_elem.h"

void	print_uint(t_printf *s);
void	print_precision_unbr(t_printf *s);
int		size_of_unumber(unsigned int i, int n);
void	print_space_precision_unbr(t_printf *s);

#endif
