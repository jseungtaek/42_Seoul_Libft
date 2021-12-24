/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:38:28 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/20 21:51:51 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	st;
	size_t	end;

	st = 0;
	end = ft_strlen(s1);
	while (s1[st] && ft_set(s1[st], set))
		st++;
	while (s1[end - 1] && ft_set(s1[end - 1], set))
		end--;
	ret = malloc(sizeof(char) * (end - st) + 2);
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s1 + st, end - st + 2);
	return (ret);
}
