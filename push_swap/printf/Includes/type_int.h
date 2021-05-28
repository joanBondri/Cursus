/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:58:06 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:58:08 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_INT_H
# define TYPE_INT_H
# include "basic_elem.h"

void	print_int(t_printf *s);
void	print_space_precision_hexa(t_printf *s);
void	print_zero_nbr(t_printf *s);
void	print_precision_nbr(t_printf *s);
int		size_of_number(int i, int n);
void	print_space_precision_nbr(t_printf *s);

#endif
