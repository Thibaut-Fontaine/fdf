/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:04:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 17:09:52 by tfontain         ###   ########.fr       */
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
	mlx->w = mlx_new_window(mlx->p, 2000, 500, "fdf");
	//
	p1->x = 100;
	p1->y = 400;
	p2->x = 300;
	p2->y = 50;
	while (p1->x != 500)
	{
		++p1->x;
		--p1->y;
		--p2->x;
		++p2->y;
		
		print_line(*mlx, *p1, *p2, 0x00FF0000);
	}
	mlx_loop(mlx->p);
	return (0);
}
