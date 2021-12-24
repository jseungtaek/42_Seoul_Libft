/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:46:54 by sejeon            #+#    #+#             */
/*   Updated: 2021/11/13 14:08:13 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	if (s == 0)
		return (NULL);
	while (len < n)
	{
		*(unsigned char *)(s + len) = c;
		len++;
	}
	return (s);
}
