/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:53:06 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 16:59:23 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	if (lst == 0)
		return (0);
	size = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp -> next;
		++size;
	}
	return (size);
}
