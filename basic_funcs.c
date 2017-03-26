/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 08:08:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 14:35:25 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

/*
** file for basic functions who display basic objects
** these funcs use the struct in the header
*/

/*
** print a line with predefined color
*/

void		print_line(t_mlx mlx, t_coord p1, t_coord p2, int color)
{
	int		dx = p2.x - p1.x;
	int		dy = p2.y - p1.y;
	int		x;
	int		y;


	x = p1.x;
	while (x < p2.x)
	{
		y = p1.y + dy * (x - p1.x) / dx;
		mlx_pixel_put(mlx.p, mlx.w, x, y, color);
		++x;
	}
}






