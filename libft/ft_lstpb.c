/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:37:27 by tkatolik          #+#    #+#             */
/*   Updated: 2019/03/03 19:19:38 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpb(t_list **begin, const void *cnt, size_t cnt_size)
{
	t_list	*crnt;

	if (!begin)
		return ;
	if (!(*begin))
	{
		*begin = ft_lstnew(cnt, cnt_size);
		return ;
	}
	crnt = *begin;
	while (crnt->next)
		crnt = crnt->next;
	crnt->next = ft_lstnew(cnt, cnt_size);
	return ;
}
