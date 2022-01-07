/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:08:23 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 13:29:37 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n_len;
	char	*ret;

	if (s == 0)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	n_len = ft_strlen(s + start);
	if (n_len < len)
		len = n_len;
	ret = malloc(sizeof(char) * len + 1);
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
