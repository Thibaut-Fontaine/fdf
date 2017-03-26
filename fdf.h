/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 08:10:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 10:45:19 by tfontain         ###   ########.fr       */
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
	void		*x;
	void		*w;
}				t_mlx;

typedef struct	s_win
{
	
}				t_win;

#endif
