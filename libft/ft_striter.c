/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:22:52 by tkatolik          #+#    #+#             */
/*   Updated: 2019/02/19 20:18:42 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
	{
		f(s);
		s++;
	}
	return ;
}