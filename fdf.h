/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 08:10:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/21 16:36:45 by tfontain         ###   ########.fr       */
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

typedef struct			s_mlx
{
	void				*p;
	void				*w;
}						t_mlx;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_coord_list
{
	t_coord				coord;
	struct s_coord_list	*next;
}						t_coord_list;

t_mlx					all_init(int size_x, int size_y, char *title);
int						print_line(t_mlx mlx, t_coord p1, t_coord p2,
		int color);
void					swap_coord(t_coord *p1, t_coord *p2);

#endif
