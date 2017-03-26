/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 00:46:55 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/26 00:49:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getline.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd;
	char*line;

	if (argc != 2)
	{
		ft_putstr("trop ou pas assez d'arguments\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	while (getline(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
