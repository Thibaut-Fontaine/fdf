/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:04:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 14:52:12 by tfontain         ###   ########.fr       */
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
	mlx->w = mlx_new_window(mlx->p, 640, 480, "salut");
	p1->x = 8;
	p1->y = 8;
	p2->x = 256;
	p2->y = 256;
	print_line(*mlx, *p1, *p2, 0x00FF00FF);
	mlx_loop(mlx->p);
	return (0);
}
