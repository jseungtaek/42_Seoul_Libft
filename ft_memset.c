/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:46:54 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/29 21:18:43 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			len;
	char			*s_ptr;
	unsigned char	data;

	s_ptr = (char *)s;
	data = (unsigned char)c;
	len = 0;
	if (s == 0)
		return (NULL);
	while (num--)
	{
		s_ptr[len++] = data;
	}
	return (s);
}
