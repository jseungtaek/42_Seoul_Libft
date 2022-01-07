/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:43:09 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 13:24:09 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && len > 0)
	{
		j = 0;
		while (big[i + j] == little[j] && j < len)
		{
			if (little[j] == '\0')
				return ((char *) big);
			j++;
		}
		i++;
		len--;
	}
	return (0);
}
