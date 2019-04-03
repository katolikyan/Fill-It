/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:28:18 by tkatolik          #+#    #+#             */
/*   Updated: 2019/02/19 20:13:08 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		if (*(char *)src != (char)c)
			*(char *)dst = *(char *)src;
		else
		{
			*(char *)dst = (char)c;
			dst++;
			return (dst);
		}
		src++;
		dst++;
		n--;
	}
	dst = NULL;
	return (dst);
}
