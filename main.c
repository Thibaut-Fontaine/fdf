/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:04:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 16:11:44 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include <mlx.h>

int				main()
{
	t_mlx		*mlx;
	t_coord		*p1;
	t_coord		*p2;

	mlx = malloc(sizeof(t_mlx));
	p1 = malloc(sizeof(t_coord));
	p2 = malloc(sizeof(t_coord));
	mlx->p = mlx_init();
	mlx->w = mlx_new_window(mlx->p, 900, 900, "fdf");
	p1->x = 600;
	p1->y = 600;
	p2->x = 50;
	p2->y = 50;
	print_line(*mlx, *p1, *p2, 0x000000FF);
	mlx_loop(mlx->p);
	return (0);
}
