/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:03:05 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 15:43:26 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/get_next_line.h"
#include "fillit.h"

static int		g_was_null = 0;

char			*ft_read_5_lines(int fd, int *v)
{
	int			nline[2];
	char		*line;
	char		*tetri;

	nline[0] = 0;
	nline[1] = fd;
	tetri = ft_memalloc(1);
	ft_read(nline, &line, v, &tetri);
	if (nline[0] == 4)
	{
		ft_memdel((void **)&line);
		return (tetri);
	}
	if (nline[0] == 0 && g_was_null == 2)
	{
		ft_memdel((void **)&tetri);
		ft_memdel((void **)&line);
		return (NULL);
	}
	ft_memdel((void **)&tetri);
	ft_memdel((void **)&line);
	*v = 0;
	return (NULL);
}

void			ft_read(int *nline, char **line, int *v, char **t)
{
	char		*tmp;

	while (nline[0] < 5)
	{
		if ((get_next_line(nline[1], line)) <= 0)
		{
			g_was_null++;
			break ;
		}
		if (ft_strlen(*line) != 4)
		{
			if (nline[0] == 4 && ft_strlen(*line) == 0)
				break ;
			ft_memdel((void **)t);
			ft_memdel((void **)line);
			*v = 0;
			break ;
		}
		tmp = ft_strjoin(*t, *line);
		ft_memdel((void **)t);
		ft_memdel((void **)line);
		*t = ft_strjoin(tmp, "\n");
		ft_memdel((void **)&tmp);
		nline[0]++;
	}
}
