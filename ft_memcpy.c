/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:18:34 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/20 19:37:54 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (dest == 0)
		return (NULL);
	while (len < n)
	{
		*(char *)(dest + len) = *(char *)(src + len);
		len++;
	}
	return (dest);
}
