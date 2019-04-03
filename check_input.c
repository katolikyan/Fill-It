/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:08:39 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 01:00:08 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/get_next_line.h"
#include "fillit.h"
#include <stdio.h>

t_list				*ft_check_input(int fd)
{
	char			*tetri;
	t_list			*list;
	int				valid;

	valid = 1;
	while ((tetri = ft_read_5_lines(fd, &valid)))
	{
		if ((ft_check_tetri(tetri)) <= 0)
		{
			free(tetri);
			return (0);
		}
		if (!(list = ft_store_tetri(tetri)))
			return (0);
		ft_memdel((void **)&tetri);
	}
	return (valid == 1 ? list : 0);
}

int					ft_check_tetri(char *str)
{
	int				i;

	i = 0;
	if (!(ft_check_symbols(str)))
		return (0);
	while (str[i] == '.' || str[i] == '\n')
		i++;
	if (str[i + 1] == '#' && str[i + 5] == '#')
	{
		if (str[i + 2] == '#' || str[i + 4] == '#' || str[i + 6] == '#')
			return (1);
		else if ((i + 10) < 20)
			return (str[i + 10] == '#' ? 1 : 0);
		return (0);
	}
	return (ft_check_tetri_2(&str[i]) == 1 ? 1 : 0);
}

int					ft_check_tetri_2(char *str)
{
	int				n;
	int				i;

	i = 0;
	n = 0;
	while (n < 3)
	{
		while (str[i] == '.' || str[i] == '\n')
			i++;
		if (str[i + 1] == '#' && str[i + 5] == '#' && n == 1)
			return (1);
		else if (str[i + 1] == '#')
		{
			i++;
			n++;
		}
		else if (str[i + 5] == '#')
		{
			i++;
			n++;
		}
		else
			return (0);
	}
	return (1);
}

int					ft_check_symbols(char *str)
{
	int				nhash;

	nhash = 0;
	while (*str)
	{
		if (*str == '.' || *str == '\n')
			str++;
		else if (*str == '#')
		{
			nhash++;
			str++;
		}
		else
			return (0);
	}
	return (nhash == 4 ? 1 : 0);
}
