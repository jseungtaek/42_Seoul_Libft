/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:43:09 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 15:00:27 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	i = ft_strlen(big);
	j = ft_strlen(little);
	if (i < j || len < j)
		return (0);
	if (i > len)
		size = len;
	else
		size = i;
	while (size >= j)
	{
		if (ft_memcmp(big, little, j) == 0)
			return ((char *)big);
		big++;
		size--;
	}
	return (0);
}
