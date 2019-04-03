/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:08:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/08 00:13:39 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

t_list			*ft_check_input(int fd);
char			*ft_read_5_lines(int fd, int *v);
int				ft_check_tetri(char *str);
int				ft_check_tetri_2(char *str);
int				ft_check_symbols(char *str);
int				*ft_define_tetri_array(char *str);
t_list			*ft_store_tetri(char *str);

int				ft_solver(t_list *tetris, char *map, int size, char **res);
int				ft_check_position(int *arr, char *map, int size, int idx);
int				ft_build_map(char **map, int numtetri);
int				ft_rebuild_map(char **map, int map_size);
void			ft_fill_tetri(char *map, int size, int *arr, char letter);
void			ft_encoder(int *arr, char *str, int *ind);

void			main_part_2(char *map, char *result, int m_size, t_list *list);
int				check_2(int *arr, char *map, int size, int *inn);
void			fill_2(int *arr, int *ind, char letter, char *map);
void			ft_read(int *nline, char **line, int *v, char **t);

#endif
