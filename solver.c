/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:46:15 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 19:38:13 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int					ft_solver(t_list *tetris, char *map, int size, char **res)
{
	static char		letter = '@';
	int				i;

	i = 0;
	if (!(tetris))
	{
		*res = ft_strdup(map);
		return (1);
	}
	while (map[i])
	{
		while (map[i] != '.' && map[i + 1])
			i++;
		if (ft_check_position(tetris->content, &map[i], size, i))
		{
			ft_fill_tetri(&map[i], size, tetris->content, ++letter);
			if (ft_solver(tetris->next, map, size, res))
				return (1);
			letter--;
			ft_fill_tetri(&map[i], size, tetris->content, '.');
		}
		i++;
	}
	return (0);
}

void				ft_fill_tetri(char *map, int size, int *arr, char letter)
{
	int				ind[3];

	ind[0] = 0;
	ind[1] = 0;
	ind[2] = size;
	map[0] = letter;
	while (ind[1] < 3)
	{
		if (arr[(ind[1])] == 1)
		{
			map[(ind[0] + 1)] = letter;
			ind[0] = ind[0] + 1;
		}
		else
			fill_2(arr, ind, letter, map);
		ind[1]++;
	}
	return ;
}

void				fill_2(int *arr, int *ind, char letter, char *map)
{
	if (arr[(ind[1])] == 2)
	{
		map[ind[0] + ind[2] + 1] = letter;
		ind[0] = ind[0] + ind[2] + 1;
	}
	else if (arr[(ind[1])] == 4)
	{
		map[ind[0] + ind[2]] = letter;
		ind[0] = ind[0] + ind[2];
	}
	else if (arr[(ind[1])] == 5)
	{
		map[ind[0] + ind[2] - 1] = letter;
		ind[0] = ind[0] + ind[2] - 1;
	}
	return ;
}

int					ft_check_position(int *arr, char *map, int size, int idx)
{
	int				inn[3];

	inn[0] = 0;
	inn[1] = 0;
	inn[2] = size * size + size - idx;
	while (inn[1] < 3)
	{
		if (arr[(inn[1])] == 1)
		{
			if (map[(inn[0] + 1)] == '.' && (inn[0] + 1) < inn[2])
				inn[0] = inn[0] + 1;
			else
				break ;
		}
		else if (!(check_2(arr, map, size, inn)))
			break ;
		inn[1] += 1;
	}
	return (inn[1] == 3 ? 1 : 0);
}

int					check_2(int *arr, char *map, int size, int *inn)
{
	if (arr[(inn[1])] == 2)
	{
		if (map[(inn[0] + size + 1)] == '.' && (inn[0] + size + 1) < inn[2])
			inn[0] = inn[0] + size + 1;
		else
			return (0);
	}
	else if (arr[(inn[1])] == 4)
	{
		if (map[(inn[0] + size)] == '.' && (inn[0] + size) < inn[2])
			inn[0] = inn[0] + size;
		else
			return (0);
	}
	else if (arr[(inn[1])] == 5)
	{
		if (map[(inn[0] + size - 1)] == '.' && (inn[0] + size - 1) < inn[2])
			inn[0] = inn[0] + size - 1;
		else
			return (0);
	}
	return (1);
}

/*
** ////////////////////   READABLE FT_CHECK_POSITION   ///////////////////////
**
**								(╯°□°）╯︵ ɯɹou
**
**
**int				ft_check_position(int *arr, char *map, int size, int idx)
**{
**	int				i;
**	int				n;
**	int				len;
**
**	i = 0;
**	n = 0;
**	len = size * size + size - idx;
**	while(n < 3)
**	{
**		if(arr[n] == 1)
**		{
**			if (map[i + 1] == '.' && (i + 1) < len)
**				i = i + 1;
**			else
**				break;
**		}
**		else if (arr[n] == 2)
**		{
**			if (map[i + size + 1] == '.' && (i + size + 1) < len)
**				i = i + size + 1;
**			else
**				break;
**		}
**		else if(arr[n] == 4)
**		{
**			if (map[i + size] == '.' && (i + size) < len)
**				i = i + size;
**			else
**				break;
**		}
**		else if(arr[n] == 5)
**		{
**			if (map[i + size - 1] == '.' && (i + size - 1) < len)
**				i = i + size - 1;
**			else
**				break;
**		}
**		n++;
**	}
**	return (n == 3 ? 1 : 0);
**}
**
** ////////////////////   REASABLE FT_FILL_TETRI   ///////////////////////////
**
**
**void				ft_fill_tetri(char *map, int size, int *arr, char letter)
**{
**	int             i;
**	int             n;
**
**	i = 0;
**	n = 0;
**	map[i] = letter;
**	while (n < 3)
**	{
**		if (arr[n] == 1)
**		{
**			map[i + 1] = letter;
**			i = i + 1;
**		}
**		else if (arr[n] == 2)
**		{
**			map[i + size + 1] = letter;
**			i = i + size + 1;
**		}
**		else if (arr[n] == 4)
**		{
**			map[i + size] = letter;
**			i = i + size;
**		}
**		else if (arr[n] == 5)
**		{
**			map[i + size - 1] = letter;
**			i = i + size - 1;
**		}
**		n++;
**	}
**	return ;
**}
**
** ///////////////////////////////////////////////////////////////////////////
*/
