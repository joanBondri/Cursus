/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:58:44 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:58:46 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_STR_H
# define TYPE_STR_H
# include "basic_elem.h"

void	print_str(t_printf *s);
void	free_data(t_bool b, void *data);
void	put_s(char *str, int precision);

#endif
