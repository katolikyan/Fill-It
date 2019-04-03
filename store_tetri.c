/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:55:18 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 16:30:09 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#include <stdio.h>

t_list				*ft_store_tetri(char *str)
{
	int				*tetri;
	static	t_list	*tetris;

	tetri = ft_define_tetri_array(str);
	ft_lstpb(&tetris, tetri, 12);
	ft_memdel((void **)&tetri);
	return (tetris);
}

int					*ft_define_tetri_array(char *str)
{
	int				*arr;
	int				ind[3];

	ind[0] = 0;
	ind[1] = 1;
	ind[2] = 0;
	if (!(arr = ft_memalloc(sizeof(int) * 3)))
		return (NULL);
	while (*str == '.' || *str == '\n')
		str++;
	ft_encoder(arr, str, ind);
	return (arr);
}

void				ft_encoder(int *arr, char *str, int *ind)
{
	while (ind[2] < 3)
	{
		while (str[(ind[1])] == '.' || str[(ind[1])] == '\n')
			ind[1]++;
		if (ind[1] - ind[0] == 1)
		{
			arr[ind[2]++] = 1;
			ind[0] = ind[1]++;
		}
		else if (((ind[1] - ind[0]) % 4) == 0)
		{
			arr[ind[2]++] = 4;
			ind[0] = ind[1]++;
		}
		else if (((ind[1] - ind[0]) % 4) == 1)
		{
			arr[ind[2]++] = 2;
			ind[0] = ind[1]++;
		}
		else if (((ind[1] - ind[0]) % 4) == 3)
		{
			arr[ind[2]++] = 5;
			ind[0] = ind[1]++;
		}
	}
}

/*
** /////////////////  READABLE FT_DEFINE_TETRI_ARRAY  ////////////////////////
**
**							(╯°□°）╯︵ ɯɹou
**
**int					*ft_define_tetri_array(char *str)
**{
**	int				*arr;
**	int				i;
**	int				n;
**	int				old;
**
**	n = 0;
**	i = 0;
**	if (!(arr = ft_memalloc(sizeof(int) * 3)))
**		return (NULL);
**	while (str[i] == '.' || str[i] == '\n')
**		i++;
**	old = i++;
**	while (n < 3)
**	{
**		while (str[i] == '.' || str[i] == '\n')
**			i++;
**		if (i - old == 1)
**		{
**			arr[n++] = 1;
**			old = i++;
**		}
**		else if (((i - old) % 4) == 0)
**		{
**			arr[n++] = 4;
**			old = i++;
**		}
**		else if (((i - old) % 4) == 1)
**		{
**			arr[n++] = 2;
**			old = i++;
**		}
**		else if (((i - old) % 4) == 3)
**		{
**			arr[n++] = 5;
**			old = i++;
**		}
**	}
**	return (arr);
**}
*/
