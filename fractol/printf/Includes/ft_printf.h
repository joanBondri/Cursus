/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:03:49 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:03:51 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "basic_elem.h"

int		ft_printf(const char *str, ...);
int		special_case(char *prin, int i, va_list *list, t_printf *data);

#endif
