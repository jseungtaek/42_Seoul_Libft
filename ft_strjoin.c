/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:26:20 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 13:30:39 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	size_t	i;
	char	*ret;

	i = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (t_len + 1));
	if (ret == 0)
		return (0);
	while (i < t_len)
	{
		if (i > ft_strlen(s1))
			ret[i] = s2[i - ft_strlen(s1)];
		else
			ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
