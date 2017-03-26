/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 08:08:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 15:46:12 by tfontain         ###   ########.fr       */
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
	if (p1.x < p2.x || p1.y < p2.y)
		ft_swap(&p1, &p2);
	double	dx = p1.x - p2.x;
	double	dy = p1.y - p2.y;

	if (dx == 0)
		; //print_vertical
	double	dr = fabs(dy / dx);
	double error = dr - 0.5;
	int y = p2.y;
	int x = p2.x;

	while (x < p1.x)
	{
		mlx_pixel_put(mlx.p, mlx.w, x, y, color);
		error = error + dr;
		if (error >= 0.5)
		{
			y = y + 1;
			error = error - 1.0;
		}
		++x;
	}
}






