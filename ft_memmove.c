/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:22:22 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 14:32:53 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*n_dst;
	unsigned char	*n_src;

	if (dest == 0 && src == 0)
		return (0);
	n_dst = (unsigned char *)dest;
	n_src = (unsigned char *)src;
	if (n_dst <= n_src)
	{
		while (n)
		{
			*n_dst++ = *n_src++;
			n--;
		}
	}
	else
	{
		while (n)
		{
			n--;
			n_dst[n] = n_src[n];
		}
	}
	return (dest);
}
