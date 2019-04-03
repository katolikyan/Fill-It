/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:36:43 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 00:59:26 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int					ft_build_map(char **map, int numtetri)
{
	int				i;
	int				n;
	int				len;
	int				map_size;

	i = 0;
	map_size = 2;
	while (map_size * map_size < numtetri * 4)
		map_size++;
	len = map_size * map_size + map_size + 1;
	*map = ft_memalloc(len);
	while (i < (len - 1))
	{
		n = map_size;
		while (n-- > 0)
			(*map)[i++] = '.';
		(*map)[i++] = '\n';
	}
	(*map)[i] = '\0';
	return (map_size);
}

int					ft_rebuild_map(char **map, int map_size)
{
	int				i;
	int				n;
	int				len;

	map_size++;
	i = 0;
	len = map_size * map_size + map_size + 1;
	*map = ft_memalloc(len);
	while (i < (len - 1))
	{
		n = map_size;
		while (n-- > 0)
			(*map)[i++] = '.';
		(*map)[i++] = '\n';
	}
	(*map)[i] = '\0';
	return (map_size);
}
