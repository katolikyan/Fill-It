/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:10:52 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 17:23:14 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/get_next_line.h"
#include "fillit.h"

int				main(int ac, char **av)
{
	int			fd;
	char		*map;
	char		*result;
	int			m_size;
	t_list		*list;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	if (!(list = ft_check_input(fd)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	result = NULL;
	m_size = ft_build_map(&map, ft_lstsize(list));
	main_part_2(map, result, m_size, list);
	close(fd);
	return (0);
}

void			main_part_2(char *map, char *result, int m_size, t_list *list)
{
	while (ft_solver(list, map, m_size, &result) == 0)
	{
		ft_memdel((void **)&map);
		m_size = ft_rebuild_map(&map, m_size);
	}
	ft_putstr(result);
	ft_memdel((void **)&map);
	ft_memdel((void **)&result);
	return ;
}
