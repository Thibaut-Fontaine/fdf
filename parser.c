/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:17:46 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/22 20:37:58 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static inline int				ft_isdigit_sign(const char c)
{
	return (ft_isdigit(c) || c == '+' || c == '-');
}

static inline size_t			stoints(const char s[], int **ret)
{
	static int					last_size = 0;
	int							size;
	const char					*pt;
	int							*tmp;

	pt = s;
	size = 0;
	while (*pt)
	{
		if ((ft_isdigit_sign(*pt) && (pt == s || !ft_isdigit_sign(*(pt - 1)))))
			++size;
		++pt;
	}
	*ret = malloc(sizeof(int) * size);
	tmp = *ret;
	pt = s;
	while (*pt)
	{
		if ((ft_isdigit_sign(*pt) && (pt == s || !ft_isdigit_sign(*(pt - 1)))))
			*tmp++ = ft_atoi(pt);
		++pt;
	}
	last_size != 0 && last_size != size ? exit(-1) : (last_size = size);
	return (size);
}

int								**parse_tab(const char *name,
		size_t *row, size_t *column)
{
	char						buff;
	int							**array;
	int							fd;
	char						*get;
	int							i;

	*row = 0;
	fd = open(name, O_RDONLY);
	while (read(fd, &buff, 1))
		if (buff == '\n')
			++*row;
	if (buff != '\n')
		++*row;
	close(fd);
	fd = open(name, O_RDONLY);
	array = malloc(sizeof(int*) * *row);
	i = 0;
	while (get_next_line(fd, &get) == 1)
	{
		*column = stoints(get, &(array[i++]));
		free(get);
	}
	close(fd);
	return (array);
}
