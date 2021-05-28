/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_elem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:03:34 by jbondri           #+#    #+#             */
/*   Updated: 2020/11/26 14:03:41 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_ELEM_H
# define BASIC_ELEM_H
# define TRUE 1
# define FALSE 0
# define INIT 0
# define INT_MINIMUM -2147483648
# define LEN_PTR 8
# define LEN_NIL 3
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef int		t_bool;
typedef struct	s_printf
{
	char	*start;
	char	type_conversion;
	void	*data;
	int		width;
	int		precision;
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
}				t_printf;

#endif
