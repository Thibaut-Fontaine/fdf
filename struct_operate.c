/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_operate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:40:36 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/27 10:56:38 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

/*
** initiate a graphic server and his flux, also create a new window.
*/

t_mlx		all_init(int size_x, int size_y, char *title)
{
	t_mlx	mlx;

	mlx.p = mlx_init();
	mlx.w = mlx_new_window(mlx.p, size_x, size_y, title);
	return (mlx);
}
