/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 16:05:36 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 16:09:44 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void			swap_coord(t_coord* p1, t_coord *p2)
{
	t_coord		tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
