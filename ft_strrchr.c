/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:01:06 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/20 19:00:02 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*st;

	st = (char *) s;
	while (*s)
		s++;
	while (s >= st)
	{
		if (*s == (char) c)
			return ((char *) s);
		s--;
	}
	return (0);
}
