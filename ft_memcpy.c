/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:18:34 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 14:32:26 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			len;
	unsigned char	*n_dst;
	unsigned char	*n_src;

	len = 0;
	if (!dest && !src)
		return (0);
	n_dst = dest;
	n_src = (unsigned char *)src;
	while (len++ < n)
	{
		*n_dst++ = *n_src++;
	}
	return (dest);
}
