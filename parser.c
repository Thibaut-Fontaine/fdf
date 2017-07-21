/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:17:46 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/21 16:46:09 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

char **parse_tab(const char *name)
{
	int nlines = 0;
	char buff;
	int fd;

	fd = open(name, O_RDONLY);
	while (read(fd, &buff, 1))
		if (buff == '\n')
			++nlines;
	if (buff != '\n')
		++nlines;

	char **tab;
	tab = malloc(sizeof(char*) * nlines);
	int i = 0;

	while (get_next_line(1, tab + i))
	{
		++i;
	}
	return (tab);
}
