/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:17:46 by tfontain          #+#    #+#             */
/*   Updated: 2017/07/22 18:57:44 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int				ft_isdigit_or_sign(const char c)
{
	return (ft_isdigit(c) || c == '+' || c == '-');
}

size_t			stoints(const char s[], int **ret)
{
	static int	last_size = 0;
	int			size;
	const char	*pt;
	int			*tmp;

	pt = s;
	size = 0;
	while (*pt)
	{
		if ((ft_isdigit_or_sign(*pt) && (pt == s || !ft_isdigit_or_sign(*(pt - 1)))))
			++size;
		++pt;
	}
	*ret = malloc(sizeof(int) * size);
	tmp = *ret;
	pt = s;
	while (*pt)
	{
		if ((ft_isdigit_or_sign(*pt) && (pt == s || !ft_isdigit_or_sign(*(pt - 1)))))
			*tmp++ = ft_atoi(pt);
		++pt;
	}
	if (last_size != 0 && last_size != size)
		exit(-1); // si les lignes ne font pas la meme taille
	last_size = size;
	return (size);
}

int **parse_tab(const char *name, size_t *row, size_t *column)
{
	char buff;
	int fd;

	*row = 0;
	fd = open(name, O_RDONLY);
	while (read(fd, &buff, 1))
		if (buff == '\n')
			++*row;
	if (buff != '\n')
		++*row;
	close(fd);
	fd = open(name, O_RDONLY);

	//

	int **array;
	array = malloc(sizeof(int*) * *row);
	char	*get;
	int		i;

	i = 0;
	while (get_next_line(fd, &get) == 1)
	{
		*column = stoints(get, &(array[i++]));
		free(get);
	}
	close(fd);
	return (array);
}

#include <stdio.h>
int main(int argc, const char *argv[])
{
	int		**array;
	size_t	row;
	size_t	column;

	if (argc != 2)
		return (0);
	array = parse_tab(argv[1], &row, &column);

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			printf("%3d ", array[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
