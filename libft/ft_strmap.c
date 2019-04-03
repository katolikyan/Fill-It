/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:45:14 by tkatolik          #+#    #+#             */
/*   Updated: 2019/02/19 20:20:10 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*new;
	char		*ptr;
	size_t		inx;

	inx = 0;
	if (!s || !f)
		return (NULL);
	ptr = (char *)s;
	if (!(new = ft_memalloc(ft_strlen(ptr) + 1)))
		return (NULL);
	while (ptr[inx])
	{
		new[inx] = f(ptr[inx]);
		inx++;
	}
	new[inx] = '\0';
	return (new);
}
