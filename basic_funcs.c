/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 08:08:01 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/27 10:47:03 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

/*
** file for basic functions who display basic objects
** these funcs use the struct in the header
** //
** -----------> x
** |
** |
** |
** ↓
** y
*/

int				print_vertical_line(t_mlx mlx, t_coord p1, t_coord p2, int color)
{
	int			ret;

	if (p1.x != p2.x)
		return (-1);
	if (p1.y > p2.y)
		swap_coord(&p1, &p2);
	ret = p2.y - p1.y;
	while (p1.y < p2.y)
	{
		mlx_pixel_put(mlx.p, mlx.w, p1.x, p1.y, color);
		++p1.y;
	}
	return (ret);
}


/*
** print a line with predefined color ; return number of printed pixels
*/

int				print_line(t_mlx mlx, t_coord p1, t_coord p2, int color)
{
	float		dr;
	float		error;
	float		ret;

	if (p1.x < p2.x)
		swap_coord(&p1, &p2);
	if (p1.x - p2.x == 0)
		return (print_vertical_line(mlx, p1, p2, color));
	dr = fabs((float)(p1.y - p2.y) / (float)(p1.x - p2.x));
	error = dr - 0.5;
	ret = p1.x - p2.x;
	while (p2.x < p1.x)
	{
		mlx_pixel_put(mlx.p, mlx.w, p2.x, p2.y, color);
		error += dr;
		if (error >= 0.5)
		{
			p2.y += 1;
			error -= 1.0;
		}
		++p2.x;
	}
	return (ret);
}






