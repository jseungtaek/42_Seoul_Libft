/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:28:16 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/20 18:31:46 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp1;

	tmp1 = (unsigned char *) s1;
	while (n)
	{
		if (tmp1 == (unsigned char) c)
			return ((void *) tmp1);
		tmp1++;
		n--;
	}
	return (0);
}
