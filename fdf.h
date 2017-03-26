/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 08:10:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 14:27:30 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "./libft/includes/libft.h"

typedef struct	s_mlx
{
	void		*p;
	void		*w;
}				t_mlx;

typedef struct	s_win
{
	t_mlx		*mlx;
	int			len_x;
	int			len_y;
}				t_win;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

void			print_line(t_mlx mlx, t_coord p1, t_coord p2, int color);

#endif
