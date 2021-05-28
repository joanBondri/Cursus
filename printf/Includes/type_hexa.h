/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexa.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:57:50 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:57:51 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HEXA_H
# define TYPE_HEXA_H
# include "basic_elem.h"

void	print_hexa(t_printf *s);
void	print_precision_hexa(t_printf *s);
int		size_of_hexa(unsigned int i, int n);
void	print_space_precision_hexa(t_printf *s);

#endif
