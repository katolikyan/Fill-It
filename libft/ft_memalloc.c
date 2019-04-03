/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:52:16 by tkatolik          #+#    #+#             */
/*   Updated: 2019/02/17 22:49:41 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*ptr;

	if (!(ptr = (void *)malloc(size)))
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
