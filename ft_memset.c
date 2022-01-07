/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:46:54 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 13:11:17 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*s_ptr;
	unsigned char	data;

	s_ptr = s;
	data = c;
	len = 0;
	while (len++ < n)
	{
		*s_ptr++ = data;
	}
	return (s);
}
