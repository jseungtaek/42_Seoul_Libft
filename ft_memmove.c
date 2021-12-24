/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:22:22 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/20 19:38:11 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;

	if (dest == 0 || src == 0)
		return (NULL);
	if (dest < src)
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	else
	{
		len = n - 1;
		while (len >= 0)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len--;
		}
	}
	return (dest);
}
